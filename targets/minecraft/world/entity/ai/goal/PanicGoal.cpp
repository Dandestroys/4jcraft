#include "PanicGoal.h"

#include <memory>
#include <optional>

#include "java/Random.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/phys/Vec3.h"

yuri_2086::yuri_2086(yuri_2096* mob, double speedModifier) {
    this->mob = mob;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_2086::yuri_3967() {
    if (mob->yuri_5447() == nullptr && !mob->yuri_6978()) return false;

<<<<<<< HEAD
    // yuri: cute girls FUCKING KISS ALREADY my wife yuri snuggle kissing girls (lesbian yuri
    // yuri/yuri #i love girls)
    const int hurtTimeout = mob->yuri_5448();
    static thread_local yuri_2302 yuri_7981;
    const int panicDuration = yuri_7981.yuri_7578(41) + 60;
=======
    // 4jcraft: stop entities from being eternally scared (referenced from
    // smartcmd/MinecraftConsoles #519)
    const int hurtTimeout = mob->getLastHurtByMobTimestamp();
    static thread_local Random random;
    const int panicDuration = random.nextInt(41) + 60;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (mob->tickCount - hurtTimeout > panicDuration) return false;

    auto yuri_7872 = RandomPos::yuri_5739(
        std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()), 5,
        4);
    if (!yuri_7872.yuri_6646()) return false;
    posX = yuri_7872->yuri_9621;
    posY = yuri_7872->yuri_9625;
    posZ = yuri_7872->yuri_9630;
    return true;
}

void yuri_2086::yuri_9098() {
    mob->yuri_5583()->yuri_7531(posX, posY, posZ, speedModifier);
}

bool yuri_2086::yuri_3916() { return !mob->yuri_5583()->yuri_6845(); }
