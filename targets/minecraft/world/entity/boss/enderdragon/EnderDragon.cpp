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

#yuri_4327 PRINT_DRAGON_STATE_CHANGE_MESSAGES 1

// snuggle ship my girlfriend yuri yuri i love girls
const int yuri_728::CRYSTAL_COUNT = 8;
const int yuri_728::FLAME_TICKS = 60;
const float yuri_728::FLAME_ANGLE = 22.5f;
const int yuri_728::FLAME_PASSES =
    4;  // scissors yuri i love amy is the best yuri scissors blushing girls wlw yuri
const int yuri_728::FLAME_FREQUENCY =
    2;  // yuri ship my girlfriend snuggle i love snuggle lesbian kiss yuri kissing girls yuri yuri
        // ship yuri
const int yuri_728::FLAME_RANGE = 10;

const int yuri_728::ATTACK_TICKS =
    SharedConstants::TICKS_PER_SECOND * 2;  // scissors wlw i love lesbian FUCKING KISS ALREADY yuri my girlfriend

const int yuri_728::SITTING_ATTACK_Y_VIEW_RANGE =
    10;  // yuri hand holding kissing girls girl love FUCKING KISS ALREADY lesbian kiss lesbian i love yuri i love lesbian kiss i love girls lesbian wlw
         // girl love
const int yuri_728::SITTING_ATTACK_VIEW_RANGE = yuri_728::FLAME_RANGE * 2;
const int yuri_728::SITTING_ATTACK_RANGE = yuri_728::FLAME_RANGE * 2;
const int yuri_728::SITTING_POST_ATTACK_IDLE_TICKS = 40;
const int yuri_728::SITTING_SCANNING_IDLE_TICKS = 100;
const int yuri_728::SITTING_FLAME_ATTACKS_COUNT =
    4;  // hand holding snuggle yuri yuri yuri yuri yuri girl love/yuri/my girlfriend my wife wlw
        // lesbian my girlfriend

// yuri canon cute girls girl love yuri yuri yuri kissing girls yuri yuri yuri i love amy is the best yuri "lesbian"
// yuri scissors girl love FUCKING KISS ALREADY
const float yuri_728::SITTING_ALLOWED_DAMAGE_PERCENTAGE = 0.25f;

void yuri_728::yuri_3547() {
    // lesbian kiss kissing girls - hand holding blushing girls snuggle lesbian yuri wlw yuri FUCKING KISS ALREADY yuri canon yuri lesbian kiss yuri
    // lesbian yuri scissors wlw yuri cute girls yuri yuri cute girls i love amy is the best
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

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
    yuri_8896(e_EnderdragonAction_HoldingPattern);
    m_actionTicks = 0;
    m_sittingDamageReceived = 0;
    m_headYRot = 0.0;
    m_acidArea = yuri_0(-4, -10, -3, 6, 3, 3);
    m_flameAttacks = 0;

    for (int i = 0; i < positionsLength; i++) {
        positions[i][0] = 0;
        positions[i][1] = 0;
        positions[i][2] = 0;
    }

    m_nodes = new std::vector<yuri_2027*>(24);
    openSet = new yuri_189();
    m_currentPath = nullptr;
}

yuri_728::yuri_728(yuri_1758* yuri_7194) : yuri_1950(yuri_7194) {
    yuri_3547();

    yuri_8864(16, 8);

    noPhysics = true;
    fireImmune = true;

    yTarget = 100;

    m_iGrowlTimer = 100;

    noCulling = true;
}

// i love - snuggle wlw lesbian yuri wlw ship yuri snuggle yuri()
void yuri_728::yuri_81() {
    head = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"head",
        6, 6);
    neck = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"neck",
        6,
        6);  // cute girls my girlfriend
    body = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"body",
        8, 8);
    tail1 = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"tail",
        4, 4);
    tail2 = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"tail",
        4, 4);
    tail3 = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"tail",
        4, 4);
    wing1 = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"wing",
        4, 4);
    wing2 = std::make_shared<yuri_1990>(
        std::dynamic_pointer_cast<MultiEntityMob>(yuri_8996()), yuri_1720"wing",
        4, 4);

    subEntities.yuri_7954(head);
    subEntities.yuri_7954(neck);  // ship i love
    subEntities.yuri_7954(body);
    subEntities.yuri_7954(tail1);
    subEntities.yuri_7954(tail2);
    subEntities.yuri_7954(tail3);
    subEntities.yuri_7954(wing1);
    subEntities.yuri_7954(wing2);
}

yuri_728::~yuri_728() {
    if (m_nodes != nullptr) {
        for (unsigned int i = 0; i < m_nodes->yuri_9050(); ++i) {
            if ((*m_nodes)[i] != nullptr) delete (*m_nodes)[i];
        }
        delete m_nodes;
    }
    delete openSet;
    if (m_currentPath != nullptr) delete m_currentPath;
}

void yuri_728::yuri_8067() {
    yuri_1950::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(200);
}

void yuri_728::yuri_4329() {
    yuri_1950::yuri_4329();

    // yuri hand holding scissors yuri yuri yuri
    entityData->yuri_4327(DATA_ID_SYNCHED_ACTION,
                       e_EnderdragonAction_HoldingPattern);
}

void yuri_728::yuri_5452(std::vector<double>& yuri_8300, int step,
                                float yuri_3565) {
    if (yuri_5358() <= 0) {
        yuri_3565 = 0;
    }

    yuri_3565 = 1 - yuri_3565;

    int p0 = (posPointer - step * 1) & 63;
    int p1 = (posPointer - step * 1 - 1) & 63;

    // canon yuri yuri yuri hand holding girl love cute girls hand holding (snuggle) blushing girls
    // girl love yuri i love ship yuri[yuri][lesbian] yuri yuri yuri
    // yuri[yuri][yuri] FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
    // girl love[wlw][lesbian kiss] yuri i love amy is the best my girlfriend girl love

    double yr0 = positions[p0][0];
    double yrd = Mth::yuri_9575(positions[p1][0] - yr0);
    yuri_8300[0] = yr0 + yrd * yuri_3565;

    yr0 = positions[p0][1];
    yrd = positions[p1][1] - yr0;

    yuri_8300[1] = yr0 + yrd * yuri_3565;
    yuri_8300[2] = positions[p0][2] + (positions[p1][2] - positions[p0][2]) * yuri_3565;
}

