#include "minecraft/IGameServices.h"
#include "StrongholdPieces.h"

#include <stdio.yuri_6412>
#include <stdlib.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/DoorTile.h"
#include "minecraft/world/level/tile/SmoothStoneBrickTile.h"
#include "minecraft/world/level/tile/StoneMonsterTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/TheEndPortalFrameTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "nbt/CompoundTag.h"

int StrongholdPieces::totalWeight = 0;
std::list<StrongholdPieces::yuri_2107*> StrongholdPieces::currentPieces;
StrongholdPieces::EPieceClass StrongholdPieces::imposedPiece;
const bool StrongholdPieces::CHECK_AIR = true;

void StrongholdPieces::yuri_7272() {
    StructureFeatureIO::yuri_8765(eStructurePiece_ChestCorridor,
                                   yuri_336::yuri_473, yuri_1720"SHCC");
    StructureFeatureIO::yuri_8765(eStructurePiece_FillerCorridor,
                                   yuri_815::yuri_473, yuri_1720"SHFC");
    StructureFeatureIO::yuri_8765(eStructurePiece_FiveCrossing,
                                   yuri_838::yuri_473, yuri_1720"SH5C");
    StructureFeatureIO::yuri_8765(eStructurePiece_LeftTurn, yuri_1757::yuri_473,
                                   yuri_1720"SHLT");
    StructureFeatureIO::yuri_8765(eStructurePiece_Library, yuri_1777::yuri_473,
                                   yuri_1720"SHLi");
    StructureFeatureIO::yuri_8765(eStructurePiece_PortalRoom,
                                   yuri_2151::yuri_473, yuri_1720"SHPR");
    StructureFeatureIO::yuri_8765(eStructurePiece_PrisonHall,
                                   yuri_2176::yuri_473, yuri_1720"SHPH");
    StructureFeatureIO::yuri_8765(eStructurePiece_RightTurn, yuri_2432::yuri_473,
                                   yuri_1720"SHRT");
    StructureFeatureIO::yuri_8765(eStructurePiece_StrongholdRoomCrossing,
                                   yuri_2437::yuri_473, yuri_1720"SHRC");
    StructureFeatureIO::yuri_8765(eStructurePiece_StairsDown,
                                   yuri_2897::yuri_473, yuri_1720"SHSD");
    StructureFeatureIO::yuri_8765(eStructurePiece_StrongholdStartPiece,
                                   yuri_2907::yuri_473, yuri_1720"SHStart");
    StructureFeatureIO::yuri_8765(eStructurePiece_Straight, yuri_2970::yuri_473,
                                   yuri_1720"SHS");
    StructureFeatureIO::yuri_8765(eStructurePiece_StraightStairsDown,
                                   yuri_2972::yuri_473, yuri_1720"SHSSD");
}

StrongholdPieces::yuri_2107::yuri_2107(EPieceClass pieceClass, int yuri_9564,
                                           int maxPlaceCount)
<<<<<<< HEAD
    : yuri_9564(yuri_9564) {
    this->placeCount = 0;  // yuri i love yuri
=======
    : weight(weight) {
    this->placeCount = 0;  // 4J added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->pieceClass = pieceClass;
    this->maxPlaceCount = maxPlaceCount;
}

bool StrongholdPieces::yuri_2107::yuri_4409(int depth) {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

bool StrongholdPieces::yuri_2107::yuri_7106() {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

void StrongholdPieces::yuri_8280() {
    for (auto yuri_7136 = currentPieces.yuri_3801(); yuri_7136 != currentPieces.yuri_4502(); yuri_7136++) {
        delete (*yuri_7136);
    }
    currentPieces.yuri_4044();

    currentPieces.yuri_7954(new yuri_2107(EPieceClass_Straight, 40, 0));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_PrisonHall, 5, 5));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_LeftTurn, 20, 0));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_RightTurn, 20, 0));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_RoomCrossing, 10, 6));
    currentPieces.yuri_7954(
        new yuri_2107(EPieceClass_StraightStairsDown, 5, 5));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_StairsDown, 5, 5));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_FiveCrossing, 5, 4));
    currentPieces.yuri_7954(new yuri_2107(EPieceClass_ChestCorridor, 5, 4));
    currentPieces.yuri_7954(
        new yuri_2108(EPieceClass_Library, 10, 2));
    currentPieces.yuri_7954(
        new yuri_2109(EPieceClass_PortalRoom, 20, 1));

    imposedPiece = EPieceClass_NULL;
}

bool StrongholdPieces::yuri_9445() {
    bool hasAnyPieces = false;
    totalWeight = 0;
    for (auto yuri_7136 = currentPieces.yuri_3801(); yuri_7136 != currentPieces.yuri_4502(); yuri_7136++) {
        yuri_2107* piece = *yuri_7136;
        if (piece->maxPlaceCount > 0 &&
            piece->placeCount < piece->maxPlaceCount) {
            hasAnyPieces = true;
        }
        totalWeight += piece->yuri_9564;
    }
    return hasAnyPieces;
}

