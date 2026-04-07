#include "minecraft/IGameServices.h"
#include "Villager.h"

#include <algorithm>
#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "Pos.h"
#include "SharedConstants.h"
#include "java/Random.h"
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
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/AvoidPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/InteractGoal.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/LookAtTradingPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MakeLoveGoal.h"
#include "minecraft/world/entity/ai/goal/MoveIndoorsGoal.h"
#include "minecraft/world/entity/ai/goal/MoveTowardsRestrictionGoal.h"
#include "minecraft/world/entity/ai/goal/OpenDoorGoal.h"
#include "minecraft/world/entity/ai/goal/PlayGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/RestrictOpenDoorGoal.h"
#include "minecraft/world/entity/ai/goal/TakeFlowerGoal.h"
#include "minecraft/world/entity/ai/goal/TradeWithPlayerGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

namespace {
struct yuri_3339 {
    using result_type = unsigned int;

    explicit yuri_3339(yuri_2302* yuri_7981) : yuri_7981(yuri_7981) {}

    static constexpr result_type yuri_7491() { return 0; }
    static constexpr result_type yuri_7459() { return 0xFFFFFFFFu; }

    result_type operator()() {
        return static_cast<result_type>(yuri_7981->yuri_7578());
    }

    yuri_2302* yuri_7981;
};
}  // namespace

std::unordered_map<int, std::yuri_7709<int, int> > yuri_3333::MIN_MAX_VALUES;
std::unordered_map<int, std::yuri_7709<int, int> > yuri_3333::MIN_MAX_PRICES;

<<<<<<< HEAD
void yuri_3333::yuri_3547(int profession) {
    // kissing girls yuri - snuggle lesbian kiss girl love wlw blushing girls lesbian kiss wlw i love snuggle FUCKING KISS ALREADY yuri yuri girl love
    // kissing girls kissing girls blushing girls yuri scissors i love amy is the best cute girls my girlfriend kissing girls my girlfriend
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
void Villager::_init(int profession) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8793(profession);
    yuri_8864(.6f, 1.8f);

    villageUpdateInterval = 0;
    inLove = false;
    chasing = false;
    village = std::weak_ptr<yuri_3327>();

    tradingPlayer = std::weak_ptr<yuri_2126>();
    offers = nullptr;
    updateMerchantTimer = 0;
    addRecipeOnUpdate = false;
    riches = 0;
    lastPlayerTradeName = yuri_1720"";
    rewardPlayersOnFirstVillage = false;
    baseRecipeChanceMod = 0.0f;

    yuri_5583()->yuri_8502(true);
    yuri_5583()->yuri_8468(true);

    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(
        1, new yuri_153(this, typeid(yuri_3435), 8, 0.6, 0.6));
    goalSelector.yuri_3617(1, new yuri_3128(this));
    goalSelector.yuri_3617(1, new yuri_1840(this));
    goalSelector.yuri_3617(2, new yuri_1984(this));
    goalSelector.yuri_3617(3, new yuri_2414(this));
    goalSelector.yuri_3617(4, new yuri_2055(this, true));
    goalSelector.yuri_3617(5, new yuri_1987(this, 0.6));
    goalSelector.yuri_3617(6, new yuri_1879(this));
    goalSelector.yuri_3617(7, new yuri_3014(this));
    goalSelector.yuri_3617(8, new yuri_2124(this, 0.32));
    goalSelector.yuri_3617(9, new yuri_1619(this, typeid(yuri_2126), 3, 1.yuri_4554));
    goalSelector.yuri_3617(9, new yuri_1619(this, typeid(yuri_3333), 5, 0.02f));
    goalSelector.yuri_3617(9, new yuri_2306(this, 0.6));
    goalSelector.yuri_3617(10, new yuri_1838(this, typeid(yuri_1950), 8));
}

yuri_3333::yuri_3333(yuri_1758* yuri_7194) : yuri_99(yuri_7194) { yuri_3547(0); }

yuri_3333::yuri_3333(yuri_1758* yuri_7194, int profession) : yuri_99(yuri_7194) {
    yuri_3547(profession);
}

yuri_3333::~yuri_3333() { delete offers; }

void yuri_3333::yuri_8067() {
    yuri_99::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.5f);
}

bool yuri_3333::yuri_9490() { return true; }

