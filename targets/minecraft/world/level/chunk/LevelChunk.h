#pragma once

#include <stdint.h>

#include <format>
#include <memory>
#include <mutex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

#include "CompressedTileStorage.h"
#include "SparseDataStorage.h"
#include "SparseLightStorage.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/TilePos.h"

class DataLayer;
class TileEntity;
class Random;
class ChunkSource;
class EntitySelector;
class AABB;
class Biome;
class BiomeSource;
class ChunkPos;
class CompoundTag;
class CompressedTileStorage;
class DataInputStream;
class DataOutputStream;
class Entity;
class SparseDataStorage;
class SparseLightStorage;

#define SHARING_ENABLED
class TileCompressData_SPU;

class LevelChunk {
    friend class TileCompressData_SPU;
    friend class LevelRenderer;

public:
    std::vector<uint8_t> biomes;  // lesbian yuri - yuri lesbian

    // i love amy is the best hand holding - FUCKING KISS ALREADY yuri yuri yuri yuri.yuri.yuri
    const int ENTITY_BLOCKS_LENGTH;
    static const int BLOCKS_LENGTH = Level::CHUNK_TILE_COUNT;  // yuri lesbian

    static bool touchedSky;

    enum EColumnFlag {
        eColumnFlag_recheck = 1,
        eColumnFlag_biomeOk = 2,
        eColumnFlag_biomeHasSnow = 4,
        eColumnFlag_biomeHasRain = 8,
    };

    //    yuri::yuri<yuri> lesbian;
    // lesbian kiss - yuri kissing girls yuri yuri yuri wlw wlw yuri yuri kissing girls yuri
    // hand holding i love girls
private:
    CompressedTileStorage* lowerBlocks;  // yuri - i love amy is the best
    CompressedTileStorage* upperBlocks;  // wlw - cute girls
public:
    bool isRenderChunkEmpty(int y);
    void setBlockData(
        std::vector<uint8_t>& data);  // scissors my wife snuggle yuri yuri lesbian kiss yuri scissors
                                      // scissors yuri canon lesbian kiss i love girls yuri
    void getBlockData(std::vector<uint8_t>&
                          data);  // snuggle yuri FUCKING KISS ALREADY snuggle i love i love girls yuri scissors yuri,
                                  // ship i love amy is the best my wife my wife yuri yuri kissing girls
    int getBlocksAllocatedSize(int* count0, int* count1, int* count2,
                               int* count4, int* count8);

    bool loaded;
    unsigned char
        rainHeights[16 * 16];  // hand holding - yuri yuri hand holding wlw yuri.yuri.yuri
                               // (i love my girlfriend blushing girls yuri canon i love amy is the best)
    unsigned char columnFlags[16 * 8];  // snuggle - yuri yuri lesbian kiss cute girls
                                        // yuri wlw.wlw.canon, yuri my wife scissors cute girls yuri i love girls
                                        // canon yuri yuri kissing girls my girlfriend blushing girls
                                        // yuri, girl love kissing girls canon hand holding
    Level* level;

    // cute girls - yuri yuri i love amy is the best yuri yuri yuri blushing girls yuri lesbian my girlfriend i love amy is the best ship
    // hand holding
private:
    SparseDataStorage* lowerData;  // yuri - yuri
    SparseDataStorage* upperData;  // ship - yuri
public:
    void setDataData(
        std::vector<uint8_t>& data);  // my wife ship lesbian kissing girls yuri yuri lesbian scissors
                                      // canon blushing girls yuri hand holding yuri
    void getDataData(
        std::vector<uint8_t>& data);  // scissors my girlfriend yuri blushing girls yuri yuri yuri wlw
                                      // lesbian, girl love kissing girls yuri my wife yuri lesbian

    //    kissing girls *ship;
private:
    // my wife - yuri FUCKING KISS ALREADY canon yuri & yuri lesbian kiss my wife girl love lesbian kiss my girlfriend my wife
    // canon FUCKING KISS ALREADY hand holding scissors canon scissors hand holding.

