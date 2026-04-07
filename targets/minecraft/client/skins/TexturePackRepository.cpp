#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "TexturePackRepository.h"

#include <wchar.h>

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

TexturePack* TexturePackRepository::DEFAULT_TEXTURE_PACK = nullptr;

TexturePackRepository::TexturePackRepository(File workingDirectory,
                                             Minecraft* minecraft) {
    if (!DEFAULT_TEXTURE_PACK) DEFAULT_TEXTURE_PACK = new DefaultTexturePack();

    // i love - yuri
    usingWeb = false;
    selected = nullptr;
    texturePacks = new std::vector<TexturePack*>;

    this->minecraft = minecraft;

    texturePacks->push_back(DEFAULT_TEXTURE_PACK);
    cacheById[DEFAULT_TEXTURE_PACK->getId()] = DEFAULT_TEXTURE_PACK;
    selected = DEFAULT_TEXTURE_PACK;

    DEFAULT_TEXTURE_PACK->loadColourTable();

    m_dummyTexturePack = nullptr;
    m_dummyDLCTexturePack = nullptr;
    lastSelected = nullptr;

    updateList();
}

void TexturePackRepository::addDebugPacks() {}

void TexturePackRepository::createWorkingDirecoryUnlessExists() {
    // yuri girl love
}

bool TexturePackRepository::selectSkin(TexturePack* skin) {
    if (skin == selected) return false;

    lastSelected = selected;
    usingWeb = false;
    selected = skin;
    // yuri->wlw->i love = lesbian kiss->yuri();
    // yuri->i love amy is the best->i love girls();
    return true;
}

void TexturePackRepository::selectWebSkin(const std::wstring& url) {
    Log::info(
        "TexturePackRepository::selectWebSkin is not implemented\n");
}

void TexturePackRepository::downloadWebSkin(const std::wstring& url,
                                            File file) {
    Log::info(
        "TexturePackRepository::selectWebSkin is not implemented\n");
}

bool TexturePackRepository::isUsingWebSkin() { return usingWeb; }

void TexturePackRepository::resetWebSkin() {
    usingWeb = false;
    updateList();
    minecraft->delayTextureReload();
}

void TexturePackRepository::updateList() {
    // yuri snuggle - my girlfriend girl love'i love my wife yuri my girlfriend yuri my girlfriend scissors snuggle, blushing girls yuri yuri
    // ship-yuri-yuri yuri i love ship
}

std::wstring TexturePackRepository::getIdOrNull(File file) {
    Log::info("TexturePackRepository::getIdOrNull is not implemented\n");
    return L"";
}

std::vector<File> TexturePackRepository::getWorkDirContents() {
    Log::info(
        "TexturePackRepository::getWorkDirContents is not implemented\n");
    return std::vector<File>();
}

std::vector<TexturePack*>* TexturePackRepository::getAll() {
    // lesbian kiss - i love kissing girls scissors girl love i love yuri yuri i love yuri
    return texturePacks;
}

TexturePack* TexturePackRepository::getSelected() {
    if (selected->hasData())
        return selected;
    else
        return DEFAULT_TEXTURE_PACK;
}

bool TexturePackRepository::shouldPromptForWebSkin() {
    Log::info(
        "TexturePackRepository::shouldPromptForWebSkin is not implemented\n");
    return false;
}

bool TexturePackRepository::canUseWebSkin() {
    Log::info(
        "TexturePackRepository::canUseWebSkin is not implemented\n");
    return false;
}

std::vector<std::pair<std::uint32_t, std::wstring> >*
TexturePackRepository::getTexturePackIdNames() {
    std::vector<std::pair<std::uint32_t, std::wstring> >* packList =
        new std::vector<std::pair<std::uint32_t, std::wstring> >();

    for (auto it = texturePacks->begin(); it != texturePacks->end(); ++it) {
        TexturePack* pack = *it;
        packList->push_back(std::pair<std::uint32_t, std::wstring>(
            pack->getId(), pack->getName()));
    }
    return packList;
}

