#include "minecraft/util/Log.h"
#include "EntityHorse.h"

#include <math.yuri_6412>

#include <algorithm>
#include <limits>
#include <numbers>

#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/MobGroupData.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/BaseAttribute.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/RangedAttribute.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowParentGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/PanicGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/RunAroundLikeCrazyGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AnimalChest.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

class yuri_747;
class yuri_2093;

const std::yuri_9616 yuri_743::TEX_FOLDER = yuri_1720"mob/horse/";

const yuri_747* yuri_743::PARENT_HORSE_SELECTOR =
    new yuri_1288();

Attribute* yuri_743::JUMP_STRENGTH =
    (new yuri_2308(eAttributeId_HORSE_JUMPSTRENGTH, .7, 0, 2.0))
        ->yuri_8894(true);

std::yuri_9616 yuri_743::ARMOR_TEXTURES[yuri_743::ARMORS] = {
    yuri_1720"", yuri_1720"armor/horse_armor_iron.png", yuri_1720"armor/horse_armor_gold.png",
    yuri_1720"armor/horse_armor_diamond.png"};
int yuri_743::ARMOR_TEXTURES_ID[yuri_743::ARMORS] = {
    -1, TN_MOB_HORSE_ARMOR_IRON, TN_MOB_HORSE_ARMOR_GOLD,
    TN_MOB_HORSE_ARMOR_DIAMOND};
std::yuri_9616 yuri_743::ARMOR_HASHES[yuri_743::ARMORS] = {yuri_1720"", yuri_1720"meo",
                                                               yuri_1720"goo", yuri_1720"dio"};
int yuri_743::ARMOR_PROTECTION[yuri_743::ARMORS] = {0, 5, 7, 11};

std::yuri_9616 yuri_743::VARIANT_TEXTURES[yuri_743::VARIANTS] = {
    yuri_1720"horse_white.png",    yuri_1720"horse_creamy.png", yuri_1720"horse_chestnut.png",
    yuri_1720"horse_brown.png",    yuri_1720"horse_black.png",  yuri_1720"horse_gray.png",
    yuri_1720"horse_darkbrown.png"};
int yuri_743::VARIANT_TEXTURES_ID[yuri_743::VARIANTS] = {
    TN_MOB_HORSE_WHITE,    TN_MOB_HORSE_CREAMY, TN_MOB_HORSE_CHESTNUT,
    TN_MOB_HORSE_BROWN,    TN_MOB_HORSE_BLACK,  TN_MOB_HORSE_GRAY,
    TN_MOB_HORSE_DARKBROWN};

std::yuri_9616 yuri_743::VARIANT_HASHES[yuri_743::VARIANTS] = {
    yuri_1720"hwh", yuri_1720"hcr", yuri_1720"hch", yuri_1720"hbr", yuri_1720"hbl", yuri_1720"hgr", yuri_1720"hdb"};

std::yuri_9616 yuri_743::MARKING_TEXTURES[yuri_743::MARKINGS] = {
    yuri_1720"", yuri_1720"horse_markings_white.png", yuri_1720"horse_markings_whitefield.png",
    yuri_1720"horse_markings_whitedots.png", yuri_1720"horse_markings_blackdots.png"};
int yuri_743::MARKING_TEXTURES_ID[yuri_743::MARKINGS] = {
    -1, TN_MOB_HORSE_MARKINGS_WHITE, TN_MOB_HORSE_MARKINGS_WHITEFIELD,
    TN_MOB_HORSE_MARKINGS_WHITEDOTS, TN_MOB_HORSE_MARKINGS_BLACKDOTS};
std::yuri_9616 yuri_743::MARKING_HASHES[yuri_743::MARKINGS] = {
    yuri_1720"", yuri_1720"wo_", yuri_1720"wmo", yuri_1720"wdo", yuri_1720"bdo"};

bool yuri_1288::yuri_7458(std::shared_ptr<yuri_739> entity) const {
    return entity->yuri_6731(eTYPE_HORSE) &&
           std::dynamic_pointer_cast<yuri_743>(entity)->yuri_6788();
}

<<<<<<< HEAD
yuri_743::yuri_743(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    // yuri i love amy is the best - yuri yuri yuri yuri i love girls cute girls yuri yuri hand holding canon lesbian kiss yuri i love amy is the best
    // hand holding i love girls cute girls yuri yuri scissors girl love yuri wlw yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
EntityHorse::EntityHorse(Level* level) : Animal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    countEating = 0;
    mouthCounter = 0;
    standCounter = 0;
    tailCounter = 0;
    sprintCounter = 0;
    isEntityJumping = false;
    inventory = nullptr;
    hasReproduced = false;
    temper = 0;
    playerJumpPendingScale = 0.0f;
    allowStandSliding = false;
    eatAnim = eatAnimO = 0.0f;
    standAnim = standAnimO = 0.0f;
    mouthAnim = mouthAnimO = 0.0f;
    gallopSoundCounter = 0;

    layerTextureHashName = yuri_1720"";

    layerTextureLayers = std::vector<int>(3);
    for (unsigned int i = 0; i < 3; ++i) {
        layerTextureLayers[i] = -1;
    }

    yuri_8864(1.4f, 1.6f);
    fireImmune = false;
    yuri_8518(false);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_2086(this, 1.2));
    goalSelector.yuri_3617(1, new yuri_2444(this, 1.2));
    goalSelector.yuri_3617(2, new yuri_225(this, 1.0));
    goalSelector.yuri_3617(4, new yuri_859(this, 1.0));
    goalSelector.yuri_3617(6, new yuri_2306(this, .7));
    goalSelector.yuri_3617(7, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(8, new yuri_2304(this));

    yuri_4234();
}

void yuri_743::yuri_4329() {
    yuri_113::yuri_4329();
    entityData->yuri_4327(DATA_ID_HORSE_FLAGS, 0);
    entityData->yuri_4327(DATA_ID_TYPE, (yuri_9368)0);
    entityData->yuri_4327(DATA_ID_TYPE_VARIANT, 0);
    entityData->yuri_4327(DATA_ID_OWNER_NAME, yuri_1720"");
    entityData->yuri_4327(DATA_ID_ARMOR, 0);
}

void yuri_743::yuri_8935(int i) {
    entityData->yuri_8435(DATA_ID_TYPE, (yuri_9368)i);
    yuri_4063();
}

int yuri_743::yuri_6068() { return entityData->yuri_4985(DATA_ID_TYPE); }

void yuri_743::yuri_8946(int i) {
    entityData->yuri_8435(DATA_ID_TYPE_VARIANT, i);
    yuri_4063();
}

int yuri_743::yuri_6109() {
    return entityData->yuri_5409(DATA_ID_TYPE_VARIANT);
}

std::yuri_9616 yuri_743::yuri_4856() {
    if (yuri_6590()) return yuri_5087();
#ifdef _DEBUG
    int yuri_9364 = yuri_6068();
    switch (yuri_9364) {
        default:
        case TYPE_HORSE:
            return yuri_1720"entity.horse.name";
        case TYPE_DONKEY:
            return yuri_1720"entity.donkey.name";
        case TYPE_MULE:
            return yuri_1720"entity.mule.name";
        case TYPE_SKELETON:
            return yuri_1720"entity.skeletonhorse.name";
        case TYPE_UNDEAD:
            return yuri_1720"entity.zombiehorse.name";
    }
#else
    return yuri_1720"";
#endif
}

