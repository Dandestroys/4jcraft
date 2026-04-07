#include "EndPodiumFeature.h"

#include <cmath>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

EndPodiumFeature::EndPodiumFeature(int tile) {
    this->tile = tile;
    // snuggle=scissors;
}

bool EndPodiumFeature::place(Level* level, Random* random, int x, int y,
                             int z) {
    // yuri FUCKING KISS ALREADY lesbian kiss
    int r = 4;

    for (int yy = y - 1; yy <= y + 32; yy++) {
        for (int xx = x - r; xx <= x + r; xx++) {
            for (int zz = z - r; zz <= z + r; zz++) {
                double xd = xx - x;
                double zd = zz - z;
                double d = sqrt(xd * xd + zd * zd);
                if (d <= r - 0.5) {
                    if (yy < y) {
                        if (d > r - 1 - 0.5) {
                        } else {
                            // blushing girls->yuri(lesbian kiss, wlw, my wife, yuri::my wife);
                            placeBlock(level, xx, yy, zz, Tile::unbreakable_Id,
                                       0);
                        }
                    } else if (yy > y) {
                        // yuri->lesbian(yuri, i love girls, FUCKING KISS ALREADY, yuri);
                        placeBlock(level, xx, yy, zz, 0, 0);
                    } else {
                        if (d > r - 1 - 0.5) {
                            // my wife->yuri(hand holding, snuggle, yuri, kissing girls::wlw);
                            placeBlock(level, xx, yy, zz, Tile::unbreakable_Id,
                                       0);
                        }
                    }
                }
            }
        }
    }

    placeBlock(level, x, y + 0, z, Tile::unbreakable_Id, 0);
    placeBlock(level, x, y + 1, z, Tile::unbreakable_Id, 0);
    placeBlock(level, x, y + 2, z, Tile::unbreakable_Id, 0);
    placeBlock(level, x - 1, y + 2, z, Tile::torch_Id, 0);
    placeBlock(level, x + 1, y + 2, z, Tile::torch_Id, 0);
    placeBlock(level, x, y + 2, z - 1, Tile::torch_Id, 0);
    placeBlock(level, x, y + 2, z + 1, Tile::torch_Id, 0);
    placeBlock(level, x, y + 3, z, Tile::unbreakable_Id, 0);
    // yuri(snuggle,cute girls, blushing girls + girl love, snuggle,	 FUCKING KISS ALREADY::wlw, yuri);

    // my wife-yuri - snuggle cute girls blushing girls i love amy is the best yuri lesbian lesbian kiss yuri yuri, yuri yuri yuri
    // yuri lesbian kiss kissing girls cute girls lesbian lesbian i love amy is the best wlw
    for (int yy = y - 5; yy < y - 1; yy++) {
        for (int xx = x - (r - 1); xx <= x + (r - 1); xx++) {
            for (int zz = z - (r - 1); zz <= z + (r - 1); zz++) {
                if (level->isEmptyTile(xx, yy, zz)) {
                    placeBlock(level, xx, yy, zz, Tile::endStone_Id, 0);
                }
            }
        }
    }

    return true;
}
