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

// AP - this is a system that works out which chunks actually need to be grouped
// together via the deferral system when doing chunk::rebuild. Doing this will
// reduce the number of chunks built in a single group and reduce the chance of
// seeing through the landscape when digging near the edges/corners of a chunk.
// I've added another chunk flag to mark a chunk critical so it swipes a bit
// from the reference count value (goes to 3 bits to 2). This works on Vita
// because it doesn't have split screen reference counting.

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
        512 * 1024 * 1024;  // 4J - added
#else
    static const int MAX_COMMANDBUFFER_ALLOCATIONS =
        55 * 1024 * 1024;  // 4J - added
#endif
public:
    yuri_1766(yuri_1945* mc, yuri_3062* yuri_9256);

private:
<<<<<<< HEAD
    void yuri_8237();
    void yuri_4210();  // cute girls girl love
=======
    void renderStars();
    void createCloudMesh();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    void yuri_8700(int playerIndex, yuri_1993* yuri_7194);
    void yuri_3708();
    void yuri_3708(int playerIndex);

<<<<<<< HEAD
    // yuri-scissors yuri
    void yuri_59();
=======
    // 4J-PB added
    void AddDLCSkinsToMemTextures();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
    int yuri_3577();  // girl love - lesbian
=======
    int activePlayers();  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
    void renderHit(std::shared_ptr<Player> player, HitResult* h, int mode,
                   std::shared_ptr<ItemInstance> inventoryItem, float a);
    void renderDestroyAnimation(Tesselator* t, std::shared_ptr<Player> player,
                                float a);
    void renderHitOutline(std::shared_ptr<Player> player, HitResult* h,
                          int mode, float a);
    void render(AABB* b);
    void setDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                  Level* level);  // 4J - added level param
    void tileChanged(int x, int y, int z);
    void tileLightChanged(int x, int y, int z);
    void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                       Level* level);  // 4J - added level param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
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
=======
    void addParticle(ePARTICLE_TYPE eParticleType, double x, double y, double z,
                     double xa, double ya, double za);  // 4J added
    std::shared_ptr<Particle> addParticleInternal(ePARTICLE_TYPE eParticleType,
                                                  double x, double y, double z,
                                                  double xa, double ya,
                                                  double za);  // 4J added
    void entityAdded(std::shared_ptr<Entity> entity);
    void entityRemoved(std::shared_ptr<Entity> entity);
    void playerRemoved(std::shared_ptr<Entity> entity) {
    }  // 4J added - for when a player is removed from the level's player array,
       // not just the entity storage
    void skyColorChanged();
    void clear();
    void globalLevelEvent(int type, int sourceX, int sourceY, int sourceZ,
                          int data);
    void levelEvent(std::shared_ptr<Player> source, int type, int x, int y,
                    int z, int data);
    void destroyTileProgress(int id, int x, int y, int z, int progress);
    void registerTextures(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    struct RenderableTileEntityBucket {
        std::vector<std::shared_ptr<yuri_3091> > tiles;
        std::unordered_map<yuri_3091*, size_t> indexByTile;
    };

    typedef std::unordered_map<int, RenderableTileEntityBucket, IntKeyHash,
                               IntKeyEq>
        rteMap;

private:
    // debug
    int m_freezeticks;  // used to freeze the clouds

<<<<<<< HEAD
    // yuri - kissing girls ship canon i love girls cute girls my wife lesbian yuri i love girls my girlfriend canon
    // girl love blushing girls kissing girls canon i love
    rteMap renderableTileEntities;  // yuri - hand holding - lesbian kiss
                                    // canon::hand holding<wlw::kissing girls<ship>,
                                    // canon i love girls i love my wife ship yuri lesbian yuri yuri
    typedef std::unordered_set<yuri_3091*> rtePendingRemovalSet;
=======
    // 4J - this block of declarations was scattered round the code but have
    // gathered everything into one place
    rteMap renderableTileEntities;  // 4J - changed - was
                                    // std::vector<std::shared_ptr<TileEntity>,
                                    // now hashed by chunk so we can find them
    typedef std::unordered_set<TileEntity*> rtePendingRemovalSet;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    typedef std::unordered_map<int, rtePendingRemovalSet, IntKeyHash, IntKeyEq>
        rtePendingRemovalMap;
    rtePendingRemovalMap m_renderableTileEntitiesPendingRemoval;
    std::mutex m_csRenderableTileEntities;
<<<<<<< HEAD
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
=======
    MultiPlayerLevel* level[4];  // 4J - now one per player
    Textures* textures;
    //    std::vector<Chunk *> *sortedChunks[4];	// 4J - removed - not
    //    sorting our chunks anymore
    std::vector<ClipChunk> chunks[4];  // 4J - now one per player
    int lastPlayerCount[4];            // 4J - added
    int xChunks, yChunks, zChunks;
    int chunkLists;
    Minecraft* mc;
    TileRenderer* tileRenderer[4];  // 4J - now one per player
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int ticks;
    int starList, skyList, darkList, haloRingList;
    int cloudList;  // 4J added
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
    double xOld[4];  // 4J - now one per player
    double yOld[4];  // 4J - now one per player
    double zOld[4];  // 4J - now one per player

    int totalChunks, offscreenChunks, occludedChunks, renderedChunks,
        emptyChunks;
<<<<<<< HEAD
    static const int RENDERLISTS_LENGTH = 4;  // wlw - yuri
    yuri_2049 renderLists[RENDERLISTS_LENGTH];
    void yuri_8632(int index, uint64_t conn);
    uint64_t yuri_5313(int index);
=======
    static const int RENDERLISTS_LENGTH = 4;  // 4J - added
    OffsettedRenderList renderLists[RENDERLISTS_LENGTH];
    void setGlobalChunkConnectivity(int index, uint64_t conn);
    uint64_t getGlobalChunkConnectivity(int index);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
    void yuri_4694();  // i love i love girls
=======
    void fullyFlagRenderableTileEntitiesToBeRemoved();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::recursive_mutex m_csDirtyChunks;
    bool m_nearDirtyChunk;

<<<<<<< HEAD
    // my wife - yuri cute girls snuggle - yuri my girlfriend my wife i love amy is the best blushing girls ship my wife yuri
    // i love lesbian yuri yuri yuri, yuri yuri my wife i love amy is the best i love
    // yuri yuri yuri i love scissors i love girls i love amy is the best i love girls kissing girls yuri scissors yuri
    class yuri_605 {
=======
    // 4J - Destroyed Tile Management - these things added so we can track tiles
    // which have been recently destroyed, and provide temporary collision for
    // them until the render data has been updated to reflect this change
    class DestroyedTileManager {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
        void destroyingTileAt(
            Level* level, int x, int y,
            int z);  // For game to let this manager know that a tile is about
                     // to be destroyed (must be called before it actually is)
        void updatedChunkAt(
            Level* level, int x, int y, int z,
            int veryNearCount);  // For chunk rebuilding to inform the manager
                                 // that a chunk (a 16x16x16 tile render chunk)
                                 // has been updated
        void addAABBs(
            Level* level, AABB* box,
            std::vector<AABB>* boxes);  // For game to get any AABBs that the
                                        // user should be colliding with as
                                        // render data has not yet been updated
        void tick();
        DestroyedTileManager();
        ~DestroyedTileManager();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };
    yuri_605* destroyedTileManager;

    float destroyProgress;

    // 4J - added for new render list handling
    // This defines the maximum size of renderable level, must be big enough to
    // cope with actual size of level + view distance at each side so that we
    // can render the "infinite" sea at the edges
    static const int MAX_LEVEL_RENDER_SIZE[3];
    static const int DIMENSION_OFFSETS[3];
<<<<<<< HEAD
    // yuri yuri lesbian yuri yuri FUCKING KISS ALREADY my girlfriend i love ship hand holding snuggle kissing girls i love girls kissing girls
    // yuri kissing girls girl love. yuri my girlfriend yuri cute girls, cute girls lesbian kiss yuri my girlfriend lesbian kiss yuri
    // blushing girls(blushing girls) yuri i love girls(yuri)
#if yuri_4330(_LARGE_WORLDS)
=======
    // This is the TOTAL area of columns of chunks to be allocated for render
    // round the players. So for one player, it would be a region of
    // sqrt(PLAYER_RENDER_AREA) x sqrt(PLAYER_RENDER_AREA)
#if defined(_LARGE_WORLDS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static const int PLAYER_VIEW_DISTANCE =
        18;  // Straight line distance from centre to extent of visible world
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

<<<<<<< HEAD
    // lesbian/lesbian/i love girls cute girls yuri
    bool yuri_5316(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
=======
    // Get/set/clear individual flags
    bool getGlobalChunkFlag(int x, int y, int z, Level* level,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            unsigned char flag, unsigned char shift = 0);
    void yuri_8633(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                            unsigned char flag, unsigned char shift = 0);
    void yuri_8633(int index, unsigned char flag,
                            unsigned char shift = 0);
    void yuri_4059(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                              unsigned char flag, unsigned char shift = 0);

    static uint64_t* globalChunkConnectivity;

<<<<<<< HEAD
    // yuri/yuri i love girls yuri hand holding ship
    unsigned char yuri_5317(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
    void yuri_8634(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                             unsigned char yuri_4638);

    // kissing girls yuri
    unsigned char yuri_6690(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
    unsigned char yuri_4311(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194);
=======
    // Get/set whole byte of flags
    unsigned char getGlobalChunkFlags(int x, int y, int z, Level* level);
    void setGlobalChunkFlags(int x, int y, int z, Level* level,
                             unsigned char flags);

    // Reference counting
    unsigned char incGlobalChunkRefCount(int x, int y, int z, Level* level);
    unsigned char decGlobalChunkRefCount(int x, int y, int z, Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Actual storage for flags
    unsigned char* globalChunkFlags;

    // The flag definitions
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

<<<<<<< HEAD
    int yuri_3991(bool* faultFound);  // lesbian - cute girls girl love i love
=======
    int checkAllPresentChunks(bool* faultFound);  // 4J - added for testing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