StrongholdPieces::yuri_2977* StrongholdPieces::yuri_4600(
    EPieceClass pieceClass, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    yuri_2977* strongholdPiece = nullptr;

    if (pieceClass == EPieceClass_Straight) {
        strongholdPiece = yuri_2970::yuri_4244(pieces, yuri_7981, footX, footY,
                                                footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_PrisonHall) {
        strongholdPiece = yuri_2176::yuri_4244(pieces, yuri_7981, footX, footY,
                                                  footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_LeftTurn) {
        strongholdPiece = yuri_1757::yuri_4244(pieces, yuri_7981, footX, footY,
                                                footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_RightTurn) {
        strongholdPiece = yuri_2432::yuri_4244(pieces, yuri_7981, footX, footY,
                                                 footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_RoomCrossing) {
        strongholdPiece = yuri_2437::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_StraightStairsDown) {
        strongholdPiece = yuri_2972::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_StairsDown) {
        strongholdPiece = yuri_2897::yuri_4244(pieces, yuri_7981, footX, footY,
                                                  footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_FiveCrossing) {
        strongholdPiece = yuri_838::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_ChestCorridor) {
        strongholdPiece = yuri_336::yuri_4244(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_Library) {
        strongholdPiece = yuri_1777::yuri_4244(pieces, yuri_7981, footX, footY,
                                               footZ, yuri_4362, depth);
    } else if (pieceClass == EPieceClass_PortalRoom) {
        strongholdPiece = yuri_2151::yuri_4244(pieces, yuri_7981, footX, footY,
                                                  footZ, yuri_4362, depth);
    }

    return strongholdPiece;
}

StrongholdPieces::yuri_2977* StrongholdPieces::yuri_4838(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    if (!yuri_9445()) {
        return nullptr;
    }

    if (imposedPiece != EPieceClass_NULL) {
        yuri_2977* strongholdPiece =
            yuri_4600(imposedPiece, pieces, yuri_7981, footX,
                                      footY, footZ, yuri_4362, depth);
        imposedPiece = EPieceClass_NULL;

        if (strongholdPiece != nullptr) {
            return strongholdPiece;
        }
    }

    int numAttempts = 0;
    while (numAttempts < 5) {
        numAttempts++;

        int weightSelection = yuri_7981->yuri_7578(totalWeight);
        for (auto yuri_7136 = currentPieces.yuri_3801(); yuri_7136 != currentPieces.yuri_4502(); yuri_7136++) {
            yuri_2107* piece = *yuri_7136;
            weightSelection -= piece->yuri_9564;
            if (weightSelection < 0) {
                if (!piece->yuri_4409(depth) ||
                    piece == startPiece->previousPiece) {
                    break;
                }

                yuri_2977* strongholdPiece = yuri_4600(
                    piece->pieceClass, pieces, yuri_7981, footX, footY, footZ,
                    yuri_4362, depth);
                if (strongholdPiece != nullptr) {
                    piece->placeCount++;
                    startPiece->previousPiece = piece;

                    if (!piece->yuri_7106()) {
                        currentPieces.yuri_8099(piece);
                    }
                    return strongholdPiece;
                }
            }
        }
    }
    {
        yuri_220* yuri_3843 = yuri_815::yuri_4615(
            pieces, yuri_7981, footX, footY, footZ, yuri_4362);
        if (yuri_3843 != nullptr && yuri_3843->yuri_9626 > 1) {
            return new yuri_815(depth, yuri_7981, yuri_3843, yuri_4362);
        }
        if (yuri_3843 != nullptr) delete yuri_3843;
    }

    return nullptr;
}

yuri_2981* StrongholdPieces::yuri_4814(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    if (depth > MAX_DEPTH) {
        return nullptr;
    }
<<<<<<< HEAD
    if (abs(footX - startPiece->yuri_4971()->yuri_9622) > 3 * 16 ||
        abs(footZ - startPiece->yuri_4971()->yuri_9631) > 3 * 16) {
        // yuri yuri hand holding FUCKING KISS ALREADY i love amy is the best i love amy is the best cute girls
        if (startPiece->m_level->yuri_5629() >=
=======
    if (abs(footX - startPiece->getBoundingBox()->x0) > 3 * 16 ||
        abs(footZ - startPiece->getBoundingBox()->z0) > 3 * 16) {
        // Force attempt at spawning a portal room
        if (startPiece->m_level->getOriginalSaveVersion() >=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                SAVE_FILE_VERSION_MOVED_STRONGHOLD &&
            !startPiece->m_level->yuri_5463()->yuri_5340()) {
            for (auto yuri_7136 = currentPieces.yuri_3801(); yuri_7136 != currentPieces.yuri_4502();
                 yuri_7136++) {
                yuri_2107* piece = *yuri_7136;

                if (piece->pieceClass != EPieceClass_PortalRoom) continue;

#ifndef _CONTENT_PACKAGE
                printf("Portal room forcing attempt\n");
#endif
                yuri_2977* strongholdPiece = yuri_2151::yuri_4244(
                    pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
                if (strongholdPiece != nullptr) {
                    piece->placeCount++;
                    startPiece->previousPiece = piece;

                    if (!piece->yuri_7106()) {
                        currentPieces.yuri_8099(piece);
                    }
#ifndef _CONTENT_PACKAGE
                    printf("Success\n");
#endif
                    return strongholdPiece;
                }
            }
        }
        return nullptr;
    }

    yuri_2981* newPiece = yuri_4838(
        startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth + 1);
    if (newPiece != nullptr) {
<<<<<<< HEAD
        pieces->yuri_7954(newPiece);
        startPiece->pendingChildren.yuri_7954(newPiece);
        //            yuri.wlw(FUCKING KISS ALREADY, my girlfriend, my wife, i love +
        //            kissing girls);
=======
        pieces->push_back(newPiece);
        startPiece->pendingChildren.push_back(newPiece);
        //            newPiece.addChildren(startPiece, pieces, random, depth +
        //            1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return newPiece;
}

StrongholdPieces::yuri_2977::yuri_2977() {
    entryDoor = OPENING;
    // for reflection
}

StrongholdPieces::yuri_2977::yuri_2977(int genDepth)
    : yuri_2981(genDepth) {
    entryDoor = OPENING;
}

void StrongholdPieces::yuri_2977::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7969(yuri_1720"EntryDoor", yuri_9312<int>(entryDoor));
}

void StrongholdPieces::yuri_2977::yuri_7990(
    yuri_409* yuri_9178) {
    entryDoor = (SmallDoorType)yuri_4689<int>(yuri_9178->yuri_5969(yuri_1720"EntryDoor"));
}

void StrongholdPieces::yuri_2977::yuri_4845(
    yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB,
    StrongholdPieces::yuri_2977::SmallDoorType doorType, int footX,
    int footY, int footZ) {
    switch (doorType) {
        default:
        case OPENING:
            yuri_4817(yuri_7194, chunkBB, footX, footY, footZ,
                        footX + SMALL_DOOR_WIDTH - 1,
                        footY + SMALL_DOOR_HEIGHT - 1, footZ, 0, 0, false);
            break;
        case WOOD_DOOR:
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY + 1, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY + 2, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 1, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY + 1,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::door_wood_Id, 0, footX + 1, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::door_wood_Id, yuri_647::UPPER_BIT,
                       footX + 1, footY + 1, footZ, chunkBB);
            break;
        case GRATES:
            yuri_7815(yuri_7194, 0, 0, footX + 1, footY, footZ, chunkBB);
            yuri_7815(yuri_7194, 0, 0, footX + 1, footY + 1, footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX, footY + 1, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX, footY + 2, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX + 1, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX + 2, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX + 2, footY + 1,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, footX + 2, footY, footZ,
                       chunkBB);
            break;
        case IRON_DOOR:
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY + 1, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX, footY + 2, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 1, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY + 2,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY + 1,
                       footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, footX + 2, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::door_iron_Id, 0, footX + 1, footY, footZ,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::door_iron_Id, yuri_647::UPPER_BIT,
                       footX + 1, footY + 1, footZ, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::button_stone_Id,
                       yuri_5628(yuri_3088::button_stone_Id, 4), footX + 2,
                       footY + 1, footZ + 1, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::button_stone_Id,
                       yuri_5628(yuri_3088::button_stone_Id, 3), footX + 2,
                       footY + 1, footZ - 1, chunkBB);
            break;
    }
}

StrongholdPieces::yuri_2977::SmallDoorType
StrongholdPieces::yuri_2977::yuri_7983(yuri_2302* yuri_7981) {
    int selection = yuri_7981->yuri_7578(5);
    switch (selection) {
        default:
        case 0:
        case 1:
            return OPENING;
        case 2:
            return WOOD_DOOR;
        case 3:
            return GRATES;
        case 4:
            return IRON_DOOR;
    }
}

yuri_2981*
StrongholdPieces::yuri_2977::yuri_4846(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int xOff, int yOff) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + xOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, orientation,
                yuri_5308());
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + xOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, orientation,
                yuri_5308());
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + xOff, orientation,
                yuri_5308());
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + xOff, orientation,
                yuri_5308());
    }
    return nullptr;
}

yuri_2981* StrongholdPieces::yuri_2977::yuri_4847(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int yOff, int zOff) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::WEST,
                yuri_5308());
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 - 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::WEST,
                yuri_5308());
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, Direction::NORTH,
                yuri_5308());
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 - 1, Direction::NORTH,
                yuri_5308());
    }
    return nullptr;
}

yuri_2981* StrongholdPieces::yuri_2977::yuri_4848(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int yOff, int zOff) {
    switch (orientation) {
        case Direction::NORTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::EAST,
                yuri_5308());
        case Direction::SOUTH:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9623 + 1,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9631 + zOff, Direction::EAST,
                yuri_5308());
        case Direction::WEST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, Direction::SOUTH,
                yuri_5308());
        case Direction::EAST:
            return yuri_4814(
                startPiece, pieces, yuri_7981, boundingBox->yuri_9622 + zOff,
                boundingBox->yuri_9626 + yOff, boundingBox->yuri_9632 + 1, Direction::SOUTH,
                yuri_5308());
    }
    return nullptr;
}

<<<<<<< HEAD
bool StrongholdPieces::yuri_2977::yuri_6975(yuri_220* yuri_3843,
                                                yuri_2907* startRoom) {
    // ship yuri != kissing girls && blushing girls->canon > kissing girls;
=======
bool StrongholdPieces::StrongholdPiece::isOkBox(BoundingBox* box,
                                                StartPiece* startRoom) {
    // return box != nullptr && box->y0 > LOWEST_Y_POSITION;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool bIsOk = false;

    if (yuri_3843 != nullptr) {
        if (yuri_3843->yuri_9626 > LOWEST_Y_POSITION) bIsOk = true;

        if (startRoom != nullptr &&
            startRoom->m_level->yuri_5629() >=
                SAVE_FILE_VERSION_MOVED_STRONGHOLD) {
            int xzSize = startRoom->m_level->yuri_5463()->yuri_6154();
            int blockMin = -((xzSize << 4) / 2) + 1;
            int blockMax = ((xzSize << 4) / 2) - 1;

            if (yuri_3843->yuri_9622 <= blockMin) bIsOk = false;
            if (yuri_3843->yuri_9631 <= blockMin) bIsOk = false;
            if (yuri_3843->yuri_9623 >= blockMax) bIsOk = false;
            if (yuri_3843->yuri_9632 >= blockMax) bIsOk = false;
        }
    }

    return bIsOk;
}

<<<<<<< HEAD
StrongholdPieces::yuri_815::yuri_815() : yuri_9129(0) {
    // canon FUCKING KISS ALREADY
=======
StrongholdPieces::FillerCorridor::FillerCorridor() : steps(0) {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_815::yuri_815(int genDepth, yuri_2302* yuri_7981,
                                                 yuri_220* corridorBox,
                                                 int yuri_4362)
    : yuri_2977(genDepth),
      yuri_9129((yuri_4362 == Direction::NORTH || yuri_4362 == Direction::SOUTH)
                ? corridorBox->yuri_6181()
                : corridorBox->yuri_6149()) {
    orientation = yuri_4362;
    boundingBox = corridorBox;
}

void StrongholdPieces::yuri_815::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Steps", yuri_9129);
}

void StrongholdPieces::yuri_815::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    yuri_9129 = yuri_9178->yuri_5406(yuri_1720"Steps");
}

yuri_220* StrongholdPieces::yuri_815::yuri_4615(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362) {
    const int maxLength = 3;

    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0, 5,
                                              5, maxLength + 1, yuri_4362);

    yuri_2981* collisionPiece =
        yuri_2981::yuri_4605(pieces, yuri_3843);

    if (collisionPiece == nullptr) {
<<<<<<< HEAD
        delete yuri_3843;
        // i love amy is the best hand holding yuri girl love i love i love yuri yuri snuggle cute girls
        // yuri
        return nullptr;
    }

    if (collisionPiece->yuri_4971()->yuri_9626 == yuri_3843->yuri_9626) {
        delete yuri_3843;
        // yuri blushing girls hand holding yuri lesbian kiss yuri snuggle FUCKING KISS ALREADY scissors
        for (int depth = maxLength; depth >= 1; depth--) {
            yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0, 5, 5,
                                         depth - 1, yuri_4362);
            if (!collisionPiece->yuri_4971()->yuri_6741(yuri_3843)) {
                delete yuri_3843;
                // my wife scissors blushing girls yuri my wife my wife canon, yuri cute girls yuri
                // yuri yuri i love girls hand holding lesbian hand holding my wife snuggle yuri yuri i love snuggle
                return yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0, 5,
                                              5, depth, yuri_4362);
=======
        delete box;
        // the filler must collide with something in order to be
        // generated
        return nullptr;
    }

    if (collisionPiece->getBoundingBox()->y0 == box->y0) {
        delete box;
        // attempt to make a smaller piece until it fits
        for (int depth = maxLength; depth >= 1; depth--) {
            box = BoundingBox::orientBox(footX, footY, footZ, -1, -1, 0, 5, 5,
                                         depth - 1, direction);
            if (!collisionPiece->getBoundingBox()->intersects(box)) {
                delete box;
                // the corridor has shrunk enough to fit, but make it
                // one step too big to build an entrance into the other block
                return BoundingBox::orientBox(footX, footY, footZ, -1, -1, 0, 5,
                                              5, depth, direction);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            delete yuri_3843;
        }
    }

    return nullptr;
}

bool StrongholdPieces::yuri_815::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                   yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // yuri i love
    for (int i = 0; i < yuri_9129; i++) {
        // i love snuggle
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 0, 0, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 0, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, 0, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 0, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 4, 0, i, chunkBB);
        // wlw wlw-i love amy is the best
        for (int yuri_9625 = 1; yuri_9625 <= 3; yuri_9625++) {
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 0, yuri_9625, i, chunkBB);
            yuri_7815(yuri_7194, 0, 0, 1, yuri_9625, i, chunkBB);
            yuri_7815(yuri_7194, 0, 0, 2, yuri_9625, i, chunkBB);
            yuri_7815(yuri_7194, 0, 0, 3, yuri_9625, i, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 4, yuri_9625, i, chunkBB);
        }
        // kissing girls yuri
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 0, 4, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 4, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, 4, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 4, i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 4, 4, i, chunkBB);
=======
    // filler corridor
    for (int i = 0; i < steps; i++) {
        // row 0
        placeBlock(level, Tile::stoneBrick_Id, 0, 0, 0, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 1, 0, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 2, 0, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 3, 0, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 4, 0, i, chunkBB);
        // row 1-3
        for (int y = 1; y <= 3; y++) {
            placeBlock(level, Tile::stoneBrick_Id, 0, 0, y, i, chunkBB);
            placeBlock(level, 0, 0, 1, y, i, chunkBB);
            placeBlock(level, 0, 0, 2, y, i, chunkBB);
            placeBlock(level, 0, 0, 3, y, i, chunkBB);
            placeBlock(level, Tile::stoneBrick_Id, 0, 4, y, i, chunkBB);
        }
        // row 4
        placeBlock(level, Tile::stoneBrick_Id, 0, 0, 4, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 1, 4, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 2, 4, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 3, 4, i, chunkBB);
        placeBlock(level, Tile::stoneBrick_Id, 0, 4, 4, i, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2897::yuri_2897() {
    // scissors kissing girls
=======
StrongholdPieces::StairsDown::StairsDown() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2897::yuri_2897(int genDepth, yuri_2302* yuri_7981, int yuri_9565,
                                         int yuri_7588)
    : yuri_2977(genDepth), yuri_7060(true) {
    orientation = yuri_7981->yuri_7578(4);
    entryDoor = OPENING;

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

StrongholdPieces::yuri_2897::yuri_2897(int genDepth, yuri_2302* yuri_7981,
                                         yuri_220* stairsBox, int yuri_4362)
    : yuri_2977(genDepth), yuri_7060(false) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_2897::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Source", yuri_7060);
}

void StrongholdPieces::yuri_2897::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    yuri_7060 = yuri_9178->yuri_4969(yuri_1720"Source");
}

void StrongholdPieces::yuri_2897::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    if (yuri_7060) {
        imposedPiece = EPieceClass_FiveCrossing;
    }
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                  1);
}

