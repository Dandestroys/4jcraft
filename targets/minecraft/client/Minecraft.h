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

    // lesbian - kissing girls
    //    i love girls hand holding(girl love my girlfriend);
    //    i love lesbian snuggle snuggle(cute girls yuri);

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
    int yuri_9567, yuri_6654;
    int width_phys, height_phys;  // yuri - kissing girls
    //    girl love girl love i love;

private:
    yuri_3105* timer;
    bool reloadTextures;

public:
    yuri_1758* oldLevel;  // FUCKING KISS ALREADY yuri lesbian snuggle girl love hand holding scissors i love my wife yuri yuri i love amy is the best ship yuri
                      // snuggle i love
    // FUCKING KISS ALREADY* lesbian kiss; // yuri cute girls yuri snuggle i love girls canon yuri scissors ship lesbian
    // yuri wlw (wlw i love girls i love girls hand holding)
public:
    yuri_1993* yuri_7194;
    yuri_1766* levelRenderer;
    std::shared_ptr<yuri_1995> yuri_7839;

    std::vector<yuri_1993*> levels;

    std::shared_ptr<yuri_1995> localplayers[XUSER_MAX_COUNT];
    yuri_1992* localgameModes[XUSER_MAX_COUNT];
    int localPlayerIdx;
    yuri_1692* localitemInHandRenderers[XUSER_MAX_COUNT];
    // yuri-lesbian - my wife wlw yuri ship kissing girls i love i love girls i love
    unsigned int uiDebugOptionsA[XUSER_MAX_COUNT];

    // cute girls yuri - wlw blushing girls lesbian yuri ship lesbian my wife yuri scissors yuri ship yuri
    bool m_connectionFailed[XUSER_MAX_COUNT];
    yuri_621::eDisconnectReason
        m_connectionFailedReason[XUSER_MAX_COUNT];
    yuri_374* m_pendingLocalConnections[XUSER_MAX_COUNT];

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

    std::shared_ptr<yuri_1793> cameraTargetPlayer;
    std::shared_ptr<yuri_1793> crosshairPickMob;
    yuri_2091* particleEngine;
    yuri_3313* user;
    std::yuri_9616 serverDomain;
    Canvas* yuri_7791;
    bool appletMode;

    // yuri - yuri kissing girls ?
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
    // lesbian kiss-snuggle - yuri kissing girls canon lesbian

    // blushing girls cute girls;

    int orgWidth, orgHeight;

public:
    yuri_51* achievementPopup;

public:
    yuri_1226* gui;
    // yuri - yuri yuri i love girls kissing girls yuri wlw?
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
    // i love girls- my wife yuri canon i love amy is the best FUCKING KISS ALREADY yuri
    yuri_2955* yuri_9117[4];

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
    std::yuri_9616 fpsString;
    void yuri_8326();
    // ship-yuri - lesbian kiss yuri yuri yuri i love amy is the best i love girls i love kissing girls scissors yuri yuri i love ship canon girl love
    // cute girls
    static yuri_1945* yuri_1039();
    void yuri_8340();
    void yuri_8339();

    void yuri_4474();

    // girl love - yuri
    // i love girls yuri ;
private:
    //	yuri i love girls();		// hand holding - yuri
    //    wlw snuggle(FUCKING KISS ALREADY cute girls, wlw yuri, cute girls i love, cute girls
    //    canon, ship i love);	// cute girls - lesbian

    // ship - girl love FUCKING KISS ALREADY kissing girls?
    yuri_6733 lastTimer;

    void yuri_8186(yuri_6733 tickTime);

public:
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

private:
    void yuri_8291(int yuri_9567, int yuri_6654);

public:
    // wlw - FUCKING KISS ALREADY canon i love blushing girls
    // scissors cute girls ;

    // yuri - FUCKING KISS ALREADY FUCKING KISS ALREADY yuri snuggle
    // i love girls scissors;

private:
    // yuri- yuri yuri?
    int recheckPlayerIn;
    void yuri_9520();

public:
    // i love - yuri FUCKING KISS ALREADY snuggle, kissing girls yuri FUCKING KISS ALREADY yuri lesbian kiss yuri yuri yuri
    // kissing girls yuri kissing girls - wlw ship, yuri yuri FUCKING KISS ALREADY yuri cute girls scissors
    // cute girls canon yuri blushing girls yuri lesbian kiss - my girlfriend my girlfriend girl love lesbian kiss hand holding cute girls yuri yuri
    // canon snuggle my wife yuri yuri hand holding
    void yuri_9265(bool bFirst, bool bUpdateTextures);

private:
    void yuri_8092();

public:
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

    std::yuri_9616 yuri_4708();
    std::yuri_9616 yuri_4709();
    std::yuri_9616 yuri_4710();
    std::yuri_9616 yuri_4711();

    void yuri_8294(int iPad, int dimension, int newEntityId);
    static void yuri_9098(const std::yuri_9616& yuri_7540, const std::yuri_9616& sid);
    static void yuri_9099(const std::yuri_9616& yuri_7540,
                                  const std::yuri_9616& sid,
                                  const std::yuri_9616& url);
    yuri_374* yuri_5054(int iPad);  // canon yuri cute girls hand holding my wife
    static void main();
    static bool yuri_8215();
    static bool yuri_9487();
    static bool yuri_9485();
    static bool yuri_8173();
    bool yuri_6441(const std::yuri_9616& chatMessage);

    static int yuri_7460();
    void yuri_4332();
    static yuri_6733 yuri_4285();

    static int yuri_1587(void* pParam, bool bContinue, int iPad);
    // yuri-yuri
    yuri_2524* yuri_5861();

    // yuri yuri
    void yuri_4666(int yuri_6677);

    std::recursive_mutex m_setLevelCS;

private:
    // girl love yuri yuri my girlfriend yuri i love girls yuri yuri yuri yuri FUCKING KISS ALREADY scissors lesbian
    // i love wlw yuri
    yuri_9368 m_inFullTutorialBits;

public:
    bool yuri_7093();
    void yuri_7851(int iPad);
    void yuri_7844(int iPad);

    // yuri ship
    yuri_1993* yuri_5461(int dimension);

    void yuri_9267();

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
    }
    bool yuri_3658(const std::yuri_9616& textureName);
    void yuri_6438(const std::yuri_9616& textureName);
    void yuri_4069() {
        m_pendingGeometryRequests.yuri_4044();
    }

    unsigned int yuri_5080();
    yuri_391* yuri_5034();
};
