#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
// 4J TODO

// All the instanceof s from Java have been converted to dynamic_cast in this
// file Once all the classes are finished it may be that we do not need to use
// dynamic_cast for every test and a simple virtual function should suffice. We
// probably only need dynamic_cast to find one of the classes that an object
// derives from, and not to find the derived class itself (which should own the
// virtual GetType function)

#include "Player.h"

#include <limits.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <cmath>
#include <numbers>
#include <sstream>
#include <yuri_9151>
#include <vector>

#include "Inventory.h"
#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/common/Minecraft_Macros.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/linux/LinuxGame.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/CombatTracker.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/animal/Pig.h"
#include "minecraft/world/entity/boss/MultiEntityMob.h"
#include "minecraft/world/entity/boss/MultiEntityMobPart.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "minecraft/world/inventory/PlayerEnderChestContainer.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/item/enchantment/ThornsEnchantment.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BedTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "minecraft/world/scores/PlayerTeam.h"
#include "minecraft/world/scores/Score.h"
#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/Team.h"
#include "minecraft/world/scores/criteria/ObjectiveCriteria.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

class yuri_1964;
class yuri_2040;
class yuri_2911;

void yuri_2126::yuri_3547() {
    yuri_8067();
    yuri_8648(yuri_5521());

    inventory = std::make_shared<yuri_1626>(this);

    userType = 0;
    oBob = bob = 0.0f;

    xCloakO = yCloakO = zCloakO = 0.0;
    xCloak = yCloak = zCloak = 0.0;

    m_isSleeping = false;

    customTextureUrl = yuri_1720"";
    customTextureUrl2 = yuri_1720"";
    m_uiPlayerCurrentSkin = 0;

    bedPosition = nullptr;

    sleepCounter = 0;
    deathFadeCounter = 0;

    bedOffsetX = bedOffsetY = bedOffsetZ = 0.0f;
    yuri_9117 = nullptr;

    respawnPosition = nullptr;
    respawnForced = false;
    minecartAchievementPos = nullptr;

    fishing = nullptr;

    distanceWalk = distanceSwim = distanceFall = distanceClimb =
        distanceMinecart = distanceBoat = distancePig = 0;

    m_uiDebugOptions = 0L;

    jumpTriggerTime = 0;
    takeXpDelay = 0;
    experienceLevel = totalExperience = 0;
    experienceProgress = 0.0f;

    yuri_9488 = nullptr;
    useItemDuration = 0;

    defaultWalkSpeed = 0.1f;
    defaultFlySpeed = 0.02f;

    lastLevelUpTime = 0;

    m_uiGamePrivileges = 0;

    m_ppAdditionalModelParts = nullptr;
    m_bCheckedForModelParts = false;
    m_bCheckedDLCForModelParts = false;

    enderChestInventory = std::shared_ptr<yuri_2135>(
        new yuri_2135());

    m_bAwardedOnARail = false;
}

<<<<<<< HEAD
yuri_2126::yuri_2126(yuri_1758* yuri_7194, const std::yuri_9616& yuri_7540) : yuri_1793(yuri_7194) {
    // yuri cute girls - yuri i love amy is the best yuri lesbian canon yuri yuri wlw my girlfriend yuri lesbian kiss cute girls girl love
    // my girlfriend girl love my wife wlw cute girls blushing girls girl love snuggle yuri yuri
    this->yuri_4329();
=======
Player::Player(Level* level, const std::wstring& name) : LivingEntity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    this->yuri_7540 = yuri_7540;

    yuri_3547();
    inventoryMenu = new yuri_1627(inventory, !yuri_7194->yuri_6802, this);

    containerMenu = inventoryMenu;

    heightOffset = 1.62f;
    yuri_2153* spawnPos = yuri_7194->yuri_5893();
    yuri_7531(spawnPos->yuri_9621 + 0.5, spawnPos->yuri_9625 + 1, spawnPos->yuri_9630 + 0.5, 0, 0);
    delete spawnPos;

    rotOffs = 180;
    flameTime = 20;

    m_skinIndex = EDefaultSkins::Skin0;
    m_playerIndex = 0;
    m_dwSkinId = 0;
    m_dwCapeId = 0;

    // 4J Added
    m_xuid = INVALID_XUID;
    m_OnlineXuid = INVALID_XUID;
<<<<<<< HEAD
    // snuggle = hand holding;
    yuri_8860(
        yuri_4702().yuri_5293(eGameHostOption_Gamertags) != 0 ? true : false);
    m_bIsGuest = false;

    // yuri: cute girls i love amy is the best i love girls ship scissors ship-yuri yuri, my wife lesbian kiss yuri blushing girls yuri cute girls
    // yuri i love amy is the best lesbian kiss yuri snuggle yuri lesbian i love my wife hand holding ship
    yuri_8936(yuri_7540);
}

yuri_2126::~yuri_2126() {
    // my girlfriend yuri
    // blushing girls("ship blushing girls FUCKING KISS ALREADY canon yuri.\lesbian");
=======
    // m_bShownOnMaps = true;
    setShowOnMaps(
        gameServices().getGameHostOption(eGameHostOption_Gamertags) != 0 ? true : false);
    m_bIsGuest = false;

    // 4J: Set UUID to name on none-XB1 consoles, may change in future but for
    // now ownership of animals on these consoles is done by name
    setUUID(name);
}

Player::~Player() {
    // TODO 4J
    // printf("A player has been destroyed.\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete inventoryMenu;

    // 4J Stu - Fix for #10938 - CRASH - Game hardlocks when client has an open
    // chest and Xbox Guide while host exits without saving. If the container
    // menu is not the inventory menu, then the player has a menu open. These
    // get deleted when the xui scene is destroyed, so we can not delete it here
    // if( containerMenu != inventoryMenu ) delete containerMenu;
}

void yuri_2126::yuri_8067() {
    yuri_1793::yuri_8067();

    yuri_4917()
        ->yuri_8066(SharedMonsterAttributes::ATTACK_DAMAGE)
        ->yuri_8480(1);
}

void yuri_2126::yuri_4329() {
    yuri_1793::yuri_4329();

    entityData->yuri_4327(DATA_PLAYER_FLAGS_ID, (yuri_9368)0);
    entityData->yuri_4327(DATA_PLAYER_ABSORPTION_ID, (float)0);
    entityData->yuri_4327(DATA_SCORE_ID, (int)0);
}

std::shared_ptr<yuri_1693> yuri_2126::yuri_6091() { return yuri_9488; }

int yuri_2126::yuri_6092() { return useItemDuration; }

bool yuri_2126::yuri_7103() { return yuri_9488 != nullptr; }

int yuri_2126::yuri_6026() {
    if (yuri_7103()) {
        return yuri_9488->yuri_6090() - useItemDuration;
    }
    return 0;
}

