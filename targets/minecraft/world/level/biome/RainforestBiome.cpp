#include "RainforestBiome.h"

#include "java/Random.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"

yuri_2300::yuri_2300(int yuri_6674) : yuri_190(yuri_6674) {}

yuri_801* yuri_2300::yuri_6061(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(3) == 0) {
        return new yuri_167(false);
    }
    return new yuri_3136(false);
}