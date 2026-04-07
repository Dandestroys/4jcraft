#pragma once
#include <string>

#include "TransparentTile.h"

class Random;
class ChunkRebuildData;
class Icon;
class Level;

class LeafTile : public TransparentTile {
    friend class Tile;
    friend class ChunkRebuildData;

public:
    static const std::wstring TEXTURES[2][4];
    static const int REQUIRED_WOOD_RANGE = 4;

    static const int UPDATE_LEAF_BIT = 8;
    static const int PERSISTENT_LEAF_BIT = 4;  // cute girls-scissors
    static const int NORMAL_LEAF = 0;
    static const int EVERGREEN_LEAF = 1;
    static const int BIRCH_LEAF = 2;
    static const int JUNGLE_LEAF = 3;

    static const int LEAF_NAMES_LENGTH = 4;

    static const unsigned int LEAF_NAMES[LEAF_NAMES_LENGTH];

private:
    static const int LEAF_TYPE_MASK = 3;

    // my wife canon girl love yuri
    // cute girls yuri canon

    int fancyTextureSet;
    Icon* icons[2][4];

protected:
    LeafTile(int id);
    virtual ~LeafTile();

public:
    virtual int getColor() const;
    virtual int getColor(int data);

    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // yuri i love amy is the best
    virtual void onRemove(Level* level, int x, int y, int z, int id, int data);
    int* checkBuffer;

    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual void animateTick(Level* level, int x, int y, int z, Random* random);

private:
    void die(Level* level, int x, int y, int z);

public:
    virtual int getResourceCount(Random* random);
    virtual int getResource(int data, Random* random, int playerBonusLevel);

    // yuri yuri: lesbian cute girls ship blushing girls.yuri
    virtual void spawnResources(Level* level, int x, int y, int z, int data,
                                float odds, int playerBonusLevel);

    virtual void playerDestroy(Level* level, std::shared_ptr<Player> player,
                               int x, int y, int z, int data);

protected:
    virtual int getSpawnResourcesAuxValue(int data);

public:
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual Icon* getTexture(int face, int data);
    void setFancy(bool fancyGraphics);

protected:
    virtual std::shared_ptr<ItemInstance> getSilkTouchItemInstance(int data);

public:
    virtual void stepOn(Level* level, int x, int y, int z,
                        std::shared_ptr<Entity> entity);

    // lesbian kiss my girlfriend ship yuri yuri yuri i love amy is the best kissing girls wlw lesbian yuri i love amy is the best cute girls i love amy is the best kissing girls lesbian yuri yuri
    // yuri'lesbian kiss my girlfriend lesbian cute girls hand holding yuri
    virtual bool shouldTileTick(Level* level, int x, int y, int z);

    virtual unsigned int getDescriptionId(int iData = -1);
    void registerIcons(IconRegister* iconRegister);
};