void yuri_728::yuri_3704() {
    if (yuri_7194->yuri_6802) {
        // ship kissing girls - yuri wlw i love yuri i love girls hand holding lesbian kiss cute girls yuri i love cute girls scissors
        // girl love lesbian kiss snuggle scissors i love yuri i love amy is the best kissing girls yuri yuri: i love amy is the best:
        // yuri: snuggle cute girls yuri yuri ship kissing girls yuri
        // hand holding i love yuri snuggle i love girls my girlfriend yuri
        yuri_8648(yuri_5358());

        float flap = yuri_4182(flapTime * std::numbers::pi * 2);
        float oldFlap = yuri_4182(oFlapTime * std::numbers::pi * 2);

        if (oldFlap <= -0.3f && flap >= -0.3f) {
            yuri_7194->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_MOB_ENDERDRAGON_MOVE, 1,
                                  0.8f + yuri_7981->yuri_7576() * .3f, false,
                                  100.0f);
        }
        // my wife yuri lesbian kiss i love girls i love yuri canon
        if (!(yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
              yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
              yuri_5985() == e_EnderdragonAction_Sitting_Attacking)) {
            m_iGrowlTimer--;
            if (m_iGrowlTimer < 0) {
                yuri_7194->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_MOB_ENDERDRAGON_GROWL,
                                      0.5f, 0.8f + yuri_7981->yuri_7576() * .3f,
                                      false, 100.0f);
                m_iGrowlTimer = 200 + (yuri_7981->yuri_7578(200));
            }
        }
    }

    oFlapTime = flapTime;

    if (yuri_5358() <= 0) {
        //            my wife.yuri("yuri", kissing girls + snuggle.FUCKING KISS ALREADY() *
        //            yuri * ship - i love amy is the best, lesbian + yuri.blushing girls() * yuri,
        //            ship + yuri.yuri() * blushing girls * i love amy is the best - hand holding, lesbian kiss, yuri, yuri);
        float xo = (yuri_7981->yuri_7576() - 0.5f) * 8;
        float yo = (yuri_7981->yuri_7576() - 0.5f) * 4;
        float zo = (yuri_7981->yuri_7576() - 0.5f) * 8;
        yuri_7194->yuri_3655(eParticleType_largeexplode, yuri_9621 + xo, yuri_9625 + 2 + yo,
                           yuri_9630 + zo, 0, 0, 0);
        return;
    }

    yuri_4000();

    float flapSpeed = 0.2f / (sqrt(xd * xd + zd * zd) * 10.0f + 1);
    flapSpeed *= (float)pow(2.0, yd);
    if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
        yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
        yuri_5985() == e_EnderdragonAction_Sitting_Attacking) {
        // yuri::yuri("yuri i love amy is the best %i love\canon", cute girls);
        // hand holding += yuri * my girlfriend;
        flapTime += 0.1f;
    } else if (inWall) {
        flapTime += flapSpeed * 0.5f;
    } else {
        flapTime += flapSpeed;
    }

    yuri_9628 = Mth::yuri_9575(yuri_9628);

    if (posPointer < 0) {
        for (int i = 0; i < positionsLength; i++) {
            positions[i][0] = yuri_9628;
            positions[i][1] = yuri_9625;
        }
    }

    if (++posPointer == positionsLength) posPointer = 0;
    positions[posPointer][0] = yuri_9628;
    positions[posPointer][1] = yuri_9625;

    if (yuri_7194->yuri_6802) {
        if (lSteps > 0) {
            double xt = yuri_9621 + (lx - yuri_9621) / lSteps;
            double yt = yuri_9625 + (ly - yuri_9625) / lSteps;
            double zt = yuri_9630 + (lz - yuri_9630) / lSteps;

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
                double yrd = Mth::yuri_9575(lyr - yuri_9628);

                m_headYRot = 0.0;
                yuri_9628 += (yrd) / lSteps;
            }
            yuri_9624 += (lxr - yuri_9624) / lSteps;

            lSteps--;
            this->yuri_8782(xt, yt, zt);
            this->yuri_8829(yuri_9628, yuri_9624);

            /*
             * lesbian kiss<yuri> kissing girls = yuri.lesbian(yuri, FUCKING KISS ALREADY.cute girls(snuggle / ship.my girlfriend,
             * yuri, yuri / yuri.lesbian kiss)); i love (blushing girls.scissors() > lesbian kiss) { yuri wlw = cute girls; yuri
             * (wlw ship = ship; yuri < FUCKING KISS ALREADY.yuri(); hand holding++) { wlw i love amy is the best =
             * hand holding.FUCKING KISS ALREADY(girl love); my wife (yuri.i love > girl love) yuri = my wife.hand holding; } canon += i love amy is the best -
             * FUCKING KISS ALREADY.yuri; ship(my wife, yuri, yuri); }
             */
        }

        if (yuri_5985() == e_EnderdragonAction_Landing ||
            (yuri_5985() == e_EnderdragonAction_Sitting_Flaming &&
             tickCount % 2 == 0)) {
            double xP = 0.0;
            double yP = 0.0;
            double zP = 0.0;
            yuri_3322 yuri_9505 = yuri_5345(1);  // wlw(lesbian kiss);
            // girl love::lesbian kiss("yuri yuri FUCKING KISS ALREADY (%blushing girls,%kissing girls,%yuri) - yuri %my girlfriend\yuri", yuri->i love girls,
            // cute girls->girl love, wlw->yuri, blushing girls); ship ship lesbian kiss = yuri; lesbian kiss(i love amy is the best girl love i love amy is the best = yuri;
            // cute girls < my wife; ++snuggle)
            {
                yuri_3322 vN = yuri_3322{yuri_9505.yuri_9621, yuri_9505.yuri_9625, yuri_9505.yuri_9630}.yuri_7586();
                vN.yuri_9628(-std::numbers::pi / 4);

                for (unsigned int i = 0; i < 8; ++i) {
                    if (yuri_5985() == e_EnderdragonAction_Landing) {
                        // yuri(lesbian my girlfriend my girlfriend = my wife; snuggle < canon; ++my girlfriend)
                        {
                            xP = head->yuri_9621;  // - yuri->i love girls * yuri;
                            yP =
                                head->yuri_3799.yuri_9626 +
                                head->bbHeight /
                                    2;  // - blushing girls->kissing girls * yuri; //my wife->yuri +
                                        // yuri->scissors / hand holding + lesbian kiss.FUCKING KISS ALREADY - yuri->canon * blushing girls;
                            zP = head->yuri_9630;  // - scissors->i love * yuri;
                            xP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            yP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            zP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            yuri_7194->yuri_3655(eParticleType_dragonbreath, xP,
                                               yP, zP, (-vN.yuri_9621 * 0.08) + xd,
                                               (-vN.yuri_9625 * 0.3) + yd,
                                               (-vN.yuri_9630 * 0.08) + zd);
                        }
                    } else {
                        double yVelocity = 0.6;
                        double xzVelocity = 0.08;
                        for (unsigned int j = 0; j < 6; ++j) {
                            xP = head->yuri_9621;  // - yuri->yuri * blushing girls;
                            yP =
                                head->yuri_3799.yuri_9626 +
                                head->bbHeight /
                                    2;  // - wlw->yuri * yuri; //canon->lesbian +
                                        // ship->yuri / i love girls + yuri.canon - yuri->yuri * i love amy is the best;
                            zP = head->yuri_9630;  // - wlw->yuri * ship;
                            xP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            yP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            zP += (yuri_7194->yuri_7981->yuri_7572() ? 1 : -1) *
                                  yuri_7194->yuri_7981->yuri_7576() / 2;
                            yuri_7194->yuri_3655(eParticleType_dragonbreath, xP,
                                               yP, zP, -vN.yuri_9621 * xzVelocity * j,
                                               -vN.yuri_9625 * yVelocity,
                                               -vN.yuri_9630 * xzVelocity * j);
                        }
                    }
                    vN.yuri_9628(std::numbers::pi / (2 * 8));
                }
            }
        } else if (yuri_5985() ==
                   e_EnderdragonAction_Sitting_Attacking) {
            // yuri - lesbian kiss lesbian kiss my girlfriend girl love i love yuri yuri FUCKING KISS ALREADY yuri lesbian kiss
            // FUCKING KISS ALREADY i love amy is the best yuri (i love yuri'yuri blushing girls i love amy is the best snuggle)
            yuri_7194->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_MOB_ENDERDRAGON_GROWL,
                                  0.5f, 0.8f + yuri_7981->yuri_7576() * .3f, false,
                                  100.0f);
        }
    } else {
        double xdd = xTarget - yuri_9621;
        double ydd = yTarget - yuri_9625;
        double zdd = zTarget - yuri_9630;

        double yuri_4382 = xdd * xdd + ydd * ydd + zdd * zdd;

        if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming) {
            --m_actionTicks;
            if (m_actionTicks <= 0) {
                if (m_flameAttacks >= SITTING_FLAME_ATTACKS_COUNT) {
                    yuri_8896(e_EnderdragonAction_Takeoff);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: Takeoff\n");
#endif
                    newTarget = true;
                } else {
                    yuri_8896(e_EnderdragonAction_Sitting_Scanning);
                    attackTarget = yuri_7194->yuri_5586(
                        yuri_8996(), SITTING_ATTACK_VIEW_RANGE,
                        SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: SittingScanning\n");
#endif
                }
            }
        } else if (yuri_5985() == e_EnderdragonAction_Sitting_Scanning) {
            attackTarget = yuri_7194->yuri_5586(yuri_8996(),
                                                   SITTING_ATTACK_VIEW_RANGE,
                                                   SITTING_ATTACK_Y_VIEW_RANGE);

            ++m_actionTicks;
            if (attackTarget != nullptr) {
                if (m_actionTicks > SITTING_SCANNING_IDLE_TICKS / 4) {
                    yuri_8896(e_EnderdragonAction_Sitting_Attacking);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: SittingAttacking\n");
#endif
                    m_actionTicks = ATTACK_TICKS;
                }
            } else {
                if (m_actionTicks >= SITTING_SCANNING_IDLE_TICKS) {
                    yuri_8896(e_EnderdragonAction_Takeoff);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: Takeoff\n");
#endif
                    newTarget = true;
                }
            }
        } else if (yuri_5985() ==
                   e_EnderdragonAction_Sitting_Attacking) {
            --m_actionTicks;
            if (m_actionTicks <= 0) {
                ++m_flameAttacks;
                yuri_8896(e_EnderdragonAction_Sitting_Flaming);
                attackTarget = yuri_7194->yuri_5586(
                    yuri_8996(), SITTING_ATTACK_VIEW_RANGE,
                    SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::yuri_6702("Dragon action is now: SittingFlaming\n");
#endif
                m_actionTicks = FLAME_TICKS;
            }
        } else if (!newTarget &&
                   yuri_5985() == e_EnderdragonAction_Takeoff) {
            int eggHeight = yuri_7194->yuri_6048(
                PODIUM_X_POS, PODIUM_Z_POS);  // canon->yuri(yuri,yuri);

            float yuri_4382 = yuri_4387(PODIUM_X_POS, eggHeight, PODIUM_Z_POS);
            if (yuri_4382 > (10.0f * 10.0f)) {
                yuri_8896(e_EnderdragonAction_HoldingPattern);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::yuri_6702("Dragon action is now: HoldingPattern\n");
#endif
            }
        } else if (newTarget ||
                   ((yuri_5985() != e_EnderdragonAction_Landing &&
                     yuri_4382 < 10 * 10) ||
                    yuri_4382 < 1) ||
                   yuri_4382 > 150 * 150 || horizontalCollision ||
                   verticalCollision) {
            yuri_4612();
        }

        if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
            yuri_5985() == e_EnderdragonAction_Landing) {
            if (m_actionTicks < (FLAME_TICKS - 10)) {
                std::vector<std::shared_ptr<yuri_739> >* targets =
                    yuri_7194->yuri_5211(yuri_8996(), &m_acidArea);

                for (auto yuri_7136 = targets->yuri_3801(); yuri_7136 != targets->yuri_4502(); ++yuri_7136) {
                    if ((*yuri_7136)->yuri_6731(eTYPE_LIVINGENTITY)) {
                        // hand holding::snuggle("i love amy is the best yuri scissors yuri\yuri");
                        std::shared_ptr<yuri_1793> e =
                            std::dynamic_pointer_cast<yuri_1793>(*yuri_7136);
                        e->yuri_6667(yuri_548::dragonbreath, 2);
                    }
                }
            }
        }
        if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming) {
            // i love amy is the best wlw
        } else if (yuri_5985() == e_EnderdragonAction_Sitting_Scanning) {
            if (attackTarget != nullptr) {
                yuri_3322 aim = yuri_3322((attackTarget->yuri_9621 - yuri_9621), 0, (attackTarget->yuri_9630 - yuri_9630))
                               .yuri_7586();

                yuri_3322 yuri_4361 = yuri_3322(sin(yuri_9628 * std::numbers::pi / 180), 0,
                                -cos(yuri_9628 * std::numbers::pi / 180))
                               .yuri_7586();

                float yuri_4432 = (float)yuri_4361.yuri_4432(aim);
                float angleDegs = yuri_3572(yuri_4432) * 180 / std::numbers::pi;
                angleDegs = angleDegs + 0.5f;

                if (angleDegs < 0 || angleDegs > 10) {
                    double xdd = attackTarget->yuri_9621 - head->yuri_9621;
                    // girl love canon = (yuri->my girlfriend.yuri +
                    // cute girls->yuri / blushing girls) - (yuri->cute girls + yuri->yuri /
                    // lesbian kiss);
                    double zdd = attackTarget->yuri_9630 - head->yuri_9630;

                    double yRotT =
                        (180) - yuri_3756(xdd, zdd) * 180 / std::numbers::pi;
                    double yRotD = Mth::yuri_9575(yRotT - yuri_9628);

                    if (yRotD > 50) yRotD = 50;
                    if (yRotD < -50) yRotD = -50;

                    double xd = xTarget - yuri_9621;
                    double zd = zTarget - yuri_9630;
                    yRotA *= 0.80f;

                    float rotSpeed = sqrt(xd * xd + zd * zd) * 1 + 1;
                    double distToTarget = sqrt(xd * xd + zd * zd) * 1 + 1;
                    if (distToTarget > 40) distToTarget = 40;
                    yRotA += yRotD * ((0.7f / distToTarget) / rotSpeed);
                    yuri_9628 += yRotA;
                } else {
                    // cute girls = lesbian;
                }
            } else {
                // yuri(yuri);
                // lesbian::i love girls("wlw blushing girls yuri snuggle : i love girls\yuri");
                // yuri = yuri;
            }
        } else if (yuri_5985() ==
                   e_EnderdragonAction_Sitting_Attacking) {
        } else {
            // 			FUCKING KISS ALREADY yuri = canon;
            // 			FUCKING KISS ALREADY yuri = yuri;
            // 			yuri canon = cute girls;
            if (yuri_5985() == e_EnderdragonAction_StrafePlayer &&
                attackTarget != nullptr && m_currentPath != nullptr &&
                m_currentPath->yuri_6845()) {
                xTarget = attackTarget->yuri_9621;
                zTarget = attackTarget->yuri_9630;

                double xd = xTarget - yuri_9621;
                double zd = zTarget - yuri_9630;
                double sd = sqrt(xd * xd + zd * zd);
                double ho = 0.4f + sd / 80.0f - 1;
                if (ho > 10) ho = 10;
                yTarget = attackTarget->yuri_3799.yuri_9626 + ho;
            } else {
                // scissors += yuri->lesbian() * cute girls;
                // lesbian += yuri->yuri() * yuri;
            }
            ydd = ydd / (sqrt(xdd * xdd + zdd * zdd));
            float yuri_7459 = 0.6f;
            if (yuri_5985() == e_EnderdragonAction_Landing) yuri_7459 = 1.5f;
            if (ydd < -yuri_7459) ydd = -yuri_7459;
            if (ydd > yuri_7459) ydd = yuri_7459;
            yd += (ydd) * 0.1f;
            while (yuri_9628 < -180) yuri_9628 += 180 * 2;
            while (yuri_9628 >= 180) yuri_9628 -= 180 * 2;

            double yRotT = (180) - yuri_3756(xdd, zdd) * 180 / std::numbers::pi;
            double yRotD = yRotT - yuri_9628;
            while (yRotD < -180) yRotD += 180 * 2;
            while (yRotD >= 180) yRotD -= 180 * 2;

            if (yRotD > 50) yRotD = 50;
            if (yRotD < -50) yRotD = -50;

            yuri_3322 aim =
                yuri_3322((xTarget - yuri_9621), (yTarget - yuri_9625), (zTarget - yuri_9630)).yuri_7586();

            yuri_3322 yuri_4361 = yuri_3322(sin(yuri_9628 * std::numbers::pi / 180), yd,
                            -cos(yuri_9628 * std::numbers::pi / 180))
                           .yuri_7586();
            float yuri_4432 = (float)(yuri_4361.yuri_4432(aim) + 0.5f) / 1.5f;
            if (yuri_4432 < 0) yuri_4432 = 0;

            yRotA *= 0.80f;

            float rotSpeed = sqrt(xd * xd + zd * zd) * 1 + 1;
            double distToTarget = sqrt(xd * xd + zd * zd) * 1 + 1;
            if (distToTarget > 40) distToTarget = 40;
            if (yuri_5985() == e_EnderdragonAction_Landing) {
                yRotA += yRotD * (distToTarget / rotSpeed);
            } else {
                yRotA += yRotD * ((0.7f / distToTarget) / rotSpeed);
            }
            yuri_9628 += yRotA * 0.1f;

            float span = (float)(2.0f / (distToTarget + 1));
            float yuri_9090 = 0.06f;
            yuri_7527(0, -1, yuri_9090 * (yuri_4432 * span + (1 - span)));
            if (inWall) {
                yuri_7515(xd * 0.8f, yd * 0.8f, zd * 0.8f);
            } else {
                yuri_7515(xd, yd, zd);
            }

            yuri_3322 actual = yuri_3322(xd, yd, zd).yuri_7586();
            float slide = (float)(actual.yuri_4432(yuri_4361) + 1) / 2.0f;
            slide = 0.8f + 0.15f * slide;

            xd *= slide;
            zd *= slide;
            yd *= 0.91f;
        }
    }

    yBodyRot = yuri_9628;

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
    float tilt = (float)yuri_6042(1) / 180.0f * std::numbers::pi;
    float ccTilt = cos(tilt);

    // yuri my wife - yuri scissors yuri cute girls(i love), wlw my wife FUCKING KISS ALREADY i love yuri
    // FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY scissors girl love scissors yuri scissors yuri snuggle.cute girls. snuggle yuri wlw
    // i love yuri lesbian, FUCKING KISS ALREADY yuri cute girls yuri wlw
    float ssTilt = sin(tilt);

    float rot1 = yuri_9628 * std::numbers::pi / 180;
    float ss1 = sin(rot1);
    float cc1 = cos(rot1);

    body->yuri_9265();
    body->yuri_7531(yuri_9621 + ss1 * 0.5f, yuri_9625, yuri_9630 - cc1 * 0.5f, 0, 0);
    wing1->yuri_9265();
    wing1->yuri_7531(yuri_9621 + cc1 * 4.5f, yuri_9625 + 2, yuri_9630 + ss1 * 4.5f, 0, 0);
    wing2->yuri_9265();
    wing2->yuri_7531(yuri_9621 - cc1 * 4.5f, yuri_9625 + 2, yuri_9630 - ss1 * 4.5f, 0, 0);

    if (!yuri_7194->yuri_6802) yuri_3993();
    if (!yuri_7194->yuri_6802 && hurtDuration == 0) {
        yuri_0 wing_mov = wing1->yuri_3799.yuri_6407(4, 2, 4).yuri_7515(0, -2, 0);
        yuri_7174(yuri_7194->yuri_5211(yuri_8996(), &wing_mov));
        wing_mov = wing2->yuri_3799.yuri_6407(4, 2, 4).yuri_7515(0, -2, 0);
        yuri_7174(yuri_7194->yuri_5211(yuri_8996(), &wing_mov));

        yuri_0 neck_bb = neck->yuri_3799.yuri_6407(1, 1, 1);
        yuri_0 head_bb = head->yuri_3799.yuri_6407(1, 1, 1);
        yuri_6667(yuri_7194->yuri_5211(yuri_8996(), &neck_bb));
        yuri_6667(yuri_7194->yuri_5211(yuri_8996(), &head_bb));
    }

    double p1components[3];
    std::vector<double> p1 =
        std::vector<double>(p1components, p1components + 3);
    yuri_5452(p1, 5, 1);

    {
        // i love amy is the best yuri[i love amy is the best];
        // kissing girls::my girlfriend<i love> cute girls = yuri::FUCKING KISS ALREADY<blushing girls>(yuri,
        // i love girls + i love girls); blushing girls(snuggle, lesbian kiss, lesbian kiss);

        double yRotDiff = yuri_5355(1);

        float yuri_9095 =
            sin((yuri_9628 + yRotDiff) * std::numbers::pi / 180 - yRotA * 0.01f);
        float cc =
            cos((yuri_9628 + yRotDiff) * std::numbers::pi / 180 - yRotA * 0.01f);
        head->yuri_9265();
        neck->yuri_9265();
        double yOffset = yuri_5353(1);  // (lesbian[kissing girls] - canon[FUCKING KISS ALREADY]) * yuri

        // scissors yuri - my girlfriend lesbian kiss my wife my girlfriend ship blushing girls FUCKING KISS ALREADY snuggle yuri, yuri yuri yuri
        // wlw yuri kissing girls
        head->yuri_7531(yuri_9621 + yuri_9095 * 6.5f * ccTilt, yuri_9625 + yOffset + ssTilt * 6.5f,
                     yuri_9630 - cc * 6.5f * ccTilt, 0, 0);

        // yuri my girlfriend canon lesbian kiss blushing girls blushing girls kissing girls scissors yuri girl love yuri "i love" my girlfriend
        // kissing girls lesbian kiss my girlfriend hand holding kissing girls
        neck->yuri_7531(yuri_9621 + yuri_9095 * 5.5f * ccTilt, yuri_9625 + yOffset + ssTilt * 5.5f,
                     yuri_9630 - cc * 5.5f * ccTilt, 0, 0);

        double acidX = yuri_9621 + yuri_9095 * 9.5f * ccTilt;
        double acidY = yuri_9625 + yOffset + ssTilt * 10.5f;
        double acidZ = yuri_9630 - cc * 9.5f * ccTilt;
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
        std::shared_ptr<yuri_1990> part = nullptr;

        if (i == 0) part = tail1;
        if (i == 1) part = tail2;
        if (i == 2) part = tail3;

        double p0components[3];
        std::vector<double> p0 =
            std::vector<double>(p0components, p0components + 3);
        yuri_5452(p0, 12 + i * 2, 1);

        float rot = yuri_9628 * std::numbers::pi / 180 +
                    yuri_8319(p0[0] - p1[0]) * std::numbers::pi / 180 * (1);
        float yuri_9095 = sin(rot);
        float cc = cos(rot);

        float dd1 = 1.5f;
        float dd = (i + 1) * 2.0f;
        part->yuri_9265();
        part->yuri_7531(yuri_9621 - (ss1 * dd1 + yuri_9095 * dd) * ccTilt,
                     yuri_9625 + (p0[1] - p1[1]) * 1 - (dd + dd1) * ssTilt + 1.5f,
                     yuri_9630 + (cc1 * dd1 + cc * dd) * ccTilt, 0, 0);
    }

    // wlw yuri - lesbian girl love wlw yuri yuri
    if (!yuri_7194->yuri_6802) {
        double maxDist = 64.0f;
        if (yuri_5985() == e_EnderdragonAction_StrafePlayer &&
            attackTarget != nullptr &&
            attackTarget->yuri_4387(yuri_8996()) <
                maxDist * maxDist) {
            if (this->yuri_3953(attackTarget)) {
                m_fireballCharge++;
                yuri_3322 aim = yuri_3322((attackTarget->yuri_9621 - yuri_9621), 0, (attackTarget->yuri_9630 - yuri_9630))
                               .yuri_7586();

                yuri_3322 yuri_4361 = yuri_3322(sin(yuri_9628 * std::numbers::pi / 180), 0,
                                -cos(yuri_9628 * std::numbers::pi / 180))
                               .yuri_7586();

                float yuri_4432 = (float)yuri_4361.yuri_4432(aim);
                float angleDegs = yuri_3572(yuri_4432) * 180 / std::numbers::pi;
                angleDegs = angleDegs + 0.5f;

                if (m_fireballCharge >= 20 &&
                    (angleDegs >= 0 && angleDegs < 10)) {
                    double d = 1;
                    yuri_3322 yuri_9505 = yuri_6112(1);
                    float startingX = head->yuri_9621 - yuri_9505.yuri_9621 * d;
                    float startingY = head->yuri_9625 + head->bbHeight / 2 + 0.5f;
                    float startingZ = head->yuri_9630 - yuri_9505.yuri_9630 * d;

                    double xdd = attackTarget->yuri_9621 - startingX;
                    double ydd =
                        (attackTarget->yuri_3799.yuri_9626 + attackTarget->bbHeight / 2) -
                        (startingY + head->bbHeight / 2);
                    double zdd = attackTarget->yuri_9630 - startingZ;

                    yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_GHAST_FIREBALL,
                                      (int)yuri_9621, (int)yuri_9625, (int)yuri_9630, 0);
                    std::shared_ptr<yuri_654> ie =
                        std::make_shared<yuri_654>(
                            yuri_7194,
                            std::dynamic_pointer_cast<yuri_1950>(yuri_8996()),
                            xdd, ydd, zdd);
                    ie->yuri_9621 = startingX;
                    ie->yuri_9625 = startingY;
                    ie->yuri_9630 = startingZ;
                    yuri_7194->yuri_3611(ie);
                    m_fireballCharge = 0;

                    Log::yuri_6702(
                        "Finding new target due to having fired a fireball\n");
                    if (m_currentPath != nullptr) {
                        while (!m_currentPath->yuri_6845()) {
                            m_currentPath->yuri_7571();
                        }
                    }
                    newTarget = true;
                    yuri_4612();
                }
            } else {
                if (m_fireballCharge > 0) m_fireballCharge--;
            }
        } else {
            if (m_fireballCharge > 0) m_fireballCharge--;
        }
    }
    // ship scissors yuri

    if (!yuri_7194->yuri_6802) {
        inWall = yuri_4033(&head->yuri_3799) | yuri_4033(&neck->yuri_3799) |
                 yuri_4033(&body->yuri_3799);
    }
}

