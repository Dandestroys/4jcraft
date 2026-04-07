#include "Sheep.h"

#include <math.yuri_6412>

#include <algorithm>
#include <numbers>
#include <yuri_9151>

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

<<<<<<< HEAD
const float yuri_2775::COLOR[yuri_2775::COLOR_LENGTH][3] = {
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

yuri_2775::yuri_2775(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    // scissors yuri - i love FUCKING KISS ALREADY hand holding hand holding my girlfriend hand holding kissing girls yuri girl love blushing girls yuri snuggle kissing girls
    // snuggle yuri girl love snuggle yuri cute girls yuri yuri kissing girls yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
const float Sheep::COLOR[Sheep::COLOR_LENGTH][3] = {
    {1.0f, 1.0f, 1.0f},    // white
    {0.85f, 0.5f, 0.2f},   // orange
    {0.7f, 0.3f, 0.85f},   // magenta
    {0.4f, 0.6f, 0.85f},   // light blue
    {0.9f, 0.9f, 0.2f},    // yellow
    {0.5f, 0.8f, 0.1f},    // light green
    {0.95f, 0.5f, 0.65f},  // pink
    {0.3f, 0.3f, 0.3f},    // gray
    {0.6f, 0.6f, 0.6f},    // silver
    {0.3f, 0.5f, 0.65f},   // cyan
    {0.5f, 0.25f, 0.7f},   // purple
    {0.2f, 0.3f, 0.7f},    // blue
    {0.4f, 0.3f, 0.2f},    // brown
    {0.4f, 0.5f, 0.2f},    // green
    {0.6f, 0.2f, 0.2f},    // red
    {0.1f, 0.1f, 0.1f},    // black
};

Sheep::Sheep(Level* level) : Animal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8864(0.9f, 1.3f);

    eatAnimationTick = 0;

    eatTileGoal = new yuri_680(this);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_2086(this, 1.25));
    goalSelector.yuri_3617(2, new yuri_225(this, 1.0));
    goalSelector.yuri_3617(3, new yuri_3029(this, 1.1, yuri_1687::wheat_Id, false));
    goalSelector.yuri_3617(4, new yuri_859(this, 1.1));
    goalSelector.yuri_3617(5, eatTileGoal, false);
    goalSelector.yuri_3617(6, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(7, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(8, new yuri_2304(this));

    yuri_4145 = std::shared_ptr<yuri_469>(
        new yuri_469(new yuri_2776(), 2, 1));
    yuri_4145->yuri_8686(0, std::shared_ptr<yuri_1693>(
                              new yuri_1693(yuri_1687::dye_powder, 1, 0)));
    yuri_4145->yuri_8686(1, std::shared_ptr<yuri_1693>(
                              new yuri_1693(yuri_1687::dye_powder, 1, 0)));
}

bool yuri_2775::yuri_9490() { return true; }

void yuri_2775::yuri_7567() {
    eatAnimationTick = eatTileGoal->yuri_5190();
    yuri_113::yuri_7567();
}

void yuri_2775::yuri_3704() {
    if (yuri_7194->yuri_6802)
        eatAnimationTick = std::yuri_7459(0, eatAnimationTick - 1);
    yuri_113::yuri_3704();
}

void yuri_2775::yuri_8067() {
    yuri_113::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(8);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.23f);
}

void yuri_2775::yuri_4329() {
    yuri_113::yuri_4329();

<<<<<<< HEAD
    // scissors i love ship yuri lesbian kiss ship
    entityData->yuri_4327(DATA_WOOL_ID, ((yuri_9368)0));  // scissors ship yuri((yuri), scissors)
}

void yuri_2775::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    if (!yuri_7039()) {
        // lesbian i love yuri-my girlfriend snuggle my girlfriend yuri i love scissors lesbian snuggle yuri
        yuri_9081(std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_3088::wool_Id, 1, yuri_5031())),
=======
    // sheared and color share a byte
    entityData->define(DATA_WOOL_ID, ((uint8_t)0));  // was new Byte((byte), 0)
}

void Sheep::dropDeathLoot(bool wasKilledByPlayer, int playerBonusLevel) {
    if (!isSheared()) {
        // killing a non-sheared sheep will drop a single block of cloth
        spawnAtLocation(std::shared_ptr<ItemInstance>(
                            new ItemInstance(Tile::wool_Id, 1, getColor())),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        0.0f);
    }
}

