#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "PineFeature.h"

#include <stdlib.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

<<<<<<< HEAD
bool yuri_2115::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri cute girls FUCKING KISS ALREADY yuri yuri
    int treeHeight = yuri_7981->yuri_7578(5) + 7;
    int trunkHeight = treeHeight - yuri_7981->yuri_7578(2) - 3;
=======
bool PineFeature::place(Level* level, Random* random, int x, int y, int z) {
    // pines can be quite tall
    int treeHeight = random->nextInt(5) + 7;
    int trunkHeight = treeHeight - random->nextInt(2) - 3;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int topHeight = treeHeight - trunkHeight;
    int topRadius = 1 + yuri_7981->yuri_7578(topHeight + 1);

    bool free = true;
<<<<<<< HEAD
    // lesbian my wife my girlfriend kissing girls kissing girls yuri wlw
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::genDepth) {
        return false;
    }

    // my wife i love amy is the best lesbian kiss kissing girls ship kissing girls yuri FUCKING KISS ALREADY i love amy is the best yuri yuri yuri
    // kissing girls FUCKING KISS ALREADY yuri
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - topRadius, yuri_9625 - 1, yuri_9630 - topRadius, yuri_9621 + topRadius, yuri_9625 + treeHeight,
            yuri_9630 + topRadius);
        if (yuri_6741) {
            // yuri::my girlfriend("yuri kissing girls girl love hand holding ship canon kissing girls
            // canon yuri yuri i love amy is the best\yuri");
=======
    // may not be outside of y boundaries
    if (y < 1 || y + treeHeight + 1 > Level::genDepth) {
        return false;
    }

    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - topRadius, y - 1, z - topRadius, x + topRadius, y + treeHeight,
            z + topRadius);
        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

<<<<<<< HEAD
    // girl love yuri blushing girls yuri yuri yuri
    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight && free; yy++) {
=======
    // make sure there is enough space
    for (int yy = y; yy <= y + 1 + treeHeight && free; yy++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int r = 1;
        if ((yy - yuri_9625) < trunkHeight) {
            r = 0;
        } else {
            r = topRadius;
        }
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::genDepth) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id) free = false;
                } else {
                    free = false;
                }
            }
        }
    }

    if (!free) return false;

<<<<<<< HEAD
    // snuggle yuri snuggle yuri
    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if ((belowTile != yuri_3088::grass_Id && belowTile != yuri_3088::dirt_Id) ||
        yuri_9625 >= yuri_1758::genDepth - treeHeight - 1)
=======
    // must stand on ground
    int belowTile = level->getTile(x, y - 1, z);
    if ((belowTile != Tile::grass_Id && belowTile != Tile::dirt_Id) ||
        y >= Level::genDepth - treeHeight - 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id);

    // place leaf top
    int currentRadius = 0;
    for (int yy = yuri_9625 + treeHeight; yy >= yuri_9625 + trunkHeight; yy--) {
        for (int xx = yuri_9621 - currentRadius; xx <= yuri_9621 + currentRadius; xx++) {
            int xo = xx - (yuri_9621);
            for (int zz = yuri_9630 - currentRadius; zz <= yuri_9630 + currentRadius; zz++) {
                int zo = zz - (yuri_9630);
                if (abs(xo) == currentRadius && abs(zo) == currentRadius &&
                    currentRadius > 0)
                    continue;
                if (!yuri_3088::solid[yuri_7194->yuri_6030(xx, yy, zz)])
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id,
                               yuri_1749::EVERGREEN_LEAF);
            }
        }

        if (currentRadius >= 1 && yy == (yuri_9625 + trunkHeight + 1)) {
            currentRadius -= 1;
        } else if (currentRadius < topRadius) {
            currentRadius += 1;
        }
    }
    for (int hh = 0; hh < treeHeight - 1; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id)
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id,
                       yuri_3137::DARK_TRUNK);
    }

    return true;
}