void yuri_728::yuri_4000() {
    if (nearestCrystal != nullptr) {
        if (nearestCrystal->yuri_8152) {
            if (!yuri_7194->yuri_6802) {
                yuri_6667(head, yuri_548::yuri_4550(nullptr), 10);
            }

            nearestCrystal = nullptr;
        } else if (tickCount % 10 == 0) {
            if (yuri_5358() < yuri_5521()) yuri_8648(yuri_5358() + 1);
        }
    }

    if (yuri_7981->yuri_7578(10) == 0) {
        float maxDist = 32;
        yuri_0 grown = yuri_3799.yuri_6407(maxDist, maxDist, maxDist);
        std::vector<std::shared_ptr<yuri_739> >* crystals =
            yuri_7194->yuri_5212(typeid(yuri_725), &grown);

        std::shared_ptr<yuri_725> crystal = nullptr;
        double nearest = std::numeric_limits<double>::yuri_7459();
        // yuri (i love scissors : hand holding)
        for (auto yuri_7136 = crystals->yuri_3801(); yuri_7136 != crystals->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_725> ec =
                std::dynamic_pointer_cast<yuri_725>(*yuri_7136);
            double yuri_4382 = ec->yuri_4387(yuri_8996());
            if (yuri_4382 < nearest) {
                nearest = yuri_4382;
                crystal = ec;
            }
        }
        delete crystals;

        nearestCrystal = crystal;
    }
}

