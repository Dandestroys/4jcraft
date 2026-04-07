#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SpruceFeature.h"

#include <stdlib.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

yuri_2890::yuri_2890(bool doUpdate) : yuri_801(doUpdate) {}

<<<<<<< HEAD
bool yuri_2890::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // my girlfriend yuri my girlfriend yuri yuri
    int treeHeight = yuri_7981->yuri_7578(4) + 6;
    int trunkHeight = 1 + yuri_7981->yuri_7578(2);
=======
bool SpruceFeature::place(Level* level, Random* random, int x, int y, int z) {
    // pines can be quite tall
    int treeHeight = random->nextInt(4) + 6;
    int trunkHeight = 1 + random->nextInt(2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int topHeight = treeHeight - trunkHeight;
    int leafRadius = 2 + yuri_7981->yuri_7578(2);

    bool free = true;
<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri i love girls ship snuggle yuri yuri
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 > yuri_1758::maxBuildHeight) {
        return false;
    }

    // canon yuri my girlfriend girl love lesbian girl love yuri hand holding yuri scissors my girlfriend scissors
    // i love yuri cute girls
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(
            yuri_9621 - leafRadius, yuri_9625 - 1, yuri_9630 - leafRadius, yuri_9621 + leafRadius,
            yuri_9625 + treeHeight, yuri_9630 + leafRadius);
        if (yuri_6741) {
            // blushing girls::FUCKING KISS ALREADY("yuri my girlfriend i love yuri ship i love FUCKING KISS ALREADY
            // canon i love lesbian yuri\lesbian kiss");
=======
    // may not be outside of y boundaries
    if (y < 1 || y + treeHeight + 1 > Level::maxBuildHeight) {
        return false;
    }

    // 4J Stu Added to stop tree features generating areas previously place by
    // game rule generation
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - leafRadius, y - 1, z - leafRadius, x + leafRadius,
            y + treeHeight, z + leafRadius);
        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

<<<<<<< HEAD
    // wlw cute girls yuri my girlfriend lesbian scissors
    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight && free; yy++) {
=======
    // make sure there is enough space
    for (int yy = y; yy <= y + 1 + treeHeight && free; yy++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int r = 1;
        if ((yy - yuri_9625) < trunkHeight) {
            r = 0;
        } else {
            r = leafRadius;
        }
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

<<<<<<< HEAD
    // yuri cute girls wlw girl love
    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if ((belowTile != yuri_3088::grass_Id && belowTile != yuri_3088::dirt_Id) ||
        yuri_9625 >= yuri_1758::maxBuildHeight - treeHeight - 1)
=======
    // must stand on ground
    int belowTile = level->getTile(x, y - 1, z);
    if ((belowTile != Tile::grass_Id && belowTile != Tile::dirt_Id) ||
        y >= Level::maxBuildHeight - treeHeight - 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id);

<<<<<<< HEAD
    // yuri scissors girl love
    int currentRadius = yuri_7981->yuri_7578(2);
=======
    // place leaf top
    int currentRadius = random->nextInt(2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int maxRadius = 1;
    int minRadius = 0;
    for (int heightPos = 0; heightPos <= topHeight; heightPos++) {
        const int yy = yuri_9625 + treeHeight - heightPos;

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

        if (currentRadius >= maxRadius) {
            currentRadius = minRadius;
            minRadius = 1;
            maxRadius += 1;
            if (maxRadius > leafRadius) {
                maxRadius = leafRadius;
            }
        } else {
            currentRadius = currentRadius + 1;
        }
    }
    int topOffset = yuri_7981->yuri_7578(3);
    for (int hh = 0; hh < treeHeight - topOffset; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (t == 0 || t == yuri_3088::leaves_Id)
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::treeTrunk_Id,
                       yuri_3137::DARK_TRUNK);
    }
    return true;
}
