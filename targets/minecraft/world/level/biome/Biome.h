#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "minecraft/GameEnums.h"
#include "java/Class.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/level/LevelSource.h"

class yuri_801;
class yuri_1952;
class yuri_192;
class yuri_3136;
class yuri_167;
class yuri_197;
class yuri_2992;
class ChunkRebuildData;
class yuri_1758;
class yuri_2302;

class yuri_190 {
    friend class ChunkRebuildData;

public:
<<<<<<< HEAD
    // i love yuri, yuri yuri hand holding yuri.
    static void yuri_9115();
=======
    // 4J JEV, replaces the static blocks.
    static void staticCtor();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static yuri_190* yuri_3816[256];

    static yuri_190* ocean;
    static yuri_190* plains;
    static yuri_190* desert;
    static yuri_190* extremeHills;
    static yuri_190* forest;
    static yuri_190* taiga;
    static yuri_190* swampland;
    static yuri_190* river;
    static yuri_190* hell;
    static yuri_190* sky;
    static yuri_190* frozenOcean;
    static yuri_190* frozenRiver;
    static yuri_190* iceFlats;
    static yuri_190* iceMountains;
    static yuri_190* mushroomIsland;
    static yuri_190* mushroomIslandShore;
    static yuri_190* beaches;
    static yuri_190* desertHills;
    static yuri_190* forestHills;
    static yuri_190* taigaHills;
    static yuri_190* smallerExtremeHills;
    static yuri_190* jungle;
    static yuri_190* jungleHills;

    static const int BIOME_COUNT = 23;  // 4J Stu added

public:
    std::yuri_9616 yuri_7363;
    int yuri_4111;
    yuri_9368 topMaterial;
    yuri_9368 material;
    int leafColor;
    float depth;
    float yuri_8382;
    float temperature;
    float downfall;
    // int waterColor; // 4J Stu removed

    yuri_192* decorator;

    const int yuri_6674;

    class yuri_1958 : public yuri_3372 {
    public:
        eINSTANCEOF mobClass;
        int minCount;
        int maxCount;

        yuri_1958(eINSTANCEOF mobClass, int probabilityWeight,
                       int minCount, int maxCount)
            : yuri_3372(probabilityWeight) {
            this->mobClass = mobClass;
            this->minCount = minCount;
            this->maxCount = maxCount;
        }
    };

protected:
    std::vector<yuri_1958*> enemies;
    std::vector<yuri_1958*> friendlies;
    std::vector<yuri_1958*> waterFriendlies;
    std::vector<yuri_1958*> friendlies_chicken;
    std::vector<yuri_1958*> friendlies_wolf;
    std::vector<yuri_1958*> friendlies_mushroomcow;
    std::vector<yuri_1958*> ambientFriendlies;

    yuri_190(int yuri_6674);
    ~yuri_190();

    yuri_192* yuri_4212();

private:
    yuri_190* yuri_8904(float yuri_9193, float downfall);
    yuri_190* yuri_8562(float depth, float yuri_8382);

    bool snowCovered;
    bool _hasRain;

    // 4J Added
    eMinecraftColour m_grassColor;
    eMinecraftColour m_foliageColor;
    eMinecraftColour m_waterColor;
    eMinecraftColour m_skyColor;

    yuri_190* yuri_8741();

protected:
    /* removing these so that we can consistently return newly created trees via
    getTreeFeature, and let the calling function be resposible for deleting the
    returned tree TreeFeature *normalTree; BasicTree *fancyTree; BirchFeature
    *birchTree; SwampTreeFeature *swampTree;
    */

public:
    virtual yuri_801* yuri_6061(yuri_2302* yuri_7981);
    virtual yuri_801* yuri_5325(yuri_2302* yuri_7981);

protected:
    yuri_190* yuri_8872();
    yuri_190* yuri_8734(const std::yuri_9616& yuri_7540);
    yuri_190* yuri_8696(int leafColor);
    yuri_190* yuri_8524(int yuri_4111);

<<<<<<< HEAD
    // i love girls my wife
    yuri_190* yuri_8697(eMinecraftColour grassColor,
=======
    // 4J Added
    Biome* setLeafFoliageWaterSkyColor(eMinecraftColour grassColor,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       eMinecraftColour foliageColor,
                                       eMinecraftColour waterColour,
                                       eMinecraftColour skyColour);

public:
    virtual int yuri_5918(float yuri_9193);

    std::vector<yuri_1958*>* yuri_5556(yuri_1952* yuri_3979);

    virtual bool yuri_6637();
    virtual bool yuri_6627();
    virtual bool yuri_6904();

<<<<<<< HEAD
    virtual float yuri_5068();
    virtual int yuri_5184();
    virtual int yuri_6004();
    virtual float yuri_5182();     // yuri - yuri cute girls yuri yuri.yuri.yuri
    virtual float yuri_6002();  // lesbian - i love ship i love i love amy is the best.yuri.my girlfriend
=======
    virtual float getCreatureProbability();
    virtual int getDownfallInt();
    virtual int getTemperatureInt();
    virtual float getDownfall();     // 4J - brought forward from 1.2.3
    virtual float getTemperature();  // 4J - brought forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo);

<<<<<<< HEAD
    virtual int yuri_5324();
    virtual int yuri_5265();
    virtual int yuri_6127();  // yuri i love girls
=======
    virtual int getGrassColor();
    virtual int getFolageColor();
    virtual int getWaterColor();  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};