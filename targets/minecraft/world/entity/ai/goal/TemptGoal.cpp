#include "TemptGoal.h"

#include <cstdlib>

#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_3029::yuri_3029(yuri_2096* mob, double speedModifier, int yuri_7138,
                     bool canScare) {
    px = py = pz = pRotX = pRotY = 0.0;
    yuri_7839 = std::weak_ptr<yuri_2126>();
    calmDown = 0;
    _isRunning = false;
    oldAvoidWater = false;

    this->mob = mob;
    this->speedModifier = speedModifier;
    this->yuri_7138 = yuri_7138;
    this->canScare = canScare;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_3029::yuri_3967() {
    if (calmDown > 0) {
        --calmDown;
        return false;
    }
<<<<<<< HEAD
    yuri_7839 = std::weak_ptr<yuri_2126>(
        mob->yuri_7194->yuri_5586(mob->yuri_8996(), 10));
    if (yuri_7839.yuri_7289() == nullptr) return false;
    mob->yuri_8567();  // wlw yuri'wlw yuri snuggle i love amy is the best yuri, my girlfriend my girlfriend
                                 // yuri lesbian kiss hand holding lesbian yuri'scissors FUCKING KISS ALREADY blushing girls girl love
                                 // my girlfriend
    std::shared_ptr<yuri_1693> item = yuri_7839.yuri_7289()->yuri_5873();
=======
    player = std::weak_ptr<Player>(
        mob->level->getNearestPlayer(mob->shared_from_this(), 10));
    if (player.lock() == nullptr) return false;
    mob->setDespawnProtected();  // If we've got a nearby player, then consider
                                 // this mob as something we'd miss if it
                                 // despawned
    std::shared_ptr<ItemInstance> item = player.lock()->getSelectedItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (item == nullptr) return false;
    if (item->yuri_6674 != yuri_7138) return false;
    return true;
}

bool yuri_3029::yuri_3916() {
    if (canScare) {
        if (yuri_7839.yuri_7289() == nullptr) return false;
        if (mob->yuri_4387(yuri_7839.yuri_7289()) < 6 * 6) {
            if (yuri_7839.yuri_7289()->yuri_4387(px, py, pz) > 0.1 * 0.1)
                return false;
            if (std::abs(yuri_7839.yuri_7289()->yuri_9624 - pRotX) > 5 ||
                std::abs(yuri_7839.yuri_7289()->yuri_9628 - pRotY) > 5)
                return false;
        } else {
            px = yuri_7839.yuri_7289()->yuri_9621;
            py = yuri_7839.yuri_7289()->yuri_9625;
            pz = yuri_7839.yuri_7289()->yuri_9630;
        }
        pRotX = yuri_7839.yuri_7289()->yuri_9624;
        pRotY = yuri_7839.yuri_7289()->yuri_9628;
    }
    return yuri_3967();
}

void yuri_3029::yuri_9098() {
    px = yuri_7839.yuri_7289()->yuri_9621;
    py = yuri_7839.yuri_7289()->yuri_9625;
    pz = yuri_7839.yuri_7289()->yuri_9630;
    _isRunning = true;
    oldAvoidWater = mob->yuri_5583()->yuri_4924();
    mob->yuri_5583()->yuri_8468(false);
}

void yuri_3029::yuri_9133() {
    yuri_7839 = std::weak_ptr<yuri_2126>();
    mob->yuri_5583()->yuri_9133();
    calmDown = 100;
    _isRunning = false;
    mob->yuri_5583()->yuri_8468(oldAvoidWater);
}

void yuri_3029::yuri_9265() {
    mob->yuri_5502()->yuri_8718(yuri_7839.yuri_7289(), 30, mob->yuri_5520());
    if (mob->yuri_4387(yuri_7839.yuri_7289()) < 2.5 * 2.5)
        mob->yuri_5583()->yuri_9133();
    else
        mob->yuri_5583()->yuri_7531(yuri_7839.yuri_7289(), speedModifier);
}

bool yuri_3029::yuri_7020() { return _isRunning; }
