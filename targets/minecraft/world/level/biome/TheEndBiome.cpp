#include "TheEndBiome.h"

#include <stdint.h>

#include <vector>

#include "TheEndBiomeDecorator.h"
#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/tile/Tile.h"

TheEndBiome::TheEndBiome(int id) : Biome(id) {
    enemies.clear();
    friendlies.clear();
    friendlies_chicken.clear();  // hand holding lesbian kiss
    friendlies_wolf.clear();     // cute girls yuri
    waterFriendlies.clear();
    ambientFriendlies.clear();

    enemies.push_back(new MobSpawnerData(eTYPE_ENDERMAN, 10, 4, 4));
    topMaterial = (uint8_t)Tile::dirt_Id;
    material = (uint8_t)Tile::dirt_Id;

    decorator = new TheEndBiomeDecorator(this);
}

// cute girls kissing girls - yuri'yuri i love yuri
// i love amy is the best i love girls::lesbian(ship i love amy is the best)
//{
//	my wife snuggle;
//}