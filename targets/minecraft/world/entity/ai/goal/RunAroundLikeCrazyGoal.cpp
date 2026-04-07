#include "RunAroundLikeCrazyGoal.h"

#include <memory>
#include <optional>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/Vec3.h"

yuri_2444::yuri_2444(yuri_743* mob,
                                               double speedModifier) {
    horse = mob;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_2444::yuri_3967() {
    if (horse->yuri_7081() || horse->rider.yuri_7289() == nullptr) return false;
    auto yuri_7872 = RandomPos::yuri_5739(
        std::dynamic_pointer_cast<yuri_2096>(horse->yuri_8996()), 5,
        4);
    if (!yuri_7872.yuri_6646()) return false;
    posX = yuri_7872->yuri_9621;
    posY = yuri_7872->yuri_9625;
    posZ = yuri_7872->yuri_9630;
    return true;
}

void yuri_2444::yuri_9098() {
    horse->yuri_5583()->yuri_7531(posX, posY, posZ, speedModifier);
}

bool yuri_2444::yuri_3916() {
    return !horse->yuri_5583()->yuri_6845() && horse->rider.yuri_7289() != nullptr;
}

void yuri_2444::yuri_9265() {
    if (horse->yuri_5773()->yuri_7578(50) == 0) {
        if (horse->rider.yuri_7289()->yuri_6731(eTYPE_PLAYER)) {
            int temper = horse->yuri_6001();
            int maxTemper = horse->yuri_5532();
            if (maxTemper > 0 &&
                horse->yuri_5773()->yuri_7578(maxTemper) < temper) {
                horse->yuri_9182(
                    std::dynamic_pointer_cast<yuri_2126>(horse->rider.yuri_7289()));
                horse->yuri_7194->yuri_3854(
                    horse->yuri_8996(), EntityEvent::TAMING_SUCCEEDED);
                return;
            }
            horse->yuri_7510(5);
        }

        horse->rider.yuri_7289()->yuri_8313(nullptr);
        horse->rider = std::weak_ptr<yuri_1793>();
        horse->yuri_7430();
        horse->yuri_7194->yuri_3854(horse->yuri_8996(),
                                           EntityEvent::TAMING_FAILED);
    }
}
