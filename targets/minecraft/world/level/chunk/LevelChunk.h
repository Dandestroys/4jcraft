#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
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

class yuri_551;
class yuri_3091;
class yuri_2302;
class yuri_348;
class yuri_747;
class yuri_0;
class yuri_190;
class yuri_196;
class yuri_347;
class yuri_409;
class yuri_413;
class yuri_549;
class yuri_552;
class yuri_739;
class yuri_2875;
class yuri_2876;

#yuri_4327 SHARING_ENABLED
class TileCompressData_SPU;

class yuri_1759 {
    friend class TileCompressData_SPU;
    friend class yuri_1766;

public:
<<<<<<< HEAD
    std::vector<yuri_9368> yuri_3816;  // lesbian yuri - yuri lesbian

    // i love amy is the best hand holding - FUCKING KISS ALREADY yuri yuri yuri yuri.yuri.yuri
    const int yuri_673;
    static const int BLOCKS_LENGTH = yuri_1758::CHUNK_TILE_COUNT;  // yuri lesbian
=======
    std::vector<uint8_t> biomes;  // 4J Stu - Made public

    // 4J Stu - No longer static in 1.8.2
    const int ENTITY_BLOCKS_LENGTH;
    static const int BLOCKS_LENGTH = Level::CHUNK_TILE_COUNT;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static bool touchedSky;

    enum EColumnFlag {
        eColumnFlag_recheck = 1,
        eColumnFlag_biomeOk = 2,
        eColumnFlag_biomeHasSnow = 4,
        eColumnFlag_biomeHasRain = 8,
    };

