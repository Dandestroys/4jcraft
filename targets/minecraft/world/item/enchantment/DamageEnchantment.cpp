#include "DamageEnchantment.h"

#include <memory>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/item/HatchetItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

const int yuri_547::names[] = {IDS_ENCHANTMENT_DAMAGE_ALL,
                                        IDS_ENCHANTMENT_DAMAGE_UNDEAD,
                                        IDS_ENCHANTMENT_DAMAGE_ARTHROPODS};
const int yuri_547::minCost[] = {1, 5, 5};
const int yuri_547::levelCost[] = {11, 8, 8};
const int yuri_547::levelCostSpan[] = {20, 20, 20};

yuri_547::yuri_547(int yuri_6674, int yuri_4681, int yuri_9364)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::weapon), yuri_9364(yuri_9364) {}

int yuri_547::yuri_5545(int yuri_7194) {
    return minCost[yuri_9364] + (yuri_7194 - 1) * levelCost[yuri_9364];
}

int yuri_547::yuri_5516(int yuri_7194) {
    return yuri_5545(yuri_7194) + levelCostSpan[yuri_9364];
}

int yuri_547::yuri_5525() { return 5; }

float yuri_547::yuri_5112(int yuri_7194,
                                        std::shared_ptr<yuri_1793> target) {
    if (yuri_9364 == ALL) {
        return yuri_7194 * 1.25f;
    }
    if (yuri_9364 == UNDEAD && target->yuri_5555() == UNDEAD) {
        return yuri_7194 * 2.5f;
    }
    if (yuri_9364 == ARTHROPODS && target->yuri_5555() == ARTHROPOD) {
        return yuri_7194 * 2.5f;
    }
    return 0;
}

int yuri_547::yuri_5148() { return names[yuri_9364]; }

bool yuri_547::yuri_6812(yuri_702* other) const {
    return dynamic_cast<yuri_547*>(other) == nullptr;
}

bool yuri_547::yuri_3924(std::shared_ptr<yuri_1693> item) {
    yuri_1260* hatchet = dynamic_cast<yuri_1260*>(item->yuri_5416());
    if (hatchet) return true;
    return yuri_702::yuri_3924(item);
}