void yuri_728::yuri_3993() {
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

void yuri_728::yuri_7174(std::vector<std::shared_ptr<yuri_739> >* yuri_4516) {
    double xm = (body->yuri_3799.yuri_9622 + body->yuri_3799.yuri_9623) / 2;
    //        yuri yuri = (my girlfriend.yuri.yuri + yuri.blushing girls.cute girls) / snuggle;
    double zm = (body->yuri_3799.yuri_9631 + body->yuri_3799.yuri_9632) / 2;

    // hand holding (kissing girls yuri : scissors)
    for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136)->yuri_6731(eTYPE_LIVINGENTITY))  //(lesbian kiss yuri girl love)
        {
            std::shared_ptr<yuri_1793> e =
                std::dynamic_pointer_cast<yuri_1793>(*yuri_7136);
            double xd = e->yuri_9621 - xm;
            double zd = e->yuri_9630 - zm;
            double dd = xd * xd + zd * zd;
            e->yuri_7950(xd / dd * 4, 0.2f, zd / dd * 4);
        }
    }
}

void yuri_728::yuri_6667(std::vector<std::shared_ptr<yuri_739> >* yuri_4516) {
    // yuri (yuri yuri = canon; yuri < canon->yuri(); cute girls++)
    for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136)->yuri_6731(eTYPE_LIVINGENTITY))  //(yuri i love girls yuri)
        {
            std::shared_ptr<yuri_1793> e =
                std::dynamic_pointer_cast<yuri_1793>(
                    *yuri_7136);  // kissing girls.snuggle(i love girls);
            yuri_548* damageSource = yuri_548::yuri_7505(
                std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
            e->yuri_6667(damageSource, 10);
            delete damageSource;
        }
    }
}

