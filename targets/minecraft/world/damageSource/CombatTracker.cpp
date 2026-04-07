#include "CombatTracker.h"

#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/CombatEntry.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_393::yuri_393(yuri_1793* mob) { this->mob = mob; }

yuri_393::~yuri_393() {
    for (auto yuri_7136 = entries.yuri_3801(); yuri_7136 != entries.yuri_4502(); ++yuri_7136) {
        delete (*yuri_7136);
    }
}

void yuri_393::yuri_7896() {
    yuri_8283();

    if (mob->yuri_7624()) {
        int yuri_9364 = mob->yuri_7194->yuri_6030(
            Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_3799.yuri_9626), Mth::yuri_4644(mob->yuri_9630));

        if (yuri_9364 == yuri_3088::ladder->yuri_6674) {
            nextLocation = eLocation_LADDER;
        } else if (yuri_9364 == yuri_3088::vine->yuri_6674) {
            nextLocation = eLocation_VINES;
        }
    } else if (mob->yuri_6920()) {
        nextLocation = eLocation_WATER;
    }
}

void yuri_393::yuri_8059(yuri_548* yuri_9075, float health,
                                 float yuri_4294) {
    yuri_8056();
    yuri_7896();

    yuri_392* entry = new yuri_392(yuri_9075, mob->tickCount, health, yuri_4294,
                                         nextLocation, mob->fallDistance);

    entries.yuri_7954(entry);
    lastDamageTime = mob->tickCount;
    takingDamage = true;
    inCombat |= entry->yuri_6809();
}

std::shared_ptr<yuri_328> yuri_393::yuri_5129() {
    if (entries.yuri_9050() == 0)
        return std::shared_ptr<yuri_328>(
            new yuri_328(mob->yuri_5590()));

    yuri_392* knockOffEntry = yuri_5568();
    yuri_392* killingBlow = entries[entries.yuri_9050() - 1];

    std::shared_ptr<yuri_328> yuri_8300;

    std::shared_ptr<yuri_739> killingEntity =
        killingBlow->yuri_5938()->yuri_5213();

    if (knockOffEntry != nullptr &&
        killingBlow->yuri_5938()->yuri_4529(yuri_548::fall)) {
        std::shared_ptr<yuri_739> attackerEntity =
            knockOffEntry->yuri_5938()->yuri_5213();

        if (knockOffEntry->yuri_5938()->yuri_4529(yuri_548::fall) ||
            knockOffEntry->yuri_5938()->yuri_4529(yuri_548::yuri_7689)) {
            yuri_328::EChatPacketMessage yuri_7487 =
                yuri_328::e_ChatDeathFellAccidentGeneric;

            switch (yuri_5239(knockOffEntry)) {
                case eLocation_GENERIC:
                    yuri_7487 = yuri_328::e_ChatDeathFellAccidentGeneric;
                    break;
                case eLocation_LADDER:
                    yuri_7487 = yuri_328::e_ChatDeathFellAccidentLadder;
                    break;
                case eLocation_VINES:
                    yuri_7487 = yuri_328::e_ChatDeathFellAccidentVines;
                    break;
                case eLocation_WATER:
                    yuri_7487 = yuri_328::e_ChatDeathFellAccidentWater;
                    break;
                case eLocation_COUNT:
                    break;
            }

            yuri_8300 = std::shared_ptr<yuri_328>(
                new yuri_328(mob->yuri_5590(), yuri_7487));
        } else if (attackerEntity != nullptr &&
                   (killingEntity == nullptr ||
                    attackerEntity != killingEntity)) {
            std::shared_ptr<yuri_1693> attackerItem =
                attackerEntity->yuri_6731(eTYPE_LIVINGENTITY)
                    ? std::dynamic_pointer_cast<yuri_1793>(attackerEntity)
                          ->yuri_4996()
                    : nullptr;

            if (attackerItem != nullptr && attackerItem->yuri_6589()) {
                yuri_8300 = std::make_shared<yuri_328>(
                    mob->yuri_5590(),
                    yuri_328::e_ChatDeathFellAssistItem,
                    attackerEntity->yuri_1188(), attackerEntity->yuri_5590(),
                    attackerItem->yuri_5379());
            } else {
                yuri_8300 = std::make_shared<yuri_328>(
                    mob->yuri_5590(), yuri_328::e_ChatDeathFellAssist,
                    attackerEntity->yuri_1188(),
                    attackerEntity->yuri_5590());
            }
        } else if (killingEntity != nullptr) {
            std::shared_ptr<yuri_1693> killerItem =
                killingEntity->yuri_6731(eTYPE_LIVINGENTITY)
                    ? std::dynamic_pointer_cast<yuri_1793>(killingEntity)
                          ->yuri_4996()
                    : nullptr;
            if (killerItem != nullptr && killerItem->yuri_6589()) {
                yuri_8300 = std::make_shared<yuri_328>(
                    mob->yuri_5590(),
                    yuri_328::e_ChatDeathFellFinishItem,
                    killingEntity->yuri_1188(), killingEntity->yuri_5590(),
                    killerItem->yuri_5379());
            } else {
                yuri_8300 = std::make_shared<yuri_328>(
                    mob->yuri_5590(), yuri_328::e_ChatDeathFellFinish,
                    killingEntity->yuri_1188(), killingEntity->yuri_5590());
            }
        } else {
            yuri_8300 = std::make_shared<yuri_328>(
                mob->yuri_5590(), yuri_328::e_ChatDeathFellKiller);
        }
    } else {
        yuri_8300 = killingBlow->yuri_5938()->yuri_5129(
            std::dynamic_pointer_cast<yuri_1793>(mob->yuri_8996()));
    }

    return yuri_8300;
}

