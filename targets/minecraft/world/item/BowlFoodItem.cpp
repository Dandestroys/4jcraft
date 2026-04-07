#include "BowlFoodItem.h"

#include <memory>

#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_222::yuri_222(int yuri_6674, int yuri_7602)
    : yuri_862(yuri_6674, yuri_7602, false) {
    yuri_8725(1);
}

std::shared_ptr<yuri_1693> yuri_222::yuri_9497(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_862::yuri_9497(instance, yuri_7194, yuri_7839);

    return std::make_shared<yuri_1693>(yuri_1687::bowl);
}