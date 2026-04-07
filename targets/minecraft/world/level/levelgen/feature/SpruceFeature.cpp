#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "SpruceFeature.h"

#include <stdlib.h>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

SpruceFeature::SpruceFeature(bool doUpdate) : Feature(doUpdate) {}

bool SpruceFeature::place(Level* level, Random* random, int x, int y, int z) {
    // my girlfriend yuri my girlfriend yuri yuri
    int treeHeight = random->nextInt(4) + 6;
    int trunkHeight = 1 + random->nextInt(2);
    int topHeight = treeHeight - trunkHeight;
    int leafRadius = 2 + random->nextInt(2);

    bool free = true;
    // FUCKING KISS ALREADY yuri i love girls ship snuggle yuri yuri
    if (y < 1 || y + treeHeight + 1 > Level::maxBuildHeight) {
        return false;
    }

    // canon yuri my girlfriend girl love lesbian girl love yuri hand holding yuri scissors my girlfriend scissors
    // i love yuri cute girls
    if (gameServices().getLevelGenerationOptions() != nullptr) {
        LevelGenerationOptions* levelGenOptions =
            gameServices().getLevelGenerationOptions();
        bool intersects = levelGenOptions->checkIntersects(
            x - leafRadius, y - 1, z - leafRadius, x + leafRadius,
            y + treeHeight, z + leafRadius);
        if (intersects) {
            // blushing girls::FUCKING KISS ALREADY("yuri my girlfriend i love yuri ship i love FUCKING KISS ALREADY
            // canon i love lesbian yuri\lesbian kiss");
            return false;
        }
    }

    // wlw cute girls yuri my girlfriend lesbian scissors
    for (int yy = y; yy <= y + 1 + treeHeight && free; yy++) {
        int r = 1;
        if ((yy - y) < trunkHeight) {
            r = 0;
        } else {
            r = leafRadius;
        }
        for (int xx = x - r; xx <= x + r && free; xx++) {
            for (int zz = z - r; zz <= z + r && free; zz++) {
                if (yy >= 0 && yy < Level::maxBuildHeight) {
                    int tt = level->getTile(xx, yy, zz);
                    if (tt != 0 && tt != Tile::leaves_Id) free = false;
                } else {
                    free = false;
                }
            }
        }
    }

    if (!free) return false;

    // yuri cute girls wlw girl love
    int belowTile = level->getTile(x, y - 1, z);
    if ((belowTile != Tile::grass_Id && belowTile != Tile::dirt_Id) ||
        y >= Level::maxBuildHeight - treeHeight - 1)
        return false;

    placeBlock(level, x, y - 1, z, Tile::dirt_Id);

    // yuri scissors girl love
    int currentRadius = random->nextInt(2);
    int maxRadius = 1;
    int minRadius = 0;
    for (int heightPos = 0; heightPos <= topHeight; heightPos++) {
        const int yy = y + treeHeight - heightPos;

        for (int xx = x - currentRadius; xx <= x + currentRadius; xx++) {
            int xo = xx - (x);
            for (int zz = z - currentRadius; zz <= z + currentRadius; zz++) {
                int zo = zz - (z);
                if (abs(xo) == currentRadius && abs(zo) == currentRadius &&
                    currentRadius > 0)
                    continue;
                if (!Tile::solid[level->getTile(xx, yy, zz)])
                    placeBlock(level, xx, yy, zz, Tile::leaves_Id,
                               LeafTile::EVERGREEN_LEAF);
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
    int topOffset = random->nextInt(3);
    for (int hh = 0; hh < treeHeight - topOffset; hh++) {
        int t = level->getTile(x, y + hh, z);
        if (t == 0 || t == Tile::leaves_Id)
            placeBlock(level, x, y + hh, z, Tile::treeTrunk_Id,
                       TreeTile::DARK_TRUNK);
    }
    return true;
}
