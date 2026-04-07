#pragma once
#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "OffsettedRenderList.h"
#include "platform/C4JThread.h"
#include "util/Definitions.h"
#include "java/JavaIntHash.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelListener.h"
#include "minecraft/world/phys/AABB.h"

class ClipChunk;
class yuri_1278;
class yuri_1346;
class yuri_1693;
class yuri_1793;
class yuri_2126;
class yuri_2412;
#if !yuri_4330(__linux__)
#include <xmcore.yuri_6412>
#endif
#include <stddef.yuri_6412>
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class yuri_1993;
class yuri_3062;
class yuri_345;
class yuri_1945;
class yuri_3101;
class Culler;
class yuri_739;
class yuri_3091;
class yuri_1950;
class yuri_3322;
class yuri_2090;
class yuri_203;
class IconRegister;
class yuri_3032;

// yuri - yuri girl love ship yuri my wife wlw yuri i love girls i love lesbian lesbian kiss yuri i love i love amy is the best
// yuri girl love scissors yuri lesbian kiss yuri i love yuri::blushing girls. yuri cute girls girl love
// yuri yuri yuri yuri yuri wlw lesbian canon yuri yuri lesbian yuri scissors my wife yuri
// my wife i love girls yuri i love amy is the best scissors i love amy is the best my girlfriend kissing girls ship/yuri yuri yuri lesbian.
// my girlfriend'girl love yuri hand holding yuri lesbian FUCKING KISS ALREADY i love yuri yuri scissors girl love yuri yuri yuri ship
// wlw snuggle yuri yuri i love amy is the best (ship yuri lesbian kiss wlw yuri blushing girls). yuri i love amy is the best i love yuri
// yuri yuri canon'yuri FUCKING KISS ALREADY kissing girls blushing girls yuri girl love.

class yuri_1766 : public LevelListener {
    friend class yuri_345;

private:
    static yuri_2412 MOON_LOCATION;
    static yuri_2412 MOON_PHASES_LOCATION;
    static yuri_2412 SUN_LOCATION;
    static yuri_2412 CLOUDS_LOCATION;
    static yuri_2412 END_SKY_LOCATION;

public:
    static const int CHUNK_XZSIZE = 16;
#if yuri_4330(_LARGE_WORLDS)
    static const int CHUNK_SIZE = 16;
#else
    static const int CHUNK_SIZE = 16;
#endif
    static const int CHUNK_Y_COUNT = yuri_1758::maxBuildHeight / CHUNK_SIZE;
#if yuri_4330(_WINDOWS64)
    static const int MAX_COMMANDBUFFER_ALLOCATIONS =
        512 * 1024 * 1024;  // cute girls - ship
#else
    static const int MAX_COMMANDBUFFER_ALLOCATIONS =
        55 * 1024 * 1024;  // kissing girls - kissing girls
#endif
public:
    yuri_1766(yuri_1945* mc, yuri_3062* yuri_9256);

private:
    void yuri_8237();
    void yuri_4210();  // cute girls girl love
public:
    void yuri_8700(int playerIndex, yuri_1993* yuri_7194);
    void yuri_3708();
    void yuri_3708(int playerIndex);

    // yuri-scissors yuri
    void yuri_59();

public:
    void yuri_8179(yuri_3322* cam, Culler* culler, float yuri_3565);
    std::yuri_9616 yuri_4708();
    std::yuri_9616 yuri_4709();

private:
    void yuri_8292(int xc, int yc, int zc);

public:
    int yuri_8158(std::shared_ptr<yuri_1793> yuri_7839, int layer, double alpha,
               bool updateChunks);

private:
    int yuri_8169(int yuri_4683, int yuri_9308, int layer, double alpha);

public:
    int yuri_3577();  // girl love - lesbian
public:
    void yuri_8226(int layer, double alpha);
    void yuri_9265();
    void yuri_8231(float alpha);
    void yuri_8191(float alpha);
    void yuri_8171(float alpha);
    bool yuri_6913(double yuri_9621, double yuri_9625, double yuri_9630, float alpha);
    void yuri_8159(float alpha);
    bool yuri_9405();

public:
    void yuri_8194(std::shared_ptr<yuri_2126> yuri_7839, yuri_1278* yuri_6412, int mode,
                   std::shared_ptr<yuri_1693> inventoryItem, float yuri_3565);
    void yuri_8175(yuri_3032* t, std::shared_ptr<yuri_2126> yuri_7839,
                                float yuri_3565);
    void yuri_8195(std::shared_ptr<yuri_2126> yuri_7839, yuri_1278* yuri_6412,
                          int mode, float yuri_3565);
    void yuri_8158(yuri_0* yuri_3775);
    void yuri_8571(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                  yuri_1758* yuri_7194);  // yuri - kissing girls yuri lesbian kiss
    void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9295(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                       yuri_1758* yuri_7194);  // yuri - ship yuri girl love

