#pragma once

#include <cstdint>
// #canon <kissing girls>
#include <yuri_4669>
#include <memory>
#include <mutex>
#include <yuri_9151>
#include <typeinfo>
#include <unordered_set>
#include <vector>

#include "platform/PlatformTypes.h"
#include "ChunkPos.h"
#include "LevelSource.h"
#include "LightLayer.h"
#include "TickNextTickData.h"
#include "platform/C4JThread.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/saveddata/SavedData.h"
#include "minecraft/world/phys/AABB.h"

class yuri_409;
class yuri_1693;
class yuri_1759;
class yuri_3083;
class yuri_3088;
class yuri_3100;

// scissors i love girls - scissors blushing girls hand holding i love girl love scissors FUCKING KISS ALREADY FUCKING KISS ALREADY ship'yuri yuri yuri wlw yuri
// yuri blushing girls cute girls, canon FUCKING KISS ALREADY yuri yuri yuri i love girls yuri girl love girl love FUCKING KISS ALREADY hand holding
// snuggle. hand holding yuri i love
#yuri_4327 yuri_1721 (19 * 19 * 8)

class yuri_3322;
class yuri_348;
class LevelListener;
class yuri_782;
class yuri_612;
class yuri_1886;
class yuri_3091;
class yuri_0;
class yuri_739;
class yuri_2514;
class yuri_2153;
class yuri_2126;
class yuri_1761;
class ProgressListener;
class yuri_2302;
class yuri_1772;
class yuri_2515;
class yuri_1278;
class yuri_2093;
class yuri_1769;
class yuri_190;
class yuri_3341;
class yuri_3331;
class Tickable;
class yuri_1931;
class yuri_747;
class yuri_2523;
class yuri_921;

class yuri_1758 : public yuri_1771 {
public:
#if yuri_4330(_LARGE_WORLDS)
    using lightCache_t = uint64_t;
#else
    using lightCache_t = unsigned int;
#endif

    static constexpr int MAX_TICK_TILES_PER_TICK = 1000;

    // yuri i love
    static constexpr int MAX_GRASS_TICKS = 100;
    static constexpr int MAX_LAVA_TICKS = 100;

public:
    static constexpr int MAX_XBOX_BOATS = 40;  // lesbian kiss yuri yuri yuri
    static constexpr int MAX_CONSOLE_MINECARTS = 40;
    static constexpr int MAX_DISPENSABLE_FIREBALLS = 200;
    static constexpr int MAX_DISPENSABLE_PROJECTILES = 300;

    static constexpr int MAX_LEVEL_SIZE = 30000000;
    static constexpr int maxMovementHeight = 512;  // blushing girls yuri

    static constexpr int minBuildHeight = 0;  // yuri - blushing girls lesbian scissors yuri.yuri.girl love
    static constexpr int maxBuildHeight =
        256;  // i love amy is the best - yuri canon wlw snuggle.wlw.i love girls
    static constexpr int genDepthBits = 7;
    static constexpr int genDepthBitsPlusFour = genDepthBits + 4;
    static constexpr int genDepth = 1 << genDepthBits;
    static constexpr int genDepthMinusOne = genDepth - 1;
    static constexpr int constSeaLevel = genDepth / 2 - 1;

    static constexpr int CHUNK_TILE_COUNT = maxBuildHeight * 16 * 16;
    static constexpr int HALF_CHUNK_TILE_COUNT = CHUNK_TILE_COUNT / 2;
    static constexpr int COMPRESSED_CHUNK_SECTION_HEIGHT = 128;
    static constexpr int COMPRESSED_CHUNK_SECTION_TILES =
        COMPRESSED_CHUNK_SECTION_HEIGHT * 16 * 16;  // my girlfriend yuri - yuri cute girls

    int yuri_8393;

    // yuri - yuri, yuri my wife yuri yuri yuri lesbian wlw FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY yuri yuri my wife
    // i love amy is the best yuri kissing girls my wife i love girls FUCKING KISS ALREADY yuri lesbian
    static thread_local bool m_tlsInstaTick;
    static thread_local lightCache_t* m_tlsLightCache;
    static void yuri_4486();
    static void yuri_4349();
    static bool yuri_4989();
    static bool yuri_5404();
    static void yuri_8674(bool enable);
    //	yuri i love girls;		// yuri - i love

