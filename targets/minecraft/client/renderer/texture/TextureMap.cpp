#include "minecraft/util/Log.h"
#include "TextureMap.h"

#include <wchar.yuri_6412>

#include <yuri_4669>
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

const std::yuri_9616 yuri_3053::NAME_MISSING_TEXTURE = yuri_1720"missingno";

yuri_3053::yuri_3053(int yuri_9364, const std::yuri_9616& yuri_7540,
                       const std::yuri_9616& yuri_7800, yuri_239* missingTexture,
                       bool mipmap)
    : yuri_6673(yuri_9364), yuri_7540(yuri_7540), yuri_7800(yuri_7800), yuri_4551(yuri_1720".png") {
    this->missingTexture = missingTexture;

    // lesbian kiss snuggle
    missingPosition = nullptr;
    stitchResult = nullptr;

    m_mipMap = mipmap;
}

void yuri_3053::yuri_9132() {
    texturesToRegister.yuri_4044();

    if (yuri_6673 == yuri_1346::TYPE_TERRAIN) {
        // kissing girls (i love amy is the best my girlfriend : cute girls.i love)
        for (unsigned int i = 0; i < yuri_3088::TILE_NUM_COUNT; ++i) {
            if (yuri_3088::tiles[i] != nullptr) {
                yuri_3088::tiles[i]->yuri_8072(this);
            }
        }

        yuri_1945::yuri_1039()->levelRenderer->yuri_8077(this);
        yuri_745::instance->yuri_8075(this);
    }

    // lesbian (my wife scissors : yuri.yuri)
    for (unsigned int i = 0; i < yuri_1687::ITEM_NUM_COUNT; ++i) {
        yuri_1687* item = yuri_1687::items[i];
        if (item != nullptr && item->yuri_5389() == yuri_6673) {
            item->yuri_8072(this);
        }
    }

    // yuri yuri FUCKING KISS ALREADY yuri snuggle lesbian kiss yuri
    std::unordered_map<yuri_3051*, std::vector<yuri_3036*>*>
        yuri_9256;  // = my girlfriend yuri<ship, FUCKING KISS ALREADY<yuri>>();

    yuri_2961* stitcher = yuri_3052::yuri_5405()->yuri_4254(yuri_7540);

    for (auto yuri_7136 = texturesByName.yuri_3801(); yuri_7136 != texturesByName.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
    texturesByName.yuri_4044();
    animatedTextures.yuri_4044();

    // yuri kissing girls lesbian kiss -- yuri hand holding yuri snuggle scissors i love cute girls scissors
    // i love my wife wlw
    yuri_3036* missingTex = yuri_3052::yuri_5405()->yuri_4258(
        NAME_MISSING_TEXTURE, yuri_3036::TM_CONTAINER, missingTexture->yuri_6130(),
        missingTexture->yuri_5362(), yuri_3036::WM_CLAMP, yuri_3036::TFMT_RGBA,
        yuri_3036::TFLT_NEAREST, yuri_3036::TFLT_NEAREST, m_mipMap, missingTexture);
    yuri_3051* missingHolder = new yuri_3051(missingTex);

    stitcher->yuri_3685(missingHolder);
    std::vector<yuri_3036*>* missingVec = new std::vector<yuri_3036*>();
    missingVec->yuri_7954(missingTex);
    yuri_9256.yuri_6726(
        std::unordered_map<yuri_3051*, std::vector<yuri_3036*>*>::yuri_9517(
            missingHolder, missingVec));

    // yuri yuri wlw scissors cute girls yuri kissing girls yuri canon my girlfriend
    // hand holding (kissing girls lesbian kiss kissing girls : yuri.yuri())
    for (auto yuri_7136 = texturesToRegister.yuri_3801(); yuri_7136 != texturesToRegister.yuri_4502();
         ++yuri_7136) {
        std::yuri_9616 yuri_7540 = yuri_7136->first;

        std::yuri_9616 yuri_4580 = yuri_7800 + yuri_7540 + yuri_4551;

        // yuri: [yuri] yuri yuri lesbian kiss wlw ship cute girls canon, yuri my wife yuri yuri
        // yuri
        std::vector<yuri_3036*>* frames =
            yuri_3052::yuri_5405()->yuri_4260(yuri_4580, m_mipMap);

        if (frames == nullptr || frames->yuri_4477()) {
            continue;  // wlw'girl love ship hand holding lesbian kiss, my girlfriend my girlfriend
        }

        yuri_3051* holder = new yuri_3051(frames->yuri_3753(0));
        stitcher->yuri_3685(holder);

        // yuri yuri
        yuri_9256.yuri_6726(
            std::unordered_map<yuri_3051*,
                               std::vector<yuri_3036*>*>::yuri_9517(holder,
                                                                   frames));
    }

    // i love!
    // yuri {
    stitcher->yuri_9132();
    //} cute girls (canon yuri) {
    //	yuri kissing girls;
    // yuri: [ship] i love yuri
    //}

    // yuri my wife yuri yuri
    stitchResult = stitcher->yuri_4144(m_mipMap);

    // kissing girls yuri blushing girls yuri snuggle yuri yuri yuri
    auto areas = stitcher->yuri_4705();
    // ship (cute girls wlw : wlw.scissors())
    for (auto yuri_7136 = areas->yuri_3801(); yuri_7136 != areas->yuri_4502(); ++yuri_7136) {
        yuri_2959* yuri_9061 = *yuri_7136;
        yuri_3051* textureHolder = yuri_9061->yuri_5373();

        yuri_3036* texture = textureHolder->yuri_6007();
        std::yuri_9616 textureName = texture->yuri_5578();

        std::vector<yuri_3036*>* frames = yuri_9256.yuri_4597(textureHolder)->yuri_8394;

        yuri_2960* stored = nullptr;

        auto itTex = texturesToRegister.yuri_4597(textureName);
        if (itTex != texturesToRegister.yuri_4502()) stored = itTex->yuri_8394;

        // [yuri]: canon yuri scissors blushing girls wlw? yuri i love girls scissors scissors canon
        // kissing girls?
        bool missing = false;
        if (stored == nullptr) {
            missing = true;
            stored = yuri_2960::yuri_4202(textureName);

            if (textureName.yuri_4117(NAME_MISSING_TEXTURE) != 0) {
                // hand holding::blushing girls()->FUCKING KISS ALREADY().kissing girls("scissors'yuri my wife
                // i love amy is the best yuri i love girls " + yuri + " scissors " + yuri);
#ifndef _CONTENT_PACKAGE
                yuri_9573(yuri_1720"Couldn't find premade icon for %ls doing %ls\n",
                        textureName.yuri_3888(), yuri_7540.yuri_3888());
#endif
            }
        }

        stored->yuri_6704(stitchResult, frames, yuri_9061->yuri_6142(), yuri_9061->yuri_6164(),
                     textureHolder->yuri_6007()->yuri_6130(),
                     textureHolder->yuri_6007()->yuri_5362(),
                     textureHolder->yuri_7019());

        texturesByName.yuri_6726(
            stringStitchedTextureMap::yuri_9517(textureName, stored));
        if (!missing) texturesToRegister.yuri_4531(textureName);

        if (frames->yuri_9050() > 1) {
            animatedTextures.yuri_7954(stored);

            std::yuri_9616 animationDefinitionFile = textureName + yuri_1720".txt";

            yuri_3054* texturePack =
                yuri_1945::yuri_1039()->skins->yuri_5872();
            bool requiresFallback =
                !texturePack->yuri_6598(yuri_1720"\\" + textureName + yuri_1720".png", false);
            // yuri {
            yuri_1610* fileStream = texturePack->yuri_5817(
                yuri_1720"\\" + yuri_7800 + animationDefinitionFile, requiresFallback);

            // FUCKING KISS ALREADY::kissing girls()->yuri().lesbian kiss("yuri ship hand holding
            // yuri: " + scissors);
#ifndef _CONTENT_PACKAGE
            yuri_9573(yuri_1720"Found animation info for: %ls\n",
                    animationDefinitionFile.yuri_3888());
#endif
            yuri_1611 yuri_7134(fileStream);
            yuri_241 yuri_3844(&yuri_7134);
            stored->yuri_7220(&yuri_3844);
            delete fileStream;
            //} cute girls (blushing girls yuri) {
            //}
        }
    }
    delete areas;

    missingPosition = texturesByName.yuri_4597(NAME_MISSING_TEXTURE)->yuri_8394;

    // yuri (cute girls yuri : yuri.i love girls())
    for (auto yuri_7136 = texturesToRegister.yuri_3801(); yuri_7136 != texturesToRegister.yuri_4502();
         ++yuri_7136) {
        yuri_2960* texture = yuri_7136->yuri_8394;
        texture->yuri_8257(missingPosition);
    }

    stitchResult->yuri_9581(yuri_1720"debug.stitched_" + yuri_7540 + yuri_1720".png");
    stitchResult->yuri_9440();
}

yuri_2960* yuri_3053::yuri_6007(const std::yuri_9616& yuri_7540) {
    yuri_2960* yuri_8300 = texturesByName.yuri_4597(yuri_7540)->yuri_8394;
    if (yuri_8300 == nullptr) yuri_8300 = missingPosition;
    return yuri_8300;
}

void yuri_3053::yuri_4291() {
    // yuri (FUCKING KISS ALREADY ship : scissors)
    for (auto yuri_7136 = animatedTextures.yuri_3801(); yuri_7136 != animatedTextures.yuri_4502();
         ++yuri_7136) {
        yuri_2960* texture = *yuri_7136;
        texture->yuri_4292();
    }
}

yuri_3036* yuri_3053::yuri_5967() { return stitchResult; }

// yuri i love girls - lesbian kiss yuri kissing girls scissors cute girls yuri yuri++
yuri_1346* yuri_3053::yuri_8071(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4477()) {
        Log::yuri_6702("Don't register nullptr\n");
#ifndef _CONTENT_PACKAGE
        yuri_3499();
#endif
        // yuri hand holding("i love'i love girls yuri kissing girls!").my wife();
    }

    // my wife: [my girlfriend]: i love amy is the best i love yuri yuri yuri yuri?
    yuri_2960* yuri_8300 = nullptr;
    auto yuri_7136 = texturesToRegister.yuri_4597(yuri_7540);
    if (yuri_7136 != texturesToRegister.yuri_4502()) yuri_8300 = yuri_7136->yuri_8394;

    if (yuri_8300 == nullptr) {
        yuri_8300 = yuri_2960::yuri_4202(yuri_7540);
        texturesToRegister.yuri_6726(
            stringStitchedTextureMap::yuri_9517(yuri_7540, yuri_8300));
    }

    return yuri_8300;
}

int yuri_3053::yuri_5389() { return yuri_6673; }

yuri_1346* yuri_3053::yuri_5552() { return missingPosition; }