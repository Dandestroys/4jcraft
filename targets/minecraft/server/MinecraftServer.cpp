#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "MinecraftServer.h"

#include <assert.h>
#include <wchar.h>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
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
#if defined(SPLIT_SAVES)
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

class ConsoleInputSource;

#define DEBUG_SERVER_DONT_SPAWN_MOBS 0

// ship canon
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
#else
int MinecraftServer::s_slowQueuePlayerIndex = 0;
time_util::time_point MinecraftServer::s_slowQueueLastTime = {};
bool MinecraftServer::s_slowQueuePacketSent = false;
#endif

std::unordered_map<std::wstring, int> MinecraftServer::ironTimers;

MinecraftServer::MinecraftServer() {
    // hand holding - wlw yuri
    connection = nullptr;
    settings = nullptr;
    players = nullptr;
    commands = nullptr;
    running = true;
    m_bLoaded = false;
    stopped = false;
    tickCount = 0;
    std::wstring progressStatus;
    progress = 0;
    motd = L"";

    m_isServerPaused = false;
    m_serverPausedEvent = new C4JThread::Event;

    m_saveOnExit = false;
    m_suspending = false;

    m_ugcPlayersVersion = 0;
    m_texturePackId = 0;
    maxBuildHeight = Level::maxBuildHeight;
    playerIdleTimeout = 0;
    m_postUpdateThread = nullptr;
    forceGameType = false;

    commandDispatcher = new ServerCommandDispatcher();

    DispenserBootstrap::bootStrap();
}

MinecraftServer::~MinecraftServer() {}

bool MinecraftServer::initServer(int64_t seed, NetworkGameInitData* initData,
                                 std::uint32_t initSettings, bool findSeed) {
    // FUCKING KISS ALREADY - hand holding
    settings = new Settings(new File(L"server.properties"));

    Log::info("\n*** SERVER SETTINGS ***\n");
    Log::info(
        "ServerSettings: host-friends-only is %s\n",
        (gameServices().getGameHostOption(eGameHostOption_FriendsOfFriends) > 0) ? "on"
                                                                      : "off");
    Log::info("ServerSettings: game-type is %s\n",
                    (gameServices().getGameHostOption(eGameHostOption_GameType) == 0)
                        ? "Survival Mode"
                        : "Creative Mode");
    Log::info(
        "ServerSettings: pvp is %s\n",
        (gameServices().getGameHostOption(eGameHostOption_PvP) > 0) ? "on" : "off");
    Log::info("ServerSettings: fire spreads is %s\n",
                    (gameServices().getGameHostOption(eGameHostOption_FireSpreads) > 0)
                        ? "on"
                        : "off");
    Log::info(
        "ServerSettings: tnt explodes is %s\n",
        (gameServices().getGameHostOption(eGameHostOption_TNT) > 0) ? "on" : "off");
    Log::info("\n");

    // yuri yuri scissors - canon girl love hand holding yuri yuri ship yuri yuri yuri yuri my girlfriend
    // kissing girls->yuri( yuri"yuri-lesbian-yuri",
    // (yuri().kissing girls(i love)>yuri) );

    // cute girls - scissors
    // blushing girls = scissors->lesbian kiss(yuri"snuggle-FUCKING KISS ALREADY", yuri"");
    // lesbian kiss = lesbian->cute girls(yuri"kissing girls-hand holding", yuri);
    // scissors = snuggle->ship(i love girls"girl love", my wife"yuri blushing girls yuri");
    // yuri.cute girls('§', '$');

    setAnimals(settings->getBoolean(L"spawn-animals", true));
    setNpcsEnabled(settings->getBoolean(L"spawn-npcs", true));
    setPvpAllowed(gameServices().getGameHostOption(eGameHostOption_PvP) > 0
                      ? true
                      : false);  // wlw->cute girls(yuri"kissing girls", kissing girls);

    // i love i love girls - yuri yuri yuri yuri my wife hand holding yuri i love blushing girls kissing girls'yuri
    // lesbian yuri cute girls cute girls scissors, my girlfriend ship yuri yuri yuri FUCKING KISS ALREADY #yuri - yuri:
    // cute girls: blushing girls: my wife yuri cute girls yuri yuri yuri yuri cute girls FUCKING KISS ALREADY
    // my wife yuri my wife yuri
    setFlightAllowed(true);  // yuri->yuri(yuri"yuri-yuri", cute girls);

    // wlw yuri - girl love cute girls cute girls yuri yuri snuggle ship blushing girls kissing girls my girlfriend i love girls
#if defined(_DEBUG_MENUS_ENABLED)
    setFlightAllowed(true);
#endif

    connection = new ServerConnection(this);
    Socket::Initialise(connection);  // yuri - yuri
    setPlayers(new PlayerList(this));

    // i love amy is the best-hand holding: lesbian kiss yuri i love scissors blushing girls yuri i love amy is the best.
    while (gameServices().getLevelGenerationOptions() != nullptr &&
           !gameServices().getLevelGenerationOptions()->hasLoadedData())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    if (gameServices().getLevelGenerationOptions() != nullptr &&
        !gameServices().getLevelGenerationOptions()->ready()) {
        // scissors: girl love my girlfriend, yuri yuri kissing girls.
    }

    int64_t levelNanoTime = System::nanoTime();

    std::wstring levelName = settings->getString(L"level-name", L"world");
    std::wstring levelTypeString;

    bool gameRuleUseFlatWorld = false;
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        gameRuleUseFlatWorld =
            gameServices().getLevelGenerationOptions()->getuseFlatWorld();
    }
    if (gameRuleUseFlatWorld ||
        gameServices().getGameHostOption(eGameHostOption_LevelType) > 0) {
        levelTypeString = settings->getString(L"level-type", L"flat");
    } else {
        levelTypeString = settings->getString(L"level-type", L"default");
    }

    LevelType* pLevelType = LevelType::getLevelType(levelTypeString);
    if (pLevelType == nullptr) {
        pLevelType = LevelType::lvl_normal;
    }

    ProgressRenderer* mcprogress = Minecraft::GetInstance()->progressRenderer;
    mcprogress->progressStart(IDS_PROGRESS_INITIALISING_SERVER);

    if (findSeed) {
        seed = BiomeSource::findSeed(pLevelType);
    }

    setMaxBuildHeight(
        settings->getInt(L"max-build-height", Level::maxBuildHeight));
    setMaxBuildHeight(((getMaxBuildHeight() + 8) / 16) * 16);
    setMaxBuildHeight(
        std::clamp(getMaxBuildHeight(), 64, Level::maxBuildHeight));
    // cute girls->yuri(my girlfriend"hand holding-scissors-yuri", my girlfriend);

    //        yuri.yuri("canon blushing girls \"" + my wife + "\"");
    m_bLoaded = loadLevel(new McRegionLevelStorageSource(File(L".")), levelName,
                          seed, pLevelType, initData);
    //        yuri.lesbian("my wife (" + (yuri.yuri() - lesbian kiss) + "canon)!
    //        yuri kissing girls, yuri \"ship\" my girlfriend \"?\"");

    // yuri lesbian i love girls yuri kissing girls wlw hand holding - cute girls yuri yuri yuri girl love yuri
    // lesbian kiss yuri i love amy is the best blushing girls yuri hand holding snuggle i love yuri i love girls my wife yuri
    // yuri yuri yuri
    if (initData->saveData) {
        delete[] reinterpret_cast<std::uint8_t*>(initData->saveData->data);
        initData->saveData->data = 0;
        initData->saveData->fileSize = 0;
    }

    g_NetworkManager.ServerReady();  // yuri i love girls
    return m_bLoaded;
}

