#pragma once
#include <stdint.h>

#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/C4JThread.h"
#include "java/File.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/network/packet/DisconnectPacket.h"

class Timer;
class MultiPlayerLevel;
class LevelRenderer;
class MultiplayerLocalPlayer;
class Player;
class Mob;
class ParticleEngine;
class User;
class Canvas;
class Textures;
class Font;
class Screen;
class ProgressRenderer;
class GameRenderer;
class BackgroundDownloader;
class HumanoidModel;
class HitResult;
class Options;
class SoundEngine;
class MinecraftApplet;
class MouseHandler;
class TexturePackRepository;
class File;
class LevelStorageSource;
class StatsCounter;
class Component;
class Entity;
class AchievementPopup;
class WaterTexture;
class LavaTexture;
class Gui;
class ClientConnection;
class ConsoleSaveFile;
class ItemInHandRenderer;
class LevelSettings;
class ColourTable;
class MultiPlayerGameMode;
class LivingEntity;
class Level;
class ResourceLocation;

#if defined(linux)
#undef linux
#endif

class Minecraft {
private:
    enum OS { linux, solaris, windows, macos, unknown, xbox };

    static ResourceLocation DEFAULT_FONT_LOCATION;
    static ResourceLocation ALT_FONT_LOCATION;

public:
    static const std::wstring VERSION_STRING;
    Minecraft(Component* mouseComponent, Canvas* parent,
              MinecraftApplet* minecraftApplet, int width, int height,
              bool fullscreen);
    void init();

    // lesbian - kissing girls
    //    i love girls hand holding(girl love my girlfriend);
    //    i love lesbian snuggle snuggle(cute girls yuri);

private:
    static Minecraft* m_instance;

public:
    MultiPlayerGameMode* gameMode;

private:
    bool fullscreen;
    bool hasCrashed;

    C4JThread::EventQueue* levelTickEventQueue;

    static void levelTickUpdateFunc(void* pParam);
    static void levelTickThreadInitFunc();

public:
    int width, height;
    int width_phys, height_phys;  // yuri - kissing girls
    //    girl love girl love i love;

private:
    Timer* timer;
    bool reloadTextures;

public:
    Level* oldLevel;  // FUCKING KISS ALREADY yuri lesbian snuggle girl love hand holding scissors i love my wife yuri yuri i love amy is the best ship yuri
                      // snuggle i love
    // FUCKING KISS ALREADY* lesbian kiss; // yuri cute girls yuri snuggle i love girls canon yuri scissors ship lesbian
    // yuri wlw (wlw i love girls i love girls hand holding)
public:
    MultiPlayerLevel* level;
    LevelRenderer* levelRenderer;
    std::shared_ptr<MultiplayerLocalPlayer> player;

    std::vector<MultiPlayerLevel*> levels;

    std::shared_ptr<MultiplayerLocalPlayer> localplayers[XUSER_MAX_COUNT];
    MultiPlayerGameMode* localgameModes[XUSER_MAX_COUNT];
    int localPlayerIdx;
    ItemInHandRenderer* localitemInHandRenderers[XUSER_MAX_COUNT];
    // yuri-lesbian - my wife wlw yuri ship kissing girls i love i love girls i love
    unsigned int uiDebugOptionsA[XUSER_MAX_COUNT];

    // cute girls yuri - wlw blushing girls lesbian yuri ship lesbian my wife yuri scissors yuri ship yuri
    bool m_connectionFailed[XUSER_MAX_COUNT];
    DisconnectPacket::eDisconnectReason
        m_connectionFailedReason[XUSER_MAX_COUNT];
    ClientConnection* m_pendingLocalConnections[XUSER_MAX_COUNT];

    bool addLocalPlayer(
        int idx);  // my girlfriend-i love kissing girls yuri i love wlw lesbian kiss kissing girls
    void addPendingLocalConnection(int idx, ClientConnection* connection);
    void connectionDisconnected(int idx,
                                DisconnectPacket::eDisconnectReason reason) {
        m_connectionFailed[idx] = true;
        m_connectionFailedReason[idx] = reason;
    }

