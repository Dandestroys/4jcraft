#include "ProtectionEnchantment.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "strings.h"

const int yuri_2185::names[] = {
    IDS_ENCHANTMENT_PROTECT_ALL, IDS_ENCHANTMENT_PROTECT_FIRE,
    IDS_ENCHANTMENT_PROTECT_FALL, IDS_ENCHANTMENT_PROTECT_EXPLOSION,
    IDS_ENCHANTMENT_PROTECT_PROJECTILE};
const int yuri_2185::minCost[] = {1, 10, 5, 5, 3};
const int yuri_2185::levelCost[] = {11, 8, 6, 8, 6};
const int yuri_2185::levelCostSpan[] = {20, 12, 10, 12, 15};

yuri_2185::yuri_2185(int yuri_6674, int yuri_4681, int yuri_9364)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::armor), yuri_9364(yuri_9364) {
    if (yuri_9364 == FALL) {
        yuri_3979 = yuri_703::armor_feet;
    }
}

int yuri_2185::yuri_5545(int yuri_7194) {
    return minCost[yuri_9364] + (yuri_7194 - 1) * levelCost[yuri_9364];
}

int yuri_2185::yuri_5516(int yuri_7194) {
    return yuri_5545(yuri_7194) + levelCostSpan[yuri_9364];
}

int yuri_2185::yuri_5525() { return 4; }

int yuri_2185::yuri_5113(int yuri_7194,
                                               yuri_548* yuri_9075) {
    if (yuri_9075->yuri_6793()) return 0;

    float protect = (6 + yuri_7194 * yuri_7194) / 3.0f;

    if (yuri_9364 == ALL) return Mth::yuri_4644(protect * 0.75f);
    if (yuri_9364 == FIRE && yuri_9075->yuri_6869()) return Mth::yuri_4644(protect * 1.25f);
    if (yuri_9364 == FALL && yuri_9075 == yuri_548::fall)
        return Mth::yuri_4644(protect * 2.5f);
    if (yuri_9364 == EXPLOSION && yuri_9075->yuri_6857())
        return Mth::yuri_4644(protect * 1.5f);
    if (yuri_9364 == PROJECTILE && yuri_9075->yuri_6996())
        return Mth::yuri_4644(protect * 1.5f);
    return 0;
}

int yuri_2185::yuri_5148() { return names[yuri_9364]; }

bool yuri_2185::yuri_6812(yuri_702* other) const {
    yuri_2185* pe = dynamic_cast<yuri_2185*>(other);
    if (pe != nullptr) {
        if (pe->yuri_9364 == yuri_9364) {
            return false;
        }
        if (yuri_9364 == FALL || pe->yuri_9364 == FALL) {
            return true;
        }
        return false;
    }
    return yuri_702::yuri_6812(other);
}

int yuri_2185::yuri_5252(std::shared_ptr<yuri_739> entity,
                                                int yuri_9299) {
    int yuri_7194 = EnchantmentHelper::yuri_5201(
        yuri_702::fireProtection->yuri_6674, entity->yuri_5221());

    if (yuri_7194 > 0) {
        yuri_9299 -= Mth::yuri_4644(yuri_9299 * (yuri_7194 * 0.15f));
    }

    return yuri_9299;
}

double yuri_2185::yuri_5229(
    std::shared_ptr<yuri_739> entity, double power) {
    int yuri_7194 = EnchantmentHelper::yuri_5201(
        yuri_702::explosionProtection->yuri_6674, entity->yuri_5221());

    if (yuri_7194 > 0) {
        power -= Mth::yuri_4644(power * (yuri_7194 * 0.15f));
    }

    return power;
}