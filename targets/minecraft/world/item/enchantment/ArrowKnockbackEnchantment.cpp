#include "ArrowKnockbackEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_142::yuri_142(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::bow) {
    yuri_8564(IDS_ENCHANTMENT_ARROW_KNOCKBACK);
}

int yuri_142::yuri_5545(int yuri_7194) {
    return 12 + (yuri_7194 - 1) * 20;
}

int yuri_142::yuri_5516(int yuri_7194) {
    return yuri_5545(yuri_7194) + 25;
}

int yuri_142::yuri_5525() { return 2; }