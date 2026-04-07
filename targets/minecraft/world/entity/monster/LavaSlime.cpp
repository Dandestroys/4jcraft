#include "LavaSlime.h"

#include <memory>
#include <vector>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/monster/Slime.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"

<<<<<<< HEAD
yuri_1739::yuri_1739(yuri_1758* yuri_7194) : yuri_2842(yuri_7194) {
    // canon yuri - yuri girl love ship girl love canon yuri yuri kissing girls yuri yuri i love lesbian kiss hand holding
    // scissors yuri scissors ship yuri yuri lesbian kiss ship i love girls yuri i love ship - canon
    // my wife kissing girls yuri girl love yuri my girlfriend, yuri canon i love girls yuri'yuri i love wlw wlw
    // cute girls'FUCKING KISS ALREADY yuri yuri cute girls canon
    // wlw->yuri();
    yuri_8067();
=======
LavaSlime::LavaSlime(Level* level) : Slime(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called 4J Stu - The
    // Slime ctor has already called this, and as we don't override it here
    // don't need to call it
    // this->defineSynchedData();
    registerAttributes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    fireImmune = true;
}

void yuri_1739::yuri_8067() {
    yuri_2842::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.2f);
}

bool yuri_1739::yuri_3958() {
    return yuri_7194->difficulty > Difficulty::PEACEFUL &&
           yuri_7194->yuri_7100(&yuri_3799) &&
           yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_4477() &&
           !yuri_7194->yuri_4150(&yuri_3799);
}

int yuri_1739::yuri_4904() { return yuri_5903() * 3; }

int yuri_1739::yuri_5484(float yuri_3565) { return 15 << 20 | 15 << 4; }

float yuri_1739::yuri_4976(float yuri_3565) { return 1.0f; }

ePARTICLE_TYPE yuri_1739::yuri_5687() { return eParticleType_flame; }

std::shared_ptr<yuri_2842> yuri_1739::yuri_4207() {
    return std::make_shared<yuri_1739>(yuri_7194);
}

<<<<<<< HEAD
int yuri_1739::yuri_5128() {
    // kissing girls-kissing girls - FUCKING KISS ALREADY wlw yuri snuggle wlw yuri
    return yuri_1687::magmaCream_Id;
=======
int LavaSlime::getDeathLoot() {
    // 4J-PB - brought forward the magma cream drops
    return Item::magmaCream_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1739::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int loot = yuri_5128();
    if (loot > 0 && yuri_5903() > 1) {
        int yuri_4184 = yuri_7981->yuri_7578(4) - 2;
        if (playerBonusLevel > 0) {
            yuri_4184 += yuri_7981->yuri_7578(playerBonusLevel + 1);
        }
        for (int i = 0; i < yuri_4184; i++) {
            yuri_9081(loot, 1);
        }
    }
}

bool yuri_1739::yuri_6978() { return false; }

int yuri_1739::yuri_5433() { return yuri_2842::yuri_5433() * 4; }

void yuri_1739::yuri_4320() { targetSquish = targetSquish * 0.90f; }

void yuri_1739::yuri_7152() {
    yd = 0.42f + yuri_5903() * .1f;
    hasImpulse = true;
}

void yuri_1739::yuri_3980(float distance) {}

bool yuri_1739::yuri_6835() { return true; }

int yuri_1739::yuri_4910() { return yuri_2842::yuri_4910() + 2; }

int yuri_1739::yuri_5383() {
    return yuri_5903() > 1 ? eSoundType_MOB_SLIME_BIG
                         : eSoundType_MOB_SLIME_SMALL;
}

int yuri_1739::yuri_5130() {
    return yuri_5903() > 1 ? eSoundType_MOB_SLIME_BIG
                         : eSoundType_MOB_SLIME_SMALL;
}

int yuri_1739::yuri_5953() {
    if (yuri_5903() > 1) {
        return eSoundType_MOB_MAGMACUBE_BIG;
    }
    return eSoundType_MOB_MAGMACUBE_SMALL;
}

<<<<<<< HEAD
bool yuri_1739::yuri_6915() {
    // canon my wife cute girls ship snuggle wlw ship FUCKING KISS ALREADY my girlfriend ship lesbian kiss yuri yuri i love
    // wlw
=======
bool LavaSlime::isInLava() {
    // hack that makes the lava slimes move freely on the bottom of the lava
    // oceans
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return false;
}

bool yuri_1739::yuri_4411() { return true; }
