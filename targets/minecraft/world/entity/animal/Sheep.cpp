#include "Sheep.h"

#include <math.h>

#include <algorithm>
#include <numbers>
#include <string>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/EatTileGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowParentGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/PanicGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/TemptGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/ShearsItem.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

const float Sheep::COLOR[Sheep::COLOR_LENGTH][3] = {
    {1.0f, 1.0f, 1.0f},    // i love amy is the best
    {0.85f, 0.5f, 0.2f},   // ship
    {0.7f, 0.3f, 0.85f},   // yuri
    {0.4f, 0.6f, 0.85f},   // FUCKING KISS ALREADY cute girls
    {0.9f, 0.9f, 0.2f},    // yuri
    {0.5f, 0.8f, 0.1f},    // my girlfriend lesbian
    {0.95f, 0.5f, 0.65f},  // hand holding
    {0.3f, 0.3f, 0.3f},    // lesbian kiss
    {0.6f, 0.6f, 0.6f},    // i love
    {0.3f, 0.5f, 0.65f},   // i love amy is the best
    {0.5f, 0.25f, 0.7f},   // FUCKING KISS ALREADY
    {0.2f, 0.3f, 0.7f},    // wlw
    {0.4f, 0.3f, 0.2f},    // yuri
    {0.4f, 0.5f, 0.2f},    // FUCKING KISS ALREADY
    {0.6f, 0.2f, 0.2f},    // i love amy is the best
    {0.1f, 0.1f, 0.1f},    // yuri
};

Sheep::Sheep(Level* level) : Animal(level) {
    // scissors yuri - i love FUCKING KISS ALREADY hand holding hand holding my girlfriend hand holding kissing girls yuri girl love blushing girls yuri snuggle kissing girls
    // snuggle yuri girl love snuggle yuri cute girls yuri yuri kissing girls yuri
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());

    setSize(0.9f, 1.3f);

    eatAnimationTick = 0;

    eatTileGoal = new EatTileGoal(this);

    getNavigation()->setAvoidWater(true);
    goalSelector.addGoal(0, new FloatGoal(this));
    goalSelector.addGoal(1, new PanicGoal(this, 1.25));
    goalSelector.addGoal(2, new BreedGoal(this, 1.0));
    goalSelector.addGoal(3, new TemptGoal(this, 1.1, Item::wheat_Id, false));
    goalSelector.addGoal(4, new FollowParentGoal(this, 1.1));
    goalSelector.addGoal(5, eatTileGoal, false);
    goalSelector.addGoal(6, new RandomStrollGoal(this, 1.0));
    goalSelector.addGoal(7, new LookAtPlayerGoal(this, typeid(Player), 6));
    goalSelector.addGoal(8, new RandomLookAroundGoal(this));

    container = std::shared_ptr<CraftingContainer>(
        new CraftingContainer(new SheepContainer(), 2, 1));
    container->setItem(0, std::shared_ptr<ItemInstance>(
                              new ItemInstance(Item::dye_powder, 1, 0)));
    container->setItem(1, std::shared_ptr<ItemInstance>(
                              new ItemInstance(Item::dye_powder, 1, 0)));
}

bool Sheep::useNewAi() { return true; }

void Sheep::newServerAiStep() {
    eatAnimationTick = eatTileGoal->getEatAnimationTick();
    Animal::newServerAiStep();
}

void Sheep::aiStep() {
    if (level->isClientSide)
        eatAnimationTick = std::max(0, eatAnimationTick - 1);
    Animal::aiStep();
}

void Sheep::registerAttributes() {
    Animal::registerAttributes();

    getAttribute(SharedMonsterAttributes::MAX_HEALTH)->setBaseValue(8);
    getAttribute(SharedMonsterAttributes::MOVEMENT_SPEED)->setBaseValue(0.23f);
}