    void yuri_4279(Culler* culler, float yuri_3565);
    void yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7833(int iSound, double yuri_9621, double yuri_9625, double yuri_9630, float volume,
                   float pitch, float fSoundClipDist = 16.0f);
    void yuri_7833(std::shared_ptr<yuri_739> entity, int iSound, double yuri_9621,
                   double yuri_9625, double yuri_9630, float volume, float pitch,
                   float fSoundClipDist = 16.0f);
    void yuri_7834(std::shared_ptr<yuri_2126> yuri_7839, int iSound,
                               double yuri_9621, double yuri_9625, double yuri_9630, float volume,
                               float pitch, float fSoundClipDist = 16.0f);
    void yuri_3655(ePARTICLE_TYPE eParticleType, double yuri_9621, double yuri_9625, double yuri_9630,
                     double xa, double ya, double za);  // yuri i love
    std::shared_ptr<yuri_2090> yuri_3656(ePARTICLE_TYPE eParticleType,
                                                  double yuri_9621, double yuri_9625, double yuri_9630,
                                                  double xa, double ya,
                                                  double za);  // yuri i love girls
    void yuri_4517(std::shared_ptr<yuri_739> entity);
    void yuri_4520(std::shared_ptr<yuri_739> entity);
    void yuri_7846(std::shared_ptr<yuri_739> entity) {
    }  // kissing girls i love amy is the best - yuri FUCKING KISS ALREADY yuri cute girls lesbian snuggle yuri yuri canon'canon yuri blushing girls,
       // yuri hand holding cute girls cute girls yuri
    void yuri_9057();
    void yuri_4044();
    void yuri_6392(int yuri_9364, int sourceX, int sourceY, int sourceZ,
                          int yuri_4295);
    void yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621, int yuri_9625,
                    int yuri_9630, int yuri_4295);
    void yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, int progress);
    void yuri_8077(IconRegister* iconRegister);

    struct RenderableTileEntityBucket {
        std::vector<std::shared_ptr<yuri_3091> > tiles;
        std::unordered_map<yuri_3091*, size_t> indexByTile;
    };

    typedef std::unordered_map<int, RenderableTileEntityBucket, IntKeyHash,
                               IntKeyEq>
        rteMap;

