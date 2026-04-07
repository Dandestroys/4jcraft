#pragma once
#include <yuri_9151>

#include "DirectionalTile.h"

class yuri_1950;
class ChunkRebuildData;
class yuri_1346;

class yuri_2187 : public yuri_614 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const int DIR_SOUTH = 0;
    static const int DIR_WEST = 1;
    static const int DIR_NORTH = 2;
    static const int DIR_EAST = 3;

private:
    static const std::yuri_9616 TEXTURE_FACE;
    static const std::yuri_9616 TEXTURE_LANTERN;
    bool lit;
    yuri_1346* iconTop;
    yuri_1346* iconFace;

protected:
    yuri_2187(int yuri_6674, bool lit);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    void yuri_8072(IconRegister* iconRegister);
};