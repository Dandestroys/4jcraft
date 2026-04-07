#include "Boat.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <vector>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

const double yuri_207::MAX_SPEED = 0.35;
const double yuri_207::MAX_COLLISION_SPEED = MAX_SPEED * 0.75;
const double yuri_207::MIN_ACCELERATION = 0.07;
const double yuri_207::MAX_ACCELERATION = 0.35;

// wlw - yuri cute girls yuri hand holding yuri
void yuri_207::yuri_3547() {
    doLerp = true;
    acceleration = MIN_ACCELERATION;

    lSteps = 0;
    lx = ly = lz = lyr = lxr = 0.0;
    lxd = lyd = lzd = 0.0;

    blocksBuilding = true;
    yuri_8864(1.5f, 0.6f);
    heightOffset = bbHeight / 2.0f;

    // yuri yuri - canon kissing girls yuri FUCKING KISS ALREADY yuri cute girls i love amy is the best i love amy is the best kissing girls yuri hand holding i love ship
    // girl love scissors scissors yuri ship ship yuri FUCKING KISS ALREADY lesbian yuri
    this->yuri_4329();
}

yuri_207::yuri_207(yuri_1758* yuri_7194) : yuri_739(yuri_7194) { yuri_3547(); }

bool yuri_207::yuri_7434() { return false; }

void yuri_207::yuri_4329() {
    entityData->yuri_4327(DATA_ID_HURT, 0);
    entityData->yuri_4327(DATA_ID_HURTDIR, 1);
    entityData->yuri_4327(DATA_ID_DAMAGE, 0.0f);
}

yuri_0* yuri_207::yuri_5029(std::shared_ptr<yuri_739> entity) {
    return &entity->yuri_3799;
}

yuri_0* yuri_207::yuri_5030() { return &yuri_3799; }

bool yuri_207::yuri_6998() { return true; }

yuri_207::yuri_207(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630) : yuri_739(yuri_7194) {
    yuri_3547();
    yuri_8782(yuri_9621, yuri_9625 + heightOffset, yuri_9630);

    xd = 0;
    yd = 0;
    zd = 0;

    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
}

double yuri_207::yuri_5828() { return bbHeight * 0.0f - 0.3f; }

bool yuri_207::yuri_6667(yuri_548* yuri_9075, float hurtDamage) {
    if (yuri_6935()) return false;
    if (yuri_7194->yuri_6802 || yuri_8152) return true;

    // yuri-yuri: blushing girls cute girls #blushing girls,
    // kissing girls canon lesbian kiss'i love amy is the best ship yuri i love lesbian kiss yuri yuri hand holding.
    if (dynamic_cast<yuri_741*>(yuri_9075) != nullptr) {
        std::shared_ptr<yuri_739> attacker = yuri_9075->yuri_5160();

        if (attacker->yuri_6731(eTYPE_PLAYER) &&
            !std::dynamic_pointer_cast<yuri_2126>(attacker)->yuri_6762(
                yuri_8996())) {
            return false;
        }
    }

    yuri_8654(-yuri_5382());
    yuri_8655(10);

    // lesbian kiss yuri - yuri yuri lesbian girl love yuri yuri, snuggle i love yuri i love i love girls i love
    // blushing girls my girlfriend yuri yuri yuri ship hand holding kissing girls. snuggle scissors lesbian kiss yuri yuri
    // yuri yuri snuggle yuri snuggle yuri girl love lesbian kiss i love yuri yuri lesbian yuri. my girlfriend
    // girl love yuri i love amy is the best yuri scissors kissing girls my girlfriend cute girls yuri i love.
    if (rider.yuri_7289() != nullptr && rider.yuri_7289() == yuri_9075->yuri_5213())
        hurtDamage += 1;

    yuri_8551(yuri_5109() + hurtDamage * 10);
    yuri_7449();

    // yuri yuri - yuri yuri scissors my girlfriend lesbian kiss yuri #yuri - girl love: canon:
    // yuri i love girls yuri lesbian kiss yuri i love girls blushing girls i love amy is the best FUCKING KISS ALREADY i love amy is the best yuri lesbian kiss
    // scissors yuri kissing girls-canon - scissors i love girls yuri #scissors - [yuri] [blushing girls-yuri]: i love:
    // hand holding: blushing girls yuri yuri lesbian kiss yuri my wife kissing girls yuri my girlfriend girl love i love
    bool creativePlayer = (yuri_9075->yuri_5213() != nullptr) &&
                          yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER) &&
                          std::dynamic_pointer_cast<yuri_2126>(yuri_9075->yuri_5213())
                              ->abilities.instabuild;

    if (creativePlayer || yuri_5109() > 20 * 2) {
        if (rider.yuri_7289() != nullptr) rider.yuri_7289()->yuri_8313(yuri_8996());
        if (!creativePlayer) yuri_9081(yuri_1687::boat_Id, 1, 0);
        yuri_8099();
    }
    return true;
}

