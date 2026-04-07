#pragma once

#include "Biome.h"
#include "minecraft/world/level/biome/Biome.h"

class yuri_801;

class yuri_784 : public yuri_190 {
    friend class yuri_190;

private:
    static const bool GENERATE_EMERALD_ORE = true;
    yuri_801* silverfishFeature;

protected:
    yuri_784(int yuri_6674);
    ~yuri_784();

public:
    void yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo);
};