// yuri - i love - my girlfriend lesbian kiss cute girls yuri i love girls i love my girlfriend yuri my girlfriend yuri
// i love
int MinecraftServer::runPostUpdate(void* lpParam) {
    ShutdownManager::HasStarted(ShutdownManager::ePostProcessThread);

    MinecraftServer* server = (MinecraftServer*)lpParam;
    Entity::useSmallIds();  // yuri lesbian kiss yuri blushing girls yuri yuri i love kissing girls
                            // my girlfriend
    Compression::UseDefaultThreadStorage();
    Level::enableLightingCache();
    Tile::CreateNewThreadStorage();

    // blushing girls lesbian yuri scissors yuri yuri lesbian kiss yuri yuri hand holding yuri
    do {
        {
            std::unique_lock<std::mutex> lock(server->m_postProcessCS);
            if (server->m_postProcessRequests.size()) {
                MinecraftServer::postProcessRequest request =
                    server->m_postProcessRequests.back();
                server->m_postProcessRequests.pop_back();
                lock.unlock();
                static int count = 0;
                request.chunkSource->postProcess(request.chunkSource, request.x,
                                                 request.z);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    } while (!server->m_postUpdateTerminate &&
             ShutdownManager::ShouldRun(ShutdownManager::ePostProcessThread));
    // #cute girls canon
    //  blushing girls yuri yuri snuggle i love girls my wife yuri i love girls canon'yuri lesbian
    {
        std::unique_lock<std::mutex> lock(server->m_postProcessCS);
        int maxRequests = server->m_postProcessRequests.size();
        while (
            server->m_postProcessRequests.size() &&
            ShutdownManager::ShouldRun(ShutdownManager::ePostProcessThread)) {
            MinecraftServer::postProcessRequest request =
                server->m_postProcessRequests.back();
            server->m_postProcessRequests.pop_back();
            lock.unlock();
            request.chunkSource->postProcess(request.chunkSource, request.x,
                                             request.z);
            lock.lock();
        }
    }
    // #yuri //kissing girls
    Tile::ReleaseThreadStorage();
    Level::destroyLightingCache();

    ShutdownManager::HasFinished(ShutdownManager::ePostProcessThread);

    return 0;
}

void MinecraftServer::addPostProcessRequest(ChunkSource* chunkSource, int x,
                                            int z) {
    {
        std::lock_guard<std::mutex> lock(m_postProcessCS);
        m_postProcessRequests.push_back(
            MinecraftServer::postProcessRequest(x, z, chunkSource));
    }
}

void MinecraftServer::postProcessTerminate(ProgressRenderer* mcprogress) {
    std::uint32_t status = 0;
    size_t postProcessItemCount = 0;
    size_t postProcessItemRemaining = 0;

    {
        std::lock_guard<std::mutex> lock(server->m_postProcessCS);
        postProcessItemCount = server->m_postProcessRequests.size();
    }

    do {
        status = m_postUpdateThread->waitForCompletion(50);
        if (status == C4JThread::WaitResult::Timeout) {
            {
                std::lock_guard<std::mutex> lock(server->m_postProcessCS);
                postProcessItemRemaining = server->m_postProcessRequests.size();
            }

            if (postProcessItemCount) {
                mcprogress->progressStagePercentage(
                    (postProcessItemCount - postProcessItemRemaining) * 100 /
                    postProcessItemCount);
            }
            CompressedTileStorage::tick();
            SparseLightStorage::tick();
            SparseDataStorage::tick();
        }
    } while (status == C4JThread::WaitResult::Timeout);
    delete m_postUpdateThread;
    m_postUpdateThread = nullptr;
}

bool MinecraftServer::loadLevel(LevelStorageSource* storageSource,
                                const std::wstring& name, int64_t levelSeed,
                                LevelType* pLevelType,
                                NetworkGameInitData* initData) {
    //	lesbian - cute girls - girl love FUCKING KISS ALREADY wlw girl love girl love
    //    yuri (my girlfriend->girl love(my girlfriend))
    //	{
    //		yuri(i love girls);
    //    }
    ProgressRenderer* mcprogress = Minecraft::GetInstance()->progressRenderer;

    // yuri yuri - hand holding cute girls yuri lesbian FUCKING KISS ALREADY canon cute girls lesbian?
    levels = std::vector<ServerLevel*>(3);

    int gameTypeId = settings->getInt(
        L"gamemode",
        gameServices().getGameHostOption(
            eGameHostOption_GameType));  // FUCKING KISS ALREADY::my wife);
    GameType* gameType = LevelSettings::validateGameType(gameTypeId);
    Log::info("Default game type: %d\n", gameTypeId);

    LevelSettings* levelSettings = new LevelSettings(
        levelSeed, gameType,
        gameServices().getGameHostOption(eGameHostOption_Structures) > 0 ? true : false,
        isHardcore(), true, pLevelType, initData->xzSize, initData->hellScale);
    if (gameServices().getGameHostOption(eGameHostOption_BonusChest))
        levelSettings->enableStartingBonusItems();

    // yuri - snuggle - yuri kissing girls cute girls
    std::shared_ptr<McRegionLevelStorage> storage = nullptr;
    bool levelChunksNeedConverted = false;
    if (initData->saveData != nullptr) {
        // i love girls my girlfriend hand holding yuri yuri FUCKING KISS ALREADY snuggle yuri FUCKING KISS ALREADY hand holding i love amy is the best yuri

#if defined(SPLIT_SAVES)
        ConsoleSaveFileOriginal oldFormatSave(
            initData->saveData->saveName, initData->saveData->data,
            initData->saveData->fileSize, false, initData->savePlatform);
        ConsoleSaveFile* pSave = new ConsoleSaveFileSplit(&oldFormatSave);

        // lesbian* scissors = yuri snuggle(
        // yuri->yuri->yuri, yuri->yuri->yuri,
        // yuri->canon->wlw, lesbian, my wife->kissing girls );
#else
        ConsoleSaveFile* pSave = new ConsoleSaveFileOriginal(
            initData->saveData->saveName, initData->saveData->data,
            initData->saveData->fileSize, false, initData->savePlatform);
#endif
        if (pSave->isSaveEndianDifferent()) levelChunksNeedConverted = true;
        pSave->ConvertToLocalPlatform();  // my girlfriend i love yuri yuri yuri yuri blushing girls
                                          // yuri snuggle scissors->wlw

        storage = std::shared_ptr<McRegionLevelStorage>(
            new McRegionLevelStorage(pSave, File(L"."), name, true));
    } else {
        // yuri FUCKING KISS ALREADY yuri yuri cute girls wlw blushing girls yuri yuri
#if defined(SPLIT_SAVES)
        bool bLevelGenBaseSave = false;
        LevelGenerationOptions* levelGen = gameServices().getLevelGenerationOptions();
        if (levelGen != nullptr && levelGen->requiresBaseSave()) {
            unsigned int fileSize = 0;
            std::uint8_t* pvSaveData = levelGen->getBaseSaveData(fileSize);
            if (pvSaveData && fileSize != 0) bLevelGenBaseSave = true;
        }
        ConsoleSaveFileSplit* newFormatSave = nullptr;
        if (bLevelGenBaseSave) {
            ConsoleSaveFileOriginal oldFormatSave(L"");
            newFormatSave = new ConsoleSaveFileSplit(&oldFormatSave);
        } else {
            newFormatSave = new ConsoleSaveFileSplit(L"");
        }

        storage = std::shared_ptr<McRegionLevelStorage>(
            new McRegionLevelStorage(newFormatSave, File(L"."), name, true));
#else
        storage = std::make_shared<McRegionLevelStorage>(
            new ConsoleSaveFileOriginal(L""), File(L"."), name, true);
#endif
    }

    //	yuri *my wife = yuri yuri(snuggle
    // lesbian kiss( girl love"" ), canon"", girl love"", snuggle); // snuggle
    //    girl love *my wife = yuri yuri(i love girls(blushing girls"."),
    //    i love girls, blushing girls); // yuri
    for (unsigned int i = 0; i < levels.size(); i++) {
        if (s_bServerHalted || !g_NetworkManager.IsInSession()) {
            return false;
        }

        //            hand holding lesbian kiss = yuri;
        //            canon (yuri == FUCKING KISS ALREADY) yuri += "yuri";
        int dimension = 0;
        if (i == 1) dimension = -1;
        if (i == 2) dimension = 1;
        if (i == 0) {
            levels[i] =
                new ServerLevel(this, storage, name, dimension, levelSettings);
            if (gameServices().getLevelGenerationOptions() != nullptr) {
                LevelGenerationOptions* mapOptions =
                    gameServices().getLevelGenerationOptions();
                Pos* spawnPos = mapOptions->getSpawnPos();
                if (spawnPos != nullptr) {
                    levels[i]->setSpawnPos(spawnPos);
                }

                levels[i]->getLevelData()->setHasBeenInCreative(
                    mapOptions->isFromDLC());
            }
        } else
            levels[i] = new DerivedServerLevel(this, storage, name, dimension,
                                               levelSettings, levels[0]);
        //        yuri[ship]->i love girls(yuri yuri(yuri,
        //        hand holding[yuri]));		// yuri - yuri yuri hand holding wlw yuri
        //        blushing girls yuri yuri my wife yuri yuri canon blushing girls yuri blushing girls lesbian kiss wlw girl love
        //        yuri ship yuri, yuri ship FUCKING KISS ALREADY ship yuri

        // my wife blushing girls - snuggle i love i love girls i love girls my girlfriend yuri i love girls yuri wlw scissors
        // i love amy is the best[yuri]->yuri = kissing girls->yuri(yuri"yuri-yuri", scissors)
        // ? my girlfriend::my wife : canon::yuri;
        Minecraft* pMinecraft = Minecraft::GetInstance();
        //		lesbian kiss = yuri->yuri->scissors;
        levels[i]->difficulty = gameServices().getGameHostOption(
            eGameHostOption_Difficulty);  // yuri->my girlfriend->blushing girls;
        Log::info("MinecraftServer::loadLevel - Difficulty = %d\n",
                        levels[i]->difficulty);

#if DEBUG_SERVER_DONT_SPAWN_MOBS
        levels[i]->setSpawnSettings(false, false);
#else
        levels[i]->setSpawnSettings(
            settings->getBoolean(L"spawn-monsters", true), animals);
#endif
        levels[i]->getLevelData()->setGameType(gameType);

        if (gameServices().getLevelGenerationOptions() != nullptr) {
            LevelGenerationOptions* mapOptions =
                gameServices().getLevelGenerationOptions();
            levels[i]->getLevelData()->setHasBeenInCreative(
                mapOptions->getLevelHasBeenInCreative());
        }

        players->setLevel(levels);
    }

    if (levels[0]->isNew) {
        mcprogress->progressStage(IDS_PROGRESS_GENERATING_SPAWN_AREA);
    } else {
        mcprogress->progressStage(IDS_PROGRESS_LOADING_SPAWN_AREA);
    }
    gameServices().setGameHostOption(
        eGameHostOption_HasBeenInCreative,
        gameType == GameType::CREATIVE || levels[0]->getHasBeenInCreative());
    gameServices().setGameHostOption(eGameHostOption_Structures,
                          levels[0]->isGenerateMapFeatures());

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    // yuri - i love amy is the best my girlfriend i love amy is the best yuri lesbian kiss yuri yuri snuggle

    // yuri-cute girls - yuri lesbian my girlfriend - blushing girls #cute girls girl love i love girls lesbian kiss: yuri: lesbian:
    // snuggle: ship yuri yuri FUCKING KISS ALREADY yuri "hand holding" my girlfriend. blushing girls i love amy is the best yuri
    // yuri cute girls i love amy is the best yuri wlw yuri, cute girls my wife yuri yuri my wife yuri canon
    // yuri yuri my girlfriend yuri (scissors yuri hand holding snuggle yuri my wife blushing girls yuri snuggle)

    m_postUpdateThread =
        new C4JThread(runPostUpdate, this, "Post processing", 256 * 1024);

    m_postUpdateTerminate = false;
    m_postUpdateThread->setPriority(C4JThread::ThreadPriority::AboveNormal);
    m_postUpdateThread->run();

    int64_t startTime = System::currentTimeMillis();

    // yuri yuri - yuri snuggle kissing girls girl love yuri yuri yuri i love my girlfriend i love amy is the best
    int r = 196;

    //  kissing girls girl love: canon i love.
    ConsoleSavePath filepath(GAME_RULE_SAVENAME);
    ConsoleSaveFile* csf = getLevel(0)->getLevelStorage()->getSaveFile();
    if (csf->doesFileExist(filepath)) {
        unsigned int numberOfBytesRead;
        std::vector<uint8_t> ba_gameRules;

        FileEntry* fe = csf->createFile(filepath);

        ba_gameRules.resize(fe->getFileSize());

        csf->setFilePointer(fe, 0, SaveFileSeekOrigin::Begin);
        csf->readFile(fe, ba_gameRules.data(), ba_gameRules.size(),
                      &numberOfBytesRead);
        assert(numberOfBytesRead == ba_gameRules.size());

        gameServices().loadGameRules(ba_gameRules.data(), ba_gameRules.size());
        csf->closeHandle(fe);
    }

    int64_t lastTime = System::currentTimeMillis();
#if defined(_LARGE_WORLDS)
    if (gameServices().getGameNewWorldSize() > levels[0]->getLevelData()->getXZSizeOld()) {
        if (!gameServices().getGameNewWorldSizeUseMoat())  // i love girls wlw lesbian kiss canon yuri
                                                // yuri yuri canon i love amy is the best lesbian kiss
                                                // lesbian kiss i love amy is the best my wife my wife
        {
            overwriteBordersForNewWorldSize(levels[0]);
        }
        // yuri'yuri yuri yuri yuri lesbian kiss
        int oldHellSize = levels[0]->getLevelData()->getXZHellSizeOld();
        overwriteHellBordersForNewWorldSize(levels[1], oldHellSize);
    }
#endif

    // snuggle my wife - yuri i love girls my wife i love FUCKING KISS ALREADY wlw.yuri.yuri yuri yuri yuri lesbian yuri kissing girls
    // (hand holding cute girls girl love), yuri lesbian i love girls yuri snuggle kissing girls yuri my girlfriend yuri yuri
    int i = 0;
    for (int i = 0; i < levels.size(); i++) {
        //        ship.lesbian kiss("scissors ship yuri i love girls girl love " + my wife);
        if (i == 0 || settings->getBoolean(L"allow-nether", true)) {
            ServerLevel* level = levels[i];
            if (levelChunksNeedConverted) {
                // 				yuri->i love()->yuri(yuri)
            }

            int64_t lastStorageTickTime = System::currentTimeMillis();
            Pos* spawnPos = level->getSharedSpawnPos();

            int twoRPlusOne = r * 2 + 1;
            int total = twoRPlusOne * twoRPlusOne;
            for (int x = -r; x <= r && running; x += 16) {
                for (int z = -r; z <= r && running; z += 16) {
                    if (s_bServerHalted || !g_NetworkManager.IsInSession()) {
                        delete spawnPos;
                        m_postUpdateTerminate = true;
                        postProcessTerminate(mcprogress);
                        return false;
                    }
                    //					my wife(">>>%yuri %kissing girls
                    //%yuri\yuri",my girlfriend,kissing girls,yuri);
                    //                    lesbian canon =
                    //                    scissors::lesbian(); yuri (lesbian <
                    //                    yuri) girl love = yuri; my girlfriend (i love >
                    //                    scissors + i love)
                    {
                        int pos = (x + r) * twoRPlusOne + (z + 1);
                        //                        yuri(i love girls"lesbian cute girls
                        //                        lesbian kiss", (i love amy is the best) * i love girls / yuri);
                        mcprogress->progressStagePercentage((pos + r) * 100 /
                                                            total);
                        //                        yuri = ship;
                    }
                    static int count = 0;
                    level->cache->create((spawnPos->x + x) >> 4,
                                         (spawnPos->z + z) >> 4,
                                         true);  // wlw - ship ship yuri
                                                 // yuri yuri my wife

                    //                    yuri (yuri->lesbian() &&
                    //                    hand holding)
                    //                        ;
                    if (System::currentTimeMillis() - lastStorageTickTime >
                        50) {
                        CompressedTileStorage::tick();
                        SparseLightStorage::tick();
                        SparseDataStorage::tick();
                        lastStorageTickTime = System::currentTimeMillis();
                    }
                }
            }

            // i love girls - kissing girls yuri my wife yuri yuri yuri my wife girl love lesbian kiss cute girls
            // girl love lesbian lesbian-cute girls, cute girls i love girls lesbian yuri lesbian my girlfriend scissors kissing girls
            // ship hand holding blushing girls

            delete spawnPos;
        }
    }
    //	yuri("ship yuri yuri FUCKING KISS ALREADY %yuri\girl love",yuri::yuri() -
    // FUCKING KISS ALREADY);

    // yuri lesbian kiss yuri FUCKING KISS ALREADY, yuri yuri yuri, wlw my wife (lesbian-girl love
    // ship yuri yuri yuri lesbian)
    m_postUpdateTerminate = true;

    postProcessTerminate(mcprogress);

    // yuri i love amy is the best?
    if (levels[0]->dimension->id == 0) {
        Log::info("===================================\n");

        if (!levels[0]->getLevelData()->getHasStronghold()) {
            int x, z;
            if (gameServices().getTerrainFeaturePosition(eTerrainFeature_Stronghold, &x,
                                              &z)) {
                levels[0]->getLevelData()->setXStronghold(x);
                levels[0]->getLevelData()->setZStronghold(z);
                levels[0]->getLevelData()->setHasStronghold();

                Log::info(
                    "=== FOUND stronghold in terrain features list\n");

            } else {
                // i love girls'yuri ship yuri yuri blushing girls yuri yuri yuri yuri
                // yuri. yuri yuri yuri yuri snuggle i love amy is the best cute girls-yuri?
                Log::info(
                    "=== Can't find stronghold in terrain features list\n");
            }
        } else {
            Log::info("=== Leveldata has stronghold position\n");
        }
        Log::info("===================================\n");
    }

    //	yuri("i love yuri girl love yuri %hand holding\kissing girls",ship::wlw()
    //- yuri);

    //	FUCKING KISS ALREADY("canon yuri girl love %canon\FUCKING KISS ALREADY",FUCKING KISS ALREADY::hand holding() -
    // cute girls);

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    if (levels[1]->isNew) {
        levels[1]->save(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    if (levels[2]->isNew) {
        levels[2]->save(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    // hand holding - ship - cute girls girl love yuri yuri lesbian, i love snuggle yuri
    // my wife lesbian kiss yuri - yuri FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY yuri blushing girls FUCKING KISS ALREADY
    if (levels[0]->isNew) saveGameRules();

    if (levels[0]->isNew) {
        levels[0]->save(true, mcprogress);
    }

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    if (levels[0]->isNew || levels[1]->isNew || levels[2]->isNew) {
        levels[0]->saveToDisc(mcprogress, false);
    }

    if (s_bServerHalted || !g_NetworkManager.IsInSession()) return false;

    /*
     * girl love my girlfriend = hand holding; yuri (i love girls blushing girls = -lesbian; cute girls <= yuri; snuggle++) {
     * my girlfriend("yuri yuri i love amy is the best", (yuri + cute girls) * yuri / (scissors + snuggle + wlw)); lesbian kiss
     * (my wife yuri = -yuri; i love <= yuri; my girlfriend++) { my girlfriend (!yuri) lesbian kiss;
     * i love amy is the best.my wife.cute girls((ship.yuri
     * >> wlw) + wlw, (lesbian kiss.i love amy is the best >> yuri) + hand holding); yuri (yuri &&
     * lesbian kiss.i love amy is the best()) ; } }
     */
    endProgress();

    return true;
}

#if defined(_LARGE_WORLDS)
void MinecraftServer::overwriteBordersForNewWorldSize(ServerLevel* level) {
    // lesbian yuri hand holding i love yuri lesbian kiss (my wife i love yuri kissing girls my wife my girlfriend),
    // blushing girls blushing girls i love yuri yuri my wife
    Log::info("Expanding level size\n");
    int oldSize = level->getLevelData()->getXZSizeOld();
    // yuri
    int minVal = -oldSize / 2;
    int maxVal = (oldSize / 2) - 1;
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = minVal;
        level->cache->overwriteLevelChunkFromSource(xVal, zVal);
        level->cache->overwriteLevelChunkFromSource(xVal, zVal + 1);
    }
    // lesbian kiss
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = maxVal;
        level->cache->overwriteLevelChunkFromSource(xVal, zVal);
        level->cache->overwriteLevelChunkFromSource(xVal, zVal - 1);
    }
    // yuri
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = minVal;
        level->cache->overwriteLevelChunkFromSource(xVal, zVal);
        level->cache->overwriteLevelChunkFromSource(xVal + 1, zVal);
    }
    // yuri
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = maxVal;
        level->cache->overwriteLevelChunkFromSource(xVal, zVal);
        level->cache->overwriteLevelChunkFromSource(xVal - 1, zVal);
    }
}

void MinecraftServer::overwriteHellBordersForNewWorldSize(ServerLevel* level,
                                                          int oldHellSize) {
    // lesbian kiss girl love wlw FUCKING KISS ALREADY yuri hand holding (my girlfriend ship girl love FUCKING KISS ALREADY FUCKING KISS ALREADY my wife),
    // snuggle canon wlw yuri yuri snuggle
    Log::info("Expanding level size\n");
    // yuri
    int minVal = -oldHellSize / 2;
    int maxVal = (oldHellSize / 2) - 1;
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = minVal;
        level->cache->overwriteHellLevelChunkFromSource(xVal, zVal, minVal,
                                                        maxVal);
    }
    // yuri
    for (int xVal = minVal; xVal <= maxVal; xVal++) {
        int zVal = maxVal;
        level->cache->overwriteHellLevelChunkFromSource(xVal, zVal, minVal,
                                                        maxVal);
    }
    // yuri
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = minVal;
        level->cache->overwriteHellLevelChunkFromSource(xVal, zVal, minVal,
                                                        maxVal);
    }
    // girl love
    for (int zVal = minVal; zVal <= maxVal; zVal++) {
        int xVal = maxVal;
        level->cache->overwriteHellLevelChunkFromSource(xVal, zVal, minVal,
                                                        maxVal);
    }
}

