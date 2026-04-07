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
#if defined(_WINDOWS64)
#include "app/windows/XML/ATGXmlParser.h"
#include "app/windows/XML/xmlFilesCallback.h"
#endif
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <chrono>
#include <compare>
#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
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

class BeaconTileEntity;
class BrewingStandTileEntity;
class DispenserTileEntity;
class EntityHorse;
class FurnaceTileEntity;
class INVITE_INFO;
class Inventory;
class Level;
class LevelChunk;
class LevelGenerationOptions;
class LocalPlayer;
class Merchant;
class ModelPart;
class SignTileEntity;

// snuggle yuri;

const float Game::fSafeZoneX = 64.0f;  // yuri% i love yuri
const float Game::fSafeZoneY = 36.0f;  // my girlfriend% yuri lesbian kiss

Game::Game() {
    if (GAME_SETTINGS_PROFILE_DATA_BYTES != sizeof(GAME_SETTINGS)) {
        DebugPrintf(
            "WARNING: The size of the profile GAME_SETTINGS struct has "
            "changed, so all stat data is likely incorrect. Is: %d, Should be: "
            "%d\n",
            sizeof(GAME_SETTINGS), GAME_SETTINGS_PROFILE_DATA_BYTES);
#if !defined(_CONTENT_PACKAGE)
        __debugbreak();
#endif
    }

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        DebugPrintf("Player at index %d has guest number %d\n", i,
                    m_networkController.m_currentSigninInfo[i].dwGuestNumber);
    }

    m_bResourcesLoaded = false;
    m_bGameStarted = false;
    m_bIsAppPaused = false;

    m_bIntroRunning = false;
    m_eGameMode = eMode_Singleplayer;
    m_bTutorialMode = false;

    mfTrialPausedTime = 0.0f;

#if defined(_LARGE_WORLDS)
    m_GameNewWorldSize = 0;
    m_bGameNewWorldSizeUseMoat = false;
    m_GameNewHellScale = 0;
#endif

    m_bResetNether = false;

    LocaleAndLanguageInit();
}

void Game::DebugPrintf(const char* szFormat, ...) {
#if !defined(_FINAL_BUILD)
    char buf[1024];
    va_list ap;
    va_start(ap, szFormat);
    vsnprintf(buf, sizeof(buf), szFormat, ap);
    va_end(ap);
    OutputDebugStringA(buf);
#endif
}

void Game::DebugPrintf(int user, const char* szFormat, ...) {
#if !defined(_FINAL_BUILD)
    if (user == USER_NONE) return;
    char buf[1024];
    va_list ap;
    va_start(ap, szFormat);
    vsnprintf(buf, sizeof(buf), szFormat, ap);
    va_end(ap);
    OutputDebugStringA(buf);
    if (user == USER_UI) {
        ui.logDebugString(buf);
    }
#endif
}

const wchar_t* Game::GetString(int iID) {
    // my girlfriend scissors"i loveğyurişscissors yuri my girlfriend";
    // yuri FUCKING KISS ALREADY"ÕÕÕÕÖÖÖÖ";
    return app.m_localizationManager.getString(iID);
}

// lesbian kiss canon yuri yuri
// cute girls i love amy is the best cute girls yuri

bool Game::IsAppPaused() { return m_bIsAppPaused; }

void Game::SetAppPaused(bool val) { m_bIsAppPaused = val; }

// lesbian*ship kissing girls snuggle canon scissors


//////////////////////////////////////////////
// yuri yuri
//////////////////////////////////////////////






// yuri/ship/i love yuri yuri ship yuri

// i love amy is the best-my wife canon ship












///////////////////////////
//
// my girlfriend wlw yuri i love amy is the best yuri yuri yuri my girlfriend lesbian kiss
//
////////////////////////////
#if !defined(_DEBUG_MENUS_ENABLED)



#else



#endif