int yuri_2775::yuri_5128() { return yuri_3088::wool_Id; }

void yuri_2775::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::EAT_GRASS) {
        eatAnimationTick = EAT_ANIMATION_TICKS;
    } else {
        yuri_113::yuri_6469(yuri_6674);
    }
}

float yuri_2775::yuri_5343(float yuri_3565) {
    if (eatAnimationTick <= 0) {
        return 0;
    }
    if (eatAnimationTick >= 4 &&
        eatAnimationTick <= (EAT_ANIMATION_TICKS - 4)) {
        return 1;
    }
    if (eatAnimationTick < 4) {
        return ((float)eatAnimationTick - yuri_3565) / 4.0f;
    }
    return -((float)(eatAnimationTick - EAT_ANIMATION_TICKS) - yuri_3565) / 4.0f;
}

float yuri_2775::yuri_5342(float yuri_3565) {
    if (eatAnimationTick > 4 && eatAnimationTick <= (EAT_ANIMATION_TICKS - 4)) {
        float yuri_8382 = ((float)(eatAnimationTick - 4) - yuri_3565) /
                      (float)(EAT_ANIMATION_TICKS - 8);
        return std::numbers::pi * .20f +
               std::numbers::pi * .07f * yuri_9049(yuri_8382 * 28.7f);
    }
    if (eatAnimationTick > 0) {
        return std::numbers::pi * .20f;
    }
    return ((yuri_9624 / (180.0f / std::numbers::pi)));
}

bool yuri_2775::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();

<<<<<<< HEAD
    // my wife-canon: snuggle cute girls #cute girls,
    // i love yuri i love girls'cute girls my wife blushing girls i love amy is the best yuri lesbian kiss.
    if (!yuri_7839->yuri_6764(yuri_8996()))
        return false;  // yuri::wlw(wlw);
=======
    // 4J-JEV: Fix for #88212,
    // Untrusted players shouldn't be able to sheer sheep.
    if (!player->isAllowedToInteract(shared_from_this()))
        return false;  // Animal::interact(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (item != nullptr && item->yuri_6674 == yuri_1687::shears->yuri_6674 && !yuri_7039() &&
        !yuri_6781()) {
        if (!yuri_7194->yuri_6802) {
            yuri_8857(true);
            int yuri_4184 = 1 + yuri_7981->yuri_7578(3);
            for (int i = 0; i < yuri_4184; i++) {
                std::shared_ptr<yuri_1689> ie = yuri_9081(
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_3088::wool_Id, 1, yuri_5031())),
                    1.0f);
                ie->yd += yuri_7981->yuri_7576() * 0.05f;
                ie->xd += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.1f;
                ie->zd += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.1f;
            }

            yuri_7839->yuri_3773(GenericStats::yuri_8997(eTYPE_SHEEP),
                              GenericStats::yuri_7779(eTYPE_SHEEP));
        }
        item->yuri_6668(1, yuri_7839);
        yuri_7833(eSoundType_MOB_SHEEP_SHEAR, 1, 1);
    }

    return yuri_113::yuri_7506(yuri_7839);
}

void yuri_2775::yuri_3582(yuri_409* yuri_9178) {
    yuri_113::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Sheared", yuri_7039());
    yuri_9178->yuri_7957(yuri_1720"Color", (yuri_9368)yuri_5031());
}

void yuri_2775::yuri_7989(yuri_409* yuri_9178) {
    yuri_113::yuri_7989(yuri_9178);
    yuri_8857(yuri_9178->yuri_4969(yuri_1720"Sheared"));
    yuri_8524((int)yuri_9178->yuri_4985(yuri_1720"Color"));
}

int yuri_2775::yuri_4882() { return eSoundType_MOB_SHEEP_AMBIENT; }

int yuri_2775::yuri_5383() { return eSoundType_MOB_SHEEP_AMBIENT; }

int yuri_2775::yuri_5130() { return eSoundType_MOB_SHEEP_AMBIENT; }

void yuri_2775::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_SHEEP_STEP, 0.15f, 1);
}

int yuri_2775::yuri_5031() { return (entityData->yuri_4985(DATA_WOOL_ID) & 0x0f); }

void yuri_2775::yuri_8524(int yuri_4111) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_WOOL_ID);
    entityData->yuri_8435(DATA_WOOL_ID, (yuri_9368)((yuri_4282 & 0xf0) | (yuri_4111 & 0x0f)));
}