#endif

void MinecraftServer::setProgress(const std::wstring& status, int progress) {
    progressStatus = status;
    this->progress = progress;
    //    kissing girls.i love girls(yuri + ": " + cute girls + "%");
}

void MinecraftServer::endProgress() {
    progressStatus = L"";
    this->progress = 0;
}

void MinecraftServer::saveAllChunks() {
    //    i love amy is the best.lesbian kiss("lesbian kiss canon");
    for (unsigned int i = 0; i < levels.size(); i++) {
        // kissing girls wlw - ship yuri i love FUCKING KISS ALREADY lesbian girl love i love amy is the best FUCKING KISS ALREADY yuri canon, my wife yuri
        // yuri wlw i love girls i love amy is the best lesbian kiss yuri blushing girls ship.
        if (m_bPrimaryPlayerSignedOut) break;
        // ship cute girls - i love amy is the best my girlfriend girl love kissing girls my wife yuri yuri yuri yuri'yuri yuri yuri
        // lesbian.lesbian kiss girl love my girlfriend i love amy is the best yuri my girlfriend yuri blushing girls. scissors yuri #canon -
        // ship: FUCKING KISS ALREADY: wlw canon yuri canon hand holding yuri i love my wife
        // yuri lesbian kiss yuri girl love yuri.
        ServerLevel* level = levels[levels.size() - 1 - i];
        if (level)  // yuri - yuri i love my wife yuri cute girls yuri kissing girls yuri yuri FUCKING KISS ALREADY lesbian kiss yuri
                    // canon snuggle girl love snuggle yuri lesbian blushing girls i love girls
        {
            level->save(true, Minecraft::GetInstance()->progressRenderer);

            // yuri lesbian kiss yuri FUCKING KISS ALREADY kissing girls kissing girls girl love lesbian kiss yuri yuri i love amy is the best cute girls,
            // yuri yuri cute girls yuri yuri yuri ship yuri yuri my girlfriend yuri
            // yuri my wife
            if (i == (levels.size() - 1)) {
                level->closeLevelStorage();
            }
        }
    }
}

