#include "MilkBucketItem.h"

#include <memory>

#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_1924::yuri_1924(int yuri_6674) : yuri_1687(yuri_6674) { yuri_8725(1); }

std::shared_ptr<yuri_1693> yuri_1924::yuri_9497(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7839->abilities.instabuild) instance->yuri_4184--;

    if (!yuri_7194->yuri_6802) {
        yuri_7839->yuri_8100();
    }

    if (instance->yuri_4184 <= 0) {
        return std::shared_ptr<yuri_1693>(
            new yuri_1693(yuri_1687::bucket_empty));
    }
    return instance;
}

int yuri_1924::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return DRINK_DURATION;
}

UseAnim yuri_1924::yuri_6087(
    std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_drink;
}

std::shared_ptr<yuri_1693> yuri_1924::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_9111(instance, yuri_6090(instance));
    return instance;
}