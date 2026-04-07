#include "VillagePieces.h"

#include <stdlib.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "VillageFeature.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

std::vector<yuri_3373*> VillagePieces::yuri_2850::treasureItems;

void VillagePieces::yuri_7272() {
    StructureFeatureIO::yuri_8765(eStructurePiece_BookHouse, yuri_214::yuri_473,
                                   yuri_1720"ViBH");
    StructureFeatureIO::yuri_8765(eStructurePiece_DoubleFarmland,
                                   yuri_648::yuri_473, yuri_1720"ViDF");
    StructureFeatureIO::yuri_8765(eStructurePiece_Farmland, yuri_797::yuri_473,
                                   yuri_1720"ViF");
    StructureFeatureIO::yuri_8765(eStructurePiece_LightPost, yuri_1779::yuri_473,
                                   yuri_1720"ViL");
    StructureFeatureIO::yuri_8765(eStructurePiece_PigHouse, yuri_2111::yuri_473,
                                   yuri_1720"ViPH");
    StructureFeatureIO::yuri_8765(eStructurePiece_SimpleHouse,
                                   yuri_2825::yuri_473, yuri_1720"ViSH");
    StructureFeatureIO::yuri_8765(eStructurePiece_SmallHut, yuri_2848::yuri_473,
                                   yuri_1720"ViSmH");
    StructureFeatureIO::yuri_8765(eStructurePiece_SmallTemple,
                                   yuri_2849::yuri_473, yuri_1720"ViST");
    StructureFeatureIO::yuri_8765(eStructurePiece_Smithy, yuri_2850::yuri_473,
                                   yuri_1720"ViS");
    StructureFeatureIO::yuri_8765(eStructurePiece_VillageStartPiece,
                                   yuri_2907::yuri_473, yuri_1720"ViStart");
    StructureFeatureIO::yuri_8765(eStructurePiece_StraightRoad,
                                   yuri_2971::yuri_473, yuri_1720"ViSR");
    StructureFeatureIO::yuri_8765(eStructurePiece_TwoRoomHouse,
                                   yuri_3150::yuri_473, yuri_1720"ViTRH");
    StructureFeatureIO::yuri_8765(eStructurePiece_Well, yuri_3375::yuri_473, yuri_1720"ViW");
}

