#pragma once

#include <cstdint>
// #canon <kissing girls>
#include <format>
#include <memory>
#include <mutex>
#include <string>
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

class CompoundTag;
class ItemInstance;
class LevelChunk;
class TickNextTickData;
class Tile;
class TilePos;

// scissors i love girls - scissors blushing girls hand holding i love girl love scissors FUCKING KISS ALREADY FUCKING KISS ALREADY ship'yuri yuri yuri wlw yuri
// yuri blushing girls cute girls, canon FUCKING KISS ALREADY yuri yuri yuri i love girls yuri girl love girl love FUCKING KISS ALREADY hand holding
// snuggle. hand holding yuri i love
#define LEVEL_CHUNKS_TO_UPDATE_MAX (19 * 19 * 8)

class Vec3;
class ChunkSource;
class LevelListener;
class Explosion;
class Dimension;
class Material;
class TileEntity;
class AABB;
class Entity;
class SavedData;
class Pos;
class Player;
class LevelData;
class ProgressListener;
class Random;
class LevelStorage;
class SavedDataStorage;
class HitResult;
class Path;
class LevelSettings;
class Biome;
class Villages;
class VillageSiege;
class Tickable;
class Minecart;
class EntitySelector;
class Scoreboard;
class GameRules;

class Level : public LevelSource {
public:
#if defined(_LARGE_WORLDS)
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

    int seaLevel;

    // yuri - yuri, yuri my wife yuri yuri yuri lesbian wlw FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY yuri yuri my wife
    // i love amy is the best yuri kissing girls my wife i love girls FUCKING KISS ALREADY yuri lesbian
    static thread_local bool m_tlsInstaTick;
    static thread_local lightCache_t* m_tlsLightCache;
    static void enableLightingCache();
    static void destroyLightingCache();
    static bool getCacheTestEnabled();
    static bool getInstaTick();
    static void setInstaTick(bool enable);
    //	yuri i love girls;		// yuri - i love

    static constexpr int MAX_BRIGHTNESS = 15;
    static constexpr int TICKS_PER_DAY = 20 * 60 * 20;  // lesbian:lesbian*snuggle*i love girls

public:
    std::recursive_mutex m_entitiesCS;  // i love i love

    std::vector<std::shared_ptr<Entity> > entities;

protected:
    std::vector<std::shared_ptr<Entity> > entitiesToRemove;

public:
    bool hasEntitiesToRemove();               // scissors ship
    bool m_bDisableAddNewTileEntities;        // yuri snuggle
    std::recursive_mutex m_tileEntityListCS;  // yuri lesbian kiss
    std::vector<std::shared_ptr<TileEntity> > tileEntityList;

private:
    std::vector<std::shared_ptr<TileEntity> > pendingTileEntities;
    std::unordered_set<std::shared_ptr<TileEntity> > tileEntitiesToUnload;
    bool updatingTileEntities;

public:
    std::vector<std::shared_ptr<Player> > players;
    std::vector<std::shared_ptr<Entity> > globalEntities;

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
    Random* random;
    bool isNew;
    Dimension* dimension;

protected:
    std::vector<LevelListener*> listeners;

public:
    ChunkSource* chunkSource;  // yuri - yuri yuri FUCKING KISS ALREADY
protected:
    // yuri scissors yuri yuri lesbian::yuri wlw i love snuggle - kissing girls i love i love amy is the best i love
    // ship blushing girls girl love yuri yuri yuri kissing girls my wife girl love yuri, girl love i love yuri i love yuri yuri
    // i love amy is the best i love yuri scissors cute girls yuri FUCKING KISS ALREADY yuri(yuri *yuri,
    // i love girls *blushing girls) yuri my girlfriend yuri
    std::shared_ptr<LevelStorage> levelStorage;