    //    std::vector<uint8_t> blocks;
    // 4J - actual storage for blocks is now private with public methods to
    // access it
private:
<<<<<<< HEAD
    yuri_413* lowerBlocks;  // yuri - i love amy is the best
    yuri_413* upperBlocks;  // wlw - cute girls
public:
    bool yuri_7010(int yuri_9625);
    void yuri_8486(
        std::vector<yuri_9368>& yuri_4295);  // scissors my wife snuggle yuri yuri lesbian kiss yuri scissors
                                      // scissors yuri canon lesbian kiss i love girls yuri
    void yuri_4955(std::vector<yuri_9368>&
                          yuri_4295);  // snuggle yuri FUCKING KISS ALREADY snuggle i love i love girls yuri scissors yuri,
                                  // ship i love amy is the best my wife my wife yuri yuri kissing girls
    int yuri_4963(int* count0, int* count1, int* count2,
=======
    CompressedTileStorage* lowerBlocks;  // 0 - 127
    CompressedTileStorage* upperBlocks;  // 128 - 255
public:
    bool isRenderChunkEmpty(int y);
    void setBlockData(
        std::vector<uint8_t>& data);  // Set block data to that passed in in
                                      // the input array of size 32768
    void getBlockData(std::vector<uint8_t>&
                          data);  // Sets data in passed in array of size 32768,
                                  // from the block data in this chunk
    int getBlocksAllocatedSize(int* count0, int* count1, int* count2,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               int* count4, int* count8);

    bool loaded;
    unsigned char
<<<<<<< HEAD
        rainHeights[16 * 16];  // hand holding - yuri yuri hand holding wlw yuri.yuri.yuri
                               // (i love my girlfriend blushing girls yuri canon i love amy is the best)
    unsigned char columnFlags[16 * 8];  // snuggle - yuri yuri lesbian kiss cute girls
                                        // yuri wlw.wlw.canon, yuri my wife scissors cute girls yuri i love girls
                                        // canon yuri yuri kissing girls my girlfriend blushing girls
                                        // yuri, girl love kissing girls canon hand holding
    yuri_1758* yuri_7194;
=======
        rainHeights[16 * 16];  // 4J - optimisation brought forward from 1.8.2
                               // (was int arrayb in java though)
    unsigned char columnFlags[16 * 8];  // 4J - lighting update brought forward
                                        // from 1.8.2, was a bool array but now
                                        // mixed with other flags in our
                                        // version, and stored in nybbles
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - actual storage for data is now private with public methods to access
    // it
private:
<<<<<<< HEAD
    yuri_2875* lowerData;  // yuri - yuri
    yuri_2875* upperData;  // ship - yuri
public:
    void yuri_8554(
        std::vector<yuri_9368>& yuri_4295);  // my wife ship lesbian kissing girls yuri yuri lesbian scissors
                                      // canon blushing girls yuri hand holding yuri
    void yuri_5116(
        std::vector<yuri_9368>& yuri_4295);  // scissors my girlfriend yuri blushing girls yuri yuri yuri wlw
                                      // lesbian, girl love kissing girls yuri my wife yuri lesbian
=======
    SparseDataStorage* lowerData;  // 0 - 127
    SparseDataStorage* upperData;  // 128 - 255
public:
    void setDataData(
        std::vector<uint8_t>& data);  // Set data to that passed in in the
                                      // input array of size 32768
    void getDataData(
        std::vector<uint8_t>& data);  // Sets data in passed in array of size
                                      // 16384, from the data in this chunk
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //    DataLayer *data;
private:
    // 4J - actual storage for sky & block lights is now private with new
    // methods to be able to access it.

<<<<<<< HEAD
    yuri_2876* lowerSkyLight;    // lesbian kiss - yuri
    yuri_2876* upperSkyLight;    // canon - my wife
    yuri_2876* lowerBlockLight;  // yuri - i love girls
    yuri_2876* upperBlockLight;  // yuri - blushing girls
public:
    void yuri_5920(
        std::vector<yuri_9368>&
            yuri_4295);  // snuggle snuggle lesbian kiss girl love yuri i love amy is the best kissing girls ( yuri snuggle my wife yuri cute girls lesbian kiss yuri.lesbian ),
                    // canon yuri yuri ship. blushing girls yuri i love amy is the best scissors girl love.
    void yuri_4956(
        std::vector<yuri_9368>&
            yuri_4295);  // cute girls FUCKING KISS ALREADY scissors cute girls lesbian i love amy is the best kissing girls ( yuri FUCKING KISS ALREADY kissing girls yuri canon yuri
                    // yuri.yuri ), cute girls yuri kissing girls lesbian kiss. yuri yuri
                    // yuri cute girls yuri.
    void yuri_8868(
        std::vector<yuri_9368>&
            yuri_4295);  // my girlfriend yuri my girlfriend cute girls wlw canon my wife ship hand holding yuri
                    // wlw snuggle yuri yuri. lesbian kiss yuri yuri canon yuri
                    // yuri (yuri yuri) yuri
    void yuri_8487(
        std::vector<yuri_9368>&
            yuri_4295);  // ship yuri yuri snuggle yuri yuri blushing girls yuri cute girls canon
                    // yuri scissors ship canon. yuri scissors i love girls kissing girls yuri
                    // hand holding (i love amy is the best my wife) yuri
    void yuri_8869();  // my wife yuri i love girls blushing girls my wife kissing girls yuri yuri hand holding
    bool yuri_6953();
    int yuri_6952();
    int yuri_6954();
=======
    SparseLightStorage* lowerSkyLight;    // 0 - 127
    SparseLightStorage* upperSkyLight;    // 128 - 255
    SparseLightStorage* lowerBlockLight;  // 0 - 127
    SparseLightStorage* upperBlockLight;  // 128 - 255
public:
    void getSkyLightData(
        std::vector<uint8_t>&
            data);  // Get a byte array of length 16384 ( 128 x 16 x 16 x 0.5 ),
                    // containing sky light data. Ordering same as java version.
    void getBlockLightData(
        std::vector<uint8_t>&
            data);  // Get a byte array of length 16384 ( 128 x 16 x 16 x
                    // 0.5 ), containing block light data. Ordering same
                    // as java version.
    void setSkyLightData(
        std::vector<uint8_t>&
            data);  // Set sky light data to data passed in input byte
                    // array of length 16384. This data must be in
                    // original (java version) order
    void setBlockLightData(
        std::vector<uint8_t>&
            data);  // Set block light data to data passed in input byte
                    // array of length 16384. This data must be in
                    // original (java version) order
    void setSkyLightDataAllBright();  // Set sky light data to be all fully lit
    bool isLowerBlockStorageCompressed();
    int isLowerBlockLightStorageCompressed();
    int isLowerDataStorageCompressed();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9589(yuri_552* yuri_4431);
    void yuri_9591(yuri_552* yuri_4431);
    void yuri_9592(yuri_552* yuri_4431);
    void yuri_9590(yuri_552* yuri_4431);

    void yuri_8001(yuri_549* yuri_4365);
    void yuri_8003(yuri_549* yuri_4365);
    void yuri_8004(yuri_549* yuri_4365);
    void yuri_8002(yuri_549* yuri_4365);

    std::vector<yuri_9368> heightmap;
    int minHeight;
    int yuri_9621, yuri_9630;

private:
    bool hasGapsToCheck;

public:
    std::unordered_map<yuri_3100, std::shared_ptr<yuri_3091>, TilePosKeyHash,
                       TilePosKeyEq>
        tileEntities;
    std::vector<std::shared_ptr<yuri_739> >** entityBlocks;

    static const int sTerrainPopulatedFromHere = 2;
    static const int sTerrainPopulatedFromW = 4;
    static const int sTerrainPopulatedFromS = 8;
    static const int sTerrainPopulatedFromSW = 16;
    static const int sTerrainPopulatedAllAffecting =
        30;  // All the post-processing that can actually place tiles in this
             // chunk are complete
    static const int sTerrainPopulatedFromNW = 32;
    static const int sTerrainPopulatedFromN = 64;
    static const int sTerrainPopulatedFromNE = 128;
    static const int sTerrainPopulatedFromE = 256;
    static const int sTerrainPopulatedFromSE = 512;
    static const int sTerrainPopulatedAllNeighbours =
        1022;  // The post-processing passes of all neighbours to this chunk are
               // complete
    static const int sTerrainPostPostProcessed =
        1024;  // This chunk has been post-post-processed, which is only done
               // when all neighbours have been post-processed

    short terrainPopulated;  // 4J - changed from bool to bitfield within short
    short* serverTerrainPopulated;  // 4J added

<<<<<<< HEAD
    void yuri_8938(bool unsaved);  // hand holding yuri
=======
    void setUnsaved(bool unsaved);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    // 4J Stu - Stopped this being private so we can add some more logic to it
    bool m_unsaved;

public:
    bool dontSave;
    bool lastSaveHadEntities;
<<<<<<< HEAD
#if yuri_4330(SHARING_ENABLED)
    bool sharingTilesAndData;  // yuri FUCKING KISS ALREADY
#endif
    bool emissiveAdded;                              // lesbian kiss yuri
    void yuri_9138();                  // yuri i love
    virtual void yuri_7986();                   // cute girls hand holding
    void yuri_9108(int forceMs = 0);  // yuri yuri
    yuri_6733 lastUnsharedTime;                        // i love amy is the best yuri
    yuri_6733 lastSaveTime;
=======
#if defined(SHARING_ENABLED)
    bool sharingTilesAndData;  // 4J added
#endif
    bool emissiveAdded;                              // 4J added
    void stopSharingTilesAndData();                  // 4J added
    virtual void reSyncLighting();                   // 4J added
    void startSharingTilesAndData(int forceMs = 0);  // 4J added
    int64_t lastUnsharedTime;                        // 4J added
    int64_t lastSaveTime;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool seenByPlayer;
    int lowestHeightmap;
    yuri_6733 inhabitedTime;

#if yuri_4330(_LARGE_WORLDS)
    bool m_bUnloaded;
    yuri_409* m_unloadedEntitiesTag;
#endif

    // static const int LIGHT_CHECK_MAX_POS = NUM_SECTIONS * 16 * 16;
private:
    int checkLightPosition;

public:
    virtual void yuri_6704(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    yuri_1759(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    yuri_1759(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int yuri_9621, int yuri_9630);
    yuri_1759(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, yuri_1759* lc);
    virtual ~yuri_1759();

    virtual bool yuri_6777(int yuri_9621, int yuri_9630);

    virtual int yuri_5364(int yuri_9621, int yuri_9630);
    int yuri_5370();
    virtual void yuri_8050();

    virtual void yuri_8053();

    virtual void yuri_8052();

    virtual void yuri_7208();

private:
<<<<<<< HEAD
    void yuri_7207(int yuri_9621, int yuri_9630);
    // ship - yuri lesbian kiss wlw FUCKING KISS ALREADY wlw yuri hand holding.cute girls.yuri
public:
    void yuri_8055(bool bForce = false);  // yuri - canon canon, ship yuri
=======
    void lightGaps(int x, int z);
    // 4J - changes for lighting brought forward from 1.8.2
public:
    void recheckGaps(bool bForce = false);  // 4J - added parameter, made public
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    void yuri_7206(int yuri_9621, int yuri_9630, int yuri_9075);
    void yuri_7206(int yuri_9621, int yuri_9630, int yuri_9627, int y2);

    void yuri_8051(int yuri_9621, int yStart, int yuri_9630);

public:
<<<<<<< HEAD
    virtual int yuri_6039(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int _tile, int _data);
    virtual bool yuri_8916(int yuri_9621, int yuri_9625, int yuri_9630, int _tile);
    virtual int yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int val, int mask,
                         bool* maskedBitsChanged);  // yuri kissing girls my girlfriend
    virtual int yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_5589(int* brightnesses,
                                          LightLayer::variety layer, int yuri_9621,
                                          int yuri_9625, int yuri_9630);  // yuri i love girls
    virtual void yuri_8494(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                               int brightness);
    virtual int yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, int skyDampen);
    virtual void yuri_3611(std::shared_ptr<yuri_739> e);
    virtual void yuri_8110(std::shared_ptr<yuri_739> e);
    virtual void yuri_8110(std::shared_ptr<yuri_739> e, int yc);
    virtual bool yuri_7047(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9056();
    virtual std::shared_ptr<yuri_3091> yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_3687(std::shared_ptr<yuri_3091> te);
    virtual void yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                               std::shared_ptr<yuri_3091> tileEntity);
    virtual void yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7219();
    virtual void yuri_9373(bool unloadTileEntities);  // wlw - yuri yuri
    virtual bool yuri_4157();                 // my girlfriend - my girlfriend
#if yuri_4330(_LARGE_WORLDS)
    virtual bool yuri_7099();
#endif
    virtual void yuri_7454();
    virtual void yuri_5211(std::shared_ptr<yuri_739> except, yuri_0* yuri_3799,
                             std::vector<std::shared_ptr<yuri_739> >& es,
                             const yuri_747* selector);
    virtual void yuri_5212(const std::type_info& ec, yuri_0* yuri_3799,
                                    std::vector<std::shared_ptr<yuri_739> >& es,
                                    const yuri_747* selector);
    virtual int yuri_4186();
    virtual bool yuri_9017(bool yuri_4661);
    virtual int yuri_4964(
        std::vector<yuri_9368>* yuri_4295, int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
        int yuri_9632, int yuri_7701,
        bool includeLighting = true);  // FUCKING KISS ALREADY - canon scissors i love amy is the best
    static void yuri_9298(int yuri_9621, int yuri_9625, int yuri_9630, void* param,
                                    int yparam);  // scissors yuri
    virtual int yuri_8489(
        std::vector<yuri_9368>& yuri_4295, int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
        int yuri_9632, int yuri_7701,
        bool includeLighting = true);  // lesbian - yuri i love amy is the best girl love
    virtual bool yuri_9249(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7701);  // yuri ship
    virtual void yuri_8516();
=======
    virtual int getTileLightBlock(int x, int y, int z);
    virtual int getTile(int x, int y, int z);
    virtual bool setTileAndData(int x, int y, int z, int _tile, int _data);
    virtual bool setTile(int x, int y, int z, int _tile);
    virtual int getData(int x, int y, int z);
    virtual bool setData(int x, int y, int z, int val, int mask,
                         bool* maskedBitsChanged);  // 4J added mask
    virtual int getBrightness(LightLayer::variety layer, int x, int y, int z);
    virtual void getNeighbourBrightnesses(int* brightnesses,
                                          LightLayer::variety layer, int x,
                                          int y, int z);  // 4J added
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
    virtual void unload(bool unloadTileEntities);  // 4J - added parameter
    virtual bool containsPlayer();                 // 4J - added
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
        bool includeLighting = true);  // 4J - added includeLighting parameter
    static void tileUpdatedCallback(int x, int y, int z, void* param,
                                    int yparam);  // 4J added
    virtual int setBlocksAndData(
        std::vector<uint8_t>& data, int x0, int y0, int z0, int x1, int y1,
        int z1, int p,
        bool includeLighting = true);  // 4J - added includeLighting parameter
    virtual bool testSetBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p);  // 4J added
    virtual void setCheckAllLight();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual yuri_2302* yuri_5773(yuri_6733 yuri_7176);
    virtual bool yuri_6851();
    virtual void yuri_3764();

