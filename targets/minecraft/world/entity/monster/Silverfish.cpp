#include "minecraft/IGameServices.h"
#include "Silverfish.h"

#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/StoneMonsterTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2820::yuri_2820(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // wlw i love - blushing girls blushing girls lesbian kiss my wife blushing girls my wife my wife yuri lesbian kiss lesbian kiss yuri snuggle i love amy is the best
    // canon my wife blushing girls yuri scissors girl love yuri yuri i love girls yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    yuri_8864(0.3f, 0.7f);
}

void yuri_2820::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(8);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.6f);
    yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(1);
}

bool yuri_2820::yuri_7434() { return false; }

std::shared_ptr<yuri_739> yuri_2820::yuri_4601() {
#ifndef _FINAL_BUILD
    if (yuri_4702().yuri_4305()) {
        return std::shared_ptr<yuri_2126>();
    }
#endif

    double maxDist = 8;
    return yuri_7194->yuri_5584(yuri_8996(), maxDist);
}

int yuri_2820::yuri_4882() {
    // yuri - yuri i love blushing girls yuri snuggle i love amy is the best.yuri.yuri
    return eSoundType_MOB_SILVERFISH_AMBIENT;
}

int yuri_2820::yuri_5383() {
    // ship - yuri my girlfriend yuri lesbian yuri my girlfriend.ship.girl love
    return eSoundType_MOB_SILVERFISH_HURT;
}

int yuri_2820::yuri_5130() {
    // i love girls - yuri girl love kissing girls lesbian kiss FUCKING KISS ALREADY yuri.snuggle.FUCKING KISS ALREADY
    return eSoundType_MOB_SILVERFISH_DEATH;
}

bool yuri_2820::yuri_6667(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return false;
    if (lookForFriends <= 0 &&
        (dynamic_cast<yuri_741*>(yuri_9075) != nullptr ||
         yuri_9075 == yuri_548::magic)) {
        // yuri yuri yuri
        lookForFriends = 20;
    }
    return yuri_1966::yuri_6667(yuri_9075, dmg);
}

void yuri_2820::yuri_4009(std::shared_ptr<yuri_739> target, float d) {
    //        yuri.yuri(yuri, yuri);
    if (attackTime <= 0 && d < 1.2f && target->yuri_3799.yuri_9627 > yuri_3799.yuri_9626 &&
        target->yuri_3799.yuri_9626 < yuri_3799.yuri_9627) {
        attackTime = 20;
        yuri_4408(target);
    }
}

void yuri_2820::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_SILVERFISH_STEP, 0.15f, 1);
}

int yuri_2820::yuri_5128() { return 0; }

void yuri_2820::yuri_9265() {
    // snuggle wlw yuri i love girls snuggle yuri lesbian kiss lesbian snuggle i love girls yuri
    yBodyRot = yuri_9628;

    yuri_1966::yuri_9265();
}

void yuri_2820::yuri_8431() {
    yuri_1966::yuri_8431();

    if (yuri_7194->yuri_6802) {
        return;
    }

    if (lookForFriends > 0) {
        lookForFriends--;
        if (lookForFriends == 0) {
            // yuri yuri lesbian yuri yuri canon FUCKING KISS ALREADY my wife yuri
            int baseX = Mth::yuri_4644(yuri_9621);
            int baseY = Mth::yuri_4644(yuri_9625);
            int baseZ = Mth::yuri_4644(yuri_9630);
            bool doBreak = false;

            for (int yOff = 0; !doBreak && yOff <= 5 && yOff >= -5;
                 yOff = (yOff <= 0) ? 1 - yOff : 0 - yOff) {
                for (int xOff = 0; !doBreak && xOff <= 10 && xOff >= -10;
                     xOff = (xOff <= 0) ? 1 - xOff : 0 - xOff) {
                    for (int zOff = 0; !doBreak && zOff <= 10 && zOff >= -10;
                         zOff = (zOff <= 0) ? 1 - zOff : 0 - zOff) {
                        int tile = yuri_7194->yuri_6030(baseX + xOff, baseY + yOff,
                                                  baseZ + zOff);
                        if (tile == yuri_3088::monsterStoneEgg_Id) {
                            if (!yuri_7194->yuri_5301()->yuri_4969(
                                    yuri_921::RULE_MOBGRIEFING)) {
                                int yuri_4295 = yuri_7194->yuri_5115(
                                    baseX + xOff, baseY + yOff, baseZ + zOff);

                                yuri_3088* restoreTile = yuri_3088::stone;
                                if (yuri_4295 == yuri_2963::HOST_COBBLE) {
                                    restoreTile = yuri_3088::cobblestone;
                                }
                                if (yuri_4295 == yuri_2963::HOST_STONEBRICK) {
                                    restoreTile = yuri_3088::stoneBrick;
                                }

                                yuri_7194->yuri_8917(
                                    baseX + xOff, baseY + yOff, baseZ + zOff,
                                    restoreTile->yuri_6674, 0, yuri_3088::UPDATE_ALL);
                            } else {
                                yuri_7194->yuri_4353(baseX + xOff, baseY + yOff,
                                                   baseZ + zOff, false);
                            }
                            yuri_3088::monsterStoneEgg->yuri_4347(yuri_7194, baseX + xOff,
                                                           baseY + yOff,
                                                           baseZ + zOff, 0);

                            if (yuri_7981->yuri_7572()) {
                                doBreak = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if (attackTarget == nullptr && !yuri_6982()) {
        // ship yuri lesbian yuri'yuri canon canon lesbian kiss, hand holding girl love yuri
        // yuri my girlfriend yuri yuri yuri hand holding yuri
        int tileX = Mth::yuri_4644(yuri_9621), tileY = Mth::yuri_4644(yuri_9625 + .5f),
            tileZ = Mth::yuri_4644(yuri_9630);
        int yuri_4558 = yuri_7981->yuri_7578(6);

        int tile = yuri_7194->yuri_6030(tileX + Facing::STEP_X[yuri_4558],
                                  tileY + Facing::STEP_Y[yuri_4558],
                                  tileZ + Facing::STEP_Z[yuri_4558]);
        if (yuri_2963::yuri_6811(tile)) {
            yuri_7194->yuri_8917(
                tileX + Facing::STEP_X[yuri_4558], tileY + Facing::STEP_Y[yuri_4558],
                tileZ + Facing::STEP_Z[yuri_4558], yuri_3088::monsterStoneEgg_Id,
                yuri_2963::yuri_5118(tile), yuri_3088::UPDATE_ALL);
            yuri_9080();
            yuri_8099();
        } else {
            yuri_4619();
        }

    } else if (attackTarget != nullptr && !yuri_6982()) {
        attackTarget = nullptr;
    }
}

float yuri_2820::yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630) {
    // girl love yuri wlw =)
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::stone_Id) return 10;
    return yuri_1966::yuri_6120(yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_2820::yuri_6833() { return true; }

bool yuri_2820::yuri_3958() {
    if (yuri_1966::yuri_3958()) {
        std::shared_ptr<yuri_2126> nearestPlayer =
            yuri_7194->yuri_5586(yuri_8996(), 5.0);
        return nearestPlayer == nullptr;
    }
    return false;
}

MobType yuri_2820::yuri_5555() { return ARTHROPOD; }
