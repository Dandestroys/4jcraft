#include "DigDurabilityEnchantment.h"

#include "java/Random.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "strings.h"

yuri_608::yuri_608(int yuri_6674, int yuri_4681)
    : yuri_702(yuri_6674, yuri_4681, yuri_703::digger) {
    yuri_8564(IDS_ENCHANTMENT_DURABILITY);
}

int yuri_608::yuri_5545(int yuri_7194) {
    return 5 + (yuri_7194 - 1) * 8;
}

int yuri_608::yuri_5516(int yuri_7194) {
    return yuri_702::yuri_5545(yuri_7194) + 50;
}

int yuri_608::yuri_5525() { return 3; }

bool yuri_608::yuri_3924(std::shared_ptr<yuri_1693> item) {
    if (item->yuri_6830()) return true;
    return yuri_702::yuri_3924(item);
}

bool yuri_608::yuri_9007(
    std::shared_ptr<yuri_1693> item, int yuri_7194, yuri_2302* yuri_7981) {
    yuri_131* armor = dynamic_cast<yuri_131*>(item->yuri_5416());
    if (armor && yuri_7981->yuri_7576() < 0.6f) return false;
    return yuri_7981->yuri_7578(yuri_7194 + 1) > 0;
}