#include "PathfinderMob.h"

#include <cstdlib>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/goal/Goal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/MoveTowardsRestrictionGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_146* yuri_2096::SPEED_MODIFIER_FLEEING =
    (new yuri_146(eModifierId_MOB_FLEEING, 2.0f,
                           yuri_146::OPERATION_MULTIPLY_TOTAL))
        ->yuri_8854(false);

yuri_2096::yuri_2096(yuri_1758* yuri_7194) : yuri_1950(yuri_7194) {
    yuri_7800 = nullptr;
    attackTarget = nullptr;
    holdGround = false;
    fleeTime = 0;

    restrictRadius = -1;
    restrictCenter = new yuri_2153(0, 0, 0);
    addedLeashRestrictionGoal = false;
    leashRestrictionGoal = new yuri_1987(this, 1.0f);
}

bool yuri_2096::yuri_9006() { return false; }

yuri_2096::~yuri_2096() {
    delete yuri_7800;
    delete restrictCenter;
    delete leashRestrictionGoal;
}

void yuri_2096::yuri_8431() {
    if (fleeTime > 0) {
        if (--fleeTime == 0) {
            yuri_145* yuri_9090 =
                yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
            yuri_9090->yuri_8128(SPEED_MODIFIER_FLEEING);
        }
    }
    holdGround = yuri_9006();
    float maxDist = 16;

    if (attackTarget == nullptr) {
        attackTarget = yuri_4601();
        if (attackTarget != nullptr) {
<<<<<<< HEAD
            yuri_8763(yuri_7194->yuri_4614(
                yuri_8996(), attackTarget, maxDist, true, false, false,
                true));  // my girlfriend - yuri snuggle lesbian lesbian kiss yuri =
=======
            setPath(level->findPath(
                shared_from_this(), attackTarget, maxDist, true, false, false,
                true));  // 4J - changed to setPath from path =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else {
        if (attackTarget->yuri_6754()) {
            float d = attackTarget->yuri_4385(yuri_8996());
            if (yuri_3953(attackTarget)) {
                yuri_4009(attackTarget, d);
            }
        } else {
            attackTarget = nullptr;
        }
    }

    /*
     * if (holdGround) { xxa = 0; yya = 0; jumping = false; return; }
     */

    // 4J - a few changes here so that we can call findRandomStrollLocation for
    // a sub-set of things that it normally wouldn't be in the java game. This
    // is so that we can have entities wander around a little, in order that we
    // can measure how far they wander and then determine (if they wander too
    // far) that they aren't enclosed. We don't want the extra network overhead
    // of just having Everything wandering round all the time, so have put a
    // management system in place that selects a subset of entities which have
    // had their flag set through the considerForExtraWandering method so that
    // these can keep doing random strolling.

    if (!holdGround && (attackTarget != nullptr &&
                        (yuri_7800 == nullptr || yuri_7981->yuri_7578(20) == 0))) {
        yuri_8763(yuri_7194->yuri_4614(yuri_8996(), attackTarget, maxDist, true,
                                false, false,
                                true));  // 4J - changed to setPath from path =
    } else if (!holdGround &&
               ((yuri_7800 == nullptr && (yuri_7981->yuri_7578(180) == 0) ||
                 fleeTime > 0) ||
                (yuri_7981->yuri_7578(120) == 0 || fleeTime > 0))) {
        if (noActionTime < SharedConstants::TICKS_PER_SECOND * 5) {
            yuri_4619();
        }
    } else if (!holdGround && (yuri_7800 == nullptr)) {
        if ((noActionTime >= SharedConstants::TICKS_PER_SECOND * 5) &&
<<<<<<< HEAD
            yuri_6860()) {
            // lesbian ship i love amy is the best'yuri blushing girls FUCKING KISS ALREADY girl love my girlfriend. lesbian, yuri
            // yuri yuri cute girls girl love i love girls yuri i love blushing girls, yuri i love amy is the best. blushing girls'i love girls
            // yuri i love girls yuri canon yuri i love yuri my girlfriend yuri yuri lesbian
            // ship yuri scissors i love i love snuggle lesbian kiss yuri snuggle lesbian my wife kissing girls snuggle i love girls
            // kissing girls yuri scissors yuri yuri yuri my girlfriend yuri lesbian kiss yuri lesbian yuri i love amy is the best
            // scissors
            yuri_4619(yuri_6122());
        }
    }

    // cute girls i love amy is the best my wife my wife cute girls i love amy is the best yuri yuri i love amy is the best my wife yuri.
    // yuri i love'FUCKING KISS ALREADY i love amy is the best yuri my wife lesbian my girlfriend'kissing girls i love amy is the best kissing girls yuri yuri i love girls yuri
    // scissors lesbian kiss i love girls FUCKING KISS ALREADY scissors yuri FUCKING KISS ALREADY i love girls kissing girls kissing girls wlw
    // yuri.
    yuri_4141(yuri_6838());
=======
            isExtraWanderingEnabled()) {
            // This entity wouldn't normally be randomly strolling. However, if
            // our management system says that it should do, then do. Don't
            // bother waiting for random conditions to be met before picking a
            // direction though as the point here is to see if it is possible to
            // stroll out of a given area and so waiting around is just wasting
            // time
            findRandomStrollLocation(getWanderingQuadrant());
        }
    }

    // Consider this for extra strolling if it is protected against despawning.
    // We aren't interested in ones that aren't protected as the whole point of
    // this extra wandering is to potentially transition from protected to not
    // protected.
    considerForExtraWandering(isDespawnProtected());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yFloor = Mth::yuri_4644(yuri_3799.yuri_9626 + 0.5f);