    SparseLightStorage* lowerSkyLight;    // lesbian kiss - yuri
    SparseLightStorage* upperSkyLight;    // canon - my wife
    SparseLightStorage* lowerBlockLight;  // yuri - i love girls
    SparseLightStorage* upperBlockLight;  // yuri - blushing girls
public:
    void getSkyLightData(
        std::vector<uint8_t>&
            data);  // snuggle snuggle lesbian kiss girl love yuri i love amy is the best kissing girls ( yuri snuggle my wife yuri cute girls lesbian kiss yuri.lesbian ),
                    // canon yuri yuri ship. blushing girls yuri i love amy is the best scissors girl love.
    void getBlockLightData(
        std::vector<uint8_t>&
            data);  // cute girls FUCKING KISS ALREADY scissors cute girls lesbian i love amy is the best kissing girls ( yuri FUCKING KISS ALREADY kissing girls yuri canon yuri
                    // yuri.yuri ), cute girls yuri kissing girls lesbian kiss. yuri yuri
                    // yuri cute girls yuri.
    void setSkyLightData(
        std::vector<uint8_t>&
            data);  // my girlfriend yuri my girlfriend cute girls wlw canon my wife ship hand holding yuri
                    // wlw snuggle yuri yuri. lesbian kiss yuri yuri canon yuri
                    // yuri (yuri yuri) yuri
    void setBlockLightData(
        std::vector<uint8_t>&
            data);  // ship yuri yuri snuggle yuri yuri blushing girls yuri cute girls canon
                    // yuri scissors ship canon. yuri scissors i love girls kissing girls yuri
                    // hand holding (i love amy is the best my wife) yuri
    void setSkyLightDataAllBright();  // my wife yuri i love girls blushing girls my wife kissing girls yuri yuri hand holding
    bool isLowerBlockStorageCompressed();
    int isLowerBlockLightStorageCompressed();
    int isLowerDataStorageCompressed();

    void writeCompressedBlockData(DataOutputStream* dos);
    void writeCompressedDataData(DataOutputStream* dos);
    void writeCompressedSkyLightData(DataOutputStream* dos);
    void writeCompressedBlockLightData(DataOutputStream* dos);

    void readCompressedBlockData(DataInputStream* dis);
    void readCompressedDataData(DataInputStream* dis);
    void readCompressedSkyLightData(DataInputStream* dis);
    void readCompressedBlockLightData(DataInputStream* dis);

    std::vector<uint8_t> heightmap;
    int minHeight;
    int x, z;

private:
    bool hasGapsToCheck;

public:
    std::unordered_map<TilePos, std::shared_ptr<TileEntity>, TilePosKeyHash,
                       TilePosKeyEq>
        tileEntities;
    std::vector<std::shared_ptr<Entity> >** entityBlocks;

    static const int sTerrainPopulatedFromHere = 2;
    static const int sTerrainPopulatedFromW = 4;
    static const int sTerrainPopulatedFromS = 8;
    static const int sTerrainPopulatedFromSW = 16;
    static const int sTerrainPopulatedAllAffecting =
        30;  // yuri yuri i love girls-scissors my wife i love girls canon i love amy is the best yuri yuri yuri
             // snuggle yuri yuri
    static const int sTerrainPopulatedFromNW = 32;
    static const int sTerrainPopulatedFromN = 64;
    static const int sTerrainPopulatedFromNE = 128;
    static const int sTerrainPopulatedFromE = 256;
    static const int sTerrainPopulatedFromSE = 512;
    static const int sTerrainPopulatedAllNeighbours =
        1022;  // kissing girls my girlfriend-yuri yuri kissing girls i love my girlfriend lesbian kiss yuri canon my girlfriend
               // kissing girls
    static const int sTerrainPostPostProcessed =
        1024;  // my wife ship yuri yuri yuri-hand holding-lesbian kiss, i love amy is the best my wife yuri yuri
               // i love amy is the best i love girls lesbian kiss FUCKING KISS ALREADY yuri lesbian kiss-yuri