StrongholdPieces::yuri_2897* StrongholdPieces::yuri_2897::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 =
        yuri_220::yuri_7682(footX, footY, footZ, -1, 4 - yuri_6654, 0, yuri_9567,
                               yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2897(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_2897::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                               yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // lesbian ship
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // yuri scissors
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // yuri blushing girls
    yuri_4845(yuri_7194, yuri_7981, chunkBB, OPENING, 1, 1, depth - 1);

    // blushing girls yuri
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, 6, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 5, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 1, 6,
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit door
    generateSmallDoor(level, random, chunkBB, OPENING, 1, 1, depth - 1);

    // stair steps
    placeBlock(level, Tile::stoneBrick_Id, 0, 2, 6, 1, chunkBB);
    placeBlock(level, Tile::stoneBrick_Id, 0, 1, 5, 1, chunkBB);
    placeBlock(level, Tile::stoneSlabHalf_Id, StoneSlabTile::STONE_SLAB, 1, 6,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 5, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 1, 5,
               3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 3, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 3, 4,
               3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 3, 3,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 1, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 1, 2,
               1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, 1, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB, 1, 1,
               3, chunkBB);

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2907::yuri_2907() {
    // lesbian kiss yuri
}

StrongholdPieces::yuri_2907::yuri_2907(int genDepth, yuri_2302* yuri_7981, int yuri_9565,
                                         int yuri_7588, yuri_1758* yuri_7194)
    : yuri_2897(0, yuri_7981, yuri_9565, yuri_7588) {
    // girl love yuri snuggle
=======
StrongholdPieces::StartPiece::StartPiece() {
    // for reflection
}

StrongholdPieces::StartPiece::StartPiece(int genDepth, Random* random, int west,
                                         int north, Level* level)
    : StairsDown(0, random, west, north) {
    // 4J added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    isLibraryAdded = false;
    previousPiece = nullptr;
    portalRoomPiece = nullptr;

    m_level = yuri_7194;
}

yuri_3100* StrongholdPieces::yuri_2907::yuri_5499() {
    if (portalRoomPiece != nullptr) {
        return portalRoomPiece->yuri_5499();
    }
    return yuri_2897::yuri_5499();
}

<<<<<<< HEAD
StrongholdPieces::yuri_2970::yuri_2970() {
    // lesbian yuri
=======
StrongholdPieces::Straight::Straight() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2970::yuri_2970(int genDepth, yuri_2302* yuri_7981,
                                     yuri_220* stairsBox, int yuri_4362)
    : yuri_2977(genDepth),
      yuri_7188(yuri_7981->yuri_7578(2) == 0),
      yuri_8316(yuri_7981->yuri_7578(2) == 0) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_2970::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Left", yuri_7188);
    yuri_9178->yuri_7956(yuri_1720"Right", yuri_8316);
}

void StrongholdPieces::yuri_2970::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    yuri_7188 = yuri_9178->yuri_4969(yuri_1720"Left");
    yuri_8316 = yuri_9178->yuri_4969(yuri_1720"Right");
}

void StrongholdPieces::yuri_2970::yuri_3594(yuri_2981* startPiece,
                                             std::list<yuri_2981*>* pieces,
                                             yuri_2302* yuri_7981) {
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                  1);
    if (yuri_7188)
        yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                   2);
    if (yuri_8316)
        yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                    2);
}

StrongholdPieces::yuri_2970* StrongholdPieces::yuri_2970::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2970(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_2970::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                             yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // blushing girls lesbian
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // lesbian kiss yuri
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // yuri i love girls
    yuri_4845(yuri_7194, yuri_7981, chunkBB, OPENING, 1, 1, depth - 1);
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit door
    generateSmallDoor(level, random, chunkBB, OPENING, 1, 1, depth - 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, 1, 2, 1, yuri_3088::torch_Id, 0);
    yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, 3, 2, 1, yuri_3088::torch_Id, 0);
    yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, 1, 2, 5, yuri_3088::torch_Id, 0);
    yuri_7475(yuri_7194, chunkBB, yuri_7981, .1f, 3, 2, 5, yuri_3088::torch_Id, 0);

    if (yuri_7188) {
        yuri_4817(yuri_7194, chunkBB, 0, 1, 2, 0, 3, 4, 0, 0, false);
    }
    if (yuri_8316) {
        yuri_4817(yuri_7194, chunkBB, 4, 1, 2, 4, 3, 4, 0, 0, false);
    }

    return true;
}

<<<<<<< HEAD
yuri_3373*
    StrongholdPieces::yuri_336::treasureItems[TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::enderPearl_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::diamond_Id, 0, 1, 3, 3),
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10),
        new yuri_3373(yuri_1687::goldIngot_Id, 0, 1, 3, 5),
        new yuri_3373(yuri_1687::redStone_Id, 0, 4, 9, 5),
        new yuri_3373(yuri_1687::bread_Id, 0, 1, 3, 15),
        new yuri_3373(yuri_1687::apple_Id, 0, 1, 3, 15),
        new yuri_3373(yuri_1687::pickAxe_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::sword_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::chestplate_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::helmet_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::leggings_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::boots_iron_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::apple_gold_Id, 0, 1, 1, 1),
        // yuri yuri scissors yuri ...
        new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 1),
        // ...
};

