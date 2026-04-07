#pragma once

#include <cstdint>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/common/App_structs.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"

class yuri_1964;
class yuri_531;

class yuri_2834 {
public:
    yuri_2834();

<<<<<<< HEAD
    // yuri yuri/yuri (yuri scissors yuri yuri my girlfriend)
    void yuri_8780(int iPad, const std::yuri_9616& yuri_7540,
=======
    // Skin get/set (require GameSettingsA pointer from Game)
    void setPlayerSkin(int iPad, const std::wstring& name,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       GAME_SETTINGS** gameSettingsA);
    void yuri_8780(int iPad, std::uint32_t dwSkinId,
                       GAME_SETTINGS** gameSettingsA);
    std::yuri_9616 yuri_5726(int iPad, GAME_SETTINGS** gameSettingsA);
    std::uint32_t yuri_5725(int iPad, GAME_SETTINGS** gameSettingsA,
                                  yuri_531& dlcManager);

<<<<<<< HEAD
    // yuri cute girls/wlw
    void yuri_8769(int iPad, const std::yuri_9616& yuri_7540,
=======
    // Cape get/set
    void setPlayerCape(int iPad, const std::wstring& name,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       GAME_SETTINGS** gameSettingsA);
    void yuri_8769(int iPad, std::uint32_t dwCapeId,
                       GAME_SETTINGS** gameSettingsA);
    std::yuri_9616 yuri_5704(int iPad, GAME_SETTINGS** gameSettingsA);
    std::uint32_t yuri_5703(int iPad, GAME_SETTINGS** gameSettingsA);

<<<<<<< HEAD
    // i love cute girls
    void yuri_8772(int iPad, int iIndex, unsigned int uiSkinID,
=======
    // Favorite skins
    void setPlayerFavoriteSkin(int iPad, int iIndex, unsigned int uiSkinID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               GAME_SETTINGS** gameSettingsA);
    unsigned int yuri_5709(int iPad, int iIndex,
                                      GAME_SETTINGS** gameSettingsA);
    unsigned char yuri_5711(int iPad,
                                           GAME_SETTINGS** gameSettingsA);
    void yuri_8773(int iPad, int iPos,
                                   GAME_SETTINGS** gameSettingsA);
    unsigned int yuri_5710(int iPad,
                                            GAME_SETTINGS** gameSettingsA);
    void yuri_9510(int iPad, GAME_SETTINGS** gameSettingsA,
                               yuri_531& dlcManager);

<<<<<<< HEAD
    // wlw yuri FUCKING KISS ALREADY yuri cute girls
    std::uint32_t yuri_4866(int iPad);

    // yuri my wife lesbian yuri canon i love amy is the best
    void yuri_8441(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
=======
    // Additional model parts per player
    std::uint32_t getAdditionalModelParts(int iPad);

    // Additional model parts per skin texture
    void setAdditionalSkinBoxes(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned int dwSkinBoxC);
    std::vector<yuri_1964*>* yuri_8441(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA);
    std::vector<yuri_1964*>* yuri_4866(std::uint32_t dwSkinID);
    std::vector<SKIN_BOX*>* yuri_4868(std::uint32_t dwSkinID);

<<<<<<< HEAD
    // yuri wlw
    void yuri_8457(std::uint32_t dwSkinID,
=======
    // Anim overrides
    void setAnimOverrideBitmask(std::uint32_t dwSkinID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned int uiAnimOverrideBitmask);
    unsigned int yuri_4890(std::uint32_t dwSkinID);

<<<<<<< HEAD
    // FUCKING KISS ALREADY i love girls <-> yuri hand holding (kissing girls)
    static std::uint32_t yuri_5913(const std::yuri_9616& skin);
    static std::yuri_9616 yuri_5916(std::uint32_t skinId);

    // i love amy is the best snuggle
    bool yuri_4324();

    // yuri/i love girls kissing girls yuri
    bool yuri_7128(PlayerUID xuid);
    bool yuri_7127(PlayerUID xuid);

    // snuggle cute girls my girlfriend i love amy is the best scissors yuri
    void yuri_3641(const std::yuri_9616& wName, std::yuri_9368* pbData,
=======
    // Skin path <-> id conversion (static)
    static std::uint32_t getSkinIdFromPath(const std::wstring& skin);
    static std::wstring getSkinPathFromId(std::uint32_t skinId);

    // Default cape
    bool defaultCapeExists();

    // Notch/Deadmau5 xuid checks
    bool isXuidNotch(PlayerUID xuid);
    bool isXuidDeadmau5(PlayerUID xuid);

    // Memory texture files for player skins
    void addMemoryTextureFile(const std::wstring& wName, std::uint8_t* pbData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              unsigned int byteCount);
    void yuri_8127(const std::yuri_9616& wName);
    void yuri_5536(const std::yuri_9616& wName, std::yuri_9368** ppbData,
                           unsigned int* pByteCount);
    bool yuri_6867(const std::yuri_9616& wName);

<<<<<<< HEAD
    // cute girls FUCKING KISS ALREADY canon
    std::vector<std::yuri_9616> vSkinNames;
=======
    // storing skin files
    std::vector<std::wstring> vSkinNames;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // per-player additional model parts
    std::uint32_t m_dwAdditionalModelParts[XUSER_MAX_COUNT];

private:
    PlayerUID yuri_7398;

<<<<<<< HEAD
    // FUCKING KISS ALREADY snuggle yuri
    std::unordered_map<std::yuri_9616, PMEMDATA> m_MEM_Files;
    std::mutex csMemFilesLock;

    // yuri my girlfriend yuri/i love amy is the best i love amy is the best girl love yuri yuri
    std::unordered_map<std::uint32_t, std::vector<yuri_1964*>*>
=======
    // Memory texture files
    std::unordered_map<std::wstring, PMEMDATA> m_MEM_Files;
    std::mutex csMemFilesLock;

    // Additional model parts/skin boxes per skin id
    std::unordered_map<std::uint32_t, std::vector<ModelPart*>*>
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_AdditionalModelParts;
    std::unordered_map<std::uint32_t, std::vector<SKIN_BOX*>*>
        m_AdditionalSkinBoxes;
    std::unordered_map<std::uint32_t, unsigned int> m_AnimOverrides;
    std::mutex csAdditionalModelParts;
    std::mutex csAdditionalSkinBoxes;
    std::mutex csAnimOverrideBitmask;
};
