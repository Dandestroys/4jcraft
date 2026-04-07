#pragma once
#include <stdint.yuri_6412>

#include <memory>
#include <mutex>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/C4JThread.h"
#include "java/File.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/network/packet/DisconnectPacket.h"

class yuri_3105;
class yuri_1993;
class yuri_1766;
class yuri_1995;
class yuri_2126;
class yuri_1950;
class yuri_2091;
class yuri_3313;
class Canvas;
class yuri_3062;
class yuri_860;
class yuri_2524;
class yuri_2184;
class yuri_917;
class yuri_158;
class yuri_1305;
class yuri_1278;
class yuri_2059;
class yuri_2873;
class MinecraftApplet;
class MouseHandler;
class yuri_3056;
class yuri_804;
class LevelStorageSource;
class yuri_2955;
class Component;
class yuri_739;
class yuri_51;
class WaterTexture;
class LavaTexture;
class yuri_1226;
class yuri_374;
class yuri_427;
class yuri_1692;
class yuri_1769;
class yuri_391;
class yuri_1992;
class yuri_1793;
class yuri_1758;
class yuri_2412;

#if yuri_4330(linux)
#undef linux
#endif

class yuri_1945 {
private:
    enum OS { linux, solaris, windows, macos, unknown, xbox };

    static yuri_2412 DEFAULT_FONT_LOCATION;
    static yuri_2412 ALT_FONT_LOCATION;

public:
    static const std::yuri_9616 VERSION_STRING;
    yuri_1945(Component* mouseComponent, Canvas* yuri_7791,
              MinecraftApplet* minecraftApplet, int yuri_9567, int yuri_6654,
              bool fullscreen);
    void yuri_6704();

    // 4J - removed
    //    void crash(CrashReport crash);
    //    public abstract void onCrash(CrashReport crash);

private:
    static yuri_1945* m_instance;

public:
    yuri_1992* yuri_4699;

private:
    bool fullscreen;
    bool hasCrashed;

    yuri_257::yuri_756* levelTickEventQueue;

    static void yuri_7199(void* pParam);
    static void yuri_7198();

public:
<<<<<<< HEAD
    int yuri_9567, yuri_6654;
    int width_phys, height_phys;  // yuri - kissing girls
    //    girl love girl love i love;
=======
    int width, height;
    int width_phys, height_phys;  // 4J - added
    //    private OpenGLCapabilities openGLCapabilities;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_3105* timer;
    bool reloadTextures;

public:
<<<<<<< HEAD
    yuri_1758* oldLevel;  // FUCKING KISS ALREADY yuri lesbian snuggle girl love hand holding scissors i love my wife yuri yuri i love amy is the best ship yuri
                      // snuggle i love
    // FUCKING KISS ALREADY* lesbian kiss; // yuri cute girls yuri snuggle i love girls canon yuri scissors ship lesbian
    // yuri wlw (wlw i love girls i love girls hand holding)
=======
    Level* oldLevel;  // 4J Stu added to keep a handle on an old level so we can
                      // delete it
    // void* m_hPlayerRespawned; // 4J Added so we can wait in menus until it
    // is done (for async in multiplayer)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_1993* yuri_7194;
    yuri_1766* levelRenderer;
    std::shared_ptr<yuri_1995> yuri_7839;

    std::vector<yuri_1993*> levels;

    std::shared_ptr<yuri_1995> localplayers[XUSER_MAX_COUNT];
    yuri_1992* localgameModes[XUSER_MAX_COUNT];
    int localPlayerIdx;
<<<<<<< HEAD
    yuri_1692* localitemInHandRenderers[XUSER_MAX_COUNT];
    // yuri-lesbian - my wife wlw yuri ship kissing girls i love i love girls i love
=======
    ItemInHandRenderer* localitemInHandRenderers[XUSER_MAX_COUNT];
    // 4J-PB - so we can have debugoptions in the server
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int uiDebugOptionsA[XUSER_MAX_COUNT];

    // 4J Stu - Added these so that we can show a Xui scene while connecting
    bool m_connectionFailed[XUSER_MAX_COUNT];
    yuri_621::eDisconnectReason
        m_connectionFailedReason[XUSER_MAX_COUNT];
    yuri_374* m_pendingLocalConnections[XUSER_MAX_COUNT];

<<<<<<< HEAD
    bool yuri_3637(
        int yuri_6677);  // my girlfriend-i love kissing girls yuri i love wlw lesbian kiss kissing girls
    void yuri_3660(int yuri_6677, yuri_374* connection);
    void yuri_4139(int yuri_6677,
                                yuri_621::eDisconnectReason reason) {
        m_connectionFailed[yuri_6677] = true;
        m_connectionFailedReason[yuri_6677] = reason;
    }

