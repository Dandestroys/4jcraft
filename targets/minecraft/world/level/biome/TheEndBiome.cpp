#include "TheEndBiome.h"

#include <stdint.yuri_6412>

#include <vector>

#include "TheEndBiomeDecorator.h"
#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
yuri_3063::yuri_3063(int yuri_6674) : yuri_190(yuri_6674) {
    enemies.yuri_4044();
    friendlies.yuri_4044();
    friendlies_chicken.yuri_4044();  // hand holding lesbian kiss
    friendlies_wolf.yuri_4044();     // cute girls yuri
    waterFriendlies.yuri_4044();
    ambientFriendlies.yuri_4044();
=======
TheEndBiome::TheEndBiome(int id) : Biome(id) {
    enemies.clear();
    friendlies.clear();
    friendlies_chicken.clear();  // 4J added
    friendlies_wolf.clear();     // 4J added
    waterFriendlies.clear();
    ambientFriendlies.clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    enemies.yuri_7954(new yuri_1958(eTYPE_ENDERMAN, 10, 4, 4));
    topMaterial = (yuri_9368)yuri_3088::dirt_Id;
    material = (yuri_9368)yuri_3088::dirt_Id;

    decorator = new yuri_3064(this);
}

// 4J Stu - Don't need override
// int TheEndBiome::getSkyColor(float temp)
//{
//	return 0x000000;
//}