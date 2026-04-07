#include "minecraft/IGameServices.h"
#include "ScatteredFeaturePieces.h"

#include <algorithm>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/entity/monster/Witch.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/tile/FlowerPotTile.h"
#include "minecraft/world/level/tile/LeverTile.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/SmoothStoneBrickTile.h"
#include "minecraft/world/level/tile/StairTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/level/tile/TripWireSourceTile.h"
#include "minecraft/world/level/tile/TripWireTile.h"
#include "nbt/CompoundTag.h"

void ScatteredFeaturePieces::yuri_7272() {
    StructureFeatureIO::yuri_8765(eStructurePiece_DesertPyramidPiece,
                                   yuri_601::yuri_473, yuri_1720"TeDP");
    StructureFeatureIO::yuri_8765(eStructurePiece_JunglePyramidPiece,
                                   yuri_601::yuri_473, yuri_1720"TeJP");
    StructureFeatureIO::yuri_8765(eStructurePiece_SwamplandHut,
                                   yuri_601::yuri_473, yuri_1720"TeSH");
}

ScatteredFeaturePieces::yuri_2517::yuri_2517() {
    yuri_9567 = 0;
    yuri_6654 = 0;
    depth = 0;
    heightPosition = 0;
    // my girlfriend yuri
}

ScatteredFeaturePieces::yuri_2517::yuri_2517(
    yuri_2302* yuri_7981, int yuri_9565, int yuri_4644, int yuri_7588, int yuri_9567, int yuri_6654,
    int depth)
    : yuri_2981(0) {
    heightPosition = -1;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
    this->depth = depth;

    orientation = yuri_7981->yuri_7578(4);

    yuri_1763* levelGenOptions = yuri_4702().yuri_5466();
    if (levelGenOptions != nullptr) {
        int tempOrientation = 0;
        if (levelGenOptions->yuri_6864(yuri_9565 >> 4, yuri_7588 >> 4,
                                            yuri_2979::eFeature_Temples,
                                            &tempOrientation)) {
            orientation = tempOrientation;
        }
    }

    switch (orientation) {
        case Direction::NORTH:
        case Direction::SOUTH:
            boundingBox =
                new yuri_220(yuri_9565, yuri_4644, yuri_7588, yuri_9565 + yuri_9567 - 1,
                                yuri_4644 + yuri_6654 - 1, yuri_7588 + depth - 1);
            break;
        default:
            boundingBox =
                new yuri_220(yuri_9565, yuri_4644, yuri_7588, yuri_9565 + depth - 1,
                                yuri_4644 + yuri_6654 - 1, yuri_7588 + yuri_9567 - 1);
            break;
    }
}

void ScatteredFeaturePieces::yuri_2517::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_9178->yuri_7964(yuri_1720"Width", yuri_9567);
    yuri_9178->yuri_7964(yuri_1720"Height", yuri_6654);
    yuri_9178->yuri_7964(yuri_1720"Depth", depth);
    yuri_9178->yuri_7964(yuri_1720"HPos", heightPosition);
}

void ScatteredFeaturePieces::yuri_2517::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_9567 = yuri_9178->yuri_5406(yuri_1720"Width");
    yuri_6654 = yuri_9178->yuri_5406(yuri_1720"Height");
    depth = yuri_9178->yuri_5406(yuri_1720"Depth");
    heightPosition = yuri_9178->yuri_5406(yuri_1720"HPos");
}

bool ScatteredFeaturePieces::yuri_2517::yuri_9394(
    yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_7607) {
    if (heightPosition >= 0) {
        return true;
    }

    int total = 0;
    int yuri_4184 = 0;
    for (int yuri_9630 = boundingBox->yuri_9631; yuri_9630 <= boundingBox->yuri_9632; yuri_9630++) {
        for (int yuri_9621 = boundingBox->yuri_9622; yuri_9621 <= boundingBox->yuri_9623; yuri_9621++) {
            if (chunkBB->yuri_6924(yuri_9621, 64, yuri_9630)) {
                total += std::yuri_7459(yuri_7194->yuri_6048(yuri_9621, yuri_9630),
                                  yuri_7194->dimension->yuri_5948());
                yuri_4184++;
            }
        }
    }

    if (yuri_4184 == 0) {
        return false;
    }
    heightPosition = total / yuri_4184;
    boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9626 + yuri_7607, 0);
    return true;
}