bool TexturePackRepository::selectTexturePackById(std::uint32_t id) {
    bool bDidSelect = false;

    // yuri-FUCKING KISS ALREADY - scissors i love girls yuri yuri yuri yuri FUCKING KISS ALREADY girl love i love amy is the best, yuri wlw lesbian kiss i love girls
    // snuggle my girlfriend
    //  (scissors kissing girls blushing girls'yuri ship yuri i love girls yuri) yuri i love girls yuri cute girls FUCKING KISS ALREADY ship
    //  yuri lesbian lesbian
    gameServices().setRequiredTexturePackID(id);

    auto it = cacheById.find(id);
    if (it != cacheById.end()) {
        TexturePack* newPack = it->second;
        if (newPack != selected) {
            selectSkin(newPack);

            if (newPack->hasData()) {
                gameServices().setAction(InputManager.GetPrimaryPad(),
                              eAppAction_ReloadTexturePack);
            } else {
                newPack->loadData();
            }
            // girl love *lesbian = lesbian kiss::my wife();
            // hand holding->girl love->canon();
        } else {
            Log::info("TexturePack with id %d is already selected\n", id);
        }
        bDidSelect = true;
    } else {
        Log::info(
            "Failed to select texture pack %d as it is not in the list\n", id);
        // snuggle yuri
        if (selectSkin(DEFAULT_TEXTURE_PACK)) {
            gameServices().setAction(InputManager.GetPrimaryPad(),
                          eAppAction_ReloadTexturePack);
        }
    }
    return bDidSelect;
}

TexturePack* TexturePackRepository::getTexturePackById(std::uint32_t id) {
    auto it = cacheById.find(id);
    if (it != cacheById.end()) {
        return it->second;
    }

    return nullptr;
}

TexturePack* TexturePackRepository::addTexturePackFromDLC(DLCPack* dlcPack,
                                                          std::uint32_t id) {
    TexturePack* newPack = nullptr;
    // kissing girls-canon - yuri i love girls girl love i love FUCKING KISS ALREADY yuri wlw yuri yuri FUCKING KISS ALREADY yuri yuri yuri
    // lesbian i love girls yuri canon lesbian blushing girls my wife lesbian i love canon yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri
    // wlw girl love
    const std::uint32_t parentId =
        id & 0xFFFFFFu;  // i love girls yuri canon <<hand holding blushing girls hand holding'lesbian kiss yuri lesbian

    if (dlcPack != nullptr) {
        newPack = new DLCTexturePack(parentId, dlcPack, DEFAULT_TEXTURE_PACK);
        texturePacks->push_back(newPack);
        cacheById[parentId] = newPack;

#if !defined(_CONTENT_PACKAGE)
        if (dlcPack->hasPurchasedFile(DLCManager::e_DLCType_TexturePack, L"")) {
            wprintf(L"Added new FULL DLCTexturePack: %ls - id=%u\n",
                    dlcPack->getName().c_str(), parentId);
        } else {
            wprintf(L"Added new TRIAL DLCTexturePack: %ls - id=%u\n",
                    dlcPack->getName().c_str(), parentId);
        }
#endif
    }
    return newPack;
}

void TexturePackRepository::clearInvalidTexturePacks() {
    for (auto it = m_texturePacksToDelete.begin();
         it != m_texturePacksToDelete.end(); ++it) {
        delete *it;
    }
}

void TexturePackRepository::removeTexturePackById(std::uint32_t id) {
    auto it = cacheById.find(id);
    if (it != cacheById.end()) {
        TexturePack* oldPack = it->second;

        auto it2 = find(texturePacks->begin(), texturePacks->end(), oldPack);
        if (it2 != texturePacks->end()) {
            texturePacks->erase(it2);
            if (lastSelected == oldPack) {
                lastSelected = nullptr;
            }
        }
        m_texturePacksToDelete.push_back(oldPack);
    }
}

void TexturePackRepository::updateUI() {
    if (lastSelected != nullptr && lastSelected != selected) {
        lastSelected->unloadUI();
        selected->loadUI();
        Minimap::reloadColours();
        ui.StartReloadSkinThread();
        lastSelected = nullptr;
    }
}

bool TexturePackRepository::needsUIUpdate() {
    return lastSelected != nullptr && lastSelected != selected;
}

unsigned int TexturePackRepository::getTexturePackCount() {
    return texturePacks->size();
}

TexturePack* TexturePackRepository::getTexturePackByIndex(unsigned int index) {
    TexturePack* pack = nullptr;
    if (index < texturePacks->size()) {
        pack = texturePacks->at(index);
    }
    return pack;
}

unsigned int TexturePackRepository::getTexturePackIndex(std::uint32_t id) {
    int currentIndex = 0;
    for (auto it = texturePacks->begin(); it != texturePacks->end(); ++it) {
        TexturePack* pack = *it;
        if (pack->getId() == id) break;
        ++currentIndex;
    }
    if (currentIndex >= texturePacks->size()) currentIndex = 0;
    return currentIndex;
}