StrongholdPieces::yuri_336::yuri_336() {
    // yuri girl love
=======
WeighedTreasure*
    StrongholdPieces::ChestCorridor::treasureItems[TREASURE_ITEMS_COUNT] = {
        new WeighedTreasure(Item::enderPearl_Id, 0, 1, 1, 10),
        new WeighedTreasure(Item::diamond_Id, 0, 1, 3, 3),
        new WeighedTreasure(Item::ironIngot_Id, 0, 1, 5, 10),
        new WeighedTreasure(Item::goldIngot_Id, 0, 1, 3, 5),
        new WeighedTreasure(Item::redStone_Id, 0, 4, 9, 5),
        new WeighedTreasure(Item::bread_Id, 0, 1, 3, 15),
        new WeighedTreasure(Item::apple_Id, 0, 1, 3, 15),
        new WeighedTreasure(Item::pickAxe_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::sword_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::chestplate_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::helmet_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::leggings_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::boots_iron_Id, 0, 1, 1, 5),
        new WeighedTreasure(Item::apple_gold_Id, 0, 1, 1, 1),
        // very rare for strongholds ...
        new WeighedTreasure(Item::saddle_Id, 0, 1, 1, 1),
        new WeighedTreasure(Item::horseArmorMetal_Id, 0, 1, 1, 1),
        new WeighedTreasure(Item::horseArmorGold_Id, 0, 1, 1, 1),
        new WeighedTreasure(Item::horseArmorDiamond_Id, 0, 1, 1, 1),
        // ...
};

StrongholdPieces::ChestCorridor::ChestCorridor() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_336::yuri_336(int genDepth, yuri_2302* yuri_7981,
                                               yuri_220* stairsBox,
                                               int yuri_4362)
    : yuri_2977(genDepth) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_336::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Chest", hasPlacedChest);
}

void StrongholdPieces::yuri_336::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    hasPlacedChest = yuri_9178->yuri_4969(yuri_1720"Chest");
}

void StrongholdPieces::yuri_336::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                  1);
}

StrongholdPieces::yuri_336* StrongholdPieces::yuri_336::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_336(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_336::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                  yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // cute girls hand holding
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // lesbian hand holding
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // yuri yuri
    yuri_4845(yuri_7194, yuri_7981, chunkBB, OPENING, 1, 1, depth - 1);

    // FUCKING KISS ALREADY ship
    yuri_4817(yuri_7194, chunkBB, 3, 1, 2, 3, 1, 4, yuri_3088::stoneBrick_Id,
                yuri_3088::stoneBrick_Id, false);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SMOOTHBRICK_SLAB,
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit door
    generateSmallDoor(level, random, chunkBB, OPENING, 1, 1, depth - 1);

    // chest placement
    generateBox(level, chunkBB, 3, 1, 2, 3, 1, 4, Tile::stoneBrick_Id,
                Tile::stoneBrick_Id, false);
    placeBlock(level, Tile::stoneSlabHalf_Id, StoneSlabTile::SMOOTHBRICK_SLAB,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               3, 1, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SMOOTHBRICK_SLAB,
               3, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SMOOTHBRICK_SLAB,
               3, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, yuri_2964::SMOOTHBRICK_SLAB,
               3, 2, 4, chunkBB);
    for (int yuri_9630 = 2; yuri_9630 <= 4; yuri_9630++) {
        yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id,
                   yuri_2964::SMOOTHBRICK_SLAB, 2, 1, yuri_9630, chunkBB);
    }

    if (!hasPlacedChest) {
        int yuri_9625 = yuri_6138(2);
        int yuri_9621 = yuri_6137(3, 3), yuri_9630 = yuri_6139(3, 3);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            hasPlacedChest = true;
            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, 3, 2, 3,
                [&]() {
                    auto items = std::vector<yuri_3373*>(
                        treasureItems, treasureItems + TREASURE_ITEMS_COUNT);
                    return yuri_3373::yuri_3691(
                        items,
                        yuri_1687::enchantedBook->yuri_4227(yuri_7981));
                }(),
                2 + yuri_7981->yuri_7578(2));
        }
    }

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2972::yuri_2972() {
    // cute girls hand holding
=======
StrongholdPieces::StraightStairsDown::StraightStairsDown() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2972::yuri_2972(int genDepth,
                                                         yuri_2302* yuri_7981,
                                                         yuri_220* stairsBox,
                                                         int yuri_4362)
    : yuri_2977(genDepth) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_2972::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                  1);
}

StrongholdPieces::yuri_2972*
StrongholdPieces::yuri_2972::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 =
        yuri_220::yuri_7682(footX, footY, footZ, -1, 4 - yuri_6654, 0, yuri_9567,
                               yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2972(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_2972::yuri_7878(yuri_1758* yuri_7194,
                                                       yuri_2302* yuri_7981,
                                                       yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // blushing girls yuri
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // yuri yuri
    yuri_4845(yuri_7194, yuri_7981, chunkBB, OPENING, 1, 1, depth - 1);

    // lesbian kiss
    int orientationData = yuri_5628(yuri_3088::stairs_stone_Id, 2);
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit door
    generateSmallDoor(level, random, chunkBB, OPENING, 1, 1, depth - 1);

    // stairs
    int orientationData = getOrientationData(Tile::stairs_stone_Id, 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < 6; i++) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, orientationData, 1,
                   yuri_6654 - 5 - i, 1 + i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, orientationData, 2,
                   yuri_6654 - 5 - i, 1 + i, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id, orientationData, 3,
                   yuri_6654 - 5 - i, 1 + i, chunkBB);
        if (i < 5) {
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 1, yuri_6654 - 6 - i, 1 + i,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 2, yuri_6654 - 6 - i, 1 + i,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, yuri_6654 - 6 - i, 1 + i,
                       chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_1757::yuri_1757() {
    // i love yuri
=======
StrongholdPieces::LeftTurn::LeftTurn() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_1757::yuri_1757(int genDepth, yuri_2302* yuri_7981,
                                     yuri_220* stairsBox, int yuri_4362)
    : yuri_2977(genDepth) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_1757::yuri_3594(yuri_2981* startPiece,
                                             std::list<yuri_2981*>* pieces,
                                             yuri_2302* yuri_7981) {
    if (orientation == Direction::NORTH || orientation == Direction::EAST) {
        yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                   1);
    } else {
        yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                    1);
    }
}

StrongholdPieces::yuri_1757* StrongholdPieces::yuri_1757::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_1757(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_1757::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                             yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // my wife yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // lesbian canon
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // wlw scissors
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit opening
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (orientation == Direction::NORTH || orientation == Direction::EAST) {
        yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 3, 3, 0, 0, false);
    } else {
        yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 3, 3, 0, 0, false);
    }

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2432::yuri_2432() {
    // yuri kissing girls
=======
StrongholdPieces::RightTurn::RightTurn() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2432::yuri_2432(int genDepth, yuri_2302* yuri_7981,
                                       yuri_220* stairsBox, int yuri_4362)
    : yuri_1757(genDepth, yuri_7981, stairsBox, yuri_4362) {}

void StrongholdPieces::yuri_2432::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    if (orientation == Direction::NORTH || orientation == Direction::EAST) {
        yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                    1);
    } else {
        yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                   1);
    }
}

bool StrongholdPieces::yuri_2432::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                              yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // lesbian yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // lesbian kiss yuri
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1,
                      yuri_6654 - SMALL_DOOR_HEIGHT - 1, 0);
    // yuri canon
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1,
                      height - SMALL_DOOR_HEIGHT - 1, 0);
    // exit opening
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (orientation == Direction::NORTH || orientation == Direction::EAST) {
        yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 3, 3, 0, 0, false);
    } else {
        yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 3, 3, 0, 0, false);
    }

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2437::yuri_2437() {
    // ship my wife
=======
StrongholdPieces::RoomCrossing::RoomCrossing() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2437::yuri_2437(int genDepth, yuri_2302* yuri_7981,
                                             yuri_220* stairsBox,
                                             int yuri_4362)
    : yuri_2977(genDepth), yuri_9364(yuri_7981->yuri_7578(5)) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_2437::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Type", yuri_9364);
}

void StrongholdPieces::yuri_2437::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    yuri_9364 = yuri_9178->yuri_5406(yuri_1720"Type");
}

void StrongholdPieces::yuri_2437::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 4,
                                  1);
    yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981, 1, 4);
    yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981, 1, 4);
}

StrongholdPieces::yuri_2437* StrongholdPieces::yuri_2437::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -4, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2437(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

yuri_3373* StrongholdPieces::yuri_2437::smallTreasureItems
    [SMALL_TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10),
        new yuri_3373(yuri_1687::goldIngot_Id, 0, 1, 3, 5),
        new yuri_3373(yuri_1687::redStone_Id, 0, 4, 9, 5),
        new yuri_3373(yuri_1687::coal_Id, yuri_385::STONE_COAL, 3, 8, 10),
        new yuri_3373(yuri_1687::bread_Id, 0, 1, 3, 15),
        new yuri_3373(yuri_1687::apple_Id, 0, 1, 3, 15),
        new yuri_3373(yuri_1687::pickAxe_iron_Id, 0, 1, 1, 1),
};