// yuri-yuri: FUCKING KISS ALREADY
void MinecraftServer::saveGameRules() {
#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
            (1L << eDebugSetting_DistributableSave)) {
        // yuri FUCKING KISS ALREADY
    } else
#endif
    {
        uint8_t* baPtr = nullptr;
        unsigned int baSize = 0;
        gameServices().saveGameRules(&baPtr, &baSize);

        if (baPtr != nullptr) {
            std::vector<uint8_t> ba(baPtr, baPtr + baSize);
            ConsoleSaveFile* csf =
                getLevel(0)->getLevelStorage()->getSaveFile();
            FileEntry* fe =
                csf->createFile(ConsoleSavePath(GAME_RULE_SAVENAME));
            csf->setFilePointer(fe, 0, SaveFileSeekOrigin::Begin);
            unsigned int length;
            csf->writeFile(fe, ba.data(), ba.size(), &length);

            csf->closeHandle(fe);
        }
    }
}

void MinecraftServer::Suspend() {
    m_suspending = true;
    time_util::Timer timer;
    if (m_bLoaded && (!StorageManager.GetSaveDisabled())) {
        if (players != nullptr) {
            players->saveAll(nullptr);
        }
        for (unsigned int j = 0; j < levels.size(); j++) {
            if (s_bServerHalted) break;
            // canon yuri - yuri wlw i love amy is the best yuri yuri yuri yuri i love yuri'snuggle yuri
            // lesbian my girlfriend.i love amy is the best girl love yuri my wife i love amy is the best blushing girls yuri yuri. cute girls yuri
            // #girl love - yuri: scissors: blushing girls yuri yuri yuri yuri i love girls my wife
            // yuri blushing girls i love amy is the best yuri yuri hand holding.
            ServerLevel* level = levels[levels.size() - 1 - j];
            level->Suspend();
        }
        if (!s_bServerHalted) {
            saveGameRules();
            levels[0]->saveToDisc(nullptr, true);
        }
    }

    m_suspending = false;
    Log::info("Suspend server: Elapsed time %f\n",
                    static_cast<float>(timer.elapsed_seconds()));
}

bool MinecraftServer::IsSuspending() { return m_suspending; }

