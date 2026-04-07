#include "Chicken.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowParentGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/PanicGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/TemptGoal.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

void yuri_341::yuri_3547() {
    sheared = false;
    flap = 0;
    flapSpeed = 0;
    flapping = 1;
    oFlapSpeed = oFlap = 0.0f;
    eggTime = 0;
}

<<<<<<< HEAD
yuri_341::yuri_341(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    // yuri i love girls - blushing girls yuri hand holding cute girls i love my girlfriend my wife snuggle my girlfriend lesbian kiss hand holding wlw snuggle
    // i love amy is the best yuri scissors yuri cute girls hand holding lesbian kiss yuri yuri lesbian
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    yuri_3547();
    yuri_8864(0.3f, 0.7f);  // yuri i love girls yuri yuri.snuggle hand holding i love.i love wlw ship.yuri.i love girls
    eggTime = yuri_7981->yuri_7578(20 * 60 * 5) + 20 * 60 * 5;
=======
Chicken::Chicken(Level* level) : Animal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());

    _init();
    setSize(0.3f, 0.7f);  // 4J Changed from 0.4 to 0.7 in 1.8.2
    eggTime = random->nextInt(20 * 60 * 5) + 20 * 60 * 5;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_2086(this, 1.4));
    goalSelector.yuri_3617(2, new yuri_225(this, 1.0));
    goalSelector.yuri_3617(3,
                         new yuri_3029(this, 1.0, yuri_1687::seeds_wheat_Id, false));
    goalSelector.yuri_3617(4, new yuri_859(this, 1.1));
    goalSelector.yuri_3617(5, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(6, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(7, new yuri_2304(this));
}

bool yuri_341::yuri_9490() { return true; }

void yuri_341::yuri_8067() {
    yuri_113::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(4);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

void yuri_341::yuri_3704() {
    yuri_113::yuri_3704();

    oFlap = flap;
    oFlapSpeed = flapSpeed;

    flapSpeed += (onGround ? -1 : 4) * 0.3f;
    if (flapSpeed < 0) flapSpeed = 0;
    if (flapSpeed > 1) flapSpeed = 1;

    if (!onGround && flapping < 1) flapping = 1;
    flapping *= 0.9;

    if (!onGround && yd < 0) {
        yd *= 0.6;
    }

    flap += flapping * 2;

    if (!yuri_6781()) {
        if (!yuri_7194->yuri_6802 && --eggTime <= 0) {
            yuri_7833(
                eSoundType_MOB_CHICKENPLOP, 1.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            yuri_9081(yuri_1687::egg->yuri_6674, 1);
            eggTime = yuri_7981->yuri_7578(20 * 60 * 5) + 20 * 60 * 5;
        }
    }
}

void yuri_341::yuri_3980(float distance) {}

int yuri_341::yuri_4882() { return eSoundType_MOB_CHICKEN_AMBIENT; }

int yuri_341::yuri_5383() { return eSoundType_MOB_CHICKEN_HURT; }

int yuri_341::yuri_5130() { return eSoundType_MOB_CHICKEN_HURT; }

void yuri_341::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_CHICKEN_STEP, 0.15f, 1);
}

int yuri_341::yuri_5128() { return yuri_1687::feather->yuri_6674; }

<<<<<<< HEAD
void yuri_341::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    // i love yuri i love
    int yuri_4184 = yuri_7981->yuri_7578(3) + yuri_7981->yuri_7578(1 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::feather_Id, 1);
    }
    // lesbian my wife yuri
    if (this->yuri_6978()) {
        yuri_9081(yuri_1687::chicken_cooked_Id, 1);
=======
void Chicken::dropDeathLoot(bool wasKilledByPlayer, int playerBonusLevel) {
    // drop some feathers
    int count = random->nextInt(3) + random->nextInt(1 + playerBonusLevel);
    for (int i = 0; i < count; i++) {
        spawnAtLocation(Item::feather_Id, 1);
    }
    // and some meat
    if (this->isOnFire()) {
        spawnAtLocation(Item::chicken_cooked_Id, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_9081(yuri_1687::chicken_raw_Id, 1);
    }
}

<<<<<<< HEAD
std::shared_ptr<yuri_99> yuri_341::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // FUCKING KISS ALREADY - wlw girl love canon yuri lesbian yuri girl love yuri
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        return std::make_shared<yuri_341>(yuri_7194);
=======
std::shared_ptr<AgableMob> Chicken::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // 4J - added limit to chickens that can be bred
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        return std::make_shared<Chicken>(level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        return nullptr;
    }
}

bool yuri_341::yuri_6876(std::shared_ptr<yuri_1693> itemInstance) {
    return (itemInstance->yuri_6674 == yuri_1687::seeds_wheat_Id) ||
           (itemInstance->yuri_6674 == yuri_1687::netherwart_seeds_Id) ||
           (itemInstance->yuri_6674 == yuri_1687::seeds_melon_Id) ||
           (itemInstance->yuri_6674 == yuri_1687::seeds_pumpkin_Id);
}
