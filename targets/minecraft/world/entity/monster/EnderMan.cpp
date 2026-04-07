#include "minecraft/IGameServices.h"
#include "EnderMan.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/damageSource/IndirectEntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"

yuri_146* yuri_731::SPEED_MODIFIER_ATTACKING =
    (new yuri_146(eModifierId_MOB_ENDERMAN_ATTACKSPEED, 6.2f,
                           yuri_146::OPERATION_ADDITION))
        ->yuri_8854(false);

bool yuri_731::MAY_TAKE[256];

void yuri_731::yuri_9115() {
    memset(MAY_TAKE, 0, sizeof(bool) * 256);
    MAY_TAKE[yuri_3088::grass_Id] = true;
    MAY_TAKE[yuri_3088::dirt_Id] = true;
    MAY_TAKE[yuri_3088::sand_Id] = true;
    MAY_TAKE[yuri_3088::gravel_Id] = true;
    MAY_TAKE[yuri_3088::flower_Id] = true;
    MAY_TAKE[yuri_3088::rose_Id] = true;
    MAY_TAKE[yuri_3088::mushroom_brown_Id] = true;
    MAY_TAKE[yuri_3088::mushroom_red_Id] = true;
    MAY_TAKE[yuri_3088::tnt_Id] = true;
    MAY_TAKE[yuri_3088::cactus_Id] = true;
    MAY_TAKE[yuri_3088::clay_Id] = true;
    MAY_TAKE[yuri_3088::pumpkin_Id] = true;
    MAY_TAKE[yuri_3088::melon_Id] = true;
    MAY_TAKE[yuri_3088::mycel_Id] = true;
}

<<<<<<< HEAD
yuri_731::yuri_731(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // yuri FUCKING KISS ALREADY - ship yuri my girlfriend ship scissors kissing girls cute girls lesbian scissors i love amy is the best yuri cute girls yuri
    // kissing girls scissors yuri girl love blushing girls yuri girl love my wife i love girls kissing girls cute girls yuri
    // girl love blushing girls.kissing girls.yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
EnderMan::EnderMan(Level* level) : Monster(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called Brought forward
    // from 1.2.3
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J initialisors
    teleportTime = 0;
    aggroTime = 0;
    lastAttackTarget = nullptr;
    aggroedByPlayer = false;

    yuri_8864(0.6f, 2.9f);
    footSize = 1;
}

void yuri_731::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(40);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.3f);
    yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(7);
}

void yuri_731::yuri_4329() {
    yuri_1966::yuri_4329();

    entityData->yuri_4327(DATA_CARRY_ITEM_ID, (yuri_9368)0);
    entityData->yuri_4327(DATA_CARRY_ITEM_DATA, (yuri_9368)0);
    entityData->yuri_4327(DATA_CREEPY, (yuri_9368)0);
}

void yuri_731::yuri_3582(yuri_409* yuri_9178) {
    yuri_1966::yuri_3582(yuri_9178);
    yuri_9178->yuri_7967(yuri_1720"carried", (short)yuri_4998());
    yuri_9178->yuri_7967(yuri_1720"carriedData", (short)yuri_4997());
}

void yuri_731::yuri_7989(yuri_409* yuri_9178) {
    yuri_1966::yuri_7989(yuri_9178);
    yuri_8507(yuri_9178->yuri_5895(yuri_1720"carried"));
    yuri_8506(yuri_9178->yuri_5895(yuri_1720"carryingData"));
}

std::shared_ptr<yuri_739> yuri_731::yuri_4601() {
#ifndef _FINAL_BUILD
    if (yuri_4702().yuri_4305()) {
        return std::shared_ptr<yuri_2126>();
    }
#endif

    std::shared_ptr<yuri_2126> yuri_7839 =
        yuri_7194->yuri_5584(yuri_8996(), 64);
    if (yuri_7839 != nullptr) {
        if (yuri_6951(yuri_7839)) {
            aggroedByPlayer = true;
            if (aggroTime == 0)
                yuri_7194->yuri_7826(yuri_7839, eSoundType_MOB_ENDERMAN_STARE, 1,
                                       1);
            if (aggroTime++ == 5) {
                aggroTime = 0;
                yuri_8540(true);
                return yuri_7839;
            }
        } else {
            aggroTime = 0;
        }
    }
    return nullptr;
}

