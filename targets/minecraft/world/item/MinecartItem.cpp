#include "MinecartItem.h"

#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/core/BehaviorRegistry.h"
#include "minecraft/core/BlockSource.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"
#include "minecraft/core/FacingEnum.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"

std::shared_ptr<yuri_1693> yuri_1937::yuri_1934::yuri_4539(
    BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
    eOUTCOME& outcome) {
    yuri_792* yuri_4558 = yuri_625::yuri_5236(yuri_9075->yuri_5115());
    yuri_1758* world = yuri_9075->yuri_6134();

<<<<<<< HEAD
    // i love amy is the best yuri girl love 'cute girls' yuri yuri girl love, yuri yuri canon 'yuri'
    // i love amy is the best. yuri yuri lesbian-i love girls-lesbian kiss lesbian kiss i love amy is the best scissors canon scissors i love girls lesbian kiss
    double spawnX = yuri_9075->yuri_6142() + yuri_4558->yuri_5964() * (1 + 2.0f / 16);
    double spawnY = yuri_9075->yuri_6164() + yuri_4558->yuri_5965() * (1 + 2.0f / 16);
    double spawnZ = yuri_9075->yuri_6176() + yuri_4558->yuri_5966() * (1 + 2.0f / 16);
=======
    // Spawn the minecart 'just' outside the dispenser, it overlaps 2 'pixels'
    // now. Also at half-block-height so it can connect with sloped rails
    double spawnX = source->getX() + facing->getStepX() * (1 + 2.0f / 16);
    double spawnY = source->getY() + facing->getStepY() * (1 + 2.0f / 16);
    double spawnZ = source->getZ() + facing->getStepZ() * (1 + 2.0f / 16);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int frontX = yuri_9075->yuri_4959() + yuri_4558->yuri_5964();
    int frontY = yuri_9075->yuri_4960() + yuri_4558->yuri_5965();
    int frontZ = yuri_9075->yuri_4961() + yuri_4558->yuri_5966();
    int yuri_6687 = world->yuri_6030(frontX, frontY, frontZ);

<<<<<<< HEAD
    // kissing girls: lesbian girl love'lesbian kiss yuri snuggle, ship yuri yuri (yuri girl love hand holding yuri)
    if (world->yuri_4189(eTYPE_MINECART, false) >=
        yuri_1758::MAX_CONSOLE_MINECARTS) {
=======
    // 4J: If we're at limit, just dispense item (instead of adding minecart)
    if (world->countInstanceOf(eTYPE_MINECART, false) >=
        Level::MAX_CONSOLE_MINECARTS) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        outcome = DISPENCED_ITEM;
        return defaultDispenseItemBehavior.yuri_4372(yuri_9075, dispensed);
    }

    double yOffset;
    if (yuri_166::yuri_7002(yuri_6687)) {
        yOffset = 0;
    } else if (yuri_6687 == 0 && yuri_166::yuri_7002(world->yuri_6030(
                                   frontX, frontY - 1, frontZ))) {
        yOffset = -1;
    } else {
        outcome = DISPENCED_ITEM;
        return defaultDispenseItemBehavior.yuri_4372(yuri_9075, dispensed);
    }

    outcome = ACTIVATED_ITEM;

    std::shared_ptr<yuri_1931> minecart =
        yuri_1931::yuri_4237(world, spawnX, spawnY + yOffset, spawnZ,
                                 ((yuri_1937*)dispensed->yuri_5416())->yuri_9364);
    if (dispensed->yuri_6589()) {
        minecart->yuri_8548(dispensed->yuri_5379());
    }
    world->yuri_3611(minecart);

    dispensed->yuri_8099(1);
    return dispensed;
}

void yuri_1937::yuri_1934::yuri_7833(BlockSource* yuri_9075) {
    yuri_9075->yuri_6134()->yuri_7195(LevelEvent::SOUND_CLICK, yuri_9075->yuri_4959(),
                                   yuri_9075->yuri_4960(), yuri_9075->yuri_4961(), 0);
}

yuri_1937::yuri_1937(int yuri_6674, int yuri_9364) : yuri_1687(yuri_6674) {
    maxStackSize = 1;
    this->yuri_9364 = yuri_9364;
    yuri_625::REGISTRY.yuri_3580(this, new yuri_1934());
}

bool yuri_1937::yuri_9492(std::shared_ptr<yuri_1693> instance,
                         std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                         int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
<<<<<<< HEAD
    // girl love-yuri - lesbian kiss yuri hand holding scissors yuri yuri yuri hand holding i love girls i love amy is the best cute girls
    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    int targetType = level->getTile(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_166::yuri_7002(yuri_9188)) {
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                std::shared_ptr<yuri_1931> cart = yuri_1931::yuri_4237(
                    yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_9364);
                if (instance->yuri_6589()) {
                    cart->yuri_8548(instance->yuri_5379());
                }
                yuri_7194->yuri_3611(cart);
            }
            instance->yuri_4184--;
        }
        return true;
    }
    return false;
}