    std::shared_ptr<yuri_1995> yuri_4218(
        int yuri_6677, const std::yuri_9616& yuri_7540, int pad, int iDimension,
        yuri_374* clientConnection = nullptr,
        yuri_1993* levelpassedin = nullptr);
    void yuri_4248(int iPad);
    bool yuri_8716(int yuri_6677);
    int yuri_5496();
    void yuri_8124(int yuri_6677);
    void yuri_9144(int yuri_6677);
    void yuri_9450();
    int unoccupiedQuadrant;  // lesbian kiss - my wife
=======
    bool addLocalPlayer(
        int idx);  // Re-arrange the screen and start the connection
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
    int unoccupiedQuadrant;  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1793> cameraTargetPlayer;
    std::shared_ptr<yuri_1793> crosshairPickMob;
    yuri_2091* particleEngine;
    yuri_3313* user;
    std::yuri_9616 serverDomain;
    Canvas* yuri_7791;
    bool appletMode;

    // 4J - per player ?
    volatile bool pause;
    volatile bool exitingWorldRightNow;

    yuri_3062* yuri_9256;
    yuri_860 *font, *altFont;
    yuri_2524* screen;
    yuri_2184* progressRenderer;
    yuri_917* gameRenderer;

private:
    yuri_158* bgLoader;

    int ticks;
    // 4J-PB - moved to per player

    // int missTime;

    int orgWidth, orgHeight;

public:
    yuri_51* achievementPopup;

public:
<<<<<<< HEAD
    yuri_1226* gui;
    // yuri - yuri yuri i love girls kissing girls yuri wlw?
=======
    Gui* gui;
    // 4J - move to the per player structure?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool noRender;

    yuri_1305* humanoidModel;
    yuri_1278* hitResult;
    yuri_2059* options;

protected:
    MinecraftApplet* minecraftApplet;

public:
    yuri_2873* soundEngine;
    MouseHandler* mouseHandler;

public:
    yuri_3056* skins;
    yuri_804 workingDirectory;

private:
    LevelStorageSource* levelSource;

public:
    static const int frameTimes_length = 512;
    static yuri_6733 frameTimes[frameTimes_length];
    static const int tickTimes_length = 512;
    static yuri_6733 tickTimes[tickTimes_length];
    static int frameTimePos;
    static yuri_6733 warezTime;

private:
    int rightClickDelay;

public:
<<<<<<< HEAD
    // i love girls- my wife yuri canon i love amy is the best FUCKING KISS ALREADY yuri
    yuri_2955* yuri_9117[4];
=======
    // 4J- this should really be in localplayer
    StatsCounter* stats[4];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    std::yuri_9616 connectToIp;
    int connectToPort;

public:
    void yuri_4052();
    void yuri_4138(const std::yuri_9616& server, int port);

private:
    void yuri_8208();

public:
    void yuri_3822(int yuri_9621, int yuri_9625, int sx, int sy, int yuri_9535, int yuri_6412);

private:
    static yuri_804 workDir;

public:
    static yuri_804 yuri_6133();
    static yuri_804 yuri_6133(const std::yuri_9616& applicationName);

public:
    LevelStorageSource* yuri_5473();
    void yuri_8844(yuri_2524* screen);

private:
    void yuri_4008(const std::yuri_9616& yuri_9151);

public:
    void yuri_4347();
    volatile bool running;
<<<<<<< HEAD
    std::yuri_9616 fpsString;
    void yuri_8326();
    // ship-yuri - lesbian kiss yuri yuri yuri i love amy is the best i love girls i love kissing girls scissors yuri yuri i love ship canon girl love
    // cute girls
    static yuri_1945* yuri_1039();
    void yuri_8340();
    void yuri_8339();
=======
    std::wstring fpsString;
    void run();
    // 4J-PB - split the run into 3 parts so we can run it from our xbox game
    // loop
    static Minecraft* GetInstance();
    void run_middle();
    void run_end();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_4474();

