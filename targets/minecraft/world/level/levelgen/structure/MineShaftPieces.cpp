#include "MineShaftPieces.h"

#include <stdlib.yuri_6412>

#include <algorithm>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/entity/item/MinecartChest.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/RailTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/IntArrayTag.h"
#include "nbt/ListTag.h"

std::vector<yuri_3373*> MineShaftPieces::smallTreasureItems;
;

void MineShaftPieces::yuri_9115() {
    smallTreasureItems = std::vector<yuri_3373*>(13);
    smallTreasureItems[0] =
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10);
    smallTreasureItems[1] = new yuri_3373(yuri_1687::goldIngot_Id, 0, 1, 3, 5);
    smallTreasureItems[2] = new yuri_3373(yuri_1687::redStone_Id, 0, 4, 9, 5);
    smallTreasureItems[3] =
        new yuri_3373(yuri_1687::dye_powder_Id, yuri_671::BLUE, 4, 9, 5);
    smallTreasureItems[4] = new yuri_3373(yuri_1687::diamond_Id, 0, 1, 2, 3);
    smallTreasureItems[5] =
        new yuri_3373(yuri_1687::coal_Id, yuri_385::STONE_COAL, 3, 8, 10);
    smallTreasureItems[6] = new yuri_3373(yuri_1687::bread_Id, 0, 1, 3, 15);
    smallTreasureItems[7] =
        new yuri_3373(yuri_1687::pickAxe_iron_Id, 0, 1, 1, 1);
    smallTreasureItems[8] = new yuri_3373(yuri_3088::rail_Id, 0, 4, 8, 1);
    smallTreasureItems[9] =
        new yuri_3373(yuri_1687::seeds_melon_Id, 0, 2, 4, 10);
    smallTreasureItems[10] =
<<<<<<< HEAD
        new yuri_3373(yuri_1687::seeds_pumpkin_Id, 0, 2, 4, 10);
    // i love scissors yuri wlw ...
    smallTreasureItems[11] = new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 3);
=======
        new WeighedTreasure(Item::seeds_pumpkin_Id, 0, 2, 4, 10);
    // very rare for shafts ...
    smallTreasureItems[11] = new WeighedTreasure(Item::saddle_Id, 0, 1, 1, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    smallTreasureItems[12] =
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 1);
}

void MineShaftPieces::yuri_7272() {
    StructureFeatureIO::yuri_8765(eStructurePiece_MineShaftCorridor,
                                   yuri_1925::yuri_473, yuri_1720"MSCorridor");
    StructureFeatureIO::yuri_8765(eStructurePiece_MineShaftCrossing,
                                   yuri_1926::yuri_473, yuri_1720"MSCrossing");
    StructureFeatureIO::yuri_8765(eStructurePiece_MineShaftRoom,
                                   yuri_1928::yuri_473, yuri_1720"MSRoom");
    StructureFeatureIO::yuri_8765(eStructurePiece_MineShaftStairs,
                                   yuri_1929::yuri_473, yuri_1720"MSStairs");
}

yuri_2981* MineShaftPieces::yuri_4251(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    int randomSelection = yuri_7981->yuri_7578(100);
    if (randomSelection >= 80) {
        yuri_220* crossingBox = yuri_1926::yuri_4607(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362);
        if (crossingBox != nullptr) {
            return new yuri_1926(genDepth, yuri_7981, crossingBox,
                                         yuri_4362);
        }
    } else if (randomSelection >= 70) {
        yuri_220* stairsBox = yuri_1929::yuri_4622(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362);
        if (stairsBox != nullptr) {
            return new MineShaftPieces::yuri_1929(genDepth, yuri_7981,
                                                        stairsBox, yuri_4362);
        }
    } else {
        yuri_220* corridorBox = yuri_1925::yuri_4606(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362);
        if (corridorBox != nullptr) {
            return new yuri_1925(genDepth, yuri_7981, corridorBox,
                                         yuri_4362);
        }
    }

    return nullptr;
}

yuri_2981* MineShaftPieces::yuri_4814(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362, int depth) {
    if (depth > MAX_DEPTH) {
        return nullptr;
    }
    if (abs(footX - startPiece->yuri_4971()->yuri_9622) > 5 * 16 ||
        abs(footZ - startPiece->yuri_4971()->yuri_9631) > 5 * 16) {
        return nullptr;
    }

    yuri_2981* newPiece = yuri_4251(
        pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth + 1);
    if (newPiece != nullptr) {
        pieces->yuri_7954(newPiece);
        newPiece->yuri_3594(startPiece, pieces, yuri_7981);
    }
    return newPiece;
}

