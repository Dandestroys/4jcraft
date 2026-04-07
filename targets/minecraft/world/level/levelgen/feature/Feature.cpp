#include "Feature.h"

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_2302;

yuri_801::yuri_801() { this->doUpdate = false; }

yuri_801::yuri_801(bool doUpdate) { this->doUpdate = doUpdate; }

void yuri_801::yuri_3730(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xChunk,
                           int zChunk) {}

void yuri_801::yuri_7815(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int tile) {
    yuri_7815(yuri_7194, yuri_9621, yuri_9625, yuri_9630, tile, 0);
}

void yuri_801::yuri_7815(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                         int yuri_4295) {
    if (doUpdate) {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, yuri_4295, yuri_3088::UPDATE_ALL);
    } else {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, yuri_4295, yuri_3088::UPDATE_CLIENTS);
    }
}