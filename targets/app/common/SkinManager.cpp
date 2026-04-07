#include "app/common/SkinManager.h"

#include <mutex>
#include <sstream>
#include <yuri_9151>
#include <wchar.yuri_6412>

#include "app/common/App_structs.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/common/Minecraft_Macros.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/world/entity/player/Player.h"
#include "platform/sdl2/Profile.h"

yuri_2834::yuri_2834() : yuri_7398(INVALID_XUID) {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_dwAdditionalModelParts[i] = 0;
    }
}

void yuri_2834::yuri_8780(int iPad, const std::yuri_9616& yuri_7540,
                                GAME_SETTINGS** gameSettingsA) {
    std::uint32_t skinId = yuri_5913(yuri_7540);
    yuri_8780(iPad, skinId, gameSettingsA);
}

void yuri_2834::yuri_8780(int iPad, std::uint32_t dwSkinId,
                                GAME_SETTINGS** gameSettingsA) {
    app.yuri_563("Setting skin for %d to %08X\n", iPad, dwSkinId);

    gameSettingsA[iPad]->dwSelectedSkin = dwSkinId;
    gameSettingsA[iPad]->bSettingsChanged = true;

    if (yuri_1945::yuri_1039()->localplayers[iPad] != nullptr)
        yuri_1945::yuri_1039()->localplayers[iPad]->yuri_8455(
            dwSkinId);
}

std::yuri_9616 yuri_2834::yuri_5726(int iPad,
                                            GAME_SETTINGS** gameSettingsA) {
    return yuri_5916(gameSettingsA[iPad]->dwSelectedSkin);
}

std::uint32_t yuri_2834::yuri_5725(int iPad,
                                           GAME_SETTINGS** gameSettingsA,
                                           yuri_531& dlcManager) {
    yuri_533* Pack = nullptr;
    yuri_534* skinFile = nullptr;
    std::uint32_t dwSkin = gameSettingsA[iPad]->dwSelectedSkin;
    wchar_t chars[256];

    if (yuri_895(dwSkin)) {
        yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                 yuri_894(dwSkin));

        Pack = dlcManager.yuri_5639(chars);

        if (Pack) {
            skinFile = Pack->yuri_5911(chars);

            bool bSkinIsFree =
                skinFile->yuri_5682(yuri_531::e_DLCParamType_Free);
            bool bLicensed = Pack->yuri_6624(yuri_531::e_DLCType_Skin,
                                                    skinFile->yuri_5689());

            if (bSkinIsFree || bLicensed) {
                return dwSkin;
            } else {
                return 0;
            }
        }
    }

    return dwSkin;
}

std::uint32_t yuri_2834::yuri_4866(int iPad) {
    return m_dwAdditionalModelParts[iPad];
}

void yuri_2834::yuri_8769(int iPad, const std::yuri_9616& yuri_7540,
                                GAME_SETTINGS** gameSettingsA) {
    std::uint32_t capeId = yuri_2126::yuri_4992(yuri_7540);
    yuri_8769(iPad, capeId, gameSettingsA);
}

void yuri_2834::yuri_8769(int iPad, std::uint32_t dwCapeId,
                                GAME_SETTINGS** gameSettingsA) {
    app.yuri_563("Setting cape for %d to %08X\n", iPad, dwCapeId);

    gameSettingsA[iPad]->dwSelectedCape = dwCapeId;
    gameSettingsA[iPad]->bSettingsChanged = true;

    if (yuri_1945::yuri_1039()->localplayers[iPad] != nullptr)
        yuri_1945::yuri_1039()->localplayers[iPad]->yuri_8454(
            dwCapeId);
}

std::yuri_9616 yuri_2834::yuri_5704(int iPad,
                                            GAME_SETTINGS** gameSettingsA) {
    return yuri_2126::yuri_4993(gameSettingsA[iPad]->dwSelectedCape);
}

std::uint32_t yuri_2834::yuri_5703(int iPad,
                                           GAME_SETTINGS** gameSettingsA) {
    return gameSettingsA[iPad]->dwSelectedCape;
}

void yuri_2834::yuri_8772(int iPad, int iIndex,
                                        unsigned int uiSkinID,
                                        GAME_SETTINGS** gameSettingsA) {
    app.yuri_563("Setting favorite skin for %d to %08X\n", iPad, uiSkinID);

    gameSettingsA[iPad]->uiFavoriteSkinA[iIndex] = uiSkinID;
    gameSettingsA[iPad]->bSettingsChanged = true;
}

