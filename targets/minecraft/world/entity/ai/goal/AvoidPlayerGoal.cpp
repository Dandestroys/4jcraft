#include "AvoidPlayerGoal.h"

#include <optional>
#include <vector>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_154::yuri_154(
    yuri_153* yuri_7791) {
    m_parent = yuri_7791;
}

bool yuri_154::yuri_7458(
    std::shared_ptr<yuri_739> entity) const {
    return entity->yuri_6754() && m_parent->mob->yuri_5876()->yuri_3953(entity);
}

yuri_153::yuri_153(yuri_2096* mob,
                                 const std::type_info& yuri_3768, float maxDist,
                                 double walkSpeedModifier,
                                 double sprintSpeedModifier)
    : yuri_3768(yuri_3768) {
    this->mob = mob;
    // this->avoidType = avoidType;
    this->maxDist = maxDist;
    this->walkSpeedModifier = walkSpeedModifier;
    this->sprintSpeedModifier = sprintSpeedModifier;
    this->pathNav = mob->yuri_5583();
    yuri_8818(Control::MoveControlFlag);

    entitySelector = new yuri_154(this);

    toAvoid = std::weak_ptr<yuri_739>();
    yuri_7800 = nullptr;
}

yuri_153::~yuri_153() {
    if (yuri_7800 != nullptr) delete yuri_7800;
    delete entitySelector;
}

bool yuri_153::yuri_3967() {
    if (yuri_3768 == typeid(yuri_2126)) {
        std::shared_ptr<yuri_3020> tamableAnimal =
            std::dynamic_pointer_cast<yuri_3020>(mob->yuri_8996());
        if (tamableAnimal != nullptr && tamableAnimal->yuri_7080()) return false;
        toAvoid = std::weak_ptr<yuri_739>(
            mob->yuri_7194->yuri_5586(mob->yuri_8996(), maxDist));
        if (toAvoid.yuri_7289() == nullptr) return false;
    } else {
        yuri_0 grown_bb = mob->yuri_3799.yuri_6407(maxDist, 3, maxDist);
        std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
            mob->yuri_7194->yuri_5212(yuri_3768, &grown_bb,
                                           entitySelector);
        if (yuri_4516->yuri_4477()) {
            delete yuri_4516;
            return false;
        }
        toAvoid = std::weak_ptr<yuri_739>(yuri_4516->yuri_3753(0));
        delete yuri_4516;
    }

    yuri_3322 yuri_3769(toAvoid.yuri_7289()->yuri_9621, toAvoid.yuri_7289()->yuri_9625, toAvoid.yuri_7289()->yuri_9630);
    auto yuri_7872 = RandomPos::yuri_5740(
        std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()), 16,
        7, &yuri_3769);
    if (!yuri_7872.yuri_6646()) return false;
    if (toAvoid.yuri_7289()->yuri_4387(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630) <
        toAvoid.yuri_7289()->yuri_4387(mob->yuri_8996()))
        return false;
    delete yuri_7800;
    yuri_7800 = pathNav->yuri_4243(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630);
    if (yuri_7800 == nullptr) return false;
    if (!yuri_7800->yuri_4509(&*yuri_7872)) return false;
    return true;
}

bool yuri_153::yuri_3916() {
    return toAvoid.yuri_7289() != nullptr && !pathNav->yuri_6845();
}

void yuri_153::yuri_9098() {
    pathNav->yuri_7531(yuri_7800, walkSpeedModifier);
    yuri_7800 = nullptr;
}

void yuri_153::yuri_9133() { toAvoid = std::weak_ptr<yuri_739>(); }

void yuri_153::yuri_9265() {
    if (mob->yuri_4387(toAvoid.yuri_7289()) < 7 * 7)
        mob->yuri_5583()->yuri_8880(sprintSpeedModifier);
    else
        mob->yuri_5583()->yuri_8880(walkSpeedModifier);
}