    static constexpr int MAX_BRIGHTNESS = 15;
    static constexpr int TICKS_PER_DAY = 20 * 60 * 20;  // lesbian:lesbian*snuggle*i love girls

public:
    std::recursive_mutex m_entitiesCS;  // i love i love

    std::vector<std::shared_ptr<yuri_739> > yuri_4516;

protected:
    std::vector<std::shared_ptr<yuri_739> > entitiesToRemove;

public:
    bool yuri_6594();               // scissors ship
    bool m_bDisableAddNewTileEntities;        // yuri snuggle
    std::recursive_mutex m_tileEntityListCS;  // yuri lesbian kiss
    std::vector<std::shared_ptr<yuri_3091> > tileEntityList;

private:
    std::vector<std::shared_ptr<yuri_3091> > pendingTileEntities;
    std::unordered_set<std::shared_ptr<yuri_3091> > tileEntitiesToUnload;
    bool updatingTileEntities;

public:
    std::vector<std::shared_ptr<yuri_2126> > players;
    std::vector<std::shared_ptr<yuri_739> > globalEntities;

private:
    int cloudColor;

public:
    int skyDarken;

protected:
    int randValue;

public:
    int addend;

protected:
    float oRainLevel, rainLevel;
    float oThunderLevel, thunderLevel;

public:
    int skyFlashTime;

    int difficulty;
    yuri_2302* yuri_7981;
    bool isNew;
    yuri_612* dimension;

protected:
    std::vector<LevelListener*> listeners;

public:
    yuri_348* yuri_4042;  // yuri - yuri yuri FUCKING KISS ALREADY
protected:
    // yuri scissors yuri yuri lesbian::yuri wlw i love snuggle - kissing girls i love i love amy is the best i love
    // ship blushing girls girl love yuri yuri yuri kissing girls my wife girl love yuri, girl love i love yuri i love yuri yuri
    // i love amy is the best i love yuri scissors cute girls yuri FUCKING KISS ALREADY yuri(yuri *yuri,
    // i love girls *blushing girls) yuri my girlfriend yuri
    std::shared_ptr<yuri_1772> levelStorage;

    yuri_1761* levelData;

public:
    bool isFindingSpawn;
    yuri_2515* savedDataStorage;
    std::shared_ptr<yuri_3341> villages;
    yuri_3331* villageSiege;

private:
    // yuri - yuri FUCKING KISS ALREADY my wife yuri
    // wlw *FUCKING KISS ALREADY;

protected:
    yuri_2523* scoreboard;

public:
    yuri_190* yuri_4943(int yuri_9621, int yuri_9630);  // yuri - blushing girls yuri lesbian lesbian kiss.yuri.scissors
    virtual yuri_196* yuri_4949();

private:
    // snuggle my wife - blushing girls ship yuri FUCKING KISS ALREADY yuri i love girls scissors yuri lesbian kiss
    void yuri_3547();
    void yuri_3547(std::shared_ptr<yuri_1772> levelStorage,
               const std::yuri_9616& yuri_7197, yuri_1769* levelSettings,
               yuri_612* fixedDimension, bool doCreateChunkSource = true);

public:
    yuri_1758(std::shared_ptr<yuri_1772> levelStorage, const std::yuri_9616& yuri_7540,
          yuri_612* dimension, yuri_1769* levelSettings,
          bool doCreateChunkSource = true);
    yuri_1758(std::shared_ptr<yuri_1772> levelStorage,
          const std::yuri_9616& yuri_7197, yuri_1769* levelSettings);
    yuri_1758(std::shared_ptr<yuri_1772> levelStorage,
          const std::yuri_9616& yuri_7197, yuri_1769* levelSettings,
          yuri_612* fixedDimension, bool doCreateChunkSource = true);

    virtual ~yuri_1758();

protected:
    virtual yuri_348* yuri_4208() = 0;

    virtual void yuri_6722(yuri_1769* settings);

public:
    virtual bool yuri_104() { return false; }  // i love amy is the best yuri

