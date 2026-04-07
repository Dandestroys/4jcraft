#include "LootBonusEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_1843::yuri_1843(int yuri_6674, int yuri_4681,
                                           const yuri_703* cat)
    : yuri_702(yuri_6674, yuri_4681, cat) {
    yuri_8564(IDS_ENCHANTMENT_LOOT_BONUS);
    if (cat == yuri_703::digger) {
        yuri_8564(IDS_ENCHANTMENT_LOOT_BONUS_DIGGER);
    }
}

int yuri_1843::yuri_5545(int yuri_7194) { return 15 + (yuri_7194 - 1) * 9; }

int yuri_1843::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_1843::yuri_5525() { return 3; }

bool yuri_1843::yuri_6812(yuri_702* other) const {
    return yuri_702::yuri_6812(other) && other->yuri_6674 != untouching->yuri_6674;
}