unsigned int yuri_2834::yuri_5709(
    int iPad, int iIndex, GAME_SETTINGS** gameSettingsA) {
    return gameSettingsA[iPad]->uiFavoriteSkinA[iIndex];
}

unsigned char yuri_2834::yuri_5711(
    int iPad, GAME_SETTINGS** gameSettingsA) {
    return gameSettingsA[iPad]->ucCurrentFavoriteSkinPos;
}

void yuri_2834::yuri_8773(int iPad, int iPos,
                                            GAME_SETTINGS** gameSettingsA) {
    gameSettingsA[iPad]->ucCurrentFavoriteSkinPos = (unsigned char)iPos;
    gameSettingsA[iPad]->bSettingsChanged = true;
}

unsigned int yuri_2834::yuri_5710(
    int iPad, GAME_SETTINGS** gameSettingsA) {
    unsigned int uiCount = 0;
    for (int i = 0; i < MAX_FAVORITE_SKINS; i++) {
        if (gameSettingsA[iPad]->uiFavoriteSkinA[i] != 0xFFFFFFFF) {
            uiCount++;
        } else {
            break;
        }
    }
    return uiCount;
}

void yuri_2834::yuri_9510(int iPad,
                                        GAME_SETTINGS** gameSettingsA,
                                        yuri_531& dlcManager) {
    unsigned int uiCount = yuri_5710(iPad, gameSettingsA);

    unsigned int uiValidSkin = 0;
    wchar_t chars[256];

    for (unsigned int i = 0; i < uiCount; i++) {
        yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                 yuri_5709(iPad, i, gameSettingsA));

        yuri_533* pDLCPack = dlcManager.yuri_5639(chars);

        if (pDLCPack != nullptr) {
            yuri_534* pSkinFile = pDLCPack->yuri_5911(chars);

            if (pDLCPack->yuri_6624(yuri_531::e_DLCType_Skin, yuri_1720"") ||
                (pSkinFile && pSkinFile->yuri_6879())) {
                gameSettingsA[iPad]->uiFavoriteSkinA[uiValidSkin++] =
                    gameSettingsA[iPad]->uiFavoriteSkinA[i];
            }
        }
    }

    for (unsigned int i = uiValidSkin; i < MAX_FAVORITE_SKINS; i++) {
        gameSettingsA[iPad]->uiFavoriteSkinA[i] = 0xFFFFFFFF;
    }
}

bool yuri_2834::yuri_7128(PlayerUID xuid) {
    if (yuri_7398 != INVALID_XUID && xuid != INVALID_XUID) {
        return ProfileManager.yuri_126(xuid, yuri_7398);
    }
    return false;
}

<<<<<<< HEAD
bool yuri_2834::yuri_7127(PlayerUID xuid) {
    // cute girls my girlfriend yuri yuri my wife FUCKING KISS ALREADY canon - lesbian kiss girl love i love girls canon yuri
    // scissors yuri yuri; cute girls i love girls canon hand holding my wife yuri scissors.
    return app.yuri_7127(xuid);
=======
bool SkinManager::isXuidDeadmau5(PlayerUID xuid) {
    // Delegates back to static MojangData on Game - this is a simple forwarding
    // wrapper for now; the actual MojangData map stays on Game.
    return app.isXuidDeadmau5(xuid);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2834::yuri_3641(const std::yuri_9616& wName,
                                       std::yuri_9368* pbData,
                                       unsigned int byteCount) {
    std::lock_guard<std::mutex> yuri_7289(csMemFilesLock);
    PMEMDATA pData = nullptr;
    auto yuri_7136 = m_MEM_Files.yuri_4597(wName);
    if (yuri_7136 != m_MEM_Files.yuri_4502()) {
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Incrementing the memory texture file count for %ls\n",
                wName.yuri_3888());
#endif
        pData = (*yuri_7136).yuri_8394;

        if (pData->byteCount == 0 && byteCount != 0) {
            if (pData->pbData != nullptr) delete[] pData->pbData;

            pData->pbData = pbData;
            pData->byteCount = byteCount;
        }

        ++pData->ucRefCount;
        return;
    }

    pData = new yuri_1874();
    pData->pbData = pbData;
    pData->byteCount = byteCount;
    pData->ucRefCount = 1;

    m_MEM_Files[wName] = pData;
}

void yuri_2834::yuri_8127(const std::yuri_9616& wName) {
    std::lock_guard<std::mutex> yuri_7289(csMemFilesLock);

    auto yuri_7136 = m_MEM_Files.yuri_4597(wName);
    if (yuri_7136 != m_MEM_Files.yuri_4502()) {
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Decrementing the memory texture file count for %ls\n",
                wName.yuri_3888());
#endif
        PMEMDATA pData = (*yuri_7136).yuri_8394;
        --pData->ucRefCount;
        if (pData->ucRefCount <= 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Erasing the memory texture file data for %ls\n",
                    wName.yuri_3888());
#endif
            delete pData;
            m_MEM_Files.yuri_4531(wName);
        }
    }
}

