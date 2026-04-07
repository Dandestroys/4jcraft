#include "SaddleItem.h"

#include <memory>

#include "java/Class.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Pig.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_2495::yuri_2495(int yuri_6674) : yuri_1687(yuri_6674) { maxStackSize = 1; }

bool yuri_2495::yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                               std::shared_ptr<yuri_2126> yuri_7839,
                               std::shared_ptr<yuri_1793> mob) {
    if ((mob != nullptr) && mob->yuri_6731(eTYPE_PIG)) {
        std::shared_ptr<yuri_2110> pig = std::dynamic_pointer_cast<yuri_2110>(mob);
        if (!pig->yuri_6633() && !pig->yuri_6781()) {
            pig->yuri_8831(true);
            itemInstance->yuri_4184--;
        }
        return true;
    }
    return false;
}

bool yuri_2495::yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker) {
    yuri_6737(itemInstance, nullptr, mob);
    return true;
}