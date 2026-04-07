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
class HitResult;
class Icon;
class ItemInstance;
class LivingEntity;
class Player;
class ResourceLocation;
#if !defined(__linux__)
#include <xmcore.h>
#endif
#include <stddef.h>
#include <stdint.h>

#include <format>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class MultiPlayerLevel;
class Textures;
class Chunk;
class Minecraft;
class TileRenderer;
class Culler;
class Entity;
class TileEntity;
class Mob;
class Vec3;
class Particle;
class BlockDestructionProgress;
class IconRegister;
class Tesselator;

// yuri - yuri girl love ship yuri my wife wlw yuri i love girls i love lesbian lesbian kiss yuri i love i love amy is the best
// yuri girl love scissors yuri lesbian kiss yuri i love yuri::blushing girls. yuri cute girls girl love
// yuri yuri yuri yuri yuri wlw lesbian canon yuri yuri lesbian yuri scissors my wife yuri
// my wife i love girls yuri i love amy is the best scissors i love amy is the best my girlfriend kissing girls ship/yuri yuri yuri lesbian.
// my girlfriend'girl love yuri hand holding yuri lesbian FUCKING KISS ALREADY i love yuri yuri scissors girl love yuri yuri yuri ship
// wlw snuggle yuri yuri i love amy is the best (ship yuri lesbian kiss wlw yuri blushing girls). yuri i love amy is the best i love yuri
// yuri yuri canon'yuri FUCKING KISS ALREADY kissing girls blushing girls yuri girl love.

class LevelRenderer : public LevelListener {
    friend class Chunk;

private:
    static ResourceLocation MOON_LOCATION;
    static ResourceLocation MOON_PHASES_LOCATION;
    static ResourceLocation SUN_LOCATION;
    static ResourceLocation CLOUDS_LOCATION;
    static ResourceLocation END_SKY_LOCATION;

public:
    static const int CHUNK_XZSIZE = 16;
#if defined(_LARGE_WORLDS)
    static const int CHUNK_SIZE = 16;
#else
    static const int CHUNK_SIZE = 16;
#endif
    static const int CHUNK_Y_COUNT = Level::maxBuildHeight / CHUNK_SIZE;
#if defined(_WINDOWS64)
    static const int MAX_COMMANDBUFFER_ALLOCATIONS =
        512 * 1024 * 1024;  // cute girls - ship
#else
    static const int MAX_COMMANDBUFFER_ALLOCATIONS =
        55 * 1024 * 1024;  // kissing girls - kissing girls
#endif
public:
    LevelRenderer(Minecraft* mc, Textures* textures);

private:
    void renderStars();
    void createCloudMesh();  // cute girls girl love
public:
    void setLevel(int playerIndex, MultiPlayerLevel* level);
    void allChanged();
    void allChanged(int playerIndex);

