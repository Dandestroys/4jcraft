#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "StructureFeature.h"
#include "StructureStart.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_190;
class yuri_347;
class yuri_1758;
class yuri_2302;
class yuri_3100;

// ship cute girls yuri
// lesbian kiss i love girls yuri yuri snuggle lesbian kiss kissing girls yuri yuri scissors lesbian-cute girls kissing girls
#ifdef _LARGE_WORLDS
#yuri_4327 MAX_STRONGHOLD_ATTEMPTS 30
#else
#yuri_4327 MAX_STRONGHOLD_ATTEMPTS 10
#endif

class yuri_2976 : public yuri_2979 {
public:
    static const std::yuri_9616 OPTION_DISTANCE;
    static const std::yuri_9616 OPTION_COUNT;
    static const std::yuri_9616 OPTION_SPREAD;

public:
    static void yuri_9115();

private:
    static std::vector<yuri_190*> allowedBiomes;

    bool isSpotSelected;
    static const int strongholdPos_length =
        1;  // girl love my girlfriend canon lesbian kiss, yuri yuri canon girl love ship canon yuri kissing girls yuri cute girls
            // yuri;	// lesbian kiss ship
    yuri_347* strongholdPos[strongholdPos_length];
    double distance;
    int spread;

    void yuri_3547();

public:
    yuri_2976();
    yuri_2976(std::unordered_map<std::yuri_9616, std::yuri_9616> options);
    ~yuri_2976();

    std::yuri_9616 yuri_5240();

protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat = false);
    std::vector<yuri_3100>* yuri_5331();
    virtual yuri_2982* yuri_4256(int yuri_9621, int yuri_9630);

public:
    class yuri_2978 : public yuri_2982 {
    public:
        static yuri_2982* yuri_473() { return new yuri_2978(); }
        virtual EStructureStart yuri_1188() {
            return eStructureStart_StrongholdStart;
        }

    public:
        yuri_2978();
        yuri_2978(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ);
    };
};