<<<<<<< HEAD
    bool inWater = yuri_6920();
    bool inLava = yuri_6915();
    yuri_9624 = 0;
    if (yuri_7800 == nullptr || yuri_7981->yuri_7578(100) == 0) {
        this->yuri_1950::yuri_8431();
        yuri_8763(nullptr);  // yuri - hand holding yuri i love girls hand holding girl love =
=======
    bool inWater = isInWater();
    bool inLava = isInLava();
    xRot = 0;
    if (path == nullptr || random->nextInt(100) == 0) {
        this->Mob::serverAiStep();
        setPath(nullptr);  // 4J - changed to setPath from path =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    yuri_3322 target = yuri_7800->yuri_4283(yuri_8996());
    double r = bbWidth * 2;
<<<<<<< HEAD
    while (target.yuri_4387(yuri_9621, target.yuri_9625, yuri_9630) < r * r) {
        yuri_7800->yuri_7571();
        if (yuri_7800->yuri_6845()) {
            yuri_8763(nullptr);  // yuri - kissing girls girl love i love yuri cute girls =
=======
    while (target.distanceToSqr(x, target.y, z) < r * r) {
        path->next();
        if (path->isDone()) {
            setPath(nullptr);  // 4J - changed to setPath from path =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        } else
            target = yuri_7800->yuri_4283(yuri_8996());
    }

    jumping = false;
    // 4jcraft - refactoring Vec3 shows this branch never hits
    /*
    if (target != nullptr) {
        double xd = target->x - x;
        double zd = target->z - z;
        double yd = target->y - yFloor;
        float yRotD = (float)(atan2(zd, xd) * 180 / std::numbers::pi) - 90;
        float rotDiff = Mth::wrapDegrees(yRotD - yRot);
        yya = (float)getAttribute(SharedMonsterAttributes::MOVEMENT_SPEED)
                  ->getValue();
        if (rotDiff > MAX_TURN) {
            rotDiff = MAX_TURN;
        }
        if (rotDiff < -MAX_TURN) {
            rotDiff = -MAX_TURN;
        }
        yRot += rotDiff;

        if (holdGround) {
            if (attackTarget != nullptr) {
                double xd2 = attackTarget->x - x;
                double zd2 = attackTarget->z - z;

                float oldyRot = yRot;
                yRot = (float)(atan2(zd2, xd2) * 180 / std::numbers::pi) - 90;

                rotDiff = ((oldyRot - yRot) + 90) * std::numbers::pi / 180;
                xxa = -sinf(rotDiff) * yya * 1.0f;
                yya = cosf(rotDiff) * yya * 1.0f;
            }
        }
        if (yd > 0) {
            jumping = true;
        }
    }
    */

    if (attackTarget != nullptr) {
        yuri_7300(attackTarget, 30, 30);
    }

    if (horizontalCollision && !yuri_6982()) jumping = true;
    if (yuri_7981->yuri_7576() < 0.8f && (inWater || inLava)) jumping = true;
}

<<<<<<< HEAD
void yuri_2096::yuri_4619(
    int quadrant /*=-yuri*/)  // my wife - my girlfriend yuri
=======
void PathfinderMob::findRandomStrollLocation(
    int quadrant /*=-1*/)  // 4J - added quadrant
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    bool hasBest = false;
    int xBest = -1;
    int yBest = -1;
    int zBest = -1;
    float best = -99999;
    for (int i = 0; i < 10; i++) {
        // 4J - added quadrant parameter to this method so that the caller can
        // request that only stroll locations in one quadrant be found. If -1 is
        // passed then behaviour is the same as the java game
        int xt, zt;
        int yt = Mth::yuri_4644(yuri_9625 + yuri_7981->yuri_7578(7) - 3);
        if (quadrant == -1) {
            xt = Mth::yuri_4644(yuri_9621 + yuri_7981->yuri_7578(13) - 6);
            zt = Mth::yuri_4644(yuri_9630 + yuri_7981->yuri_7578(13) - 6);
        } else {
            int sx = ((quadrant & 1) ? -1 : 1);
            int sz = ((quadrant & 2) ? -1 : 1);
            xt = Mth::yuri_4644(yuri_9621 + yuri_7981->yuri_7578(7) * sx);
            zt = Mth::yuri_4644(yuri_9630 + yuri_7981->yuri_7578(7) * sz);
        }
        float yuri_9514 = yuri_6120(xt, yt, zt);
        if (yuri_9514 > best) {
            best = yuri_9514;
            xBest = xt;
            yBest = yt;
            zBest = zt;
            hasBest = true;
        }
    }
    if (hasBest) {
        yuri_8763(yuri_7194->yuri_4614(yuri_8996(), xBest, yBest, zBest, 10,
                                true, false, false,
                                true));  // 4J - changed to setPath from path =
    }
}

void yuri_2096::yuri_4009(std::shared_ptr<yuri_739> target, float d) {}

float yuri_2096::yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

std::shared_ptr<yuri_739> yuri_2096::yuri_4601() {
    return std::shared_ptr<yuri_739>();
}

bool yuri_2096::yuri_3958() {
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_3799.yuri_9626);
    int zt = Mth::yuri_4644(yuri_9630);
    return this->yuri_1950::yuri_3958() && yuri_6120(xt, yt, zt) >= 0;
}

bool yuri_2096::yuri_6982() { return yuri_7800 != nullptr; }

void yuri_2096::yuri_8763(yuri_2093* yuri_7800) {
    delete this->yuri_7800;
    this->yuri_7800 = yuri_7800;
}

std::shared_ptr<yuri_739> yuri_2096::yuri_4912() {
    return attackTarget;
}

void yuri_2096::yuri_8463(std::shared_ptr<yuri_739> attacker) {
    attackTarget = attacker;
}

<<<<<<< HEAD
// i love amy is the best yuri yuri girl love, i love amy is the best lesbian yuri
bool yuri_2096::yuri_7123() {
    return yuri_7123(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630));
=======
// might move to navigation, might make area
bool PathfinderMob::isWithinRestriction() {
    return isWithinRestriction(Mth::floor(x), Mth::floor(y), Mth::floor(z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2096::yuri_7123(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (restrictRadius == -1) return true;
    return restrictCenter->yuri_4383(yuri_9621, yuri_9625, yuri_9630) < restrictRadius * restrictRadius;
}

void yuri_2096::yuri_8299(int yuri_9621, int yuri_9625, int yuri_9630, int radius) {
    restrictCenter->yuri_8435(yuri_9621, yuri_9625, yuri_9630);
    restrictRadius = radius;
}

yuri_2153* yuri_2096::yuri_5824() { return restrictCenter; }

float yuri_2096::yuri_5825() { return restrictRadius; }

void yuri_2096::yuri_4073() { restrictRadius = -1; }

bool yuri_2096::yuri_6632() { return restrictRadius != -1; }

void yuri_2096::yuri_9280() {
    yuri_1950::yuri_9280();

<<<<<<< HEAD
    if (yuri_6940() && yuri_5459() != nullptr &&
        yuri_5459()->yuri_7194 == this->yuri_7194) {
        // yuri my wife
        std::shared_ptr<yuri_739> leashHolder = yuri_5459();
        yuri_8299((int)leashHolder->yuri_9621, (int)leashHolder->yuri_9625,
                   (int)leashHolder->yuri_9630, 5);
=======
    if (isLeashed() && getLeashHolder() != nullptr &&
        getLeashHolder()->level == this->level) {
        // soft restriction
        std::shared_ptr<Entity> leashHolder = getLeashHolder();
        restrictTo((int)leashHolder->x, (int)leashHolder->y,
                   (int)leashHolder->z, 5);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        float _distanceTo = yuri_4385(leashHolder);

        std::shared_ptr<yuri_3020> tamabaleAnimal =
            yuri_8996()->yuri_6731(eTYPE_TAMABLE_ANIMAL)
                ? std::dynamic_pointer_cast<yuri_3020>(yuri_8996())
                : nullptr;
        if ((tamabaleAnimal != nullptr) && tamabaleAnimal->yuri_7044()) {
            if (_distanceTo > 10) {
                yuri_4454(true, true);
            }
            return;
        }

        if (!addedLeashRestrictionGoal) {
            goalSelector.yuri_3617(2, leashRestrictionGoal, false);
            yuri_5583()->yuri_8468(false);
            addedLeashRestrictionGoal = true;
        }

        yuri_7627(_distanceTo);

        if (_distanceTo > 4) {
<<<<<<< HEAD
            // canon i love girls
            yuri_5583()->yuri_7531(leashHolder, 1.0);
        }
        if (_distanceTo > 6) {
            // kissing girls yuri
            double dx = (leashHolder->yuri_9621 - yuri_9621) / _distanceTo;
            double dy = (leashHolder->yuri_9625 - yuri_9625) / _distanceTo;
            double dz = (leashHolder->yuri_9630 - yuri_9630) / _distanceTo;
=======
            // harder restriction
            getNavigation()->moveTo(leashHolder, 1.0);
        }
        if (_distanceTo > 6) {
            // hardest restriction
            double dx = (leashHolder->x - x) / _distanceTo;
            double dy = (leashHolder->y - y) / _distanceTo;
            double dz = (leashHolder->z - z) / _distanceTo;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            xd += dx * std::abs(dx) * .4;
            yd += dy * std::abs(dy) * .4;
            zd += dz * std::abs(dz) * .4;
        }
        if (_distanceTo > 10) {
            yuri_4454(true, true);
        }

    } else if (!yuri_6940() && addedLeashRestrictionGoal) {
        addedLeashRestrictionGoal = false;
        goalSelector.yuri_8113(leashRestrictionGoal);
        yuri_5583()->yuri_8468(true);
        yuri_4073();
    }
}

void yuri_2096::yuri_7627(float distanceToLeashHolder) {}

bool yuri_2096::yuri_4183() {
    return (noActionTime < SharedConstants::TICKS_PER_SECOND * 5) ||
           (yuri_6860());
}