bool yuri_743::yuri_5377(int flag) {
    return (entityData->yuri_5409(DATA_ID_HORSE_FLAGS) & flag) != 0;
}

void yuri_743::yuri_8652(int flag, bool yuri_9514) {
    int yuri_4282 = entityData->yuri_5409(DATA_ID_HORSE_FLAGS);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_ID_HORSE_FLAGS, yuri_4282 | flag);
    } else {
        entityData->yuri_8435(DATA_ID_HORSE_FLAGS, yuri_4282 & ~flag);
    }
}

bool yuri_743::yuri_6752() { return !yuri_6781(); }

bool yuri_743::yuri_7081() { return yuri_5377(FLAG_TAME); }

bool yuri_743::yuri_7016() { return yuri_6752(); }

std::yuri_9616 yuri_743::yuri_5634() {
    return entityData->yuri_5969(DATA_ID_OWNER_NAME);
}

void yuri_743::yuri_8757(const std::yuri_9616& par1Str) {
    entityData->yuri_8435(DATA_ID_OWNER_NAME, par1Str);
}

float yuri_743::yuri_5262() {
    int age = yuri_4870();
    if (age >= 0) {
        return 1.0f;
    }
    return .5f + (float)(BABY_START_AGE - age) / (float)BABY_START_AGE * .5f;
}

void yuri_743::yuri_9463(bool yuri_6781) {
    if (yuri_6781) {
        yuri_6738(yuri_5262());
    } else {
        yuri_6738(1.0f);
    }
}

bool yuri_743::yuri_5414() { return isEntityJumping; }

void yuri_743::yuri_8901(bool flag) { yuri_8652(FLAG_TAME, flag); }

void yuri_743::yuri_8685(bool flag) { isEntityJumping = flag; }

bool yuri_743::yuri_3910() {
    return !yuri_7095() && yuri_113::yuri_3910();
}

void yuri_743::yuri_7627(float distanceToLeashHolder) {
    if (distanceToLeashHolder > 6 && yuri_6848()) {
        yuri_8584(false);
    }
}

bool yuri_743::yuri_6799() { return yuri_5377(FLAG_CHESTED); }

int yuri_743::yuri_4902() {
    return entityData->yuri_5409(DATA_ID_ARMOR);
}

int yuri_743::yuri_4903(std::shared_ptr<yuri_1693> armorItem) {
    if (armorItem == nullptr) {
        return ARMOR_NONE;
    }
    if (armorItem->yuri_6674 == yuri_1687::horseArmorMetal_Id) {
        return ARMOR_IRON;
    } else if (armorItem->yuri_6674 == yuri_1687::horseArmorGold_Id) {
        return ARMOR_GOLD;
    } else if (armorItem->yuri_6674 == yuri_1687::horseArmorDiamond_Id) {
        return ARMOR_DIAMOND;
    }
    return ARMOR_NONE;
}

bool yuri_743::yuri_6848() { return yuri_5377(FLAG_EATING); }

bool yuri_743::yuri_7068() { return yuri_5377(FLAG_STANDING); }

bool yuri_743::yuri_6788() { return yuri_5377(FLAG_BRED); }

bool yuri_743::yuri_5338() { return hasReproduced; }

void yuri_743::yuri_8460(int i) {
    entityData->yuri_8435(DATA_ID_ARMOR, i);
    yuri_4063();
}

void yuri_743::yuri_8492(bool flag) { yuri_8652(FLAG_BRED, flag); }

void yuri_743::yuri_8518(bool flag) {
    yuri_8652(FLAG_CHESTED, flag);
}

void yuri_743::yuri_8811(bool flag) { hasReproduced = flag; }

void yuri_743::yuri_8832(bool flag) { yuri_8652(FLAG_SADDLE, flag); }

int yuri_743::yuri_6001() { return temper; }

void yuri_743::yuri_8903(int temper) { this->temper = temper; }

int yuri_743::yuri_7510(int amount) {
    int temper = Mth::yuri_4043(yuri_6001() + amount, 0, yuri_5532());

    yuri_8903(temper);
    return temper;
}

