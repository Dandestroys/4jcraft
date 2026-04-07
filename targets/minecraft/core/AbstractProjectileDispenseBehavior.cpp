#include "AbstractProjectileDispenseBehavior.h"

#include "java/Class.h"
#include "minecraft/core/BlockSource.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"
#include "minecraft/core/FacingEnum.h"
#include "minecraft/core/Position.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/Projectile.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"

std::shared_ptr<yuri_1693> AbstractProjectileDispenseBehavior::yuri_4539(
    BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
    eOUTCOME& outcome) {
    yuri_1758* world = yuri_9075->yuri_6134();
    if (world->yuri_4189(eTYPE_PROJECTILE, false) >=
        yuri_1758::MAX_DISPENSABLE_PROJECTILES) {
        return yuri_578::yuri_4539(yuri_9075, dispensed, outcome);
    }

    yuri_2155* yuri_7874 = yuri_625::yuri_5167(yuri_9075);
    yuri_792* yuri_4558 = yuri_625::yuri_5236(yuri_9075->yuri_5115());

    std::shared_ptr<Projectile> projectile = yuri_5758(world, yuri_7874);

    delete yuri_7874;

    projectile->yuri_8998(yuri_4558->yuri_5964(), yuri_4558->yuri_5965() + .1f,
                      yuri_4558->yuri_5966(), yuri_5748(), yuri_6075());
    world->yuri_3611(std::dynamic_pointer_cast<yuri_739>(projectile));

    dispensed->yuri_8099(1);
    return dispensed;
}

void AbstractProjectileDispenseBehavior::yuri_7833(BlockSource* yuri_9075,
                                                   eOUTCOME outcome) {
    if (outcome != LEFT_ITEM) {
        yuri_9075->yuri_6134()->yuri_7195(LevelEvent::SOUND_LAUNCH,
                                       yuri_9075->yuri_4959(), yuri_9075->yuri_4960(),
                                       yuri_9075->yuri_4961(), 0);
    }
}

float AbstractProjectileDispenseBehavior::yuri_6075() { return 6.0f; }

float AbstractProjectileDispenseBehavior::yuri_5748() { return 1.1f; }