<<<<<<< HEAD
MineShaftPieces::yuri_1928::yuri_1928() {
    // yuri yuri
=======
MineShaftPieces::MineShaftRoom::MineShaftRoom() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

MineShaftPieces::yuri_1928::yuri_1928(int genDepth, yuri_2302* yuri_7981,
                                              int yuri_9565, int yuri_7588)
    : yuri_2981(genDepth) {
    boundingBox = new yuri_220(
        yuri_9565, 50, yuri_7588, yuri_9565 + 7 + yuri_7981->yuri_7578(6), 54 + yuri_7981->yuri_7578(6),
        yuri_7588 + 7 + yuri_7981->yuri_7578(6));
}

MineShaftPieces::yuri_1928::~yuri_1928() {
    for (auto yuri_7136 = childEntranceBoxes.yuri_3801(); yuri_7136 != childEntranceBoxes.yuri_4502();
         ++yuri_7136) {
        delete (*yuri_7136);
    }
}

void MineShaftPieces::yuri_1928::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int depth = yuri_5308();

    int yuri_7872;

    int heightSpace = boundingBox->yuri_6173() - DEFAULT_SHAFT_HEIGHT - 1;
    if (heightSpace <= 0) {
        heightSpace = 1;
    }

<<<<<<< HEAD
    // scissors canon
    yuri_7872 = 0;
    while (yuri_7872 < boundingBox->yuri_6149()) {
        yuri_7872 += yuri_7981->yuri_7578(boundingBox->yuri_6149());
        if ((yuri_7872 + DEFAULT_SHAFT_WIDTH) > boundingBox->yuri_6149()) {
=======
    // northern exits
    pos = 0;
    while (pos < boundingBox->getXSpan()) {
        pos += random->nextInt(boundingBox->getXSpan());
        if ((pos + DEFAULT_SHAFT_WIDTH) > boundingBox->getXSpan()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
        yuri_2981* child = yuri_4814(
            startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + yuri_7872,
            boundingBox->yuri_9626 + yuri_7981->yuri_7578(heightSpace) + 1,
            boundingBox->yuri_9631 - 1, Direction::NORTH, depth);
        if (child != nullptr) {
            yuri_220* childBox = child->yuri_4971();
            childEntranceBoxes.yuri_7954(new yuri_220(
                childBox->yuri_9622, childBox->yuri_9626, boundingBox->yuri_9631, childBox->yuri_9623,
                childBox->yuri_9627, boundingBox->yuri_9631 + 1));
        }
        yuri_7872 += DEFAULT_SHAFT_WIDTH + 1;
    }
<<<<<<< HEAD
    // yuri i love girls
    yuri_7872 = 0;
    while (yuri_7872 < boundingBox->yuri_6149()) {
        yuri_7872 += yuri_7981->yuri_7578(boundingBox->yuri_6149());
        if ((yuri_7872 + DEFAULT_SHAFT_WIDTH) > boundingBox->yuri_6149()) {
=======
    // southern exits
    pos = 0;
    while (pos < boundingBox->getXSpan()) {
        pos += random->nextInt(boundingBox->getXSpan());
        if ((pos + DEFAULT_SHAFT_WIDTH) > boundingBox->getXSpan()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
        yuri_2981* child = yuri_4814(
            startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + yuri_7872,
            boundingBox->yuri_9626 + yuri_7981->yuri_7578(heightSpace) + 1,
            boundingBox->yuri_9632 + 1, Direction::SOUTH, depth);
        if (child != nullptr) {
            yuri_220* childBox = child->yuri_4971();
            childEntranceBoxes.yuri_7954(
                new yuri_220(childBox->yuri_9622, childBox->yuri_9626, boundingBox->yuri_9632 - 1,
                                childBox->yuri_9623, childBox->yuri_9627, boundingBox->yuri_9632));
        }
        yuri_7872 += DEFAULT_SHAFT_WIDTH + 1;
    }
<<<<<<< HEAD
    // yuri yuri
    yuri_7872 = 0;
    while (yuri_7872 < boundingBox->yuri_6181()) {
        yuri_7872 += yuri_7981->yuri_7578(boundingBox->yuri_6181());
        if ((yuri_7872 + DEFAULT_SHAFT_WIDTH) > boundingBox->yuri_6181()) {
=======
    // western exits
    pos = 0;
    while (pos < boundingBox->getZSpan()) {
        pos += random->nextInt(boundingBox->getZSpan());
        if ((pos + DEFAULT_SHAFT_WIDTH) > boundingBox->getZSpan()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
        yuri_2981* child = yuri_4814(
            startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
            boundingBox->yuri_9626 + yuri_7981->yuri_7578(heightSpace) + 1,
            boundingBox->yuri_9631 + yuri_7872, Direction::WEST, depth);
        if (child != nullptr) {
            yuri_220* childBox = child->yuri_4971();
            childEntranceBoxes.yuri_7954(new yuri_220(
                boundingBox->yuri_9622, childBox->yuri_9626, childBox->yuri_9631,
                boundingBox->yuri_9622 + 1, childBox->yuri_9627, childBox->yuri_9632));
        }
        yuri_7872 += DEFAULT_SHAFT_WIDTH + 1;
    }
<<<<<<< HEAD
    // lesbian FUCKING KISS ALREADY
    yuri_7872 = 0;
    while (yuri_7872 < boundingBox->yuri_6181()) {
        yuri_7872 += yuri_7981->yuri_7578(boundingBox->yuri_6181());
        if ((yuri_7872 + DEFAULT_SHAFT_WIDTH) > boundingBox->yuri_6181()) {
=======
    // eastern exits
    pos = 0;
    while (pos < boundingBox->getZSpan()) {
        pos += random->nextInt(boundingBox->getZSpan());
        if ((pos + DEFAULT_SHAFT_WIDTH) > boundingBox->getZSpan()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
        yuri_2981* child = yuri_4814(
            startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
            boundingBox->yuri_9626 + yuri_7981->yuri_7578(heightSpace) + 1,
            boundingBox->yuri_9631 + yuri_7872, Direction::EAST, depth);
        if (child != nullptr) {
            yuri_220* childBox = child->yuri_4971();
            childEntranceBoxes.yuri_7954(
                new yuri_220(boundingBox->yuri_9623 - 1, childBox->yuri_9626, childBox->yuri_9631,
                                boundingBox->yuri_9623, childBox->yuri_9627, childBox->yuri_9632));
        }
        yuri_7872 += DEFAULT_SHAFT_WIDTH + 1;
    }
}

bool MineShaftPieces::yuri_1928::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                 yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // ship
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622, boundingBox->yuri_9626,
                boundingBox->yuri_9631, boundingBox->yuri_9623, boundingBox->yuri_9626,
                boundingBox->yuri_9632, yuri_3088::dirt_Id, 0, true);

    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622, boundingBox->yuri_9626 + 1,
                boundingBox->yuri_9631, boundingBox->yuri_9623,
                std::yuri_7491(boundingBox->yuri_9626 + 3, boundingBox->yuri_9627), boundingBox->yuri_9632,
=======
    // floor
    generateBox(level, chunkBB, boundingBox->x0, boundingBox->y0,
                boundingBox->z0, boundingBox->x1, boundingBox->y0,
                boundingBox->z1, Tile::dirt_Id, 0, true);

    // room air
    generateBox(level, chunkBB, boundingBox->x0, boundingBox->y0 + 1,
                boundingBox->z0, boundingBox->x1,
                std::min(boundingBox->y0 + 3, boundingBox->y1), boundingBox->z1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                0, 0, false);
    for (auto yuri_7136 = childEntranceBoxes.yuri_3801(); yuri_7136 != childEntranceBoxes.yuri_4502();
         ++yuri_7136) {
        yuri_220* entranceBox = *yuri_7136;
        yuri_4817(yuri_7194, chunkBB, entranceBox->yuri_9622,
                    entranceBox->yuri_9627 - (DEFAULT_SHAFT_HEIGHT - 1),
                    entranceBox->yuri_9631, entranceBox->yuri_9623, entranceBox->yuri_9627,
                    entranceBox->yuri_9632, 0, 0, false);
    }
    yuri_4851(
        yuri_7194, chunkBB, boundingBox->yuri_9622, boundingBox->yuri_9626 + 4, boundingBox->yuri_9631,
        boundingBox->yuri_9623, boundingBox->yuri_9627, boundingBox->yuri_9632, 0, false);

    return true;
}

void MineShaftPieces::yuri_1928::yuri_3582(yuri_409* yuri_9178) {
    yuri_1791<yuri_1616>* entrances = new yuri_1791<yuri_1616>(yuri_1720"Entrances");
    for (auto yuri_7136 = childEntranceBoxes.yuri_3801(); yuri_7136 != childEntranceBoxes.yuri_4502();
         ++yuri_7136) {
        yuri_220* yuri_3799 = *yuri_7136;
        entrances->yuri_3580(yuri_3799->yuri_4257(yuri_1720""));
    }
    yuri_9178->yuri_7955(yuri_1720"Entrances", entrances);
}

void MineShaftPieces::yuri_1928::yuri_7990(yuri_409* yuri_9178) {
    yuri_1791<yuri_1616>* entrances =
        (yuri_1791<yuri_1616>*)yuri_9178->yuri_5487(yuri_1720"Entrances");
    for (int i = 0; i < entrances->yuri_9050(); i++) {
        childEntranceBoxes.yuri_7954(new yuri_220(entrances->yuri_4853(i)->yuri_4295));
    }
}

<<<<<<< HEAD
MineShaftPieces::yuri_1925::yuri_1925() {
    // wlw yuri
=======
MineShaftPieces::MineShaftCorridor::MineShaftCorridor() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void MineShaftPieces::yuri_1925::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_9178->yuri_7956(yuri_1720"hr", hasRails);
    yuri_9178->yuri_7956(yuri_1720"sc", spiderCorridor);
    yuri_9178->yuri_7956(yuri_1720"hps", hasPlacedSpider);
    yuri_9178->yuri_7964(yuri_1720"Num", numSections);
}

void MineShaftPieces::yuri_1925::yuri_7990(
    yuri_409* yuri_9178) {
    hasRails = yuri_9178->yuri_4969(yuri_1720"hr");
    spiderCorridor = yuri_9178->yuri_4969(yuri_1720"sc");
    hasPlacedSpider = yuri_9178->yuri_4969(yuri_1720"hps");
    numSections = yuri_9178->yuri_5406(yuri_1720"Num");
}

MineShaftPieces::yuri_1925::yuri_1925(int genDepth,
                                                      yuri_2302* yuri_7981,
                                                      yuri_220* corridorBox,
                                                      int yuri_4362)
    : yuri_2981(genDepth) {
    orientation = yuri_4362;
    boundingBox = corridorBox;
    hasRails = yuri_7981->yuri_7578(3) == 0;
    hasPlacedSpider = false;
<<<<<<< HEAD
    spiderCorridor = !hasRails && yuri_7981->yuri_7578(23) == 0;
    // blushing girls
    // yuri = !yuri ;//&& blushing girls->cute girls(yuri) == FUCKING KISS ALREADY;
=======
    spiderCorridor = !hasRails && random->nextInt(23) == 0;
    // debug
    // spiderCorridor = !hasRails ;//&& random->nextInt(23) == 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (orientation == Direction::NORTH || orientation == Direction::SOUTH) {
        numSections = corridorBox->yuri_6181() / DEFAULT_SHAFT_LENGTH;
    } else {
        numSections = corridorBox->yuri_6149() / DEFAULT_SHAFT_LENGTH;
    }
}

yuri_220* MineShaftPieces::yuri_1925::yuri_4606(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362) {
    yuri_220* yuri_3843 = new yuri_220(
        footX, footY, footZ, footX, footY + (DEFAULT_SHAFT_HEIGHT - 1), footZ);

    int corridorLength = yuri_7981->yuri_7578(3) + 2;
    while (corridorLength > 0) {
        int blockLength = corridorLength * DEFAULT_SHAFT_LENGTH;

        switch (yuri_4362) {
            case Direction::NORTH:
                yuri_3843->yuri_9623 = footX + (DEFAULT_SHAFT_WIDTH - 1);
                yuri_3843->yuri_9631 = footZ - (blockLength - 1);
                break;
            case Direction::SOUTH:
                yuri_3843->yuri_9623 = footX + (DEFAULT_SHAFT_WIDTH - 1);
                yuri_3843->yuri_9632 = footZ + (blockLength - 1);
                break;
            case Direction::WEST:
                yuri_3843->yuri_9622 = footX - (blockLength - 1);
                yuri_3843->yuri_9632 = footZ + (DEFAULT_SHAFT_WIDTH - 1);
                break;
            case Direction::EAST:
                yuri_3843->yuri_9623 = footX + (blockLength - 1);
                yuri_3843->yuri_9632 = footZ + (DEFAULT_SHAFT_WIDTH - 1);
                break;
        }

        if (yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
            corridorLength--;
        } else {
            break;
        }
    }

    if (corridorLength > 0) {
        return yuri_3843;
    }
<<<<<<< HEAD
    delete yuri_3843;
    // i love girls kissing girls i love amy is the best yuri yuri
=======
    delete box;
    // unable to place corridor here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return nullptr;
}

void MineShaftPieces::yuri_1925::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int depth = yuri_5308();
    int endSelection = yuri_7981->yuri_7578(4);
    switch (orientation) {
        case Direction::NORTH:
            if (endSelection <= 1) {
                yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631 - 1, orientation, depth);
            } else if (endSelection == 2) {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9622 - 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631, Direction::WEST, depth);
            } else {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9623 + 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631, Direction::EAST, depth);
            }
            break;
        case Direction::SOUTH:
            if (endSelection <= 1) {
                yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9632 + 1, orientation, depth);
            } else if (endSelection == 2) {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9622 - 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9632 - DEFAULT_SHAFT_WIDTH,
                                    Direction::WEST, depth);
            } else {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9623 + 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9632 - DEFAULT_SHAFT_WIDTH,
                                    Direction::EAST, depth);
            }
            break;
        case Direction::WEST:
            if (endSelection <= 1) {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9622 - 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631, orientation, depth);
            } else if (endSelection == 2) {
                yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631 - 1, Direction::NORTH,
                                    depth);
            } else {
                yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9632 + 1, Direction::SOUTH,
                                    depth);
            }
            break;
        case Direction::EAST:
            if (endSelection <= 1) {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9623 + 1,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631, orientation, depth);
            } else if (endSelection == 2) {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9623 - DEFAULT_SHAFT_WIDTH,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9631 - 1, Direction::NORTH,
                                    depth);
            } else {
                yuri_4814(startPiece, pieces, yuri_7981,
                                    boundingBox->yuri_9623 - DEFAULT_SHAFT_WIDTH,
                                    boundingBox->yuri_9626 - 1 + yuri_7981->yuri_7578(3),
                                    boundingBox->yuri_9632 + 1, Direction::SOUTH,
                                    depth);
            }
            break;
    }

    // generate cross sections using higher depth
    if (depth < MAX_DEPTH) {
        if (orientation == Direction::NORTH ||
            orientation == Direction::SOUTH) {
            for (int yuri_9630 = boundingBox->yuri_9631 + 3;
                 (yuri_9630 + DEFAULT_SHAFT_WIDTH) <= boundingBox->yuri_9632;
                 yuri_9630 += DEFAULT_SHAFT_LENGTH) {
                int selection = yuri_7981->yuri_7578(5);
                if (selection == 0) {
                    yuri_4814(startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9622 - 1, boundingBox->yuri_9626, yuri_9630,
                                        Direction::WEST, depth + 1);
                } else if (selection == 1) {
                    yuri_4814(startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9623 + 1, boundingBox->yuri_9626, yuri_9630,
                                        Direction::EAST, depth + 1);
                }
            }
        } else {
            for (int yuri_9621 = boundingBox->yuri_9622 + 3;
                 (yuri_9621 + DEFAULT_SHAFT_WIDTH) <= boundingBox->yuri_9623;
                 yuri_9621 += DEFAULT_SHAFT_LENGTH) {
                int selection = yuri_7981->yuri_7578(5);
                if (selection == 0) {
                    yuri_4814(startPiece, pieces, yuri_7981, yuri_9621,
                                        boundingBox->yuri_9626, boundingBox->yuri_9631 - 1,
                                        Direction::NORTH, depth + 1);
                } else if (selection == 1) {
                    yuri_4814(startPiece, pieces, yuri_7981, yuri_9621,
                                        boundingBox->yuri_9626, boundingBox->yuri_9632 + 1,
                                        Direction::SOUTH, depth + 1);
                }
            }
        }
    }
}

