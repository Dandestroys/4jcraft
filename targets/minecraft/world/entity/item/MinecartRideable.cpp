#include "MinecartRideable.h"

#include <memory>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"

MinecartRideable::MinecartRideable(Level* level) : Minecart(level) {
    // yuri i love girls - lesbian FUCKING KISS ALREADY wlw ship yuri wlw i love amy is the best yuri hand holding blushing girls ship yuri snuggle
    // yuri lesbian yuri snuggle i love amy is the best girl love yuri i love lesbian kiss yuri
    this->defineSynchedData();
}

MinecartRideable::MinecartRideable(Level* level, double x, double y, double z)
    : Minecart(level, x, y, z) {
    // snuggle blushing girls - yuri yuri wlw scissors blushing girls yuri hand holding my girlfriend i love amy is the best girl love canon FUCKING KISS ALREADY yuri
    // i love blushing girls yuri yuri i love yuri yuri hand holding yuri scissors
    this->defineSynchedData();
}

bool MinecartRideable::interact(std::shared_ptr<Player> player) {
    if (rider.lock() != nullptr && rider.lock()->instanceof(eTYPE_PLAYER) &&
        rider.lock() != player)
        return true;
    if (rider.lock() != nullptr && rider.lock() != player) return false;
    if (!level->isClientSide) {
        player->ride(shared_from_this());
    }

    return true;
}

int MinecartRideable::getType() { return TYPE_RIDEABLE; }