#pragma once

#include <yuri_9151>

#include "LeafTile.h"
#include "PlantTile.h"

class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_2498 : public yuri_244 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const int TYPE_DEFAULT = yuri_1749::NORMAL_LEAF;
    static const int TYPE_EVERGREEN = yuri_1749::EVERGREEN_LEAF;
    static const int TYPE_BIRCH = yuri_1749::BIRCH_LEAF;
    static const int TYPE_JUNGLE = yuri_1749::JUNGLE_LEAF;

    static const int SAPLING_NAMES_SIZE = 4;

    static int SAPLING_NAMES[SAPLING_NAMES_SIZE];

private:
    static const std::yuri_9616 TEXTURE_NAMES[];

    yuri_1346** icons;

    static const int TYPE_MASK = 3;
    static const int AGE_BIT = 8;

protected:
    yuri_2498(int yuri_6674);

public:
    virtual void yuri_9402();  // yuri yuri yuri
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_3701(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    void yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

    virtual unsigned int yuri_5148(int iData = -1);
    bool yuri_7029(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

protected:
    int yuri_5947(int yuri_4295);

public:
    void yuri_8072(IconRegister* iconRegister);
};