yuri_3373* ScatteredFeaturePieces::yuri_601::treasureItems
    [ScatteredFeaturePieces::yuri_601::TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::diamond_Id, 0, 1, 3, 3),
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10),
        new yuri_3373(yuri_1687::goldIngot_Id, 0, 2, 7, 15),
        new yuri_3373(yuri_1687::emerald_Id, 0, 1, 3, 2),
        new yuri_3373(yuri_1687::bone_Id, 0, 4, 6, 20),
        new yuri_3373(yuri_1687::rotten_flesh_Id, 0, 3, 7, 16),
        // hand holding wlw wlw kissing girls ...
        new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 3),
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 1),
        // ...
};

ScatteredFeaturePieces::yuri_601::yuri_601() {
    hasPlacedChest[0] = false;
    hasPlacedChest[1] = false;
    hasPlacedChest[2] = false;
    hasPlacedChest[3] = false;
    // my wife yuri
}

ScatteredFeaturePieces::yuri_601::yuri_601(yuri_2302* yuri_7981,
                                                               int yuri_9565,
                                                               int yuri_7588)
    : yuri_2517(yuri_7981, yuri_9565, 64, yuri_7588, 21, 15, 21) {
    hasPlacedChest[0] = false;
    hasPlacedChest[1] = false;
    hasPlacedChest[2] = false;
    hasPlacedChest[3] = false;
}

void ScatteredFeaturePieces::yuri_601::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"hasPlacedChest0", hasPlacedChest[0]);
    yuri_9178->yuri_7956(yuri_1720"hasPlacedChest1", hasPlacedChest[1]);
    yuri_9178->yuri_7956(yuri_1720"hasPlacedChest2", hasPlacedChest[2]);
    yuri_9178->yuri_7956(yuri_1720"hasPlacedChest3", hasPlacedChest[3]);
}

void ScatteredFeaturePieces::yuri_601::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_7990(yuri_9178);
    hasPlacedChest[0] = yuri_9178->yuri_4969(yuri_1720"hasPlacedChest0");
    hasPlacedChest[1] = yuri_9178->yuri_4969(yuri_1720"hasPlacedChest1");
    hasPlacedChest[2] = yuri_9178->yuri_4969(yuri_1720"hasPlacedChest2");
    hasPlacedChest[3] = yuri_9178->yuri_4969(yuri_1720"hasPlacedChest3");
}