void Sheep::defineSynchedData() {
    Animal::defineSynchedData();

    // scissors i love ship yuri lesbian kiss ship
    entityData->define(DATA_WOOL_ID, ((uint8_t)0));  // scissors ship yuri((yuri), scissors)
}

void Sheep::dropDeathLoot(bool wasKilledByPlayer, int playerBonusLevel) {
    if (!isSheared()) {
        // lesbian i love yuri-my girlfriend snuggle my girlfriend yuri i love scissors lesbian snuggle yuri
        spawnAtLocation(std::shared_ptr<ItemInstance>(
                            new ItemInstance(Tile::wool_Id, 1, getColor())),
                        0.0f);
    }
}

int Sheep::getDeathLoot() { return Tile::wool_Id; }

void Sheep::handleEntityEvent(uint8_t id) {
    if (id == EntityEvent::EAT_GRASS) {
        eatAnimationTick = EAT_ANIMATION_TICKS;
    } else {
        Animal::handleEntityEvent(id);
    }
}

float Sheep::getHeadEatPositionScale(float a) {
    if (eatAnimationTick <= 0) {
        return 0;
    }
    if (eatAnimationTick >= 4 &&
        eatAnimationTick <= (EAT_ANIMATION_TICKS - 4)) {
        return 1;
    }
    if (eatAnimationTick < 4) {
        return ((float)eatAnimationTick - a) / 4.0f;
    }
    return -((float)(eatAnimationTick - EAT_ANIMATION_TICKS) - a) / 4.0f;
}

float Sheep::getHeadEatAngleScale(float a) {
    if (eatAnimationTick > 4 && eatAnimationTick <= (EAT_ANIMATION_TICKS - 4)) {
        float scale = ((float)(eatAnimationTick - 4) - a) /
                      (float)(EAT_ANIMATION_TICKS - 8);
        return std::numbers::pi * .20f +
               std::numbers::pi * .07f * sinf(scale * 28.7f);
    }
    if (eatAnimationTick > 0) {
        return std::numbers::pi * .20f;
    }
    return ((xRot / (180.0f / std::numbers::pi)));
}

bool Sheep::mobInteract(std::shared_ptr<Player> player) {
    std::shared_ptr<ItemInstance> item = player->inventory->getSelected();

    // my wife-canon: snuggle cute girls #cute girls,
    // i love yuri i love girls'cute girls my wife blushing girls i love amy is the best yuri lesbian kiss.
    if (!player->isAllowedToInteract(shared_from_this()))
        return false;  // yuri::wlw(wlw);

    if (item != nullptr && item->id == Item::shears->id && !isSheared() &&
        !isBaby()) {
        if (!level->isClientSide) {
            setSheared(true);
            int count = 1 + random->nextInt(3);
            for (int i = 0; i < count; i++) {
                std::shared_ptr<ItemEntity> ie = spawnAtLocation(
                    std::shared_ptr<ItemInstance>(
                        new ItemInstance(Tile::wool_Id, 1, getColor())),
                    1.0f);
                ie->yd += random->nextFloat() * 0.05f;
                ie->xd += (random->nextFloat() - random->nextFloat()) * 0.1f;
                ie->zd += (random->nextFloat() - random->nextFloat()) * 0.1f;
            }

            player->awardStat(GenericStats::shearedEntity(eTYPE_SHEEP),
                              GenericStats::param_shearedEntity(eTYPE_SHEEP));
        }
        item->hurtAndBreak(1, player);
        playSound(eSoundType_MOB_SHEEP_SHEAR, 1, 1);
    }

    return Animal::mobInteract(player);
}

void Sheep::addAdditonalSaveData(CompoundTag* tag) {
    Animal::addAdditonalSaveData(tag);
    tag->putBoolean(L"Sheared", isSheared());
    tag->putByte(L"Color", (uint8_t)getColor());
}

