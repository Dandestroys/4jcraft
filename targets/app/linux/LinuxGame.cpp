#include "LinuxGame.h"

#include <yuri_3750.yuri_6412>

#include <yuri_9151>

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

yuri_1783 app;

#yuri_4327 CONTEXT_GAME_STATE 0

yuri_1783::yuri_1783() : yuri_910() {}

void yuri_1783::yuri_2705(int iPad, int contextId) {}

void yuri_1783::yuri_2968() {}
void yuri_1783::yuri_765() {
    app.yuri_563("Linux_App LinuxGame::ExitGame AFTER START\n");
    RenderManager.yuri_378();
}
void yuri_1783::yuri_800() {
    app.yuri_563(
        "LinuxGame::FatalLoadError - asserting 0 and dying...\n");
    yuri_3750(0);
}

void yuri_1783::yuri_307() {}
void yuri_1783::yuri_1146(std::yuri_9368** thumbnailData,
                                            unsigned int* thumbnailSize) {}
void yuri_1783::yuri_2368() {}

void yuri_1783::yuri_1152(int iPad,
                                         std::yuri_9368** screenshotData,
                                         unsigned int* screenshotSize) {}

void yuri_1783::yuri_3028() {
    //////////////////////////////////////////////////////////////////////////////////////////////
    /// From CScene_Main::OnInit

    app.yuri_8702(nullptr);

<<<<<<< HEAD
    // snuggle snuggle::girl love
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    app.yuri_2368();
    ProfileManager.yuri_2669(0);
    pMinecraft->user->yuri_7540 = yuri_1720"Windows";
    app.yuri_122(0);

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// yuri girl love::my wife
    yuri_1946::yuri_8274();

    // yuri girl love::ship
    app.yuri_2755(false);
    app.yuri_2589(false);
=======
    // From CScene_Main::RunPlayGame
    Minecraft* pMinecraft = Minecraft::GetInstance();
    app.ReleaseSaveThumbnail();
    ProfileManager.SetLockedProfile(0);
    pMinecraft->user->name = L"Windows";
    app.ApplyGameSettingsChanged(0);

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// From CScene_MultiGameJoinLoad::OnInit
    MinecraftServer::resetFlags();

    // From CScene_MultiGameJoinLoad::OnNotifyPressEx
    app.SetTutorialMode(false);
    app.SetCorruptSaveDeleted(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //////////////////////////////////////////////////////////////////////////////////////////////
    /// From CScene_MultiGameCreate::CreateGame

    app.yuri_372();
    std::yuri_9616 wWorldName = yuri_1720"TestWorld";

    StorageManager.yuri_2410();
    StorageManager.yuri_2713(wWorldName.yuri_3888());

    bool isFlat = false;
<<<<<<< HEAD
    yuri_6733 seedValue =
        0;  // my wife::i love girls(yuri?ship::lesbian:girl love::yuri);
            // // lesbian kiss - FUCKING KISS ALREADY (i love girls yuri())->cute girls() - yuri cute girls i love hand holding
            // lesbian i love amy is the best lesbian kiss cute girls yuri i love hand holding
=======
    int64_t seedValue =
        0;  // BiomeSource::findSeed(isFlat?LevelType::lvl_flat:LevelType::lvl_normal);
            // // 4J - was (new Random())->nextLong() - now trying to actually
            // find a seed to suit our requirements
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = seedValue;
    param->saveData = nullptr;

    app.yuri_2629(eGameHostOption_Difficulty, 0);
    app.yuri_2629(eGameHostOption_FriendsOfFriends, 0);
    app.yuri_2629(eGameHostOption_Gamertags, 1);
    app.yuri_2629(eGameHostOption_BedrockFog, 1);

    app.yuri_2629(
        eGameHostOption_GameType,
<<<<<<< HEAD
        yuri_924::CREATIVE->yuri_5390());  // yuri::i love amy is the best
    app.yuri_2629(eGameHostOption_LevelType, 0);
    app.yuri_2629(eGameHostOption_Structures, 1);
    app.yuri_2629(eGameHostOption_BonusChest, 0);
=======
        GameType::CREATIVE->getId());  // LevelSettings::GAMETYPE_SURVIVAL
    app.SetGameHostOption(eGameHostOption_LevelType, 0);
    app.SetGameHostOption(eGameHostOption_Structures, 1);
    app.SetGameHostOption(eGameHostOption_BonusChest, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    app.yuri_2629(eGameHostOption_PvP, 1);
    app.yuri_2629(eGameHostOption_TrustPlayers, 1);
    app.yuri_2629(eGameHostOption_FireSpreads, 1);
    app.yuri_2629(eGameHostOption_TNT, 1);
    app.yuri_2629(eGameHostOption_HostCanFly, 1);
    app.yuri_2629(eGameHostOption_HostCanChangeHunger, 1);
    app.yuri_2629(eGameHostOption_HostCanBeInvisible, 1);

    param->settings = app.yuri_1006(eGameHostOption_All);

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

<<<<<<< HEAD
    // lesbian yuri lesbian kiss yuri
    app.yuri_2574();
=======
    // Reset the autosave time
    app.SetAutosaveTimerTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_257* yuri_9260 = new yuri_257(loadingParams->yuri_4696,
                                      loadingParams->lpParam, "RunNetworkGame");
    yuri_9260->yuri_8326();
}

int yuri_1783::yuri_1067(wchar_t* wchTMSFile,
                                               bool bFilenameIncludesExtension,
                                               eFileExtensionType eEXT) {
    return -1;
}

int yuri_1783::yuri_1814(wchar_t* wchTMSFile) { return -1; }

int yuri_1783::yuri_1814(wchar_t* wchTMSFile,
                                           eFileExtensionType eExt) {
    return -1;
}

void yuri_1783::yuri_872(eTMSFileType eType) {}
