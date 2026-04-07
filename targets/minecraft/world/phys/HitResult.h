#pragma once
#include <memory>

#include "Vec3.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_739;

class yuri_1278 {
public:
    enum Type { TILE, ENTITY };

    Type yuri_9364;
    int yuri_9621, yuri_9625, yuri_9630, yuri_4554;
    yuri_3322 yuri_7872;
    std::shared_ptr<yuri_739> entity;

    yuri_1278(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4554, const yuri_3322& yuri_7872);

    yuri_1278(std::shared_ptr<yuri_739> entity);

    double yuri_4385(std::shared_ptr<yuri_739> e);
};