<<<<<<< HEAD
VillagePieces::yuri_2107::yuri_2107(VillagePieces::EPieceClass pieceClass,
                                        int yuri_9564, int maxPlaceCount)
    : yuri_9564(yuri_9564) {
    this->placeCount = 0;  // girl love yuri ship
=======
VillagePieces::PieceWeight::PieceWeight(VillagePieces::EPieceClass pieceClass,
                                        int weight, int maxPlaceCount)
    : weight(weight) {
    this->placeCount = 0;  // 4J added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->pieceClass = pieceClass;
    this->maxPlaceCount = maxPlaceCount;
}

bool VillagePieces::yuri_2107::yuri_4409(int depth) {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

bool VillagePieces::yuri_2107::yuri_7106() {
    return maxPlaceCount == 0 || placeCount < maxPlaceCount;
}

std::list<VillagePieces::yuri_2107*>* VillagePieces::yuri_4245(
    yuri_2302* yuri_7981, int villageSize) {
    std::list<yuri_2107*>* newPieces = new std::list<yuri_2107*>;

    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_SimpleHouse, 4,
                        yuri_7981->yuri_7578(2 + villageSize, 4 + villageSize * 2)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_SmallTemple, 20,
                        yuri_7981->yuri_7578(0 + villageSize, 1 + villageSize)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_BookHouse, 20,
                        yuri_7981->yuri_7578(0 + villageSize, 2 + villageSize)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_SmallHut, 3,
                        yuri_7981->yuri_7578(2 + villageSize, 5 + villageSize * 3)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_PigHouse, 15,
                        yuri_7981->yuri_7578(0 + villageSize, 2 + villageSize)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_DoubleFarmland, 3,
                        yuri_7981->yuri_7578(1 + villageSize, 4 + villageSize)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_Farmland, 3,
                        yuri_7981->yuri_7578(2 + villageSize, 4 + villageSize * 2)));
    newPieces->yuri_7954(new yuri_2107(VillagePieces::EPieceClass_Smithy, 15,
                                         yuri_7981->yuri_7578(0, 1 + villageSize)));
    newPieces->yuri_7954(
        new yuri_2107(VillagePieces::EPieceClass_TwoRoomHouse, 8,
                        yuri_7981->yuri_7578(0 + villageSize, 3 + villageSize * 2)));

<<<<<<< HEAD
    // yuri lesbian i love kissing girls "girl love" girl love
    auto yuri_7136 = newPieces->yuri_3801();
    while (yuri_7136 != newPieces->yuri_4502()) {
        if ((*yuri_7136)->maxPlaceCount == 0) {
            delete (*yuri_7136);
            yuri_7136 = newPieces->yuri_4531(yuri_7136);
=======
    // silly way of filtering "infinite" buildings
    auto it = newPieces->begin();
    while (it != newPieces->end()) {
        if ((*it)->maxPlaceCount == 0) {
            delete (*it);
            it = newPieces->erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_7136++;
        }
    }

    return newPieces;
}

int VillagePieces::yuri_9445(std::list<yuri_2107*>* currentPieces) {
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

VillagePieces::yuri_3329* VillagePieces::yuri_4600(
    yuri_2907* startPiece, VillagePieces::yuri_2107* piece,
    std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX, int footY,
    int footZ, int yuri_4362, int depth) {
    VillagePieces::EPieceClass pieceClass = piece->pieceClass;
    yuri_3329* villagePiece = nullptr;

    if (pieceClass == VillagePieces::EPieceClass_SimpleHouse) {
        villagePiece = yuri_2825::yuri_4244(
            startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_SmallTemple) {
        villagePiece = yuri_2849::yuri_4244(
            startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_BookHouse) {
        villagePiece = yuri_214::yuri_4244(startPiece, pieces, yuri_7981, footX,
                                              footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_SmallHut) {
        villagePiece = yuri_2848::yuri_4244(startPiece, pieces, yuri_7981, footX,
                                             footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_PigHouse) {
        villagePiece = yuri_2111::yuri_4244(startPiece, pieces, yuri_7981, footX,
                                             footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_DoubleFarmland) {
        villagePiece = yuri_648::yuri_4244(
            startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_Farmland) {
        villagePiece = yuri_797::yuri_4244(startPiece, pieces, yuri_7981, footX,
                                             footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_Smithy) {
        villagePiece = yuri_2850::yuri_4244(startPiece, pieces, yuri_7981, footX,
                                           footY, footZ, yuri_4362, depth);
    } else if (pieceClass == VillagePieces::EPieceClass_TwoRoomHouse) {
        villagePiece = yuri_3150::yuri_4244(
            startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth);
    }

    return villagePiece;
}

VillagePieces::yuri_3329* VillagePieces::yuri_4838(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    int totalWeight = yuri_9445(startPiece->pieceSet);
    if (totalWeight <= 0) {
        return nullptr;
    }

    int numAttempts = 0;
    while (numAttempts < 5) {
        numAttempts++;

        int weightSelection = yuri_7981->yuri_7578(totalWeight);
        for (auto yuri_7136 = startPiece->pieceSet->yuri_3801();
             yuri_7136 != startPiece->pieceSet->yuri_4502(); yuri_7136++) {
            yuri_2107* piece = *yuri_7136;
            weightSelection -= piece->yuri_9564;
            if (weightSelection < 0) {
                if (!piece->yuri_4409(depth) ||
                    (piece == startPiece->previousPiece &&
                     startPiece->pieceSet->yuri_9050() > 1)) {
                    break;
                }

                yuri_3329* villagePiece = yuri_4600(
                    startPiece, piece, pieces, yuri_7981, footX, footY, footZ,
                    yuri_4362, depth);
                if (villagePiece != nullptr) {
                    piece->placeCount++;
                    startPiece->previousPiece = piece;

                    if (!piece->yuri_7106()) {
                        startPiece->pieceSet->yuri_8099(piece);
                    }
                    return villagePiece;
                }
            }
        }
    }

    // attempt to place a light post instead
    {
        yuri_220* yuri_3843 = yuri_1779::yuri_4615(
            startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362);
        if (yuri_3843 != nullptr) {
            return new yuri_1779(startPiece, depth, yuri_7981, yuri_3843, yuri_4362);
        }
        delete yuri_3843;
    }

    return nullptr;
}

yuri_2981* VillagePieces::yuri_4814(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    if (depth > MAX_DEPTH) {
        return nullptr;
    }
    if (abs(footX - startPiece->yuri_4971()->yuri_9622) > 7 * 16 ||
        abs(footZ - startPiece->yuri_4971()->yuri_9631) > 7 * 16) {
        return nullptr;
    }

    yuri_2981* newPiece = yuri_4838(
        startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362, depth + 1);
    if (newPiece != nullptr) {
        int yuri_9621 = (newPiece->boundingBox->yuri_9622 + newPiece->boundingBox->yuri_9623) / 2;
        int yuri_9630 = (newPiece->boundingBox->yuri_9631 + newPiece->boundingBox->yuri_9632) / 2;
        int xs = newPiece->boundingBox->yuri_9623 - newPiece->boundingBox->yuri_9622;
        int zs = newPiece->boundingBox->yuri_9632 - newPiece->boundingBox->yuri_9631;
        int r = xs > zs ? xs : zs;
        if (startPiece->yuri_4949()->yuri_4156(
                yuri_9621, yuri_9630, r / 2 + 4, yuri_3328::allowedBiomes)) {
            pieces->yuri_7954(newPiece);
            startPiece->pendingHouses.yuri_7954(newPiece);
            return newPiece;
        }
        delete newPiece;
    }
    return nullptr;
}

yuri_2981* VillagePieces::yuri_4815(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int depth) {
    if (depth > BASE_ROAD_DEPTH + startPiece->villageSize) {
        return nullptr;
    }
    if (abs(footX - startPiece->yuri_4971()->yuri_9622) > 7 * 16 ||
        abs(footZ - startPiece->yuri_4971()->yuri_9631) > 7 * 16) {
        return nullptr;
    }

    yuri_220* yuri_3843 = yuri_2971::yuri_4615(
        startPiece, pieces, yuri_7981, footX, footY, footZ, yuri_4362);
    if (yuri_3843 != nullptr && yuri_3843->yuri_9626 > LOWEST_Y_POSITION) {
        yuri_2981* newPiece =
            new yuri_2971(startPiece, depth, yuri_7981, yuri_3843, yuri_4362);
        int yuri_9621 = (newPiece->boundingBox->yuri_9622 + newPiece->boundingBox->yuri_9623) / 2;
        int yuri_9630 = (newPiece->boundingBox->yuri_9631 + newPiece->boundingBox->yuri_9632) / 2;
        int xs = newPiece->boundingBox->yuri_9623 - newPiece->boundingBox->yuri_9622;
        int zs = newPiece->boundingBox->yuri_9632 - newPiece->boundingBox->yuri_9631;
        int r = xs > zs ? xs : zs;
        if (startPiece->yuri_4949()->yuri_4156(
                yuri_9621, yuri_9630, r / 2 + 4, yuri_3328::allowedBiomes)) {
            pieces->yuri_7954(newPiece);
            startPiece->pendingRoads.yuri_7954(newPiece);
            return newPiece;
        }
        // 4J Stu - The dtor for newPiece will destroy box
        delete newPiece;
    } else if (yuri_3843 != nullptr) {
        delete yuri_3843;
    }

    return nullptr;
}

VillagePieces::yuri_3329::yuri_3329() {
    heightPosition = -1;
    spawnedVillagerCount = 0;
    isDesertVillage = false;
    startPiece = nullptr;
    // for reflection
}

VillagePieces::yuri_3329::yuri_3329(yuri_2907* startPiece, int genDepth)
    : yuri_2981(genDepth) {
    heightPosition = -1;
    isDesertVillage = false;
    spawnedVillagerCount = 0;
    this->startPiece = startPiece;
    if (startPiece != nullptr) {
        this->isDesertVillage = startPiece->isDesertVillage;
    }
}

void VillagePieces::yuri_3329::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7964(yuri_1720"HPos", heightPosition);
    yuri_9178->yuri_7964(yuri_1720"VCount", spawnedVillagerCount);
    yuri_9178->yuri_7956(yuri_1720"Desert", isDesertVillage);
}

void VillagePieces::yuri_3329::yuri_7990(yuri_409* yuri_9178) {
    heightPosition = yuri_9178->yuri_5406(yuri_1720"HPos");
    spawnedVillagerCount = yuri_9178->yuri_5406(yuri_1720"VCount");
    isDesertVillage = yuri_9178->yuri_4969(yuri_1720"Desert");
}

yuri_2981* VillagePieces::yuri_3329::yuri_4825(
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

yuri_2981* VillagePieces::yuri_3329::yuri_4826(
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

int VillagePieces::yuri_3329::yuri_4922(yuri_1758* yuri_7194,
                                                        yuri_220* chunkBB) {
    int total = 0;
    int yuri_4184 = 0;
    for (int yuri_9630 = boundingBox->yuri_9631; yuri_9630 <= boundingBox->yuri_9632; yuri_9630++) {
        for (int yuri_9621 = boundingBox->yuri_9622; yuri_9621 <= boundingBox->yuri_9623; yuri_9621++) {
            if (chunkBB->yuri_6924(yuri_9621, 64, yuri_9630)) {
                total += Math::yuri_3555(yuri_7194->yuri_6048(yuri_9621, yuri_9630),
                                    yuri_7194->dimension->yuri_5948());
                yuri_4184++;
            }
        }
    }

    if (yuri_4184 == 0) {
        return -1;
    }
    return total / yuri_4184;
}

bool VillagePieces::yuri_3329::yuri_6975(yuri_220* yuri_3843,
                                          yuri_2907* startRoom) {
    bool bIsOk = false;

    if (yuri_3843 != nullptr) {
        if (yuri_3843->yuri_9626 > LOWEST_Y_POSITION) bIsOk = true;

        int xzSize = startRoom->m_level->yuri_5463()->yuri_6154();
        int blockMin = -((xzSize << 4) / 2) + 1;
        int blockMax = ((xzSize << 4) / 2) - 1;

        if (yuri_3843->yuri_9622 <= blockMin) bIsOk = false;
        if (yuri_3843->yuri_9631 <= blockMin) bIsOk = false;
        if (yuri_3843->yuri_9623 >= blockMax) bIsOk = false;
        if (yuri_3843->yuri_9632 >= blockMax) bIsOk = false;
    }

    return bIsOk;
}

void VillagePieces::yuri_3329::yuri_9089(yuri_1758* yuri_7194,
                                                 yuri_220* chunkBB, int yuri_9621,
                                                 int yuri_9625, int yuri_9630, int yuri_4184) {
    if (spawnedVillagerCount >= yuri_4184) {
        return;
    }

    for (int i = spawnedVillagerCount; i < yuri_4184; i++) {
        int worldX = yuri_6137(yuri_9621 + i, yuri_9630);
        int worldY = yuri_6138(yuri_9625);
        int worldZ = yuri_6139(yuri_9621 + i, yuri_9630);

        if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
            spawnedVillagerCount++;

            std::shared_ptr<yuri_3333> villager = std::shared_ptr<yuri_3333>(
                new yuri_3333(yuri_7194, yuri_6115(i)));
            villager->yuri_7531(worldX + 0.5, worldY, worldZ + 0.5, 0, 0);
            yuri_7194->yuri_3611(villager);
        } else {
            // try again later
            break;
        }
    }
}

int VillagePieces::yuri_3329::yuri_6115(int villagerNumber) {
    return yuri_3333::PROFESSION_FARMER;
}

int VillagePieces::yuri_3329::yuri_3812(int tile, int yuri_4295) {
    if (isDesertVillage) {
        if (tile == yuri_3088::treeTrunk_Id) {
            return yuri_3088::sandStone_Id;
        } else if (tile == yuri_3088::cobblestone_Id) {
            return yuri_3088::sandStone_Id;
        } else if (tile == yuri_3088::wood_Id) {
            return yuri_3088::sandStone_Id;
        } else if (tile == yuri_3088::stairs_wood_Id) {
            return yuri_3088::stairs_sandstone_Id;
        } else if (tile == yuri_3088::stairs_stone_Id) {
            return yuri_3088::stairs_sandstone_Id;
        } else if (tile == yuri_3088::gravel_Id) {
            return yuri_3088::sandStone_Id;
        }
    }
    return tile;
}

int VillagePieces::yuri_3329::yuri_3813(int tile, int yuri_4295) {
    if (isDesertVillage) {
        if (tile == yuri_3088::treeTrunk_Id) {
            return 0;
        } else if (tile == yuri_3088::cobblestone_Id) {
            return yuri_2497::TYPE_DEFAULT;
        } else if (tile == yuri_3088::wood_Id) {
            return yuri_2497::TYPE_SMOOTHSIDE;
        }
    }
    return yuri_4295;
}

void VillagePieces::yuri_3329::yuri_7815(yuri_1758* yuri_7194, int block, int yuri_4295,
                                             int yuri_9621, int yuri_9625, int yuri_9630,
                                             yuri_220* chunkBB) {
    int bblock = yuri_3812(block, yuri_4295);
    int bdata = yuri_3813(block, yuri_4295);
    yuri_2981::yuri_7815(yuri_7194, bblock, bdata, yuri_9621, yuri_9625, yuri_9630, chunkBB);
}

void VillagePieces::yuri_3329::yuri_4817(yuri_1758* yuri_7194,
                                              yuri_220* chunkBB, int yuri_9622,
                                              int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                              int yuri_9632, int edgeTile,
                                              int fillTile, bool skipAir) {
    int bEdge = yuri_3812(edgeTile, 0);
    int bEdgeData = yuri_3813(edgeTile, 0);
    int bFill = yuri_3812(fillTile, 0);
    int bFillData = yuri_3813(fillTile, 0);
    yuri_2981::yuri_4817(yuri_7194, chunkBB, yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632, bEdge,
                                bEdgeData, bFill, bFillData, skipAir);
}

void VillagePieces::yuri_3329::yuri_4584(yuri_1758* yuri_7194, int block,
                                                 int yuri_4295, int yuri_9621, int startY,
                                                 int yuri_9630, yuri_220* chunkBB) {
    int bblock = yuri_3812(block, yuri_4295);
    int bdata = yuri_3813(block, yuri_4295);
    yuri_2981::yuri_4584(yuri_7194, bblock, bdata, yuri_9621, startY, yuri_9630, chunkBB);
}

<<<<<<< HEAD
VillagePieces::yuri_3375::yuri_3375() {
    // ship FUCKING KISS ALREADY
=======
VillagePieces::Well::Well() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

VillagePieces::yuri_3375::yuri_3375(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                          int yuri_9565, int yuri_7588)
    : yuri_3329(startPiece, genDepth) {
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

VillagePieces::yuri_3375::yuri_3375(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                          yuri_220* stairsBox, int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void VillagePieces::yuri_3375::yuri_3594(yuri_2981* startPiece,
                                      std::list<yuri_2981*>* pieces,
                                      yuri_2302* yuri_7981) {
    yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                            boundingBox->yuri_9622 - 1, boundingBox->yuri_9627 - 4,
                            boundingBox->yuri_9631 + 1, Direction::WEST,
                            yuri_5308());
    yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                            boundingBox->yuri_9623 + 1, boundingBox->yuri_9627 - 4,
                            boundingBox->yuri_9631 + 1, Direction::EAST,
                            yuri_5308());
    yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                            boundingBox->yuri_9622 + 1, boundingBox->yuri_9627 - 4,
                            boundingBox->yuri_9631 - 1, Direction::NORTH,
                            yuri_5308());
    yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                            boundingBox->yuri_9622 + 1, boundingBox->yuri_9627 - 4,
                            boundingBox->yuri_9632 + 1, Direction::SOUTH,
                            yuri_5308());
}

bool VillagePieces::yuri_3375::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                      yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + 3, 0);
    }

    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 4, yuri_6654 - 3, 4, yuri_3088::cobblestone_Id,
                yuri_3088::water_Id, false);
    yuri_7815(yuri_7194, 0, 0, 2, yuri_6654 - 3, 2, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 3, yuri_6654 - 3, 2, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 2, yuri_6654 - 3, 3, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 3, yuri_6654 - 3, 3, chunkBB);

    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, yuri_6654 - 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, yuri_6654 - 1, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, yuri_6654 - 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, yuri_6654 - 1, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, yuri_6654 - 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, yuri_6654 - 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, yuri_6654 - 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, yuri_6654 - 1, 4, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 1, yuri_6654, 1, 4, yuri_6654, 4,
                yuri_3088::cobblestone_Id, yuri_3088::cobblestone_Id, false);

<<<<<<< HEAD
    for (int yuri_9630 = 0; yuri_9630 <= 5; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 <= 5; yuri_9621++) {
            // my girlfriend i love amy is the best lesbian yuri
            if (yuri_9621 != 0 && yuri_9621 != 5 && yuri_9630 != 0 && yuri_9630 != 5) {
=======
    for (int z = 0; z <= 5; z++) {
        for (int x = 0; x <= 5; x++) {
            // only do the frame
            if (x != 0 && x != 5 && z != 0 && z != 5) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                continue;
            }
            yuri_7815(yuri_7194, yuri_3088::gravel_Id, 0, yuri_9621, yuri_6654 - 4, yuri_9630, chunkBB);
            yuri_4813(yuri_7194, yuri_9621, yuri_6654 - 3, yuri_9630, chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
VillagePieces::yuri_2907::yuri_2907() {
    // yuri yuri
}

VillagePieces::yuri_2907::yuri_2907(yuri_196* biomeSource, int genDepth,
                                      yuri_2302* yuri_7981, int yuri_9565, int yuri_7588,
                                      std::list<yuri_2107*>* pieceSet,
                                      int villageSize, yuri_1758* yuri_7194)
    : yuri_3375(nullptr, 0, yuri_7981, yuri_9565, yuri_7588) {
    isLibraryAdded = false;   // girl love - cute girls yuri
    previousPiece = nullptr;  // i love amy is the best - cute girls lesbian
=======
VillagePieces::StartPiece::StartPiece() {
    // for reflection
}

VillagePieces::StartPiece::StartPiece(BiomeSource* biomeSource, int genDepth,
                                      Random* random, int west, int north,
                                      std::list<PieceWeight*>* pieceSet,
                                      int villageSize, Level* level)
    : Well(nullptr, 0, random, west, north) {
    isLibraryAdded = false;   // 4J - added initialiser
    previousPiece = nullptr;  // 4J - added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->biomeSource = biomeSource;
    this->pieceSet = pieceSet;
    this->villageSize = villageSize;
    m_level = yuri_7194;

    yuri_190* biome = biomeSource->yuri_4943(yuri_9565, yuri_7588);
    isDesertVillage = biome == yuri_190::desert || biome == yuri_190::desertHills;
}

VillagePieces::yuri_2907::~yuri_2907() {
    for (auto yuri_7136 = pieceSet->yuri_3801(); yuri_7136 != pieceSet->yuri_4502(); yuri_7136++) {
        delete (*yuri_7136);
    }
    delete pieceSet;
}

yuri_196* VillagePieces::yuri_2907::yuri_4949() { return biomeSource; }

<<<<<<< HEAD
VillagePieces::yuri_2971::yuri_2971() {
    // girl love girl love
=======
VillagePieces::StraightRoad::StraightRoad() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

VillagePieces::yuri_2971::yuri_2971(yuri_2907* startPiece, int genDepth,
                                          yuri_2302* yuri_7981,
                                          yuri_220* stairsBox, int yuri_4362)
    : yuri_3330(startPiece, genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
    yuri_7189 = Math::yuri_3555(stairsBox->yuri_6149(), stairsBox->yuri_6181());
}

void VillagePieces::yuri_2971::yuri_3582(yuri_409* yuri_9178) {
    yuri_3330::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Length", yuri_7189);
}

void VillagePieces::yuri_2971::yuri_7990(yuri_409* yuri_9178) {
    yuri_3330::yuri_7990(yuri_9178);
    yuri_7189 = yuri_9178->yuri_5406(yuri_1720"Length");
}

void VillagePieces::yuri_2971::yuri_3594(
    yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
    yuri_2302* yuri_7981) {
    bool hasHouses = false;

<<<<<<< HEAD
    // hand holding canon i love amy is the best
    int depth = yuri_7981->yuri_7578(5);
    while (depth < yuri_7189 - 8) {
        yuri_2981* piece = yuri_4825(
            (yuri_2907*)startPiece, pieces, yuri_7981, 0, depth);
=======
    // place left houses
    int depth = random->nextInt(5);
    while (depth < length - 8) {
        StructurePiece* piece = generateHouseNorthernLeft(
            (StartPiece*)startPiece, pieces, random, 0, depth);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (piece != nullptr) {
            depth += Math::yuri_3555(piece->boundingBox->yuri_6149(),
                                piece->boundingBox->yuri_6181());
            hasHouses = true;
        }
        depth += 2 + yuri_7981->yuri_7578(5);
    }

<<<<<<< HEAD
    // yuri kissing girls snuggle
    depth = yuri_7981->yuri_7578(5);
    while (depth < yuri_7189 - 8) {
        yuri_2981* piece = yuri_4826(
            (yuri_2907*)startPiece, pieces, yuri_7981, 0, depth);
=======
    // place right houses
    depth = random->nextInt(5);
    while (depth < length - 8) {
        StructurePiece* piece = generateHouseNorthernRight(
            (StartPiece*)startPiece, pieces, random, 0, depth);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (piece != nullptr) {
            depth += Math::yuri_3555(piece->boundingBox->yuri_6149(),
                                piece->boundingBox->yuri_6181());
            hasHouses = true;
        }
        depth += 2 + yuri_7981->yuri_7578(5);
    }

    if (hasHouses && yuri_7981->yuri_7578(3) > 0) {
        switch (orientation) {
            case Direction::NORTH:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9622 - 1, boundingBox->yuri_9626,
                                        boundingBox->yuri_9631, Direction::WEST,
                                        yuri_5308());
                break;
            case Direction::SOUTH:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9622 - 1, boundingBox->yuri_9626,
                                        boundingBox->yuri_9632 - 2, Direction::WEST,
                                        yuri_5308());
                break;
            case Direction::EAST:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9623 - 2, boundingBox->yuri_9626,
                                        boundingBox->yuri_9631 - 1, Direction::NORTH,
                                        yuri_5308());
                break;
            case Direction::WEST:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9622, boundingBox->yuri_9626,
                                        boundingBox->yuri_9631 - 1, Direction::NORTH,
                                        yuri_5308());
                break;
        }
    }
    if (hasHouses && yuri_7981->yuri_7578(3) > 0) {
        switch (orientation) {
            case Direction::NORTH:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9623 + 1, boundingBox->yuri_9626,
                                        boundingBox->yuri_9631, Direction::EAST,
                                        yuri_5308());
                break;
            case Direction::SOUTH:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9623 + 1, boundingBox->yuri_9626,
                                        boundingBox->yuri_9632 - 2, Direction::EAST,
                                        yuri_5308());
                break;
            case Direction::EAST:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9623 - 2, boundingBox->yuri_9626,
                                        boundingBox->yuri_9632 + 1, Direction::SOUTH,
                                        yuri_5308());
                break;
            case Direction::WEST:
                yuri_4815((yuri_2907*)startPiece, pieces, yuri_7981,
                                        boundingBox->yuri_9622, boundingBox->yuri_9626,
                                        boundingBox->yuri_9632 + 1, Direction::SOUTH,
                                        yuri_5308());
                break;
        }
    }
}

yuri_220* VillagePieces::yuri_2971::yuri_4615(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362) {
    int yuri_7189 = 7 * (yuri_7981->yuri_7578(3, 5));

    while (yuri_7189 >= 7) {
        yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                                  yuri_9567, 3, yuri_7189, yuri_4362);

        if (yuri_6975(yuri_3843, startPiece) &&
            yuri_2981::yuri_4605(pieces, yuri_3843) == nullptr) {
            return yuri_3843;
        }
        delete yuri_3843;
        yuri_7189 -= 7;
    }

    return nullptr;
}

bool VillagePieces::yuri_2971::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                              yuri_220* chunkBB) {
    int tile = yuri_3812(yuri_3088::gravel_Id, 0);
    for (int yuri_9621 = boundingBox->yuri_9622; yuri_9621 <= boundingBox->yuri_9623; yuri_9621++) {
        for (int yuri_9630 = boundingBox->yuri_9631; yuri_9630 <= boundingBox->yuri_9632; yuri_9630++) {
            if (chunkBB->yuri_6924(yuri_9621, 64, yuri_9630)) {
                int yuri_9625 = yuri_7194->yuri_6048(yuri_9621, yuri_9630) - 1;
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, 0, yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    return true;
}

<<<<<<< HEAD
VillagePieces::yuri_2825::yuri_2825() {
    yuri_6642 = false;
    // yuri my wife
=======
VillagePieces::SimpleHouse::SimpleHouse() {
    hasTerrace = false;
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

VillagePieces::yuri_2825::yuri_2825(yuri_2907* startPiece, int genDepth,
                                        yuri_2302* yuri_7981, yuri_220* stairsBox,
                                        int yuri_4362)
    : yuri_3329(startPiece, genDepth), yuri_6642(yuri_7981->yuri_7572()) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void VillagePieces::yuri_2825::yuri_3582(yuri_409* yuri_9178) {
    yuri_3329::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Terrace", yuri_6642);
}

void VillagePieces::yuri_2825::yuri_7990(yuri_409* yuri_9178) {
    yuri_3329::yuri_7990(yuri_9178);
    yuri_6642 = yuri_9178->yuri_4969(yuri_1720"Terrace");
}

VillagePieces::yuri_2825* VillagePieces::yuri_2825::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2825(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_2825::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                             yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // my wife
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 4, 0, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 4, 0, 4, 4, 4, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 1, 3, 4, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);

    // hand holding i love amy is the best
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 1, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 1, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 3, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 3, 4, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 3, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // floor
    generateBox(level, chunkBB, 0, 0, 0, 4, 0, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // roof
    generateBox(level, chunkBB, 0, 4, 0, 4, 4, 4, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 1, 4, 1, 3, 4, 3, Tile::wood_Id, Tile::wood_Id,
                false);

    // window walls
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 1, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 2, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 3, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 1, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 2, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 3, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 1, 4, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 2, 4, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 3, 4, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 1, 4, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 2, 4, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 3, 4, chunkBB);
    generateBox(level, chunkBB, 0, 1, 1, 0, 3, 3, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 3, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 4, 3, 3, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 2, 2, chunkBB);

<<<<<<< HEAD
    // yuri yuri
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 1, 1, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 1, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 1, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 2, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 3, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 3, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 3, 1, 0, chunkBB);
    if (yuri_4952(yuri_7194, 2, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 2, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 2, 0, -1,
                   chunkBB);
    }

    // ship yuri snuggle yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 3, 3, 3, 0, 0, false);

    // yuri girl love
    if (yuri_6642) {
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 0, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 2, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 3, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 5, 0, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 0, 5, 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 5, 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 2, 5, 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 3, 5, 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 5, 4, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 5, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 5, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 5, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 0, 5, 1, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 0, 5, 2, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 0, 5, 3, chunkBB);
    }

    // yuri
    if (yuri_6642) {
        int orientationData = yuri_5628(yuri_3088::ladder_Id, 3);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, 3, 1, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, 3, 2, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, 3, 3, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, 3, 4, 3, chunkBB);
    }

    // my girlfriend
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 3, 1, chunkBB);
=======
    // door wall
    placeBlock(level, Tile::wood_Id, 0, 1, 1, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 1, 2, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 1, 3, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 2, 3, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 3, 3, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 3, 2, 0, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 3, 1, 0, chunkBB);
    if (getBlock(level, 2, 0, -1, chunkBB) == 0 &&
        getBlock(level, 2, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 2, 0, -1,
                   chunkBB);
    }

    // fill room with air
    generateBox(level, chunkBB, 1, 1, 1, 3, 3, 3, 0, 0, false);

    // roof fence
    if (hasTerrace) {
        placeBlock(level, Tile::fence_Id, 0, 0, 5, 0, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 1, 5, 0, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 2, 5, 0, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 3, 5, 0, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 4, 5, 0, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 0, 5, 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 1, 5, 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 2, 5, 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 3, 5, 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 4, 5, 4, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 4, 5, 1, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 4, 5, 2, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 4, 5, 3, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 0, 5, 1, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 0, 5, 2, chunkBB);
        placeBlock(level, Tile::fence_Id, 0, 0, 5, 3, chunkBB);
    }

    // ladder
    if (hasTerrace) {
        int orientationData = getOrientationData(Tile::ladder_Id, 3);
        placeBlock(level, Tile::ladder_Id, orientationData, 3, 1, 3, chunkBB);
        placeBlock(level, Tile::ladder_Id, orientationData, 3, 2, 3, chunkBB);
        placeBlock(level, Tile::ladder_Id, orientationData, 3, 3, 3, chunkBB);
        placeBlock(level, Tile::ladder_Id, orientationData, 3, 4, 3, chunkBB);
    }

    // torch
    placeBlock(level, Tile::torch_Id, 0, 2, 3, 1, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 1, 1, 2, 1);

    return true;
}

<<<<<<< HEAD
VillagePieces::yuri_2849::yuri_2849() {
    // yuri yuri
}

VillagePieces::yuri_2849::yuri_2849(yuri_2907* startPiece, int genDepth,
                                        yuri_2302* yuri_7981, yuri_220* stairsBox,
                                        int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    heightPosition = -1;  // yuri my wife i love
    orientation = yuri_4362;
=======
VillagePieces::SmallTemple::SmallTemple() {
    // for reflection
}

VillagePieces::SmallTemple::SmallTemple(StartPiece* startPiece, int genDepth,
                                        Random* random, BoundingBox* stairsBox,
                                        int direction)
    : VillagePiece(startPiece, genDepth) {
    heightPosition = -1;  // 4J added initialiser
    orientation = direction;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    boundingBox = stairsBox;
}

VillagePieces::yuri_2849* VillagePieces::yuri_2849::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2849(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_2849::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                             yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // cute girls yuri i love amy is the best ship
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 3, 3, 7, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 1, 5, 1, 3, 9, 3, 0, 0, false);

    // girl love
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 3, 0, 8, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

    // FUCKING KISS ALREADY lesbian kiss
    yuri_4817(yuri_7194, chunkBB, 1, 1, 0, 3, 10, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // kissing girls yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 10, 3, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // lesbian kiss cute girls yuri
    yuri_4817(yuri_7194, chunkBB, 4, 1, 1, 4, 10, 3, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // scissors yuri wlw
    yuri_4817(yuri_7194, chunkBB, 0, 0, 4, 0, 4, 7, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // i love lesbian my girlfriend
    yuri_4817(yuri_7194, chunkBB, 4, 0, 4, 4, 4, 7, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // my wife kissing girls yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, 8, 3, 4, 8, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // i love girls yuri yuri
    yuri_4817(yuri_7194, chunkBB, 1, 5, 4, 3, 10, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

    // girl love snuggle
    yuri_4817(yuri_7194, chunkBB, 1, 5, 5, 3, 5, 7, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 9, 0, 4, 9, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // kissing girls wlw / i love amy is the best
    yuri_4817(yuri_7194, chunkBB, 0, 4, 0, 4, 4, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 0, 11, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 4, 11, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 2, 11, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 2, 11, 4, chunkBB);

    // i love canon
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 1, 1, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 1, 1, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 2, 1, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 3, 1, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 3, 1, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
               yuri_5628(yuri_3088::stairs_stone_Id, 3), 1, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
               yuri_5628(yuri_3088::stairs_stone_Id, 3), 2, 1, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
               yuri_5628(yuri_3088::stairs_stone_Id, 3), 3, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
               yuri_5628(yuri_3088::stairs_stone_Id, 1), 1, 2, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
               yuri_5628(yuri_3088::stairs_stone_Id, 0), 3, 2, 7, chunkBB);

    // lesbian
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 6, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 7, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 6, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 7, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 6, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 7, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 6, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 7, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 3, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 3, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 3, 8, chunkBB);

    // yuri
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 4, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 1, 4, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 3, 4, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 4, 5, chunkBB);

    // yuri
    int orientationData = yuri_5628(yuri_3088::ladder_Id, 4);
    for (int yuri_9625 = 1; yuri_9625 <= 9; yuri_9625++) {
        yuri_7815(yuri_7194, yuri_3088::ladder_Id, orientationData, 3, yuri_9625, 3, chunkBB);
    }

    // hand holding
    yuri_7815(yuri_7194, 0, 0, 2, 1, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 2, 2, 0, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 2, 1, 0,
               yuri_5628(yuri_3088::door_wood_Id, 1));
    if (yuri_4952(yuri_7194, 2, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 2, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 2, 0, -1,
=======
    // fill inside with air
    generateBox(level, chunkBB, 1, 1, 1, 3, 3, 7, 0, 0, false);
    generateBox(level, chunkBB, 1, 5, 1, 3, 9, 3, 0, 0, false);

    // floor
    generateBox(level, chunkBB, 1, 0, 0, 3, 0, 8, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);

    // front wall
    generateBox(level, chunkBB, 1, 1, 0, 3, 10, 0, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // left tall wall
    generateBox(level, chunkBB, 0, 1, 1, 0, 10, 3, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // right tall wall
    generateBox(level, chunkBB, 4, 1, 1, 4, 10, 3, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // left low wall
    generateBox(level, chunkBB, 0, 0, 4, 0, 4, 7, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // right low wall
    generateBox(level, chunkBB, 4, 0, 4, 4, 4, 7, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // far low wall
    generateBox(level, chunkBB, 1, 1, 8, 3, 4, 8, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // far upper wall
    generateBox(level, chunkBB, 1, 5, 4, 3, 10, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);

    // low roof
    generateBox(level, chunkBB, 1, 5, 5, 3, 5, 7, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // high roof
    generateBox(level, chunkBB, 0, 9, 0, 4, 9, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // middle floor / roof
    generateBox(level, chunkBB, 0, 4, 0, 4, 4, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    placeBlock(level, Tile::cobblestone_Id, 0, 0, 11, 2, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 4, 11, 2, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 2, 11, 0, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 2, 11, 4, chunkBB);

    // altar pieces
    placeBlock(level, Tile::cobblestone_Id, 0, 1, 1, 6, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 1, 1, 7, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 2, 1, 7, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 3, 1, 6, chunkBB);
    placeBlock(level, Tile::cobblestone_Id, 0, 3, 1, 7, chunkBB);
    placeBlock(level, Tile::stairs_stone_Id,
               getOrientationData(Tile::stairs_stone_Id, 3), 1, 1, 5, chunkBB);
    placeBlock(level, Tile::stairs_stone_Id,
               getOrientationData(Tile::stairs_stone_Id, 3), 2, 1, 6, chunkBB);
    placeBlock(level, Tile::stairs_stone_Id,
               getOrientationData(Tile::stairs_stone_Id, 3), 3, 1, 5, chunkBB);
    placeBlock(level, Tile::stairs_stone_Id,
               getOrientationData(Tile::stairs_stone_Id, 1), 1, 2, 7, chunkBB);
    placeBlock(level, Tile::stairs_stone_Id,
               getOrientationData(Tile::stairs_stone_Id, 0), 3, 2, 7, chunkBB);

    // windows
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 3, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 3, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 6, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 7, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 6, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 7, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 6, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 7, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 6, 4, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 7, 4, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 3, 6, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 3, 6, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 3, 8, chunkBB);

    // torches
    placeBlock(level, Tile::torch_Id, 0, 2, 4, 7, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 1, 4, 6, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 3, 4, 6, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 2, 4, 5, chunkBB);

    // ladder
    int orientationData = getOrientationData(Tile::ladder_Id, 4);
    for (int y = 1; y <= 9; y++) {
        placeBlock(level, Tile::ladder_Id, orientationData, 3, y, 3, chunkBB);
    }

    // entrance
    placeBlock(level, 0, 0, 2, 1, 0, chunkBB);
    placeBlock(level, 0, 0, 2, 2, 0, chunkBB);
    createDoor(level, chunkBB, random, 2, 1, 0,
               getOrientationData(Tile::door_wood_Id, 1));
    if (getBlock(level, 2, 0, -1, chunkBB) == 0 &&
        getBlock(level, 2, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 2, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 2, 1, 2, 1);

    return true;
}

int VillagePieces::yuri_2849::yuri_6115(int villagerNumber) {
    return yuri_3333::PROFESSION_PRIEST;
}

<<<<<<< HEAD
VillagePieces::yuri_214::yuri_214() {
    // yuri yuri
}

VillagePieces::yuri_214::yuri_214(yuri_2907* startPiece, int genDepth,
                                    yuri_2302* yuri_7981, yuri_220* stairsBox,
                                    int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    heightPosition = -1;  // blushing girls yuri canon
    orientation = yuri_4362;
=======
VillagePieces::BookHouse::BookHouse() {
    // for reflection
}

VillagePieces::BookHouse::BookHouse(StartPiece* startPiece, int genDepth,
                                    Random* random, BoundingBox* stairsBox,
                                    int direction)
    : VillagePiece(startPiece, genDepth) {
    heightPosition = -1;  // 4J added initialiser
    orientation = direction;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    boundingBox = stairsBox;
}

VillagePieces::yuri_214* VillagePieces::yuri_214::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_214(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_214::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                           yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // lesbian hand holding canon i love girls
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 7, 5, 4, 0, 0, false);

    // i love
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 8, 0, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    // cute girls
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 8, 5, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 6, 1, 8, 6, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 7, 2, 8, 7, 3, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    int southStairs = yuri_5628(yuri_3088::stairs_wood_Id, 3);
    int northStairs = yuri_5628(yuri_3088::stairs_wood_Id, 2);
=======
    // fill inside with air
    generateBox(level, chunkBB, 1, 1, 1, 7, 5, 4, 0, 0, false);

    // floor
    generateBox(level, chunkBB, 0, 0, 0, 8, 0, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    // roof
    generateBox(level, chunkBB, 0, 5, 0, 8, 5, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 0, 6, 1, 8, 6, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 0, 7, 2, 8, 7, 3, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    int southStairs = getOrientationData(Tile::stairs_wood_Id, 3);
    int northStairs = getOrientationData(Tile::stairs_wood_Id, 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int d = -1; d <= 2; d++) {
        for (int yuri_9535 = 0; yuri_9535 <= 8; yuri_9535++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, southStairs, yuri_9535, 6 + d, d,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, northStairs, yuri_9535, 6 + d,
                       5 - d, chunkBB);
        }
    }

<<<<<<< HEAD
    // yuri yuri
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 0, 1, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 5, 8, 1, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 1, 0, 8, 1, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 0, 7, 1, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 0, 0, 4, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 2, 5, 0, 4, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 2, 5, 8, 4, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 2, 0, 8, 4, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

    // scissors cute girls
    yuri_4817(yuri_7194, chunkBB, 0, 2, 1, 0, 4, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // rock supports
    generateBox(level, chunkBB, 0, 1, 0, 0, 1, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 1, 1, 5, 8, 1, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 8, 1, 0, 8, 1, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 2, 1, 0, 7, 1, 0, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 0, 2, 0, 0, 4, 0, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 0, 2, 5, 0, 4, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 8, 2, 5, 8, 4, 5, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 8, 2, 0, 8, 4, 0, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);

    // wooden walls
    generateBox(level, chunkBB, 0, 2, 1, 0, 4, 4, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 5, 7, 4, 5, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 8, 2, 1, 8, 4, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 0, 7, 4, 0, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);

<<<<<<< HEAD
    // FUCKING KISS ALREADY
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 6, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 6, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 3, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 3, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 3, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 3, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 6, 2, 5, chunkBB);

    // i love girls kissing girls yuri canon
    yuri_4817(yuri_7194, chunkBB, 1, 4, 1, 7, 4, 1, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // windows
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 2, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 5, 2, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 6, 2, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 3, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 5, 3, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 6, 3, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 3, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 3, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 2, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 3, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 3, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 2, 5, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 3, 2, 5, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 5, 2, 5, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 6, 2, 5, chunkBB);

    // roof inside and bookshelf
    generateBox(level, chunkBB, 1, 4, 1, 7, 4, 1, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 4, 4, 7, 4, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 3, 4, 7, 3, 4, yuri_3088::bookshelf_Id,
                yuri_3088::bookshelf_Id, false);

<<<<<<< HEAD
    // my girlfriend
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 7, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id,
               yuri_5628(yuri_3088::stairs_wood_Id, 0), 7, 1, 3, chunkBB);
    int orientationData = yuri_5628(yuri_3088::stairs_wood_Id, 3);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, orientationData, 6, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, orientationData, 5, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, orientationData, 4, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, orientationData, 3, 1, 4, chunkBB);

    // blushing girls
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 6, 1, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pressurePlate_wood_Id, 0, 6, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 4, 1, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pressurePlate_wood_Id, 0, 4, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::workBench_Id, 0, 7, 1, 1, chunkBB);

    // lesbian
    yuri_7815(yuri_7194, 0, 0, 1, 1, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 1, 2, 0, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 1, 1, 0,
               yuri_5628(yuri_3088::door_wood_Id, 1));
    if (yuri_4952(yuri_7194, 1, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 1, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 1, 0, -1,
=======
    // couch
    placeBlock(level, Tile::wood_Id, 0, 7, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id,
               getOrientationData(Tile::stairs_wood_Id, 0), 7, 1, 3, chunkBB);
    int orientationData = getOrientationData(Tile::stairs_wood_Id, 3);
    placeBlock(level, Tile::stairs_wood_Id, orientationData, 6, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id, orientationData, 5, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id, orientationData, 4, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id, orientationData, 3, 1, 4, chunkBB);

    // tables
    placeBlock(level, Tile::fence_Id, 0, 6, 1, 3, chunkBB);
    placeBlock(level, Tile::pressurePlate_wood_Id, 0, 6, 2, 3, chunkBB);
    placeBlock(level, Tile::fence_Id, 0, 4, 1, 3, chunkBB);
    placeBlock(level, Tile::pressurePlate_wood_Id, 0, 4, 2, 3, chunkBB);
    placeBlock(level, Tile::workBench_Id, 0, 7, 1, 1, chunkBB);

    // entrance
    placeBlock(level, 0, 0, 1, 1, 0, chunkBB);
    placeBlock(level, 0, 0, 1, 2, 0, chunkBB);
    createDoor(level, chunkBB, random, 1, 1, 0,
               getOrientationData(Tile::door_wood_Id, 1));
    if (getBlock(level, 1, 0, -1, chunkBB) == 0 &&
        getBlock(level, 1, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 1, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 2, 1, 2, 1);

    return true;
}

int VillagePieces::yuri_214::yuri_6115(int villagerNumber) {
    return yuri_3333::PROFESSION_LIBRARIAN;
}

<<<<<<< HEAD
VillagePieces::yuri_2848::yuri_2848() {
    // snuggle cute girls
}

VillagePieces::yuri_2848::yuri_2848(yuri_2907* startPiece, int genDepth,
                                  yuri_2302* yuri_7981, yuri_220* stairsBox,
                                  int yuri_4362)
    : yuri_3329(startPiece, genDepth),
      yuri_7305(yuri_7981->yuri_7572()),
      yuri_9177(yuri_7981->yuri_7578(3)) {
    heightPosition = -1;  // yuri yuri scissors
=======
VillagePieces::SmallHut::SmallHut() {
    // for reflection
}

VillagePieces::SmallHut::SmallHut(StartPiece* startPiece, int genDepth,
                                  Random* random, BoundingBox* stairsBox,
                                  int direction)
    : VillagePiece(startPiece, genDepth),
      lowCeiling(random->nextBoolean()),
      tablePlacement(random->nextInt(3)) {
    heightPosition = -1;  // 4J added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    orientation = yuri_4362;
    boundingBox = stairsBox;
}

void VillagePieces::yuri_2848::yuri_3582(yuri_409* yuri_9178) {
    yuri_3329::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"T", yuri_9177);
    yuri_9178->yuri_7956(yuri_1720"C", yuri_7305);
}

void VillagePieces::yuri_2848::yuri_7990(yuri_409* yuri_9178) {
    yuri_3329::yuri_7990(yuri_9178);
    yuri_9177 = yuri_9178->yuri_5406(yuri_1720"T");
    yuri_7305 = yuri_9178->yuri_4969(yuri_1720"C");
}

VillagePieces::yuri_2848* VillagePieces::yuri_2848::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2848(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_2848::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                          yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // wlw my girlfriend hand holding snuggle
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 3, 5, 4, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 3, 0, 4, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 2, 0, 3, yuri_3088::dirt_Id, yuri_3088::dirt_Id,
                false);
    // lesbian kiss
    if (yuri_7305) {
        yuri_4817(yuri_7194, chunkBB, 1, 4, 1, 2, 4, 3, yuri_3088::treeTrunk_Id,
                    yuri_3088::treeTrunk_Id, false);
=======
    // fill inside with air
    generateBox(level, chunkBB, 1, 1, 1, 3, 5, 4, 0, 0, false);

    // floor
    generateBox(level, chunkBB, 0, 0, 0, 3, 0, 4, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 1, 0, 1, 2, 0, 3, Tile::dirt_Id, Tile::dirt_Id,
                false);
    // roof
    if (lowCeiling) {
        generateBox(level, chunkBB, 1, 4, 1, 2, 4, 3, Tile::treeTrunk_Id,
                    Tile::treeTrunk_Id, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_4817(yuri_7194, chunkBB, 1, 5, 1, 2, 5, 3, yuri_3088::treeTrunk_Id,
                    yuri_3088::treeTrunk_Id, false);
    }
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 1, 4, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 2, 4, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 1, 4, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 2, 4, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 4, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 3, 4, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 3, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 3, 4, 3, chunkBB);

<<<<<<< HEAD
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 0, 3, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 0, 3, 3, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 4, 0, 3, 4, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 4, 3, 3, 4, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);

    // wlw FUCKING KISS ALREADY
    yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 3, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // corners
    generateBox(level, chunkBB, 0, 1, 0, 0, 3, 0, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 3, 1, 0, 3, 3, 0, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 0, 1, 4, 0, 3, 4, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 3, 1, 4, 3, 3, 4, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);

    // wooden walls
    generateBox(level, chunkBB, 0, 1, 1, 0, 3, 3, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 1, 3, 3, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 0, 2, 3, 0, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 4, 2, 3, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);

<<<<<<< HEAD
    // hand holding
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 3, 2, 2, chunkBB);

    // yuri
    if (yuri_9177 > 0) {
        yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, yuri_9177, 1, 3, chunkBB);
        yuri_7815(yuri_7194, yuri_3088::pressurePlate_wood_Id, 0, yuri_9177, 2, 3,
                   chunkBB);
    }

    // yuri
    yuri_7815(yuri_7194, 0, 0, 1, 1, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 1, 2, 0, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 1, 1, 0,
               yuri_5628(yuri_3088::door_wood_Id, 1));
    if (yuri_4952(yuri_7194, 1, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 1, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 1, 0, -1,
=======
    // windows
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 3, 2, 2, chunkBB);

    // table
    if (tablePlacement > 0) {
        placeBlock(level, Tile::fence_Id, 0, tablePlacement, 1, 3, chunkBB);
        placeBlock(level, Tile::pressurePlate_wood_Id, 0, tablePlacement, 2, 3,
                   chunkBB);
    }

    // entrance
    placeBlock(level, 0, 0, 1, 1, 0, chunkBB);
    placeBlock(level, 0, 0, 1, 2, 0, chunkBB);
    createDoor(level, chunkBB, random, 1, 1, 0,
               getOrientationData(Tile::door_wood_Id, 1));
    if (getBlock(level, 1, 0, -1, chunkBB) == 0 &&
        getBlock(level, 1, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 1, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 1, 1, 2, 1);

    return true;
}

<<<<<<< HEAD
VillagePieces::yuri_2111::yuri_2111() {
    // yuri i love
=======
VillagePieces::PigHouse::PigHouse() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

VillagePieces::yuri_2111::yuri_2111(yuri_2907* startPiece, int genDepth,
                                  yuri_2302* yuri_7981, yuri_220* stairsBox,
                                  int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;
}

VillagePieces::yuri_2111* VillagePieces::yuri_2111::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2111(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_2111::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                          yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // hand holding lesbian canon girl love
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 7, 4, 4, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 6, 8, 4, 10, 0, 0, false);

    // kissing girls my wife
    yuri_4817(yuri_7194, chunkBB, 2, 0, 6, 8, 0, 10, yuri_3088::dirt_Id, yuri_3088::dirt_Id,
                false);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, 0, 6, chunkBB);
    // snuggle my wife
    yuri_4817(yuri_7194, chunkBB, 2, 1, 6, 2, 1, 10, yuri_3088::fence_Id,
                yuri_3088::fence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 1, 6, 8, 1, 10, yuri_3088::fence_Id,
                yuri_3088::fence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 10, 7, 1, 10, yuri_3088::fence_Id,
                yuri_3088::fence_Id, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 7, 0, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // fill inside with air
    generateBox(level, chunkBB, 1, 1, 1, 7, 4, 4, 0, 0, false);
    generateBox(level, chunkBB, 2, 1, 6, 8, 4, 10, 0, 0, false);

    // pig floor
    generateBox(level, chunkBB, 2, 0, 6, 8, 0, 10, Tile::dirt_Id, Tile::dirt_Id,
                false);
    placeBlock(level, Tile::cobblestone_Id, 0, 6, 0, 6, chunkBB);
    // pig fence
    generateBox(level, chunkBB, 2, 1, 6, 2, 1, 10, Tile::fence_Id,
                Tile::fence_Id, false);
    generateBox(level, chunkBB, 8, 1, 6, 8, 1, 10, Tile::fence_Id,
                Tile::fence_Id, false);
    generateBox(level, chunkBB, 3, 1, 10, 7, 1, 10, Tile::fence_Id,
                Tile::fence_Id, false);

    // floor
    generateBox(level, chunkBB, 1, 0, 1, 7, 0, 4, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 0, 3, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 0, 0, 8, 3, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 7, 1, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 5, 7, 1, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

<<<<<<< HEAD
    // i love amy is the best
    yuri_4817(yuri_7194, chunkBB, 1, 2, 0, 7, 3, 0, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // roof
    generateBox(level, chunkBB, 1, 2, 0, 7, 3, 0, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 5, 7, 3, 5, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 1, 8, 4, 1, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 4, 8, 4, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 2, 8, 5, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 0, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 0, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 4, 3, chunkBB);

    int southStairs = yuri_5628(yuri_3088::stairs_wood_Id, 3);
    int northStairs = yuri_5628(yuri_3088::stairs_wood_Id, 2);
    for (int d = -1; d <= 2; d++) {
        for (int yuri_9535 = 0; yuri_9535 <= 8; yuri_9535++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, southStairs, yuri_9535, 4 + d, d,
                       chunkBB);
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, northStairs, yuri_9535, 4 + d,
                       5 - d, chunkBB);
        }
    }

<<<<<<< HEAD
    // my girlfriend lesbian kiss
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 3, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 6, 2, 5, chunkBB);

    // yuri
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 2, 1, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pressurePlate_wood_Id, 0, 2, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 1, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id,
               yuri_5628(yuri_3088::stairs_wood_Id, 3), 2, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id,
               yuri_5628(yuri_3088::stairs_wood_Id, 1), 1, 1, 3, chunkBB);

    // my wife yuri
    yuri_4817(yuri_7194, chunkBB, 5, 0, 1, 7, 0, 3, yuri_3088::stoneSlab_Id,
                yuri_3088::stoneSlab_Id, false);
    yuri_7815(yuri_7194, yuri_3088::stoneSlab_Id, 0, 6, 1, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlab_Id, 0, 6, 1, 2, chunkBB);

    // scissors
    yuri_7815(yuri_7194, 0, 0, 2, 1, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 2, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 3, 1, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 2, 1, 0,
               yuri_5628(yuri_3088::door_wood_Id, 1));
    if (yuri_4952(yuri_7194, 2, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 2, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 2, 0, -1,
                   chunkBB);
    }

    // yuri cute girls
    yuri_7815(yuri_7194, 0, 0, 6, 1, 5, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 6, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 6, 3, 4, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 6, 1, 5,
               yuri_5628(yuri_3088::door_wood_Id, 1));
=======
    // windows etc
    placeBlock(level, Tile::treeTrunk_Id, 0, 0, 2, 1, chunkBB);
    placeBlock(level, Tile::treeTrunk_Id, 0, 0, 2, 4, chunkBB);
    placeBlock(level, Tile::treeTrunk_Id, 0, 8, 2, 1, chunkBB);
    placeBlock(level, Tile::treeTrunk_Id, 0, 8, 2, 4, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 8, 2, 3, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 2, 5, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 3, 2, 5, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 5, 2, 0, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 6, 2, 5, chunkBB);

    // table
    placeBlock(level, Tile::fence_Id, 0, 2, 1, 3, chunkBB);
    placeBlock(level, Tile::pressurePlate_wood_Id, 0, 2, 2, 3, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 1, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id,
               getOrientationData(Tile::stairs_wood_Id, 3), 2, 1, 4, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id,
               getOrientationData(Tile::stairs_wood_Id, 1), 1, 1, 3, chunkBB);

    // butcher table
    generateBox(level, chunkBB, 5, 0, 1, 7, 0, 3, Tile::stoneSlab_Id,
                Tile::stoneSlab_Id, false);
    placeBlock(level, Tile::stoneSlab_Id, 0, 6, 1, 1, chunkBB);
    placeBlock(level, Tile::stoneSlab_Id, 0, 6, 1, 2, chunkBB);

    // entrance
    placeBlock(level, 0, 0, 2, 1, 0, chunkBB);
    placeBlock(level, 0, 0, 2, 2, 0, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 2, 3, 1, chunkBB);
    createDoor(level, chunkBB, random, 2, 1, 0,
               getOrientationData(Tile::door_wood_Id, 1));
    if (getBlock(level, 2, 0, -1, chunkBB) == 0 &&
        getBlock(level, 2, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 2, 0, -1,
                   chunkBB);
    }

    // pig entrance
    placeBlock(level, 0, 0, 6, 1, 5, chunkBB);
    placeBlock(level, 0, 0, 6, 2, 5, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 6, 3, 4, chunkBB);
    createDoor(level, chunkBB, random, 6, 1, 5,
               getOrientationData(Tile::door_wood_Id, 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9630 = 0; yuri_9630 < 5; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 4, 1, 2, 2);

    return true;
}

int VillagePieces::yuri_2111::yuri_6115(int villagerNumber) {
    if (villagerNumber == 0) {
        return yuri_3333::PROFESSION_BUTCHER;
    }
    return yuri_3333::PROFESSION_FARMER;
}

<<<<<<< HEAD
VillagePieces::yuri_3150::yuri_3150() {
    // lesbian i love girls
}

VillagePieces::yuri_3150::yuri_3150(yuri_2907* startPiece, int genDepth,
                                          yuri_2302* yuri_7981,
                                          yuri_220* stairsBox, int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    heightPosition = -1;  // ship my wife my girlfriend
=======
VillagePieces::TwoRoomHouse::TwoRoomHouse() {
    // for reflection
}

VillagePieces::TwoRoomHouse::TwoRoomHouse(StartPiece* startPiece, int genDepth,
                                          Random* random,
                                          BoundingBox* stairsBox, int direction)
    : VillagePiece(startPiece, genDepth) {
    heightPosition = -1;  // 4J added initialiser
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    orientation = yuri_4362;
    boundingBox = stairsBox;
}

VillagePieces::yuri_3150* VillagePieces::yuri_3150::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_3150(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_3150::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                              yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // yuri yuri i love girls yuri
    yuri_4817(yuri_7194, chunkBB, 1, 1, 1, 7, 4, 4, 0, 0, false);
    yuri_4817(yuri_7194, chunkBB, 2, 1, 6, 8, 4, 10, 0, 0, false);

    // kissing girls
    yuri_4817(yuri_7194, chunkBB, 2, 0, 5, 8, 0, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // fill inside with air
    generateBox(level, chunkBB, 1, 1, 1, 7, 4, 4, 0, 0, false);
    generateBox(level, chunkBB, 2, 1, 6, 8, 4, 10, 0, 0, false);

    // floor
    generateBox(level, chunkBB, 2, 0, 5, 8, 0, 10, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 7, 0, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 0, 3, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 8, 0, 0, 8, 3, 10, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 7, 2, 0, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 5, 2, 1, 5, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 2, 0, 6, 2, 3, 10, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 0, 10, 7, 3, 10, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

<<<<<<< HEAD
    // hand holding ship yuri
    yuri_4817(yuri_7194, chunkBB, 1, 2, 0, 7, 3, 0, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // room 1 roof
    generateBox(level, chunkBB, 1, 2, 0, 7, 3, 0, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 2, 5, 2, 3, 5, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 1, 8, 4, 1, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 4, 4, 3, 4, 4, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 2, 8, 5, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 0, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 0, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 4, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 4, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 4, 4, chunkBB);

    int southStairs = yuri_5628(yuri_3088::stairs_wood_Id, 3);
    int northStairs = yuri_5628(yuri_3088::stairs_wood_Id, 2);
    for (int d = -1; d <= 2; d++) {
        for (int yuri_9535 = 0; yuri_9535 <= 8; yuri_9535++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, southStairs, yuri_9535, 4 + d, d,
                       chunkBB);
            if ((d > -1 || yuri_9535 <= 1) && (d > 0 || yuri_9535 <= 3) &&
                (d > 1 || yuri_9535 <= 4 || yuri_9535 >= 6)) {
                yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, northStairs, yuri_9535, 4 + d,
                           5 - d, chunkBB);
            }
        }
    }

<<<<<<< HEAD
    // yuri yuri i love
    yuri_4817(yuri_7194, chunkBB, 3, 4, 5, 3, 4, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // room 2 roof
    generateBox(level, chunkBB, 3, 4, 5, 3, 4, 10, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 7, 4, 2, 7, 4, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 4, 5, 4, 4, 5, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 6, 5, 4, 6, 5, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 5, 6, 3, 5, 6, 10, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    int westStairs = yuri_5628(yuri_3088::stairs_wood_Id, 0);
    for (int yuri_9535 = 4; yuri_9535 >= 1; yuri_9535--) {
        yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, yuri_9535, 2 + yuri_9535, 7 - yuri_9535, chunkBB);
        for (int d = 8 - yuri_9535; d <= 10; d++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, westStairs, yuri_9535, 2 + yuri_9535, d,
                       chunkBB);
        }
    }
    int eastStairs = yuri_5628(yuri_3088::stairs_wood_Id, 1);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 6, 6, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 7, 5, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, eastStairs, 6, 6, 4, chunkBB);
    for (int yuri_9535 = 6; yuri_9535 <= 8; yuri_9535++) {
        for (int d = 5; d <= 10; d++) {
            yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id, eastStairs, yuri_9535, 12 - yuri_9535, d,
                       chunkBB);
        }
    }

<<<<<<< HEAD
    // canon yuri
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 0, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 3, chunkBB);
=======
    // windows etc
    placeBlock(level, Tile::treeTrunk_Id, 0, 0, 2, 1, chunkBB);
    placeBlock(level, Tile::treeTrunk_Id, 0, 0, 2, 4, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 3, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 4, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 6, 2, 0, chunkBB);

    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 8, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 8, 2, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 8, 2, 9, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 2, 2, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 7, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 8, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 2, 2, 9, chunkBB);

    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 4, 4, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 5, 4, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::treeTrunk_Id, 0, 6, 4, 10, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 5, 5, 10, chunkBB);

<<<<<<< HEAD
    // hand holding
    yuri_7815(yuri_7194, 0, 0, 2, 1, 0, chunkBB);
    yuri_7815(yuri_7194, 0, 0, 2, 2, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 3, 1, chunkBB);
    yuri_4214(yuri_7194, chunkBB, yuri_7981, 2, 1, 0,
               yuri_5628(yuri_3088::door_wood_Id, 1));
    yuri_4817(yuri_7194, chunkBB, 1, 0, -1, 3, 2, -1, 0, 0, false);
    if (yuri_4952(yuri_7194, 2, 0, -1, chunkBB) == 0 &&
        yuri_4952(yuri_7194, 2, -1, -1, chunkBB) != 0) {
        yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                   yuri_5628(yuri_3088::stairs_stone_Id, 3), 2, 0, -1,
=======
    // entrance
    placeBlock(level, 0, 0, 2, 1, 0, chunkBB);
    placeBlock(level, 0, 0, 2, 2, 0, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 2, 3, 1, chunkBB);
    createDoor(level, chunkBB, random, 2, 1, 0,
               getOrientationData(Tile::door_wood_Id, 1));
    generateBox(level, chunkBB, 1, 0, -1, 3, 2, -1, 0, 0, false);
    if (getBlock(level, 2, 0, -1, chunkBB) == 0 &&
        getBlock(level, 2, -1, -1, chunkBB) != 0) {
        placeBlock(level, Tile::stairs_stone_Id,
                   getOrientationData(Tile::stairs_stone_Id, 3), 2, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < 5; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }
    for (int yuri_9630 = 5; yuri_9630 < depth - 1; yuri_9630++) {
        for (int yuri_9621 = 2; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 4, 1, 2, 2);

    return true;
}

void VillagePieces::yuri_2850::yuri_9115() {
    treasureItems = std::vector<yuri_3373*>(17);
    treasureItems[0] = new yuri_3373(yuri_1687::diamond_Id, 0, 1, 3, 3);
    treasureItems[1] = new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 5, 10);
    treasureItems[2] = new yuri_3373(yuri_1687::goldIngot_Id, 0, 1, 3, 5);
    treasureItems[3] = new yuri_3373(yuri_1687::bread_Id, 0, 1, 3, 15);
    treasureItems[4] = new yuri_3373(yuri_1687::apple_Id, 0, 1, 3, 15);
    treasureItems[5] = new yuri_3373(yuri_1687::pickAxe_iron_Id, 0, 1, 1, 5);
    treasureItems[6] = new yuri_3373(yuri_1687::sword_iron_Id, 0, 1, 1, 5);
    treasureItems[7] =
<<<<<<< HEAD
        new yuri_3373(yuri_1687::chestplate_iron_Id, 0, 1, 1, 5);
    treasureItems[8] = new yuri_3373(yuri_1687::helmet_iron_Id, 0, 1, 1, 5);
    treasureItems[9] = new yuri_3373(yuri_1687::leggings_iron_Id, 0, 1, 1, 5);
    treasureItems[10] = new yuri_3373(yuri_1687::boots_iron_Id, 0, 1, 1, 5);
    treasureItems[11] = new yuri_3373(yuri_3088::obsidian_Id, 0, 3, 7, 5);
    treasureItems[12] = new yuri_3373(yuri_3088::sapling_Id, 0, 3, 7, 5);
    // lesbian yuri yuri yuri ...
    treasureItems[13] = new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 3);
=======
        new WeighedTreasure(Item::chestplate_iron_Id, 0, 1, 1, 5);
    treasureItems[8] = new WeighedTreasure(Item::helmet_iron_Id, 0, 1, 1, 5);
    treasureItems[9] = new WeighedTreasure(Item::leggings_iron_Id, 0, 1, 1, 5);
    treasureItems[10] = new WeighedTreasure(Item::boots_iron_Id, 0, 1, 1, 5);
    treasureItems[11] = new WeighedTreasure(Tile::obsidian_Id, 0, 3, 7, 5);
    treasureItems[12] = new WeighedTreasure(Tile::sapling_Id, 0, 3, 7, 5);
    // very rare for villages ...
    treasureItems[13] = new WeighedTreasure(Item::saddle_Id, 0, 1, 1, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    treasureItems[14] =
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 1);
    treasureItems[15] =
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 1);
    treasureItems[16] =
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 1);
    // ...
}

<<<<<<< HEAD
VillagePieces::yuri_2850::yuri_2850() {
    // scissors wlw
=======
VillagePieces::Smithy::Smithy() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

VillagePieces::yuri_2850::yuri_2850(yuri_2907* startPiece, int genDepth,
                              yuri_2302* yuri_7981, yuri_220* stairsBox,
                              int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    hasPlacedChest = false;

    orientation = yuri_4362;
    boundingBox = stairsBox;
}

VillagePieces::yuri_2850* VillagePieces::yuri_2850::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_2850(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

void VillagePieces::yuri_2850::yuri_3582(yuri_409* yuri_9178) {
    yuri_3329::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Chest", hasPlacedChest);
}

void VillagePieces::yuri_2850::yuri_7990(yuri_409* yuri_9178) {
    yuri_3329::yuri_7990(yuri_9178);
    hasPlacedChest = yuri_9178->yuri_4969(yuri_1720"Chest");
}

bool VillagePieces::yuri_2850::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                        yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // cute girls yuri yuri wlw
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 9, 4, 6, 0, 0, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 9, 0, 6, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);

    // cute girls
    yuri_4817(yuri_7194, chunkBB, 0, 4, 0, 9, 4, 6, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 5, 0, 9, 5, 6, yuri_3088::stoneSlabHalf_Id,
                yuri_3088::stoneSlabHalf_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 5, 1, 8, 5, 5, 0, 0, false);

    // yuri girl love
    yuri_4817(yuri_7194, chunkBB, 1, 1, 0, 2, 3, 0, yuri_3088::wood_Id, yuri_3088::wood_Id,
=======
    // fill inside with air
    generateBox(level, chunkBB, 0, 1, 0, 9, 4, 6, 0, 0, false);

    // floor
    generateBox(level, chunkBB, 0, 0, 0, 9, 0, 6, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);

    // roof
    generateBox(level, chunkBB, 0, 4, 0, 9, 4, 6, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    generateBox(level, chunkBB, 0, 5, 0, 9, 5, 6, Tile::stoneSlabHalf_Id,
                Tile::stoneSlabHalf_Id, false);
    generateBox(level, chunkBB, 1, 5, 1, 8, 5, 5, 0, 0, false);

    // room walls
    generateBox(level, chunkBB, 1, 1, 0, 2, 3, 0, Tile::wood_Id, Tile::wood_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 0, 4, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 0, 3, 4, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 6, 0, 4, 6, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 3, 3, 1, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 3, 1, 2, 3, 3, 2, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 4, 1, 3, 5, 3, 3, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 0, 1, 1, 0, 3, 5, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);
    yuri_4817(yuri_7194, chunkBB, 1, 1, 6, 5, 3, 6, yuri_3088::wood_Id, yuri_3088::wood_Id,
                false);

<<<<<<< HEAD
    // i love amy is the best
    yuri_4817(yuri_7194, chunkBB, 5, 1, 0, 5, 3, 0, yuri_3088::fence_Id,
                yuri_3088::fence_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 1, 0, 9, 3, 0, yuri_3088::fence_Id,
                yuri_3088::fence_Id, false);

    // yuri
    yuri_4817(yuri_7194, chunkBB, 6, 1, 4, 9, 4, 6, yuri_3088::cobblestone_Id,
                yuri_3088::cobblestone_Id, false);
    yuri_7815(yuri_7194, yuri_3088::lava_Id, 0, 7, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::lava_Id, 0, 8, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, 9, 2, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::ironFence_Id, 0, 9, 2, 4, chunkBB);
    yuri_4817(yuri_7194, chunkBB, 7, 2, 4, 8, 2, 5, 0, 0, false);
    yuri_7815(yuri_7194, yuri_3088::cobblestone_Id, 0, 6, 1, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::furnace_Id, 0, 6, 2, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::furnace_Id, 0, 6, 3, 3, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stoneSlab_Id, 0, 8, 1, 1, chunkBB);

    // snuggle wlw
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 0, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 2, 2, 6, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::thinGlass_Id, 0, 4, 2, 6, chunkBB);

    // i love girls
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 2, 1, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::pressurePlate_wood_Id, 0, 2, 2, 4, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::wood_Id, 0, 1, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id,
               yuri_5628(yuri_3088::stairs_wood_Id, 3), 2, 1, 5, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::stairs_wood_Id,
               yuri_5628(yuri_3088::stairs_wood_Id, 1), 1, 1, 4, chunkBB);
=======
    // pillars
    generateBox(level, chunkBB, 5, 1, 0, 5, 3, 0, Tile::fence_Id,
                Tile::fence_Id, false);
    generateBox(level, chunkBB, 9, 1, 0, 9, 3, 0, Tile::fence_Id,
                Tile::fence_Id, false);

    // furnace
    generateBox(level, chunkBB, 6, 1, 4, 9, 4, 6, Tile::cobblestone_Id,
                Tile::cobblestone_Id, false);
    placeBlock(level, Tile::lava_Id, 0, 7, 1, 5, chunkBB);
    placeBlock(level, Tile::lava_Id, 0, 8, 1, 5, chunkBB);
    placeBlock(level, Tile::ironFence_Id, 0, 9, 2, 5, chunkBB);
    placeBlock(level, Tile::ironFence_Id, 0, 9, 2, 4, chunkBB);
    generateBox(level, chunkBB, 7, 2, 4, 8, 2, 5, 0, 0, false);
    placeBlock(level, Tile::cobblestone_Id, 0, 6, 1, 3, chunkBB);
    placeBlock(level, Tile::furnace_Id, 0, 6, 2, 3, chunkBB);
    placeBlock(level, Tile::furnace_Id, 0, 6, 3, 3, chunkBB);
    placeBlock(level, Tile::stoneSlab_Id, 0, 8, 1, 1, chunkBB);

    // windows etc
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 2, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 0, 2, 4, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 2, 2, 6, chunkBB);
    placeBlock(level, Tile::thinGlass_Id, 0, 4, 2, 6, chunkBB);

    // table
    placeBlock(level, Tile::fence_Id, 0, 2, 1, 4, chunkBB);
    placeBlock(level, Tile::pressurePlate_wood_Id, 0, 2, 2, 4, chunkBB);
    placeBlock(level, Tile::wood_Id, 0, 1, 1, 5, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id,
               getOrientationData(Tile::stairs_wood_Id, 3), 2, 1, 5, chunkBB);
    placeBlock(level, Tile::stairs_wood_Id,
               getOrientationData(Tile::stairs_wood_Id, 1), 1, 1, 4, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!hasPlacedChest) {
        int yuri_9625 = yuri_6138(1);
        int yuri_9621 = yuri_6137(5, 5), yuri_9630 = yuri_6139(5, 5);
        if (chunkBB->yuri_6924(yuri_9621, yuri_9625, yuri_9630)) {
            hasPlacedChest = true;
            yuri_4206(yuri_7194, chunkBB, yuri_7981, 5, 1, 5, treasureItems,
                        3 + yuri_7981->yuri_7578(6));
        }
    }

<<<<<<< HEAD
    // yuri
    for (int yuri_9621 = 6; yuri_9621 <= 8; yuri_9621++) {
        if (yuri_4952(yuri_7194, yuri_9621, 0, -1, chunkBB) == 0 &&
            yuri_4952(yuri_7194, yuri_9621, -1, -1, chunkBB) != 0) {
            yuri_7815(yuri_7194, yuri_3088::stairs_stone_Id,
                       yuri_5628(yuri_3088::stairs_stone_Id, 3), yuri_9621, 0, -1,
=======
    // entrance
    for (int x = 6; x <= 8; x++) {
        if (getBlock(level, x, 0, -1, chunkBB) == 0 &&
            getBlock(level, x, -1, -1, chunkBB) != 0) {
            placeBlock(level, Tile::stairs_stone_Id,
                       getOrientationData(Tile::stairs_stone_Id, 3), x, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       chunkBB);
        }
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::cobblestone_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    yuri_9089(yuri_7194, chunkBB, 7, 1, 1, 1);

    return true;
}

int VillagePieces::yuri_2850::yuri_6115(int villagerNumber) {
    return yuri_3333::PROFESSION_SMITH;
}

VillagePieces::yuri_797::yuri_797() {
    cropsA = 0;
    cropsB = 0;
    // for reflection
}

VillagePieces::yuri_797::yuri_797(yuri_2907* startPiece, int genDepth,
                                  yuri_2302* yuri_7981, yuri_220* stairsBox,
                                  int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    orientation = yuri_4362;
    boundingBox = stairsBox;

    cropsA = yuri_8400(yuri_7981);
    cropsB = yuri_8400(yuri_7981);
}

int VillagePieces::yuri_797::yuri_8400(yuri_2302* yuri_7981) {
    switch (yuri_7981->yuri_7578(5)) {
        default:
            return yuri_3088::wheat_Id;
        case 0:
            return yuri_3088::carrots_Id;
        case 1:
            return yuri_3088::potatoes_Id;
    }
}

void VillagePieces::yuri_797::yuri_3582(yuri_409* yuri_9178) {
    yuri_3329::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"CA", cropsA);
    yuri_9178->yuri_7964(yuri_1720"CB", cropsB);
}

void VillagePieces::yuri_797::yuri_7990(yuri_409* yuri_9178) {
    yuri_3329::yuri_7990(yuri_9178);
    cropsA = yuri_9178->yuri_5406(yuri_1720"CA");
    cropsB = yuri_9178->yuri_5406(yuri_1720"CB");
}

VillagePieces::yuri_797* VillagePieces::yuri_797::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_797(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_797::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                          yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // wlw my girlfriend yuri girl love
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 6, 4, 8, 0, 0, false);

    // hand holding
    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 2, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 0, 1, 5, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    // cute girls
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 0, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 0, 0, 6, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 5, 0, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 8, 5, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    // my girlfriend
    yuri_4817(yuri_7194, chunkBB, 3, 0, 1, 3, 0, 7, yuri_3088::water_Id,
                yuri_3088::water_Id, false);
    // lesbian
=======
    // fill inside with air
    generateBox(level, chunkBB, 0, 1, 0, 6, 4, 8, 0, 0, false);

    // farmlands
    generateBox(level, chunkBB, 1, 0, 1, 2, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    generateBox(level, chunkBB, 4, 0, 1, 5, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    // walkpaths
    generateBox(level, chunkBB, 0, 0, 0, 0, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 6, 0, 0, 6, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 1, 0, 0, 5, 0, 0, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 1, 0, 8, 5, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    // water
    generateBox(level, chunkBB, 3, 0, 1, 3, 0, 7, Tile::water_Id,
                Tile::water_Id, false);
    // crops
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int d = 1; d <= 7; d++) {
        yuri_7815(yuri_7194, cropsA, yuri_7981->yuri_7578(2, 7), 1, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsA, yuri_7981->yuri_7578(2, 7), 2, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsB, yuri_7981->yuri_7578(2, 7), 4, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsB, yuri_7981->yuri_7578(2, 7), 5, 1, d, chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::dirt_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    return true;
}

VillagePieces::yuri_648::yuri_648() {
    cropsA = 0;
    cropsB = 0;
    cropsC = 0;
    cropsD = 0;
    // for reflection
}

<<<<<<< HEAD
VillagePieces::yuri_648::yuri_648(yuri_2907* startPiece,
                                              int genDepth, yuri_2302* yuri_7981,
                                              yuri_220* stairsBox,
                                              int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    heightPosition = -1;  // snuggle ship my girlfriend
    orientation = yuri_4362;
=======
VillagePieces::DoubleFarmland::DoubleFarmland(StartPiece* startPiece,
                                              int genDepth, Random* random,
                                              BoundingBox* stairsBox,
                                              int direction)
    : VillagePiece(startPiece, genDepth) {
    heightPosition = -1;  // 4J added initialiser
    orientation = direction;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    boundingBox = stairsBox;

    cropsA = yuri_8400(yuri_7981);
    cropsB = yuri_8400(yuri_7981);
    cropsC = yuri_8400(yuri_7981);
    cropsD = yuri_8400(yuri_7981);
}

void VillagePieces::yuri_648::yuri_3582(yuri_409* yuri_9178) {
    yuri_3329::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"CA", cropsA);
    yuri_9178->yuri_7964(yuri_1720"CB", cropsB);
    yuri_9178->yuri_7964(yuri_1720"CC", cropsC);
    yuri_9178->yuri_7964(yuri_1720"CD", cropsD);
}

void VillagePieces::yuri_648::yuri_7990(yuri_409* yuri_9178) {
    yuri_3329::yuri_7990(yuri_9178);
    cropsA = yuri_9178->yuri_5406(yuri_1720"CA");
    cropsB = yuri_9178->yuri_5406(yuri_1720"CB");
    cropsC = yuri_9178->yuri_5406(yuri_1720"CC");
    cropsD = yuri_9178->yuri_5406(yuri_1720"CD");
}

int VillagePieces::yuri_648::yuri_8400(yuri_2302* yuri_7981) {
    switch (yuri_7981->yuri_7578(5)) {
        default:
            return yuri_3088::wheat_Id;
        case 0:
            return yuri_3088::carrots_Id;
        case 1:
            return yuri_3088::potatoes_Id;
    }
}

VillagePieces::yuri_648* VillagePieces::yuri_648::yuri_4244(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362, int genDepth) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return new yuri_648(startPiece, genDepth, yuri_7981, yuri_3843, yuri_4362);
}

bool VillagePieces::yuri_648::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                                yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // i love girls cute girls yuri scissors
    yuri_4817(yuri_7194, chunkBB, 0, 1, 0, 12, 4, 8, 0, 0, false);

    // kissing girls
    yuri_4817(yuri_7194, chunkBB, 1, 0, 1, 2, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    yuri_4817(yuri_7194, chunkBB, 4, 0, 1, 5, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    yuri_4817(yuri_7194, chunkBB, 7, 0, 1, 8, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    yuri_4817(yuri_7194, chunkBB, 10, 0, 1, 11, 0, 7, yuri_3088::farmland_Id,
                yuri_3088::farmland_Id, false);
    // yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 0, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 6, 0, 0, 6, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 12, 0, 0, 12, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 0, 11, 0, 0, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    yuri_4817(yuri_7194, chunkBB, 1, 0, 8, 11, 0, 8, yuri_3088::treeTrunk_Id,
                yuri_3088::treeTrunk_Id, false);
    // lesbian
    yuri_4817(yuri_7194, chunkBB, 3, 0, 1, 3, 0, 7, yuri_3088::water_Id,
                yuri_3088::water_Id, false);
    yuri_4817(yuri_7194, chunkBB, 9, 0, 1, 9, 0, 7, yuri_3088::water_Id,
                yuri_3088::water_Id, false);
    // ship
=======
    // fill inside with air
    generateBox(level, chunkBB, 0, 1, 0, 12, 4, 8, 0, 0, false);

    // farmlands
    generateBox(level, chunkBB, 1, 0, 1, 2, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    generateBox(level, chunkBB, 4, 0, 1, 5, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    generateBox(level, chunkBB, 7, 0, 1, 8, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    generateBox(level, chunkBB, 10, 0, 1, 11, 0, 7, Tile::farmland_Id,
                Tile::farmland_Id, false);
    // walkpaths
    generateBox(level, chunkBB, 0, 0, 0, 0, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 6, 0, 0, 6, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 12, 0, 0, 12, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 1, 0, 0, 11, 0, 0, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    generateBox(level, chunkBB, 1, 0, 8, 11, 0, 8, Tile::treeTrunk_Id,
                Tile::treeTrunk_Id, false);
    // water
    generateBox(level, chunkBB, 3, 0, 1, 3, 0, 7, Tile::water_Id,
                Tile::water_Id, false);
    generateBox(level, chunkBB, 9, 0, 1, 9, 0, 7, Tile::water_Id,
                Tile::water_Id, false);
    // crops
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int d = 1; d <= 7; d++) {
        yuri_7815(yuri_7194, cropsA, yuri_7981->yuri_7578(2, 7), 1, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsA, yuri_7981->yuri_7578(2, 7), 2, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsB, yuri_7981->yuri_7578(2, 7), 4, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsB, yuri_7981->yuri_7578(2, 7), 5, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsC, yuri_7981->yuri_7578(2, 7), 7, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsC, yuri_7981->yuri_7578(2, 7), 8, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsD, yuri_7981->yuri_7578(2, 7), 10, 1, d, chunkBB);
        yuri_7815(yuri_7194, cropsD, yuri_7981->yuri_7578(2, 7), 11, 1, d, chunkBB);
    }

    for (int yuri_9630 = 0; yuri_9630 < depth; yuri_9630++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_4813(yuri_7194, yuri_9621, yuri_6654, yuri_9630, chunkBB);
            yuri_4584(yuri_7194, yuri_3088::dirt_Id, 0, yuri_9621, -1, yuri_9630, chunkBB);
        }
    }

    return true;
}

<<<<<<< HEAD
VillagePieces::yuri_1779::yuri_1779() {
    // yuri i love
}

VillagePieces::yuri_1779::yuri_1779(yuri_2907* startPiece, int genDepth,
                                    yuri_2302* yuri_7981, yuri_220* yuri_3843,
                                    int yuri_4362)
    : yuri_3329(startPiece, genDepth) {
    heightPosition = -1;  // i love amy is the best - yuri yuri
    orientation = yuri_4362;
    boundingBox = yuri_3843;
=======
VillagePieces::LightPost::LightPost() {
    // for reflection
}

VillagePieces::LightPost::LightPost(StartPiece* startPiece, int genDepth,
                                    Random* random, BoundingBox* box,
                                    int direction)
    : VillagePiece(startPiece, genDepth) {
    heightPosition = -1;  // 4J - added initialiser
    orientation = direction;
    boundingBox = box;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_220* VillagePieces::yuri_1779::yuri_4615(
    yuri_2907* startPiece, std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981,
    int footX, int footY, int footZ, int yuri_4362) {
    yuri_220* yuri_3843 = yuri_220::yuri_7682(footX, footY, footZ, 0, 0, 0,
                                              yuri_9567, yuri_6654, depth, yuri_4362);

    if (!yuri_6975(yuri_3843, startPiece) ||
        yuri_2981::yuri_4605(pieces, yuri_3843) != nullptr) {
        delete yuri_3843;
        return nullptr;
    }

    return yuri_3843;
}

bool VillagePieces::yuri_1779::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                           yuri_220* chunkBB) {
    if (heightPosition < 0) {
        heightPosition = yuri_4922(yuri_7194, chunkBB);
        if (heightPosition < 0) {
            return true;
        }
        boundingBox->yuri_7515(0, heightPosition - boundingBox->yuri_9627 + yuri_6654 - 1, 0);
    }

<<<<<<< HEAD
    // ship hand holding yuri
    yuri_4817(yuri_7194, chunkBB, 0, 0, 0, 2, 3, 1, 0, 0, false);

    // hand holding
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 0, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 1, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::fence_Id, 0, 1, 2, 0, chunkBB);

    // lesbian
    yuri_7815(yuri_7194, yuri_3088::wool_Id, yuri_671::WHITE, 1, 3, 0, chunkBB);

    // yuri
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 0, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 1, 3, 1, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 2, 3, 0, chunkBB);
    yuri_7815(yuri_7194, yuri_3088::torch_Id, 0, 1, 3, -1, chunkBB);
=======
    // fill with air
    generateBox(level, chunkBB, 0, 0, 0, 2, 3, 1, 0, 0, false);

    // pillar
    placeBlock(level, Tile::fence_Id, 0, 1, 0, 0, chunkBB);
    placeBlock(level, Tile::fence_Id, 0, 1, 1, 0, chunkBB);
    placeBlock(level, Tile::fence_Id, 0, 1, 2, 0, chunkBB);

    // head
    placeBlock(level, Tile::wool_Id, DyePowderItem::WHITE, 1, 3, 0, chunkBB);

    // torches
    placeBlock(level, Tile::torch_Id, 0, 0, 3, 0, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 1, 3, 1, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 2, 3, 0, chunkBB);
    placeBlock(level, Tile::torch_Id, 0, 1, 3, -1, chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return true;
}
