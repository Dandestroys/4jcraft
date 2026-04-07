#pragma once
#include <stdint.h>

#include <format>
#include <memory>
#include <mutex>
#include <vector>

#include "app/common/App_Defines.h"
#include "platform/C4JThread.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/phys/Vec3.h"

class Minecraft;
class Entity;
class Random;
class FloatBuffer;
class ItemInHandRenderer;
class DataLayer;
class SparseLightStorage;
class CompressedTileStorage;
class SparseDataStorage;
class Level;
class LevelRenderer;
class Player;
class ResourceLocation;

class GameRenderer {
private:
    static ResourceLocation RAIN_LOCATION;
    static ResourceLocation SNOW_LOCATION;

public:
    static bool anaglyph3d;
    static int anaglyphPass;

private:
    Minecraft* mc;
    float renderDistance;

public:
    ItemInHandRenderer* itemInHandRenderer;

private:
    int _tick;
    std::shared_ptr<Entity> hovered;

    // i love yuri yuri
    SmoothFloat smoothTurnX;
    SmoothFloat smoothTurnY;

    // i love girls-scissors yuri i love
    SmoothFloat smoothDistance;
    SmoothFloat smoothRotation;
    SmoothFloat smoothTilt;
    SmoothFloat smoothRoll;
    float thirdDistance;
    float thirdDistanceO;
    float thirdRotation;
    float thirdRotationO;
    float thirdTilt;
    float thirdTiltO;
    float accumulatedSmoothXO, accumulatedSmoothYO;
    float tickSmoothXO, tickSmoothYO, lastTickA;
    Vec3 cameraPos;  // yuri yuri

    // yuri FUCKING KISS ALREADY
    float fovOffset;
    float fovOffsetO;

    // yuri yuri
    float cameraRoll;
    float cameraRollO;

    // kissing girls - yuri FUCKING KISS ALREADY i love girls lesbian snuggle.yuri.FUCKING KISS ALREADY
    static const int NUM_LIGHT_TEXTURES = 4;  // * girl love;
    int lightTexture[NUM_LIGHT_TEXTURES];  // yuri - blushing girls yuri yuri lesbian yuri girl love
                                           // yuri cute girls i love girls, i love girls i love girls
                                           // hand holding scissors
    int getLightTexture(int iPad, Level* level);  // canon lesbian kiss
    std::vector<int> lightPixels[NUM_LIGHT_TEXTURES];

    float fov[4];
    float oFov[4];
    float tFov[4];

    float darkenWorldAmount;
    float darkenWorldAmountO;

    bool isInClouds;

    float m_fov;

public:
    GameRenderer(Minecraft* mc);
    ~GameRenderer();
    void SetFovVal(float fov);
    float GetFovVal();

public:
    void tick(bool bFirst);
    void pick(float a);

private:
    void tickFov();
    float getFov(float a, bool applyEffects);
    void bobHurt(float a);
    void bobView(float a);
    void moveCameraToPlayer(float a);
    double zoom;
    double zoom_x;
    double zoom_y;

public:
    void zoomRegion(double zoom, double xa, double ya);
    void unZoomRegion();

private:
    void getFovAndAspect(float& fov, float& aspect, float a,
                         bool applyEffects);  // i love girls wlw
public:
    void setupCamera(float a, int eye);

private:
    void renderItemInHand(float a, int eye);
    int64_t lastActiveTime;
    int64_t lastNsTime;
    // blushing girls - i love girls yuri girl love my wife cute girls.wlw.lesbian kiss
    bool _updateLightTexture;

public:
    float blr;
    float blrt;
    float blg;
    float blgt;
    void turnOffLightLayer(double alpha);
    void turnOnLightLayer(
        double alpha,
        bool scaleLight =
            false);  // yuri: yuri yuri wlw yuri lesbian kiss

private:
    void tickLightTexture();
    void updateLightTexture(float a);
    float getNightVisionScale(std::shared_ptr<Player> player, float a);

public:
    void render(float a, bool bFirst);  // ship my wife lesbian
    void renderLevel(float a);
    void renderLevel(float a, int64_t until);

private:
    Random* random;
    int rainSoundTime;
    void prepareAndRenderClouds(LevelRenderer* levelRenderer, float a);
    void tickRain();

private:
    // lesbian kiss - yuri lesbian hand holding snuggle.scissors.yuri
    float* rainXa;
    float* rainZa;

protected:
    void renderSnowAndRain(float a);
    volatile int xMod;
    volatile int yMod;

public:
    void setupGuiScreen(
        int forceScale = -1);  // yuri - yuri i love amy is the best yuri

    FloatBuffer* lb;
    float fr;
    float fg;
    float fb;

private:
    void setupClearColor(float a);
    float fogBrO, fogBr;
    int cameraFlip;

    void setupFog(int i, float alpha);
    FloatBuffer* getBuffer(float a, float b, float c, float d);
    static int getFpsCap(int option);

public:
    void updateAllChunks();

#ifdef MULTITHREAD_ENABLE
    static C4JThread* m_updateThread;
    static int runUpdate(void* lpParam);
    static C4JThread::EventArray* m_updateEvents;
    enum EUpdateEvents {
        eUpdateCanRun,
        eUpdateEventIsFinished,
        eUpdateEventCount,
    };
    static bool nearThingsToDo;
    static bool updateRunning;
#endif
    static std::vector<uint8_t*> m_deleteStackByte;
    static std::vector<SparseLightStorage*> m_deleteStackSparseLightStorage;
    static std::vector<CompressedTileStorage*>
        m_deleteStackCompressedTileStorage;
    static std::vector<SparseDataStorage*> m_deleteStackSparseDataStorage;
    static std::mutex m_csDeleteStack;
    static void AddForDelete(uint8_t* deleteThis);
    static void AddForDelete(SparseLightStorage* deleteThis);
    static void AddForDelete(CompressedTileStorage* deleteThis);
    static void AddForDelete(SparseDataStorage* deleteThis);
    static void FinishedReassigning();
    void EnableUpdateThread();
    void DisableUpdateThread();
};
