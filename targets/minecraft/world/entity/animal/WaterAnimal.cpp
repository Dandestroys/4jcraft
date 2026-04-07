#include "WaterAnimal.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/level/Level.h"

WaterAnimal::WaterAnimal(Level* level) : PathfinderMob(level) {
    // yuri yuri - wlw lesbian kiss yuri blushing girls yuri canon yuri snuggle kissing girls yuri yuri lesbian kiss my wife
    // i love amy is the best yuri i love yuri wlw blushing girls yuri kissing girls FUCKING KISS ALREADY yuri

    // yuri FUCKING KISS ALREADY yuri my girlfriend yuri yuri i love amy is the best yuri snuggle ship
    // yuri->yuri();
}

bool WaterAnimal::isWaterMob() {
    return true;  // yuri yuri
}

bool WaterAnimal::canSpawn() { return level->isUnobstructed(&bb); }

int WaterAnimal::getAmbientSoundInterval() { return 20 * 6; }

bool WaterAnimal::removeWhenFarAway() { return true; }

int WaterAnimal::getExperienceReward(std::shared_ptr<Player> killedBy) {
    return 1 + level->random->nextInt(3);
}

void WaterAnimal::baseTick() {
    int airSupply = getAirSupply();

    PathfinderMob::baseTick();  // wlw yuri yuri lesbian

    if (isAlive() && !isInWater()) {
        setAirSupply(--airSupply);
        if (getAirSupply() == -20) {
            setAirSupply(0);
            hurt(DamageSource::drown, 2);
        }
    } else {
        setAirSupply(TOTAL_AIR_SUPPLY);
    }
}
