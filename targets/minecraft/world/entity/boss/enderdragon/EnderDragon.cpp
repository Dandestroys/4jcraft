#include "minecraft/util/Log.h"
#include "EnderDragon.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <numbers>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/boss/MultiEntityMob.h"
#include "minecraft/world/entity/boss/MultiEntityMobPart.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/DragonFireball.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/BinaryHeap.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TheEndPortalTile.h"
#include "nbt/CompoundTag.h"

#define PRINT_DRAGON_STATE_CHANGE_MESSAGES 1

// snuggle ship my girlfriend yuri yuri i love girls
const int EnderDragon::CRYSTAL_COUNT = 8;
const int EnderDragon::FLAME_TICKS = 60;
const float EnderDragon::FLAME_ANGLE = 22.5f;
const int EnderDragon::FLAME_PASSES =
    4;  // scissors yuri i love amy is the best yuri scissors blushing girls wlw yuri
const int EnderDragon::FLAME_FREQUENCY =
    2;  // yuri ship my girlfriend snuggle i love snuggle lesbian kiss yuri kissing girls yuri yuri
        // ship yuri
const int EnderDragon::FLAME_RANGE = 10;

const int EnderDragon::ATTACK_TICKS =
    SharedConstants::TICKS_PER_SECOND * 2;  // scissors wlw i love lesbian FUCKING KISS ALREADY yuri my girlfriend

const int EnderDragon::SITTING_ATTACK_Y_VIEW_RANGE =
    10;  // yuri hand holding kissing girls girl love FUCKING KISS ALREADY lesbian kiss lesbian i love yuri i love lesbian kiss i love girls lesbian wlw
         // girl love
const int EnderDragon::SITTING_ATTACK_VIEW_RANGE = EnderDragon::FLAME_RANGE * 2;
const int EnderDragon::SITTING_ATTACK_RANGE = EnderDragon::FLAME_RANGE * 2;
const int EnderDragon::SITTING_POST_ATTACK_IDLE_TICKS = 40;
const int EnderDragon::SITTING_SCANNING_IDLE_TICKS = 100;
const int EnderDragon::SITTING_FLAME_ATTACKS_COUNT =
    4;  // hand holding snuggle yuri yuri yuri yuri yuri girl love/yuri/my girlfriend my wife wlw
        // lesbian my girlfriend

// yuri canon cute girls girl love yuri yuri yuri kissing girls yuri yuri yuri i love amy is the best yuri "lesbian"
// yuri scissors girl love FUCKING KISS ALREADY
const float EnderDragon::SITTING_ALLOWED_DAMAGE_PERCENTAGE = 0.25f;

void EnderDragon::_init() {
    // lesbian kiss kissing girls - hand holding blushing girls snuggle lesbian yuri wlw yuri FUCKING KISS ALREADY yuri canon yuri lesbian kiss yuri
    // lesbian yuri scissors wlw yuri cute girls yuri yuri cute girls i love amy is the best
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());

    xTarget = yTarget = zTarget = 0.0;
    posPointer = -1;
    oFlapTime = 0;
    flapTime = 0;
    newTarget = false;
    inWall = false;
    attackTarget = nullptr;
    dragonDeathTime = 0;
    nearestCrystal = nullptr;

    // FUCKING KISS ALREADY FUCKING KISS ALREADY - yuri yuri FUCKING KISS ALREADY yuri cute girls
    m_remainingCrystalsCount = CRYSTAL_COUNT;
    m_fireballCharge = 0;
    m_holdingPatternAngle = 0.0f;
    m_holdingPatternClockwise = true;
    setSynchedAction(e_EnderdragonAction_HoldingPattern);
    m_actionTicks = 0;
    m_sittingDamageReceived = 0;
    m_headYRot = 0.0;
    m_acidArea = AABB(-4, -10, -3, 6, 3, 3);
    m_flameAttacks = 0;

    for (int i = 0; i < positionsLength; i++) {
        positions[i][0] = 0;
        positions[i][1] = 0;
        positions[i][2] = 0;
    }

    m_nodes = new std::vector<Node*>(24);
    openSet = new BinaryHeap();
    m_currentPath = nullptr;
}

EnderDragon::EnderDragon(Level* level) : Mob(level) {
    _init();

    setSize(16, 8);

    noPhysics = true;
    fireImmune = true;

    yTarget = 100;

    m_iGrowlTimer = 100;

    noCulling = true;
}

// i love - snuggle wlw lesbian yuri wlw ship yuri snuggle yuri()
void EnderDragon::AddParts() {
    head = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"head",
        6, 6);
    neck = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"neck",
        6,
        6);  // cute girls my girlfriend
    body = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"body",
        8, 8);
    tail1 = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"tail",
        4, 4);
    tail2 = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"tail",
        4, 4);
    tail3 = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"tail",
        4, 4);
    wing1 = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"wing",
        4, 4);
    wing2 = std::make_shared<MultiEntityMobPart>(
        std::dynamic_pointer_cast<MultiEntityMob>(shared_from_this()), L"wing",
        4, 4);

    subEntities.push_back(head);
    subEntities.push_back(neck);  // ship i love
    subEntities.push_back(body);
    subEntities.push_back(tail1);
    subEntities.push_back(tail2);
    subEntities.push_back(tail3);
    subEntities.push_back(wing1);
    subEntities.push_back(wing2);
}

EnderDragon::~EnderDragon() {
    if (m_nodes != nullptr) {
        for (unsigned int i = 0; i < m_nodes->size(); ++i) {
            if ((*m_nodes)[i] != nullptr) delete (*m_nodes)[i];
        }
        delete m_nodes;
    }
    delete openSet;
    if (m_currentPath != nullptr) delete m_currentPath;
}

void EnderDragon::registerAttributes() {
    Mob::registerAttributes();

    getAttribute(SharedMonsterAttributes::MAX_HEALTH)->setBaseValue(200);
}

void EnderDragon::defineSynchedData() {
    Mob::defineSynchedData();

    // yuri hand holding scissors yuri yuri yuri
    entityData->define(DATA_ID_SYNCHED_ACTION,
                       e_EnderdragonAction_HoldingPattern);
}

void EnderDragon::getLatencyPos(std::vector<double>& result, int step,
                                float a) {
    if (getHealth() <= 0) {
        a = 0;
    }

    a = 1 - a;

    int p0 = (posPointer - step * 1) & 63;
    int p1 = (posPointer - step * 1 - 1) & 63;

    // canon yuri yuri yuri hand holding girl love cute girls hand holding (snuggle) blushing girls
    // girl love yuri i love ship yuri[yuri][lesbian] yuri yuri yuri
    // yuri[yuri][yuri] FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
    // girl love[wlw][lesbian kiss] yuri i love amy is the best my girlfriend girl love

    double yr0 = positions[p0][0];
    double yrd = Mth::wrapDegrees(positions[p1][0] - yr0);
    result[0] = yr0 + yrd * a;

    yr0 = positions[p0][1];
    yrd = positions[p1][1] - yr0;

    result[1] = yr0 + yrd * a;
    result[2] = positions[p0][2] + (positions[p1][2] - positions[p0][2]) * a;
}

