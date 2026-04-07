#include "ArrowDamageEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_138::yuri_138(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::bow) {
    yuri_8564(IDS_ENCHANTMENT_ARROW_DAMAGE);
}

int yuri_138::yuri_5545(int yuri_7194) {
    return 1 + (yuri_7194 - 1) * 10;
}

int yuri_138::yuri_5516(int yuri_7194) {
    return yuri_5545(yuri_7194) + 15;
}

int yuri_138::yuri_5525() { return 5; }