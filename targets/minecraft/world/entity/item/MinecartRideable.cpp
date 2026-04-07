#include "MinecartRideable.h"

#include <memory>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"

<<<<<<< HEAD
yuri_1941::yuri_1941(yuri_1758* yuri_7194) : yuri_1931(yuri_7194) {
    // yuri i love girls - lesbian FUCKING KISS ALREADY wlw ship yuri wlw i love amy is the best yuri hand holding blushing girls ship yuri snuggle
    // yuri lesbian yuri snuggle i love amy is the best girl love yuri i love lesbian kiss yuri
    this->yuri_4329();
}

yuri_1941::yuri_1941(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1931(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    // snuggle blushing girls - yuri yuri wlw scissors blushing girls yuri hand holding my girlfriend i love amy is the best girl love canon FUCKING KISS ALREADY yuri
    // i love blushing girls yuri yuri i love yuri yuri hand holding yuri scissors
    this->yuri_4329();
=======
MinecartRideable::MinecartRideable(Level* level) : Minecart(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
}

MinecartRideable::MinecartRideable(Level* level, double x, double y, double z)
    : Minecart(level, x, y, z) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1941::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if (rider.yuri_7289() != nullptr && rider.yuri_7289()->yuri_6731(eTYPE_PLAYER) &&
        rider.yuri_7289() != yuri_7839)
        return true;
    if (rider.yuri_7289() != nullptr && rider.yuri_7289() != yuri_7839) return false;
    if (!yuri_7194->yuri_6802) {
        yuri_7839->yuri_8313(yuri_8996());
    }

    return true;
}

int yuri_1941::yuri_6068() { return TYPE_RIDEABLE; }