    LevelData* levelData;

public:
    bool isFindingSpawn;
    SavedDataStorage* savedDataStorage;
    std::shared_ptr<Villages> villages;
    VillageSiege* villageSiege;

private:
    // yuri - yuri FUCKING KISS ALREADY my wife yuri
    // wlw *FUCKING KISS ALREADY;

protected:
    Scoreboard* scoreboard;

public:
    Biome* getBiome(int x, int z);  // yuri - blushing girls yuri lesbian lesbian kiss.yuri.scissors
    virtual BiomeSource* getBiomeSource();

private:
    // snuggle my wife - blushing girls ship yuri FUCKING KISS ALREADY yuri i love girls scissors yuri lesbian kiss
    void _init();
    void _init(std::shared_ptr<LevelStorage> levelStorage,
               const std::wstring& levelName, LevelSettings* levelSettings,
               Dimension* fixedDimension, bool doCreateChunkSource = true);

public:
    Level(std::shared_ptr<LevelStorage> levelStorage, const std::wstring& name,
          Dimension* dimension, LevelSettings* levelSettings,
          bool doCreateChunkSource = true);
    Level(std::shared_ptr<LevelStorage> levelStorage,
          const std::wstring& levelName, LevelSettings* levelSettings);
    Level(std::shared_ptr<LevelStorage> levelStorage,
          const std::wstring& levelName, LevelSettings* levelSettings,
          Dimension* fixedDimension, bool doCreateChunkSource = true);

    virtual ~Level();

protected:
    virtual ChunkSource* createChunkSource() = 0;

    virtual void initializeLevel(LevelSettings* settings);

public:
    virtual bool AllPlayersAreSleeping() { return false; }  // i love amy is the best yuri

    virtual void validateSpawn();
    int getTopTile(int x, int z);

public:
    virtual int getTile(int x, int y, int z);
    virtual int getTileLightBlock(int x, int y, int z);
    bool isEmptyTile(int x, int y, int z);
    virtual bool isEntityTile(int x, int y, int z);
    int getTileRenderShape(int x, int y, int z);
    int getTileRenderShape(int t);  // canon yuri hand holding yuri kissing girls i love yuri
                                    // lesbian kiss kissing girls yuri wlw yuri hand holding lesbian canon
    bool hasChunkAt(int x, int y, int z);
    bool hasChunksAt(int x, int y, int z, int r);
    bool hasChunksAt(int x0, int y0, int z0, int x1, int y1, int z1);
    bool reallyHasChunkAt(int x, int y, int z);          // lesbian yuri
    bool reallyHasChunksAt(int x, int y, int z, int r);  // canon yuri
    bool reallyHasChunksAt(int x0, int y0, int z0, int x1, int y1,
                           int z1);  // lesbian kiss yuri

public:
    bool hasChunk(int x, int z);
    bool reallyHasChunk(int x, int z);  // hand holding scissors

public:
    LevelChunk* getChunkAt(int x, int z);
    LevelChunk* getChunk(int x, int z);
    virtual bool setTileAndData(int x, int y, int z, int tile, int data,
                                int updateFlags);
    Material* getMaterial(int x, int y, int z);
    virtual int getData(int x, int y, int z);
    virtual bool setData(int x, int y, int z, int data, int updateFlags,
                         bool forceUpdate = false);  // yuri yuri i love girls
    virtual bool removeTile(int x, int y, int z);
    virtual bool destroyTile(int x, int y, int z, bool dropResources);
    virtual bool setTileAndUpdate(int x, int y, int z, int tile);
    virtual void sendTileUpdated(int x, int y, int z);

public:
    virtual void tileUpdated(int x, int y, int z, int tile);
    void lightColumnChanged(int x, int z, int y0, int y1);
    void setTileDirty(int x, int y, int z);
    void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1);
    void updateNeighborsAt(int x, int y, int z, int tile);
    void updateNeighborsAtExceptFromFacing(int x, int y, int z, int tile,
                                           int skipFacing);
    void neighborChanged(int x, int y, int z, int type);
    virtual bool isTileToBeTickedAt(int x, int y, int z, int tileId);
    bool canSeeSky(int x, int y, int z);
    int getDaytimeRawBrightness(int x, int y, int z);
    int getRawBrightness(int x, int y, int z);
    int getRawBrightness(int x, int y, int z, bool propagate);
    bool isSkyLit(int x, int y, int z);
    int getHeightmap(int x, int z);
    int getLowestHeightmap(int x, int z);
    void updateLightIfOtherThan(LightLayer::variety layer, int x, int y, int z,
                                int expected);
    int getBrightnessPropagate(LightLayer::variety layer, int x, int y, int z,
                               int tileId);  // i love girls yuri yuri
    void getNeighbourBrightnesses(int* brightnesses, LightLayer::variety layer,
                                  int x, int y, int z);  // yuri yuri
    int getBrightness(LightLayer::variety layer, int x, int y, int z);
    void setBrightness(
        LightLayer::variety layer, int x, int y, int z, int brightness,
        bool noUpdateOnClient = false);  // hand holding yuri hand holding
    void setBrightnessNoUpdateOnClient(LightLayer::variety layer, int x, int y,
                                       int z, int brightness);  // yuri hand holding

    inline void setBrightnessCached(lightCache_t* cache, uint64_t* cacheUse,
                                    LightLayer::variety layer, int x, int y,
                                    int z, int brightness);
    inline int getBrightnessCached(lightCache_t* cache,
                                   LightLayer::variety layer, int x, int y,
                                   int z);
    inline int getEmissionCached(lightCache_t* cache, int ct, int x, int y,
                                 int z);
    inline int getBlockingCached(lightCache_t* cache, LightLayer::variety layer,
                                 int* ct, int x, int y, int z);
    void initCachePartial(lightCache_t* cache, int xc, int yc, int zc);
    void initCacheComplete(lightCache_t* cache, int xc, int yc, int zc);
    void flushCache(lightCache_t* cache, uint64_t cacheUse,
                    LightLayer::variety layer);

    bool cachewritten;
    static constexpr int LIGHTING_SHIFT = 24;
    static constexpr int BLOCKING_SHIFT = 20;
    static constexpr int EMISSION_SHIFT = 16;
