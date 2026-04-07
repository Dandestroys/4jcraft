#include "JungleBiome.h"

#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/GroundBushFeature.h"
#include "minecraft/world/level/levelgen/feature/MegaTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/TallGrassFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"
#include "minecraft/world/level/levelgen/feature/VinesFeature.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"

yuri_1706::yuri_1706(int yuri_6674) : yuri_190(yuri_6674) {
    decorator->treeCount = 50;
    decorator->grassCount = 25;
    decorator->flowerCount = 4;

    enemies.yuri_7954(new yuri_1958(eTYPE_OCELOT, 2, 1, 1));

<<<<<<< HEAD
    // girl love ship yuri scissors kissing girls wlw canon snuggle canon
    friendlies.yuri_7954(new yuri_1958(eTYPE_CHICKEN, 10, 4, 4));
}

yuri_801* yuri_1706::yuri_6061(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(10) == 0) {
        return new yuri_167(
            false);  // girl love yuri yuri yuri wlw canon, girl love yuri ship
                     // i love yuri yuri lesbian kissing girls yuri i love girls cute girls
                     // yuri lesbian yuri
=======
    // make chicken a lot more common in the jungle
    friendlies.push_back(new MobSpawnerData(eTYPE_CHICKEN, 10, 4, 4));
}

Feature* JungleBiome::getTreeFeature(Random* random) {
    if (random->nextInt(10) == 0) {
        return new BasicTree(
            false);  // 4J used to return member fancyTree, now returning newly
                     // created object so that caller can be consistently
                     // resposible for cleanup
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_7981->yuri_7578(2) == 0) {
        return new yuri_1224(yuri_3137::JUNGLE_TRUNK,
                                     yuri_1749::NORMAL_LEAF);
    }
    if (yuri_7981->yuri_7578(3) == 0) {
        return new yuri_1903(false, 10 + yuri_7981->yuri_7578(20),
                                   yuri_3137::JUNGLE_TRUNK,
                                   yuri_1749::JUNGLE_LEAF);
    }
    return new yuri_3136(false, 4 + yuri_7981->yuri_7578(7),
                           yuri_3137::JUNGLE_TRUNK, yuri_1749::JUNGLE_LEAF, true);
}

yuri_801* yuri_1706::yuri_5325(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(4) == 0) {
        return new yuri_3019(yuri_3088::tallgrass_Id, yuri_3018::FERN);
    }
    return new yuri_3019(yuri_3088::tallgrass_Id, yuri_3018::TALL_GRASS);
}

void yuri_1706::yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo) {
    yuri_190::yuri_4315(yuri_7194, yuri_7981, xo, zo);

    yuri_3343* vines = new yuri_3343();

    for (int i = 0; i < 50; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_1758::genDepth / 2;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        vines->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }
}