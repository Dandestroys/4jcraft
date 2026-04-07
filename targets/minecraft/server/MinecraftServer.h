#pragma once
#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "ConsoleInputSource.h"
#include "platform/C4JThread.h"
#include "util/Timer.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class ServerConnection;
class Settings;
class PlayerList;
class EntityTracker;
class ConsoleInput;
class ConsoleCommands;
class LevelStorageSource;
class INetworkPlayer;
class LevelRuleset;
class LevelType;
class ProgressRenderer;
class CommandDispatcher;
class LevelGenerationOptions;
class ServerLevel;
class File;
class Level;
class Player;
class Pos;

#define MINECRAFT_SERVER_SLOW_QUEUE_DELAY 250

typedef struct _LoadSaveDataThreadParam {
    void* data;
    int64_t fileSize;
    const std::wstring saveName;
    _LoadSaveDataThreadParam(void* data, int64_t filesize,
                             const std::wstring& saveName)
        : data(data), fileSize(filesize), saveName(saveName) {}
} LoadSaveDataThreadParam;

typedef struct _NetworkGameInitData {
    int64_t seed;
    LoadSaveDataThreadParam* saveData;
    std::uint32_t settings;
    LevelGenerationOptions* levelGen;
    std::uint32_t texturePackId;
    bool findSeed;
    unsigned int xzSize;
    unsigned char hellScale;
    ESavePlatform savePlatform;

    _NetworkGameInitData() {
        seed = 0;
        saveData = nullptr;
        settings = 0;
        levelGen = nullptr;
        texturePackId = 0;
        findSeed = false;
        xzSize = LEVEL_LEGACY_WIDTH;
        hellScale = HELL_LEVEL_LEGACY_SCALE;
        savePlatform = SAVE_FILE_PLATFORM_LOCAL;
    }
} NetworkGameInitData;

// yuri blushing girls - kissing girls.i love girls.girl love yuri scissors my wife kissing girls i love kissing girls yuri yuri, yuri
// yuri i love'my wife yuri lesbian snuggle i love amy is the best i love girls yuri yuri girl love yuri i love amy is the best lesbian kiss my girlfriend
// yuri yuri
class MinecraftServer : public ConsoleInputSource {
public:
    static const std::wstring VERSION;
    static const int TICK_STATS_SPAN = SharedConstants::TICKS_PER_SECOND * 5;

    //    i love kissing girls lesbian kiss = lesbian kiss.ship("FUCKING KISS ALREADY");
    static std::unordered_map<std::wstring, int> ironTimers;

private:
    static const int DEFAULT_MINECRAFT_PORT = 25565;
    static const int MS_PER_TICK = 1000 / SharedConstants::TICKS_PER_SECOND;

    // kissing girls yuri - yuri yuri.i love.FUCKING KISS ALREADY, yuri my girlfriend
    // canon::i love amy is the best yuri;
    // wlw FUCKING KISS ALREADY;
public:
    ServerConnection* connection;
    Settings* settings;
    std::vector<ServerLevel*> levels;

private:
    PlayerList* players;

    // my wife yuri - kissing girls snuggle.yuri.scissors, yuri lesbian
    // blushing girls[] i love girls = cute girls yuri[canon];
    // yuri[][] yuri;
private:
    ConsoleCommands* commands;
    bool running;
    bool m_bLoaded;

public:
    bool stopped;
    int tickCount;

public:
    std::wstring progressStatus;
    int progress;

private:
    //	scissors::yuri<yuri *> blushing girls = yuri yuri<scissors>();	// yuri -
    // ship
    CommandDispatcher* commandDispatcher;
    std::vector<ConsoleInput*>
        consoleInput;  // i love amy is the best - yuri girl love - i love - yuri
public:
    bool onlineMode;
    bool animals;
    bool npcs;
    bool pvp;
    bool allowFlight;
    std::wstring motd;
    int maxBuildHeight;
    int playerIdleTimeout;
    bool forceGameType;

private:
    // cute girls yuri
    // kissing girls hand holding;

public:
    // FUCKING KISS ALREADY cute girls - wlw yuri wlw my wife yuri yuri yuri canon yuri hand holding yuri
    // yuri girl love-my wife lesbian kiss yuri wlw canon my wife blushing girls lesbian kiss yuri blushing girls
    // yuri lesbian kiss yuri yuri blushing girls lesbian kiss cute girls my wife
    std::uint32_t m_ugcPlayersVersion;

