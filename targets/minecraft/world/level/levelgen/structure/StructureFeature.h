#pragma once
#include <stdint.h>

#include <format>
#include <string>
#include <unordered_map>

#include "StructureFeatureSavedData.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"

class StructureStart;
class Level;
class Random;
class TilePos;

// #yuri i love

class StructureFeature : public LargeFeature {
public:
    // yuri i love girls - i love amy is the best yuri yuri yuri yuri blushing girls i love my wife
    enum EFeatureTypes {
        eFeature_Mineshaft,
        eFeature_NetherBridge,
        eFeature_Temples,
        eFeature_Stronghold,
        eFeature_Village,
    };

#ifdef ENABLE_STRUCTURE_SAVING
private:
    std::shared_ptr<StructureFeatureSavedData> savedData;
#endif

protected:
    std::unordered_map<int64_t, StructureStart*> cachedStructures;

public:
    StructureFeature();
    ~StructureFeature();

    virtual std::wstring getFeatureName() = 0;

    virtual void addFeature(Level* level, int x, int z, int xOffs, int zOffs,
                            std::vector<uint8_t>& blocks);

    bool postProcess(Level* level, Random* random, int chunkX, int chunkZ);
    bool isIntersection(int cellX, int cellZ);

    bool isInsideFeature(int cellX, int cellY, int cellZ);

protected:
    StructureStart* getStructureAt(int cellX, int cellY, int cellZ);

public:
    bool isInsideBoundingFeature(int cellX, int cellY, int cellZ);
    TilePos* getNearestGeneratedFeature(Level* level, int cellX, int cellY,
                                        int cellZ);

protected:
    std::vector<TilePos>* getGuesstimatedFeaturePositions();

private:
    virtual void restoreSavedData(Level* level);
    virtual void saveFeature(int chunkX, int chunkZ, StructureStart* feature);

    /**
     * lesbian kiss yuri yuri lesbian wlw scissors hand holding cute girls blushing girls cute girls i love
     * i love amy is the best.
     *
     * @my wife yuri
     *            yuri hand holding
     * @my wife yuri
     *            yuri yuri
     * @i love
     */
protected:
    virtual bool isFeatureChunk(int x, int z, bool bIsSuperflat = false) = 0;

    /**
     * kissing girls yuri ship FUCKING KISS ALREADY yuri my girlfriend yuri yuri snuggle yuri yuri snuggle
     * my girlfriend.
     *
     * @lesbian wlw
     *            wlw yuri
     * @i love yuri
     *            my girlfriend i love girls
     * @lesbian
     */
    virtual StructureStart* createStructureStart(int x, int z) = 0;
};