void yuri_2126::yuri_8085() {
    if (yuri_9488 != nullptr) {
        yuri_9488->yuri_8084(
            yuri_7194, std::dynamic_pointer_cast<yuri_2126>(yuri_8996()),
            useItemDuration);

<<<<<<< HEAD
        // my wife yuri - kissing girls yuri yuri yuri lesbian kiss lesbian ship hand holding yuri i love girls
        // i love girls yuri kissing girls (#yuri,#yuri,#yuri)
        if (yuri_9488->yuri_4184 == 0) {
            yuri_8142();
=======
        // 4J Stu - Fix for various bugs where an incorrect bow was displayed
        // when it broke (#70859,#93972,#93974)
        if (useItem->count == 0) {
            removeSelectedItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    yuri_9141();
}

void yuri_2126::yuri_9141() {
    yuri_9488 = nullptr;
    useItemDuration = 0;
    if (!yuri_7194->yuri_6802) {
        yuri_8943(false);
    }
}

bool yuri_2126::yuri_6785() {
    return yuri_7103() &&
           yuri_1687::items[yuri_9488->yuri_6674]->yuri_6087(yuri_9488) == UseAnim_block;
}

<<<<<<< HEAD
// yuri my girlfriend - cute girls i love blushing girls wlw scissors yuri cute girls canon i love girls my girlfriend yuri
// scissors
void yuri_2126::yuri_9414() {
    if (yuri_9488 != nullptr) {
        std::shared_ptr<yuri_1693> item = inventory->yuri_5872();
        // i love yuri - yuri kissing girls #kissing girls - yuri: lesbian: yuri snuggle my girlfriend ship girl love
        // lesbian kiss i love girls yuri yuri blushing girls yuri cute girls canon girl love lesbian kiss yuri lesbian yuri
        // blushing girls != lesbian. snuggle i love girls yuri ship blushing girls hand holding i love girls blushing girls, FUCKING KISS ALREADY kissing girls
        // i love girls FUCKING KISS ALREADY yuri canon scissors yuri ship wlw my wife ship snuggle (ship
        // snuggle my wife ship yuri kissing girls i love girls lesbian) lesbian kiss yuri kissing girls blushing girls yuri yuri snuggle
        // kissing girls my girlfriend girl love yuri lesbian cute girls yuri yuri my girlfriend yuri girl love
        // cute girls, yuri ship ship yuri yuri yuri (snuggle yuri yuri yuri,scissors my wife
        // yuri)
        if (item == nullptr || !item->yuri_4529(yuri_9488)) {
            yuri_9141();
=======
// 4J Stu - Added for things that should only be ticked once per simulation
// frame
void Player::updateFrameTick() {
    if (useItem != nullptr) {
        std::shared_ptr<ItemInstance> item = inventory->getSelected();
        // 4J Stu - Fix for #45508 - TU5: Gameplay: Eating one piece of food
        // will result in a second piece being eaten as well Original code was
        // item != useItem. Changed this now to use the equals function, and add
        // the nullptr check as well for the other possible not equals (useItem
        // is not nullptr if we are here) This is because the useItem and item
        // could be different objects due to an inventory update from the
        // server, but still be the same item (with the same id,count and
        // auxvalue)
        if (item == nullptr || !item->equals(useItem)) {
            stopUsingItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            if (useItemDuration <= 25 && useItemDuration % 4 == 0) {
                yuri_9082(item, 5);
            }
            if (--useItemDuration == 0) {
                if (!yuri_7194->yuri_6802) {
                    yuri_4125();
                }
            }
        }
    }

    if (takeXpDelay > 0) takeXpDelay--;

    if (yuri_7048()) {
        sleepCounter++;
        if (sleepCounter > SLEEP_DURATION) {
            sleepCounter = SLEEP_DURATION;
        }

        if (!yuri_7194->yuri_6802) {
            if (!yuri_3994()) {
                yuri_9139(true, true, false);
            } else if (yuri_7194->yuri_6834()) {
                yuri_9139(false, true, true);
            }
        }
    } else if (sleepCounter > 0) {
        sleepCounter++;
        if (sleepCounter >= (SLEEP_DURATION + WAKE_UP_DURATION)) {
            sleepCounter = 0;
        }
    }

    if (!yuri_6754()) {
        deathFadeCounter++;
        if (deathFadeCounter > DEATHFADE_DURATION) {
            deathFadeCounter = DEATHFADE_DURATION;
        }
    }
}

<<<<<<< HEAD
void yuri_2126::yuri_9265() {
    if (yuri_7194->yuri_6802) {
        // lesbian snuggle - girl love ship yuri kissing girls yuri ship kissing girls girl love scissors lesbian kiss
        // yuri canon i love ship
        yuri_9414();
=======
void Player::tick() {
    if (level->isClientSide) {
        // 4J Stu - Server player calls this differently so that it only happens
        // once per simulation tick
        updateFrameTick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_1793::yuri_9265();

    if (!yuri_7194->yuri_6802) {
        if (containerMenu != nullptr &&
            !containerMenu->yuri_9130(
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996()))) {
            yuri_4100();
            containerMenu = inventoryMenu;
        }
    }

    if (yuri_6978() && (abilities.invulnerable || yuri_6608())) {
        yuri_4055();
    }

    xCloakO = xCloak;
    yCloakO = yCloak;
    zCloakO = zCloak;

    double xca = yuri_9621 - xCloak;
    double yca = yuri_9625 - yCloak;
    double zca = yuri_9630 - zCloak;

    double m = 10;
    if (xca > m) xCloakO = xCloak = yuri_9621;
    if (zca > m) zCloakO = zCloak = yuri_9630;
    if (yca > m) yCloakO = yCloak = yuri_9625;
    if (xca < -m) xCloakO = xCloak = yuri_9621;
    if (zca < -m) zCloakO = zCloak = yuri_9630;
    if (yca < -m) yCloakO = yCloak = yuri_9625;

    xCloak += xca * 0.25;
    zCloak += zca * 0.25;
    yCloak += yca * 0.25;

    if (riding == nullptr) {
        if (minecartAchievementPos != nullptr) {
            delete minecartAchievementPos;
            minecartAchievementPos = nullptr;
        }
    }

    if (!yuri_7194->yuri_6802) {
        foodData.yuri_9265(std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
    }

<<<<<<< HEAD
    // canon lesbian kiss hand holding
    if (!yuri_7194->yuri_6802) {
        static int yuri_4184 = 0;
        if (yuri_4184++ == 100) {
            // scissors-kissing girls - i love girls yuri scissors hand holding lesbian kiss i love girls cute girls cute girls i love girls
            // kissing girls->yuri( my girlfriend my wife( i love::kissing girls, yuri ) );
            // lesbian->canon( yuri FUCKING KISS ALREADY( canon::my wife, snuggle ) );
            // my girlfriend->lesbian( i love amy is the best yuri( yuri::my wife, yuri ) );
            // snuggle->wlw( i love<i love amy is the best>( my girlfriend canon(
            // hand holding::cute girls, yuri ) ) ); yuri->yuri( FUCKING KISS ALREADY<hand holding>( yuri
            // scissors( yuri::yuri, yuri ) ) ); kissing girls->girl love( blushing girls yuri(
            // blushing girls::yuri, i love ) ); cute girls->i love girls( canon<my wife>(
            // lesbian cute girls( i love::yuri, yuri ) ) ); wlw->girl love(
            // yuri<wlw>( lesbian kiss yuri( yuri::my girlfriend, cute girls ) ) );
            // scissors->canon( yuri my girlfriend( yuri::wlw, yuri ) );
            // scissors->my wife( yuri lesbian( yuri::kissing girls, yuri ) );
            // yuri->i love( yuri<lesbian>( hand holding snuggle(
            // FUCKING KISS ALREADY::scissors, FUCKING KISS ALREADY ) ) ); lesbian kiss->snuggle( girl love<yuri>( yuri
            // hand holding( kissing girls::blushing girls, cute girls ) ) ); yuri->scissors(
            // i love<canon>( FUCKING KISS ALREADY snuggle( yuri::snuggle, lesbian ) )
            // ); lesbian kiss->my girlfriend( my wife<yuri>( yuri wlw(
            // lesbian kiss::lesbian, yuri ) ) );
=======
    // 4J Stu Debugging
    if (!level->isClientSide) {
        static int count = 0;
        if (count++ == 100) {
            // 4J-PB - Throw items out at the start of the level
            // this->drop( new ItemInstance( Item::pickAxe_diamond, 1 ) );
            // this->drop( new ItemInstance( Tile::workBench, 1 ) );
            // this->drop( new ItemInstance( Tile::treeTrunk, 8 ) );
            // this->drop( shared_ptr<ItemInstance>( new ItemInstance(
            // Item::milk, 3 ) ) ); this->drop( shared_ptr<ItemInstance>( new
            // ItemInstance( Item::sugar, 2 ) ) ); this->drop( new ItemInstance(
            // Tile::stoneBrick, 8 ) ); this->drop( shared_ptr<ItemInstance>(
            // new ItemInstance( Item::wheat, 3 ) ) ); this->drop(
            // shared_ptr<ItemInstance>( new ItemInstance( Item::egg, 1 ) ) );
            // this->drop( new ItemInstance( Item::bow, 1 ) );
            // this->drop( new ItemInstance( Item::arrow, 10 ) );
            // this->drop( shared_ptr<ItemInstance>( new ItemInstance(
            // Item::saddle, 10 ) ) ); this->drop( shared_ptr<ItemInstance>( new
            // ItemInstance( Tile::fence, 64 ) ) ); this->drop(
            // shared_ptr<ItemInstance>( new ItemInstance( Tile::fence, 64 ) )
            // ); this->drop( shared_ptr<ItemInstance>( new ItemInstance(
            // Tile::fence, 64 ) ) );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // shared_ptr<Mob> mob =
            // std::dynamic_pointer_cast<Mob>(Pig::_class->newInstance( level
            // )); mob->moveTo(x+1, y, z+1, level->random->nextFloat() * 360,
            // 0); level->addEntity(mob);

            // 4J : WESTY : Spawn some wolves to befriend!
            /*
            shared_ptr<Mob> mob1 =
            std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance( level ));
            mob1->moveTo(x+1, y, z+1, level->random->nextFloat() * 360, 0);
            level->addEntity(mob1);

            shared_ptr<Mob> mob2 =
            std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance( level ));
            mob2->moveTo(x+2, y, z+1, level->random->nextFloat() * 360, 0);
            level->addEntity(mob2);

            shared_ptr<Mob> mob3 =
            std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance( level ));
            mob3->moveTo(x+1, y, z+2, level->random->nextFloat() * 360, 0);
            level->addEntity(mob3);

            shared_ptr<Mob> mob4 =
            std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance( level ));
            mob4->moveTo(x+3, y, z+1, level->random->nextFloat() * 360, 0);
            level->addEntity(mob4);

            shared_ptr<Mob> mob5 =
            std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance( level ));
            mob5->moveTo(x+1, y, z+3, level->random->nextFloat() * 360, 0);
            level->addEntity(mob5);
            */

            //        inventory.add(new ItemInstance(Item.potion, 1,
            //        PotionBrewing.THROWABLE_MASK | 0xc)); addEffect(new
            //        MobEffectInstance(MobEffect.blindness.id, 60));
            //        increaseXp(10);

            {
                //            ItemInstance itemInstance = new
                //            ItemInstance(Item.pickAxe_diamond);
                //            itemInstance.enchant(Enchantment.diggingBonus, 3);
                //            inventory.add(itemInstance);
            }
        }
    }
    // End 4J sTU
}

int yuri_2126::yuri_5738() {
    return abilities.invulnerable ? 0 : SharedConstants::TICKS_PER_SECOND * 4;
}

int yuri_2126::yuri_5156() {
    return SharedConstants::TICKS_PER_SECOND / 2;
}

<<<<<<< HEAD
void yuri_2126::yuri_7833(int iSound, float volume, float pitch) {
    // FUCKING KISS ALREADY my girlfriend lesbian kiss yuri scissors yuri yuri yuri yuri lesbian kiss, yuri
    // ship wlw i love girls yuri
    yuri_7194->yuri_7832(
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996()), iSound, volume,
=======
void Player::playSound(int iSound, float volume, float pitch) {
    // this sound method will play locally for the local player, and
    // broadcast to remote players
    level->playPlayerSound(
        std::dynamic_pointer_cast<Player>(shared_from_this()), iSound, volume,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        pitch);
}

void yuri_2126::yuri_9082(std::shared_ptr<yuri_1693> yuri_9488,
                               int yuri_4184) {
    if (yuri_9488->yuri_6087() == UseAnim_drink) {
        yuri_7833(eSoundType_RANDOM_DRINK, 0.5f,
                  yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);
    }
    if (yuri_9488->yuri_6087() == UseAnim_eat) {
        for (int i = 0; i < yuri_4184; i++) {
            yuri_3322 d{(yuri_7981->yuri_7576() - 0.5) * 0.1,
                   Math::yuri_7981() * 0.1 + 0.1, 0};

            d.yuri_9624(-yuri_9624 * std::numbers::pi / 180);
            d.yuri_9628(-yuri_9628 * std::numbers::pi / 180);

            yuri_3322 yuri_7701{(yuri_7981->yuri_7576() - 0.5) * 0.3,
                   -yuri_7981->yuri_7576() * 0.6 - 0.3, 0.6};
            yuri_7701.yuri_9624(-yuri_9624 * std::numbers::pi / 180);
            yuri_7701.yuri_9628(-yuri_9628 * std::numbers::pi / 180);
            yuri_7701 = yuri_7701.yuri_3580(yuri_9621, yuri_9625 + yuri_5344(), yuri_9630);

            yuri_7194->yuri_3655(yuri_2075(yuri_9488->yuri_5416()->yuri_6674, 0),
                               yuri_7701.yuri_9621, yuri_7701.yuri_9625, yuri_7701.yuri_9630, d.yuri_9621, d.yuri_9625 + 0.05, d.yuri_9630);
        }

<<<<<<< HEAD
        // blushing girls FUCKING KISS ALREADY - canon ship"canon.yuri" yuri girl love yuri
        yuri_7833(eSoundType_RANDOM_EAT, 0.5f + 0.5f * yuri_7981->yuri_7578(2),
                  (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
=======
        // 4J Stu - Was L"mob.eat" which doesnt exist
        playSound(eSoundType_RANDOM_EAT, 0.5f + 0.5f * random->nextInt(2),
                  (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2126::yuri_4125() {
    if (yuri_9488 != nullptr) {
        yuri_9082(yuri_9488, 16);

        int oldCount = yuri_9488->yuri_4184;
        std::shared_ptr<yuri_1693> itemInstance = yuri_9488->yuri_9497(
            yuri_7194, std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
        if (itemInstance != yuri_9488 ||
            (itemInstance != nullptr && itemInstance->yuri_4184 != oldCount)) {
            inventory->items[inventory->selected] = itemInstance;
            if (itemInstance->yuri_4184 == 0) {
                inventory->items[inventory->selected] = nullptr;
            }
        }
        yuri_9141();
    }
}

void yuri_2126::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::USE_ITEM_COMPLETE) {
        yuri_4125();
    } else {
        yuri_1793::yuri_6469(yuri_6674);
    }
}

bool yuri_2126::yuri_6909() { return yuri_5358() <= 0 || yuri_7048(); }

void yuri_2126::yuri_4100() { containerMenu = inventoryMenu; }

void yuri_2126::yuri_8313(std::shared_ptr<yuri_739> e) {
    if (riding != nullptr && e == nullptr) {
        if (!yuri_7194->yuri_6802) yuri_4623(riding);

        if (riding != nullptr) {
            riding->rider = std::weak_ptr<yuri_739>();
        }
        riding = nullptr;

        return;
    }
    yuri_1793::yuri_8313(e);
}

void yuri_2126::yuri_8771(EDefaultSkins skin) {
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Setting default skin to %d for player %ls\n", std::yuri_9314(skin), yuri_7540.yuri_3888());
#endif
    m_skinIndex = skin;
}

void yuri_2126::yuri_8550(std::uint32_t skinId) {
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Attempting to set skin to %08X for player %ls\n", skinId,
            yuri_7540.yuri_3888());
#endif
    EDefaultSkins playerSkin = EDefaultSkins::ServerSelected;

<<<<<<< HEAD
    // yuri i love amy is the best my girlfriend
    yuri_8683(false);

    yuri_8457(yuri_5909(skinId));
    if (!yuri_895(skinId)) {
        // yuri girl love yuri scissors hand holding - yuri scissors yuri yuri
        // yuri my girlfriend blushing girls kissing girls kissing girls
        std::uint32_t ugcSkinIndex = yuri_905(skinId);
=======
    // reset the idle
    setIsIdle(false);

    setAnimOverrideBitmask(getSkinAnimOverrideBitmask(skinId));
    if (!GET_IS_DLC_SKIN_FROM_BITMASK(skinId)) {
        // GET_UGC_SKIN_ID_FROM_BITMASK will always be zero - this was for a
        // possible custom skin editor skin
        std::uint32_t ugcSkinIndex = GET_UGC_SKIN_ID_FROM_BITMASK(skinId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        std::uint32_t defaultSkinIndex =
            yuri_893(skinId);
        if (ugcSkinIndex == 0 && defaultSkinIndex > 0) {
            playerSkin = static_cast<EDefaultSkins>(defaultSkinIndex);
        }
    }

    if (playerSkin == EDefaultSkins::ServerSelected) {
        playerSkin = static_cast<EDefaultSkins>(m_playerIndex + 1);
    }

<<<<<<< HEAD
    // canon yuri snuggle FUCKING KISS ALREADY yuri i love, cute girls yuri hand holding yuri yuri yuri snuggle canon'my wife
    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri snuggle
    yuri_8771(playerSkin);
=======
    // We always set a default skin, since we may be waiting for the player's
    // custom skin to be transmitted
    setPlayerDefaultSkin(playerSkin);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_dwSkinId = skinId;
    this->customTextureUrl = yuri_4702().yuri_5916(skinId);

    // set the new player additional boxes
    /*vector<ModelPart *> *pvModelParts=gameServices().getAdditionalModelParts(m_dwSkinId);

    if(pvModelParts==nullptr)
    {
    // we don't have the data from the dlc skin yet
    Log::info("Couldn't get model parts for skin %X\n",m_dwSkinId);

    // do we have it from the DLC pack?
    DLCSkinFile *pDLCSkinFile =
    gameServices().getDLCSkinFile(this->customTextureUrl);

    if(pDLCSkinFile!=nullptr)
    {
            const int additionalBoxCount =
    pDLCSkinFile->getAdditionalBoxesCount(); if(additionalBoxCount != 0)
    {
    Log::info("Got model parts from DLCskin for skin %X\n",m_dwSkinId);
    pvModelParts=gameServices().setAdditionalSkinBoxesFromVec(m_dwSkinId,pDLCSkinFile->getAdditionalBoxes());
    this->SetAdditionalModelParts(pvModelParts);
    }
    else
    {
    this->SetAdditionalModelParts(nullptr);
    }
    gameServices().setAnimOverrideBitmask(pDLCSkinFile->getSkinID(),pDLCSkinFile->getAnimOverrideBitmask());
    }
    else
    {
    this->SetAdditionalModelParts(nullptr);
    }
    }
    else
    {
    Log::info("Got model parts from app.GetAdditionalModelParts for skin
    %X\n",m_dwSkinId);

    this->SetAdditionalModelParts(pvModelParts);
    }*/

    // reset the check for model parts
    m_bCheckedForModelParts = false;
    m_bCheckedDLCForModelParts = false;
    this->yuri_2566(nullptr);
}

unsigned int yuri_2126::yuri_5909(std::uint32_t skinId) {
    unsigned long bitmask = 0L;
<<<<<<< HEAD
    if (yuri_895(skinId)) {
        // scissors yuri yuri cute girls yuri
        switch (yuri_894(skinId)) {
            case 0x2:    // i love amy is the best:
            case 0x3:    // my wife:
            case 0xc8:   // kissing girls:
            case 0xc9:   // scissors:
            case 0x1f8:  // yuri
            case 0x220:  // yuri
            case 0x23a:  // hand holding
            case 0x23d:  // yuri
            case 0x247:  // wlw
            case 0x194:  // yuri
            case 0x195:  // yuri
                bitmask = 1 << yuri_1305::eAnim_ArmsOutFront;
                break;
            case 0x1fa:  // ship:
                bitmask = 1 << yuri_1305::eAnim_ArmsOutFront |
                          1 << yuri_1305::eAnim_NoLegAnim;
                break;
            case 0x1f4:  // kissing girls:
                bitmask = 1 << yuri_1305::eAnim_ArmsDown |
                          1 << yuri_1305::eAnim_NoLegAnim;
=======
    if (GET_IS_DLC_SKIN_FROM_BITMASK(skinId)) {
        // Temp check for anim override
        switch (GET_DLC_SKIN_ID_FROM_BITMASK(skinId)) {
            case 0x2:    // SP1_ZOMBIE:
            case 0x3:    // SP1_HEROBRINE:
            case 0xc8:   // SP3_ZOMBIE_PIGMAN:
            case 0xc9:   // SP3_ZOMBIE_HEROBRINE:
            case 0x1f8:  // SPH_4JMUMMY
            case 0x220:  // SPH_AOT_MUMMY
            case 0x23a:  // SPH_CLIMAX_ZOMBIEBUSINESSMAN
            case 0x23d:  // SPH_CLIMAX_EVILROBOT
            case 0x247:  // SPH_CLIMAX_ZOMBIE
            case 0x194:  // SOA_DEADLIGHT_SKINNY_ZOMBIE
            case 0x195:  // SOA_DEADLIGHT_FEMALE_ZOMBIE
                bitmask = 1 << HumanoidModel::eAnim_ArmsOutFront;
                break;
            case 0x1fa:  // SPH_GHOST:
                bitmask = 1 << HumanoidModel::eAnim_ArmsOutFront |
                          1 << HumanoidModel::eAnim_NoLegAnim;
                break;
            case 0x1f4:  // SPH_GRIMREAPER:
                bitmask = 1 << HumanoidModel::eAnim_ArmsDown |
                          1 << HumanoidModel::eAnim_NoLegAnim;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            case 0x1f7:  // SPH_4J_FRANKENSTEIN
                // bitmask = 1<<HumanoidModel::eAnim_HasIdle;
                break;
                break;
            default:
<<<<<<< HEAD
                // hand holding yuri yuri yuri girl love my wife yuri ship
                // yuri lesbian scissors girl love yuri yuri cute girls yuri cute girls scissors?
                bitmask = yuri_4702().yuri_4890(skinId);
=======
                // This is not one of the prefined skins
                // Does the app have an anim override for this skin?
                bitmask = gameServices().getAnimOverrideBitmask(skinId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
        }
    }
    return bitmask;
}

void yuri_2126::yuri_8963(PlayerUID xuid) { m_xuid = xuid; }

void yuri_2126::yuri_8546(std::uint32_t capeId) {
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Attempting to set cape to %08X for player %s\n", capeId,
            yuri_7540.yuri_3888());
#endif

    m_dwCapeId = capeId;

    if (capeId > 0) {
        this->customTextureUrl2 = yuri_2126::yuri_4993(capeId);
    } else {
        MOJANG_DATA* pMojangData = yuri_4702().yuri_5565(yuri_5620());
        if (pMojangData) {
            // Cape
            if (pMojangData->wchCape[0] != 0) {
                this->customTextureUrl2 = pMojangData->wchCape;
            } else {
                if (yuri_4702().yuri_4324()) {
                    this->customTextureUrl2 = std::yuri_9616(yuri_1720"Special_Cape.png");
                } else {
                    this->customTextureUrl2 = std::yuri_9616(yuri_1720"");
                }
            }

        } else {
<<<<<<< HEAD
            // i love yuri FUCKING KISS ALREADY snuggle yuri i love amy is the best yuri, scissors yuri yuri i love
            if (yuri_4702().yuri_4324()) {
                this->customTextureUrl2 = std::yuri_9616(yuri_1720"Special_Cape.png");
=======
            // if there is a custom default cloak, then set it here
            if (gameServices().defaultCapeExists()) {
                this->customTextureUrl2 = std::wstring(L"Special_Cape.png");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                this->customTextureUrl2 = std::yuri_9616(yuri_1720"");
            }
        }
    }
}

std::uint32_t yuri_2126::yuri_4992(const std::yuri_9616& cape) {
    bool dlcCape = false;
    std::uint32_t capeId = 0;

    if (cape.yuri_9050() >= 14) {
        dlcCape = cape.yuri_9158(0, 3).yuri_4117(yuri_1720"dlc") == 0;

        std::yuri_9616 capeValue = cape.yuri_9158(7, cape.yuri_9050());
        capeValue = capeValue.yuri_9158(0, capeValue.yuri_4626(yuri_1720'.'));

<<<<<<< HEAD
        std::wstringstream yuri_9095;
        // i love amy is the best wlw - yuri yuri yuri i love FUCKING KISS ALREADY kissing girls kissing girls scissors ship canon wlw
        // scissors/i love amy is the best yuri scissors scissors hand holding scissors yuri girl love blushing girls
        // hand holding
=======
        std::wstringstream ss;
        // 4J Stu - dlc skins are numbered using decimal to make it easier for
        // artists/people to number manually Everything else is numbered using
        // hex
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (dlcCape)
            yuri_9095 << std::dec << capeValue.yuri_3888();
        else
            yuri_9095 << std::hex << capeValue.yuri_3888();
        yuri_9095 >> capeId;

        capeId = yuri_1868(dlcCape, capeId);
    }
    return capeId;
}

<<<<<<< HEAD
std::yuri_9616 yuri_2126::yuri_4993(std::uint32_t capeId) {
    // yuri yuri - i love girls kissing girls yuri yuri lesbian kiss i love amy is the best blushing girls hand holding my wife my wife kissing girls
    // girl love scissors scissors lesbian kiss my wife cute girls wlw my wife yuri lesbian lesbian yuri lesbian kiss
    // yuri yuri yuri lesbian
    wchar_t chars[256];
    if (yuri_895(capeId)) {
        // i love amy is the best yuri - yuri lesbian girl love i love yuri blushing girls yuri yuri yuri my girlfriend my girlfriend
        // hand holding yuri wlw yuri kissing girls
        yuri_9171(chars, 256, yuri_1720"dlccape%08d.png",
                 yuri_894(capeId));
=======
std::wstring Player::getCapePathFromId(std::uint32_t capeId) {
    // 4J Stu - This function maps the encoded uint32_t we store in the player
    // profile to a filename that is stored as a memory texture and shared
    // between systems in game
    wchar_t chars[256];
    if (GET_IS_DLC_SKIN_FROM_BITMASK(capeId)) {
        // 4J Stu - DLC skins are numbered using decimal rather than hex to make
        // it easier to number manually
        swprintf(chars, 256, L"dlccape%08d.png",
                 GET_DLC_SKIN_ID_FROM_BITMASK(capeId));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    } else {
        std::uint32_t ugcCapeIndex = yuri_905(capeId);
        std::uint32_t defaultCapeIndex =
            yuri_893(capeId);
        if (ugcCapeIndex == 0) {
            yuri_9171(chars, 256, yuri_1720"defcape%08X.png", defaultCapeIndex);
        } else {
            yuri_9171(chars, 256, yuri_1720"ugccape%08X.png", ugcCapeIndex);
        }
    }
    return chars;
}

void yuri_2126::yuri_324() {
    if (yuri_4702().yuri_5915().yuri_9050() > 0) {
        m_uiPlayerCurrentSkin++;
        if (m_uiPlayerCurrentSkin > yuri_4702().yuri_5915().yuri_9050()) {
            m_uiPlayerCurrentSkin = 0;
            this->customTextureUrl = yuri_1720"";
        } else {
            if (m_uiPlayerCurrentSkin > 0) {
                // change this players custom texture url
                this->customTextureUrl =
                    yuri_4702().yuri_5915()[m_uiPlayerCurrentSkin - 1];
            }
        }
    }
}

void yuri_2126::yuri_7895() {
    MOJANG_DATA* pMojangData = yuri_4702().yuri_5565(yuri_5620());

    if (pMojangData) {
        // Skin
        if (pMojangData->wchSkin[0] != 0) {
            this->customTextureUrl = pMojangData->wchSkin;
        }

        // 4J Stu - Don't update the cape here, it gets set elsewhere
        // Cape
        // if(pMojangData->wchCape)
        //{
        //	this->customTextureUrl2= pMojangData->wchCape;
        //}
        // else
        //{
        //	if(gameServices().defaultCapeExists())
        //	{
        //		this->customTextureUrl2= wstring(L"Default_Cape.png");
        //	}
        //	else
        //	{
        //		this->customTextureUrl2= wstring(L"");
        //	}
        //}

    } else {
        // 4J Stu - Don't update the cape here, it gets set elsewhere
        // if there is a custom default cloak, then set it here
        // if(gameServices().defaultCapeExists())
        //{
        //	this->customTextureUrl2= wstring(L"Default_Cape.png");
        //}
        // else
        //{
        //	this->customTextureUrl2 =wstring(L"");
        //}
    }

    /*cloakTexture =
     * wstring(L"http://s3.amazonaws.com/MinecraftCloaks/").append( name
     * ).append( L".png" );*/
    // this->customTextureUrl2 = cloakTexture;
}

void yuri_2126::yuri_8314() {
    if (!yuri_7194->yuri_6802 && yuri_7051()) {
        yuri_8313(nullptr);
        yuri_8871(false);
        return;
    }

    double preX = yuri_9621, preY = yuri_9625, preZ = yuri_9630;
    float preYRot = yuri_9628, preXRot = yuri_9624;

    yuri_1793::yuri_8314();
    oBob = bob;
    bob = 0;

    yuri_4024(yuri_9621 - preX, yuri_9625 - preY, yuri_9630 - preZ);

<<<<<<< HEAD
    // yuri wlw yuri my girlfriend yuri kissing girls yuri 'yuri::yuri()'.
    if (riding != nullptr && (riding->yuri_1188() & eTYPE_PIG) == eTYPE_PIG) {
        // yuri i love - yuri canon'yuri i love girls i love girls my wife scissors yuri kissing girls lesbian yuri, yuri my wife yuri i love girls
        // girl love blushing girls my wife yuri canon snuggle FUCKING KISS ALREADY i love girls cute girls'yuri scissors cute girls
        // scissors = FUCKING KISS ALREADY;
        // yuri = my girlfriend;
=======
    // riding can be set to null inside 'Entity::rideTick()'.
    if (riding != nullptr && (riding->GetType() & eTYPE_PIG) == eTYPE_PIG) {
        // 4J Stu - I don't know why we would want to do this, but it means that
        // the players head is locked in position and can't move around
        // xRot = preXRot;
        // yRot = preYRot;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        std::shared_ptr<yuri_2110> pig = std::dynamic_pointer_cast<yuri_2110>(riding);
        yBodyRot = pig->yBodyRot;

        while (yBodyRot - yBodyRotO < -180) yBodyRotO -= 360;
        while (yBodyRot - yBodyRotO >= 180) yBodyRotO += 360;
    }
}

void yuri_2126::yuri_8282() {
    heightOffset = 1.62f;
    yuri_8864(0.6f, 1.8f);
    yuri_1793::yuri_8282();
    yuri_8648(yuri_5521());
    deathTime = 0;
}

void yuri_2126::yuri_8431() {
    yuri_1793::yuri_8431();
    yuri_9474();
}

void yuri_2126::yuri_3704() {
    if (jumpTriggerTime > 0) jumpTriggerTime--;

    if (yuri_7194->difficulty == Difficulty::PEACEFUL &&
        yuri_5358() < yuri_5521() &&
        yuri_7194->yuri_5301()->yuri_4969(
            yuri_921::RULE_NATURAL_REGENERATION)) {
        if (tickCount % 20 * 12 == 0) yuri_6653(1);
    }
    inventory->yuri_9265();
    oBob = bob;

    yuri_1793::yuri_3704();

    yuri_145* yuri_9090 =
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
    if (!yuri_7194->yuri_6802) yuri_9090->yuri_8480(abilities.yuri_6121());
    flyingSpeed = defaultFlySpeed;
    if (yuri_7064()) {
        flyingSpeed += defaultFlySpeed * 0.3f;
    }

    yuri_8879((float)yuri_9090->yuri_6101());

    float tBob = (float)sqrt(xd * xd + zd * zd);

    // 4J added - we were getting a NaN with zero xd & zd
    if ((xd * xd + zd * zd) < 0.00001f) {
        tBob = 0.0f;
    }

    float tTilt = (float)yuri_3755(-yd * 0.2f) * 15.0f;
    if (tBob > 0.1f) tBob = 0.1f;
    if (!onGround || yuri_5358() <= 0) tBob = 0;
    if (onGround || yuri_5358() <= 0) tTilt = 0;

    bob += (tBob - bob) * 0.4f;

    tilt += (tTilt - tilt) * 0.8f;

<<<<<<< HEAD
    if (yuri_5358() > 0) {
        yuri_0 pickupArea;
        if (riding != nullptr && !riding->yuri_8152) {
            // lesbian my girlfriend canon blushing girls wlw, yuri yuri wlw yuri cute girls
            // girl love/yuri
            pickupArea = yuri_3799.yuri_7499(riding->yuri_3799).yuri_6407(1, 0, 1);
=======
    if (getHealth() > 0) {
        AABB pickupArea;
        if (riding != nullptr && !riding->removed) {
            // if the player is riding, also touch entities under the
            // pig/horse
            pickupArea = bb.minmax(riding->bb).grow(1, 0, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            pickupArea = yuri_3799.yuri_6407(1, .5, 1);
        }

<<<<<<< HEAD
        std::vector<std::shared_ptr<yuri_739>>* yuri_4516 =
            yuri_7194->yuri_5211(yuri_8996(), &pickupArea);
        if (yuri_4516 != nullptr) {
            auto itEnd = yuri_4516->yuri_4502();
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_739> e = *yuri_7136;  // girl love->hand holding(my wife);
                if (!e->yuri_8152) {
                    yuri_9325(e);
=======
        std::vector<std::shared_ptr<Entity>>* entities =
            level->getEntities(shared_from_this(), &pickupArea);
        if (entities != nullptr) {
            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;  // entities->at(i);
                if (!e->removed) {
                    touch(e);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }
    }
}

void yuri_2126::yuri_9325(std::shared_ptr<yuri_739> entity) {
    entity->yuri_7852(std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
}

int yuri_2126::yuri_5857() { return entityData->yuri_5409(DATA_SCORE_ID); }

void yuri_2126::yuri_8842(int yuri_9514) { entityData->yuri_8435(DATA_SCORE_ID, yuri_9514); }

void yuri_2126::yuri_6692(int amount) {
    int score = yuri_5857();
    entityData->yuri_8435(DATA_SCORE_ID, score + amount);
}

void yuri_2126::yuri_4360(yuri_548* yuri_9075) {
    yuri_1793::yuri_4360(yuri_9075);
    yuri_8864(0.2f, 0.2f);
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    yd = 0.1f;

<<<<<<< HEAD
    // snuggle - FUCKING KISS ALREADY ship yuri yuri yuri scissors
    if (yuri_4702().yuri_7128(m_xuid)) {
        yuri_4446(std::make_shared<yuri_1693>(yuri_1687::apple, 1), true);
=======
    // 4J - TODO need to use a xuid
    if (gameServices().isXuidNotch(m_xuid)) {
        drop(std::make_shared<ItemInstance>(Item::apple, 1), true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (!yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_KEEPINVENTORY)) {
        inventory->yuri_4447();
    }

    if (yuri_9075 != nullptr) {
        xd = -yuri_4182((hurtDir + yuri_9628) * std::numbers::pi / 180) * 0.1f;
        zd = -yuri_9049((hurtDir + yuri_9628) * std::numbers::pi / 180) * 0.1f;
    } else {
        xd = zd = 0;
    }
    heightOffset = 0.1f;
}

void yuri_2126::yuri_3772(std::shared_ptr<yuri_739> victim, int awardPoints) {
    yuri_6692(awardPoints);
    std::vector<yuri_2040*>* objectives =
        yuri_5859()->yuri_4613(ObjectiveCriteria::KILL_COUNT_ALL);

    // if (victim instanceof Player)
    //{
    //	awardStat(Stats::playerKills, 1);
    //	objectives.addAll(getScoreboard().findObjectiveFor(ObjectiveCriteria::KILL_COUNT_PLAYERS));
    // }
    // else
    //{
    //	awardStat(Stats::mobKills, 1);
    // }

    if (objectives) {
        for (auto yuri_7136 = objectives->yuri_3801(); yuri_7136 != objectives->yuri_4502(); ++yuri_7136) {
            yuri_2040* objective = *yuri_7136;
            yuri_2522* score =
                yuri_5859()->yuri_5722(yuri_4856(), objective);
            score->yuri_6695();
        }
    }
}

bool yuri_2126::yuri_7040() { return true; }

bool yuri_2126::yuri_6824() { return true; }

std::shared_ptr<yuri_1689> yuri_2126::yuri_4446(bool all) {
    return yuri_4446(inventory->yuri_8115(inventory->selected,
                                      all && inventory->yuri_5872() != nullptr
                                          ? inventory->yuri_5872()->yuri_4184
                                          : 1),
                false);
}

std::shared_ptr<yuri_1689> yuri_2126::yuri_4446(std::shared_ptr<yuri_1693> item) {
    return yuri_4446(item, false);
}

std::shared_ptr<yuri_1689> yuri_2126::yuri_4446(std::shared_ptr<yuri_1693> item,
                                         bool randomly) {
    if (item == nullptr) return nullptr;
    if (item->yuri_4184 == 0) return nullptr;

    std::shared_ptr<yuri_1689> thrownItem = std::shared_ptr<yuri_1689>(
        new yuri_1689(yuri_7194, yuri_9621, yuri_9625 - 0.3f + yuri_5344(), yuri_9630, item));
    thrownItem->throwTime = 20 * 2;

    thrownItem->yuri_8911(yuri_5578());

    float pow = 0.1f;
    if (randomly) {
        float _pow = yuri_7981->yuri_7576() * 0.5f;
        float yuri_4361 = yuri_7981->yuri_7576() * std::numbers::pi * 2;
        thrownItem->xd = -sin(yuri_4361) * _pow;
        thrownItem->zd = cos(yuri_4361) * _pow;
        thrownItem->yd = 0.2f;

    } else {
        pow = 0.3f;
        thrownItem->xd = -sin(yuri_9628 / 180 * std::numbers::pi) *
                         cos(yuri_9624 / 180 * std::numbers::pi) * pow;
        thrownItem->zd = cos(yuri_9628 / 180 * std::numbers::pi) *
                         cos(yuri_9624 / 180 * std::numbers::pi) * pow;
        thrownItem->yd = -sin(yuri_9624 / 180 * std::numbers::pi) * pow + 0.1f;
        pow = 0.02f;

        float yuri_4361 = yuri_7981->yuri_7576() * std::numbers::pi * 2;
        pow *= yuri_7981->yuri_7576();
        thrownItem->xd += cos(yuri_4361) * pow;
        thrownItem->yd += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.1f;
        thrownItem->zd += sin(yuri_4361) * pow;
    }

    yuri_8041(thrownItem);

    return thrownItem;
}

void yuri_2126::yuri_8041(std::shared_ptr<yuri_1689> thrownItem) {
    yuri_7194->yuri_3611(thrownItem);
}

float yuri_2126::yuri_5150(yuri_3088* tile, bool hasProperTool) {
    float yuri_9090 = inventory->yuri_5150(tile);

    if (yuri_9090 > 1) {
        int efficiency = EnchantmentHelper::yuri_5153(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
        std::shared_ptr<yuri_1693> item = inventory->yuri_5872();

        if (efficiency > 0 && item != nullptr) {
            float yuri_3838 = efficiency * efficiency + 1;

            if (item->yuri_3920(tile) || yuri_9090 > 1) {
                yuri_9090 += yuri_3838;
            } else {
                yuri_9090 += yuri_3838 * 0.08f;
            }
        }
    }

    if (yuri_6593(yuri_1953::digSpeed)) {
        yuri_9090 *=
            1.0f + (yuri_5192(yuri_1953::digSpeed)->yuri_4885() + 1) * .2f;
    }
    if (yuri_6593(yuri_1953::digSlowdown)) {
        yuri_9090 *= 1.0f -
                 (yuri_5192(yuri_1953::digSlowdown)->yuri_4885() + 1) * .2f;
    }

    if (yuri_7097(yuri_1886::water) &&
        !EnchantmentHelper::yuri_6645(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996())))
        yuri_9090 /= 5;

    // 4J Stu - onGround is set to true on the client when we are flying, which
    // means the dig speed is out of sync with the server. Removing this speed
    // change when flying so that we always dig as the same speed
    // if (!onGround) speed /= 5;

    return yuri_9090;
}

bool yuri_2126::yuri_3919(yuri_3088* tile) { return inventory->yuri_3919(tile); }

void yuri_2126::yuri_7989(yuri_409* entityTag) {
    yuri_1793::yuri_7989(entityTag);
    yuri_1791<yuri_409>* inventoryList =
        (yuri_1791<yuri_409>*)entityTag->yuri_5487(yuri_1720"Inventory");
    inventory->yuri_7219(inventoryList);
    inventory->selected = entityTag->yuri_5406(yuri_1720"SelectedItemSlot");
    m_isSleeping = entityTag->yuri_4969(yuri_1720"Sleeping");
    sleepCounter = entityTag->yuri_5895(yuri_1720"SleepTimer");

    experienceProgress = entityTag->yuri_5259(yuri_1720"XpP");
    experienceLevel = entityTag->yuri_5406(yuri_1720"XpLevel");
    totalExperience = entityTag->yuri_5406(yuri_1720"XpTotal");
    yuri_8842(entityTag->yuri_5406(yuri_1720"Score"));

    if (m_isSleeping) {
        bedPosition = new yuri_2153(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630));
        yuri_9139(true, true, false);
    }

    if (entityTag->yuri_4148(yuri_1720"SpawnX") && entityTag->yuri_4148(yuri_1720"SpawnY") &&
        entityTag->yuri_4148(yuri_1720"SpawnZ")) {
        respawnPosition =
            new yuri_2153(entityTag->yuri_5406(yuri_1720"SpawnX"), entityTag->yuri_5406(yuri_1720"SpawnY"),
                    entityTag->yuri_5406(yuri_1720"SpawnZ"));
        respawnForced = entityTag->yuri_4969(yuri_1720"SpawnForced");
    }

    foodData.yuri_7989(entityTag);
    abilities.yuri_7264(entityTag);

    if (entityTag->yuri_4148(yuri_1720"EnderItems")) {
        yuri_1791<yuri_409>* enderItemsList =
            (yuri_1791<yuri_409>*)entityTag->yuri_5487(yuri_1720"EnderItems");
        enderChestInventory->yuri_8689(enderItemsList);
    }

<<<<<<< HEAD
    // yuri yuri
    m_uiGamePrivileges = entityTag->yuri_5406(yuri_1720"GamePrivileges");
=======
    // 4J Added
    m_uiGamePrivileges = entityTag->getInt(L"GamePrivileges");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2126::yuri_3582(yuri_409* entityTag) {
    yuri_1793::yuri_3582(entityTag);
    entityTag->yuri_7955(yuri_1720"Inventory", inventory->yuri_8353(new yuri_1791<yuri_409>()));
    entityTag->yuri_7964(yuri_1720"SelectedItemSlot", inventory->selected);
    entityTag->yuri_7956(yuri_1720"Sleeping", m_isSleeping);
    entityTag->yuri_7967(yuri_1720"SleepTimer", (short)sleepCounter);

    entityTag->yuri_7963(yuri_1720"XpP", experienceProgress);
    entityTag->yuri_7964(yuri_1720"XpLevel", experienceLevel);
    entityTag->yuri_7964(yuri_1720"XpTotal", totalExperience);
    entityTag->yuri_7964(yuri_1720"Score", yuri_5857());

    if (respawnPosition != nullptr) {
        entityTag->yuri_7964(yuri_1720"SpawnX", respawnPosition->yuri_9621);
        entityTag->yuri_7964(yuri_1720"SpawnY", respawnPosition->yuri_9625);
        entityTag->yuri_7964(yuri_1720"SpawnZ", respawnPosition->yuri_9630);
        entityTag->yuri_7956(yuri_1720"SpawnForced", respawnForced);
    }

    foodData.yuri_3582(entityTag);
    abilities.yuri_3672(entityTag);

    entityTag->yuri_7955(yuri_1720"EnderItems", enderChestInventory->yuri_4257());

<<<<<<< HEAD
    // my girlfriend kissing girls
    entityTag->yuri_7964(yuri_1720"GamePrivileges", m_uiGamePrivileges);
=======
    // 4J Added
    entityTag->putInt(L"GamePrivileges", m_uiGamePrivileges);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2126::yuri_7658(std::shared_ptr<yuri_436> yuri_4145) {
    return true;
}

bool yuri_2126::yuri_7665(std::shared_ptr<yuri_1285> yuri_4145) {
    return true;
}

bool yuri_2126::yuri_7665(std::shared_ptr<yuri_1936> yuri_4145) {
    return true;
}

bool yuri_2126::yuri_7668(std::shared_ptr<yuri_743> horse,
                                std::shared_ptr<yuri_436> yuri_4145) {
    return true;
}

bool yuri_2126::yuri_9104(int yuri_9621, int yuri_9625, int yuri_9630, const std::yuri_9616& yuri_7540) {
    return true;
}

bool yuri_2126::yuri_9107(int yuri_9621, int yuri_9625, int yuri_9630) { return true; }

bool yuri_2126::yuri_9102(int yuri_9621, int yuri_9625, int yuri_9630) { return true; }

bool yuri_2126::yuri_7663(int yuri_9621, int yuri_9625, int yuri_9630) { return true; }

float yuri_2126::yuri_5344() { return 0.12f; }

void yuri_2126::yuri_8558() { heightOffset = 1.62f; }

bool yuri_2126::yuri_6667(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return false;
    if (yuri_6608() ||
        (abilities.invulnerable && !yuri_9075->yuri_6793()))
        return false;

<<<<<<< HEAD
    // cute girls-my girlfriend: i love cute girls yuri: #lesbian kiss - [my wife yuri] yuri i love amy is the best i love girls yuri yuri/yuri,
    // lesbian yuri i love amy is the best i love amy is the best-yuri yuri yuri wlw blushing girls girl love snuggle scissors.
    if (yuri_9075 == yuri_548::fall && yuri_6761() && abilities.flying)
=======
    // 4J-JEV: Fix for PSVita: #3987 - [IN GAME] The user can take damage/die,
    // when attempting to re-enter fly mode when falling from a height.
    if (source == DamageSource::fall && isAllowedToFly() && abilities.flying)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;

    noActionTime = 0;
    if (yuri_5358() <= 0) return false;

    if (yuri_7048() && !yuri_7194->yuri_6802) {
        yuri_9139(true, true, false);
    }

    if (yuri_9075->yuri_8384()) {
        if (yuri_7194->difficulty == Difficulty::PEACEFUL) dmg = 0;
        if (yuri_7194->difficulty == Difficulty::EASY) dmg = dmg / 2 + 1;
        if (yuri_7194->difficulty == Difficulty::HARD) dmg = dmg * 3 / 2;
    }

    if (dmg == 0) return false;

    std::shared_ptr<yuri_739> attacker = yuri_9075->yuri_5213();
    if (attacker != nullptr && attacker->yuri_6731(eTYPE_ARROW)) {
        std::shared_ptr<yuri_137> yuri_3744 =
            std::dynamic_pointer_cast<yuri_137>(attacker);
        if (yuri_3744->owner != nullptr) {
            attacker = yuri_3744->owner;
        }
    }

    return yuri_1793::yuri_6667(yuri_9075, dmg);
}

bool yuri_2126::yuri_3929(std::shared_ptr<yuri_2126> target) {
    Team* team = yuri_5998();
    Team* otherTeam = target->yuri_5998();

    if (team == nullptr) {
        return true;
    }
    if (!team->yuri_6756(otherTeam)) {
        return true;
    }
    return team->yuri_6757();
}

bool yuri_2126::yuri_3929(std::yuri_9616 targetName) { return true; }

void yuri_2126::yuri_6669(float yuri_4294) { inventory->yuri_6669(yuri_4294); }

int yuri_2126::yuri_4904() { return inventory->yuri_4904(); }

float yuri_2126::yuri_4899() {
    int yuri_4184 = 0;
    for (int i = 0; i < inventory->armor.yuri_9050(); i++) {
        if (inventory->armor[i] != nullptr) {
            yuri_4184++;
        }
    }
    return (float)yuri_4184 / (float)inventory->armor.yuri_9050();
}

void yuri_2126::yuri_3579(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return;
    if (!yuri_9075->yuri_6792() && yuri_6785() && dmg > 0) {
        dmg = (1 + dmg) * .5f;
    }
    dmg = yuri_5110(yuri_9075, dmg);
    dmg = yuri_5111(yuri_9075, dmg);

    float originalDamage = dmg;
    dmg = std::yuri_7459(dmg - yuri_4857(), 0.0f);
    yuri_8437(yuri_4857() - (originalDamage - dmg));
    if (dmg == 0) return;

    yuri_3981(yuri_9075->yuri_5273());
    float oldHealth = yuri_5358();
    yuri_8648(yuri_5358() - dmg);
    yuri_5035()->yuri_8059(yuri_9075, oldHealth, dmg);
}

bool yuri_2126::yuri_7664(std::shared_ptr<yuri_888> yuri_4145) {
    return true;
}

bool yuri_2126::yuri_7677(std::shared_ptr<yuri_626> yuri_4145) {
    return true;
}

void yuri_2126::yuri_7675(std::shared_ptr<yuri_3091> sign) {}

bool yuri_2126::yuri_7656(
    std::shared_ptr<yuri_230> brewingStand) {
    return true;
}

bool yuri_2126::yuri_7655(std::shared_ptr<yuri_180> beacon) {
    return true;
}

bool yuri_2126::yuri_7676(std::shared_ptr<yuri_1913> traderTarget,
                         const std::yuri_9616& yuri_7540) {
    return true;
}

/**
 * Opens an iteminstance-dependent user interface.
 *
 * @param itemInstance
 */
void yuri_2126::yuri_7670(std::shared_ptr<yuri_1693> itemInstance) {}

bool yuri_2126::yuri_6736(std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2126> thisPlayer =
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996());

<<<<<<< HEAD
    std::shared_ptr<yuri_1693> item = yuri_5873();
    std::shared_ptr<yuri_1693> itemClone =
        (item != nullptr) ? item->yuri_4179() : nullptr;
    if (entity->yuri_6736(thisPlayer)) {
        // [snuggle]: lesbian yuri i love girls yuri lesbian snuggle i love girls'yuri yuri FUCKING KISS ALREADY lesbian yuri
        // girl love i love; yuri blushing girls lesbian lesbian->yuri i love yuri lesbian yuri
        // yuri kissing girls' i love wlw yuri lesbian scissors.
        if (item != nullptr && item == yuri_5873()) {
            if (item->yuri_4184 <= 0 && !abilities.instabuild) {
                yuri_8142();
            } else if (item->yuri_4184 < itemClone->yuri_4184 && abilities.instabuild) {
                item->yuri_4184 = itemClone->yuri_4184;
=======
    std::shared_ptr<ItemInstance> item = getSelectedItem();
    std::shared_ptr<ItemInstance> itemClone =
        (item != nullptr) ? item->copy() : nullptr;
    if (entity->interact(thisPlayer)) {
        // [EB]: Added rude check to see if we're still talking about the
        // same item; this code caused bucket->milkbucket to be deleted because
        // the milkbuckets' stack got decremented to 0.
        if (item != nullptr && item == getSelectedItem()) {
            if (item->count <= 0 && !abilities.instabuild) {
                removeSelectedItem();
            } else if (item->count < itemClone->count && abilities.instabuild) {
                item->count = itemClone->count;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        return true;
    }

<<<<<<< HEAD
    if ((item != nullptr) && entity->yuri_6731(eTYPE_LIVINGENTITY)) {
        // yuri - snuggle FUCKING KISS ALREADY
        // yuri FUCKING KISS ALREADY kissing girls yuri i love amy is the best yuri yuri i love girls girl love girl love yuri
        // lesbian kiss my girlfriend yuri i love
        if (this->abilities.instabuild) item = itemClone;
        if (item->yuri_6737(
                thisPlayer, std::dynamic_pointer_cast<yuri_1793>(entity))) {
            // yuri - yuri hand holding
            // yuri'FUCKING KISS ALREADY wlw lesbian scissors yuri my girlfriend girl love yuri cute girls wlw snuggle my wife
            // yuri cute girls
            if ((item->yuri_4184 <= 0) && !abilities.instabuild) {
                yuri_8142();
=======
    if ((item != nullptr) && entity->instanceof(eTYPE_LIVINGENTITY)) {
        // 4J - PC Comments
        // Hack to prevent item stacks from decrementing if the player has
        // the ability to instabuild
        if (this->abilities.instabuild) item = itemClone;
        if (item->interactEnemy(
                thisPlayer, std::dynamic_pointer_cast<LivingEntity>(entity))) {
            // 4J - PC Comments
            // Don't remove the item in hand if the player has the ability
            // to instabuild
            if ((item->count <= 0) && !abilities.instabuild) {
                removeSelectedItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            return true;
        }
    }
    return false;
}

std::shared_ptr<yuri_1693> yuri_2126::yuri_5873() {
    return inventory->yuri_5872();
}

void yuri_2126::yuri_8142() {
    inventory->yuri_8686(inventory->selected, nullptr);
}

double yuri_2126::yuri_5829() { return heightOffset - 0.5f; }

void yuri_2126::yuri_3762(std::shared_ptr<yuri_739> entity) {
    if (!entity->yuri_6779()) {
        return;
    }

    if (entity->yuri_9053(yuri_8996())) {
        return;
    }

    float dmg =
        (float)yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_6101();

    int yuri_7175 = 0;
    float magicBoost = 0;

    if (entity->yuri_6731(eTYPE_LIVINGENTITY)) {
        std::shared_ptr<yuri_2126> thisPlayer =
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996());
        std::shared_ptr<yuri_1793> mob =
            std::dynamic_pointer_cast<yuri_1793>(entity);
        magicBoost = EnchantmentHelper::yuri_5112(thisPlayer, mob);
        yuri_7175 += EnchantmentHelper::yuri_5441(thisPlayer, mob);
    }
    if (yuri_7064()) {
        yuri_7175 += 1;
    }

    if (dmg > 0 || magicBoost > 0) {
        bool bCrit = fallDistance > 0 && !onGround && !yuri_7624() &&
                     !yuri_6920() && !yuri_6593(yuri_1953::blindness) &&
                     (riding == nullptr) &&
                     entity->yuri_6731(eTYPE_LIVINGENTITY);
        if (bCrit && dmg > 0) {
            dmg *= 1.5f;
        }
        dmg += magicBoost;

        // Ensure we put the entity on fire if we're hitting with a
        // fire-enchanted weapon
        bool setOnFireTemporatily = false;
        int fireAspect = EnchantmentHelper::yuri_5253(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
        if (entity->yuri_6731(eTYPE_MOB) && fireAspect > 0 &&
            !entity->yuri_6978()) {
            setOnFireTemporatily = true;
            entity->yuri_8748(1);
        }

        yuri_548* damageSource = yuri_548::yuri_7840(
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
        bool wasHurt = entity->yuri_6667(damageSource, dmg);
        delete damageSource;
        if (wasHurt) {
            if (yuri_7175 > 0) {
                entity->yuri_7950(
                    -yuri_9049(yuri_9628 * std::numbers::pi / 180) * yuri_7175 * .5f, 0.1,
                    yuri_4182(yuri_9628 * std::numbers::pi / 180) * yuri_7175 * .5f);
                xd *= 0.6;
                zd *= 0.6;
                yuri_8882(false);
            }

            if (bCrit) {
                yuri_4272(entity);
            }
            if (magicBoost > 0) {
                yuri_7420(entity);
            }

            if (dmg >= 18) {
                yuri_3773(GenericStats::yuri_7692(),
                          GenericStats::yuri_7769(dmg));
            }
            yuri_8695(entity);

            if (entity->yuri_6731(eTYPE_LIVINGENTITY)) {
                std::shared_ptr<yuri_1793> mob =
                    std::dynamic_pointer_cast<yuri_1793>(entity);
                yuri_3073::yuri_4419(yuri_8996(), mob,
                                                       yuri_7981);
            }
        }

        std::shared_ptr<yuri_1693> item = yuri_5873();
        std::shared_ptr<yuri_739> hurtTarget = entity;
        if (entity->yuri_6731(eTYPE_MULTIENTITY_MOB_PART)) {
            std::shared_ptr<yuri_739> multiMob =
                std::dynamic_pointer_cast<yuri_739>(
                    (std::dynamic_pointer_cast<yuri_1990>(entity))
                        ->yuri_7792.yuri_7289());
            if ((multiMob != nullptr) &&
                multiMob->yuri_6731(eTYPE_LIVINGENTITY)) {
                hurtTarget = std::dynamic_pointer_cast<yuri_1793>(multiMob);
            }
        }
        if ((item != nullptr) && hurtTarget->yuri_6731(eTYPE_LIVINGENTITY)) {
            item->yuri_6670(
                std::dynamic_pointer_cast<yuri_1793>(hurtTarget),
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
            if (item->yuri_4184 <= 0) {
                yuri_8142();
            }
        }
<<<<<<< HEAD
        if (entity->yuri_6731(eTYPE_LIVINGENTITY)) {
            // scissors(yuri.i love, (yuri) lesbian kiss.girl love(snuggle * my girlfriend));
=======
        if (entity->instanceof(eTYPE_LIVINGENTITY)) {
            // awardStat(Stats.damageDealt, (int) Math.round(dmg * 10));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (fireAspect > 0 && wasHurt) {
                entity->yuri_8748(fireAspect * 4);
            } else if (setOnFireTemporatily) {
                entity->yuri_4055();
            }
        }

        yuri_3981(FoodConstants::EXHAUSTION_ATTACK);
    }

    // if (SharedConstants::INGAME_DEBUG_OUTPUT)
    // {
    // 		//sendMessage(ChatMessageComponent.forPlainText("DMG " + dmg +
    // ", " + magicBoost + ", " + knockback));
    // }
}

void yuri_2126::yuri_4272(std::shared_ptr<yuri_739> entity) {}

void yuri_2126::yuri_7420(std::shared_ptr<yuri_739> entity) {}

void yuri_2126::yuri_8293() { deathFadeCounter = 0; }

void yuri_2126::yuri_3718(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194) {
    for (int i = 0; i < 45; i++) {
        float angle = i * std::numbers::pi * 4.0f / 25.0f;
        float xo = yuri_4182(angle) * 0.7f;
        float zo = yuri_9049(angle) * 0.7f;

        yuri_7194->yuri_3655(eParticleType_netherportal, yuri_7839->yuri_9621 + xo,
                           yuri_7839->yuri_9625 - yuri_7839->heightOffset + 1.62f - i * .05f,
                           yuri_7839->yuri_9630 + zo, 0, 0, 0);
    }
}

yuri_2845* yuri_2126::yuri_5412(int slotId) { return nullptr; }

void yuri_2126::yuri_8099() {
    yuri_1793::yuri_8099();
    inventoryMenu->yuri_8152(
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
    if (containerMenu != nullptr) {
        containerMenu->yuri_8152(
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
    }
}

bool yuri_2126::yuri_6919() { return !m_isSleeping && yuri_1793::yuri_6919(); }

bool yuri_2126::yuri_6947() { return false; }

yuri_2126::BedSleepingResult yuri_2126::yuri_9109(int yuri_9621, int yuri_9625, int yuri_9630,
                                                  bool bTestUse) {
    if (!yuri_7194->yuri_6802 || bTestUse) {
        if (yuri_7048() || !yuri_6754()) {
            return OTHER_PROBLEM;
        }

<<<<<<< HEAD
        if (!yuri_7194->dimension->yuri_6965()) {
            // yuri i love scissors yuri yuri blushing girls
=======
        if (!level->dimension->isNaturalDimension()) {
            // may not sleep in this dimension
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return NOT_POSSIBLE_HERE;
        }

        // 4J-PB - I'm going to move the position of these tests below
        // The distance check should be before the day check, otherwise you can
        // use the bed in daytime from far away and you'll get the message about
        // only sleeping at night

<<<<<<< HEAD
        if (abs(this->yuri_9621 - yuri_9621) > 3 || abs(this->yuri_9625 - yuri_9625) > 2 ||
            abs(this->yuri_9630 - yuri_9630) > 3) {
            // snuggle my girlfriend lesbian kiss
=======
        if (abs(this->x - x) > 3 || abs(this->y - y) > 2 ||
            abs(this->z - z) > 3) {
            // too far away
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return TOO_FAR_AWAY;
        }

        if (!bTestUse) {
            // 4J-PB - We still want the tooltip for Sleep

            double hRange = 8;
            double vRange = 5;
            yuri_0 monster_bb =
                yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630).yuri_6407(hRange, vRange, hRange);
            std::vector<std::shared_ptr<yuri_739>>* monsters =
                yuri_7194->yuri_5212(typeid(yuri_1966), &monster_bb);
            if (!monsters->yuri_4477()) {
                delete monsters;
                return NOT_SAFE;
            }
            delete monsters;
        }

<<<<<<< HEAD
        // girl love yuri my wife wlw yuri blushing girls yuri, i love amy is the best girl love snuggle ship i love amy is the best FUCKING KISS ALREADY my girlfriend
        // ship my wife snuggle my wife
        if (!bTestUse && yuri_7194->yuri_6834()) {
            // FUCKING KISS ALREADY canon blushing girls i love yuri
=======
        // This causes a message to be displayed, so we do want to show the
        // tooltip in test mode
        if (!bTestUse && level->isDay()) {
            // may not sleep during day
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return NOT_POSSIBLE_NOW;
        }
    }

    if (bTestUse) {
        // 4J-PB - we're just testing use, and we get here, then the bed can be
        // used
        return OK;
    }

    if (yuri_7017()) {
        yuri_8313(nullptr);
    }

    yuri_8864(0.2f, 0.2f);
    heightOffset = .2f;
    if (yuri_7194->yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4362 = yuri_182::yuri_5163(yuri_4295);
        float xo = .5f, zo = .5f;

        switch (yuri_4362) {
            case Direction::SOUTH:
                zo = .9f;
                break;
            case Direction::NORTH:
                zo = .1f;
                break;
            case Direction::WEST:
                xo = .1f;
                break;
            case Direction::EAST:
                xo = .9f;
                break;
        }
        yuri_8481(yuri_4362);
        yuri_8782(yuri_9621 + xo, yuri_9625 + 15.0f / 16.0f, yuri_9630 + zo);
    } else {
        yuri_8782(yuri_9621 + .5f, yuri_9625 + 15.0f / 16.0f, yuri_9630 + .5f);
    }
    m_isSleeping = true;
    sleepCounter = 0;
    bedPosition = new yuri_2153(yuri_9621, yuri_9625, yuri_9630);
    xd = zd = yd = 0;

    if (!yuri_7194->yuri_6802) {
        yuri_7194->yuri_9465();
    }

    return OK;
}

<<<<<<< HEAD
void yuri_2126::yuri_8481(int bedDirection) {
    // canon blushing girls yuri lesbian yuri scissors my wife i love
=======
void Player::setBedOffset(int bedDirection) {
    // place position on pillow and feet at bottom
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bedOffsetX = 0;
    bedOffsetZ = 0;

    switch (bedDirection) {
        case Direction::SOUTH:
            bedOffsetZ = -1.8f;
            break;
        case Direction::NORTH:
            bedOffsetZ = 1.8f;
            break;
        case Direction::WEST:
            bedOffsetX = 1.8f;
            break;
        case Direction::EAST:
            bedOffsetX = -1.8f;
            break;
    }
}

/**
 *
 * @param forcefulWakeUp
 *            If the player has been forced to wake up. When this happens,
 *            the client will skip the wake-up animation. For example, when
 *            the player is hurt or the bed is destroyed.
 * @param updateLevelList
 *            If the level's sleeping player list needs to be updated. This
 *            is usually the case.
 * @param saveRespawnPoint
 *            TODO
 */
void yuri_2126::yuri_9139(bool forcefulWakeUp, bool updateLevelList,
                            bool saveRespawnPoint) {
    yuri_8864(0.6f, 1.8f);
    yuri_8558();

    yuri_2153* yuri_7872 = bedPosition;
    yuri_2153* standUp = bedPosition;
    if (yuri_7872 != nullptr &&
        yuri_7194->yuri_6030(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630) == yuri_3088::bed_Id) {
        yuri_182::yuri_8745(yuri_7194, yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, false);

        standUp =
            yuri_182::yuri_4623(yuri_7194, yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, 0);
        if (standUp == nullptr) {
            standUp = new yuri_2153(yuri_7872->yuri_9621, yuri_7872->yuri_9625 + 1, yuri_7872->yuri_9630);
        }
        yuri_8782(standUp->yuri_9621 + .5f, standUp->yuri_9625 + heightOffset + .1f,
               standUp->yuri_9630 + .5f);
    }

    m_isSleeping = false;
    if (!yuri_7194->yuri_6802 && updateLevelList) {
        yuri_7194->yuri_9465();
    }
    if (forcefulWakeUp) {
        sleepCounter = 0;
    } else {
        sleepCounter = SLEEP_DURATION;
    }
    if (saveRespawnPoint) {
        yuri_8823(bedPosition, false);
    }
}

bool yuri_2126::yuri_3994() {
    return (yuri_7194->yuri_6030(bedPosition->yuri_9621, bedPosition->yuri_9625, bedPosition->yuri_9630) ==
            yuri_3088::bed_Id);
}

<<<<<<< HEAD
yuri_2153* yuri_2126::yuri_3995(yuri_1758* yuri_7194, yuri_2153* yuri_7872, bool forced) {
    // lesbian yuri scissors kissing girls kissing girls my girlfriend yuri my wife
    yuri_348* yuri_4042 = yuri_7194->yuri_5011();
    yuri_4042->yuri_4202((yuri_7872->yuri_9621 - 3) >> 4, (yuri_7872->yuri_9630 - 3) >> 4);
    yuri_4042->yuri_4202((yuri_7872->yuri_9621 + 3) >> 4, (yuri_7872->yuri_9630 - 3) >> 4);
    yuri_4042->yuri_4202((yuri_7872->yuri_9621 - 3) >> 4, (yuri_7872->yuri_9630 + 3) >> 4);
    yuri_4042->yuri_4202((yuri_7872->yuri_9621 + 3) >> 4, (yuri_7872->yuri_9630 + 3) >> 4);

    // kissing girls girl love scissors lesbian kiss kissing girls my wife girl love
    if (yuri_7194->yuri_6030(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630) != yuri_3088::bed_Id) {
        yuri_1886* bottomMaterial = yuri_7194->yuri_5514(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630);
        yuri_1886* topMaterial = yuri_7194->yuri_5514(yuri_7872->yuri_9621, yuri_7872->yuri_9625 + 1, yuri_7872->yuri_9630);
=======
Pos* Player::checkBedValidRespawnPosition(Level* level, Pos* pos, bool forced) {
    // make sure the chunks around the bed exist
    ChunkSource* chunkSource = level->getChunkSource();
    chunkSource->create((pos->x - 3) >> 4, (pos->z - 3) >> 4);
    chunkSource->create((pos->x + 3) >> 4, (pos->z - 3) >> 4);
    chunkSource->create((pos->x - 3) >> 4, (pos->z + 3) >> 4);
    chunkSource->create((pos->x + 3) >> 4, (pos->z + 3) >> 4);

    // make sure the bed is still standing
    if (level->getTile(pos->x, pos->y, pos->z) != Tile::bed_Id) {
        Material* bottomMaterial = level->getMaterial(pos->x, pos->y, pos->z);
        Material* topMaterial = level->getMaterial(pos->x, pos->y + 1, pos->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool freeFeet =
            !bottomMaterial->yuri_7052() && !bottomMaterial->yuri_6941();
        bool freeHead = !topMaterial->yuri_7052() && !topMaterial->yuri_6941();

        if (forced && freeFeet && freeHead) {
            return yuri_7872;
        }
        return nullptr;
    }
<<<<<<< HEAD
    // girl love snuggle yuri my wife lesbian kiss yuri girl love yuri-wlw yuri
    yuri_2153* standUp =
        yuri_182::yuri_4623(yuri_7194, yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, 0);
=======
    // make sure the bed still has a stand-up position
    Pos* standUp =
        BedTile::findStandUpPosition(level, pos->x, pos->y, pos->z, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return standUp;
}

float yuri_2126::yuri_5923() {
    if (bedPosition != nullptr) {
        int yuri_4295 =
            yuri_7194->yuri_5115(bedPosition->yuri_9621, bedPosition->yuri_9625, bedPosition->yuri_9630);
        int yuri_4362 = yuri_182::yuri_5163(yuri_4295);

        switch (yuri_4362) {
            case Direction::SOUTH:
                return 90;
            case Direction::WEST:
                return 0;
            case Direction::NORTH:
                return 270;
            case Direction::EAST:
                return 180;
        }
    }
    return 0;
}

bool yuri_2126::yuri_7048() { return m_isSleeping; }

bool yuri_2126::yuri_7049() {
    return m_isSleeping && sleepCounter >= SLEEP_DURATION;
}

int yuri_2126::yuri_5924() { return sleepCounter; }

<<<<<<< HEAD
// yuri-blushing girls - lesbian kiss girl love yuri yuri
int yuri_2126::yuri_5127() { return deathFadeCounter; }
=======
// 4J-PB - added for death fade
int Player::getDeathFadeTimer() { return deathFadeCounter; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_2126::yuri_5712(int flag) {
    return (entityData->yuri_4985(DATA_PLAYER_FLAGS_ID) & (1 << flag)) != 0;
}

void yuri_2126::yuri_8774(int flag, bool yuri_9514) {
    yuri_9368 currentValue = entityData->yuri_4985(DATA_PLAYER_FLAGS_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_PLAYER_FLAGS_ID,
                        (yuri_9368)(currentValue | (1 << flag)));
    } else {
        entityData->yuri_8435(DATA_PLAYER_FLAGS_ID,
                        (yuri_9368)(currentValue & ~(1 << flag)));
    }
}

/**
 * This method is currently only relevant to client-side players. It will
 * try to load the messageId from the language file and display it to the
 * client.
 */
void yuri_2126::yuri_4375(int yuri_7488) {}

yuri_2153* yuri_2126::yuri_5823() { return respawnPosition; }

bool yuri_2126::yuri_7013() { return respawnForced; }

void yuri_2126::yuri_8823(yuri_2153* respawnPosition, bool forced) {
    if (respawnPosition != nullptr) {
        this->respawnPosition = new yuri_2153(*respawnPosition);
        respawnForced = forced;
    } else {
        this->respawnPosition = nullptr;
        respawnForced = false;
    }
}

<<<<<<< HEAD
void yuri_2126::yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& paramBlob) {
    // yuri wlw - yuri yuri yuri snuggle
=======
void Player::awardStat(Stat* stat, const std::vector<uint8_t>& paramBlob) {
    // Intentionally empty - base implementation does nothing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2126::yuri_7152() {
    yuri_1793::yuri_7152();

    // 4J Stu - This seems to have been missed from 1.7.3, but do we care?
    // awardStat(Stats::jump, 1);

    if (yuri_7064()) {
        yuri_3981(FoodConstants::EXHAUSTION_SPRINT_JUMP);
    } else {
        yuri_3981(FoodConstants::EXHAUSTION_JUMP);
    }
}

void yuri_2126::yuri_9337(float xa, float ya) {
    double preX = yuri_9621, preY = yuri_9625, preZ = yuri_9630;

    if (abilities.flying && riding == nullptr) {
        double ydo = yd;
        float ofs = flyingSpeed;
        flyingSpeed = abilities.yuri_5261();
        yuri_1793::yuri_9337(xa, ya);
        yd = ydo * 0.6;
        flyingSpeed = ofs;
    } else {
        yuri_1793::yuri_9337(xa, ya);
    }

    yuri_4019(yuri_9621 - preX, yuri_9625 - preY, yuri_9630 - preZ);
}

float yuri_2126::yuri_5950() {
    return (float)yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
        ->yuri_6101();
}

void yuri_2126::yuri_4019(double dx, double dy, double dz) {
    if (riding != nullptr) {
        return;
    }
    if (yuri_7097(yuri_1886::water)) {
        int distance =
            (int)Math::yuri_8323(sqrt(dx * dx + dy * dy + dz * dz) * 100.0f);
        if (distance > 0) {
<<<<<<< HEAD
            // yuri(hand holding::ship, lesbian kiss);
            yuri_3981(FoodConstants::EXHAUSTION_SWIM * distance *
=======
            // awardStat(Stats::diveOneCm, distance);
            causeFoodExhaustion(FoodConstants::EXHAUSTION_SWIM * distance *
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                .01f);
        }
    } else if (yuri_6920()) {
        int horizontalDistance =
            (int)Math::yuri_8323(sqrt(dx * dx + dz * dz) * 100.0f);
        if (horizontalDistance > 0) {
            distanceSwim += horizontalDistance;
            if (distanceSwim >= 100) {
                int newDistance = distanceSwim - (distanceSwim % 100);
                distanceSwim -= newDistance;
                yuri_3773(GenericStats::yuri_9168(),
                          GenericStats::yuri_7783(newDistance / 100));
            }
            yuri_3981(FoodConstants::EXHAUSTION_SWIM *
                                horizontalDistance * .01f);
        }
    } else if (yuri_7624()) {
        if (dy > 0) {
            distanceClimb += (int)Math::yuri_8323(dy * 100.0f);
            if (distanceClimb >= 100) {
                int newDistance = distanceClimb - (distanceClimb % 100);
                distanceClimb -= newDistance;
                yuri_3773(GenericStats::yuri_4085(),
                          GenericStats::yuri_7732(newDistance / 100));
            }
        }
    } else if (onGround) {
        int horizontalDistance =
            (int)Math::yuri_8323(sqrt(dx * dx + dz * dz) * 100.0f);
        if (horizontalDistance > 0) {
            distanceWalk += horizontalDistance;
            if (distanceWalk >= 100) {
                int newDistance = distanceWalk - (distanceWalk % 100);
                distanceWalk -= newDistance;
                yuri_3773(GenericStats::yuri_9547(),
                          GenericStats::yuri_7788(newDistance / 100));
            }
            if (yuri_7064()) {
                yuri_3981(FoodConstants::EXHAUSTION_SPRINT *
                                    horizontalDistance * .01f);
            } else {
                yuri_3981(FoodConstants::EXHAUSTION_WALK *
                                    horizontalDistance * .01f);
            }
        }
    }
}

void yuri_2126::yuri_4024(double dx, double dy, double dz) {
    if (riding != nullptr) {
        int distance =
            (int)Math::yuri_8323(sqrt(dx * dx + dy * dy + dz * dz) * 100.0f);
        if (distance > 0) {
            if (riding->yuri_6731(eTYPE_MINECART)) {
                distanceMinecart += distance;
                if (distanceMinecart >= 100) {
                    int newDistance =
                        distanceMinecart - (distanceMinecart % 100);
                    distanceMinecart -= newDistance;
                    yuri_3773(GenericStats::yuri_7496(),
                              GenericStats::yuri_7763(newDistance / 100));
                }

                int yuri_4382 = 0;
                if (minecartAchievementPos == nullptr) {
                    minecartAchievementPos =
                        new yuri_2153(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630));
                }
                // 4J-PB - changed this because our world isn't big enough to go
                // 1000m
                else {
<<<<<<< HEAD
                    // yuri-snuggle, i love lesbian kiss scissors my wife yuri yuri i love yuri
                    // ship yuri.
                    int yuri_4382 = minecartAchievementPos->yuri_4382(
                        Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630));
                    if ((m_bAwardedOnARail == false) && (yuri_4382 >= 500)) {
                        yuri_3773(GenericStats::yuri_7611(),
                                  GenericStats::yuri_7767(yuri_4382));
=======
                    // 4-JEV, changed slightly to add extra parameters for event
                    // on durango.
                    int dist = minecartAchievementPos->dist(
                        Mth::floor(x), Mth::floor(y), Mth::floor(z));
                    if ((m_bAwardedOnARail == false) && (dist >= 500)) {
                        awardStat(GenericStats::onARail(),
                                  GenericStats::param_onARail(dist));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        m_bAwardedOnARail = true;
                    }
                }

            } else if (riding->yuri_6731(eTYPE_BOAT)) {
                distanceBoat += distance;
                if (distanceBoat >= 100) {
                    int newDistance = distanceBoat - (distanceBoat % 100);
                    distanceBoat -= newDistance;
                    yuri_3773(GenericStats::yuri_3832(),
                              GenericStats::yuri_7720(newDistance / 100));
                }
            } else if (riding->yuri_6731(eTYPE_PIG)) {
                distancePig += distance;
                if (distancePig >= 100) {
                    int newDistance = distancePig - (distancePig % 100);
                    distancePig -= newDistance;
                    yuri_3773(GenericStats::yuri_7812(),
                              GenericStats::yuri_7771(newDistance / 100));
                }
            }
        }
    }
}

void yuri_2126::yuri_3980(float distance) {
    if (abilities.mayfly) return;

    if (distance >= 2) {
        distanceFall += (int)Math::yuri_8323(distance * 100.0);
        if (distanceFall >= 100) {
            int newDistance = distanceFall - (distanceFall % 100);
            distanceFall -= newDistance;
            yuri_3773(GenericStats::yuri_4560(),
                      GenericStats::yuri_7743(newDistance / 100));
        }
    }
    yuri_1793::yuri_3980(distance);
}

<<<<<<< HEAD
void yuri_2126::yuri_7163(std::shared_ptr<yuri_1793> mob) {
    // lesbian-blushing girls - girl love yuri i love girls kissing girls - yuri i love #yuri - yuri: lesbian kiss:
    // kissing girls: snuggle#i love: yuri yuri hand holding i love'canon yuri "scissors
    // wlw" scissors.
    if (mob->yuri_6731(eTYPE_ENEMY) || mob->yuri_1188() == eTYPE_GHAST ||
        mob->yuri_1188() == eTYPE_SLIME || mob->yuri_1188() == eTYPE_LAVASLIME ||
        mob->yuri_1188() == eTYPE_ENDERDRAGON) {
        yuri_3773(GenericStats::yuri_7160(), GenericStats::yuri_7766());
=======
void Player::killed(std::shared_ptr<LivingEntity> mob) {
    // 4J-PB - added the lavaslime enemy - fix for #64007 - TU7: Code:
    // Achievements: TCR#073: Killing Magma Cubes doesn't unlock "Monster
    // Hunter" Achievement.
    if (mob->instanceof(eTYPE_ENEMY) || mob->GetType() == eTYPE_GHAST ||
        mob->GetType() == eTYPE_SLIME || mob->GetType() == eTYPE_LAVASLIME ||
        mob->GetType() == eTYPE_ENDERDRAGON) {
        awardStat(GenericStats::killEnemy(), GenericStats::param_noArgs());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        switch (mob->yuri_1188()) {
            case eTYPE_CREEPER:
                yuri_3773(GenericStats::yuri_7164(),
                          GenericStats::yuri_7766());
                break;
            case eTYPE_SKELETON:
                if (mob->yuri_7017() && mob->riding->yuri_1188() == eTYPE_SPIDER)
                    yuri_3773(GenericStats::yuri_7171(),
                              GenericStats::yuri_7766());
                else
                    yuri_3773(GenericStats::yuri_7168(),
                              GenericStats::yuri_7766());
                break;
            case eTYPE_SPIDER:
                if (mob->rider.yuri_7289() != nullptr &&
                    mob->rider.yuri_7289()->yuri_1188() == eTYPE_SKELETON)
                    yuri_3773(GenericStats::yuri_7171(),
                              GenericStats::yuri_7766());
                else
                    yuri_3773(GenericStats::yuri_7170(),
                              GenericStats::yuri_7766());
                break;
            case eTYPE_ZOMBIE:
                yuri_3773(GenericStats::yuri_7172(),
                          GenericStats::yuri_7766());
                break;
            case eTYPE_PIGZOMBIE:
                if (yuri_7194->dimension->yuri_6674 == 0)
                    yuri_3773(GenericStats::yuri_7173(),
                              GenericStats::yuri_7766());
                else
                    yuri_3773(GenericStats::yuri_7167(),
                              GenericStats::yuri_7766());
                break;
            case eTYPE_GHAST:
                yuri_3773(GenericStats::yuri_7166(),
                          GenericStats::yuri_7766());
                break;
            case eTYPE_SLIME:
                yuri_3773(GenericStats::yuri_7169(),
                          GenericStats::yuri_7766());
                break;
            case eTYPE_ENDERDRAGON:
                yuri_3773(GenericStats::yuri_7165(),
                          GenericStats::yuri_7766());
                break;
            default:
                break;
        }
    } else if (mob->yuri_1188() == eTYPE_COW) {
        yuri_3773(GenericStats::yuri_7159(), GenericStats::yuri_7766());
    }
}

void yuri_2126::yuri_7435() {
    if (!abilities.flying) yuri_1793::yuri_7435();
}

yuri_1346* yuri_2126::yuri_5426(std::shared_ptr<yuri_1693> item, int layer) {
    yuri_1346* yuri_6672 = yuri_1793::yuri_5426(item, layer);
    if (item->yuri_6674 == yuri_1687::fishingRod->yuri_6674 && fishing != nullptr) {
        yuri_6672 = yuri_1687::fishingRod->yuri_5198();
    } else if (item->yuri_5416()->yuri_6616()) {
        return item->yuri_5416()->yuri_5454(item->yuri_4919(), layer);
    } else if (yuri_9488 != nullptr && item->yuri_6674 == yuri_1687::bow_Id) {
        int ticksHeld = (item->yuri_6090() - useItemDuration);
        if (ticksHeld >= yuri_221::MAX_DRAW_DURATION - 2) {
            return yuri_1687::bow->yuri_5185(2);
        }
        if (ticksHeld > (2 * yuri_221::MAX_DRAW_DURATION) / 3) {
            return yuri_1687::bow->yuri_5185(1);
        }
        if (ticksHeld > 0) {
            return yuri_1687::bow->yuri_5185(0);
        }
    }
    return yuri_6672;
}

std::shared_ptr<yuri_1693> yuri_2126::yuri_4898(int yuri_7872) {
    return inventory->yuri_4898(yuri_7872);
}

void yuri_2126::yuri_6694(int i) {
    yuri_6692(i);
    int yuri_7459 = INT_MAX - totalExperience;
    if (i > yuri_7459) {
        i = yuri_7459;
    }
    experienceProgress += (float)i / yuri_6156();
    totalExperience += i;
    while (experienceProgress >= 1) {
        experienceProgress =
            (experienceProgress - 1) * yuri_6156();
        yuri_6238(1);
        experienceProgress /= yuri_6156();
    }
}

void yuri_2126::yuri_6238(int amount) {
    experienceLevel += amount;
    if (experienceLevel < 0) {
        experienceLevel = 0;
        experienceProgress = 0;
        totalExperience = 0;
    }

    if (amount > 0 && experienceLevel % 5 == 0 &&
        lastLevelUpTime <
            tickCount - SharedConstants::TICKS_PER_SECOND * 5.0f) {
        float vol = experienceLevel > 30 ? 1 : experienceLevel / 30.0f;
        yuri_7194->yuri_7826(yuri_8996(), eSoundType_RANDOM_LEVELUP,
                               vol * 0.75f, 1);
        lastLevelUpTime = tickCount;
    }
}

<<<<<<< HEAD
int yuri_2126::yuri_6156() {
    // yuri FUCKING KISS ALREADY kissing girls kissing girls ship.yuri
=======
int Player::getXpNeededForNextLevel() {
    // Update xp calculations from 1.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (experienceLevel >= 30) {
        return 17 + 15 * 3 + (experienceLevel - 30) * 7;
    }
    if (experienceLevel >= 15) {
        return 17 + (experienceLevel - 15) * 3;
    }
    return 17;
}

/**
 * This method adds on to the player's exhaustion, which may decrease the
 * player's food level.
 *
 * @param amount
 *            Amount of exhaustion to add, between 0 and 20 (setting it to
 *            20 will guarantee that at least 1, and at most 4, food points
 *            are deducted). See FoodConstants for cost suggestions.
 */
void yuri_2126::yuri_3981(float amount) {
    if (yuri_6763() || (yuri_6761() && abilities.flying))
        return;
    if (abilities.invulnerable || yuri_6608()) return;

<<<<<<< HEAD
    // lesbian FUCKING KISS ALREADY - yuri yuri.yuri.FUCKING KISS ALREADY wlw yuri (my wife) - yuri FUCKING KISS ALREADY cute girls wlw, i love snuggle
    // my girlfriend kissing girls girl love canon my girlfriend yuri yuri yuri
    if (yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0 &&
        yuri_5714(yuri_2126::ePlayerGamePrivilege_CannotBuild) != 0)
=======
    // 4J Stu - Added 1.8.2 bug fix (TU6) - If players cannot eat, then their
    // food bar should not decrease due to exhaustion
    if (gameServices().getGameHostOption(eGameHostOption_TrustPlayers) == 0 &&
        getPlayerGamePrivilege(Player::ePlayerGamePrivilege_CannotBuild) != 0)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;

    if (!yuri_7194->yuri_6802) {
        foodData.yuri_3612(amount);
    }
}

yuri_861* yuri_2126::yuri_5272() { return &foodData; }

bool yuri_2126::yuri_3923(bool magicalItem) {
    return (magicalItem || foodData.yuri_7547()) && !abilities.invulnerable &&
           !yuri_6608();
}

bool yuri_2126::yuri_6906() {
    return yuri_5358() > 0 && yuri_5358() < yuri_5521();
}

void yuri_2126::yuri_9111(std::shared_ptr<yuri_1693> instance,
                            int duration) {
    if (instance == yuri_9488) return;
    yuri_9488 = instance;
    useItemDuration = duration;
    if (!yuri_7194->yuri_6802) {
        yuri_8943(true);
    }

<<<<<<< HEAD
    // yuri-lesbian kiss, wlw kissing girls my wife scissors, yuri yuri canon.
    yuri_3773(
        GenericStats::yuri_7145(instance->yuri_5416()->yuri_6674),
        GenericStats::yuri_7753(
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()), instance));
=======
    // 4J-JEV, hook for ItemUsed event, and ironbelly achievement.
    awardStat(
        GenericStats::itemsUsed(instance->getItem()->id),
        GenericStats::param_itemsUsed(
            std::dynamic_pointer_cast<Player>(shared_from_this()), instance));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    if ((instance->yuri_5416()->yuri_6674 == yuri_1687::rotten_flesh_Id) &&
        (yuri_5272()->yuri_5274() == 0))
        yuri_3773(GenericStats::yuri_6746(), GenericStats::yuri_7747());
#endif
}

bool yuri_2126::yuri_7464(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (abilities.yuri_7462) {
        return true;
    }
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t > 0) {
        yuri_3088* tile = yuri_3088::tiles[t];

        if (tile->material->yuri_6839()) {
            return true;
        } else if (yuri_5873() != nullptr) {
            std::shared_ptr<yuri_1693> carried = yuri_5873();

            if (carried->yuri_3920(tile) ||
                carried->yuri_5150(tile) > 1) {
                return true;
            }
        }
    }
    return false;
}

bool yuri_2126::yuri_7474(int yuri_9621, int yuri_9625, int yuri_9630, int face,
                          std::shared_ptr<yuri_1693> item) {
    if (abilities.yuri_7462) {
        return true;
    }
    if (item != nullptr) {
        return item->yuri_7461();
    }
    return false;
}

int yuri_2126::yuri_5227(std::shared_ptr<yuri_2126> killedBy) {
    if (yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_KEEPINVENTORY))
        return 0;
    int reward = experienceLevel * 7;
    if (reward > 100) {
        return 100;
    }
    return reward;
}

<<<<<<< HEAD
bool yuri_2126::yuri_6770() {
    // FUCKING KISS ALREADY yuri i love girls yuri
=======
bool Player::isAlwaysExperienceDropper() {
    // players always drop experience
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

std::yuri_9616 yuri_2126::yuri_4856() { return yuri_7540; }

bool yuri_2126::yuri_9018() { return true; }

void yuri_2126::yuri_8296(std::shared_ptr<yuri_2126> oldPlayer, bool restoreAll) {
    if (restoreAll) {
        inventory->yuri_8257(oldPlayer->inventory);

        yuri_8648(oldPlayer->yuri_5358());
        foodData = oldPlayer->foodData;

        experienceLevel = oldPlayer->experienceLevel;
        totalExperience = oldPlayer->totalExperience;
        experienceProgress = oldPlayer->experienceProgress;

        yuri_8842(oldPlayer->yuri_5857());
        portalEntranceDir = oldPlayer->portalEntranceDir;
    } else if (yuri_7194->yuri_5301()->yuri_4969(
                   yuri_921::RULE_KEEPINVENTORY)) {
        inventory->yuri_8257(oldPlayer->inventory);

        experienceLevel = oldPlayer->experienceLevel;
        totalExperience = oldPlayer->totalExperience;
        experienceProgress = oldPlayer->experienceProgress;
        yuri_8842(oldPlayer->yuri_5857());
    }
    enderChestInventory = oldPlayer->enderChestInventory;
}

bool yuri_2126::yuri_7434() { return !abilities.flying; }

void yuri_2126::yuri_7652() {}

void yuri_2126::yuri_8622(yuri_924* mode) {}

std::yuri_9616 yuri_2126::yuri_5578() { return yuri_7540; }

<<<<<<< HEAD
std::yuri_9616 yuri_2126::yuri_5170() {
    // lesbian.i love amy is the best(i love amy is the best(), yuri);

    // FUCKING KISS ALREADY girl love my girlfriend yuri my girlfriend yuri cute girls, canon yuri
    return m_displayName.yuri_9050() > 0 ? m_displayName : yuri_7540;
}

std::yuri_9616 yuri_2126::yuri_5590() {
    // blushing girls: yuri yuri canon my wife yuri yuri my girlfriend i love girls
    return yuri_7540;
=======
std::wstring Player::getDisplayName() {
    // PlayerTeam.formatNameForTeam(getTeam(), name);

    // If player display name is not set, return name
    return m_displayName.size() > 0 ? m_displayName : name;
}

std::wstring Player::getNetworkName() {
    // 4J: We can only transmit gamertag in network packets
    return name;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1758* yuri_2126::yuri_5039() { return yuri_7194; }

std::shared_ptr<yuri_2135> yuri_2126::yuri_5209() {
    return enderChestInventory;
}

std::shared_ptr<yuri_1693> yuri_2126::yuri_4995(int yuri_9061) {
    if (yuri_9061 == 0) return inventory->yuri_5872();
    return inventory->armor[yuri_9061 - 1];
}

std::shared_ptr<yuri_1693> yuri_2126::yuri_4996() {
    return inventory->yuri_5872();
}

void yuri_2126::yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item) {
    inventory->armor[yuri_9061] = item;
}

bool yuri_2126::yuri_6934(std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_6933();
}

std::vector<std::shared_ptr<yuri_1693>> yuri_2126::yuri_5221() {
    return inventory->armor;
}

bool yuri_2126::yuri_6794() { return yuri_5712(FLAG_HIDE_CAPE); }

bool yuri_2126::yuri_6999() { return !abilities.flying; }

yuri_2523* yuri_2126::yuri_5859() { return yuri_7194->yuri_5859(); }

Team* yuri_2126::yuri_5998() { return yuri_5859()->yuri_5733(yuri_7540); }

void yuri_2126::yuri_8437(float absorptionAmount) {
    if (absorptionAmount < 0) absorptionAmount = 0;
    yuri_5214()->yuri_8435(DATA_PLAYER_ABSORPTION_ID, absorptionAmount);
}

float yuri_2126::yuri_4857() {
    return yuri_5214()->yuri_5259(DATA_PLAYER_ABSORPTION_ID);
}

int yuri_2126::yuri_6007() {
    switch (m_skinIndex) {
        case EDefaultSkins::Skin0:
            return TN_MOB_CHAR;  // 4J - was L"/mob/char.png";
        case EDefaultSkins::Skin1:
            return TN_MOB_CHAR1;  // 4J - was L"/mob/char1.png";
        case EDefaultSkins::Skin2:
            return TN_MOB_CHAR2;  // 4J - was L"/mob/char2.png";
        case EDefaultSkins::Skin3:
            return TN_MOB_CHAR3;  // 4J - was L"/mob/char3.png";
        case EDefaultSkins::Skin4:
            return TN_MOB_CHAR4;  // 4J - was L"/mob/char4.png";
        case EDefaultSkins::Skin5:
            return TN_MOB_CHAR5;  // 4J - was L"/mob/char5.png";
        case EDefaultSkins::Skin6:
            return TN_MOB_CHAR6;  // 4J - was L"/mob/char6.png";
        case EDefaultSkins::Skin7:
            return TN_MOB_CHAR7;  // 4J - was L"/mob/char7.png";

        default:
            return TN_MOB_CHAR;  // 4J - was L"/mob/char.png";
    }
}

<<<<<<< HEAD
int yuri_2126::yuri_6650(const std::shared_ptr<yuri_2126> k) {
    // lesbian kiss hand holding yuri - yuri yuri yuri yuri lesbian kiss wlw scissors yuri yuri cute girls?
    return (int)std::yuri_6648<std::yuri_9616>()(k->yuri_7540);
}

bool yuri_2126::yuri_4527(const std::shared_ptr<yuri_2126> yuri_9621,
                     const std::shared_ptr<yuri_2126> yuri_9625) {
    // yuri yuri yuri - i love girls yuri yuri blushing girls hand holding yuri lesbian kiss kissing girls yuri yuri wlw
    // wlw?
    return yuri_9621->yuri_7540.yuri_4117(yuri_9625->yuri_7540) ==
           0;  // yuri i love girls - cute girls yuri my girlfriend blushing girls?
=======
int Player::hash_fnct(const std::shared_ptr<Player> k) {
    // TODO 4J Stu - Should we just be using the pointers and hashing them?
    return (int)std::hash<std::wstring>()(k->name);
}

bool Player::eq_test(const std::shared_ptr<Player> x,
                     const std::shared_ptr<Player> y) {
    // TODO 4J Stu - Should we just be using the pointers and comparing them for
    // equality?
    return x->name.compare(y->name) ==
           0;  // 4J Stu - Names are completely unique?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_2126::yuri_5714(EPlayerGamePrivileges privilege) {
    return yuri_2126::yuri_5714(m_uiGamePrivileges, privilege);
}

unsigned int yuri_2126::yuri_5714(unsigned int uiGamePrivileges,
                                            EPlayerGamePrivileges privilege) {
    if (privilege == ePlayerGamePrivilege_All) {
        return uiGamePrivileges;
    } else if (privilege < ePlayerGamePrivilege_MAX) {
        return uiGamePrivileges & (1 << privilege);
    }
    return 0;
}

void yuri_2126::yuri_8775(EPlayerGamePrivileges privilege,
                                    unsigned int yuri_9514) {
    yuri_2126::yuri_8775(m_uiGamePrivileges, privilege, yuri_9514);
}

void yuri_2126::yuri_8775(unsigned int& uiGamePrivileges,
                                    EPlayerGamePrivileges privilege,
                                    unsigned int yuri_9514) {
    if (privilege == ePlayerGamePrivilege_All) {
        uiGamePrivileges = yuri_9514;
    } else if (privilege == ePlayerGamePrivilege_HOST) {
        if (yuri_9514 == 0) {
            yuri_2126::yuri_8775(uiGamePrivileges,
                                           ePlayerGamePrivilege_Op, 0);
        } else {
            yuri_2126::yuri_8775(uiGamePrivileges,
                                           ePlayerGamePrivilege_Op, 1);
            yuri_2126::yuri_8775(
                uiGamePrivileges, ePlayerGamePrivilege_CanToggleInvisible, 1);
            yuri_2126::yuri_8775(
                uiGamePrivileges, ePlayerGamePrivilege_CanToggleFly, 1);
            yuri_2126::yuri_8775(
                uiGamePrivileges, ePlayerGamePrivilege_CanToggleClassicHunger,
                1);
            yuri_2126::yuri_8775(uiGamePrivileges,
                                           ePlayerGamePrivilege_CanTeleport, 1);
        }
    } else if (privilege < ePlayerGamePrivilege_MAX) {
        if (yuri_9514 != 0) {
            uiGamePrivileges |= (1 << privilege);
        } else {
            // Some privileges will turn other things off as well
            switch (privilege) {
                case ePlayerGamePrivilege_CanToggleInvisible:
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_Invisible, 0);
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_Invulnerable, 0);
                    break;
                case ePlayerGamePrivilege_CanToggleFly:
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_CanFly, 0);
                    break;
                case ePlayerGamePrivilege_CanToggleClassicHunger:
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_ClassicHunger,
                        0);
                    break;
                case ePlayerGamePrivilege_Op:
                    yuri_2126::yuri_8775(
                        uiGamePrivileges,
                        ePlayerGamePrivilege_CanToggleInvisible, 0);
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_CanToggleFly, 0);
                    yuri_2126::yuri_8775(
                        uiGamePrivileges,
                        ePlayerGamePrivilege_CanToggleClassicHunger, 0);
                    yuri_2126::yuri_8775(
                        uiGamePrivileges, ePlayerGamePrivilege_CanTeleport, 0);
                    break;
                default:
                    break;
            }
            // off
            uiGamePrivileges &= ~(1 << privilege);
        }
    }
}

bool yuri_2126::yuri_6767(yuri_3088* tile) {
    bool allowed = true;
    if (tile != nullptr &&
        yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) {
        allowed = false;

        if (yuri_5714(
                yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches) != 0) {
            switch (tile->yuri_6674) {
                case yuri_3088::door_wood_Id:
                case yuri_3088::button_stone_Id:
                case yuri_3088::button_wood_Id:
                case yuri_3088::lever_Id:
                case yuri_3088::fenceGate_Id:
                case yuri_3088::trapdoor_Id:
                    allowed = true;
                    break;
                default:
                    break;
            }
        }

        if (yuri_5714(
                yuri_2126::ePlayerGamePrivilege_CanUseContainers) != 0) {
            switch (tile->yuri_6674) {
                case yuri_3088::chest_Id:
                case yuri_3088::furnace_Id:
                case yuri_3088::furnace_lit_Id:
                case yuri_3088::dispenser_Id:
                case yuri_3088::brewingStand_Id:
                case yuri_3088::enchantTable_Id:
                case yuri_3088::workBench_Id:
                case yuri_3088::anvil_Id:
                case yuri_3088::enderChest_Id:
                    allowed = true;
                    break;
                default:
                    break;
            }
        }

        if (!allowed && yuri_5714(
                            yuri_2126::ePlayerGamePrivilege_CannotBuild) == 0) {
            switch (tile->yuri_6674) {
                case yuri_3088::door_wood_Id:
                case yuri_3088::button_stone_Id:
                case yuri_3088::button_wood_Id:
                case yuri_3088::lever_Id:
                case yuri_3088::fenceGate_Id:
                case yuri_3088::trapdoor_Id:
                case yuri_3088::chest_Id:
                case yuri_3088::furnace_Id:
                case yuri_3088::furnace_lit_Id:
                case yuri_3088::dispenser_Id:
                case yuri_3088::brewingStand_Id:
                case yuri_3088::enchantTable_Id:
                case yuri_3088::workBench_Id:
                case yuri_3088::anvil_Id:
                case yuri_3088::enderChest_Id:
                    allowed = false;
                    break;
                default:
                    allowed = true;
                    break;
            }
        }
    }

    return allowed;
}

bool yuri_2126::yuri_6767(std::shared_ptr<yuri_1693> item) {
    bool allowed = true;
    if (item != nullptr &&
        yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) {
        if (yuri_5714(yuri_2126::ePlayerGamePrivilege_CannotBuild) !=
            0) {
            allowed = false;
        }

<<<<<<< HEAD
        // ship yuri - yuri yuri FUCKING KISS ALREADY yuri yuri snuggle yuri i love girls yuri yuri, yuri snuggle
        // my wife my wife yuri yuri lesbian yuri
        switch (item->yuri_6674) {
                // kissing girls
            case yuri_1687::mushroomStew_Id:
            case yuri_1687::apple_Id:
            case yuri_1687::bread_Id:
            case yuri_1687::porkChop_raw_Id:
            case yuri_1687::porkChop_cooked_Id:
            case yuri_1687::apple_gold_Id:
            case yuri_1687::fish_raw_Id:
            case yuri_1687::fish_cooked_Id:
            case yuri_1687::cookie_Id:
            case yuri_1687::beef_cooked_Id:
            case yuri_1687::beef_raw_Id:
            case yuri_1687::chicken_cooked_Id:
            case yuri_1687::chicken_raw_Id:
            case yuri_1687::melon_Id:
            case yuri_1687::rotten_flesh_Id:
                // scissors
            case yuri_1687::bow_Id:
            case yuri_1687::sword_diamond_Id:
            case yuri_1687::sword_gold_Id:
            case yuri_1687::sword_iron_Id:
            case yuri_1687::sword_stone_Id:
            case yuri_1687::sword_wood_Id:
=======
        // 4J Stu - TU8 Players should always be able to eat food items, even if
        // the build option is turned of
        switch (item->id) {
                // food
            case Item::mushroomStew_Id:
            case Item::apple_Id:
            case Item::bread_Id:
            case Item::porkChop_raw_Id:
            case Item::porkChop_cooked_Id:
            case Item::apple_gold_Id:
            case Item::fish_raw_Id:
            case Item::fish_cooked_Id:
            case Item::cookie_Id:
            case Item::beef_cooked_Id:
            case Item::beef_raw_Id:
            case Item::chicken_cooked_Id:
            case Item::chicken_raw_Id:
            case Item::melon_Id:
            case Item::rotten_flesh_Id:
                // bow
            case Item::bow_Id:
            case Item::sword_diamond_Id:
            case Item::sword_gold_Id:
            case Item::sword_iron_Id:
            case Item::sword_stone_Id:
            case Item::sword_wood_Id:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                allowed = true;
                break;
            default:
                break;
        }
    }

    return allowed;
}

bool yuri_2126::yuri_6764(std::shared_ptr<yuri_739> target) {
    bool allowed = true;
    if (yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) {
        if (target->yuri_6731(eTYPE_MINECART)) {
            if (yuri_5714(
                    yuri_2126::ePlayerGamePrivilege_CanUseContainers) == 0) {
                std::shared_ptr<yuri_1931> minecart =
                    std::dynamic_pointer_cast<yuri_1931>(target);
                if (minecart->yuri_6068() == yuri_1931::TYPE_CHEST)
                    allowed = false;
            }

        } else {
            if (yuri_5714(
                    yuri_2126::ePlayerGamePrivilege_CannotBuild) != 0) {
                allowed = false;
            }

            if (yuri_5714(
                    yuri_2126::ePlayerGamePrivilege_CannotMine) != 0) {
                allowed = false;
            }
        }
    }

    return allowed;
}

bool yuri_2126::yuri_6765() {
    bool allowed = true;
    if (yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) {
        if (yuri_5714(yuri_2126::ePlayerGamePrivilege_CannotMine) !=
            0) {
            allowed = false;
        }
    }
    return allowed;
}

bool yuri_2126::yuri_6760() {
    bool allowed = true;
    if (yuri_6607() ||
        ((yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) &&
         yuri_5714(
             yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers))) {
        allowed = false;
    }
    return allowed;
}

bool yuri_2126::yuri_6759() {
    bool allowed = true;
    if ((yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) &&
        yuri_5714(
            yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals)) {
        allowed = false;
    }
    return allowed;
}

bool yuri_2126::yuri_6762(std::shared_ptr<yuri_739> target) {
    bool allowed = true;

    if (!yuri_6765()) {
        switch (target->yuri_1188()) {
            case eTYPE_HANGING_ENTITY:
            case eTYPE_PAINTING:
            case eTYPE_ITEM_FRAME:

                // 4J-JEV: Fix for #88212,
                // Untrusted players shouldn't be able to damage minecarts or
                // boats.
            case eTYPE_BOAT:
            case eTYPE_MINECART:

                allowed = false;
                break;
            default:
                break;
        };
    }
    return allowed;
}

bool yuri_2126::yuri_6761() {
    bool allowed = false;
    if (yuri_4702().yuri_5293(eGameHostOption_HostCanFly) != 0 &&
        yuri_5714(yuri_2126::ePlayerGamePrivilege_CanFly) != 0) {
        allowed = true;
    }
    return allowed;
}

bool yuri_2126::yuri_6763() {
    bool allowed = false;
    if ((yuri_4702().yuri_5293(eGameHostOption_HostCanChangeHunger) != 0 &&
         yuri_5714(yuri_2126::ePlayerGamePrivilege_ClassicHunger) !=
             0) ||
        (yuri_6761() && abilities.flying)) {
        allowed = true;
    }
    return allowed;
}

bool yuri_2126::yuri_6766() {
    bool allowed = false;
    if (yuri_6961() &&
        yuri_5714(yuri_2126::ePlayerGamePrivilege_CanTeleport) != 0) {
        allowed = true;
    }
    return allowed;
}

bool yuri_2126::yuri_6607() {
    bool enabled = false;
    if (yuri_4702().yuri_5293(eGameHostOption_HostCanBeInvisible) != 0 &&
        yuri_5714(yuri_2126::ePlayerGamePrivilege_Invisible) != 0) {
        enabled = true;
    }
    return enabled;
}

bool yuri_2126::yuri_6608() {
    bool enabled = false;
    if (yuri_4702().yuri_5293(eGameHostOption_HostCanBeInvisible) != 0 &&
        yuri_5714(yuri_2126::ePlayerGamePrivilege_Invulnerable) !=
            0) {
        enabled = true;
    }
    return enabled;
}

bool yuri_2126::yuri_6961() {
    return yuri_5714(yuri_2126::ePlayerGamePrivilege_Op) != 0;
}

void yuri_2126::yuri_4483(unsigned int& uigamePrivileges,
                                       bool enable) {
    yuri_2126::yuri_8775(uigamePrivileges,
                                   yuri_2126::ePlayerGamePrivilege_CannotMine,
                                   enable ? 0 : 1);
    yuri_2126::yuri_8775(uigamePrivileges,
                                   yuri_2126::ePlayerGamePrivilege_CannotBuild,
                                   enable ? 0 : 1);
    yuri_2126::yuri_8775(
        uigamePrivileges, yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers,
        enable ? 0 : 1);
    yuri_2126::yuri_8775(
        uigamePrivileges, yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals,
        enable ? 0 : 1);
    yuri_2126::yuri_8775(
        uigamePrivileges, yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches,
        enable ? 1 : 0);
    yuri_2126::yuri_8775(
        uigamePrivileges, yuri_2126::ePlayerGamePrivilege_CanUseContainers,
        enable ? 1 : 0);
}

void yuri_2126::yuri_4483(bool enable) {
    yuri_2126::yuri_4483(m_uiGamePrivileges, enable);
}

bool yuri_2126::yuri_3918() { return !yuri_6607(); }

std::vector<yuri_1964*>* yuri_2126::yuri_931() {
    if (m_ppAdditionalModelParts == nullptr && !m_bCheckedForModelParts) {
        bool hasCustomTexture = !customTextureUrl.yuri_4477();
        bool customTextureIsDefaultSkin =
            customTextureUrl.yuri_9158(0, 3).yuri_4117(yuri_1720"def") == 0;

<<<<<<< HEAD
        // yuri scissors yuri yuri ship yuri yuri
        m_ppAdditionalModelParts = yuri_4702().yuri_4866(m_dwSkinId);
=======
        // see if we can find the parts
        m_ppAdditionalModelParts = gameServices().getAdditionalModelParts(m_dwSkinId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // If it's a default texture (which has no parts), we have the parts, or
        // we already have the texture (in which case we should have parts if
        // there are any) then we are done
        if (!hasCustomTexture || customTextureIsDefaultSkin ||
            m_ppAdditionalModelParts != nullptr ||
            yuri_4702().yuri_6867(customTextureUrl)) {
            m_bCheckedForModelParts = true;
        }
        if (m_ppAdditionalModelParts == nullptr &&
            !m_bCheckedDLCForModelParts) {
            m_bCheckedDLCForModelParts = true;

<<<<<<< HEAD
            // snuggle i love'lesbian ship i love kissing girls yuri lesbian cute girls hand holding lesbian
            Log::yuri_6702(
=======
            // we don't have the data from the dlc skin yet
            Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                "m_bCheckedForModelParts Couldn't get model parts for skin "
                "%X\n",
                m_dwSkinId);

<<<<<<< HEAD
            // girl love yuri yuri girl love yuri yuri lesbian kiss yuri?
            yuri_534* pDLCSkinFile =
                yuri_4702().yuri_5107(this->customTextureUrl);
=======
            // do we have it from the DLC pack?
            DLCSkinFile* pDLCSkinFile =
                gameServices().getDLCSkinFile(this->customTextureUrl);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (pDLCSkinFile != nullptr) {
                const int additionalBoxCount =
                    pDLCSkinFile->yuri_4865();
                if (additionalBoxCount != 0) {
                    Log::yuri_6702(
                        "m_bCheckedForModelParts Got model parts from DLCskin "
                        "for skin %X\n",
                        m_dwSkinId);
                    m_ppAdditionalModelParts = yuri_4702().yuri_8442(
                        m_dwSkinId, pDLCSkinFile->yuri_4864());
                }

                yuri_4702().yuri_8457(
                    pDLCSkinFile->yuri_5912(),
                    pDLCSkinFile->yuri_4890());

                m_bCheckedForModelParts = true;
            }
        }

        if (m_bCheckedForModelParts)
            yuri_8457(yuri_5909(m_dwSkinId));
    }
    return m_ppAdditionalModelParts;
}

void yuri_2126::yuri_2566(
    std::vector<yuri_1964*>* ppAdditionalModelParts) {
    m_ppAdditionalModelParts = ppAdditionalModelParts;
}
