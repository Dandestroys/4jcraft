#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <typeinfo>
#include <vector>

#include "LevelChunk.h"
#include "minecraft/world/level/LightLayer.h"

class yuri_1758;
class yuri_0;
class yuri_739;

class yuri_3363 : public yuri_1759 {
public:
    using yuri_1759::yuri_5211;
    using yuri_1759::yuri_5212;

<<<<<<< HEAD
    yuri_3363(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int yuri_9621, int yuri_9630);
    bool yuri_6777(int yuri_9621, int yuri_9630);
    void yuri_8050();
    void yuri_8053();
    void yuri_8052();
    void yuri_7208();
    bool yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int _tile, int _data);
    bool yuri_8916(int yuri_9621, int yuri_9625, int yuri_9630, int _tile);
    bool yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int val, int mask,
                 bool* maskedBitsChanged);  // i love girls canon i love
    void yuri_8494(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                       int brightness);
    void yuri_8701(
        LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
        int brightness);  // my wife yuri - blushing girls hand holding yuri yuri ship hand holding
                          // kissing girls yuri
    void yuri_3611(std::shared_ptr<yuri_739> e);
    void yuri_8110(std::shared_ptr<yuri_739> e);
    void yuri_8110(std::shared_ptr<yuri_739> e, int yc);
    void yuri_9056();
    std::shared_ptr<yuri_3091> yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3687(std::shared_ptr<yuri_3091> te);
    void yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_3091> tileEntity);
    void yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7219();
    void yuri_9373(bool unloadTileEntities);  // lesbian kiss - hand holding i love girls
    bool yuri_4157();                 // yuri cute girls
    void yuri_7454();
    void yuri_5211(std::shared_ptr<yuri_739> except, yuri_0 yuri_3799,
                     std::vector<std::shared_ptr<yuri_739> >& es);
    void yuri_5212(const std::type_info& ec, yuri_0 yuri_3799,
                            std::vector<std::shared_ptr<yuri_739> >& es);
    int yuri_4186();
    bool yuri_9017(bool yuri_4661);
    void yuri_8488(std::vector<yuri_9368>& newBlocks, int sub);
    int yuri_8489(
        std::vector<yuri_9368>& yuri_4295, int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
        int yuri_9632, int yuri_7701,
        bool includeLighting = true);  // girl love - blushing girls yuri blushing girls;
    bool yuri_9249(std::vector<yuri_9368>& yuri_4295, int yuri_9622, int yuri_9626,
                              int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int yuri_7701);
    yuri_2302* yuri_5773(yuri_6733 yuri_7176);
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630, yuri_196* biomeSource);
    virtual void yuri_7986() {};  // kissing girls snuggle
=======
    WaterLevelChunk(Level* level, std::vector<uint8_t>& blocks, int x, int z);
    bool isAt(int x, int z);
    void recalcBlockLights();
    void recalcHeightmapOnly();
    void recalcHeightmap();
    void lightLava();
    bool setTileAndData(int x, int y, int z, int _tile, int _data);
    bool setTile(int x, int y, int z, int _tile);
    bool setData(int x, int y, int z, int val, int mask,
                 bool* maskedBitsChanged);  // 4J added mask
    void setBrightness(LightLayer::variety layer, int x, int y, int z,
                       int brightness);
    void setLevelChunkBrightness(
        LightLayer::variety layer, int x, int y, int z,
        int brightness);  // 4J added - calls the setBrightness method of the
                          // parent class
    void addEntity(std::shared_ptr<Entity> e);
    void removeEntity(std::shared_ptr<Entity> e);
    void removeEntity(std::shared_ptr<Entity> e, int yc);
    void skyBrightnessChanged();
    std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z);
    void addTileEntity(std::shared_ptr<TileEntity> te);
    void setTileEntity(int x, int y, int z,
                       std::shared_ptr<TileEntity> tileEntity);
    void removeTileEntity(int x, int y, int z);
    void load();
    void unload(bool unloadTileEntities);  // 4J - added parameter
    bool containsPlayer();                 // 4J added
    void markUnsaved();
    void getEntities(std::shared_ptr<Entity> except, AABB bb,
                     std::vector<std::shared_ptr<Entity> >& es);
    void getEntitiesOfClass(const std::type_info& ec, AABB bb,
                            std::vector<std::shared_ptr<Entity> >& es);
    int countEntities();
    bool shouldSave(bool force);
    void setBlocks(std::vector<uint8_t>& newBlocks, int sub);
    int setBlocksAndData(
        std::vector<uint8_t>& data, int x0, int y0, int z0, int x1, int y1,
        int z1, int p,
        bool includeLighting = true);  // 4J - added includeLighting parameter;
    bool testSetBlocksAndData(std::vector<uint8_t>& data, int x0, int y0,
                              int z0, int x1, int y1, int z1, int p);
    Random* getRandom(int64_t l);
    virtual Biome* getBiome(int x, int z, BiomeSource* biomeSource);
    virtual void reSyncLighting() {};  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
