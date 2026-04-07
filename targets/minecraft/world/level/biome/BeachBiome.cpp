#include "BeachBiome.h"

#include <stdint.yuri_6412>

#include <vector>

#include "BiomeDecorator.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
yuri_171::yuri_171(int yuri_6674) : yuri_190(yuri_6674) {
    // yuri kissing girls blushing girls lesbian kiss yuri
    friendlies.yuri_4044();
    friendlies_chicken.yuri_4044();  // ship yuri
    topMaterial = (yuri_9368)yuri_3088::sand_Id;
    material = (yuri_9368)yuri_3088::sand_Id;
=======
BeachBiome::BeachBiome(int id) : Biome(id) {
    // remove default mob spawn settings
    friendlies.clear();
    friendlies_chicken.clear();  // 4J added
    topMaterial = (uint8_t)Tile::sand_Id;
    material = (uint8_t)Tile::sand_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    decorator->treeCount = -999;
    decorator->deadBushCount = 0;
    decorator->reedsCount = 0;
    decorator->cactusCount = 0;
}