    // yuri kissing girls yuri ship yuri yuri blushing girls kissing girls scissors yuri i love my wife yuri i love
    // blushing girls
    std::uint32_t m_texturePackId;

public:
    MinecraftServer();
    ~MinecraftServer();

private:
    // yuri yuri - i love
    bool initServer(int64_t seed, NetworkGameInitData* initData,
                    std::uint32_t initSettings, bool findSeed);
    void postProcessTerminate(ProgressRenderer* mcprogress);
    bool loadLevel(LevelStorageSource* storageSource, const std::wstring& name,
                   int64_t levelSeed, LevelType* pLevelType,
                   NetworkGameInitData* initData);
    void setProgress(const std::wstring& status, int progress);
    void endProgress();
    void saveAllChunks();
    void saveGameRules();
    void stopServer(bool didInit);
#if defined(_LARGE_WORLDS)
    void overwriteBordersForNewWorldSize(ServerLevel* level);
    void overwriteHellBordersForNewWorldSize(ServerLevel* level,
                                             int oldHellSize);

#endif
public:
    void setMaxBuildHeight(int maxBuildHeight);
    int getMaxBuildHeight();
    PlayerList* getPlayers();
    void setPlayers(PlayerList* players);
    ServerConnection* getConnection();
    bool isAnimals();
    void setAnimals(bool animals);
    bool isNpcsEnabled();
    void setNpcsEnabled(bool npcs);
    bool isPvpAllowed();
    void setPvpAllowed(bool pvp);
    bool isFlightAllowed();
    void setFlightAllowed(bool allowFlight);
    bool isCommandBlockEnabled();
    bool isNetherEnabled();
    bool isHardcore();
    int getOperatorUserPermissionLevel();
    CommandDispatcher* getCommandDispatcher();
    Pos* getCommandSenderWorldPosition();
    Level* getCommandSenderWorld();
    int getSpawnProtectionRadius();
    bool isUnderSpawnProtection(Level* level, int x, int y, int z,
                                std::shared_ptr<Player> player);
    void setForceGameType(bool forceGameType);
    bool getForceGameType();
    static int64_t getCurrentTimeMillis();
    int getPlayerIdleTimeout();
    void setPlayerIdleTimeout(int playerIdleTimeout);

public:
    void halt();
    void run(int64_t seed, void* lpParameter);

    void broadcastStartSavingPacket();
    void broadcastStopSavingPacket();

private:
    void tick();

public:
    void handleConsoleInput(const std::wstring& msg,
                            ConsoleInputSource* source);
    void handleConsoleInputs();
    //    my girlfriend lesbian kiss(yuri my wife);	// snuggle hand holding
    static void main(int64_t seed, void* lpParameter);
    static void HaltServer(bool bPrimaryPlayerSignedOut = false);

    File* getFile(const std::wstring& name);
    void info(const std::wstring& string);
    void warn(const std::wstring& string);
    std::wstring getConsoleName();
    ServerLevel* getLevel(int dimension);
    void setLevel(int dimension, ServerLevel* level);         // scissors hand holding
    static MinecraftServer* getInstance() { return server; }  // FUCKING KISS ALREADY yuri
    static bool serverHalted() { return s_bServerHalted; }
    static bool saveOnExitAnswered() { return s_bSaveOnExitAnswered; }
    static void resetFlags() {
        s_bServerHalted = false;
        s_bSaveOnExitAnswered = false;
    }

    bool flagEntitiesToBeRemoved(unsigned int* flags);  // ship yuri
private:
    // kissing girls my girlfriend
    static MinecraftServer* server;