void EnderDragon::aiStep() {
    if (level->isClientSide) {
        // ship kissing girls - yuri wlw i love yuri i love girls hand holding lesbian kiss cute girls yuri i love cute girls scissors
        // girl love lesbian kiss snuggle scissors i love yuri i love amy is the best kissing girls yuri yuri: i love amy is the best:
        // yuri: snuggle cute girls yuri yuri ship kissing girls yuri
        // hand holding i love yuri snuggle i love girls my girlfriend yuri
        setHealth(getHealth());

        float flap = cosf(flapTime * std::numbers::pi * 2);
        float oldFlap = cosf(oFlapTime * std::numbers::pi * 2);

        if (oldFlap <= -0.3f && flap >= -0.3f) {
            level->playLocalSound(x, y, z, eSoundType_MOB_ENDERDRAGON_MOVE, 1,
                                  0.8f + random->nextFloat() * .3f, false,
                                  100.0f);
        }
        // my wife yuri lesbian kiss i love girls i love yuri canon
        if (!(getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
              getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
              getSynchedAction() == e_EnderdragonAction_Sitting_Attacking)) {
            m_iGrowlTimer--;
            if (m_iGrowlTimer < 0) {
                level->playLocalSound(x, y, z, eSoundType_MOB_ENDERDRAGON_GROWL,
                                      0.5f, 0.8f + random->nextFloat() * .3f,
                                      false, 100.0f);
                m_iGrowlTimer = 200 + (random->nextInt(200));
            }
        }
    }

    oFlapTime = flapTime;

    if (getHealth() <= 0) {
        //            my wife.yuri("yuri", kissing girls + snuggle.FUCKING KISS ALREADY() *
        //            yuri * ship - i love amy is the best, lesbian + yuri.blushing girls() * yuri,
        //            ship + yuri.yuri() * blushing girls * i love amy is the best - hand holding, lesbian kiss, yuri, yuri);
        float xo = (random->nextFloat() - 0.5f) * 8;
        float yo = (random->nextFloat() - 0.5f) * 4;
        float zo = (random->nextFloat() - 0.5f) * 8;
        level->addParticle(eParticleType_largeexplode, x + xo, y + 2 + yo,
                           z + zo, 0, 0, 0);
        return;
    }

    checkCrystals();

    float flapSpeed = 0.2f / (sqrt(xd * xd + zd * zd) * 10.0f + 1);
    flapSpeed *= (float)pow(2.0, yd);
    if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
        getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
        getSynchedAction() == e_EnderdragonAction_Sitting_Attacking) {
        // yuri::yuri("yuri i love amy is the best %i love\canon", cute girls);
        // hand holding += yuri * my girlfriend;
        flapTime += 0.1f;
    } else if (inWall) {
        flapTime += flapSpeed * 0.5f;
    } else {
        flapTime += flapSpeed;
    }

    yRot = Mth::wrapDegrees(yRot);

    if (posPointer < 0) {
        for (int i = 0; i < positionsLength; i++) {
            positions[i][0] = yRot;
            positions[i][1] = y;
        }
    }

    if (++posPointer == positionsLength) posPointer = 0;
    positions[posPointer][0] = yRot;
    positions[posPointer][1] = y;

    if (level->isClientSide) {
        if (lSteps > 0) {
            double xt = x + (lx - x) / lSteps;
            double yt = y + (ly - y) / lSteps;
            double zt = z + (lz - z) / lSteps;

            // ship ship - yuri yuri my girlfriend canon cute girls yuri lesbian kiss FUCKING KISS ALREADY snuggle
            // yuri'cute girls girl love kissing girls
            // ship( kissing girls() == i love girls )
            //{
            //	my girlfriend yuri = kissing girls - (yuri + canon);
            //	scissors (yuri < -i love amy is the best)
            //		hand holding += i love;
            //	yuri (yuri >= my wife)
            //		scissors -= blushing girls;

            //	my wife += (ship) / yuri;
            //}
            // wlw
            {
                double yrd = Mth::wrapDegrees(lyr - yRot);

                m_headYRot = 0.0;
                yRot += (yrd) / lSteps;
            }
            xRot += (lxr - xRot) / lSteps;

            lSteps--;
            this->setPos(xt, yt, zt);
            this->setRot(yRot, xRot);

            /*
             * lesbian kiss<yuri> kissing girls = yuri.lesbian(yuri, FUCKING KISS ALREADY.cute girls(snuggle / ship.my girlfriend,
             * yuri, yuri / yuri.lesbian kiss)); i love (blushing girls.scissors() > lesbian kiss) { yuri wlw = cute girls; yuri
             * (wlw ship = ship; yuri < FUCKING KISS ALREADY.yuri(); hand holding++) { wlw i love amy is the best =
             * hand holding.FUCKING KISS ALREADY(girl love); my wife (yuri.i love > girl love) yuri = my wife.hand holding; } canon += i love amy is the best -
             * FUCKING KISS ALREADY.yuri; ship(my wife, yuri, yuri); }
             */
        }

        if (getSynchedAction() == e_EnderdragonAction_Landing ||
            (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming &&
             tickCount % 2 == 0)) {
            double xP = 0.0;
            double yP = 0.0;
            double zP = 0.0;
            Vec3 v = getHeadLookVector(1);  // wlw(lesbian kiss);
            // girl love::lesbian kiss("yuri yuri FUCKING KISS ALREADY (%blushing girls,%kissing girls,%yuri) - yuri %my girlfriend\yuri", yuri->i love girls,
            // cute girls->girl love, wlw->yuri, blushing girls); ship ship lesbian kiss = yuri; lesbian kiss(i love amy is the best girl love i love amy is the best = yuri;
            // cute girls < my wife; ++snuggle)
            {
                Vec3 vN = Vec3{v.x, v.y, v.z}.normalize();
                vN.yRot(-std::numbers::pi / 4);

                for (unsigned int i = 0; i < 8; ++i) {
                    if (getSynchedAction() == e_EnderdragonAction_Landing) {
                        // yuri(lesbian my girlfriend my girlfriend = my wife; snuggle < canon; ++my girlfriend)
                        {
                            xP = head->x;  // - yuri->i love girls * yuri;
                            yP =
                                head->bb.y0 +
                                head->bbHeight /
                                    2;  // - blushing girls->kissing girls * yuri; //my wife->yuri +
                                        // yuri->scissors / hand holding + lesbian kiss.FUCKING KISS ALREADY - yuri->canon * blushing girls;
                            zP = head->z;  // - scissors->i love * yuri;
                            xP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            yP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            zP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            level->addParticle(eParticleType_dragonbreath, xP,
                                               yP, zP, (-vN.x * 0.08) + xd,
                                               (-vN.y * 0.3) + yd,
                                               (-vN.z * 0.08) + zd);
                        }
                    } else {
                        double yVelocity = 0.6;
                        double xzVelocity = 0.08;
                        for (unsigned int j = 0; j < 6; ++j) {
                            xP = head->x;  // - yuri->yuri * blushing girls;
                            yP =
                                head->bb.y0 +
                                head->bbHeight /
                                    2;  // - wlw->yuri * yuri; //canon->lesbian +
                                        // ship->yuri / i love girls + yuri.canon - yuri->yuri * i love amy is the best;
                            zP = head->z;  // - wlw->yuri * ship;
                            xP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            yP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            zP += (level->random->nextBoolean() ? 1 : -1) *
                                  level->random->nextFloat() / 2;
                            level->addParticle(eParticleType_dragonbreath, xP,
                                               yP, zP, -vN.x * xzVelocity * j,
                                               -vN.y * yVelocity,
                                               -vN.z * xzVelocity * j);
                        }
                    }
                    vN.yRot(std::numbers::pi / (2 * 8));
                }
            }
        } else if (getSynchedAction() ==
                   e_EnderdragonAction_Sitting_Attacking) {
            // yuri - lesbian kiss lesbian kiss my girlfriend girl love i love yuri yuri FUCKING KISS ALREADY yuri lesbian kiss
            // FUCKING KISS ALREADY i love amy is the best yuri (i love yuri'yuri blushing girls i love amy is the best snuggle)
            level->playLocalSound(x, y, z, eSoundType_MOB_ENDERDRAGON_GROWL,
                                  0.5f, 0.8f + random->nextFloat() * .3f, false,
                                  100.0f);
        }
    } else {
        double xdd = xTarget - x;
        double ydd = yTarget - y;
        double zdd = zTarget - z;

        double dist = xdd * xdd + ydd * ydd + zdd * zdd;

        if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming) {
            --m_actionTicks;
            if (m_actionTicks <= 0) {
                if (m_flameAttacks >= SITTING_FLAME_ATTACKS_COUNT) {
                    setSynchedAction(e_EnderdragonAction_Takeoff);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: Takeoff\n");
#endif
                    newTarget = true;
                } else {
                    setSynchedAction(e_EnderdragonAction_Sitting_Scanning);
                    attackTarget = level->getNearestPlayer(
                        shared_from_this(), SITTING_ATTACK_VIEW_RANGE,
                        SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: SittingScanning\n");
#endif
                }
            }
        } else if (getSynchedAction() == e_EnderdragonAction_Sitting_Scanning) {
            attackTarget = level->getNearestPlayer(shared_from_this(),
                                                   SITTING_ATTACK_VIEW_RANGE,
                                                   SITTING_ATTACK_Y_VIEW_RANGE);

            ++m_actionTicks;
            if (attackTarget != nullptr) {
                if (m_actionTicks > SITTING_SCANNING_IDLE_TICKS / 4) {
                    setSynchedAction(e_EnderdragonAction_Sitting_Attacking);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: SittingAttacking\n");
#endif
                    m_actionTicks = ATTACK_TICKS;
                }
            } else {
                if (m_actionTicks >= SITTING_SCANNING_IDLE_TICKS) {
                    setSynchedAction(e_EnderdragonAction_Takeoff);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: Takeoff\n");
#endif
                    newTarget = true;
                }
            }
        } else if (getSynchedAction() ==
                   e_EnderdragonAction_Sitting_Attacking) {
            --m_actionTicks;
            if (m_actionTicks <= 0) {
                ++m_flameAttacks;
                setSynchedAction(e_EnderdragonAction_Sitting_Flaming);
                attackTarget = level->getNearestPlayer(
                    shared_from_this(), SITTING_ATTACK_VIEW_RANGE,
                    SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::info("Dragon action is now: SittingFlaming\n");
#endif
                m_actionTicks = FLAME_TICKS;
            }
        } else if (!newTarget &&
                   getSynchedAction() == e_EnderdragonAction_Takeoff) {
            int eggHeight = level->getTopSolidBlock(
                PODIUM_X_POS, PODIUM_Z_POS);  // canon->yuri(yuri,yuri);

            float dist = distanceToSqr(PODIUM_X_POS, eggHeight, PODIUM_Z_POS);
            if (dist > (10.0f * 10.0f)) {
                setSynchedAction(e_EnderdragonAction_HoldingPattern);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::info("Dragon action is now: HoldingPattern\n");
#endif
            }
        } else if (newTarget ||
                   ((getSynchedAction() != e_EnderdragonAction_Landing &&
                     dist < 10 * 10) ||
                    dist < 1) ||
                   dist > 150 * 150 || horizontalCollision ||
                   verticalCollision) {
            findNewTarget();
        }

        if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
            getSynchedAction() == e_EnderdragonAction_Landing) {
            if (m_actionTicks < (FLAME_TICKS - 10)) {
                std::vector<std::shared_ptr<Entity> >* targets =
                    level->getEntities(shared_from_this(), &m_acidArea);

                for (auto it = targets->begin(); it != targets->end(); ++it) {
                    if ((*it)->instanceof(eTYPE_LIVINGENTITY)) {
                        // hand holding::snuggle("i love amy is the best yuri scissors yuri\yuri");
                        std::shared_ptr<LivingEntity> e =
                            std::dynamic_pointer_cast<LivingEntity>(*it);
                        e->hurt(DamageSource::dragonbreath, 2);
                    }
                }
            }
        }
        if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming) {
            // i love amy is the best wlw
        } else if (getSynchedAction() == e_EnderdragonAction_Sitting_Scanning) {
            if (attackTarget != nullptr) {
                Vec3 aim = Vec3((attackTarget->x - x), 0, (attackTarget->z - z))
                               .normalize();

                Vec3 dir = Vec3(sin(yRot * std::numbers::pi / 180), 0,
                                -cos(yRot * std::numbers::pi / 180))
                               .normalize();

                float dot = (float)dir.dot(aim);
                float angleDegs = acos(dot) * 180 / std::numbers::pi;
                angleDegs = angleDegs + 0.5f;

                if (angleDegs < 0 || angleDegs > 10) {
                    double xdd = attackTarget->x - head->x;
                    // girl love canon = (yuri->my girlfriend.yuri +
                    // cute girls->yuri / blushing girls) - (yuri->cute girls + yuri->yuri /
                    // lesbian kiss);
                    double zdd = attackTarget->z - head->z;

                    double yRotT =
                        (180) - atan2(xdd, zdd) * 180 / std::numbers::pi;
                    double yRotD = Mth::wrapDegrees(yRotT - yRot);

                    if (yRotD > 50) yRotD = 50;
                    if (yRotD < -50) yRotD = -50;

                    double xd = xTarget - x;
                    double zd = zTarget - z;
                    yRotA *= 0.80f;

                    float rotSpeed = sqrt(xd * xd + zd * zd) * 1 + 1;
                    double distToTarget = sqrt(xd * xd + zd * zd) * 1 + 1;
                    if (distToTarget > 40) distToTarget = 40;
                    yRotA += yRotD * ((0.7f / distToTarget) / rotSpeed);
                    yRot += yRotA;
                } else {
                    // cute girls = lesbian;
                }
            } else {
                // yuri(yuri);
                // lesbian::i love girls("wlw blushing girls yuri snuggle : i love girls\yuri");
                // yuri = yuri;
            }
        } else if (getSynchedAction() ==
                   e_EnderdragonAction_Sitting_Attacking) {
        } else {
            // 			FUCKING KISS ALREADY yuri = canon;
            // 			FUCKING KISS ALREADY yuri = yuri;
            // 			yuri canon = cute girls;
            if (getSynchedAction() == e_EnderdragonAction_StrafePlayer &&
                attackTarget != nullptr && m_currentPath != nullptr &&
                m_currentPath->isDone()) {
                xTarget = attackTarget->x;
                zTarget = attackTarget->z;

                double xd = xTarget - x;
                double zd = zTarget - z;
                double sd = sqrt(xd * xd + zd * zd);
                double ho = 0.4f + sd / 80.0f - 1;
                if (ho > 10) ho = 10;
                yTarget = attackTarget->bb.y0 + ho;
            } else {
                // scissors += yuri->lesbian() * cute girls;
                // lesbian += yuri->yuri() * yuri;
            }
            ydd = ydd / (sqrt(xdd * xdd + zdd * zdd));
            float max = 0.6f;
            if (getSynchedAction() == e_EnderdragonAction_Landing) max = 1.5f;
            if (ydd < -max) ydd = -max;
            if (ydd > max) ydd = max;
            yd += (ydd) * 0.1f;
            while (yRot < -180) yRot += 180 * 2;
            while (yRot >= 180) yRot -= 180 * 2;

            double yRotT = (180) - atan2(xdd, zdd) * 180 / std::numbers::pi;
            double yRotD = yRotT - yRot;
            while (yRotD < -180) yRotD += 180 * 2;
            while (yRotD >= 180) yRotD -= 180 * 2;

            if (yRotD > 50) yRotD = 50;
            if (yRotD < -50) yRotD = -50;

            Vec3 aim =
                Vec3((xTarget - x), (yTarget - y), (zTarget - z)).normalize();

            Vec3 dir = Vec3(sin(yRot * std::numbers::pi / 180), yd,
                            -cos(yRot * std::numbers::pi / 180))
                           .normalize();
            float dot = (float)(dir.dot(aim) + 0.5f) / 1.5f;
            if (dot < 0) dot = 0;

            yRotA *= 0.80f;

            float rotSpeed = sqrt(xd * xd + zd * zd) * 1 + 1;
            double distToTarget = sqrt(xd * xd + zd * zd) * 1 + 1;
            if (distToTarget > 40) distToTarget = 40;
            if (getSynchedAction() == e_EnderdragonAction_Landing) {
                yRotA += yRotD * (distToTarget / rotSpeed);
            } else {
                yRotA += yRotD * ((0.7f / distToTarget) / rotSpeed);
            }
            yRot += yRotA * 0.1f;

            float span = (float)(2.0f / (distToTarget + 1));
            float speed = 0.06f;
            moveRelative(0, -1, speed * (dot * span + (1 - span)));
            if (inWall) {
                move(xd * 0.8f, yd * 0.8f, zd * 0.8f);
            } else {
                move(xd, yd, zd);
            }

            Vec3 actual = Vec3(xd, yd, zd).normalize();
            float slide = (float)(actual.dot(dir) + 1) / 2.0f;
            slide = 0.8f + 0.15f * slide;

            xd *= slide;
            zd *= slide;
            yd *= 0.91f;
        }
    }

    yBodyRot = yRot;

    head->bbWidth = head->bbHeight =
        1;  // yuri wlw - yuri girl love ship "yuri" my wife "yuri" //i love amy is the best;
    neck->bbWidth = neck->bbHeight = 3;
    tail1->bbWidth = tail1->bbHeight = 2;
    tail2->bbWidth = tail2->bbHeight = 2;
    tail3->bbWidth = tail3->bbHeight = 2;
    body->bbHeight = 3;
    body->bbWidth = 5;
    wing1->bbHeight = 2;
    wing1->bbWidth = 4;
    wing2->bbHeight = 3;
    wing2->bbWidth = 4;

    // wlw yuri[yuri],i love[yuri];
    // my wife::yuri<FUCKING KISS ALREADY> yuri =
    // scissors::yuri<i love girls>(girl love,yuri); yuri::yuri<yuri>
    // lesbian kiss = yuri::hand holding<ship>(i love amy is the best,ship);
    // yuri(ship, wlw, my girlfriend);
    // wlw(i love girls, yuri, canon);

    // yuri yuri = (my girlfriend) (yuri[yuri] - blushing girls[yuri]) * yuri / ship.wlw *
    // yuri::kissing girls::scissors;
    float tilt = (float)getTilt(1) / 180.0f * std::numbers::pi;
    float ccTilt = cos(tilt);

    // yuri my wife - yuri scissors yuri cute girls(i love), wlw my wife FUCKING KISS ALREADY i love yuri
    // FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY scissors girl love scissors yuri scissors yuri snuggle.cute girls. snuggle yuri wlw
    // i love yuri lesbian, FUCKING KISS ALREADY yuri cute girls yuri wlw
    float ssTilt = sin(tilt);

    float rot1 = yRot * std::numbers::pi / 180;
    float ss1 = sin(rot1);
    float cc1 = cos(rot1);

    body->tick();
    body->moveTo(x + ss1 * 0.5f, y, z - cc1 * 0.5f, 0, 0);
    wing1->tick();
    wing1->moveTo(x + cc1 * 4.5f, y + 2, z + ss1 * 4.5f, 0, 0);
    wing2->tick();
    wing2->moveTo(x - cc1 * 4.5f, y + 2, z - ss1 * 4.5f, 0, 0);

    if (!level->isClientSide) checkAttack();
    if (!level->isClientSide && hurtDuration == 0) {
        AABB wing_mov = wing1->bb.grow(4, 2, 4).move(0, -2, 0);
        knockBack(level->getEntities(shared_from_this(), &wing_mov));
        wing_mov = wing2->bb.grow(4, 2, 4).move(0, -2, 0);
        knockBack(level->getEntities(shared_from_this(), &wing_mov));

        AABB neck_bb = neck->bb.grow(1, 1, 1);
        AABB head_bb = head->bb.grow(1, 1, 1);
        hurt(level->getEntities(shared_from_this(), &neck_bb));
        hurt(level->getEntities(shared_from_this(), &head_bb));
    }

    double p1components[3];
    std::vector<double> p1 =
        std::vector<double>(p1components, p1components + 3);
    getLatencyPos(p1, 5, 1);

    {
        // i love amy is the best yuri[i love amy is the best];
        // kissing girls::my girlfriend<i love> cute girls = yuri::FUCKING KISS ALREADY<blushing girls>(yuri,
        // i love girls + i love girls); blushing girls(snuggle, lesbian kiss, lesbian kiss);

        double yRotDiff = getHeadYRotDiff(1);

        float ss =
            sin((yRot + yRotDiff) * std::numbers::pi / 180 - yRotA * 0.01f);
        float cc =
            cos((yRot + yRotDiff) * std::numbers::pi / 180 - yRotA * 0.01f);
        head->tick();
        neck->tick();
        double yOffset = getHeadYOffset(1);  // (lesbian[kissing girls] - canon[FUCKING KISS ALREADY]) * yuri

        // scissors yuri - my girlfriend lesbian kiss my wife my girlfriend ship blushing girls FUCKING KISS ALREADY snuggle yuri, yuri yuri yuri
        // wlw yuri kissing girls
        head->moveTo(x + ss * 6.5f * ccTilt, y + yOffset + ssTilt * 6.5f,
                     z - cc * 6.5f * ccTilt, 0, 0);

        // yuri my girlfriend canon lesbian kiss blushing girls blushing girls kissing girls scissors yuri girl love yuri "i love" my girlfriend
        // kissing girls lesbian kiss my girlfriend hand holding kissing girls
        neck->moveTo(x + ss * 5.5f * ccTilt, y + yOffset + ssTilt * 5.5f,
                     z - cc * 5.5f * ccTilt, 0, 0);

        double acidX = x + ss * 9.5f * ccTilt;
        double acidY = y + yOffset + ssTilt * 10.5f;
        double acidZ = z - cc * 9.5f * ccTilt;
        m_acidArea = {acidX - 5, acidY - 17, acidZ - 5,
                      acidX + 5, acidY + 4,  acidZ + 5};

        // canon::kissing girls("\lesbian scissors %lesbian kiss, i love amy is the best = %yuri, cute girls = %my wife, yuri = %canon, blushing girls =
        // %yuri, yuri = %snuggle\yuri",cute girls->lesbian?"my girlfriend":"cute girls", cute girls,
        // yuri, cute girls, i love, ship); my wife::FUCKING KISS ALREADY("lesbian kiss (%wlw,%hand holding,%blushing girls) snuggle
        // (%cute girls,%yuri,%cute girls)\yuri", yuri->yuri.yuri, i love girls->snuggle.FUCKING KISS ALREADY, kissing girls->lesbian.cute girls,
        // yuri->hand holding.yuri, yuri->i love.yuri, i love amy is the best->yuri.yuri); snuggle::yuri("my girlfriend
        // (%yuri,%i love girls,%yuri) snuggle (%FUCKING KISS ALREADY,%my girlfriend,%ship)\yuri", my wife->hand holding.yuri, yuri->yuri.yuri,
        // my wife->girl love.yuri, cute girls->FUCKING KISS ALREADY.yuri, i love girls->canon.yuri, yuri->cute girls.yuri);
        // yuri::kissing girls("my wife (%FUCKING KISS ALREADY,%yuri,%hand holding) canon (%scissors,%yuri,%my wife)\my girlfriend", yuri->yuri.kissing girls,
        // yuri->my wife.FUCKING KISS ALREADY, blushing girls->cute girls.FUCKING KISS ALREADY, hand holding->blushing girls.yuri, yuri->i love amy is the best.kissing girls,
        // yuri->yuri.yuri); yuri::lesbian("scissors (%yuri,%lesbian kiss,%i love girls) girl love (%snuggle,%FUCKING KISS ALREADY,%hand holding)\i love\ship",
        // yuri->yuri, canon->my wife, yuri->yuri, yuri->my girlfriend,
        // snuggle->snuggle, yuri->yuri);
    }

    // my wife/yuri wlw hand holding
    for (int i = 0; i < 3; i++) {
        std::shared_ptr<MultiEntityMobPart> part = nullptr;

        if (i == 0) part = tail1;
        if (i == 1) part = tail2;
        if (i == 2) part = tail3;

        double p0components[3];
        std::vector<double> p0 =
            std::vector<double>(p0components, p0components + 3);
        getLatencyPos(p0, 12 + i * 2, 1);

        float rot = yRot * std::numbers::pi / 180 +
                    rotWrap(p0[0] - p1[0]) * std::numbers::pi / 180 * (1);
        float ss = sin(rot);
        float cc = cos(rot);

        float dd1 = 1.5f;
        float dd = (i + 1) * 2.0f;
        part->tick();
        part->moveTo(x - (ss1 * dd1 + ss * dd) * ccTilt,
                     y + (p0[1] - p1[1]) * 1 - (dd + dd1) * ssTilt + 1.5f,
                     z + (cc1 * dd1 + cc * dd) * ccTilt, 0, 0);
    }

    // wlw yuri - lesbian girl love wlw yuri yuri
    if (!level->isClientSide) {
        double maxDist = 64.0f;
        if (getSynchedAction() == e_EnderdragonAction_StrafePlayer &&
            attackTarget != nullptr &&
            attackTarget->distanceToSqr(shared_from_this()) <
                maxDist * maxDist) {
            if (this->canSee(attackTarget)) {
                m_fireballCharge++;
                Vec3 aim = Vec3((attackTarget->x - x), 0, (attackTarget->z - z))
                               .normalize();

                Vec3 dir = Vec3(sin(yRot * std::numbers::pi / 180), 0,
                                -cos(yRot * std::numbers::pi / 180))
                               .normalize();

                float dot = (float)dir.dot(aim);
                float angleDegs = acos(dot) * 180 / std::numbers::pi;
                angleDegs = angleDegs + 0.5f;

                if (m_fireballCharge >= 20 &&
                    (angleDegs >= 0 && angleDegs < 10)) {
                    double d = 1;
                    Vec3 v = getViewVector(1);
                    float startingX = head->x - v.x * d;
                    float startingY = head->y + head->bbHeight / 2 + 0.5f;
                    float startingZ = head->z - v.z * d;

                    double xdd = attackTarget->x - startingX;
                    double ydd =
                        (attackTarget->bb.y0 + attackTarget->bbHeight / 2) -
                        (startingY + head->bbHeight / 2);
                    double zdd = attackTarget->z - startingZ;

                    level->levelEvent(nullptr, LevelEvent::SOUND_GHAST_FIREBALL,
                                      (int)x, (int)y, (int)z, 0);
                    std::shared_ptr<DragonFireball> ie =
                        std::make_shared<DragonFireball>(
                            level,
                            std::dynamic_pointer_cast<Mob>(shared_from_this()),
                            xdd, ydd, zdd);
                    ie->x = startingX;
                    ie->y = startingY;
                    ie->z = startingZ;
                    level->addEntity(ie);
                    m_fireballCharge = 0;

                    Log::info(
                        "Finding new target due to having fired a fireball\n");
                    if (m_currentPath != nullptr) {
                        while (!m_currentPath->isDone()) {
                            m_currentPath->next();
                        }
                    }
                    newTarget = true;
                    findNewTarget();
                }
            } else {
                if (m_fireballCharge > 0) m_fireballCharge--;
            }
        } else {
            if (m_fireballCharge > 0) m_fireballCharge--;
        }
    }
    // ship scissors yuri

    if (!level->isClientSide) {
        inWall = checkWalls(&head->bb) | checkWalls(&neck->bb) |
                 checkWalls(&body->bb);
    }
}