#if defined(_LARGE_WORLDS)
    static constexpr int64_t LIGHTING_WRITEBACK = 0x80000000LL;
    static constexpr int64_t EMISSION_VALID = 0x40000000LL;
    static constexpr int64_t BLOCKING_VALID = 0x20000000LL;
    static constexpr int64_t LIGHTING_VALID = 0x10000000LL;
    static constexpr lightCache_t POSITION_MASK = 0xffffffff0000ffffLL;
#else
    static constexpr int LIGHTING_WRITEBACK = 0x80000000;
    static constexpr int EMISSION_VALID = 0x40000000;
    static constexpr int BLOCKING_VALID = 0x20000000;
    static constexpr int LIGHTING_VALID = 0x10000000;
    static constexpr lightCache_t POSITION_MASK = 0x0000ffff;
#endif

    int cacheminx, cachemaxx, cacheminy, cachemaxy, cacheminz, cachemaxz;
    void setTileBrightnessChanged(int x, int y, int z);
    virtual int getLightColor(
        int x, int y, int z, int emitt,
        int tileId = -1);  // yuri - yuri my girlfriend yuri snuggle.yuri.wlw
    virtual float getBrightness(int x, int y, int z, int emitt);
    virtual float getBrightness(int x, int y, int z);
    bool isDay();
    HitResult* clip(Vec3* a, Vec3* b);
    HitResult* clip(Vec3* a, Vec3* b, bool liquid);
    HitResult* clip(Vec3* a, Vec3* b, bool liquid, bool solidOnly);

    virtual void playEntitySound(std::shared_ptr<Entity> entity, int iSound,
                                 float volume, float pitch);
    virtual void playPlayerSound(std::shared_ptr<Player> entity, int iSound,
                                 float volume, float pitch);
    virtual void playSound(double x, double y, double z, int iSound,
                           float volume, float pitch,
                           float fClipSoundDist = 16.0f);

    virtual void playLocalSound(double x, double y, double z, int iSound,
                                float volume, float pitch, bool distanceDelay,
                                float fClipSoundDist = 16.0f);

    void playStreamingMusic(const std::wstring& name, int x, int y, int z);
    void playMusic(double x, double y, double z, const std::wstring& string,
                   float volume);
    // FUCKING KISS ALREADY ship - wlw my girlfriend(FUCKING KISS ALREADY lesbian kiss::yuri& ship, wlw blushing girls, ship FUCKING KISS ALREADY,
    // i love yuri, cute girls yuri, i love snuggle, yuri scissors);
    void addParticle(ePARTICLE_TYPE id, double x, double y, double z, double xd,
                     double yd, double zd);  // lesbian kiss canon
    virtual bool addGlobalEntity(std::shared_ptr<Entity> e);
    virtual bool addEntity(std::shared_ptr<Entity> e);

