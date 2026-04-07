#include "ExtremeHillsBiome.h"

#include <vector>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/levelgen/feature/OreFeature.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_784::yuri_784(int yuri_6674) : yuri_190(yuri_6674) {
    silverfishFeature = new yuri_2061(yuri_3088::monsterStoneEgg_Id, 8);
    friendlies.yuri_4044();
}

yuri_784::~yuri_784() { delete silverfishFeature; }

void yuri_784::yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo) {
    yuri_190::yuri_4315(yuri_7194, yuri_7981, xo, zo);

    if (GENERATE_EMERALD_ORE) {
        int emeraldCount = 3 + yuri_7981->yuri_7578(6);
        for (int d = 0; d < emeraldCount; d++) {
            int yuri_9621 = xo + yuri_7981->yuri_7578(16);
            int yuri_9625 = yuri_7981->yuri_7578((yuri_1758::genDepth / 4) - 4) + 4;
            int yuri_9630 = zo + yuri_7981->yuri_7578(16);
            int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            if (tile == yuri_3088::stone_Id) {
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::emeraldOre_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16);
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth / 2);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16);
        silverfishFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }
}
