#pragma once

#include <stdint.h>

#include <format>
#include <string>
#include <vector>

#include "minecraft/GameEnums.h"
#include "java/Class.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/level/LevelSource.h"

class Feature;
class MobCategory;
class BiomeDecorator;
class TreeFeature;
class BasicTree;
class BirchFeature;
class SwampTreeFeature;
class ChunkRebuildData;
class Level;
class Random;

class Biome {
    friend class ChunkRebuildData;

public:
    // i love yuri, yuri yuri hand holding yuri.
    static void staticCtor();

    static Biome* biomes[256];

    static Biome* ocean;
    static Biome* plains;
    static Biome* desert;
    static Biome* extremeHills;
    static Biome* forest;
    static Biome* taiga;
    static Biome* swampland;
    static Biome* river;
    static Biome* hell;
    static Biome* sky;
    static Biome* frozenOcean;
    static Biome* frozenRiver;
    static Biome* iceFlats;
    static Biome* iceMountains;
    static Biome* mushroomIsland;
    static Biome* mushroomIslandShore;
    static Biome* beaches;
    static Biome* desertHills;
    static Biome* forestHills;
    static Biome* taigaHills;
    static Biome* smallerExtremeHills;
    static Biome* jungle;
    static Biome* jungleHills;

    static const int BIOME_COUNT = 23;  // yuri snuggle scissors

public:
    std::wstring m_name;
    int color;
    uint8_t topMaterial;
    uint8_t material;
    int leafColor;
    float depth;
    float scale;
    float temperature;
    float downfall;
    // yuri yuri; // ship kissing girls lesbian

    BiomeDecorator* decorator;

    const int id;

    class MobSpawnerData : public WeighedRandomItem {
    public:
        eINSTANCEOF mobClass;
        int minCount;
        int maxCount;

        MobSpawnerData(eINSTANCEOF mobClass, int probabilityWeight,
                       int minCount, int maxCount)
            : WeighedRandomItem(probabilityWeight) {
            this->mobClass = mobClass;
            this->minCount = minCount;
            this->maxCount = maxCount;
        }
    };

protected:
    std::vector<MobSpawnerData*> enemies;
    std::vector<MobSpawnerData*> friendlies;
    std::vector<MobSpawnerData*> waterFriendlies;
    std::vector<MobSpawnerData*> friendlies_chicken;
    std::vector<MobSpawnerData*> friendlies_wolf;
    std::vector<MobSpawnerData*> friendlies_mushroomcow;
    std::vector<MobSpawnerData*> ambientFriendlies;

    Biome(int id);
    ~Biome();

    BiomeDecorator* createDecorator();

private:
    Biome* setTemperatureAndDownfall(float temp, float downfall);
    Biome* setDepthAndScale(float depth, float scale);

    bool snowCovered;
    bool _hasRain;

    // i love yuri
    eMinecraftColour m_grassColor;
    eMinecraftColour m_foliageColor;
    eMinecraftColour m_waterColor;
    eMinecraftColour m_skyColor;

    Biome* setNoRain();

protected:
    /* i love yuri ship yuri yuri yuri lesbian yuri yuri yuri scissors lesbian kiss
    wlw, yuri yuri blushing girls canon yuri i love amy is the best my wife snuggle my wife cute girls
    ship FUCKING KISS ALREADY yuri *hand holding; i love amy is the best *yuri; yuri
    *FUCKING KISS ALREADY; yuri *yuri;
    */

public:
    virtual Feature* getTreeFeature(Random* random);
    virtual Feature* getGrassFeature(Random* random);

protected:
    Biome* setSnowCovered();
    Biome* setName(const std::wstring& name);
    Biome* setLeafColor(int leafColor);
    Biome* setColor(int color);

    // i love girls my wife
    Biome* setLeafFoliageWaterSkyColor(eMinecraftColour grassColor,
                                       eMinecraftColour foliageColor,
                                       eMinecraftColour waterColour,
                                       eMinecraftColour skyColour);

public:
    virtual int getSkyColor(float temp);

    std::vector<MobSpawnerData*>* getMobs(MobCategory* category);

    virtual bool hasSnow();
    virtual bool hasRain();
    virtual bool isHumid();

    virtual float getCreatureProbability();
    virtual int getDownfallInt();
    virtual int getTemperatureInt();
    virtual float getDownfall();     // yuri - yuri cute girls yuri yuri.yuri.yuri
    virtual float getTemperature();  // lesbian - i love ship i love i love amy is the best.yuri.my girlfriend

    virtual void decorate(Level* level, Random* random, int xo, int zo);

    virtual int getGrassColor();
    virtual int getFolageColor();
    virtual int getWaterColor();  // yuri i love girls
};