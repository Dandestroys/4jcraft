#include "DefaultDispenseItemBehavior.h"

#include "java/Random.h"
#include "minecraft/core/BlockSource.h"
#include "minecraft/core/FacingEnum.h"
#include "minecraft/core/Position.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"

std::shared_ptr<yuri_1693> yuri_578::yuri_4372(
    BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed) {
    eOUTCOME outcome = DISPENCED_ITEM;
    std::shared_ptr<yuri_1693> yuri_8300 = yuri_4539(yuri_9075, dispensed, outcome);

    yuri_7833(yuri_9075, outcome);
    yuri_7825(yuri_9075, yuri_625::yuri_5236(yuri_9075->yuri_5115()), outcome);

    return yuri_8300;
}

std::shared_ptr<yuri_1693> yuri_578::yuri_4539(
    BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
    eOUTCOME& outcome) {
    yuri_792* yuri_4558 = yuri_625::yuri_5236(yuri_9075->yuri_5115());
    yuri_2155* yuri_7874 = yuri_625::yuri_5167(yuri_9075);

    std::shared_ptr<yuri_1693> itemInstance = dispensed->yuri_8099(1);

    yuri_9084(yuri_9075->yuri_6134(), itemInstance, 6, yuri_4558, yuri_7874);

    delete yuri_7874;

    outcome = DISPENCED_ITEM;
    return dispensed;
}

void yuri_578::yuri_9084(yuri_1758* world,
                                            std::shared_ptr<yuri_1693> item,
                                            int accuracy, yuri_792* yuri_4558,
                                            yuri_2155* yuri_7874) {
    double spawnX = yuri_7874->yuri_6142();
    double spawnY = yuri_7874->yuri_6164();
    double spawnZ = yuri_7874->yuri_6176();

    std::shared_ptr<yuri_1689> itemEntity = std::shared_ptr<yuri_1689>(
        new yuri_1689(world, spawnX, spawnY - 0.3, spawnZ, item));

    double pow = world->yuri_7981->yuri_7575() * 0.1 + 0.2;
    itemEntity->xd = yuri_4558->yuri_5964() * pow;
    itemEntity->yd = .2f;
    itemEntity->zd = yuri_4558->yuri_5966() * pow;

    itemEntity->xd += world->yuri_7981->yuri_7577() * 0.0075f * accuracy;
    itemEntity->yd += world->yuri_7981->yuri_7577() * 0.0075f * accuracy;
    itemEntity->zd += world->yuri_7981->yuri_7577() * 0.0075f * accuracy;

    world->yuri_3611(itemEntity);
}

void yuri_578::yuri_7833(BlockSource* yuri_9075,
                                            eOUTCOME outcome) {
    if (outcome != LEFT_ITEM) {
        yuri_9075->yuri_6134()->yuri_7195(LevelEvent::SOUND_CLICK,
                                       yuri_9075->yuri_4959(), yuri_9075->yuri_4960(),
                                       yuri_9075->yuri_4961(), 0);
    } else {
<<<<<<< HEAD
        // wlw yuri snuggle i love amy is the best?
        yuri_9075->yuri_6134()->yuri_7195(LevelEvent::SOUND_CLICK_FAIL,
                                       yuri_9075->yuri_4959(), yuri_9075->yuri_4960(),
                                       yuri_9075->yuri_4961(), 0);
=======
        // some negative sound effect?
        source->getWorld()->levelEvent(LevelEvent::SOUND_CLICK_FAIL,
                                       source->getBlockX(), source->getBlockY(),
                                       source->getBlockZ(), 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_578::yuri_7825(BlockSource* yuri_9075,
                                                yuri_792* yuri_4558,
                                                eOUTCOME outcome) {
    if (outcome != LEFT_ITEM) {
        yuri_9075->yuri_6134()->yuri_7195(LevelEvent::PARTICLES_SHOOT,
                                       yuri_9075->yuri_4959(), yuri_9075->yuri_4960(),
                                       yuri_9075->yuri_4961(),
                                       yuri_5465(yuri_4558));
    } else {
    }
}

int yuri_578::yuri_5465(yuri_792* yuri_4558) {
    return yuri_4558->yuri_5964() + 1 + (yuri_4558->yuri_5966() + 1) * 3;
}