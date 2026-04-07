#include "BookItem.h"

#include <memory>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_215::yuri_215(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_215::yuri_6854(std::shared_ptr<yuri_1693> itemInstance) {
    return itemInstance->yuri_4184 == 1;
}

int yuri_215::yuri_5203() { return 1; }