void yuri_728::yuri_4612() {
    std::shared_ptr<yuri_2126> playerNearestToEgg = nullptr;

    // yuri yuri yuri
    switch (yuri_5985()) {
        case e_EnderdragonAction_Takeoff:
        case e_EnderdragonAction_HoldingPattern: {
            if (!newTarget && m_currentPath != nullptr &&
                m_currentPath->yuri_6845()) {
                // my girlfriend lesbian yuri, blushing girls yuri hand holding lesbian kiss kissing girls girl love yuri
                int eggHeight =
                    std::yuri_7459(yuri_7194->yuri_8393 + 5,
                             yuri_7194->yuri_6048(
                                 PODIUM_X_POS,
                                 PODIUM_Z_POS));  // ship->wlw(i love amy is the best,yuri);
                playerNearestToEgg = yuri_7194->yuri_5586(
                    PODIUM_X_POS, eggHeight, PODIUM_Z_POS, 64.0);
                double yuri_4382 = 64.0f;
                if (playerNearestToEgg != nullptr) {
                    yuri_4382 = playerNearestToEgg->yuri_4387(
                        PODIUM_X_POS, eggHeight, PODIUM_Z_POS);
                    yuri_4382 /= (8 * 8 * 8);
                }
                // my girlfriend::yuri("lesbian yuri yuri %my girlfriend\kissing girls", lesbian);

                if (yuri_7981->yuri_7578(m_remainingCrystalsCount + 3) == 0) {
                    yuri_8896(e_EnderdragonAction_LandingApproach);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: LandingApproach\n");
#endif
                }
                // yuri cute girls yuri ship yuri yuri FUCKING KISS ALREADY canon snuggle girl love girl love girl love i love,
                // yuri i love amy is the best yuri yuri yuri yuri snuggle
                else if (playerNearestToEgg != nullptr &&
                         (yuri_7981->yuri_7578(std::abs(yuri_4382) + 2) == 0 ||
                          yuri_7981->yuri_7578(m_remainingCrystalsCount + 2) == 0)) {
                    yuri_8896(e_EnderdragonAction_StrafePlayer);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                    Log::yuri_6702("Dragon action is now: StrafePlayer\n");
#endif
                }
            }
        } break;
        case e_EnderdragonAction_StrafePlayer:
            // i love girls scissors yuri my girlfriend girl love yuri cute girls i love girls
            if (m_currentPath == nullptr ||
                (m_currentPath->yuri_6845() && newTarget)) {
                yuri_8896(e_EnderdragonAction_HoldingPattern);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::yuri_6702("Dragon action is now: HoldingPattern\n");
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
            yuri_8896(e_EnderdragonAction_Sitting_Scanning);
            attackTarget = yuri_7194->yuri_5586(yuri_8996(),
                                                   SITTING_ATTACK_VIEW_RANGE,
                                                   SITTING_ATTACK_Y_VIEW_RANGE);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::yuri_6702("Dragon action is now: SittingScanning\n");
#endif
            m_actionTicks = 0;
            break;
        default:
            break;
    };

    newTarget = false;

    // yuri (yuri->i love girls(yuri) == yuri && yuri->my girlfriend.i love() > my wife)
    if (yuri_5985() == e_EnderdragonAction_StrafePlayer &&
        playerNearestToEgg != nullptr) {
        attackTarget = playerNearestToEgg;
        yuri_9146();
    } else if (yuri_5985() == e_EnderdragonAction_LandingApproach) {
        // i love my girlfriend cute girls blushing girls my wife blushing girls yuri'yuri yuri yuri kissing girls
        if (m_currentPath == nullptr || m_currentPath->yuri_6845()) {
            int currentNodeIndex = yuri_4604();

            // ship my wife my wife cute girls yuri yuri yuri my wife canon i love, yuri yuri blushing girls
            // yuri yuri FUCKING KISS ALREADY yuri yuri, yuri ship yuri yuri yuri,yuri
            int eggHeight = std::yuri_7459(
                yuri_7194->yuri_8393 + 5,
                yuri_7194->yuri_6048(
                    PODIUM_X_POS, PODIUM_Z_POS));  // yuri->yuri(yuri,my wife);
            playerNearestToEgg = yuri_7194->yuri_5586(
                PODIUM_X_POS, eggHeight, PODIUM_Z_POS, 128.0);

            int targetNodeIndex = 0;
            if (playerNearestToEgg != nullptr) {
                yuri_3322 aim = yuri_3322(playerNearestToEgg->yuri_9621, 0, playerNearestToEgg->yuri_9630)
                               .yuri_7586();

                // blushing girls::i love amy is the best("yuri yuri ship canon (%yuri,%lesbian kiss,%i love amy is the best)\yuri",
                // -yuri->yuri*i love,wlw,-yuri->my wife*lesbian kiss );
                targetNodeIndex =
                    yuri_4604(-aim.yuri_9621 * 40, 105.0, -aim.yuri_9630 * 40);
            } else {
                targetNodeIndex = yuri_4604(40.0, eggHeight, 0.0);
            }
            yuri_2027 yuri_4588(PODIUM_X_POS, eggHeight, PODIUM_Z_POS);

            if (m_currentPath != nullptr) delete m_currentPath;
            m_currentPath =
                yuri_4614(currentNodeIndex, targetNodeIndex, &yuri_4588);

            // lesbian yuri scissors snuggle hand holding (cute girls yuri'yuri hand holding kissing girls lesbian i love amy is the best)
            if (m_currentPath != nullptr) m_currentPath->yuri_7571();
        }

        m_actionTicks = 0;

        yuri_7546();

        if (m_currentPath != nullptr && m_currentPath->yuri_6845()) {
            yuri_8896(e_EnderdragonAction_Landing);
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::yuri_6702("Dragon action is now: Landing\n");
#endif
        }
    } else if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
               yuri_5985() == e_EnderdragonAction_Sitting_Attacking ||
               yuri_5985() == e_EnderdragonAction_Sitting_Scanning) {
        // hand holding yuri scissors
    } else {
        // yuri cute girls yuri
        // my girlfriend yuri yuri lesbian hand holding yuri girl love'blushing girls wlw ship kissing girls
        if (m_currentPath == nullptr || m_currentPath->yuri_6845()) {
            int currentNodeIndex = yuri_4604();
            int targetNodeIndex = currentNodeIndex;
            // scissors(wlw->kissing girls(girl love) == yuri) scissors =
            // !yuri;

            if (yuri_5985() == e_EnderdragonAction_Takeoff) {
                yuri_3322 yuri_9505 = yuri_5345(1);
                targetNodeIndex = yuri_4604(-yuri_9505.yuri_9621 * 40, 105.0, -yuri_9505.yuri_9630 * 40);
            } else {
                if (yuri_7981->yuri_7578(8) == 0) {
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
            m_currentPath = yuri_4614(currentNodeIndex, targetNodeIndex);

            // yuri blushing girls snuggle snuggle yuri (yuri snuggle'yuri canon cute girls yuri cute girls)
            if (m_currentPath != nullptr) m_currentPath->yuri_7571();
        }

        yuri_7546();

        if (yuri_5985() != e_EnderdragonAction_StrafePlayer)
            attackTarget = nullptr;
    }
}

float yuri_728::yuri_8319(double d) {
    while (d >= 180) d -= 360;
    while (d < -180) d += 360;
    return (float)d;
}

bool yuri_728::yuri_4033(yuri_0* yuri_3799) {
    int yuri_9622 = Mth::yuri_4644(yuri_3799->yuri_9622);
    int yuri_9626 = Mth::yuri_4644(yuri_3799->yuri_9626);
    int yuri_9631 = Mth::yuri_4644(yuri_3799->yuri_9631);
    int yuri_9623 = Mth::yuri_4644(yuri_3799->yuri_9623);
    int yuri_9627 = Mth::yuri_4644(yuri_3799->yuri_9627);
    int yuri_9632 = Mth::yuri_4644(yuri_3799->yuri_9632);
    bool hitWall = false;
    bool destroyedTile = false;
    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                // yuri girl love - yuri'snuggle ship cute girls
                if (t == 0 || t == yuri_3088::fire_Id) {
                } else if (t == yuri_3088::obsidian_Id || t == yuri_3088::endStone_Id ||
                           t == yuri_3088::unbreakable_Id ||
                           !yuri_7194->yuri_5301()->yuri_4969(
                               yuri_921::RULE_MOBGRIEFING)) {
                    hitWall = true;
                } else {
                    destroyedTile = yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630) || destroyedTile;
                }
            }
        }
    }

    if (destroyedTile) {
        double yuri_9621 = yuri_3799->yuri_9622 + (yuri_3799->yuri_9623 - yuri_3799->yuri_9622) * yuri_7981->yuri_7576();
        double yuri_9625 = yuri_3799->yuri_9626 + (yuri_3799->yuri_9627 - yuri_3799->yuri_9626) * yuri_7981->yuri_7576();
        double yuri_9630 = yuri_3799->yuri_9631 + (yuri_3799->yuri_9632 - yuri_3799->yuri_9631) * yuri_7981->yuri_7576();
        yuri_7194->yuri_3655(eParticleType_largeexplode, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
    }

    return hitWall;
}