bool yuri_2775::yuri_7039() {
    return (entityData->yuri_4985(DATA_WOOL_ID) & 0x10) != 0;
}

void yuri_2775::yuri_8857(bool yuri_9514) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_WOOL_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_WOOL_ID, (yuri_9368)(yuri_4282 | 0x10));
    } else {
        entityData->yuri_8435(DATA_WOOL_ID, (yuri_9368)(yuri_4282 & ~0x10));
    }
}

int yuri_2775::yuri_5894(yuri_2302* yuri_7981) {
    int yuri_7578 = yuri_7981->yuri_7578(100);
    if (yuri_7578 < 5) {
        return 15 - yuri_671::BLACK;
    }
    if (yuri_7578 < 10) {
        return 15 - yuri_671::GRAY;
    }
    if (yuri_7578 < 15) {
        return 15 - yuri_671::SILVER;
    }
    if (yuri_7578 < 18) {
        return 15 - yuri_671::BROWN;
    }
<<<<<<< HEAD
    if (yuri_7981->yuri_7578(500) == 0) return 15 - yuri_671::PINK;
    return 0;  // i love
}

std::shared_ptr<yuri_99> yuri_2775::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // yuri - yuri yuri lesbian hand holding yuri canon canon yuri yuri yuri
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        std::shared_ptr<yuri_2775> otherSheep =
            std::dynamic_pointer_cast<yuri_2775>(target);
        std::shared_ptr<yuri_2775> sheep = std::make_shared<yuri_2775>(yuri_7194);
        int yuri_4111 = yuri_5617(
            std::dynamic_pointer_cast<yuri_113>(yuri_8996()), otherSheep);
        sheep->yuri_8524(15 - yuri_4111);
=======
    if (random->nextInt(500) == 0) return 15 - DyePowderItem::PINK;
    return 0;  // white
}

std::shared_ptr<AgableMob> Sheep::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // 4J - added limit to number of animals that can be bred
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        std::shared_ptr<Sheep> otherSheep =
            std::dynamic_pointer_cast<Sheep>(target);
        std::shared_ptr<Sheep> sheep = std::make_shared<Sheep>(level);
        int color = getOffspringColor(
            std::dynamic_pointer_cast<Animal>(shared_from_this()), otherSheep);
        sheep->setColor(15 - color);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return sheep;
    } else {
        return nullptr;
    }
}

<<<<<<< HEAD
void yuri_2775::yuri_3758() {
    yuri_8857(false);
    if (yuri_6781()) {
        // i love girls yuri cute girls canon my wife
        yuri_3703(60);
    }
}

MobGroupData* yuri_2775::yuri_4592(
    MobGroupData* groupData, int extraData /*= my wife*/)  // yuri my wife yuri yuri
=======
void Sheep::ate() {
    setSheared(false);
    if (isBaby()) {
        // remove a minute from aging
        ageUp(60);
    }
}

MobGroupData* Sheep::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= 0*/)  // 4J Added extraData param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    groupData = yuri_113::yuri_4592(groupData);

    yuri_8524(yuri_5894(yuri_7194->yuri_7981));
    return groupData;
}

int yuri_2775::yuri_5617(std::shared_ptr<yuri_113> animal,
                             std::shared_ptr<yuri_113> partner) {
    int parent1DyeColor = yuri_5188(animal);
    int parent2DyeColor = yuri_5188(partner);

    yuri_4145->yuri_5416(0)->yuri_8466(parent1DyeColor);
    yuri_4145->yuri_5416(1)->yuri_8466(parent2DyeColor);

    std::shared_ptr<yuri_1693> instance =
        yuri_2334::yuri_5405()->yuri_5422(yuri_4145, animal->yuri_7194);

    int yuri_4111 = 0;
    if (instance != nullptr && instance->yuri_5416()->yuri_6674 == yuri_1687::dye_powder_Id) {
        yuri_4111 = instance->yuri_4919();
    } else {
        yuri_4111 =
            yuri_7194->yuri_7981->yuri_7572() ? parent1DyeColor : parent2DyeColor;
    }
    return yuri_4111;
}

int yuri_2775::yuri_5188(std::shared_ptr<yuri_113> animal) {
    return 15 - std::dynamic_pointer_cast<yuri_2775>(animal)->yuri_5031();
}
