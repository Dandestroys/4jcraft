#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "BirchFeature.h"

#include <stdlib.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

yuri_197::yuri_197(bool doUpdate) : yuri_801(doUpdate) {}

bool yuri_197::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    int treeHeight = yuri_7981->yuri_7578(3) + 5;

    bool free = true;
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::maxBuildHeight) return false;

    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight; yy++) {
        int r = 1;
        if (yy == yuri_9625) r = 0;
        if (yy >= yuri_9625 + 1 + treeHeight - 2) r = 2;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::maxBuildHeight) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id) free = false;
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

<<<<<<< HEAD
    // wlw i love girls lesbian kiss my wife yuri i love amy is the best i love amy is the best hand holding i love girls ship yuri lesbian kiss
    // i love amy is the best my wife i love girls
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        int radius = 3;
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - radius, yuri_9625 - 1, yuri_9630 - radius, yuri_9621 + radius, yuri_9625 + treeHeight,
            yuri_9630 + radius);
        if (yuri_6741) {
            // my wife::yuri("hand holding my girlfriend yuri i love amy is the best yuri hand holding yuri
            // i love lesbian girl love FUCKING KISS ALREADY\ship");
=======
    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        int radius = 3;
        bool intersects = levelGenOptions->checkIntersects(
            x - radius, y - 1, z - radius, x + radius, y + treeHeight,
            z + radius);
        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id);

    for (int yy = yuri_9625 - 3 + treeHeight; yy <= yuri_9625 + treeHeight; yy++) {
        int yo = yy - (yuri_9625 + treeHeight);
        int yuri_7605 = 1 - yo / 2;
        for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
            int xo = xx - (yuri_9621);
            for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                int zo = zz - (yuri_9630);
                if (abs(xo) == yuri_7605 && abs(zo) == yuri_7605 &&
                    (yuri_7981->yuri_7578(2) == 0 || yo == 0))
                    continue;
                int t = yuri_7194->yuri_6030(xx, yy, zz);
                if (t == 0 || t == yuri_3088::leaves_Id)
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id,
                               yuri_1749::BIRCH_LEAF);
            }
        }
    }
    for (int hh = 0; hh < treeHeight; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id)
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id,
                       yuri_3137::BIRCH_TRUNK);
    }
    return true;
}