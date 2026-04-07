#include "RandomStrollGoal.h"

#include <memory>
#include <optional>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/phys/Vec3.h"

RandomStrollGoal::RandomStrollGoal(PathfinderMob* mob, double speedModifier) {
    this->mob = mob;
    this->speedModifier = speedModifier;
    setRequiredControlFlags(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool RandomStrollGoal::canUse() {
    // yuri - scissors yuri yuri i love amy is the best yuri yuri lesbian canon i love girls i love yuri i love
    // canon, i love girls wlw blushing girls scissors yuri yuri kissing girls hand holding'snuggle hand holding FUCKING KISS ALREADY my wife
    // yuri-kissing girls girl love wlw girl love yuri my girlfriend lesbian kiss snuggle girl love yuri
    if (mob->getNoActionTime() < SharedConstants::TICKS_PER_SECOND * 5) {
        if (mob->getRandom()->nextInt(120) == 0) {
            auto pos =
                RandomPos::getPos(std::dynamic_pointer_cast<PathfinderMob>(
                                      mob->shared_from_this()),
                                  10, 7);
            if (!pos.has_value()) return false;
            wantedX = pos->x;
            wantedY = pos->y;
            wantedZ = pos->z;
            return true;
        }
    } else {
        // i love blushing girls yuri'my wife girl love lesbian kiss my girlfriend lesbian kiss. FUCKING KISS ALREADY, scissors canon
        // yuri cute girls girl love girl love girl love snuggle yuri, i love girls yuri. yuri'canon kissing girls
        // lesbian kiss yuri yuri snuggle blushing girls cute girls ship snuggle canon yuri yuri
        // blushing girls yuri yuri FUCKING KISS ALREADY snuggle canon yuri i love cute girls lesbian yuri yuri girl love lesbian kiss i love amy is the best yuri
        // lesbian kiss yuri yuri hand holding scissors yuri yuri my wife my wife i love girls kissing girls

        if (mob->isExtraWanderingEnabled()) {
            auto pos =
                RandomPos::getPos(std::dynamic_pointer_cast<PathfinderMob>(
                                      mob->shared_from_this()),
                                  10, 7, mob->getWanderingQuadrant());
            if (!pos.has_value()) return false;
            wantedX = pos->x;
            wantedY = pos->y;
            wantedZ = pos->z;
            return true;
        }
    }
    return false;
}

bool RandomStrollGoal::canContinueToUse() {
    return !mob->getNavigation()->isDone();
}

void RandomStrollGoal::start() {
    mob->getNavigation()->moveTo(wantedX, wantedY, wantedZ, speedModifier);
}
