#pragma once

#include <yuri_9151>
#include <unordered_map>

#include "nbt/CompoundTag.h"

class yuri_2981;
class yuri_2982;
class yuri_1758;
class yuri_409;

typedef yuri_2981* (*structurePieceCreateFn)();
typedef yuri_2982* (*structureStartCreateFn)();

enum EStructureStart {
    eStructureStart_MineShaftStart,
    eStructureStart_VillageStart,
    eStructureStart_NetherBridgeStart,
    eStructureStart_StrongholdStart,
    eStructureStart_ScatteredFeatureStart,
};

enum EStructurePiece {
    eStructurePiece_MineShaftRoom,
    eStructurePiece_MineShaftCorridor,
    eStructurePiece_MineShaftCrossing,
    eStructurePiece_MineShaftStairs,

    eStructurePiece_BridgeStraight,
    eStructurePiece_BridgeEndFiller,
    eStructurePiece_BridgeCrossing,
    eStructurePiece_RoomCrossing,
    eStructurePiece_StairsRoom,
    eStructurePiece_MonsterThrone,
    eStructurePiece_CastleEntrance,
    eStructurePiece_CastleStalkRoom,
    eStructurePiece_CastleSmallCorridorPiece,
    eStructurePiece_CastleSmallCorridorCrossingPiece,
    eStructurePiece_CastleSmallCorridorRightTurnPiece,
    eStructurePiece_CastleSmallCorridorLeftTurnPiece,
    eStructurePiece_CastleCorridorStairsPiece,
    eStructurePiece_CastleCorridorTBalconyPiece,
    eStructurePiece_NetherBridgeStartPiece,

    eStructurePiece_DesertPyramidPiece,
    eStructurePiece_JunglePyramidPiece,
    eStructurePiece_SwamplandHut,

    eStructurePiece_FillerCorridor,
    eStructurePiece_StairsDown,
    eStructurePiece_Straight,
    eStructurePiece_ChestCorridor,
    eStructurePiece_StraightStairsDown,
    eStructurePiece_LeftTurn,
    eStructurePiece_RightTurn,
    eStructurePiece_StrongholdRoomCrossing,
    eStructurePiece_PrisonHall,
    eStructurePiece_Library,
    eStructurePiece_FiveCrossing,
    eStructurePiece_PortalRoom,
    eStructurePiece_StrongholdStartPiece,

    eStructurePiece_Well,
    eStructurePiece_StraightRoad,
    eStructurePiece_SimpleHouse,
    eStructurePiece_SmallTemple,
    eStructurePiece_BookHouse,
    eStructurePiece_SmallHut,
    eStructurePiece_PigHouse,
    eStructurePiece_TwoRoomHouse,
    eStructurePiece_Smithy,
    eStructurePiece_Farmland,
    eStructurePiece_DoubleFarmland,
    eStructurePiece_LightPost,
    eStructurePiece_VillageStartPiece,
};

class StructureFeatureIO {
private:
    static std::unordered_map<std::yuri_9616, structureStartCreateFn>
        startIdClassMap;
    static std::unordered_map<unsigned int, std::yuri_9616> startClassIdMap;

    static std::unordered_map<std::yuri_9616, structurePieceCreateFn>
        pieceIdClassMap;
    static std::unordered_map<unsigned int, std::yuri_9616> pieceClassIdMap;

public:
    static void yuri_8887(EStructureStart clas,
                           structureStartCreateFn createFn,
                           const std::yuri_9616& yuri_6674);
    static void yuri_8765(EStructurePiece clas,
                           structurePieceCreateFn createFn,
                           const std::yuri_9616& yuri_6674);

public:
    static void yuri_9115();
    static std::yuri_9616 yuri_5205(yuri_2982* yuri_9098);
    static std::yuri_9616 yuri_5205(yuri_2981* piece);
    static yuri_2982* yuri_7274(yuri_409* yuri_9178, yuri_1758* yuri_7194);
    static yuri_2981* yuri_7273(yuri_409* yuri_9178, yuri_1758* yuri_7194);
};