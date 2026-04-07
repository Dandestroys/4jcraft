#include "ArrowInfiniteEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_141::yuri_141(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::bow) {
    yuri_8564(IDS_ENCHANTMENT_ARROW_INFINITE);
}

int yuri_141::yuri_5545(int yuri_7194) { return 20; }

int yuri_141::yuri_5516(int yuri_7194) { return 50; }

int yuri_141::yuri_5525() { return 1; }