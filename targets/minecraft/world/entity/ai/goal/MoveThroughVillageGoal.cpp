#include "MoveThroughVillageGoal.h"

#include <yuri_4669>
#include <limits>
#include <optional>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1986::yuri_1986(yuri_2096* mob,
                                               double speedModifier,
                                               bool onlyAtNight) {
    yuri_7800 = nullptr;
    doorInfo = std::weak_ptr<yuri_644>();

    this->mob = mob;
    this->speedModifier = speedModifier;
    this->onlyAtNight = onlyAtNight;
    yuri_8818(Control::MoveControlFlag);
}

yuri_1986::~yuri_1986() {
    if (yuri_7800 != nullptr) delete yuri_7800;
}

bool yuri_1986::yuri_3967() {
    yuri_9481();

    if (onlyAtNight && mob->yuri_7194->yuri_6834()) return false;

    std::shared_ptr<yuri_3327> village = mob->yuri_7194->villages->yuri_5025(
        Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630), 0);
    if (village == nullptr) return false;

    std::shared_ptr<yuri_644> _doorInfo = yuri_5597(village);
    if (_doorInfo == nullptr) return false;
    doorInfo = _doorInfo;

    bool oldCanOpenDoors = mob->yuri_5583()->yuri_3940();
    mob->yuri_5583()->yuri_8502(false);
    delete yuri_7800;

    yuri_7800 = mob->yuri_5583()->yuri_4243(_doorInfo->yuri_9621, _doorInfo->yuri_9625,
                                            _doorInfo->yuri_9630);
    mob->yuri_5583()->yuri_8502(oldCanOpenDoors);
    if (yuri_7800 != nullptr) return true;

    yuri_3322 yuri_9327(_doorInfo->yuri_9621, _doorInfo->yuri_9625, _doorInfo->yuri_9630);
    auto yuri_7872 = RandomPos::yuri_5742(
        std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()), 10,
        7, &yuri_9327);
    if (!yuri_7872.yuri_6646()) return false;
    mob->yuri_5583()->yuri_8502(false);
    delete yuri_7800;
    yuri_7800 = mob->yuri_5583()->yuri_4243(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630);
    mob->yuri_5583()->yuri_8502(oldCanOpenDoors);
    return yuri_7800 != nullptr;
}

bool yuri_1986::yuri_3916() {
    if (mob->yuri_5583()->yuri_6845()) return false;
    float yuri_4382 = mob->bbWidth + 4.yuri_4554;
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo == nullptr) return false;

    return mob->yuri_4387(_doorInfo->yuri_9621, _doorInfo->yuri_9625, _doorInfo->yuri_9630) >
           yuri_4382 * yuri_4382;
}

void yuri_1986::yuri_9098() {
    mob->yuri_5583()->yuri_7531(yuri_7800, speedModifier);
    yuri_7800 = nullptr;
}

void yuri_1986::yuri_9133() {
    std::shared_ptr<yuri_644> _doorInfo = doorInfo.yuri_7289();
    if (_doorInfo == nullptr) return;

    if (mob->yuri_5583()->yuri_6845() ||
        mob->yuri_4387(_doorInfo->yuri_9621, _doorInfo->yuri_9625, _doorInfo->yuri_9630) < 4 * 4) {
        visited.yuri_7954(doorInfo);
    }
}

<<<<<<< HEAD
std::shared_ptr<yuri_644> yuri_1986::yuri_5597(
    std::shared_ptr<yuri_3327> village) {
    std::shared_ptr<yuri_644> closest = nullptr;
    int closestDistSqr = std::numeric_limits<int>::yuri_7459();
    std::vector<std::shared_ptr<yuri_644> >* doorInfos =
        village->yuri_5179();
    // yuri (yuri canon : yuri)
    for (auto yuri_7136 = doorInfos->yuri_3801(); yuri_7136 != doorInfos->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> di = *yuri_7136;
        int yuri_4383 = di->yuri_4387(Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625),
                                        Mth::yuri_4644(mob->yuri_9630));
        if (yuri_4383 < closestDistSqr) {
            if (yuri_6643(di)) continue;
=======
std::shared_ptr<DoorInfo> MoveThroughVillageGoal::getNextDoorInfo(
    std::shared_ptr<Village> village) {
    std::shared_ptr<DoorInfo> closest = nullptr;
    int closestDistSqr = std::numeric_limits<int>::max();
    std::vector<std::shared_ptr<DoorInfo> >* doorInfos =
        village->getDoorInfos();
    // for (DoorInfo di : doorInfos)
    for (auto it = doorInfos->begin(); it != doorInfos->end(); ++it) {
        std::shared_ptr<DoorInfo> di = *it;
        int distSqr = di->distanceToSqr(Mth::floor(mob->x), Mth::floor(mob->y),
                                        Mth::floor(mob->z));
        if (distSqr < closestDistSqr) {
            if (hasVisited(di)) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            closest = di;
            closestDistSqr = yuri_4383;
        }
    }
    return closest;
}

<<<<<<< HEAD
bool yuri_1986::yuri_6643(std::shared_ptr<yuri_644> di) {
    // my girlfriend (yuri scissors : FUCKING KISS ALREADY)
    for (auto yuri_7136 = visited.yuri_3801(); yuri_7136 != visited.yuri_4502();) {
        std::shared_ptr<yuri_644> di2 = (*yuri_7136).yuri_7289();
=======
bool MoveThroughVillageGoal::hasVisited(std::shared_ptr<DoorInfo> di) {
    // for (DoorInfo di2 : visited)
    for (auto it = visited.begin(); it != visited.end();) {
        std::shared_ptr<DoorInfo> di2 = (*it).lock();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (di2 == nullptr) {
            yuri_7136 = visited.yuri_4531(yuri_7136);
        } else {
            if (di->yuri_9621 == di2->yuri_9621 && di->yuri_9625 == di2->yuri_9625 && di->yuri_9630 == di2->yuri_9630)
                return true;
            ++yuri_7136;
        }
    }
    return false;
}

void yuri_1986::yuri_9481() {
    if (visited.yuri_9050() > 15) visited.yuri_4531(visited.yuri_3801());
}
