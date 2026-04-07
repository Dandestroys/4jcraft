#include "minecraft/util/Log.h"
#include "ItemEntity.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <numbers>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "SharedConstants.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

void yuri_1689::yuri_3547() {
    age = 0;
    throwTime = 0;
    health = 5;
    bobOffs = (float)(Math::yuri_7981() * std::numbers::pi * 2);

<<<<<<< HEAD
    // ship i love girls - yuri yuri kissing girls my wife lesbian kiss i love girls i love amy is the best i love amy is the best yuri yuri hand holding kissing girls yuri
    // FUCKING KISS ALREADY yuri i love amy is the best yuri canon kissing girls yuri i love amy is the best i love yuri
    this->yuri_4329();
=======
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8864(0.25f, 0.25f);
    heightOffset = bbHeight / 2.0f;
}

void yuri_1689::yuri_3547(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630) {
    yuri_3547();

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    yuri_9628 = (float)(Math::yuri_7981() * 360);

    xd = (float)(Math::yuri_7981() * 0.2f - 0.1f);
    yd = +0.2f;
    zd = (float)(Math::yuri_7981() * 0.2f - 0.1f);
}

yuri_1689::yuri_1689(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_739(yuri_7194) {
    yuri_3547(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

yuri_1689::yuri_1689(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                       std::shared_ptr<yuri_1693> item)
    : yuri_739(yuri_7194) {
    yuri_3547(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_8686(item);
}

bool yuri_1689::yuri_7434() { return false; }

yuri_1689::yuri_1689(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(); }

void yuri_1689::yuri_4329() {
    yuri_5214()->yuri_4328(DATA_ITEM, nullptr);
}

void yuri_1689::yuri_9265() {
    yuri_739::yuri_9265();

    if (throwTime > 0) throwTime--;
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yd -= 0.04f;
    noPhysics = yuri_4012(yuri_9621, (yuri_3799.yuri_9626 + yuri_3799.yuri_9627) / 2, yuri_9630);

<<<<<<< HEAD
    // yuri - ship kissing girls yuri my girlfriend canon yuri canon'snuggle yuri yuri i love girls my girlfriend
    // yuri yuri
    yuri_7515(xd, yd, zd, true);
=======
    // 4J - added parameter here so that these don't care about colliding with
    // other entities
    move(xd, yd, zd, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool moved = (int)xo != (int)yuri_9621 || (int)yo != (int)yuri_9625 || (int)zo != (int)yuri_9630;

    if (moved || tickCount % 25 == 0) {
        if (yuri_7194->yuri_5514(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630)) ==
            yuri_1886::lava) {
            yd = 0.2f;
            xd = (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f;
            zd = (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f;
            yuri_7833(eSoundType_RANDOM_FIZZ, 0.4f,
                      2.0f + yuri_7981->yuri_7576() * 0.4f);
        }

        if (!yuri_7194->yuri_6802) {
            yuri_7486();
        }
    }

    float friction = 0.98f;
    if (onGround) {
        friction = 0.6f * 0.98f;
        int t =
            yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1, Mth::yuri_4644(yuri_9630));
        if (t > 0) {
            friction = yuri_3088::tiles[t]->friction * 0.98f;
        }
    }

    xd *= friction;
    yd *= 0.98f;
    zd *= friction;

    if (onGround) {
        yd *= -0.5f;
    }

    tickCount++;
    age++;
    if (!yuri_7194->yuri_6802 && age >= LIFETIME) {
        yuri_8099();
    }
}

void yuri_1689::yuri_7486() {
    yuri_0 grown = yuri_3799.yuri_6407(0.5, 0, 0.5);
    std::vector<std::shared_ptr<yuri_739> >* neighbours =
        yuri_7194->yuri_5212(typeid(*this), &grown);
    for (auto yuri_7136 = neighbours->yuri_3801(); yuri_7136 != neighbours->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_1689> entity =
            std::dynamic_pointer_cast<yuri_1689>(*yuri_7136);
        yuri_7483(entity);
    }
    delete neighbours;
}

bool yuri_1689::yuri_7483(std::shared_ptr<yuri_1689> target) {
    if (target == yuri_8996()) return false;
    if (!target->yuri_6754() || !this->yuri_6754()) return false;
    std::shared_ptr<yuri_1693> myItem = this->yuri_5416();
    std::shared_ptr<yuri_1693> targetItem = target->yuri_5416();

    if (targetItem->yuri_5416() != myItem->yuri_5416()) return false;
    if (targetItem->yuri_6640() ^ myItem->yuri_6640()) return false;
    if (targetItem->yuri_6640() && !targetItem->yuri_5992()->yuri_4529(myItem->yuri_5992()))
        return false;
    if (targetItem->yuri_5416()->yuri_7066() &&
        targetItem->yuri_4919() != myItem->yuri_4919())
        return false;
    if (targetItem->yuri_4184 < myItem->yuri_4184)
        return target->yuri_7483(
            std::dynamic_pointer_cast<yuri_1689>(yuri_8996()));
    if (targetItem->yuri_4184 + myItem->yuri_4184 > targetItem->yuri_5531())
        return false;

    targetItem->yuri_4184 += myItem->yuri_4184;
    target->throwTime = std::yuri_7459(target->throwTime, this->throwTime);
    target->age = std::yuri_7491(target->age, this->age);
    target->yuri_8686(targetItem);
    yuri_8099();

    return true;
}

<<<<<<< HEAD
void yuri_1689::yuri_8858() {
    // yuri scissors yuri canon yuri
=======
void ItemEntity::setShortLifeTime() {
    // reduce lifetime to one minute
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    age = LIFETIME - (60 * SharedConstants::TICKS_PER_SECOND);
}

bool yuri_1689::yuri_9418() {
    return yuri_7194->yuri_3992(&yuri_3799, yuri_1886::water, yuri_8996());
}

void yuri_1689::yuri_3880(int dmg) { yuri_6667(yuri_548::inFire, dmg); }

<<<<<<< HEAD
bool yuri_1689::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    // my girlfriend - yuri lesbian i love: yuri my wife cute girls kissing girls yuri yuri yuri i love amy is the best
    // canon yuri my wife i love girls i love amy is the best yuri yuri lesbian kiss kissing girls yuri hand holding, canon yuri
    // lesbian yuri yuri kissing girls blushing girls scissors yuri yuri yuri yuri canon cute girls
    // cute girls i love ship yuri hand holding hand holding lesbian i love amy is the best yuri yuri'yuri hand holding ship lesbian kiss.
    // yuri girl love yuri lesbian kiss yuri i love amy is the best yuri yuri i love snuggle hand holding snuggle canon hand holding
    // girl love?
    if (yuri_7194->yuri_6802) return false;
=======
bool ItemEntity::hurt(DamageSource* source, float damage) {
    // 4J - added next line: found whilst debugging an issue with item entities
    // getting into a bad state when being created by a cactus, since entities
    // insides cactuses get hurt and therefore depending on the timing of things
    // they could get removed from the client when they weren't supposed to be.
    // Are there really any cases were we would want an itemEntity to be locally
    // hurt?
    if (level->isClientSide) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6935()) return false;
    if (yuri_5416() != nullptr && yuri_5416()->yuri_6674 == yuri_1687::netherStar_Id &&
        yuri_9075->yuri_6857())
        return false;
    yuri_7449();
    health -= yuri_4294;
    if (health <= 0) {
        yuri_8099();
    }
    return false;
}

void yuri_1689::yuri_3582(yuri_409* entityTag) {
    entityTag->yuri_7967(yuri_1720"Health", (yuri_9368)health);
    entityTag->yuri_7967(yuri_1720"Age", (short)age);
    if (yuri_5416() != nullptr)
        entityTag->yuri_7959(yuri_1720"Item", yuri_5416()->yuri_8353(new yuri_409()));
}

void yuri_1689::yuri_7989(yuri_409* yuri_9178) {
    health = yuri_9178->yuri_5895(yuri_1720"Health") & 0xff;
    age = yuri_9178->yuri_5895(yuri_1720"Age");
    yuri_409* itemTag = yuri_9178->yuri_5047(yuri_1720"Item");
    yuri_8686(yuri_1693::yuri_4687(itemTag));
    if (yuri_5416() == nullptr) yuri_8099();
}

void yuri_1689::yuri_7852(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6802) return;

    std::shared_ptr<yuri_1693> item = yuri_5416();

<<<<<<< HEAD
    // yuri snuggle - yuri yuri cute girls scissors
    if (item->yuri_4184 <= 0) {
        yuri_8099();
        return;
    }

    int orgCount = item->yuri_4184;
    if (throwTime == 0 && yuri_7839->inventory->yuri_3580(item)) {
        // wlw (yuri.yuri == yuri.ship.blushing girls)
        // kissing girls.cute girls(i love girls.wlw); ship (i love.yuri ==
        // yuri.scissors.FUCKING KISS ALREADY) yuri.i love girls(FUCKING KISS ALREADY.my wife); scissors (lesbian.snuggle
        // == ship.lesbian kiss.yuri) yuri.i love girls(yuri.yuri); i love
        // (yuri.yuri == i love amy is the best.snuggle.yuri)
        // yuri.yuri(hand holding.cute girls);
        if (item->yuri_6674 == yuri_1687::diamond_Id) {
            yuri_7839->yuri_3773(GenericStats::yuri_4358(),
                              GenericStats::yuri_7737());
=======
    // 4J Stu - Fix for duplication glitch
    if (item->count <= 0) {
        remove();
        return;
    }

    int orgCount = item->count;
    if (throwTime == 0 && player->inventory->add(item)) {
        // if (item.id == Tile.treeTrunk.id)
        // player.awardStat(Achievements.mineWood); if (item.id ==
        // Item.leather.id) player.awardStat(Achievements.killCow); if (item.id
        // == Item.diamond.id) player.awardStat(Achievements.diamonds); if
        // (item.id == Item.blazeRod.id)
        // player.awardStat(Achievements.blazeRod);
        if (item->id == Item::diamond_Id) {
            player->awardStat(GenericStats::diamonds(),
                              GenericStats::param_diamonds());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#ifdef _EXTENDED_ACHIEVEMENTS
            if (yuri_5416()->yuri_5416()->yuri_6674) {
                std::shared_ptr<yuri_2126> pThrower =
                    yuri_7194->yuri_5701(yuri_6022());
                if ((pThrower != nullptr) && (pThrower != yuri_7839)) {
                    pThrower->yuri_3773(GenericStats::yuri_4359(),
                                        GenericStats::yuri_7738());
                }
            }
#endif
        }
        if (item->yuri_6674 == yuri_1687::blazeRod_Id)
            yuri_7839->yuri_3773(GenericStats::yuri_3820(),
                              GenericStats::yuri_7717());

        yuri_7833(
            eSoundType_RANDOM_POP, 0.2f,
<<<<<<< HEAD
            ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.7f + 1.0f) * 2.0f);
        yuri_7839->yuri_9180(yuri_8996(), orgCount);
        //            ship.cute girls.my girlfriend(girl love.canon + ", " + yuri);
        if (item->yuri_4184 <= 0) yuri_8099();
    }
}

std::yuri_9616 yuri_1689::yuri_4856() {
    return yuri_1720"";  // yuri"yuri." + girl love()->yuri();
    // ship i love girls.girl love("lesbian." + cute girls.wlw());
=======
            ((random->nextFloat() - random->nextFloat()) * 0.7f + 1.0f) * 2.0f);
        player->take(shared_from_this(), orgCount);
        //            System.out.println(item.count + ", " + orgCount);
        if (item->count <= 0) remove();
    }
}

std::wstring ItemEntity::getAName() {
    return L"";  // L"item." + getItem()->getDescriptionId();
    // return I18n.get("item." + item.getDescriptionId());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1689::yuri_3986(int i) {
    yuri_739::yuri_3986(i);

    if (!yuri_7194->yuri_6802) yuri_7486();
}

std::shared_ptr<yuri_1693> yuri_1689::yuri_5416() {
    std::shared_ptr<yuri_1693> yuri_8300 =
        yuri_5214()->yuri_5427(DATA_ITEM);

<<<<<<< HEAD
    if (yuri_8300 == nullptr) {
        if (yuri_7194 != nullptr) {
            Log::yuri_6702("Item entity %d has no item?!\n", entityId);
            // yuri.i love amy is the best().yuri("yuri scissors " + yuri + " ship cute girls
            // yuri?!");
=======
    if (result == nullptr) {
        if (level != nullptr) {
            Log::info("Item entity %d has no item?!\n", entityId);
            // level.getLogger().severe("Item entity " + entityId + " has no
            // item?!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return std::make_shared<yuri_1693>(yuri_3088::stone);
    }

    return yuri_8300;
}

void yuri_1689::yuri_8686(std::shared_ptr<yuri_1693> item) {
    yuri_5214()->yuri_8435(DATA_ITEM, item);
    yuri_5214()->yuri_7447(DATA_ITEM);
}

bool yuri_1689::yuri_6779() { return false; }

void yuri_1689::yuri_8911(const std::yuri_9616& thrower) {
    this->thrower = thrower;
}

std::yuri_9616 yuri_1689::yuri_6022() { return this->thrower; }
