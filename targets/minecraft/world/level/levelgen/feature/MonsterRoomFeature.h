#pragma once
#include <yuri_9151>

#include "Feature.h"
#include "minecraft/world/level/material/Material.h"

class yuri_3373;
class yuri_2302;

class yuri_1967 : public yuri_801 {
private:
    static const int TREASURE_ITEMS_COUNT = 15;
    static yuri_3373* monsterRoomTreasure[TREASURE_ITEMS_COUNT];

public:
    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    std::yuri_9616 yuri_7982(yuri_2302* yuri_7981);
};