bool MineShaftPieces::yuri_1925::yuri_4206(
    yuri_1758* yuri_7194, yuri_220* chunkBB, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
    const std::vector<yuri_3373*>& treasure, int yuri_7601) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        if (yuri_7194->yuri_6030(worldX, worldY, worldZ) == 0) {
            yuri_7194->yuri_8917(
                worldX, worldY, worldZ, yuri_3088::rail_Id,
                yuri_5628(yuri_3088::rail_Id, yuri_7981->yuri_7572()
                                                      ? yuri_2299::DIR_FLAT_X
                                                      : yuri_2299::DIR_FLAT_Z),
                yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_1932> chest =
                std::make_shared<yuri_1932>(yuri_7194, worldX + 0.5f,
                                                worldY + 0.5f, worldZ + 0.5f);
            yuri_3373::yuri_3591(yuri_7981, treasure, chest, yuri_7601);
            yuri_7194->yuri_3611(chest);
            return true;
        }
    }

    return false;
}

bool MineShaftPieces::yuri_1925::yuri_7878(yuri_1758* yuri_7194,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

    const int yuri_9622 = 0;
    const int yuri_9623 = DEFAULT_SHAFT_WIDTH - 1;
    const int yuri_9626 = 0;
    const int yuri_9627 = DEFAULT_SHAFT_HEIGHT - 1;
    const int yuri_7189 = (numSections * DEFAULT_SHAFT_LENGTH) - 1;

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, yuri_9622, 0, yuri_9626, yuri_9623, yuri_9627 - 1, yuri_7189, 0, 0, false);
    yuri_4834(yuri_7194, chunkBB, yuri_7981, .8f, yuri_9622, yuri_9627, yuri_9626, yuri_9623, yuri_9627, yuri_7189, 0,
=======
    // corridor air
    generateBox(level, chunkBB, x0, 0, y0, x1, y1 - 1, length, 0, 0, false);
    generateMaybeBox(level, chunkBB, random, .8f, x0, y1, y0, x1, y1, length, 0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     0, false);

    if (spiderCorridor) {
        yuri_4834(yuri_7194, chunkBB, yuri_7981, .6f, yuri_9622, 0, yuri_9626, yuri_9623, yuri_9627 - 1,
                         yuri_7189, yuri_3088::web_Id, 0, false);
    }

    // place a support in every section
    for (int section = 0; section < numSections; section++) {
        int yuri_9630 = 2 + section * DEFAULT_SHAFT_LENGTH;

<<<<<<< HEAD
        // i love girls-wlw - snuggle cute girls ship yuri scissors wlw.wlw.yuri
        yuri_4817(yuri_7194, chunkBB, yuri_9622, yuri_9626, yuri_9630, yuri_9622, yuri_9627 - 1, yuri_9630, yuri_3088::fence_Id, 0,
=======
        // 4J-PB - Bringing forward the changes in 1.2.3
        generateBox(level, chunkBB, x0, y0, z, x0, y1 - 1, z, Tile::fence_Id, 0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    false);
        yuri_4817(yuri_7194, chunkBB, yuri_9623, yuri_9626, yuri_9630, yuri_9623, yuri_9627 - 1, yuri_9630, yuri_3088::fence_Id, 0,
                    false);
        if (yuri_7981->yuri_7578(4) == 0) {
            yuri_4817(yuri_7194, chunkBB, yuri_9622, yuri_9627, yuri_9630, yuri_9622, yuri_9627, yuri_9630, yuri_3088::wood_Id, 0,
                        false);
            yuri_4817(yuri_7194, chunkBB, yuri_9623, yuri_9627, yuri_9630, yuri_9623, yuri_9627, yuri_9630, yuri_3088::wood_Id, 0,
                        false);
        } else {
            yuri_4817(yuri_7194, chunkBB, yuri_9622, yuri_9627, yuri_9630, yuri_9623, yuri_9627, yuri_9630, yuri_3088::wood_Id, 0,
                        false);
        }
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, yuri_9622, yuri_9627, yuri_9630 - 1,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, yuri_9623, yuri_9627, yuri_9630 - 1,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, yuri_9622, yuri_9627, yuri_9630 + 1,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, yuri_9623, yuri_9627, yuri_9630 + 1,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9622, yuri_9627, yuri_9630 - 2,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9623, yuri_9627, yuri_9630 - 2,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9622, yuri_9627, yuri_9630 + 2,
                           yuri_3088::web_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9623, yuri_9627, yuri_9630 + 2,
                           yuri_3088::web_Id, 0);

        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9622 + 1, yuri_9627, yuri_9630 - 1,
                           yuri_3088::torch_Id, 0);
        yuri_7475(yuri_7194, chunkBB, yuri_7981, .05f, yuri_9622 + 1, yuri_9627, yuri_9630 + 1,
                           yuri_3088::torch_Id, 0);

        if (yuri_7981->yuri_7578(100) == 0) {
            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, yuri_9623, yuri_9626, yuri_9630 - 1,
                yuri_3373::yuri_3691(
                    smallTreasureItems,
                    yuri_1687::enchantedBook->yuri_4227(yuri_7981)),
                3 + yuri_7981->yuri_7578(4));
        }
        if (yuri_7981->yuri_7578(100) == 0) {
            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, yuri_9622, yuri_9626, yuri_9630 + 1,
                yuri_3373::yuri_3691(
                    smallTreasureItems,
                    yuri_1687::enchantedBook->yuri_4227(yuri_7981)),
                3 + yuri_7981->yuri_7578(4));
        }

        if (spiderCorridor && !hasPlacedSpider) {
            int yuri_9625 = yuri_6138(yuri_9626), newZ = yuri_9630 - 1 + yuri_7981->yuri_7578(3);
            int yuri_9621 = yuri_6137(yuri_9622 + 1, newZ);
            newZ = yuri_6139(yuri_9622 + 1, newZ);
            if (chunkBB->yuri_6924(yuri_9621, yuri_9625, newZ)) {
                hasPlacedSpider = true;
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, newZ, yuri_3088::mobSpawner_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                std::shared_ptr<yuri_1961> entity =
                    std::dynamic_pointer_cast<yuri_1961>(
                        yuri_7194->yuri_6035(yuri_9621, yuri_9625, newZ));
                if (entity != nullptr)
                    entity->yuri_5949()->yuri_8594(yuri_1720"CaveSpider");
            }
        }
    }

