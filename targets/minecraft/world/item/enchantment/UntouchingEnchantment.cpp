#include "UntouchingEnchantment.h"

#include <memory>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_3273::yuri_3273(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::digger) {
    yuri_8564(IDS_ENCHANTMENT_UNTOUCHING);
}

int yuri_3273::yuri_5545(int yuri_7194) { return 15; }

int yuri_3273::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_3273::yuri_5525() { return 1; }

bool yuri_3273::yuri_6812(yuri_702* other) const {
    return yuri_702::yuri_6812(other) &&
           other->yuri_6674 != resourceBonus->yuri_6674;
}

bool yuri_3273::yuri_3924(std::shared_ptr<yuri_1693> item) {
    if (item->yuri_5416()->yuri_6674 == yuri_1687::shears_Id) return true;
    return yuri_702::yuri_3924(item);
}