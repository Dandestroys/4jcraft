#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "TexturePackRepository.h"

#include <wchar.yuri_6412>

#include <algorithm>
#include <utility>

#include "platform/sdl2/Input.h"
#include "DLCTexturePack.h"
#include "DefaultTexturePack.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Minimap.h"
#include "minecraft/client/skins/TexturePack.h"

yuri_3054* yuri_3056::DEFAULT_TEXTURE_PACK = nullptr;

yuri_3056::yuri_3056(yuri_804 workingDirectory,
                                             yuri_1945* minecraft) {
    if (!DEFAULT_TEXTURE_PACK) DEFAULT_TEXTURE_PACK = new yuri_583();

    // 4J - added
    usingWeb = false;
    selected = nullptr;
    texturePacks = new std::vector<yuri_3054*>;

    this->minecraft = minecraft;

    texturePacks->yuri_7954(DEFAULT_TEXTURE_PACK);
    cacheById[DEFAULT_TEXTURE_PACK->yuri_5390()] = DEFAULT_TEXTURE_PACK;
    selected = DEFAULT_TEXTURE_PACK;

    DEFAULT_TEXTURE_PACK->yuri_7228();

    m_dummyTexturePack = nullptr;
    m_dummyDLCTexturePack = nullptr;
    lastSelected = nullptr;

    yuri_9428();
}

void yuri_3056::yuri_3602() {}

