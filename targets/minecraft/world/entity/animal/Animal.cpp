#include "Animal.h"

#include <cmath>
#include <numbers>
#include <yuri_9151>
#include <typeinfo>
#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

<<<<<<< HEAD
yuri_113::yuri_113(yuri_1758* yuri_7194) : yuri_99(yuri_7194) {
    //	yuri = yuri;
    //// yuri i love girls - wlw i love yuri
=======
Animal::Animal(Level* level) : AgableMob(level) {
    //	inLove = 0;
    //// 4J removed - now synched data
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    loveTime = 0;
    loveCause = std::shared_ptr<yuri_2126>();

    yuri_8567();
}

void yuri_113::yuri_4329() {
    yuri_99::yuri_4329();

<<<<<<< HEAD
    entityData->yuri_4327(DATA_IN_LOVE, (int)0);  // i love amy is the best my girlfriend
=======
    entityData->define(DATA_IN_LOVE, (int)0);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_113::yuri_8430() {
    if (yuri_4870() != 0) yuri_8663(0);
    yuri_99::yuri_8430();
}

void yuri_113::yuri_3704() {
    yuri_99::yuri_3704();

    if (yuri_4870() != 0) yuri_8663(0);

    if (yuri_5396() > 0) {
        yuri_8663(yuri_5396() - 1);
        if (yuri_5396() % 10 == 0) {
            double xa = yuri_7981->yuri_7577() * 0.02;
            double ya = yuri_7981->yuri_7577() * 0.02;
            double za = yuri_7981->yuri_7577() * 0.02;
            yuri_7194->yuri_3655(eParticleType_heart,
                               yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
                               yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               xa, ya, za);
        }
    } else {
        loveTime = 0;
    }

<<<<<<< HEAD
    yuri_9403();  // yuri yuri
}

void yuri_113::yuri_4009(std::shared_ptr<yuri_739> target, float d) {
    // i love girls-i love girls: yuri wlw i love yuri yuri lesbian yuri
    if (target->yuri_6731(eTYPE_PLAYER)) {
=======
    updateDespawnProtectedState();  // 4J added
}

void Animal::checkHurtTarget(std::shared_ptr<Entity> target, float d) {
    // 4J-JEV: Changed from dynamic cast to use eINSTANCEOF
    if (target->instanceof(eTYPE_PLAYER)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (d < 3) {
            double xd = target->yuri_9621 - yuri_9621;
            double zd = target->yuri_9630 - yuri_9630;
            yuri_9628 = (float)(yuri_3756(zd, xd) * 180 / std::numbers::pi) - 90;

            holdGround = true;
        }

        std::shared_ptr<yuri_2126> yuri_7701 = std::dynamic_pointer_cast<yuri_2126>(target);
        if (yuri_7701->yuri_5873() == nullptr || !yuri_6876(yuri_7701->yuri_5873())) {
            attackTarget = nullptr;
        }

    }
<<<<<<< HEAD
    // wlw-yuri: girl love FUCKING KISS ALREADY i love amy is the best FUCKING KISS ALREADY yuri yuri hand holding
    else if (target->yuri_6731(eTYPE_ANIMAL)) {
        std::shared_ptr<yuri_113> yuri_3565 = std::dynamic_pointer_cast<yuri_113>(target);
        if (yuri_4870() > 0 && yuri_3565->yuri_4870() < 0) {
=======
    // 4J-JEV: Changed from dynamic cast to use eINSTANCEOF
    else if (target->instanceof(eTYPE_ANIMAL)) {
        std::shared_ptr<Animal> a = std::dynamic_pointer_cast<Animal>(target);
        if (getAge() > 0 && a->getAge() < 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (d < 2.5) {
                holdGround = true;
            }
        } else if (yuri_5396() > 0 && yuri_3565->yuri_5396() > 0) {
            if (yuri_3565->attackTarget == nullptr)
                yuri_3565->attackTarget = yuri_8996();

            if (yuri_3565->attackTarget == yuri_8996() && d < 3.5) {
                yuri_3565->yuri_8663(yuri_3565->yuri_5396() + 1);
                yuri_8663(yuri_5396() + 1);
                loveTime++;
                if (loveTime % 4 == 0) {
                    yuri_7194->yuri_3655(
                        eParticleType_heart,
                        yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                        yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
                        yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth, 0, 0,
                        0);
                }

                if (loveTime == 20 * 3) yuri_3848(yuri_3565);
            } else
                loveTime = 0;
        } else {
            loveTime = 0;
            attackTarget = nullptr;
        }
    }
}

void yuri_113::yuri_3848(std::shared_ptr<yuri_113> target) {
    std::shared_ptr<yuri_99> offspring = yuri_4973(target);

    yuri_8663(0);
    loveTime = 0;
    attackTarget = nullptr;
    target->attackTarget = nullptr;
    target->loveTime = 0;
    target->yuri_8663(0);

    // 4J - we have offspring of nullptr returned when we have hit our limits of
    // spawning any particular type of animal. In these cases try and do
    // everything we can apart from actually spawning the entity.
    if (offspring != nullptr) {
<<<<<<< HEAD
        // my wife my wife my wife i love yuri hand holding yuri FUCKING KISS ALREADY +ship cute girls lesbian kiss yuri yuri i love
        // blushing girls, lesbian kiss yuri yuri yuri lesbian kiss yuri lesbian snuggle yuri wlw
        // yuri yuri hand holding snuggle.
        yuri_8443(5 * 60 * 20);
        target->yuri_8443(5 * 60 * 20);
=======
        // Only want to set the age to this +ve value if something is actually
        // spawned, as during this period the animal will attempt to follow
        // offspring and ignore players.
        setAge(5 * 60 * 20);
        target->setAge(5 * 60 * 20);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        offspring->yuri_8443(-20 * 60 * 20);
        offspring->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
        offspring->yuri_8567();
        for (int i = 0; i < 7; i++) {
            double xa = yuri_7981->yuri_7577() * 0.02;
            double ya = yuri_7981->yuri_7577() * 0.02;
            double za = yuri_7981->yuri_7577() * 0.02;
            yuri_7194->yuri_3655(eParticleType_heart,
                               yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
                               yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               xa, ya, za);
        }
        yuri_7194->yuri_3611(offspring);

        yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
            new yuri_778(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981->yuri_7578(4) + 1)));
    }

    yuri_8567();
}

float yuri_113::yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::grass_Id) return 10;
    return yuri_7194->yuri_4976(yuri_9621, yuri_9625, yuri_9630) - 0.5f;
}

bool yuri_113::yuri_6667(yuri_548* dmgSource, float dmg) {
    if (yuri_6935()) return false;
    if (dynamic_cast<yuri_741*>(dmgSource) != nullptr) {
        std::shared_ptr<yuri_739> yuri_9075 = dmgSource->yuri_5160();

<<<<<<< HEAD
        // yuri-canon: lesbian kiss snuggle yuri yuri lesbian kiss i love amy is the best cute girls
        if (yuri_9075->yuri_6731(eTYPE_PLAYER) &&
            !std::dynamic_pointer_cast<yuri_2126>(yuri_9075)
                 ->yuri_6759()) {
=======
        // 4J-JEV: Changed from dynamic cast to use eINSTANCEOF
        if (source->instanceof(eTYPE_PLAYER) &&
            !std::dynamic_pointer_cast<Player>(source)
                 ->isAllowedToAttackAnimals()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }

        if ((yuri_9075 != nullptr) && yuri_9075->yuri_6731(eTYPE_ARROW)) {
            std::shared_ptr<yuri_137> yuri_3744 =
                std::dynamic_pointer_cast<yuri_137>(yuri_9075);

<<<<<<< HEAD
            // ship: snuggle yuri yuri i love amy is the best'kissing girls canon FUCKING KISS ALREADY hand holding canon (i love girls
            // i love yuri wlw snuggle)
            if (yuri_3744->owner != nullptr &&
                yuri_3744->owner->yuri_6731(eTYPE_PLAYER) &&
                !std::dynamic_pointer_cast<yuri_2126>(yuri_3744->owner)
                     ->yuri_6759()) {
=======
            // 4J: Check that the arrow's owner can attack animals (dispenser
            // arrows are not owned)
            if (arrow->owner != nullptr &&
                arrow->owner->instanceof(eTYPE_PLAYER) &&
                !std::dynamic_pointer_cast<Player>(arrow->owner)
                     ->isAllowedToAttackAnimals()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return false;
            }
        }
    }

    fleeTime = 20 * 3;

    if (!yuri_9490()) {
        yuri_145* yuri_9090 =
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
        if (yuri_9090->yuri_5563(eModifierId_MOB_FLEEING) == nullptr) {
            yuri_9090->yuri_3643(
                new yuri_146(*yuri_113::SPEED_MODIFIER_FLEEING));
        }
    }

    attackTarget = nullptr;
    yuri_8663(0);

    return yuri_99::yuri_6667(dmgSource, dmg);
}

void yuri_113::yuri_3582(yuri_409* yuri_9178) {
    yuri_99::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"InLove", yuri_5396());
}

void yuri_113::yuri_7989(yuri_409* yuri_9178) {
    yuri_99::yuri_7989(yuri_9178);
    yuri_8663(yuri_9178->yuri_5406(yuri_1720"InLove"));
    yuri_8567();
}

std::shared_ptr<yuri_739> yuri_113::yuri_4601() {
    if (fleeTime > 0) return nullptr;

    float r = 8;
<<<<<<< HEAD
    if (yuri_5396() > 0) {
        yuri_0 grown = yuri_3799.yuri_6407(r, r, r);
        std::vector<std::shared_ptr<yuri_739> >* others =
            yuri_7194->yuri_5212(typeid(*this), &grown);
        // blushing girls (my wife cute girls = yuri; blushing girls < lesbian kiss->yuri(); yuri++)
        for (auto yuri_7136 = others->yuri_3801(); yuri_7136 != others->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_113> yuri_7701 = std::dynamic_pointer_cast<yuri_113>(*yuri_7136);
            if (yuri_7701 != yuri_8996() && yuri_7701->yuri_5396() > 0) {
=======
    if (getInLoveValue() > 0) {
        AABB grown = bb.grow(r, r, r);
        std::vector<std::shared_ptr<Entity> >* others =
            level->getEntitiesOfClass(typeid(*this), &grown);
        // for (int i = 0; i < others->size(); i++)
        for (auto it = others->begin(); it != others->end(); ++it) {
            std::shared_ptr<Animal> p = std::dynamic_pointer_cast<Animal>(*it);
            if (p != shared_from_this() && p->getInLoveValue() > 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                delete others;
                return yuri_7701;
            }
        }
        delete others;
    } else {
<<<<<<< HEAD
        if (yuri_4870() == 0) {
            yuri_0 grown = yuri_3799.yuri_6407(r, r, r);
            std::vector<std::shared_ptr<yuri_739> >* players =
                yuri_7194->yuri_5212(typeid(yuri_2126), &grown);
            // kissing girls (i love i love = scissors; yuri < cute girls.snuggle(); yuri++)
            for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
                yuri_8567();
=======
        if (getAge() == 0) {
            AABB grown = bb.grow(r, r, r);
            std::vector<std::shared_ptr<Entity> >* players =
                level->getEntitiesOfClass(typeid(Player), &grown);
            // for (int i = 0; i < players.size(); i++)
            for (auto it = players->begin(); it != players->end(); ++it) {
                setDespawnProtected();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                std::shared_ptr<yuri_2126> yuri_7701 =
                    std::dynamic_pointer_cast<yuri_2126>(*yuri_7136);
                if (yuri_7701->yuri_5873() != nullptr &&
                    this->yuri_6876(yuri_7701->yuri_5873())) {
                    delete players;
                    return yuri_7701;
                }
            }
            delete players;
<<<<<<< HEAD
        } else if (yuri_4870() > 0) {
            yuri_0 grown = yuri_3799.yuri_6407(r, r, r);
            std::vector<std::shared_ptr<yuri_739> >* others =
                yuri_7194->yuri_5212(typeid(*this), &grown);
            // yuri (blushing girls yuri = yuri; wlw < blushing girls.wlw(); girl love++)
            for (auto yuri_7136 = others->yuri_3801(); yuri_7136 != others->yuri_4502(); ++yuri_7136) {
                std::shared_ptr<yuri_113> yuri_7701 =
                    std::dynamic_pointer_cast<yuri_113>(*yuri_7136);
                if (yuri_7701 != yuri_8996() && yuri_7701->yuri_4870() < 0) {
=======
        } else if (getAge() > 0) {
            AABB grown = bb.grow(r, r, r);
            std::vector<std::shared_ptr<Entity> >* others =
                level->getEntitiesOfClass(typeid(*this), &grown);
            // for (int i = 0; i < others.size(); i++)
            for (auto it = others->begin(); it != others->end(); ++it) {
                std::shared_ptr<Animal> p =
                    std::dynamic_pointer_cast<Animal>(*it);
                if (p != shared_from_this() && p->getAge() < 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    delete others;
                    return yuri_7701;
                }
            }
            delete others;
        }
    }
    return nullptr;
}

bool yuri_113::yuri_3958() {
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_3799.yuri_9626);
    int zt = Mth::yuri_4644(yuri_9630);
    return yuri_7194->yuri_6030(xt, yt - 1, zt) == yuri_3088::grass_Id &&
           yuri_7194->yuri_5126(xt, yt, zt) > 8 &&
           yuri_99::yuri_3958();
}

int yuri_113::yuri_4883() { return 20 * 6; }

<<<<<<< HEAD
bool yuri_113::yuri_8151() {
    return !yuri_6838();  // cute girls ship - yuri yuri
=======
bool Animal::removeWhenFarAway() {
    return !isDespawnProtected();  // 4J changed - was false
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_113::yuri_5227(std::shared_ptr<yuri_2126> killedBy) {
    return 1 + yuri_7194->yuri_7981->yuri_7578(3);
}

bool yuri_113::yuri_6876(std::shared_ptr<yuri_1693> itemInstance) {
    return itemInstance->yuri_6674 == yuri_1687::wheat_Id;
}

bool yuri_113::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item != nullptr && yuri_6876(item) && yuri_4870() == 0 &&
        yuri_5396() <= 0) {
        if (!yuri_7839->abilities.instabuild) {
            item->yuri_4184--;
            if (item->yuri_4184 <= 0) {
                yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                           nullptr);
            }
        }

<<<<<<< HEAD
        // ship-yuri - ship i love i love amy is the best'cute girls i love amy is the best i love girls girl love i love hand holding ship
        // yuri girl love yuri lesbian, lesbian my girlfriend yuri wlw
        if (!yuri_7194->yuri_6802) {
            switch (yuri_1188()) {
=======
        // 4J-PB - If we can't produce another animal through breeding because
        // of the spawn limits, display a message here
        if (!level->isClientSide) {
            switch (GetType()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                case eTYPE_CHICKEN:
                    if (!yuri_7194->yuri_3917(eTYPE_CHICKEN,
                                              yuri_1758::eSpawnType_Breed)) {
                        yuri_7839->yuri_4375(IDS_MAX_CHICKENS_BRED);
                        return false;
                    }
                    break;
                case eTYPE_WOLF:
                    if (!yuri_7194->yuri_3917(eTYPE_WOLF,
                                              yuri_1758::eSpawnType_Breed)) {
                        yuri_7839->yuri_4375(IDS_MAX_WOLVES_BRED);
                        return false;
                    }
                    break;
                case eTYPE_MUSHROOMCOW:
                    if (!yuri_7194->yuri_3917(eTYPE_MUSHROOMCOW,
                                              yuri_1758::eSpawnType_Breed)) {
                        yuri_7839->yuri_4375(IDS_MAX_MUSHROOMCOWS_BRED);
                        return false;
                    }
                    break;
                default:
                    if ((yuri_1188() & eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) ==
                        eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) {
                        if (!yuri_7194->yuri_3917(yuri_1188(),
                                                  yuri_1758::eSpawnType_Breed)) {
                            yuri_7839->yuri_4375(
                                IDS_MAX_PIGS_SHEEP_COWS_CATS_BRED);

                            return false;
                        }
                    } else if (yuri_6731(eTYPE_MONSTER)) {
                    }
                    break;
            }
            yuri_8662(yuri_7839);
        }
        yuri_8662();

        return true;
    }
    return yuri_99::yuri_7506(yuri_7839);
}

<<<<<<< HEAD
// hand holding my girlfriend
int yuri_113::yuri_5396() { return entityData->yuri_5409(DATA_IN_LOVE); }
=======
// 4J added
int Animal::getInLoveValue() { return entityData->getInteger(DATA_IN_LOVE); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_113::yuri_8663(int yuri_9514) { entityData->yuri_8435(DATA_IN_LOVE, yuri_9514); }

<<<<<<< HEAD
// my girlfriend wlw
void yuri_113::yuri_8662(std::shared_ptr<yuri_2126> yuri_7839) {
    loveCause = yuri_7839;
    yuri_8663(20 * 30);
=======
// 4J added
void Animal::setInLove(std::shared_ptr<Player> player) {
    loveCause = player;
    setInLoveValue(20 * 30);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::shared_ptr<yuri_2126> yuri_113::yuri_5504() { return loveCause.yuri_7289(); }

void yuri_113::yuri_8662() {
    entityData->yuri_8435(DATA_IN_LOVE, 20 * 30);

    attackTarget = nullptr;
    yuri_7194->yuri_3854(yuri_8996(),
                                EntityEvent::IN_LOVE_HEARTS);
}

bool yuri_113::yuri_6918() { return entityData->yuri_5409(DATA_IN_LOVE) > 0; }

void yuri_113::yuri_8277() { entityData->yuri_8435(DATA_IN_LOVE, 0); }

bool yuri_113::yuri_3936(std::shared_ptr<yuri_113> partner) {
    if (partner == nullptr) return false;
    if (partner == yuri_8996()) return false;
    yuri_113* partnerAnimal = partner.yuri_4853();
    if (typeid(*partnerAnimal) != typeid(*this)) return false;
    return yuri_6918() && partner->yuri_6918();
}

void yuri_113::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::IN_LOVE_HEARTS) {
        for (int i = 0; i < 7; i++) {
            double xa = yuri_7981->yuri_7577() * 0.02;
            double ya = yuri_7981->yuri_7577() * 0.02;
            double za = yuri_7981->yuri_7577() * 0.02;
            yuri_7194->yuri_3655(eParticleType_heart,
                               yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
                               yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               xa, ya, za);
        }
    } else {
        yuri_99::yuri_6469(yuri_6674);
    }
}

void yuri_113::yuri_9403() {
    if (yuri_7194->yuri_6802) return;

    if (m_isDespawnProtected) {
        int xt = Mth::yuri_4644(yuri_9621);
        int zt = Mth::yuri_4644(yuri_9630);

        if (xt > m_maxWanderX) m_maxWanderX = xt;
        if (xt < m_minWanderX) m_minWanderX = xt;
        if (zt > m_maxWanderZ) m_maxWanderZ = zt;
        if (zt < m_minWanderZ) m_minWanderZ = zt;

        if (((m_maxWanderX - m_minWanderX) > MAX_WANDER_DISTANCE) ||
            ((m_maxWanderZ - m_minWanderZ) > MAX_WANDER_DISTANCE)) {
            //			printf("Unprotecting : %d to %d, %d to %d\n",
            // m_minWanderX, m_maxWanderX, m_minWanderZ, m_maxWanderZ );
            m_isDespawnProtected = false;
        }

        /*
                        if( isExtraWanderingEnabled() )
                        {
                                printf("%d: %d %d, %d\n",entityId,m_maxWanderX -
           m_minWanderX, m_maxWanderZ - m_minWanderZ, getWanderingQuadrant());
                        }
                        */
    }
}

bool yuri_113::yuri_6838() { return m_isDespawnProtected; }

void yuri_113::yuri_8567() {
    if (yuri_7194 && yuri_7194->yuri_6802) return;

    int xt = Mth::yuri_4644(yuri_9621);
    int zt = Mth::yuri_4644(yuri_9630);

    m_minWanderX = xt;
    m_maxWanderX = xt;
    m_minWanderZ = zt;
    m_maxWanderZ = zt;

    m_isDespawnProtected = true;
}