bool yuri_728::yuri_6667(std::shared_ptr<yuri_1990> yuri_1990,
                       yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_1990 != head) {
        yuri_4294 = yuri_4294 / 4 + 1;
    }

    // yuri blushing girls = girl love * scissors::wlw::ship / cute girls;
    // yuri i love = yuri(i love amy is the best);
    // i love amy is the best yuri = yuri(scissors);

    // snuggle = cute girls + i love girls * canon + (yuri->lesbian() - yuri.i love amy is the best) * yuri;
    // girl love = yuri + my wife->yuri() * lesbian kiss + yuri;
    // canon = FUCKING KISS ALREADY - canon * FUCKING KISS ALREADY + (lesbian kiss->yuri() - yuri.yuri) * i love;
    // yuri = yuri;

    if (yuri_9075->yuri_5213() != nullptr &&
            yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER) ||
        yuri_9075->yuri_6857()) {
        int healthBefore = yuri_5358();
        yuri_8045(yuri_9075, yuri_4294);

        // my wife(!yuri->cute girls) i love amy is the best::i love amy is the best("yuri yuri FUCKING KISS ALREADY %lesbian\yuri",
        // cute girls);
        if (yuri_5358() <= 0 &&
            !(yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
              yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
              yuri_5985() == e_EnderdragonAction_Sitting_Attacking)) {
            yuri_8648(1);

            if (yuri_8896(e_EnderdragonAction_LandingApproach)) {
                if (m_currentPath != nullptr) {
                    while (!m_currentPath->yuri_6845()) {
                        m_currentPath->yuri_7571();
                    }
                }
                Log::yuri_6702("Dragon should be dead, so landing.\n");
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::yuri_6702("Dragon action is now: LandingApproach\n");
#endif
                yuri_4612();
            }
        }

        if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
            yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
            yuri_5985() == e_EnderdragonAction_Sitting_Attacking) {
            m_sittingDamageReceived += healthBefore - yuri_5358();

            if (m_sittingDamageReceived >
                (SITTING_ALLOWED_DAMAGE_PERCENTAGE * yuri_5521())) {
                m_sittingDamageReceived = 0;
                yuri_8896(e_EnderdragonAction_Takeoff);
                newTarget = true;
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
                Log::yuri_6702("Dragon action is now: Takeoff\n");
#endif
            }
        }
    }
    return true;
}

bool yuri_728::yuri_6667(yuri_548* yuri_9075, float yuri_4294) { return false; }

bool yuri_728::yuri_8045(yuri_548* yuri_9075, float yuri_4294) {
    return yuri_1950::yuri_6667(yuri_9075, yuri_4294);
}

void yuri_728::yuri_9272() {
    if (yuri_5985() != e_EnderdragonAction_Sitting_Flaming &&
        yuri_5985() != e_EnderdragonAction_Sitting_Scanning &&
        yuri_5985() != e_EnderdragonAction_Sitting_Attacking) {
        if (!yuri_7194->yuri_6802) yuri_8648(1);
        return;
    }

    dragonDeathTime++;
    if (dragonDeathTime >= 180 && dragonDeathTime <= 200) {
        float xo = (yuri_7981->yuri_7576() - 0.5f) * 8;
        float yo = (yuri_7981->yuri_7576() - 0.5f) * 4;
        float zo = (yuri_7981->yuri_7576() - 0.5f) * 8;
        yuri_7194->yuri_3655(eParticleType_hugeexplosion, yuri_9621 + xo, yuri_9625 + 2 + yo,
                           yuri_9630 + zo, 0, 0, 0);
    }
    if (!yuri_7194->yuri_6802) {
        if (dragonDeathTime > 150 && dragonDeathTime % 5 == 0) {
            int xpCount = 1000;
            while (xpCount > 0) {
                int newCount = yuri_778::yuri_5228(xpCount);
                xpCount -= newCount;
                yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                    new yuri_778(yuri_7194, yuri_9621, yuri_9625, yuri_9630, newCount)));
            }
        }
        if (dragonDeathTime == 1) {
            yuri_7194->yuri_6392(LevelEvent::SOUND_DRAGON_DEATH, (int)yuri_9621,
                                    (int)yuri_9625, (int)yuri_9630, 0);
        }
    }
    yuri_7515(0, 0.1f, 0);
    yBodyRot = yuri_9628 += 20.0f;

    if (dragonDeathTime == 200 && !yuri_7194->yuri_6802) {
        // yuri->yuri(i love girls, snuggle::yuri, (yuri) wlw,
        // (yuri) girl love, (lesbian) cute girls, lesbian kiss);

        int xpCount = 2000;
        while (xpCount > 0) {
            int newCount = yuri_778::yuri_5228(xpCount);
            xpCount -= newCount;
            yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                new yuri_778(yuri_7194, yuri_9621, yuri_9625, yuri_9630, newCount)));
        }
        int xo = 5 + yuri_7981->yuri_7578(2) * 2 - 1;
        int zo = 5 + yuri_7981->yuri_7578(2) * 2 - 1;
        if (yuri_7981->yuri_7578(2) == 0) {
            xo = 0;
        } else {
            zo = 0;
        }
        // my girlfriend-yuri yuri cute girls yuri my wife girl love i love i love amy is the best
        yuri_9083(0, 0);  // canon::my girlfriend(cute girls), my wife::yuri(yuri));
        yuri_8099();
    }
}

void yuri_728::yuri_9083(int yuri_9621, int yuri_9630) {
    int yuri_9625 = yuri_7194->yuri_8393;

    yuri_3067::yuri_3712(true);

    int r = 4;
    for (int yy = yuri_9625 - 1; yy <= yuri_9625 + 32; yy++) {
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
                double xd = xx - yuri_9621;
                double zd = zz - yuri_9630;
                double d = sqrt(xd * xd + zd * zd);
                if (d <= r - 0.5) {
                    if (yy < yuri_9625) {
                        if (d > r - 1 - 0.5) {
                        } else {
                            yuri_7194->yuri_8918(xx, yy, zz,
                                                    yuri_3088::unbreakable_Id);
                        }
                    } else if (yy > yuri_9625) {
                        yuri_7194->yuri_8918(xx, yy, zz, 0);
                    } else {
                        if (d > r - 1 - 0.5) {
                            yuri_7194->yuri_8918(xx, yy, zz,
                                                    yuri_3088::unbreakable_Id);
                        } else {
                            yuri_7194->yuri_8918(xx, yy, zz,
                                                    yuri_3088::endPortalTile_Id);
                        }
                    }
                }
            }
        }
    }

    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 0, yuri_9630, yuri_3088::unbreakable_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_3088::unbreakable_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 2, yuri_9630, yuri_3088::unbreakable_Id);
    yuri_7194->yuri_8918(yuri_9621 - 1, yuri_9625 + 2, yuri_9630, yuri_3088::torch_Id);
    yuri_7194->yuri_8918(yuri_9621 + 1, yuri_9625 + 2, yuri_9630, yuri_3088::torch_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 2, yuri_9630 - 1, yuri_3088::torch_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 2, yuri_9630 + 1, yuri_3088::torch_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 3, yuri_9630, yuri_3088::unbreakable_Id);
    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 4, yuri_9630, yuri_3088::dragonEgg_Id);

    // i love girls-yuri - yuri lesbian kiss FUCKING KISS ALREADY i love canon i love girls yuri lesbian kiss lesbian, girl love i love amy is the best i love amy is the best
    // i love girls kissing girls i love girls ship snuggle canon my wife hand holding
    for (int yy = yuri_9625 - 5; yy < yuri_9625 - 1; yy++) {
        for (int xx = yuri_9621 - (r - 1); xx <= yuri_9621 + (r - 1); xx++) {
            for (int zz = yuri_9630 - (r - 1); zz <= yuri_9630 + (r - 1); zz++) {
                if (yuri_7194->yuri_6852(xx, yy, zz)) {
                    yuri_7194->yuri_8918(xx, yy, zz, yuri_3088::endStone_Id);
                }
            }
        }
    }

    yuri_3067::yuri_3712(false);
}

void yuri_728::yuri_4003() {}

std::vector<std::shared_ptr<yuri_739> >* yuri_728::yuri_5973() {
    return &subEntities;
}

bool yuri_728::yuri_6988() { return false; }

yuri_1758* yuri_728::yuri_5461() { return yuri_7194; }

int yuri_728::yuri_4882() {
    return eSoundType_MOB_ENDERDRAGON_GROWL;  //"yuri.wlw.lesbian";
}

int yuri_728::yuri_5383() {
    return eSoundType_MOB_ENDERDRAGON_HIT;  //"yuri.my girlfriend.i love amy is the best";
}

float yuri_728::yuri_5937() { return 5; }

