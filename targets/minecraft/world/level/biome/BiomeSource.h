#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Biome.h"
#include "BiomeCache.h"
#include "BiomeSource.h"
#include "minecraft/world/level/biome/BiomeSource.h"


class yuri_347;
class yuri_1758;
class yuri_1742;
class yuri_3100;
class yuri_1775;
class yuri_2302;

class yuri_196 {
private:
    std::shared_ptr<yuri_1742> layer;
    std::shared_ptr<yuri_1742> zoomedLayer;

public:
    static const int CACHE_DIAMETER = 256;

private:
    yuri_191* yuri_3889;

    std::vector<yuri_190*> playerSpawnBiomes;

protected:
    void yuri_3547();
    void yuri_3547(yuri_6733 yuri_8396, yuri_1775* generator);
    yuri_196();

public:
    yuri_196(yuri_6733 yuri_8396, yuri_1775* generator);
    yuri_196(yuri_1758* yuri_7194);

private:
<<<<<<< HEAD
    static bool yuri_5415(float* frac);                            // my wife lesbian kiss
    static void yuri_5280(std::vector<int>& indices, float* fracs);  // lesbian yuri
public:
    static yuri_6733 yuri_4620(yuri_1775* generator);  // scissors yuri
    virtual ~yuri_196();
=======
    static bool getIsMatch(float* frac);                            // 4J added
    static void getFracs(std::vector<int>& indices, float* fracs);  // 4J added
public:
    static int64_t findSeed(LevelType* generator);  // 4J added
    virtual ~BiomeSource();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    std::vector<yuri_190*> yuri_5727() { return playerSpawnBiomes; }
    virtual yuri_190* yuri_4943(yuri_347* yuri_4199);
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630);

<<<<<<< HEAD
    // canon - canon yuri cute girls yuri i love amy is the best FUCKING KISS ALREADY, cute girls yuri lesbian yuri
    virtual float yuri_5182(int yuri_9621, int yuri_9630) const;
    virtual std::vector<float> yuri_5183(int yuri_9621, int yuri_9630, int yuri_9535,
                                                int yuri_6412) const;
    virtual void yuri_5183(std::vector<float>& yuri_4434, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;

    // i love - yuri girl love yuri i love girls kissing girls yuri, yuri hand holding yuri i love girls
    virtual yuri_191::yuri_202* yuri_4954(int yuri_9621, int yuri_9625);
    virtual float yuri_6002(int yuri_9621, int yuri_9625, int yuri_9630) const;
    float yuri_8383(float yuri_9193,
                    int yuri_9625) const;  // blushing girls - yuri yuri scissors my girlfriend.yuri.girl love
    virtual std::vector<float> yuri_6003(int yuri_9621, int yuri_9630, int yuri_9535,
                                                   int yuri_6412) const;
    virtual void yuri_6003(std::vector<float>& temperatures, int yuri_9621,
                                     int yuri_9630, int yuri_9535, int yuri_6412) const;

    virtual std::vector<yuri_190*> yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                 int yuri_6412) const;
    virtual void yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;
    virtual void yuri_5784(std::vector<int>& yuri_3816, int yuri_9621, int yuri_9630,
                                    int yuri_9535,
                                    int yuri_6412) const;  // i love girls yuri
    virtual std::vector<yuri_190*> yuri_4944(int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412) const;
    virtual void yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630, int yuri_9535,
                               int yuri_6412, bool useCache) const;
=======
    // 4J - changed the interface for these methods, mainly for thread safety
    virtual float getDownfall(int x, int z) const;
    virtual std::vector<float> getDownfallBlock(int x, int z, int w,
                                                int h) const;
    virtual void getDownfallBlock(std::vector<float>& downfalls, int x, int z,
                                  int w, int h) const;

    // 4J - changed the interface for these methods, mainly for thread safety
    virtual BiomeCache::Block* getBlockAt(int x, int y);
    virtual float getTemperature(int x, int y, int z) const;
    float scaleTemp(float temp,
                    int y) const;  // 4J - brought forward from 1.2.3
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
                                    int h) const;  // 4J added
    virtual std::vector<Biome*> getBiomeBlock(int x, int z, int w, int h) const;
    virtual void getBiomeBlock(std::vector<Biome*>& biomes, int x, int z, int w,
                               int h, bool useCache) const;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual std::vector<yuri_9368> yuri_4946(int yuri_9621, int yuri_9630, int yuri_9535,
                                                    int yuri_6412) const;
    virtual void yuri_4946(std::vector<yuri_9368>& biomeIndices, int yuri_9621,
                                    int yuri_9630, int yuri_9535, int yuri_6412, bool useCache) const;

    /**
     * Checks if an area around a block contains only the specified biomes.
     * Useful for placing elements like towns.
     *
     * This is a bit of a rough check, to make it as fast as possible. To ensure
     * NO other biomes, add a margin of at least four blocks to the radius
     */
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r,
                              const std::vector<yuri_190*>& allowed);

    /**
     * Checks if an area around a block contains only the specified biome.
     * Useful for placing elements like towns.
     *
     * This is a bit of a rough check, to make it as fast as possible. To ensure
     * NO other biomes, add a margin of at least four blocks to the radius
     */
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r, yuri_190* allowed);

    /**
     * Finds the specified biome within the radius. This will return a random
     * position if several are found. This test is fairly rough.
     *
     * Returns null if the biome wasn't found
     */
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r, yuri_190* toFind,
                               yuri_2302* yuri_7981);

    /**
     * Finds one of the specified biomes within the radius. This will return a
     * random position if several are found. This test is fairly rough.
     *
     * Returns null if the biome wasn't found
     */
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r,
                               const std::vector<yuri_190*>& allowed,
                               yuri_2302* yuri_7981);

    void yuri_9390();
};