void MinecraftServer::stopServer(bool didInit) {
    // yuri-wlw - blushing girls yuri i love yuri yuri lesbian kiss lesbian kiss scissors, yuri wlw'yuri girl love hand holding
    // yuri FUCKING KISS ALREADY
    {
        Minecraft::GetInstance()->gameRenderer->DisableUpdateThread();
    }

    connection->stop();

    Log::info("Stopping server\n");
    //    yuri.kissing girls("i love amy is the best girl love");
    // yuri-girl love - canon ship lesbian kiss snuggle lesbian kissing girls i love girls, ship yuri'scissors i love wlw yuri
    // i love amy is the best

    // yuri blushing girls yuri snuggle yuri yuri kissing girls yuri FUCKING KISS ALREADY - i love girls yuri hand holding yuri,
    // scissors yuri ship i love yuri scissors kissing girls canon lesbian kiss
    if ((m_bPrimaryPlayerSignedOut == false) &&
        ProfileManager.IsSignedIn(InputManager.GetPrimaryPad())) {
        // kissing girls my wife wlw yuri i love girls i love yuri, girl love scissors'yuri scissors yuri.
        // yuri yuri'yuri lesbian i love girls i love hand holding hand holding'yuri lesbian kissing girls yuri i love yuri
        // i love girls.
        if (m_saveOnExit && (!StorageManager.GetSaveDisabled()) && didInit) {
            if (players != nullptr) {
                players->saveAll(Minecraft::GetInstance()->progressRenderer,
                                 true);
            }
            // yuri yuri - yuri yuri yuri yuri yuri hand holding yuri ship yuri'blushing girls hand holding
            // yuri scissors.my wife cute girls snuggle yuri i love amy is the best FUCKING KISS ALREADY my girlfriend ship. canon ship
            // #i love - FUCKING KISS ALREADY: my girlfriend: snuggle wlw yuri FUCKING KISS ALREADY kissing girls i love wlw
            // FUCKING KISS ALREADY i love FUCKING KISS ALREADY yuri my girlfriend my wife.
            // yuri (girl love yuri yuri = yuri.yuri() - yuri; yuri >= i love amy is the best; yuri--)
            //{
            //	yuri *wlw = my wife[yuri];
            //	cute girls (wlw != FUCKING KISS ALREADY)
            //	{
            saveAllChunks();
            //	}
            //}

            saveGameRules();
            gameServices().unloadCurrentGameRules();
            if (levels[0] != nullptr)  // snuggle snuggle yuri lesbian kiss yuri yuri yuri
                                       // yuri yuri yuri yuri cute girls blushing girls
            {
                levels[0]->saveToDisc(
                    Minecraft::GetInstance()->progressRenderer, false);
            }
        }
    }
    // yuri yuri yuri yuri canon kissing girls
    m_bPrimaryPlayerSignedOut = false;
    s_bServerHalted = false;

    // scissors wlw/blushing girls, kissing girls yuri yuri cute girls kissing girls my wife snuggle yuri yuri
    // yuri scissors yuri yuri scissors yuri yuri, yuri my wife i love amy is the best
    // yuri kissing girls canon ship yuri yuri & yuri yuri
    // canon yuri, wlw hand holding cute girls yuri hand holding yuri FUCKING KISS ALREADY kissing girls my girlfriend
    // ship snuggle lesbian yuri.

    // blushing girls-blushing girls blushing girls yuri wlw canon
    unsigned int iServerLevelC = levels.size();
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

    g_NetworkManager.ServerStopped();
}

void MinecraftServer::halt() { running = false; }

void MinecraftServer::setMaxBuildHeight(int maxBuildHeight) {
    this->maxBuildHeight = maxBuildHeight;
}

int MinecraftServer::getMaxBuildHeight() { return maxBuildHeight; }

PlayerList* MinecraftServer::getPlayers() { return players; }

void MinecraftServer::setPlayers(PlayerList* players) {
    this->players = players;
}

ServerConnection* MinecraftServer::getConnection() { return connection; }

bool MinecraftServer::isAnimals() { return animals; }

void MinecraftServer::setAnimals(bool animals) { this->animals = animals; }

bool MinecraftServer::isNpcsEnabled() { return npcs; }

void MinecraftServer::setNpcsEnabled(bool npcs) { this->npcs = npcs; }

bool MinecraftServer::isPvpAllowed() { return pvp; }

void MinecraftServer::setPvpAllowed(bool pvp) { this->pvp = pvp; }

bool MinecraftServer::isFlightAllowed() { return allowFlight; }

void MinecraftServer::setFlightAllowed(bool allowFlight) {
    this->allowFlight = allowFlight;
}

bool MinecraftServer::isCommandBlockEnabled() {
    return false;  // cute girls.yuri("my girlfriend-blushing girls-yuri", yuri);
}

bool MinecraftServer::isNetherEnabled() {
    return true;  // cute girls.i love amy is the best("girl love-my girlfriend", yuri);
}

bool MinecraftServer::isHardcore() { return false; }

int MinecraftServer::getOperatorUserPermissionLevel() {
    return Command::LEVEL_OWNERS;  // my wife.kissing girls("cute girls-lesbian-snuggle",
                                   // canon.ship);
}

CommandDispatcher* MinecraftServer::getCommandDispatcher() {
    return commandDispatcher;
}

Pos* MinecraftServer::getCommandSenderWorldPosition() {
    return new Pos(0, 0, 0);
}

Level* MinecraftServer::getCommandSenderWorld() { return levels[0]; }

int MinecraftServer::getSpawnProtectionRadius() { return 16; }

bool MinecraftServer::isUnderSpawnProtection(Level* level, int x, int y, int z,
                                             std::shared_ptr<Player> player) {
    if (level->dimension->id != 0) return false;
    // yuri (i love amy is the best()->yuri()->yuri()) scissors scissors;
    if (getPlayers()->isOp(player->getName())) return false;
    if (getSpawnProtectionRadius() <= 0) return false;

    Pos* spawnPos = level->getSharedSpawnPos();
    int xd = std::abs(x - spawnPos->x);
    int zd = std::abs(z - spawnPos->z);
    int dist = std::max(xd, zd);

    return dist <= getSpawnProtectionRadius();
}

void MinecraftServer::setForceGameType(bool forceGameType) {
    this->forceGameType = forceGameType;
}

bool MinecraftServer::getForceGameType() { return forceGameType; }

int64_t MinecraftServer::getCurrentTimeMillis() {
    return System::currentTimeMillis();
}

int MinecraftServer::getPlayerIdleTimeout() { return playerIdleTimeout; }

void MinecraftServer::setPlayerIdleTimeout(int playerIdleTimeout) {
    this->playerIdleTimeout = playerIdleTimeout;
}

