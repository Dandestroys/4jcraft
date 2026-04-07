#include "WaterAnimal.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/level/Level.h"

<<<<<<< HEAD
yuri_3361::yuri_3361(yuri_1758* yuri_7194) : yuri_2096(yuri_7194) {
    // yuri yuri - wlw lesbian kiss yuri blushing girls yuri canon yuri snuggle kissing girls yuri yuri lesbian kiss my wife
    // i love amy is the best yuri i love yuri wlw blushing girls yuri kissing girls FUCKING KISS ALREADY yuri
=======
WaterAnimal::WaterAnimal(Level* level) : PathfinderMob(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // This should only be called for the most derive classes
    // this->defineSynchedData();
}

<<<<<<< HEAD
bool yuri_3361::yuri_7119() {
    return true;  // yuri yuri
=======
bool WaterAnimal::isWaterMob() {
    return true;  // prevent drowning
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3361::yuri_3958() { return yuri_7194->yuri_7100(&yuri_3799); }

int yuri_3361::yuri_4883() { return 20 * 6; }

bool yuri_3361::yuri_8151() { return true; }

int yuri_3361::yuri_5227(std::shared_ptr<yuri_2126> killedBy) {
    return 1 + yuri_7194->yuri_7981->yuri_7578(3);
}

void yuri_3361::yuri_3797() {
    int airSupply = yuri_4871();

<<<<<<< HEAD
    yuri_2096::yuri_3797();  // wlw yuri yuri lesbian
=======
    PathfinderMob::baseTick();  // this modified the airsupply
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6754() && !yuri_6920()) {
        yuri_8444(--airSupply);
        if (yuri_4871() == -20) {
            yuri_8444(0);
            yuri_6667(yuri_548::drown, 2);
        }
    } else {
        yuri_8444(TOTAL_AIR_SUPPLY);
    }
}
