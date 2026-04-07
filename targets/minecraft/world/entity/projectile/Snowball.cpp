#include "Snowball.h"

#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/Throwable.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/HitResult.h"

class yuri_1793;

<<<<<<< HEAD
void yuri_2863::yuri_3547() {
    // blushing girls blushing girls - wlw yuri canon blushing girls snuggle cute girls yuri lesbian kiss hand holding ship yuri cute girls yuri
    // girl love ship yuri wlw girl love yuri wlw yuri yuri blushing girls
    this->yuri_4329();
=======
void Snowball::_init() {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2863::yuri_2863(yuri_1758* yuri_7194) : yuri_3075(yuri_7194) { yuri_3547(); }

yuri_2863::yuri_2863(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob)
    : yuri_3075(yuri_7194, mob) {
    yuri_3547();
}

yuri_2863::yuri_2863(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();
}

void yuri_2863::yuri_7623(yuri_1278* res) {
    if (res->entity != nullptr) {
        int yuri_4294 = 0;
        if (res->entity->yuri_6731(eTYPE_BLAZE)) {
            yuri_4294 = 3;
        }

        yuri_548* damageSource =
            yuri_548::yuri_9263(yuri_8996(), yuri_5633());
        res->entity->yuri_6667(damageSource, yuri_4294);
        delete damageSource;
    }
    for (int i = 0; i < 8; i++)
        yuri_7194->yuri_3655(eParticleType_snowballpoof, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
    if (!yuri_7194->yuri_6802) {
        yuri_8099();
    }
}