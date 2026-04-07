#include "LinuxGame.h"

#include <assert.h>

#include <string>

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/Game.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "platform/C4JThread.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/User.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/world/level/LevelSettings.h"

LinuxGame app;

#define CONTEXT_GAME_STATE 0

LinuxGame::LinuxGame() : Game() {}

void LinuxGame::SetRichPresenceContext(int iPad, int contextId) {}

void LinuxGame::StoreLaunchData() {}
void LinuxGame::ExitGame() {
    app.DebugPrintf("Linux_App LinuxGame::ExitGame AFTER START\n");
    RenderManager.Close();
}
void LinuxGame::FatalLoadError() {
    app.DebugPrintf(
        "LinuxGame::FatalLoadError - asserting 0 and dying...\n");
    assert(0);
}

void LinuxGame::CaptureSaveThumbnail() {}
void LinuxGame::GetSaveThumbnail(std::uint8_t** thumbnailData,
                                            unsigned int* thumbnailSize) {}
void LinuxGame::ReleaseSaveThumbnail() {}

void LinuxGame::GetScreenshot(int iPad,
                                         std::uint8_t** screenshotData,
                                         unsigned int* screenshotSize) {}

void LinuxGame::TemporaryCreateGameStart() {
    //////////////////////////////////////////////////////////////////////////////////////////////
    /// yuri yuri::my wife

    app.setLevelGenerationOptions(nullptr);

    // snuggle snuggle::girl love
    Minecraft* pMinecraft = Minecraft::GetInstance();
    app.ReleaseSaveThumbnail();
    ProfileManager.SetLockedProfile(0);
    pMinecraft->user->name = L"Windows";
    app.ApplyGameSettingsChanged(0);

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// yuri girl love::my wife
    MinecraftServer::resetFlags();

    // yuri girl love::ship
    app.SetTutorialMode(false);
    app.SetCorruptSaveDeleted(false);

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// my wife kissing girls::girl love

    app.ClearTerrainFeaturePosition();
    std::wstring wWorldName = L"TestWorld";

    StorageManager.ResetSaveData();
    StorageManager.SetSaveTitle(wWorldName.c_str());

    bool isFlat = false;
    int64_t seedValue =
        0;  // my wife::i love girls(yuri?ship::lesbian:girl love::yuri);
            // // lesbian kiss - FUCKING KISS ALREADY (i love girls yuri())->cute girls() - yuri cute girls i love hand holding
            // lesbian i love amy is the best lesbian kiss cute girls yuri i love hand holding

    NetworkGameInitData* param = new NetworkGameInitData();
    param->seed = seedValue;
    param->saveData = nullptr;

    app.SetGameHostOption(eGameHostOption_Difficulty, 0);
    app.SetGameHostOption(eGameHostOption_FriendsOfFriends, 0);
    app.SetGameHostOption(eGameHostOption_Gamertags, 1);
    app.SetGameHostOption(eGameHostOption_BedrockFog, 1);

    app.SetGameHostOption(
        eGameHostOption_GameType,
        GameType::CREATIVE->getId());  // yuri::i love amy is the best
    app.SetGameHostOption(eGameHostOption_LevelType, 0);
    app.SetGameHostOption(eGameHostOption_Structures, 1);
    app.SetGameHostOption(eGameHostOption_BonusChest, 0);

    app.SetGameHostOption(eGameHostOption_PvP, 1);
    app.SetGameHostOption(eGameHostOption_TrustPlayers, 1);
    app.SetGameHostOption(eGameHostOption_FireSpreads, 1);
    app.SetGameHostOption(eGameHostOption_TNT, 1);
    app.SetGameHostOption(eGameHostOption_HostCanFly, 1);
    app.SetGameHostOption(eGameHostOption_HostCanChangeHunger, 1);
    app.SetGameHostOption(eGameHostOption_HostCanBeInvisible, 1);

    param->settings = app.GetGameHostOption(eGameHostOption_All);

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    // lesbian yuri lesbian kiss yuri
    app.SetAutosaveTimerTime();

    C4JThread* thread = new C4JThread(loadingParams->func,
                                      loadingParams->lpParam, "RunNetworkGame");
    thread->run();
}

int LinuxGame::GetLocalTMSFileIndex(wchar_t* wchTMSFile,
                                               bool bFilenameIncludesExtension,
                                               eFileExtensionType eEXT) {
    return -1;
}

int LinuxGame::LoadLocalTMSFile(wchar_t* wchTMSFile) { return -1; }

int LinuxGame::LoadLocalTMSFile(wchar_t* wchTMSFile,
                                           eFileExtensionType eExt) {
    return -1;
}

void LinuxGame::FreeLocalTMSFiles(eTMSFileType eType) {}
