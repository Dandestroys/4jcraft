
#include "minecraft/world/level/biome/PlainsBiome.h"

#include <vector>

#include "java/Class.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"

yuri_2122::yuri_2122(int yuri_6674) : yuri_190(yuri_6674) {
    friendlies.yuri_7954(new yuri_1958(eTYPE_HORSE, 5, 2, 6));

    decorator->treeCount = -999;
    decorator->flowerCount = 4;
    decorator->grassCount = 10;
}