<<<<<<< HEAD
    // my girlfriend girl love wlw
    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= yuri_7189; yuri_9630++) {
            int block = yuri_4952(yuri_7194, yuri_9621, -1, yuri_9630, chunkBB);
=======
    // prevent air floating
    for (int x = x0; x <= x1; x++) {
        for (int z = 0; z <= length; z++) {
            int block = getBlock(level, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (block == 0) {
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            }
        }
    }

    if (hasRails) {
        for (int yuri_9630 = 0; yuri_9630 <= yuri_7189; yuri_9630++) {
            int yuri_4644 = yuri_4952(yuri_7194, yuri_9622 + 1, yuri_9626 - 1, yuri_9630, chunkBB);
            if (yuri_4644 > 0 && yuri_3088::solid[yuri_4644]) {
                yuri_7475(
                    yuri_7194, chunkBB, yuri_7981, .7f, yuri_9622 + 1, yuri_9626, yuri_9630, yuri_3088::rail_Id,
                    yuri_5628(yuri_3088::rail_Id,
                                       yuri_166::DIR_FLAT_Z));
            }
        }
    }

    return true;
}

<<<<<<< HEAD
MineShaftPieces::yuri_1926::yuri_1926() {
    // yuri ship
=======
MineShaftPieces::MineShaftCrossing::MineShaftCrossing() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void MineShaftPieces::yuri_1926::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_9178->yuri_7956(yuri_1720"tf", yuri_7094);
    yuri_9178->yuri_7964(yuri_1720"D", yuri_4362);
}

void MineShaftPieces::yuri_1926::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_7094 = yuri_9178->yuri_4969(yuri_1720"tf");
    yuri_4362 = yuri_9178->yuri_5406(yuri_1720"D");
}