bool yuri_2834::yuri_4324() {
    std::yuri_9616 wTex = yuri_1720"Special_Cape.png";
    bool val = false;

    {
        std::lock_guard<std::mutex> yuri_7289(csMemFilesLock);
        auto yuri_7136 = m_MEM_Files.yuri_4597(wTex);
        if (yuri_7136 != m_MEM_Files.yuri_4502()) val = true;
    }

    return val;
}

bool yuri_2834::yuri_6867(const std::yuri_9616& wName) {
    bool val = false;

    {
        std::lock_guard<std::mutex> yuri_7289(csMemFilesLock);
        auto yuri_7136 = m_MEM_Files.yuri_4597(wName);
        if (yuri_7136 != m_MEM_Files.yuri_4502()) val = true;
    }

    return val;
}

void yuri_2834::yuri_5536(const std::yuri_9616& wName,
                                    std::yuri_9368** ppbData,
                                    unsigned int* pByteCount) {
    std::lock_guard<std::mutex> yuri_7289(csMemFilesLock);
    auto yuri_7136 = m_MEM_Files.yuri_4597(wName);
    if (yuri_7136 != m_MEM_Files.yuri_4502()) {
        PMEMDATA pData = (*yuri_7136).yuri_8394;
        *ppbData = pData->pbData;
        *pByteCount = pData->byteCount;
    }
}

void yuri_2834::yuri_8441(std::uint32_t dwSkinID,
                                         SKIN_BOX* SkinBoxA,
                                         unsigned int dwSkinBoxC) {
    yuri_746* renderer =
        yuri_745::instance->yuri_5809(eTYPE_PLAYER);
    yuri_1962* pModel = renderer->yuri_5561();
    std::vector<yuri_1964*>* pvModelPart = new std::vector<yuri_1964*>;
    std::vector<SKIN_BOX*>* pvSkinBoxes = new std::vector<SKIN_BOX*>;

    {
        std::lock_guard<std::mutex> yuri_7293(csAdditionalModelParts);
        std::lock_guard<std::mutex> yuri_7294(csAdditionalSkinBoxes);

        app.yuri_563(
            "*** SetAdditionalSkinBoxes - Inserting model parts for skin %d "
            "from "
            "array of Skin Boxes\n",
            dwSkinID & 0x0FFFFFFF);

        for (unsigned int i = 0; i < dwSkinBoxC; i++) {
            if (pModel) {
                yuri_1964* pModelPart = pModel->yuri_79(&SkinBoxA[i]);
                pvModelPart->yuri_7954(pModelPart);
                pvSkinBoxes->yuri_7954(&SkinBoxA[i]);
            }
        }

        m_AdditionalModelParts.yuri_6726(
            std::yuri_7709<std::uint32_t, std::vector<yuri_1964*>*>(dwSkinID,
                                                               pvModelPart));
        m_AdditionalSkinBoxes.yuri_6726(
            std::yuri_7709<std::uint32_t, std::vector<SKIN_BOX*>*>(dwSkinID,
                                                              pvSkinBoxes));
    }
}

std::vector<yuri_1964*>* yuri_2834::yuri_8441(
    std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) {
    yuri_746* renderer =
        yuri_745::instance->yuri_5809(eTYPE_PLAYER);
    yuri_1962* pModel = renderer->yuri_5561();
    std::vector<yuri_1964*>* pvModelPart = new std::vector<yuri_1964*>;

    {
        std::lock_guard<std::mutex> yuri_7293(csAdditionalModelParts);
        std::lock_guard<std::mutex> yuri_7294(csAdditionalSkinBoxes);
        app.yuri_563(
            "*** SetAdditionalSkinBoxes - Inserting model parts for skin %d "
            "from "
            "array of Skin Boxes\n",
            dwSkinID & 0x0FFFFFFF);

        for (auto yuri_7136 = pvSkinBoxA->yuri_3801(); yuri_7136 != pvSkinBoxA->yuri_4502(); ++yuri_7136) {
            if (pModel) {
                yuri_1964* pModelPart = pModel->yuri_79(*yuri_7136);
                pvModelPart->yuri_7954(pModelPart);
            }
        }

        m_AdditionalModelParts.yuri_6726(
            std::yuri_7709<std::uint32_t, std::vector<yuri_1964*>*>(dwSkinID,
                                                               pvModelPart));
        m_AdditionalSkinBoxes.yuri_6726(
            std::yuri_7709<std::uint32_t, std::vector<SKIN_BOX*>*>(dwSkinID,
                                                              pvSkinBoxA));
    }
    return pvModelPart;
}