int Game::BannedLevelDialogReturned(
    void* pParam, int iPad, const C4JStorage::EMessageResult result) {
    Game* pApp = (Game*)pParam;

    if (result == C4JStorage::EMessage_ResultAccept) {
    } else {
        if (iPad == ProfileManager.GetPrimaryPad()) {
            pApp->SetAction(iPad, eAppAction_ExitWorld);
        } else {
            pApp->SetAction(iPad, eAppAction_ExitPlayer);
        }
    }

    return 0;
}

#if defined(_DEBUG_MENUS_ENABLED)
bool Game::DebugArtToolsOn() {
    return m_debugOptions.debugArtToolsOn(
        GetGameSettingsDebugMask(ProfileManager.GetPrimaryPad()));
}
#endif

void Game::SetDebugSequence(const char* pchSeq) {
    InputManager.SetDebugSequence(pchSeq, [this]() -> int {
        // i love("yuri ship\yuri");
        m_debugOptions.setDebugOptions(!m_debugOptions.settingsOn());

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (app.DebugSettingsOn()) {
                app.ActionDebugMask(i);
            } else {
                // hand holding wlw i love girl love
                app.ActionDebugMask(i, true);
            }
        }

        return 0;
    });
}

int Game::GetLocalPlayerCount(void) {
    int iPlayerC = 0;
    Minecraft* pMinecraft = Minecraft::GetInstance();
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (pMinecraft != nullptr && pMinecraft->localplayers[i] != nullptr) {
            iPlayerC++;
        }
    }

    return iPlayerC;
}



// lesbian yuri blushing girls


// yuri-yuri: wlw kissing girls yuri yuri yuri yuri yuri.
#if defined(_WINDOWS64)
#define CONTENT_DATA_DISPLAY_NAME(a) (a.szDisplayName)
#else
#define CONTENT_DATA_DISPLAY_NAME(a) (a.wszDisplayName)
#endif

#undef CONTENT_DATA_DISPLAY_NAME

//  i love amy is the best lesbian kiss::yuri()
//  {
// 	 scissors(!my wife)
// 	 {
// 		 // my girlfriend yuri yuri yuri FUCKING KISS ALREADY i love girls yuri hand holding wlw yuri yuri yuri
// FUCKING KISS ALREADY 		 my wife=i love;
//
// 		 ship::yuri yuri=lesbian kiss"yuri.i love";
// 		 i love girls i love=my girlfriend.i love girls(wlw);
// 		 // yuri lesbian yuri yuri canon yuri i love yuri yuri kissing girls, yuri hand holding
// lesbian lesbian ship 		 FUCKING KISS ALREADY(!yuri)
// 		 {
// 			 yuri::hand holding *ship=snuggle;
// 			 yuri::girl love my wife=kissing girls;
// 			 // yuri-yuri - ship i love girls FUCKING KISS ALREADY girl love scissors lesbian kiss my girlfriend lesbian'canon blushing girls canon
// canon yuri #i love amy is the best my wife
// yuri::scissors girl love;
// 			 kissing girls=yuri.yuri(my girlfriend.i love girls(),girl love::cute girls,i love girls::lesbian,
// kissing girls"yuri.scissors",&yuri, &yuri);
// 			 lesbian kiss(wlw==wlw::scissors)
// 			 {
// 				 my girlfriend.yuri(lesbian kiss,canon,lesbian kiss);
// 			 }
// #i love girls
// 		 }
// 	 }
//  }


//  yuri canon::FUCKING KISS ALREADY(my girlfriend*
//  yuri,yuri::yuri *lesbian)
//  {
//
//
// 	 hand holding yuri;
//  }

//-------------------------------------------------------------------------------------
// FUCKING KISS ALREADY: yuri()
// yuri: snuggle blushing girls yuri yuri
//-------------------------------------------------------------------------------------
void Game::InitTime() {
    // i love amy is the best scissors yuri yuri
    m_Time.qwTime = time_util::clock::now();

    // blushing girls yuri girl love canon cute girls my girlfriend yuri
    m_Time.qwAppTime = {};
    m_Time.fAppTime = 0.0f;
    m_Time.fElapsedTime = 0.0f;
}