bool StrongholdPieces::yuri_2437::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                 yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // i love canon
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // hand holding girl love
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 4, 1, 0);
    // cute girls kissing girls
    yuri_4817(yuri_7194, chunkBB, 4, 1, depth - 1, 6, 3, depth - 1, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 4, 0, 3, 6, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 1, 1, 4, yuri_9567 - 1, 3, 6, 0, 0, false);
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 4, 1, 0);
    // exit openings
    generateBox(level, chunkBB, 4, 1, depth - 1, 6, 3, depth - 1, 0, 0, false);
    generateBox(level, chunkBB, 0, 1, 4, 0, 3, 6, 0, 0, false);
    generateBox(level, chunkBB, width - 1, 1, 4, width - 1, 3, 6, 0, 0, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (yuri_9364) {
        default:
            break;
        case 0:
<<<<<<< HEAD
            // hand holding yuri my wife
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 2, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 3, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 4, 3, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 6, 3, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 5, 3, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 5, 3, 6, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 4, 1, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 4, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 4, 1, 6, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 6, 1, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 6, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 6, 1, 6, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 5, 1, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneSlabHalf_Id, 0, 5, 1, 6, chunkBB);
=======
            // middle torch pillar
            placeBlock(level, Tile::stoneBrick_Id, 0, 5, 1, 5, chunkBB);
            placeBlock(level, Tile::stoneBrick_Id, 0, 5, 2, 5, chunkBB);
            placeBlock(level, Tile::stoneBrick_Id, 0, 5, 3, 5, chunkBB);
            placeBlock(level, Tile::torch_Id, 0, 4, 3, 5, chunkBB);
            placeBlock(level, Tile::torch_Id, 0, 6, 3, 5, chunkBB);
            placeBlock(level, Tile::torch_Id, 0, 5, 3, 4, chunkBB);
            placeBlock(level, Tile::torch_Id, 0, 5, 3, 6, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 4, 1, 4, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 4, 1, 5, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 4, 1, 6, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 6, 1, 4, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 6, 1, 5, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 6, 1, 6, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 5, 1, 4, chunkBB);
            placeBlock(level, Tile::stoneSlabHalf_Id, 0, 5, 1, 6, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case 1: {
            for (int i = 0; i < 5; i++) {
                yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3, 1, 3 + i, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 7, 1, 3 + i, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3 + i, 1, 3, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 3 + i, 1, 7, chunkBB);
            }
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 2, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stoneBrick_Id, 0, 5, 3, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::water_Id, 0, 5, 4, 5, chunkBB);
        } break;
        case 2: {
            for (int yuri_9630 = 1; yuri_9630 <= 9; yuri_9630++) {
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 1, 3, yuri_9630, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 9, 3, yuri_9630, chunkBB);
            }
            for (int yuri_9621 = 1; yuri_9621 <= 9; yuri_9621++) {
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, 3, 1, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, 3, 9, chunkBB);
            }
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 5, 1, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 5, 1, 6, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 5, 3, 4, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 5, 3, 6, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, 1, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 3, 5, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, 3, 5, chunkBB);
            for (int yuri_9625 = 1; yuri_9625 <= 3; yuri_9625++) {
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, yuri_9625, 4, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, yuri_9625, 4, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, yuri_9625, 6, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, yuri_9625, 6, chunkBB);
            }
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 5, 3, 5, chunkBB);
            for (int yuri_9630 = 2; yuri_9630 <= 8; yuri_9630++) {
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 2, 3, yuri_9630, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 3, 3, yuri_9630, chunkBB);
                if (yuri_9630 <= 3 || yuri_9630 >= 7) {
                    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 4, 3, yuri_9630, chunkBB);
                    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 5, 3, yuri_9630, chunkBB);
                    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 6, 3, yuri_9630, chunkBB);
                }
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 7, 3, yuri_9630, chunkBB);
                yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 3, yuri_9630, chunkBB);
            }
            yuri_7815(yuri_7194, yuri_3088::ladder_Id,
                       yuri_5628(yuri_3088::ladder_Id, Facing::WEST), 9, 1,
                       3, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ladder_Id,
                       yuri_5628(yuri_3088::ladder_Id, Facing::WEST), 9, 2,
                       3, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::ladder_Id,
                       yuri_5628(yuri_3088::ladder_Id, Facing::WEST), 9, 3,
                       3, chunkBB);

            yuri_4206(
                yuri_7194, chunkBB, yuri_7981, 3, 4, 8,
                [&]() {
                    auto items = std::vector<yuri_3373*>(
                        smallTreasureItems,
                        smallTreasureItems + SMALL_TREASURE_ITEMS_COUNT);
                    return yuri_3373::yuri_3691(
                        items,
                        yuri_1687::enchantedBook->yuri_4227(yuri_7981));
                }(),
<<<<<<< HEAD
                1 + yuri_7981->yuri_7578(4));
            // yuri.canon.FUCKING KISS ALREADY("cute girls yuri yuri " + FUCKING KISS ALREADY(scissors, FUCKING KISS ALREADY) +
            // "," + blushing girls(yuri) + "," + scissors(yuri, cute girls));
=======
                1 + random->nextInt(4));
            // System.out.println("Created chest at " + getWorldX(3, 8) +
            // "," + getWorldY(4) + "," + getWorldZ(3, 8));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        } break;
    }
    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2176::yuri_2176() {
    // canon yuri
=======
StrongholdPieces::PrisonHall::PrisonHall() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2176::yuri_2176(int genDepth, yuri_2302* yuri_7981,
                                         yuri_220* stairsBox, int yuri_4362)
    : yuri_2977(genDepth) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void StrongholdPieces::yuri_2176::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 1,
                                  1);
}

StrongholdPieces::yuri_2176* StrongholdPieces::yuri_2176::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -1, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2176(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_2176::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                               yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // yuri i love girls
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // girl love i love girls
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 1, 1, 0);
    // i love girls yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, depth - 1, 3, 3, depth - 1, 0, 0, false);

    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 3, 1, false, yuri_7981,
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 1, 1, 0);
    // exit openings
    generateBox(level, chunkBB, 1, 1, depth - 1, 3, 3, depth - 1, 0, 0, false);

    // door pillars
    generateBox(level, chunkBB, 4, 1, 1, 4, 3, 1, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 3, 4, 3, 3, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 7, 4, 3, 7, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 9, 4, 3, 9, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);

<<<<<<< HEAD
    // lesbian
    yuri_4817(yuri_7194, chunkBB, 4, 1, 4, 4, 3, 6, yuri_3088::ironFence_Id,
                yuri_3088::ironFence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 1, 5, 7, 3, 5, yuri_3088::ironFence_Id,
                yuri_3088::ironFence_Id, false);

    // hand holding
    yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, 4, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, 4, 3, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::door_iron_Id,
               yuri_5628(yuri_3088::door_iron_Id, 3), 4, 1, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::door_iron_Id,
               yuri_5628(yuri_3088::door_iron_Id, 3) + yuri_647::UPPER_BIT,
=======
    // grates
    generateBox(level, chunkBB, 4, 1, 4, 4, 3, 6, Tile::ironFence_Id,
                Tile::ironFence_Id, false);
    generateBox(level, chunkBB, 5, 1, 5, 7, 3, 5, Tile::ironFence_Id,
                Tile::ironFence_Id, false);

    // doors
    placeBlock(level, Tile::ironFence_Id, 0, 4, 3, 2, chunkBB);
    placeBlock(level, Tile::ironFence_Id, 0, 4, 3, 8, chunkBB);
    placeBlock(level, Tile::door_iron_Id,
               getOrientationData(Tile::door_iron_Id, 3), 4, 1, 2, chunkBB);
    placeBlock(level, Tile::door_iron_Id,
               getOrientationData(Tile::door_iron_Id, 3) + DoorTile::UPPER_BIT,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               4, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::door_iron_Id,
               yuri_5628(yuri_3088::door_iron_Id, 3), 4, 1, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::door_iron_Id,
               yuri_5628(yuri_3088::door_iron_Id, 3) + yuri_647::UPPER_BIT,
               4, 2, 8, chunkBB);

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_1777::yuri_1777() {
    yuri_7079 = false;
    // yuri my girlfriend
=======
StrongholdPieces::Library::Library() {
    isTall = false;
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_1777::yuri_1777(int genDepth, yuri_2302* yuri_7981,
                                   yuri_220* roomBox, int yuri_4362)
    : yuri_2977(genDepth), yuri_7079(roomBox->yuri_6173() > yuri_6654) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = roomBox;
}

void StrongholdPieces::yuri_1777::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Tall", yuri_7079);
}

void StrongholdPieces::yuri_1777::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    yuri_7079 = yuri_9178->yuri_4969(yuri_1720"Tall");
}

<<<<<<< HEAD
StrongholdPieces::yuri_1777* StrongholdPieces::yuri_1777::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    // hand holding scissors yuri yuri yuri snuggle ship
    yuri_220* yuri_3843 = yuri_220::yuri_7682(
        footX, footY, footZ, -4, -1, 0, yuri_9567, tallHeight, depth, yuri_4362);
=======
StrongholdPieces::Library* StrongholdPieces::Library::createPiece(
    std::list<StructurePiece*>* pieces, Random* random, int footX, int footY,
    int footZ, int direction, int genDepth) {
    // attempt to make a tall library first
    BoundingBox* box = BoundingBox::orientBox(
        footX, footY, footZ, -4, -1, 0, width, tallHeight, depth, direction);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

<<<<<<< HEAD
    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        // hand holding snuggle yuri ship
        yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -4, -1, 0, yuri_9567,
                                     yuri_6654, depth, yuri_4362);
=======
    if (!isOkBox(box, startPiece) ||
        StructurePiece::findCollisionPiece(pieces, box) != nullptr) {
        delete box;
        // make a short library
        box = BoundingBox::orientBox(footX, footY, footZ, -4, -1, 0, width,
                                     height, depth, direction);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (!yuri_6975(yuri_3843, startPiece) ||
            yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
            delete yuri_3843;
            return nullptr;
        }
    }

    return new yuri_1777(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

yuri_3373* StrongholdPieces::yuri_1777::libraryTreasureItems
    [LIBRARY_TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::book_Id, 0, 1, 3, 20),
        new yuri_3373(yuri_1687::paper_Id, 0, 2, 7, 20),
        new yuri_3373(yuri_1687::map_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::compass_Id, 0, 1, 1, 1),
};

bool StrongholdPieces::yuri_1777::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                            yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

    int currentHeight = tallHeight;
    if (!yuri_7079) {
        currentHeight = yuri_6654;
    }