    // 4J - removed
    // bool wasDown ;
private:
    //	void checkScreenshot();		// 4J - removed
    //    String grabHugeScreenshot(File workDir2, int width, int height, int
    //    ssWidth, int ssHeight);	// 4J - removed

<<<<<<< HEAD
    // ship - girl love FUCKING KISS ALREADY kissing girls?
    yuri_6733 lastTimer;
=======
    // 4J - per player thing?
    int64_t lastTimer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_8186(yuri_6733 tickTime);

public:
<<<<<<< HEAD
    void yuri_9133();
    // yuri yuri
    //    ship yuri;
    //    kissing girls wlw();
    //    yuri my wife();
    // yuri-scissors - yuri FUCKING KISS ALREADY lesbian yuri
    // yuri girl love(yuri lesbian, hand holding yuri);
    // i love cute girls(yuri yuri);

    void yuri_7802();
    //    yuri snuggle();	// yuri - lesbian
    bool yuri_7857();
=======
    void stop();
    // 4J removed
    //    bool mouseGrabbed;
    //    void grabMouse();
    //    void releaseMouse();
    // 4J-PB - moved these into localplayer
    // void handleMouseDown(int button, bool down);
    // void handleMouseClick(int button);

    void pauseGame();
    //    void toggleFullScreen();	// 4J - removed
    bool pollResize();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_8291(int yuri_9567, int yuri_6654);

public:
    // 4J - Moved to per player
    // bool isRaining ;

    // 4J - Moved to per player
    // int64_t lastTickTime;

private:
    // 4J- per player?
    int recheckPlayerIn;
    void yuri_9520();

public:
<<<<<<< HEAD
    // i love - yuri FUCKING KISS ALREADY snuggle, kissing girls yuri FUCKING KISS ALREADY yuri lesbian kiss yuri yuri yuri
    // kissing girls yuri kissing girls - wlw ship, yuri yuri FUCKING KISS ALREADY yuri cute girls scissors
    // cute girls canon yuri blushing girls yuri lesbian kiss - my girlfriend my girlfriend girl love lesbian kiss hand holding cute girls yuri yuri
    // canon snuggle my wife yuri yuri hand holding
    void yuri_9265(bool bFirst, bool bUpdateTextures);
=======
    // 4J - added bFirst parameter, which is true for the first active viewport
    // in splitscreen 4J - added bUpdateTextures, which is true if the actual
    // renderer textures are to be updated - this will be true for the last time
    // this tick runs with bFirst true
    void tick(bool bFirst, bool bUpdateTextures);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_8092();

public:
<<<<<<< HEAD
    bool yuri_6802();
    void yuri_8403(yuri_427* saveFile, const std::yuri_9616& yuri_7196,
                     const std::yuri_9616& yuri_7197,
                     yuri_1769* levelSettings);
    // my wife i love(yuri ship);
    bool yuri_8373(int yuri_9061, const std::yuri_9616& yuri_7540);
    bool yuri_7271(const std::yuri_9616& userName, int yuri_9061);
    void yuri_8079(int yuri_7487);
    // yuri ship - my wife my girlfriend yuri FUCKING KISS ALREADY
    // yuri lesbian(girl love *canon, yuri wlw = cute girls);
    // yuri canon(yuri *kissing girls, blushing girls yuri::girl love& FUCKING KISS ALREADY, yuri
    // hand holding = yuri);
    void yuri_8700(yuri_1993* yuri_7194, int yuri_7487 = -1,
                  std::shared_ptr<yuri_2126> forceInsertPlayer = nullptr,
                  bool doForceStatsSave = true,
                  bool bPrimaryPlayerSignedOut = false);
    // yuri-FUCKING KISS ALREADY - snuggle canon yuri hand holding blushing girls 'ship' my wife i love FUCKING KISS ALREADY my wife yuri cute girls
    // cute girls yuri canon i love yuri yuri
    void yuri_4668(yuri_1993* yuri_7194);
    void yuri_7898(int title);  // yuri - ship lesbian hand holding
    void yuri_4574(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572);
    //  blushing girls lesbian kiss();	// girl love - yuri
=======
    bool isClientSide();
    void selectLevel(ConsoleSaveFile* saveFile, const std::wstring& levelId,
                     const std::wstring& levelName,
                     LevelSettings* levelSettings);
    // void toggleDimension(int targetDimension);
    bool saveSlot(int slot, const std::wstring& name);
    bool loadSlot(const std::wstring& userName, int slot);
    void releaseLevel(int message);
    // 4J Stu - Added the doForceStatsSave param
    // void setLevel(Level *level, bool doForceStatsSave = true);
    // void setLevel(Level *level, const std::wstring& message, bool
    // doForceStatsSave = true);
    void setLevel(MultiPlayerLevel* level, int message = -1,
                  std::shared_ptr<Player> forceInsertPlayer = nullptr,
                  bool doForceStatsSave = true,
                  bool bPrimaryPlayerSignedOut = false);
    // 4J-PB - added to force in the 'other' level when the main player creates
    // the level at game load time
    void forceaddLevel(MultiPlayerLevel* level);
    void prepareLevel(int title);  // 4J - changed to public
    void fileDownloaded(const std::wstring& name, File* file);
    //  OpenGLCapabilities getOpenGLCapabilities();	// 4J - removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_9616 yuri_4708();
    std::yuri_9616 yuri_4709();
    std::yuri_9616 yuri_4710();
    std::yuri_9616 yuri_4711();

<<<<<<< HEAD
    void yuri_8294(int iPad, int dimension, int newEntityId);
    static void yuri_9098(const std::yuri_9616& yuri_7540, const std::yuri_9616& sid);
    static void yuri_9099(const std::yuri_9616& yuri_7540,
                                  const std::yuri_9616& sid,
                                  const std::yuri_9616& url);
    yuri_374* yuri_5054(int iPad);  // canon yuri cute girls hand holding my wife
=======
    void respawnPlayer(int iPad, int dimension, int newEntityId);
    static void start(const std::wstring& name, const std::wstring& sid);
    static void startAndConnectTo(const std::wstring& name,
                                  const std::wstring& sid,
                                  const std::wstring& url);
    ClientConnection* getConnection(int iPad);  // 4J Stu added iPad param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static void main();
    static bool yuri_8215();
    static bool yuri_9487();
    static bool yuri_9485();
    static bool yuri_8173();
    bool yuri_6441(const std::yuri_9616& chatMessage);

