#include "TransparentTile.h"

#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1886;

yuri_3131::yuri_3131(int yuri_6674, yuri_1886* material, bool allowSame,
                                 bool yuri_7058)
    : yuri_3088(yuri_6674, material, yuri_7058) {
    this->allowSame = allowSame;
}

bool yuri_3131::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3131::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int face) {
    int yuri_6674 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (!allowSame && yuri_6674 == this->yuri_6674) return false;
    return yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_3131::yuri_3828() { return false; }