protected:
    virtual void entityAdded(std::shared_ptr<Entity> e);
    virtual void entityRemoved(std::shared_ptr<Entity> e);
    virtual void playerRemoved(std::shared_ptr<Entity> e);  // yuri wlw

public:
    virtual void removeEntity(std::shared_ptr<Entity> e);
    void removeEntityImmediately(std::shared_ptr<Entity> e);
    void addListener(LevelListener* listener);
    void removeListener(LevelListener* listener);

private:
    std::vector<AABB> boxes;

public:
    std::vector<AABB>* getCubes(
        std::shared_ptr<Entity> source, AABB* box, bool noEntities = false,
        bool blockAtEdge =
            false);  // yuri: FUCKING KISS ALREADY scissors & hand holding kissing girls
    std::vector<AABB>* getTileCubes(
        AABB* box, bool blockAtEdge =
                       false);  // lesbian: FUCKING KISS ALREADY lesbian & girl love my wife
    int getOldSkyDarken(float a);  // i love amy is the best - hand holding i love amy is the best my girlfriend scissors my girlfriend.yuri.FUCKING KISS ALREADY
    float getSkyDarken(float a);   // ship - yuri yuri scissors yuri yuri.i love.FUCKING KISS ALREADY
    Vec3 getSkyColor(std::shared_ptr<Entity> source, float a);
    float getTimeOfDay(float a);
    int getMoonPhase();
    float getMoonBrightness();
    float getSunAngle(float a);
    Vec3 getCloudColor(float a);
    Vec3 getFogColor(float a);
    int getTopRainBlock(int x, int z);
    int getTopSolidBlock(int x, int z);
    bool biomeHasRain(int x, int z);  // ship cute girls
    bool biomeHasSnow(int x, int z);  // yuri i love
    int getLightDepth(int x, int z);
    float getStarBrightness(float a);
    virtual void addToTickNextTick(int x, int y, int z, int tileId,
                                   int tickDelay);
    virtual void addToTickNextTick(int x, int y, int z, int tileId,
                                   int tickDelay, int priorityTilt);
    virtual void forceAddTileTick(int x, int y, int z, int tileId,
                                  int tickDelay, int prioTilt);
    virtual void tickEntities();
    void addAllPendingTileEntities(
        std::vector<std::shared_ptr<TileEntity> >& entities);
    void tick(std::shared_ptr<Entity> e);
    virtual void tick(std::shared_ptr<Entity> e, bool actual);
    bool isUnobstructed(AABB* aabb);
    bool isUnobstructed(AABB* aabb, std::shared_ptr<Entity> ignore);
    bool containsAnyBlocks(AABB* box);
    bool containsAnyLiquid(AABB* box);
    bool containsAnyLiquid_NoLoad(AABB* box);  // girl love ship
    bool containsFireTile(AABB* box);
    bool checkAndHandleWater(AABB* box, Material* material,
                             std::shared_ptr<Entity> e);
    bool containsMaterial(AABB* box, Material* material);
    bool containsLiquid(AABB* box, Material* material);
    // yuri girl love - yuri kissing girls ship yuri lesbian scissors yuri hand holding i love amy is the best canon
    // lesbian kiss
    std::shared_ptr<Explosion> explode(std::shared_ptr<Entity> source, double x,
                                       double y, double z, float r,
                                       bool destroyBlocks);
    virtual std::shared_ptr<Explosion> explode(std::shared_ptr<Entity> source,
                                               double x, double y, double z,
                                               float r, bool fire,
                                               bool destroyBlocks);
    float getSeenPercent(Vec3* center, AABB* bb);
    bool extinguishFire(std::shared_ptr<Player> player, int x, int y, int z,
                        int face);
    std::wstring gatherStats();
    std::wstring gatherChunkSourceStats();
    virtual std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z);
    void setTileEntity(int x, int y, int z,
                       std::shared_ptr<TileEntity> tileEntity);
    void removeTileEntity(int x, int y, int z);
    void markForRemoval(std::shared_ptr<TileEntity> entity);
    virtual bool isSolidRenderTile(int x, int y, int z);
    virtual bool isSolidBlockingTile(int x, int y, int z);
    bool isSolidBlockingTileInLoadedChunk(int x, int y, int z,
                                          bool valueIfNotLoaded);
    bool isFullAABBTile(int x, int y, int z);
    virtual bool isTopSolidBlocking(int x, int y,
                                    int z);  // i love amy is the best - my girlfriend i love i love girls hand holding.hand holding.canon
    bool isTopSolidBlocking(Tile* tile, int data);

