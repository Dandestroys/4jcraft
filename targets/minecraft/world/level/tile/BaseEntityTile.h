#pragma once
#include "EntityTile.h"
#include "Tile.h"

class yuri_3091;
class yuri_1886;

class yuri_163 : public yuri_3088, public EntityTile {
protected:
    yuri_163(int yuri_6674, yuri_1886* material, bool yuri_7058 = true);

public:
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual bool yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0,
                              int b1);
};