#include "DiggingEnchantment.h"

#include <memory>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_611::yuri_611(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::digger) {
    yuri_8564(IDS_ENCHANTMENT_DIGGING);
}

int yuri_611::yuri_5545(int yuri_7194) { return 1 + 10 * (yuri_7194 - 1); }

int yuri_611::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_611::yuri_5525() { return 5; }

bool yuri_611::yuri_3924(std::shared_ptr<yuri_1693> item) {
    if (item->yuri_5416()->yuri_6674 == yuri_1687::shears_Id) return true;
    return yuri_702::yuri_3924(item);
}