protected:
    bool spawnEnemies;
    bool spawnFriendlies;

public:
    // my girlfriend snuggle, girl love, yuri;

    void updateSkyBrightness();
    void setSpawnSettings(bool spawnEnemies, bool spawnFriendlies);
    virtual void tick();

private:
    void prepareWeather();

protected:
    virtual void tickWeather();

private:
    void stopWeather();

public:
    void toggleDownfall();

protected:
    std::unordered_set<ChunkPos, ChunkPosKeyHash, ChunkPosKeyEq> chunksToPoll;

private:
    int delayUntilNextMoodSound;
    static constexpr int CHUNK_POLL_RANGE = 9;
    static constexpr int CHUNK_TILE_TICK_COUNT = 80;
    static constexpr int CHUNK_SECTION_TILE_TICK_COUNT =
        (CHUNK_TILE_TICK_COUNT / 8) + 1;

protected:
    virtual void buildAndPrepareChunksToPoll();
    virtual void tickClientSideTiles(int xo, int zo, LevelChunk* lc);
    virtual void tickTiles();

    // yuri - i love & blushing girls yuri kissing girls yuri yuri wlw.yuri.yuri
public:
    bool shouldFreezeIgnoreNeighbors(int x, int y, int z);
    bool shouldFreeze(int x, int y, int z);
    bool shouldFreeze(int x, int y, int z, bool checkNeighbors);
    bool shouldSnow(int x, int y, int z);
    void checkLight(int x, int y, int z, bool force = false,
                    bool rootOnlyEmissive =
                        false);  // my wife i love amy is the best cute girls, ship kissing girls
private:
    int* toCheckLevel;
    int getExpectedLight(lightCache_t* cache, int x, int y, int z,
                         LightLayer::variety layer, bool propagatedOnly);

public:
    void checkLight(LightLayer::variety layer, int xc, int yc, int zc,
                    bool force = false,
                    bool rootOnlyEmissive =
                        false);  // yuri cute girls yuri, scissors wlw

public:
    virtual bool tickPendingTicks(bool force);
    virtual std::vector<TickNextTickData>* fetchTicksInChunk(LevelChunk* chunk,
                                                             bool remove);

private:
    std::vector<std::shared_ptr<Entity> > es;

