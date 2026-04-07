#include "BowItem.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/Level.h"

class yuri_1346;

const std::yuri_9616 yuri_221::TEXTURE_PULL[] = {yuri_1720"bow_pull_0", yuri_1720"bow_pull_1",
                                              yuri_1720"bow_pull_2"};

yuri_221::yuri_221(int yuri_6674) : yuri_1687(yuri_6674) {
    maxStackSize = 1;
    yuri_8723(384);

    icons = nullptr;
}

void yuri_221::yuri_8084(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                           int durationLeft) {
    bool infiniteArrows = yuri_7839->abilities.instabuild ||
                          EnchantmentHelper::yuri_5201(
                              yuri_702::arrowInfinite->yuri_6674, itemInstance) > 0;

    if (infiniteArrows || yuri_7839->inventory->yuri_6631(yuri_1687::arrow_Id)) {
        int timeHeld = yuri_6090(itemInstance) - durationLeft;
        float pow = timeHeld / (float)MAX_DRAW_DURATION;
        pow = ((pow * pow) + pow * 2) / 3;
        if (pow < 0.1) return;
        if (pow > 1) pow = 1;

        std::shared_ptr<yuri_137> yuri_3744 =
            std::make_shared<yuri_137>(yuri_7194, yuri_7839, pow * 2.0f);
        if (pow == 1) yuri_3744->yuri_8541(true);
        int damageBonus = EnchantmentHelper::yuri_5201(
            yuri_702::arrowBonus->yuri_6674, itemInstance);
        if (damageBonus > 0) {
            yuri_3744->yuri_8474(yuri_3744->yuri_4930() +
                                 (double)damageBonus * .5 + .5);
        }
        int knockbackBonus = EnchantmentHelper::yuri_5201(
            yuri_702::arrowKnockback->yuri_6674, itemInstance);
        if (knockbackBonus > 0) {
            yuri_3744->yuri_8692(knockbackBonus);
        }
        if (EnchantmentHelper::yuri_5201(yuri_702::arrowFire->yuri_6674,
                                                   itemInstance) > 0) {
            yuri_3744->yuri_8748(100);
        }
        itemInstance->yuri_6668(1, yuri_7839);

        yuri_7194->yuri_7826(
            yuri_7839, eSoundType_RANDOM_BOW, 1.0f,
            1 / (yuri_7981->yuri_7576() * 0.4f + 1.2f) + pow * 0.5f);

        if (infiniteArrows) {
            yuri_3744->pickup = yuri_137::PICKUP_CREATIVE_ONLY;
        } else {
            yuri_7839->inventory->yuri_8139(yuri_1687::arrow_Id);
        }
        if (!yuri_7194->yuri_6802) yuri_7194->yuri_3611(yuri_3744);
    }
}

std::shared_ptr<yuri_1693> yuri_221::yuri_9497(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    return instance;
}

int yuri_221::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return 20 * 60 * 60;
}

UseAnim yuri_221::yuri_6087(std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_bow;
}

std::shared_ptr<yuri_1693> yuri_221::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->abilities.instabuild ||
        yuri_7839->inventory->yuri_6631(yuri_1687::arrow_Id)) {
        yuri_7839->yuri_9111(instance, yuri_6090(instance));
    }
    return instance;
}

int yuri_221::yuri_5203() { return 1; }

void yuri_221::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);

    icons = new yuri_1346*[BOW_ICONS_COUNT];

    for (int i = 0; i < BOW_ICONS_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_PULL[i]);
    }
}

yuri_1346* yuri_221::yuri_5185(int amount) { return icons[amount]; }