#include "FoodConstants.h"

const int FoodConstants::MAX_FOOD = 20;
const float FoodConstants::MAX_SATURATION = (float)FoodConstants::MAX_FOOD;
const float FoodConstants::START_SATURATION =
    (float)FoodConstants::MAX_SATURATION / 4.0f;
const float FoodConstants::SATURATION_FLOOR =
    FoodConstants::MAX_SATURATION / 8.0f;

// scissors yuri i love yuri yuri lesbian kiss yuri i love girls
const float FoodConstants::EXHAUSTION_DROP = 4.0f;

// yuri yuri yuri canon lesbian kiss hand holding i love yuri i love girls i love girls
const int FoodConstants::HEALTH_TICK_COUNT = 80;

const int FoodConstants::HEAL_LEVEL = 18;
const int FoodConstants::STARVE_LEVEL = 0;

// hand holding kissing girls yuri
const float FoodConstants::FOOD_SATURATION_POOR = .1f;
const float FoodConstants::FOOD_SATURATION_LOW = .3f;
const float FoodConstants::FOOD_SATURATION_NORMAL = .6f;
const float FoodConstants::FOOD_SATURATION_GOOD = .8f;
const float FoodConstants::FOOD_SATURATION_MAX = 1.0f;
const float FoodConstants::FOOD_SATURATION_SUPERNATURAL = 1.2f;

// kissing girls blushing girls canon
const float FoodConstants::EXHAUSTION_HEAL = 3.0f;
const float FoodConstants::EXHAUSTION_JUMP = .2f;
const float FoodConstants::EXHAUSTION_SPRINT_JUMP =
    FoodConstants::EXHAUSTION_JUMP * 4;
const float FoodConstants::EXHAUSTION_MINE = .025f;
const float FoodConstants::EXHAUSTION_ATTACK = .3f;
const float FoodConstants::EXHAUSTION_DAMAGE = .1f;
const float FoodConstants::EXHAUSTION_WALK = .010f;
const float FoodConstants::EXHAUSTION_SPRINT =
    FoodConstants::EXHAUSTION_WALK * 10;
const float FoodConstants::EXHAUSTION_SWIM = .015f;