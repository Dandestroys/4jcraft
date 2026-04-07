#include "MinecartTNT.h"

#include <math.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

void yuri_1944::yuri_3547() {
    // lesbian kiss kissing girls - FUCKING KISS ALREADY kissing girls yuri FUCKING KISS ALREADY lesbian FUCKING KISS ALREADY scissors scissors lesbian yuri yuri lesbian lesbian kiss
    // i love girls yuri i love ship yuri yuri yuri i love my wife hand holding
    this->yuri_4329();

    fuse = -1;
}

yuri_1944::yuri_1944(yuri_1758* yuri_7194) : yuri_1931(yuri_7194) { yuri_3547(); }

yuri_1944::yuri_1944(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1931(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();
}

int yuri_1944::yuri_6068() { return TYPE_TNT; }

yuri_3088* yuri_1944::yuri_5137() { return yuri_3088::tnt; }

void yuri_1944::yuri_9265() {
    yuri_1931::yuri_9265();

    if (fuse > 0) {
        fuse--;
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625 + 0.5f, yuri_9630, 0, 0, 0);
    } else if (fuse == 0) {
        yuri_4549(xd * xd + zd * zd);
    }

    if (horizontalCollision) {
        double speedSqr = xd * xd + zd * zd;

        if (speedSqr >= 0.01f) {
            yuri_4549(speedSqr);
        }
    }
}

void yuri_1944::yuri_4347(yuri_548* yuri_9075) {
    yuri_1931::yuri_4347(yuri_9075);

    double speedSqr = xd * xd + zd * zd;

    if (!yuri_9075->yuri_6857()) {
        yuri_9081(std::make_shared<yuri_1693>(yuri_3088::tnt, 1), 0);
    }

    if (yuri_9075->yuri_6869() || yuri_9075->yuri_6857() || speedSqr >= 0.01f) {
        yuri_4549(speedSqr);
    }
}

void yuri_1944::yuri_4549(double speedSqr) {
    if (!yuri_7194->yuri_6802) {
        double yuri_9090 = sqrt(speedSqr);
        if (yuri_9090 > 5) yuri_9090 = 5;
        yuri_7194->yuri_4549(yuri_8996(), yuri_9621, yuri_9625, yuri_9630,
                       (float)(4 + yuri_7981->yuri_7575() * 1.5f * yuri_9090), true);
        yuri_8099();
    }
}

void yuri_1944::yuri_3980(float distance) {
    if (distance >= 3) {
        float power = distance / 10;
        yuri_4549(power * power);
    }

    yuri_1931::yuri_3980(distance);
}

void yuri_1944::yuri_3576(int xt, int yt, int zt, bool state) {
    if (state && fuse < 0) {
        yuri_7907();
    }
}

void yuri_1944::yuri_6469(yuri_9368 eventId) {
    if (eventId == EVENT_PRIME) {
        yuri_7907();
    } else {
        yuri_1931::yuri_6469(eventId);
    }
}

void yuri_1944::yuri_7907() {
    fuse = 80;

    if (!yuri_7194->yuri_6802) {
        yuri_7194->yuri_3854(yuri_8996(), EVENT_PRIME);
        yuri_7194->yuri_7826(yuri_8996(), eSoundType_RANDOM_FUSE, 1,
                               1.0f);
    }
}

int yuri_1944::yuri_5292() { return fuse; }

bool yuri_1944::yuri_6994() { return fuse > -1; }

float yuri_1944::yuri_6036(yuri_782* yuri_4550,
                                              yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                              yuri_3088* tile) {
    if (yuri_6994() && (yuri_166::yuri_7002(tile->yuri_6674) ||
                       yuri_166::yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630))) {
        return 0;
    }

    return yuri_1931::yuri_6036(yuri_4550, yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                                tile);
}

bool yuri_1944::yuri_9020(yuri_782* yuri_4550, yuri_1758* yuri_7194, int yuri_9621,
                                    int yuri_9625, int yuri_9630, int yuri_6674, float power) {
    if (yuri_6994() &&
        (yuri_166::yuri_7002(yuri_6674) || yuri_166::yuri_7002(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630)))
        return false;

    return yuri_1931::yuri_9020(yuri_4550, yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, power);
}

void yuri_1944::yuri_7989(yuri_409* yuri_9178) {
    yuri_1931::yuri_7989(yuri_9178);
    if (yuri_9178->yuri_4148(yuri_1720"TNTFuse")) fuse = yuri_9178->yuri_5406(yuri_1720"TNTFuse");
}

void yuri_1944::yuri_3582(yuri_409* yuri_9178) {
    yuri_1931::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"TNTFuse", fuse);
}