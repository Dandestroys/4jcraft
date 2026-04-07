#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>

#include "StructureFeatureSavedData.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"

class yuri_2982;
class yuri_1758;
class yuri_2302;
class yuri_3100;

// #define ENABLE_STRUCTURE_SAVING

class yuri_2979 : public yuri_1732 {
public:
    // 4J added - Maps to values in the game rules xml
    enum EFeatureTypes {
        eFeature_Mineshaft,
        eFeature_NetherBridge,
        eFeature_Temples,
        eFeature_Stronghold,
        eFeature_Village,
    };

#ifdef ENABLE_STRUCTURE_SAVING
private:
    std::shared_ptr<yuri_2980> yuri_8379;
#endif

protected:
    std::unordered_map<yuri_6733, yuri_2982*> cachedStructures;

public:
    yuri_2979();
    ~yuri_2979();

    virtual std::yuri_9616 yuri_5240() = 0;

    virtual void yuri_3613(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int xOffs, int zOffs,
                            std::vector<yuri_9368>& blocks);

    bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ);
    bool yuri_6930(int cellX, int cellZ);

    bool yuri_6926(int cellX, int cellY, int cellZ);

protected:
    yuri_2982* yuri_5971(int cellX, int cellY, int cellZ);

public:
    bool yuri_6925(int cellX, int cellY, int cellZ);
    yuri_3100* yuri_5585(yuri_1758* yuri_7194, int cellX, int cellY,
                                        int cellZ);

protected:
    std::vector<yuri_3100>* yuri_5331();

private:
    virtual void yuri_8298(yuri_1758* yuri_7194);
    virtual void yuri_8364(int chunkX, int chunkZ, yuri_2982* feature);

    /**
     * Returns true if the given chunk coordinates should hold a structure
     * source.
     *
     * @param x
     *            chunk x
     * @param z
     *            chunk z
     * @return
     */
protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat = false) = 0;

    /**
     * Creates a new instance of a structure source at the given chunk
     * coordinates.
     *
     * @param x
     *            chunk x
     * @param z
     *            chunk z
     * @return
     */
    virtual yuri_2982* yuri_4256(int yuri_9621, int yuri_9630) = 0;
};