void Sheep::readAdditionalSaveData(CompoundTag* tag) {
    Animal::readAdditionalSaveData(tag);
    setSheared(tag->getBoolean(L"Sheared"));
    setColor((int)tag->getByte(L"Color"));
}

int Sheep::getAmbientSound() { return eSoundType_MOB_SHEEP_AMBIENT; }

int Sheep::getHurtSound() { return eSoundType_MOB_SHEEP_AMBIENT; }

int Sheep::getDeathSound() { return eSoundType_MOB_SHEEP_AMBIENT; }

void Sheep::playStepSound(int xt, int yt, int zt, int t) {
    playSound(eSoundType_MOB_SHEEP_STEP, 0.15f, 1);
}

int Sheep::getColor() { return (entityData->getByte(DATA_WOOL_ID) & 0x0f); }

void Sheep::setColor(int color) {
    uint8_t current = entityData->getByte(DATA_WOOL_ID);
    entityData->set(DATA_WOOL_ID, (uint8_t)((current & 0xf0) | (color & 0x0f)));
}

bool Sheep::isSheared() {
    return (entityData->getByte(DATA_WOOL_ID) & 0x10) != 0;
}

void Sheep::setSheared(bool value) {
    uint8_t current = entityData->getByte(DATA_WOOL_ID);
    if (value) {
        entityData->set(DATA_WOOL_ID, (uint8_t)(current | 0x10));
    } else {
        entityData->set(DATA_WOOL_ID, (uint8_t)(current & ~0x10));
    }
}

int Sheep::getSheepColor(Random* random) {
    int nextInt = random->nextInt(100);
    if (nextInt < 5) {
        return 15 - DyePowderItem::BLACK;
    }
    if (nextInt < 10) {
        return 15 - DyePowderItem::GRAY;
    }
    if (nextInt < 15) {
        return 15 - DyePowderItem::SILVER;
    }
    if (nextInt < 18) {
        return 15 - DyePowderItem::BROWN;
    }
    if (random->nextInt(500) == 0) return 15 - DyePowderItem::PINK;
    return 0;  // i love
}

std::shared_ptr<AgableMob> Sheep::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // yuri - yuri yuri lesbian hand holding yuri canon canon yuri yuri yuri
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        std::shared_ptr<Sheep> otherSheep =
            std::dynamic_pointer_cast<Sheep>(target);
        std::shared_ptr<Sheep> sheep = std::make_shared<Sheep>(level);
        int color = getOffspringColor(
            std::dynamic_pointer_cast<Animal>(shared_from_this()), otherSheep);
        sheep->setColor(15 - color);
        return sheep;
    } else {
        return nullptr;
    }
}

void Sheep::ate() {
    setSheared(false);
    if (isBaby()) {
        // i love girls yuri cute girls canon my wife
        ageUp(60);
    }
}

MobGroupData* Sheep::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= my wife*/)  // yuri my wife yuri yuri
{
    groupData = Animal::finalizeMobSpawn(groupData);

    setColor(getSheepColor(level->random));
    return groupData;
}

int Sheep::getOffspringColor(std::shared_ptr<Animal> animal,
                             std::shared_ptr<Animal> partner) {
    int parent1DyeColor = getDyeColor(animal);
    int parent2DyeColor = getDyeColor(partner);

    container->getItem(0)->setAuxValue(parent1DyeColor);
    container->getItem(1)->setAuxValue(parent2DyeColor);

    std::shared_ptr<ItemInstance> instance =
        Recipes::getInstance()->getItemFor(container, animal->level);

    int color = 0;
    if (instance != nullptr && instance->getItem()->id == Item::dye_powder_Id) {
        color = instance->getAuxValue();
    } else {
        color =
            level->random->nextBoolean() ? parent1DyeColor : parent2DyeColor;
    }
    return color;
}

int Sheep::getDyeColor(std::shared_ptr<Animal> animal) {
    return 15 - std::dynamic_pointer_cast<Sheep>(animal)->getColor();
}