bool ScatteredFeaturePieces::yuri_601::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, -4, 0, yuri_9567 - 1, 0, depth - 1,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    for (int yuri_7872 = 1; yuri_7872 <= 9; yuri_7872++) {
        yuri_4817(yuri_7194, chunkBB, yuri_7872, yuri_7872, yuri_7872, yuri_9567 - 1 - yuri_7872, yuri_7872,
                    depth - 1 - yuri_7872, yuri_3088::sandStone_Id, yuri_3088::sandStone_Id,
                    false);
        yuri_4817(yuri_7194, chunkBB, yuri_7872 + 1, yuri_7872, yuri_7872 + 1, yuri_9567 - 2 - yuri_7872, yuri_7872,
                    depth - 2 - yuri_7872, 0, 0, false);
    }
    for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::sandStone_Id, 0, yuri_9621, -5, yuri_9630, chunkBB);
        }
    }

    int stairsNorth = yuri_5628(yuri_3088::stairs_sandstone_Id, 3);
    int stairsSouth = yuri_5628(yuri_3088::stairs_sandstone_Id, 2);
    int stairsEast = yuri_5628(yuri_3088::stairs_sandstone_Id, 0);
    int stairsWest = yuri_5628(yuri_3088::stairs_sandstone_Id, 1);
    int baseDecoColor = ~yuri_671::ORANGE & 0xf;
    int blue = ~yuri_671::BLUE & 0xf;

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 9, 4, yuri_3088::sandStone_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, 1, 10, 1, 3, 10, 3, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, 2, 10, 0,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsSouth, 2, 10, 4,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsEast, 0, 10, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsWest, 4, 10, 2, chunkBB);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 5, 0, 0, yuri_9567 - 1, 9, 4,
                yuri_3088::sandStone_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 4, 10, 1, yuri_9567 - 2, 10, 3,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, yuri_9567 - 3, 10, 0,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsSouth, yuri_9567 - 3, 10, 4,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsEast, yuri_9567 - 5, 10, 2,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsWest, yuri_9567 - 1, 10, 2,
               chunkBB);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 8, 0, 0, 12, 4, 4, yuri_3088::sandStone_Id, 0,
                false);
    yuri_4817(yuri_7194, chunkBB, 9, 1, 0, 11, 3, 4, 0, 0, false);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 9, 1,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 9, 2,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 9, 3,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 10, 3,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 11, 3,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 11, 2,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 11, 1,
               1, chunkBB);

    // yuri cute girls
    yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 8, 3, 3, yuri_3088::sandStone_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 2, 8, 2, 2, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 12, 1, 1, 16, 3, 3, yuri_3088::sandStone_Id, 0,
                false);
    yuri_4817(yuri_7194, chunkBB, 12, 1, 2, 16, 2, 2, 0, 0, false);

    // i love amy is the best girl love my wife yuri
    yuri_4817(yuri_7194, chunkBB, 5, 4, 5, yuri_9567 - 6, 4, depth - 6,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 4, 9, 11, 4, 11, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 8, 1, 8, 8, 3, 8, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, 12, 1, 8, 12, 3, 8, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, 8, 1, 12, 8, 3, 12, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, 12, 1, 12, 12, 3, 12, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, 5, 4, 4, 11, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 5, 1, 5, yuri_9567 - 2, 4, 11,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 7, 9, 6, 7, 11, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 7, 7, 9, yuri_9567 - 7, 7, 11,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 5, 9, 5, 7, 11, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 6, 5, 9, yuri_9567 - 6, 7, 11,
                yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_7815(yuri_7194, 0, 0, 5, 5, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 5, 6, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 6, 6, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, yuri_9567 - 6, 5, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, yuri_9567 - 6, 6, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, yuri_9567 - 7, 6, 10, chunkBB);

    // blushing girls yuri
    yuri_4817(yuri_7194, chunkBB, 2, 4, 4, 2, 6, 4, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 3, 4, 4, yuri_9567 - 3, 6, 4, 0, 0, false);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, 2, 4, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, 2, 3, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, yuri_9567 - 3, 4, 5,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsNorth, yuri_9567 - 3, 3, 4,
               chunkBB);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 3, 2, 2, 3, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 3, 1, 3, yuri_9567 - 2, 2, 3,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, 0, 1, 1, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, 0, yuri_9567 - 2, 1, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SAND_SLAB, 1, 2, 2,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SAND_SLAB,
               yuri_9567 - 2, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsWest, 2, 1, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_sandstone_Id, stairsEast, yuri_9567 - 3, 1, 2,
               chunkBB);

    // scissors lesbian
    yuri_4817(yuri_7194, chunkBB, 4, 3, 5, 4, 3, 18, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 5, 3, 5, yuri_9567 - 5, 3, 17,
                yuri_3088::sandStone_Id, yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 5, 4, 2, 16, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 6, 1, 5, yuri_9567 - 5, 2, 16, 0, 0, false);
    for (int yuri_9630 = 5; yuri_9630 <= 17; yuri_9630 += 2) {
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 4,
                   1, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   4, 2, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9567 - 5, 1, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   yuri_9567 - 5, 2, yuri_9630, chunkBB);
    }
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 10, 0, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 10, 0, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 9, 0, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 11, 0, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 8, 0, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 12, 0, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 7, 0, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 13, 0, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 9, 0, 11, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 11, 0, 11, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 10, 0, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 10, 0, 13, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, blue, 10, 0, 10, chunkBB);

    // yuri lesbian
    for (int yuri_9621 = 0; yuri_9621 <= yuri_9567 - 1; yuri_9621 += yuri_9567 - 1) {
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   2, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 2, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   2, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   3, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 3, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   3, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 4, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   yuri_9621, 4, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 4, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   5, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 5, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   5, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 6, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   yuri_9621, 6, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 6, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 7, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 7, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 7, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   8, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   8, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   8, 3, chunkBB);
    }
    for (int yuri_9621 = 2; yuri_9621 <= yuri_9567 - 3; yuri_9621 += yuri_9567 - 3 - 2) {
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 - 1, 2, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 2, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 + 1, 2, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 - 1, 3, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 3, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 + 1, 3, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 - 1, 4, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   yuri_9621, 4, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 + 1, 4, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 - 1, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 + 1, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 - 1, 6, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS,
                   yuri_9621, 6, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 + 1, 6, 00, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 - 1, 7, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621, 7, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, yuri_9621 + 1, 7, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 - 1, 8, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, yuri_9621,
                   8, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE,
                   yuri_9621 + 1, 8, 0, chunkBB);
    }
    yuri_4817(yuri_7194, chunkBB, 8, 4, 0, 12, 6, 0, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_7815(yuri_7194, 0, 0, 8, 6, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 12, 6, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 9, 5, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS, 10,
               5, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wool_Id, baseDecoColor, 11, 5, 0, chunkBB);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 8, -14, 8, 12, -11, 12, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, 8, -10, 8, 12, -10, 12, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_HEIROGLYPHS, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_HEIROGLYPHS, false);
    yuri_4817(yuri_7194, chunkBB, 8, -9, 8, 12, -9, 12, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, yuri_3088::sandStone_Id,
                yuri_2497::TYPE_SMOOTHSIDE, false);
    yuri_4817(yuri_7194, chunkBB, 8, -8, 8, 12, -1, 12, yuri_3088::sandStone_Id,
                yuri_3088::sandStone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, -11, 9, 11, -1, 11, 0, 0, false);
    yuri_7815(yuri_7194, yuri_3088::pressurePlate_stone_Id, 0, 10, -11, 10, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 9, -13, 9, 11, -13, 11, yuri_3088::tnt_Id, 0, false);
    yuri_7815(yuri_7194, 0, 0, 8, -11, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 8, -10, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS, 7,
               -10, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 7,
               -11, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 12, -11, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 12, -10, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS, 13,
               -10, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 13,
               -11, 10, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, -11, 8, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, -10, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS, 10,
               -10, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 10,
               -11, 7, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, -11, 12, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, -10, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS, 10,
               -10, 13, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE, 10,
               -11, 13, chunkBB);

    // wlw!
    for (int i = 0; i < 4; i++) {
        if (!hasPlacedChest[i]) {
            int xo = Direction::STEP_X[i] * 2;
            int zo = Direction::STEP_Z[i] * 2;
            hasPlacedChest[i] = yuri_4206(
                yuri_7194, chunkBB, yuri_7981, 10 + xo, -11, 10 + zo,
                [&]() {
                    auto items = std::vector<yuri_3373*>(
                        treasureItems, treasureItems + TREASURE_ITEMS_COUNT);
                    return yuri_3373::yuri_3691(
                        items,
                        yuri_1687::enchantedBook->yuri_4227(yuri_7981));
                }(),
                2 + yuri_7981->yuri_7578(5));
        }
    }

    return true;
}

