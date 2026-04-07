#include "OxygenEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_2071::yuri_2071(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::armor_head) {
    yuri_8564(IDS_ENCHANTMENT_OXYGEN);
}

int yuri_2071::yuri_5545(int yuri_7194) { return 10 * yuri_7194; }

int yuri_2071::yuri_5516(int yuri_7194) { return yuri_5545(yuri_7194) + 30; }

int yuri_2071::yuri_5525() { return 3; }