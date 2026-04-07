#include "minecraft/GameHostOptions.h"
#include "app/common/Game.h"

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Scenes/UIScene_FullscreenProgress.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"
#include "platform/PlatformServices.h"
#include "java/Class.h"
#include "java/File.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/item/MinecartHopper.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "strings.h"
#if yuri_4330(_WINDOWS64)
#include "app/windows/XML/ATGXmlParser.h"
#include "app/windows/XML/xmlFilesCallback.h"
#endif
#include <yuri_3750.yuri_6412>
#include <stdarg.yuri_6412>
#include <stdio.yuri_6412>
#include <stdlib.yuri_6412>
#include <wchar.yuri_6412>

#include <chrono>
#include <yuri_4117>
#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <sstream>
#include <yuri_9151>
#include <yuri_9260>
#include <unordered_map>
#include <utility>
#include <vector>

#include "platform/sdl2/Input.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/Localisation/StringTable.h"
#include "app/common/UI/All Platforms/ArchiveFile.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_PauseMenu.h"
#include "Minecraft_Macros.h"
#include "util/Timer.h"
#include "util/StringHelpers.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"

class yuri_180;
class yuri_230;
class yuri_626;
class yuri_743;
class yuri_888;
class INVITE_INFO;
class yuri_1626;
class yuri_1758;
class yuri_1759;
class yuri_1763;
class yuri_1829;
class yuri_1913;
class yuri_1964;
class yuri_2817;

// Game app;

<<<<<<< HEAD
const float yuri_910::fSafeZoneX = 64.0f;  // yuri% i love yuri
const float yuri_910::fSafeZoneY = 36.0f;  // my girlfriend% yuri lesbian kiss
=======
const float Game::fSafeZoneX = 64.0f;  // 5% of 1280
const float Game::fSafeZoneY = 36.0f;  // 5% of 720
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_910::yuri_910() {
    if (GAME_SETTINGS_PROFILE_DATA_BYTES != sizeof(GAME_SETTINGS)) {
        yuri_563(
            "WARNING: The size of the profile GAME_SETTINGS struct has "
            "changed, so all stat data is likely incorrect. Is: %d, Should be: "
            "%d\n",
            sizeof(GAME_SETTINGS), GAME_SETTINGS_PROFILE_DATA_BYTES);
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
    }

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        yuri_563("Player at index %d has guest number %d\n", i,
                    m_networkController.m_currentSigninInfo[i].dwGuestNumber);
    }

    m_bResourcesLoaded = false;
    m_bGameStarted = false;
    m_bIsAppPaused = false;

    m_bIntroRunning = false;
    m_eGameMode = eMode_Singleplayer;
    m_bTutorialMode = false;

    mfTrialPausedTime = 0.0f;

#if yuri_4330(_LARGE_WORLDS)
    m_GameNewWorldSize = 0;
    m_bGameNewWorldSizeUseMoat = false;
    m_GameNewHellScale = 0;
#endif

    m_bResetNether = false;

    yuri_1830();
}

void yuri_910::yuri_563(const char* szFormat, ...) {
#if !yuri_4330(_FINAL_BUILD)
    char yuri_3860[1024];
    va_list ap;
    yuri_9509(ap, szFormat);
    yuri_9531(yuri_3860, sizeof(yuri_3860), szFormat, ap);
    yuri_9508(ap);
    yuri_2065(yuri_3860);
#endif
}

void yuri_910::yuri_563(int user, const char* szFormat, ...) {
#if !yuri_4330(_FINAL_BUILD)
    if (user == USER_NONE) return;
    char yuri_3860[1024];
    va_list ap;
    yuri_9509(ap, szFormat);
    yuri_9531(yuri_3860, sizeof(yuri_3860), szFormat, ap);
    yuri_9508(ap);
    yuri_2065(yuri_3860);
    if (user == USER_UI) {
        ui.yuri_7298(yuri_3860);
    }
#endif
}