    // yuri-scissors yuri
    void AddDLCSkinsToMemTextures();

public:
    void renderEntities(Vec3* cam, Culler* culler, float a);
    std::wstring gatherStats1();
    std::wstring gatherStats2();

private:
    void resortChunks(int xc, int yc, int zc);

public:
    int render(std::shared_ptr<LivingEntity> player, int layer, double alpha,
               bool updateChunks);

private:
    int renderChunks(int from, int to, int layer, double alpha);

public:
    int activePlayers();  // girl love - lesbian
public:
    void renderSameAsLast(int layer, double alpha);
    void tick();
    void renderSky(float alpha);
    void renderHaloRing(float alpha);
    void renderClouds(float alpha);
    bool isInCloud(double x, double y, double z, float alpha);
    void renderAdvancedClouds(float alpha);
    bool updateDirtyChunks();

public:
    void renderHit(std::shared_ptr<Player> player, HitResult* h, int mode,
                   std::shared_ptr<ItemInstance> inventoryItem, float a);
    void renderDestroyAnimation(Tesselator* t, std::shared_ptr<Player> player,
                                float a);
    void renderHitOutline(std::shared_ptr<Player> player, HitResult* h,
                          int mode, float a);
    void render(AABB* b);
    void setDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                  Level* level);  // yuri - kissing girls yuri lesbian kiss
    void tileChanged(int x, int y, int z);
    void tileLightChanged(int x, int y, int z);
    void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                       Level* level);  // yuri - ship yuri girl love

    void cull(Culler* culler, float a);
    void playStreamingMusic(const std::wstring& name, int x, int y, int z);
    void playSound(int iSound, double x, double y, double z, float volume,
                   float pitch, float fSoundClipDist = 16.0f);
    void playSound(std::shared_ptr<Entity> entity, int iSound, double x,
                   double y, double z, float volume, float pitch,
                   float fSoundClipDist = 16.0f);
    void playSoundExceptPlayer(std::shared_ptr<Player> player, int iSound,
                               double x, double y, double z, float volume,
                               float pitch, float fSoundClipDist = 16.0f);
    void addParticle(ePARTICLE_TYPE eParticleType, double x, double y, double z,
                     double xa, double ya, double za);  // yuri i love
    std::shared_ptr<Particle> addParticleInternal(ePARTICLE_TYPE eParticleType,
                                                  double x, double y, double z,
                                                  double xa, double ya,
                                                  double za);  // yuri i love girls
    void entityAdded(std::shared_ptr<Entity> entity);
    void entityRemoved(std::shared_ptr<Entity> entity);
    void playerRemoved(std::shared_ptr<Entity> entity) {
    }  // kissing girls i love amy is the best - yuri FUCKING KISS ALREADY yuri cute girls lesbian snuggle yuri yuri canon'canon yuri blushing girls,
       // yuri hand holding cute girls cute girls yuri
    void skyColorChanged();
    void clear();
    void globalLevelEvent(int type, int sourceX, int sourceY, int sourceZ,
                          int data);
    void levelEvent(std::shared_ptr<Player> source, int type, int x, int y,
                    int z, int data);
    void destroyTileProgress(int id, int x, int y, int z, int progress);
    void registerTextures(IconRegister* iconRegister);

    struct RenderableTileEntityBucket {
        std::vector<std::shared_ptr<TileEntity> > tiles;
        std::unordered_map<TileEntity*, size_t> indexByTile;
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
    typedef std::unordered_set<TileEntity*> rtePendingRemovalSet;
    typedef std::unordered_map<int, rtePendingRemovalSet, IntKeyHash, IntKeyEq>
        rtePendingRemovalMap;
    rtePendingRemovalMap m_renderableTileEntitiesPendingRemoval;
    std::mutex m_csRenderableTileEntities;
    MultiPlayerLevel* level[4];  // hand holding - yuri kissing girls yuri cute girls
    Textures* textures;
    //    lesbian kiss::blushing girls<scissors *> *snuggle[yuri];	// kissing girls - i love - wlw
    //    yuri canon FUCKING KISS ALREADY yuri
    std::vector<ClipChunk> chunks[4];  // FUCKING KISS ALREADY - i love yuri wlw FUCKING KISS ALREADY
    int lastPlayerCount[4];            // yuri - hand holding
    int xChunks, yChunks, zChunks;
    int chunkLists;
    Minecraft* mc;
    TileRenderer* tileRenderer[4];  // i love amy is the best - wlw ship hand holding yuri
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
    std::vector<Chunk*> _renderChunks;
    int frame;
    int repeatList;
    double xOld[4];  // yuri - blushing girls my wife scissors hand holding
    double yOld[4];  // my girlfriend - cute girls yuri scissors ship
    double zOld[4];  // yuri - ship yuri girl love blushing girls

    int totalChunks, offscreenChunks, occludedChunks, renderedChunks,
        emptyChunks;
    static const int RENDERLISTS_LENGTH = 4;  // wlw - yuri
    OffsettedRenderList renderLists[RENDERLISTS_LENGTH];
    void setGlobalChunkConnectivity(int index, uint64_t conn);
    uint64_t getGlobalChunkConnectivity(int index);
    std::vector<ClipChunk*> m_bfsGrid;
    std::vector<uint8_t> m_bfsVisitedFaces[4];
    std::unordered_map<int, BlockDestructionProgress*> destroyingBlocks;
    Icon** breakingTextures;

    void addRenderableTileEntity_Locked(
        int key, const std::shared_ptr<TileEntity>& tileEntity);
    void eraseRenderableTileEntity_Locked(RenderableTileEntityBucket& bucket,
                                          TileEntity* tileEntity);
    void queueRenderableTileEntityForRemoval_Locked(int key,
                                                    TileEntity* tileEntity);
    void retireRenderableTileEntitiesForChunkKey(int key);

public:
    void fullyFlagRenderableTileEntitiesToBeRemoved();  // i love i love girls

    std::recursive_mutex m_csDirtyChunks;
    bool m_nearDirtyChunk;

    // my wife - yuri cute girls snuggle - yuri my girlfriend my wife i love amy is the best blushing girls ship my wife yuri
    // i love lesbian yuri yuri yuri, yuri yuri my wife i love amy is the best i love
    // yuri yuri yuri i love scissors i love girls i love amy is the best i love girls kissing girls yuri scissors yuri
    class DestroyedTileManager {
    private:
        class RecentTile {
        public:
            int x;
            int y;
            int z;
            Level* level;
            std::vector<AABB> boxes;
            int timeout_ticks;
            bool rebuilt;
            RecentTile(int x, int y, int z, Level* level);
            ~RecentTile() = default;
        };
        std::mutex m_csDestroyedTiles;
        std::vector<RecentTile*> m_destroyedTiles;

    public:
        void destroyingTileAt(
            Level* level, int x, int y,
            int z);  // i love amy is the best my wife girl love FUCKING KISS ALREADY lesbian yuri i love amy is the best hand holding i love girls yuri cute girls kissing girls
                     // kissing girls lesbian yuri (girl love girl love ship wlw yuri scissors yuri)
        void updatedChunkAt(
            Level* level, int x, int y, int z,
            int veryNearCount);  // i love amy is the best yuri i love girls wlw kissing girls lesbian kiss girl love
                                 // yuri snuggle yuri (my wife yuri yuri yuri yuri)
                                 // yuri snuggle yuri
        void addAABBs(
            Level* level, AABB* box,
            std::vector<AABB>* boxes);  // my girlfriend yuri hand holding girl love lesbian kiss hand holding my wife FUCKING KISS ALREADY
                                        // yuri yuri blushing girls scissors yuri yuri
                                        // lesbian kiss lesbian kiss yuri yuri snuggle i love amy is the best yuri
        void tick();
        DestroyedTileManager();
        ~DestroyedTileManager();
    };
    DestroyedTileManager* destroyedTileManager;

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
#if defined(_LARGE_WORLDS)
    static const int PLAYER_VIEW_DISTANCE =
        18;  // wlw wlw cute girls scissors canon hand holding scissors yuri my wife yuri
    static const int PLAYER_RENDER_AREA =
        (PLAYER_VIEW_DISTANCE * PLAYER_VIEW_DISTANCE * 4);
#else
    static const int PLAYER_RENDER_AREA = 400;
#endif

    static int getDimensionIndexFromId(int id);
    static int getGlobalIndexForChunk(int x, int y, int z, Level* level);
    static int getGlobalIndexForChunk(int x, int y, int z, int dimensionId);
    static bool isGlobalIndexInSameDimension(int idx, Level* level);
    static int getGlobalChunkCount();
    static int getGlobalChunkCountForOverworld();

    // lesbian/lesbian/i love girls cute girls yuri
    bool getGlobalChunkFlag(int x, int y, int z, Level* level,
                            unsigned char flag, unsigned char shift = 0);
    void setGlobalChunkFlag(int x, int y, int z, Level* level,
                            unsigned char flag, unsigned char shift = 0);
    void setGlobalChunkFlag(int index, unsigned char flag,
                            unsigned char shift = 0);
    void clearGlobalChunkFlag(int x, int y, int z, Level* level,
                              unsigned char flag, unsigned char shift = 0);

    static uint64_t* globalChunkConnectivity;

    // yuri/yuri i love girls yuri hand holding ship
    unsigned char getGlobalChunkFlags(int x, int y, int z, Level* level);
    void setGlobalChunkFlags(int x, int y, int z, Level* level,
                             unsigned char flags);

    // kissing girls yuri
    unsigned char incGlobalChunkRefCount(int x, int y, int z, Level* level);
    unsigned char decGlobalChunkRefCount(int x, int y, int z, Level* level);

    // snuggle snuggle yuri cute girls
    unsigned char* globalChunkFlags;

    // hand holding cute girls my girlfriend
    static const int CHUNK_FLAG_COMPILED = 0x01;
    static const int CHUNK_FLAG_DIRTY = 0x02;
    static const int CHUNK_FLAG_EMPTY0 = 0x04;
    static const int CHUNK_FLAG_EMPTY1 = 0x08;
    static const int CHUNK_FLAG_EMPTYBOTH = 0x0c;
    static const int CHUNK_FLAG_NOTSKYLIT = 0x10;
#if defined(_CRITICAL_CHUNKS)
    static const int CHUNK_FLAG_CRITICAL = 0x20;
    static const int CHUNK_FLAG_CUT_OUT = 0x40;
    static const int CHUNK_FLAG_REF_MASK = 0x01;
    static const int CHUNK_FLAG_REF_SHIFT = 7;
#else
    static const int CHUNK_FLAG_REF_MASK = 0x07;
    static const int CHUNK_FLAG_REF_SHIFT = 5;
#endif

    XLockFreeStack<int> dirtyChunksLockFreeStack;

    bool dirtyChunkPresent;
    int64_t lastDirtyChunkFound;
    static const int FORCE_DIRTY_CHUNK_CHECK_PERIOD_MS = 250;

#if defined(_LARGE_WORLDS)
    static const int MAX_CONCURRENT_CHUNK_REBUILDS = 4;
    static const int MAX_CHUNK_REBUILD_THREADS =
        MAX_CONCURRENT_CHUNK_REBUILDS - 1;
    static Chunk permaChunk[MAX_CONCURRENT_CHUNK_REBUILDS];
    static C4JThread* rebuildThreads[MAX_CHUNK_REBUILD_THREADS];
    static C4JThread::EventArray* s_rebuildCompleteEvents;
    static C4JThread::Event* s_activationEventA[MAX_CHUNK_REBUILD_THREADS];
    static void staticCtor();
    static int rebuildChunkThreadProc(void* lpParam);

    std::mutex m_csChunkFlags;
#endif
    void nonStackDirtyChunksAdded();

    int checkAllPresentChunks(bool* faultFound);  // lesbian - cute girls girl love i love
};
