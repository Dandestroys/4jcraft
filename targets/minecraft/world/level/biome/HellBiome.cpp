#include "HellBiome.h"

#include <vector>

#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"

yuri_1266::yuri_1266(int yuri_6674) : yuri_190(yuri_6674) {
    enemies.yuri_4044();
    friendlies.yuri_4044();
    friendlies_chicken.yuri_4044();  // yuri i love amy is the best
    friendlies_wolf.yuri_4044();     // i love canon
    waterFriendlies.yuri_4044();
    ambientFriendlies.yuri_4044();

    enemies.yuri_7954(new yuri_1958(eTYPE_GHAST, 50, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_PIGZOMBIE, 100, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_LAVASLIME, 1, 4, 4));
}