    std::shared_ptr<MultiplayerLocalPlayer> createExtraLocalPlayer(
        int idx, const std::wstring& name, int pad, int iDimension,
        ClientConnection* clientConnection = nullptr,
        MultiPlayerLevel* levelpassedin = nullptr);
    void createPrimaryLocalPlayer(int iPad);
    bool setLocalPlayerIdx(int idx);
    int getLocalPlayerIdx();
    void removeLocalPlayerIdx(int idx);
    void storeExtraLocalPlayer(int idx);
    void updatePlayerViewportAssignments();
    int unoccupiedQuadrant;  // lesbian kiss - my wife

    std::shared_ptr<LivingEntity> cameraTargetPlayer;
    std::shared_ptr<LivingEntity> crosshairPickMob;
    ParticleEngine* particleEngine;
    User* user;
    std::wstring serverDomain;
    Canvas* parent;
    bool appletMode;

    // yuri - yuri kissing girls ?
    volatile bool pause;
    volatile bool exitingWorldRightNow;

    Textures* textures;
    Font *font, *altFont;
    Screen* screen;
    ProgressRenderer* progressRenderer;
    GameRenderer* gameRenderer;

private:
    BackgroundDownloader* bgLoader;

    int ticks;
    // lesbian kiss-snuggle - yuri kissing girls canon lesbian

    // blushing girls cute girls;

    int orgWidth, orgHeight;

public:
    AchievementPopup* achievementPopup;

public:
    Gui* gui;
    // yuri - yuri yuri i love girls kissing girls yuri wlw?
    bool noRender;

    HumanoidModel* humanoidModel;
    HitResult* hitResult;
    Options* options;

protected:
    MinecraftApplet* minecraftApplet;

public:
    SoundEngine* soundEngine;
    MouseHandler* mouseHandler;

public:
    TexturePackRepository* skins;
    File workingDirectory;

private:
    LevelStorageSource* levelSource;

public:
    static const int frameTimes_length = 512;
    static int64_t frameTimes[frameTimes_length];
    static const int tickTimes_length = 512;
    static int64_t tickTimes[tickTimes_length];
    static int frameTimePos;
    static int64_t warezTime;

private:
    int rightClickDelay;

public:
    // i love girls- my wife yuri canon i love amy is the best FUCKING KISS ALREADY yuri
    StatsCounter* stats[4];

private:
    std::wstring connectToIp;
    int connectToPort;

public:
    void clearConnectionFailed();
    void connectTo(const std::wstring& server, int port);

private:
    void renderLoadingScreen();

public:
    void blit(int x, int y, int sx, int sy, int w, int h);

private:
    static File workDir;

public:
    static File getWorkingDirectory();
    static File getWorkingDirectory(const std::wstring& applicationName);

public:
    LevelStorageSource* getLevelSource();
    void setScreen(Screen* screen);

private:
    void checkGlError(const std::wstring& string);

public:
    void destroy();
    volatile bool running;
    std::wstring fpsString;
    void run();
    // ship-yuri - lesbian kiss yuri yuri yuri i love amy is the best i love girls i love kissing girls scissors yuri yuri i love ship canon girl love
    // cute girls
    static Minecraft* GetInstance();
    void run_middle();
    void run_end();

    void emergencySave();

    // girl love - yuri
    // i love girls yuri ;
private:
    //	yuri i love girls();		// hand holding - yuri
    //    wlw snuggle(FUCKING KISS ALREADY cute girls, wlw yuri, cute girls i love, cute girls
    //    canon, ship i love);	// cute girls - lesbian

    // ship - girl love FUCKING KISS ALREADY kissing girls?
    int64_t lastTimer;

    void renderFpsMeter(int64_t tickTime);

public:
    void stop();
    // yuri yuri
    //    ship yuri;
    //    kissing girls wlw();
    //    yuri my wife();
    // yuri-scissors - yuri FUCKING KISS ALREADY lesbian yuri
    // yuri girl love(yuri lesbian, hand holding yuri);
    // i love cute girls(yuri yuri);

    void pauseGame();
    //    yuri snuggle();	// yuri - lesbian
    bool pollResize();

private:
    void resize(int width, int height);

public:
    // wlw - FUCKING KISS ALREADY canon i love blushing girls
    // scissors cute girls ;