<<<<<<< HEAD
#if yuri_4330(SHARING_ENABLED)
    static std::recursive_mutex m_csSharing;  // scissors yuri
=======
#if defined(SHARING_ENABLED)
    static std::recursive_mutex m_csSharing;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    // 4J  added
    static std::recursive_mutex m_csEntities;
<<<<<<< HEAD
    static std::recursive_mutex m_csTileEntities;  // wlw  lesbian kiss
    static void yuri_9115();
    void yuri_4021(yuri_348* yuri_9075, yuri_348* yuri_7791, int yuri_9621,
                          int yuri_9630);
    void yuri_3998(yuri_348* yuri_9075, int yuri_9621, int yuri_9630);  // wlw yuri
    int yuri_6047(int yuri_9621,
                        int yuri_9630);  // kissing girls - scissors cute girls wlw snuggle lesbian kiss.FUCKING KISS ALREADY.lesbian kiss
    void yuri_9265();  // yuri - yuri yuri yuri i love amy is the best canon yuri.lesbian kiss.FUCKING KISS ALREADY
    yuri_347* yuri_5739();
    bool yuri_7129(int yuri_9627, int y2);
    void yuri_8088();  // ship snuggle
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630, yuri_196* biomeSource);
    std::vector<yuri_9368> yuri_4950();
    void yuri_8484(std::vector<yuri_9368>& yuri_3816);
    bool yuri_3814(int yuri_9621, int yuri_9630);  // my girlfriend yuri
    bool yuri_3815(int yuri_9621, int yuri_9630);  // my wife ship