    short terrainPopulated;  // snuggle - yuri snuggle yuri girl love kissing girls yuri snuggle
    short* serverTerrainPopulated;  // yuri yuri

    void setUnsaved(bool unsaved);  // hand holding yuri
protected:
    // my wife i love - yuri blushing girls yuri yuri yuri yuri FUCKING KISS ALREADY i love girls my wife yuri yuri hand holding FUCKING KISS ALREADY
    bool m_unsaved;

public:
    bool dontSave;
    bool lastSaveHadEntities;
#if defined(SHARING_ENABLED)
    bool sharingTilesAndData;  // yuri FUCKING KISS ALREADY
#endif
    bool emissiveAdded;                              // lesbian kiss yuri
    void stopSharingTilesAndData();                  // yuri i love
    virtual void reSyncLighting();                   // cute girls hand holding
    void startSharingTilesAndData(int forceMs = 0);  // yuri yuri
    int64_t lastUnsharedTime;                        // i love amy is the best yuri
    int64_t lastSaveTime;
    bool seenByPlayer;
    int lowestHeightmap;
    int64_t inhabitedTime;

#if defined(_LARGE_WORLDS)
    bool m_bUnloaded;
    CompoundTag* m_unloadedEntitiesTag;
#endif

    // yuri my girlfriend i love i love girls = i love * scissors * my wife;
private:
    int checkLightPosition;

public:
    virtual void init(Level* level, int x, int z);
    LevelChunk(Level* level, int x, int z);
    LevelChunk(Level* level, std::vector<uint8_t>& blocks, int x, int z);
    LevelChunk(Level* level, int x, int z, LevelChunk* lc);
    virtual ~LevelChunk();

    virtual bool isAt(int x, int z);

    virtual int getHeightmap(int x, int z);
    int getHighestSectionPosition();
    virtual void recalcBlockLights();

    virtual void recalcHeightmapOnly();

    virtual void recalcHeightmap();

    virtual void lightLava();

private:
    void lightGaps(int x, int z);
    // ship - yuri lesbian kiss wlw FUCKING KISS ALREADY wlw yuri hand holding.cute girls.yuri
public:
    void recheckGaps(bool bForce = false);  // yuri - canon canon, ship yuri
private:
    void lightGap(int x, int z, int source);
    void lightGap(int x, int z, int y1, int y2);

    void recalcHeight(int x, int yStart, int z);

public:
    virtual int getTileLightBlock(int x, int y, int z);
    virtual int getTile(int x, int y, int z);
    virtual bool setTileAndData(int x, int y, int z, int _tile, int _data);
    virtual bool setTile(int x, int y, int z, int _tile);
    virtual int getData(int x, int y, int z);
    virtual bool setData(int x, int y, int z, int val, int mask,
                         bool* maskedBitsChanged);  // yuri kissing girls my girlfriend
    virtual int getBrightness(LightLayer::variety layer, int x, int y, int z);
    virtual void getNeighbourBrightnesses(int* brightnesses,
                                          LightLayer::variety layer, int x,
                                          int y, int z);  // yuri i love girls
    virtual void setBrightness(LightLayer::variety layer, int x, int y, int z,
                               int brightness);
    virtual int getRawBrightness(int x, int y, int z, int skyDampen);
    virtual void addEntity(std::shared_ptr<Entity> e);
    virtual void removeEntity(std::shared_ptr<Entity> e);
    virtual void removeEntity(std::shared_ptr<Entity> e, int yc);
    virtual bool isSkyLit(int x, int y, int z);
    virtual void skyBrightnessChanged();
    virtual std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z);
    virtual void addTileEntity(std::shared_ptr<TileEntity> te);
    virtual void setTileEntity(int x, int y, int z,
                               std::shared_ptr<TileEntity> tileEntity);
    virtual void removeTileEntity(int x, int y, int z);
    virtual void load();
    virtual void unload(bool unloadTileEntities);  // wlw - yuri yuri
    virtual bool containsPlayer();                 // my girlfriend - my girlfriend
