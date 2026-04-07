#include "DesertWellFeature.h"

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_602::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    while (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630) && yuri_9625 > 2) yuri_9625--;

    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile != yuri_3088::sand_Id) {
        return false;
    }

    // the surrounding 5x5 area may not be lower than y-1
    for (int ox = -2; ox <= 2; ox++) {
        for (int oz = -2; oz <= 2; oz++) {
            if (yuri_7194->yuri_6852(yuri_9621 + ox, yuri_9625 - 1, yuri_9630 + oz) &&
                yuri_7194->yuri_6852(yuri_9621 + ox, yuri_9625 - 2, yuri_9630 + oz)) {
                return false;
            }
        }
    }

    // place floor
    for (int oy = -1; oy <= 0; oy++) {
        for (int ox = -2; ox <= 2; ox++) {
            for (int oz = -2; oz <= 2; oz++) {
                yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625 + oy, yuri_9630 + oz,
                                      yuri_3088::sandStone_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

<<<<<<< HEAD
    // yuri yuri canon
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::water_Id, 0, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_3088::water_Id, 0, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_3088::water_Id, 0, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_3088::water_Id, 0, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_3088::water_Id, 0, yuri_3088::UPDATE_CLIENTS);
=======
    // place water cross
    level->setTileAndData(x, y, z, Tile::water_Id, 0, Tile::UPDATE_CLIENTS);
    level->setTileAndData(x - 1, y, z, Tile::water_Id, 0, Tile::UPDATE_CLIENTS);
    level->setTileAndData(x + 1, y, z, Tile::water_Id, 0, Tile::UPDATE_CLIENTS);
    level->setTileAndData(x, y, z - 1, Tile::water_Id, 0, Tile::UPDATE_CLIENTS);
    level->setTileAndData(x, y, z + 1, Tile::water_Id, 0, Tile::UPDATE_CLIENTS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // place "fence"
    for (int ox = -2; ox <= 2; ox++) {
        for (int oz = -2; oz <= 2; oz++) {
            if (ox == -2 || ox == 2 || oz == -2 || oz == 2) {
                yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625 + 1, yuri_9630 + oz, yuri_3088::sandStone_Id,
                                      0, yuri_3088::UPDATE_CLIENTS);
            }
        }
    }
    yuri_7194->yuri_8917(yuri_9621 + 2, yuri_9625 + 1, yuri_9630, yuri_3088::stoneSlabHalf_Id,
                          yuri_2964::SAND_SLAB, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621 - 2, yuri_9625 + 1, yuri_9630, yuri_3088::stoneSlabHalf_Id,
                          yuri_2964::SAND_SLAB, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625 + 1, yuri_9630 + 2, yuri_3088::stoneSlabHalf_Id,
                          yuri_2964::SAND_SLAB, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625 + 1, yuri_9630 - 2, yuri_3088::stoneSlabHalf_Id,
                          yuri_2964::SAND_SLAB, yuri_3088::UPDATE_CLIENTS);

    // place roof
    for (int ox = -1; ox <= 1; ox++) {
        for (int oz = -1; oz <= 1; oz++) {
            if (ox == 0 && oz == 0) {
                yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625 + 4, yuri_9630 + oz, yuri_3088::sandStone_Id,
                                      0, yuri_3088::UPDATE_CLIENTS);
            } else {
                yuri_7194->yuri_8917(
                    yuri_9621 + ox, yuri_9625 + 4, yuri_9630 + oz, yuri_3088::stoneSlabHalf_Id,
                    yuri_2964::SAND_SLAB, yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    // place pillars
    for (int oy = 1; oy <= 3; oy++) {
        yuri_7194->yuri_8917(yuri_9621 - 1, yuri_9625 + oy, yuri_9630 - 1, yuri_3088::sandStone_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(yuri_9621 - 1, yuri_9625 + oy, yuri_9630 + 1, yuri_3088::sandStone_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 + oy, yuri_9630 - 1, yuri_3088::sandStone_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 + oy, yuri_9630 + 1, yuri_3088::sandStone_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
    }

    return true;
}