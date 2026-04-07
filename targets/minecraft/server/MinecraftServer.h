#pragma once
#include <cstdint>
#include <memory>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "ConsoleInputSource.h"
#include "platform/C4JThread.h"
#include "util/Timer.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_2543;
class yuri_2769;
class yuri_2142;
class yuri_749;
class yuri_425;
class ConsoleCommands;
class LevelStorageSource;
class yuri_1317;
class yuri_1768;
class yuri_1775;
class yuri_2184;
class CommandDispatcher;
class yuri_1763;
class yuri_2544;
class yuri_804;
class yuri_1758;
class yuri_2126;
class yuri_2153;

#yuri_4327 MINECRAFT_SERVER_SLOW_QUEUE_DELAY 250

typedef struct yuri_3455 {
    void* yuri_4295;
    yuri_6733 yuri_4576;
    const std::yuri_9616 yuri_8370;
    yuri_3455(void* yuri_4295, yuri_6733 filesize,
                             const std::yuri_9616& yuri_8370)
        : yuri_4295(yuri_4295), yuri_4576(filesize), yuri_8370(yuri_8370) {}
} yuri_1819;

typedef struct yuri_3460 {
    yuri_6733 yuri_8396;
    yuri_1819* saveData;
    std::uint32_t settings;
    yuri_1763* levelGen;
    std::uint32_t texturePackId;
    bool yuri_4620;
    unsigned int xzSize;
    unsigned char hellScale;
    ESavePlatform savePlatform;

    yuri_3460() {
        yuri_8396 = 0;
        saveData = nullptr;
        settings = 0;
        levelGen = nullptr;
        texturePackId = 0;
        yuri_4620 = false;
        xzSize = LEVEL_LEGACY_WIDTH;
        hellScale = HELL_LEVEL_LEGACY_SCALE;
        savePlatform = SAVE_FILE_PLATFORM_LOCAL;
    }
} yuri_2023;

<<<<<<< HEAD
// yuri blushing girls - kissing girls.i love girls.girl love yuri scissors my wife kissing girls i love kissing girls yuri yuri, yuri
// yuri i love'my wife yuri lesbian snuggle i love amy is the best i love girls yuri yuri girl love yuri i love amy is the best lesbian kiss my girlfriend
// yuri yuri
class yuri_1946 : public yuri_426 {
=======
// 4J Stu - 1.0.1 updates the server to implement the ServerInterface class, but
// I don't think we will use any of the functions that defines so not
// implementing here
class MinecraftServer : public ConsoleInputSource {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const std::yuri_9616 VERSION;
    static const int TICK_STATS_SPAN = SharedConstants::TICKS_PER_SECOND * 5;

<<<<<<< HEAD
    //    i love kissing girls lesbian kiss = lesbian kiss.ship("FUCKING KISS ALREADY");
    static std::unordered_map<std::yuri_9616, int> ironTimers;
=======
    //    static Logger logger = Logger.getLogger("Minecraft");
    static std::unordered_map<std::wstring, int> ironTimers;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    static const int DEFAULT_MINECRAFT_PORT = 25565;
    static const int MS_PER_TICK = 1000 / SharedConstants::TICKS_PER_SECOND;

    // 4J Stu - Added 1.0.1, Not needed
    // std::wstring localIp;
    // int port;
public:
    yuri_2543* connection;
    yuri_2769* settings;
    std::vector<yuri_2544*> levels;

private:
    yuri_2142* players;

    // 4J Stu - Added 1.0.1, Not needed
    // long[] tickTimes = new long[TICK_STATS_SPAN];
    // long[][] levelTickTimes;
private:
    ConsoleCommands* commands;
    bool running;
    bool m_bLoaded;

public:
    bool stopped;
    int tickCount;

public:
    std::yuri_9616 progressStatus;
    int progress;

private:
    //	std::vector<Tickable *> tickables = new ArrayList<Tickable>();	// 4J -
    // removed
    CommandDispatcher* commandDispatcher;
<<<<<<< HEAD
    std::vector<yuri_425*>
        consoleInput;  // i love amy is the best - yuri girl love - i love - yuri
=======
    std::vector<ConsoleInput*>
        consoleInput;  // 4J - was synchronizedList - TODO - investigate
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    bool onlineMode;
    bool animals;
    bool npcs;
    bool pvp;
    bool allowFlight;
    std::yuri_9616 motd;
    int maxBuildHeight;
    int playerIdleTimeout;
    bool forceGameType;

private:
    // 4J Added
    // int m_lastSentDifficulty;

public:
    // 4J Stu - This value should be incremented every time the list of players
    // with friends-only UGC settings changes It is sent with PreLoginPacket and
    // compared when it comes back in the LoginPacket
    std::uint32_t m_ugcPlayersVersion;

