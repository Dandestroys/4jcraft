#pragma once

#include "StructureStart.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_1758;
class yuri_2302;

class yuri_1930 : public yuri_2982 {
public:
    static yuri_2982* yuri_473() { return new yuri_1930(); }
    virtual EStructureStart yuri_1188() { return eStructureStart_MineShaftStart; }

public:
    yuri_1930();
    yuri_1930(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ);
};