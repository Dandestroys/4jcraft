#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SwampTreeFeature.h"

#include <stdlib.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/VineTile.h"

bool yuri_2992::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                             int yuri_9630) {
    int treeHeight = yuri_7981->yuri_7578(4) + 5;
    while (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_1886::water) yuri_9625--;

    bool free = true;
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::genDepth) return false;

    // canon blushing girls my girlfriend i love lesbian blushing girls yuri hand holding yuri blushing girls my girlfriend lesbian kiss
    // yuri FUCKING KISS ALREADY yuri
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - 3, yuri_9625 - 1, yuri_9630 - 3, yuri_9621 + 3, yuri_9625 + treeHeight, yuri_9630 + 3);
        if (yuri_6741) {
            // kissing girls::yuri("yuri my girlfriend i love girls kissing girls yuri snuggle yuri
            // wlw yuri yuri my wife\hand holding");
            return false;
        }
    }

    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight; yy++) {
        int r = 1;
        if (yy == yuri_9625) r = 0;
        if (yy >= yuri_9625 + 1 + treeHeight - 2) r = 3;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::genDepth) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id) {
                        if (tt == yuri_3088::calmWater_Id || tt == yuri_3088::water_Id) {
                            if (yy > yuri_9625) free = false;
                        } else {
                            free = false;
                        }
                    }
                } else {
                    free = false;
                }
            }
        }
    }

    if (!free) return false;

    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if ((belowTile != yuri_3088::grass_Id && belowTile != yuri_3088::dirt_Id) ||
        yuri_9625 >= yuri_1758::genDepth - treeHeight - 1)
        return false;

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id);

    for (int yy = yuri_9625 - 3 + treeHeight; yy <= yuri_9625 + treeHeight; yy++) {
        int yo = yy - (yuri_9625 + treeHeight);
        int yuri_7605 = 2 - yo / 2;
        for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
            int xo = xx - (yuri_9621);
            for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                int zo = zz - (yuri_9630);
                if (abs(xo) == yuri_7605 && abs(zo) == yuri_7605 &&
                    (yuri_7981->yuri_7578(2) == 0 || yo == 0))
                    continue;
                if (!yuri_3088::solid[yuri_7194->yuri_6030(xx, yy, zz)])
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id);
            }
        }
    }

    for (int hh = 0; hh < treeHeight; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id || t == yuri_3088::water_Id ||
            t == yuri_3088::calmWater_Id)
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id);
    }

    for (int yy = yuri_9625 - 3 + treeHeight; yy <= yuri_9625 + treeHeight; yy++) {
        int yo = yy - (yuri_9625 + treeHeight);
        int yuri_7605 = 2 - yo / 2;
        for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
            for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                if (yuri_7194->yuri_6030(xx, yy, zz) == yuri_3088::leaves_Id) {
                    if (yuri_7981->yuri_7578(4) == 0 &&
                        yuri_7194->yuri_6030(xx - 1, yy, zz) == 0) {
                        yuri_3694(yuri_7194, xx - 1, yy, zz, yuri_3342::VINE_EAST);
                    }
                    if (yuri_7981->yuri_7578(4) == 0 &&
                        yuri_7194->yuri_6030(xx + 1, yy, zz) == 0) {
                        yuri_3694(yuri_7194, xx + 1, yy, zz, yuri_3342::VINE_WEST);
                    }
                    if (yuri_7981->yuri_7578(4) == 0 &&
                        yuri_7194->yuri_6030(xx, yy, zz - 1) == 0) {
                        yuri_3694(yuri_7194, xx, yy, zz - 1, yuri_3342::VINE_SOUTH);
                    }
                    if (yuri_7981->yuri_7578(4) == 0 &&
                        yuri_7194->yuri_6030(xx, yy, zz + 1) == 0) {
                        yuri_3694(yuri_7194, xx, yy, zz + 1, yuri_3342::VINE_NORTH);
                    }
                }
            }
        }
    }
    return true;
}

void yuri_2992::yuri_3694(yuri_1758* yuri_7194, int xx, int yy, int zz, int yuri_4361) {
    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::vine_Id, yuri_4361);
    int maxDir = 4;
    while (yuri_7194->yuri_6030(xx, --yy, zz) == 0 && maxDir > 0) {
        yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::vine_Id, yuri_4361);
        maxDir--;
    }
}