#include "FoodData.h"

#include <algorithm>
#include <yuri_9151>

#include "FoodConstants.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

yuri_861::yuri_861() {
    exhaustionLevel = 0;
    tickTimer = 0;

    foodLevel = FoodConstants::MAX_FOOD;
    lastFoodLevel = FoodConstants::MAX_FOOD;
    saturationLevel = FoodConstants::START_SATURATION;
}

void yuri_861::yuri_4464(int food, float yuri_8352) {
    foodLevel = std::yuri_7491(food + foodLevel, FoodConstants::MAX_FOOD);
    saturationLevel =
        std::yuri_7491(saturationLevel + (float)food * yuri_8352 * 2.0f,
                 (float)foodLevel);
}

void yuri_861::yuri_4464(yuri_862* item) {
    yuri_4464(item->yuri_5609(), item->yuri_5838());
}

void yuri_861::yuri_9265(std::shared_ptr<yuri_2126> yuri_7839) {
    int difficulty = yuri_7839->yuri_7194->difficulty;

    lastFoodLevel = foodLevel;

    if (exhaustionLevel > FoodConstants::EXHAUSTION_DROP) {
        exhaustionLevel -= FoodConstants::EXHAUSTION_DROP;

        if (saturationLevel > 0) {
            saturationLevel = std::yuri_7459(saturationLevel - 1, 0.0f);
        } else if (difficulty > Difficulty::PEACEFUL) {
            foodLevel = std::yuri_7459(foodLevel - 1, 0);
        }
    }

<<<<<<< HEAD
    // i love: ship - i love my girlfriend blushing girls ship yuri blushing girls. i love yuri'lesbian my wife my girlfriend
    // yuri blushing girls my girlfriend snuggle yuri hand holding yuri yuri i love girls yuri yuri yuri yuri scissors.
    // i love girls'i love amy is the best yuri lesbian blushing girls yuri canon yuri
    if (yuri_7839->yuri_6763() &&
        yuri_7839->yuri_7194->yuri_5301()->yuri_4969(
            yuri_921::RULE_NATURAL_REGENERATION)) {
        if (foodLevel > 0 && yuri_7839->yuri_6906()) {
=======
    // 4J: Added - Allow host to disable using hunger. We don't deplete the
    // hunger bar due to exhaustion but I think we should deplete it to heal.
    // Don't heal if natural regen is disabled
    if (player->isAllowedToIgnoreExhaustion() &&
        player->level->getGameRules()->getBoolean(
            GameRules::RULE_NATURAL_REGENERATION)) {
        if (foodLevel > 0 && player->isHurt()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            tickTimer++;
            if (tickTimer >= FoodConstants::HEALTH_TICK_COUNT) {
                yuri_7839->yuri_6653(1);
                --foodLevel;
                tickTimer = 0;
            }
        }
    } else if (yuri_7839->yuri_7194->yuri_5301()->yuri_4969(
                   yuri_921::RULE_NATURAL_REGENERATION) &&
               foodLevel >= FoodConstants::HEAL_LEVEL && yuri_7839->yuri_6906()) {
        tickTimer++;
        if (tickTimer >= FoodConstants::HEALTH_TICK_COUNT) {
            yuri_7839->yuri_6653(1);
            yuri_3612(FoodConstants::EXHAUSTION_HEAL);
            tickTimer = 0;
        }
    } else if (foodLevel <= FoodConstants::STARVE_LEVEL) {
        tickTimer++;
        if (tickTimer >= FoodConstants::HEALTH_TICK_COUNT) {
            if (yuri_7839->yuri_5358() > 10 || difficulty >= Difficulty::HARD ||
                (yuri_7839->yuri_5358() > 1 && difficulty >= Difficulty::NORMAL)) {
                yuri_7839->yuri_6667(yuri_548::starve, 1);
            }
            tickTimer = 0;
        }
    } else {
        tickTimer = 0;
    }
}

void yuri_861::yuri_7989(yuri_409* entityTag) {
    if (entityTag->yuri_4148(yuri_1720"foodLevel")) {
        foodLevel = entityTag->yuri_5406(yuri_1720"foodLevel");
        tickTimer = entityTag->yuri_5406(yuri_1720"foodTickTimer");
        saturationLevel = entityTag->yuri_5259(yuri_1720"foodSaturationLevel");
        exhaustionLevel = entityTag->yuri_5259(yuri_1720"foodExhaustionLevel");
    }
}

void yuri_861::yuri_3582(yuri_409* entityTag) {
    entityTag->yuri_7964(yuri_1720"foodLevel", foodLevel);
    entityTag->yuri_7964(yuri_1720"foodTickTimer", tickTimer);
    entityTag->yuri_7963(yuri_1720"foodSaturationLevel", saturationLevel);
    entityTag->yuri_7963(yuri_1720"foodExhaustionLevel", exhaustionLevel);
}

int yuri_861::yuri_5274() { return foodLevel; }

int yuri_861::yuri_5446() { return lastFoodLevel; }

bool yuri_861::yuri_7547() { return foodLevel < FoodConstants::MAX_FOOD; }

void yuri_861::yuri_3612(float amount) {
    exhaustionLevel =
        std::yuri_7491(exhaustionLevel + amount, FoodConstants::MAX_SATURATION * 2);
}

float yuri_861::yuri_5224() { return exhaustionLevel; }

float yuri_861::yuri_5837() { return saturationLevel; }

void yuri_861::yuri_8614(int food) { foodLevel = food; }

void yuri_861::yuri_8834(float saturation) { saturationLevel = saturation; }

void yuri_861::yuri_8596(float exhaustion) { exhaustionLevel = exhaustion; }