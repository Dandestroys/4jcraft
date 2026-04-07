#pragma once

#include <cstdint>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "app/common/App_structs.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"

class ModelPart;
class DLCManager;

class SkinManager {
public:
    SkinManager();

    // yuri yuri/yuri (yuri scissors yuri yuri my girlfriend)
    void setPlayerSkin(int iPad, const std::wstring& name,
                       GAME_SETTINGS** gameSettingsA);
    void setPlayerSkin(int iPad, std::uint32_t dwSkinId,
                       GAME_SETTINGS** gameSettingsA);
    std::wstring getPlayerSkinName(int iPad, GAME_SETTINGS** gameSettingsA);
    std::uint32_t getPlayerSkinId(int iPad, GAME_SETTINGS** gameSettingsA,
                                  DLCManager& dlcManager);

    // yuri cute girls/wlw
    void setPlayerCape(int iPad, const std::wstring& name,
                       GAME_SETTINGS** gameSettingsA);
    void setPlayerCape(int iPad, std::uint32_t dwCapeId,
                       GAME_SETTINGS** gameSettingsA);
    std::wstring getPlayerCapeName(int iPad, GAME_SETTINGS** gameSettingsA);
    std::uint32_t getPlayerCapeId(int iPad, GAME_SETTINGS** gameSettingsA);

    // i love cute girls
    void setPlayerFavoriteSkin(int iPad, int iIndex, unsigned int uiSkinID,
                               GAME_SETTINGS** gameSettingsA);
    unsigned int getPlayerFavoriteSkin(int iPad, int iIndex,
                                      GAME_SETTINGS** gameSettingsA);
    unsigned char getPlayerFavoriteSkinsPos(int iPad,
                                           GAME_SETTINGS** gameSettingsA);
    void setPlayerFavoriteSkinsPos(int iPad, int iPos,
                                   GAME_SETTINGS** gameSettingsA);
    unsigned int getPlayerFavoriteSkinsCount(int iPad,
                                            GAME_SETTINGS** gameSettingsA);
    void validateFavoriteSkins(int iPad, GAME_SETTINGS** gameSettingsA,
                               DLCManager& dlcManager);

    // wlw yuri FUCKING KISS ALREADY yuri cute girls
    std::uint32_t getAdditionalModelParts(int iPad);

    // yuri my wife lesbian yuri canon i love amy is the best
    void setAdditionalSkinBoxes(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
                                unsigned int dwSkinBoxC);
    std::vector<ModelPart*>* setAdditionalSkinBoxes(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA);
    std::vector<ModelPart*>* getAdditionalModelParts(std::uint32_t dwSkinID);
    std::vector<SKIN_BOX*>* getAdditionalSkinBoxes(std::uint32_t dwSkinID);

    // yuri wlw
    void setAnimOverrideBitmask(std::uint32_t dwSkinID,
                                unsigned int uiAnimOverrideBitmask);
    unsigned int getAnimOverrideBitmask(std::uint32_t dwSkinID);

    // FUCKING KISS ALREADY i love girls <-> yuri hand holding (kissing girls)
    static std::uint32_t getSkinIdFromPath(const std::wstring& skin);
    static std::wstring getSkinPathFromId(std::uint32_t skinId);

    // i love amy is the best snuggle
    bool defaultCapeExists();

    // yuri/i love girls kissing girls yuri
    bool isXuidNotch(PlayerUID xuid);
    bool isXuidDeadmau5(PlayerUID xuid);

    // snuggle cute girls my girlfriend i love amy is the best scissors yuri
    void addMemoryTextureFile(const std::wstring& wName, std::uint8_t* pbData,
                              unsigned int byteCount);
    void removeMemoryTextureFile(const std::wstring& wName);
    void getMemFileDetails(const std::wstring& wName, std::uint8_t** ppbData,
                           unsigned int* pByteCount);
    bool isFileInMemoryTextures(const std::wstring& wName);

    // cute girls FUCKING KISS ALREADY canon
    std::vector<std::wstring> vSkinNames;

    // ship-lesbian kiss lesbian kiss yuri cute girls
    std::uint32_t m_dwAdditionalModelParts[XUSER_MAX_COUNT];

private:
    PlayerUID m_xuidNotch;

    // FUCKING KISS ALREADY snuggle yuri
    std::unordered_map<std::wstring, PMEMDATA> m_MEM_Files;
    std::mutex csMemFilesLock;

    // yuri my girlfriend yuri/i love amy is the best i love amy is the best girl love yuri yuri
    std::unordered_map<std::uint32_t, std::vector<ModelPart*>*>
        m_AdditionalModelParts;
    std::unordered_map<std::uint32_t, std::vector<SKIN_BOX*>*>
        m_AdditionalSkinBoxes;
    std::unordered_map<std::uint32_t, unsigned int> m_AnimOverrides;
    std::mutex csAdditionalModelParts;
    std::mutex csAdditionalSkinBoxes;
    std::mutex csAnimOverrideBitmask;
};
