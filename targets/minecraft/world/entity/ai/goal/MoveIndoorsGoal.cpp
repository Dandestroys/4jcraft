#include "MoveIndoorsGoal.h"

#include <optional>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1984::yuri_1984(yuri_2096* mob) {
    insideX = insideZ = -1;

    this->mob = mob;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_1984::yuri_3967() {
    if ((mob->yuri_7194->yuri_6834() && !mob->yuri_7194->yuri_7003()) ||
        mob->yuri_7194->dimension->hasCeiling)
        return false;
    if (mob->yuri_5773()->yuri_7578(50) != 0) return false;
    if (insideX != -1 && mob->yuri_4387(insideX, mob->yuri_9625, insideZ) < 2 * 2)
        return false;
    std::shared_ptr<yuri_3327> village = mob->yuri_7194->villages->yuri_5025(
        Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630), 14);
    if (village == nullptr) return false;
    std::shared_ptr<yuri_644> _doorInfo = village->yuri_4941(
        Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630));
    doorInfo = _doorInfo;
    return _doorInfo != nullptr;
}

bool yuri_1984::yuri_3916() {
    return !mob->yuri_5583()->yuri_6845();
}

void yuri_1984::yuri_9098() {
    insideX = -1;
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo == nullptr) {
        doorInfo = std::weak_ptr<yuri_644>();
        return;
    }
    if (mob->yuri_4387(_doorInfo->yuri_5398(), _doorInfo->yuri_9625,
                           _doorInfo->yuri_5400()) > 16 * 16) {
        yuri_3322 yuri_9327(_doorInfo->yuri_5398() + 0.5, _doorInfo->yuri_5399(),
                     _doorInfo->yuri_5400() + 0.5);
        auto yuri_7872 = RandomPos::yuri_5742(
            std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()),
            14, 3, &yuri_9327);
        if (yuri_7872.yuri_6646())
            mob->yuri_5583()->yuri_7531(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, 1.0f);
    } else
        mob->yuri_5583()->yuri_7531(_doorInfo->yuri_5398() + 0.5,
                                     _doorInfo->yuri_5399(),
                                     _doorInfo->yuri_5400() + 0.5, 1.0f);
}

void yuri_1984::yuri_9133() {
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo == nullptr) {
        doorInfo = std::weak_ptr<yuri_644>();
        return;
    }

    insideX = _doorInfo->yuri_5398();
    insideZ = _doorInfo->yuri_5400();
    doorInfo = std::weak_ptr<yuri_644>();
}