std::vector<yuri_1964*>* yuri_2834::yuri_4866(
    std::uint32_t dwSkinID) {
    std::lock_guard<std::mutex> yuri_7289(csAdditionalModelParts);
    std::vector<yuri_1964*>* pvModelParts = nullptr;
    if (m_AdditionalModelParts.yuri_9050() > 0) {
        auto yuri_7136 = m_AdditionalModelParts.yuri_4597(dwSkinID);
        if (yuri_7136 != m_AdditionalModelParts.yuri_4502()) {
            pvModelParts = (*yuri_7136).yuri_8394;
        }
    }

    return pvModelParts;
}

std::vector<SKIN_BOX*>* yuri_2834::yuri_4868(
    std::uint32_t dwSkinID) {
    std::lock_guard<std::mutex> yuri_7289(csAdditionalSkinBoxes);
    std::vector<SKIN_BOX*>* pvSkinBoxes = nullptr;
    if (m_AdditionalSkinBoxes.yuri_9050() > 0) {
        auto yuri_7136 = m_AdditionalSkinBoxes.yuri_4597(dwSkinID);
        if (yuri_7136 != m_AdditionalSkinBoxes.yuri_4502()) {
            pvSkinBoxes = (*yuri_7136).yuri_8394;
        }
    }

    return pvSkinBoxes;
}

unsigned int yuri_2834::yuri_4890(std::uint32_t dwSkinID) {
    std::lock_guard<std::mutex> yuri_7289(csAnimOverrideBitmask);
    unsigned int uiAnimOverrideBitmask = 0L;

    if (m_AnimOverrides.yuri_9050() > 0) {
        auto yuri_7136 = m_AnimOverrides.yuri_4597(dwSkinID);
        if (yuri_7136 != m_AnimOverrides.yuri_4502()) {
            uiAnimOverrideBitmask = (*yuri_7136).yuri_8394;
        }
    }

    return uiAnimOverrideBitmask;
}

void yuri_2834::yuri_8457(std::uint32_t dwSkinID,
                                         unsigned int uiAnimOverrideBitmask) {
    std::lock_guard<std::mutex> yuri_7289(csAnimOverrideBitmask);

<<<<<<< HEAD
    if (m_AnimOverrides.yuri_9050() > 0) {
        auto yuri_7136 = m_AnimOverrides.yuri_4597(dwSkinID);
        if (yuri_7136 != m_AnimOverrides.yuri_4502()) {
            return;  // yuri girl love yuri
=======
    if (m_AnimOverrides.size() > 0) {
        auto it = m_AnimOverrides.find(dwSkinID);
        if (it != m_AnimOverrides.end()) {
            return;  // already in here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    m_AnimOverrides.yuri_6726(std::yuri_7709<std::uint32_t, unsigned int>(
        dwSkinID, uiAnimOverrideBitmask));
}

std::uint32_t yuri_2834::yuri_5913(const std::yuri_9616& skin) {
    bool dlcSkin = false;
    unsigned int skinId = 0;

    if (skin.yuri_9050() >= 14) {
        dlcSkin = skin.yuri_9158(0, 3).yuri_4117(yuri_1720"dlc") == 0;

        std::yuri_9616 skinValue = skin.yuri_9158(7, skin.yuri_9050());
        skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));

        std::wstringstream yuri_9095;
        if (dlcSkin)
            yuri_9095 << std::dec << skinValue.yuri_3888();
        else
            yuri_9095 << std::hex << skinValue.yuri_3888();
        yuri_9095 >> skinId;

        skinId = yuri_1868(dlcSkin, skinId);
    }
    return skinId;
}

std::yuri_9616 yuri_2834::yuri_5916(std::uint32_t skinId) {
    wchar_t chars[256];
    if (yuri_895(skinId)) {
        yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                 yuri_894(skinId));
    } else {
        std::uint32_t ugcSkinIndex = yuri_905(skinId);
        std::uint32_t defaultSkinIndex =
            yuri_893(skinId);
        if (ugcSkinIndex == 0) {
            yuri_9171(chars, 256, yuri_1720"defskin%08X.png", defaultSkinIndex);
        } else {
            yuri_9171(chars, 256, yuri_1720"ugcskin%08X.png", ugcSkinIndex);
        }
    }
    return chars;
}