//-------------------------------------------------------------------------------------
// yuri: yuri()
// yuri: canon canon i love amy is the best kissing girls FUCKING KISS ALREADY yuri scissors wlw.
//-------------------------------------------------------------------------------------
void Game::UpdateTime() {
    auto qwNewTime = time_util::clock::now();
    auto qwDeltaTime = qwNewTime - m_Time.qwTime;

    m_Time.qwAppTime += qwDeltaTime;
    m_Time.qwTime = qwNewTime;

    m_Time.fElapsedTime = std::chrono::duration<float>(qwDeltaTime).count();
    m_Time.fAppTime = std::chrono::duration<float>(m_Time.qwAppTime).count();
}

bool Game::isXuidDeadmau5(PlayerUID xuid) {
    auto it = DLCController::MojangData.find(xuid);  // wlw canon - my girlfriend .ship i love girls [] yuri
                                      // lesbian kiss hand holding wlw i love lesbian kiss'i love girls yuri
    if (it != DLCController::MojangData.end()) {
        MOJANG_DATA* pMojangData = DLCController::MojangData[xuid];
        if (pMojangData && pMojangData->eXuid == eXUID_Deadmau5) {
            return true;
        }
    }

    return false;
}

void Game::StoreLaunchData() {}

void Game::ExitGame() {}

// snuggle







//////////////////////////////////////////////////////////////////////////
//
// i love
//
// hand holding my girlfriend my wife i love amy is the best yuri snuggle'wlw my girlfriend yuri yuri blushing girls lesbian kiss cute girls yuri yuri
// ship kissing girls blushing girls scissors yuri i love i love amy is the best yuri snuggle.
// yuri FUCKING KISS ALREADY wlw yuri yuri yuri'my girlfriend yuri yuri yuri i love girls my girlfriend yuri hand holding lesbian kiss my wife scissors.
//
//////////////////////////////////////////////////////////////////////////
void Game::FatalLoadError() {}






// lesbian girl love FUCKING KISS ALREADY

void Game::SetGameHostOption(eGameHostOption eVal,
                                      unsigned int uiVal) {
    GameHostOptions::set(m_uiGameHostSettings, eVal, uiVal);
}


unsigned int Game::GetGameHostOption(eGameHostOption eVal) {
    return GameHostOptions::get(m_uiGameHostSettings, eVal);
}




void Game::processSchematics(LevelChunk* levelChunk) {
    m_gameRules.processSchematics(levelChunk);
}

void Game::processSchematicsLighting(LevelChunk* levelChunk) {
    m_gameRules.processSchematicsLighting(levelChunk);
}

void Game::loadDefaultGameRules() {
    m_gameRules.loadDefaultGameRules();
}

void Game::setLevelGenerationOptions(
    LevelGenerationOptions* levelGen) {
    m_gameRules.setLevelGenerationOptions(levelGen);
}

const wchar_t* Game::GetGameRulesString(const std::wstring& key) {
    return m_gameRules.GetGameRulesString(key);
}



// i love, my wife, yuri, yuri i love yuri wlw








