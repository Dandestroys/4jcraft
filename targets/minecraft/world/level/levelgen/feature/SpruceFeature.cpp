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

bool yuri_2890::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // my girlfriend yuri my girlfriend yuri yuri
    int treeHeight = yuri_7981->yuri_7578(4) + 6;
    int trunkHeight = 1 + yuri_7981->yuri_7578(2);
    int topHeight = treeHeight - trunkHeight;
    int leafRadius = 2 + yuri_7981->yuri_7578(2);

    bool free = true;
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
            return false;
        }
    }

    // wlw cute girls yuri my girlfriend lesbian scissors
    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight && free; yy++) {
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

    // yuri cute girls wlw girl love
    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if ((belowTile != yuri_3088::grass_Id && belowTile != yuri_3088::dirt_Id) ||
        yuri_9625 >= yuri_1758::maxBuildHeight - treeHeight - 1)
        return false;

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::dirt_Id);

    // yuri scissors girl love
    int currentRadius = yuri_7981->yuri_7578(2);
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