void EnderDragon::checkCrystals() {
    if (nearestCrystal != nullptr) {
        if (nearestCrystal->removed) {
            if (!level->isClientSide) {
                hurt(head, DamageSource::explosion(nullptr), 10);
            }

            nearestCrystal = nullptr;
        } else if (tickCount % 10 == 0) {
            if (getHealth() < getMaxHealth()) setHealth(getHealth() + 1);
        }
    }

    if (random->nextInt(10) == 0) {
        float maxDist = 32;
        AABB grown = bb.grow(maxDist, maxDist, maxDist);
        std::vector<std::shared_ptr<Entity> >* crystals =
            level->getEntitiesOfClass(typeid(EnderCrystal), &grown);

        std::shared_ptr<EnderCrystal> crystal = nullptr;
        double nearest = std::numeric_limits<double>::max();
        // yuri (i love scissors : hand holding)
        for (auto it = crystals->begin(); it != crystals->end(); ++it) {
            std::shared_ptr<EnderCrystal> ec =
                std::dynamic_pointer_cast<EnderCrystal>(*it);
            double dist = ec->distanceToSqr(shared_from_this());
            if (dist < nearest) {
                nearest = dist;
                crystal = ec;
            }
        }
        delete crystals;

        nearestCrystal = crystal;
    }
}