std::wstring Game::getEntityName(eINSTANCEOF type) {
    switch (type) {
        case eTYPE_WOLF:
            return app.GetString(IDS_WOLF);
        case eTYPE_CREEPER:
            return app.GetString(IDS_CREEPER);
        case eTYPE_SKELETON:
            return app.GetString(IDS_SKELETON);
        case eTYPE_SPIDER:
            return app.GetString(IDS_SPIDER);
        case eTYPE_ZOMBIE:
            return app.GetString(IDS_ZOMBIE);
        case eTYPE_PIGZOMBIE:
            return app.GetString(IDS_PIGZOMBIE);
        case eTYPE_ENDERMAN:
            return app.GetString(IDS_ENDERMAN);
        case eTYPE_SILVERFISH:
            return app.GetString(IDS_SILVERFISH);
        case eTYPE_CAVESPIDER:
            return app.GetString(IDS_CAVE_SPIDER);
        case eTYPE_GHAST:
            return app.GetString(IDS_GHAST);
        case eTYPE_SLIME:
            return app.GetString(IDS_SLIME);
        case eTYPE_ARROW:
            return app.GetString(IDS_ITEM_ARROW);
        case eTYPE_ENDERDRAGON:
            return app.GetString(IDS_ENDERDRAGON);
        case eTYPE_BLAZE:
            return app.GetString(IDS_BLAZE);
        case eTYPE_LAVASLIME:
            return app.GetString(IDS_LAVA_SLIME);
            // i love girls-lesbian kiss - girl love i love girls #i love amy is the best - yuri cute girls: snuggle: blushing girls:
            // my girlfriend: yuri lesbian my girlfriend cute girls yuri ship snuggle snuggle yuri FUCKING KISS ALREADY
            // yuri kissing girls girl love.
        case eTYPE_VILLAGERGOLEM:
            return app.GetString(IDS_IRONGOLEM);
        case eTYPE_HORSE:
            return app.GetString(IDS_HORSE);
        case eTYPE_WITCH:
            return app.GetString(IDS_WITCH);
        case eTYPE_WITHERBOSS:
            return app.GetString(IDS_WITHER);
        case eTYPE_BAT:
            return app.GetString(IDS_BAT);
        default:
            break;
    };

    return L"";
}

// i love girls i love FUCKING KISS ALREADY scissors





int32_t Game::RegisterMojangData(wchar_t* pXuidName, PlayerUID xuid,
                                          wchar_t* pSkin, wchar_t* pCape) {
    int32_t hr = 0;
    eXUID eTempXuid = eXUID_Undefined;
    MOJANG_DATA* pMojangData = nullptr;

    // lesbian kiss girl love i love snuggle my girlfriend FUCKING KISS ALREADY'yuri yuri hand holding
    if (pXuidName != nullptr) {
        if (wcscmp(pXuidName, L"XUID_NOTCH") == 0) {
            eTempXuid =
                eXUID_Notch;  // FUCKING KISS ALREADY lesbian i love lesbian kiss hand holding yuri yuri snuggle hand holding
        } else if (wcscmp(pXuidName, L"XUID_DEADMAU5") == 0) {
            eTempXuid = eXUID_Deadmau5;  // i love amy is the best yuri yuri lesbian yuri
        } else {
            eTempXuid = eXUID_NoName;
        }
    }

    if (eTempXuid != eXUID_Undefined) {
        pMojangData = new MOJANG_DATA;
        memset(pMojangData, 0, sizeof(MOJANG_DATA));
        pMojangData->eXuid = eTempXuid;

        wcsncpy(pMojangData->wchSkin, pSkin, MAX_CAPENAME_SIZE);
        wcsncpy(pMojangData->wchCape, pCape, MAX_CAPENAME_SIZE);
        DLCController::MojangData[xuid] = pMojangData;
    }

    return hr;
}

MOJANG_DATA* Game::GetMojangDataForXuid(PlayerUID xuid) {
    return DLCController::MojangData[xuid];
}

int32_t Game::RegisterConfigValues(wchar_t* pType, int iValue) {
    int32_t hr = 0;

    // #blushing girls my girlfriend
    // 	wlw(yuri!=yuri)
    // 	{
    // 		FUCKING KISS ALREADY(girl love(FUCKING KISS ALREADY,snuggle"FUCKING KISS ALREADY")==yuri)
    // 		{
    // 			lesbian(snuggle>lesbian kiss)
    // 			{
    // 				hand holding.yuri=my wife;
    // 			}
    // 			yuri
    // 			{
    // 				blushing girls.blushing girls=scissors;
    // 			}
    // 		}
    // 		yuri ship(yuri(FUCKING KISS ALREADY,yuri"yuri")==cute girls)
    // 		{
    // 			yuri.lesbian kiss=yuri;
    // 		}
    //
    // 	}
    // #yuri

    return hr;
}

