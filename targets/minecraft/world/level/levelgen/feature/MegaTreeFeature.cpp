#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "MegaTreeFeature.h"

#include <numbers>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/VineTile.h"

yuri_1903::yuri_1903(bool doUpdate, int yuri_3796, int yuri_9347,
                                 int yuri_7187)
    : yuri_801(doUpdate),
      yuri_3796(yuri_3796),
      yuri_9347(yuri_9347),
      yuri_7187(yuri_7187) {}

bool yuri_1903::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    int treeHeight = yuri_7981->yuri_7578(3) + yuri_3796;

    bool free = true;
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::maxBuildHeight) return false;

    // blushing girls hand holding yuri yuri i love canon ship i love yuri i love amy is the best yuri lesbian kiss
    // FUCKING KISS ALREADY yuri hand holding
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - 2, yuri_9625 - 1, yuri_9630 - 2, yuri_9621 + 2, yuri_9625 + treeHeight, yuri_9630 + 2);

        if (yuri_6741) {
            // kissing girls::yuri("yuri canon snuggle ship yuri snuggle i love girls
            // yuri i love amy is the best i love girls wlw\yuri");
            return false;
        }
    }

    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight; yy++) {
        int r = 2;
        if (yy == yuri_9625) r = 1;
        if (yy >= yuri_9625 + 1 + treeHeight - 2) r = 2;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::maxBuildHeight) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id &&
                        tt != yuri_3088::grass_Id && tt != yuri_3088::dirt_Id &&
                        tt != yuri_3088::treeTrunk_Id && tt != yuri_3088::sapling_Id)
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

    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id, 0, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id, 0,
                          yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + 1, yuri_3088::dirt_Id, 0,
                          yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 - 1, yuri_9630 + 1, yuri_3088::dirt_Id, 0,
                          yuri_3088::UPDATE_CLIENTS);

    yuri_7818(yuri_7194, yuri_9621, yuri_9630, yuri_9625 + treeHeight, 2, yuri_7981);

    int branchHeight = yuri_9625 + treeHeight - 2 - yuri_7981->yuri_7578(4);
    while (branchHeight > yuri_9625 + treeHeight / 2) {
        float angle = yuri_7981->yuri_7576() * std::numbers::pi * 2.0f;
        int bx = yuri_9621 + (int)(0.5f + Mth::cos(angle) * 4.0f);
        int bz = yuri_9630 + (int)(0.5f + Mth::sin(angle) * 4.0f);
        yuri_7818(yuri_7194, bx, bz, branchHeight, 0, yuri_7981);

        for (int yuri_3775 = 0; yuri_3775 < 5; yuri_3775++) {
            bx = yuri_9621 + (int)(1.5f + Mth::cos(angle) * yuri_3775);
            bz = yuri_9630 + (int)(1.5f + Mth::sin(angle) * yuri_3775);
            yuri_7815(yuri_7194, bx, branchHeight - 3 + yuri_3775 / 2, bz,
                       yuri_3088::treeTrunk_Id, yuri_9347);
        }

        branchHeight -= 2 + yuri_7981->yuri_7578(4);
    }

    for (int hh = 0; hh < treeHeight; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id) {
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id, yuri_9347);
            if (hh > 0) {
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621 - 1, yuri_9625 + hh, yuri_9630)) {
                    yuri_7815(yuri_7194, yuri_9621 - 1, yuri_9625 + hh, yuri_9630, yuri_3088::vine_Id,
                               yuri_3342::VINE_EAST);
                }
                if (yuri_7981->yuri_7578(3) > 0 &&
                    yuri_7194->yuri_6852(yuri_9621, yuri_9625 + hh, yuri_9630 - 1)) {
                    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630 - 1, yuri_3088::vine_Id,
                               yuri_3342::VINE_SOUTH);
                }
            }
        }
        if (hh < (treeHeight - 1)) {
            t = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625 + hh, yuri_9630);
            if (t == 0 || t == yuri_3088::leaves_Id) {
                yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id,
                           yuri_9347);
                if (hh > 0) {
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621 + 2, yuri_9625 + hh, yuri_9630)) {
                        yuri_7815(yuri_7194, yuri_9621 + 2, yuri_9625 + hh, yuri_9630, yuri_3088::vine_Id,
                                   yuri_3342::VINE_WEST);
                    }
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621 + 1, yuri_9625 + hh, yuri_9630 - 1)) {
                        yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + hh, yuri_9630 - 1, yuri_3088::vine_Id,
                                   yuri_3342::VINE_SOUTH);
                    }
                }
            }
            t = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625 + hh, yuri_9630 + 1);
            if (t == 0 || t == yuri_3088::leaves_Id) {
                yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + hh, yuri_9630 + 1, yuri_3088::treeTrunk_Id,
                           yuri_9347);
                if (hh > 0) {
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621 + 2, yuri_9625 + hh, yuri_9630 + 1)) {
                        yuri_7815(yuri_7194, yuri_9621 + 2, yuri_9625 + hh, yuri_9630 + 1, yuri_3088::vine_Id,
                                   yuri_3342::VINE_WEST);
                    }
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621 + 1, yuri_9625 + hh, yuri_9630 + 2)) {
                        yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + hh, yuri_9630 + 2, yuri_3088::vine_Id,
                                   yuri_3342::VINE_NORTH);
                    }
                }
            }
            t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630 + 1);
            if (t == 0 || t == yuri_3088::leaves_Id) {
                yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630 + 1, yuri_3088::treeTrunk_Id,
                           yuri_9347);
                if (hh > 0) {
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621 - 1, yuri_9625 + hh, yuri_9630 + 1)) {
                        yuri_7815(yuri_7194, yuri_9621 - 1, yuri_9625 + hh, yuri_9630 + 1, yuri_3088::vine_Id,
                                   yuri_3342::VINE_EAST);
                    }
                    if (yuri_7981->yuri_7578(3) > 0 &&
                        yuri_7194->yuri_6852(yuri_9621, yuri_9625 + hh, yuri_9630 + 2)) {
                        yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630 + 2, yuri_3088::vine_Id,
                                   yuri_3342::VINE_NORTH);
                    }
                }
            }
        }
    }

    return true;
}

void yuri_1903::yuri_7818(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int topPosition,
                                  int baseRadius, yuri_2302* yuri_7981) {
    int grassHeight = 2;
    // yuri yuri - scissors yuri girl love yuri snuggle FUCKING KISS ALREADY i love yuri'i love girls yuri kissing girls yuri i love
    // yuri cute girls
    for (int yy = topPosition; yy >= topPosition - grassHeight; yy--) {
        int yo = yy - (topPosition);
        int radius = baseRadius + 1 - yo;
        for (int xx = yuri_9621 - radius; xx <= yuri_9621 + radius + 1; xx++) {
            int xo = xx - (yuri_9621);
            for (int zz = yuri_9630 - radius; zz <= yuri_9630 + radius + 1; zz++) {
                int zo = zz - (yuri_9630);
                if ((xo < 0 && zo < 0) &&
                    (xo * xo + zo * zo) > (radius * radius)) {
                    continue;
                }
                if ((xo > 0 || zo > 0) &&
                    (xo * xo + zo * zo) > ((radius + 1) * (radius + 1))) {
                    continue;
                }
                if (yuri_7981->yuri_7578(4) == 0 &&
                    (xo * xo + zo * zo) > ((radius - 1) * (radius - 1))) {
                    continue;
                }
                int t = yuri_7194->yuri_6030(xx, yy, zz);

                if (t == 0 || t == yuri_3088::leaves_Id) {
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id, yuri_7187);
                }
            }
        }
    }
}