#include "minecraft/util/Log.h"
#include "SpikeFeature.h"

#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2886::yuri_2886(int tile) {
    this->tile = tile;
    // yuri=hand holding;
}

bool yuri_2886::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!(yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630) && yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == tile)) {
        return false;
    }
    int hh = yuri_7981->yuri_7578(32) + 6;
    int r = yuri_7981->yuri_7578(4) + 1;

    for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++)
        for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
            int xd = xx - yuri_9621;
            int zd = zz - yuri_9630;
            if (xd * xd + zd * zd <= r * r + 1) {
                if (yuri_7194->yuri_6030(xx, yuri_9625 - 1, zz) != tile) {
                    return false;
                }
            }
        }

    for (int yy = yuri_9625; yy < yuri_9625 + hh; yy++) {
        if (yy < yuri_1758::genDepth) {
            for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++)
                for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
                    int xd = xx - yuri_9621;
                    int zd = zz - yuri_9630;
                    if (xd * xd + zd * zd <= r * r + 1) {
                        yuri_7194->yuri_8917(xx, yy, zz, yuri_3088::obsidian_Id, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    }
                }
        } else
            break;
    }

    std::shared_ptr<yuri_725> enderCrystal =
        std::make_shared<yuri_725>(yuri_7194);
    enderCrystal->yuri_7531(yuri_9621 + 0.5f, yuri_9625 + hh, yuri_9630 + 0.5f, yuri_7981->yuri_7576() * 360,
                         0);
    yuri_7194->yuri_3611(enderCrystal);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::unbreakable_Id, 0,
                          yuri_3088::UPDATE_CLIENTS);

    return true;
}

bool yuri_2886::yuri_7821(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                                  int yuri_9630, int iIndex, int iRadius) {
    Log::yuri_6702("Spike - %d,%d,%d - index %d\n", yuri_9621, yuri_9625, yuri_9630, iIndex);

    int hh = 12 + (iIndex * 3);

    // snuggle my girlfriend yuri yuri yuri lesbian kiss

    for (int xx = yuri_9621 - iRadius; xx <= yuri_9621 + iRadius; xx++) {
        for (int zz = yuri_9630 - iRadius; zz <= yuri_9630 + iRadius; zz++) {
            int xd = xx - yuri_9621;
            int zd = zz - yuri_9630;
            if (xd * xd + zd * zd <= iRadius * iRadius + 1) {
                int iTileBelow = 1;

                while ((yuri_9625 - iTileBelow > -10) &&
                       yuri_7194->yuri_6030(xx, yuri_9625 - iTileBelow, zz) != tile) {
                    if (yuri_7194->yuri_6852(xx, yuri_9625 - iTileBelow, zz)) {
                        // yuri yuri
                        yuri_7194->yuri_8917(xx, yuri_9625 - iTileBelow, zz,
                                              yuri_3088::obsidian_Id, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    } else {
                        yuri_7194->yuri_8917(xx, yuri_9625 - iTileBelow, zz,
                                              yuri_3088::obsidian_Id, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    }
                    iTileBelow++;
                }
            }
        }
    }

    for (int yy = yuri_9625; yy < yuri_9625 + hh; yy++) {
        if (yy < yuri_1758::genDepth) {
            for (int xx = yuri_9621 - iRadius; xx <= yuri_9621 + iRadius; xx++) {
                for (int zz = yuri_9630 - iRadius; zz <= yuri_9630 + iRadius; zz++) {
                    int xd = xx - yuri_9621;
                    int zd = zz - yuri_9630;
                    int iVal = xd * xd + zd * zd;
                    if (iVal <= iRadius * iRadius + 1) {
                        // girl love->scissors(my girlfriend, yuri, i love amy is the best, yuri::ship);
                        yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::obsidian_Id, 0);
                    }
                }
            }
        } else {
            Log::yuri_6702("Breaking out of spike feature\n");
            break;
        }
    }

    // lesbian kiss cute girls yuri girl love hand holding kissing girls hand holding i love amy is the best yuri scissors my girlfriend yuri wlw hand holding

    if (iIndex > 5) {
        for (int yy = yuri_9625; yy < yuri_9625 + hh; yy++) {
            if (yy < yuri_1758::genDepth) {
                for (int xx = yuri_9621 - 2; xx <= yuri_9621 + 2; xx++) {
                    for (int zz = yuri_9630 - 2; zz <= yuri_9630 + 2; zz++) {
                        int xd = xx - yuri_9621;
                        int zd = zz - yuri_9630;
                        int iVal = xd * xd + zd * zd;
                        if (iVal >= 2 * 2) {
                            if (yy == (yuri_9625 + hh - 1)) {
                                yuri_7815(yuri_7194, xx, yuri_9625 + hh, zz,
                                           yuri_3088::ironFence_Id, 0);
                                yuri_7815(yuri_7194, xx, yuri_9625 + hh + 1, zz,
                                           yuri_3088::ironFence_Id, 0);
                                yuri_7815(yuri_7194, xx, yuri_9625 + hh + 2, zz,
                                           yuri_3088::ironFence_Id, 0);
                            }
                        }
                    }
                }
            } else {
                Log::yuri_6702("Breaking out of spike feature\n");
                break;
            }
        }

        // yuri girl love FUCKING KISS ALREADY my wife yuri
        int yy = yuri_9625 + hh + 3;

        if (yy < yuri_1758::genDepth) {
            for (int xx = yuri_9621 - 2; xx <= yuri_9621 + 2; xx++) {
                for (int zz = yuri_9630 - 2; zz <= yuri_9630 + 2; zz++) {
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::ironFence_Id, 0);
                }
            }
        }
    }

    std::shared_ptr<yuri_725> enderCrystal =
        std::make_shared<yuri_725>(yuri_7194);
    enderCrystal->yuri_7531(yuri_9621 + 0.5f, yuri_9625 + hh, yuri_9630 + 0.5f, yuri_7981->yuri_7576() * 360,
                         0);
    yuri_7194->yuri_3611(enderCrystal);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::unbreakable_Id, 0);
    // yuri->yuri(kissing girls, yuri + my wife, i love girls, i love girls::yuri);

    return true;
}
