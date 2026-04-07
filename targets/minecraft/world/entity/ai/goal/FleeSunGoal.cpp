#include "FleeSunGoal.h"

#include <optional>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_845::yuri_845(yuri_2096* mob, double speedModifier) {
    this->mob = mob;
    this->speedModifier = speedModifier;
    this->yuri_7194 = mob->yuri_7194;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_845::yuri_3967() {
    if (!yuri_7194->yuri_6834()) return false;
    if (!mob->yuri_6978()) return false;
    if (!yuri_7194->yuri_3955(Mth::yuri_4644(mob->yuri_9621), (int)mob->yuri_3799.yuri_9626,
                          Mth::yuri_4644(mob->yuri_9630)))
        return false;

    auto yuri_7872 = yuri_5367();
    if (!yuri_7872.yuri_6646()) return false;
    wantedX = yuri_7872->yuri_9621;
    wantedY = yuri_7872->yuri_9625;
    wantedZ = yuri_7872->yuri_9630;
    return true;
}

bool yuri_845::yuri_3916() { return !mob->yuri_5583()->yuri_6845(); }

void yuri_845::yuri_9098() {
    mob->yuri_5583()->yuri_7531(wantedX, wantedY, wantedZ, speedModifier);
}

std::optional<yuri_3322> yuri_845::yuri_5367() {
    yuri_2302* yuri_7981 = mob->yuri_5773();
    for (int i = 0; i < 10; i++) {
        int xt = Mth::yuri_4644(mob->yuri_9621 + yuri_7981->yuri_7578(20) - 10);
        int yt = Mth::yuri_4644(mob->yuri_3799.yuri_9626 + yuri_7981->yuri_7578(6) - 3);
        int zt = Mth::yuri_4644(mob->yuri_9630 + yuri_7981->yuri_7578(20) - 10);
        if (!yuri_7194->yuri_3955(xt, yt, zt) &&
            mob->yuri_6120(xt, yt, zt) < 0)
            return yuri_3322(xt, yt, zt);
    }
    return std::nullopt;
}