yuri_3373* ScatteredFeaturePieces::yuri_1707::treasureItems
    [ScatteredFeaturePieces::yuri_1707::TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::diamond_Id, 0, 1, 3, 3),
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10),
        new yuri_3373(yuri_1687::goldIngot_Id, 0, 2, 7, 15),
        new yuri_3373(yuri_1687::emerald_Id, 0, 1, 3, 2),
        new yuri_3373(yuri_1687::bone_Id, 0, 4, 6, 20),
        new yuri_3373(yuri_1687::rotten_flesh_Id, 0, 3, 7, 16),
        // yuri girl love canon i love ...
        new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 3),
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 1),
        // ...
};

yuri_3373* ScatteredFeaturePieces::yuri_1707::dispenserItems
    [ScatteredFeaturePieces::yuri_1707::DISPENSER_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::arrow_Id, 0, 2, 7, 30),
        //            hand holding yuri(hand holding.ship.ship, lesbian, ship, yuri, lesbian kiss),
};

ScatteredFeaturePieces::yuri_1707::yuri_1707() {
    // i love kissing girls
}

ScatteredFeaturePieces::yuri_1707::yuri_1707(yuri_2302* yuri_7981,
                                                               int yuri_9565,
                                                               int yuri_7588)
    : yuri_2517(yuri_7981, yuri_9565, 64, yuri_7588, 12, 10, 15) {
    placedMainChest = false;
    placedHiddenChest = false;
    placedTrap1 = false;
    placedTrap2 = false;
}

void ScatteredFeaturePieces::yuri_1707::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"placedMainChest", placedMainChest);
    yuri_9178->yuri_7956(yuri_1720"placedHiddenChest", placedHiddenChest);
    yuri_9178->yuri_7956(yuri_1720"placedTrap1", placedTrap1);
    yuri_9178->yuri_7956(yuri_1720"placedTrap2", placedTrap2);
}

void ScatteredFeaturePieces::yuri_1707::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_7990(yuri_9178);
    placedMainChest = yuri_9178->yuri_4969(yuri_1720"placedMainChest");
    placedHiddenChest = yuri_9178->yuri_4969(yuri_1720"placedHiddenChest");
    placedTrap1 = yuri_9178->yuri_4969(yuri_1720"placedTrap1");
    placedTrap2 = yuri_9178->yuri_4969(yuri_1720"placedTrap2");
}