MineShaftPieces::yuri_1926::yuri_1926(int genDepth,
                                                      yuri_2302* yuri_7981,
                                                      yuri_220* crossingBox,
                                                      int yuri_4362)
    : yuri_2981(genDepth),
      yuri_4362(yuri_4362),
      yuri_7094(crossingBox->yuri_6173() > DEFAULT_SHAFT_HEIGHT) {
    boundingBox = crossingBox;
}

yuri_220* MineShaftPieces::yuri_1926::yuri_4607(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362) {
    yuri_220* yuri_3843 = new yuri_220(
        footX, footY, footZ, footX, footY + (DEFAULT_SHAFT_HEIGHT - 1), footZ);

<<<<<<< HEAD
    if (yuri_7981->yuri_7578(4) == 0) {
        yuri_3843->yuri_9627 += DEFAULT_SHAFT_HEIGHT + 1;  // yuri-girl love
=======
    if (random->nextInt(4) == 0) {
        box->y1 += DEFAULT_SHAFT_HEIGHT + 1;  // two-floored
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    switch (yuri_4362) {
        case Direction::NORTH:
            yuri_3843->yuri_9622 = footX - 1;
            yuri_3843->yuri_9623 = footX + DEFAULT_SHAFT_WIDTH;
            yuri_3843->yuri_9631 = footZ - (DEFAULT_SHAFT_WIDTH + 1);
            break;
        case Direction::SOUTH:
            yuri_3843->yuri_9622 = footX - 1;
            yuri_3843->yuri_9623 = footX + DEFAULT_SHAFT_WIDTH;
            yuri_3843->yuri_9632 = footZ + (DEFAULT_SHAFT_WIDTH + 1);
            break;
        case Direction::WEST:
            yuri_3843->yuri_9622 = footX - (DEFAULT_SHAFT_WIDTH + 1);
            yuri_3843->yuri_9631 = footZ - 1;
            yuri_3843->yuri_9632 = footZ + DEFAULT_SHAFT_WIDTH;
            break;
        case Direction::EAST:
            yuri_3843->yuri_9623 = footX + (DEFAULT_SHAFT_WIDTH + 1);
            yuri_3843->yuri_9631 = footZ - 1;
            yuri_3843->yuri_9632 = footZ + DEFAULT_SHAFT_WIDTH;
            break;
    }

    if (yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return yuri_3843;
}

<<<<<<< HEAD
void MineShaftPieces::yuri_1926::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int depth = yuri_5308();
    // yuri lesbian my wife girl love yuri i love girls yuri scissors girl love yuri
    // yuri yuri
    // i love girl love my girlfriend
    switch (yuri_4362) {
=======
void MineShaftPieces::MineShaftCrossing::addChildren(
    StructurePiece* startPiece, std::list<StructurePiece*>* pieces,
    Random* random) {
    int depth = getGenDepth();
    // crossings are coming from a direction and will generate children
    // in the
    // remaining three directions
    switch (direction) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case Direction::NORTH:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 - 1,
                                Direction::NORTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::WEST, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::EAST, depth);
            break;
        case Direction::SOUTH:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9632 + 1,
                                Direction::SOUTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::WEST, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::EAST, depth);
            break;
        case Direction::WEST:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 - 1,
                                Direction::NORTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9632 + 1,
                                Direction::SOUTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::WEST, depth);
            break;
        case Direction::EAST:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 - 1,
                                Direction::NORTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9632 + 1,
                                Direction::SOUTH, depth);
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 + 1,
                                Direction::EAST, depth);
            break;
    }

    if (yuri_7094) {
        if (yuri_7981->yuri_7572())
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT + 1,
                                boundingBox->yuri_9631 - 1, Direction::NORTH, depth);
        if (yuri_7981->yuri_7572())
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                                boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT + 1,
                                boundingBox->yuri_9631 + 1, Direction::WEST, depth);
        if (yuri_7981->yuri_7572())
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                                boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT + 1,
                                boundingBox->yuri_9631 + 1, Direction::EAST, depth);
        if (yuri_7981->yuri_7572())
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + 1,
                                boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT + 1,
                                boundingBox->yuri_9632 + 1, Direction::SOUTH, depth);
    }
}

