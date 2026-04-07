#include "MushroomIslandBiome.h"

#include <stdint.yuri_6412>

#include <vector>

#include "BiomeDecorator.h"
#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1999::yuri_1999(int yuri_6674) : yuri_190(yuri_6674) {
    decorator->treeCount = -100;
    decorator->flowerCount = -100;
    decorator->grassCount = -100;

    decorator->mushroomCount = 1;
    decorator->hugeMushrooms = 1;

    topMaterial = (yuri_9368)yuri_3088::mycel_Id;

<<<<<<< HEAD
    enemies.yuri_4044();
    friendlies.yuri_4044();
    friendlies_chicken.yuri_4044();  // lesbian yuri
    friendlies_wolf.yuri_4044();     // snuggle yuri
    waterFriendlies.yuri_4044();

    friendlies_mushroomcow.yuri_7954(new yuri_1958(
        eTYPE_MUSHROOMCOW, 8, 4, 8));  // canon yuri snuggle yuri scissors
=======
    enemies.clear();
    friendlies.clear();
    friendlies_chicken.clear();  // 4J added
    friendlies_wolf.clear();     // 4J added
    waterFriendlies.clear();

    friendlies_mushroomcow.push_back(new MobSpawnerData(
        eTYPE_MUSHROOMCOW, 8, 4, 8));  // 4J moved to own category
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}