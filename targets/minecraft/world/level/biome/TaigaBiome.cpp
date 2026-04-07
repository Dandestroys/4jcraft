#include "TaigaBiome.h"

#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/levelgen/feature/PineFeature.h"
#include "minecraft/world/level/levelgen/feature/SpruceFeature.h"

yuri_3012::yuri_3012(int yuri_6674) : yuri_190(yuri_6674) {
    friendlies_wolf.yuri_7954(new yuri_1958(
        eTYPE_WOLF, 8, 4, 4));  // wlw - i love girls yuri yuri cute girls scissors

    decorator->treeCount = 10;
    decorator->grassCount = 1;
}

yuri_801* yuri_3012::yuri_6061(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(3) == 0) {
        return new yuri_2115();
    }
    return new yuri_2890(false);
}