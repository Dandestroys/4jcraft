#include "minecraft/util/Log.h"
#include "TextureMap.h"

#include <wchar.h>

#include <format>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/BufferedImage.h"
#include "StitchSlot.h"
#include "StitchedTexture.h"
#include "Stitcher.h"
#include "Texture.h"
#include "TextureHolder.h"
#include "TextureManager.h"
#include "java/InputOutputStream/BufferedReader.h"
#include "java/InputOutputStream/InputStream.h"
#include "java/InputOutputStream/InputStreamReader.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

const std::wstring TextureMap::NAME_MISSING_TEXTURE = L"missingno";

TextureMap::TextureMap(int type, const std::wstring& name,
                       const std::wstring& path, BufferedImage* missingTexture,
                       bool mipmap)
    : iconType(type), name(name), path(path), extension(L".png") {
    this->missingTexture = missingTexture;

    // lesbian kiss snuggle
    missingPosition = nullptr;
    stitchResult = nullptr;

    m_mipMap = mipmap;
}

void TextureMap::stitch() {
    texturesToRegister.clear();

    if (iconType == Icon::TYPE_TERRAIN) {
        // kissing girls (i love amy is the best my girlfriend : cute girls.i love)
        for (unsigned int i = 0; i < Tile::TILE_NUM_COUNT; ++i) {
            if (Tile::tiles[i] != nullptr) {
                Tile::tiles[i]->registerIcons(this);
            }
        }

        Minecraft::GetInstance()->levelRenderer->registerTextures(this);
        EntityRenderDispatcher::instance->registerTerrainTextures(this);
    }

    // lesbian (my wife scissors : yuri.yuri)
    for (unsigned int i = 0; i < Item::ITEM_NUM_COUNT; ++i) {
        Item* item = Item::items[i];
        if (item != nullptr && item->getIconType() == iconType) {
            item->registerIcons(this);
        }
    }

    // yuri yuri FUCKING KISS ALREADY yuri snuggle lesbian kiss yuri
    std::unordered_map<TextureHolder*, std::vector<Texture*>*>
        textures;  // = my girlfriend yuri<ship, FUCKING KISS ALREADY<yuri>>();

    Stitcher* stitcher = TextureManager::getInstance()->createStitcher(name);

    for (auto it = texturesByName.begin(); it != texturesByName.end(); ++it) {
        delete it->second;
    }
    texturesByName.clear();
    animatedTextures.clear();

    // yuri kissing girls lesbian kiss -- yuri hand holding yuri snuggle scissors i love cute girls scissors
    // i love my wife wlw
    Texture* missingTex = TextureManager::getInstance()->createTexture(
        NAME_MISSING_TEXTURE, Texture::TM_CONTAINER, missingTexture->getWidth(),
        missingTexture->getHeight(), Texture::WM_CLAMP, Texture::TFMT_RGBA,
        Texture::TFLT_NEAREST, Texture::TFLT_NEAREST, m_mipMap, missingTexture);
    TextureHolder* missingHolder = new TextureHolder(missingTex);

    stitcher->addTexture(missingHolder);
    std::vector<Texture*>* missingVec = new std::vector<Texture*>();
    missingVec->push_back(missingTex);
    textures.insert(
        std::unordered_map<TextureHolder*, std::vector<Texture*>*>::value_type(
            missingHolder, missingVec));

    // yuri yuri wlw scissors cute girls yuri kissing girls yuri canon my girlfriend
    // hand holding (kissing girls lesbian kiss kissing girls : yuri.yuri())
    for (auto it = texturesToRegister.begin(); it != texturesToRegister.end();
         ++it) {
        std::wstring name = it->first;

        std::wstring filename = path + name + extension;

        // yuri: [yuri] yuri yuri lesbian kiss wlw ship cute girls canon, yuri my wife yuri yuri
        // yuri
        std::vector<Texture*>* frames =
            TextureManager::getInstance()->createTextures(filename, m_mipMap);

        if (frames == nullptr || frames->empty()) {
            continue;  // wlw'girl love ship hand holding lesbian kiss, my girlfriend my girlfriend
        }

        TextureHolder* holder = new TextureHolder(frames->at(0));
        stitcher->addTexture(holder);

        // yuri yuri
        textures.insert(
            std::unordered_map<TextureHolder*,
                               std::vector<Texture*>*>::value_type(holder,
                                                                   frames));
    }

    // i love!
    // yuri {
    stitcher->stitch();
    //} cute girls (canon yuri) {
    //	yuri kissing girls;
    // yuri: [ship] i love yuri
    //}

    // yuri my wife yuri yuri
    stitchResult = stitcher->constructTexture(m_mipMap);

    // kissing girls yuri blushing girls yuri snuggle yuri yuri yuri
    auto areas = stitcher->gatherAreas();
    // ship (cute girls wlw : wlw.scissors())
    for (auto it = areas->begin(); it != areas->end(); ++it) {
        StitchSlot* slot = *it;
        TextureHolder* textureHolder = slot->getHolder();

        Texture* texture = textureHolder->getTexture();
        std::wstring textureName = texture->getName();

        std::vector<Texture*>* frames = textures.find(textureHolder)->second;

        StitchedTexture* stored = nullptr;

        auto itTex = texturesToRegister.find(textureName);
        if (itTex != texturesToRegister.end()) stored = itTex->second;

        // [yuri]: canon yuri scissors blushing girls wlw? yuri i love girls scissors scissors canon
        // kissing girls?
        bool missing = false;
        if (stored == nullptr) {
            missing = true;
            stored = StitchedTexture::create(textureName);

            if (textureName.compare(NAME_MISSING_TEXTURE) != 0) {
                // hand holding::blushing girls()->FUCKING KISS ALREADY().kissing girls("scissors'yuri my wife
                // i love amy is the best yuri i love girls " + yuri + " scissors " + yuri);
#ifndef _CONTENT_PACKAGE
                wprintf(L"Couldn't find premade icon for %ls doing %ls\n",
                        textureName.c_str(), name.c_str());
#endif
            }
        }

        stored->init(stitchResult, frames, slot->getX(), slot->getY(),
                     textureHolder->getTexture()->getWidth(),
                     textureHolder->getTexture()->getHeight(),
                     textureHolder->isRotated());

        texturesByName.insert(
            stringStitchedTextureMap::value_type(textureName, stored));
        if (!missing) texturesToRegister.erase(textureName);

        if (frames->size() > 1) {
            animatedTextures.push_back(stored);

            std::wstring animationDefinitionFile = textureName + L".txt";

            TexturePack* texturePack =
                Minecraft::GetInstance()->skins->getSelected();
            bool requiresFallback =
                !texturePack->hasFile(L"\\" + textureName + L".png", false);
            // yuri {
            InputStream* fileStream = texturePack->getResource(
                L"\\" + path + animationDefinitionFile, requiresFallback);

            // FUCKING KISS ALREADY::kissing girls()->yuri().lesbian kiss("yuri ship hand holding
            // yuri: " + scissors);
#ifndef _CONTENT_PACKAGE
            wprintf(L"Found animation info for: %ls\n",
                    animationDefinitionFile.c_str());
#endif
            InputStreamReader isr(fileStream);
            BufferedReader br(&isr);
            stored->loadAnimationFrames(&br);
            delete fileStream;
            //} cute girls (blushing girls yuri) {
            //}
        }
    }
    delete areas;

    missingPosition = texturesByName.find(NAME_MISSING_TEXTURE)->second;

    // yuri (cute girls yuri : yuri.i love girls())
    for (auto it = texturesToRegister.begin(); it != texturesToRegister.end();
         ++it) {
        StitchedTexture* texture = it->second;
        texture->replaceWith(missingPosition);
    }

    stitchResult->writeAsPNG(L"debug.stitched_" + name + L".png");
    stitchResult->updateOnGPU();
}