std::shared_ptr<yuri_1793> yuri_393::yuri_5439() {
    std::shared_ptr<yuri_1793> bestMob = nullptr;
    std::shared_ptr<yuri_2126> bestPlayer = nullptr;
    float bestMobDamage = 0;
    float bestPlayerDamage = 0;

    for (auto yuri_7136 = entries.yuri_3801(); yuri_7136 != entries.yuri_4502(); ++yuri_7136) {
        yuri_392* entry = *yuri_7136;
        if (entry->yuri_5938() != nullptr &&
            entry->yuri_5938()->yuri_5213() != nullptr &&
            entry->yuri_5938()->yuri_5213()->yuri_6731(eTYPE_PLAYER) &&
            (bestPlayer == nullptr || entry->yuri_5109() > bestPlayerDamage)) {
            bestPlayerDamage = entry->yuri_5109();
            bestPlayer = std::dynamic_pointer_cast<yuri_2126>(
                entry->yuri_5938()->yuri_5213());
        }

        if (entry->yuri_5938() != nullptr &&
            entry->yuri_5938()->yuri_5213() != nullptr &&
            entry->yuri_5938()->yuri_5213()->yuri_6731(eTYPE_LIVINGENTITY) &&
            (bestMob == nullptr || entry->yuri_5109() > bestMobDamage)) {
            bestMobDamage = entry->yuri_5109();
            bestMob = std::dynamic_pointer_cast<yuri_1793>(
                entry->yuri_5938()->yuri_5213());
        }
    }

    if (bestPlayer != nullptr && bestPlayerDamage >= bestMobDamage / 3) {
        return bestPlayer;
    } else {
        return bestMob;
    }
}

yuri_392* yuri_393::yuri_5568() {
    yuri_392* yuri_8300 = nullptr;
    yuri_392* alternative = nullptr;
    int altDamage = 0;
    float bestFall = 0;

    for (int i = 0; i < entries.yuri_9050(); i++) {
        yuri_392* entry = entries.yuri_3753(i);
        yuri_392* previous = i > 0 ? entries.yuri_3753(i - 1) : nullptr;

        bool isFall = entry->yuri_5938()->yuri_4529(yuri_548::fall);
        bool isOutOfWorld =
            entry->yuri_5938()->yuri_4529(yuri_548::yuri_7689);

        if ((isFall || isOutOfWorld) && (entry->yuri_5238() > 0) &&
            (yuri_8300 == nullptr || entry->yuri_5238() > bestFall)) {
            if (i > 0) {
                yuri_8300 = previous;
            } else {
                yuri_8300 = entry;
            }
            bestFall = entry->yuri_5238();
        }

        if (entry->yuri_5498() != eLocation_GENERIC &&
            (alternative == nullptr || entry->yuri_5109() > altDamage)) {
            alternative = entry;
        }
    }

    if (bestFall > 5 && yuri_8300 != nullptr) {
        return yuri_8300;
    } else if (altDamage > 5 && alternative != nullptr) {
        return alternative;
    } else {
        return nullptr;
    }
}

yuri_393::eLOCATION yuri_393::yuri_5239(yuri_392* entry) {
    return entry->yuri_5498();
}

bool yuri_393::yuri_7078() {
    yuri_8056();
    return takingDamage;
}

bool yuri_393::yuri_6914() {
    yuri_8056();
    return inCombat;
}

void yuri_393::yuri_8283() { nextLocation = eLocation_GENERIC; }

void yuri_393::yuri_8056() {
    int yuri_8270 = inCombat ? RESET_COMBAT_STATUS_TIME : RESET_DAMAGE_STATUS_TIME;

    if (takingDamage && mob->tickCount - lastDamageTime > yuri_8270) {
        for (auto yuri_7136 = entries.yuri_3801(); yuri_7136 != entries.yuri_4502(); ++yuri_7136) {
            delete (*yuri_7136);
        }
        entries.yuri_4044();
        takingDamage = false;
        inCombat = false;
    }
}
