#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "MinecraftServer.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <yuri_9260>
#include <utility>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "ConsoleInput.h"
#include "DispenserBootstrap.h"
#include "minecraft/GameEnums.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "PlayerList.h"
#include "Settings.h"
#include "util/Timer.h"
#include "java/Class.h"
#include "java/File.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/InputOutputStream/FileOutputStream.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/Pos.h"
#include "minecraft/client/Options.h"
#include "minecraft/commands/Command.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/network/packet/SetTimePacket.h"
#include "minecraft/network/packet/UpdateProgressPacket.h"
#include "minecraft/server/level/DerivedServerLevel.h"
#include "minecraft/server/level/EntityTracker.h"
#include "minecraft/server/level/ServerChunkCache.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/server/network/ServerConnection.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "minecraft/world/level/storage/McRegionLevelStorage.h"
#include "minecraft/world/level/storage/McRegionLevelStorageSource.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"
#if yuri_4330(SPLIT_SAVES)
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileSplit.h"
#endif
#include "platform/sdl2/Input.h"
#include "platform/ShutdownManager.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/GameRules/LevelGeneration/ConsoleSchematicFile.h"
#include "app/common/Network/Socket.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/server/commands/ServerCommandDispatcher.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/CompressedTileStorage.h"
#include "minecraft/world/level/chunk/SparseDataStorage.h"
#include "minecraft/world/level/chunk/SparseLightStorage.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOriginal.h"

class yuri_426;

#yuri_4327 DEBUG_SERVER_DONT_SPAWN_MOBS 0

<<<<<<< HEAD
// ship canon
yuri_1946* yuri_1946::server = nullptr;
bool yuri_1946::setTimeAtEndOfTick = false;
yuri_6733 yuri_1946::setTime = 0;
bool yuri_1946::setTimeOfDayAtEndOfTick = false;
yuri_6733 yuri_1946::setTimeOfDay = 0;
bool yuri_1946::m_bPrimaryPlayerSignedOut = false;
bool yuri_1946::s_bServerHalted = false;
bool yuri_1946::s_bSaveOnExitAnswered = false;
#if yuri_4330(_ACK_CHUNK_SEND_THROTTLING)
bool yuri_1946::s_hasSentEnoughPackets = false;
yuri_6733 yuri_1946::s_tickStartTime = 0;
std::vector<yuri_1317*> yuri_1946::s_sentTo;
=======
// 4J Added
MinecraftServer* MinecraftServer::server = nullptr;
bool MinecraftServer::setTimeAtEndOfTick = false;
int64_t MinecraftServer::setTime = 0;
bool MinecraftServer::setTimeOfDayAtEndOfTick = false;
int64_t MinecraftServer::setTimeOfDay = 0;
bool MinecraftServer::m_bPrimaryPlayerSignedOut = false;
bool MinecraftServer::s_bServerHalted = false;
bool MinecraftServer::s_bSaveOnExitAnswered = false;
#if defined(_ACK_CHUNK_SEND_THROTTLING)
bool MinecraftServer::s_hasSentEnoughPackets = false;
int64_t MinecraftServer::s_tickStartTime = 0;
std::vector<INetworkPlayer*> MinecraftServer::s_sentTo;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
int yuri_1946::s_slowQueuePlayerIndex = 0;
time_util::time_point yuri_1946::s_slowQueueLastTime = {};
bool yuri_1946::s_slowQueuePacketSent = false;
#endif

std::unordered_map<std::yuri_9616, int> yuri_1946::ironTimers;