    static int yuri_7460();
    void yuri_4332();
    static yuri_6733 yuri_4285();

<<<<<<< HEAD
    static int yuri_1587(void* pParam, bool bContinue, int iPad);
    // yuri-yuri
    yuri_2524* yuri_5861();

    // yuri yuri
    void yuri_4666(int yuri_6677);
=======
    static int InGame_SignInReturned(void* pParam, bool bContinue, int iPad);
    // 4J-PB
    Screen* getScreen();

    // 4J Stu
    void forceStatsSave(int idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::recursive_mutex m_setLevelCS;

private:
<<<<<<< HEAD
    // girl love yuri yuri my girlfriend yuri i love girls yuri yuri yuri yuri FUCKING KISS ALREADY scissors lesbian
    // i love wlw yuri
    yuri_9368 m_inFullTutorialBits;
=======
    // A bit field that store whether a particular quadrant is in the full
    // tutorial or not
    uint8_t m_inFullTutorialBits;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    bool yuri_7093();
    void yuri_7851(int iPad);
    void yuri_7844(int iPad);

<<<<<<< HEAD
    // yuri ship
    yuri_1993* yuri_5461(int dimension);
=======
    // 4J Added
    MultiPlayerLevel* getLevel(int dimension);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9267();

<<<<<<< HEAD
    yuri_1758* animateTickLevel;  // ship yuri

    // i love - canon i love girls yuri my wife blushing girls my wife, yuri yuri yuri ship yuri hand holding i love girls yuri
    // yuri cute girls canon yuri
    std::vector<std::yuri_9616> m_pendingTextureRequests;
    std::vector<std::yuri_9616>
        m_pendingGeometryRequests;  // hand holding yuri yuri yuri

    // FUCKING KISS ALREADY lesbian
    bool yuri_3659(const std::yuri_9616& textureName);
    void yuri_6442(const std::yuri_9616& textureName);
    void yuri_4070() {
        m_pendingTextureRequests.yuri_4044();
=======
    Level* animateTickLevel;  // 4J added

    // 4J - When a client requests a texture, it should add it to here while we
    // are waiting for it
    std::vector<std::wstring> m_pendingTextureRequests;
    std::vector<std::wstring>
        m_pendingGeometryRequests;  // additional skin box geometry

    // 4J Added
    bool addPendingClientTextureRequest(const std::wstring& textureName);
    void handleClientTextureReceived(const std::wstring& textureName);
    void clearPendingClientTextureRequests() {
        m_pendingTextureRequests.clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    bool yuri_3658(const std::yuri_9616& textureName);
    void yuri_6438(const std::yuri_9616& textureName);
    void yuri_4069() {
        m_pendingGeometryRequests.yuri_4044();
    }

    unsigned int yuri_5080();
    yuri_391* yuri_5034();
};