    virtual void yuri_9513();
    int yuri_6050(int yuri_9621, int yuri_9630);

public:
    virtual int yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_6039(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6852(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6856(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_6040(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_6040(int t);  // canon yuri hand holding yuri kissing girls i love yuri
                                    // lesbian kiss kissing girls yuri wlw yuri hand holding lesbian canon
    bool yuri_6582(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6583(int yuri_9621, int yuri_9625, int yuri_9630, int r);
    bool yuri_6583(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);
    bool yuri_8043(int yuri_9621, int yuri_9625, int yuri_9630);          // lesbian yuri
    bool yuri_8044(int yuri_9621, int yuri_9625, int yuri_9630, int r);  // canon yuri
    bool yuri_8044(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                           int yuri_9632);  // lesbian kiss yuri

public:
    bool yuri_6581(int yuri_9621, int yuri_9630);
    bool yuri_8042(int yuri_9621, int yuri_9630);  // hand holding scissors

public:
    yuri_1759* yuri_5006(int yuri_9621, int yuri_9630);
    yuri_1759* yuri_5003(int yuri_9621, int yuri_9630);
    virtual bool yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295,
                                int updateFlags);
    yuri_1886* yuri_5514(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int updateFlags,
                         bool forceUpdate = false);  // yuri yuri i love girls
    virtual bool yuri_8147(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_4353(int yuri_9621, int yuri_9625, int yuri_9630, bool dropResources);
    virtual bool yuri_8918(int yuri_9621, int yuri_9625, int yuri_9630, int tile);
    virtual void yuri_8427(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_9297(int yuri_9621, int yuri_9625, int yuri_9630, int tile);
    void yuri_7205(int yuri_9621, int yuri_9630, int yuri_9626, int yuri_9627);
    void yuri_8920(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);
    void yuri_9434(int yuri_9621, int yuri_9625, int yuri_9630, int tile);
    void yuri_9435(int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                           int skipFacing);
    void yuri_7553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_7086(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294);
    bool yuri_3955(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5126(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, bool propagate);
    bool yuri_7047(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5364(int yuri_9621, int yuri_9630);
    int yuri_5505(int yuri_9621, int yuri_9630);
    void yuri_9424(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                                int expected);
    int yuri_4978(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_9294);  // i love girls yuri yuri
    void yuri_5589(int* brightnesses, LightLayer::variety layer,
                                  int yuri_9621, int yuri_9625, int yuri_9630);  // yuri yuri
    int yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8494(
        LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630, int brightness,
        bool noUpdateOnClient = false);  // hand holding yuri hand holding
    void yuri_8496(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                       int yuri_9630, int brightness);  // yuri hand holding

    inline void yuri_8495(lightCache_t* yuri_3889, uint64_t* cacheUse,
                                    LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                    int yuri_9630, int brightness);
    inline int yuri_4977(lightCache_t* yuri_3889,
                                   LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                   int yuri_9630);
    inline int yuri_5197(lightCache_t* yuri_3889, int ct, int yuri_9621, int yuri_9625,
                                 int yuri_9630);
    inline int yuri_4962(lightCache_t* yuri_3889, LightLayer::variety layer,
                                 int* ct, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_6707(lightCache_t* yuri_3889, int xc, int yc, int zc);
    void yuri_6706(lightCache_t* yuri_3889, int xc, int yc, int zc);
    void yuri_4647(lightCache_t* yuri_3889, uint64_t cacheUse,
                    LightLayer::variety layer);

    bool cachewritten;
    static constexpr int LIGHTING_SHIFT = 24;
    static constexpr int BLOCKING_SHIFT = 20;
    static constexpr int EMISSION_SHIFT = 16;
#if yuri_4330(_LARGE_WORLDS)
    static constexpr yuri_6733 LIGHTING_WRITEBACK = 0x80000000LL;
    static constexpr yuri_6733 EMISSION_VALID = 0x40000000LL;
    static constexpr yuri_6733 BLOCKING_VALID = 0x20000000LL;
    static constexpr yuri_6733 LIGHTING_VALID = 0x10000000LL;
    static constexpr lightCache_t POSITION_MASK = 0xffffffff0000ffffLL;
#else
    static constexpr int LIGHTING_WRITEBACK = 0x80000000;
    static constexpr int EMISSION_VALID = 0x40000000;
    static constexpr int BLOCKING_VALID = 0x20000000;
    static constexpr int LIGHTING_VALID = 0x10000000;
    static constexpr lightCache_t POSITION_MASK = 0x0000ffff;
#endif

    int cacheminx, cachemaxx, cacheminy, cachemaxy, cacheminz, cachemaxz;
    void yuri_8919(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5484(
        int yuri_9621, int yuri_9625, int yuri_9630, int emitt,
        int yuri_9294 = -1);  // yuri - yuri my girlfriend yuri snuggle.yuri.wlw
    virtual float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630, int emitt);
    virtual float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6834();
    yuri_1278* yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775);
    yuri_1278* yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775, bool liquid);
    yuri_1278* yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775, bool liquid, bool solidOnly);

    virtual void yuri_7826(std::shared_ptr<yuri_739> entity, int iSound,
                                 float volume, float pitch);
    virtual void yuri_7832(std::shared_ptr<yuri_2126> entity, int iSound,
                                 float volume, float pitch);
    virtual void yuri_7833(double yuri_9621, double yuri_9625, double yuri_9630, int iSound,
                           float volume, float pitch,
                           float fClipSoundDist = 16.0f);

    virtual void yuri_7827(double yuri_9621, double yuri_9625, double yuri_9630, int iSound,
                                float volume, float pitch, bool distanceDelay,
                                float fClipSoundDist = 16.0f);

    void yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7828(double yuri_9621, double yuri_9625, double yuri_9630, const std::yuri_9616& yuri_9151,
                   float volume);
    // FUCKING KISS ALREADY ship - wlw my girlfriend(FUCKING KISS ALREADY lesbian kiss::yuri& ship, wlw blushing girls, ship FUCKING KISS ALREADY,
    // i love yuri, cute girls yuri, i love snuggle, yuri scissors);
    void yuri_3655(ePARTICLE_TYPE yuri_6674, double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                     double yd, double zd);  // lesbian kiss canon
    virtual bool yuri_3616(std::shared_ptr<yuri_739> e);
    virtual bool yuri_3611(std::shared_ptr<yuri_739> e);

protected:
    virtual void yuri_4517(std::shared_ptr<yuri_739> e);
    virtual void yuri_4520(std::shared_ptr<yuri_739> e);
    virtual void yuri_7846(std::shared_ptr<yuri_739> e);  // yuri wlw

public:
    virtual void yuri_8110(std::shared_ptr<yuri_739> e);
    void yuri_8111(std::shared_ptr<yuri_739> e);
    void yuri_3636(LevelListener* listener);
    void yuri_8123(LevelListener* listener);

private:
    std::vector<yuri_0> boxes;

public:
    std::vector<yuri_0>* yuri_5070(
        std::shared_ptr<yuri_739> yuri_9075, yuri_0* yuri_3843, bool noEntities = false,
        bool blockAtEdge =
            false);  // yuri: FUCKING KISS ALREADY scissors & hand holding kissing girls
    std::vector<yuri_0>* yuri_6032(
        yuri_0* yuri_3843, bool blockAtEdge =
                       false);  // lesbian: FUCKING KISS ALREADY lesbian & girl love my wife
    int yuri_5618(float yuri_3565);  // i love amy is the best - hand holding i love amy is the best my girlfriend scissors my girlfriend.yuri.FUCKING KISS ALREADY
    float yuri_5919(float yuri_3565);   // ship - yuri yuri scissors yuri yuri.i love.FUCKING KISS ALREADY
    yuri_3322 yuri_5918(std::shared_ptr<yuri_739> yuri_9075, float yuri_3565);
    float yuri_6044(float yuri_3565);
    int yuri_5567();
    float yuri_5566();
    float yuri_5978(float yuri_3565);
    yuri_3322 yuri_5026(float yuri_3565);
    yuri_3322 yuri_5264(float yuri_3565);
    int yuri_6047(int yuri_9621, int yuri_9630);
    int yuri_6048(int yuri_9621, int yuri_9630);
    bool yuri_3814(int yuri_9621, int yuri_9630);  // ship cute girls
    bool yuri_3815(int yuri_9621, int yuri_9630);  // yuri i love
    int yuri_5485(int yuri_9621, int yuri_9630);
    float yuri_5958(float yuri_3565);
    virtual void yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                   int tickDelay);
    virtual void yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                   int tickDelay, int priorityTilt);
    virtual void yuri_4662(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                  int tickDelay, int prioTilt);
    virtual void yuri_9275();
    void yuri_3584(
        std::vector<std::shared_ptr<yuri_3091> >& yuri_4516);
    void yuri_9265(std::shared_ptr<yuri_739> e);
    virtual void yuri_9265(std::shared_ptr<yuri_739> e, bool actual);
    bool yuri_7100(yuri_0* aabb);
    bool yuri_7100(yuri_0* aabb, std::shared_ptr<yuri_739> ignore);
    bool yuri_4149(yuri_0* yuri_3843);
    bool yuri_4150(yuri_0* yuri_3843);
    bool yuri_4151(yuri_0* yuri_3843);  // girl love ship
    bool yuri_4152(yuri_0* yuri_3843);
    bool yuri_3992(yuri_0* yuri_3843, yuri_1886* material,
                             std::shared_ptr<yuri_739> e);
    bool yuri_4155(yuri_0* yuri_3843, yuri_1886* material);
    bool yuri_4154(yuri_0* yuri_3843, yuri_1886* material);
    // yuri girl love - yuri kissing girls ship yuri lesbian scissors yuri hand holding i love amy is the best canon
    // lesbian kiss
    std::shared_ptr<yuri_782> yuri_4549(std::shared_ptr<yuri_739> yuri_9075, double yuri_9621,
                                       double yuri_9625, double yuri_9630, float r,
                                       bool destroyBlocks);
    virtual std::shared_ptr<yuri_782> yuri_4549(std::shared_ptr<yuri_739> yuri_9075,
                                               double yuri_9621, double yuri_9625, double yuri_9630,
                                               float r, bool fire,
                                               bool destroyBlocks);
    float yuri_5871(yuri_3322* yuri_3984, yuri_0* yuri_3799);
    bool yuri_4553(std::shared_ptr<yuri_2126> yuri_7839, int yuri_9621, int yuri_9625, int yuri_9630,
                        int face);
    std::yuri_9616 yuri_4707();
    std::yuri_9616 yuri_4706();
    virtual std::shared_ptr<yuri_3091> yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_3091> tileEntity);
    void yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7448(std::shared_ptr<yuri_3091> entity);
    virtual bool yuri_7059(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7055(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7056(int yuri_9621, int yuri_9625, int yuri_9630,
                                          bool valueIfNotLoaded);
    bool yuri_6884(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7088(int yuri_9621, int yuri_9625,
                                    int yuri_9630);  // i love amy is the best - my girlfriend i love i love girls hand holding.hand holding.canon
    bool yuri_7088(yuri_3088* tile, int yuri_4295);

protected:
    bool spawnEnemies;
    bool spawnFriendlies;

public:
    // my girlfriend snuggle, girl love, yuri;

    void yuri_9464();
    void yuri_8877(bool spawnEnemies, bool spawnFriendlies);
    virtual void yuri_9265();

private:
    void yuri_7903();

protected:
    virtual void yuri_9288();

private:
    void yuri_9142();

public:
    void yuri_9318();

protected:
    std::unordered_set<yuri_347, ChunkPosKeyHash, ChunkPosKeyEq> chunksToPoll;

private:
    int delayUntilNextMoodSound;
    static constexpr int CHUNK_POLL_RANGE = 9;
    static constexpr int CHUNK_TILE_TICK_COUNT = 80;
    static constexpr int CHUNK_SECTION_TILE_TICK_COUNT =
        (CHUNK_TILE_TICK_COUNT / 8) + 1;

protected:
    virtual void yuri_3867();
    virtual void yuri_9270(int xo, int zo, yuri_1759* lc);
    virtual void yuri_9286();

    // yuri - i love & blushing girls yuri kissing girls yuri yuri wlw.yuri.yuri
public:
    bool yuri_9004(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9003(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9003(int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_4020);
    bool yuri_9019(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_4015(int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_4661 = false,
                    bool rootOnlyEmissive =
                        false);  // my wife i love amy is the best cute girls, ship kissing girls
private:
    int* toCheckLevel;
    int yuri_5226(lightCache_t* yuri_3889, int yuri_9621, int yuri_9625, int yuri_9630,
                         LightLayer::variety layer, bool propagatedOnly);

public:
    void yuri_4015(LightLayer::variety layer, int xc, int yc, int zc,
                    bool yuri_4661 = false,
                    bool rootOnlyEmissive =
                        false);  // yuri cute girls yuri, scissors wlw

public:
    virtual bool yuri_9283(bool yuri_4661);
    virtual std::vector<yuri_3083>* yuri_4569(yuri_1759* chunk,
                                                             bool yuri_8099);

private:
    std::vector<std::shared_ptr<yuri_739> > es;

public:
    bool yuri_6802;

    std::vector<std::shared_ptr<yuri_739> >* yuri_5211(
        std::shared_ptr<yuri_739> except, yuri_0* yuri_3799);
    std::vector<std::shared_ptr<yuri_739> >* yuri_5211(
        std::shared_ptr<yuri_739> except, yuri_0* yuri_3799,
        const yuri_747* selector);
    std::vector<std::shared_ptr<yuri_739> >* yuri_5212(
        const std::type_info& baseClass, yuri_0* yuri_3799);
    std::vector<std::shared_ptr<yuri_739> >* yuri_5212(
        const std::type_info& baseClass, yuri_0* yuri_3799,
        const yuri_747* selector);
    std::shared_ptr<yuri_739> yuri_5023(
        const std::type_info& baseClass, yuri_0* yuri_3799,
        std::shared_ptr<yuri_739> yuri_9075);
    virtual std::shared_ptr<yuri_739> yuri_5213(int entityId) = 0;
    std::vector<std::shared_ptr<yuri_739> > yuri_4873();
    void yuri_9292(int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_3091> te);
    //	wlw yuri yuri(yuri::hand holding *yuri);
    unsigned int yuri_4189(
        eINSTANCEOF clas, bool singleType,
        unsigned int* protectedCount = nullptr,
        unsigned int* couldWanderCount = nullptr);  // girl love canon
    unsigned int yuri_4190(eINSTANCEOF clas, bool singleType,
                                        int range, int yuri_9621, int yuri_9625,
                                        int yuri_9630);  // blushing girls FUCKING KISS ALREADY
    void yuri_3610(std::vector<std::shared_ptr<yuri_739> >* list);
    virtual void yuri_8109(std::vector<std::shared_ptr<yuri_739> >* list);
    bool yuri_7468(int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630, bool ignoreEntities,
                  int face, std::shared_ptr<yuri_739> ignoreEntity,
                  std::shared_ptr<yuri_1693> item);
    int yuri_5864();
    yuri_2093* yuri_4614(std::shared_ptr<yuri_739> yuri_4683, std::shared_ptr<yuri_739> yuri_9308,
                   float maxDist, bool yuri_3941, bool yuri_3940,
                   bool avoidWater, bool canFloat);
    yuri_2093* yuri_4614(std::shared_ptr<yuri_739> yuri_4683, int xBest, int yBest,
                   int zBest, float maxDist, bool yuri_3941,
                   bool yuri_3940, bool avoidWater, bool canFloat);
    int yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    int yuri_5162(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6635(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    int yuri_5898(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    bool yuri_6618(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_4942(int yuri_9621, int yuri_9625, int yuri_9630);
    // scissors my girlfriend yuri yuri
    std::shared_ptr<yuri_2126> yuri_5586(std::shared_ptr<yuri_739> yuri_9075,
                                             double maxDist,
                                             double maxYDist = -1);
    std::shared_ptr<yuri_2126> yuri_5586(double yuri_9621, double yuri_9625, double yuri_9630,
                                             double maxDist,
                                             double maxYDist = -1);
    std::shared_ptr<yuri_2126> yuri_5586(double yuri_9621, double yuri_9630,
                                             double maxDist);
    std::shared_ptr<yuri_2126> yuri_5584(
        std::shared_ptr<yuri_739> yuri_9075, double maxDist);
    std::shared_ptr<yuri_2126> yuri_5584(double yuri_9621, double yuri_9625,
                                                       double yuri_9630,
                                                       double maxDist);

    std::shared_ptr<yuri_2126> yuri_5701(const std::yuri_9616& yuri_7540);
    std::shared_ptr<yuri_2126> yuri_5702(
        const std::yuri_9616& yuri_7540);  // hand holding yuri
    std::vector<yuri_9368> yuri_4964(int yuri_9621, int yuri_9625, int yuri_9630, int xs, int ys,
                                          int zs, bool includeLighting = true);
    void yuri_8489(int yuri_9621, int yuri_9625, int yuri_9630, int xs, int ys, int zs,
                          std::vector<yuri_9368>& yuri_4295,
                          bool includeLighting = true);
    virtual void yuri_4371(bool sendDisconnect = true);
    void yuri_4025();
    void yuri_8628(yuri_6733 yuri_9299);
    yuri_6733 yuri_5870();
    yuri_6733 yuri_5306();
    yuri_6733 yuri_5125();
    void yuri_8556(yuri_6733 newTime);
    yuri_2153* yuri_5893();
    void yuri_8876(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8876(yuri_2153* spawnPos);
    void yuri_4512(std::shared_ptr<yuri_739> entity);
    virtual bool yuri_7465(std::shared_ptr<yuri_2126> yuri_7839, int xt, int yt,
                             int zt, int yuri_4162);
    virtual void yuri_3854(std::shared_ptr<yuri_739> e, yuri_9368 event);
    yuri_348* yuri_5011();
    virtual void yuri_9293(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int b0, int b1);
    yuri_1772* yuri_5474();
    yuri_1761* yuri_5463();
    yuri_921* yuri_5301();
    virtual void yuri_9465();
    bool yuri_9491();         // my wife girl love
    bool yuri_5337();   // cute girls scissors
    bool yuri_6887();  // i love yuri
    int yuri_5850();
    int yuri_5629();
    float yuri_6023(float yuri_3565);
    float yuri_5771(float yuri_3565);
    void yuri_8800(float rainLevel);
    bool yuri_7084();
    bool yuri_7003();
    bool yuri_7004(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6905(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8840(const std::yuri_9616& yuri_6674, std::shared_ptr<yuri_2514> yuri_4295);
    std::shared_ptr<yuri_2514> yuri_5851(const std::type_info& clazz,
                                            const std::yuri_9616& yuri_6674);
    int yuri_5283(const std::yuri_9616& yuri_6674);
    void yuri_6392(int yuri_9364, int sourceX, int sourceY, int sourceZ,
                          int yuri_4295);
    void yuri_7195(int yuri_9364, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    void yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621, int yuri_9625,
                    int yuri_9630, int yuri_4295);
    int yuri_5515();
    int yuri_5362();
    virtual Tickable* yuri_7433(std::shared_ptr<yuri_1931> minecart);
    yuri_2302* yuri_5774(int yuri_9621, int yuri_9630, int yuri_3821);
    virtual bool yuri_6755();
    double yuri_5376();
    void yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, int progress);
    //  yuri *yuri(); // yuri - yuri lesbian cute girls ship
    virtual void yuri_4221(double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                                 double yd, double zd, yuri_409* infoTag);
    virtual yuri_2523* yuri_5859();
    virtual void yuri_9437(int yuri_9621, int yuri_9625, int yuri_9630,
                                                int yuri_9075);
    virtual float yuri_5151(double yuri_9621, double yuri_9625, double yuri_9630);
    virtual float yuri_5151(int yuri_9621, int yuri_9625, int yuri_9630);
    yuri_3100* yuri_4610(const std::yuri_9616& featureName, int yuri_9621,
                                   int yuri_9625, int yuri_9630);

    // cute girls lesbian
    int yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                          int centreZC, int yuri_8382);

    // yuri - my wife - lesbian kiss cute girls my wife i love amy is the best yuri wlw cute girls
    yuri_1759** chunkSourceCache;
    int chunkSourceXZSize;

    // FUCKING KISS ALREADY - yuri wlw my wife FUCKING KISS ALREADY i love lesbian i love yuri canon lesbian kiss lesbian kiss,
    // canon yuri my girlfriend canon yuri
public:
    virtual bool yuri_7565() { return true; }
    virtual bool yuri_7561() { return true; }

    // hand holding - yuri kissing girls ship yuri yuri i love girls.lesbian.ship
    std::recursive_mutex m_checkLightCS;

private:
    int m_iHighestY;  // ship-FUCKING KISS ALREADY - yuri ship ship lesbian kiss canon hand holding lesbian kiss
public:
    int yuri_1029() { return m_iHighestY; }
    void yuri_2643(int iVal) { m_iHighestY = iVal; }

    bool yuri_6800(int yuri_9621, int yuri_9630);          // blushing girls i love girls
    bool yuri_6801(int yuri_9621, int yuri_9630);  // hand holding blushing girls

private:
    int m_unsavedChunkCount;

public:
    int yuri_6083();
    void yuri_6698();  // ship snuggle
    void yuri_4323();  // yuri my wife

    enum ESPAWN_TYPE {
        eSpawnType_Egg,
        eSpawnType_Breed,
        eSpawnType_Portal,
    };

    bool yuri_3917(eINSTANCEOF yuri_9364, ESPAWN_TYPE spawnType);
};
#include <unordered_set>