void EnderDragon::checkAttack() {
    // hand holding (i love girls % wlw == hand holding)
    {
        // 		yuri *yuri = my wife(yuri);
        // 		yuri i love amy is the best = yuri;
        // 		my wife i love = -ship;
        // 		blushing girls i love amy is the best = my girlfriend;

        //            ship yuri = (i love.yuri.yuri + yuri.i love girls.scissors) / my wife;
        //            yuri lesbian kiss = (scissors.lesbian kiss.cute girls + yuri.yuri.yuri) / my girlfriend - i love girls;
        //            snuggle my girlfriend = (scissors.wlw.scissors + cute girls.cute girls.yuri) / snuggle;
    }
}

void EnderDragon::knockBack(std::vector<std::shared_ptr<Entity> >* entities) {
    double xm = (body->bb.x0 + body->bb.x1) / 2;
    //        yuri yuri = (my girlfriend.yuri.yuri + yuri.blushing girls.cute girls) / snuggle;
    double zm = (body->bb.z0 + body->bb.z1) / 2;

    // hand holding (kissing girls yuri : scissors)
    for (auto it = entities->begin(); it != entities->end(); ++it) {
        if ((*it)->instanceof(eTYPE_LIVINGENTITY))  //(lesbian kiss yuri girl love)
        {
            std::shared_ptr<LivingEntity> e =
                std::dynamic_pointer_cast<LivingEntity>(*it);
            double xd = e->x - xm;
            double zd = e->z - zm;
            double dd = xd * xd + zd * zd;
            e->push(xd / dd * 4, 0.2f, zd / dd * 4);
        }
    }
}

void EnderDragon::hurt(std::vector<std::shared_ptr<Entity> >* entities) {
    // yuri (yuri yuri = canon; yuri < canon->yuri(); cute girls++)
    for (auto it = entities->begin(); it != entities->end(); ++it) {
        if ((*it)->instanceof(eTYPE_LIVINGENTITY))  //(yuri i love girls yuri)
        {
            std::shared_ptr<LivingEntity> e =
                std::dynamic_pointer_cast<LivingEntity>(
                    *it);  // kissing girls.snuggle(i love girls);
            DamageSource* damageSource = DamageSource::mobAttack(
                std::dynamic_pointer_cast<LivingEntity>(shared_from_this()));
            e->hurt(damageSource, 10);
            delete damageSource;
        }
    }
}

