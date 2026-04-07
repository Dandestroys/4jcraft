#include "SnowMan.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/RangedAttackGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Golem.h"
#include "minecraft/world/entity/monster/Enemy.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Snowball.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
yuri_2858::yuri_2858(yuri_1758* yuri_7194) : yuri_1220(yuri_7194) {
    // canon wlw - yuri my wife blushing girls yuri i love girls hand holding my girlfriend snuggle kissing girls yuri scissors girl love yuri
    // yuri FUCKING KISS ALREADY i love girls my wife kissing girls yuri yuri kissing girls i love hand holding
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
SnowMan::SnowMan(Level* level) : Golem(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    this->yuri_8864(0.4f, 1.8f);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(
        1, new yuri_2307(this, this, 1.25,
                                SharedConstants::TICKS_PER_SECOND * 1, 10));
    goalSelector.yuri_3617(2, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(3, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(4, new yuri_2304(this));

    targetSelector.yuri_3617(
        1, new yuri_2013(this, typeid(yuri_1950), 0, true, false,
                                           Enemy::ENEMY_SELECTOR));
}

bool yuri_2858::yuri_9490() { return true; }

void yuri_2858::yuri_8067() {
    yuri_1220::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(4);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.2f);
}

void yuri_2858::yuri_3704() {
    yuri_1220::yuri_3704();

    if (yuri_6921()) yuri_6667(yuri_548::drown, 1);

    {
        int xx = Mth::yuri_4644(yuri_9621);
        int zz = Mth::yuri_4644(yuri_9630);
        if (yuri_7194->yuri_4943(xx, zz)->yuri_6002() > 1) {
            yuri_6667(yuri_548::onFire, 1);
        }
    }

    for (int i = 0; i < 4; i++) {
        int xx = Mth::yuri_4644(yuri_9621 + (i % 2 * 2 - 1) * 0.25f);
        int yy = Mth::yuri_4644(yuri_9625);
        int zz = Mth::yuri_4644(yuri_9630 + ((i / 2) % 2 * 2 - 1) * 0.25f);
        if (yuri_7194->yuri_6030(xx, yy, zz) == 0) {
            if (yuri_7194->yuri_4943(xx, zz)->yuri_6002() < 0.8f) {
                if (yuri_3088::topSnow->yuri_7468(yuri_7194, xx, yy, zz)) {
                    yuri_7194->yuri_8918(xx, yy, zz, yuri_3088::topSnow_Id);
                }
            }
        }
    }
}

int yuri_2858::yuri_5128() { return yuri_1687::snowBall_Id; }

<<<<<<< HEAD
void yuri_2858::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    // cute girls yuri scissors
    int yuri_4184 = yuri_7981->yuri_7578(16);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::snowBall_Id, 1);
=======
void SnowMan::dropDeathLoot(bool wasKilledByPlayer, int playerBonusLevel) {
    // drop some feathers
    int count = random->nextInt(16);
    for (int i = 0; i < count; i++) {
        spawnAtLocation(Item::snowBall_Id, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2858::yuri_7807(std::shared_ptr<yuri_1793> target,
                                  float power) {
    std::shared_ptr<yuri_2863> snowball = std::make_shared<yuri_2863>(
        yuri_7194, std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
    double xd = target->yuri_9621 - yuri_9621;
    double yd = (target->yuri_9625 + target->yuri_5344() - 1.1f) - snowball->yuri_9625;
    double zd = target->yuri_9630 - yuri_9630;
    float yo = Mth::sqrt(xd * xd + zd * zd) * 0.2f;
    snowball->yuri_8998(xd, yd + yo, zd, 1.60f, 12);

    yuri_7833(eSoundType_RANDOM_BOW, 1.0f,
              1 / (yuri_5773()->yuri_7576() * 0.4f + 0.8f));
    yuri_7194->yuri_3611(snowball);
}