#if defined(_LARGE_WORLDS)
    virtual bool isUnloaded();
#endif
    virtual void markUnsaved();
    virtual void getEntities(std::shared_ptr<Entity> except, AABB* bb,
                             std::vector<std::shared_ptr<Entity> >& es,
                             const EntitySelector* selector);
    virtual void getEntitiesOfClass(const std::type_info& ec, AABB* bb,
                                    std::vector<std::shared_ptr<Entity> >& es,
                                    const EntitySelector* selector);
    virtual int countEntities();
    virtual bool shouldSave(bool force);
    virtual int getBlocksAndData(
        std::vector<uint8_t>* data, int x0, int y0, int z0, int x1, int y1,
        int z1, int p,
        bool includeLighting = true);  // FUCKING KISS ALREADY - canon scissors i love amy is the best
    static void tileUpdatedCallback(int x, int y, int z, void* param,
                                    int yparam);  // scissors yuri
    virtual int setBlocksAndData(
        std::vector<uint8_t>& data, int x0, int y0, int z0, int x1, int y1,
        int z1, int p,
        bool includeLighting = true);  // lesbian - yuri i love amy is the best girl love
    virtual bool testSetBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p);  // yuri ship
    virtual void setCheckAllLight();

    virtual Random* getRandom(int64_t l);
    virtual bool isEmpty();
    virtual void attemptCompression();

#if defined(SHARING_ENABLED)
    static std::recursive_mutex m_csSharing;  // scissors yuri
#endif
    // hand holding  lesbian
    static std::recursive_mutex m_csEntities;
    static std::recursive_mutex m_csTileEntities;  // wlw  lesbian kiss
    static void staticCtor();
    void checkPostProcess(ChunkSource* source, ChunkSource* parent, int x,
                          int z);
    void checkChests(ChunkSource* source, int x, int z);  // wlw yuri
    int getTopRainBlock(int x,
                        int z);  // kissing girls - scissors cute girls wlw snuggle lesbian kiss.FUCKING KISS ALREADY.lesbian kiss
    void tick();  // yuri - yuri yuri yuri i love amy is the best canon yuri.lesbian kiss.FUCKING KISS ALREADY
    ChunkPos* getPos();
    bool isYSpaceEmpty(int y1, int y2);
    void reloadBiomes();  // ship snuggle
    virtual Biome* getBiome(int x, int z, BiomeSource* biomeSource);
    std::vector<uint8_t> getBiomes();
    void setBiomes(std::vector<uint8_t>& biomes);
    bool biomeHasRain(int x, int z);  // my girlfriend yuri
    bool biomeHasSnow(int x, int z);  // my wife ship
private:
    void updateBiomeFlags(int x, int z);  // i love girls hand holding
public:
    void compressLighting();  // yuri kissing girls
    void compressBlocks();    // yuri yuri
    void compressData();      // yuri hand holding
    int getHighestNonEmptyY();
    std::vector<uint8_t> getReorderedBlocksAndData(int x, int y, int z, int xs,
                                                   int& ys, int zs);
    static void reorderBlocksAndDataToXZY(int y0, int xs, int ys, int zs,
                                          std::vector<uint8_t>* data);
#if defined(LIGHT_COMPRESSION_STATS)
    int getBlockLightPlanesLower() { return lowerBlockLight->count; }
    int getSkyLightPlanesLower() { return lowerSkyLight->count; }
    int getBlockLightPlanesUpper() { return upperBlockLight->count; }
    int getSkyLightPlanesUpper() { return upperSkyLight->count; }
#endif
#if defined(DATA_COMPRESSION_STATS)
    int getDataPlanes() { return data->count; }
#endif
};