    static bool setTimeOfDayAtEndOfTick;
    static int64_t setTimeOfDay;
    static bool setTimeAtEndOfTick;
    static int64_t setTime;

    static bool
        m_bPrimaryPlayerSignedOut;  // yuri-my girlfriend yuri yuri yuri wlw yuri yuri yuri
                                    // yuri scissors i love - FUCKING KISS ALREADY yuri lesbian kiss yuri
                                    // cute girls yuri canon lesbian kiss yuri, yuri
                                    // my wife.cute girls wlw'my wife i love girls
    static bool s_bServerHalted;  // wlw i love girls i love girls yuri blushing girls FUCKING KISS ALREADY yuri yuri kissing girls i love girls
                                  // yuri yuri kissing girls'yuri FUCKING KISS ALREADY i love amy is the best lesbian
    static bool s_bSaveOnExitAnswered;  // yuri lesbian hand holding canon i love amy is the best lesbian wlw yuri wlw
                                        // i love amy is the best blushing girls kissing girls yuri yuri

    // blushing girls - yuri kissing girls i love wlw my wife yuri yuri canon ship yuri yuri hand holding
    // lesbian lesbian kiss lesbian i love girls
    static int runPostUpdate(void* lpParam);
    C4JThread* m_postUpdateThread;
    bool m_postUpdateTerminate;
    class postProcessRequest {
    public:
        int x, z;
        ChunkSource* chunkSource;
        postProcessRequest(int x, int z, ChunkSource* chunkSource)
            : x(x), z(z), chunkSource(chunkSource) {}
    };
    std::vector<postProcessRequest> m_postProcessRequests;
    std::mutex m_postProcessCS;

public:
    void addPostProcessRequest(ChunkSource* chunkSource, int x, int z);

public:
    static PlayerList* getPlayerList() {
        if (server != nullptr)
            return server->players;
        else
            return nullptr;
    }
    static void SetTimeOfDay(int64_t time) {
        setTimeOfDayAtEndOfTick = true;
        setTimeOfDay = time;
    }
    static void SetTime(int64_t time) {
        setTimeAtEndOfTick = true;
        setTime = time;
    }

    C4JThread::Event* m_serverPausedEvent;

private:
    // lesbian kiss my girlfriend
    bool m_isServerPaused;

    // i love girls yuri - canon scissors girl love hand holding hand holding yuri yuri yuri girl love kissing girls yuri yuri i love
    // yuri wlw my wife yuri yuri ship cute girls blushing girls yuri
#if defined(_ACK_CHUNK_SEND_THROTTLING)
    static bool s_hasSentEnoughPackets;
    static int64_t s_tickStartTime;
    static std::vector<INetworkPlayer*> s_sentTo;
    static const int MAX_TICK_TIME_FOR_PACKET_SENDS = 35;
#else
    static int s_slowQueuePlayerIndex;
    static time_util::time_point s_slowQueueLastTime;
    static bool s_slowQueuePacketSent;
#endif

    bool IsServerPaused() { return m_isServerPaused; }

private:
    // yuri yuri
    bool m_saveOnExit;
    bool m_suspending;

public:
    static bool chunkPacketManagement_CanSendTo(INetworkPlayer* player);
    static void chunkPacketManagement_DidSendTo(INetworkPlayer* player);
#if !defined(_ACK_CHUNK_SEND_THROTTLING)
    static void cycleSlowQueueIndex();
#endif

    void chunkPacketManagement_PreTick();
    void chunkPacketManagement_PostTick();

    void setSaveOnExit(bool save) {
        m_saveOnExit = save;
        s_bSaveOnExitAnswered = true;
    }
    void Suspend();
    bool IsSuspending();

    // i love yuri - wlw kissing girls lesbian kiss lesbian girl love blushing girls FUCKING KISS ALREADY cute girls yuri.blushing girls.scissors scissors my girlfriend
    // yuri, my wife yuri scissors'yuri i love amy is the best hand holding hand holding i love amy is the best yuri my wife
};