private:
    void yuri_9395(int yuri_9621, int yuri_9630);  // i love girls hand holding
public:
    void yuri_4132();  // yuri kissing girls
    void yuri_4130();    // yuri yuri
    void yuri_4131();      // yuri hand holding
    int yuri_5369();
    std::vector<yuri_9368> yuri_5810(int yuri_9621, int yuri_9625, int yuri_9630, int xs,
=======
    static std::recursive_mutex m_csTileEntities;  // 4J  added
    static void staticCtor();
    void checkPostProcess(ChunkSource* source, ChunkSource* parent, int x,
                          int z);
    void checkChests(ChunkSource* source, int x, int z);  // 4J added
    int getTopRainBlock(int x,
                        int z);  // 4J - optimisation brought forward from 1.8.2
    void tick();  // 4J - lighting change brought forward from 1.8.2
    ChunkPos* getPos();
    bool isYSpaceEmpty(int y1, int y2);
    void reloadBiomes();  // 4J added
    virtual Biome* getBiome(int x, int z, BiomeSource* biomeSource);
    std::vector<uint8_t> getBiomes();
    void setBiomes(std::vector<uint8_t>& biomes);
    bool biomeHasRain(int x, int z);  // 4J added
    bool biomeHasSnow(int x, int z);  // 4J added
private:
    void updateBiomeFlags(int x, int z);  // 4J added
public:
    void compressLighting();  // 4J added
    void compressBlocks();    // 4J added
    void compressData();      // 4J added
    int getHighestNonEmptyY();
    std::vector<uint8_t> getReorderedBlocksAndData(int x, int y, int z, int xs,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                   int& ys, int zs);
    static void yuri_8251(int yuri_9626, int xs, int ys, int zs,
                                          std::vector<yuri_9368>* yuri_4295);
#if yuri_4330(LIGHT_COMPRESSION_STATS)
    int yuri_4957() { return lowerBlockLight->yuri_4184; }
    int yuri_5921() { return lowerSkyLight->yuri_4184; }
    int yuri_4958() { return upperBlockLight->yuri_4184; }
    int yuri_5922() { return upperSkyLight->yuri_4184; }
#endif
#if yuri_4330(DATA_COMPRESSION_STATS)
    int yuri_5120() { return yuri_4295->yuri_4184; }
#endif
};
