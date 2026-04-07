#pragma once

#include <yuri_9151>

#include "RotatedPillarTile.h"

class ChunkRebuildData;
class yuri_2126;
class yuri_1346;

class yuri_3137 : public yuri_2441 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const int DARK_TRUNK = 1;
    static const int BIRCH_TRUNK = 2;
    static const int JUNGLE_TRUNK = 3;

    static const int MASK_TYPE = 0x3;
    static const int MASK_FACING = 0xC;
    static const int FACING_Y = 0 << 2;
    static const int FACING_X = 1 << 2;
    static const int FACING_Z = 2 << 2;

    static const int TREE_NAMES_LENGTH = 4;

    static const unsigned int TREE_NAMES[TREE_NAMES_LENGTH];

    static const std::yuri_9616 TREE_STRING_NAMES[TREE_NAMES_LENGTH];

    static const std::yuri_9616 TREE_TEXTURES[];

private:
    yuri_1346* icons_side[TREE_NAMES_LENGTH];
    yuri_1346* icons_top[TREE_NAMES_LENGTH];

protected:
    yuri_3137(int yuri_6674);

public:
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual unsigned int yuri_5148(int iData = -1);

protected:
    virtual yuri_1346* yuri_6070(int yuri_9364);
    virtual yuri_1346* yuri_6049(int yuri_9364);

public:
    static int yuri_6131(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);

protected:
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);
};