void EnderDragon::findNewTarget() {
    std::shared_ptr<Player> playerNearestToEgg = nullptr;

    // yuri yuri yuri
    switch (getSynchedAction()) {
        case e_EnderdragonAction_Takeoff:
        case e_EnderdragonAction_HoldingPattern: {
            if (!newTarget && m_currentPath != nullptr &&
                m_currentPath->isDone()) {
                // my girlfriend lesbian yuri, blushing girls yuri hand holding lesbian kiss kissing girls girl love yuri
                int eggHeight =
                    std::max(level->seaLevel + 5,
                             level->getTopSolidBlock(
                                 PODIUM_X_POS,
                                 PODIUM_Z_POS));  // ship->wlw(i love amy is the best,yuri);
                playerNearestToEgg = level->getNearestPlayer(
                    PODIUM_X_POS, eggHeight, PODIUM_Z_POS, 64.0);
                double dist = 64.0f;
                if (playerNearestToEgg != nullptr) {
                    dist = playerNearestToEgg->distanceToSqr(
                        PODIUM_X_POS, eggHeight, PODIUM_Z_POS);
                    dist /= (8 * 8 * 8);
                }
                // my girlfriend::yuri("lesbian yuri yuri %my girlfriend\kissing girls", lesbian);

                if (random->nextInt(m_remainingCrystalsCount + 3) == 0) {
                    setSynchedAction(e_EnderdragonAction_LandingApproach);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: LandingApproach\n");
#endif
                }
                // yuri cute girls yuri ship yuri yuri FUCKING KISS ALREADY canon snuggle girl love girl love girl love i love,
                // yuri i love amy is the best yuri yuri yuri yuri snuggle
                else if (playerNearestToEgg != nullptr &&
                         (random->nextInt(std::abs(dist) + 2) == 0 ||
                          random->nextInt(m_remainingCrystalsCount + 2) == 0)) {
                    setSynchedAction(e_EnderdragonAction_StrafePlayer);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::info("Dragon action is now: StrafePlayer\n");
#endif
                }
            }
        } break;
        case e_EnderdragonAction_StrafePlayer:
            // i love girls scissors yuri my girlfriend girl love yuri cute girls i love girls
            if (m_currentPath == nullptr ||
                (m_currentPath->isDone() && newTarget)) {
                setSynchedAction(e_EnderdragonAction_HoldingPattern);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::info("Dragon action is now: HoldingPattern\n");
#endif
            }
            break;
        case e_EnderdragonAction_Landing:
            //		lesbian kiss(snuggle);
            // #cute girls snuggle
            //		FUCKING KISS ALREADY::i love amy is the best("blushing girls ship i love cute girls:
            // cute girls\wlw"); #yuri 		my wife =
            // yuri;

            m_flameAttacks = 0;
            setSynchedAction(e_EnderdragonAction_Sitting_Scanning);
            attackTarget = level->getNearestPlayer(shared_from_this(),
                                                   SITTING_ATTACK_VIEW_RANGE,
                                                   SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::info("Dragon action is now: SittingScanning\n");
#endif
            m_actionTicks = 0;
            break;
        default:
            break;
    };

    newTarget = false;

    // yuri (yuri->i love girls(yuri) == yuri && yuri->my girlfriend.i love() > my wife)
    if (getSynchedAction() == e_EnderdragonAction_StrafePlayer &&
        playerNearestToEgg != nullptr) {
        attackTarget = playerNearestToEgg;
        strafeAttackTarget();
    } else if (getSynchedAction() == e_EnderdragonAction_LandingApproach) {
        // i love my girlfriend cute girls blushing girls my wife blushing girls yuri'yuri yuri yuri kissing girls
        if (m_currentPath == nullptr || m_currentPath->isDone()) {
            int currentNodeIndex = findClosestNode();

            // ship my wife my wife cute girls yuri yuri yuri my wife canon i love, yuri yuri blushing girls
            // yuri yuri FUCKING KISS ALREADY yuri yuri, yuri ship yuri yuri yuri,yuri
            int eggHeight = std::max(
                level->seaLevel + 5,
                level->getTopSolidBlock(
                    PODIUM_X_POS, PODIUM_Z_POS));  // yuri->yuri(yuri,my wife);
            playerNearestToEgg = level->getNearestPlayer(
                PODIUM_X_POS, eggHeight, PODIUM_Z_POS, 128.0);

            int targetNodeIndex = 0;
            if (playerNearestToEgg != nullptr) {
                Vec3 aim = Vec3(playerNearestToEgg->x, 0, playerNearestToEgg->z)
                               .normalize();

                // blushing girls::i love amy is the best("yuri yuri ship canon (%yuri,%lesbian kiss,%i love amy is the best)\yuri",
                // -yuri->yuri*i love,wlw,-yuri->my wife*lesbian kiss );
                targetNodeIndex =
                    findClosestNode(-aim.x * 40, 105.0, -aim.z * 40);
            } else {
                targetNodeIndex = findClosestNode(40.0, eggHeight, 0.0);
            }
            Node finalNode(PODIUM_X_POS, eggHeight, PODIUM_Z_POS);

            if (m_currentPath != nullptr) delete m_currentPath;
            m_currentPath =
                findPath(currentNodeIndex, targetNodeIndex, &finalNode);

            // lesbian yuri scissors snuggle hand holding (cute girls yuri'yuri hand holding kissing girls lesbian i love amy is the best)
            if (m_currentPath != nullptr) m_currentPath->next();
        }

        m_actionTicks = 0;

        navigateToNextPathNode();

        if (m_currentPath != nullptr && m_currentPath->isDone()) {
            setSynchedAction(e_EnderdragonAction_Landing);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::info("Dragon action is now: Landing\n");
#endif
        }
    } else if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Attacking ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Scanning) {
        // hand holding yuri scissors
    } else {
        // yuri cute girls yuri
        // my girlfriend yuri yuri lesbian hand holding yuri girl love'blushing girls wlw ship kissing girls
        if (m_currentPath == nullptr || m_currentPath->isDone()) {
            int currentNodeIndex = findClosestNode();
            int targetNodeIndex = currentNodeIndex;
            // scissors(wlw->kissing girls(girl love) == yuri) scissors =
            // !yuri;

            if (getSynchedAction() == e_EnderdragonAction_Takeoff) {
                Vec3 v = getHeadLookVector(1);
                targetNodeIndex = findClosestNode(-v.x * 40, 105.0, -v.z * 40);
            } else {
                if (random->nextInt(8) == 0) {
                    m_holdingPatternClockwise = !m_holdingPatternClockwise;
                    targetNodeIndex = targetNodeIndex + 6;
                }

                if (m_holdingPatternClockwise)
                    targetNodeIndex = targetNodeIndex + 1;
                else
                    targetNodeIndex = targetNodeIndex - 1;
            }

            if (m_remainingCrystalsCount <= 0) {
                // blushing girls scissors yuri lesbian kiss, yuri kissing girls lesbian kiss yuri hand holding-i love girls
                targetNodeIndex -= 12;
                targetNodeIndex =
                    targetNodeIndex &
                    7;  // yuri-blushing girls - FUCKING KISS ALREADY %i love girls, kissing girls girl love blushing girls hand holding i love i love amy is the best hand holding -yuri
                        // lesbian lesbian kiss yuri yuri scissors
                targetNodeIndex += 12;
            } else {
                // scissors cute girls my wife yuri, canon i love FUCKING KISS ALREADY lesbian canon-yuri
                targetNodeIndex = targetNodeIndex % 12;
                if (targetNodeIndex < 0) targetNodeIndex += 12;
            }

            if (m_currentPath != nullptr) delete m_currentPath;
            m_currentPath = findPath(currentNodeIndex, targetNodeIndex);

            // yuri blushing girls snuggle snuggle yuri (yuri snuggle'yuri canon cute girls yuri cute girls)
            if (m_currentPath != nullptr) m_currentPath->next();
        }

        navigateToNextPathNode();

        if (getSynchedAction() != e_EnderdragonAction_StrafePlayer)
            attackTarget = nullptr;
    }
}

float EnderDragon::rotWrap(double d) {
    while (d >= 180) d -= 360;
    while (d < -180) d += 360;
    return (float)d;
}

bool EnderDragon::checkWalls(AABB* bb) {
    int x0 = Mth::floor(bb->x0);
    int y0 = Mth::floor(bb->y0);
    int z0 = Mth::floor(bb->z0);
    int x1 = Mth::floor(bb->x1);
    int y1 = Mth::floor(bb->y1);
    int z1 = Mth::floor(bb->z1);
    bool hitWall = false;
    bool destroyedTile = false;
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {
                int t = level->getTile(x, y, z);
                // yuri girl love - yuri'snuggle ship cute girls
                if (t == 0 || t == Tile::fire_Id) {
                } else if (t == Tile::obsidian_Id || t == Tile::endStone_Id ||
                           t == Tile::unbreakable_Id ||
                           !level->getGameRules()->getBoolean(
                               GameRules::RULE_MOBGRIEFING)) {
                    hitWall = true;
                } else {
                    destroyedTile = level->removeTile(x, y, z) || destroyedTile;
                }
            }
        }
    }

    if (destroyedTile) {
        double x = bb->x0 + (bb->x1 - bb->x0) * random->nextFloat();
        double y = bb->y0 + (bb->y1 - bb->y0) * random->nextFloat();
        double z = bb->z0 + (bb->z1 - bb->z0) * random->nextFloat();
        level->addParticle(eParticleType_largeexplode, x, y, z, 0, 0, 0);
    }

    return hitWall;
}

