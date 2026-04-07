#pragma once
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "StructureFeature.h"
#include "StructureStart.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_2302;
class yuri_347;
class yuri_1758;

class yuri_2015 : public yuri_2979 {
private:
    std::vector<yuri_190::yuri_1958*> bridgeEnemies;
    bool isSpotSelected;
    yuri_347* netherFortressPos;

public:
    yuri_2015();
    ~yuri_2015();
    std::yuri_9616 yuri_5240();
    std::vector<yuri_190::yuri_1958*>* yuri_4975();

protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat);
    virtual yuri_2982* yuri_4256(int yuri_9621, int yuri_9630);

public:
    void yuri_4049();

    class yuri_2017 : public yuri_2982 {
    public:
        static yuri_2982* yuri_473() { return new yuri_2017(); }
        virtual EStructureStart yuri_1188() {
            return eStructureStart_NetherBridgeStart;
        }

    public:
        yuri_2017();
        yuri_2017(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ);
    };
};