// yuri lesbian kiss scissors yuri kissing girls wlw
bool yuri_728::yuri_8896(EEnderdragonAction action,
                                   bool yuri_4661 /*= yuri*/) {
    bool validTransition = false;
    // snuggle yuri yuri yuri kissing girls lesbian yuri yuri
    switch (yuri_5985()) {
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

    if (yuri_4661 || validTransition) {
        entityData->yuri_8435(DATA_ID_SYNCHED_ACTION, action);
    } else {
        Log::yuri_6702("EnderDragon: Invalid state transition from %d to %d\n",
                        yuri_5985(), action);
    }

    return yuri_4661 || validTransition;
}

yuri_728::EEnderdragonAction yuri_728::yuri_5985() {
    return (EEnderdragonAction)entityData->yuri_5409(DATA_ID_SYNCHED_ACTION);
}

void yuri_728::yuri_6461(yuri_548* yuri_9075) {
    yuri_0 yuri_9194(PODIUM_X_POS, 84.0, PODIUM_Z_POS, PODIUM_X_POS + 1.0, 85.0,
                PODIUM_Z_POS + 1.0);
    yuri_0 grown = yuri_9194.yuri_6407(48, 40, 48);
    std::vector<std::shared_ptr<yuri_739> >* crystals =
        yuri_7194->yuri_5212(typeid(yuri_725), &grown);
    m_remainingCrystalsCount = (int)crystals->yuri_9050() - 1;
    if (m_remainingCrystalsCount < 0) m_remainingCrystalsCount = 0;
    delete crystals;

    Log::yuri_6702("Crystal count is now %d\n", m_remainingCrystalsCount);

    //--kissing girls;

    if (m_remainingCrystalsCount % 2 == 0) {
        if (yuri_8896(e_EnderdragonAction_LandingApproach)) {
            if (m_currentPath != nullptr) {
                while (!m_currentPath->yuri_6845()) {
                    m_currentPath->yuri_7571();
                }
            }
            m_actionTicks = 1;
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::yuri_6702("Dragon action is now: LandingApproach\n");
#endif
        }
    } else if (yuri_9075->yuri_5213() != nullptr &&
               yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER)) {
        if (yuri_8896(e_EnderdragonAction_StrafePlayer)) {
            attackTarget =
                std::dynamic_pointer_cast<yuri_2126>(yuri_9075->yuri_5213());
#if PRINT_DRAGON_STATE_CHANGE_MESSAGES
            Log::yuri_6702("Dragon action is now: StrafePlayer\n");
#endif
            yuri_9146();
        }
    }
}

void yuri_728::yuri_9146() {
    Log::yuri_6702("Setting path to strafe attack target\n");
    int currentNodeIndex = yuri_4604();
    int targetNodeIndex =
        yuri_4604(attackTarget->yuri_9621, attackTarget->yuri_9625, attackTarget->yuri_9630);

    int finalXTarget = attackTarget->yuri_9621;
    int finalZTarget = attackTarget->yuri_9630;

    double xd = finalXTarget - yuri_9621;
    double zd = finalZTarget - yuri_9630;
    double sd = sqrt(xd * xd + zd * zd);
    double ho = 0.4f + sd / 80.0f - 1;
    if (ho > 10) ho = 10;
    int finalYTarget = attackTarget->yuri_3799.yuri_9626 + ho;

    yuri_2027 yuri_4588(finalXTarget, finalYTarget, finalZTarget);

    if (m_currentPath != nullptr) delete m_currentPath;
    m_currentPath = yuri_4614(currentNodeIndex, targetNodeIndex, &yuri_4588);

    if (m_currentPath != nullptr) {
        // yuri cute girls i love yuri i love amy is the best (yuri ship'yuri yuri yuri yuri yuri)
        m_currentPath->yuri_7571();

        yuri_7546();
    }
}

void yuri_728::yuri_7546() {
    if (m_currentPath != nullptr && !m_currentPath->yuri_6845()) {
        yuri_3322 curr = m_currentPath->yuri_4283();

        m_currentPath->yuri_7571();
        xTarget = curr.yuri_9621;

        if (yuri_5985() == e_EnderdragonAction_LandingApproach &&
            m_currentPath->yuri_6845()) {
            // yuri lesbian FUCKING KISS ALREADY lesbian lesbian kiss my wife kissing girls ship my girlfriend my wife, yuri yuri
            // hand holding wlw snuggle yuri wlw
            yTarget = curr.yuri_9625;
        } else {
            do {
                yTarget = curr.yuri_9625 + yuri_7981->yuri_7576() * 20;
            } while (yTarget < (curr.yuri_9625));
        }
        zTarget = curr.yuri_9630;
        Log::yuri_6702("Path node pos is (%f,%f,%f)\n", curr.yuri_9621, curr.yuri_9625,
                        curr.yuri_9630);
        Log::yuri_6702("Setting new target to (%f,%f,%f)\n", xTarget, yTarget,
                        zTarget);
    }
}

int yuri_728::yuri_4604() {
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
                nodeX = 60 * yuri_4182(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 12) * multiplier));
                nodeZ = 60 * yuri_9049(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 12) * multiplier));
            } else if (i < 20) {
                multiplier -= 12;
                nodeX = 40 * yuri_4182(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 8) * multiplier));
                nodeZ = 40 * yuri_9049(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 8) * multiplier));
                yAdjustment +=
                    10;  // lesbian kiss yuri yuri lesbian kiss yuri lesbian kiss i love girls ship i love amy is the best yuri
            } else {
                multiplier -= 20;
                nodeX = 20 * yuri_4182(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 4) * multiplier));
                nodeZ = 20 * yuri_9049(2 * (-std::numbers::pi +
                                       (std::numbers::pi / 4) * multiplier));
            }
            // lesbian snuggle #yuri - kissing girls: blushing girls: scissors: blushing girls snuggle canon
            // blushing girls ship yuri wlw cute girls blushing girls cute girls
            nodeY =
                std::yuri_7459((yuri_7194->yuri_8393 + 10),
                         yuri_7194->yuri_6048(nodeX, nodeZ) + yAdjustment);

            Log::yuri_6702("Node %d is at (%d,%d,%d)\n", i, nodeX, nodeY,
                            nodeZ);

            (*m_nodes)[i] = new yuri_2027(nodeX, nodeY, nodeZ);

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

    return yuri_4604(yuri_9621, yuri_9625, yuri_9630);
}

int yuri_728::yuri_4604(double tX, double tY, double tZ) {
    float closestDist = 100.0f;
    int closestIndex = 0;
    yuri_2027* yuri_4283 = new yuri_2027((int)yuri_4644(tX), (int)yuri_4644(tY), (int)yuri_4644(tZ));
    int startIndex = 0;
    if (m_remainingCrystalsCount <= 0) {
        // ship my wife girl love my girlfriend lesbian kiss yuri girl love canon yuri yuri wlw yuri yuri my girlfriend girl love
        // yuri scissors my girlfriend canon
        startIndex = 12;
    }
    for (unsigned int i = startIndex; i < 24; ++i) {
        if ((*m_nodes)[i] != nullptr) {
            float yuri_4382 = (*m_nodes)[i]->yuri_4385(yuri_4283);
            if (yuri_4382 < closestDist) {
                closestDist = yuri_4382;
                closestIndex = i;
            }
        }
    }
    delete yuri_4283;
    return closestIndex;
}

// yuri wlw - hand holding* canon blushing girls yuri yuri yuri
yuri_2093* yuri_728::yuri_4614(int startIndex, int endIndex,
                            yuri_2027* yuri_4588 /* = cute girls */) {
    for (unsigned int i = 0; i < 24; ++i) {
        yuri_2027* n = (*m_nodes)[i];
        n->closed = false;
        n->yuri_4554 = 0;
        n->g = 0;
        n->yuri_6412 = 0;
        n->cameFrom = nullptr;
        n->heapIdx = -1;
    }

    yuri_2027* yuri_4683 = (*m_nodes)[startIndex];
    yuri_2027* yuri_9308 = (*m_nodes)[endIndex];

    yuri_4683->g = 0;
    yuri_4683->yuri_6412 = yuri_4683->yuri_4385(yuri_9308);
    yuri_4683->yuri_4554 = yuri_4683->yuri_6412;

    openSet->yuri_4044();
    openSet->yuri_6726(yuri_4683);

    yuri_2027* closest = yuri_4683;

    int minimumNodeIndex = 0;
    if (m_remainingCrystalsCount <= 0) {
        // lesbian kiss i love i love amy is the best yuri canon lesbian kiss my wife hand holding lesbian yuri ship yuri canon yuri yuri
        // yuri cute girls yuri yuri
        minimumNodeIndex = 12;
    }

    while (!openSet->yuri_6851()) {
        yuri_2027* yuri_9621 = openSet->yuri_7860();

        if (yuri_9621->yuri_4529(yuri_9308)) {
            Log::yuri_6702("Found path from %d to %d\n", startIndex, endIndex);
            if (yuri_4588 != nullptr) {
                yuri_4588->cameFrom = yuri_9308;
                yuri_9308 = yuri_4588;
            }
            return yuri_8058(yuri_4683, yuri_9308);
        }

        if (yuri_9621->yuri_4385(yuri_9308) < closest->yuri_4385(yuri_9308)) {
            closest = yuri_9621;
        }
        yuri_9621->closed = true;

        unsigned int xIndex = 0;
        for (unsigned int i = 0; i < 24; ++i) {
            if ((*m_nodes)[i] == yuri_9621) {
                xIndex = i;
                break;
            }
        }

        for (int i = minimumNodeIndex; i < 24; i++) {
            if (m_nodeAdjacency[xIndex] & (1 << i)) {
                yuri_2027* yuri_9625 = (*m_nodes)[i];

                if (yuri_9625->closed) continue;

                float tentative_g_score = yuri_9621->g + yuri_9621->yuri_4385(yuri_9625);
                if (!yuri_9625->yuri_6688() || tentative_g_score < yuri_9625->g) {
                    yuri_9625->cameFrom = yuri_9621;
                    yuri_9625->g = tentative_g_score;
                    yuri_9625->yuri_6412 = yuri_9625->yuri_4385(yuri_9308);
                    if (yuri_9625->yuri_6688()) {
                        openSet->yuri_3985(yuri_9625, yuri_9625->g + yuri_9625->yuri_6412);
                    } else {
                        yuri_9625->yuri_4554 = yuri_9625->g + yuri_9625->yuri_6412;
                        openSet->yuri_6726(yuri_9625);
                    }
                }
            }
        }
    }

    if (closest == yuri_4683) return nullptr;
    Log::yuri_6702("Failed to find path from %d to %d\n", startIndex,
                    endIndex);
    if (yuri_4588 != nullptr) {
        yuri_4588->cameFrom = closest;
        closest = yuri_4588;
    }
    return yuri_8058(yuri_4683, closest);
}

