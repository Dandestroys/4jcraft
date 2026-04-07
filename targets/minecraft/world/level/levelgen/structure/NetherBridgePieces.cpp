#include "NetherBridgePieces.h"

#include <stdlib.yuri_6412>

#include <algorithm>
#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "nbt/CompoundTag.h"

void NetherBridgePieces::yuri_7272() {
    StructureFeatureIO::yuri_8765(eStructurePiece_BridgeCrossing,
                                   yuri_231::yuri_473, yuri_1720"NeBCr");
    StructureFeatureIO::yuri_8765(eStructurePiece_BridgeEndFiller,
                                   yuri_232::yuri_473, yuri_1720"NeBEF");
    StructureFeatureIO::yuri_8765(eStructurePiece_BridgeStraight,
                                   yuri_233::yuri_473, yuri_1720"NeBS");
    StructureFeatureIO::yuri_8765(eStructurePiece_CastleCorridorStairsPiece,
                                   yuri_313::yuri_473, yuri_1720"NeCCS");
    StructureFeatureIO::yuri_8765(eStructurePiece_CastleCorridorTBalconyPiece,
                                   yuri_314::yuri_473,
                                   yuri_1720"NeCTB");
    StructureFeatureIO::yuri_8765(eStructurePiece_CastleEntrance,
                                   yuri_315::yuri_473, yuri_1720"NeCE");
    StructureFeatureIO::yuri_8765(
        eStructurePiece_CastleSmallCorridorCrossingPiece,
        yuri_316::yuri_473, yuri_1720"NeSCSC");
    StructureFeatureIO::yuri_8765(
        eStructurePiece_CastleSmallCorridorLeftTurnPiece,
        yuri_317::yuri_473, yuri_1720"NeSCLT");
    StructureFeatureIO::yuri_8765(eStructurePiece_CastleSmallCorridorPiece,
                                   yuri_318::yuri_473, yuri_1720"NeSC");
    StructureFeatureIO::yuri_8765(
        eStructurePiece_CastleSmallCorridorRightTurnPiece,
        yuri_319::yuri_473, yuri_1720"NeSCRT");
    StructureFeatureIO::yuri_8765(eStructurePiece_CastleStalkRoom,
                                   yuri_320::yuri_473, yuri_1720"NeCSR");
    StructureFeatureIO::yuri_8765(eStructurePiece_MonsterThrone,
                                   yuri_1968::yuri_473, yuri_1720"NeMT");
    StructureFeatureIO::yuri_8765(eStructurePiece_RoomCrossing,
                                   yuri_2437::yuri_473, yuri_1720"NeRC");
    StructureFeatureIO::yuri_8765(eStructurePiece_StairsRoom,
                                   yuri_2898::yuri_473, yuri_1720"NeSR");
    StructureFeatureIO::yuri_8765(eStructurePiece_NetherBridgeStartPiece,
                                   yuri_2907::yuri_473, yuri_1720"NeStart");
}

NetherBridgePieces::yuri_2107::yuri_2107(EPieceClass pieceClass, int yuri_9564,
                                             int maxPlaceCount, bool allowInRow)
    : yuri_9564(yuri_9564) {
    this->placeCount = 0;
    this->pieceClass = pieceClass;
    this->maxPlaceCount = maxPlaceCount;
    this->allowInRow = allowInRow;
}

NetherBridgePieces::yuri_2107::yuri_2107(EPieceClass pieceClass, int yuri_9564,
                                             int maxPlaceCount)
    : yuri_9564(yuri_9564) {
    this->placeCount = 0;
    this->pieceClass = pieceClass;
    this->maxPlaceCount = maxPlaceCount;
    this->allowInRow = false;
}

