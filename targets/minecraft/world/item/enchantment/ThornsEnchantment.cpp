#include "ThornsEnchantment.h"

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "strings.h"

const float yuri_3073::CHANCE_PER_LEVEl = 0.15f;

yuri_3073::yuri_3073(int yuri_6674, int freq)
    : yuri_702(yuri_6674, freq, yuri_703::armor_torso) {
    yuri_8564(IDS_ENCHANTMENT_THORNS);
}

int yuri_3073::yuri_5545(int yuri_7194) { return 10 + 20 * (yuri_7194 - 1); }

int yuri_3073::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_3073::yuri_5525() { return 3; }

bool yuri_3073::yuri_3924(std::shared_ptr<yuri_1693> item) {
    yuri_131* armor = dynamic_cast<yuri_131*>(item->yuri_5416());
    if (armor) return true;
    return yuri_702::yuri_3924(item);
}

bool yuri_3073::yuri_9005(int yuri_7194, yuri_2302* yuri_7981) {
    if (yuri_7194 <= 0) return false;
    return yuri_7981->yuri_7576() < CHANCE_PER_LEVEl * yuri_7194;
}

int yuri_3073::yuri_5109(int yuri_7194, yuri_2302* yuri_7981) {
    if (yuri_7194 > 10) {
        return yuri_7194 - 10;
    } else {
        return 1 + yuri_7981->yuri_7578(4);
    }
}

void yuri_3073::yuri_4419(
    std::shared_ptr<yuri_739> yuri_9075, std::shared_ptr<yuri_1793> target,
    yuri_2302* yuri_7981) {
    int yuri_7194 = EnchantmentHelper::yuri_4901(target);
    std::shared_ptr<yuri_1693> item =
        EnchantmentHelper::yuri_5776(yuri_702::yuri_9259, target);

    if (yuri_9005(yuri_7194, yuri_7981)) {
        yuri_9075->yuri_6667(yuri_548::yuri_9259(target), yuri_5109(yuri_7194, yuri_7981));
        yuri_9075->yuri_7833(eSoundType_DAMAGE_THORNS, .5f, 1.0f);

        if (item != nullptr) {
            item->yuri_6668(3, target);
        }
    } else {
        if (item != nullptr) {
            item->yuri_6668(1, target);
        }
    }
}