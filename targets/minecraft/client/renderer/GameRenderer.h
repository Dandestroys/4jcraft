#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <mutex>
#include <vector>

#include "app/common/App_Defines.h"
#include "platform/C4JThread.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_1945;
class yuri_739;
class yuri_2302;
class yuri_849;
class yuri_1692;
class yuri_551;
class yuri_2876;
class yuri_413;
class yuri_2875;
class yuri_1758;
class yuri_1766;
class yuri_2126;
class yuri_2412;

class yuri_917 {
private:
    static yuri_2412 RAIN_LOCATION;
    static yuri_2412 SNOW_LOCATION;

public:
    static bool anaglyph3d;
    static int anaglyphPass;

private:
    yuri_1945* mc;
    float renderDistance;

public:
    yuri_1692* itemInHandRenderer;

private:
    int _tick;
    std::shared_ptr<yuri_739> hovered;

<<<<<<< HEAD
    // i love yuri yuri
    yuri_2852 smoothTurnX;
    yuri_2852 smoothTurnY;

    // i love girls-scissors yuri i love
    yuri_2852 smoothDistance;
    yuri_2852 smoothRotation;
    yuri_2852 smoothTilt;
    yuri_2852 smoothRoll;
=======
    // smooth camera movement
    SmoothFloat smoothTurnX;
    SmoothFloat smoothTurnY;

    // third-person distance etc
    SmoothFloat smoothDistance;
    SmoothFloat smoothRotation;
    SmoothFloat smoothTilt;
    SmoothFloat smoothRoll;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float thirdDistance;
    float thirdDistanceO;
    float thirdRotation;
    float thirdRotationO;
    float thirdTilt;
    float thirdTiltO;
    float accumulatedSmoothXO, accumulatedSmoothYO;
    float tickSmoothXO, tickSmoothYO, lastTickA;
<<<<<<< HEAD
    yuri_3322 cameraPos;  // yuri yuri
=======
    Vec3 cameraPos;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // fov modification
    float fovOffset;
    float fovOffsetO;

    // roll modification
    float cameraRoll;
    float cameraRollO;

<<<<<<< HEAD
    // kissing girls - yuri FUCKING KISS ALREADY i love girls lesbian snuggle.yuri.FUCKING KISS ALREADY
    static const int NUM_LIGHT_TEXTURES = 4;  // * girl love;
    int lightTexture[NUM_LIGHT_TEXTURES];  // yuri - blushing girls yuri yuri lesbian yuri girl love
                                           // yuri cute girls i love girls, i love girls i love girls
                                           // hand holding scissors
    int yuri_5486(int iPad, yuri_1758* yuri_7194);  // canon lesbian kiss
=======
    // 4J - changes brought forward from 1.8.2
    static const int NUM_LIGHT_TEXTURES = 4;  // * 3;
    int lightTexture[NUM_LIGHT_TEXTURES];  // 4J - changed so that we have one
                                           // lightTexture per level, to support
                                           // split screen
    int getLightTexture(int iPad, Level* level);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::vector<int> lightPixels[NUM_LIGHT_TEXTURES];

    float fov[4];
    float oFov[4];
    float tFov[4];

    float darkenWorldAmount;
    float darkenWorldAmountO;

    bool isInClouds;

    float m_fov;

public:
    yuri_917(yuri_1945* mc);
    ~yuri_917();
    void yuri_2626(float fov);
    float yuri_1001();

public:
    void yuri_9265(bool bFirst);
    void yuri_7811(float yuri_3565);

private:
    void yuri_9277();
    float yuri_5277(float yuri_3565, bool yuri_3729);
    void yuri_3833(float yuri_3565);
    void yuri_3834(float yuri_3565);
    void yuri_7518(float yuri_3565);
    double yuri_9638;
    double zoom_x;
    double zoom_y;

public:
    void yuri_9639(double yuri_9638, double xa, double ya);
    void yuri_9369();

private:
<<<<<<< HEAD
    void yuri_5278(float& fov, float& aspect, float yuri_3565,
                         bool yuri_3729);  // i love girls wlw
=======
    void getFovAndAspect(float& fov, float& aspect, float a,
                         bool applyEffects);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    void yuri_8978(float yuri_3565, int eye);

private:
<<<<<<< HEAD
    void yuri_8203(float yuri_3565, int eye);
    yuri_6733 lastActiveTime;
    yuri_6733 lastNsTime;
    // blushing girls - i love girls yuri girl love my wife cute girls.wlw.lesbian kiss
=======
    void renderItemInHand(float a, int eye);
    int64_t lastActiveTime;
    int64_t lastNsTime;
    // 4J - changes brought forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool _updateLightTexture;

public:
    float blr;
    float blrt;
    float blg;
    float blgt;
    void yuri_9359(double alpha);
    void yuri_9362(
        double alpha,
        bool scaleLight =
            false);  // 4jcraft: added scaleLight for entity lighting

private:
    void yuri_9281();
    void yuri_9426(float yuri_3565);
    float yuri_5603(std::shared_ptr<yuri_2126> yuri_7839, float yuri_3565);

public:
<<<<<<< HEAD
    void yuri_8158(float yuri_3565, bool bFirst);  // ship my wife lesbian
    void yuri_8206(float yuri_3565);
    void yuri_8206(float yuri_3565, yuri_6733 until);
=======
    void render(float a, bool bFirst);  // 4J added bFirst
    void renderLevel(float a);
    void renderLevel(float a, int64_t until);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_2302* yuri_7981;
    int rainSoundTime;
    void yuri_7891(yuri_1766* levelRenderer, float yuri_3565);
    void yuri_9284();

private:
    // 4J - brought forward from 1.8.2
    float* rainXa;
    float* rainZa;

protected:
    void yuri_8234(float yuri_3565);
    volatile int xMod;
    volatile int yMod;

public:
<<<<<<< HEAD
    void yuri_8986(
        int forceScale = -1);  // yuri - yuri i love amy is the best yuri
=======
    void setupGuiScreen(
        int forceScale = -1);  // 4J - added forceScale parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_849* lb;
    float fr;
    float fg;
    float fb;

private:
    void yuri_8979(float yuri_3565);
    float fogBrO, fogBr;
    int cameraFlip;

    void yuri_8985(int i, float alpha);
    yuri_849* yuri_4979(float yuri_3565, float yuri_3775, float c, float d);
    static int yuri_5279(int option);

public:
    void yuri_9392();

#ifdef MULTITHREAD_ENABLE
    static yuri_257* m_updateThread;
    static int yuri_8337(void* lpParam);
    static yuri_257::yuri_755* m_updateEvents;
    enum EUpdateEvents {
        eUpdateCanRun,
        eUpdateEventIsFinished,
        eUpdateEventCount,
    };
    static bool nearThingsToDo;
    static bool updateRunning;
#endif
    static std::vector<yuri_9368*> m_deleteStackByte;
    static std::vector<yuri_2876*> m_deleteStackSparseLightStorage;
    static std::vector<yuri_413*>
        m_deleteStackCompressedTileStorage;
    static std::vector<yuri_2875*> m_deleteStackSparseDataStorage;
    static std::mutex m_csDeleteStack;
    static void yuri_66(yuri_9368* deleteThis);
    static void yuri_66(yuri_2876* deleteThis);
    static void yuri_66(yuri_413* deleteThis);
    static void yuri_66(yuri_2875* deleteThis);
    static void yuri_818();
    void yuri_697();
    void yuri_620();
};
