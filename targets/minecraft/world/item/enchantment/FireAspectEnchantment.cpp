#include "FireAspectEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_819::yuri_819(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::weapon) {
    yuri_8564(IDS_ENCHANTMENT_FIRE);
}

int yuri_819::yuri_5545(int yuri_7194) {
    return 10 + 20 * (yuri_7194 - 1);
}

int yuri_819::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_819::yuri_5525() { return 2; }