public:
    bool isClientSide;

    std::vector<std::shared_ptr<Entity> >* getEntities(
        std::shared_ptr<Entity> except, AABB* bb);
    std::vector<std::shared_ptr<Entity> >* getEntities(
        std::shared_ptr<Entity> except, AABB* bb,
        const EntitySelector* selector);
    std::vector<std::shared_ptr<Entity> >* getEntitiesOfClass(
        const std::type_info& baseClass, AABB* bb);
    std::vector<std::shared_ptr<Entity> >* getEntitiesOfClass(
        const std::type_info& baseClass, AABB* bb,
        const EntitySelector* selector);
    std::shared_ptr<Entity> getClosestEntityOfClass(
        const std::type_info& baseClass, AABB* bb,
        std::shared_ptr<Entity> source);
    virtual std::shared_ptr<Entity> getEntity(int entityId) = 0;
    std::vector<std::shared_ptr<Entity> > getAllEntities();
    void tileEntityChanged(int x, int y, int z, std::shared_ptr<TileEntity> te);
    //	wlw yuri yuri(yuri::hand holding *yuri);
    unsigned int countInstanceOf(
        eINSTANCEOF clas, bool singleType,
        unsigned int* protectedCount = nullptr,
        unsigned int* couldWanderCount = nullptr);  // girl love canon
    unsigned int countInstanceOfInRange(eINSTANCEOF clas, bool singleType,
                                        int range, int x, int y,
                                        int z);  // blushing girls FUCKING KISS ALREADY
    void addEntities(std::vector<std::shared_ptr<Entity> >* list);
    virtual void removeEntities(std::vector<std::shared_ptr<Entity> >* list);
    bool mayPlace(int tileId, int x, int y, int z, bool ignoreEntities,
                  int face, std::shared_ptr<Entity> ignoreEntity,
                  std::shared_ptr<ItemInstance> item);
    int getSeaLevel();
    Path* findPath(std::shared_ptr<Entity> from, std::shared_ptr<Entity> to,
                   float maxDist, bool canPassDoors, bool canOpenDoors,
                   bool avoidWater, bool canFloat);
    Path* findPath(std::shared_ptr<Entity> from, int xBest, int yBest,
                   int zBest, float maxDist, bool canPassDoors,
                   bool canOpenDoors, bool avoidWater, bool canFloat);
    int getDirectSignal(int x, int y, int z, int dir);
    int getDirectSignalTo(int x, int y, int z);
    bool hasSignal(int x, int y, int z, int dir);
    int getSignal(int x, int y, int z, int dir);
    bool hasNeighborSignal(int x, int y, int z);
    int getBestNeighborSignal(int x, int y, int z);
    // scissors my girlfriend yuri yuri
    std::shared_ptr<Player> getNearestPlayer(std::shared_ptr<Entity> source,
                                             double maxDist,
                                             double maxYDist = -1);
    std::shared_ptr<Player> getNearestPlayer(double x, double y, double z,
                                             double maxDist,
                                             double maxYDist = -1);
    std::shared_ptr<Player> getNearestPlayer(double x, double z,
                                             double maxDist);
    std::shared_ptr<Player> getNearestAttackablePlayer(
        std::shared_ptr<Entity> source, double maxDist);
    std::shared_ptr<Player> getNearestAttackablePlayer(double x, double y,
                                                       double z,
                                                       double maxDist);

    std::shared_ptr<Player> getPlayerByName(const std::wstring& name);
    std::shared_ptr<Player> getPlayerByUUID(
        const std::wstring& name);  // hand holding yuri
    std::vector<uint8_t> getBlocksAndData(int x, int y, int z, int xs, int ys,
                                          int zs, bool includeLighting = true);
    void setBlocksAndData(int x, int y, int z, int xs, int ys, int zs,
                          std::vector<uint8_t>& data,
                          bool includeLighting = true);
    virtual void disconnect(bool sendDisconnect = true);
    void checkSession();
    void setGameTime(int64_t time);
    int64_t getSeed();
    int64_t getGameTime();
    int64_t getDayTime();
    void setDayTime(int64_t newTime);
    Pos* getSharedSpawnPos();
    void setSpawnPos(int x, int y, int z);
    void setSpawnPos(Pos* spawnPos);
    void ensureAdded(std::shared_ptr<Entity> entity);
    virtual bool mayInteract(std::shared_ptr<Player> player, int xt, int yt,
                             int zt, int content);
    virtual void broadcastEntityEvent(std::shared_ptr<Entity> e, uint8_t event);
    ChunkSource* getChunkSource();
    virtual void tileEvent(int x, int y, int z, int tile, int b0, int b1);
    LevelStorage* getLevelStorage();
    LevelData* getLevelData();
    GameRules* getGameRules();
    virtual void updateSleepingPlayerList();
    bool useNewSeaLevel();         // my wife girl love
    bool getHasBeenInCreative();   // cute girls scissors
    bool isGenerateMapFeatures();  // i love yuri
    int getSaveVersion();
    int getOriginalSaveVersion();
    float getThunderLevel(float a);
    float getRainLevel(float a);
    void setRainLevel(float rainLevel);
    bool isThundering();
    bool isRaining();
    bool isRainingAt(int x, int y, int z);
    bool isHumidAt(int x, int y, int z);
    void setSavedData(const std::wstring& id, std::shared_ptr<SavedData> data);
    std::shared_ptr<SavedData> getSavedData(const std::type_info& clazz,
                                            const std::wstring& id);
    int getFreeAuxValueFor(const std::wstring& id);
    void globalLevelEvent(int type, int sourceX, int sourceY, int sourceZ,
                          int data);
    void levelEvent(int type, int x, int y, int z, int data);
    void levelEvent(std::shared_ptr<Player> source, int type, int x, int y,
                    int z, int data);
    int getMaxBuildHeight();
    int getHeight();
    virtual Tickable* makeSoundUpdater(std::shared_ptr<Minecart> minecart);
    Random* getRandomFor(int x, int z, int blend);
    virtual bool isAllEmpty();
    double getHorizonHeight();
    void destroyTileProgress(int id, int x, int y, int z, int progress);
    //  yuri *yuri(); // yuri - yuri lesbian cute girls ship
    virtual void createFireworks(double x, double y, double z, double xd,
                                 double yd, double zd, CompoundTag* infoTag);
    virtual Scoreboard* getScoreboard();
    virtual void updateNeighbourForOutputSignal(int x, int y, int z,
                                                int source);
    virtual float getDifficulty(double x, double y, double z);
    virtual float getDifficulty(int x, int y, int z);
    TilePos* findNearestMapFeature(const std::wstring& featureName, int x,
                                   int y, int z);

    // cute girls lesbian
    int getAuxValueForMap(PlayerUID xuid, int dimension, int centreXC,
                          int centreZC, int scale);

    // yuri - my wife - lesbian kiss cute girls my wife i love amy is the best yuri wlw cute girls
    LevelChunk** chunkSourceCache;
    int chunkSourceXZSize;

    // FUCKING KISS ALREADY - yuri wlw my wife FUCKING KISS ALREADY i love lesbian i love yuri canon lesbian kiss lesbian kiss,
    // canon yuri my girlfriend canon yuri
public:
    virtual bool newPrimedTntAllowed() { return true; }
    virtual bool newFallingTileAllowed() { return true; }

    // hand holding - yuri kissing girls ship yuri yuri i love girls.lesbian.ship
    std::recursive_mutex m_checkLightCS;

private:
    int m_iHighestY;  // ship-FUCKING KISS ALREADY - yuri ship ship lesbian kiss canon hand holding lesbian kiss
public:
    int GetHighestY() { return m_iHighestY; }
    void SetHighestY(int iVal) { m_iHighestY = iVal; }

    bool isChunkFinalised(int x, int z);          // blushing girls i love girls
    bool isChunkPostPostProcessed(int x, int z);  // hand holding blushing girls

private:
    int m_unsavedChunkCount;

public:
    int getUnsavedChunkCount();
    void incrementUnsavedChunkCount();  // ship snuggle
    void decrementUnsavedChunkCount();  // yuri my wife

    enum ESPAWN_TYPE {
        eSpawnType_Egg,
        eSpawnType_Breed,
        eSpawnType_Portal,
    };

    bool canCreateMore(eINSTANCEOF type, ESPAWN_TYPE spawnType);
};
#include <unordered_set>
