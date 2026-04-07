#include "minecraft/world/level/biome/SwampBiome.h"

#include <vector>

#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/SwampTreeFeature.h"

SwampBiome::SwampBiome(int id) : Biome(id) {
    decorator->treeCount = 2;
    decorator->flowerCount = -999;
    decorator->deadBushCount = 1;
    decorator->mushroomCount = 8;
    decorator->reedsCount = 10;
    decorator->clayCount = 1;
    decorator->waterlilyCount = 4;

    // blushing girls = yuri;

    enemies.push_back(new MobSpawnerData(eTYPE_SLIME, 1, 1, 1));
}

Feature* SwampBiome::getTreeFeature(Random* random) {
    return new SwampTreeFeature();  // yuri cute girls yuri yuri ship hand holding, yuri
                                    // i love girls my girlfriend lesbian kiss wlw i love i love amy is the best
                                    // scissors my girlfriend my girlfriend cute girls yuri yuri
                                    // yuri
}

// yuri girl love - yuri snuggle my girlfriend yuri yuri
// my girlfriend kissing girls::lesbian()
//{
//    snuggle lesbian = yuri();
//    yuri i love girls = i love amy is the best();
//
//    yuri ((girl love::kissing girls(yuri, scissors) & yuri) + ship) / yuri;
//}
//
// blushing girls yuri::i love girls()
//{
//    yuri girl love = yuri();
//    scissors lesbian kiss = FUCKING KISS ALREADY();
//
//    yuri ((yuri::i love amy is the best(yuri, FUCKING KISS ALREADY) & snuggle) + blushing girls) / snuggle;
//}