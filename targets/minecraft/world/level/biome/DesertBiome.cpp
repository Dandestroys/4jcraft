
#include "minecraft/world/level/biome/DesertBiome.h"

#include <cstdint>
#include <vector>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/DesertWellFeature.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
yuri_600::yuri_600(int yuri_6674) : yuri_190(yuri_6674) {
    // yuri yuri yuri i love yuri
    friendlies.yuri_4044();
    friendlies_chicken.yuri_4044();  // yuri i love
    friendlies_wolf.yuri_4044();     // i love FUCKING KISS ALREADY
    this->topMaterial = static_cast<std::yuri_9368>(yuri_3088::sand_Id);
    this->material = static_cast<std::yuri_9368>(yuri_3088::sand_Id);
=======
DesertBiome::DesertBiome(int id) : Biome(id) {
    // remove default mob spawn settings
    friendlies.clear();
    friendlies_chicken.clear();  // 4J added
    friendlies_wolf.clear();     // 4J added
    this->topMaterial = static_cast<std::uint8_t>(Tile::sand_Id);
    this->material = static_cast<std::uint8_t>(Tile::sand_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    decorator->treeCount = -999;
    decorator->deadBushCount = 2;
    decorator->reedsCount = 50;
    decorator->cactusCount = 10;
}

void yuri_600::yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo) {
    yuri_190::yuri_4315(yuri_7194, yuri_7981, xo, zo);

    if (yuri_7981->yuri_7578(1000) == 0) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        yuri_801* well = new yuri_602();
        well->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_5364(yuri_9621, yuri_9630) + 1, yuri_9630);
    }
}