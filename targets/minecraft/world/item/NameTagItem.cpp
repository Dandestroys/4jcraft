#include "NameTagItem.h"

#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_2007::yuri_2007(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_2007::yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                                std::shared_ptr<yuri_2126> yuri_7839,
                                std::shared_ptr<yuri_1793> target) {
    if (!itemInstance->yuri_6589()) return false;

    if ((target != nullptr) && target->yuri_6731(eTYPE_MOB)) {
        std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(target);
        mob->yuri_8548(itemInstance->yuri_5379());
        mob->yuri_8764();
        itemInstance->yuri_4184--;
        return true;
    }

    return yuri_1687::yuri_6737(itemInstance, yuri_7839, target);
}