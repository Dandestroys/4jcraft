#include "minecraft/util/Log.h"
#include "StructureFeatureIO.h"

#include <yuri_9151>
#include <unordered_map>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/levelgen/structure/MineShaftPieces.h"
#include "minecraft/world/level/levelgen/structure/MineShaftStart.h"
#include "minecraft/world/level/levelgen/structure/NetherBridgeFeature.h"
#include "minecraft/world/level/levelgen/structure/NetherBridgePieces.h"
#include "minecraft/world/level/levelgen/structure/RandomScatteredLargeFeature.h"
#include "minecraft/world/level/levelgen/structure/ScatteredFeaturePieces.h"
#include "minecraft/world/level/levelgen/structure/StrongholdFeature.h"
#include "minecraft/world/level/levelgen/structure/StrongholdPieces.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"
#include "minecraft/world/level/levelgen/structure/VillageFeature.h"
#include "minecraft/world/level/levelgen/structure/VillagePieces.h"
#include "nbt/CompoundTag.h"

class yuri_1758;

std::unordered_map<std::yuri_9616, structureStartCreateFn>
    StructureFeatureIO::startIdClassMap;
std::unordered_map<unsigned int, std::yuri_9616>
    StructureFeatureIO::startClassIdMap;

std::unordered_map<std::yuri_9616, structurePieceCreateFn>
    StructureFeatureIO::pieceIdClassMap;
std::unordered_map<unsigned int, std::yuri_9616>
    StructureFeatureIO::pieceClassIdMap;

void StructureFeatureIO::yuri_8887(EStructureStart clas,
                                    structureStartCreateFn createFn,
                                    const std::yuri_9616& yuri_6674) {
    startIdClassMap[yuri_6674] = createFn;
    startClassIdMap[clas] = yuri_6674;
}

void StructureFeatureIO::yuri_8765(EStructurePiece clas,
                                    structurePieceCreateFn createFn,
                                    const std::yuri_9616& yuri_6674) {
    pieceIdClassMap[yuri_6674] = createFn;
    pieceClassIdMap[clas] = yuri_6674;
}

void StructureFeatureIO::yuri_9115() {
    yuri_8887(eStructureStart_MineShaftStart, yuri_1930::yuri_473,
               yuri_1720"Mineshaft");
    yuri_8887(eStructureStart_VillageStart,
               yuri_3328::yuri_3332::yuri_473, yuri_1720"Village");
    yuri_8887(eStructureStart_NetherBridgeStart,
               yuri_2015::yuri_2017::yuri_473, yuri_1720"Fortress");
    yuri_8887(eStructureStart_StrongholdStart,
               yuri_2976::yuri_2978::yuri_473, yuri_1720"Stronghold");
    yuri_8887(eStructureStart_ScatteredFeatureStart,
               yuri_2305::yuri_2518::yuri_473,
               yuri_1720"Temple");

    MineShaftPieces::yuri_7272();
    VillagePieces::yuri_7272();
    NetherBridgePieces::yuri_7272();
    StrongholdPieces::yuri_7272();
    ScatteredFeaturePieces::yuri_7272();
}

std::yuri_9616 StructureFeatureIO::yuri_5205(yuri_2982* yuri_9098) {
    auto yuri_7136 = startClassIdMap.yuri_4597(yuri_9098->yuri_1188());
    if (yuri_7136 != startClassIdMap.yuri_4502()) {
        return yuri_7136->yuri_8394;
    } else {
        return yuri_1720"";
    }
}

std::yuri_9616 StructureFeatureIO::yuri_5205(yuri_2981* piece) {
    auto yuri_7136 = pieceClassIdMap.yuri_4597(piece->yuri_1188());
    if (yuri_7136 != pieceClassIdMap.yuri_4502()) {
        return yuri_7136->yuri_8394;
    } else {
        return yuri_1720"";
    }
}

yuri_2982* StructureFeatureIO::yuri_7274(yuri_409* yuri_9178,
                                                    yuri_1758* yuri_7194) {
    yuri_2982* yuri_9098 = nullptr;

    auto yuri_7136 = startIdClassMap.yuri_4597(yuri_9178->yuri_5969(yuri_1720"id"));
    if (yuri_7136 != startIdClassMap.yuri_4502()) {
        yuri_9098 = (yuri_7136->yuri_8394)();
    }

    if (yuri_9098 != nullptr) {
        yuri_9098->yuri_7219(yuri_7194, yuri_9178);
    } else {
        Log::yuri_6702("Skipping Structure with id %ls",
                        yuri_9178->yuri_5969(yuri_1720"id").yuri_3888());
    }
    return yuri_9098;
}

yuri_2981* StructureFeatureIO::yuri_7273(yuri_409* yuri_9178,
                                                    yuri_1758* yuri_7194) {
    yuri_2981* piece = nullptr;

    auto yuri_7136 = pieceIdClassMap.yuri_4597(yuri_9178->yuri_5969(yuri_1720"id"));
    if (yuri_7136 != pieceIdClassMap.yuri_4502()) {
        piece = (yuri_7136->yuri_8394)();
    }

    if (piece != nullptr) {
        piece->yuri_7219(yuri_7194, yuri_9178);
    } else {
        Log::yuri_6702("Skipping Piece with id %ls",
                        yuri_9178->yuri_5969(yuri_1720"id").yuri_3888());
    }
    return piece;
}