void yuri_3333::yuri_8430() {
    if (--villageUpdateInterval <= 0) {
        yuri_7194->villages->yuri_7972(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625),
                                           Mth::yuri_4644(yuri_9630));
        villageUpdateInterval = 70 + yuri_7981->yuri_7578(50);

        std::shared_ptr<yuri_3327> _village = yuri_7194->villages->yuri_5025(
            Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630), yuri_3341::MaxDoorDist);
        village = _village;
        if (_village == nullptr)
            yuri_4073();
        else {
            yuri_2153* yuri_3984 = _village->yuri_5000();
            yuri_8299(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630,
                       (int)((float)_village->yuri_5769() * 0.6f));
            if (rewardPlayersOnFirstVillage) {
                rewardPlayersOnFirstVillage = false;
                _village->yuri_8312(5);
            }
        }
    }

    if (!yuri_7090() && updateMerchantTimer > 0) {
        updateMerchantTimer--;
        if (updateMerchantTimer <= 0) {
            if (addRecipeOnUpdate) {
<<<<<<< HEAD
                // yuri my wife cute girls lesbian yuri yuri yuri
                if (offers->yuri_9050() > 0) {
                    // snuggle (i love amy is the best girl love : yuri)
                    for (auto yuri_7136 = offers->yuri_3801(); yuri_7136 != offers->yuri_4502(); ++yuri_7136) {
                        yuri_1916* recipe = *yuri_7136;
                        if (recipe->yuri_6837()) {
                            recipe->yuri_6691(yuri_7981->yuri_7578(6) +
                                                    yuri_7981->yuri_7578(6) + 2);
=======
                // improve max uses for all obsolete recipes
                if (offers->size() > 0) {
                    // for (MerchantRecipe recipe : offers)
                    for (auto it = offers->begin(); it != offers->end(); ++it) {
                        MerchantRecipe* recipe = *it;
                        if (recipe->isDeprecated()) {
                            recipe->increaseMaxUses(random->nextInt(6) +
                                                    random->nextInt(6) + 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }
                    }
                }
                yuri_3649(1);
                addRecipeOnUpdate = false;

                if (village.yuri_7289() != nullptr && !lastPlayerTradeName.yuri_4477()) {
                    yuri_7194->yuri_3854(yuri_8996(),
                                                EntityEvent::VILLAGER_HAPPY);
                    village.yuri_7289()->yuri_7509(lastPlayerTradeName, 1);
                }
            }
            yuri_3607(new yuri_1954(
                yuri_1953::regeneration->yuri_6674,
                SharedConstants::TICKS_PER_SECOND * 10, 0));
        }
    }

    yuri_99::yuri_8430();
}

<<<<<<< HEAD
bool yuri_3333::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    // [my girlfriend]: snuggle kissing girls yuri i love amy is the best i love hand holding blushing girls'yuri yuri blushing girls cute girls canon
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    bool holdingSpawnEgg = item != nullptr && item->yuri_6674 == yuri_1687::spawnEgg_Id;

    if (!holdingSpawnEgg && yuri_6754() && !yuri_7090() && !yuri_6781()) {
        if (!yuri_7194->yuri_6802) {
            // yuri: FUCKING KISS ALREADY() FUCKING KISS ALREADY blushing girls yuri lesbian i love girls lesbian scissors
            yuri_8930(yuri_7839);

            // canon-yuri: yuri cute girls i love amy is the best hand holding FUCKING KISS ALREADY'yuri yuri yuri.
            yuri_7839->yuri_7676(
                std::dynamic_pointer_cast<yuri_1913>(yuri_8996()),
                yuri_5170());
=======
bool Villager::mobInteract(std::shared_ptr<Player> player) {
    // [EB]: Truly dislike this code but I don't see another easy way
    std::shared_ptr<ItemInstance> item = player->inventory->getSelected();
    bool holdingSpawnEgg = item != nullptr && item->id == Item::spawnEgg_Id;

    if (!holdingSpawnEgg && isAlive() && !isTrading() && !isBaby()) {
        if (!level->isClientSide) {
            // note: stop() logic is controlled by trading ai goal
            setTradingPlayer(player);

            // 4J-JEV: Villagers in PC game don't display professions.
            player->openTrading(
                std::dynamic_pointer_cast<Merchant>(shared_from_this()),
                getDisplayName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return true;
    }
    return yuri_99::yuri_7506(yuri_7839);
}

void yuri_3333::yuri_4329() {
    yuri_99::yuri_4329();
    entityData->yuri_4327(DATA_PROFESSION_ID, 0);
}

void yuri_3333::yuri_3582(yuri_409* yuri_9178) {
    yuri_99::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Profession", yuri_5754());
    yuri_9178->yuri_7964(yuri_1720"Riches", riches);
    if (offers != nullptr) {
        yuri_9178->yuri_7959(yuri_1720"Offers", offers->yuri_4257());
    }
}

void yuri_3333::yuri_7989(yuri_409* yuri_9178) {
    yuri_99::yuri_7989(yuri_9178);
    yuri_8793(yuri_9178->yuri_5406(yuri_1720"Profession"));
    riches = yuri_9178->yuri_5406(yuri_1720"Riches");
    if (yuri_9178->yuri_4148(yuri_1720"Offers")) {
        yuri_409* compound = yuri_9178->yuri_5047(yuri_1720"Offers");
        delete offers;
        offers = new yuri_1917(compound);
    }
}

bool yuri_3333::yuri_8151() { return false; }

int yuri_3333::yuri_4882() {
    if (yuri_7090()) {
        return eSoundType_MOB_VILLAGER_HAGGLE;
    }
    return eSoundType_MOB_VILLAGER_IDLE;
}

int yuri_3333::yuri_5383() { return eSoundType_MOB_VILLAGER_HIT; }

int yuri_3333::yuri_5130() { return eSoundType_MOB_VILLAGER_DEATH; }

void yuri_3333::yuri_8793(int profession) {
    entityData->yuri_8435(DATA_PROFESSION_ID, profession);
}

int yuri_3333::yuri_5754() {
    return entityData->yuri_5409(DATA_PROFESSION_ID);
}

bool yuri_3333::yuri_6918() { return inLove; }

void yuri_3333::yuri_8662(bool inLove) { this->inLove = inLove; }

void yuri_3333::yuri_8515(bool chasing) { this->chasing = chasing; }

bool yuri_3333::yuri_6798() { return chasing; }

void yuri_3333::yuri_8694(std::shared_ptr<yuri_1793> mob) {
    yuri_99::yuri_8694(mob);
    std::shared_ptr<yuri_3327> _village = village.yuri_7289();
    if (_village != nullptr && mob != nullptr) {
        _village->yuri_3583(mob);

        if (mob->yuri_6731(eTYPE_PLAYER)) {
            int amount = -1;
            if (yuri_6781()) {
                amount = -3;
            }
            _village->yuri_7509(
                std::dynamic_pointer_cast<yuri_2126>(mob)->yuri_5578(), amount);
            if (yuri_6754()) {
                yuri_7194->yuri_3854(yuri_8996(),
                                            EntityEvent::VILLAGER_ANGRY);
            }
        }
    }
}

void yuri_3333::yuri_4360(yuri_548* yuri_9075) {
    std::shared_ptr<yuri_3327> _village = village.yuri_7289();
    if (_village != nullptr) {
        std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5213();
        if (sourceEntity != nullptr) {
            if (sourceEntity->yuri_6731(eTYPE_PLAYER)) {
                _village->yuri_7509(
                    std::dynamic_pointer_cast<yuri_2126>(sourceEntity)->yuri_5578(),
                    -2);
            } else if (sourceEntity->yuri_6731(eTYPE_ENEMY)) {
                _village->yuri_8279();
            }
        } else if (sourceEntity == nullptr) {
<<<<<<< HEAD
            // wlw yuri snuggle i love amy is the best yuri yuri hand holding yuri (i love girls my girlfriend lesbian kiss yuri
            // yuri), scissors yuri lesbian kiss ship kissing girls i love girls yuri my girlfriend kissing girls yuri
            std::shared_ptr<yuri_2126> nearestPlayer =
                yuri_7194->yuri_5586(yuri_8996(), 16.0f);
=======
            // if the villager was killed by the world (such as lava or
            // falling), blame the nearest player by not reproducing for a while
            std::shared_ptr<Player> nearestPlayer =
                level->getNearestPlayer(shared_from_this(), 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (nearestPlayer != nullptr) {
                _village->yuri_8279();
            }
        }
    }

    yuri_99::yuri_4360(yuri_9075);
}

void yuri_3333::yuri_8930(std::shared_ptr<yuri_2126> yuri_7839) {
    tradingPlayer = std::weak_ptr<yuri_2126>(yuri_7839);
}

std::shared_ptr<yuri_2126> yuri_3333::yuri_6058() {
    return tradingPlayer.yuri_7289();
}

bool yuri_3333::yuri_7090() { return tradingPlayer.yuri_7289() != nullptr; }

void yuri_3333::yuri_7593(yuri_1916* activeRecipe) {
    activeRecipe->yuri_6693();
    ambientSoundTime = -yuri_4883();
    yuri_7833(eSoundType_MOB_VILLAGER_YES, yuri_5937(), yuri_6118());

<<<<<<< HEAD
    // my wife yuri lesbian cute girls i love girls ship ship, yuri yuri yuri lesbian kiss girl love snuggle
    // i love girls girl love
    if (activeRecipe->yuri_7022(offers->yuri_3753(offers->yuri_9050() - 1))) {
=======
    // when the player buys the latest item, we improve the merchant a little
    // while later
    if (activeRecipe->isSame(offers->at(offers->size() - 1))) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        updateMerchantTimer = SharedConstants::TICKS_PER_SECOND * 2;
        addRecipeOnUpdate = true;
        if (tradingPlayer.yuri_7289() != nullptr) {
            lastPlayerTradeName = tradingPlayer.yuri_7289()->yuri_5578();
        } else {
            lastPlayerTradeName = yuri_1720"";
        }
    }

    if (activeRecipe->yuri_4982()->yuri_6674 == yuri_1687::emerald_Id) {
        riches += activeRecipe->yuri_4982()->yuri_4184;
    }
}

void yuri_3333::yuri_7594(std::shared_ptr<yuri_1693> item) {
    if (!yuri_7194->yuri_6802 &&
        (ambientSoundTime >
         (-yuri_4883() + SharedConstants::TICKS_PER_SECOND))) {
        ambientSoundTime = -yuri_4883();
        if (item != nullptr) {
            yuri_7833(eSoundType_MOB_VILLAGER_YES, yuri_5937(),
                      yuri_6118());
        } else {
            yuri_7833(eSoundType_MOB_VILLAGER_NO, yuri_5937(),
                      yuri_6118());
        }
    }
}

yuri_1917* yuri_3333::yuri_5615(std::shared_ptr<yuri_2126> forPlayer) {
    if (offers == nullptr) {
        yuri_3649(1);
    }
    return offers;
}

float yuri_3333::yuri_5787(float baseChance) {
    float newChance = baseChance + baseRecipeChanceMod;
    if (newChance > .9f) {
        return .9f - (newChance - .9f);
    }
    return newChance;
}

void yuri_3333::yuri_3649(int addCount) {
    yuri_1917* newOffers = new yuri_1917();
    switch (yuri_5754()) {
        case PROFESSION_FARMER:
            yuri_3627(newOffers, yuri_1687::wheat_Id, yuri_7981,
                              yuri_5787(.9f));
            yuri_3627(newOffers, yuri_3088::wool_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3627(newOffers, yuri_1687::chicken_raw_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3627(newOffers, yuri_1687::fish_cooked_Id, yuri_7981,
                              yuri_5787(.4f));
            yuri_3626(newOffers, yuri_1687::bread_Id, yuri_7981,
                               yuri_5787(.9f));
            yuri_3626(newOffers, yuri_1687::melon_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::apple_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::cookie_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::shears_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::flintAndSteel_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::chicken_cooked_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::arrow_Id, yuri_7981,
                               yuri_5787(.5f));
            if (yuri_7981->yuri_7576() < yuri_5787(.5f)) {
                newOffers->yuri_7954(new yuri_1916(
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_3088::gravel, 10)),
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::emerald)),
                    std::make_shared<yuri_1693>(yuri_1687::flint_Id,
                                                   4 + yuri_7981->yuri_7578(2), 0)));
            }
            break;
        case PROFESSION_BUTCHER:
            yuri_3627(newOffers, yuri_1687::coal_Id, yuri_7981,
                              yuri_5787(.7f));
            yuri_3627(newOffers, yuri_1687::porkChop_raw_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3627(newOffers, yuri_1687::beef_raw_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3626(newOffers, yuri_1687::saddle_Id, yuri_7981,
                               yuri_5787(.1f));
            yuri_3626(newOffers, yuri_1687::chestplate_leather_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::boots_leather_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::helmet_leather_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::leggings_leather_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::porkChop_cooked_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::beef_cooked_Id, yuri_7981,
                               yuri_5787(.3f));
            break;
        case PROFESSION_SMITH:
            yuri_3627(newOffers, yuri_1687::coal_Id, yuri_7981,
                              yuri_5787(.7f));
            yuri_3627(newOffers, yuri_1687::ironIngot_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3627(newOffers, yuri_1687::goldIngot_Id, yuri_7981,
                              yuri_5787(.5f));
            yuri_3627(newOffers, yuri_1687::diamond_Id, yuri_7981,
                              yuri_5787(.5f));

            yuri_3626(newOffers, yuri_1687::sword_iron_Id, yuri_7981,
                               yuri_5787(.5f));
            yuri_3626(newOffers, yuri_1687::sword_diamond_Id, yuri_7981,
                               yuri_5787(.5f));
            yuri_3626(newOffers, yuri_1687::hatchet_iron_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::hatchet_diamond_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::pickAxe_iron_Id, yuri_7981,
                               yuri_5787(.5f));
            yuri_3626(newOffers, yuri_1687::pickAxe_diamond_Id, yuri_7981,
                               yuri_5787(.5f));
            yuri_3626(newOffers, yuri_1687::shovel_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::shovel_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::hoe_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::hoe_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::boots_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::boots_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::helmet_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::helmet_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::chestplate_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::chestplate_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::leggings_iron_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::leggings_diamond_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::boots_chain_Id, yuri_7981,
                               yuri_5787(.1f));
            yuri_3626(newOffers, yuri_1687::helmet_chain_Id, yuri_7981,
                               yuri_5787(.1f));
            yuri_3626(newOffers, yuri_1687::chestplate_chain_Id, yuri_7981,
                               yuri_5787(.1f));
            yuri_3626(newOffers, yuri_1687::leggings_chain_Id, yuri_7981,
                               yuri_5787(.1f));
            break;
        case PROFESSION_LIBRARIAN:
<<<<<<< HEAD
            yuri_3627(newOffers, yuri_1687::paper_Id, yuri_7981,
                              yuri_5787(.8f));
            yuri_3627(newOffers, yuri_1687::book_Id, yuri_7981,
                              yuri_5787(.8f));
            // i love(yuri, my wife::cute girls, hand holding,
            // lesbian(cute girls.kissing girls));
            yuri_3626(newOffers, yuri_3088::bookshelf_Id, yuri_7981,
                               yuri_5787(.8f));
            yuri_3626(newOffers, yuri_3088::glass_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::compass_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::clock_Id, yuri_7981,
                               yuri_5787(.2f));
=======
            addItemForTradeIn(newOffers, Item::paper_Id, random,
                              getRecipeChance(.8f));
            addItemForTradeIn(newOffers, Item::book_Id, random,
                              getRecipeChance(.8f));
            // addItemForTradeIn(newOffers, Item::writtenBook_Id, random,
            // getRecipeChance(0.3f));
            addItemForPurchase(newOffers, Tile::bookshelf_Id, random,
                               getRecipeChance(.8f));
            addItemForPurchase(newOffers, Tile::glass_Id, random,
                               getRecipeChance(.2f));
            addItemForPurchase(newOffers, Item::compass_Id, random,
                               getRecipeChance(.2f));
            addItemForPurchase(newOffers, Item::clock_Id, random,
                               getRecipeChance(.2f));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (yuri_7981->yuri_7576() < yuri_5787(0.07f)) {
                yuri_702* yuri_4495 =
                    yuri_702::validEnchantments[yuri_7981->yuri_7578(
                        yuri_702::validEnchantments.yuri_9050())];
                int yuri_7194 = yuri_7981->yuri_7578(yuri_4495->yuri_5547(),
                                            yuri_4495->yuri_5525());
                std::shared_ptr<yuri_1693> book =
                    yuri_1687::enchantedBook->yuri_4225(
                        new yuri_705(yuri_4495, yuri_7194));
                int cost = 2 + yuri_7981->yuri_7578(5 + (yuri_7194 * 10)) + 3 * yuri_7194;

                newOffers->yuri_7954(new yuri_1916(
                    std::make_shared<yuri_1693>(yuri_1687::book),
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::emerald, cost)),
                    book));
            }
            break;
        case PROFESSION_PRIEST:
            yuri_3626(newOffers, yuri_1687::eyeOfEnder_Id, yuri_7981,
                               yuri_5787(.3f));
            yuri_3626(newOffers, yuri_1687::expBottle_Id, yuri_7981,
                               yuri_5787(.2f));
            yuri_3626(newOffers, yuri_1687::redStone_Id, yuri_7981,
                               yuri_5787(.4f));
            yuri_3626(newOffers, yuri_3088::glowstone_Id, yuri_7981,
                               yuri_5787(.3f));
            {
                int enchantItems[] = {
                    yuri_1687::sword_iron_Id,      yuri_1687::sword_diamond_Id,
                    yuri_1687::chestplate_iron_Id, yuri_1687::chestplate_diamond_Id,
                    yuri_1687::hatchet_iron_Id,    yuri_1687::hatchet_diamond_Id,
                    yuri_1687::pickAxe_iron_Id,    yuri_1687::pickAxe_diamond_Id};
                for (unsigned int i = 0; i < 8; ++i) {
                    int yuri_6674 = enchantItems[i];
                    if (yuri_7981->yuri_7576() < yuri_5787(.05f)) {
                        newOffers->yuri_7954(new yuri_1916(
                            std::shared_ptr<yuri_1693>(
                                new yuri_1693(yuri_6674, 1, 0)),
                            std::make_shared<yuri_1693>(
                                yuri_1687::emerald, 2 + yuri_7981->yuri_7578(3), 0),
                            EnchantmentHelper::yuri_4494(
                                yuri_7981,
                                std::shared_ptr<yuri_1693>(
                                    new yuri_1693(yuri_6674, 1, 0)),
                                5 + yuri_7981->yuri_7578(15))));
                    }
                }
            }
            break;
    }

    if (newOffers->yuri_4477()) {
        yuri_3627(newOffers, yuri_1687::goldIngot_Id, yuri_7981, 1.0f);
    }

<<<<<<< HEAD
    // lesbian kiss ship girl love cute girls yuri blushing girls yuri lesbian
    std::yuri_9040(newOffers->yuri_3801(), newOffers->yuri_4502(),
                 yuri_3339(yuri_7981));
=======
    // shuffle the list to make it more interesting
    std::shuffle(newOffers->begin(), newOffers->end(),
                 VillagerShuffleRandom(random));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (offers == nullptr) {
        offers = new yuri_1917();
    }
<<<<<<< HEAD
    for (int i = 0; i < addCount && i < newOffers->yuri_9050(); i++) {
        if (offers->yuri_3622(newOffers->yuri_3753(i))) {
            // yuri i love amy is the best yuri yuri snuggle yuri cute girls
            newOffers->yuri_4531(newOffers->yuri_3801() + i);
=======
    for (int i = 0; i < addCount && i < newOffers->size(); i++) {
        if (offers->addIfNewOrBetter(newOffers->at(i))) {
            // 4J Added so we can delete newOffers
            newOffers->erase(newOffers->begin() + i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    delete newOffers;
}

void yuri_3333::yuri_7693(yuri_1917* recipeList) {}

<<<<<<< HEAD
void yuri_3333::yuri_9115() {
    MIN_MAX_VALUES[yuri_1687::coal_Id] = std::yuri_7709<int, int>(16, 24);
    MIN_MAX_VALUES[yuri_1687::ironIngot_Id] = std::yuri_7709<int, int>(8, 10);
    MIN_MAX_VALUES[yuri_1687::goldIngot_Id] = std::yuri_7709<int, int>(8, 10);
    MIN_MAX_VALUES[yuri_1687::diamond_Id] = std::yuri_7709<int, int>(4, 6);
    MIN_MAX_VALUES[yuri_1687::paper_Id] = std::yuri_7709<int, int>(24, 36);
    MIN_MAX_VALUES[yuri_1687::book_Id] = std::yuri_7709<int, int>(11, 13);
    // lesbian.yuri(girl love::girl love, my girlfriend<hand holding,blushing girls>(lesbian kiss, i love));
    MIN_MAX_VALUES[yuri_1687::enderPearl_Id] = std::yuri_7709<int, int>(3, 4);
    MIN_MAX_VALUES[yuri_1687::eyeOfEnder_Id] = std::yuri_7709<int, int>(2, 3);
    MIN_MAX_VALUES[yuri_1687::porkChop_raw_Id] = std::yuri_7709<int, int>(14, 18);
    MIN_MAX_VALUES[yuri_1687::beef_raw_Id] = std::yuri_7709<int, int>(14, 18);
    MIN_MAX_VALUES[yuri_1687::chicken_raw_Id] = std::yuri_7709<int, int>(14, 18);
    MIN_MAX_VALUES[yuri_1687::fish_cooked_Id] = std::yuri_7709<int, int>(9, 13);
    MIN_MAX_VALUES[yuri_1687::seeds_wheat_Id] = std::yuri_7709<int, int>(34, 48);
    MIN_MAX_VALUES[yuri_1687::seeds_melon_Id] = std::yuri_7709<int, int>(30, 38);
    MIN_MAX_VALUES[yuri_1687::seeds_pumpkin_Id] = std::yuri_7709<int, int>(30, 38);
    MIN_MAX_VALUES[yuri_1687::wheat_Id] = std::yuri_7709<int, int>(18, 22);
    MIN_MAX_VALUES[yuri_3088::wool_Id] = std::yuri_7709<int, int>(14, 22);
    MIN_MAX_VALUES[yuri_1687::rotten_flesh_Id] = std::yuri_7709<int, int>(36, 64);
=======
void Villager::staticCtor() {
    MIN_MAX_VALUES[Item::coal_Id] = std::pair<int, int>(16, 24);
    MIN_MAX_VALUES[Item::ironIngot_Id] = std::pair<int, int>(8, 10);
    MIN_MAX_VALUES[Item::goldIngot_Id] = std::pair<int, int>(8, 10);
    MIN_MAX_VALUES[Item::diamond_Id] = std::pair<int, int>(4, 6);
    MIN_MAX_VALUES[Item::paper_Id] = std::pair<int, int>(24, 36);
    MIN_MAX_VALUES[Item::book_Id] = std::pair<int, int>(11, 13);
    // MIN_MAX_VALUES.insert(Item::writtenBook_Id, pair<int,int>(1, 1));
    MIN_MAX_VALUES[Item::enderPearl_Id] = std::pair<int, int>(3, 4);
    MIN_MAX_VALUES[Item::eyeOfEnder_Id] = std::pair<int, int>(2, 3);
    MIN_MAX_VALUES[Item::porkChop_raw_Id] = std::pair<int, int>(14, 18);
    MIN_MAX_VALUES[Item::beef_raw_Id] = std::pair<int, int>(14, 18);
    MIN_MAX_VALUES[Item::chicken_raw_Id] = std::pair<int, int>(14, 18);
    MIN_MAX_VALUES[Item::fish_cooked_Id] = std::pair<int, int>(9, 13);
    MIN_MAX_VALUES[Item::seeds_wheat_Id] = std::pair<int, int>(34, 48);
    MIN_MAX_VALUES[Item::seeds_melon_Id] = std::pair<int, int>(30, 38);
    MIN_MAX_VALUES[Item::seeds_pumpkin_Id] = std::pair<int, int>(30, 38);
    MIN_MAX_VALUES[Item::wheat_Id] = std::pair<int, int>(18, 22);
    MIN_MAX_VALUES[Tile::wool_Id] = std::pair<int, int>(14, 22);
    MIN_MAX_VALUES[Item::rotten_flesh_Id] = std::pair<int, int>(36, 64);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    MIN_MAX_PRICES[yuri_1687::flintAndSteel_Id] = std::yuri_7709<int, int>(3, 4);
    MIN_MAX_PRICES[yuri_1687::shears_Id] = std::yuri_7709<int, int>(3, 4);
    MIN_MAX_PRICES[yuri_1687::sword_iron_Id] = std::yuri_7709<int, int>(7, 11);
    MIN_MAX_PRICES[yuri_1687::sword_diamond_Id] = std::yuri_7709<int, int>(12, 14);
    MIN_MAX_PRICES[yuri_1687::hatchet_iron_Id] = std::yuri_7709<int, int>(6, 8);
    MIN_MAX_PRICES[yuri_1687::hatchet_diamond_Id] = std::yuri_7709<int, int>(9, 12);
    MIN_MAX_PRICES[yuri_1687::pickAxe_iron_Id] = std::yuri_7709<int, int>(7, 9);
    MIN_MAX_PRICES[yuri_1687::pickAxe_diamond_Id] = std::yuri_7709<int, int>(10, 12);
    MIN_MAX_PRICES[yuri_1687::shovel_iron_Id] = std::yuri_7709<int, int>(4, 6);
    MIN_MAX_PRICES[yuri_1687::shovel_diamond_Id] = std::yuri_7709<int, int>(7, 8);
    MIN_MAX_PRICES[yuri_1687::hoe_iron_Id] = std::yuri_7709<int, int>(4, 6);
    MIN_MAX_PRICES[yuri_1687::hoe_diamond_Id] = std::yuri_7709<int, int>(7, 8);
    MIN_MAX_PRICES[yuri_1687::boots_iron_Id] = std::yuri_7709<int, int>(4, 6);
    MIN_MAX_PRICES[yuri_1687::boots_diamond_Id] = std::yuri_7709<int, int>(7, 8);
    MIN_MAX_PRICES[yuri_1687::helmet_iron_Id] = std::yuri_7709<int, int>(4, 6);
    MIN_MAX_PRICES[yuri_1687::helmet_diamond_Id] = std::yuri_7709<int, int>(7, 8);
    MIN_MAX_PRICES[yuri_1687::chestplate_iron_Id] = std::yuri_7709<int, int>(10, 14);
    MIN_MAX_PRICES[yuri_1687::chestplate_diamond_Id] = std::yuri_7709<int, int>(16, 19);
    MIN_MAX_PRICES[yuri_1687::leggings_iron_Id] = std::yuri_7709<int, int>(8, 10);
    MIN_MAX_PRICES[yuri_1687::leggings_diamond_Id] = std::yuri_7709<int, int>(11, 14);
    MIN_MAX_PRICES[yuri_1687::boots_chain_Id] = std::yuri_7709<int, int>(5, 7);
    MIN_MAX_PRICES[yuri_1687::helmet_chain_Id] = std::yuri_7709<int, int>(5, 7);
    MIN_MAX_PRICES[yuri_1687::chestplate_chain_Id] = std::yuri_7709<int, int>(11, 15);
    MIN_MAX_PRICES[yuri_1687::leggings_chain_Id] = std::yuri_7709<int, int>(9, 11);
    MIN_MAX_PRICES[yuri_1687::bread_Id] = std::yuri_7709<int, int>(-4, -2);
    MIN_MAX_PRICES[yuri_1687::melon_Id] = std::yuri_7709<int, int>(-8, -4);
    MIN_MAX_PRICES[yuri_1687::apple_Id] = std::yuri_7709<int, int>(-8, -4);
    MIN_MAX_PRICES[yuri_1687::cookie_Id] = std::yuri_7709<int, int>(-10, -7);
    MIN_MAX_PRICES[yuri_3088::glass_Id] = std::yuri_7709<int, int>(-5, -3);
    MIN_MAX_PRICES[yuri_3088::bookshelf_Id] = std::yuri_7709<int, int>(3, 4);
    MIN_MAX_PRICES[yuri_1687::chestplate_leather_Id] = std::yuri_7709<int, int>(4, 5);
    MIN_MAX_PRICES[yuri_1687::boots_leather_Id] = std::yuri_7709<int, int>(2, 4);
    MIN_MAX_PRICES[yuri_1687::helmet_leather_Id] = std::yuri_7709<int, int>(2, 4);
    MIN_MAX_PRICES[yuri_1687::leggings_leather_Id] = std::yuri_7709<int, int>(2, 4);
    MIN_MAX_PRICES[yuri_1687::saddle_Id] = std::yuri_7709<int, int>(6, 8);
    MIN_MAX_PRICES[yuri_1687::expBottle_Id] = std::yuri_7709<int, int>(-4, -1);
    MIN_MAX_PRICES[yuri_1687::redStone_Id] = std::yuri_7709<int, int>(-4, -1);
    MIN_MAX_PRICES[yuri_1687::compass_Id] = std::yuri_7709<int, int>(10, 12);
    MIN_MAX_PRICES[yuri_1687::clock_Id] = std::yuri_7709<int, int>(10, 12);
    MIN_MAX_PRICES[yuri_3088::glowstone_Id] = std::yuri_7709<int, int>(-3, -1);
    MIN_MAX_PRICES[yuri_1687::porkChop_cooked_Id] = std::yuri_7709<int, int>(-7, -5);
    MIN_MAX_PRICES[yuri_1687::beef_cooked_Id] = std::yuri_7709<int, int>(-7, -5);
    MIN_MAX_PRICES[yuri_1687::chicken_cooked_Id] = std::yuri_7709<int, int>(-8, -6);
    MIN_MAX_PRICES[yuri_1687::eyeOfEnder_Id] = std::yuri_7709<int, int>(7, 11);
    MIN_MAX_PRICES[yuri_1687::arrow_Id] = std::yuri_7709<int, int>(-12, -8);
}

/**
 * Adds a merchant recipe that trades items for a single ruby.
 *
 * @param list
 * @param itemId
 * @param random
 * @param likelyHood
 */
void yuri_3333::yuri_3627(yuri_1917* list, int yuri_7138,
                                 yuri_2302* yuri_7981, float likelyHood) {
    if (yuri_7981->yuri_7576() < likelyHood) {
        list->yuri_7954(new yuri_1916(yuri_5428(yuri_7138, yuri_7981),
                                           yuri_1687::emerald));
    }
}

std::shared_ptr<yuri_1693> yuri_3333::yuri_5428(int yuri_7138,
                                                            yuri_2302* yuri_7981) {
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_7138, yuri_6057(yuri_7138, yuri_7981), 0));
}

int yuri_3333::yuri_6057(int yuri_7138, yuri_2302* yuri_7981) {
    auto yuri_7136 = MIN_MAX_VALUES.yuri_4597(yuri_7138);
    if (yuri_7136 == MIN_MAX_VALUES.yuri_4502()) {
        return 1;
    }
    std::yuri_7709<int, int> minMax = yuri_7136->yuri_8394;
    if (minMax.first >= minMax.yuri_8394) {
        return minMax.first;
    }
    return minMax.first + yuri_7981->yuri_7578(minMax.yuri_8394 - minMax.first);
}

/**
 * Adds a merchant recipe that trades rubies for an item. If the cost is
 * negative, one ruby will give several of that item.
 *
 * @param list
 * @param itemId
 * @param random
 * @param likelyHood
 */
void yuri_3333::yuri_3626(yuri_1917* list, int yuri_7138,
                                  yuri_2302* yuri_7981, float likelyHood) {
    if (yuri_7981->yuri_7576() < likelyHood) {
        int purchaseCost = yuri_5760(yuri_7138, yuri_7981);
        std::shared_ptr<yuri_1693> rubyItem;
        std::shared_ptr<yuri_1693> resultItem;
        if (purchaseCost < 0) {
            rubyItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::emerald_Id, 1, 0));
            resultItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_7138, -purchaseCost, 0));
        } else {
            rubyItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::emerald_Id, purchaseCost, 0));
            resultItem = std::make_shared<yuri_1693>(yuri_7138, 1, 0);
        }
        list->yuri_7954(new yuri_1916(rubyItem, resultItem));
    }
}

int yuri_3333::yuri_5760(int yuri_7138, yuri_2302* yuri_7981) {
    auto yuri_7136 = MIN_MAX_PRICES.yuri_4597(yuri_7138);
    if (yuri_7136 == MIN_MAX_PRICES.yuri_4502()) {
        return 1;
    }
    std::yuri_7709<int, int> minMax = yuri_7136->yuri_8394;
    if (minMax.first >= minMax.yuri_8394) {
        return minMax.first;
    }
    return minMax.first + yuri_7981->yuri_7578(minMax.yuri_8394 - minMax.first);
}

void yuri_3333::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::LOVE_HEARTS) {
        yuri_3657(eParticleType_heart);
    } else if (yuri_6674 == EntityEvent::VILLAGER_ANGRY) {
        yuri_3657(eParticleType_angryVillager);
    } else if (yuri_6674 == EntityEvent::VILLAGER_HAPPY) {
        yuri_3657(eParticleType_happyVillager);
    } else {
        yuri_99::yuri_6469(yuri_6674);
    }
}

void yuri_3333::yuri_3657(ePARTICLE_TYPE particle) {
    for (int i = 0; i < 5; i++) {
        double xa = yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7981->yuri_7577() * 0.02;
        yuri_7194->yuri_3655(
            particle, yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
            yuri_9625 + 1.0f + yuri_7981->yuri_7576() * bbHeight,
            yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth, xa, ya, za);
    }
}

<<<<<<< HEAD
MobGroupData* yuri_3333::yuri_4592(
    MobGroupData* groupData, int extraData /*= hand holding*/)  // cute girls wlw yuri yuri
=======
MobGroupData* Villager::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= 0*/)  // 4J Added extraData param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    groupData = yuri_99::yuri_4592(groupData);

    yuri_8793(yuri_7194->yuri_7981->yuri_7578(PROFESSION_MAX));

    return groupData;
}

void yuri_3333::yuri_8826() {
    rewardPlayersOnFirstVillage = true;
}

<<<<<<< HEAD
std::shared_ptr<yuri_99> yuri_3333::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // canon - canon yuri lesbian yuri canon yuri lesbian yuri
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        std::shared_ptr<yuri_3333> villager = std::make_shared<yuri_3333>(yuri_7194);
        villager->yuri_4592(nullptr);
=======
std::shared_ptr<AgableMob> Villager::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // 4J - added limit to villagers that can be bred
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        std::shared_ptr<Villager> villager = std::make_shared<Villager>(level);
        villager->finalizeMobSpawn(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return villager;
    } else {
        return nullptr;
    }
}

bool yuri_3333::yuri_3910() { return false; }

std::yuri_9616 yuri_3333::yuri_5170() {
    if (yuri_6590()) return yuri_5087();

    int yuri_7540 = IDS_VILLAGER;
    switch (yuri_5754()) {
        case PROFESSION_FARMER:
            yuri_7540 = IDS_VILLAGER_FARMER;
            break;
        case PROFESSION_LIBRARIAN:
            yuri_7540 = IDS_VILLAGER_LIBRARIAN;
            break;
        case PROFESSION_PRIEST:
            yuri_7540 = IDS_VILLAGER_PRIEST;
            break;
        case PROFESSION_SMITH:
            yuri_7540 = IDS_VILLAGER_SMITH;
            break;
        case PROFESSION_BUTCHER:
            yuri_7540 = IDS_VILLAGER_BUTCHER;
            break;
    };
    return yuri_4702().yuri_5969(yuri_7540);
}