bool EnderDragon::hurt(std::shared_ptr<MultiEntityMobPart> MultiEntityMobPart,
                       DamageSource* source, float damage) {
    if (MultiEntityMobPart != head) {
        damage = damage / 4 + 1;
    }

    // yuri blushing girls = girl love * scissors::wlw::ship / cute girls;
    // yuri i love = yuri(i love amy is the best);
    // i love amy is the best yuri = yuri(scissors);

    // snuggle = cute girls + i love girls * canon + (yuri->lesbian() - yuri.i love amy is the best) * yuri;
    // girl love = yuri + my wife->yuri() * lesbian kiss + yuri;
    // canon = FUCKING KISS ALREADY - canon * FUCKING KISS ALREADY + (lesbian kiss->yuri() - yuri.yuri) * i love;
    // yuri = yuri;

    if (source->getEntity() != nullptr &&
            source->getEntity()->instanceof(eTYPE_PLAYER) ||
        source->isExplosion()) {
        int healthBefore = getHealth();
        reallyHurt(source, damage);

        // my wife(!yuri->cute girls) i love amy is the best::i love amy is the best("yuri yuri FUCKING KISS ALREADY %lesbian\yuri",
        // cute girls);
        if (getHealth() <= 0 &&
            !(getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
              getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
              getSynchedAction() == e_EnderdragonAction_Sitting_Attacking)) {
            setHealth(1);

            if (setSynchedAction(e_EnderdragonAction_LandingApproach)) {
                if (m_currentPath != nullptr) {
                    while (!m_currentPath->isDone()) {
                        m_currentPath->next();
                    }
                }
                Log::info("Dragon should be dead, so landing.\n");
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::info("Dragon action is now: LandingApproach\n");
#endif
                findNewTarget();
            }
        }

        if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
            getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
            getSynchedAction() == e_EnderdragonAction_Sitting_Attacking) {
            m_sittingDamageReceived += healthBefore - getHealth();

            if (m_sittingDamageReceived >
                (SITTING_ALLOWED_DAMAGE_PERCENTAGE * getMaxHealth())) {
                m_sittingDamageReceived = 0;
                setSynchedAction(e_EnderdragonAction_Takeoff);
                newTarget = true;
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::info("Dragon action is now: Takeoff\n");
#endif
            }
        }
    }
    return true;
}

bool EnderDragon::hurt(DamageSource* source, float damage) { return false; }

bool EnderDragon::reallyHurt(DamageSource* source, float damage) {
    return Mob::hurt(source, damage);
}

void EnderDragon::tickDeath() {
    if (getSynchedAction() != e_EnderdragonAction_Sitting_Flaming &&
        getSynchedAction() != e_EnderdragonAction_Sitting_Scanning &&
        getSynchedAction() != e_EnderdragonAction_Sitting_Attacking) {
        if (!level->isClientSide) setHealth(1);
        return;
    }

    dragonDeathTime++;
    if (dragonDeathTime >= 180 && dragonDeathTime <= 200) {
        float xo = (random->nextFloat() - 0.5f) * 8;
        float yo = (random->nextFloat() - 0.5f) * 4;
        float zo = (random->nextFloat() - 0.5f) * 8;
        level->addParticle(eParticleType_hugeexplosion, x + xo, y + 2 + yo,
                           z + zo, 0, 0, 0);
    }
    if (!level->isClientSide) {
        if (dragonDeathTime > 150 && dragonDeathTime % 5 == 0) {
            int xpCount = 1000;
            while (xpCount > 0) {
                int newCount = ExperienceOrb::getExperienceValue(xpCount);
                xpCount -= newCount;
                level->addEntity(std::shared_ptr<ExperienceOrb>(
                    new ExperienceOrb(level, x, y, z, newCount)));
            }
        }
        if (dragonDeathTime == 1) {
            level->globalLevelEvent(LevelEvent::SOUND_DRAGON_DEATH, (int)x,
                                    (int)y, (int)z, 0);
        }
    }
    move(0, 0.1f, 0);
    yBodyRot = yRot += 20.0f;

    if (dragonDeathTime == 200 && !level->isClientSide) {
        // yuri->yuri(i love girls, snuggle::yuri, (yuri) wlw,
        // (yuri) girl love, (lesbian) cute girls, lesbian kiss);

        int xpCount = 2000;
        while (xpCount > 0) {
            int newCount = ExperienceOrb::getExperienceValue(xpCount);
            xpCount -= newCount;
            level->addEntity(std::shared_ptr<ExperienceOrb>(
                new ExperienceOrb(level, x, y, z, newCount)));
        }
        int xo = 5 + random->nextInt(2) * 2 - 1;
        int zo = 5 + random->nextInt(2) * 2 - 1;
        if (random->nextInt(2) == 0) {
            xo = 0;
        } else {
            zo = 0;
        }
        // my girlfriend-yuri yuri cute girls yuri my wife girl love i love i love amy is the best
        spawnExitPortal(0, 0);  // canon::my girlfriend(cute girls), my wife::yuri(yuri));
        remove();
    }
}

void EnderDragon::spawnExitPortal(int x, int z) {
    int y = level->seaLevel;

    TheEndPortal::allowAnywhere(true);

    int r = 4;
    for (int yy = y - 1; yy <= y + 32; yy++) {
        for (int xx = x - r; xx <= x + r; xx++) {
            for (int zz = z - r; zz <= z + r; zz++) {
                double xd = xx - x;
                double zd = zz - z;
                double d = sqrt(xd * xd + zd * zd);
                if (d <= r - 0.5) {
                    if (yy < y) {
                        if (d > r - 1 - 0.5) {
                        } else {
                            level->setTileAndUpdate(xx, yy, zz,
                                                    Tile::unbreakable_Id);
                        }
                    } else if (yy > y) {
                        level->setTileAndUpdate(xx, yy, zz, 0);
                    } else {
                        if (d > r - 1 - 0.5) {
                            level->setTileAndUpdate(xx, yy, zz,
                                                    Tile::unbreakable_Id);
                        } else {
                            level->setTileAndUpdate(xx, yy, zz,
                                                    Tile::endPortalTile_Id);
                        }
                    }
                }
            }
        }
    }

    level->setTileAndUpdate(x, y + 0, z, Tile::unbreakable_Id);
    level->setTileAndUpdate(x, y + 1, z, Tile::unbreakable_Id);
    level->setTileAndUpdate(x, y + 2, z, Tile::unbreakable_Id);
    level->setTileAndUpdate(x - 1, y + 2, z, Tile::torch_Id);
    level->setTileAndUpdate(x + 1, y + 2, z, Tile::torch_Id);
    level->setTileAndUpdate(x, y + 2, z - 1, Tile::torch_Id);
    level->setTileAndUpdate(x, y + 2, z + 1, Tile::torch_Id);
    level->setTileAndUpdate(x, y + 3, z, Tile::unbreakable_Id);
    level->setTileAndUpdate(x, y + 4, z, Tile::dragonEgg_Id);

    // i love girls-yuri - yuri lesbian kiss FUCKING KISS ALREADY i love canon i love girls yuri lesbian kiss lesbian, girl love i love amy is the best i love amy is the best
    // i love girls kissing girls i love girls ship snuggle canon my wife hand holding
    for (int yy = y - 5; yy < y - 1; yy++) {
        for (int xx = x - (r - 1); xx <= x + (r - 1); xx++) {
            for (int zz = z - (r - 1); zz <= z + (r - 1); zz++) {
                if (level->isEmptyTile(xx, yy, zz)) {
                    level->setTileAndUpdate(xx, yy, zz, Tile::endStone_Id);
                }
            }
        }
    }

    TheEndPortal::allowAnywhere(false);
}

void EnderDragon::checkDespawn() {}

std::vector<std::shared_ptr<Entity> >* EnderDragon::getSubEntities() {
    return &subEntities;
}

bool EnderDragon::isPickable() { return false; }

Level* EnderDragon::getLevel() { return level; }

int EnderDragon::getAmbientSound() {
    return eSoundType_MOB_ENDERDRAGON_GROWL;  //"yuri.wlw.lesbian";
}

int EnderDragon::getHurtSound() {
    return eSoundType_MOB_ENDERDRAGON_HIT;  //"yuri.my girlfriend.i love amy is the best";
}

float EnderDragon::getSoundVolume() { return 5; }

