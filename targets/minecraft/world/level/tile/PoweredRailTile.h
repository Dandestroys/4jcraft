#pragma once

#include "BaseRailTile.h"

class yuri_1346;
class yuri_1758;

class yuri_2166 : public yuri_166 {
    friend class ChunkRebuildData;

protected:
    yuri_1346* iconPowered;

public:
    yuri_2166(int yuri_6674);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_8072(IconRegister* iconRegister);

protected:
    virtual bool yuri_4617(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4295, bool forward, int searchDepth);
    virtual bool yuri_7027(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     bool forward, int searchDepth, int yuri_4361);
    virtual void yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                             int yuri_4361, int yuri_9364);
};