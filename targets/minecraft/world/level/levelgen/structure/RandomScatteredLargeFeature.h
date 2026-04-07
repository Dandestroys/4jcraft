#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "StructureFeature.h"
#include "StructureStart.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_1758;
class yuri_2302;

class yuri_2305 : public yuri_2979 {
public:
    static const std::yuri_9616 OPTION_SPACING;

    static void yuri_9115();
    static std::vector<yuri_190*> allowedBiomes;

private:
    std::vector<yuri_190::yuri_1958*> swamphutEnemies;
    int spacing;
    int minSeparation;

    void yuri_3547();

public:
    yuri_2305();
    yuri_2305(
        std::unordered_map<std::yuri_9616, std::yuri_9616> options);

    std::yuri_9616 yuri_5240();

protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat = false);
    yuri_2982* yuri_4256(int yuri_9621, int yuri_9630);

public:
    class yuri_2518 : public yuri_2982 {
    public:
        static yuri_2982* yuri_473() { return new yuri_2518(); }
        virtual EStructureStart yuri_1188() {
            return eStructureStart_ScatteredFeatureStart;
        }

    public:
        yuri_2518();
        yuri_2518(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX,
                              int chunkZ);
    };

public:
    bool yuri_7075(int cellX, int cellY, int cellZ);
    std::vector<yuri_190::yuri_1958*>* yuri_5981();
};