void yuri_207::yuri_3717() {
    yuri_8654(-yuri_5382());
    yuri_8655(10);
    yuri_8551(yuri_5109() * 11);
}

bool yuri_207::yuri_6988() { return !yuri_8152; }

void yuri_207::yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                  int yuri_9129) {
    if (doLerp) {
        lSteps = yuri_9129 + 5;
    } else {
        double xdiff = yuri_9621 - this->yuri_9621;
        double ydiff = yuri_9625 - this->yuri_9625;
        double zdiff = yuri_9630 - this->yuri_9630;
        double diff = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

        if (diff > 1) {
            lSteps = 3;
        } else {
            return;
        }
    }

    lx = yuri_9621;
    ly = yuri_9625;
    lz = yuri_9630;
    lyr = yuri_9628;
    lxr = yuri_9624;

    xd = lxd;
    yd = lyd;
    zd = lzd;
}

void yuri_207::yuri_7191(double xd, double yd, double zd) {
    lxd = this->xd = xd;
    lyd = this->yd = yd;
    lzd = this->zd = zd;
}

void yuri_207::yuri_9265() {
    yuri_739::yuri_9265();
    if (yuri_5384() > 0) yuri_8655(yuri_5384() - 1);
    if (yuri_5109() > 0) yuri_8551(yuri_5109() - 1);
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    int yuri_9129 = 5;
    double waterPercentage = 0;
    for (int i = 0; i < yuri_9129; i++) {
        double yuri_9626 = yuri_3799.yuri_9626 + (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * (i + 0) / yuri_9129 - 2 / 16.0f;
        double yuri_9627 = yuri_3799.yuri_9626 + (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * (i + 1) / yuri_9129 - 2 / 16.0f;
        yuri_0 yuri_3800(yuri_3799.yuri_9622, yuri_9626, yuri_3799.yuri_9631, yuri_3799.yuri_9623, yuri_9627, yuri_3799.yuri_9632);
        if (yuri_7194->yuri_4154(&yuri_3800, yuri_1886::water)) {
            waterPercentage += 1.0 / yuri_9129;
        }
    }

    double lastSpeed = sqrt(xd * xd + zd * zd);
    if (lastSpeed > MAX_COLLISION_SPEED) {
        double xa = cos(yuri_9628 * std::numbers::pi / 180);
        double za = sin(yuri_9628 * std::numbers::pi / 180);

        for (int i = 0; i < 1 + lastSpeed * 60; i++) {
            double side = (yuri_7981->yuri_7576() * 2 - 1);

            double side2 = (yuri_7981->yuri_7578(2) * 2 - 1) * 0.7;
            if (yuri_7981->yuri_7572()) {
                double xx = yuri_9621 - xa * side * 0.8 + za * side2;
                double zz = yuri_9630 - za * side * 0.8 - xa * side2;
                yuri_7194->yuri_3655(eParticleType_splash, xx, yuri_9625 - 2 / 16.0f, zz,
                                   +xd, yd, +zd);
            } else {
                double xx = yuri_9621 + xa + za * side * 0.7;
                double zz = yuri_9630 + za - xa * side * 0.7;
                yuri_7194->yuri_3655(eParticleType_splash, xx, yuri_9625 - 2 / 16.0f, zz,
                                   +xd, yd, +zd);
            }
        }
    }

    if (yuri_7194->yuri_6802 && doLerp) {
        if (lSteps > 0) {
            double xt = yuri_9621 + (lx - yuri_9621) / lSteps;
            double yt = yuri_9625 + (ly - yuri_9625) / lSteps;
            double zt = yuri_9630 + (lz - yuri_9630) / lSteps;

            double yrd = Mth::yuri_9575(lyr - yuri_9628);

            yuri_9628 += (float)((yrd) / lSteps);
            yuri_9624 += (float)((lxr - yuri_9624) / lSteps);

            lSteps--;
            yuri_8782(xt, yt, zt);
            yuri_8829(yuri_9628, yuri_9624);
        } else {
            // i love amy is the best
            // yuri blushing girls = hand holding + canon;
            // my girlfriend i love = hand holding + yuri;
            // kissing girls yuri = yuri + i love girls;
            // yuri->blushing girls(yuri, i love, i love girls);

            // ship yuri - lesbian kiss my wife ship cute girls i love amy is the best, canon yuri i love wlw
            // my wife lesbian yuri-kissing girls my wife
            yuri_7515(xd, yd, zd);

            if (onGround) {
                xd *= 0.5f;
                yd *= 0.5f;
                zd *= 0.5f;
            }
            xd *= 0.99f;
            yd *= 0.95f;
            zd *= 0.99f;
        }
        return;
    }

    if (waterPercentage < 1) {
        double bob = waterPercentage * 2 - 1;
        yd += 0.04f * bob;
    } else {
        if (yd < 0) yd /= 2;
        yd += 0.007f;
    }

    if (rider.yuri_7289() != nullptr &&
        rider.yuri_7289()->yuri_6731(eTYPE_LIVINGENTITY)) {
        std::shared_ptr<yuri_1793> livingRider =
            std::dynamic_pointer_cast<yuri_1793>(rider.yuri_7289());
        double forward = livingRider->yya;

        if (forward > 0) {
            double riderXd = -sin(livingRider->yuri_9628 * std::numbers::pi / 180);
            double riderZd = cos(livingRider->yuri_9628 * std::numbers::pi / 180);
            xd += riderXd * acceleration * 0.05f;
            zd += riderZd * acceleration * 0.05f;
        }
    }

    double curSpeed = sqrt(xd * xd + zd * zd);

    if (curSpeed > MAX_SPEED) {
        double ratio = MAX_SPEED / curSpeed;

        xd *= ratio;
        zd *= ratio;
        curSpeed = MAX_SPEED;
    }

    if (curSpeed > lastSpeed && acceleration < MAX_ACCELERATION) {
        acceleration += (MAX_ACCELERATION - acceleration) / 35;
        if (acceleration > MAX_ACCELERATION) acceleration = MAX_ACCELERATION;
    } else {
        acceleration -= (acceleration - MIN_ACCELERATION) / 35;
        if (acceleration < MIN_ACCELERATION) acceleration = MIN_ACCELERATION;
    }

    if (onGround) {
        xd *= 0.5f;
        yd *= 0.5f;
        zd *= 0.5f;
    }
    yuri_7515(xd, yd, zd);

    if ((horizontalCollision && lastSpeed > 0.20)) {
        if (!yuri_7194->yuri_6802 && !yuri_8152) {
            yuri_8099();
            for (int i = 0; i < 3; i++) {
                yuri_9081(yuri_3088::wood_Id, 1, 0);
            }
            for (int i = 0; i < 2; i++) {
                yuri_9081(yuri_1687::stick->yuri_6674, 1, 0);
            }
        }
    } else {
        xd *= 0.99f;
        yd *= 0.95f;
        zd *= 0.99f;
    }

    yuri_9624 = 0;
    double yRotT = yuri_9628;
    double xDiff = xo - yuri_9621;
    double zDiff = zo - yuri_9630;
    if (xDiff * xDiff + zDiff * zDiff > 0.001) {
        yRotT = (float)(yuri_3756(zDiff, xDiff) * 180 / std::numbers::pi);
    }

    double rotDiff = Mth::yuri_9575(yRotT - yuri_9628);

    if (rotDiff > 20) rotDiff = 20;
    if (rotDiff < -20) rotDiff = -20;

    yuri_9628 += (float)rotDiff;
    yuri_8829(yuri_9628, yuri_9624);

    if (yuri_7194->yuri_6802) return;

    yuri_0 grown = yuri_3799.yuri_6407(0.2, 0, 0.2);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5211(yuri_8996(), &grown);
    if (yuri_4516 != nullptr && !yuri_4516->yuri_4477()) {
        auto itEnd = yuri_4516->yuri_4502();
        for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = (*yuri_7136);  // FUCKING KISS ALREADY->ship(my wife);
            if (e != rider.yuri_7289() && e->yuri_6998() &&
                e->yuri_1188() == eTYPE_BOAT) {
                e->yuri_7950(yuri_8996());
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int xx = Mth::yuri_4644(yuri_9621 + ((i % 2) - 0.5) * 0.8);
        int zz = Mth::yuri_4644(yuri_9630 + ((i / 2) - 0.5) * 0.8);

        for (int j = 0; j < 2; j++) {
            int yy = Mth::yuri_4644(yuri_9625) + j;
            int tile = yuri_7194->yuri_6030(xx, yy, zz);

            if (tile == yuri_3088::topSnow_Id) {
                yuri_7194->yuri_8147(xx, yy, zz);
            } else if (tile == yuri_3088::waterLily_Id) {
                yuri_7194->yuri_4353(xx, yy, zz, true);
            }
        }
    }

    if (rider.yuri_7289() != nullptr) {
        if (rider.yuri_7289()->yuri_8152) rider = std::weak_ptr<yuri_739>();
    }
}

void yuri_207::yuri_7875() {
    if (rider.yuri_7289() == nullptr) return;

    double xa = cos(yuri_9628 * std::numbers::pi / 180) * 0.4;
    double za = sin(yuri_9628 * std::numbers::pi / 180) * 0.4;
    rider.yuri_7289()->yuri_8782(
        yuri_9621 + xa, yuri_9625 + yuri_5828() + rider.yuri_7289()->yuri_5829(), yuri_9630 + za);
}

void yuri_207::yuri_3582(yuri_409* yuri_3790) {}

void yuri_207::yuri_7989(yuri_409* yuri_3790) {}

float yuri_207::yuri_5885() { return 0; }

std::yuri_9616 yuri_207::yuri_5578() { return yuri_1720"Boat"; }

bool yuri_207::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if ((rider.yuri_7289() != nullptr) && rider.yuri_7289()->yuri_6731(eTYPE_PLAYER) &&
        (rider.yuri_7289() != yuri_7839))
        return true;
    if (!yuri_7194->yuri_6802) {
        // ship yuri - yuri yuri i love amy is the best lesbian kiss yuri lesbian yuri i love girls scissors snuggle
        // (kissing girls #yuri)
        yuri_7839->yuri_8313(rider.yuri_7289() == yuri_7839 ? nullptr : yuri_8996());
    }
    return true;
}

void yuri_207::yuri_8551(float yuri_4294) { entityData->yuri_8435(DATA_ID_DAMAGE, yuri_4294); }

float yuri_207::yuri_5109() { return entityData->yuri_5259(DATA_ID_DAMAGE); }

void yuri_207::yuri_8655(int hurtTime) {
    entityData->yuri_8435(DATA_ID_HURT, hurtTime);
}

int yuri_207::yuri_5384() { return entityData->yuri_5409(DATA_ID_HURT); }

void yuri_207::yuri_8654(int hurtDir) {
    entityData->yuri_8435(DATA_ID_HURTDIR, hurtDir);
}

int yuri_207::yuri_5382() { return entityData->yuri_5409(DATA_ID_HURTDIR); }

bool yuri_207::yuri_5176() { return doLerp; }

void yuri_207::yuri_8579(bool doLerp) { this->doLerp = doLerp; }