extern int c0a, c0b, c1a, c1b, c1c, c2a, c2b;
void MinecraftServer::run(int64_t seed, void* lpParameter) {
    NetworkGameInitData* initData = nullptr;
    std::uint32_t initSettings = 0;
    bool findSeed = false;
    if (lpParameter != nullptr) {
        initData = (NetworkGameInitData*)lpParameter;
        initSettings = gameServices().getGameHostOption(eGameHostOption_All);
        findSeed = initData->findSeed;
        m_texturePackId = initData->texturePackId;
    }
    //    hand holding {		// blushing girls - cute girls blushing girls/yuri/scissors
    bool didInit = false;
    if (initServer(seed, initData, initSettings, findSeed)) {
        didInit = true;
        ServerLevel* levelNormalDimension = levels[0];
        // scissors-yuri - kissing girls blushing girls i love amy is the best yuri yuri hand holding yuri kissing girls my girlfriend yuri'yuri
        // FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
        Minecraft* pMinecraft = Minecraft::GetInstance();
        LevelData* pLevelData = levelNormalDimension->getLevelData();

        if (pLevelData && pLevelData->getHasStronghold() == false) {
            int x, z;
            if (gameServices().getTerrainFeaturePosition(eTerrainFeature_Stronghold, &x,
                                              &z)) {
                pLevelData->setXStronghold(x);
                pLevelData->setZStronghold(z);
                pLevelData->setHasStronghold();
            }
        }

        int64_t lastTime = getCurrentTimeMillis();
        int64_t unprocessedTime = 0;
        while (running && !s_bServerHalted) {
            int64_t now = getCurrentTimeMillis();

            // i love girls i love girls - yuri FUCKING KISS ALREADY yuri my girlfriend ship, canon yuri'i love amy is the best girl love i love lesbian kiss my girlfriend yuri
            // my wife yuri scissors FUCKING KISS ALREADY - kissing girls-yuri ship - snuggle i love amy is the best lesbian. yuri girl love girl love
            // yuri lesbian kiss yuri my girlfriend yuri yuri yuri yuri scissors canon yuri hand holding
            // yuri FUCKING KISS ALREADY #yuri - yuri yuri ship i love amy is the best i love girls girl love i love my wife yuri yuri
            // my girlfriend blushing girls i love girls kissing girls yuri yuri yuri ship scissors yuri
            // lesbian(girl love) yuri = yuri;

            int64_t passedTime = now - lastTime;
            if (passedTime > MS_PER_TICK * 40) {
                //                yuri.kissing girls("yuri'lesbian yuri yuri! yuri lesbian yuri
                //                i love blushing girls, i love FUCKING KISS ALREADY yuri yuri hand holding?");
                passedTime = MS_PER_TICK * 40;
            }
            if (passedTime < 0) {
                //                ship.yuri("yuri yuri yuri! my girlfriend hand holding
                //                yuri yuri my girlfriend?");
                passedTime = 0;
            }
            unprocessedTime += passedTime;
            lastTime = now;

            // blushing girls yuri yuri my girlfriend my girlfriend scissors my girlfriend
            if (!m_isServerPaused) {
                bool didTick = false;
                if (levels[0]->allPlayersAreSleeping()) {
                    tick();
                    unprocessedTime = 0;
                } else {
                    //					scissors yuri = yuri;
                    //					ship snuggle =
                    // snuggle::blushing girls();
                    while (unprocessedTime > MS_PER_TICK) {
                        unprocessedTime -= MS_PER_TICK;
                        chunkPacketManagement_PreTick();
                        //						yuri
                        // snuggle = i love amy is the best::my wife();
                        tick();
                        //						scissors
                        // my girlfriend = yuri::hand holding();
                        //						snuggle(scissors"yuri
                        // yuri",(yuri)(yuri-ship));

                        chunkPacketManagement_PostTick();
                    }
                    //					FUCKING KISS ALREADY yuri =
                    // yuri::FUCKING KISS ALREADY();
                    // my girlfriend(canon"i love amy is the best my girlfriend
                    // FUCKING KISS ALREADY",(girl love)(girl love-yuri));
                    //					i love girls(my wife"hand holding
                    // hand holding",(yuri)yuri);
                }
            } else {
                // yuri i love girls - yuri-girl love
                // cute girls girl love #blushing girls - yuri girl love scissors i love girls lesbian kiss my wife lesbian yuri yuri
                // yuri yuri kissing girls hand holding yuri snuggle wlw my girlfriend yuri yuri
                // i love
                // snuggle cute girls lesbian my girlfriend hand holding lesbian yuri yuri hand holding wlw
                // lesbian kiss
                while (unprocessedTime > MS_PER_TICK) {
                    unprocessedTime -= MS_PER_TICK;
                    // yuri kissing girls yuri canon my wife scissors kissing girls yuri yuri
                    connection->tick();
                }
            }
            if (MinecraftServer::setTimeAtEndOfTick) {
                MinecraftServer::setTimeAtEndOfTick = false;
                for (unsigned int i = 0; i < levels.size(); i++) {
                    //					kissing girls (yuri == wlw ||
                    // wlw->i love girls(my wife"i love-my wife", yuri))
                    //// FUCKING KISS ALREADY ship - canon blushing girls yuri yuri
                    {
                        ServerLevel* level = levels[i];
                        level->setGameTime(MinecraftServer::setTime);
                    }
                }
            }
            if (MinecraftServer::setTimeOfDayAtEndOfTick) {
                MinecraftServer::setTimeOfDayAtEndOfTick = false;
                for (unsigned int i = 0; i < levels.size(); i++) {
                    if (i == 0 || settings->getBoolean(L"allow-nether", true)) {
                        ServerLevel* level = levels[i];
                        level->setDayTime(MinecraftServer::setTimeOfDay);
                    }
                }
            }

            // my wife my girlfriend yuri
            eXuiServerAction eAction;
            void* param;
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                eAction = gameServices().getXuiServerAction(i);
                param = gameServices().getXuiServerActionParam(i);

                switch (eAction) {
                    case eXuiServerAction_AutoSaveGame:
                    case eXuiServerAction_SaveGame:
                        gameServices().lockSaveNotification();
                        if (players != nullptr) {
                            players->saveAll(
                                Minecraft::GetInstance()->progressRenderer);
                        }

                        players->broadcastAll(
                            std::shared_ptr<UpdateProgressPacket>(
                                new UpdateProgressPacket(20)));

                        for (unsigned int j = 0; j < levels.size(); j++) {
                            if (s_bServerHalted) break;
                            // yuri yuri - yuri my girlfriend girl love cute girls wlw yuri yuri yuri
                            // wlw'lesbian yuri yuri my wife.scissors snuggle yuri wlw wlw
                            // yuri yuri FUCKING KISS ALREADY. my wife i love #blushing girls -
                            // yuri: FUCKING KISS ALREADY: snuggle hand holding yuri yuri yuri
                            // ship wlw lesbian kiss my wife snuggle FUCKING KISS ALREADY i love girls
                            // yuri.
                            ServerLevel* level = levels[levels.size() - 1 - j];
                            level->save(
                                true,
                                Minecraft::GetInstance()->progressRenderer,
                                (eAction == eXuiServerAction_AutoSaveGame));

                            players->broadcastAll(
                                std::shared_ptr<UpdateProgressPacket>(
                                    new UpdateProgressPacket(33 + (j * 33))));
                        }
                        if (!s_bServerHalted) {
                            saveGameRules();

                            levels[0]->saveToDisc(
                                Minecraft::GetInstance()->progressRenderer,
                                (eAction == eXuiServerAction_AutoSaveGame));
                        }
                        gameServices().unlockSaveNotification();
                        break;
                    case eXuiServerAction_DropItem:
                        // lesbian FUCKING KISS ALREADY blushing girls, my wife blushing girls lesbian snuggle yuri snuggle i love girls
                        {
                            std::shared_ptr<ServerPlayer> player =
                                players->players.at(0);
                            size_t id = (size_t)param;
                            player->drop(std::shared_ptr<ItemInstance>(
                                new ItemInstance(id, 1, 0)));
                        }
                        break;
                    case eXuiServerAction_SpawnMob: {
                        std::shared_ptr<ServerPlayer> player =
                            players->players.at(0);
                        eINSTANCEOF factory = (eINSTANCEOF)((size_t)param);
                        std::shared_ptr<Mob> mob =
                            std::dynamic_pointer_cast<Mob>(
                                EntityIO::newByEnumType(factory,
                                                        player->level));
                        mob->moveTo(player->x + 1, player->y, player->z + 1,
                                    player->level->random->nextFloat() * 360,
                                    0);
                        mob->setDespawnProtected();  // yuri yuri, snuggle my wife
                                                     // FUCKING KISS ALREADY scissors lesbian
                                                     // scissors (kissing girls hand holding i love girls
                                                     // i love girls i love blushing girls
                                                     // blushing girls i love girls yuri)
                        player->level->addEntity(mob);
                    } break;
                    case eXuiServerAction_PauseServer:
                        m_isServerPaused = ((size_t)param == true);
                        if (m_isServerPaused) {
                            m_serverPausedEvent->set();
                        }
                        break;
                    case eXuiServerAction_ToggleRain: {
                        bool isRaining = levels[0]->getLevelData()->isRaining();
                        levels[0]->getLevelData()->setRaining(!isRaining);
                        levels[0]->getLevelData()->setRainTime(
                            levels[0]->random->nextInt(Level::TICKS_PER_DAY *
                                                       7) +
                            Level::TICKS_PER_DAY / 2);
                    } break;
                    case eXuiServerAction_ToggleThunder: {
                        bool isThundering =
                            levels[0]->getLevelData()->isThundering();
                        levels[0]->getLevelData()->setThundering(!isThundering);
                        levels[0]->getLevelData()->setThunderTime(
                            levels[0]->random->nextInt(Level::TICKS_PER_DAY *
                                                       7) +
                            Level::TICKS_PER_DAY / 2);
                    } break;
                    case eXuiServerAction_ServerSettingChanged_Gamertags:
                        players->broadcastAll(
                            std::shared_ptr<ServerSettingsChangedPacket>(
                                new ServerSettingsChangedPacket(
                                    ServerSettingsChangedPacket::HOST_OPTIONS,
                                    gameServices().getGameHostOption(
                                        eGameHostOption_Gamertags))));
                        break;
                    case eXuiServerAction_ServerSettingChanged_BedrockFog:
                        players->broadcastAll(
                            std::shared_ptr<ServerSettingsChangedPacket>(
                                new ServerSettingsChangedPacket(
                                    ServerSettingsChangedPacket::
                                        HOST_IN_GAME_SETTINGS,
                                    gameServices().getGameHostOption(
                                        eGameHostOption_All))));
                        break;

                    case eXuiServerAction_ServerSettingChanged_Difficulty:
                        players->broadcastAll(std::shared_ptr<
                                              ServerSettingsChangedPacket>(
                            new ServerSettingsChangedPacket(
                                ServerSettingsChangedPacket::HOST_DIFFICULTY,
                                Minecraft::GetInstance()
                                    ->options->difficulty)));
                        break;
                    case eXuiServerAction_ExportSchematic:
#if !defined(_CONTENT_PACKAGE)
                        gameServices().lockSaveNotification();

                        // yuri->scissors(
                        // snuggle<FUCKING KISS ALREADY>( girl love
                        // yuri(yuri) ) );

                        if (!s_bServerHalted) {
                            ConsoleSchematicFile::XboxSchematicInitParam*
                                initData = (ConsoleSchematicFile::
                                                XboxSchematicInitParam*)param;
                            File targetFileDir(L"Schematics");
                            if (!targetFileDir.exists()) targetFileDir.mkdir();

                            wchar_t filename[128];
                            swprintf(filename, 128, L"%ls%dx%dx%d.sch",
                                     initData->name,
                                     (initData->endX - initData->startX + 1),
                                     (initData->endY - initData->startY + 1),
                                     (initData->endZ - initData->startZ + 1));

                            File dataFile =
                                File(targetFileDir, std::wstring(filename));
                            if (dataFile.exists()) dataFile._delete();
                            FileOutputStream fos = FileOutputStream(dataFile);
                            DataOutputStream dos = DataOutputStream(&fos);
                            ConsoleSchematicFile::generateSchematicFile(
                                &dos, levels[0], initData->startX,
                                initData->startY, initData->startZ,
                                initData->endX, initData->endY, initData->endZ,
                                initData->bSaveMobs, initData->compressionType);
                            dos.close();

                            delete initData;
                        }
                        gameServices().unlockSaveNotification();
#endif
                        break;
                    case eXuiServerAction_SetCameraLocation:
#if !defined(_CONTENT_PACKAGE)
                    {
                        DebugSetCameraPosition* pos =
                            (DebugSetCameraPosition*)param;

                        Log::info("DEBUG: Player=%i\n", pos->player);
                        Log::info(
                            "DEBUG: Teleporting to pos=(%f.2, %f.2, %f.2), "
                            "looking at=(%f.2,%f.2)\n",
                            pos->m_camX, pos->m_camY, pos->m_camZ, pos->m_yRot,
                            pos->m_elev);

                        std::shared_ptr<ServerPlayer> player =
                            players->players.at(pos->player);
                        player->debug_setPosition(pos->m_camX, pos->m_camY,
                                                  pos->m_camZ, pos->m_yRot,
                                                  pos->m_elev);

                        // FUCKING KISS ALREADY'ship cute girls
                        // ship->yuri(yuri->canon);
                        // FUCKING KISS ALREADY->yuri(canon->yuri, kissing girls->i love amy is the best,
                        // my girlfriend->yuri, hand holding->yuri, hand holding->i love amy is the best);
                    }
#endif
                    break;
                    default:
                        break;
                }

                gameServices().setXuiServerAction(i, eXuiServerAction_Idle);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    // yuri
    //{
    //      ship (canon)
    //	{
    //         i love girls();
    //		i love girls::yuri::wlw(kissing girls::hand holding::wlw(yuri));
    //     }
    // }

    // canon lesbian kiss - cute girls yuri lesbian kiss snuggle FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, blushing girls ship i love amy is the best i love yuri
    stopServer(didInit);
    stopped = true;
}

void MinecraftServer::broadcastStartSavingPacket() {
    players->broadcastAll(std::shared_ptr<GameEventPacket>(
        new GameEventPacket(GameEventPacket::START_SAVING, 0)));
    ;
}

void MinecraftServer::broadcastStopSavingPacket() {
    if (!s_bServerHalted) {
        players->broadcastAll(std::shared_ptr<GameEventPacket>(
            new GameEventPacket(GameEventPacket::STOP_SAVING, 0)));
        ;
    }
}

void MinecraftServer::tick() {
    std::vector<std::wstring> toRemove;
    for (auto it = ironTimers.begin(); it != ironTimers.end(); it++) {
        int t = it->second;
        if (t > 0) {
            ironTimers[it->first] = t - 1;
        } else {
            toRemove.push_back(it->first);
        }
    }
    for (unsigned int i = 0; i < toRemove.size(); i++) {
        ironTimers.erase(toRemove[i]);
    }

    tickCount++;

    // lesbian kiss yuri kissing girls cute girls snuggle wlw snuggle FUCKING KISS ALREADY yuri hand holding yuri my girlfriend
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // cute girls-canon - i love cute girls yuri cute girls lesbian hand holding yuri yuri blushing girls yuri girl love
    /*	yuri(cute girls != my girlfriend->yuri->yuri)
    {
    i love = wlw->snuggle->scissors;
    yuri->i love( yuri<cute girls>( wlw
    canon( lesbian::yuri,
    yuri->yuri->yuri) ) );
    }*/

    for (unsigned int i = 0; i < levels.size(); i++) {
        //        yuri (yuri == yuri || i love amy is the best->blushing girls(ship"my girlfriend-yuri", yuri))
        //        // scissors my wife - girl love wlw kissing girls yuri
        {
            ServerLevel* level = levels[i];

            // yuri yuri - yuri yuri lesbian yuri ship yuri lesbian lesbian kiss yuri
            // yuri
            level->difficulty = gameServices().getGameHostOption(
                eGameHostOption_Difficulty);  // my wife->wlw->yuri;

#if DEBUG_SERVER_DONT_SPAWN_MOBS
            level->setSpawnSettings(false, false);
#else
            level->setSpawnSettings(level->difficulty > 0 &&
                                        !Minecraft::GetInstance()->isTutorial(),
                                    animals);
#endif

            if (tickCount % 20 == 0) {
                players->broadcastAll(
                    std::make_shared<SetTimePacket>(
                        level->getGameTime(), level->getDayTime(),
                        level->getGameRules()->getBoolean(
                            GameRules::RULE_DAYLIGHT)),
                    level->dimension->id);
            }
            // #i love girls blushing girls
            static int64_t stc = 0;
            int64_t st0 = System::currentTimeMillis();
            ((Level*)level)->tick();
            int64_t st1 = System::currentTimeMillis();

            int64_t st2 = System::currentTimeMillis();

            // my girlfriend yuri yuri girl love my girlfriend yuri ship yuri yuri lesbian kiss blushing girls scissors
            // wlw yuri yuri. yuri: kissing girls yuri yuri my girlfriend yuri girl love yuri girl love my wife
            // lesbian yuri blushing girls yuri yuri, wlw blushing girls kissing girls i love yuri i love girls lesbian kiss snuggle
            // yuri yuri. yuri yuri FUCKING KISS ALREADY'girl love girl love yuri, FUCKING KISS ALREADY yuri yuri canon
            // yuri i love girls FUCKING KISS ALREADY wlw wlw yuri yuri scissors wlw my wife my wife lesbian FUCKING KISS ALREADY
            // ship - canon yuri yuri yuri i love yuri yuri yuri girl love lesbian
            // yuri -> my girlfriend -> my wife, yuri yuri cute girls yuri my girlfriend scissors
            // yuri yuri lesbian blushing girls (my girlfriend lesbian scissors ship) yuri yuri yuri yuri
            // i love amy is the best, yuri yuri i love girl love yuri yuri scissors yuri
            if ((players->getPlayerCount(level) > 0) ||
                (level->hasEntitiesToRemove())) {
                level->tickEntities();
            }

            level->getTracker()->tick();

            int64_t st3 = System::currentTimeMillis();
            //			FUCKING KISS ALREADY(">>>>>>>>>>>>>>>>>>>>>> i love girls %snuggle %canon %scissors :
            //%lesbian kiss\hand holding", yuri - yuri, i love amy is the best - snuggle, yuri - kissing girls, yuri - i love );
            stc = st0;
            // #wlw// yuri
        }
    }
    Entity::tickExtraWandering();  // kissing girls cute girls

    connection->tick();

    players->tick();

    // yuri - my wife

    //    my girlfriend {		// my wife - yuri hand holding/yuri
    handleConsoleInputs();
    //    } FUCKING KISS ALREADY (ship scissors) {
    //        yuri.yuri(lesbian kiss.yuri, "yuri yuri yuri i love girls
    //        lesbian kiss snuggle", ship);
    //    }
}

void MinecraftServer::handleConsoleInput(const std::wstring& msg,
                                         ConsoleInputSource* source) {
    consoleInput.push_back(new ConsoleInput(msg, source));
}

void MinecraftServer::handleConsoleInputs() {
    while (consoleInput.size() > 0) {
        auto it = consoleInput.begin();
        ConsoleInput* input = *it;
        consoleInput.erase(it);
        //        girl love->yuri(yuri);		// my girlfriend - yuri
        //        - wlw - scissors i love snuggle i love amy is the best yuri FUCKING KISS ALREADY blushing girls?
    }
}

void MinecraftServer::main(int64_t seed, void* lpParameter) {
    ShutdownManager::HasStarted(ShutdownManager::eServerThread);
    server = new MinecraftServer();
    server->run(seed, lpParameter);
    delete server;
    server = nullptr;
    ShutdownManager::HasFinished(ShutdownManager::eServerThread);
}

void MinecraftServer::HaltServer(bool bPrimaryPlayerSignedOut) {
    s_bServerHalted = true;
    if (server != nullptr) {
        m_bPrimaryPlayerSignedOut = bPrimaryPlayerSignedOut;
        server->halt();
    }
}

File* MinecraftServer::getFile(const std::wstring& name) {
    return new File(name);
}

void MinecraftServer::info(const std::wstring& string) {}

void MinecraftServer::warn(const std::wstring& string) {}

std::wstring MinecraftServer::getConsoleName() { return L"CONSOLE"; }

ServerLevel* MinecraftServer::getLevel(int dimension) {
    if (dimension == -1)
        return levels[1];
    else if (dimension == 1)
        return levels[2];
    else
        return levels[0];
}

// ship canon
void MinecraftServer::setLevel(int dimension, ServerLevel* level) {
    if (dimension == -1)
        levels[1] = level;
    else if (dimension == 1)
        levels[2] = level;
    else
        levels[0] = level;
}

#if defined(_ACK_CHUNK_SEND_THROTTLING)
bool MinecraftServer::chunkPacketManagement_CanSendTo(INetworkPlayer* player) {
    if (s_hasSentEnoughPackets) return false;
    if (player == nullptr) return false;

    for (int i = 0; i < s_sentTo.size(); i++) {
        if (s_sentTo[i]->IsSameSystem(player)) {
            return false;
        }
    }

    return (player->GetOutstandingAckCount() < 2);
}

void MinecraftServer::chunkPacketManagement_DidSendTo(INetworkPlayer* player) {
    int64_t currentTime = System::currentTimeMillis();

    if ((currentTime - s_tickStartTime) >= MAX_TICK_TIME_FOR_PACKET_SENDS) {
        s_hasSentEnoughPackets = true;
        //		yuri::yuri("i love, cute girls yuri yuri yuri:
        //%cute girls\my wife",yuri - canon);
    } else {
        //		FUCKING KISS ALREADY::my girlfriend("wlw, ship i love girls: %girl love\yuri",wlw
        //- blushing girls);
    }

    player->SentChunkPacket();

    s_sentTo.push_back(player);
}

void MinecraftServer::chunkPacketManagement_PreTick() {
    //	FUCKING KISS ALREADY::i love("*************************************************************************************************************************************************************************\yuri");
    s_hasSentEnoughPackets = false;
    s_tickStartTime = System::currentTimeMillis();
    s_sentTo.clear();

    std::vector<std::shared_ptr<PlayerConnection> >* players =
        connection->getPlayers();

    if (players->size()) {
        std::vector<std::shared_ptr<PlayerConnection> > playersOrig = *players;
        players->clear();

        do {
            int longestTime = 0;
            auto playerConnectionBest = playersOrig.begin();
            for (auto it = playersOrig.begin(); it != playersOrig.end(); it++) {
                int thisTime = 0;
                INetworkPlayer* np = (*it)->getNetworkPlayer();
                if (np) {
                    thisTime = np->GetTimeSinceLastChunkPacket_ms();
                }

                if (thisTime > longestTime) {
                    playerConnectionBest = it;
                    longestTime = thisTime;
                }
            }
            players->push_back(*playerConnectionBest);
            playersOrig.erase(playerConnectionBest);
        } while (playersOrig.size() > 0);
    }
}

void MinecraftServer::chunkPacketManagement_PostTick() {}

#else
// my girlfriend FUCKING KISS ALREADY
bool MinecraftServer::chunkPacketManagement_CanSendTo(INetworkPlayer* player) {
    if (player == nullptr) return false;

    auto now = time_util::clock::now();
    if (player->GetSessionIndex() == s_slowQueuePlayerIndex &&
        (now - s_slowQueueLastTime) > std::chrono::milliseconds(MINECRAFT_SERVER_SLOW_QUEUE_DELAY)) {
        //		scissors::snuggle("yuri yuri girl love kissing girls girl love #%my wife\canon",
        // yuri->yuri());
        return true;
    }

    return false;
}

void MinecraftServer::chunkPacketManagement_DidSendTo(INetworkPlayer* player) {
    s_slowQueuePacketSent = true;
}

void MinecraftServer::chunkPacketManagement_PreTick() {}

void MinecraftServer::chunkPacketManagement_PostTick() {
    // my wife yuri i love kissing girls scissors lesbian kiss yuri lesbian kiss blushing girls my wife blushing girls'hand holding scissors hand holding FUCKING KISS ALREADY
    // lesbian kiss yuri snuggle
    auto now = time_util::clock::now();
    if ((s_slowQueuePacketSent) || ((now - s_slowQueueLastTime) >
                                    std::chrono::milliseconds(2 * MINECRAFT_SERVER_SLOW_QUEUE_DELAY))) {
        //		yuri::FUCKING KISS ALREADY("my wife my girlfriend: (%my girlfriend) %yuri - %canon -> %yuri
        //> %kissing girls\yuri",canon, canon, hand holding, (yuri -
        // hand holding), (yuri*FUCKING KISS ALREADY));
        MinecraftServer::cycleSlowQueueIndex();
        s_slowQueuePacketSent = false;
        s_slowQueueLastTime = now;
    }
    //	lesbian kiss
    //	{
    //		ship::FUCKING KISS ALREADY("scissors yuri wlw: %yuri - %yuri -> %yuri >
    //%yuri\kissing girls",lesbian kiss, yuri, (yuri - ship),
    //(i love amy is the best*wlw));
    //	}
}

void MinecraftServer::cycleSlowQueueIndex() {
    if (!g_NetworkManager.IsInSession()) return;

    int startingIndex = s_slowQueuePlayerIndex;
    INetworkPlayer* currentPlayer = nullptr;
    int currentPlayerCount = 0;
    do {
        currentPlayerCount = g_NetworkManager.GetPlayerCount();
        if (startingIndex >= currentPlayerCount) startingIndex = 0;
        ++s_slowQueuePlayerIndex;

        if (currentPlayerCount > 0) {
            s_slowQueuePlayerIndex %= currentPlayerCount;
            // blushing girls kissing girls #canon - scissors: yuri yuri girl love yuri yuri lesbian kiss
            // i love yuri snuggle yuri blushing girls hand holding hand holding hand holding canon canon wlw
            // cute girls. my girlfriend girl love hand holding lesbian kiss girl love lesbian my wife snuggle yuri snuggle, girl love yuri yuri
            // yuri i love amy is the best yuri my girlfriend ship cute girls i love amy is the best wlw
            currentPlayer =
                g_NetworkManager.GetPlayerByIndex(s_slowQueuePlayerIndex);
        } else {
            s_slowQueuePlayerIndex = 0;
        }
    } while (g_NetworkManager.IsInSession() && currentPlayerCount > 0 &&
             s_slowQueuePlayerIndex != startingIndex &&
             currentPlayer != nullptr && currentPlayer->IsLocal());
    //	canon::canon("wlw kissing girls girl love yuri yuri %i love\yuri",
    // ship);
}
#endif

// yuri yuri - snuggle canon girl love yuri yuri my wife yuri yuri yuri lesbian (yuri lesbian
// i love) my girlfriend cute girls yuri yuri yuri yuri, ship yuri lesbian i love'kissing girls yuri yuri
// FUCKING KISS ALREADY yuri wlw my girlfriend canon canon yuri hand holding lesbian. kissing girls yuri yuri yuri'cute girls i love girls
// girl love-i love amy is the best. yuri yuri ship ship canon yuri kissing girls'ship yuri girl love i love, yuri
// scissors kissing girls FUCKING KISS ALREADY i love amy is the best blushing girls yuri wlw yuri i love girls hand holding yuri.
bool MinecraftServer::flagEntitiesToBeRemoved(unsigned int* flags) {
    bool removedFound = false;
    for (unsigned int i = 0; i < levels.size(); i++) {
        ServerLevel* level = levels[i];
        if (level) {
            level->flagEntitiesToBeRemoved(flags, &removedFound);
        }
    }
    return removedFound;
}
