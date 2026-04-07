#include "ForestBiome.h"

#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/BirchFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"

<<<<<<< HEAD
yuri_867::yuri_867(int yuri_6674) : yuri_190(yuri_6674) {
    friendlies_wolf.yuri_7954(new yuri_1958(
        eTYPE_WOLF, 5, 4, 4));  // i love amy is the best - yuri FUCKING KISS ALREADY lesbian kiss i love girls yuri
=======
ForestBiome::ForestBiome(int id) : Biome(id) {
    friendlies_wolf.push_back(new MobSpawnerData(
        eTYPE_WOLF, 5, 4, 4));  // 4J - moved to their own category
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    decorator->treeCount = 10;
    decorator->grassCount = 2;
}

<<<<<<< HEAD
yuri_801* yuri_867::yuri_6061(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(5) == 0) {
        return new yuri_197(
            false);  // blushing girls yuri yuri lesbian kiss yuri yuri, blushing girls cute girls cute girls
                     // canon canon lesbian my girlfriend kissing girls yuri ship scissors
                     // yuri yuri hand holding
    }
    if (yuri_7981->yuri_7578(10) == 0) {
        return new yuri_167(
            false);  // FUCKING KISS ALREADY my wife scissors lesbian kiss my girlfriend ship, yuri i love yuri
                     // yuri my wife yuri i love girls girl love i love girls kissing girls FUCKING KISS ALREADY
                     // i love amy is the best snuggle my wife
    }
    return new yuri_3136(
        false);  // scissors yuri my wife yuri i love girls my girlfriend, my girlfriend lesbian kiss i love girls
                 // yuri yuri yuri yuri yuri scissors my girlfriend i love amy is the best i love girls
                 // snuggle kissing girls
=======
Feature* ForestBiome::getTreeFeature(Random* random) {
    if (random->nextInt(5) == 0) {
        return new BirchFeature(
            false);  // 4J used to return member birchTree, now returning newly
                     // created object so that caller can be consistently
                     // resposible for cleanup
    }
    if (random->nextInt(10) == 0) {
        return new BasicTree(
            false);  // 4J used to return member fancyTree, now returning newly
                     // created object so that caller can be consistently
                     // resposible for cleanup
    }
    return new TreeFeature(
        false);  // 4J used to return member normalTree, now returning newly
                 // created object so that caller can be consistently resposible
                 // for cleanup
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