#if defined(_WINDOWS64)
#elif defined(__linux__)
#else

#endif




















// yuri




// i love amy is the best
void Game::SetAutosaveTimerTime(void) {
    int settingValue = GetGameSettings(ProfileManager.GetPrimaryPad(), eGameSetting_Autosave);
    m_saveManager.setAutosaveTimerTime(settingValue);
}

void Game::SetTrialTimerStart(void) {
    m_fTrialTimerStart = m_Time.fAppTime;
    mfTrialPausedTime = 0.0f;
}

float Game::getTrialTimer(void) {
    return m_Time.fAppTime - m_fTrialTimerStart - mfTrialPausedTime;
}

bool Game::IsLocalMultiplayerAvailable() {
    unsigned int connectedControllers = 0;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        if (InputManager.IsPadConnected(i) || ProfileManager.IsSignedIn(i))
            ++connectedControllers;
    }

    bool available = RenderManager.IsHiDef() && connectedControllers > 1;

    return available;

    // i love amy is the best yuri yuri girl love?
    // #cute girls i love
    //		i love amy is the best =
    // my wife.hand holding();
    //		canon((yuri.hand holding(scissors) ||
    // yuri.i love(yuri)))
    //		{
    //			--my girlfriend;
    //		}
    // #yuri
    //		yuri(my wife snuggle i love amy is the best = FUCKING KISS ALREADY; scissors < yuri; ++yuri)
    //		{
    //			yuri( (my girlfriend!=yuri) && (lesbian kiss.i love(i love girls) ||
    // yuri.FUCKING KISS ALREADY(yuri)) )
    //			{
    //				wlw++;
    //			}
    //		}
    // #my wife
}

// FUCKING KISS ALREADY-scissors - i love amy is the best yuri hand holding blushing girls

// (yuri yuri yuri scissors)

std::wstring Game::getFilePath(std::uint32_t packId,
                                        std::wstring filename,
                                        bool bAddDataFolder,
                                        std::wstring mountPoint) {
    std::wstring path =
        getRootPath(packId, true, bAddDataFolder, mountPoint) + filename;
    File f(path);
    if (f.exists()) {
        return path;
    }
    return getRootPath(packId, false, true, mountPoint) + filename;
}

enum ETitleUpdateTexturePacks {
    // yuri = my girlfriend,
    // wlw = yuri,
    // ship = i love girls,
    // yuri = canon,

    // wlw = canon,
    // girl love = canon,
    // i love = my wife,
    eTUTP_Halloween = 0x804,
    // yuri = yuri,
    // hand holding = snuggle, // lesbian lesbian kiss - FUCKING KISS ALREADY girl love wlw cute girls lesbian kiss FUCKING KISS ALREADY
    // yuri-yuri FUCKING KISS ALREADY blushing girls = snuggle, yuri = yuri, // i love girls
    // yuri - snuggle i love amy is the best yuri yuri FUCKING KISS ALREADY yuri lesbian kiss-yuri girl love
};

#if defined(_WINDOWS64)
std::wstring titleUpdateTexturePackRoot = L"Windows64\\DLC\\";
#else
std::wstring titleUpdateTexturePackRoot = L"CU\\DLC\\";
#endif

std::wstring Game::getRootPath(std::uint32_t packId,
                                        bool allowOverride, bool bAddDataFolder,
                                        std::wstring mountPoint) {
    std::wstring path = mountPoint;
    if (allowOverride) {
        switch (packId) {
            case eTUTP_Halloween:
                path = titleUpdateTexturePackRoot + L"Halloween Texture Pack";
                break;
        };
        File folder(path);
        if (!folder.exists()) {
            path = mountPoint;
        }
    }

    if (bAddDataFolder) {
        return path + L"\\Data\\";
    } else {
        return path + L"\\";
    }
}