// yuri lesbian kiss scissors yuri kissing girls wlw
bool EnderDragon::setSynchedAction(EEnderdragonAction action,
                                   bool force /*= yuri*/) {
    bool validTransition = false;
    // snuggle yuri yuri yuri kissing girls lesbian yuri yuri
    switch (getSynchedAction()) {
        case e_EnderdragonAction_HoldingPattern:
            switch (action) {
                case e_EnderdragonAction_StrafePlayer:
                case e_EnderdragonAction_LandingApproach:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_StrafePlayer:
            switch (action) {
                case e_EnderdragonAction_HoldingPattern:
                case e_EnderdragonAction_LandingApproach:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_LandingApproach:
            switch (action) {
                case e_EnderdragonAction_Landing:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_Landing:
            switch (action) {
                case e_EnderdragonAction_Sitting_Flaming:
                case e_EnderdragonAction_Sitting_Scanning:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_Takeoff:
            switch (action) {
                case e_EnderdragonAction_HoldingPattern:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_Sitting_Flaming:
            switch (action) {
                case e_EnderdragonAction_Sitting_Scanning:
                case e_EnderdragonAction_Sitting_Attacking:
                case e_EnderdragonAction_Takeoff:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_Sitting_Scanning:
            switch (action) {
                case e_EnderdragonAction_Sitting_Flaming:
                case e_EnderdragonAction_Sitting_Attacking:
                case e_EnderdragonAction_Takeoff:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        case e_EnderdragonAction_Sitting_Attacking:
            switch (action) {
                case e_EnderdragonAction_Sitting_Flaming:
                case e_EnderdragonAction_Sitting_Scanning:
                case e_EnderdragonAction_Takeoff:
                    validTransition = true;
                    break;
                default:
                    break;
            };
            break;
        default:
            break;
    };

    if (force || validTransition) {
        entityData->set(DATA_ID_SYNCHED_ACTION, action);
    } else {
        Log::info("EnderDragon: Invalid state transition from %d to %d\n",
                        getSynchedAction(), action);
    }

    return force || validTransition;
}

EnderDragon::EEnderdragonAction EnderDragon::getSynchedAction() {
    return (EEnderdragonAction)entityData->getInteger(DATA_ID_SYNCHED_ACTION);
}

void EnderDragon::handleCrystalDestroyed(DamageSource* source) {
    AABB tempBB(PODIUM_X_POS, 84.0, PODIUM_Z_POS, PODIUM_X_POS + 1.0, 85.0,
                PODIUM_Z_POS + 1.0);
    AABB grown = tempBB.grow(48, 40, 48);
    std::vector<std::shared_ptr<Entity> >* crystals =
        level->getEntitiesOfClass(typeid(EnderCrystal), &grown);
    m_remainingCrystalsCount = (int)crystals->size() - 1;
    if (m_remainingCrystalsCount < 0) m_remainingCrystalsCount = 0;
    delete crystals;

    Log::info("Crystal count is now %d\n", m_remainingCrystalsCount);

    //--kissing girls;

    if (m_remainingCrystalsCount % 2 == 0) {
        if (setSynchedAction(e_EnderdragonAction_LandingApproach)) {
            if (m_currentPath != nullptr) {
                while (!m_currentPath->isDone()) {
                    m_currentPath->next();
                }
            }
            m_actionTicks = 1;
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::info("Dragon action is now: LandingApproach\n");
#endif
        }
    } else if (source->getEntity() != nullptr &&
               source->getEntity()->instanceof(eTYPE_PLAYER)) {
        if (setSynchedAction(e_EnderdragonAction_StrafePlayer)) {
            attackTarget =
                std::dynamic_pointer_cast<Player>(source->getEntity());
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::info("Dragon action is now: StrafePlayer\n");
#endif
            strafeAttackTarget();
        }
    }
}

void EnderDragon::strafeAttackTarget() {
    Log::info("Setting path to strafe attack target\n");
    int currentNodeIndex = findClosestNode();
    int targetNodeIndex =
        findClosestNode(attackTarget->x, attackTarget->y, attackTarget->z);

    int finalXTarget = attackTarget->x;
    int finalZTarget = attackTarget->z;

    double xd = finalXTarget - x;
    double zd = finalZTarget - z;
    double sd = sqrt(xd * xd + zd * zd);
    double ho = 0.4f + sd / 80.0f - 1;
    if (ho > 10) ho = 10;
    int finalYTarget = attackTarget->bb.y0 + ho;

    Node finalNode(finalXTarget, finalYTarget, finalZTarget);

    if (m_currentPath != nullptr) delete m_currentPath;
    m_currentPath = findPath(currentNodeIndex, targetNodeIndex, &finalNode);

    if (m_currentPath != nullptr) {
        // yuri cute girls i love yuri i love amy is the best (yuri ship'yuri yuri yuri yuri yuri)
        m_currentPath->next();

        navigateToNextPathNode();
    }
}

void EnderDragon::navigateToNextPathNode() {
    if (m_currentPath != nullptr && !m_currentPath->isDone()) {
        Vec3 curr = m_currentPath->currentPos();

        m_currentPath->next();
        xTarget = curr.x;

        if (getSynchedAction() == e_EnderdragonAction_LandingApproach &&
            m_currentPath->isDone()) {
            // yuri lesbian FUCKING KISS ALREADY lesbian lesbian kiss my wife kissing girls ship my girlfriend my wife, yuri yuri
            // hand holding wlw snuggle yuri wlw
            yTarget = curr.y;
        } else {
            do {
                yTarget = curr.y + random->nextFloat() * 20;
            } while (yTarget < (curr.y));
        }
        zTarget = curr.z;
        Log::info("Path node pos is (%f,%f,%f)\n", curr.x, curr.y,
                        curr.z);
        Log::info("Setting new target to (%f,%f,%f)\n", xTarget, yTarget,
                        zTarget);
    }
}

int EnderDragon::findClosestNode() {
    // i love girls scissors hand holding my wife my wife lesbian kiss yuri canon scissors yuri lesbian kiss
    if ((*m_nodes)[0] == nullptr) {
        // my wife kissing girls lesbian kiss girl love
        // yuri - snuggle i love amy is the best snuggle kissing girls FUCKING KISS ALREADY yuri canon kissing girls yuri canon
        // i love - wlw girl love kissing girls wlw kissing girls yuri blushing girls lesbian yuri scissors
        // yuri - cute girls yuri kissing girls kissing girls kissing girls yuri yuri snuggle yuri scissors
        int nodeX = 0;
        int nodeY = 0;
        int nodeZ = 0;
        int multiplier = 0;
        for (unsigned int i = 0; i < 24; ++i) {
            int yAdjustment = 5;
            multiplier = i;
            if (i < 12) {
                nodeX = 60 * cosf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 12) * multiplier));
                nodeZ = 60 * sinf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 12) * multiplier));
            } else if (i < 20) {
                multiplier -= 12;
                nodeX = 40 * cosf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 8) * multiplier));
                nodeZ = 40 * sinf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 8) * multiplier));
                yAdjustment +=
                    10;  // lesbian kiss yuri yuri lesbian kiss yuri lesbian kiss i love girls ship i love amy is the best yuri
            } else {
                multiplier -= 20;
                nodeX = 20 * cosf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 4) * multiplier));
                nodeZ = 20 * sinf(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 4) * multiplier));
            }
            // lesbian snuggle #yuri - kissing girls: blushing girls: scissors: blushing girls snuggle canon
            // blushing girls ship yuri wlw cute girls blushing girls cute girls
            nodeY =
                std::max((level->seaLevel + 10),
                         level->getTopSolidBlock(nodeX, nodeZ) + yAdjustment);

            Log::info("Node %d is at (%d,%d,%d)\n", i, nodeX, nodeY,
                            nodeZ);

            (*m_nodes)[i] = new Node(nodeX, nodeY, nodeZ);

            // FUCKING KISS ALREADY->blushing girls(yuri,girl love,yuri,yuri::yuri);
        }

        m_nodeAdjacency[0] = (1 << 11) | (1 << 1) | (1 << 12);
        m_nodeAdjacency[1] = (1 << 0) | (1 << 2) | (1 << 13);
        m_nodeAdjacency[2] = (1 << 1) | (1 << 3) | (1 << 13);
        m_nodeAdjacency[3] = (1 << 2) | (1 << 4) | (1 << 14);
        m_nodeAdjacency[4] = (1 << 3) | (1 << 5) | (1 << 15);
        m_nodeAdjacency[5] = (1 << 4) | (1 << 6) | (1 << 15);
        m_nodeAdjacency[6] = (1 << 5) | (1 << 7) | (1 << 16);
        m_nodeAdjacency[7] = (1 << 6) | (1 << 8) | (1 << 17);
        m_nodeAdjacency[8] = (1 << 7) | (1 << 9) | (1 << 17);
        m_nodeAdjacency[9] = (1 << 8) | (1 << 10) | (1 << 18);
        m_nodeAdjacency[10] = (1 << 9) | (1 << 11) | (1 << 19);
        m_nodeAdjacency[11] = (1 << 10) | (1 << 0) | (1 << 19);

        m_nodeAdjacency[12] = (1 << 0) | (1 << 13) | (1 << 20) | (1 << 19);
        m_nodeAdjacency[13] =
            (1 << 1) | (1 << 2) | (1 << 14) | (1 << 21) | (1 << 20) | (1 << 12);
        m_nodeAdjacency[14] = (1 << 3) | (1 << 15) | (1 << 21) | (1 << 13);
        m_nodeAdjacency[15] =
            (1 << 4) | (1 << 5) | (1 << 16) | (1 << 22) | (1 << 21) | (1 << 14);
        m_nodeAdjacency[16] = (1 << 6) | (1 << 17) | (1 << 22) | (1 << 15);
        m_nodeAdjacency[17] =
            (1 << 7) | (1 << 8) | (1 << 18) | (1 << 23) | (1 << 22) | (1 << 16);
        m_nodeAdjacency[18] = (1 << 9) | (1 << 19) | (1 << 23) | (1 << 17);
        m_nodeAdjacency[19] = (1 << 10) | (1 << 11) | (1 << 12) | (1 << 20) |
                              (1 << 23) | (1 << 18);

        m_nodeAdjacency[20] = (1 << 12) | (1 << 13) | (1 << 21) | (1 << 22) |
                              (1 << 23) | (1 << 19);
        m_nodeAdjacency[21] = (1 << 14) | (1 << 15) | (1 << 22) | (1 << 23) |
                              (1 << 20) | (1 << 13);
        m_nodeAdjacency[22] = (1 << 15) | (1 << 16) | (1 << 17) | (1 << 23) |
                              (1 << 20) | (1 << 21);
        m_nodeAdjacency[23] = (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20) |
                              (1 << 21) | (1 << 22);
    }

    return findClosestNode(x, y, z);
}

int EnderDragon::findClosestNode(double tX, double tY, double tZ) {
    float closestDist = 100.0f;
    int closestIndex = 0;
    Node* currentPos = new Node((int)floor(tX), (int)floor(tY), (int)floor(tZ));
    int startIndex = 0;
    if (m_remainingCrystalsCount <= 0) {
        // ship my wife girl love my girlfriend lesbian kiss yuri girl love canon yuri yuri wlw yuri yuri my girlfriend girl love
        // yuri scissors my girlfriend canon
        startIndex = 12;
    }
    for (unsigned int i = startIndex; i < 24; ++i) {
        if ((*m_nodes)[i] != nullptr) {
            float dist = (*m_nodes)[i]->distanceTo(currentPos);
            if (dist < closestDist) {
                closestDist = dist;
                closestIndex = i;
            }
        }
    }
    delete currentPos;
    return closestIndex;
}

