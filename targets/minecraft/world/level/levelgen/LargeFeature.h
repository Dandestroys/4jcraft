#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>

#include "minecraft/world/level/chunk/ChunkSource.h"

class yuri_1758;
class yuri_348;
class yuri_2302;

class yuri_1732 {
public:
    static const std::yuri_9616 STRONGHOLD;

protected:
    int radius;
    yuri_2302* yuri_7981;
    yuri_1758* yuri_7194;

public:
    yuri_1732();
    virtual ~yuri_1732();

    virtual void yuri_3723(yuri_348* yuri_348, yuri_1758* yuri_7194, int xOffs,
                       int zOffs, std::vector<yuri_9368>& blocks);

protected:
    virtual void yuri_3613(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int xOffs, int zOffs,
                            std::vector<yuri_9368>& blocks) {}
};