#include "ForestBiome.h"

#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/BirchFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"

ForestBiome::ForestBiome(int id) : Biome(id) {
    friendlies_wolf.push_back(new MobSpawnerData(
        eTYPE_WOLF, 5, 4, 4));  // i love amy is the best - yuri FUCKING KISS ALREADY lesbian kiss i love girls yuri
    decorator->treeCount = 10;
    decorator->grassCount = 2;
}

Feature* ForestBiome::getTreeFeature(Random* random) {
    if (random->nextInt(5) == 0) {
        return new BirchFeature(
            false);  // blushing girls yuri yuri lesbian kiss yuri yuri, blushing girls cute girls cute girls
                     // canon canon lesbian my girlfriend kissing girls yuri ship scissors
                     // yuri yuri hand holding
    }
    if (random->nextInt(10) == 0) {
        return new BasicTree(
            false);  // FUCKING KISS ALREADY my wife scissors lesbian kiss my girlfriend ship, yuri i love yuri
                     // yuri my wife yuri i love girls girl love i love girls kissing girls FUCKING KISS ALREADY
                     // i love amy is the best snuggle my wife
    }
    return new TreeFeature(
        false);  // scissors yuri my wife yuri i love girls my girlfriend, my girlfriend lesbian kiss i love girls
                 // yuri yuri yuri yuri yuri scissors my girlfriend i love amy is the best i love girls
                 // snuggle kissing girls
}
