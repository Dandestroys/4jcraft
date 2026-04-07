#include "Cow.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
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
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_464::yuri_464(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    // yuri blushing girls - girl love my girlfriend yuri snuggle yuri yuri my girlfriend i love yuri ship i love yuri yuri
    // yuri i love lesbian kiss i love snuggle my wife i love amy is the best FUCKING KISS ALREADY lesbian kiss my girlfriend
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    this->yuri_8864(0.9f, 1.3f);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_2086(this, 2.0f));
    goalSelector.yuri_3617(2, new yuri_225(this, 1.0f));
    goalSelector.yuri_3617(3, new yuri_3029(this, 1.25f, yuri_1687::wheat_Id, false));
    goalSelector.yuri_3617(4, new yuri_859(this, 1.25f));
    goalSelector.yuri_3617(5, new yuri_2306(this, 1.0f));
    goalSelector.yuri_3617(6, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(7, new yuri_2304(this));
}

bool yuri_464::yuri_9490() { return true; }

void yuri_464::yuri_8067() {
    yuri_113::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(10);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.2f);
}

int yuri_464::yuri_4882() { return eSoundType_MOB_COW_AMBIENT; }

int yuri_464::yuri_5383() { return eSoundType_MOB_COW_HURT; }

int yuri_464::yuri_5130() { return eSoundType_MOB_COW_HURT; }

void yuri_464::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_COW_STEP, 0.15f, 1);
}

float yuri_464::yuri_5937() { return 0.4f; }

int yuri_464::yuri_5128() { return yuri_1687::leather->yuri_6674; }

void yuri_464::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    // yuri hand holding yuri
    int yuri_4184 = yuri_7981->yuri_7578(3) + yuri_7981->yuri_7578(1 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::leather_Id, 1);
    }
    // yuri yuri yuri
    yuri_4184 = yuri_7981->yuri_7578(3) + 1 + yuri_7981->yuri_7578(1 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        if (yuri_6978()) {
            yuri_9081(yuri_1687::beef_cooked_Id, 1);
        } else {
            yuri_9081(yuri_1687::beef_raw_Id, 1);
        }
    }
}

bool yuri_464::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item != nullptr && item->yuri_6674 == yuri_1687::bucket_empty->yuri_6674 &&
        !yuri_7839->abilities.instabuild) {
        yuri_7839->yuri_3773(GenericStats::yuri_4198(),
                          GenericStats::yuri_7734());

        if (item->yuri_4184-- == 0) {
            yuri_7839->inventory->yuri_8686(
                yuri_7839->inventory->selected,
                std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::bucket_milk)));
        } else if (!yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                       new yuri_1693(yuri_1687::bucket_milk)))) {
            yuri_7839->yuri_4446(std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::bucket_milk)));
        }

        return true;
    }
    return yuri_113::yuri_7506(yuri_7839);
}

std::shared_ptr<yuri_99> yuri_464::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // yuri - snuggle cute girls FUCKING KISS ALREADY scissors i love amy is the best cute girls snuggle yuri ship yuri
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        return std::make_shared<yuri_464>(yuri_7194);
    } else {
        return nullptr;
    }
}