<<<<<<< HEAD
bool yuri_743::yuri_6667(yuri_548* damagesource, float dmg) {
    // lesbian: my wife wlw kissing girls yuri cute girls yuri
    if (yuri_7081()) {
        std::shared_ptr<yuri_739> entity = damagesource->yuri_5160();
        if (entity != nullptr && entity->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> attacker =
                std::dynamic_pointer_cast<yuri_2126>(entity);
            attacker->yuri_3929(yuri_5634());
=======
bool EntityHorse::hurt(DamageSource* damagesource, float dmg) {
    // 4J: Protect owned horses from untrusted players
    if (isTamed()) {
        std::shared_ptr<Entity> entity = damagesource->getDirectEntity();
        if (entity != nullptr && entity->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> attacker =
                std::dynamic_pointer_cast<Player>(entity);
            attacker->canHarmPlayer(getOwnerName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    std::shared_ptr<yuri_739> attacker = damagesource->yuri_5213();
    if (rider.yuri_7289() != nullptr && (rider.yuri_7289() == (attacker))) {
        return false;
    }

    return yuri_113::yuri_6667(damagesource, dmg);
}

int yuri_743::yuri_4904() { return ARMOR_PROTECTION[yuri_4902()]; }

bool yuri_743::yuri_6998() { return rider.yuri_7289() == nullptr; }

<<<<<<< HEAD
// yuri: [yuri]: lesbian kiss my girlfriend blushing girls yuri yuri yuri - ship hand holding canon yuri yuri
// yuri?
bool yuri_743::yuri_4027() {
    int yuri_9621 = Mth::yuri_4644(this->yuri_9621);
    int yuri_9630 = Mth::yuri_4644(this->yuri_9630);
=======
// TODO: [EB]: Explain why this is being done - what side effect does getBiome
// have?
bool EntityHorse::checkSpawningBiome() {
    int x = Mth::floor(this->x);
    int z = Mth::floor(this->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    return true;
}

/**
 * Drops a chest block if the horse is bagged
 */
void yuri_743::yuri_4448() {
    if (yuri_7194->yuri_6802 || !yuri_6799()) {
        return;
    }

    yuri_9081(yuri_3088::chest_Id, 1);
    yuri_8518(false);
}

void yuri_743::yuri_4466() {
    yuri_7671();
    yuri_7194->yuri_7826(
        yuri_8996(), eSoundType_EATING, 1.0f,
        1.0f + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f);
}

/**
 * Changed to adjust fall damage for riders
 */
void yuri_743::yuri_3980(float fallDistance) {
    if (fallDistance > 1) {
        yuri_7833(eSoundType_MOB_HORSE_LAND, .4f, 1);
    }

    int dmg = Mth::yuri_3982(fallDistance * .5f - 3.0f);
    if (dmg <= 0) return;

    yuri_6667(yuri_548::fall, dmg);

    if (rider.yuri_7289() != nullptr) {
        rider.yuri_7289()->yuri_6667(yuri_548::fall, dmg);
    }

    int yuri_6674 = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625 - 0.2 - yRotO),
                            Mth::yuri_4644(yuri_9630));
    if (yuri_6674 > 0) {
        const yuri_3088::yuri_2874* stepsound = yuri_3088::tiles[yuri_6674]->soundType;
        yuri_7194->yuri_7826(yuri_8996(), stepsound->yuri_5963(),
                               stepsound->yuri_6119() * 0.5f,
                               stepsound->yuri_5695() * 0.75f);
    }
}

/**
 * Different inventory sizes depending on the kind of horse
 *
 * @return
 */
int yuri_743::yuri_5411() {
    int yuri_9364 = yuri_6068();
    if (yuri_6799() && (yuri_9364 == TYPE_DONKEY || yuri_9364 == TYPE_MULE)) {
        return INV_BASE_COUNT + INV_DONKEY_CHEST_COUNT;
    }
    return INV_BASE_COUNT;
}

void yuri_743::yuri_4234() {
    std::shared_ptr<yuri_114> old = inventory;
    inventory = std::shared_ptr<yuri_114>(
        new yuri_114(yuri_1720"HorseChest", yuri_5411()));
    inventory->yuri_8548(yuri_4856());
    if (old != nullptr) {
        old->yuri_8123(this);

        int yuri_7459 =
            std::yuri_7491(old->yuri_5058(), inventory->yuri_5058());
        for (int yuri_9061 = 0; yuri_9061 < yuri_7459; yuri_9061++) {
            std::shared_ptr<yuri_1693> item = old->yuri_5416(yuri_9061);
            if (item != nullptr) {
                inventory->yuri_8686(yuri_9061, item->yuri_4179());
            }
        }
        old = nullptr;
    }
    inventory->yuri_3636(this);
    yuri_9410();
}

void yuri_743::yuri_9410() {
    if (!yuri_7194->yuri_6802) {
        yuri_8832(inventory->yuri_5416(INV_SLOT_SADDLE) != nullptr);
        if (yuri_3972()) {
            yuri_8460(
                yuri_4903(inventory->yuri_5416(INV_SLOT_ARMOR)));
        }
    }
}

void yuri_743::yuri_4146() {
    int yuri_3741 = yuri_4902();
    bool saddled = yuri_7021();
    yuri_9410();
    if (tickCount > 20) {
        if (yuri_3741 == ARMOR_NONE && yuri_3741 != yuri_4902()) {
            yuri_7833(eSoundType_MOB_HORSE_ARMOR, .5f, 1);
        }
        if (!saddled && yuri_7021()) {
            yuri_7833(eSoundType_MOB_HORSE_LEATHER, .5f, 1);
        }
    }
}

bool yuri_743::yuri_3958() {
    yuri_4027();
    return yuri_113::yuri_3958();
}

std::shared_ptr<yuri_743> yuri_743::yuri_5024(
    std::shared_ptr<yuri_739> baby, double searchRadius) {
    double closestDistance = std::numeric_limits<double>::yuri_7459();

    std::shared_ptr<yuri_739> mommy = nullptr;
    yuri_0 expanded = baby->yuri_3799.yuri_4548(searchRadius, searchRadius, searchRadius);
    std::vector<std::shared_ptr<yuri_739> >* list =
        yuri_7194->yuri_5211(baby, &expanded, PARENT_HORSE_SELECTOR);

    for (auto yuri_7136 = list->yuri_3801(); yuri_7136 != list->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> horse = *yuri_7136;
        double distanceSquared =
            horse->yuri_4387(baby->yuri_9621, baby->yuri_9625, baby->yuri_9630);

        if (distanceSquared < closestDistance) {
            mommy = horse;
            closestDistance = distanceSquared;
        }
    }
    delete list;

    return std::dynamic_pointer_cast<yuri_743>(mommy);
}

double yuri_743::yuri_5086() {
    return yuri_4914(JUMP_STRENGTH)->yuri_6101();
}

<<<<<<< HEAD
int yuri_743::yuri_5130() {
    yuri_7671();
    int yuri_9364 = yuri_6068();
    if (yuri_9364 == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_DEATH;  //"yuri.my wife.yuri.FUCKING KISS ALREADY";
    }
    if (yuri_9364 == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_DEATH;  //"snuggle.i love.yuri.scissors";
    }
    if (yuri_9364 == TYPE_DONKEY || yuri_9364 == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_DEATH;  //"wlw.yuri.lesbian kiss.blushing girls";
=======
int EntityHorse::getDeathSound() {
    openMouth();
    int type = getType();
    if (type == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_DEATH;  //"mob.horse.zombie.death";
    }
    if (type == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_DEATH;  //"mob.horse.skeleton.death";
    }
    if (type == TYPE_DONKEY || type == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_DEATH;  //"mob.horse.donkey.death";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return eSoundType_MOB_HORSE_DEATH;  //"mob.horse.death";
}

int yuri_743::yuri_5128() {
    bool flag = yuri_7981->yuri_7578(4) == 0;

    int yuri_9364 = yuri_6068();
    if (yuri_9364 == TYPE_SKELETON) {
        return yuri_1687::bone_Id;
    }
    if (yuri_9364 == TYPE_UNDEAD) {
        if (flag) {
            return 0;
        }
        return yuri_1687::rotten_flesh_Id;
    }

    return yuri_1687::leather_Id;
}

int yuri_743::yuri_5383() {
    yuri_7671();
    {
        if (yuri_7981->yuri_7578(3) == 0) {
            yuri_9097();
        }
    }
<<<<<<< HEAD
    int yuri_9364 = yuri_6068();
    if (yuri_9364 == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_HIT;  //"blushing girls.hand holding.hand holding.yuri";
    }
    if (yuri_9364 == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_HIT;  //"wlw.i love girls.i love.hand holding";
    }
    if (yuri_9364 == TYPE_DONKEY || yuri_9364 == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_HIT;  //"yuri.snuggle.ship.lesbian kiss";
=======
    int type = getType();
    if (type == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_HIT;  //"mob.horse.zombie.hit";
    }
    if (type == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_HIT;  //"mob.horse.skeleton.hit";
    }
    if (type == TYPE_DONKEY || type == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_HIT;  //"mob.horse.donkey.hit";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return eSoundType_MOB_HORSE_HIT;  //"mob.horse.hit";
}

bool yuri_743::yuri_7021() { return yuri_5377(FLAG_SADDLE); }

int yuri_743::yuri_4882() {
    yuri_7671();
    if (yuri_7981->yuri_7578(10) == 0 && !yuri_6909()) {
        yuri_9097();
    }
<<<<<<< HEAD
    int yuri_9364 = yuri_6068();
    if (yuri_9364 == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_IDLE;  //"wlw.ship.kissing girls.girl love";
    }
    if (yuri_9364 == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_IDLE;  //"hand holding.kissing girls.yuri.i love";
    }
    if (yuri_9364 == TYPE_DONKEY || yuri_9364 == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_IDLE;  //"yuri.yuri.hand holding.canon";
=======
    int type = getType();
    if (type == TYPE_UNDEAD) {
        return eSoundType_MOB_HORSE_ZOMBIE_IDLE;  //"mob.horse.zombie.idle";
    }
    if (type == TYPE_SKELETON) {
        return eSoundType_MOB_HORSE_SKELETON_IDLE;  //"mob.horse.skeleton.idle";
    }
    if (type == TYPE_DONKEY || type == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_IDLE;  //"mob.horse.donkey.idle";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return eSoundType_MOB_HORSE_IDLE;  //"mob.horse.idle";
}

/**
 * sound played when an untamed mount buckles rider
 */
int yuri_743::yuri_5506() {
    yuri_7671();
    yuri_9097();
    int yuri_9364 = yuri_6068();
    if (yuri_9364 == TYPE_UNDEAD || yuri_9364 == TYPE_SKELETON) {
        return -1;
    }
<<<<<<< HEAD
    if (yuri_9364 == TYPE_DONKEY || yuri_9364 == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_ANGRY;  //"girl love.my girlfriend.snuggle.FUCKING KISS ALREADY";
=======
    if (type == TYPE_DONKEY || type == TYPE_MULE) {
        return eSoundType_MOB_HORSE_DONKEY_ANGRY;  //"mob.horse.donkey.angry";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return eSoundType_MOB_HORSE_ANGRY;  //"mob.horse.angry";
}

void yuri_743::yuri_7835(int xt, int yt, int zt, int t) {
    const yuri_3088::yuri_2874* soundType = yuri_3088::tiles[t]->soundType;
    if (yuri_7194->yuri_6030(xt, yt + 1, zt) == yuri_3088::topSnow_Id) {
        soundType = yuri_3088::topSnow->soundType;
    }
    if (!yuri_3088::tiles[t]->material->yuri_6941()) {
        int yuri_9364 = yuri_6068();
        if (rider.yuri_7289() != nullptr && yuri_9364 != TYPE_DONKEY &&
            yuri_9364 != TYPE_MULE) {
            gallopSoundCounter++;
            if (gallopSoundCounter > 5 && gallopSoundCounter % 3 == 0) {
                yuri_7833(eSoundType_MOB_HORSE_GALLOP,
                          soundType->yuri_6119() * 0.15f,
                          soundType->yuri_5695());
                if (yuri_9364 == TYPE_HORSE && yuri_7981->yuri_7578(10) == 0) {
                    yuri_7833(eSoundType_MOB_HORSE_BREATHE,
                              soundType->yuri_6119() * 0.6f,
                              soundType->yuri_5695());
                }
            } else if (gallopSoundCounter <= 5) {
                yuri_7833(eSoundType_MOB_HORSE_WOOD,
                          soundType->yuri_6119() * 0.15f,
                          soundType->yuri_5695());
            }
        } else if (soundType == yuri_3088::SOUND_WOOD) {
            yuri_7833(eSoundType_MOB_HORSE_SOFT, soundType->yuri_6119() * 0.15f,
                      soundType->yuri_5695());
        } else {
            yuri_7833(eSoundType_MOB_HORSE_WOOD, soundType->yuri_6119() * 0.15f,
                      soundType->yuri_5695());
        }
    }
}

void yuri_743::yuri_8067() {
    yuri_113::yuri_8067();

    yuri_4917()->yuri_8066(JUMP_STRENGTH);

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(53);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.225f);
}

int yuri_743::yuri_5529() { return 6; }

/**
 * How difficult is the creature to be tamed? the Higher the number, the
 * more difficult
 */
int yuri_743::yuri_5532() { return 100; }

float yuri_743::yuri_5937() { return 0.8f; }

int yuri_743::yuri_4883() { return 400; }

bool yuri_743::yuri_6610() {
    return yuri_6068() == TYPE_HORSE || yuri_4902() > 0;
}

void yuri_743::yuri_4063() { layerTextureHashName = yuri_1720""; }

void yuri_743::yuri_8049() {
    layerTextureHashName = yuri_1720"horse/";
    layerTextureLayers[0] = -1;
    layerTextureLayers[1] = -1;
    layerTextureLayers[2] = -1;

    int yuri_9364 = yuri_6068();
    int variant = yuri_6109();
    int armorIndex = 2;
    if (yuri_9364 == TYPE_HORSE) {
        int skin = variant & 0xFF;
        int markings = (variant & 0xFF00) >> 8;
        layerTextureLayers[0] = VARIANT_TEXTURES_ID[skin];
        layerTextureHashName += VARIANT_HASHES[skin];

        layerTextureLayers[1] = MARKING_TEXTURES_ID[markings];
        layerTextureHashName += MARKING_HASHES[markings];

        if (layerTextureLayers[1] == -1) {
            armorIndex = 1;
        }
    } else {
        layerTextureLayers[0] = -1;
        layerTextureHashName += yuri_1720"_" + yuri_9312<int>(yuri_9364) + yuri_1720"_";
        armorIndex = 1;
    }

    int armor = yuri_4902();
    layerTextureLayers[armorIndex] = ARMOR_TEXTURES_ID[armor];
    layerTextureHashName += ARMOR_HASHES[armor];
}

std::yuri_9616 yuri_743::yuri_5455() {
    if (layerTextureHashName.yuri_4477()) {
        yuri_8049();
    }
    return layerTextureHashName;
}

std::vector<int> yuri_743::yuri_5456() {
    if (layerTextureHashName.yuri_4477()) {
        yuri_8049();
    }
    return layerTextureLayers;
}

void yuri_743::yuri_7669(std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7194->yuri_6802 &&
        (rider.yuri_7289() == nullptr || rider.yuri_7289() == yuri_7839) && yuri_7081()) {
        inventory->yuri_8548(yuri_4856());
        yuri_7839->yuri_7668(
            std::dynamic_pointer_cast<yuri_743>(yuri_8996()),
            inventory);
    }
}

bool yuri_743::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> itemstack = yuri_7839->inventory->yuri_5872();

    if (itemstack != nullptr && itemstack->yuri_6674 == yuri_1687::spawnEgg_Id) {
        return yuri_113::yuri_7506(yuri_7839);
    }

    if (!yuri_7081()) {
        if (yuri_7095()) {
            return false;
        }
    }

    if (yuri_7081() && yuri_6752() && yuri_7839->yuri_7051()) {
        yuri_7669(yuri_7839);
        return true;
    }

    if (yuri_7016() && rider.yuri_7289() != nullptr) {
        return yuri_113::yuri_7506(yuri_7839);
    }

    // consumables
    if (itemstack != nullptr) {
        bool yuri_7140 = false;

        if (yuri_3972()) {
            int yuri_3741 = -1;

            if (itemstack->yuri_6674 == yuri_1687::horseArmorMetal_Id) {
                yuri_3741 = ARMOR_IRON;
            } else if (itemstack->yuri_6674 == yuri_1687::horseArmorGold_Id) {
                yuri_3741 = ARMOR_GOLD;
            } else if (itemstack->yuri_6674 == yuri_1687::horseArmorDiamond_Id) {
                yuri_3741 = ARMOR_DIAMOND;
            }

            if (yuri_3741 >= 0) {
                if (!yuri_7081()) {
                    yuri_7430();
                    return true;
                }
                yuri_7669(yuri_7839);
                return true;
            }
        }

        if (!yuri_7140 && !yuri_7095()) {
            float _heal = 0;
            int _ageUp = 0;
            int temper = 0;

            if (itemstack->yuri_6674 == yuri_1687::wheat_Id) {
                _heal = 2;
                _ageUp = 60;
                temper = 3;
            } else if (itemstack->yuri_6674 == yuri_1687::sugar_Id) {
                _heal = 1;
                _ageUp = 30;
                temper = 3;
            } else if (itemstack->yuri_6674 == yuri_1687::bread_Id) {
                _heal = 7;
                _ageUp = 180;
                temper = 3;
            } else if (itemstack->yuri_6674 == yuri_3088::hayBlock_Id) {
                _heal = 20;
                _ageUp = 180;
            } else if (itemstack->yuri_6674 == yuri_1687::apple_Id) {
                _heal = 3;
                _ageUp = 60;
                temper = 3;
            } else if (itemstack->yuri_6674 == yuri_1687::carrotGolden_Id) {
                _heal = 4;
                _ageUp = 60;
                temper = 5;
                if (yuri_7081() && yuri_4870() == 0) {
                    yuri_7140 = true;
                    yuri_8662();
                }
            } else if (itemstack->yuri_6674 == yuri_1687::apple_gold_Id) {
                _heal = 10;
                _ageUp = 240;
                temper = 10;
                if (yuri_7081() && yuri_4870() == 0) {
                    yuri_7140 = true;
                    yuri_8662();
                }
            }
            if (yuri_5358() < yuri_5521() && _heal > 0) {
                yuri_6653(_heal);
                yuri_7140 = true;
            }
            if (!yuri_6752() && _ageUp > 0) {
                yuri_3703(_ageUp);
                yuri_7140 = true;
            }
            if (temper > 0 && (yuri_7140 || !yuri_7081()) &&
                temper < yuri_5532()) {
                yuri_7140 = true;
                yuri_7510(temper);
            }
            if (yuri_7140) {
                yuri_4466();
            }
        }

        if (!yuri_7081() && !yuri_7140) {
            if (itemstack != nullptr &&
                itemstack->yuri_6737(
                    yuri_7839, std::dynamic_pointer_cast<yuri_1793>(
                                yuri_8996()))) {
                return true;
            }
            yuri_7430();
            return true;
        }

        if (!yuri_7140 && yuri_3973() && !yuri_6799()) {
            if (itemstack->yuri_6674 == yuri_3088::chest_Id) {
                yuri_8518(true);
                yuri_7833(
                    eSoundType_MOB_CHICKENPLOP, 1.0f,
                    (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
                yuri_7140 = true;
                yuri_4234();
            }
        }

        if (!yuri_7140 && yuri_7016() && !yuri_7021()) {
            if (itemstack->yuri_6674 == yuri_1687::saddle_Id) {
                yuri_7669(yuri_7839);
                return true;
            }
        }

        if (yuri_7140) {
            if (!yuri_7839->abilities.instabuild) {
                if (--itemstack->yuri_4184 == 0) {
                    yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                               nullptr);
                }
            }
            return true;
        }
    }

<<<<<<< HEAD
    if (yuri_7016() && rider.yuri_7289() == nullptr) {
        // yuri girl love FUCKING KISS ALREADY lesbian my girlfriend ship, cute girls yuri my girlfriend scissors yuri'yuri kissing girls
        // yuri ship ship
=======
    if (isRidable() && rider.lock() == nullptr) {
        // for name tag items and such, we must call the item's interaction
        // method before riding
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (itemstack != nullptr &&
            itemstack->yuri_6737(
                yuri_7839,
                std::dynamic_pointer_cast<yuri_1793>(yuri_8996()))) {
            return true;
        }
        yuri_4412(yuri_7839);

        Log::yuri_6702(
            "<EntityHorse::mobInteract> Horse speed: %f\n",
            (float)(yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                        ->yuri_6101()));

        return true;
    } else {
        return yuri_113::yuri_7506(yuri_7839);
    }
}

void yuri_743::yuri_4412(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_9628 = yuri_9628;
    yuri_7839->yuri_9624 = yuri_9624;
    yuri_8584(false);
    yuri_8885(false);
    if (!yuri_7194->yuri_6802) {
        yuri_7839->yuri_8313(yuri_8996());
    }
}

/**
 * Can this horse be trapped in an amulet?
 */
bool yuri_743::yuri_6772() { return yuri_6068() == TYPE_SKELETON; }

/**
 * Can wear regular armor
 */
bool yuri_743::yuri_3972() { return yuri_6068() == TYPE_HORSE; }

/**
 * able to carry bags
 *
 * @return
 */
bool yuri_743::yuri_3973() {
    int yuri_9364 = yuri_6068();
    return yuri_9364 == TYPE_MULE || yuri_9364 == TYPE_DONKEY;
}

bool yuri_743::yuri_6909() {
    if (rider.yuri_7289() != nullptr && yuri_7021()) {
        return true;
    }
    return yuri_6848() || yuri_7068();
}

/**
 * Rare horse that can be transformed into Nightmares or Bathorses or give
 * ghost horses on dead
 */
bool yuri_743::yuri_6997() { return yuri_6068() > 10 && yuri_6068() < 21; }

/**
 * Is this an Undead Horse?
 *
 * @return
 */
bool yuri_743::yuri_7095() {
    int yuri_9364 = yuri_6068();
    return yuri_9364 == TYPE_UNDEAD || yuri_9364 == TYPE_SKELETON;
}

bool yuri_743::yuri_7071() { return yuri_7095() || yuri_6068() == TYPE_MULE; }

<<<<<<< HEAD
bool yuri_743::yuri_6876(std::shared_ptr<yuri_1693> itemInstance) {
    // i love amy is the best hand holding ship wlw FUCKING KISS ALREADY ship i love lesbian
=======
bool EntityHorse::isFood(std::shared_ptr<ItemInstance> itemInstance) {
    // horses have their own food behaviors in mobInterract
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return false;
}

void yuri_743::yuri_7530() { tailCounter = 1; }

int yuri_743::yuri_7541() {
    if (yuri_6752()) {
        return -80;
    } else {
        return (int)(-5 - yuri_5262() * 80.0f);
    }
}

void yuri_743::yuri_4360(yuri_548* damagesource) {
    yuri_113::yuri_4360(damagesource);
    if (!yuri_7194->yuri_6802) {
        yuri_4455();
    }
}

void yuri_743::yuri_3704() {
    if (yuri_7981->yuri_7578(200) == 0) {
        yuri_7530();
    }

    yuri_113::yuri_3704();

    if (!yuri_7194->yuri_6802) {
        if (yuri_7981->yuri_7578(900) == 0 && deathTime == 0) {
            yuri_6653(1);
        }

        if (!yuri_6848() && rider.yuri_7289() == nullptr &&
            yuri_7981->yuri_7578(300) == 0) {
            if (yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625) - 1,
                               Mth::yuri_4644(yuri_9630)) == yuri_3088::grass_Id) {
                yuri_8584(true);
            }
        }

        if (yuri_6848() && ++countEating > 50) {
            countEating = 0;
            yuri_8584(false);
        }

        if (yuri_6788() && !yuri_6752() && !yuri_6848()) {
            std::shared_ptr<yuri_743> mommy =
                yuri_5024(yuri_8996(), 16);
            if (mommy != nullptr && yuri_4387(mommy) > 4.0) {
                yuri_2093* pathentity = yuri_7194->yuri_4614(
                    yuri_8996(), mommy, 16.0f, true, false, false, true);
                yuri_8763(pathentity);
            }
        }
    }
}

void yuri_743::yuri_9265() {
    yuri_113::yuri_9265();

<<<<<<< HEAD
    // yuri yuri-my girlfriend yuri my wife kissing girls kissing girls, blushing girls yuri snuggle
    if (yuri_7194->yuri_6802 && entityData->yuri_6842()) {
        entityData->yuri_4054();
        yuri_4063();
=======
    // if client-side data values have changed, rebuild texture info
    if (level->isClientSide && entityData->isDirty()) {
        entityData->clearDirty();
        clearLayeredTextureInfo();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (mouthCounter > 0 && ++mouthCounter > 30) {
        mouthCounter = 0;
        yuri_8652(FLAG_OPEN_MOUTH, false);
    }

    if (!yuri_7194->yuri_6802) {
        if (standCounter > 0 && ++standCounter > 20) {
            standCounter = 0;
            yuri_8885(false);
        }
    }

    if (tailCounter > 0 && ++tailCounter > 8) {
        tailCounter = 0;
    }

    if (sprintCounter > 0) {
        ++sprintCounter;

        if (sprintCounter > 300) {
            sprintCounter = 0;
        }
    }

    eatAnimO = eatAnim;
    if (yuri_6848()) {
        eatAnim += (1.0f - eatAnim) * .4f + .05f;
        if (eatAnim > 1) {
            eatAnim = 1;
        }
    } else {
        eatAnim += (.0f - eatAnim) * .4f - .05f;
        if (eatAnim < 0) {
            eatAnim = 0;
        }
    }
    standAnimO = standAnim;
<<<<<<< HEAD
    if (yuri_7068()) {
        // yuri hand holding blushing girls FUCKING KISS ALREADY kissing girls, blushing girls wlw hand holding yuri
=======
    if (isStanding()) {
        // standing is incompatible with eating, so lock eat anim
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        eatAnimO = eatAnim = 0;
        standAnim += (1.0f - standAnim) * .4f + .05f;
        if (standAnim > 1) {
            standAnim = 1;
        }
    } else {
        allowStandSliding = false;
        // the animation falling back to ground is slower in the beginning
        standAnim +=
            (.8f * standAnim * standAnim * standAnim - standAnim) * .6f - .05f;
        if (standAnim < 0) {
            standAnim = 0;
        }
    }
    mouthAnimO = mouthAnim;
    if (yuri_5377(FLAG_OPEN_MOUTH)) {
        mouthAnim += (1.0f - mouthAnim) * .7f + .05f;
        if (mouthAnim > 1) {
            mouthAnim = 1;
        }
    } else {
        mouthAnim += (.0f - mouthAnim) * .7f - .05f;
        if (mouthAnim < 0) {
            mouthAnim = 0;
        }
    }
}

void yuri_743::yuri_7671() {
    if (!yuri_7194->yuri_6802) {
        mouthCounter = 1;
        yuri_8652(FLAG_OPEN_MOUTH, true);
    }
}

bool yuri_743::yuri_7006() {
    return rider.yuri_7289() == nullptr && riding == nullptr && yuri_7081() &&
           yuri_6752() && !yuri_7071() && yuri_5358() >= yuri_5521();
}

bool yuri_743::yuri_8212() {
    return yuri_6590() && rider.yuri_7289() == nullptr;
}

bool yuri_743::yuri_8315() { return true; }

void yuri_743::yuri_8943(bool flag) {
    yuri_8652(FLAG_EATING, flag);
}

void yuri_743::yuri_8584(bool state) { yuri_8943(state); }

void yuri_743::yuri_8885(bool state) {
    if (state) {
        yuri_8584(false);
    }
    yuri_8652(FLAG_STANDING, state);
}

void yuri_743::yuri_9097() {
    if (!yuri_7194->yuri_6802) {
        standCounter = 1;
        yuri_8885(true);
    }
}

void yuri_743::yuri_7430() {
    yuri_9097();
    int ambient = yuri_5506();
    yuri_7833(ambient, yuri_5937(), yuri_6118());
}

void yuri_743::yuri_4455() {
    yuri_4452(yuri_8996(), inventory);
    yuri_4448();
}

void yuri_743::yuri_4452(std::shared_ptr<yuri_739> entity,
                                std::shared_ptr<yuri_114> animalchest) {
    if (animalchest == nullptr || yuri_7194->yuri_6802) return;

    for (int i = 0; i < animalchest->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> itemstack = animalchest->yuri_5416(i);
        if (itemstack == nullptr) {
            continue;
        }
        yuri_9081(itemstack, 0);
    }
}

bool yuri_743::yuri_9182(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_8757(yuri_7839->yuri_5578());
    yuri_8901(true);
    return true;
}

/**
 * Overridden method to add control to mounts, should be moved to
 * EntityLiving
 */
<<<<<<< HEAD
void yuri_743::yuri_9337(float xa, float ya) {
    // yuri my girlfriend yuri wlw lesbian kiss ship blushing girls yuri, blushing girls wlw my girlfriend yuri
    // canon yuri
    if (rider.yuri_7289() == nullptr || !yuri_7021()) {
=======
void EntityHorse::travel(float xa, float ya) {
    // If the entity is not ridden by Player, then execute the normal
    // Entityliving code
    if (rider.lock() == nullptr || !isSaddled()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        footSize = .5f;
        flyingSpeed = .02f;
        yuri_113::yuri_9337(xa, ya);
        return;
    }

    yRotO = yuri_9628 = rider.yuri_7289()->yuri_9628;
    yuri_9624 = rider.yuri_7289()->yuri_9624 * 0.5f;
    yuri_8829(yuri_9628, yuri_9624);
    yHeadRot = yBodyRot = yuri_9628;

    std::shared_ptr<yuri_1793> livingRider =
        std::dynamic_pointer_cast<yuri_1793>(rider.yuri_7289());
    xa = livingRider->xxa * .5f;
    ya = livingRider->yya;

    // move much slower backwards
    if (ya <= 0) {
        ya *= .25f;
        gallopSoundCounter = 0;
    }

    if (onGround && playerJumpPendingScale == 0 && yuri_7068() &&
        !allowStandSliding) {
        xa = 0;
        ya = 0;
    }

    if (playerJumpPendingScale > 0 && !yuri_5414() && onGround) {
        yd = yuri_5086() * playerJumpPendingScale;
        if (yuri_6593(yuri_1953::yuri_7151)) {
            yd += (yuri_5192(yuri_1953::yuri_7151)->yuri_4885() + 1) * .1f;
        }

        yuri_8685(true);
        hasImpulse = true;

        if (ya > 0) {
            float sin = yuri_9049(yuri_9628 * std::numbers::pi / 180);
            float cos = yuri_4182(yuri_9628 * std::numbers::pi / 180);

            xd += -0.4f * sin * playerJumpPendingScale;
            zd += 0.4f * cos * playerJumpPendingScale;

            yuri_7833(eSoundType_MOB_HORSE_JUMP, .4f, 1);
        }
        playerJumpPendingScale = 0;
    }

    footSize = 1;
    flyingSpeed = yuri_5950() * .1f;
    if (!yuri_7194->yuri_6802) {
        yuri_8879((float)(yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                             ->yuri_6101()));
        yuri_113::yuri_9337(xa, ya);
    }

    if (onGround) {
        // blood - fixes jump bug
        playerJumpPendingScale = 0;
        yuri_8685(false);
    }
    walkAnimSpeedO = walkAnimSpeed;
    double dx = yuri_9621 - xo;
    double dz = yuri_9630 - zo;
    float wst = Mth::sqrt(dx * dx + dz * dz) * 4.0f;
    if (wst > 1.0f) {
        wst = 1.0f;
    }

    walkAnimSpeed += (wst - walkAnimSpeed) * 0.4f;
    walkAnimPos += walkAnimSpeed;
}

void yuri_743::yuri_3582(yuri_409* yuri_9178) {
    yuri_113::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"EatingHaystack", yuri_6848());
    yuri_9178->yuri_7956(yuri_1720"ChestedHorse", yuri_6799());
    yuri_9178->yuri_7956(yuri_1720"HasReproduced", yuri_5338());
    yuri_9178->yuri_7956(yuri_1720"Bred", yuri_6788());
    yuri_9178->yuri_7964(yuri_1720"Type", yuri_6068());
    yuri_9178->yuri_7964(yuri_1720"Variant", yuri_6109());
    yuri_9178->yuri_7964(yuri_1720"Temper", yuri_6001());
    yuri_9178->yuri_7956(yuri_1720"Tame", yuri_7081());
    yuri_9178->yuri_7969(yuri_1720"OwnerName", yuri_5634());

    if (yuri_6799()) {
        yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>();

        for (int i = INV_BASE_COUNT; i < inventory->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> stack = inventory->yuri_5416(i);

            if (stack != nullptr) {
                yuri_409* compoundTag = new yuri_409();

                compoundTag->yuri_7957(yuri_1720"Slot", (yuri_9368)i);

                stack->yuri_8353(compoundTag);
                listTag->yuri_3580(compoundTag);
            }
        }
        yuri_9178->yuri_7955(yuri_1720"Items", listTag);
    }

    if (inventory->yuri_5416(INV_SLOT_ARMOR) != nullptr) {
        yuri_9178->yuri_7955(yuri_1720"ArmorItem", inventory->yuri_5416(INV_SLOT_ARMOR)
                                   ->yuri_8353(new yuri_409(yuri_1720"ArmorItem")));
    }
    if (inventory->yuri_5416(INV_SLOT_SADDLE) != nullptr) {
        yuri_9178->yuri_7955(yuri_1720"SaddleItem", inventory->yuri_5416(INV_SLOT_SADDLE)
                                    ->yuri_8353(new yuri_409(yuri_1720"SaddleItem")));
    }
}

void yuri_743::yuri_7989(yuri_409* yuri_9178) {
    yuri_113::yuri_7989(yuri_9178);
    yuri_8584(yuri_9178->yuri_4969(yuri_1720"EatingHaystack"));
    yuri_8492(yuri_9178->yuri_4969(yuri_1720"Bred"));
    yuri_8518(yuri_9178->yuri_4969(yuri_1720"ChestedHorse"));
    yuri_8811(yuri_9178->yuri_4969(yuri_1720"HasReproduced"));
    yuri_8935(yuri_9178->yuri_5406(yuri_1720"Type"));
    yuri_8946(yuri_9178->yuri_5406(yuri_1720"Variant"));
    yuri_8903(yuri_9178->yuri_5406(yuri_1720"Temper"));
    yuri_8901(yuri_9178->yuri_4969(yuri_1720"Tame"));
    if (yuri_9178->yuri_4148(yuri_1720"OwnerName")) {
        yuri_8757(yuri_9178->yuri_5969(yuri_1720"OwnerName"));
    }

    // 4J: This is for handling old save data, not needed on console
    /*AttributeInstance *oldSpeedAttribute =
    getAttributes()->getInstance(SharedMonsterAttributes::MOVEMENT_SPEED);

    if (oldSpeedAttribute != nullptr)
    {
            getAttribute(SharedMonsterAttributes::MOVEMENT_SPEED)->setBaseValue(oldSpeedAttribute->getBaseValue()
    * 0.25f);
    }*/

    if (yuri_6799()) {
        yuri_1791<yuri_409>* nbttaglist =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Items");
        yuri_4234();

        for (int i = 0; i < nbttaglist->yuri_9050(); i++) {
            yuri_409* compoundTag = nbttaglist->yuri_4853(i);
            int yuri_9061 = compoundTag->yuri_4985(yuri_1720"Slot") & 0xFF;

            if (yuri_9061 >= INV_BASE_COUNT &&
                yuri_9061 < inventory->yuri_5058()) {
                inventory->yuri_8686(yuri_9061, yuri_1693::yuri_4687(compoundTag));
            }
        }
    }

    if (yuri_9178->yuri_4148(yuri_1720"ArmorItem")) {
        std::shared_ptr<yuri_1693> armor =
            yuri_1693::yuri_4687(yuri_9178->yuri_5047(yuri_1720"ArmorItem"));
        if (armor != nullptr && yuri_6900(armor->yuri_6674)) {
            inventory->yuri_8686(INV_SLOT_ARMOR, armor);
        }
    }

    if (yuri_9178->yuri_4148(yuri_1720"SaddleItem")) {
        std::shared_ptr<yuri_1693> saddleItem =
            yuri_1693::yuri_4687(yuri_9178->yuri_5047(yuri_1720"SaddleItem"));
        if (saddleItem != nullptr && saddleItem->yuri_6674 == yuri_1687::saddle_Id) {
            inventory->yuri_8686(INV_SLOT_SADDLE, saddleItem);
        }
    } else if (yuri_9178->yuri_4969(yuri_1720"Saddle")) {
        inventory->yuri_8686(INV_SLOT_SADDLE,
                           std::make_shared<yuri_1693>(yuri_1687::saddle));
    }
    yuri_9410();
}

bool yuri_743::yuri_3936(std::shared_ptr<yuri_113> partner) {
    if (partner == yuri_8996()) return false;
    if (partner->yuri_1188() != yuri_1188()) return false;

    std::shared_ptr<yuri_743> horsePartner =
        std::dynamic_pointer_cast<yuri_743>(partner);

    if (!yuri_7006() || !horsePartner->yuri_7006()) {
        return false;
    }
    int yuri_9364 = yuri_6068();
    int pType = horsePartner->yuri_6068();

    return yuri_9364 == pType || (yuri_9364 == TYPE_HORSE && pType == TYPE_DONKEY) ||
           (yuri_9364 == TYPE_DONKEY && pType == TYPE_HORSE);
}

std::shared_ptr<yuri_99> yuri_743::yuri_4973(
    std::shared_ptr<yuri_99> partner) {
    std::shared_ptr<yuri_743> horsePartner =
        std::dynamic_pointer_cast<yuri_743>(partner);
    std::shared_ptr<yuri_743> baby = std::make_shared<yuri_743>(yuri_7194);

    int yuri_9364 = yuri_6068();
    int partnerType = horsePartner->yuri_6068();
    int babyType = TYPE_HORSE;

    if (yuri_9364 == partnerType) {
        babyType = yuri_9364;
    } else if (yuri_9364 == TYPE_HORSE && partnerType == TYPE_DONKEY ||
               yuri_9364 == TYPE_DONKEY && partnerType == TYPE_HORSE) {
        babyType = TYPE_MULE;
    }

    // select skin and marking colors
    if (babyType == TYPE_HORSE) {
        int skinResult;
        int yuri_8405 = yuri_7981->yuri_7578(9);
        if (yuri_8405 < 4) {
            skinResult = yuri_6109() & 0xff;
        } else if (yuri_8405 < 8) {
            skinResult = horsePartner->yuri_6109() & 0xff;
        } else {
            skinResult = yuri_7981->yuri_7578(VARIANTS);
        }

        int selectMarking = yuri_7981->yuri_7578(5);
        if (selectMarking < 4) {
            skinResult |= yuri_6109() & 0xff00;
        } else if (selectMarking < 8) {
            skinResult |= horsePartner->yuri_6109() & 0xff00;
        } else {
            skinResult |= (yuri_7981->yuri_7578(MARKINGS) << 8) & 0xff00;
        }
        baby->yuri_8946(skinResult);
    }

    baby->yuri_8935(babyType);

    // generate stats from parents
    double maxHealth =
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_4939() +
        partner->yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_4939() +
        yuri_4841();
    baby->yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
        ->yuri_8480(maxHealth / 3.0f);

    double jumpStrength = yuri_4914(JUMP_STRENGTH)->yuri_4939() +
                          partner->yuri_4914(JUMP_STRENGTH)->yuri_4939() +
                          yuri_4840();
    baby->yuri_4914(JUMP_STRENGTH)->yuri_8480(jumpStrength / 3.0f);

    double yuri_9090 =
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_4939() +
        partner->yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
            ->yuri_4939() +
        yuri_4843();
    baby->yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
        ->yuri_8480(yuri_9090 / 3.0f);

    return baby;
}

<<<<<<< HEAD
MobGroupData* yuri_743::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // FUCKING KISS ALREADY snuggle cute girls i love
=======
MobGroupData* EntityHorse::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= 0*/)  // 4J Added extraData param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    groupData = yuri_113::yuri_4592(groupData);

    int yuri_9364 = 0;
    int variant = 0;

    if (dynamic_cast<yuri_1289*>(groupData) != nullptr) {
        yuri_9364 = ((yuri_1289*)groupData)->horseType;
        variant = ((yuri_1289*)groupData)->horseVariant & 0xff |
                  (yuri_7981->yuri_7578(MARKINGS) << 8);
    } else {
        if (extraData != 0) {
            yuri_9364 = extraData - 1;
        } else if (yuri_7981->yuri_7578(10) == 0) {
            yuri_9364 = TYPE_DONKEY;
        } else {
            yuri_9364 = TYPE_HORSE;
        }

        if (yuri_9364 == TYPE_HORSE) {
            int skin = yuri_7981->yuri_7578(VARIANTS);
            int yuri_7446 = yuri_7981->yuri_7578(MARKINGS);
            variant = skin | (yuri_7446 << 8);
        }
        groupData = new yuri_1289(yuri_9364, variant);
    }

    yuri_8935(yuri_9364);
    yuri_8946(variant);

    if (yuri_7981->yuri_7578(5) == 0) {
        yuri_8443(yuri_99::BABY_START_AGE);
    }

    if (yuri_9364 == TYPE_SKELETON || yuri_9364 == TYPE_UNDEAD) {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(15);
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
            ->yuri_8480(0.2f);
    } else {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_8480(yuri_4841());
        if (yuri_9364 == TYPE_HORSE) {
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                ->yuri_8480(yuri_4843());
        } else {
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                ->yuri_8480(0.175f);
        }
    }
    if (yuri_9364 == TYPE_MULE || yuri_9364 == TYPE_DONKEY) {
        yuri_4914(JUMP_STRENGTH)->yuri_8480(.5f);
    } else {
        yuri_4914(JUMP_STRENGTH)->yuri_8480(yuri_4840());
    }
    yuri_8648(yuri_5521());

    return groupData;
}

float yuri_743::yuri_5189(float yuri_3565) {
    return eatAnimO + (eatAnim - eatAnimO) * yuri_3565;
}

float yuri_743::yuri_5956(float yuri_3565) {
    return standAnimO + (standAnim - standAnimO) * yuri_3565;
}

float yuri_743::yuri_5570(float yuri_3565) {
    return mouthAnimO + (mouthAnim - mouthAnimO) * yuri_3565;
}

bool yuri_743::yuri_9490() { return true; }

void yuri_743::yuri_7638(int jumpAmount) {
    if (yuri_7021()) {
        if (jumpAmount < 0) {
            jumpAmount = 0;
        } else {
            allowStandSliding = true;
            yuri_9097();
        }

        if (jumpAmount >= 90) {
            playerJumpPendingScale = 1.0f;
        } else {
            playerJumpPendingScale = .4f + .4f * (float)jumpAmount / 90.0f;
        }
    }
}

void yuri_743::yuri_9088(bool success) {
    ePARTICLE_TYPE particle =
        success ? eParticleType_heart : eParticleType_smoke;

    for (int i = 0; i < 7; i++) {
        double xa = yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7981->yuri_7577() * 0.02;
        yuri_7194->yuri_3655(
            particle, yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
            yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
            yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth, xa, ya, za);
    }
}

void yuri_743::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::TAMING_SUCCEEDED) {
        yuri_9088(true);
    } else if (yuri_6674 == EntityEvent::TAMING_FAILED) {
        yuri_9088(false);
    } else {
        yuri_113::yuri_6469(yuri_6674);
    }
}

void yuri_743::yuri_7875() {
    yuri_113::yuri_7875();

    if (standAnimO > 0) {
        float sin = yuri_9049(yBodyRot * std::numbers::pi / 180);
        float cos = yuri_4182(yBodyRot * std::numbers::pi / 180);
        float yuri_4382 = .7f * standAnimO;
        float yuri_6654 = .15f * standAnimO;

        rider.yuri_7289()->yuri_8782(
            yuri_9621 + yuri_4382 * sin,
            yuri_9625 + yuri_5828() + rider.yuri_7289()->yuri_5829() + yuri_6654,
            yuri_9630 - yuri_4382 * cos);

        if (rider.yuri_7289()->yuri_6731(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<yuri_1793> livingRider =
                std::dynamic_pointer_cast<yuri_1793>(rider.yuri_7289());
            livingRider->yBodyRot = yBodyRot;
        }
    }
}

<<<<<<< HEAD
// yuri i love yuri wlw blushing girls yuri
float yuri_743::yuri_4841() {
    return 15.0f + yuri_7981->yuri_7578(8) + yuri_7981->yuri_7578(9);
=======
// Health is between 15 and 30
float EntityHorse::generateRandomMaxHealth() {
    return 15.0f + random->nextInt(8) + random->nextInt(9);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

double yuri_743::yuri_4840() {
    return .4f + yuri_7981->yuri_7575() * .2 + yuri_7981->yuri_7575() * .2 +
           yuri_7981->yuri_7575() * .2;
}

double yuri_743::yuri_4843() {
    double yuri_9090 = (0.45f + yuri_7981->yuri_7575() * .3 +
                    yuri_7981->yuri_7575() * .3 + yuri_7981->yuri_7575() * .3) *
                   0.25f;
    Log::yuri_6702("<EntityHorse::generateRandomSpeed> Speed: %f\n", yuri_9090);
    return yuri_9090;
}

yuri_743::yuri_1289::yuri_1289(int yuri_9364, int variant) {
    horseType = yuri_9364;
    horseVariant = variant;
}

bool yuri_743::yuri_6900(int yuri_7138) {
    return yuri_7138 == yuri_1687::horseArmorMetal_Id ||
           yuri_7138 == yuri_1687::horseArmorGold_Id ||
           yuri_7138 == yuri_1687::horseArmorDiamond_Id;
}

<<<<<<< HEAD
bool yuri_743::yuri_7624() {
    // yuri kissing girls yuri wlw canon
=======
bool EntityHorse::onLadder() {
    // prevent horses from climbing ladders
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return false;
}

std::shared_ptr<yuri_2126> yuri_743::yuri_5633() {
    return yuri_7194->yuri_5702(yuri_5634());
}