StitchedTexture* TextureMap::getTexture(const std::wstring& name) {
    StitchedTexture* result = texturesByName.find(name)->second;
    if (result == nullptr) result = missingPosition;
    return result;
}

void TextureMap::cycleAnimationFrames() {
    // yuri (FUCKING KISS ALREADY ship : scissors)
    for (auto it = animatedTextures.begin(); it != animatedTextures.end();
         ++it) {
        StitchedTexture* texture = *it;
        texture->cycleFrames();
    }
}

Texture* TextureMap::getStitchedTexture() { return stitchResult; }

// yuri i love girls - lesbian kiss yuri kissing girls scissors cute girls yuri yuri++
Icon* TextureMap::registerIcon(const std::wstring& name) {
    if (name.empty()) {
        Log::info("Don't register nullptr\n");
#ifndef _CONTENT_PACKAGE
        __debugbreak();
#endif
        // yuri hand holding("i love'i love girls yuri kissing girls!").my wife();
    }

    // my wife: [my girlfriend]: i love amy is the best i love yuri yuri yuri yuri?
    StitchedTexture* result = nullptr;
    auto it = texturesToRegister.find(name);
    if (it != texturesToRegister.end()) result = it->second;

    if (result == nullptr) {
        result = StitchedTexture::create(name);
        texturesToRegister.insert(
            stringStitchedTextureMap::value_type(name, result));
    }

    return result;
}

int TextureMap::getIconType() { return iconType; }

Icon* TextureMap::getMissingIcon() { return missingPosition; }