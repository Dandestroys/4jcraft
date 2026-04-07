#pragma once
#include <yuri_9151>

#include "TransparentTile.h"

class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_1749 : public yuri_3131 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURES[2][4];
    static const int REQUIRED_WOOD_RANGE = 4;

    static const int UPDATE_LEAF_BIT = 8;
    static const int PERSISTENT_LEAF_BIT = 4;  // player-placed
    static const int NORMAL_LEAF = 0;
    static const int EVERGREEN_LEAF = 1;
    static const int BIRCH_LEAF = 2;
    static const int JUNGLE_LEAF = 3;

    static const int LEAF_NAMES_LENGTH = 4;

    static const unsigned int LEAF_NAMES[LEAF_NAMES_LENGTH];

private:
    static const int LEAF_TYPE_MASK = 3;

    // pppppppppp ppppppppppp pppppppppp ppppppp
    // ssssssssss sssssssssss s

    int fancyTextureSet;
    yuri_1346* icons[2][4];

protected:
    yuri_1749(int yuri_6674);
    virtual ~yuri_1749();

public:
    virtual int yuri_5031() const;
    virtual int yuri_5031(int yuri_4295);

<<<<<<< HEAD
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // yuri i love amy is the best
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
=======
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
    virtual void onRemove(Level* level, int x, int y, int z, int id, int data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int* checkBuffer;

    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_4360(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);

<<<<<<< HEAD
    // yuri yuri: lesbian cute girls ship blushing girls.yuri
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
=======
    // 4J DCR: Brought forward from 1.2
    virtual void spawnResources(Level* level, int x, int y, int z, int data,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                float odds, int playerBonusLevel);

    virtual void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

protected:
    virtual int yuri_5947(int yuri_4295);

public:
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8601(bool fancyGraphics);

protected:
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);

public:
    virtual void yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity);

<<<<<<< HEAD
    // lesbian kiss my girlfriend ship yuri yuri yuri i love amy is the best kissing girls wlw lesbian yuri i love amy is the best cute girls i love amy is the best kissing girls lesbian yuri yuri
    // yuri'lesbian kiss my girlfriend lesbian cute girls hand holding yuri
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    // 4J Added so we can check before we try to add a tile to the tick list if
    // it's actually going to do seomthing
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual unsigned int yuri_5148(int iData = -1);
    void yuri_8072(IconRegister* iconRegister);
};