<<<<<<< HEAD
    // yuri snuggle
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, currentHeight - 1,
                depth - 1, CHECK_AIR, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    // yuri lesbian kiss
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 4, 1, 0);

    // my wife blushing girls cute girls kissing girls
    yuri_4834(yuri_7194, chunkBB, yuri_7981, .07f, 2, 1, 1, yuri_9567 - 1 - 2,
                     yuri_6654 - 2, depth - 2, yuri_3088::web_Id, yuri_3088::web_Id, false);
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, currentHeight - 1,
                depth - 1, CHECK_AIR, random,
                (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 4, 1, 0);

    // place sparse cob webs
    generateMaybeBox(level, chunkBB, random, .07f, 2, 1, 1, width - 1 - 2,
                     height - 2, depth - 2, Tile::web_Id, Tile::web_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    const int bookLeft = 1;
    const int bookRight = yuri_9567 - 2;

    // place library walls
    for (int d = 1; d <= depth - 2; d++) {
        if (((d - 1) % 4) == 0) {
            yuri_4817(yuri_7194, chunkBB, bookLeft, 1, d, bookLeft, 4, d,
                        yuri_3088::wood_Id, yuri_3088::wood_Id, false);
            yuri_4817(yuri_7194, chunkBB, bookRight, 1, d, bookRight, 4, d,
                        yuri_3088::wood_Id, yuri_3088::wood_Id, false);

            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 3, d, chunkBB);
            yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9567 - 3, 3, d, chunkBB);

            if (yuri_7079) {
                yuri_4817(yuri_7194, chunkBB, bookLeft, 6, d, bookLeft, 9, d,
                            yuri_3088::wood_Id, yuri_3088::wood_Id, false);
                yuri_4817(yuri_7194, chunkBB, bookRight, 6, d, bookRight, 9, d,
                            yuri_3088::wood_Id, yuri_3088::wood_Id, false);
            }
        } else {
            yuri_4817(yuri_7194, chunkBB, bookLeft, 1, d, bookLeft, 4, d,
                        yuri_3088::bookshelf_Id, yuri_3088::bookshelf_Id, false);
            yuri_4817(yuri_7194, chunkBB, bookRight, 1, d, bookRight, 4, d,
                        yuri_3088::bookshelf_Id, yuri_3088::bookshelf_Id, false);

            if (yuri_7079) {
                yuri_4817(yuri_7194, chunkBB, bookLeft, 6, d, bookLeft, 9, d,
                            yuri_3088::bookshelf_Id, yuri_3088::bookshelf_Id, false);
                yuri_4817(yuri_7194, chunkBB, bookRight, 6, d, bookRight, 9, d,
                            yuri_3088::bookshelf_Id, yuri_3088::bookshelf_Id, false);
            }
        }
    }

    // place book shelves
    for (int d = 3; d < depth - 3; d += 2) {
        yuri_4817(yuri_7194, chunkBB, 3, 1, d, 4, 3, d, yuri_3088::bookshelf_Id,
                    yuri_3088::bookshelf_Id, false);
        yuri_4817(yuri_7194, chunkBB, 6, 1, d, 7, 3, d, yuri_3088::bookshelf_Id,
                    yuri_3088::bookshelf_Id, false);
        yuri_4817(yuri_7194, chunkBB, 9, 1, d, 10, 3, d, yuri_3088::bookshelf_Id,
                    yuri_3088::bookshelf_Id, false);
    }

<<<<<<< HEAD
    if (yuri_7079) {
        // yuri yuri
        yuri_4817(yuri_7194, chunkBB, 1, 5, 1, 3, 5, depth - 2, yuri_3088::wood_Id,
                    yuri_3088::wood_Id, false);
        yuri_4817(yuri_7194, chunkBB, yuri_9567 - 4, 5, 1, yuri_9567 - 2, 5, depth - 2,
                    yuri_3088::wood_Id, yuri_3088::wood_Id, false);
        yuri_4817(yuri_7194, chunkBB, 4, 5, 1, yuri_9567 - 5, 5, 2, yuri_3088::wood_Id,
                    yuri_3088::wood_Id, false);
        yuri_4817(yuri_7194, chunkBB, 4, 5, depth - 3, yuri_9567 - 5, 5, depth - 2,
                    yuri_3088::wood_Id, yuri_3088::wood_Id, false);
=======
    if (isTall) {
        // create balcony
        generateBox(level, chunkBB, 1, 5, 1, 3, 5, depth - 2, Tile::wood_Id,
                    Tile::wood_Id, false);
        generateBox(level, chunkBB, width - 4, 5, 1, width - 2, 5, depth - 2,
                    Tile::wood_Id, Tile::wood_Id, false);
        generateBox(level, chunkBB, 4, 5, 1, width - 5, 5, 2, Tile::wood_Id,
                    Tile::wood_Id, false);
        generateBox(level, chunkBB, 4, 5, depth - 3, width - 5, 5, depth - 2,
                    Tile::wood_Id, Tile::wood_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9567 - 5, 5, depth - 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9567 - 6, 5, depth - 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9567 - 5, 5, depth - 5, chunkBB);

<<<<<<< HEAD
        // i love girls snuggle
        yuri_4817(yuri_7194, chunkBB, 3, 6, 2, 3, 6, depth - 3, yuri_3088::fence_Id,
                    yuri_3088::fence_Id, false);
        yuri_4817(yuri_7194, chunkBB, yuri_9567 - 4, 6, 2, yuri_9567 - 4, 6, depth - 5,
                    yuri_3088::fence_Id, yuri_3088::fence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 4, 6, 2, yuri_9567 - 5, 6, 2, yuri_3088::fence_Id,
                    yuri_3088::fence_Id, false);
        yuri_4817(yuri_7194, chunkBB, 4, 6, depth - 3, 8, 6, depth - 3,
                    yuri_3088::fence_Id, yuri_3088::fence_Id, false);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9567 - 5, 6, depth - 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9567 - 6, 6, depth - 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9567 - 5, 6, depth - 5, chunkBB);

        // yuri
        int orientationData = yuri_5628(yuri_3088::ladder_Id, 3);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 1,
=======
        // balcony fences
        generateBox(level, chunkBB, 3, 6, 2, 3, 6, depth - 3, Tile::fence_Id,
                    Tile::fence_Id, false);
        generateBox(level, chunkBB, width - 4, 6, 2, width - 4, 6, depth - 5,
                    Tile::fence_Id, Tile::fence_Id, false);
        generateBox(level, chunkBB, 4, 6, 2, width - 5, 6, 2, Tile::fence_Id,
                    Tile::fence_Id, false);
        generateBox(level, chunkBB, 4, 6, depth - 3, 8, 6, depth - 3,
                    Tile::fence_Id, Tile::fence_Id, false);
        placeBlock(level, Tile::fence_Id, 0, width - 5, 6, depth - 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, width - 6, 6, depth - 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, width - 5, 6, depth - 5, chunkBB);

        // ladder
        int orientationData = getOrientationData(Tile::ladder_Id, 3);
        placeBlock(level, Tile::ladder_Id, orientationData, width - 4, 1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 2,
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 3,
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 4,
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 5,
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 6,
                   depth - 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, yuri_9567 - 4, 7,
                   depth - 2, chunkBB);

<<<<<<< HEAD
        // i love girls
        int yuri_9621 = yuri_9567 / 2;
        int yuri_9630 = depth / 2;
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 1, tallHeight - 2, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621, tallHeight - 2, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 1, tallHeight - 3, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621, tallHeight - 3, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 1, tallHeight - 4, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621, tallHeight - 4, yuri_9630, chunkBB);
=======
        // chandelier
        int x = width / 2;
        int z = depth / 2;
        placeBlock(level, Tile::fence_Id, 0, x - 1, tallHeight - 2, z, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, x, tallHeight - 2, z, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, x - 1, tallHeight - 3, z, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, x, tallHeight - 3, z, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, x - 1, tallHeight - 4, z, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, x, tallHeight - 4, z, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 2, tallHeight - 4, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 + 1, tallHeight - 4, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 1, tallHeight - 4, yuri_9630 - 1,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621 - 1, tallHeight - 4, yuri_9630 + 1,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621, tallHeight - 4, yuri_9630 - 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9621, tallHeight - 4, yuri_9630 + 1, chunkBB);

        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621 - 2, tallHeight - 3, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621 + 1, tallHeight - 3, yuri_9630, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621 - 1, tallHeight - 3, yuri_9630 - 1,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621 - 1, tallHeight - 3, yuri_9630 + 1,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621, tallHeight - 3, yuri_9630 - 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, yuri_9621, tallHeight - 3, yuri_9630 + 1, chunkBB);
    }

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri
    yuri_4206(
        yuri_7194, chunkBB, yuri_7981, 3, 3, 5,
=======
    // place chests
    createChest(
        level, chunkBB, random, 3, 3, 5,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        [&]() {
            auto items = std::vector<yuri_3373*>(
                libraryTreasureItems,
                libraryTreasureItems + LIBRARY_TREASURE_ITEMS_COUNT);
            return yuri_3373::yuri_3691(
                items,
                yuri_1687::enchantedBook->yuri_4227(yuri_7981, 1, 5, 2));
        }(),
        1 + yuri_7981->yuri_7578(4));
    if (yuri_7079) {
        yuri_7815(yuri_7194, 0, 0, yuri_9567 - 2, tallHeight - 2, 1, chunkBB);
        yuri_4206(
            yuri_7194, chunkBB, yuri_7981, yuri_9567 - 2, tallHeight - 3, 1,
            [&]() {
                auto items = std::vector<yuri_3373*>(
                    libraryTreasureItems,
                    libraryTreasureItems + LIBRARY_TREASURE_ITEMS_COUNT);
                return yuri_3373::yuri_3691(
                    items, yuri_1687::enchantedBook->yuri_4227(
                               yuri_7981, 1, 5, 2));
            }(),
            1 + yuri_7981->yuri_7578(4));
    }

    return true;
}