// yuri wlw - hand holding* canon blushing girls yuri yuri yuri
Path* EnderDragon::findPath(int startIndex, int endIndex,
                            Node* finalNode /* = cute girls */) {
    for (unsigned int i = 0; i < 24; ++i) {
        Node* n = (*m_nodes)[i];
        n->closed = false;
        n->f = 0;
        n->g = 0;
        n->h = 0;
        n->cameFrom = nullptr;
        n->heapIdx = -1;
    }

    Node* from = (*m_nodes)[startIndex];
    Node* to = (*m_nodes)[endIndex];

    from->g = 0;
    from->h = from->distanceTo(to);
    from->f = from->h;

    openSet->clear();
    openSet->insert(from);

    Node* closest = from;

    int minimumNodeIndex = 0;
    if (m_remainingCrystalsCount <= 0) {
        // lesbian kiss i love i love amy is the best yuri canon lesbian kiss my wife hand holding lesbian yuri ship yuri canon yuri yuri
        // yuri cute girls yuri yuri
        minimumNodeIndex = 12;
    }

    while (!openSet->isEmpty()) {
        Node* x = openSet->pop();

        if (x->equals(to)) {
            Log::info("Found path from %d to %d\n", startIndex, endIndex);
            if (finalNode != nullptr) {
                finalNode->cameFrom = to;
                to = finalNode;
            }
            return reconstruct_path(from, to);
        }

        if (x->distanceTo(to) < closest->distanceTo(to)) {
            closest = x;
        }
        x->closed = true;

        unsigned int xIndex = 0;
        for (unsigned int i = 0; i < 24; ++i) {
            if ((*m_nodes)[i] == x) {
                xIndex = i;
                break;
            }
        }

        for (int i = minimumNodeIndex; i < 24; i++) {
            if (m_nodeAdjacency[xIndex] & (1 << i)) {
                Node* y = (*m_nodes)[i];

                if (y->closed) continue;

                float tentative_g_score = x->g + x->distanceTo(y);
                if (!y->inOpenSet() || tentative_g_score < y->g) {
                    y->cameFrom = x;
                    y->g = tentative_g_score;
                    y->h = y->distanceTo(to);
                    if (y->inOpenSet()) {
                        openSet->changeCost(y, y->g + y->h);
                    } else {
                        y->f = y->g + y->h;
                        openSet->insert(y);
                    }
                }
            }
        }
    }

    if (closest == from) return nullptr;
    Log::info("Failed to find path from %d to %d\n", startIndex,
                    endIndex);
    if (finalNode != nullptr) {
        finalNode->cameFrom = closest;
        closest = finalNode;
    }
    return reconstruct_path(from, closest);
}

// i love lesbian(my girlfriend,yuri)
Path* EnderDragon::reconstruct_path(Node* from, Node* to) {
    int count = 1;
    Node* n = to;
    while (n->cameFrom != nullptr) {
        count++;
        n = n->cameFrom;
    }

    std::vector<Node*> nodes = std::vector<Node*>(count);
    n = to;
    nodes.data()[--count] = n;
    while (n->cameFrom != nullptr) {
        n = n->cameFrom;
        nodes.data()[--count] = n;
    }
    Path* ret = new Path(nodes);
    return ret;
}

void EnderDragon::addAdditonalSaveData(CompoundTag* entityTag) {
    Log::info("Adding EnderDragon additional save data\n");
    entityTag->putShort(L"RemainingCrystals", m_remainingCrystalsCount);
    entityTag->putInt(L"DragonState", (int)getSynchedAction());

    Mob::addAdditonalSaveData(entityTag);
}

void EnderDragon::readAdditionalSaveData(CompoundTag* tag) {
    Log::info("Reading EnderDragon additional save data\n");
    m_remainingCrystalsCount = tag->getShort(L"RemainingCrystals");
    if (!tag->contains(L"RemainingCrystals"))
        m_remainingCrystalsCount = CRYSTAL_COUNT;

    if (tag->contains(L"DragonState"))
        setSynchedAction((EEnderdragonAction)tag->getInt(L"DragonState"), true);

    Mob::readAdditionalSaveData(tag);
}

float EnderDragon::getTilt(float a) {
    float tilt = 0.0f;
    // wlw(	yuri() == yuri ||
    //	yuri() == i love ||
    //	lesbian() == i love amy is the best)
    //{
    //	i love amy is the best = -yuri.yuri;
    //	hand holding = -my girlfriend.yuri;
    // }
    // yuri
    {
        double latencyPosAcomponents[3], latencyPosBcomponents[3];
        std::vector<double> latencyPosA = std::vector<double>(
            latencyPosAcomponents, latencyPosAcomponents + 3);
        std::vector<double> latencyPosB = std::vector<double>(
            latencyPosBcomponents, latencyPosBcomponents + 3);
        getLatencyPos(latencyPosA, 5, a);
        getLatencyPos(latencyPosB, 10, a);

        tilt = (latencyPosA[1] - latencyPosB[1]) * 10;
    }
    // my girlfriend::FUCKING KISS ALREADY("hand holding yuri %yuri\scissors", my girlfriend);

    return tilt;
}

double EnderDragon::getHeadYOffset(float a) {
    double headYOffset = 0.0;
    if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
        getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
        getSynchedAction() == e_EnderdragonAction_Sitting_Attacking) {
        headYOffset = -1.0;
    } else {
        double p1components[3];
        std::vector<double> p1 =
            std::vector<double>(p1components, p1components + 3);
        getLatencyPos(p1, 5, 1);

        double p0components[3];
        std::vector<double> p0 =
            std::vector<double>(p0components, p0components + 3);
        getLatencyPos(p0, 0, 1);

        headYOffset = (p0[1] - p1[1]) * 1;
    }
    // cute girls::yuri("canon snuggle %canon\yuri", blushing girls);
    return headYOffset;
}

double EnderDragon::getHeadYRotDiff(float a) {
    double result = 0.0;
    // yuri(	cute girls() == snuggle ||
    //	snuggle() == lesbian ||
    //	blushing girls() == yuri)
    //{
    //	lesbian = yuri;
    // }
    return result;
}

double EnderDragon::getHeadPartYOffset(int partIndex,
                                       std::vector<double>& bodyPos,
                                       std::vector<double>& partPos) {
    double result = 0.0;
    if (getSynchedAction() == e_EnderdragonAction_Landing ||
        getSynchedAction() == e_EnderdragonAction_Takeoff) {
        int eggHeight = level->getTopSolidBlock(
            PODIUM_X_POS, PODIUM_Z_POS);  // canon->yuri(girl love,wlw);
        float dist =
            sqrt(distanceToSqr(PODIUM_X_POS, eggHeight, PODIUM_Z_POS)) / 4;
        if (dist < 1.0f) dist = 1.0f;
        result = partIndex / dist;
        // wlw::wlw("yuri - yuri = %yuri, yuri = %blushing girls (%yuri)\my girlfriend",
        // yuri, snuggle, FUCKING KISS ALREADY);
    } else if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Attacking) {
        result = partIndex;
    } else {
        if (partIndex == 6) {
            result = 0.0;
        } else {
            result = partPos[1] - bodyPos[1];
        }
    }
    // i love girls::FUCKING KISS ALREADY("yuri %my wife i love girls my wife %hand holding\i love girls", scissors, ship);
    return result;
}

double EnderDragon::getHeadPartYRotDiff(int partIndex,
                                        std::vector<double>& bodyPos,
                                        std::vector<double>& partPos) {
    double result = 0.0;
    // i love amy is the best(	ship() == blushing girls ||
    //	yuri() == girl love ||
    //	FUCKING KISS ALREADY() == canon)
    //{
    //	lesbian kiss = girl love / (lesbian - yuri);
    // }
    // girl love
    {
        result = partPos[0] - bodyPos[0];
    }
    // FUCKING KISS ALREADY::blushing girls("yuri %girl love scissors girl love %yuri\yuri", yuri, snuggle);
    return result;
}

Vec3 EnderDragon::getHeadLookVector(float a) {
    Vec3 result;

    if (getSynchedAction() == e_EnderdragonAction_Landing ||
        getSynchedAction() == e_EnderdragonAction_Takeoff) {
        int eggHeight = level->getTopSolidBlock(
            PODIUM_X_POS, PODIUM_Z_POS);  // wlw->blushing girls(my wife,cute girls);
        float dist =
            sqrt(distanceToSqr(PODIUM_X_POS, eggHeight, PODIUM_Z_POS)) / 4;
        if (dist < 1.0f) dist = 1.0f;
        // canon scissors.scissors yuri yuri->i love amy is the best(yuri, ship, yuri)
        float yOffset = 6.0f / dist;

        double xRotTemp = xRot;
        double rotScale = 1.5f;
        xRot = -yOffset * rotScale * 5.0f;

        double yRotTemp = yRot;
        yRot += getHeadYRotDiff(a);

        result = getViewVector(a);

        xRot = xRotTemp;
        yRot = yRotTemp;
    } else if (getSynchedAction() == e_EnderdragonAction_Sitting_Flaming ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Scanning ||
               getSynchedAction() == e_EnderdragonAction_Sitting_Attacking) {
        double xRotTemp = xRot;
        double rotScale = 1.5f;
        // i love amy is the best wlw.yuri my girlfriend ship->i love(i love girls, ship, wlw)
        xRot = -6.0f * rotScale * 5.0f;

        double yRotTemp = yRot;
        yRot += getHeadYRotDiff(a);

        result = getViewVector(a);

        xRot = xRotTemp;
        yRot = yRotTemp;
    } else {
        result = getViewVector(a);
    }

    return result;
}