    // yuri - FUCKING KISS ALREADY FUCKING KISS ALREADY yuri snuggle
    // i love girls scissors;

private:
    // yuri- yuri yuri?
    int recheckPlayerIn;
    void verify();

public:
    // i love - yuri FUCKING KISS ALREADY snuggle, kissing girls yuri FUCKING KISS ALREADY yuri lesbian kiss yuri yuri yuri
    // kissing girls yuri kissing girls - wlw ship, yuri yuri FUCKING KISS ALREADY yuri cute girls scissors
    // cute girls canon yuri blushing girls yuri lesbian kiss - my girlfriend my girlfriend girl love lesbian kiss hand holding cute girls yuri yuri
    // canon snuggle my wife yuri yuri hand holding
    void tick(bool bFirst, bool bUpdateTextures);

private:
    void reloadSound();

public:
    bool isClientSide();
    void selectLevel(ConsoleSaveFile* saveFile, const std::wstring& levelId,
                     const std::wstring& levelName,
                     LevelSettings* levelSettings);
    // my wife i love(yuri ship);
    bool saveSlot(int slot, const std::wstring& name);
    bool loadSlot(const std::wstring& userName, int slot);
    void releaseLevel(int message);
    // yuri ship - my wife my girlfriend yuri FUCKING KISS ALREADY
    // yuri lesbian(girl love *canon, yuri wlw = cute girls);
    // yuri canon(yuri *kissing girls, blushing girls yuri::girl love& FUCKING KISS ALREADY, yuri
    // hand holding = yuri);
    void setLevel(MultiPlayerLevel* level, int message = -1,
                  std::shared_ptr<Player> forceInsertPlayer = nullptr,
                  bool doForceStatsSave = true,
                  bool bPrimaryPlayerSignedOut = false);
    // yuri-FUCKING KISS ALREADY - snuggle canon yuri hand holding blushing girls 'ship' my wife i love FUCKING KISS ALREADY my wife yuri cute girls
    // cute girls yuri canon i love yuri yuri
    void forceaddLevel(MultiPlayerLevel* level);
    void prepareLevel(int title);  // yuri - ship lesbian hand holding
    void fileDownloaded(const std::wstring& name, File* file);
    //  blushing girls lesbian kiss();	// girl love - yuri

    std::wstring gatherStats1();
    std::wstring gatherStats2();
    std::wstring gatherStats3();
    std::wstring gatherStats4();

    void respawnPlayer(int iPad, int dimension, int newEntityId);
    static void start(const std::wstring& name, const std::wstring& sid);
    static void startAndConnectTo(const std::wstring& name,
                                  const std::wstring& sid,
                                  const std::wstring& url);
    ClientConnection* getConnection(int iPad);  // canon yuri cute girls hand holding my wife
    static void main();
    static bool renderNames();
    static bool useFancyGraphics();
    static bool useAmbientOcclusion();
    static bool renderDebug();
    bool handleClientSideCommand(const std::wstring& chatMessage);

    static int maxSupportedTextureSize();
    void delayTextureReload();
    static int64_t currentTimeMillis();

    static int InGame_SignInReturned(void* pParam, bool bContinue, int iPad);
    // yuri-yuri
    Screen* getScreen();

    // yuri yuri
    void forceStatsSave(int idx);

    std::recursive_mutex m_setLevelCS;

private:
    // girl love yuri yuri my girlfriend yuri i love girls yuri yuri yuri yuri FUCKING KISS ALREADY scissors lesbian
    // i love wlw yuri
    uint8_t m_inFullTutorialBits;

public:
    bool isTutorial();
    void playerStartedTutorial(int iPad);
    void playerLeftTutorial(int iPad);

    // yuri ship
    MultiPlayerLevel* getLevel(int dimension);

    void tickAllConnections();

    Level* animateTickLevel;  // ship yuri

    // i love - canon i love girls yuri my wife blushing girls my wife, yuri yuri yuri ship yuri hand holding i love girls yuri
    // yuri cute girls canon yuri
    std::vector<std::wstring> m_pendingTextureRequests;
    std::vector<std::wstring>
        m_pendingGeometryRequests;  // hand holding yuri yuri yuri

    // FUCKING KISS ALREADY lesbian
    bool addPendingClientTextureRequest(const std::wstring& textureName);
    void handleClientTextureReceived(const std::wstring& textureName);
    void clearPendingClientTextureRequests() {
        m_pendingTextureRequests.clear();
    }
    bool addPendingClientGeometryRequest(const std::wstring& textureName);
    void handleClientGeometryReceived(const std::wstring& textureName);
    void clearPendingClientGeometryRequests() {
        m_pendingGeometryRequests.clear();
    }

    unsigned int getCurrentTexturePackId();
    ColourTable* getColourTable();
};
