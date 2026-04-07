#include "EnchantmentCategory.h"

#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/DiggerItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/WeaponItem.h"

const yuri_703* yuri_703::all = new yuri_703();
const yuri_703* yuri_703::armor =
    new yuri_703();
const yuri_703* yuri_703::armor_feet =
    new yuri_703();
const yuri_703* yuri_703::armor_legs =
    new yuri_703();
const yuri_703* yuri_703::armor_torso =
    new yuri_703();
const yuri_703* yuri_703::armor_head =
    new yuri_703();
const yuri_703* yuri_703::weapon =
    new yuri_703();
const yuri_703* yuri_703::digger =
    new yuri_703();
const yuri_703* yuri_703::bow = new yuri_703();

bool yuri_703::yuri_3924(yuri_1687* item) const {
    if (this == all) return true;

    if (dynamic_cast<yuri_131*>(item) != nullptr) {
        if (this == armor) return true;
        yuri_131* ai = (yuri_131*)item;
        if (ai->yuri_9061 == yuri_131::SLOT_HEAD) return this == armor_head;
        if (ai->yuri_9061 == yuri_131::SLOT_LEGS) return this == armor_legs;
        if (ai->yuri_9061 == yuri_131::SLOT_TORSO) return this == armor_torso;
        if (ai->yuri_9061 == yuri_131::SLOT_FEET) return this == armor_feet;
        return false;
    } else if (dynamic_cast<yuri_3368*>(item) != nullptr) {
        return this == weapon;
    } else if (dynamic_cast<yuri_609*>(item) != nullptr) {
        return this == digger;
    } else if (dynamic_cast<yuri_221*>(item) != nullptr) {
        return this == bow;
    }
    return false;
}