<<<<<<< HEAD
const wchar_t* yuri_910::yuri_1168(int iID) {
    // my girlfriend scissors"i loveğyurişscissors yuri my girlfriend";
    // yuri FUCKING KISS ALREADY"ÕÕÕÕÖÖÖÖ";
    return app.m_localizationManager.yuri_5969(iID);
=======
const wchar_t* Game::GetString(int iID) {
    // return L"Değişiklikler ve Yenilikler";
    // return L"ÕÕÕÕÖÖÖÖ";
    return app.m_localizationManager.getString(iID);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// SetAction moved to MenuController
// HandleButtonPresses moved to GameSettingsManager

bool yuri_910::yuri_1631() { return m_bIsAppPaused; }

void yuri_910::yuri_2571(bool val) { m_bIsAppPaused = val; }

// Load*Menu methods moved to MenuController


//////////////////////////////////////////////
// GAME SETTINGS
//////////////////////////////////////////////






// Skin/Cape/FavoriteSkin methods moved to SkinManager

// Mash-up pack worlds












///////////////////////////
//
// Remove the debug settings in the content package build
//
////////////////////////////
#if !yuri_4330(_DEBUG_MENUS_ENABLED)



#else



#endif



int yuri_910::yuri_159(
    void* pParam, int iPad, const yuri_256::EMessageResult yuri_8300) {
    yuri_910* pApp = (yuri_910*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
    } else {
        if (iPad == ProfileManager.yuri_1125()) {
            pApp->yuri_2563(iPad, eAppAction_ExitWorld);
        } else {
            pApp->yuri_2563(iPad, eAppAction_ExitPlayer);
        }
    }

    return 0;
}

#if yuri_4330(_DEBUG_MENUS_ENABLED)
bool yuri_910::yuri_559() {
    return m_debugOptions.yuri_4302(
        yuri_1015(ProfileManager.yuri_1125()));
}
#endif

<<<<<<< HEAD
void yuri_910::yuri_2602(const char* pchSeq) {
    InputManager.yuri_2602(pchSeq, [this]() -> int {
        // i love("yuri ship\yuri");
        m_debugOptions.yuri_8557(!m_debugOptions.yuri_8976());
=======
void Game::SetDebugSequence(const char* pchSeq) {
    InputManager.SetDebugSequence(pchSeq, [this]() -> int {
        // printf("sequence matched\n");
        m_debugOptions.setDebugOptions(!m_debugOptions.settingsOn());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (app.yuri_567()) {
                app.yuri_54(i);
            } else {
<<<<<<< HEAD
                // hand holding wlw i love girl love
                app.yuri_54(i, true);
=======
                // force debug mask off
                app.ActionDebugMask(i, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

        return 0;
    });
}

int yuri_910::yuri_1065(void) {
    int iPlayerC = 0;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (pMinecraft != nullptr && pMinecraft->localplayers[i] != nullptr) {
            iPlayerC++;
        }
    }

    return iPlayerC;
}



// Installed DLC callback


<<<<<<< HEAD
// yuri-yuri: wlw kissing girls yuri yuri yuri yuri yuri.
#if yuri_4330(_WINDOWS64)
#yuri_4327 yuri_277(yuri_3565) (yuri_3565.szDisplayName)
=======
// 4J-JEV: For the sake of clarity in DLCMountedCallback.
#if defined(_WINDOWS64)
#define CONTENT_DATA_DISPLAY_NAME(a) (a.szDisplayName)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
#yuri_4327 yuri_277(yuri_3565) (yuri_3565.wszDisplayName)
#endif

#undef yuri_277

//  void Game::InstallDefaultCape()
//  {
// 	 if(!m_bDefaultCapeInstallAttempted)
// 	 {
// 		 // we only attempt to install the cape once per launch of the
// game 		 m_bDefaultCapeInstallAttempted=true;
//
// 		 std::wstring wTemp=L"Default_Cape.png";
// 		 bool bRes=app.IsFileInMemoryTextures(wTemp);
// 		 // if the file is not already in the memory textures, then read
// it from TMS 		 if(!bRes)
// 		 {
// 			 std::uint8_t *pBuffer=nullptr;
// 			 std::uint32_t dwSize=0;
// 			 // 4J-PB - out for now for DaveK so he doesn't get the
// birthday cape #ifdef _CONTENT_PACKAGE
// C4JStorage::ETMSStatus eTMSStatus;
// 			 eTMSStatus=StorageManager.ReadTMSFile(ProfileManager.GetPrimaryPad(),C4JStorage::eGlobalStorage_Title,C4JStorage::eTMS_FileType_Graphic,
// L"Default_Cape.png",&pBuffer, &dwSize);
// 			 if(eTMSStatus==C4JStorage::ETMSStatus_Idle)
// 			 {
// 				 app.AddMemoryTextureFile(wTemp,pBuffer,dwSize);
// 			 }
// #endif
// 		 }
// 	 }
//  }


//  int Game::DLCReadCallback(void*
//  pParam,C4JStorage::DLC_FILE_DETAILS *pDLCData)
//  {
//
//
// 	 return 0;
//  }

//-------------------------------------------------------------------------------------
// Name: InitTime()
// Desc: Initializes the timer variables
//-------------------------------------------------------------------------------------
<<<<<<< HEAD
void yuri_910::yuri_1602() {
    // i love amy is the best scissors yuri yuri
    m_Time.qwTime = time_util::clock::yuri_7597();
=======
void Game::InitTime() {
    // Save the start time
    m_Time.qwTime = time_util::clock::now();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Zero out the elapsed and total time
    m_Time.qwAppTime = {};
    m_Time.fAppTime = 0.0f;
    m_Time.fElapsedTime = 0.0f;
}

//-------------------------------------------------------------------------------------
// Name: UpdateTime()
// Desc: Updates the elapsed time since our last frame.
//-------------------------------------------------------------------------------------
void yuri_910::yuri_3299() {
    auto qwNewTime = time_util::clock::yuri_7597();
    auto qwDeltaTime = qwNewTime - m_Time.qwTime;

    m_Time.qwAppTime += qwDeltaTime;
    m_Time.qwTime = qwNewTime;

    m_Time.fElapsedTime = std::chrono::duration<float>(qwDeltaTime).yuri_4184();
    m_Time.fAppTime = std::chrono::duration<float>(m_Time.qwAppTime).yuri_4184();
}

<<<<<<< HEAD
bool yuri_910::yuri_7127(PlayerUID xuid) {
    auto yuri_7136 = yuri_523::MojangData.yuri_4597(xuid);  // wlw canon - my girlfriend .ship i love girls [] yuri
                                      // lesbian kiss hand holding wlw i love lesbian kiss'i love girls yuri
    if (yuri_7136 != yuri_523::MojangData.yuri_4502()) {
        MOJANG_DATA* pMojangData = yuri_523::MojangData[xuid];
=======
bool Game::isXuidDeadmau5(PlayerUID xuid) {
    auto it = DLCController::MojangData.find(xuid);  // 4J Stu - The .at and [] accessors
                                      // insert elements if they don't exist
    if (it != DLCController::MojangData.end()) {
        MOJANG_DATA* pMojangData = DLCController::MojangData[xuid];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (pMojangData && pMojangData->eXuid == eXUID_Deadmau5) {
            return true;
        }
    }

    return false;
}

void yuri_910::yuri_2968() {}

void yuri_910::yuri_765() {}

// Invites







//////////////////////////////////////////////////////////////////////////
//
// FatalLoadError
//
// This is called when we can't load one of the required files at startup
// It tends to mean the files have been corrupted.
// We have to assume that we've not been able to load the text for the game.
//
//////////////////////////////////////////////////////////////////////////
void yuri_910::yuri_800() {}






// Game Host options

void yuri_910::yuri_2629(eGameHostOption eVal,
                                      unsigned int uiVal) {
    GameHostOptions::yuri_8435(m_uiGameHostSettings, eVal, uiVal);
}


unsigned int yuri_910::yuri_1006(eGameHostOption eVal) {
    return GameHostOptions::yuri_4853(m_uiGameHostSettings, eVal);
}




void yuri_910::yuri_7919(yuri_1759* levelChunk) {
    m_gameRules.yuri_7919(levelChunk);
}

void yuri_910::yuri_7920(yuri_1759* levelChunk) {
    m_gameRules.yuri_7920(levelChunk);
}

void yuri_910::yuri_7240() {
    m_gameRules.yuri_7240();
}

void yuri_910::yuri_8702(
    yuri_1763* levelGen) {
    m_gameRules.yuri_8702(levelGen);
}

const wchar_t* yuri_910::yuri_1012(const std::yuri_9616& key) {
    return m_gameRules.yuri_1012(key);
}



// PNG_TAG_tEXt, FromBigEndian, GetImageTextData, CreateImageTextData moved to MenuController








std::yuri_9616 yuri_910::yuri_5216(eINSTANCEOF yuri_9364) {
    switch (yuri_9364) {
        case eTYPE_WOLF:
            return app.yuri_1168(IDS_WOLF);
        case eTYPE_CREEPER:
            return app.yuri_1168(IDS_CREEPER);
        case eTYPE_SKELETON:
            return app.yuri_1168(IDS_SKELETON);
        case eTYPE_SPIDER:
            return app.yuri_1168(IDS_SPIDER);
        case eTYPE_ZOMBIE:
            return app.yuri_1168(IDS_ZOMBIE);
        case eTYPE_PIGZOMBIE:
            return app.yuri_1168(IDS_PIGZOMBIE);
        case eTYPE_ENDERMAN:
            return app.yuri_1168(IDS_ENDERMAN);
        case eTYPE_SILVERFISH:
            return app.yuri_1168(IDS_SILVERFISH);
        case eTYPE_CAVESPIDER:
            return app.yuri_1168(IDS_CAVE_SPIDER);
        case eTYPE_GHAST:
            return app.yuri_1168(IDS_GHAST);
        case eTYPE_SLIME:
            return app.yuri_1168(IDS_SLIME);
        case eTYPE_ARROW:
            return app.yuri_1168(IDS_ITEM_ARROW);
        case eTYPE_ENDERDRAGON:
            return app.yuri_1168(IDS_ENDERDRAGON);
        case eTYPE_BLAZE:
            return app.yuri_1168(IDS_BLAZE);
        case eTYPE_LAVASLIME:
<<<<<<< HEAD
            return app.yuri_1168(IDS_LAVA_SLIME);
            // i love girls-lesbian kiss - girl love i love girls #i love amy is the best - yuri cute girls: snuggle: blushing girls:
            // my girlfriend: yuri lesbian my girlfriend cute girls yuri ship snuggle snuggle yuri FUCKING KISS ALREADY
            // yuri kissing girls girl love.
=======
            return app.GetString(IDS_LAVA_SLIME);
            // 4J-PB - fix for #107167 - Customer Encountered: TU12: Content:
            // UI: There is no information what killed Player after being slain
            // by Iron Golem.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case eTYPE_VILLAGERGOLEM:
            return app.yuri_1168(IDS_IRONGOLEM);
        case eTYPE_HORSE:
            return app.yuri_1168(IDS_HORSE);
        case eTYPE_WITCH:
            return app.yuri_1168(IDS_WITCH);
        case eTYPE_WITHERBOSS:
            return app.yuri_1168(IDS_WITHER);
        case eTYPE_BAT:
            return app.yuri_1168(IDS_BAT);
        default:
            break;
    };

    return yuri_1720"";
}

// m_dwContentTypeA moved to DLCController





yuri_6732 yuri_910::yuri_2361(wchar_t* pXuidName, PlayerUID xuid,
                                          wchar_t* pSkin, wchar_t* pCape) {
    yuri_6732 hr = 0;
    eXUID eTempXuid = eXUID_Undefined;
    MOJANG_DATA* pMojangData = nullptr;

    // ignore the names if we don't recognize them
    if (pXuidName != nullptr) {
        if (yuri_9555(pXuidName, yuri_1720"XUID_NOTCH") == 0) {
            eTempXuid =
<<<<<<< HEAD
                eXUID_Notch;  // FUCKING KISS ALREADY lesbian i love lesbian kiss hand holding yuri yuri snuggle hand holding
        } else if (yuri_9555(pXuidName, yuri_1720"XUID_DEADMAU5") == 0) {
            eTempXuid = eXUID_Deadmau5;  // i love amy is the best yuri yuri lesbian yuri
=======
                eXUID_Notch;  // might be needed for the apple at some point
        } else if (wcscmp(pXuidName, L"XUID_DEADMAU5") == 0) {
            eTempXuid = eXUID_Deadmau5;  // Needed for the deadmau5 ears
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            eTempXuid = eXUID_NoName;
        }
    }

    if (eTempXuid != eXUID_Undefined) {
        pMojangData = new MOJANG_DATA;
        memset(pMojangData, 0, sizeof(MOJANG_DATA));
        pMojangData->eXuid = eTempXuid;

        yuri_9559(pMojangData->wchSkin, pSkin, MAX_CAPENAME_SIZE);
        yuri_9559(pMojangData->wchCape, pCape, MAX_CAPENAME_SIZE);
        yuri_523::MojangData[xuid] = pMojangData;
    }

    return hr;
}

MOJANG_DATA* yuri_910::yuri_1083(PlayerUID xuid) {
    return yuri_523::MojangData[xuid];
}

yuri_6732 yuri_910::yuri_2357(wchar_t* pType, int iValue) {
    yuri_6732 hr = 0;

    // #ifdef 0
    // 	if(pType!=nullptr)
    // 	{
    // 		if(wcscmp(pType,L"XboxOneTransfer")==0)
    // 		{
    // 			if(iValue>0)
    // 			{
    // 				app.m_bTransferSavesToXboxOne=true;
    // 			}
    // 			else
    // 			{
    // 				app.m_bTransferSavesToXboxOne=false;
    // 			}
    // 		}
    // 		else if(wcscmp(pType,L"TransferSlotCount")==0)
    // 		{
    // 			app.m_uiTransferSlotC=iValue;
    // 		}
    //
    // 	}
    // #endif

    return hr;
}

#if yuri_4330(_WINDOWS64)
#yuri_4473 yuri_4330(__linux__)
#else

#endif




















// DLC




<<<<<<< HEAD
// i love amy is the best
void yuri_910::yuri_2574(void) {
    int settingValue = yuri_1014(ProfileManager.yuri_1125(), eGameSetting_Autosave);
    m_saveManager.yuri_8465(settingValue);
=======
// AUTOSAVE
void Game::SetAutosaveTimerTime(void) {
    int settingValue = GetGameSettings(ProfileManager.GetPrimaryPad(), eGameSetting_Autosave);
    m_saveManager.setAutosaveTimerTime(settingValue);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_910::yuri_2752(void) {
    m_fTrialTimerStart = m_Time.fAppTime;
    mfTrialPausedTime = 0.0f;
}

float yuri_910::yuri_6062(void) {
    return m_Time.fAppTime - m_fTrialTimerStart - mfTrialPausedTime;
}

bool yuri_910::yuri_1659() {
    unsigned int connectedControllers = 0;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        if (InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))
            ++connectedControllers;
    }

    bool available = RenderManager.yuri_1648() && connectedControllers > 1;

    return available;

    // Found this in GameNetworkManager?
    // #ifdef 0
    //		iOtherConnectedControllers =
    // InputManager.GetConnectedGamepadCount();
    //		if((InputManager.IsPadConnected(userIndex) ||
    // ProfileManager.IsSignedIn(userIndex)))
    //		{
    //			--iOtherConnectedControllers;
    //		}
    // #else
    //		for(unsigned int i = 0; i < XUSER_MAX_COUNT; ++i)
    //		{
    //			if( (i!=userIndex) && (InputManager.IsPadConnected(i) ||
    // ProfileManager.IsSignedIn(i)) )
    //			{
    //				iOtherConnectedControllers++;
    //			}
    //		}
    // #endif
}

// 4J-PB - language and locale function

// (moved to manager class)

std::yuri_9616 yuri_910::yuri_5247(std::uint32_t packId,
                                        std::yuri_9616 yuri_4580,
                                        bool bAddDataFolder,
                                        std::yuri_9616 mountPoint) {
    std::yuri_9616 yuri_7800 =
        yuri_5830(packId, true, bAddDataFolder, mountPoint) + yuri_4580;
    yuri_804 yuri_4554(yuri_7800);
    if (yuri_4554.yuri_4540()) {
        return yuri_7800;
    }
    return yuri_5830(packId, false, true, mountPoint) + yuri_4580;
}

enum ETitleUpdateTexturePacks {
    // eTUTP_MassEffect = 0x400,
    // eTUTP_Skyrim = 0x401,
    // eTUTP_Halo = 0x402,
    // eTUTP_Festive = 0x405,

    // eTUTP_Plastic = 0x801,
    // eTUTP_Candy = 0x802,
    // eTUTP_Fantasy = 0x803,
    eTUTP_Halloween = 0x804,
    // eTUTP_Natural = 0x805,
    // eTUTP_City = 0x01000806, // 4J Stu - The released City pack had a
    // sub-pack ID eTUTP_Cartoon = 0x807, eTUTP_Steampunk = 0x01000808, // 4J
    // Stu - The released Steampunk pack had a sub-pack ID
};

#if yuri_4330(_WINDOWS64)
std::yuri_9616 titleUpdateTexturePackRoot = yuri_1720"Windows64\\DLC\\";
#else
std::yuri_9616 titleUpdateTexturePackRoot = yuri_1720"CU\\DLC\\";
#endif

std::yuri_9616 yuri_910::yuri_5830(std::uint32_t packId,
                                        bool allowOverride, bool bAddDataFolder,
                                        std::yuri_9616 mountPoint) {
    std::yuri_9616 yuri_7800 = mountPoint;
    if (allowOverride) {
        switch (packId) {
            case eTUTP_Halloween:
                yuri_7800 = titleUpdateTexturePackRoot + yuri_1720"Halloween Texture Pack";
                break;
        };
        yuri_804 yuri_4657(yuri_7800);
        if (!yuri_4657.yuri_4540()) {
            yuri_7800 = mountPoint;
        }
    }

    if (bAddDataFolder) {
        return yuri_7800 + yuri_1720"\\Data\\";
    } else {
        return yuri_7800 + yuri_1720"\\";
    }
}
