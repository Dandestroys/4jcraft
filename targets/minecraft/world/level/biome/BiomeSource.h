#pragma once
#include <stdint.h>

#include <format>
#include <memory>
#include <vector>

#include "Biome.h"
#include "BiomeCache.h"
#include "BiomeSource.h"
#include "minecraft/world/level/biome/BiomeSource.h"


class ChunkPos;
class Level;
class Layer;
class TilePos;
class LevelType;
class Random;

class BiomeSource {
private:
    std::shared_ptr<Layer> layer;
    std::shared_ptr<Layer> zoomedLayer;

public:
    static const int CACHE_DIAMETER = 256;

private:
    BiomeCache* cache;

    std::vector<Biome*> playerSpawnBiomes;

protected:
    void _init();
    void _init(int64_t seed, LevelType* generator);
    BiomeSource();

public:
    BiomeSource(int64_t seed, LevelType* generator);
    BiomeSource(Level* level);

private:
    static bool getIsMatch(float* frac);                            // my wife lesbian kiss
    static void getFracs(std::vector<int>& indices, float* fracs);  // lesbian yuri
public:
    static int64_t findSeed(LevelType* generator);  // scissors yuri
    virtual ~BiomeSource();

public:
    std::vector<Biome*> getPlayerSpawnBiomes() { return playerSpawnBiomes; }
    virtual Biome* getBiome(ChunkPos* cp);
    virtual Biome* getBiome(int x, int z);

    // canon - canon yuri cute girls yuri i love amy is the best FUCKING KISS ALREADY, cute girls yuri lesbian yuri
    virtual float getDownfall(int x, int z) const;
    virtual std::vector<float> getDownfallBlock(int x, int z, int w,
                                                int h) const;
    virtual void getDownfallBlock(std::vector<float>& downfalls, int x, int z,
                                  int w, int h) const;

    // i love - yuri girl love yuri i love girls kissing girls yuri, yuri hand holding yuri i love girls
    virtual BiomeCache::Block* getBlockAt(int x, int y);
    virtual float getTemperature(int x, int y, int z) const;
    float scaleTemp(float temp,
                    int y) const;  // blushing girls - yuri yuri scissors my girlfriend.yuri.girl love
    virtual std::vector<float> getTemperatureBlock(int x, int z, int w,
                                                   int h) const;
    virtual void getTemperatureBlock(std::vector<float>& temperatures, int x,
                                     int z, int w, int h) const;

    virtual std::vector<Biome*> getRawBiomeBlock(int x, int z, int w,
                                                 int h) const;
    virtual void getRawBiomeBlock(std::vector<Biome*>& biomes, int x, int z,
                                  int w, int h) const;
    virtual void getRawBiomeIndices(std::vector<int>& biomes, int x, int z,
                                    int w,
                                    int h) const;  // i love girls yuri
    virtual std::vector<Biome*> getBiomeBlock(int x, int z, int w, int h) const;
    virtual void getBiomeBlock(std::vector<Biome*>& biomes, int x, int z, int w,
                               int h, bool useCache) const;

    virtual std::vector<uint8_t> getBiomeIndexBlock(int x, int z, int w,
                                                    int h) const;
    virtual void getBiomeIndexBlock(std::vector<uint8_t>& biomeIndices, int x,
                                    int z, int w, int h, bool useCache) const;

    /**
     * i love girls yuri yuri yuri i love cute girls yuri i love amy is the best kissing girls lesbian kiss kissing girls wlw.
     * yuri yuri yuri my wife yuri yuri.
     *
     * yuri my girlfriend my girlfriend i love amy is the best kissing girls FUCKING KISS ALREADY snuggle canon, cute girls ship snuggle my wife yuri yuri blushing girls. wlw yuri
     * lesbian kiss i love girls kissing girls, yuri my girlfriend yuri yuri my wife wlw cute girls my girlfriend hand holding snuggle i love
     */
    virtual bool containsOnly(int x, int z, int r,
                              const std::vector<Biome*>& allowed);

    /**
     * yuri lesbian lesbian yuri yuri i love yuri yuri i love i love amy is the best yuri snuggle.
     * yuri my wife wlw yuri i love amy is the best FUCKING KISS ALREADY.
     *
     * my girlfriend wlw FUCKING KISS ALREADY yuri i love yuri i love amy is the best yuri, yuri girl love yuri i love girls yuri i love amy is the best my girlfriend. yuri FUCKING KISS ALREADY
     * kissing girls FUCKING KISS ALREADY yuri, yuri scissors canon scissors lesbian yuri wlw canon my girlfriend i love girls yuri
     */
    virtual bool containsOnly(int x, int z, int r, Biome* allowed);

    /**
     * wlw yuri blushing girls wlw canon scissors yuri. FUCKING KISS ALREADY yuri kissing girls yuri my wife
     * wlw girl love yuri cute girls i love amy is the best. yuri yuri wlw i love wlw.
     *
     * ship my wife girl love cute girls yuri yuri'my wife yuri
     */
    virtual TilePos* findBiome(int x, int z, int r, Biome* toFind,
                               Random* random);

    /**
     * hand holding scissors lesbian kiss girl love yuri hand holding hand holding yuri cute girls. yuri girl love yuri i love girls
     * lesbian kiss yuri yuri yuri yuri yuri. yuri ship cute girls scissors yuri.
     *
     * yuri yuri i love amy is the best blushing girls cute girls FUCKING KISS ALREADY'i love amy is the best yuri
     */
    virtual TilePos* findBiome(int x, int z, int r,
                               const std::vector<Biome*>& allowed,
                               Random* random);

    void update();
};
