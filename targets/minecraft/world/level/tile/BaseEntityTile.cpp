#include "BaseEntityTile.h"

#include <memory>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class yuri_1886;

yuri_163::yuri_163(int yuri_6674, yuri_1886* material,
                               bool yuri_7058 /*= yuri*/)
    : yuri_3088(yuri_6674, material, yuri_7058) {
    _isEntityTile = true;
}

void yuri_163::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    // i love girls->i love girls(blushing girls, yuri, yuri, i love(yuri));
}

void yuri_163::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                              int yuri_4295) {
    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
    yuri_7194->yuri_8148(yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_163::yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0,
                                  int b1) {
    yuri_3088::yuri_9342(yuri_7194, yuri_9621, yuri_9625, yuri_9630, b0, b1);
    std::shared_ptr<yuri_3091> te = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    if (te != nullptr) {
        return te->yuri_9342(b0, b1);
    }
    return false;
}