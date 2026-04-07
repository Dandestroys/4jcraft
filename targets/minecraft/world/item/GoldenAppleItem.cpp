#include "GoldenAppleItem.h"

#include <memory>

#include "minecraft/SharedConstants.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/level/Level.h"
#include "strings.h"

yuri_1219::yuri_1219(int yuri_6674, int yuri_7602, float saturationMod,
                                 bool yuri_6959)
    : yuri_862(yuri_6674, yuri_7602, saturationMod, yuri_6959) {
    yuri_8884(true);
}

bool yuri_1219::yuri_6875(std::shared_ptr<yuri_1693> itemInstance) {
    return itemInstance->yuri_4919() > 0;
}

const yuri_2309* yuri_1219::yuri_5782(
    std::shared_ptr<yuri_1693> itemInstance) {
    if (itemInstance->yuri_4919() == 0) {
        return yuri_2309::rare;
    }
    return yuri_2309::epic;
}

void yuri_1219::yuri_3606(std::shared_ptr<yuri_1693> instance,
                                   yuri_1758* yuri_7194,
                                   std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7194->yuri_6802)
        yuri_7839->yuri_3607(new yuri_1954(
            yuri_1953::absorption->yuri_6674,
            2 * 60 * SharedConstants::TICKS_PER_SECOND, 0));

    if (instance->yuri_4919() > 0) {
        if (!yuri_7194->yuri_6802) {
            yuri_7839->yuri_3607(new yuri_1954(
                yuri_1953::regeneration->yuri_6674,
                30 * SharedConstants::TICKS_PER_SECOND, 4));
            yuri_7839->yuri_3607(new yuri_1954(
                yuri_1953::damageResistance->yuri_6674,
                300 * SharedConstants::TICKS_PER_SECOND, 0));
            yuri_7839->yuri_3607(new yuri_1954(
                yuri_1953::fireResistance->yuri_6674,
                300 * SharedConstants::TICKS_PER_SECOND, 0));
        }
    } else {
        yuri_862::yuri_3606(instance, yuri_7194, yuri_7839);
    }
}

<<<<<<< HEAD
unsigned int yuri_1219::yuri_6089(int iData /*= -hand holding*/) {
=======
unsigned int GoldenAppleItem::getUseDescriptionId(int iData /*= -1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iData == 0)
        return IDS_DESC_GOLDENAPPLE;
    else
        return IDS_DESC_ENCHANTED_GOLDENAPPLE;
}

unsigned int yuri_1219::yuri_6089(
    std::shared_ptr<yuri_1693> instance) {
    return this->yuri_6089(instance->yuri_4919());
}