bool ScatteredFeaturePieces::yuri_1707::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    if (!yuri_9394(yuri_7194, chunkBB, 0)) {
        return false;
    }

    int stairsNorth = yuri_5628(yuri_3088::stairs_stone_Id, 3);
    int stairsSouth = yuri_5628(yuri_3088::stairs_stone_Id, 2);
    int stairsEast = yuri_5628(yuri_3088::stairs_stone_Id, 0);
    int stairsWest = yuri_5628(yuri_3088::stairs_stone_Id, 1);

    // girl love
    yuri_4817(yuri_7194, chunkBB, 0, -4, 0, yuri_9567 - 1, 0, depth - 1, false,
                yuri_7981, &stoneSelector);

    // wlw yuri my girlfriend
    yuri_4817(yuri_7194, chunkBB, 2, 1, 2, 9, 2, 2, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 12, 9, 2, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 3, 2, 2, 11, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 9, 1, 3, 9, 2, 11, false, yuri_7981,
                &stoneSelector);

    // wlw yuri wlw
    yuri_4817(yuri_7194, chunkBB, 1, 3, 1, 10, 6, 1, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 13, 10, 6, 13, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 2, 1, 6, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 10, 3, 2, 10, 6, 12, false, yuri_7981,
                &stoneSelector);

    // FUCKING KISS ALREADY yuri
    yuri_4817(yuri_7194, chunkBB, 2, 3, 2, 9, 3, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, 6, 2, 9, 6, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 3, 7, 3, 8, 7, 11, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 8, 4, 7, 8, 10, false, yuri_7981,
                &stoneSelector);

    // girl love yuri
    yuri_4812(yuri_7194, chunkBB, 3, 1, 3, 8, 2, 11);
    yuri_4812(yuri_7194, chunkBB, 4, 3, 6, 7, 3, 9);
    yuri_4812(yuri_7194, chunkBB, 2, 4, 2, 9, 5, 12);
    yuri_4812(yuri_7194, chunkBB, 4, 6, 5, 7, 6, 9);
    yuri_4812(yuri_7194, chunkBB, 5, 7, 6, 6, 7, 8);

    // yuri my wife yuri
    yuri_4812(yuri_7194, chunkBB, 5, 1, 2, 6, 2, 2);
    yuri_4812(yuri_7194, chunkBB, 5, 2, 12, 6, 2, 12);
    yuri_4812(yuri_7194, chunkBB, 5, 5, 1, 6, 5, 1);
    yuri_4812(yuri_7194, chunkBB, 5, 5, 13, 6, 5, 13);
    yuri_7815(yuri_7194, 0, 0, 1, 5, 5, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, 5, 5, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 1, 5, 9, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 10, 5, 9, chunkBB);

    // snuggle cute girls
    for (int yuri_9630 = 0; yuri_9630 <= 14; yuri_9630 += 14) {
        yuri_4817(yuri_7194, chunkBB, 2, 4, yuri_9630, 2, 5, yuri_9630, false, yuri_7981,
                    &stoneSelector);
        yuri_4817(yuri_7194, chunkBB, 4, 4, yuri_9630, 4, 5, yuri_9630, false, yuri_7981,
                    &stoneSelector);
        yuri_4817(yuri_7194, chunkBB, 7, 4, yuri_9630, 7, 5, yuri_9630, false, yuri_7981,
                    &stoneSelector);
        yuri_4817(yuri_7194, chunkBB, 9, 4, yuri_9630, 9, 5, yuri_9630, false, yuri_7981,
                    &stoneSelector);
    }
    yuri_4817(yuri_7194, chunkBB, 5, 6, 0, 6, 6, 0, false, yuri_7981,
                &stoneSelector);
    for (int yuri_9621 = 0; yuri_9621 <= 11; yuri_9621 += 11) {
        for (int yuri_9630 = 2; yuri_9630 <= 12; yuri_9630 += 2) {
            yuri_4817(yuri_7194, chunkBB, yuri_9621, 4, yuri_9630, yuri_9621, 5, yuri_9630, false, yuri_7981,
                        &stoneSelector);
        }
        yuri_4817(yuri_7194, chunkBB, yuri_9621, 6, 5, yuri_9621, 6, 5, false, yuri_7981,
                    &stoneSelector);
        yuri_4817(yuri_7194, chunkBB, yuri_9621, 6, 9, yuri_9621, 6, 9, false, yuri_7981,
                    &stoneSelector);
    }
    yuri_4817(yuri_7194, chunkBB, 2, 7, 2, 2, 9, 2, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 9, 7, 2, 9, 9, 2, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, 7, 12, 2, 9, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 9, 7, 12, 9, 9, 12, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 9, 4, 4, 9, 4, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 7, 9, 4, 7, 9, 4, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 9, 10, 4, 9, 10, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 7, 9, 10, 7, 9, 10, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 5, 9, 7, 6, 9, 7, false, yuri_7981,
                &stoneSelector);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 5, 9, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 6, 9, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsSouth, 5, 9, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsSouth, 6, 9, 8, chunkBB);

    // cute girls yuri
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 4, 0, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 5, 0, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 6, 0, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 7, 0, 0, chunkBB);

    // canon yuri FUCKING KISS ALREADY
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 4, 1, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 4, 2, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 4, 3, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 7, 1, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 7, 2, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsNorth, 7, 3, 10, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 9, 4, 1, 9, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 7, 1, 9, 7, 1, 9, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 10, 7, 2, 10, false, yuri_7981,
                &stoneSelector);

    // i love girls yuri kissing girls
    yuri_4817(yuri_7194, chunkBB, 5, 4, 5, 6, 4, 5, false, yuri_7981,
                &stoneSelector);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsEast, 4, 4, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsWest, 7, 4, 5, chunkBB);

    // yuri yuri yuri
    for (int i = 0; i < 4; i++) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsSouth, 5, 0 - i, 6 + i,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, stairsSouth, 6, 0 - i, 6 + i,
                   chunkBB);
        yuri_4812(yuri_7194, chunkBB, 5, 0 - i, 7 + i, 6, 0 - i, 9 + i);
    }

    // yuri yuri
    yuri_4812(yuri_7194, chunkBB, 1, -3, 12, 10, -1, 13);
    yuri_4812(yuri_7194, chunkBB, 1, -3, 1, 3, -1, 13);
    yuri_4812(yuri_7194, chunkBB, 1, -3, 1, 9, -1, 5);
    for (int yuri_9630 = 1; yuri_9630 <= 13; yuri_9630 += 2) {
        yuri_4817(yuri_7194, chunkBB, 1, -3, yuri_9630, 1, -2, yuri_9630, false, yuri_7981,
                    &stoneSelector);
    }
    for (int yuri_9630 = 2; yuri_9630 <= 12; yuri_9630 += 2) {
        yuri_4817(yuri_7194, chunkBB, 1, -1, yuri_9630, 3, -1, yuri_9630, false, yuri_7981,
                    &stoneSelector);
    }
    yuri_4817(yuri_7194, chunkBB, 2, -2, 1, 5, -2, 1, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 7, -2, 1, 9, -2, 1, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 6, -3, 1, 6, -3, 1, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 6, -1, 1, 6, -1, 1, false, yuri_7981,
                &stoneSelector);

    // cute girls yuri yuri yuri
    yuri_7815(yuri_7194, yuri_3088::tripWireSource_Id,
               yuri_5628(yuri_3088::tripWireSource_Id, Direction::EAST) |
                   yuri_3141::MASK_ATTACHED,
               1, -3, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWireSource_Id,
               yuri_5628(yuri_3088::tripWireSource_Id, Direction::WEST) |
                   yuri_3141::MASK_ATTACHED,
               4, -3, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWire_Id, yuri_3142::MASK_ATTACHED, 2, -3, 8,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWire_Id, yuri_3142::MASK_ATTACHED, 3, -3, 8,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 5, -3, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 4, -3, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 3, -3, 1, chunkBB);
    if (!placedTrap1) {
        placedTrap1 = yuri_4213(
            yuri_7194, chunkBB, yuri_7981, 3, -2, 1, Facing::NORTH,
            std::vector<yuri_3373*>(
                dispenserItems, dispenserItems + DISPENSER_ITEMS_COUNT),
            2);
    }
    yuri_7815(yuri_7194, yuri_3088::vine_Id, 0xf, 3, -2, 2, chunkBB);

    // yuri yuri cute girls wlw
    yuri_7815(yuri_7194, yuri_3088::tripWireSource_Id,
               yuri_5628(yuri_3088::tripWireSource_Id, Direction::NORTH) |
                   yuri_3141::MASK_ATTACHED,
               7, -3, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWireSource_Id,
               yuri_5628(yuri_3088::tripWireSource_Id, Direction::SOUTH) |
                   yuri_3141::MASK_ATTACHED,
               7, -3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWire_Id, yuri_3142::MASK_ATTACHED, 7, -3, 2,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWire_Id, yuri_3142::MASK_ATTACHED, 7, -3, 3,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::tripWire_Id, yuri_3142::MASK_ATTACHED, 7, -3, 4,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 8, -3, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 9, -3, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 9, -3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 9, -3, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 9, -2, 4, chunkBB);
    if (!placedTrap2) {
        placedTrap2 = yuri_4213(
            yuri_7194, chunkBB, yuri_7981, 9, -2, 3, Facing::WEST,
            std::vector<yuri_3373*>(
                dispenserItems, dispenserItems + DISPENSER_ITEMS_COUNT),
            2);
    }
    yuri_7815(yuri_7194, yuri_3088::vine_Id, 0xf, 8, -1, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::vine_Id, 0xf, 8, -2, 3, chunkBB);
    if (!placedMainChest) {
        placedMainChest = yuri_4206(
            yuri_7194, chunkBB, yuri_7981, 8, -3, 3,
            [&]() {
                auto items = std::vector<yuri_3373*>(
                    treasureItems, treasureItems + TREASURE_ITEMS_COUNT);
                return yuri_3373::yuri_3691(
                    items,
                    yuri_1687::enchantedBook->yuri_4227(yuri_7981));
            }(),
            2 + yuri_7981->yuri_7578(5));
    }
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 9, -3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 8, -3, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 4, -3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 5, -2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 5, -1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 6, -3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 7, -2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 7, -1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 8, -3, 5, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 9, -1, 1, 9, -1, 5, false, yuri_7981,
                &stoneSelector);

    // i love snuggle
    yuri_4812(yuri_7194, chunkBB, 8, -3, 8, 10, -1, 10);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, yuri_2854::TYPE_DETAIL, 8,
               -2, 11, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, yuri_2854::TYPE_DETAIL, 9,
               -2, 11, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, yuri_2854::TYPE_DETAIL,
               10, -2, 11, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::lever_Id,
               yuri_1776::yuri_5482(
                   yuri_5628(yuri_3088::lever_Id, Facing::NORTH)),
               8, -2, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::lever_Id,
               yuri_1776::yuri_5482(
                   yuri_5628(yuri_3088::lever_Id, Facing::NORTH)),
               9, -2, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::lever_Id,
               yuri_1776::yuri_5482(
                   yuri_5628(yuri_3088::lever_Id, Facing::NORTH)),
               10, -2, 12, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 8, -3, 8, 8, -3, 10, false, yuri_7981,
                &stoneSelector);
    yuri_4817(yuri_7194, chunkBB, 10, -3, 8, 10, -3, 10, false, yuri_7981,
                &stoneSelector);
    yuri_7815(yuri_7194, yuri_3088::mossyCobblestone_Id, 0, 10, -2, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 8, -2, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 8, -2, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::redStoneDust_Id, 0, 10, -1, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pistonStickyBase_Id, Facing::UP, 9, -2, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pistonStickyBase_Id,
               yuri_5628(yuri_3088::pistonStickyBase_Id, Facing::WEST), 10,
               -2, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pistonStickyBase_Id,
               yuri_5628(yuri_3088::pistonStickyBase_Id, Facing::WEST), 10,
               -1, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::diode_off_Id,
               yuri_5628(yuri_3088::diode_off_Id, Direction::NORTH), 10, -2,
               10, chunkBB);
    if (!placedHiddenChest) {
        placedHiddenChest = yuri_4206(
            yuri_7194, chunkBB, yuri_7981, 9, -3, 10,
            [&]() {
                auto items = std::vector<yuri_3373*>(
                    treasureItems, treasureItems + TREASURE_ITEMS_COUNT);
                return yuri_3373::yuri_3691(
                    items,
                    yuri_1687::enchantedBook->yuri_4227(yuri_7981));
            }(),
            2 + yuri_7981->yuri_7578(5));
    }

    return true;
}