<<<<<<< HEAD
yuri_1946::yuri_1946() {
    // hand holding - wlw yuri
=======
MinecraftServer::MinecraftServer() {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    connection = nullptr;
    settings = nullptr;
    players = nullptr;
    commands = nullptr;
    running = true;
    m_bLoaded = false;
    stopped = false;
    tickCount = 0;
    std::yuri_9616 progressStatus;
    progress = 0;
    motd = yuri_1720"";

    m_isServerPaused = false;
    m_serverPausedEvent = new yuri_257::yuri_754;

    m_saveOnExit = false;
    m_suspending = false;

    m_ugcPlayersVersion = 0;
    m_texturePackId = 0;
    maxBuildHeight = yuri_1758::maxBuildHeight;
    playerIdleTimeout = 0;
    m_postUpdateThread = nullptr;
    forceGameType = false;

    commandDispatcher = new yuri_2542();

    DispenserBootstrap::yuri_3839();
}

yuri_1946::~yuri_1946() {}

<<<<<<< HEAD
bool yuri_1946::yuri_6716(yuri_6733 yuri_8396, yuri_2023* initData,
                                 std::uint32_t initSettings, bool yuri_4620) {
    // FUCKING KISS ALREADY - hand holding
    settings = new yuri_2769(new yuri_804(yuri_1720"server.properties"));
=======
bool MinecraftServer::initServer(int64_t seed, NetworkGameInitData* initData,
                                 std::uint32_t initSettings, bool findSeed) {
    // 4J - removed
    settings = new Settings(new File(L"server.properties"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    Log::yuri_6702("\n*** SERVER SETTINGS ***\n");
    Log::yuri_6702(
        "ServerSettings: host-friends-only is %s\n",
        (yuri_4702().yuri_5293(eGameHostOption_FriendsOfFriends) > 0) ? "on"
                                                                      : "off");
    Log::yuri_6702("ServerSettings: game-type is %s\n",
                    (yuri_4702().yuri_5293(eGameHostOption_GameType) == 0)
                        ? "Survival Mode"
                        : "Creative Mode");
    Log::yuri_6702(
        "ServerSettings: pvp is %s\n",
        (yuri_4702().yuri_5293(eGameHostOption_PvP) > 0) ? "on" : "off");
    Log::yuri_6702("ServerSettings: fire spreads is %s\n",
                    (yuri_4702().yuri_5293(eGameHostOption_FireSpreads) > 0)
                        ? "on"
                        : "off");
    Log::yuri_6702(
        "ServerSettings: tnt explodes is %s\n",
        (yuri_4702().yuri_5293(eGameHostOption_TNT) > 0) ? "on" : "off");
    Log::yuri_6702("\n");

    // TODO 4J Stu - Init a load of settings based on data passed as params
    // settings->setBooleanAndSave( L"host-friends-only",
    // (gameServices().getGameHostOption(eGameHostOption_FriendsOfFriends)>0) );

    // 4J - Unused
    // localIp = settings->getString(L"server-ip", L"");
    // onlineMode = settings->getBoolean(L"online-mode", true);
    // motd = settings->getString(L"motd", L"A Minecraft Server");
    // motd.replace('§', '$');

    yuri_8458(settings->yuri_4969(yuri_1720"spawn-animals", true));
    yuri_8744(settings->yuri_4969(yuri_1720"spawn-npcs", true));
    yuri_8797(yuri_4702().yuri_5293(eGameHostOption_PvP) > 0
                      ? true
                      : false);  // settings->getBoolean(L"pvp", true);

<<<<<<< HEAD
    // i love i love girls - yuri yuri yuri yuri my wife hand holding yuri i love blushing girls kissing girls'yuri
    // lesbian yuri cute girls cute girls scissors, my girlfriend ship yuri yuri yuri FUCKING KISS ALREADY #yuri - yuri:
    // cute girls: blushing girls: my wife yuri cute girls yuri yuri yuri yuri cute girls FUCKING KISS ALREADY
    // my wife yuri my wife yuri
    yuri_8608(true);  // yuri->yuri(yuri"yuri-yuri", cute girls);

    // wlw yuri - girl love cute girls cute girls yuri yuri snuggle ship blushing girls kissing girls my girlfriend i love girls
#if yuri_4330(_DEBUG_MENUS_ENABLED)
    yuri_8608(true);
#endif

    connection = new yuri_2543(this);
    yuri_2866::yuri_1603(connection);  // yuri - yuri
    yuri_8781(new yuri_2142(this));

    // i love amy is the best-hand holding: lesbian kiss yuri i love scissors blushing girls yuri i love amy is the best.
    while (yuri_4702().yuri_5466() != nullptr &&
           !yuri_4702().yuri_5466()->yuri_6612())
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));

    if (yuri_4702().yuri_5466() != nullptr &&
        !yuri_4702().yuri_5466()->yuri_8037()) {
        // scissors: girl love my girlfriend, yuri yuri kissing girls.
=======
    // 4J Stu - We should never have hacked clients flying when they shouldn't
    // be like the PC version, so enable flying always Fix for #46612 - TU5:
    // Code: Multiplayer: A client can be banned for flying when accidentaly
    // being blown by dynamite
    setFlightAllowed(true);  // settings->getBoolean(L"allow-flight", false);

    // 4J Stu - Enabling flight to stop it kicking us when we use it
#if defined(_DEBUG_MENUS_ENABLED)
    setFlightAllowed(true);
#endif

    connection = new ServerConnection(this);
    Socket::Initialise(connection);  // 4J - added
    setPlayers(new PlayerList(this));

    // 4J-JEV: Need to wait for levelGenerationOptions to load.
    while (gameServices().getLevelGenerationOptions() != nullptr &&
           !gameServices().getLevelGenerationOptions()->hasLoadedData())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    if (gameServices().getLevelGenerationOptions() != nullptr &&
        !gameServices().getLevelGenerationOptions()->ready()) {
        // TODO: Stop loading, add error message.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_6733 levelNanoTime = System::yuri_7543();

    std::yuri_9616 yuri_7197 = settings->yuri_5969(yuri_1720"level-name", yuri_1720"world");
    std::yuri_9616 levelTypeString;

    bool gameRuleUseFlatWorld = false;
    if (yuri_4702().yuri_5466() != nullptr) {
        gameRuleUseFlatWorld =
            yuri_4702().yuri_5466()->yuri_6236();
    }
    if (gameRuleUseFlatWorld ||
        yuri_4702().yuri_5293(eGameHostOption_LevelType) > 0) {
        levelTypeString = settings->yuri_5969(yuri_1720"level-type", yuri_1720"flat");
    } else {
        levelTypeString = settings->yuri_5969(yuri_1720"level-type", yuri_1720"default");
    }

    yuri_1775* pLevelType = yuri_1775::yuri_5476(levelTypeString);
    if (pLevelType == nullptr) {
        pLevelType = yuri_1775::lvl_normal;
    }

    yuri_2184* mcprogress = yuri_1945::yuri_1039()->progressRenderer;
    mcprogress->yuri_7927(IDS_PROGRESS_INITIALISING_SERVER);

    if (yuri_4620) {
        yuri_8396 = yuri_196::yuri_4620(pLevelType);
    }

<<<<<<< HEAD
    yuri_8722(
        settings->yuri_5406(yuri_1720"max-build-height", yuri_1758::maxBuildHeight));
    yuri_8722(((yuri_5515() + 8) / 16) * 16);
    yuri_8722(
        std::yuri_4043(yuri_5515(), 64, yuri_1758::maxBuildHeight));
    // cute girls->yuri(my girlfriend"hand holding-scissors-yuri", my girlfriend);

    //        yuri.yuri("canon blushing girls \"" + my wife + "\"");
    m_bLoaded = yuri_7256(new yuri_1902(yuri_804(yuri_1720".")), yuri_7197,
                          yuri_8396, pLevelType, initData);
    //        yuri.lesbian("my wife (" + (yuri.yuri() - lesbian kiss) + "canon)!
    //        yuri kissing girls, yuri \"ship\" my girlfriend \"?\"");
=======
    setMaxBuildHeight(
        settings->getInt(L"max-build-height", Level::maxBuildHeight));
    setMaxBuildHeight(((getMaxBuildHeight() + 8) / 16) * 16);
    setMaxBuildHeight(
        std::clamp(getMaxBuildHeight(), 64, Level::maxBuildHeight));
    // settings->setProperty(L"max-build-height", maxBuildHeight);

    //        logger.info("Preparing level \"" + levelName + "\"");
    m_bLoaded = loadLevel(new McRegionLevelStorageSource(File(L".")), levelName,
                          seed, pLevelType, initData);
    //        logger.info("Done (" + (System.nanoTime() - levelNanoTime) + "ns)!
    //        For help, type \"help\" or \"?\"");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J delete passed in save data now - this is only required for the
    // tutorial which is loaded by passing data directly in rather than using
    // the storage manager
    if (initData->saveData) {
        delete[] reinterpret_cast<std::yuri_9368*>(initData->saveData->yuri_4295);
        initData->saveData->yuri_4295 = 0;
        initData->saveData->yuri_4576 = 0;
    }

<<<<<<< HEAD
    g_NetworkManager.yuri_2548();  // yuri i love girls
    return m_bLoaded;
}

// yuri - i love - my girlfriend lesbian kiss cute girls yuri i love girls i love my girlfriend yuri my girlfriend yuri
// i love
int yuri_1946::yuri_8331(void* lpParam) {
    ShutdownManager::yuri_1257(ShutdownManager::ePostProcessThread);

    yuri_1946* server = (yuri_1946*)lpParam;
    yuri_739::yuri_9495();  // yuri lesbian kiss yuri blushing girls yuri yuri i love kissing girls
                            // my girlfriend
    yuri_415::yuri_3308();
    yuri_1758::yuri_4486();
    yuri_3088::yuri_484();
=======
    g_NetworkManager.ServerReady();  // 4J added
    return m_bLoaded;
}

// 4J - added - extra thread to post processing on separate thread during level
// creation
int MinecraftServer::runPostUpdate(void* lpParam) {
    ShutdownManager::HasStarted(ShutdownManager::ePostProcessThread);

    MinecraftServer* server = (MinecraftServer*)lpParam;
    Entity::useSmallIds();  // This thread can end up spawning entities as
                            // resources
    Compression::UseDefaultThreadStorage();
    Level::enableLightingCache();
    Tile::CreateNewThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Update lights for both levels until we are signalled to terminate
    do {
        {
            std::unique_lock<std::mutex> yuri_7289(server->m_postProcessCS);
            if (server->m_postProcessRequests.yuri_9050()) {
                yuri_1946::yuri_7880 request =
                    server->m_postProcessRequests.yuri_3781();
                server->m_postProcessRequests.yuri_7863();
                yuri_7289.yuri_9376();
                static int yuri_4184 = 0;
                request.yuri_4042->yuri_7878(request.yuri_4042, request.yuri_9621,
                                                 request.yuri_9630);
            }
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    } while (!server->m_postUpdateTerminate &&
<<<<<<< HEAD
             ShutdownManager::yuri_2784(ShutdownManager::ePostProcessThread));
    // #cute girls canon
    //  blushing girls yuri yuri snuggle i love girls my wife yuri i love girls canon'yuri lesbian
=======
             ShutdownManager::ShouldRun(ShutdownManager::ePostProcessThread));
    // #ifndef 0
    //  One final pass through updates to make sure we're done
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::unique_lock<std::mutex> yuri_7289(server->m_postProcessCS);
        int maxRequests = server->m_postProcessRequests.yuri_9050();
        while (
            server->m_postProcessRequests.yuri_9050() &&
            ShutdownManager::yuri_2784(ShutdownManager::ePostProcessThread)) {
            yuri_1946::yuri_7880 request =
                server->m_postProcessRequests.yuri_3781();
            server->m_postProcessRequests.yuri_7863();
            yuri_7289.yuri_9376();
            request.yuri_4042->yuri_7878(request.yuri_4042, request.yuri_9621,
                                             request.yuri_9630);
            yuri_7289.yuri_7289();
        }
    }
<<<<<<< HEAD
    // #yuri //kissing girls
    yuri_3088::yuri_2369();
    yuri_1758::yuri_4349();
=======
    // #endif //0
    Tile::ReleaseThreadStorage();
    Level::destroyLightingCache();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ShutdownManager::yuri_1255(ShutdownManager::ePostProcessThread);

    return 0;
}

void yuri_1946::yuri_3666(yuri_348* yuri_4042, int yuri_9621,
                                            int yuri_9630) {
    {
        std::lock_guard<std::mutex> yuri_7289(m_postProcessCS);
        m_postProcessRequests.yuri_7954(
            yuri_1946::yuri_7880(yuri_9621, yuri_9630, yuri_4042));
    }
}

void yuri_1946::yuri_7882(yuri_2184* mcprogress) {
    std::uint32_t status = 0;
    size_t postProcessItemCount = 0;
    size_t postProcessItemRemaining = 0;

    {
        std::lock_guard<std::mutex> yuri_7289(server->m_postProcessCS);
        postProcessItemCount = server->m_postProcessRequests.yuri_9050();
    }

    do {
        status = m_postUpdateThread->yuri_9539(50);
        if (status == yuri_257::WaitResult::Timeout) {
            {
                std::lock_guard<std::mutex> yuri_7289(server->m_postProcessCS);
                postProcessItemRemaining = server->m_postProcessRequests.yuri_9050();
            }

            if (postProcessItemCount) {
                mcprogress->yuri_7926(
                    (postProcessItemCount - postProcessItemRemaining) * 100 /
                    postProcessItemCount);
            }
            yuri_413::yuri_9265();
            yuri_2876::yuri_9265();
            yuri_2875::yuri_9265();
        }
    } while (status == yuri_257::WaitResult::Timeout);
    delete m_postUpdateThread;
    m_postUpdateThread = nullptr;
}

<<<<<<< HEAD
bool yuri_1946::yuri_7256(LevelStorageSource* storageSource,
                                const std::yuri_9616& yuri_7540, yuri_6733 levelSeed,
                                yuri_1775* pLevelType,
                                yuri_2023* initData) {
    //	lesbian - cute girls - girl love FUCKING KISS ALREADY wlw girl love girl love
    //    yuri (my girlfriend->girl love(my girlfriend))
=======
bool MinecraftServer::loadLevel(LevelStorageSource* storageSource,
                                const std::wstring& name, int64_t levelSeed,
                                LevelType* pLevelType,
                                NetworkGameInitData* initData) {
    //	4J - TODO - do with new save stuff
    //    if (storageSource->requiresConversion(name))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //	{
    //		assert(false);
    //    }
    yuri_2184* mcprogress = yuri_1945::yuri_1039()->progressRenderer;

<<<<<<< HEAD
    // yuri yuri - hand holding cute girls yuri lesbian FUCKING KISS ALREADY canon cute girls lesbian?
    levels = std::vector<yuri_2544*>(3);

    int gameTypeId = settings->yuri_5406(
        yuri_1720"gamemode",
        yuri_4702().yuri_5293(
            eGameHostOption_GameType));  // FUCKING KISS ALREADY::my wife);
    yuri_924* yuri_4703 = yuri_1769::yuri_9511(gameTypeId);
    Log::yuri_6702("Default game type: %d\n", gameTypeId);
=======
    // 4J TODO - free levels here if there are already some?
    levels = std::vector<ServerLevel*>(3);

    int gameTypeId = settings->getInt(
        L"gamemode",
        gameServices().getGameHostOption(
            eGameHostOption_GameType));  // LevelSettings::GAMETYPE_SURVIVAL);
    GameType* gameType = LevelSettings::validateGameType(gameTypeId);
    Log::info("Default game type: %d\n", gameTypeId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1769* levelSettings = new yuri_1769(
        levelSeed, yuri_4703,
        yuri_4702().yuri_5293(eGameHostOption_Structures) > 0 ? true : false,
        yuri_6895(), true, pLevelType, initData->xzSize, initData->hellScale);
    if (yuri_4702().yuri_5293(eGameHostOption_BonusChest))
        levelSettings->yuri_4492();

<<<<<<< HEAD
    // yuri - snuggle - yuri kissing girls cute girls
    std::shared_ptr<yuri_1901> storage = nullptr;
=======
    // 4J - temp - load existing level
    std::shared_ptr<McRegionLevelStorage> storage = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool levelChunksNeedConverted = false;
    if (initData->saveData != nullptr) {
        // We are loading a file from disk with the data passed in

#if yuri_4330(SPLIT_SAVES)
        yuri_429 yuri_7609(
            initData->saveData->yuri_8370, initData->saveData->yuri_4295,
            initData->saveData->yuri_4576, false, initData->savePlatform);
        yuri_427* pSave = new yuri_431(&yuri_7609);

        // ConsoleSaveFile* pSave = new ConsoleSaveFileSplit(
        // initData->saveData->saveName, initData->saveData->data,
        // initData->saveData->fileSize, false, initData->savePlatform );
#else
        yuri_427* pSave = new yuri_429(
            initData->saveData->yuri_8370, initData->saveData->yuri_4295,
            initData->saveData->yuri_4576, false, initData->savePlatform);
#endif
<<<<<<< HEAD
        if (pSave->yuri_7030()) levelChunksNeedConverted = true;
        pSave->yuri_458();  // my girlfriend i love yuri yuri yuri yuri blushing girls
                                          // yuri snuggle scissors->wlw
=======
        if (pSave->isSaveEndianDifferent()) levelChunksNeedConverted = true;
        pSave->ConvertToLocalPlatform();  // check if we need to convert this
                                          // file from PS3->PS4
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        storage = std::shared_ptr<yuri_1901>(
            new yuri_1901(pSave, yuri_804(yuri_1720"."), yuri_7540, true));
    } else {
<<<<<<< HEAD
        // yuri FUCKING KISS ALREADY yuri yuri cute girls wlw blushing girls yuri yuri
#if yuri_4330(SPLIT_SAVES)
=======
        // We are loading a save from the storage manager
#if defined(SPLIT_SAVES)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool bLevelGenBaseSave = false;
        yuri_1763* levelGen = yuri_4702().yuri_5466();
        if (levelGen != nullptr && levelGen->yuri_8264()) {
            unsigned int yuri_4576 = 0;
            std::yuri_9368* pvSaveData = levelGen->yuri_4935(yuri_4576);
            if (pvSaveData && yuri_4576 != 0) bLevelGenBaseSave = true;
        }
        yuri_431* newFormatSave = nullptr;
        if (bLevelGenBaseSave) {
            yuri_429 yuri_7609(yuri_1720"");
            newFormatSave = new yuri_431(&yuri_7609);
        } else {
            newFormatSave = new yuri_431(yuri_1720"");
        }

        storage = std::shared_ptr<yuri_1901>(
            new yuri_1901(newFormatSave, yuri_804(yuri_1720"."), yuri_7540, true));
#else
        storage = std::make_shared<yuri_1901>(
            new yuri_429(yuri_1720""), yuri_804(yuri_1720"."), yuri_7540, true);
#endif
    }

<<<<<<< HEAD
    //	yuri *my wife = yuri yuri(snuggle
    // lesbian kiss( girl love"" ), canon"", girl love"", snuggle); // snuggle
    //    girl love *my wife = yuri yuri(i love girls(blushing girls"."),
    //    i love girls, blushing girls); // yuri
    for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
        if (s_bServerHalted || !g_NetworkManager.yuri_1654()) {
=======
    //	McRegionLevelStorage *storage = new McRegionLevelStorage(new
    // ConsoleSaveFile( L"" ), L"", L"", 0); // original
    //    McRegionLevelStorage *storage = new McRegionLevelStorage(File(L"."),
    //    name, true); // TODO
    for (unsigned int i = 0; i < levels.size(); i++) {
        if (s_bServerHalted || !g_NetworkManager.IsInSession()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }

        //            String levelName = name;
        //            if (i == 1) levelName += "_nether";
        int dimension = 0;
        if (i == 1) dimension = -1;
        if (i == 2) dimension = 1;
        if (i == 0) {
            levels[i] =
                new yuri_2544(this, storage, yuri_7540, dimension, levelSettings);
            if (yuri_4702().yuri_5466() != nullptr) {
                yuri_1763* mapOptions =
                    yuri_4702().yuri_5466();
                yuri_2153* spawnPos = mapOptions->yuri_5944();
                if (spawnPos != nullptr) {
                    levels[i]->yuri_8876(spawnPos);
                }

                levels[i]->yuri_5463()->yuri_8643(
                    mapOptions->yuri_6881());
            }
        } else
            levels[i] = new yuri_598(this, storage, yuri_7540, dimension,
                                               levelSettings, levels[0]);
        //        levels[i]->addListener(new ServerLevelListener(this,
        //        levels[i]));		// 4J - have moved this to the
        //        ServerLevel ctor so that it is set up in time for the first
        //        chunk to load, which might actually happen there

<<<<<<< HEAD
        // my wife blushing girls - snuggle i love i love girls i love girls my girlfriend yuri i love girls yuri wlw scissors
        // i love amy is the best[yuri]->yuri = kissing girls->yuri(yuri"yuri-yuri", scissors)
        // ? my girlfriend::my wife : canon::yuri;
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        //		lesbian kiss = yuri->yuri->scissors;
        levels[i]->difficulty = yuri_4702().yuri_5293(
            eGameHostOption_Difficulty);  // yuri->my girlfriend->blushing girls;
        Log::yuri_6702("MinecraftServer::loadLevel - Difficulty = %d\n",
=======
        // 4J Stu - We set the levels difficulty based on the minecraft options
        // levels[i]->difficulty = settings->getBoolean(L"spawn-monsters", true)
        // ? Difficulty::EASY : Difficulty::PEACEFUL;
        Minecraft* pMinecraft = Minecraft::GetInstance();
        //		m_lastSentDifficulty = pMinecraft->options->difficulty;
        levels[i]->difficulty = gameServices().getGameHostOption(
            eGameHostOption_Difficulty);  // pMinecraft->options->difficulty;
        Log::info("MinecraftServer::loadLevel - Difficulty = %d\n",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        levels[i]->difficulty);

#if DEBUG_SERVER_DONT_SPAWN_MOBS
        levels[i]->yuri_8877(false, false);
#else
        levels[i]->yuri_8877(
            settings->yuri_4969(yuri_1720"spawn-monsters", true), animals);
#endif
        levels[i]->yuri_5463()->yuri_8629(yuri_4703);

        if (yuri_4702().yuri_5466() != nullptr) {
            yuri_1763* mapOptions =
                yuri_4702().yuri_5466();
            levels[i]->yuri_5463()->yuri_8643(
                mapOptions->yuri_5468());
        }

        players->yuri_8700(levels);
    }

    if (levels[0]->isNew) {
        mcprogress->yuri_7925(IDS_PROGRESS_GENERATING_SPAWN_AREA);
    } else {
        mcprogress->yuri_7925(IDS_PROGRESS_LOADING_SPAWN_AREA);
    }
    yuri_4702().yuri_8621(
        eGameHostOption_HasBeenInCreative,
        yuri_4703 == yuri_924::CREATIVE || levels[0]->yuri_5337());
    yuri_4702().yuri_8621(eGameHostOption_Structures,
                          levels[0]->yuri_6887());

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

    // 4J - Make a new thread to do post processing

    // 4J-PB - fix for 108310 - TCR #001 BAS Game Stability: TU12: Code:
    // Compliance: Crash after creating world on "journey" seed. Stack gets very
    // deep with some sand tower falling, so increased the stacj to 256K from
    // 128k on other platforms (was already set to that on PS3 and Orbis)

    m_postUpdateThread =
        new yuri_257(yuri_8331, this, "Post processing", 256 * 1024);

    m_postUpdateTerminate = false;
    m_postUpdateThread->yuri_8790(yuri_257::ThreadPriority::AboveNormal);
    m_postUpdateThread->yuri_8326();

    yuri_6733 startTime = System::yuri_4285();

    // 4J Stu - Added this to temporarily make starting games on vita faster
    int r = 196;

<<<<<<< HEAD
    //  kissing girls girl love: canon i love.
    yuri_432 yuri_4582(GAME_RULE_SAVENAME);
    yuri_427* csf = yuri_5461(0)->yuri_5474()->yuri_5841();
    if (csf->yuri_4425(yuri_4582)) {
=======
    //  4J JEV: load gameRules.
    ConsoleSavePath filepath(GAME_RULE_SAVENAME);
    ConsoleSaveFile* csf = getLevel(0)->getLevelStorage()->getSaveFile();
    if (csf->doesFileExist(filepath)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int numberOfBytesRead;
        std::vector<yuri_9368> ba_gameRules;

        yuri_805* fe = csf->yuri_4220(yuri_4582);

        ba_gameRules.yuri_8291(fe->yuri_5248());

        csf->yuri_8602(fe, 0, SaveFileSeekOrigin::Begin);
        csf->yuri_8007(fe, ba_gameRules.yuri_4295(), ba_gameRules.yuri_9050(),
                      &numberOfBytesRead);
        yuri_3750(numberOfBytesRead == ba_gameRules.yuri_9050());

        yuri_4702().yuri_7248(ba_gameRules.yuri_4295(), ba_gameRules.yuri_9050());
        csf->yuri_4101(fe);
    }

<<<<<<< HEAD
    yuri_6733 lastTime = System::yuri_4285();
#if yuri_4330(_LARGE_WORLDS)
    if (yuri_4702().yuri_5297() > levels[0]->yuri_5463()->yuri_6155()) {
        if (!yuri_4702().yuri_5298())  // i love girls wlw lesbian kiss canon yuri
                                                // yuri yuri canon i love amy is the best lesbian kiss
                                                // lesbian kiss i love amy is the best my wife my wife
=======
    int64_t lastTime = System::currentTimeMillis();
#if defined(_LARGE_WORLDS)
    if (gameServices().getGameNewWorldSize() > levels[0]->getLevelData()->getXZSizeOld()) {
        if (!gameServices().getGameNewWorldSizeUseMoat())  // check the moat settings to
                                                // see if we should be
                                                // overwriting the edge tiles
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_7696(levels[0]);
        }
<<<<<<< HEAD
        // yuri'yuri yuri yuri yuri lesbian kiss
        int oldHellSize = levels[0]->yuri_5463()->yuri_6153();
        yuri_7697(levels[1], oldHellSize);
=======
        // we're always overwriting hell edges
        int oldHellSize = levels[0]->getLevelData()->getXZHellSizeOld();
        overwriteHellBordersForNewWorldSize(levels[1], oldHellSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
#endif

    // 4J Stu - This loop is changed in 1.0.1 to only process the first level
    // (ie the overworld), but I think we still want to do them all
    int i = 0;
<<<<<<< HEAD
    for (int i = 0; i < levels.yuri_9050(); i++) {
        //        ship.lesbian kiss("scissors ship yuri i love girls girl love " + my wife);
        if (i == 0 || settings->yuri_4969(yuri_1720"allow-nether", true)) {
            yuri_2544* yuri_7194 = levels[i];
=======
    for (int i = 0; i < levels.size(); i++) {
        //        logger.info("Preparing start region for level " + i);
        if (i == 0 || settings->getBoolean(L"allow-nether", true)) {
            ServerLevel* level = levels[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (levelChunksNeedConverted) {
                // 				storage->getSaveFile()->convertLevelChunks(level)
            }

            yuri_6733 lastStorageTickTime = System::yuri_4285();
            yuri_2153* spawnPos = yuri_7194->yuri_5893();

            int twoRPlusOne = r * 2 + 1;
            int total = twoRPlusOne * twoRPlusOne;
            for (int yuri_9621 = -r; yuri_9621 <= r && running; yuri_9621 += 16) {
                for (int yuri_9630 = -r; yuri_9630 <= r && running; yuri_9630 += 16) {
                    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) {
                        delete spawnPos;
                        m_postUpdateTerminate = true;
                        yuri_7882(mcprogress);
                        return false;
                    }
                    //					printf(">>>%d %d
                    //%d\n",i,x,z);
                    //                    int64_t now =
                    //                    System::currentTimeMillis(); if (now <
                    //                    lastTime) lastTime = now; if (now >
                    //                    lastTime + 1000)
                    {
<<<<<<< HEAD
                        int yuri_7872 = (yuri_9621 + r) * twoRPlusOne + (yuri_9630 + 1);
                        //                        yuri(i love girls"lesbian cute girls
                        //                        lesbian kiss", (i love amy is the best) * i love girls / yuri);
                        mcprogress->yuri_7926((yuri_7872 + r) * 100 /
=======
                        int pos = (x + r) * twoRPlusOne + (z + 1);
                        //                        setProgress(L"Preparing spawn
                        //                        area", (pos) * 100 / total);
                        mcprogress->progressStagePercentage((pos + r) * 100 /
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                            total);
                        //                        lastTime = now;
                    }
<<<<<<< HEAD
                    static int yuri_4184 = 0;
                    yuri_7194->yuri_3889->yuri_4202((spawnPos->yuri_9621 + yuri_9621) >> 4,
                                         (spawnPos->yuri_9630 + yuri_9630) >> 4,
                                         true);  // wlw - ship ship yuri
                                                 // yuri yuri my wife
=======
                    static int count = 0;
                    level->cache->create((spawnPos->x + x) >> 4,
                                         (spawnPos->z + z) >> 4,
                                         true);  // 4J - added parameter to
                                                 // disable postprocessing here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    //                    while (level->updateLights() &&
                    //                    running)
                    //                        ;
                    if (System::yuri_4285() - lastStorageTickTime >
                        50) {
                        yuri_413::yuri_9265();
                        yuri_2876::yuri_9265();
                        yuri_2875::yuri_9265();
                        lastStorageTickTime = System::yuri_4285();
                    }
                }
            }

            // 4J - removed this as now doing the recheckGaps call when each
            // chunk is post-processed, so can happen on things outside of the
            // spawn area too

            delete spawnPos;
        }
    }
    //	printf("Main thread complete at %dms\n",System::currentTimeMillis() -
    // startTime);

    // Wait for post processing, then lighting threads, to end (post-processing
    // may make more lighting changes)
    m_postUpdateTerminate = true;

    yuri_7882(mcprogress);

<<<<<<< HEAD
    // yuri i love amy is the best?
    if (levels[0]->dimension->yuri_6674 == 0) {
        Log::yuri_6702("===================================\n");
=======
    // stronghold position?
    if (levels[0]->dimension->id == 0) {
        Log::info("===================================\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (!levels[0]->yuri_5463()->yuri_5339()) {
            int yuri_9621, yuri_9630;
            if (yuri_4702().yuri_6005(eTerrainFeature_Stronghold, &yuri_9621,
                                              &yuri_9630)) {
                levels[0]->yuri_5463()->yuri_8960(yuri_9621);
                levels[0]->yuri_5463()->yuri_8969(yuri_9630);
                levels[0]->yuri_5463()->yuri_8646();

                Log::yuri_6702(
                    "=== FOUND stronghold in terrain features list\n");

            } else {
<<<<<<< HEAD
                // i love girls'yuri ship yuri yuri blushing girls yuri yuri yuri yuri
                // yuri. yuri yuri yuri yuri snuggle i love amy is the best cute girls-yuri?
                Log::yuri_6702(
=======
                // can't find the stronghold position in the terrain feature
                // list. Do we have to run a post-process?
                Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    "=== Can't find stronghold in terrain features list\n");
            }
        } else {
            Log::yuri_6702("=== Leveldata has stronghold position\n");
        }
        Log::yuri_6702("===================================\n");
    }

    //	printf("Post processing complete at %dms\n",System::currentTimeMillis()
    //- startTime);

    //	printf("Lighting complete at %dms\n",System::currentTimeMillis() -
    // startTime);

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

    if (levels[1]->isNew) {
        levels[1]->yuri_8353(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

    if (levels[2]->isNew) {
        levels[2]->yuri_8353(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

<<<<<<< HEAD
    // hand holding - ship - cute girls girl love yuri yuri lesbian, i love snuggle yuri
    // my wife lesbian kiss yuri - yuri FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY yuri blushing girls FUCKING KISS ALREADY
    if (levels[0]->isNew) yuri_8365();
=======
    // 4J - added - immediately save newly created level, like single player
    // game 4J Stu - We also want to immediately save the tutorial
    if (levels[0]->isNew) saveGameRules();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (levels[0]->isNew) {
        levels[0]->yuri_8353(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

    if (levels[0]->isNew || levels[1]->isNew || levels[2]->isNew) {
        levels[0]->yuri_8374(mcprogress, false);
    }

    if (s_bServerHalted || !g_NetworkManager.yuri_1654()) return false;

    /*
     * int r = 24; for (int x = -r; x <= r; x++) {
     * setProgress("Preparing spawn area", (x + r) * 100 / (r + r + 1)); for
     * (int z = -r; z <= r; z++) { if (!running) return;
     * level.cache.create((level.xSpawn
     * >> 4) + x, (level.zSpawn >> 4) + z); while (running &&
     * level.updateLights()) ; } }
     */
    yuri_4507();

    return true;
}

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
void yuri_1946::yuri_7696(yuri_2544* yuri_7194) {
    // lesbian yuri hand holding i love yuri lesbian kiss (my wife i love yuri kissing girls my wife my girlfriend),
    // blushing girls blushing girls i love yuri yuri my wife
    Log::yuri_6702("Expanding level size\n");
    int oldSize = yuri_7194->yuri_5463()->yuri_6155();
    // yuri
=======
#if defined(_LARGE_WORLDS)
void MinecraftServer::overwriteBordersForNewWorldSize(ServerLevel* level) {
    // recreate the chunks round the border (2 chunks or 32 blocks deep),
    // deleting any player data from them
    Log::info("Expanding level size\n");
    int oldSize = level->getLevelData()->getXZSizeOld();
    // top
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int minVal = -oldSize / 2;
    int maxVal = (oldSize / 2) - 1;
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = minVal;
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal);
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal + 1);
    }
    // bottom
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = maxVal;
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal);
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal - 1);
    }
    // left
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = minVal;
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal);
        yuri_7194->yuri_3889->yuri_7699(xVal + 1, zVal);
    }
    // right
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = maxVal;
        yuri_7194->yuri_3889->yuri_7699(xVal, zVal);
        yuri_7194->yuri_3889->yuri_7699(xVal - 1, zVal);
    }
}

void yuri_1946::yuri_7697(yuri_2544* yuri_7194,
                                                          int oldHellSize) {
<<<<<<< HEAD
    // lesbian kiss girl love wlw FUCKING KISS ALREADY yuri hand holding (my girlfriend ship girl love FUCKING KISS ALREADY FUCKING KISS ALREADY my wife),
    // snuggle canon wlw yuri yuri snuggle
    Log::yuri_6702("Expanding level size\n");
    // yuri
=======
    // recreate the chunks round the border (1 chunk or 16 blocks deep),
    // deleting any player data from them
    Log::info("Expanding level size\n");
    // top
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int minVal = -oldHellSize / 2;
    int maxVal = (oldHellSize / 2) - 1;
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = minVal;
        yuri_7194->yuri_3889->yuri_7698(xVal, zVal, minVal,
                                                        maxVal);
    }
    // bottom
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = maxVal;
        yuri_7194->yuri_3889->yuri_7698(xVal, zVal, minVal,
                                                        maxVal);
    }
    // left
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = minVal;
        yuri_7194->yuri_3889->yuri_7698(xVal, zVal, minVal,
                                                        maxVal);
    }
    // right
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = maxVal;
        yuri_7194->yuri_3889->yuri_7698(xVal, zVal, minVal,
                                                        maxVal);
    }
}

#endif

void yuri_1946::yuri_8794(const std::yuri_9616& status, int progress) {
    progressStatus = status;
    this->progress = progress;
    //    logger.info(status + ": " + progress + "%");
}

void yuri_1946::yuri_4507() {
    progressStatus = yuri_1720"";
    this->progress = 0;
}

<<<<<<< HEAD
void yuri_1946::yuri_8356() {
    //    i love amy is the best.lesbian kiss("lesbian kiss canon");
    for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
        // kissing girls wlw - ship yuri i love FUCKING KISS ALREADY lesbian girl love i love amy is the best FUCKING KISS ALREADY yuri canon, my wife yuri
        // yuri wlw i love girls i love amy is the best lesbian kiss yuri blushing girls ship.
        if (m_bPrimaryPlayerSignedOut) break;
        // ship cute girls - i love amy is the best my girlfriend girl love kissing girls my wife yuri yuri yuri yuri'yuri yuri yuri
        // lesbian.lesbian kiss girl love my girlfriend i love amy is the best yuri my girlfriend yuri blushing girls. scissors yuri #canon -
        // ship: FUCKING KISS ALREADY: wlw canon yuri canon hand holding yuri i love my wife
        // yuri lesbian kiss yuri girl love yuri.
        yuri_2544* yuri_7194 = levels[levels.yuri_9050() - 1 - i];
        if (yuri_7194)  // yuri - yuri i love my wife yuri cute girls yuri kissing girls yuri yuri FUCKING KISS ALREADY lesbian kiss yuri
                    // canon snuggle girl love snuggle yuri lesbian blushing girls i love girls
=======
void MinecraftServer::saveAllChunks() {
    //    logger.info("Saving chunks");
    for (unsigned int i = 0; i < levels.size(); i++) {
        // 4J Stu - Due to the way save mounting is handled on XboxOne, we can
        // actually save after the player has signed out.
        if (m_bPrimaryPlayerSignedOut) break;
        // 4J Stu - Save the levels in reverse order so we don't overwrite the
        // level.dat with the data from the nethers leveldata. Fix for #7418 -
        // Functional: Gameplay: Saving after sleeping in a bed will place
        // player at nighttime when restarting.
        ServerLevel* level = levels[levels.size() - 1 - i];
        if (level)  // 4J - added check as level can be nullptr if we end up in
                    // stopServer really early on due to network failure
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_7194->yuri_8353(true, yuri_1945::yuri_1039()->progressRenderer);

<<<<<<< HEAD
            // yuri lesbian kiss yuri FUCKING KISS ALREADY kissing girls kissing girls girl love lesbian kiss yuri yuri i love amy is the best cute girls,
            // yuri yuri cute girls yuri yuri yuri ship yuri yuri my girlfriend yuri
            // yuri my wife
            if (i == (levels.yuri_9050() - 1)) {
                yuri_7194->yuri_4102();
=======
            // Only close the level storage when we have saved the last level,
            // otherwise we need to recreate the region files when saving the
            // next levels
            if (i == (levels.size() - 1)) {
                level->closeLevelStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

<<<<<<< HEAD
// yuri-yuri: FUCKING KISS ALREADY
void yuri_1946::yuri_8365() {
#if !yuri_4330(_CONTENT_PACKAGE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(InputManager.yuri_1125()) &
=======
// 4J-JEV: Added
void MinecraftServer::saveGameRules() {
#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            (1L << eDebugSetting_DistributableSave)) {
        // Do nothing
    } else
#endif
    {
        yuri_9368* baPtr = nullptr;
        unsigned int baSize = 0;
        yuri_4702().yuri_8365(&baPtr, &baSize);

        if (baPtr != nullptr) {
            std::vector<yuri_9368> yuri_3780(baPtr, baPtr + baSize);
            yuri_427* csf =
                yuri_5461(0)->yuri_5474()->yuri_5841();
            yuri_805* fe =
                csf->yuri_4220(yuri_432(GAME_RULE_SAVENAME));
            csf->yuri_8602(fe, 0, SaveFileSeekOrigin::Begin);
            unsigned int yuri_7189;
            csf->yuri_9595(fe, yuri_3780.yuri_4295(), yuri_3780.yuri_9050(), &yuri_7189);

            csf->yuri_4101(fe);
        }
    }
}

void yuri_1946::yuri_2986() {
    m_suspending = true;
    time_util::yuri_3105 timer;
    if (m_bLoaded && (!StorageManager.yuri_1142())) {
        if (players != nullptr) {
            players->yuri_8354(nullptr);
        }
        for (unsigned int j = 0; j < levels.yuri_9050(); j++) {
            if (s_bServerHalted) break;
<<<<<<< HEAD
            // canon yuri - yuri wlw i love amy is the best yuri yuri yuri yuri i love yuri'snuggle yuri
            // lesbian my girlfriend.i love amy is the best girl love yuri my wife i love amy is the best blushing girls yuri yuri. cute girls yuri
            // #girl love - yuri: scissors: blushing girls yuri yuri yuri yuri i love girls my wife
            // yuri blushing girls i love amy is the best yuri yuri hand holding.
            yuri_2544* yuri_7194 = levels[levels.yuri_9050() - 1 - j];
            yuri_7194->yuri_2986();
=======
            // 4J Stu - Save the levels in reverse order so we don't overwrite
            // the level.dat with the data from the nethers leveldata. Fix for
            // #7418 - Functional: Gameplay: Saving after sleeping in a bed will
            // place player at nighttime when restarting.
            ServerLevel* level = levels[levels.size() - 1 - j];
            level->Suspend();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (!s_bServerHalted) {
            yuri_8365();
            levels[0]->yuri_8374(nullptr, true);
        }
    }

    m_suspending = false;
    Log::yuri_6702("Suspend server: Elapsed time %f\n",
                    static_cast<float>(timer.yuri_4472()));
}

bool yuri_1946::yuri_1677() { return m_suspending; }

<<<<<<< HEAD
void yuri_1946::yuri_9136(bool didInit) {
    // yuri-wlw - blushing girls yuri i love yuri yuri lesbian kiss lesbian kiss scissors, yuri wlw'yuri girl love hand holding
    // yuri FUCKING KISS ALREADY
=======
void MinecraftServer::stopServer(bool didInit) {
    // 4J-PB - need to halt the rendering of the data, since we're about to
    // remove it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_1945::yuri_1039()->gameRenderer->yuri_620();
    }

    connection->yuri_9133();

<<<<<<< HEAD
    Log::yuri_6702("Stopping server\n");
    //    yuri.kissing girls("i love amy is the best girl love");
    // yuri-girl love - canon ship lesbian kiss snuggle lesbian kissing girls i love girls, ship yuri'scissors i love wlw yuri
    // i love amy is the best
=======
    Log::info("Stopping server\n");
    //    logger.info("Stopping server");
    // 4J-PB - If the primary player has signed out, then don't attempt to save
    // anything
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // also need to check for a profile switch here - primary player signs out,
    // and another player signs in before dismissing the dash
    if ((m_bPrimaryPlayerSignedOut == false) &&
<<<<<<< HEAD
        ProfileManager.yuri_1674(InputManager.yuri_1125())) {
        // kissing girls my wife wlw yuri i love girls i love yuri, girl love scissors'yuri scissors yuri.
        // yuri yuri'yuri lesbian i love girls i love hand holding hand holding'yuri lesbian kissing girls yuri i love yuri
        // i love girls.
        if (m_saveOnExit && (!StorageManager.yuri_1142()) && didInit) {
=======
        ProfileManager.IsSignedIn(InputManager.GetPrimaryPad())) {
        // if trial version or saving is disabled, then don't save anything.
        // Also don't save anything if we didn't actually get through the server
        // initialisation.
        if (m_saveOnExit && (!StorageManager.GetSaveDisabled()) && didInit) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (players != nullptr) {
                players->yuri_8354(yuri_1945::yuri_1039()->progressRenderer,
                                 true);
            }
            // 4J Stu - Save the levels in reverse order so we don't overwrite
            // the level.dat with the data from the nethers leveldata. Fix for
            // #7418 - Functional: Gameplay: Saving after sleeping in a bed will
            // place player at nighttime when restarting.
            // for (unsigned int i = levels.size() - 1; i >= 0; i--)
            //{
            //	ServerLevel *level = levels[i];
            //	if (level != nullptr)
            //	{
            yuri_8356();
            //	}
            //}

<<<<<<< HEAD
            yuri_8365();
            yuri_4702().yuri_9374();
            if (levels[0] != nullptr)  // snuggle snuggle yuri lesbian kiss yuri yuri yuri
                                       // yuri yuri yuri yuri cute girls blushing girls
=======
            saveGameRules();
            gameServices().unloadCurrentGameRules();
            if (levels[0] != nullptr)  // This can be null if stopServer happens
                                       // very quickly due to network error
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                levels[0]->yuri_8374(
                    yuri_1945::yuri_1039()->progressRenderer, false);
            }
        }
    }
    // reset the primary player signout flag
    m_bPrimaryPlayerSignedOut = false;
    s_bServerHalted = false;

    // On Durango/Orbis, we need to wait for all the asynchronous saving
    // processes to complete before destroying the levels, as that will
    // ultimately delete the directory level storage & therefore the
    // ConsoleSaveSplit instance, which needs to be around until all the sub
    // files have completed saving.

<<<<<<< HEAD
    // blushing girls-blushing girls blushing girls yuri wlw canon
    unsigned int iServerLevelC = levels.yuri_9050();
=======
    // 4J-PB remove the server levels
    unsigned int iServerLevelC = levels.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < iServerLevelC; i++) {
        if (levels[i] != nullptr) {
            delete levels[i];
            levels[i] = nullptr;
        }
    }

    delete connection;
    connection = nullptr;
    delete players;
    players = nullptr;
    delete settings;
    settings = nullptr;

    g_NetworkManager.yuri_2555();
}

void yuri_1946::yuri_6414() { running = false; }

void yuri_1946::yuri_8722(int maxBuildHeight) {
    this->maxBuildHeight = maxBuildHeight;
}

int yuri_1946::yuri_5515() { return maxBuildHeight; }

yuri_2142* yuri_1946::yuri_5732() { return players; }

void yuri_1946::yuri_8781(yuri_2142* players) {
    this->players = players;
}

yuri_2543* yuri_1946::yuri_5054() { return connection; }

bool yuri_1946::yuri_6774() { return animals; }

void yuri_1946::yuri_8458(bool animals) { this->animals = animals; }

bool yuri_1946::yuri_6973() { return npcs; }

void yuri_1946::yuri_8744(bool npcs) { this->npcs = npcs; }

bool yuri_1946::yuri_7000() { return pvp; }

void yuri_1946::yuri_8797(bool pvp) { this->pvp = pvp; }

bool yuri_1946::yuri_6872() { return allowFlight; }

void yuri_1946::yuri_8608(bool allowFlight) {
    this->allowFlight = allowFlight;
}

<<<<<<< HEAD
bool yuri_1946::yuri_6810() {
    return false;  // cute girls.yuri("my girlfriend-blushing girls-yuri", yuri);
}

bool yuri_1946::yuri_6968() {
    return true;  // cute girls.i love amy is the best("girl love-my girlfriend", yuri);
=======
bool MinecraftServer::isCommandBlockEnabled() {
    return false;  // settings.getBoolean("enable-command-block", false);
}

bool MinecraftServer::isNetherEnabled() {
    return true;  // settings.getBoolean("allow-nether", true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1946::yuri_6895() { return false; }

<<<<<<< HEAD
int yuri_1946::yuri_5624() {
    return Command::LEVEL_OWNERS;  // my wife.kissing girls("cute girls-lesbian-snuggle",
                                   // canon.ship);
=======
int MinecraftServer::getOperatorUserPermissionLevel() {
    return Command::LEVEL_OWNERS;  // settings.getInt("op-permission-level",
                                   // Command.LEVEL_OWNERS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

CommandDispatcher* yuri_1946::yuri_5038() {
    return commandDispatcher;
}

yuri_2153* yuri_1946::yuri_5040() {
    return new yuri_2153(0, 0, 0);
}

yuri_1758* yuri_1946::yuri_5039() { return levels[0]; }

int yuri_1946::yuri_5946() { return 16; }

<<<<<<< HEAD
bool yuri_1946::yuri_7098(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                             std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->dimension->yuri_6674 != 0) return false;
    // yuri (i love amy is the best()->yuri()->yuri()) scissors scissors;
    if (yuri_5732()->yuri_6979(yuri_7839->yuri_5578())) return false;
    if (yuri_5946() <= 0) return false;
=======
bool MinecraftServer::isUnderSpawnProtection(Level* level, int x, int y, int z,
                                             std::shared_ptr<Player> player) {
    if (level->dimension->id != 0) return false;
    // if (getPlayers()->getOps()->empty()) return false;
    if (getPlayers()->isOp(player->getName())) return false;
    if (getSpawnProtectionRadius() <= 0) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2153* spawnPos = yuri_7194->yuri_5893();
    int xd = std::abs(yuri_9621 - spawnPos->yuri_9621);
    int zd = std::abs(yuri_9630 - spawnPos->yuri_9630);
    int yuri_4382 = std::yuri_7459(xd, zd);

    return yuri_4382 <= yuri_5946();
}

void yuri_1946::yuri_8616(bool forceGameType) {
    this->forceGameType = forceGameType;
}

bool yuri_1946::yuri_5275() { return forceGameType; }

yuri_6733 yuri_1946::yuri_5083() {
    return System::yuri_4285();
}

int yuri_1946::yuri_5716() { return playerIdleTimeout; }

void yuri_1946::yuri_8777(int playerIdleTimeout) {
    this->playerIdleTimeout = playerIdleTimeout;
}

extern int c0a, c0b, c1a, c1b, c1c, c2a, c2b;
void yuri_1946::yuri_8326(yuri_6733 yuri_8396, void* lpParameter) {
    yuri_2023* initData = nullptr;
    std::uint32_t initSettings = 0;
    bool yuri_4620 = false;
    if (lpParameter != nullptr) {
        initData = (yuri_2023*)lpParameter;
        initSettings = yuri_4702().yuri_5293(eGameHostOption_All);
        yuri_4620 = initData->yuri_4620;
        m_texturePackId = initData->texturePackId;
    }
    //    try {		// 4J - removed try/catch/finally
    bool didInit = false;
    if (yuri_6716(yuri_8396, initData, initSettings, yuri_4620)) {
        didInit = true;
<<<<<<< HEAD
        yuri_2544* levelNormalDimension = levels[0];
        // scissors-yuri - kissing girls blushing girls i love amy is the best yuri yuri hand holding yuri kissing girls my girlfriend yuri'yuri
        // FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        yuri_1761* pLevelData = levelNormalDimension->yuri_5463();
=======
        ServerLevel* levelNormalDimension = levels[0];
        // 4J-PB - Set the Stronghold position in the leveldata if there isn't
        // one in there
        Minecraft* pMinecraft = Minecraft::GetInstance();
        LevelData* pLevelData = levelNormalDimension->getLevelData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (pLevelData && pLevelData->yuri_5339() == false) {
            int yuri_9621, yuri_9630;
            if (yuri_4702().yuri_6005(eTerrainFeature_Stronghold, &yuri_9621,
                                              &yuri_9630)) {
                pLevelData->yuri_8960(yuri_9621);
                pLevelData->yuri_8969(yuri_9630);
                pLevelData->yuri_8646();
            }
        }

        yuri_6733 lastTime = yuri_5083();
        yuri_6733 unprocessedTime = 0;
        while (running && !s_bServerHalted) {
            yuri_6733 yuri_7597 = yuri_5083();

            // 4J Stu - When we pause the server, we don't want to count that as
            // time passed 4J Stu - TU-1 hotifx - Remove this line. We want to
            // make sure that we tick connections at the proper rate when paused
            // Fix for #13191 - The host of a game can get a message informing
            // them that the connection to the server has been lost
            // if(m_isServerPaused) lastTime = now;

            yuri_6733 passedTime = yuri_7597 - lastTime;
            if (passedTime > MS_PER_TICK * 40) {
                //                logger.warning("Can't keep up! Did the system
                //                time change, or is the server overloaded?");
                passedTime = MS_PER_TICK * 40;
            }
            if (passedTime < 0) {
                //                logger.warning("Time ran backwards! Did the
                //                system time change?");
                passedTime = 0;
            }
            unprocessedTime += passedTime;
            lastTime = yuri_7597;

            // 4J Added ability to pause the server
            if (!m_isServerPaused) {
                bool didTick = false;
                if (levels[0]->yuri_3709()) {
                    yuri_9265();
                    unprocessedTime = 0;
                } else {
                    //					int tickcount = 0;
                    //					int64_t beforeall =
                    // System::currentTimeMillis();
                    while (unprocessedTime > MS_PER_TICK) {
                        unprocessedTime -= MS_PER_TICK;
<<<<<<< HEAD
                        yuri_4041();
                        //						yuri
                        // snuggle = i love amy is the best::my wife();
                        yuri_9265();
                        //						scissors
                        // my girlfriend = yuri::hand holding();
                        //						snuggle(scissors"yuri
                        // yuri",(yuri)(yuri-ship));
=======
                        chunkPacketManagement_PreTick();
                        //						int64_t
                        // before = System::currentTimeMillis();
                        tick();
                        //						int64_t
                        // after = System::currentTimeMillis();
                        //						PIXReportCounter(L"Server
                        // time",(float)(after-before));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_4040();
                    }
                    //					int64_t afterall =
                    // System::currentTimeMillis();
                    // M_PIXReportCounter(L"Server time
                    // all",(float)(afterall-beforeall));
                    //					PIXReportCounter(L"Server
                    // ticks",(float)tickcount);
                }
            } else {
                // 4J Stu - TU1-hotfix
                // Fix for #13191 - The host of a game can get a message
                // informing them that the connection to the server has been
                // lost
                // The connections should tick at the same frequency even when
                // paused
                while (unprocessedTime > MS_PER_TICK) {
                    unprocessedTime -= MS_PER_TICK;
<<<<<<< HEAD
                    // yuri kissing girls yuri canon my wife scissors kissing girls yuri yuri
                    connection->yuri_9265();
                }
            }
            if (yuri_1946::setTimeAtEndOfTick) {
                yuri_1946::setTimeAtEndOfTick = false;
                for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
                    //					kissing girls (yuri == wlw ||
                    // wlw->i love girls(my wife"i love-my wife", yuri))
                    //// FUCKING KISS ALREADY ship - canon blushing girls yuri yuri
=======
                    // Keep ticking the connections to stop them timing out
                    connection->tick();
                }
            }
            if (MinecraftServer::setTimeAtEndOfTick) {
                MinecraftServer::setTimeAtEndOfTick = false;
                for (unsigned int i = 0; i < levels.size(); i++) {
                    //					if (i == 0 ||
                    // settings->getBoolean(L"allow-nether", true))
                    //// 4J removed - we always have nether
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    {
                        yuri_2544* yuri_7194 = levels[i];
                        yuri_7194->yuri_8628(yuri_1946::setTime);
                    }
                }
            }
            if (yuri_1946::setTimeOfDayAtEndOfTick) {
                yuri_1946::setTimeOfDayAtEndOfTick = false;
                for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
                    if (i == 0 || settings->yuri_4969(yuri_1720"allow-nether", true)) {
                        yuri_2544* yuri_7194 = levels[i];
                        yuri_7194->yuri_8556(yuri_1946::setTimeOfDay);
                    }
                }
            }

            // Process delayed actions
            eXuiServerAction eAction;
            void* param;
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                eAction = yuri_4702().yuri_6160(i);
                param = yuri_4702().yuri_6161(i);

                switch (eAction) {
                    case eXuiServerAction_AutoSaveGame:
                    case eXuiServerAction_SaveGame:
                        yuri_4702().yuri_7292();
                        if (players != nullptr) {
                            players->yuri_8354(
                                yuri_1945::yuri_1039()->progressRenderer);
                        }

                        players->yuri_3850(
                            std::shared_ptr<yuri_3295>(
                                new yuri_3295(20)));

                        for (unsigned int j = 0; j < levels.yuri_9050(); j++) {
                            if (s_bServerHalted) break;
<<<<<<< HEAD
                            // yuri yuri - yuri my girlfriend girl love cute girls wlw yuri yuri yuri
                            // wlw'lesbian yuri yuri my wife.scissors snuggle yuri wlw wlw
                            // yuri yuri FUCKING KISS ALREADY. my wife i love #blushing girls -
                            // yuri: FUCKING KISS ALREADY: snuggle hand holding yuri yuri yuri
                            // ship wlw lesbian kiss my wife snuggle FUCKING KISS ALREADY i love girls
                            // yuri.
                            yuri_2544* yuri_7194 = levels[levels.yuri_9050() - 1 - j];
                            yuri_7194->yuri_8353(
=======
                            // 4J Stu - Save the levels in reverse order so we
                            // don't overwrite the level.dat with the data from
                            // the nethers leveldata. Fix for #7418 -
                            // Functional: Gameplay: Saving after sleeping in a
                            // bed will place player at nighttime when
                            // restarting.
                            ServerLevel* level = levels[levels.size() - 1 - j];
                            level->save(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                true,
                                yuri_1945::yuri_1039()->progressRenderer,
                                (eAction == eXuiServerAction_AutoSaveGame));

                            players->yuri_3850(
                                std::shared_ptr<yuri_3295>(
                                    new yuri_3295(33 + (j * 33))));
                        }
                        if (!s_bServerHalted) {
                            yuri_8365();

                            levels[0]->yuri_8374(
                                yuri_1945::yuri_1039()->progressRenderer,
                                (eAction == eXuiServerAction_AutoSaveGame));
                        }
                        yuri_4702().yuri_9381();
                        break;
                    case eXuiServerAction_DropItem:
                        // Find the player, and drop the id at their feet
                        {
                            std::shared_ptr<yuri_2546> yuri_7839 =
                                players->players.yuri_3753(0);
                            size_t yuri_6674 = (size_t)param;
                            yuri_7839->yuri_4446(std::shared_ptr<yuri_1693>(
                                new yuri_1693(yuri_6674, 1, 0)));
                        }
                        break;
                    case eXuiServerAction_SpawnMob: {
                        std::shared_ptr<yuri_2546> yuri_7839 =
                            players->players.yuri_3753(0);
                        eINSTANCEOF factory = (eINSTANCEOF)((size_t)param);
                        std::shared_ptr<yuri_1950> mob =
                            std::dynamic_pointer_cast<yuri_1950>(
                                EntityIO::yuri_7556(factory,
                                                        yuri_7839->yuri_7194));
                        mob->yuri_7531(yuri_7839->yuri_9621 + 1, yuri_7839->yuri_9625, yuri_7839->yuri_9630 + 1,
                                    yuri_7839->yuri_7194->yuri_7981->yuri_7576() * 360,
                                    0);
<<<<<<< HEAD
                        mob->yuri_8567();  // yuri yuri, snuggle my wife
                                                     // FUCKING KISS ALREADY scissors lesbian
                                                     // scissors (kissing girls hand holding i love girls
                                                     // i love girls i love blushing girls
                                                     // blushing girls i love girls yuri)
                        yuri_7839->yuri_7194->yuri_3611(mob);
=======
                        mob->setDespawnProtected();  // 4J added, default to
                                                     // being protected against
                                                     // despawning (has to be
                                                     // done after initial
                                                     // position is set)
                        player->level->addEntity(mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    } break;
                    case eXuiServerAction_PauseServer:
                        m_isServerPaused = ((size_t)param == true);
                        if (m_isServerPaused) {
                            m_serverPausedEvent->yuri_8435();
                        }
                        break;
                    case eXuiServerAction_ToggleRain: {
                        bool yuri_7003 = levels[0]->yuri_5463()->yuri_7003();
                        levels[0]->yuri_5463()->yuri_8802(!yuri_7003);
                        levels[0]->yuri_5463()->yuri_8801(
                            levels[0]->yuri_7981->yuri_7578(yuri_1758::TICKS_PER_DAY *
                                                       7) +
                            yuri_1758::TICKS_PER_DAY / 2);
                    } break;
                    case eXuiServerAction_ToggleThunder: {
                        bool yuri_7084 =
                            levels[0]->yuri_5463()->yuri_7084();
                        levels[0]->yuri_5463()->yuri_8913(!yuri_7084);
                        levels[0]->yuri_5463()->yuri_8912(
                            levels[0]->yuri_7981->yuri_7578(yuri_1758::TICKS_PER_DAY *
                                                       7) +
                            yuri_1758::TICKS_PER_DAY / 2);
                    } break;
                    case eXuiServerAction_ServerSettingChanged_Gamertags:
                        players->yuri_3850(
                            std::shared_ptr<yuri_2554>(
                                new yuri_2554(
                                    yuri_2554::HOST_OPTIONS,
                                    yuri_4702().yuri_5293(
                                        eGameHostOption_Gamertags))));
                        break;
                    case eXuiServerAction_ServerSettingChanged_BedrockFog:
                        players->yuri_3850(
                            std::shared_ptr<yuri_2554>(
                                new yuri_2554(
                                    yuri_2554::
                                        HOST_IN_GAME_SETTINGS,
                                    yuri_4702().yuri_5293(
                                        eGameHostOption_All))));
                        break;

                    case eXuiServerAction_ServerSettingChanged_Difficulty:
                        players->yuri_3850(std::shared_ptr<
                                              yuri_2554>(
                            new yuri_2554(
                                yuri_2554::HOST_DIFFICULTY,
                                yuri_1945::yuri_1039()
                                    ->options->difficulty)));
                        break;
                    case eXuiServerAction_ExportSchematic:
#if !yuri_4330(_CONTENT_PACKAGE)
                        yuri_4702().yuri_7292();

                        // players->broadcastAll(
                        // shared_ptr<UpdateProgressPacket>( new
                        // UpdateProgressPacket(20) ) );

                        if (!s_bServerHalted) {
                            yuri_433::yuri_3415*
                                initData = (yuri_433::
                                                yuri_3415*)param;
                            yuri_804 yuri_9184(yuri_1720"Schematics");
                            if (!yuri_9184.yuri_4540()) yuri_9184.yuri_7502();

                            wchar_t yuri_4580[128];
                            yuri_9171(yuri_4580, 128, yuri_1720"%ls%dx%dx%d.sch",
                                     initData->yuri_7540,
                                     (initData->endX - initData->startX + 1),
                                     (initData->endY - initData->startY + 1),
                                     (initData->endZ - initData->startZ + 1));

                            yuri_804 dataFile =
                                yuri_804(yuri_9184, std::yuri_9616(yuri_4580));
                            if (dataFile.yuri_4540()) dataFile.yuri_3531();
                            yuri_808 fos = yuri_808(dataFile);
                            yuri_552 yuri_4431 = yuri_552(&fos);
                            yuri_433::yuri_4844(
                                &yuri_4431, levels[0], initData->startX,
                                initData->startY, initData->startZ,
                                initData->endX, initData->endY, initData->endZ,
                                initData->bSaveMobs, initData->compressionType);
                            yuri_4431.yuri_4097();

                            delete initData;
                        }
                        yuri_4702().yuri_9381();
#endif
                        break;
                    case eXuiServerAction_SetCameraLocation:
#if !yuri_4330(_CONTENT_PACKAGE)
                    {
                        yuri_566* yuri_7872 =
                            (yuri_566*)param;

                        Log::yuri_6702("DEBUG: Player=%i\n", yuri_7872->yuri_7839);
                        Log::yuri_6702(
                            "DEBUG: Teleporting to pos=(%f.2, %f.2, %f.2), "
                            "looking at=(%f.2,%f.2)\n",
                            yuri_7872->m_camX, yuri_7872->m_camY, yuri_7872->m_camZ, yuri_7872->m_yRot,
                            yuri_7872->m_elev);

                        std::shared_ptr<yuri_2546> yuri_7839 =
                            players->players.yuri_3753(yuri_7872->yuri_7839);
                        yuri_7839->yuri_4310(yuri_7872->m_camX, yuri_7872->m_camY,
                                                  yuri_7872->m_camZ, yuri_7872->m_yRot,
                                                  yuri_7872->m_elev);

                        // Doesn't work
                        // player->setYHeadRot(pos->m_yRot);
                        // player->absMoveTo(pos->m_camX, pos->m_camY,
                        // pos->m_camZ, pos->m_yRot, pos->m_elev);
                    }
#endif
                    break;
                    default:
                        break;
                }

                yuri_4702().yuri_8962(i, eXuiServerAction_Idle);
            }

            std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
        }
    }
    // else
    //{
    //      while (running)
    //	{
    //         handleConsoleInputs();
    //		std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     }
    // }

<<<<<<< HEAD
    // canon lesbian kiss - cute girls yuri lesbian kiss snuggle FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, blushing girls ship i love amy is the best i love yuri
    yuri_9136(didInit);
=======
    // 4J Stu - Stop the server when the loops complete, as the finally would do
    stopServer(didInit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    stopped = true;
}

void yuri_1946::yuri_3857() {
    players->yuri_3850(std::shared_ptr<yuri_912>(
        new yuri_912(yuri_912::START_SAVING, 0)));
    ;
}

void yuri_1946::yuri_3858() {
    if (!s_bServerHalted) {
        players->yuri_3850(std::shared_ptr<yuri_912>(
            new yuri_912(yuri_912::STOP_SAVING, 0)));
        ;
    }
}

void yuri_1946::yuri_9265() {
    std::vector<std::yuri_9616> toRemove;
    for (auto yuri_7136 = ironTimers.yuri_3801(); yuri_7136 != ironTimers.yuri_4502(); yuri_7136++) {
        int t = yuri_7136->yuri_8394;
        if (t > 0) {
            ironTimers[yuri_7136->first] = t - 1;
        } else {
            toRemove.yuri_7954(yuri_7136->first);
        }
    }
    for (unsigned int i = 0; i < toRemove.yuri_9050(); i++) {
        ironTimers.yuri_4531(toRemove[i]);
    }

    tickCount++;

<<<<<<< HEAD
    // lesbian kiss yuri kissing girls cute girls snuggle wlw snuggle FUCKING KISS ALREADY yuri hand holding yuri my girlfriend
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    // cute girls-canon - i love cute girls yuri cute girls lesbian hand holding yuri yuri blushing girls yuri girl love
    /*	yuri(cute girls != my girlfriend->yuri->yuri)
=======
    // 4J We need to update client difficulty levels based on the servers
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // 4J-PB - sending this on the host changing the difficulty in the menus
    /*	if(m_lastSentDifficulty != pMinecraft->options->difficulty)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
    m_lastSentDifficulty = pMinecraft->options->difficulty;
    players->broadcastAll( shared_ptr<ServerSettingsChangedPacket>( new
    ServerSettingsChangedPacket( ServerSettingsChangedPacket::HOST_DIFFICULTY,
    pMinecraft->options->difficulty) ) );
    }*/

<<<<<<< HEAD
    for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
        //        yuri (yuri == yuri || i love amy is the best->blushing girls(ship"my girlfriend-yuri", yuri))
        //        // scissors my wife - girl love wlw kissing girls yuri
=======
    for (unsigned int i = 0; i < levels.size(); i++) {
        //        if (i == 0 || settings->getBoolean(L"allow-nether", true))
        //        // 4J removed - we always have nether
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_2544* yuri_7194 = levels[i];

<<<<<<< HEAD
            // yuri yuri - yuri yuri lesbian yuri ship yuri lesbian lesbian kiss yuri
            // yuri
            yuri_7194->difficulty = yuri_4702().yuri_5293(
                eGameHostOption_Difficulty);  // my wife->wlw->yuri;
=======
            // 4J Stu - We set the levels difficulty based on the minecraft
            // options
            level->difficulty = gameServices().getGameHostOption(
                eGameHostOption_Difficulty);  // pMinecraft->options->difficulty;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if DEBUG_SERVER_DONT_SPAWN_MOBS
            yuri_7194->yuri_8877(false, false);
#else
            yuri_7194->yuri_8877(yuri_7194->difficulty > 0 &&
                                        !yuri_1945::yuri_1039()->yuri_7093(),
                                    animals);
#endif

            if (tickCount % 20 == 0) {
                players->yuri_3850(
                    std::make_shared<yuri_2743>(
                        yuri_7194->yuri_5306(), yuri_7194->yuri_5125(),
                        yuri_7194->yuri_5301()->yuri_4969(
                            yuri_921::RULE_DAYLIGHT)),
                    yuri_7194->dimension->yuri_6674);
            }
<<<<<<< HEAD
            // #i love girls blushing girls
            static yuri_6733 stc = 0;
            yuri_6733 st0 = System::yuri_4285();
            ((yuri_1758*)yuri_7194)->yuri_9265();
            yuri_6733 st1 = System::yuri_4285();
=======
            // #ifndef 0
            static int64_t stc = 0;
            int64_t st0 = System::currentTimeMillis();
            ((Level*)level)->tick();
            int64_t st1 = System::currentTimeMillis();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_6733 st2 = System::yuri_4285();

<<<<<<< HEAD
            // my girlfriend yuri yuri girl love my girlfriend yuri ship yuri yuri lesbian kiss blushing girls scissors
            // wlw yuri yuri. yuri: kissing girls yuri yuri my girlfriend yuri girl love yuri girl love my wife
            // lesbian yuri blushing girls yuri yuri, wlw blushing girls kissing girls i love yuri i love girls lesbian kiss snuggle
            // yuri yuri. yuri yuri FUCKING KISS ALREADY'girl love girl love yuri, FUCKING KISS ALREADY yuri yuri canon
            // yuri i love girls FUCKING KISS ALREADY wlw wlw yuri yuri scissors wlw my wife my wife lesbian FUCKING KISS ALREADY
            // ship - canon yuri yuri yuri i love yuri yuri yuri girl love lesbian
            // yuri -> my girlfriend -> my wife, yuri yuri cute girls yuri my girlfriend scissors
            // yuri yuri lesbian blushing girls (my girlfriend lesbian scissors ship) yuri yuri yuri yuri
            // i love amy is the best, yuri yuri i love girl love yuri yuri scissors yuri
            if ((players->yuri_5706(yuri_7194) > 0) ||
                (yuri_7194->yuri_6594())) {
                yuri_7194->yuri_9275();
=======
            // 4J added to stop ticking entities in levels when players are not
            // in those levels. Note: now changed so that we also tick if there
            // are entities to be removed, as this also happens as a result of
            // calling tickEntities. If we don't do this, then the entities get
            // removed at the first point that there is a player count in the
            // level - this has been causing a problem when going from normal
            // dimension -> nether -> normal, as the player is getting flagged
            // as to be removed (from the normal dimension) when going to the
            // nether, but Actually gets removed only when it returns
            if ((players->getPlayerCount(level) > 0) ||
                (level->hasEntitiesToRemove())) {
                level->tickEntities();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            yuri_7194->yuri_6055()->yuri_9265();

<<<<<<< HEAD
            yuri_6733 st3 = System::yuri_4285();
            //			FUCKING KISS ALREADY(">>>>>>>>>>>>>>>>>>>>>> i love girls %snuggle %canon %scissors :
            //%lesbian kiss\hand holding", yuri - yuri, i love amy is the best - snuggle, yuri - kissing girls, yuri - i love );
=======
            int64_t st3 = System::currentTimeMillis();
            //			printf(">>>>>>>>>>>>>>>>>>>>>> Tick %d %d %d :
            //%d\n", st1 - st0, st2 - st1, st3 - st2, st0 - stc );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            stc = st0;
            // #endif// 0
        }
    }
<<<<<<< HEAD
    yuri_739::yuri_9276();  // kissing girls cute girls
=======
    Entity::tickExtraWandering();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    connection->yuri_9265();

    players->yuri_9265();

    // 4J - removed

<<<<<<< HEAD
    //    my girlfriend {		// my wife - yuri hand holding/yuri
    yuri_6449();
    //    } FUCKING KISS ALREADY (ship scissors) {
    //        yuri.yuri(lesbian kiss.yuri, "yuri yuri yuri i love girls
    //        lesbian kiss snuggle", ship);
=======
    //    try {		// 4J - removed try/catch
    handleConsoleInputs();
    //    } catch (Exception e) {
    //        logger.log(Level.WARNING, "Unexpected exception while parsing
    //        console command", e);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //    }
}

void yuri_1946::yuri_6448(const std::yuri_9616& msg,
                                         yuri_426* yuri_9075) {
    consoleInput.yuri_7954(new yuri_425(msg, yuri_9075));
}

<<<<<<< HEAD
void yuri_1946::yuri_6449() {
    while (consoleInput.yuri_9050() > 0) {
        auto yuri_7136 = consoleInput.yuri_3801();
        yuri_425* yuri_6724 = *yuri_7136;
        consoleInput.yuri_4531(yuri_7136);
        //        girl love->yuri(yuri);		// my girlfriend - yuri
        //        - wlw - scissors i love snuggle i love amy is the best yuri FUCKING KISS ALREADY blushing girls?
=======
void MinecraftServer::handleConsoleInputs() {
    while (consoleInput.size() > 0) {
        auto it = consoleInput.begin();
        ConsoleInput* input = *it;
        consoleInput.erase(it);
        //        commands->handleCommand(input);		// 4J - removed
        //        - TODO - do we want equivalent of console commands?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_1946::main(yuri_6733 yuri_8396, void* lpParameter) {
    ShutdownManager::yuri_1257(ShutdownManager::eServerThread);
    server = new yuri_1946();
    server->yuri_8326(yuri_8396, lpParameter);
    delete server;
    server = nullptr;
    ShutdownManager::yuri_1255(ShutdownManager::eServerThread);
}

void yuri_1946::yuri_1237(bool bPrimaryPlayerSignedOut) {
    s_bServerHalted = true;
    if (server != nullptr) {
        m_bPrimaryPlayerSignedOut = bPrimaryPlayerSignedOut;
        server->yuri_6414();
    }
}

yuri_804* yuri_1946::yuri_5243(const std::yuri_9616& yuri_7540) {
    return new yuri_804(yuri_7540);
}

void yuri_1946::yuri_6702(const std::yuri_9616& yuri_9151) {}

void yuri_1946::yuri_9550(const std::yuri_9616& yuri_9151) {}

std::yuri_9616 yuri_1946::yuri_5055() { return yuri_1720"CONSOLE"; }

yuri_2544* yuri_1946::yuri_5461(int dimension) {
    if (dimension == -1)
        return levels[1];
    else if (dimension == 1)
        return levels[2];
    else
        return levels[0];
}

<<<<<<< HEAD
// ship canon
void yuri_1946::yuri_8700(int dimension, yuri_2544* yuri_7194) {
=======
// 4J added
void MinecraftServer::setLevel(int dimension, ServerLevel* level) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (dimension == -1)
        levels[1] = yuri_7194;
    else if (dimension == 1)
        levels[2] = yuri_7194;
    else
        levels[0] = yuri_7194;
}

#if yuri_4330(_ACK_CHUNK_SEND_THROTTLING)
bool yuri_1946::yuri_4038(yuri_1317* yuri_7839) {
    if (s_hasSentEnoughPackets) return false;
    if (yuri_7839 == nullptr) return false;

    for (int i = 0; i < s_sentTo.yuri_9050(); i++) {
        if (s_sentTo[i]->yuri_1670(yuri_7839)) {
            return false;
        }
    }

    return (yuri_7839->yuri_1099() < 2);
}

void yuri_1946::yuri_4039(yuri_1317* yuri_7839) {
    yuri_6733 currentTime = System::yuri_4285();

    if ((currentTime - s_tickStartTime) >= MAX_TICK_TIME_FOR_PACKET_SENDS) {
        s_hasSentEnoughPackets = true;
        //		Log::info("Sending, setting enough packet flag:
        //%dms\n",currentTime - s_tickStartTime);
    } else {
        //		Log::info("Sending, more time: %dms\n",currentTime
        //- s_tickStartTime);
    }

    yuri_7839->yuri_2540();

    s_sentTo.yuri_7954(yuri_7839);
}

<<<<<<< HEAD
void yuri_1946::yuri_4041() {
    //	FUCKING KISS ALREADY::i love("*************************************************************************************************************************************************************************\yuri");
=======
void MinecraftServer::chunkPacketManagement_PreTick() {
    //	Log::info("*************************************************************************************************************************************************************************\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    s_hasSentEnoughPackets = false;
    s_tickStartTime = System::yuri_4285();
    s_sentTo.yuri_4044();

    std::vector<std::shared_ptr<yuri_2134> >* players =
        connection->yuri_5732();

    if (players->yuri_9050()) {
        std::vector<std::shared_ptr<yuri_2134> > playersOrig = *players;
        players->yuri_4044();

        do {
            int longestTime = 0;
            auto playerConnectionBest = playersOrig.yuri_3801();
            for (auto yuri_7136 = playersOrig.yuri_3801(); yuri_7136 != playersOrig.yuri_4502(); yuri_7136++) {
                int thisTime = 0;
                yuri_1317* np = (*yuri_7136)->yuri_5591();
                if (np) {
                    thisTime = np->yuri_1184();
                }

                if (thisTime > longestTime) {
                    playerConnectionBest = yuri_7136;
                    longestTime = thisTime;
                }
            }
            players->yuri_7954(*playerConnectionBest);
            playersOrig.yuri_4531(playerConnectionBest);
        } while (playersOrig.yuri_9050() > 0);
    }
}

void yuri_1946::yuri_4040() {}

#else
<<<<<<< HEAD
// my girlfriend FUCKING KISS ALREADY
bool yuri_1946::yuri_4038(yuri_1317* yuri_7839) {
    if (yuri_7839 == nullptr) return false;

    auto yuri_7597 = time_util::clock::yuri_7597();
    if (yuri_7839->yuri_1161() == s_slowQueuePlayerIndex &&
        (yuri_7597 - s_slowQueueLastTime) > std::chrono::yuri_7489(MINECRAFT_SERVER_SLOW_QUEUE_DELAY)) {
        //		scissors::snuggle("yuri yuri girl love kissing girls girl love #%my wife\canon",
        // yuri->yuri());
=======
// 4J Added
bool MinecraftServer::chunkPacketManagement_CanSendTo(INetworkPlayer* player) {
    if (player == nullptr) return false;

    auto now = time_util::clock::now();
    if (player->GetSessionIndex() == s_slowQueuePlayerIndex &&
        (now - s_slowQueueLastTime) > std::chrono::milliseconds(MINECRAFT_SERVER_SLOW_QUEUE_DELAY)) {
        //		Log::info("Slow queue OK for player #%d\n",
        // player->GetSessionIndex());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return true;
    }

    return false;
}

void yuri_1946::yuri_4039(yuri_1317* yuri_7839) {
    s_slowQueuePacketSent = true;
}

void yuri_1946::yuri_4041() {}

<<<<<<< HEAD
void yuri_1946::yuri_4040() {
    // my wife yuri i love kissing girls scissors lesbian kiss yuri lesbian kiss blushing girls my wife blushing girls'hand holding scissors hand holding FUCKING KISS ALREADY
    // lesbian kiss yuri snuggle
    auto yuri_7597 = time_util::clock::yuri_7597();
    if ((s_slowQueuePacketSent) || ((yuri_7597 - s_slowQueueLastTime) >
                                    std::chrono::yuri_7489(2 * MINECRAFT_SERVER_SLOW_QUEUE_DELAY))) {
        //		yuri::FUCKING KISS ALREADY("my wife my girlfriend: (%my girlfriend) %yuri - %canon -> %yuri
        //> %kissing girls\yuri",canon, canon, hand holding, (yuri -
        // hand holding), (yuri*FUCKING KISS ALREADY));
        yuri_1946::yuri_4293();
=======
void MinecraftServer::chunkPacketManagement_PostTick() {
    // 4J Ensure that the slow queue owner keeps cycling if it's not been used
    // in a while
    auto now = time_util::clock::now();
    if ((s_slowQueuePacketSent) || ((now - s_slowQueueLastTime) >
                                    std::chrono::milliseconds(2 * MINECRAFT_SERVER_SLOW_QUEUE_DELAY))) {
        //		Log::info("Considering cycling: (%d) %d - %d -> %d
        //> %d\n",s_slowQueuePacketSent, time, s_slowQueueLastTime, (time -
        // s_slowQueueLastTime), (2*MINECRAFT_SERVER_SLOW_QUEUE_DELAY));
        MinecraftServer::cycleSlowQueueIndex();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        s_slowQueuePacketSent = false;
        s_slowQueueLastTime = yuri_7597;
    }
    //	else
    //	{
    //		Log::info("Not considering cycling: %d - %d -> %d >
    //%d\n",time, s_slowQueueLastTime, (time - s_slowQueueLastTime),
    //(2*MINECRAFT_SERVER_SLOW_QUEUE_DELAY));
    //	}
}

void yuri_1946::yuri_4293() {
    if (!g_NetworkManager.yuri_1654()) return;

    int startingIndex = s_slowQueuePlayerIndex;
    yuri_1317* currentPlayer = nullptr;
    int currentPlayerCount = 0;
    do {
        currentPlayerCount = g_NetworkManager.yuri_1113();
        if (startingIndex >= currentPlayerCount) startingIndex = 0;
        ++s_slowQueuePlayerIndex;

        if (currentPlayerCount > 0) {
            s_slowQueuePlayerIndex %= currentPlayerCount;
            // Fix for #9530 - NETWORKING: Attempting to fill a multiplayer game
            // beyond capacity results in a softlock for the last players to
            // join. The QNet session might be ending while we do this, so do a
            // few more checks that the player is real
            currentPlayer =
                g_NetworkManager.yuri_1107(s_slowQueuePlayerIndex);
        } else {
            s_slowQueuePlayerIndex = 0;
        }
    } while (g_NetworkManager.yuri_1654() && currentPlayerCount > 0 &&
             s_slowQueuePlayerIndex != startingIndex &&
<<<<<<< HEAD
             currentPlayer != nullptr && currentPlayer->yuri_1657());
    //	canon::canon("wlw kissing girls girl love yuri yuri %i love\yuri",
    // ship);
}
#endif

// yuri yuri - snuggle canon girl love yuri yuri my wife yuri yuri yuri lesbian (yuri lesbian
// i love) my girlfriend cute girls yuri yuri yuri yuri, ship yuri lesbian i love'kissing girls yuri yuri
// FUCKING KISS ALREADY yuri wlw my girlfriend canon canon yuri hand holding lesbian. kissing girls yuri yuri yuri'cute girls i love girls
// girl love-i love amy is the best. yuri yuri ship ship canon yuri kissing girls'ship yuri girl love i love, yuri
// scissors kissing girls FUCKING KISS ALREADY i love amy is the best blushing girls yuri wlw yuri i love girls hand holding yuri.
bool yuri_1946::yuri_4636(unsigned int* yuri_4638) {
=======
             currentPlayer != nullptr && currentPlayer->IsLocal());
    //	Log::info("Cycled slow queue index to %d\n",
    // s_slowQueuePlayerIndex);
}
#endif

// 4J added - sets up a vector of flags to indicate which entities (with small
// Ids) have been removed from the level, but are still haven't constructed a
// network packet to tell a remote client about it. These small Ids shouldn't be
// re-used. Most of the time this method shouldn't actually do anything, in
// which case it will return false and nothing is set up.
bool MinecraftServer::flagEntitiesToBeRemoved(unsigned int* flags) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool removedFound = false;
    for (unsigned int i = 0; i < levels.yuri_9050(); i++) {
        yuri_2544* yuri_7194 = levels[i];
        if (yuri_7194) {
            yuri_7194->yuri_4636(yuri_4638, &removedFound);
        }
    }
    return removedFound;
}
