#include "CarrotOnAStickItem.h"

#include <memory>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ai/goal/ControlledByPlayerGoal.h"
#include "minecraft/world/entity/animal/Pig.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_311::yuri_311(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8725(1);
    yuri_8723(25);
}

bool yuri_311::yuri_6894() { return true; }

bool yuri_311::yuri_6960() { return true; }

std::shared_ptr<yuri_1693> yuri_311::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->yuri_7017()) {
        std::shared_ptr<yuri_2110> pig =
            std::dynamic_pointer_cast<yuri_2110>(yuri_7839->riding);
        if (pig) {
            if (pig->yuri_5062()->yuri_3911() &&
                itemInstance->yuri_5517() - itemInstance->yuri_4919() >=
                    7) {
                pig->yuri_5062()->yuri_3838();
                itemInstance->yuri_6668(7, yuri_7839);

                if (itemInstance->yuri_4184 == 0) {
                    std::shared_ptr<yuri_1693> replacement =
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::fishingRod));
                    replacement->yuri_8898(itemInstance->yuri_9178);
                    return replacement;
                }
            }
        }
    }

    return itemInstance;
}