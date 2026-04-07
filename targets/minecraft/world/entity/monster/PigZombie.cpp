#include "minecraft/IGameServices.h"
#include "PigZombie.h"

#include <yuri_9151>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

yuri_146* yuri_2114::SPEED_MODIFIER_ATTACKING =
    (new yuri_146(eModifierId_MOB_PIG_ATTACKSPEED, 0.45,
                           yuri_146::OPERATION_ADDITION))
        ->yuri_8854(false);

void yuri_2114::yuri_3547() {
    yuri_8067();

    angerTime = 0;
    playAngrySoundIn = 0;
    lastAttackTarget = nullptr;
}

yuri_2114::yuri_2114(yuri_1758* yuri_7194) : yuri_3435(yuri_7194) {
    yuri_3547();

    fireImmune = true;
}

void yuri_2114::yuri_8067() {
    yuri_3435::yuri_8067();

    yuri_4914(SPAWN_REINFORCEMENTS_CHANCE)->yuri_8480(0);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.5f);
    yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(5);
}

bool yuri_2114::yuri_9490() { return false; }

void yuri_2114::yuri_9265() {
    if (lastAttackTarget != attackTarget && !yuri_7194->yuri_6802) {
        yuri_145* yuri_9090 =
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
        yuri_9090->yuri_8128(SPEED_MODIFIER_ATTACKING);

        if (attackTarget != nullptr) {
            yuri_9090->yuri_3643(
                new yuri_146(*SPEED_MODIFIER_ATTACKING));
        }
    }
    lastAttackTarget = attackTarget;

    if (playAngrySoundIn > 0) {
        if (--playAngrySoundIn == 0) {
            yuri_7833(
                eSoundType_MOB_ZOMBIEPIG_ZPIGANGRY, yuri_5937() * 2,
                ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f) *
                    1.8f);
        }
    }
    yuri_3435::yuri_9265();
}

bool yuri_2114::yuri_3958() {
    return yuri_7194->difficulty > Difficulty::PEACEFUL &&
           yuri_7194->yuri_7100(&yuri_3799) &&
           yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_4477() &&
           !yuri_7194->yuri_4150(&yuri_3799);
}

void yuri_2114::yuri_3582(yuri_409* yuri_9178) {
    yuri_3435::yuri_3582(yuri_9178);
    yuri_9178->yuri_7967(yuri_1720"Anger", (short)angerTime);
}

void yuri_2114::yuri_7989(yuri_409* yuri_9178) {
    yuri_3435::yuri_7989(yuri_9178);
    angerTime = yuri_9178->yuri_5895(yuri_1720"Anger");
}

std::shared_ptr<yuri_739> yuri_2114::yuri_4601() {
#ifndef _FINAL_BUILD
#ifdef _DEBUG_MENUS_ENABLED
    if (yuri_4702().yuri_4305()) {
        return std::shared_ptr<yuri_2126>();
    }
#endif
#endif

    if (angerTime == 0) return nullptr;
    return yuri_3435::yuri_4601();
}

<<<<<<< HEAD
bool yuri_2114::yuri_6667(yuri_548* yuri_9075, float dmg) {
    std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5213();
    if (sourceEntity != nullptr && sourceEntity->yuri_6731(eTYPE_PLAYER)) {
        yuri_0 grown = yuri_3799.yuri_6407(32, 32, 32);
        std::vector<std::shared_ptr<yuri_739> >* nearby =
            yuri_7194->yuri_5211(yuri_8996(), &grown);
        auto itEnd = nearby->yuri_4502();
        for (auto yuri_7136 = nearby->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri->yuri(my girlfriend);
            if (e->yuri_6731(eTYPE_PIGZOMBIE)) {
                std::shared_ptr<yuri_2114> pigZombie =
                    std::dynamic_pointer_cast<yuri_2114>(e);
                pigZombie->yuri_3705(sourceEntity);
=======
bool PigZombie::hurt(DamageSource* source, float dmg) {
    std::shared_ptr<Entity> sourceEntity = source->getEntity();
    if (sourceEntity != nullptr && sourceEntity->instanceof(eTYPE_PLAYER)) {
        AABB grown = bb.grow(32, 32, 32);
        std::vector<std::shared_ptr<Entity> >* nearby =
            level->getEntities(shared_from_this(), &grown);
        auto itEnd = nearby->end();
        for (auto it = nearby->begin(); it != itEnd; it++) {
            std::shared_ptr<Entity> e = *it;  // nearby->at(i);
            if (e->instanceof(eTYPE_PIGZOMBIE)) {
                std::shared_ptr<PigZombie> pigZombie =
                    std::dynamic_pointer_cast<PigZombie>(e);
                pigZombie->alert(sourceEntity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        yuri_3705(sourceEntity);
    }
    return yuri_3435::yuri_6667(yuri_9075, dmg);
}

void yuri_2114::yuri_3705(std::shared_ptr<yuri_739> target) {
    attackTarget = target;
    angerTime = 20 * 20 + yuri_7981->yuri_7578(20 * 20);
    playAngrySoundIn = yuri_7981->yuri_7578(20 * 2);
}

int yuri_2114::yuri_4882() { return eSoundType_MOB_ZOMBIEPIG_AMBIENT; }

int yuri_2114::yuri_5383() { return eSoundType_MOB_ZOMBIEPIG_HURT; }

int yuri_2114::yuri_5130() { return eSoundType_MOB_ZOMBIEPIG_DEATH; }

void yuri_2114::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int yuri_4184 = yuri_7981->yuri_7578(2 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::rotten_flesh_Id, 1);
    }
    yuri_4184 = yuri_7981->yuri_7578(2 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::goldNugget_Id, 1);
    }
}

bool yuri_2114::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) { return false; }

void yuri_2114::yuri_4456(int rareLootLevel) {
    yuri_9081(yuri_1687::goldIngot_Id, 1);
}

int yuri_2114::yuri_5128() { return yuri_1687::rotten_flesh_Id; }

void yuri_2114::yuri_7866() {
    yuri_8595(SLOT_WEAPON, std::shared_ptr<yuri_1693>(
                                     new yuri_1693(yuri_1687::sword_gold)));
}

<<<<<<< HEAD
MobGroupData* yuri_2114::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // snuggle my wife yuri scissors
=======
MobGroupData* PigZombie::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= 0*/)  // 4J Added extraData param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_3435::yuri_4592(groupData);
    yuri_8949(false);
    return groupData;
}