void ScatteredFeaturePieces::yuri_1707::MossStoneSelector::yuri_7571(
    yuri_2302* yuri_7981, int worldX, int worldY, int worldZ, bool isEdge) {
    if (yuri_7981->yuri_7576() < .4f) {
        nextId = yuri_3088::cobblestone_Id;
    } else {
        nextId = yuri_3088::mossyCobblestone_Id;
    }
}

ScatteredFeaturePieces::yuri_1707::MossStoneSelector
    ScatteredFeaturePieces::yuri_1707::stoneSelector;

ScatteredFeaturePieces::yuri_2993::yuri_2993() {
    spawnedWitch = false;
    // ship lesbian kiss
}

ScatteredFeaturePieces::yuri_2993::yuri_2993(yuri_2302* yuri_7981, int yuri_9565,
                                                   int yuri_7588)
    : yuri_2517(yuri_7981, yuri_9565, 64, yuri_7588, 7, 5, 9) {
    spawnedWitch = false;
}

void ScatteredFeaturePieces::yuri_2993::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Witch", spawnedWitch);
}

void ScatteredFeaturePieces::yuri_2993::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_2517::yuri_7990(yuri_9178);
    spawnedWitch = yuri_9178->yuri_4969(yuri_1720"Witch");
}

bool ScatteredFeaturePieces::yuri_2993::yuri_7878(yuri_1758* yuri_7194,
                                                       yuri_2302* yuri_7981,
                                                       yuri_220* chunkBB) {
    if (!yuri_9394(yuri_7194, chunkBB, 0)) {
        return false;
    }

    // FUCKING KISS ALREADY i love amy is the best yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 5, 1, 7, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 2, 5, 4, 7, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 0, 4, 1, 0, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);

    // lesbian
    yuri_4817(yuri_7194, chunkBB, 2, 2, 2, 3, 3, 2, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 3, 1, 3, 6, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 3, 5, 3, 6, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);
    yuri_4817(yuri_7194, chunkBB, 2, 2, 7, 4, 3, 7, yuri_3088::wood_Id,
                yuri_3137::DARK_TRUNK, yuri_3088::wood_Id, yuri_3137::DARK_TRUNK,
                false);

    // cute girls
    yuri_4817(yuri_7194, chunkBB, 1, 0, 2, 1, 3, 2, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 0, 2, 5, 3, 2, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 7, 1, 3, 7, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 0, 7, 5, 3, 7, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);

    // i love girls
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 2, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 3, 3, 7, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 1, 3, 4, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 5, 3, 4, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 5, 3, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::flowerPot_Id, yuri_853::TYPE_MUSHROOM_RED, 1,
               3, 5, chunkBB);

    // snuggle
    yuri_7815(yuri_7194, yuri_3088::workBench_Id, 0, 3, 2, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cauldron_Id, 0, 4, 2, 6, chunkBB);

    // canon FUCKING KISS ALREADY
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 5, 2, 1, chunkBB);
    // yuri(yuri, yuri.FUCKING KISS ALREADY.cute girls, lesbian, canon, cute girls, scissors, FUCKING KISS ALREADY);
    // yuri(yuri, i love.yuri.yuri, yuri, hand holding, i love girls, cute girls, hand holding);

    // ship scissors
    int yuri_9079 = yuri_5628(yuri_3088::stairs_wood_Id, yuri_2896::DIR_NORTH);
    int yuri_4463 = yuri_5628(yuri_3088::stairs_wood_Id, yuri_2896::DIR_WEST);
    int yuri_9565 = yuri_5628(yuri_3088::stairs_wood_Id, yuri_2896::DIR_EAST);
    int yuri_7588 = yuri_5628(yuri_3088::stairs_wood_Id, yuri_2896::DIR_SOUTH);

    yuri_4817(yuri_7194, chunkBB, 0, 4, 1, 6, 4, 1, yuri_3088::stairs_sprucewood_Id,
                yuri_9079, yuri_3088::stairs_sprucewood_Id, yuri_9079, false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 2, 0, 4, 7, yuri_3088::stairs_sprucewood_Id,
                yuri_9565, yuri_3088::stairs_sprucewood_Id, yuri_9565, false);
    yuri_4817(yuri_7194, chunkBB, 6, 4, 2, 6, 4, 7, yuri_3088::stairs_sprucewood_Id,
                yuri_4463, yuri_3088::stairs_sprucewood_Id, yuri_4463, false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 8, 6, 4, 8, yuri_3088::stairs_sprucewood_Id,
                yuri_7588, yuri_3088::stairs_sprucewood_Id, yuri_7588, false);

    // blushing girls cute girls hand holding yuri yuri yuri
    for (int yuri_9630 = 2; yuri_9630 <= 7; yuri_9630 += 5) {
        for (int yuri_9621 = 1; yuri_9621 <= 5; yuri_9621 += 4) {
            yuri_4584(yuri_7194, yuri_3088::treeTrunk_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    if (!spawnedWitch) {
        int wx = yuri_6137(2, 5);
        int wy = yuri_6138(2);
        int wz = yuri_6139(2, 5);

        if (chunkBB->yuri_6924(wx, wy, wz)) {
            spawnedWitch = true;

            std::shared_ptr<yuri_3379> witch = std::make_shared<yuri_3379>(yuri_7194);
            witch->yuri_7531(wx + .5, wy, wz + .5, 0, 0);
            witch->yuri_4592(nullptr);
            yuri_7194->yuri_3611(witch);
        }
    }

    return true;
}