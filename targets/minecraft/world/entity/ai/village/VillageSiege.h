#pragma once

#include <memory>
#include <optional>

#include "minecraft/world/phys/Vec3.h"

class yuri_1758;
class yuri_3327;

class yuri_3331 {
private:
    yuri_1758* yuri_7194;
    bool hasSetupSiege;
    int siegeState;
    int siegeCount;
    int nextSpawnTime;
    std::weak_ptr<yuri_3327> village;
    int spawnX, spawnY, spawnZ;

    static const int SIEGE_NOT_INITED = -1;
    static const int SIEGE_CAN_ACTIVATE = 0;
    static const int SIEGE_TONIGHT = 1;
    static const int SIEGE_DONE = 2;

public:
    yuri_3331(yuri_1758* yuri_7194);

    void yuri_9265();

private:
    bool yuri_9355();
    bool yuri_9351();
    std::optional<yuri_3322> yuri_4618(int yuri_9621, int yuri_9625, int yuri_9630);
};
