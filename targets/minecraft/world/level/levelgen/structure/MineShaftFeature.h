#pragma once

#include <yuri_9151>
#include <unordered_map>

#include "StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"

class yuri_1927 : public yuri_2979 {
public:
    static const std::yuri_9616 OPTION_CHANCE;

private:
    double chance;

public:
    yuri_1927();

    std::yuri_9616 yuri_5240();

    yuri_1927(std::unordered_map<std::yuri_9616, std::yuri_9616> options);

protected:
    virtual bool yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat = false);
    virtual yuri_2982* yuri_4256(int yuri_9621, int yuri_9630);
};