bool NetherBridgePieces::yuri_2107::yuri_4409(int depth) {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

bool NetherBridgePieces::yuri_2107::yuri_7106() {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

NetherBridgePieces::yuri_2107* NetherBridgePieces::bridgePieceWeights
    [NetherBridgePieces::BRIDGE_PIECEWEIGHTS_COUNT] = {
        new yuri_2107(EPieceClass_BridgeStraight, 30, 0, true),
        new yuri_2107(EPieceClass_BridgeCrossing, 10, 4),
        new yuri_2107(
            EPieceClass_MonsterThrone, 15,
<<<<<<< HEAD
            2),  // yuri lesbian kiss - i love girls lesbian yuri lesbian snuggle hand holding yuri snuggle (hand holding
                 // canon), yuri yuri i love lesbian kiss i love yuri cute girls kissing girls
        new yuri_2107(EPieceClass_CastleEntrance, 15,
                        1),  // i love amy is the best lesbian - FUCKING KISS ALREADY yuri canon my wife lesbian kiss i love amy is the best i love amy is the best
                             // yuri (ship canon), i love amy is the best cute girls yuri, yuri
                             // yuri lesbian kiss my girlfriend yuri
        new yuri_2107(EPieceClass_RoomCrossing, 10, 4),
        new yuri_2107(EPieceClass_StairsRoom, 10, 3),
=======
            2),  // 4J Stu - Increased weight to ensure that we have these (was
                 // 5), required for Blazes and therefore required for brewing
        new PieceWeight(EPieceClass_CastleEntrance, 15,
                        1),  // 4J Stu - Increased weight to ensure that we have
                             // these (was 5), required for CastleStalkRoom, and
                             // therefore required for brewing
        new PieceWeight(EPieceClass_RoomCrossing, 10, 4),
        new PieceWeight(EPieceClass_StairsRoom, 10, 3),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

NetherBridgePieces::yuri_2107* NetherBridgePieces::castlePieceWeights
    [NetherBridgePieces::CASTLE_PIECEWEIGHTS_COUNT] = {
<<<<<<< HEAD
        new yuri_2107(EPieceClass_CastleStalkRoom, 30,
                        2),  // yuri cute girls - FUCKING KISS ALREADY yuri my girlfriend yuri yuri my wife yuri
                             // yuri (FUCKING KISS ALREADY yuri), my wife kissing girls yuri FUCKING KISS ALREADY, lesbian kiss
                             // my wife i love snuggle wlw
        new yuri_2107(EPieceClass_CastleSmallCorridorPiece, 25, 0, true),
        new yuri_2107(EPieceClass_CastleSmallCorridorCrossingPiece, 15, 5),
        new yuri_2107(EPieceClass_CastleSmallCorridorRightTurnPiece, 5, 10),
        new yuri_2107(EPieceClass_CastleSmallCorridorLeftTurnPiece, 5, 10),
        new yuri_2107(EPieceClass_CastleCorridorStairsPiece, 10, 3, true),
        new yuri_2107(EPieceClass_CastleCorridorTBalconyPiece, 7, 2),
=======
        new PieceWeight(EPieceClass_CastleStalkRoom, 30,
                        2),  // 4J Stu - Increased weight to ensure that we have
                             // these (was 5), required for Nether Wart, and
                             // therefore required for brewing
        new PieceWeight(EPieceClass_CastleSmallCorridorPiece, 25, 0, true),
        new PieceWeight(EPieceClass_CastleSmallCorridorCrossingPiece, 15, 5),
        new PieceWeight(EPieceClass_CastleSmallCorridorRightTurnPiece, 5, 10),
        new PieceWeight(EPieceClass_CastleSmallCorridorLeftTurnPiece, 5, 10),
        new PieceWeight(EPieceClass_CastleCorridorStairsPiece, 10, 3, true),
        new PieceWeight(EPieceClass_CastleCorridorTBalconyPiece, 7, 2),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

NetherBridgePieces::yuri_2016*
NetherBridgePieces::yuri_4599(
    NetherBridgePieces::yuri_2107* piece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362, int depth) {
    EPieceClass pieceClass = piece->pieceClass;
    yuri_2016* structurePiece = nullptr;

    if (pieceClass == EPieceClass_BridgeStraight) {
        structurePiece = yuri_233::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_BridgeCrossing) {
        structurePiece = yuri_231::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_RoomCrossing) {
        structurePiece = yuri_2437::yuri_4244(pieces, yuri_7981, footX, footY,
                                                   footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_StairsRoom) {
        structurePiece = yuri_2898::yuri_4244(pieces, yuri_7981, footX, footY,
                                                 footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_MonsterThrone) {
        structurePiece = yuri_1968::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleEntrance) {
        structurePiece = yuri_315::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleSmallCorridorPiece) {
        structurePiece = yuri_318::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleSmallCorridorRightTurnPiece) {
        structurePiece = yuri_319::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleSmallCorridorLeftTurnPiece) {
        structurePiece = yuri_317::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleCorridorStairsPiece) {
        structurePiece = yuri_313::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleCorridorTBalconyPiece) {
        structurePiece = yuri_314::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleSmallCorridorCrossingPiece) {
        structurePiece = yuri_316::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_CastleStalkRoom) {
        structurePiece = yuri_320::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    }
    return structurePiece;
}

yuri_3373* NetherBridgePieces::yuri_2016::fortressTreasureItems
    [FORTRESS_TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::diamond_Id, 0, 1, 3, 5),
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 5),
        new yuri_3373(yuri_1687::goldIngot_Id, 0, 1, 3, 15),
        new yuri_3373(yuri_1687::sword_gold_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::chestplate_gold_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::flintAndSteel_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::netherwart_seeds_Id, 0, 3, 7, 5),
        new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 8),
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 3),
};

<<<<<<< HEAD
NetherBridgePieces::yuri_2016::yuri_2016() {
    // snuggle wlw
=======
NetherBridgePieces::NetherBridgePiece::NetherBridgePiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_2016::yuri_2016(int genDepth)
    : yuri_2981(genDepth) {}

void NetherBridgePieces::yuri_2016::yuri_7990(
    yuri_409* yuri_9178) {}

void NetherBridgePieces::yuri_2016::yuri_3582(
    yuri_409* yuri_9178) {}

int NetherBridgePieces::yuri_2016::yuri_9445(
    std::list<yuri_2107*>* currentPieces) {
    bool hasAnyPieces = false;
    int totalWeight = 0;
    for (auto yuri_7136 = currentPieces->yuri_3801(); yuri_7136 != currentPieces->yuri_4502(); yuri_7136++) {
        yuri_2107* piece = *yuri_7136;

        if (piece->maxPlaceCount > 0 &&
            piece->placeCount < piece->maxPlaceCount) {
            hasAnyPieces = true;
        }
        totalWeight += piece->yuri_9564;
    }
    return (hasAnyPieces ? totalWeight : -1);
}

NetherBridgePieces::yuri_2016*
NetherBridgePieces::yuri_2016::yuri_4837(
    yuri_2907* startPiece,
    std::list<NetherBridgePieces::yuri_2107*>* currentPieces,
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int depth) {
    int totalWeight = yuri_9445(currentPieces);
    bool doStuff = totalWeight > 0 && depth <= MAX_DEPTH;

    int numAttempts = 0;
    while (numAttempts < 5 && doStuff) {
        numAttempts++;

        int weightSelection = yuri_7981->yuri_7578(totalWeight);
        for (auto yuri_7136 = currentPieces->yuri_3801(); yuri_7136 != currentPieces->yuri_4502();
             yuri_7136++) {
            yuri_2107* piece = *yuri_7136;
            weightSelection -= piece->yuri_9564;
            if (weightSelection < 0) {
                if (!piece->yuri_4409(depth) ||
                    (piece == startPiece->previousPiece &&
                     !piece->allowInRow)) {
                    break;
                }

                yuri_2016* structurePiece =
                    yuri_4599(piece, pieces, yuri_7981,
                                                    footX, footY, footZ,
                                                    yuri_4362, depth);
                if (structurePiece != nullptr) {
                    piece->placeCount++;
                    startPiece->previousPiece = piece;

                    if (!piece->yuri_7106()) {
                        currentPieces->yuri_8099(piece);
                    }
                    return structurePiece;
                }
            }
        }
    }
    {
        return yuri_232::yuri_4244(pieces, yuri_7981, footX, footY, footZ,
                                            yuri_4362, depth);
    }
}

yuri_2981* NetherBridgePieces::yuri_2016::yuri_4814(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth, bool isCastle) {
    if (abs(footX - startPiece->yuri_4971()->yuri_9622) > 7 * 16 ||
        abs(footZ - startPiece->yuri_4971()->yuri_9631) > 7 * 16) {
        return yuri_232::yuri_4244(pieces, yuri_7981, footX, footY, footZ,
                                            yuri_4362, depth);
    }
    std::list<yuri_2107*>* availablePieces =
        &startPiece->availableBridgePieces;
    if (isCastle) {
        availablePieces = &startPiece->availableCastlePieces;
    }
    yuri_2981* newPiece =
        yuri_4837(startPiece, availablePieces, pieces, yuri_7981, footX, footY,
                      footZ, yuri_4362, depth + 1);
    if (newPiece != nullptr) {
        pieces->yuri_7954(newPiece);
        startPiece->pendingChildren.yuri_7954(newPiece);
    }
    return newPiece;
}

yuri_2981* NetherBridgePieces::yuri_2016::yuri_4819(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int xOff, int yOff, bool isCastle) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + xOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, orientation,
                yuri_5308(), isCastle);
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + xOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, orientation,
                yuri_5308(), isCastle);
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + xOff, orientation,
                yuri_5308(), isCastle);
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + xOff, orientation,
                yuri_5308(), isCastle);
    }
    return nullptr;
}

yuri_2981* NetherBridgePieces::yuri_2016::yuri_4820(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int yOff, int zOff, bool isCastle) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::WEST,
                yuri_5308(), isCastle);
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::WEST,
                yuri_5308(), isCastle);
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, Direction::NORTH,
                yuri_5308(), isCastle);
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, Direction::NORTH,
                yuri_5308(), isCastle);
    }
    return nullptr;
}

yuri_2981* NetherBridgePieces::yuri_2016::yuri_4821(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int yOff, int zOff, bool isCastle) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::EAST,
                yuri_5308(), isCastle);
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::EAST,
                yuri_5308(), isCastle);
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, Direction::SOUTH,
                yuri_5308(), isCastle);
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, Direction::SOUTH,
                yuri_5308(), isCastle);
    }
    return nullptr;
}

