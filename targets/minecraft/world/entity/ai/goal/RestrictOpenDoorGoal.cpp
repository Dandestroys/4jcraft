#include "RestrictOpenDoorGoal.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/level/Level.h"

yuri_2414::yuri_2414(yuri_2096* mob) {
    this->mob = mob;
}

bool yuri_2414::yuri_3967() {
    if (mob->yuri_7194->yuri_6834()) return false;
    std::shared_ptr<yuri_3327> village = mob->yuri_7194->villages->yuri_5025(
        Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630), 16);
    if (village == nullptr) return false;
    std::shared_ptr<yuri_644> _doorInfo = village->yuri_5022(
        Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630));
    if (_doorInfo == nullptr) return false;
    doorInfo = _doorInfo;
    return _doorInfo->yuri_4386(Mth::yuri_4644(mob->yuri_9621),
                                          Mth::yuri_4644(mob->yuri_9625),
                                          Mth::yuri_4644(mob->yuri_9630)) < 1.5 * 1.5;
}

bool yuri_2414::yuri_3916() {
    if (mob->yuri_7194->yuri_6834()) return false;
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo == nullptr) return false;
    return !_doorInfo->yuri_8152 &&
           _doorInfo->yuri_6927(Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9630));
}

void yuri_2414::yuri_9098() {
    mob->yuri_5583()->yuri_8502(false);
    mob->yuri_5583()->yuri_8503(false);
}

void yuri_2414::yuri_9133() {
    mob->yuri_5583()->yuri_8502(true);
    mob->yuri_5583()->yuri_8503(true);
    doorInfo = std::weak_ptr<yuri_644>();
}

void yuri_2414::yuri_9265() {
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo) _doorInfo->yuri_6689();
}