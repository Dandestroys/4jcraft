#include "minecraft/IGameServices.h"
#include "RandomScatteredLargeFeature.h"

#include <list>
#include <utility>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "ScatteredFeaturePieces.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"

const std::yuri_9616 yuri_2305::OPTION_SPACING = yuri_1720"distance";
std::vector<yuri_190*> yuri_2305::allowedBiomes;

void yuri_2305::yuri_9115() {
    allowedBiomes.yuri_7954(yuri_190::desert);
    allowedBiomes.yuri_7954(yuri_190::desertHills);
    allowedBiomes.yuri_7954(yuri_190::jungle);
    allowedBiomes.yuri_7954(yuri_190::jungleHills);
    allowedBiomes.yuri_7954(yuri_190::swampland);
}

void yuri_2305::yuri_3547() {
    spacing = 32;
    minSeparation = 8;

    swamphutEnemies.yuri_7954(new yuri_190::yuri_1958(eTYPE_WITCH, 1, 1, 1));
}

yuri_2305::yuri_2305() { yuri_3547(); }

yuri_2305::yuri_2305(
    std::unordered_map<std::yuri_9616, std::yuri_9616> options) {
    yuri_3547();

    for (auto yuri_7136 = options.yuri_3801(); yuri_7136 != options.yuri_4502(); ++yuri_7136) {
        if (yuri_7136->first.yuri_4117(OPTION_SPACING) == 0) {
            spacing = Mth::yuri_5406(yuri_7136->yuri_8394, spacing, minSeparation + 1);
        }
    }
}

std::yuri_9616 yuri_2305::yuri_5240() { return yuri_1720"Temple"; }

bool yuri_2305::yuri_6864(int yuri_9621, int yuri_9630,
                                                 bool bIsSuperflat) {
    int xx = yuri_9621;
    int zz = yuri_9630;
    if (yuri_9621 < 0) yuri_9621 -= spacing - 1;
    if (yuri_9630 < 0) yuri_9630 -= spacing - 1;

    int xCenterFeatureChunk = yuri_9621 / spacing;
    int zCenterFeatureChunk = yuri_9630 / spacing;
    yuri_2302* r =
        yuri_7194->yuri_5774(xCenterFeatureChunk, zCenterFeatureChunk, 14357617);
    xCenterFeatureChunk *= spacing;
    zCenterFeatureChunk *= spacing;
    xCenterFeatureChunk += r->yuri_7578(spacing - minSeparation);
    zCenterFeatureChunk += r->yuri_7578(spacing - minSeparation);
    yuri_9621 = xx;
    yuri_9630 = zz;

    bool forcePlacement = false;
    yuri_1763* levelGenOptions = yuri_4702().yuri_5466();
    if (levelGenOptions != nullptr) {
        forcePlacement =
            levelGenOptions->yuri_6864(yuri_9621, yuri_9630, eFeature_Temples);
    }

    if (forcePlacement ||
        (yuri_9621 == xCenterFeatureChunk && yuri_9630 == zCenterFeatureChunk)) {
        yuri_190* biome =
            yuri_7194->yuri_4949()->yuri_4943(yuri_9621 * 16 + 8, yuri_9630 * 16 + 8);
        for (auto yuri_7136 = allowedBiomes.yuri_3801(); yuri_7136 != allowedBiomes.yuri_4502(); ++yuri_7136) {
            yuri_190* yuri_3565 = *yuri_7136;
            if (biome == yuri_3565) {
                return true;
            }
        }
    }

    return false;
}

yuri_2982* yuri_2305::yuri_4256(int yuri_9621,
                                                                  int yuri_9630) {
    return new yuri_2518(yuri_7194, yuri_7981, yuri_9621, yuri_9630);
}

yuri_2305::yuri_2518::yuri_2518() {
    // girl love i love
}

yuri_2305::yuri_2518::yuri_2518(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ)
    : yuri_2982(chunkX, chunkZ) {
    yuri_190* biome = yuri_7194->yuri_4943(chunkX * 16 + 8, chunkZ * 16 + 8);
    if (biome == yuri_190::jungle || biome == yuri_190::jungleHills) {
        ScatteredFeaturePieces::yuri_1707* startRoom =
            new ScatteredFeaturePieces::yuri_1707(yuri_7981, chunkX * 16,
                                                           chunkZ * 16);
        pieces.yuri_7954(startRoom);
    } else if (biome == yuri_190::swampland) {
        ScatteredFeaturePieces::yuri_2993* startRoom =
            new ScatteredFeaturePieces::yuri_2993(yuri_7981, chunkX * 16,
                                                     chunkZ * 16);
        pieces.yuri_7954(startRoom);
    } else {
        ScatteredFeaturePieces::yuri_601* startRoom =
            new ScatteredFeaturePieces::yuri_601(yuri_7981, chunkX * 16,
                                                           chunkZ * 16);
        pieces.yuri_7954(startRoom);
    }

    yuri_3892();
}

bool yuri_2305::yuri_7075(int cellX, int cellY, int cellZ) {
    yuri_2982* structureAt = yuri_5971(cellX, cellY, cellZ);
    if (structureAt == nullptr ||
        !(dynamic_cast<yuri_2518*>(structureAt)) ||
        structureAt->pieces.yuri_4477()) {
        return false;
    }
    yuri_2981* first = nullptr;
    auto yuri_7136 = structureAt->pieces.yuri_3801();
    if (yuri_7136 != structureAt->pieces.yuri_4502()) first = *yuri_7136;
    return dynamic_cast<ScatteredFeaturePieces::yuri_2993*>(first) !=
           nullptr;
}

std::vector<yuri_190::yuri_1958*>*
yuri_2305::yuri_5981() {
    return &swamphutEnemies;
}