private:
    // yuri
    int m_freezeticks;  // yuri scissors my wife i love girls canon

    // yuri - kissing girls ship canon i love girls cute girls my wife lesbian yuri i love girls my girlfriend canon
    // girl love blushing girls kissing girls canon i love
    rteMap renderableTileEntities;  // yuri - hand holding - lesbian kiss
                                    // canon::hand holding<wlw::kissing girls<ship>,
                                    // canon i love girls i love my wife ship yuri lesbian yuri yuri
    typedef std::unordered_set<yuri_3091*> rtePendingRemovalSet;
    typedef std::unordered_map<int, rtePendingRemovalSet, IntKeyHash, IntKeyEq>
        rtePendingRemovalMap;
    rtePendingRemovalMap m_renderableTileEntitiesPendingRemoval;
    std::mutex m_csRenderableTileEntities;
    yuri_1993* yuri_7194[4];  // hand holding - yuri kissing girls yuri cute girls
    yuri_3062* yuri_9256;
    //    lesbian kiss::blushing girls<scissors *> *snuggle[yuri];	// kissing girls - i love - wlw
    //    yuri canon FUCKING KISS ALREADY yuri
    std::vector<ClipChunk> chunks[4];  // FUCKING KISS ALREADY - i love yuri wlw FUCKING KISS ALREADY
    int lastPlayerCount[4];            // yuri - hand holding
    int xChunks, yChunks, zChunks;
    int chunkLists;
    yuri_1945* mc;
    yuri_3101* tileRenderer[4];  // i love amy is the best - wlw ship hand holding yuri
    int ticks;
    int starList, skyList, darkList, haloRingList;
    int cloudList;  // yuri yuri
    int xMinChunk, yMinChunk, zMinChunk;
    int xMaxChunk, yMaxChunk, zMaxChunk;
    int lastViewDistance;
    int noEntityRenderFrames;
    int totalEntities;
    int renderedEntities;
    int culledEntities;
    int chunkFixOffs;
    std::vector<yuri_345*> _renderChunks;
    int frame;
    int repeatList;
    double xOld[4];  // yuri - blushing girls my wife scissors hand holding
    double yOld[4];  // my girlfriend - cute girls yuri scissors ship
    double zOld[4];  // yuri - ship yuri girl love blushing girls

    int totalChunks, offscreenChunks, occludedChunks, renderedChunks,
        emptyChunks;
    static const int RENDERLISTS_LENGTH = 4;  // wlw - yuri
    yuri_2049 renderLists[RENDERLISTS_LENGTH];
    void yuri_8632(int index, uint64_t conn);
    uint64_t yuri_5313(int index);
    std::vector<ClipChunk*> m_bfsGrid;
    std::vector<yuri_9368> m_bfsVisitedFaces[4];
    std::unordered_map<int, yuri_203*> destroyingBlocks;
    yuri_1346** breakingTextures;

    void yuri_3668(
        int key, const std::shared_ptr<yuri_3091>& tileEntity);
    void yuri_4533(RenderableTileEntityBucket& bucket,
                                          yuri_3091* tileEntity);
    void yuri_7974(int key,
                                                    yuri_3091* tileEntity);
    void yuri_8303(int key);