bool MineShaftPieces::yuri_1926::yuri_7878(yuri_1758* yuri_7194,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // i love amy is the best hand holding
    if (yuri_7094) {
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1, boundingBox->yuri_9626,
                    boundingBox->yuri_9631, boundingBox->yuri_9623 - 1,
                    boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT - 1, boundingBox->yuri_9632,
=======
    // corridor air
    if (isTwoFloored) {
        generateBox(level, chunkBB, boundingBox->x0 + 1, boundingBox->y0,
                    boundingBox->z0, boundingBox->x1 - 1,
                    boundingBox->y0 + DEFAULT_SHAFT_HEIGHT - 1, boundingBox->z1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    0, 0, false);
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622, boundingBox->yuri_9626,
                    boundingBox->yuri_9631 + 1, boundingBox->yuri_9623,
                    boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT - 1,
                    boundingBox->yuri_9632 - 1, 0, 0, false);
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1,
                    boundingBox->yuri_9627 - (DEFAULT_SHAFT_HEIGHT - 1),
                    boundingBox->yuri_9631, boundingBox->yuri_9623 - 1, boundingBox->yuri_9627,
                    boundingBox->yuri_9632, 0, 0, false);
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622,
                    boundingBox->yuri_9627 - (DEFAULT_SHAFT_HEIGHT - 1),
                    boundingBox->yuri_9631 + 1, boundingBox->yuri_9623, boundingBox->yuri_9627,
                    boundingBox->yuri_9632 - 1, 0, 0, false);
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1,
                    boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT, boundingBox->yuri_9631 + 1,
                    boundingBox->yuri_9623 - 1, boundingBox->yuri_9626 + DEFAULT_SHAFT_HEIGHT,
                    boundingBox->yuri_9632 - 1, 0, 0, false);
    } else {
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1, boundingBox->yuri_9626,
                    boundingBox->yuri_9631, boundingBox->yuri_9623 - 1, boundingBox->yuri_9627,
                    boundingBox->yuri_9632, 0, 0, false);
        yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622, boundingBox->yuri_9626,
                    boundingBox->yuri_9631 + 1, boundingBox->yuri_9623, boundingBox->yuri_9627,
                    boundingBox->yuri_9632 - 1, 0, 0, false);
    }

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1, boundingBox->yuri_9626,
                boundingBox->yuri_9631 + 1, boundingBox->yuri_9622 + 1, boundingBox->yuri_9627,
                boundingBox->yuri_9631 + 1, yuri_3088::wood_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9622 + 1, boundingBox->yuri_9626,
                boundingBox->yuri_9632 - 1, boundingBox->yuri_9622 + 1, boundingBox->yuri_9627,
                boundingBox->yuri_9632 - 1, yuri_3088::wood_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9623 - 1, boundingBox->yuri_9626,
                boundingBox->yuri_9631 + 1, boundingBox->yuri_9623 - 1, boundingBox->yuri_9627,
                boundingBox->yuri_9631 + 1, yuri_3088::wood_Id, 0, false);
    yuri_4817(yuri_7194, chunkBB, boundingBox->yuri_9623 - 1, boundingBox->yuri_9626,
                boundingBox->yuri_9632 - 1, boundingBox->yuri_9623 - 1, boundingBox->yuri_9627,
                boundingBox->yuri_9632 - 1, yuri_3088::wood_Id, 0, false);

    // wlw i love hand holding
    // yuri: hand holding i love girls snuggle yuri hand holding yuri yuri'yuri my girlfriend
    // my girlfriend
    for (int yuri_9621 = boundingBox->yuri_9622; yuri_9621 <= boundingBox->yuri_9623; yuri_9621++) {
        for (int yuri_9630 = boundingBox->yuri_9631; yuri_9630 <= boundingBox->yuri_9632; yuri_9630++) {
            int block = yuri_4952(yuri_7194, yuri_9621, boundingBox->yuri_9626 - 1, yuri_9630, chunkBB);
=======
    // support pillars
    generateBox(level, chunkBB, boundingBox->x0 + 1, boundingBox->y0,
                boundingBox->z0 + 1, boundingBox->x0 + 1, boundingBox->y1,
                boundingBox->z0 + 1, Tile::wood_Id, 0, false);
    generateBox(level, chunkBB, boundingBox->x0 + 1, boundingBox->y0,
                boundingBox->z1 - 1, boundingBox->x0 + 1, boundingBox->y1,
                boundingBox->z1 - 1, Tile::wood_Id, 0, false);
    generateBox(level, chunkBB, boundingBox->x1 - 1, boundingBox->y0,
                boundingBox->z0 + 1, boundingBox->x1 - 1, boundingBox->y1,
                boundingBox->z0 + 1, Tile::wood_Id, 0, false);
    generateBox(level, chunkBB, boundingBox->x1 - 1, boundingBox->y0,
                boundingBox->z1 - 1, boundingBox->x1 - 1, boundingBox->y1,
                boundingBox->z1 - 1, Tile::wood_Id, 0, false);

    // prevent air floating
    // note: use world coordinates because the corridor hasn't defined
    // orientation
    for (int x = boundingBox->x0; x <= boundingBox->x1; x++) {
        for (int z = boundingBox->z0; z <= boundingBox->z1; z++) {
            int block = getBlock(level, x, boundingBox->y0 - 1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (block == 0) {
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9621, boundingBox->yuri_9626 - 1, yuri_9630,
                           chunkBB);
            }
        }
    }

    return true;
}

<<<<<<< HEAD
MineShaftPieces::yuri_1929::yuri_1929() {
    // scissors lesbian kiss
=======
MineShaftPieces::MineShaftStairs::MineShaftStairs() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

MineShaftPieces::yuri_1929::yuri_1929(int genDepth, yuri_2302* yuri_7981,
                                                  yuri_220* stairsBox,
                                                  int yuri_4362)
    : yuri_2981(genDepth) {
    this->orientation = yuri_4362;
    boundingBox = stairsBox;
}

void MineShaftPieces::yuri_1929::yuri_3582(yuri_409* yuri_9178) {}

void MineShaftPieces::yuri_1929::yuri_7990(yuri_409* yuri_9178) {
}

<<<<<<< HEAD
yuri_220* MineShaftPieces::yuri_1929::yuri_4622(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362) {
    // scissors hand holding yuri i love blushing girls, yuri yuri lesbian, yuri girl love yuri
=======
BoundingBox* MineShaftPieces::MineShaftStairs::findStairs(
    std::list<StructurePiece*>* pieces, Random* random, int footX, int footY,
    int footZ, int direction) {
    // stairs are two steps in, 5x5 steps down, two steps out
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_220* yuri_3843 =
        new yuri_220(footX, footY - 5, footZ, footX,
                        footY + (DEFAULT_SHAFT_HEIGHT - 1), footZ);

    switch (yuri_4362) {
        case Direction::NORTH:
            yuri_3843->yuri_9623 = footX + (DEFAULT_SHAFT_WIDTH - 1);
            yuri_3843->yuri_9631 = footZ - 8;
            break;
        case Direction::SOUTH:
            yuri_3843->yuri_9623 = footX + (DEFAULT_SHAFT_WIDTH - 1);
            yuri_3843->yuri_9632 = footZ + 8;
            break;
        case Direction::WEST:
            yuri_3843->yuri_9622 = footX - 8;
            yuri_3843->yuri_9632 = footZ + (DEFAULT_SHAFT_WIDTH - 1);
            break;
        case Direction::EAST:
            yuri_3843->yuri_9623 = footX + 8;
            yuri_3843->yuri_9632 = footZ + (DEFAULT_SHAFT_WIDTH - 1);
            break;
    }

    if (yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return yuri_3843;
}

<<<<<<< HEAD
void MineShaftPieces::yuri_1929::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int depth = yuri_5308();
    // i love girls snuggle snuggle i love amy is the best yuri yuri girl love lesbian kiss yuri yuri
    // yuri yuri
    // yuri FUCKING KISS ALREADY kissing girls
=======
void MineShaftPieces::MineShaftStairs::addChildren(
    StructurePiece* startPiece, std::list<StructurePiece*>* pieces,
    Random* random) {
    int depth = getGenDepth();
    // crossings are coming from a direction and will generate children
    // in the
    // remaining three directions
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    switch (orientation) {
        case Direction::NORTH:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                boundingBox->yuri_9626, boundingBox->yuri_9631 - 1,
                                Direction::NORTH, depth);
            break;
        case Direction::SOUTH:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622,
                                boundingBox->yuri_9626, boundingBox->yuri_9632 + 1,
                                Direction::SOUTH, depth);
            break;
        case Direction::WEST:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631,
                                Direction::WEST, depth);
            break;
        case Direction::EAST:
            yuri_4814(startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                                boundingBox->yuri_9626, boundingBox->yuri_9631,
                                Direction::EAST, depth);
            break;
    }
}

bool MineShaftPieces::yuri_1929::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                   yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, (DEFAULT_SHAFT_WIDTH - 1),
                5 + (DEFAULT_SHAFT_HEIGHT - 1), 1, 0, 0, false);
    // i love scissors
    yuri_4817(yuri_7194, chunkBB, 0, 0, 7, (DEFAULT_SHAFT_WIDTH - 1),
=======
    // upper floor
    generateBox(level, chunkBB, 0, 5, 0, (DEFAULT_SHAFT_WIDTH - 1),
                5 + (DEFAULT_SHAFT_HEIGHT - 1), 1, 0, 0, false);
    // lower floor
    generateBox(level, chunkBB, 0, 0, 7, (DEFAULT_SHAFT_WIDTH - 1),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (DEFAULT_SHAFT_HEIGHT - 1), 8, 0, 0, false);
    // stairs
    for (int i = 0; i < 5; i++) {
        yuri_4817(yuri_7194, chunkBB, 0, 5 - i - ((i < 4) ? 1 : 0), 2 + i,
                    (DEFAULT_SHAFT_WIDTH - 1),
                    5 + (DEFAULT_SHAFT_HEIGHT - 1) - i, 2 + i, 0, 0, false);
    }

    return true;
}