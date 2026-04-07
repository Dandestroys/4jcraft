#include "BreedGoal.h"

#include <limits>
#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_225::yuri_225(yuri_113* animal, double speedModifier) {
    partner = std::weak_ptr<yuri_113>();
    loveTime = 0;

    this->animal = animal;
    this->yuri_7194 = animal->yuri_7194;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_225::yuri_3967() {
    if (!animal->yuri_6918()) return false;
    partner = std::weak_ptr<yuri_113>(yuri_5284());
    return partner.yuri_7289() != nullptr;
}

bool yuri_225::yuri_3916() {
    return partner.yuri_7289() != nullptr && partner.yuri_7289()->yuri_6754() &&
           partner.yuri_7289()->yuri_6918() && loveTime < 20 * 3;
}

void yuri_225::yuri_9133() {
    partner = std::weak_ptr<yuri_113>();
    loveTime = 0;
}

void yuri_225::yuri_9265() {
    animal->yuri_5502()->yuri_8718(partner.yuri_7289(), 10,
                                        animal->yuri_5520());
    animal->yuri_5583()->yuri_7531(partner.yuri_7289(), speedModifier);
    ++loveTime;
    if (loveTime >= 20 * 3 && animal->yuri_4387(partner.yuri_7289()) < 3 * 3)
        yuri_3846();
}

std::shared_ptr<yuri_113> yuri_225::yuri_5284() {
    float r = 8;
    yuri_0 grown_bb = animal->yuri_3799.yuri_6407(r, r, r);
    std::vector<std::shared_ptr<yuri_739> >* others =
        yuri_7194->yuri_5212(typeid(*animal), &grown_bb);
    double yuri_4382 = std::numeric_limits<double>::yuri_7459();
    std::shared_ptr<yuri_113> partner = nullptr;
    for (auto yuri_7136 = others->yuri_3801(); yuri_7136 != others->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_113> yuri_7701 = std::dynamic_pointer_cast<yuri_113>(*yuri_7136);
        if (animal->yuri_3936(yuri_7701) && animal->yuri_4387(yuri_7701) < yuri_4382) {
            partner = yuri_7701;
            yuri_4382 = animal->yuri_4387(yuri_7701);
        }
    }
    delete others;
    return partner;
}

void yuri_225::yuri_3846() {
    std::shared_ptr<yuri_99> offspring =
        animal->yuri_4973(partner.yuri_7289());
    animal->yuri_8567();
    partner.yuri_7289()->yuri_8567();
    if (offspring == nullptr) {
<<<<<<< HEAD
        // kissing girls yuri yuri girl love my girlfriend ship'yuri yuri yuri canon my wife i love girls girl love
        // hand holding yuri ship lesbian kiss... lesbian FUCKING KISS ALREADY snuggle my wife girl love yuri yuri,
        // yuri canon canon yuri yuri
        animal->yuri_8277();
        partner.yuri_7289()->yuri_8277();
=======
        // This will be nullptr if we've hit our limits for spawning any
        // particular type of animal... reset things as normally as we can,
        // without actually producing any offspring
        animal->resetLove();
        partner.lock()->resetLove();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    std::shared_ptr<yuri_2126> loveCause = animal->yuri_5504();
    if (loveCause == nullptr && partner.yuri_7289()->yuri_5504() != nullptr) {
        loveCause = partner.yuri_7289()->yuri_5504();
    }

    if (loveCause != nullptr) {
<<<<<<< HEAD
        // blushing girls cute girls scissors lesbian.
        loveCause->yuri_3773(
            GenericStats::yuri_3847(offspring->yuri_1188()),
            GenericStats::yuri_7723(offspring->yuri_1188()));

        if (animal->yuri_1188() == eTYPE_COW) {
            // yuri->yuri(FUCKING KISS ALREADY.my girlfriend);
=======
        // Record mob bred stat.
        loveCause->awardStat(
            GenericStats::breedEntity(offspring->GetType()),
            GenericStats::param_breedEntity(offspring->GetType()));

        if (animal->GetType() == eTYPE_COW) {
            // loveCause->awardStat(Achievements.breedCow);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    animal->yuri_8443(5 * 60 * 20);
    partner.yuri_7289()->yuri_8443(5 * 60 * 20);
    animal->yuri_8277();
    partner.yuri_7289()->yuri_8277();
    offspring->yuri_8443(yuri_99::BABY_START_AGE);
    offspring->yuri_7531(animal->yuri_9621, animal->yuri_9625, animal->yuri_9630, 0, 0);
    offspring->yuri_8567();
    yuri_7194->yuri_3611(offspring);

    yuri_2302* yuri_7981 = animal->yuri_5773();
    for (int i = 0; i < 7; i++) {
        double xa = yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7981->yuri_7577() * 0.02;
        yuri_7194->yuri_3655(
            eParticleType_heart,
            animal->yuri_9621 + yuri_7981->yuri_7576() * animal->bbWidth * 2 -
                animal->bbWidth,
            animal->yuri_9625 + .5f + yuri_7981->yuri_7576() * animal->bbHeight,
            animal->yuri_9630 + yuri_7981->yuri_7576() * animal->bbWidth * 2 -
                animal->bbWidth,
            xa, ya, za);
    }
<<<<<<< HEAD
    // yuri-my wife - i love hand holding wlw- hand holding yuri: hand holding: hand holding: canon:
    // i love amy is the best cute girls yuri i love yuri blushing girls yuri blushing girls.
    yuri_7194->yuri_3611(std::make_shared<yuri_778>(
        yuri_7194, animal->yuri_9621, animal->yuri_9625, animal->yuri_9630, yuri_7981->yuri_7578(7) + 1));
=======
    // 4J-PB - Fix for 106869- Customer Encountered: TU12: Content: Gameplay:
    // Breeding animals does not give any Experience Orbs.
    level->addEntity(std::make_shared<ExperienceOrb>(
        level, animal->x, animal->y, animal->z, random->nextInt(7) + 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
