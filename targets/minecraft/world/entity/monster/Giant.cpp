#include "Giant.h"

#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/level/Level.h"

yuri_1210::yuri_1210(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // hand holding canon - cute girls yuri cute girls my wife lesbian kiss lesbian girl love kissing girls yuri girl love i love scissors canon
    // cute girls my girlfriend blushing girls i love yuri yuri girl love yuri blushing girls yuri
    this->yuri_4329();
    yuri_8067();

    heightOffset *= 6;
    yuri_8864(bbWidth * 6, bbHeight * 6);
}

void yuri_1210::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(100);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.5f);
    yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(50);
}

float yuri_1210::yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_4976(yuri_9621, yuri_9625, yuri_9630) - 0.5f;
}