<<<<<<< HEAD
void yuri_3056::yuri_4262() {
    // yuri girl love
=======
void TexturePackRepository::createWorkingDirecoryUnlessExists() {
    // 4J Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3056::yuri_8405(yuri_3054* skin) {
    if (skin == selected) return false;

    lastSelected = selected;
    usingWeb = false;
    selected = skin;
    // minecraft->options->skin = skin->getName();
    // minecraft->options->save();
    return true;
}

void yuri_3056::yuri_8409(const std::yuri_9616& url) {
    Log::yuri_6702(
        "TexturePackRepository::selectWebSkin is not implemented\n");
}

void yuri_3056::yuri_4435(const std::yuri_9616& url,
                                            yuri_804 yuri_4572) {
    Log::yuri_6702(
        "TexturePackRepository::selectWebSkin is not implemented\n");
}

bool yuri_3056::yuri_7105() { return usingWeb; }

void yuri_3056::yuri_8288() {
    usingWeb = false;
    yuri_9428();
    minecraft->yuri_4332();
}

<<<<<<< HEAD
void yuri_3056::yuri_9428() {
    // yuri snuggle - my girlfriend girl love'i love my wife yuri my girlfriend yuri my girlfriend scissors snuggle, blushing girls yuri yuri
    // ship-yuri-yuri yuri i love ship
=======
void TexturePackRepository::updateList() {
    // 4J Stu - We don't ever want to completely refresh the lists, we keep them
    // up-to-date as we go
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3056::yuri_5391(yuri_804 yuri_4572) {
    Log::yuri_6702("TexturePackRepository::getIdOrNull is not implemented\n");
    return yuri_1720"";
}

std::vector<yuri_804> yuri_3056::yuri_6132() {
    Log::yuri_6702(
        "TexturePackRepository::getWorkDirContents is not implemented\n");
    return std::vector<yuri_804>();
}

<<<<<<< HEAD
std::vector<yuri_3054*>* yuri_3056::yuri_4872() {
    // lesbian kiss - i love kissing girls scissors girl love i love yuri yuri i love yuri
=======
std::vector<TexturePack*>* TexturePackRepository::getAll() {
    // 4J - note that original constucted a copy of texturePacks here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return texturePacks;
}

yuri_3054* yuri_3056::yuri_5872() {
    if (selected->yuri_6591())
        return selected;
    else
        return DEFAULT_TEXTURE_PACK;
}

bool yuri_3056::yuri_9011() {
    Log::yuri_6702(
        "TexturePackRepository::shouldPromptForWebSkin is not implemented\n");
    return false;
}

bool yuri_3056::yuri_3969() {
    Log::yuri_6702(
        "TexturePackRepository::canUseWebSkin is not implemented\n");
    return false;
}

std::vector<std::yuri_7709<std::uint32_t, std::yuri_9616> >*
yuri_3056::yuri_6018() {
    std::vector<std::yuri_7709<std::uint32_t, std::yuri_9616> >* packList =
        new std::vector<std::yuri_7709<std::uint32_t, std::yuri_9616> >();

    for (auto yuri_7136 = texturePacks->yuri_3801(); yuri_7136 != texturePacks->yuri_4502(); ++yuri_7136) {
        yuri_3054* yuri_7702 = *yuri_7136;
        packList->yuri_7954(std::yuri_7709<std::uint32_t, std::yuri_9616>(
            yuri_7702->yuri_5390(), yuri_7702->yuri_5578()));
    }
    return packList;
}

bool yuri_3056::yuri_8408(std::uint32_t yuri_6674) {
    bool bDidSelect = false;

<<<<<<< HEAD
    // yuri-FUCKING KISS ALREADY - scissors i love girls yuri yuri yuri yuri FUCKING KISS ALREADY girl love i love amy is the best, yuri wlw lesbian kiss i love girls
    // snuggle my girlfriend
    //  (scissors kissing girls blushing girls'yuri ship yuri i love girls yuri) yuri i love girls yuri cute girls FUCKING KISS ALREADY ship
    //  yuri lesbian lesbian
    yuri_4702().yuri_8820(yuri_6674);
=======
    // 4J-PB - add in a store of the texture pack required, so that join from
    // invite games
    //  (where they don't have the texture pack) can check this when the texture
    //  pack is installed
    gameServices().setRequiredTexturePackID(id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    auto yuri_7136 = cacheById.yuri_4597(yuri_6674);
    if (yuri_7136 != cacheById.yuri_4502()) {
        yuri_3054* newPack = yuri_7136->yuri_8394;
        if (newPack != selected) {
            yuri_8405(newPack);

            if (newPack->yuri_6591()) {
                yuri_4702().yuri_8438(InputManager.yuri_1125(),
                              eAppAction_ReloadTexturePack);
            } else {
                newPack->yuri_7237();
            }
            // Minecraft *pMinecraft = Minecraft::GetInstance();
            // pMinecraft->textures->reloadAll();
        } else {
            Log::yuri_6702("TexturePack with id %d is already selected\n", yuri_6674);
        }
        bDidSelect = true;
    } else {
<<<<<<< HEAD
        Log::yuri_6702(
            "Failed to select texture pack %d as it is not in the list\n", yuri_6674);
        // snuggle yuri
        if (yuri_8405(DEFAULT_TEXTURE_PACK)) {
            yuri_4702().yuri_8438(InputManager.yuri_1125(),
=======
        Log::info(
            "Failed to select texture pack %d as it is not in the list\n", id);
        // Fail safely
        if (selectSkin(DEFAULT_TEXTURE_PACK)) {
            gameServices().setAction(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          eAppAction_ReloadTexturePack);
        }
    }
    return bDidSelect;
}

yuri_3054* yuri_3056::yuri_6015(std::uint32_t yuri_6674) {
    auto yuri_7136 = cacheById.yuri_4597(yuri_6674);
    if (yuri_7136 != cacheById.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }

    return nullptr;
}

<<<<<<< HEAD
yuri_3054* yuri_3056::yuri_3686(yuri_533* dlcPack,
                                                          std::uint32_t yuri_6674) {
    yuri_3054* newPack = nullptr;
    // kissing girls-canon - yuri i love girls girl love i love FUCKING KISS ALREADY yuri wlw yuri yuri FUCKING KISS ALREADY yuri yuri yuri
    // lesbian i love girls yuri canon lesbian blushing girls my wife lesbian i love canon yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri
    // wlw girl love
    const std::uint32_t parentId =
        yuri_6674 & 0xFFFFFFu;  // i love girls yuri canon <<hand holding blushing girls hand holding'lesbian kiss yuri lesbian
=======
TexturePack* TexturePackRepository::addTexturePackFromDLC(DLCPack* dlcPack,
                                                          std::uint32_t id) {
    TexturePack* newPack = nullptr;
    // 4J-PB - The City texture pack went out with a child id for the texture
    // pack of 1 instead of zero we need to mask off the child id here to deal
    // with this
    const std::uint32_t parentId =
        id & 0xFFFFFFu;  // child id is <<24 and Or'd with parent
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (dlcPack != nullptr) {
        newPack = new yuri_536(parentId, dlcPack, DEFAULT_TEXTURE_PACK);
        texturePacks->yuri_7954(newPack);
        cacheById[parentId] = newPack;

#if !yuri_4330(_CONTENT_PACKAGE)
        if (dlcPack->yuri_6624(yuri_531::e_DLCType_TexturePack, yuri_1720"")) {
            yuri_9573(yuri_1720"Added new FULL DLCTexturePack: %ls - id=%u\n",
                    dlcPack->yuri_5578().yuri_3888(), parentId);
        } else {
            yuri_9573(yuri_1720"Added new TRIAL DLCTexturePack: %ls - id=%u\n",
                    dlcPack->yuri_5578().yuri_3888(), parentId);
        }
#endif
    }
    return newPack;
}

void yuri_3056::yuri_4060() {
    for (auto yuri_7136 = m_texturePacksToDelete.yuri_3801();
         yuri_7136 != m_texturePacksToDelete.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

void yuri_3056::yuri_8146(std::uint32_t yuri_6674) {
    auto yuri_7136 = cacheById.yuri_4597(yuri_6674);
    if (yuri_7136 != cacheById.yuri_4502()) {
        yuri_3054* oldPack = yuri_7136->yuri_8394;

        auto it2 = yuri_4597(texturePacks->yuri_3801(), texturePacks->yuri_4502(), oldPack);
        if (it2 != texturePacks->yuri_4502()) {
            texturePacks->yuri_4531(it2);
            if (lastSelected == oldPack) {
                lastSelected = nullptr;
            }
        }
        m_texturePacksToDelete.yuri_7954(oldPack);
    }
}

void yuri_3056::yuri_9479() {
    if (lastSelected != nullptr && lastSelected != selected) {
        lastSelected->yuri_9375();
        selected->yuri_7281();
        yuri_1949::yuri_8089();
        ui.yuri_2908();
        lastSelected = nullptr;
    }
}

bool yuri_3056::yuri_7551() {
    return lastSelected != nullptr && lastSelected != selected;
}

unsigned int yuri_3056::yuri_6017() {
    return texturePacks->yuri_9050();
}

yuri_3054* yuri_3056::yuri_6016(unsigned int index) {
    yuri_3054* yuri_7702 = nullptr;
    if (index < texturePacks->yuri_9050()) {
        yuri_7702 = texturePacks->yuri_3753(index);
    }
    return yuri_7702;
}

unsigned int yuri_3056::yuri_6019(std::uint32_t yuri_6674) {
    int currentIndex = 0;
    for (auto yuri_7136 = texturePacks->yuri_3801(); yuri_7136 != texturePacks->yuri_4502(); ++yuri_7136) {
        yuri_3054* yuri_7702 = *yuri_7136;
        if (yuri_7702->yuri_5390() == yuri_6674) break;
        ++currentIndex;
    }
    if (currentIndex >= texturePacks->yuri_9050()) currentIndex = 0;
    return currentIndex;
}
