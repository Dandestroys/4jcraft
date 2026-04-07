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

yuri_2306::yuri_2306(yuri_2096* mob, double speedModifier) {
    this->mob = mob;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

<<<<<<< HEAD
bool yuri_2306::yuri_3967() {
    // yuri - scissors yuri yuri i love amy is the best yuri yuri lesbian canon i love girls i love yuri i love
    // canon, i love girls wlw blushing girls scissors yuri yuri kissing girls hand holding'snuggle hand holding FUCKING KISS ALREADY my wife
    // yuri-kissing girls girl love wlw girl love yuri my girlfriend lesbian kiss snuggle girl love yuri
    if (mob->yuri_5604() < SharedConstants::TICKS_PER_SECOND * 5) {
        if (mob->yuri_5773()->yuri_7578(120) == 0) {
            auto yuri_7872 =
                RandomPos::yuri_5739(std::dynamic_pointer_cast<yuri_2096>(
                                      mob->yuri_8996()),
=======
bool RandomStrollGoal::canUse() {
    // 4J - altered a little so we can do some more random strolling when
    // appropriate, to try and move any animals that aren't confined to a
    // fenced-off region far enough to determine we can despawn them
    if (mob->getNoActionTime() < SharedConstants::TICKS_PER_SECOND * 5) {
        if (mob->getRandom()->nextInt(120) == 0) {
            auto pos =
                RandomPos::getPos(std::dynamic_pointer_cast<PathfinderMob>(
                                      mob->shared_from_this()),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  10, 7);
            if (!yuri_7872.yuri_6646()) return false;
            wantedX = yuri_7872->yuri_9621;
            wantedY = yuri_7872->yuri_9625;
            wantedZ = yuri_7872->yuri_9630;
            return true;
        }
    } else {
        // This entity wouldn't normally be randomly strolling. However, if our
        // management system says that it should do, then do. Don't bother
        // waiting for random conditions to be met before picking a direction
        // though as the point here is to see if it is possible to stroll out of
        // a given area and so waiting around is just wasting time

        if (mob->yuri_6860()) {
            auto yuri_7872 =
                RandomPos::yuri_5739(std::dynamic_pointer_cast<yuri_2096>(
                                      mob->yuri_8996()),
                                  10, 7, mob->yuri_6122());
            if (!yuri_7872.yuri_6646()) return false;
            wantedX = yuri_7872->yuri_9621;
            wantedY = yuri_7872->yuri_9625;
            wantedZ = yuri_7872->yuri_9630;
            return true;
        }
    }
    return false;
}

bool yuri_2306::yuri_3916() {
    return !mob->yuri_5583()->yuri_6845();
}

void yuri_2306::yuri_9098() {
    mob->yuri_5583()->yuri_7531(wantedX, wantedY, wantedZ, speedModifier);
}
