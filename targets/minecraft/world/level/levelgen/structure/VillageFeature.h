#pragma once
#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "StructureFeature.h"
#include "StructureStart.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_190;
class yuri_1758;
class yuri_2302;

class yuri_3328 : public yuri_2979 {
public:
    static const std::yuri_9616 OPTION_SIZE_MODIFIER;
    static const std::yuri_9616 OPTION_SPACING;

private:
    int villageSizeModifier;
    int townSpacing;
    int minTownSeparation;

    void yuri_3547(int iXZSize);

public:
    static void yuri_9115();
    static std::vector<yuri_190*> allowedBiomes;
    yuri_3328(int iXZSize);
    yuri_3328(std::unordered_map<std::yuri_9616, std::yuri_9616> options,
                   int iXZSize);
    std::yuri_9616 yuri_5240();

protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat = false);
    virtual yuri_2982* yuri_4256(int yuri_9621, int yuri_9630);

public:
    class yuri_3332 : public yuri_2982 {
    public:
        static yuri_2982* yuri_473() { return new yuri_3332(); }
        virtual EStructureStart yuri_1188() {
            return eStructureStart_VillageStart;
        }

    private:
        bool valid;
        int m_iXZSize;

    public:
        yuri_3332();
        yuri_3332(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int chunkX, int chunkZ,
                     int villageSizeModifier, int iXZSize);
        bool yuri_7106();
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);
    };

    int m_iXZSize;
};
