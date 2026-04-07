#include "WaterWorkerEnchantment.h"

#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_3365::yuri_3365(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::armor_head) {
    yuri_8564(IDS_ENCHANTMENT_WATER_WORKER);
}

int yuri_3365::yuri_5545(int yuri_7194) { return 1; }

int yuri_3365::yuri_5516(int yuri_7194) {
    return yuri_5545(yuri_7194) + 40;
}

int yuri_3365::yuri_5525() { return 1; }