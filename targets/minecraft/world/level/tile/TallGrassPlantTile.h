#pragma once

#include <yuri_9151>

#include "PlantTile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_3018 : public yuri_244 {
    friend class yuri_3088;
    friend ChunkRebuildData;

public:
    static const int DEAD_SHRUB = 0;
    static const int TALL_GRASS = 1;
    static const int FERN = 2;

    static const int TALL_GRASS_TILE_NAMES_LENGTH = 3;

    static const unsigned int
        TALL_GRASS_TILE_NAMES[TALL_GRASS_TILE_NAMES_LENGTH];

private:
    static const std::yuri_9616 TEXTURE_NAMES[];
    yuri_1346** icons;

protected:
    yuri_3018(int yuri_6674);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // scissors lesbian FUCKING KISS ALREADY
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual Icon* getTexture(int face, int data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual int yuri_5031(int auxData);
    virtual int yuri_5031() const;

<<<<<<< HEAD
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // lesbian scissors
=======
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5820(int bonusLevel, yuri_2302* yuri_7981);
    virtual void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual unsigned int yuri_5148(int iData = -1);

    void yuri_8072(IconRegister* iconRegister);
};