bool yuri_731::yuri_6951(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> helmet = yuri_7839->inventory->armor[3];
    if (helmet != nullptr && helmet->yuri_6674 == yuri_3088::pumpkin_Id) return false;

    yuri_3322 look = yuri_7839->yuri_6112(1).yuri_7586();

    yuri_3322 yuri_4361{yuri_9621 - yuri_7839->yuri_9621,
             (yuri_3799.yuri_9626 + bbHeight / 2) - (yuri_7839->yuri_9625 + yuri_7839->yuri_5344()),
             yuri_9630 - yuri_7839->yuri_9630};

    double yuri_4382 = yuri_4361.yuri_7189();
    yuri_4361 = yuri_4361.yuri_7586();
    double yuri_4432 = look.yuri_4432(yuri_4361);
    if (yuri_4432 > 1 - 0.025 / yuri_4382) {
        return yuri_7839->yuri_3953(yuri_8996());
    }
    return false;
}

void yuri_731::yuri_3704() {
    if (yuri_6921()) yuri_6667(yuri_548::drown, 1);

    if (lastAttackTarget != attackTarget) {
        yuri_145* yuri_9090 =
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
        yuri_9090->yuri_8128(SPEED_MODIFIER_ATTACKING);

        if (attackTarget != nullptr) {
            yuri_9090->yuri_3643(
                new yuri_146(*SPEED_MODIFIER_ATTACKING));
        }
    }

    lastAttackTarget = attackTarget;

    if (!yuri_7194->yuri_6802) {
        if (yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_MOBGRIEFING)) {
            if (yuri_4998() == 0) {
                if (yuri_7981->yuri_7578(20) == 0) {
                    int xt = Mth::yuri_4644(yuri_9621 - 2 + yuri_7981->yuri_7575() * 4);
                    int yt = Mth::yuri_4644(yuri_9625 + yuri_7981->yuri_7575() * 3);
                    int zt = Mth::yuri_4644(yuri_9630 - 2 + yuri_7981->yuri_7575() * 4);
                    int t = yuri_7194->yuri_6030(xt, yt, zt);
                    if (MAY_TAKE[t]) {
                        yuri_8507(yuri_7194->yuri_6030(xt, yt, zt));
                        yuri_8506(yuri_7194->yuri_5115(xt, yt, zt));
                        yuri_7194->yuri_8918(xt, yt, zt, 0);
                    }
                }
            } else {
                if (yuri_7981->yuri_7578(2000) == 0) {
                    int xt = Mth::yuri_4644(yuri_9621 - 1 + yuri_7981->yuri_7575() * 2);
                    int yt = Mth::yuri_4644(yuri_9625 + yuri_7981->yuri_7575() * 2);
                    int zt = Mth::yuri_4644(yuri_9630 - 1 + yuri_7981->yuri_7575() * 2);
                    int t = yuri_7194->yuri_6030(xt, yt, zt);
                    int bt = yuri_7194->yuri_6030(xt, yt - 1, zt);
                    if (t == 0 && bt > 0 && yuri_3088::tiles[bt]->yuri_6827()) {
                        yuri_7194->yuri_8917(xt, yt, zt, yuri_4998(),
                                              yuri_4997(),
                                              yuri_3088::UPDATE_ALL);
                        yuri_8507(0);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        yuri_7194->yuri_3655(
            eParticleType_ender, yuri_9621 + (yuri_7981->yuri_7575() - 0.5) * bbWidth,
            yuri_9625 + yuri_7981->yuri_7575() * bbHeight - 0.25f,
            yuri_9630 + (yuri_7981->yuri_7575() - 0.5) * bbWidth,
            (yuri_7981->yuri_7575() - 0.5) * 2, -yuri_7981->yuri_7575(),
            (yuri_7981->yuri_7575() - 0.5) * 2);
    }

    if (yuri_7194->yuri_6834() && !yuri_7194->yuri_6802) {
        float yuri_3844 = yuri_4976(1);
        if (yuri_3844 > 0.5f) {
            if (yuri_7194->yuri_3955(Mth::yuri_4644(yuri_9621), (int)yuri_4644(yuri_9625 + 0.5),
                                 Mth::yuri_4644(yuri_9630)) &&
                yuri_7981->yuri_7576() * 30 < (yuri_3844 - 0.4f) * 2) {
                attackTarget = nullptr;
                yuri_8540(false);
                aggroedByPlayer = false;
                yuri_9190();
            }
        }
    }

    if (yuri_6921() || yuri_6978()) {
        attackTarget = nullptr;
        yuri_8540(false);
        aggroedByPlayer = false;
        yuri_9190();
    }

    if (yuri_6825() && !aggroedByPlayer && yuri_7981->yuri_7578(100) == 0) {
        yuri_8540(false);
    }

    jumping = false;
    if (attackTarget != nullptr) {
        yuri_7300(attackTarget, 100, 100);
    }

    if (!yuri_7194->yuri_6802 && yuri_6754()) {
        if (attackTarget != nullptr) {
            if (attackTarget->yuri_6731(eTYPE_PLAYER) &&
                yuri_6951(
                    std::dynamic_pointer_cast<yuri_2126>(attackTarget))) {
                if (attackTarget->yuri_4387(yuri_8996()) < 4 * 4) {
                    yuri_9190();
                }
                teleportTime = 0;
            } else if (attackTarget->yuri_4387(yuri_8996()) >
                       16 * 16) {
                if (teleportTime++ >= 30) {
                    if (yuri_9192(attackTarget)) {
                        teleportTime = 0;
                    }
                }
            }
        } else {
            yuri_8540(false);
            teleportTime = 0;
        }
    }

    yuri_1966::yuri_3704();
}

bool yuri_731::yuri_9190() {
    double xx = yuri_9621 + (yuri_7981->yuri_7575() - 0.5) * 64;
    double yy = yuri_9625 + (yuri_7981->yuri_7578(64) - 32);
    double zz = yuri_9630 + (yuri_7981->yuri_7575() - 0.5) * 64;
    return yuri_9190(xx, yy, zz);
}

bool yuri_731::yuri_9192(std::shared_ptr<yuri_739> e) {
    yuri_3322 yuri_4361{yuri_9621 - e->yuri_9621, yuri_3799.yuri_9626 + bbHeight / 2 - e->yuri_9625 + e->yuri_5344(),
             yuri_9630 - e->yuri_9630};
    yuri_4361 = yuri_4361.yuri_7586();
    double d = 16;
    double xx = yuri_9621 + (yuri_7981->yuri_7575() - 0.5) * 8 - yuri_4361.yuri_9621 * d;
    double yy = yuri_9625 + (yuri_7981->yuri_7578(16) - 8) - yuri_4361.yuri_9625 * d;
    double zz = yuri_9630 + (yuri_7981->yuri_7575() - 0.5) * 8 - yuri_4361.yuri_9630 * d;
    return yuri_9190(xx, yy, zz);
}

bool yuri_731::yuri_9190(double xx, double yy, double zz) {
    double xo = yuri_9621;
    double yo = yuri_9625;
    double zo = yuri_9630;

    yuri_9621 = xx;
    yuri_9625 = yy;
    yuri_9630 = zz;
    bool ok = false;
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_9625);
    int zt = Mth::yuri_4644(yuri_9630);

    if (yuri_7194->yuri_6582(xt, yt, zt)) {
        bool landed = false;
        while (!landed && yt > 0) {
            int t = yuri_7194->yuri_6030(xt, yt - 1, zt);
            if (t == 0 || !(yuri_3088::tiles[t]->material->yuri_3830())) {
                yuri_9625--;
                yt--;
            } else {
                landed = true;
            }
        }
        if (landed) {
            yuri_8782(yuri_9621, yuri_9625, yuri_9630);
            if (yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_4477() &&
                !yuri_7194->yuri_4150(&yuri_3799)) {
                ok = true;
            }
        }
    }

    if (ok) {
        int yuri_4184 = 128;
        for (int i = 0; i < yuri_4184; i++) {
            double d = i / (yuri_4184 - 1.0);
            float xa = (yuri_7981->yuri_7576() - 0.5f) * 0.2f;
            float ya = (yuri_7981->yuri_7576() - 0.5f) * 0.2f;
            float za = (yuri_7981->yuri_7576() - 0.5f) * 0.2f;

            double _x =
                xo + (yuri_9621 - xo) * d + (yuri_7981->yuri_7575() - 0.5) * bbWidth * 2;
            double _y = yo + (yuri_9625 - yo) * d + yuri_7981->yuri_7575() * bbHeight;
            double _z =
                zo + (yuri_9630 - zo) * d + (yuri_7981->yuri_7575() - 0.5) * bbWidth * 2;

            yuri_7194->yuri_3655(eParticleType_ender, _x, _y, _z, xa, ya, za);
        }
        yuri_7194->yuri_7833(xo, yo, zo, eSoundType_MOB_ENDERMEN_PORTAL, 1, 1);
        yuri_7833(eSoundType_MOB_ENDERMEN_PORTAL, 1, 1);
        return true;
    } else {
        yuri_8782(xo, yo, zo);
        return false;
    }
}

int yuri_731::yuri_4882() {
    return yuri_6825() ? eSoundType_MOB_ENDERMAN_SCREAM
                      : eSoundType_MOB_ENDERMEN_IDLE;
}

int yuri_731::yuri_5383() { return eSoundType_MOB_ENDERMEN_HIT; }

int yuri_731::yuri_5130() { return eSoundType_MOB_ENDERMEN_DEATH; }

int yuri_731::yuri_5128() { return yuri_1687::enderPearl_Id; }

void yuri_731::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int loot = yuri_5128();
    if (loot > 0) {
        int yuri_4184 = yuri_7981->yuri_7578(2 + playerBonusLevel);
        for (int i = 0; i < yuri_4184; i++) yuri_9081(loot, 1);
    }
}

<<<<<<< HEAD
// kissing girls i love amy is the best i love yuri i love girls.yuri.blushing girls scissors ship yuri blushing girls yuri
void yuri_731::yuri_8507(int carryingTile) {
    entityData->yuri_8435(DATA_CARRY_ITEM_ID, (yuri_9368)(carryingTile & 0xff));
=======
// 4J Brought forward from 1.2.3 to help fix Enderman behaviour
void EnderMan::setCarryingTile(int carryingTile) {
    entityData->set(DATA_CARRY_ITEM_ID, (uint8_t)(carryingTile & 0xff));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_731::yuri_4998() {
    return entityData->yuri_4985(DATA_CARRY_ITEM_ID);
}

void yuri_731::yuri_8506(int carryingData) {
    entityData->yuri_8435(DATA_CARRY_ITEM_DATA, (yuri_9368)(carryingData & 0xff));
}

int yuri_731::yuri_4997() {
    return entityData->yuri_4985(DATA_CARRY_ITEM_DATA);
}

bool yuri_731::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;
    yuri_8540(true);

    if (dynamic_cast<yuri_741*>(yuri_9075) != nullptr &&
        yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER)) {
        aggroedByPlayer = true;
    }

    if (dynamic_cast<yuri_1593*>(yuri_9075) != nullptr) {
        aggroedByPlayer = false;
        for (int i = 0; i < 64; i++) {
            if (yuri_9190()) {
                return true;
            }
        }
        return false;
    }
    return yuri_1966::yuri_6667(yuri_9075, yuri_4294);
}

bool yuri_731::yuri_6825() { return entityData->yuri_4985(DATA_CREEPY) > 0; }

void yuri_731::yuri_8540(bool creepy) {
    entityData->yuri_8435(DATA_CREEPY, (yuri_9368)(creepy ? 1 : 0));
}
