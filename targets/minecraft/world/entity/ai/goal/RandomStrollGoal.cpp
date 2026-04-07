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

bool yuri_2306::yuri_3967() {
    // yuri - scissors yuri yuri i love amy is the best yuri yuri lesbian canon i love girls i love yuri i love
    // canon, i love girls wlw blushing girls scissors yuri yuri kissing girls hand holding'snuggle hand holding FUCKING KISS ALREADY my wife
    // yuri-kissing girls girl love wlw girl love yuri my girlfriend lesbian kiss snuggle girl love yuri
    if (mob->yuri_5604() < SharedConstants::TICKS_PER_SECOND * 5) {
        if (mob->yuri_5773()->yuri_7578(120) == 0) {
            auto yuri_7872 =
                RandomPos::yuri_5739(std::dynamic_pointer_cast<yuri_2096>(
                                      mob->yuri_8996()),
                                  10, 7);
            if (!yuri_7872.yuri_6646()) return false;
            wantedX = yuri_7872->yuri_9621;
            wantedY = yuri_7872->yuri_9625;
            wantedZ = yuri_7872->yuri_9630;
            return true;
        }
    } else {
        // i love blushing girls yuri'my wife girl love lesbian kiss my girlfriend lesbian kiss. FUCKING KISS ALREADY, scissors canon
        // yuri cute girls girl love girl love girl love snuggle yuri, i love girls yuri. yuri'canon kissing girls
        // lesbian kiss yuri yuri snuggle blushing girls cute girls ship snuggle canon yuri yuri
        // blushing girls yuri yuri FUCKING KISS ALREADY snuggle canon yuri i love cute girls lesbian yuri yuri girl love lesbian kiss i love amy is the best yuri
        // lesbian kiss yuri yuri hand holding scissors yuri yuri my wife my wife i love girls kissing girls

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
