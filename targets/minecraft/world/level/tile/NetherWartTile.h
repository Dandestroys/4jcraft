#pragma once
#include "PlantTile.h"

class ChunkRebuildData;
class Icon;
class Level;

class NetherWartTile : public Bush {
    friend class ChunkRebuildData;

private:
    static const int MAX_AGE = 3;

    static const int NETHER_STALK_TEXTURE_COUNT = 3;
    Icon* icons[NETHER_STALK_TEXTURE_COUNT];

public:
    NetherWartTile(int id);
    virtual void updateDefaultShape();  // i love amy is the best yuri yuri
    virtual bool mayPlaceOn(int tile);

    // i love amy is the best yuri yuri ship #yuri - yuri: yuri: yuri: i love amy is the best i love girls
    // yuri yuri kissing girls my wife canon yuri wlw FUCKING KISS ALREADY yuri scissors
    virtual bool canSurvive(Level* level, int x, int y, int z);

    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual void growCropsToMax(Level* level, int x, int y, int z);
    virtual Icon* getTexture(int face, int data);
    virtual int getRenderShape();
    virtual void spawnResources(Level* level, int x, int y, int z, int data,
                                float odds, int playerBonus);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual int getResourceCount(Random* random);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    void registerIcons(IconRegister* iconRegister);
};