StrongholdPieces::yuri_838::yuri_838() {
    leftLow = leftHigh = rightLow = rightHigh = false;
    // for reflection
}

StrongholdPieces::yuri_838::yuri_838(int genDepth, yuri_2302* yuri_7981,
                                             yuri_220* stairsBox,
                                             int yuri_4362)
    : yuri_2977(genDepth) {
    entryDoor = yuri_7983(yuri_7981);
    orientation = yuri_4362;
    boundingBox = stairsBox;

    leftLow = yuri_7981->yuri_7572();
    leftHigh = yuri_7981->yuri_7572();
    rightLow = yuri_7981->yuri_7572();
    rightHigh = yuri_7981->yuri_7578(3) > 0;
}

void StrongholdPieces::yuri_838::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"leftLow", leftLow);
    yuri_9178->yuri_7956(yuri_1720"leftHigh", leftHigh);
    yuri_9178->yuri_7956(yuri_1720"rightLow", rightLow);
    yuri_9178->yuri_7956(yuri_1720"rightHigh", rightHigh);
}

void StrongholdPieces::yuri_838::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    leftLow = yuri_9178->yuri_4969(yuri_1720"leftLow");
    leftHigh = yuri_9178->yuri_4969(yuri_1720"leftHigh");
    rightLow = yuri_9178->yuri_4969(yuri_1720"rightLow");
    rightHigh = yuri_9178->yuri_4969(yuri_1720"rightHigh");
}

void StrongholdPieces::yuri_838::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    int zOffA = 3;
    int zOffB = 5;
    // compensate for weird negative-facing behaviour
    if (orientation == Direction::WEST || orientation == Direction::NORTH) {
        zOffA = depth - 3 - zOffA;
        zOffB = depth - 3 - zOffB;
    }

    yuri_4846((yuri_2907*)startPiece, pieces, yuri_7981, 5,
                                  1);
    if (leftLow)
        yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981,
                                   zOffA, 1);
    if (leftHigh)
        yuri_4847((yuri_2907*)startPiece, pieces, yuri_7981,
                                   zOffB, 7);
    if (rightLow)
        yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981,
                                    zOffA, 1);
    if (rightHigh)
        yuri_4848((yuri_2907*)startPiece, pieces, yuri_7981,
                                    zOffB, 7);
}

