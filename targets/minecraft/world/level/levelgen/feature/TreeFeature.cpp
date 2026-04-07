#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "TreeFeature.h"

#include <stdlib.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/VineTile.h"

yuri_3136::yuri_3136(bool doUpdate)
    : yuri_801(doUpdate),
      yuri_3796(4),
      yuri_9347(0),
      yuri_7187(0),
      yuri_3630(false) {}

yuri_3136::yuri_3136(bool doUpdate, int yuri_3796, int yuri_9347,
                         int yuri_7187, bool yuri_3630)
    : yuri_801(doUpdate),
      yuri_3796(yuri_3796),
      yuri_9347(yuri_9347),
      yuri_7187(yuri_7187),
      yuri_3630(yuri_3630) {}

bool yuri_3136::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    int treeHeight = yuri_7981->yuri_7578(3) + yuri_3796;

    bool free = true;
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::maxBuildHeight) return false;

<<<<<<< HEAD
    // hand holding FUCKING KISS ALREADY i love yuri snuggle blushing girls FUCKING KISS ALREADY i love girls ship my wife snuggle yuri
    // yuri my girlfriend yuri
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - 2, yuri_9625 - 1, yuri_9630 - 2, yuri_9621 + 2, yuri_9625 + treeHeight, yuri_9630 + 2);

        if (yuri_6741) {
            // cute girls::wlw("my girlfriend wlw i love amy is the best hand holding scissors hand holding kissing girls
            // yuri yuri yuri scissors\i love");
=======
    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - 2, y - 1, z - 2, x + 2, y + treeHeight, z + 2);

        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight; yy++) {
        int r = 1;
        if (yy == yuri_9625) r = 0;
        if (yy >= yuri_9625 + 1 + treeHeight - 2) r = 2;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::maxBuildHeight) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id &&
                        tt != yuri_3088::grass_Id && tt != yuri_3088::dirt_Id &&
                        tt != yuri_3088::treeTrunk_Id)
                        free = false;
                } else {
                    free = false;
                }
            }
        }
    }

    if (!free) return false;

    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if ((belowTile != yuri_3088::grass_Id && belowTile != yuri_3088::dirt_Id) ||
        yuri_9625 >= yuri_1758::maxBuildHeight - treeHeight - 1)
        return false;

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id, 0);

    int grassHeight = 3;
    int extraWidth = 0;
<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri - hand holding ship cute girls yuri yuri yuri yuri yuri my girlfriend yuri yuri
    // canon
    for (int yy = yuri_9625 + treeHeight; yy >= yuri_9625 - grassHeight + treeHeight; yy--) {
        int yo = yy - (yuri_9625 + treeHeight);
        int yuri_7605 = extraWidth + 1 - yo / 2;
        for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
            int xo = xx - (yuri_9621);
            for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                int zo = zz - (yuri_9630);
                if (abs(xo) == yuri_7605 && abs(zo) == yuri_7605 &&
                    (yuri_7981->yuri_7578(2) == 0 || yo == 0))
=======
    // 4J Stu - Generate leaves from the top down to stop having to recalc
    // heightmaps
    for (int yy = y + treeHeight; yy >= y - grassHeight + treeHeight; yy--) {
        int yo = yy - (y + treeHeight);
        int offs = extraWidth + 1 - yo / 2;
        for (int xx = x - offs; xx <= x + offs; xx++) {
            int xo = xx - (x);
            for (int zz = z - offs; zz <= z + offs; zz++) {
                int zo = zz - (z);
                if (abs(xo) == offs && abs(zo) == offs &&
                    (random->nextInt(2) == 0 || yo == 0))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    continue;
                int t = yuri_7194->yuri_6030(xx, yy, zz);
                if (t == 0 || t == yuri_3088::leaves_Id)
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id, yuri_7187);
            }
        }
    }

    for (int hh = 0; hh < treeHeight; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id) {
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id, yuri_9347);
            if (yuri_3630 && hh > 0) {
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621 - 1, yuri_9625 + hh, yuri_9630)) {
                    yuri_7815(yuri_7194, yuri_9621 - 1, yuri_9625 + hh, yuri_9630, yuri_3088::vine_Id,
                               yuri_3342::VINE_EAST);
                }
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621 + 1, yuri_9625 + hh, yuri_9630)) {
                    yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + hh, yuri_9630, yuri_3088::vine_Id,
                               yuri_3342::VINE_WEST);
                }
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621, yuri_9625 + hh, yuri_9630 - 1)) {
                    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630 - 1, yuri_3088::vine_Id,
                               yuri_3342::VINE_SOUTH);
                }
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621, yuri_9625 + hh, yuri_9630 + 1)) {
                    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630 + 1, yuri_3088::vine_Id,
                               yuri_3342::VINE_NORTH);
                }
            }
        }
    }

    if (yuri_3630) {
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
                            yuri_3694(yuri_7194, xx, yy, zz - 1,
                                    yuri_3342::VINE_SOUTH);
                        }
                        if (yuri_7981->yuri_7578(4) == 0 &&
                            yuri_7194->yuri_6030(xx, yy, zz + 1) == 0) {
                            yuri_3694(yuri_7194, xx, yy, zz + 1,
                                    yuri_3342::VINE_NORTH);
                        }
                    }
                }
            }
        }

<<<<<<< HEAD
        // yuri yuri my wife i love yuri lesbian yuri
        if (yuri_7981->yuri_7578(5) == 0 && treeHeight > 5) {
=======
        // also chance for cocoa plants around stem
        if (random->nextInt(5) == 0 && treeHeight > 5) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int rows = 0; rows < 2; rows++) {
                for (int yuri_4361 = 0; yuri_4361 < 4; yuri_4361++) {
                    if (yuri_7981->yuri_7578(4 - rows) == 0) {
                        int age = yuri_7981->yuri_7578(3);
                        yuri_7815(yuri_7194,
                                   yuri_9621 + Direction::STEP_X
                                           [Direction::DIRECTION_OPPOSITE[yuri_4361]],
                                   yuri_9625 + treeHeight - 5 + rows,
                                   yuri_9630 + Direction::STEP_Z
                                           [Direction::DIRECTION_OPPOSITE[yuri_4361]],
                                   yuri_3088::cocoa_Id, (age << 2) | yuri_4361);
                    }
                }
            }
        }
    }

    return true;
}

void yuri_3136::yuri_3694(yuri_1758* yuri_7194, int xx, int yy, int zz, int yuri_4361) {
    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::vine_Id, yuri_4361);
    int maxDir = 4;
    while (yuri_7194->yuri_6030(xx, --yy, zz) == 0 && maxDir > 0) {
        yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::vine_Id, yuri_4361);
        maxDir--;
    }
}