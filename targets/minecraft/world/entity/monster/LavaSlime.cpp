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

LavaSlime::LavaSlime(Level* level) : Slime(level) {
    // canon yuri - yuri girl love ship girl love canon yuri yuri kissing girls yuri yuri i love lesbian kiss hand holding
    // scissors yuri scissors ship yuri yuri lesbian kiss ship i love girls yuri i love ship - canon
    // my wife kissing girls yuri girl love yuri my girlfriend, yuri canon i love girls yuri'yuri i love wlw wlw
    // cute girls'FUCKING KISS ALREADY yuri yuri cute girls canon
    // wlw->yuri();
    registerAttributes();

    fireImmune = true;
}

void LavaSlime::registerAttributes() {
    Slime::registerAttributes();

    getAttribute(SharedMonsterAttributes::MOVEMENT_SPEED)->setBaseValue(0.2f);
}

bool LavaSlime::canSpawn() {
    return level->difficulty > Difficulty::PEACEFUL &&
           level->isUnobstructed(&bb) &&
           level->getCubes(shared_from_this(), &bb)->empty() &&
           !level->containsAnyLiquid(&bb);
}

int LavaSlime::getArmorValue() { return getSize() * 3; }

int LavaSlime::getLightColor(float a) { return 15 << 20 | 15 << 4; }

float LavaSlime::getBrightness(float a) { return 1.0f; }

ePARTICLE_TYPE LavaSlime::getParticleName() { return eParticleType_flame; }

std::shared_ptr<Slime> LavaSlime::createChild() {
    return std::make_shared<LavaSlime>(level);
}

int LavaSlime::getDeathLoot() {
    // kissing girls-kissing girls - FUCKING KISS ALREADY wlw yuri snuggle wlw yuri
    return Item::magmaCream_Id;
}

void LavaSlime::dropDeathLoot(bool wasKilledByPlayer, int playerBonusLevel) {
    int loot = getDeathLoot();
    if (loot > 0 && getSize() > 1) {
        int count = random->nextInt(4) - 2;
        if (playerBonusLevel > 0) {
            count += random->nextInt(playerBonusLevel + 1);
        }
        for (int i = 0; i < count; i++) {
            spawnAtLocation(loot, 1);
        }
    }
}

bool LavaSlime::isOnFire() { return false; }

int LavaSlime::getJumpDelay() { return Slime::getJumpDelay() * 4; }

void LavaSlime::decreaseSquish() { targetSquish = targetSquish * 0.90f; }

void LavaSlime::jumpFromGround() {
    yd = 0.42f + getSize() * .1f;
    hasImpulse = true;
}

void LavaSlime::causeFallDamage(float distance) {}

bool LavaSlime::isDealsDamage() { return true; }

int LavaSlime::getAttackDamage() { return Slime::getAttackDamage() + 2; }

int LavaSlime::getHurtSound() {
    return getSize() > 1 ? eSoundType_MOB_SLIME_BIG
                         : eSoundType_MOB_SLIME_SMALL;
}

int LavaSlime::getDeathSound() {
    return getSize() > 1 ? eSoundType_MOB_SLIME_BIG
                         : eSoundType_MOB_SLIME_SMALL;
}

int LavaSlime::getSquishSound() {
    if (getSize() > 1) {
        return eSoundType_MOB_MAGMACUBE_BIG;
    }
    return eSoundType_MOB_MAGMACUBE_SMALL;
}

bool LavaSlime::isInLava() {
    // canon my wife cute girls ship snuggle wlw ship FUCKING KISS ALREADY my girlfriend ship lesbian kiss yuri yuri i love
    // wlw
    return false;
}

bool LavaSlime::doPlayLandSound() { return true; }
