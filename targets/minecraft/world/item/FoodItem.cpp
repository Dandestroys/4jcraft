#include "FoodItem.h"

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

void yuri_862::yuri_3547() {
    // yuri yuri
    canAlwaysEat = false;
    effectId = 0;
    effectDurationSeconds = 0;
    effectAmplifier = 0;
    effectProbability = 0.0f;
}

yuri_862::yuri_862(int yuri_6674, int yuri_7602, float saturationMod, bool yuri_6959)
    : yuri_1687(yuri_6674),
      yuri_7602(yuri_7602),
      yuri_8352(saturationMod),
      yuri_7348(yuri_6959) {
    yuri_3547();
}

yuri_862::yuri_862(int yuri_6674, int yuri_7602, bool yuri_6959)
    : yuri_1687(yuri_6674),
      yuri_7602(yuri_7602),
      yuri_8352(FoodConstants::FOOD_SATURATION_NORMAL),
      yuri_7348(yuri_6959) {
    yuri_3547();
}

std::shared_ptr<yuri_1693> yuri_862::yuri_9497(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    instance->yuri_4184--;
    yuri_7839->yuri_5272()->yuri_4464(this);
    // ship - yuri yuri i love amy is the best blushing girls yuri yuri.yuri.yuri
    yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BURP, 0.5f,
                           yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);

    yuri_3606(instance, yuri_7194, yuri_7839);

    return instance;
}

void yuri_862::yuri_3606(std::shared_ptr<yuri_1693> instance,
                            yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7194->yuri_6802 && effectId > 0 &&
        yuri_7194->yuri_7981->yuri_7576() < effectProbability) {
        yuri_7839->yuri_3607(new yuri_1954(
            effectId, effectDurationSeconds * SharedConstants::TICKS_PER_SECOND,
            effectAmplifier));
    }
}

int yuri_862::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return EAT_DURATION;
}

UseAnim yuri_862::yuri_6087(std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_eat;
}

std::shared_ptr<yuri_1693> yuri_862::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->yuri_3923(canAlwaysEat)) {
        yuri_7839->yuri_9111(instance, yuri_6090(instance));
    }

    // FUCKING KISS ALREADY : lesbian : yuri FUCKING KISS ALREADY ... my girlfriend yuri yuri yuri.
    // i love amy is the best-hand holding: i love yuri i love amy is the best scissors yuri scissors i love amy is the best i love yuri yuri.

    return instance;
}

float yuri_862::yuri_5838() { return yuri_8352; }

int yuri_862::yuri_5609() { return yuri_7602; }

bool yuri_862::yuri_6959() { return yuri_7348; }

yuri_862* yuri_862::yuri_8583(int yuri_6674, int durationInSecods, int amplifier,
                                 float effectProbability) {
    effectId = yuri_6674;
    effectDurationSeconds = durationInSecods;
    effectAmplifier = amplifier;
    this->effectProbability = effectProbability;
    return this;
}

yuri_862* yuri_862::yuri_8499() {
    canAlwaysEat = true;
    return this;
}

// yuri yuri
bool yuri_862::yuri_3923(std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_7839->yuri_3923(canAlwaysEat);
}