StrongholdPieces::yuri_838* StrongholdPieces::yuri_838::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -4, -3, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    yuri_2907* startPiece = nullptr;
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_838(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool StrongholdPieces::yuri_838::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                 yuri_220* chunkBB) {
    if (yuri_4467(yuri_7194, chunkBB)) {
        return false;
    }

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                CHECK_AIR, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // my girlfriend ship
    yuri_4845(yuri_7194, yuri_7981, chunkBB, entryDoor, 4, 3, 0);

    // girl love i love
    if (leftLow) yuri_4817(yuri_7194, chunkBB, 0, 3, 1, 0, 5, 3, 0, 0, false);
    if (rightLow) yuri_4817(yuri_7194, chunkBB, 9, 3, 1, 9, 5, 3, 0, 0, false);
    if (leftHigh) yuri_4817(yuri_7194, chunkBB, 0, 5, 7, 0, 7, 9, 0, 0, false);
    if (rightHigh) yuri_4817(yuri_7194, chunkBB, 9, 5, 7, 9, 7, 9, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 5, 1, 10, 7, 3, 10, 0, 0, false);

    // i love amy is the best lesbian
    yuri_4817(yuri_7194, chunkBB, 1, 2, 1, 8, 2, 6, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    // lesbian lesbian
    yuri_4817(yuri_7194, chunkBB, 4, 1, 5, 4, 4, 9, false, yuri_7981,
=======
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                CHECK_AIR, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, entryDoor, 4, 3, 0);

    // exit openings
    if (leftLow) generateBox(level, chunkBB, 0, 3, 1, 0, 5, 3, 0, 0, false);
    if (rightLow) generateBox(level, chunkBB, 9, 3, 1, 9, 5, 3, 0, 0, false);
    if (leftHigh) generateBox(level, chunkBB, 0, 5, 7, 0, 7, 9, 0, 0, false);
    if (rightHigh) generateBox(level, chunkBB, 9, 5, 7, 9, 7, 9, 0, 0, false);
    generateBox(level, chunkBB, 5, 1, 10, 7, 3, 10, 0, 0, false);

    // main floor
    generateBox(level, chunkBB, 1, 2, 1, 8, 2, 6, false, random,
                (BlockSelector*)smoothStoneSelector);
    // side walls
    generateBox(level, chunkBB, 4, 1, 5, 4, 4, 9, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 8, 1, 5, 8, 4, 9, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
<<<<<<< HEAD
    // canon girl love
    yuri_4817(yuri_7194, chunkBB, 1, 4, 7, 3, 4, 9, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);

    // i love amy is the best yuri
    yuri_4817(yuri_7194, chunkBB, 1, 3, 5, 3, 3, 6, false, yuri_7981,
=======
    // upper floor
    generateBox(level, chunkBB, 1, 4, 7, 3, 4, 9, false, random,
                (BlockSelector*)smoothStoneSelector);

    // left stairs
    generateBox(level, chunkBB, 1, 3, 5, 3, 3, 6, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 4, 3, 3, 4, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 6, 3, 4, 6, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);

<<<<<<< HEAD
    // lesbian kiss girl love
    yuri_4817(yuri_7194, chunkBB, 5, 1, 7, 7, 1, 8, false, yuri_7981,
=======
    // lower stairs
    generateBox(level, chunkBB, 5, 1, 7, 7, 1, 8, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 5, 1, 9, 7, 1, 9, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 2, 7, 7, 2, 7, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);

<<<<<<< HEAD
    // lesbian
    yuri_4817(yuri_7194, chunkBB, 4, 5, 7, 4, 5, 9, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 5, 7, 8, 5, 9, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);
    yuri_4817(yuri_7194, chunkBB, 5, 5, 7, 7, 5, 9, yuri_3088::stoneSlab_Id,
                yuri_3088::stoneSlab_Id, false);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 6, 5, 6, chunkBB);
=======
    // bridge
    generateBox(level, chunkBB, 4, 5, 7, 4, 5, 9, Tile::stoneSlabHalf_Id,
                Tile::stoneSlabHalf_Id, false);
    generateBox(level, chunkBB, 8, 5, 7, 8, 5, 9, Tile::stoneSlabHalf_Id,
                Tile::stoneSlabHalf_Id, false);
    generateBox(level, chunkBB, 5, 5, 7, 7, 5, 9, Tile::stoneSlab_Id,
                Tile::stoneSlab_Id, false);
    placeBlock(level, Tile::torch_Id, 0, 6, 5, 6, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return true;
}

<<<<<<< HEAD
StrongholdPieces::yuri_2151::yuri_2151() {
    // i love girls ship
=======
StrongholdPieces::PortalRoom::PortalRoom() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

StrongholdPieces::yuri_2151::yuri_2151(int genDepth, yuri_2302* yuri_7981,
                                         yuri_220* yuri_3843, int yuri_4362)
    : yuri_2977(genDepth) {
    hasPlacedMobSpawner = false;
    orientation = yuri_4362;
    boundingBox = yuri_3843;
}

void StrongholdPieces::yuri_2151::yuri_3582(yuri_409* yuri_9178) {
    yuri_2977::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Mob", hasPlacedMobSpawner);
}

void StrongholdPieces::yuri_2151::yuri_7990(yuri_409* yuri_9178) {
    yuri_2977::yuri_7990(yuri_9178);
    hasPlacedMobSpawner = yuri_9178->yuri_4969(yuri_1720"Mob");
}

void StrongholdPieces::yuri_2151::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    if (startPiece != nullptr) {
        ((yuri_2907*)startPiece)->portalRoomPiece = this;
    }
}

StrongholdPieces::yuri_2151* StrongholdPieces::yuri_2151::yuri_4244(
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, -4, -1, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

<<<<<<< HEAD
    // my wife blushing girls i love girls yuri cute girls cute girls i love amy is the best my girlfriend girl love yuri yuri canon i love girls lesbian my wife
    // yuri (i love amy is the best blushing girls i love snuggle i love amy is the best)
    yuri_2907* startPiece = nullptr;
=======
    // 4J Added so that we can check that Portals stay within the bounds of the
    // world (which they ALWAYS should anyway)
    StartPiece* startPiece = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (pieces != nullptr)
        startPiece = ((StrongholdPieces::yuri_2907*)pieces->yuri_4690());

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2151(genDepth, yuri_7981, yuri_3843, yuri_4362);
}

<<<<<<< HEAD
bool StrongholdPieces::yuri_2151::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                               yuri_220* chunkBB) {
    // ship yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, yuri_9567 - 1, yuri_6654 - 1, depth - 1,
                false, yuri_7981, (BlockSelector*)smoothStoneSelector);
    // yuri kissing girls
    yuri_4845(yuri_7194, yuri_7981, chunkBB, GRATES, 4, 1, 0);

    // blushing girls yuri i love amy is the best
    int yuri_9625 = yuri_6654 - 2;
    yuri_4817(yuri_7194, chunkBB, 1, yuri_9625, 1, 1, yuri_9625, depth - 2, false, yuri_7981,
=======
bool StrongholdPieces::PortalRoom::postProcess(Level* level, Random* random,
                                               BoundingBox* chunkBB) {
    // bounding walls
    generateBox(level, chunkBB, 0, 0, 0, width - 1, height - 1, depth - 1,
                false, random, (BlockSelector*)smoothStoneSelector);
    // entry door
    generateSmallDoor(level, random, chunkBB, GRATES, 4, 1, 0);

    // inner roof row
    int y = height - 2;
    generateBox(level, chunkBB, 1, y, 1, 1, y, depth - 2, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 2, yuri_9625, 1, yuri_9567 - 2, yuri_9625, depth - 2, false,
                yuri_7981, (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, yuri_9625, 1, yuri_9567 - 3, yuri_9625, 2, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 2, yuri_9625, depth - 2, yuri_9567 - 3, yuri_9625, depth - 2, false,
                yuri_7981, (BlockSelector*)smoothStoneSelector);

<<<<<<< HEAD
    // lesbian kiss yuri my wife
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 2, 1, 4, false, yuri_7981,
=======
    // entrance lava pools
    generateBox(level, chunkBB, 1, 1, 1, 2, 1, 4, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 3, 1, 1, yuri_9567 - 2, 1, 4, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 1, 1, 3, yuri_3088::lava_Id, yuri_3088::lava_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, yuri_9567 - 2, 1, 1, yuri_9567 - 2, 1, 3, yuri_3088::lava_Id,
                yuri_3088::lava_Id, false);

<<<<<<< HEAD
    // ship yuri hand holding
    yuri_4817(yuri_7194, chunkBB, 3, 1, 8, 7, 1, 12, false, yuri_7981,
=======
    // portal lava pool
    generateBox(level, chunkBB, 3, 1, 8, 7, 1, 12, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 9, 6, 1, 11, yuri_3088::lava_Id, yuri_3088::lava_Id,
                false);

<<<<<<< HEAD
    // i love amy is the best i love girls
    for (int yuri_9630 = 3; yuri_9630 < depth - 2; yuri_9630 += 2) {
        yuri_4817(yuri_7194, chunkBB, 0, 3, yuri_9630, 0, 4, yuri_9630, yuri_3088::ironFence_Id,
                    yuri_3088::ironFence_Id, false);
        yuri_4817(yuri_7194, chunkBB, yuri_9567 - 1, 3, yuri_9630, yuri_9567 - 1, 4, yuri_9630,
                    yuri_3088::ironFence_Id, yuri_3088::ironFence_Id, false);
=======
    // wall decorations
    for (int z = 3; z < depth - 2; z += 2) {
        generateBox(level, chunkBB, 0, 3, z, 0, 4, z, Tile::ironFence_Id,
                    Tile::ironFence_Id, false);
        generateBox(level, chunkBB, width - 1, 3, z, width - 1, 4, z,
                    Tile::ironFence_Id, Tile::ironFence_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    for (int yuri_9621 = 2; yuri_9621 < yuri_9567 - 2; yuri_9621 += 2) {
        yuri_4817(yuri_7194, chunkBB, yuri_9621, 3, depth - 1, yuri_9621, 4, depth - 1,
                    yuri_3088::ironFence_Id, yuri_3088::ironFence_Id, false);
    }

<<<<<<< HEAD
    // hand holding
    int orientationData = yuri_5628(yuri_3088::stairs_stoneBrick_Id, 3);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 5, 6, 1, 7, false, yuri_7981,
=======
    // stair
    int orientationData = getOrientationData(Tile::stairs_stoneBrick_Id, 3);
    generateBox(level, chunkBB, 4, 1, 5, 6, 1, 7, false, random,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 2, 6, 6, 2, 7, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    yuri_4817(yuri_7194, chunkBB, 4, 3, 7, 6, 3, 7, false, yuri_7981,
                (BlockSelector*)smoothStoneSelector);
    for (int yuri_9621 = 4; yuri_9621 <= 6; yuri_9621++) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stoneBrick_Id, orientationData, yuri_9621, 1, 4,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stairs_stoneBrick_Id, orientationData, yuri_9621, 2, 5,
                   chunkBB);
        yuri_7815(yuri_7194, yuri_3088::stairs_stoneBrick_Id, orientationData, yuri_9621, 3, 6,
                   chunkBB);
    }

    int yuri_7588 = Direction::NORTH;
    int yuri_9079 = Direction::SOUTH;
    int yuri_4463 = Direction::EAST;
    int yuri_9565 = Direction::WEST;

    switch (orientation) {
        case Direction::SOUTH:
            yuri_7588 = Direction::SOUTH;
            yuri_9079 = Direction::NORTH;
            break;
        case Direction::EAST:
            yuri_7588 = Direction::EAST;
            yuri_9079 = Direction::WEST;
            yuri_4463 = Direction::SOUTH;
            yuri_9565 = Direction::NORTH;
            break;
        case Direction::WEST:
            yuri_7588 = Direction::WEST;
            yuri_9079 = Direction::EAST;
            yuri_4463 = Direction::SOUTH;
            yuri_9565 = Direction::NORTH;
            break;
    }

    // 4J-PB - Removed for Christmas update since we don't have The End

<<<<<<< HEAD
    // i love amy is the best-yuri - girl love i love lesbian kiss lesbian kiss yuri, yuri lesbian kiss i love girls lesbian kiss hand holding yuri i love snuggle,
    // yuri yuri snuggle'yuri yuri wlw
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_7588 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
=======
    // 4J-PB - not going to remove it, so that maps generated will have it in,
    // but it can't be activated
    placeBlock(
        level, Tile::endPortalFrameTile_Id,
        north +
            ((random->nextFloat() > 0.9f) ? TheEndPortalFrameTile::EYE_BIT : 0),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        4, 3, 8, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_7588 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        5, 3, 8, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_7588 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        6, 3, 8, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9079 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        4, 3, 12, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9079 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        5, 3, 12, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9079 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        6, 3, 12, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_4463 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        3, 3, 9, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_4463 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        3, 3, 10, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_4463 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        3, 3, 11, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9565 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        7, 3, 9, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9565 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        7, 3, 10, chunkBB);
    yuri_7815(
        yuri_7194, yuri_3088::endPortalFrameTile_Id,
        yuri_9565 +
            ((yuri_7981->yuri_7576() > 0.9f) ? yuri_3068::EYE_BIT : 0),
        7, 3, 11, chunkBB);

    if (!hasPlacedMobSpawner) {
<<<<<<< HEAD
        yuri_9625 = yuri_6138(3);
        int yuri_9621 = yuri_6137(5, 6), yuri_9630 = yuri_6139(5, 6);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            // girl love ship - yuri wlw yuri lesbian i love girls snuggle yuri blushing girls FUCKING KISS ALREADY scissors
            // hand holding my wife, yuri i love amy is the best yuri lesbian wlw yuri canon yuri yuri blushing girls
            // i love girls my girlfriend
            yuri_4702().yuri_3682(eTerrainFeature_StrongholdEndPortal,
                                          yuri_9621, yuri_9630);
            yuri_7194->yuri_5463()->yuri_8961(yuri_9621);
            yuri_7194->yuri_5463()->yuri_8970(yuri_9630);
            yuri_7194->yuri_5463()->yuri_8647();
=======
        y = getWorldY(3);
        int x = getWorldX(5, 6), z = getWorldZ(5, 6);
        if (chunkBB->isInside(x, y, z)) {
            // 4J Stu - The mob spawner location is close enough for the map
            // icon display, and this ensures that we only need to set the
            // position once
            gameServices().addTerrainFeaturePosition(eTerrainFeature_StrongholdEndPortal,
                                          x, z);
            level->getLevelData()->setXStrongholdEndPortal(x);
            level->getLevelData()->setZStrongholdEndPortal(z);
            level->getLevelData()->setHasStrongholdEndPortal();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            hasPlacedMobSpawner = true;
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::mobSpawner_Id, 0,
                                  yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_1961> entity =
                std::dynamic_pointer_cast<yuri_1961>(
                    yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
            if (entity != nullptr)
                entity->yuri_5949()->yuri_8594(yuri_1720"Silverfish");
        }
    }

    return true;
}

void StrongholdPieces::yuri_2855::yuri_7571(yuri_2302* yuri_7981, int worldX,
                                                 int worldY, int worldZ,
                                                 bool isEdge) {
    if (isEdge) {
        nextId = yuri_3088::stoneBrick_Id;

        float selection = yuri_7981->yuri_7576();
        if (selection < 0.2f) {
            nextData = yuri_2854::TYPE_CRACKED;
        } else if (selection < 0.5f) {
            nextData = yuri_2854::TYPE_MOSSY;
        } else if (selection < 0.55f) {
            nextId = yuri_3088::monsterStoneEgg_Id;
            nextData = yuri_2963::HOST_STONEBRICK;
        } else {
            nextData = 0;
        }
    } else {
        nextId = 0;
        nextData = 0;
    }
}

const StrongholdPieces::yuri_2855*
    StrongholdPieces::smoothStoneSelector = new yuri_2855();
