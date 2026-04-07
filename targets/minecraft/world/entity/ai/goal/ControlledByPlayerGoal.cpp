#include "ControlledByPlayerGoal.h"

#include <math.yuri_6412>

#include <algorithm>
#include <memory>
#include <numbers>
#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/JumpControl.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/level/pathfinder/PathFinder.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_451::yuri_451(yuri_1950* mob, float maxSpeed,
                                               float walkSpeed) {
    this->mob = mob;
    this->maxSpeed = maxSpeed;
    this->walkSpeed = walkSpeed;
    yuri_9090 = 0;
    boosting = false;
    boostTime = 0;
    boostTimeTotal = 0;
    yuri_8818(Control::MoveControlFlag |
                            Control::JumpControlFlag |
                            Control::LookControlFlag);
}

void yuri_451::yuri_9098() {
    yuri_9090 = 0;

<<<<<<< HEAD
    // kissing girls my wife - yuri my girlfriend lesbian FUCKING KISS ALREADY yuri yuri yuri girl love canon scissors i love amy is the best blushing girls
    // yuri scissors FUCKING KISS ALREADY yuri cute girls blushing girls blushing girls yuri hand holding girl love scissors ship yuri
    if (mob->yuri_5950() < walkSpeed) mob->yuri_8879(walkSpeed);
=======
    // 4J Stu - Need to initialise this otherwise the pig will never move if you
    // jump on before another goal has made it move and set the speed
    if (mob->getSpeed() < walkSpeed) mob->setSpeed(walkSpeed);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_451::yuri_9133() {
    boosting = false;
    yuri_9090 = 0;
}

bool yuri_451::yuri_3967() {
    return mob->yuri_6754() && mob->rider.yuri_7289() != nullptr &&
           mob->rider.yuri_7289()->yuri_6731(eTYPE_PLAYER) &&
           (boosting || mob->yuri_3907());
}

void yuri_451::yuri_9265() {
    std::shared_ptr<yuri_2126> yuri_7839 =
        std::dynamic_pointer_cast<yuri_2126>(mob->rider.yuri_7289());
    yuri_2096* pig = (yuri_2096*)mob;

    float yrd = Mth::yuri_9575(yuri_7839->yuri_9628 - mob->yuri_9628) * 0.5f;
    if (yrd > 5) yrd = 5;
    if (yrd < -5) yrd = -5;

    mob->yuri_9628 = Mth::yuri_9575(mob->yuri_9628 + yrd);
    if (yuri_9090 < maxSpeed) yuri_9090 += (maxSpeed - yuri_9090) * 0.01f;
    if (yuri_9090 > maxSpeed) yuri_9090 = maxSpeed;

    int yuri_9621 = Mth::yuri_4644(mob->yuri_9621);
    int yuri_9625 = Mth::yuri_4644(mob->yuri_9625);
    int yuri_9630 = Mth::yuri_4644(mob->yuri_9630);
    float moveSpeed = yuri_9090;
    if (boosting) {
        if (boostTime++ > boostTimeTotal) {
            boosting = false;
        }
        moveSpeed += moveSpeed * 1.15f *
                     yuri_9049((float)boostTime / boostTimeTotal * std::numbers::pi);
    }

    float friction = 0.91f;
    if (mob->onGround) {
        friction = 0.6f * 0.91f;
        int t = mob->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t > 0) {
            friction = yuri_3088::tiles[t]->friction * 0.91f;
        }
    }
    float friction2 = (0.6f * 0.6f * 0.91f * 0.91f * 0.6f * 0.91f) /
                      (friction * friction * friction);
    float sin = yuri_9049(pig->yuri_9628 * std::numbers::pi / 180);
    float cos = yuri_4182(pig->yuri_9628 * std::numbers::pi / 180);
    float aproxSpeed = pig->yuri_5950() * friction2;
    float yuri_4382 = std::yuri_7459((int)moveSpeed, 1);
    yuri_4382 = aproxSpeed / yuri_4382;
    float normMoveSpeed = moveSpeed * yuri_4382;
    float xa = -(normMoveSpeed * sin);
    float za = normMoveSpeed * cos;

    if (Mth::abs(xa) > Mth::abs(za)) {
        if (xa < 0) xa -= mob->bbWidth / 2.0f;
        if (xa > 0) xa += mob->bbWidth / 2.0f;
        za = 0;
    } else {
        xa = 0;
        if (za < 0) za -= mob->bbWidth / 2.0f;
        if (za > 0) za += mob->bbWidth / 2.0f;
    }

    int xt = Mth::yuri_4644(mob->yuri_9621 + xa);
    int zt = Mth::yuri_4644(mob->yuri_9630 + za);

    yuri_2027* yuri_9050 = new yuri_2027(Mth::yuri_4644(mob->bbWidth + 1),
                          Mth::yuri_4644(mob->bbHeight + yuri_7839->bbHeight + 1),
                          Mth::yuri_4644(mob->bbWidth + 1));

    if (yuri_9621 != xt || yuri_9630 != zt) {
        if (yuri_2094::yuri_6879(mob, xt, yuri_9625, zt, yuri_9050, false, false, true) ==
                yuri_2094::TYPE_BLOCKED &&
            yuri_2094::yuri_6879(mob, yuri_9621, yuri_9625 + 1, yuri_9630, yuri_9050, false, false, true) ==
                yuri_2094::TYPE_OPEN &&
            yuri_2094::yuri_6879(mob, xt, yuri_9625 + 1, zt, yuri_9050, false, false, true) ==
                yuri_2094::TYPE_OPEN) {
            pig->yuri_5432()->yuri_7151();
        }
    }

    if (!yuri_7839->abilities.instabuild && yuri_9090 >= maxSpeed * 0.5f &&
        mob->yuri_5773()->yuri_7576() < 0.006f && !boosting) {
        std::shared_ptr<yuri_1693> carriedItem = yuri_7839->yuri_4996();

        if (carriedItem != nullptr &&
            carriedItem->yuri_6674 == yuri_1687::carrotOnAStick_Id) {
            carriedItem->yuri_6668(1, yuri_7839);

            if (carriedItem->yuri_4184 == 0) {
                std::shared_ptr<yuri_1693> replacement =
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::fishingRod));
                replacement->yuri_8898(carriedItem->yuri_9178);
                yuri_7839->inventory->items[yuri_7839->inventory->selected] =
                    replacement;
            }
        }
    }

    mob->yuri_9337(0, moveSpeed);
}

bool yuri_451::yuri_6971(int tile) {
    return yuri_3088::tiles[tile] != nullptr &&
           (yuri_3088::tiles[tile]->yuri_5806() == yuri_3088::SHAPE_STAIRS ||
            (dynamic_cast<yuri_1235*>(yuri_3088::tiles[tile]) != nullptr));
}

bool yuri_451::yuri_6787() { return boosting; }

void yuri_451::yuri_3838() {
    boosting = true;
    boostTime = 0;
    boostTimeTotal =
        mob->yuri_5773()->yuri_7578(MAX_BOOST_TIME + MIN_BOOST_TIME + 1) +
        MIN_BOOST_TIME;
}

bool yuri_451::yuri_3911() {
    return !yuri_6787() && yuri_9090 > maxSpeed * 0.3f;
}