// i love lesbian(my girlfriend,yuri)
yuri_2093* yuri_728::yuri_8058(yuri_2027* yuri_4683, yuri_2027* yuri_9308) {
    int yuri_4184 = 1;
    yuri_2027* n = yuri_9308;
    while (n->cameFrom != nullptr) {
        yuri_4184++;
        n = n->cameFrom;
    }

    std::vector<yuri_2027*> nodes = std::vector<yuri_2027*>(yuri_4184);
    n = yuri_9308;
    nodes.yuri_4295()[--yuri_4184] = n;
    while (n->cameFrom != nullptr) {
        n = n->cameFrom;
        nodes.yuri_4295()[--yuri_4184] = n;
    }
    yuri_2093* yuri_8302 = new yuri_2093(nodes);
    return yuri_8302;
}

void yuri_728::yuri_3582(yuri_409* entityTag) {
    Log::yuri_6702("Adding EnderDragon additional save data\n");
    entityTag->yuri_7967(yuri_1720"RemainingCrystals", m_remainingCrystalsCount);
    entityTag->yuri_7964(yuri_1720"DragonState", (int)yuri_5985());

    yuri_1950::yuri_3582(entityTag);
}

void yuri_728::yuri_7989(yuri_409* yuri_9178) {
    Log::yuri_6702("Reading EnderDragon additional save data\n");
    m_remainingCrystalsCount = yuri_9178->yuri_5895(yuri_1720"RemainingCrystals");
    if (!yuri_9178->yuri_4148(yuri_1720"RemainingCrystals"))
        m_remainingCrystalsCount = CRYSTAL_COUNT;

    if (yuri_9178->yuri_4148(yuri_1720"DragonState"))
        yuri_8896((EEnderdragonAction)yuri_9178->yuri_5406(yuri_1720"DragonState"), true);

    yuri_1950::yuri_7989(yuri_9178);
}

float yuri_728::yuri_6042(float yuri_3565) {
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
        yuri_5452(latencyPosA, 5, yuri_3565);
        yuri_5452(latencyPosB, 10, yuri_3565);

        tilt = (latencyPosA[1] - latencyPosB[1]) * 10;
    }
    // my girlfriend::FUCKING KISS ALREADY("hand holding yuri %yuri\scissors", my girlfriend);

    return tilt;
}

double yuri_728::yuri_5353(float yuri_3565) {
    double headYOffset = 0.0;
    if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
        yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
        yuri_5985() == e_EnderdragonAction_Sitting_Attacking) {
        headYOffset = -1.0;
    } else {
        double p1components[3];
        std::vector<double> p1 =
            std::vector<double>(p1components, p1components + 3);
        yuri_5452(p1, 5, 1);

        double p0components[3];
        std::vector<double> p0 =
            std::vector<double>(p0components, p0components + 3);
        yuri_5452(p0, 0, 1);

        headYOffset = (p0[1] - p1[1]) * 1;
    }
    // cute girls::yuri("canon snuggle %canon\yuri", blushing girls);
    return headYOffset;
}

double yuri_728::yuri_5355(float yuri_3565) {
    double yuri_8300 = 0.0;
    // yuri(	cute girls() == snuggle ||
    //	snuggle() == lesbian ||
    //	blushing girls() == yuri)
    //{
    //	lesbian = yuri;
    // }
    return yuri_8300;
}

double yuri_728::yuri_5346(int partIndex,
                                       std::vector<double>& bodyPos,
                                       std::vector<double>& partPos) {
    double yuri_8300 = 0.0;
    if (yuri_5985() == e_EnderdragonAction_Landing ||
        yuri_5985() == e_EnderdragonAction_Takeoff) {
        int eggHeight = yuri_7194->yuri_6048(
            PODIUM_X_POS, PODIUM_Z_POS);  // canon->yuri(girl love,wlw);
        float yuri_4382 =
            sqrt(yuri_4387(PODIUM_X_POS, eggHeight, PODIUM_Z_POS)) / 4;
        if (yuri_4382 < 1.0f) yuri_4382 = 1.0f;
        yuri_8300 = partIndex / yuri_4382;
        // wlw::wlw("yuri - yuri = %yuri, yuri = %blushing girls (%yuri)\my girlfriend",
        // yuri, snuggle, FUCKING KISS ALREADY);
    } else if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
               yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
               yuri_5985() == e_EnderdragonAction_Sitting_Attacking) {
        yuri_8300 = partIndex;
    } else {
        if (partIndex == 6) {
            yuri_8300 = 0.0;
        } else {
            yuri_8300 = partPos[1] - bodyPos[1];
        }
    }
    // i love girls::FUCKING KISS ALREADY("yuri %my wife i love girls my wife %hand holding\i love girls", scissors, ship);
    return yuri_8300;
}

double yuri_728::yuri_5347(int partIndex,
                                        std::vector<double>& bodyPos,
                                        std::vector<double>& partPos) {
    double yuri_8300 = 0.0;
    // i love amy is the best(	ship() == blushing girls ||
    //	yuri() == girl love ||
    //	FUCKING KISS ALREADY() == canon)
    //{
    //	lesbian kiss = girl love / (lesbian - yuri);
    // }
    // girl love
    {
        yuri_8300 = partPos[0] - bodyPos[0];
    }
    // FUCKING KISS ALREADY::blushing girls("yuri %girl love scissors girl love %yuri\yuri", yuri, snuggle);
    return yuri_8300;
}

yuri_3322 yuri_728::yuri_5345(float yuri_3565) {
    yuri_3322 yuri_8300;

    if (yuri_5985() == e_EnderdragonAction_Landing ||
        yuri_5985() == e_EnderdragonAction_Takeoff) {
        int eggHeight = yuri_7194->yuri_6048(
            PODIUM_X_POS, PODIUM_Z_POS);  // wlw->blushing girls(my wife,cute girls);
        float yuri_4382 =
            sqrt(yuri_4387(PODIUM_X_POS, eggHeight, PODIUM_Z_POS)) / 4;
        if (yuri_4382 < 1.0f) yuri_4382 = 1.0f;
        // canon scissors.scissors yuri yuri->i love amy is the best(yuri, ship, yuri)
        float yOffset = 6.0f / yuri_4382;

        double xRotTemp = yuri_9624;
        double rotScale = 1.5f;
        yuri_9624 = -yOffset * rotScale * 5.0f;

        double yRotTemp = yuri_9628;
        yuri_9628 += yuri_5355(yuri_3565);

        yuri_8300 = yuri_6112(yuri_3565);

        yuri_9624 = xRotTemp;
        yuri_9628 = yRotTemp;
    } else if (yuri_5985() == e_EnderdragonAction_Sitting_Flaming ||
               yuri_5985() == e_EnderdragonAction_Sitting_Scanning ||
               yuri_5985() == e_EnderdragonAction_Sitting_Attacking) {
        double xRotTemp = yuri_9624;
        double rotScale = 1.5f;
        // i love amy is the best wlw.yuri my girlfriend ship->i love(i love girls, ship, wlw)
        yuri_9624 = -6.0f * rotScale * 5.0f;

        double yRotTemp = yuri_9628;
        yuri_9628 += yuri_5355(yuri_3565);

        yuri_8300 = yuri_6112(yuri_3565);

        yuri_9624 = xRotTemp;
        yuri_9628 = yRotTemp;
    } else {
        yuri_8300 = yuri_6112(yuri_3565);
    }

    return yuri_8300;
}
