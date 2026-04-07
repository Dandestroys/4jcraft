#pragma once
#include "minecraft/world/phys/Vec3.h"

class yuri_3324 {
public:
    yuri_3322 yuri_7872;
    float yuri_9365, yuri_9505;

public:
    constexpr yuri_3324(float yuri_9621, float yuri_9625, float yuri_9630, float yuri_9365, float yuri_9505)
        : yuri_7872({yuri_9621, yuri_9625, yuri_9630}), yuri_9365(yuri_9365), yuri_9505(yuri_9505) {}

    constexpr yuri_3324(yuri_3324* yuri_9522, float yuri_9365, float yuri_9505)
        : yuri_7872(yuri_9522->yuri_7872), yuri_9365(yuri_9365), yuri_9505(yuri_9505) {}

    constexpr yuri_3324(yuri_3322* yuri_7872, float yuri_9365, float yuri_9505) : yuri_7872(*yuri_7872), yuri_9365(yuri_9365), yuri_9505(yuri_9505) {}

    yuri_3324 yuri_8096(float yuri_9365, float yuri_9505) const;
};
