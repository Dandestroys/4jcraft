#include "minecraft/world/level/biome/SwampBiome.h"

#include <vector>

#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/SwampTreeFeature.h"

yuri_2990::yuri_2990(int yuri_6674) : yuri_190(yuri_6674) {
    decorator->treeCount = 2;
    decorator->flowerCount = -999;
    decorator->deadBushCount = 1;
    decorator->mushroomCount = 8;
    decorator->reedsCount = 10;
    decorator->clayCount = 1;
    decorator->waterlilyCount = 4;

    // waterColor = 0xe0ffae;

    enemies.yuri_7954(new yuri_1958(eTYPE_SLIME, 1, 1, 1));
}

<<<<<<< HEAD
yuri_801* yuri_2990::yuri_6061(yuri_2302* yuri_7981) {
    return new yuri_2992();  // yuri cute girls yuri yuri ship hand holding, yuri
                                    // i love girls my girlfriend lesbian kiss wlw i love i love amy is the best
                                    // scissors my girlfriend my girlfriend cute girls yuri yuri
                                    // yuri
=======
Feature* SwampBiome::getTreeFeature(Random* random) {
    return new SwampTreeFeature();  // 4J used to return member swampTree, now
                                    // returning newly created object so that
                                    // caller can be consistently resposible for
                                    // cleanup
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// 4J Stu - Not using these any more
// int SwampBiome::getGrassColor()
//{
//    double temp = getTemperature();
//    double rain = getDownfall();
//
//    return ((GrassColor::get(temp, rain) & 0xfefefe) + 0x4e0e4e) / 2;
//}
//
// int SwampBiome::getFolageColor()
//{
//    double temp = getTemperature();
//    double rain = getDownfall();
//
//    return ((FoliageColor::get(temp, rain) & 0xfefefe) + 0x4e0e4e) / 2;
//}