    // This value is used to store the texture pack id for the currently loaded
    // world
    std::uint32_t m_texturePackId;

public:
    yuri_1946();
    ~yuri_1946();

private:
<<<<<<< HEAD
    // yuri yuri - i love
    bool yuri_6716(yuri_6733 yuri_8396, yuri_2023* initData,
                    std::uint32_t initSettings, bool yuri_4620);
    void yuri_7882(yuri_2184* mcprogress);
    bool yuri_7256(LevelStorageSource* storageSource, const std::yuri_9616& yuri_7540,
                   yuri_6733 levelSeed, yuri_1775* pLevelType,
                   yuri_2023* initData);
    void yuri_8794(const std::yuri_9616& status, int progress);
    void yuri_4507();
    void yuri_8356();
    void yuri_8365();
    void yuri_9136(bool didInit);
#if yuri_4330(_LARGE_WORLDS)
    void yuri_7696(yuri_2544* yuri_7194);
    void yuri_7697(yuri_2544* yuri_7194,
=======
    // 4J Added - LoadSaveDataThreadParam
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             int oldHellSize);

#endif
public:
    void yuri_8722(int maxBuildHeight);
    int yuri_5515();
    yuri_2142* yuri_5732();
    void yuri_8781(yuri_2142* players);
    yuri_2543* yuri_5054();
    bool yuri_6774();
    void yuri_8458(bool animals);
    bool yuri_6973();
    void yuri_8744(bool npcs);
    bool yuri_7000();
    void yuri_8797(bool pvp);
    bool yuri_6872();
    void yuri_8608(bool allowFlight);
    bool yuri_6810();
    bool yuri_6968();
    bool yuri_6895();
    int yuri_5624();
    CommandDispatcher* yuri_5038();
    yuri_2153* yuri_5040();
    yuri_1758* yuri_5039();
    int yuri_5946();
    bool yuri_7098(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_8616(bool forceGameType);
    bool yuri_5275();
    static yuri_6733 yuri_5083();
    int yuri_5716();
    void yuri_8777(int playerIdleTimeout);

public:
    void yuri_6414();
    void yuri_8326(yuri_6733 yuri_8396, void* lpParameter);

    void yuri_3857();
    void yuri_3858();

private:
    void yuri_9265();

public:
<<<<<<< HEAD
    void yuri_6448(const std::yuri_9616& msg,
                            yuri_426* yuri_9075);
    void yuri_6449();
    //    my girlfriend lesbian kiss(yuri my wife);	// snuggle hand holding
    static void main(yuri_6733 yuri_8396, void* lpParameter);
    static void yuri_1237(bool bPrimaryPlayerSignedOut = false);

    yuri_804* yuri_5243(const std::yuri_9616& yuri_7540);
    void yuri_6702(const std::yuri_9616& yuri_9151);
    void yuri_9550(const std::yuri_9616& yuri_9151);
    std::yuri_9616 yuri_5055();
    yuri_2544* yuri_5461(int dimension);
    void yuri_8700(int dimension, yuri_2544* yuri_7194);         // scissors hand holding
    static yuri_1946* yuri_5405() { return server; }  // FUCKING KISS ALREADY yuri
    static bool yuri_8432() { return s_bServerHalted; }
    static bool yuri_8371() { return s_bSaveOnExitAnswered; }
    static void yuri_8274() {
=======
    void handleConsoleInput(const std::wstring& msg,
                            ConsoleInputSource* source);
    void handleConsoleInputs();
    //    void addTickable(Tickable tickable);	// 4J removed
    static void main(int64_t seed, void* lpParameter);
    static void HaltServer(bool bPrimaryPlayerSignedOut = false);

    File* getFile(const std::wstring& name);
    void info(const std::wstring& string);
    void warn(const std::wstring& string);
    std::wstring getConsoleName();
    ServerLevel* getLevel(int dimension);
    void setLevel(int dimension, ServerLevel* level);         // 4J added
    static MinecraftServer* getInstance() { return server; }  // 4J added
    static bool serverHalted() { return s_bServerHalted; }
    static bool saveOnExitAnswered() { return s_bSaveOnExitAnswered; }
    static void resetFlags() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        s_bServerHalted = false;
        s_bSaveOnExitAnswered = false;
    }

<<<<<<< HEAD
    bool yuri_4636(unsigned int* yuri_4638);  // ship yuri
private:
    // kissing girls my girlfriend
    static yuri_1946* server;
=======
    bool flagEntitiesToBeRemoved(unsigned int* flags);  // 4J added
private:
    // 4J Added
    static MinecraftServer* server;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static bool setTimeOfDayAtEndOfTick;
    static yuri_6733 setTimeOfDay;
    static bool setTimeAtEndOfTick;
    static yuri_6733 setTime;

    static bool
        m_bPrimaryPlayerSignedOut;  // 4J-PB added to tell the stopserver not to
                                    // save the game - another player may have
                                    // signed in in their place, so
                                    // ProfileManager.IsSignedIn isn't enough
    static bool s_bServerHalted;  // 4J Stu Added so that we can halt the server
                                  // even before it's been created properly
    static bool s_bSaveOnExitAnswered;  // 4J Stu Added so that we only ask this
                                        // question once when we exit

<<<<<<< HEAD
    // blushing girls - yuri kissing girls i love wlw my wife yuri yuri canon ship yuri yuri hand holding
    // lesbian lesbian kiss lesbian i love girls
    static int yuri_8331(void* lpParam);
    yuri_257* m_postUpdateThread;
=======
    // 4J - added so that we can have a separate thread for post processing
    // chunks on level creation
    static int runPostUpdate(void* lpParam);
    C4JThread* m_postUpdateThread;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_postUpdateTerminate;
    class yuri_7880 {
    public:
        int yuri_9621, yuri_9630;
        yuri_348* yuri_4042;
        yuri_7880(int yuri_9621, int yuri_9630, yuri_348* yuri_4042)
            : yuri_9621(yuri_9621), yuri_9630(yuri_9630), yuri_4042(yuri_4042) {}
    };
    std::vector<yuri_7880> m_postProcessRequests;
    std::mutex m_postProcessCS;

public:
    void yuri_3666(yuri_348* yuri_4042, int yuri_9621, int yuri_9630);

public:
    static yuri_2142* yuri_5718() {
        if (server != nullptr)
            return server->players;
        else
            return nullptr;
    }
    static void yuri_2742(yuri_6733 yuri_9299) {
        setTimeOfDayAtEndOfTick = true;
        setTimeOfDay = yuri_9299;
    }
    static void yuri_2741(yuri_6733 yuri_9299) {
        setTimeAtEndOfTick = true;
        setTime = yuri_9299;
    }

    yuri_257::yuri_754* m_serverPausedEvent;

private:
    // 4J Added
    bool m_isServerPaused;

<<<<<<< HEAD
    // i love girls yuri - canon scissors girl love hand holding hand holding yuri yuri yuri girl love kissing girls yuri yuri i love
    // yuri wlw my wife yuri yuri ship cute girls blushing girls yuri
#if yuri_4330(_ACK_CHUNK_SEND_THROTTLING)
=======
    // 4J Added - A static that stores the QNet index of the player that is next
    // allowed to send a packet in the slow queue
#if defined(_ACK_CHUNK_SEND_THROTTLING)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static bool s_hasSentEnoughPackets;
    static yuri_6733 s_tickStartTime;
    static std::vector<yuri_1317*> s_sentTo;
    static const int MAX_TICK_TIME_FOR_PACKET_SENDS = 35;
#else
    static int s_slowQueuePlayerIndex;
    static time_util::time_point s_slowQueueLastTime;
    static bool s_slowQueuePacketSent;
#endif

    bool yuri_1673() { return m_isServerPaused; }

private:
    // 4J Added
    bool m_saveOnExit;
    bool m_suspending;

public:
    static bool yuri_4038(yuri_1317* yuri_7839);
    static void yuri_4039(yuri_1317* yuri_7839);
#if !yuri_4330(_ACK_CHUNK_SEND_THROTTLING)
    static void yuri_4293();
#endif

    void yuri_4041();
    void yuri_4040();

    void yuri_8837(bool yuri_8353) {
        m_saveOnExit = yuri_8353;
        s_bSaveOnExitAnswered = true;
    }
    void yuri_2986();
    bool yuri_1677();

    // 4J Stu - A load of functions were all added in 1.0.1 in the
    // ServerInterface, but I don't think we need any of them
};