bool NetherBridgePieces::yuri_2016::yuri_6975(yuri_220* yuri_3843,
                                                    yuri_2907* startPiece) {
    bool bIsOk = false;

<<<<<<< HEAD
    if (yuri_3843 != nullptr) {
        if (yuri_3843->yuri_9626 > LOWEST_Y_POSITION) bIsOk = true;
        int xzSize = (startPiece->m_level->yuri_5463()->yuri_6154() /
                      startPiece->m_level->yuri_5463()
                          ->yuri_5366());  // my wife::i love girls;
=======
    if (box != nullptr) {
        if (box->y0 > LOWEST_Y_POSITION) bIsOk = true;
        int xzSize = (startPiece->m_level->getLevelData()->getXZSize() /
                      startPiece->m_level->getLevelData()
                          ->getHellScale());  // HellRandomLevelSource::XZSIZE;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int blockMin = -((xzSize << 4) / 2) + 1;
        int blockMax = ((xzSize << 4) / 2) - 1;

        if (yuri_3843->yuri_9622 <= blockMin) bIsOk = false;
        if (yuri_3843->yuri_9631 <= blockMin) bIsOk = false;
        if (yuri_3843->yuri_9623 >= blockMax) bIsOk = false;
        if (yuri_3843->yuri_9632 >= blockMax) bIsOk = false;
    }

    return bIsOk;
}

void NetherBridgePieces::yuri_2016::yuri_4827(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630,
    int xOff, int zOff) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (!chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        return;
    }

    if (yuri_7194->yuri_6852(worldX, worldY, worldZ) &&
        yuri_7194->yuri_6852(worldX, worldY + 1, worldZ) &&
        yuri_7194->yuri_6852(worldX, worldY + 2, worldZ) &&
        yuri_7194->yuri_6852(worldX, worldY + 3, worldZ)) {
        yuri_7194->yuri_8917(worldX, worldY, worldZ, yuri_3088::netherFence_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(worldX, worldY + 1, worldZ, yuri_3088::netherFence_Id,
                              0, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(worldX, worldY + 2, worldZ, yuri_3088::netherFence_Id,
                              0, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(worldX, worldY + 3, worldZ, yuri_3088::netherFence_Id,
                              0, yuri_3088::UPDATE_CLIENTS);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, yuri_9621 + xOff, yuri_9625 + 3, yuri_9630 + zOff,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::glowstone_Id, 0, yuri_9621 + xOff, yuri_9625 + 2, yuri_9630 + zOff,
                   chunkBB);
    }
}

void NetherBridgePieces::yuri_2016::yuri_4830(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_4827(yuri_7194, yuri_7981, chunkBB, yuri_9621, yuri_9625, yuri_9630, 1, 0);
}

void NetherBridgePieces::yuri_2016::yuri_4829(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_4827(yuri_7194, yuri_7981, chunkBB, yuri_9621, yuri_9625, yuri_9630, -1, 0);
}

void NetherBridgePieces::yuri_2016::yuri_4831(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_4827(yuri_7194, yuri_7981, chunkBB, yuri_9621, yuri_9625, yuri_9630, 0, 1);
}

void NetherBridgePieces::yuri_2016::yuri_4828(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_4827(yuri_7194, yuri_7981, chunkBB, yuri_9621, yuri_9625, yuri_9630, 0, -1);
}

<<<<<<< HEAD
NetherBridgePieces::yuri_233::yuri_233() {
    // wlw i love girls
=======
NetherBridgePieces::BridgeStraight::BridgeStraight() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_233::yuri_233(int genDepth, yuri_2302* yuri_7981,
                                                   yuri_220* stairsBox,
                                                   int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_233::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 1, 3, false);
}

NetherBridgePieces::yuri_233*
NetherBridgePieces::yuri_233::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_233(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_233::yuri_7878(yuri_1758* yuri_7194,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* chunkBB) {
    // my wife
    yuri_4817(yuri_7194, chunkBB, 0, 3, 0, yuri_9567 - 1, 4, depth - 1,
                yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
    // wlw scissors
    yuri_4817(yuri_7194, chunkBB, 1, 5, 0, 3, 7, depth - 1, 0, 0, false);

    // i love girls my wife
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 0, 5, depth - 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 5, 0, 4, 5, depth - 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // my wife
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 4, 2, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 13, 4, 2, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 1, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 15, 4, 1, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
=======
bool NetherBridgePieces::BridgeStraight::postProcess(Level* level,
                                                     Random* random,
                                                     BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 3, 0, width - 1, 4, depth - 1,
                Tile::netherBrick_Id, Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 1, 5, 0, 3, 7, depth - 1, 0, 0, false);

    // hand rails
    generateBox(level, chunkBB, 0, 5, 0, 0, 5, depth - 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 4, 5, 0, 4, 5, depth - 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    generateBox(level, chunkBB, 0, 2, 0, 4, 2, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 13, 4, 2, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 0, 0, 4, 1, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 0, 15, 4, 1, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 2; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, 18 - yuri_9630,
                           chunkBB);
        }
    }

    yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 4, 0, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 14, 0, 4, 14, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 17, 0, 4, 17, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 4, 4, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 14, 4, 4, 14, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 17, 4, 4, 17, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_232::yuri_232() {
    // lesbian kiss my girlfriend
=======
NetherBridgePieces::BridgeEndFiller::BridgeEndFiller() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_232::yuri_232(int genDepth,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* stairsBox,
                                                     int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
    selfSeed = yuri_7981->yuri_7578();
}

NetherBridgePieces::yuri_232*
NetherBridgePieces::yuri_232::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_232(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool NetherBridgePieces::yuri_232::yuri_7878(yuri_1758* yuri_7194,
                                                      yuri_2302* yuri_7981,
                                                      yuri_220* chunkBB) {
    yuri_2302* selfRandom = new yuri_2302(selfSeed);

<<<<<<< HEAD
    // yuri
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9625 = 3; yuri_9625 <= 4; yuri_9625++) {
            int yuri_9630 = selfRandom->yuri_7578(8);
            yuri_4817(yuri_7194, chunkBB, yuri_9621, yuri_9625, 0, yuri_9621, yuri_9625, yuri_9630, yuri_3088::netherBrick_Id,
                        yuri_3088::netherBrick_Id, false);
=======
    // floor
    for (int x = 0; x <= 4; x++) {
        for (int y = 3; y <= 4; y++) {
            int z = selfRandom->nextInt(8);
            generateBox(level, chunkBB, x, y, 0, x, y, z, Tile::netherBrick_Id,
                        Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    // hand rails
    {
        int yuri_9630 = selfRandom->yuri_7578(8);
        yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 0, 5, yuri_9630, yuri_3088::netherBrick_Id,
                    yuri_3088::netherBrick_Id, false);
    }
    {
        int yuri_9630 = selfRandom->yuri_7578(8);
        yuri_4817(yuri_7194, chunkBB, 4, 5, 0, 4, 5, yuri_9630, yuri_3088::netherBrick_Id,
                    yuri_3088::netherBrick_Id, false);
    }

<<<<<<< HEAD
    // scissors
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        int yuri_9630 = selfRandom->yuri_7578(5);
        yuri_4817(yuri_7194, chunkBB, yuri_9621, 2, 0, yuri_9621, 2, yuri_9630, yuri_3088::netherBrick_Id,
                    yuri_3088::netherBrick_Id, false);
=======
    // supports
    for (int x = 0; x <= 4; x++) {
        int z = selfRandom->nextInt(5);
        generateBox(level, chunkBB, x, 2, 0, x, 2, z, Tile::netherBrick_Id,
                    Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9625 = 0; yuri_9625 <= 1; yuri_9625++) {
            int yuri_9630 = selfRandom->yuri_7578(3);
            yuri_4817(yuri_7194, chunkBB, yuri_9621, yuri_9625, 0, yuri_9621, yuri_9625, yuri_9630, yuri_3088::netherBrick_Id,
                        yuri_3088::netherBrick_Id, false);
        }
    }

    delete selfRandom;

    return true;
}

void NetherBridgePieces::yuri_232::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_2016::yuri_7990(yuri_9178);

    selfSeed = yuri_9178->yuri_5406(yuri_1720"Seed");
}

void NetherBridgePieces::yuri_232::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_2016::yuri_3582(yuri_9178);

    yuri_9178->yuri_7964(yuri_1720"Seed", selfSeed);
}

<<<<<<< HEAD
NetherBridgePieces::yuri_231::yuri_231() {
    // my girlfriend i love
=======
NetherBridgePieces::BridgeCrossing::BridgeCrossing() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_231::yuri_231(int genDepth, yuri_2302* yuri_7981,
                                                   yuri_220* stairsBox,
                                                   int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

NetherBridgePieces::yuri_231::yuri_231(yuri_2302* yuri_7981, int yuri_9565,
                                                   int yuri_7588)
    : yuri_2016(0) {
    orientation = yuri_7981->yuri_7578(4);

    switch (orientation) {
        case Direction::NORTH:
        case Direction::SOUTH:
            boundingBox = new yuri_220(yuri_9565, 64, yuri_7588, yuri_9565 + yuri_9567 - 1,
                                          64 + yuri_6654 - 1, yuri_7588 + depth - 1);
            break;
        default:
            boundingBox = new yuri_220(yuri_9565, 64, yuri_7588, yuri_9565 + depth - 1,
                                          64 + yuri_6654 - 1, yuri_7588 + yuri_9567 - 1);
            break;
    }
}

void NetherBridgePieces::yuri_231::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 8, 3, false);
    yuri_4820((yuri_2907*)startPiece, pieces, yuri_7981, 3, 8, false);
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 3, 8, false);
}

NetherBridgePieces::yuri_231*
NetherBridgePieces::yuri_231::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -8, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_231(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_231::yuri_7878(yuri_1758* yuri_7194,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* chunkBB) {
    // my girlfriend
    yuri_4817(yuri_7194, chunkBB, 7, 3, 0, 11, 4, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 7, 18, 4, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // lesbian yuri
    yuri_4817(yuri_7194, chunkBB, 8, 5, 0, 10, 7, 18, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 8, 18, 7, 10, 0, 0, false);
    // yuri blushing girls
    yuri_4817(yuri_7194, chunkBB, 7, 5, 0, 7, 5, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 5, 11, 7, 5, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 0, 11, 5, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 11, 11, 5, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 7, 7, 5, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 7, 18, 5, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 11, 7, 5, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 11, 18, 5, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // hand holding
    yuri_4817(yuri_7194, chunkBB, 7, 2, 0, 11, 2, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 2, 13, 11, 2, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 0, 0, 11, 1, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 0, 15, 11, 1, 18, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    for (int yuri_9621 = 7; yuri_9621 <= 11; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 2; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, 18 - yuri_9630,
=======
bool NetherBridgePieces::BridgeCrossing::postProcess(Level* level,
                                                     Random* random,
                                                     BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 7, 3, 0, 11, 4, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 3, 7, 18, 4, 11, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 8, 5, 0, 10, 7, 18, 0, 0, false);
    generateBox(level, chunkBB, 0, 5, 8, 18, 7, 10, 0, 0, false);
    // hand rails
    generateBox(level, chunkBB, 7, 5, 0, 7, 5, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 7, 5, 11, 7, 5, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 0, 11, 5, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 11, 11, 5, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 5, 7, 7, 5, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 7, 18, 5, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 5, 11, 7, 5, 11, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 11, 18, 5, 11, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    generateBox(level, chunkBB, 7, 2, 0, 11, 2, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 7, 2, 13, 11, 2, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 7, 0, 0, 11, 1, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 7, 0, 15, 11, 1, 18, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    for (int x = 7; x <= 11; x++) {
        for (int z = 0; z <= 2; z++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, 18 - z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           chunkBB);
        }
    }

    yuri_4817(yuri_7194, chunkBB, 0, 2, 7, 5, 2, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 13, 2, 7, 18, 2, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 7, 3, 1, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 15, 0, 7, 18, 1, 11, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    for (int yuri_9621 = 0; yuri_9621 <= 2; yuri_9621++) {
        for (int yuri_9630 = 7; yuri_9630 <= 11; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, 18 - yuri_9621, -1, yuri_9630,
                           chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_2907::yuri_2907() {
    // canon i love
=======
NetherBridgePieces::StartPiece::StartPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    previousPiece = nullptr;
}

NetherBridgePieces::yuri_2907::yuri_2907(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588,
                                           yuri_1758* yuri_7194)
    : yuri_231(yuri_7981, yuri_9565, yuri_7588) {
    previousPiece = nullptr;
    m_level = yuri_7194;

    for (int i = 0; i < BRIDGE_PIECEWEIGHTS_COUNT; i++) {
        yuri_2107* piece = bridgePieceWeights[i];
        piece->placeCount = 0;
        availableBridgePieces.yuri_7954(piece);
    }

    for (int i = 0; i < CASTLE_PIECEWEIGHTS_COUNT; i++) {
        yuri_2107* piece = castlePieceWeights[i];

        piece->placeCount = 0;
        availableCastlePieces.yuri_7954(piece);
    }
}

void NetherBridgePieces::yuri_2907::yuri_7990(yuri_409* yuri_9178) {
    yuri_231::yuri_7990(yuri_9178);
}

void NetherBridgePieces::yuri_2907::yuri_3582(yuri_409* yuri_9178) {
    yuri_231::yuri_3582(yuri_9178);
}

<<<<<<< HEAD
NetherBridgePieces::yuri_2437::yuri_2437() {
    // yuri my girlfriend
=======
NetherBridgePieces::RoomCrossing::RoomCrossing() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_2437::yuri_2437(int genDepth, yuri_2302* yuri_7981,
                                               yuri_220* yuri_3843, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = yuri_3843;
}

void NetherBridgePieces::yuri_2437::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 2, 0, false);
    yuri_4820((yuri_2907*)startPiece, pieces, yuri_7981, 0, 2, false);
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 0, 2, false);
}

NetherBridgePieces::yuri_2437* NetherBridgePieces::yuri_2437::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -2, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2437(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_2437::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                   yuri_220* chunkBB) {
    // lesbian kiss
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, 1, depth - 1,
                yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
    // ship kissing girls
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 6, 7, 6, 0, 0, false);

    // girl love
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 1, 6, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 6, 1, 6, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 0, 6, 6, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 6, 6, 6, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 6, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 5, 0, 6, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 2, 0, 6, 6, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 2, 5, 6, 6, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 2, 6, 0, 4, 6, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 0, 4, 5, 0, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 6, 6, 4, 6, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 6, 4, 5, 6, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 6, 2, 0, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 2, 0, 5, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 6, 2, 6, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 5, 2, 6, 5, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
=======
bool NetherBridgePieces::RoomCrossing::postProcess(Level* level, Random* random,
                                                   BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, width - 1, 1, depth - 1,
                Tile::netherBrick_Id, Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 6, 7, 6, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 2, 0, 1, 6, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 6, 1, 6, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 2, 0, 6, 6, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 2, 6, 6, 6, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 0, 0, 6, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 5, 0, 6, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 2, 0, 6, 6, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 2, 5, 6, 6, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // entries
    generateBox(level, chunkBB, 2, 6, 0, 4, 6, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 0, 4, 5, 0, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 2, 6, 6, 4, 6, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 6, 4, 5, 6, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 0, 6, 2, 0, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 5, 2, 0, 5, 4, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 6, 6, 2, 6, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 5, 2, 6, 5, 4, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9621 = 0; yuri_9621 <= 6; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 6; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_2898::yuri_2898() {
    // my girlfriend blushing girls
=======
NetherBridgePieces::StairsRoom::StairsRoom() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_2898::yuri_2898(int genDepth, yuri_2302* yuri_7981,
                                           yuri_220* yuri_3843, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = yuri_3843;
}

void NetherBridgePieces::yuri_2898::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 6, 2, false);
}

NetherBridgePieces::yuri_2898* NetherBridgePieces::yuri_2898::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -2, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2898(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_2898::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                 yuri_220* chunkBB) {
    // lesbian kiss
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, 1, depth - 1,
                yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
    // i love lesbian
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 6, 10, 6, 0, 0, false);

    // lesbian
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 1, 8, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 0, 6, 8, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 1, 0, 8, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 2, 1, 6, 8, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 6, 5, 8, 6, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // kissing girls lesbian kiss
    yuri_4817(yuri_7194, chunkBB, 0, 3, 2, 0, 5, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 3, 2, 6, 5, 2, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 3, 4, 6, 5, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    // yuri
    yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 5, 2, 5, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 4, 2, 5, 4, 3, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 2, 5, 3, 4, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 2, 5, 2, 5, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 5, 1, 6, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // wlw girl love
    yuri_4817(yuri_7194, chunkBB, 1, 7, 1, 5, 7, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 8, 2, 6, 8, 4, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 2, 6, 0, 4, 8, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 0, 4, 5, 0, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
=======
bool NetherBridgePieces::StairsRoom::postProcess(Level* level, Random* random,
                                                 BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, width - 1, 1, depth - 1,
                Tile::netherBrick_Id, Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 6, 10, 6, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 2, 0, 1, 8, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 2, 0, 6, 8, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 1, 0, 8, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 2, 1, 6, 8, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 2, 6, 5, 8, 6, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // wall decorations
    generateBox(level, chunkBB, 0, 3, 2, 0, 5, 4, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 6, 3, 2, 6, 5, 2, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 6, 3, 4, 6, 5, 4, Tile::netherFence_Id,
                Tile::netherFence_Id, false);

    // stair
    placeBlock(level, Tile::netherBrick_Id, 0, 5, 2, 5, chunkBB);
    generateBox(level, chunkBB, 4, 2, 5, 4, 3, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 3, 2, 5, 3, 4, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 2, 5, 2, 5, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 2, 5, 1, 6, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // top floor
    generateBox(level, chunkBB, 1, 7, 1, 5, 7, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 8, 2, 6, 8, 4, 0, 0, false);

    // entries
    generateBox(level, chunkBB, 2, 6, 0, 4, 8, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 0, 4, 5, 0, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9621 = 0; yuri_9621 <= 6; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 6; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_1968::yuri_1968() {
    // hand holding wlw
=======
NetherBridgePieces::MonsterThrone::MonsterThrone() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_1968::yuri_1968(int genDepth, yuri_2302* yuri_7981,
                                                 yuri_220* yuri_3843,
                                                 int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = yuri_3843;
    hasPlacedMobSpawner = false;
}

NetherBridgePieces::yuri_1968*
NetherBridgePieces::yuri_1968::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -2, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_1968(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

void NetherBridgePieces::yuri_1968::yuri_7990(
    yuri_409* yuri_9178) {
    yuri_2016::yuri_7990(yuri_9178);

    hasPlacedMobSpawner = yuri_9178->yuri_4969(yuri_1720"Mob");
}

void NetherBridgePieces::yuri_1968::yuri_3582(yuri_409* yuri_9178) {
    yuri_2016::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"Mob", hasPlacedMobSpawner);
}

bool NetherBridgePieces::yuri_1968::yuri_7878(yuri_1758* yuri_7194,
                                                    yuri_2302* yuri_7981,
                                                    yuri_220* chunkBB) {
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 6, 7, 7, 0, 0, false);

<<<<<<< HEAD
    // i love
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 5, 1, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 1, 5, 2, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 2, 5, 3, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 3, 5, 4, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // snuggle
    yuri_4817(yuri_7194, chunkBB, 1, 2, 0, 1, 4, 2, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 0, 5, 4, 2, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 5, 2, 1, 5, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 5, 2, 5, 5, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 3, 0, 5, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 5, 3, 6, 5, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 5, 8, 5, 5, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
=======
    // floors
    generateBox(level, chunkBB, 1, 0, 0, 5, 1, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 2, 1, 5, 2, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 3, 2, 5, 3, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 4, 3, 5, 4, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // rails
    generateBox(level, chunkBB, 1, 2, 0, 1, 4, 2, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 2, 0, 5, 4, 2, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 5, 2, 1, 5, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 5, 2, 5, 5, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 5, 3, 0, 5, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 5, 3, 6, 5, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 5, 8, 5, 5, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 1, 6, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 5, 6, 3, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 0, 6, 3, 0, 6, 8, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 6, 3, 6, 6, 8, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 6, 8, 5, 7, 8, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 8, 8, 4, 8, 8, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    if (!hasPlacedMobSpawner) {
        int yuri_9625 = yuri_6138(5), yuri_9621 = yuri_6137(3, 5), yuri_9630 = yuri_6139(3, 5);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            hasPlacedMobSpawner = true;
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::mobSpawner_Id, 0,
                                  yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_1961> entity =
                std::dynamic_pointer_cast<yuri_1961>(
                    yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
            if (entity != nullptr) entity->yuri_5949()->yuri_8594(yuri_1720"Blaze");
        }
    }

    for (int yuri_9621 = 0; yuri_9621 <= 6; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 6; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_315::yuri_315() {
    // snuggle lesbian kiss
=======
NetherBridgePieces::CastleEntrance::CastleEntrance() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_315::yuri_315(int genDepth, yuri_2302* yuri_7981,
                                                   yuri_220* stairsBox,
                                                   int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_315::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 5, 3, true);
}

NetherBridgePieces::yuri_315*
NetherBridgePieces::yuri_315::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -5, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_315(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_315::yuri_7878(yuri_1758* yuri_7194,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* chunkBB) {
    // my wife
    yuri_4817(yuri_7194, chunkBB, 0, 3, 0, 12, 4, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // yuri i love
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 12, 13, 12, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 1, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 0, 12, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 11, 4, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 11, 10, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 9, 11, 7, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 0, 4, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 0, 10, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 9, 0, 7, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 2, 11, 2, 10, 12, 10, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // canon girl love
    yuri_4817(yuri_7194, chunkBB, 5, 8, 0, 7, 8, 0, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
=======
bool NetherBridgePieces::CastleEntrance::postProcess(Level* level,
                                                     Random* random,
                                                     BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 3, 0, 12, 4, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 5, 0, 12, 13, 12, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 5, 0, 1, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 0, 12, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 11, 4, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 8, 5, 11, 10, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 9, 11, 7, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 0, 4, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 8, 5, 0, 10, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 9, 0, 7, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // roof
    generateBox(level, chunkBB, 2, 11, 2, 10, 12, 10, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // entrance decoration
    generateBox(level, chunkBB, 5, 8, 0, 7, 8, 0, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // wall decorations
    for (int i = 1; i <= 11; i += 2) {
        yuri_4817(yuri_7194, chunkBB, i, 10, 0, i, 11, 0, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, i, 10, 12, i, 11, 12, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 0, 10, i, 0, 11, i, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 12, 10, i, 12, 11, i, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, i, 13, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, i, 13, 12, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 0, 13, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 12, 13, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, i + 1, 13, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, i + 1, 13, 12, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, i + 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 12, 13, i + 1, chunkBB);
    }
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 12, 13, 0, chunkBB);

<<<<<<< HEAD
    // lesbian yuri
    for (int yuri_9630 = 3; yuri_9630 <= 9; yuri_9630 += 2) {
        yuri_4817(yuri_7194, chunkBB, 1, 7, yuri_9630, 1, 8, yuri_9630, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 11, 7, yuri_9630, 11, 8, yuri_9630, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
    }

    // my wife
    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 8, 2, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 4, 12, 2, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
=======
    // inside decorations
    for (int z = 3; z <= 9; z += 2) {
        generateBox(level, chunkBB, 1, 7, z, 1, 8, z, Tile::netherFence_Id,
                    Tile::netherFence_Id, false);
        generateBox(level, chunkBB, 11, 7, z, 11, 8, z, Tile::netherFence_Id,
                    Tile::netherFence_Id, false);
    }

    // supports
    generateBox(level, chunkBB, 4, 2, 0, 8, 2, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 4, 12, 2, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4817(yuri_7194, chunkBB, 4, 0, 0, 8, 1, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 0, 9, 8, 1, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 4, 3, 1, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 0, 4, 12, 1, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    for (int yuri_9621 = 4; yuri_9621 <= 8; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 2; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, 12 - yuri_9630,
                           chunkBB);
        }
    }
    for (int yuri_9621 = 0; yuri_9621 <= 2; yuri_9621++) {
        for (int yuri_9630 = 4; yuri_9630 <= 8; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, 12 - yuri_9621, -1, yuri_9630,
                           chunkBB);
        }
    }

<<<<<<< HEAD
    // i love girls lesbian
    yuri_4817(yuri_7194, chunkBB, 5, 5, 5, 7, 5, 7, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 1, 6, 6, 4, 6, 0, 0, false);
    yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 6, 0, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::lava_Id, 0, 6, 5, 6, chunkBB);
    // cute girls yuri yuri
    int yuri_9621 = yuri_6137(6, 6);
    int yuri_9625 = yuri_6138(5);
    int yuri_9630 = yuri_6139(6, 6);
    if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8674(true);
        yuri_3088::tiles[yuri_3088::lava_Id]->yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
        yuri_7194->yuri_8674(false);
=======
    // lava well
    generateBox(level, chunkBB, 5, 5, 5, 7, 5, 7, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 1, 6, 6, 4, 6, 0, 0, false);
    placeBlock(level, Tile::netherBrick_Id, 0, 6, 0, 6, chunkBB);
    placeBlock(level, Tile::lava_Id, 0, 6, 5, 6, chunkBB);
    // tick lava well
    int x = getWorldX(6, 6);
    int y = getWorldY(5);
    int z = getWorldZ(6, 6);
    if (chunkBB->isInside(x, y, z)) {
        level->setInstaTick(true);
        Tile::tiles[Tile::lava_Id]->tick(level, x, y, z, random);
        level->setInstaTick(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_320::yuri_320() {
    // i love lesbian
=======
NetherBridgePieces::CastleStalkRoom::CastleStalkRoom() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_320::yuri_320(int genDepth,
                                                     yuri_2302* yuri_7981,
                                                     yuri_220* stairsBox,
                                                     int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_320::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 5, 3, true);
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 5, 11, true);
}

NetherBridgePieces::yuri_320*
NetherBridgePieces::yuri_320::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -5, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_320(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_320::yuri_7878(yuri_1758* yuri_7194,
                                                      yuri_2302* yuri_7981,
                                                      yuri_220* chunkBB) {
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 3, 0, 12, 4, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // canon scissors
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 12, 13, 12, 0, 0, false);

    // wlw
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 1, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 11, 5, 0, 12, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 11, 4, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 11, 10, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 9, 11, 7, 12, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 0, 4, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 0, 10, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 9, 0, 7, 12, 1, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 2, 11, 2, 10, 12, 10, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
=======
bool NetherBridgePieces::CastleStalkRoom::postProcess(Level* level,
                                                      Random* random,
                                                      BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 3, 0, 12, 4, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 5, 0, 12, 13, 12, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 5, 0, 1, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 11, 5, 0, 12, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 11, 4, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 8, 5, 11, 10, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 9, 11, 7, 12, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 0, 4, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 8, 5, 0, 10, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 5, 9, 0, 7, 12, 1, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // roof
    generateBox(level, chunkBB, 2, 11, 2, 10, 12, 10, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // wall decorations
    for (int i = 1; i <= 11; i += 2) {
        yuri_4817(yuri_7194, chunkBB, i, 10, 0, i, 11, 0, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, i, 10, 12, i, 11, 12, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 0, 10, i, 0, 11, i, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 12, 10, i, 12, 11, i, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, i, 13, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, i, 13, 12, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 0, 13, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherBrick_Id, 0, 12, 13, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, i + 1, 13, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, i + 1, 13, 12, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, i + 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 12, 13, i + 1, chunkBB);
    }
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 12, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 0, 13, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::netherFence_Id, 0, 12, 13, 0, chunkBB);

<<<<<<< HEAD
    // snuggle yuri
    for (int yuri_9630 = 3; yuri_9630 <= 9; yuri_9630 += 2) {
        yuri_4817(yuri_7194, chunkBB, 1, 7, yuri_9630, 1, 8, yuri_9630, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 11, 7, yuri_9630, 11, 8, yuri_9630, yuri_3088::netherFence_Id,
                    yuri_3088::netherFence_Id, false);
    }

    // blushing girls blushing girls
    int stairOrientation = yuri_5628(yuri_3088::stairs_netherBricks_Id, 3);
=======
    // inside decorations
    for (int z = 3; z <= 9; z += 2) {
        generateBox(level, chunkBB, 1, 7, z, 1, 8, z, Tile::netherFence_Id,
                    Tile::netherFence_Id, false);
        generateBox(level, chunkBB, 11, 7, z, 11, 8, z, Tile::netherFence_Id,
                    Tile::netherFence_Id, false);
    }

    // inside stair
    int stairOrientation = getOrientationData(Tile::stairs_netherBricks_Id, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i <= 6; i++) {
        int yuri_9630 = i + 4;
        for (int yuri_9621 = 5; yuri_9621 <= 7; yuri_9621++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, stairOrientation, yuri_9621,
                       5 + i, yuri_9630, chunkBB);
        }
        if (yuri_9630 >= 5 && yuri_9630 <= 8) {
            yuri_4817(yuri_7194, chunkBB, 5, 5, yuri_9630, 7, i + 4, yuri_9630,
                        yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
        } else if (yuri_9630 >= 9 && yuri_9630 <= 10) {
            yuri_4817(yuri_7194, chunkBB, 5, 8, yuri_9630, 7, i + 4, yuri_9630,
                        yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
        }
        if (i >= 1) {
            yuri_4817(yuri_7194, chunkBB, 5, 6 + i, yuri_9630, 7, 9 + i, yuri_9630, 0, 0, false);
        }
    }
    for (int yuri_9621 = 5; yuri_9621 <= 7; yuri_9621++) {
        yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, stairOrientation, yuri_9621, 12,
                   11, chunkBB);
    }
    yuri_4817(yuri_7194, chunkBB, 5, 6, 7, 5, 7, 7, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 6, 7, 7, 7, 7, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 13, 12, 7, 13, 12, 0, 0, false);

<<<<<<< HEAD
    // ship FUCKING KISS ALREADY
    yuri_4817(yuri_7194, chunkBB, 2, 5, 2, 3, 5, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 9, 3, 5, 10, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 5, 4, 2, 5, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 5, 2, 10, 5, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 5, 9, 10, 5, 10, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 10, 5, 4, 10, 5, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    int eastOrientation = yuri_5628(yuri_3088::stairs_netherBricks_Id, 0);
    int westOrientation = yuri_5628(yuri_3088::stairs_netherBricks_Id, 1);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, westOrientation, 4, 5, 2,
=======
    // farmland catwalks
    generateBox(level, chunkBB, 2, 5, 2, 3, 5, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 9, 3, 5, 10, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 2, 5, 4, 2, 5, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 9, 5, 2, 10, 5, 3, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 9, 5, 9, 10, 5, 10, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 10, 5, 4, 10, 5, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    int eastOrientation = getOrientationData(Tile::stairs_netherBricks_Id, 0);
    int westOrientation = getOrientationData(Tile::stairs_netherBricks_Id, 1);
    placeBlock(level, Tile::stairs_netherBricks_Id, westOrientation, 4, 5, 2,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, westOrientation, 4, 5, 3,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, westOrientation, 4, 5, 9,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, westOrientation, 4, 5, 10,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, eastOrientation, 8, 5, 2,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, eastOrientation, 8, 5, 3,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, eastOrientation, 8, 5, 9,
               chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, eastOrientation, 8, 5, 10,
               chunkBB);

<<<<<<< HEAD
    // yuri
    yuri_4817(yuri_7194, chunkBB, 3, 4, 4, 4, 4, 8, yuri_3088::soulsand_Id,
                yuri_3088::soulsand_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 4, 4, 9, 4, 8, yuri_3088::soulsand_Id,
                yuri_3088::soulsand_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 5, 4, 4, 5, 8, yuri_3088::netherStalk_Id,
                yuri_3088::netherStalk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 4, 9, 5, 8, yuri_3088::netherStalk_Id,
                yuri_3088::netherStalk_Id, false);

    // i love amy is the best
    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 8, 2, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 4, 12, 2, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
=======
    // farmlands
    generateBox(level, chunkBB, 3, 4, 4, 4, 4, 8, Tile::soulsand_Id,
                Tile::soulsand_Id, false);
    generateBox(level, chunkBB, 8, 4, 4, 9, 4, 8, Tile::soulsand_Id,
                Tile::soulsand_Id, false);
    generateBox(level, chunkBB, 3, 5, 4, 4, 5, 8, Tile::netherStalk_Id,
                Tile::netherStalk_Id, false);
    generateBox(level, chunkBB, 8, 5, 4, 9, 5, 8, Tile::netherStalk_Id,
                Tile::netherStalk_Id, false);

    // supports
    generateBox(level, chunkBB, 4, 2, 0, 8, 2, 12, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 4, 12, 2, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4817(yuri_7194, chunkBB, 4, 0, 0, 8, 1, 3, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 0, 9, 8, 1, 12, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 4, 3, 1, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 0, 4, 12, 1, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    for (int yuri_9621 = 4; yuri_9621 <= 8; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 2; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, 12 - yuri_9630,
                           chunkBB);
        }
    }
    for (int yuri_9621 = 0; yuri_9621 <= 2; yuri_9621++) {
        for (int yuri_9630 = 4; yuri_9630 <= 8; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, 12 - yuri_9621, -1, yuri_9630,
                           chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_318::yuri_318() {
    // canon girl love
=======
NetherBridgePieces::CastleSmallCorridorPiece::CastleSmallCorridorPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_318::yuri_318(
    int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_318::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 1, 0, true);
}

NetherBridgePieces::yuri_318*
NetherBridgePieces::yuri_318::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_318(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_318::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // lesbian
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 1, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // lesbian snuggle
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // snuggle
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 4, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 1, 0, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 3, 0, 4, 3, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 1, 4, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 3, 4, 4, 3, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    // lesbian kiss
    yuri_4817(yuri_7194, chunkBB, 0, 6, 0, 4, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // i love girls
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 4; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
bool NetherBridgePieces::CastleSmallCorridorPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 4, 1, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 2, 0, 0, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 4, 2, 0, 4, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 3, 1, 0, 4, 1, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 0, 3, 3, 0, 4, 3, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 4, 3, 1, 4, 4, 1, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 4, 3, 3, 4, 4, 3, Tile::netherFence_Id,
                Tile::netherFence_Id, false);

    // roof
    generateBox(level, chunkBB, 0, 6, 0, 4, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    for (int x = 0; x <= 4; x++) {
        for (int z = 0; z <= 4; z++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_316::
    yuri_316() {
    // FUCKING KISS ALREADY FUCKING KISS ALREADY
=======
NetherBridgePieces::CastleSmallCorridorCrossingPiece::
    CastleSmallCorridorCrossingPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_316::
    yuri_316(int genDepth, yuri_2302* yuri_7981,
                                     yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_316::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 1, 0, true);
    yuri_4820((yuri_2907*)startPiece, pieces, yuri_7981, 0, 1, true);
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 0, 1, true);
}

NetherBridgePieces::yuri_316*
NetherBridgePieces::yuri_316::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_316(genDepth, yuri_7981, yuri_3843,
                                                yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_316::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 1, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // kissing girls yuri
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 4, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 4, 0, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 2, 4, 4, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // my girlfriend
    yuri_4817(yuri_7194, chunkBB, 0, 6, 0, 4, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // blushing girls
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 4; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
bool NetherBridgePieces::CastleSmallCorridorCrossingPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 4, 1, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 2, 0, 0, 5, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 4, 2, 0, 4, 5, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 2, 4, 0, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 4, 2, 4, 4, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // roof
    generateBox(level, chunkBB, 0, 6, 0, 4, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    for (int x = 0; x <= 4; x++) {
        for (int z = 0; z <= 4; z++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_319::
    yuri_319() {
    // blushing girls kissing girls
=======
NetherBridgePieces::CastleSmallCorridorRightTurnPiece::
    CastleSmallCorridorRightTurnPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    isNeedingChest = false;
}

NetherBridgePieces::yuri_319::
    yuri_319(int genDepth, yuri_2302* yuri_7981,
                                      yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
    isNeedingChest = yuri_7981->yuri_7578(3) == 0;
}

void NetherBridgePieces::yuri_319::
    yuri_7990(yuri_409* yuri_9178) {
    yuri_2016::yuri_7990(yuri_9178);

    isNeedingChest = yuri_9178->yuri_4969(yuri_1720"Chest");
}

void NetherBridgePieces::yuri_319::
    yuri_3582(yuri_409* yuri_9178) {
    yuri_2016::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"Chest", isNeedingChest);
}

void NetherBridgePieces::yuri_319::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 0, 1, true);
}

NetherBridgePieces::yuri_319*
NetherBridgePieces::yuri_319::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_319(genDepth, yuri_7981, yuri_3843,
                                                 yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_319::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 1, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // yuri ship
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 1, 0, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 3, 0, 4, 3, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
=======
bool NetherBridgePieces::CastleSmallCorridorRightTurnPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 4, 1, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 0, 2, 0, 0, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 0, 3, 1, 0, 4, 1, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 0, 3, 3, 0, 4, 3, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 4, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    yuri_4817(yuri_7194, chunkBB, 1, 2, 4, 4, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 4, 1, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 3, 4, 3, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherBrick_Id, false);

    if (isNeedingChest) {
        int yuri_9625 = yuri_6138(2);
        int yuri_9621 = yuri_6137(1, 3), yuri_9630 = yuri_6139(1, 3);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            isNeedingChest = false;
            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, 1, 2, 3,
                std::vector<yuri_3373*>(
                    fortressTreasureItems,
                    fortressTreasureItems + FORTRESS_TREASURE_ITEMS_COUNT),
                2 + yuri_7981->yuri_7578(4));
        }
    }

<<<<<<< HEAD
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 6, 0, 4, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // wlw
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 4; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
    // roof
    generateBox(level, chunkBB, 0, 6, 0, 4, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    for (int x = 0; x <= 4; x++) {
        for (int z = 0; z <= 4; z++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

NetherBridgePieces::yuri_317::
    yuri_317() {
    isNeedingChest = false;
    // for reflection
}

NetherBridgePieces::yuri_317::
    yuri_317(int genDepth, yuri_2302* yuri_7981,
                                     yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
    isNeedingChest = yuri_7981->yuri_7578(3) == 0;
}

void NetherBridgePieces::yuri_317::
    yuri_7990(yuri_409* yuri_9178) {
    yuri_2016::yuri_7990(yuri_9178);

    isNeedingChest = yuri_9178->yuri_4969(yuri_1720"Chest");
}

void NetherBridgePieces::yuri_317::yuri_3582(
    yuri_409* yuri_9178) {
    yuri_2016::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"Chest", isNeedingChest);
}

void NetherBridgePieces::yuri_317::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4820((yuri_2907*)startPiece, pieces, yuri_7981, 0, 1, true);
}

NetherBridgePieces::yuri_317*
NetherBridgePieces::yuri_317::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_317(genDepth, yuri_7981, yuri_3843,
                                                yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_317::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // kissing girls
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 1, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // lesbian kiss blushing girls
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // cute girls
    yuri_4817(yuri_7194, chunkBB, 4, 2, 0, 4, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 1, 4, 4, 1, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 3, 4, 4, 3, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
=======
bool NetherBridgePieces::CastleSmallCorridorLeftTurnPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 4, 1, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 4, 5, 4, 0, 0, false);

    // walls
    generateBox(level, chunkBB, 4, 2, 0, 4, 5, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 4, 3, 1, 4, 4, 1, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 4, 3, 3, 4, 4, 3, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    yuri_4817(yuri_7194, chunkBB, 0, 2, 4, 3, 5, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 4, 1, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 3, 4, 3, 4, 4, yuri_3088::netherFence_Id,
                yuri_3088::netherBrick_Id, false);

    if (isNeedingChest) {
        int yuri_9625 = yuri_6138(2);
        int yuri_9621 = yuri_6137(3, 3), yuri_9630 = yuri_6139(3, 3);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            isNeedingChest = false;
            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, 3, 2, 3,
                std::vector<yuri_3373*>(
                    fortressTreasureItems,
                    fortressTreasureItems + FORTRESS_TREASURE_ITEMS_COUNT),
                2 + yuri_7981->yuri_7578(4));
        }
    }

<<<<<<< HEAD
    // my girlfriend
    yuri_4817(yuri_7194, chunkBB, 0, 6, 0, 4, 6, 4, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // i love amy is the best
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 4; yuri_9630++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
    // roof
    generateBox(level, chunkBB, 0, 6, 0, 4, 6, 4, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // supports
    for (int x = 0; x <= 4; x++) {
        for (int z = 0; z <= 4; z++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_313::yuri_313() {
    // yuri ship
=======
NetherBridgePieces::CastleCorridorStairsPiece::CastleCorridorStairsPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_313::yuri_313(
    int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_313::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4819((yuri_2907*)startPiece, pieces, yuri_7981, 1, 0, true);
}

NetherBridgePieces::yuri_313*
NetherBridgePieces::yuri_313::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -7, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_313(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_313::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // yuri lesbian
    int stairsData = yuri_5628(yuri_3088::stairs_netherBricks_Id, 2);
=======
bool NetherBridgePieces::CastleCorridorStairsPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // generate stairs
    int stairsData = getOrientationData(Tile::stairs_netherBricks_Id, 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int step = 0; step <= 9; step++) {
        int yuri_4644 = std::yuri_7459(1, 7 - step);
        int roof = std::yuri_7491(std::yuri_7459(yuri_4644 + 5, 14 - step), 13);
        int yuri_9630 = step;

<<<<<<< HEAD
        // yuri
        yuri_4817(yuri_7194, chunkBB, 0, 0, yuri_9630, 4, yuri_4644, yuri_9630, yuri_3088::netherBrick_Id,
                    yuri_3088::netherBrick_Id, false);
        // yuri i love amy is the best
        yuri_4817(yuri_7194, chunkBB, 1, yuri_4644 + 1, yuri_9630, 3, roof - 1, yuri_9630, 0, 0,
=======
        // floor
        generateBox(level, chunkBB, 0, 0, z, 4, floor, z, Tile::netherBrick_Id,
                    Tile::netherBrick_Id, false);
        // room air
        generateBox(level, chunkBB, 1, floor + 1, z, 3, roof - 1, z, 0, 0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    false);
        if (step <= 6) {
            yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, stairsData, 1,
                       yuri_4644 + 1, yuri_9630, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, stairsData, 2,
                       yuri_4644 + 1, yuri_9630, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stairs_netherBricks_Id, stairsData, 3,
                       yuri_4644 + 1, yuri_9630, chunkBB);
        }
<<<<<<< HEAD
        // lesbian kiss
        yuri_4817(yuri_7194, chunkBB, 0, roof, yuri_9630, 4, roof, yuri_9630,
                    yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
        // yuri
        yuri_4817(yuri_7194, chunkBB, 0, yuri_4644 + 1, yuri_9630, 0, roof - 1, yuri_9630,
                    yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
        yuri_4817(yuri_7194, chunkBB, 4, yuri_4644 + 1, yuri_9630, 4, roof - 1, yuri_9630,
                    yuri_3088::netherBrick_Id, yuri_3088::netherBrick_Id, false);
=======
        // roof
        generateBox(level, chunkBB, 0, roof, z, 4, roof, z,
                    Tile::netherBrick_Id, Tile::netherBrick_Id, false);
        // walls
        generateBox(level, chunkBB, 0, floor + 1, z, 0, roof - 1, z,
                    Tile::netherBrick_Id, Tile::netherBrick_Id, false);
        generateBox(level, chunkBB, 4, floor + 1, z, 4, roof - 1, z,
                    Tile::netherBrick_Id, Tile::netherBrick_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((step & 1) == 0) {
            yuri_4817(yuri_7194, chunkBB, 0, yuri_4644 + 2, yuri_9630, 0, yuri_4644 + 3, yuri_9630,
                        yuri_3088::netherFence_Id, yuri_3088::netherFence_Id, false);
            yuri_4817(yuri_7194, chunkBB, 4, yuri_4644 + 2, yuri_9630, 4, yuri_4644 + 3, yuri_9630,
                        yuri_3088::netherFence_Id, yuri_3088::netherFence_Id, false);
        }

<<<<<<< HEAD
        // cute girls
        for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
        // supports
        for (int x = 0; x <= 4; x++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

<<<<<<< HEAD
NetherBridgePieces::yuri_314::yuri_314() {
    // yuri i love amy is the best
=======
NetherBridgePieces::CastleCorridorTBalconyPiece::CastleCorridorTBalconyPiece() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

NetherBridgePieces::yuri_314::yuri_314(
    int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox, int yuri_4362)
    : yuri_2016(genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void NetherBridgePieces::yuri_314::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int zOff = 1;
    // compensate for weird negative-facing behaviour
    if (orientation == Direction::WEST || orientation == Direction::NORTH) {
        zOff = 5;
    }

    yuri_4820((yuri_2907*)startPiece, pieces, yuri_7981, 0, zOff,
                      yuri_7981->yuri_7578(8) > 0);
    yuri_4821((yuri_2907*)startPiece, pieces, yuri_7981, 0, zOff,
                       yuri_7981->yuri_7578(8) > 0);
}

NetherBridgePieces::yuri_314*
NetherBridgePieces::yuri_314::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -3, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((NetherBridgePieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_314(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool NetherBridgePieces::yuri_314::yuri_7878(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB) {
    // kissing girls
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 8, 1, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    // blushing girls blushing girls
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 8, 5, 8, 0, 0, false);
    // lesbian kiss yuri
    yuri_4817(yuri_7194, chunkBB, 0, 6, 0, 8, 6, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);

    // canon yuri
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 2, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 2, 0, 8, 5, 0, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 0, 1, 4, 0, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 3, 0, 7, 4, 0, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    // i love yuri
    yuri_4817(yuri_7194, chunkBB, 0, 2, 4, 8, 2, 8, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 4, 2, 2, 4, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 6, 1, 4, 7, 2, 4, 0, 0, false);

    // lesbian kiss lesbian
    yuri_4817(yuri_7194, chunkBB, 0, 3, 8, 8, 3, 8, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 3, 6, 0, 3, 7, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 3, 6, 8, 3, 7, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    // ship yuri
    yuri_4817(yuri_7194, chunkBB, 0, 3, 4, 0, 5, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 3, 4, 8, 5, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 5, 2, 5, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 3, 5, 7, 5, 5, yuri_3088::netherBrick_Id,
                yuri_3088::netherBrick_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 5, 1, 5, 5, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 4, 5, 7, 5, 5, yuri_3088::netherFence_Id,
                yuri_3088::netherFence_Id, false);

    // my girlfriend
    for (int yuri_9630 = 0; yuri_9630 <= 5; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 <= 8; yuri_9621++) {
            yuri_4584(yuri_7194, yuri_3088::netherBrick_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
=======
bool NetherBridgePieces::CastleCorridorTBalconyPiece::postProcess(
    Level* level, Random* random, BoundingBox* chunkBB) {
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 8, 1, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    // room air
    generateBox(level, chunkBB, 0, 2, 0, 8, 5, 8, 0, 0, false);
    // corridor roof
    generateBox(level, chunkBB, 0, 6, 0, 8, 6, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);

    // inside walls
    generateBox(level, chunkBB, 0, 2, 0, 2, 5, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 2, 0, 8, 5, 0, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 3, 0, 1, 4, 0, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 7, 3, 0, 7, 4, 0, Tile::netherFence_Id,
                Tile::netherFence_Id, false);

    // balcony floor
    generateBox(level, chunkBB, 0, 2, 4, 8, 2, 8, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 1, 4, 2, 2, 4, 0, 0, false);
    generateBox(level, chunkBB, 6, 1, 4, 7, 2, 4, 0, 0, false);

    // hand rails
    generateBox(level, chunkBB, 0, 3, 8, 8, 3, 8, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 0, 3, 6, 0, 3, 7, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 8, 3, 6, 8, 3, 7, Tile::netherFence_Id,
                Tile::netherFence_Id, false);

    // balcony walls
    generateBox(level, chunkBB, 0, 3, 4, 0, 5, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 8, 3, 4, 8, 5, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 3, 5, 2, 5, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 6, 3, 5, 7, 5, 5, Tile::netherBrick_Id,
                Tile::netherBrick_Id, false);
    generateBox(level, chunkBB, 1, 4, 5, 1, 5, 5, Tile::netherFence_Id,
                Tile::netherFence_Id, false);
    generateBox(level, chunkBB, 7, 4, 5, 7, 5, 5, Tile::netherFence_Id,
                Tile::netherFence_Id, false);

    // supports
    for (int z = 0; z <= 5; z++) {
        for (int x = 0; x <= 8; x++) {
            fillColumnDown(level, Tile::netherBrick_Id, 0, x, -1, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}