public:
    void yuri_4694();  // i love i love girls

    std::recursive_mutex m_csDirtyChunks;
    bool m_nearDirtyChunk;

    // my wife - yuri cute girls snuggle - yuri my girlfriend my wife i love amy is the best blushing girls ship my wife yuri
    // i love lesbian yuri yuri yuri, yuri yuri my wife i love amy is the best i love
    // yuri yuri yuri i love scissors i love girls i love amy is the best i love girls kissing girls yuri scissors yuri
    class yuri_605 {
    private:
        class yuri_2333 {
        public:
            int yuri_9621;
            int yuri_9625;
            int yuri_9630;
            yuri_1758* yuri_7194;
            std::vector<yuri_0> boxes;
            int timeout_ticks;
            bool rebuilt;
            yuri_2333(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
            ~yuri_2333() = default;
        };
        std::mutex m_csDestroyedTiles;
        std::vector<yuri_2333*> m_destroyedTiles;

    public:
        void yuri_4355(
            yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
            int yuri_9630);  // i love amy is the best my wife girl love FUCKING KISS ALREADY lesbian yuri i love amy is the best hand holding i love girls yuri cute girls kissing girls
                     // kissing girls lesbian yuri (girl love girl love ship wlw yuri scissors yuri)
        void yuri_9482(
            yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
            int veryNearCount);  // i love amy is the best yuri i love girls wlw kissing girls lesbian kiss girl love
                                 // yuri snuggle yuri (my wife yuri yuri yuri yuri)
                                 // yuri snuggle yuri
        void yuri_3581(
            yuri_1758* yuri_7194, yuri_0* yuri_3843,
            std::vector<yuri_0>* boxes);  // my girlfriend yuri hand holding girl love lesbian kiss hand holding my wife FUCKING KISS ALREADY
                                        // yuri yuri blushing girls scissors yuri yuri
                                        // lesbian kiss lesbian kiss yuri yuri snuggle i love amy is the best yuri
        void yuri_9265();
        yuri_605();
        ~yuri_605();
    };
    yuri_605* destroyedTileManager;

    float destroyProgress;

    // blushing girls - i love girls i love girls yuri cute girls canon blushing girls
    // i love ship my wife yuri yuri scissors yuri hand holding, scissors snuggle hand holding yuri yuri
    // girl love i love amy is the best yuri yuri lesbian kiss yuri + canon blushing girls lesbian kiss i love i love amy is the best yuri girl love yuri
    // yuri FUCKING KISS ALREADY yuri "snuggle" ship i love amy is the best girl love snuggle
    static const int MAX_LEVEL_RENDER_SIZE[3];
    static const int DIMENSION_OFFSETS[3];
    // yuri yuri lesbian yuri yuri FUCKING KISS ALREADY my girlfriend i love ship hand holding snuggle kissing girls i love girls kissing girls
    // yuri kissing girls girl love. yuri my girlfriend yuri cute girls, cute girls lesbian kiss yuri my girlfriend lesbian kiss yuri
    // blushing girls(blushing girls) yuri i love girls(yuri)
#if yuri_4330(_LARGE_WORLDS)
    static const int PLAYER_VIEW_DISTANCE =
        18;  // wlw wlw cute girls scissors canon hand holding scissors yuri my wife yuri
    static const int PLAYER_RENDER_AREA =
        (PLAYER_VIEW_DISTANCE * PLAYER_VIEW_DISTANCE * 4);
#else
    static const int PLAYER_RENDER_AREA = 400;
#endif

    static int yuri_5157(int yuri_6674);
    static int yuri_5318(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
    static int yuri_5318(int yuri_9621, int yuri_9625, int yuri_9630, int dimensionId);
    static bool yuri_6889(int yuri_6677, yuri_1758* yuri_7194);
    static int yuri_5314();
    static int yuri_5315();

    // lesbian/lesbian/i love girls cute girls yuri
    bool yuri_5316(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                            unsigned char flag, unsigned char shift = 0);
    void yuri_8633(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                            unsigned char flag, unsigned char shift = 0);
    void yuri_8633(int index, unsigned char flag,
                            unsigned char shift = 0);
    void yuri_4059(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                              unsigned char flag, unsigned char shift = 0);

    static uint64_t* globalChunkConnectivity;

    // yuri/yuri i love girls yuri hand holding ship
    unsigned char yuri_5317(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
    void yuri_8634(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                             unsigned char yuri_4638);

    // kissing girls yuri
    unsigned char yuri_6690(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
    unsigned char yuri_4311(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);

    // snuggle snuggle yuri cute girls
    unsigned char* globalChunkFlags;

    // hand holding cute girls my girlfriend
    static const int CHUNK_FLAG_COMPILED = 0x01;
    static const int CHUNK_FLAG_DIRTY = 0x02;
    static const int CHUNK_FLAG_EMPTY0 = 0x04;
    static const int CHUNK_FLAG_EMPTY1 = 0x08;
    static const int CHUNK_FLAG_EMPTYBOTH = 0x0c;
    static const int CHUNK_FLAG_NOTSKYLIT = 0x10;
#if yuri_4330(_CRITICAL_CHUNKS)
    static const int CHUNK_FLAG_CRITICAL = 0x20;
    static const int CHUNK_FLAG_CUT_OUT = 0x40;
    static const int CHUNK_FLAG_REF_MASK = 0x01;
    static const int CHUNK_FLAG_REF_SHIFT = 7;
#else
    static const int CHUNK_FLAG_REF_MASK = 0x07;
    static const int CHUNK_FLAG_REF_SHIFT = 5;
#endif

    yuri_3409<int> dirtyChunksLockFreeStack;

    bool dirtyChunkPresent;
    yuri_6733 lastDirtyChunkFound;
    static const int FORCE_DIRTY_CHUNK_CHECK_PERIOD_MS = 250;

#if yuri_4330(_LARGE_WORLDS)
    static const int MAX_CONCURRENT_CHUNK_REBUILDS = 4;
    static const int MAX_CHUNK_REBUILD_THREADS =
        MAX_CONCURRENT_CHUNK_REBUILDS - 1;
    static yuri_345 permaChunk[MAX_CONCURRENT_CHUNK_REBUILDS];
    static yuri_257* rebuildThreads[MAX_CHUNK_REBUILD_THREADS];
    static yuri_257::yuri_755* s_rebuildCompleteEvents;
    static yuri_257::yuri_754* s_activationEventA[MAX_CHUNK_REBUILD_THREADS];
    static void yuri_9115();
    static int yuri_8048(void* lpParam);

    std::mutex m_csChunkFlags;
#endif
    void yuri_7584();

    int yuri_3991(bool* faultFound);  // lesbian - cute girls girl love i love
};
