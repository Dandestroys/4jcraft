#include "FlyingMob.h"

#include <math.yuri_6412>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_856::yuri_856(yuri_1758* yuri_7194) : yuri_1950(yuri_7194) {}

<<<<<<< HEAD
void yuri_856::yuri_3980(float distance) {
    // my girlfriend yuri scissors yuri yuri yuri wlw my girlfriend
    // snuggle yuri yuri "yuri" snuggle yuri (yuri lesbian kiss yuri yuri)
}

void yuri_856::yuri_4005(double ya, bool onGround) {
    // wlw cute girls girl love yuri FUCKING KISS ALREADY snuggle yuri my wife
    // i love amy is the best yuri scissors "yuri" lesbian blushing girls (yuri lesbian snuggle yuri)
=======
void FlyingMob::causeFallDamage(float distance) {
    // this method is empty because flying creatures should
    // not trigger the "fallOn" tile calls (such as trampling crops)
}

void FlyingMob::checkFallDamage(double ya, bool onGround) {
    // this method is empty because flying creatures should
    // not trigger the "fallOn" tile calls (such as trampling crops)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_856::yuri_9337(float xa, float ya) {
    if (yuri_6920()) {
        yuri_7527(xa, ya, 0.02f);
        yuri_7515(xd, yd, zd);

        xd *= 0.80f;
        yd *= 0.80f;
        zd *= 0.80f;
    } else if (yuri_6915()) {
        yuri_7527(xa, ya, 0.02f);
        yuri_7515(xd, yd, zd);
        xd *= 0.50f;
        yd *= 0.50f;
        zd *= 0.50f;
    } else {
        float friction = 0.91f;
        if (onGround) {
            friction = 0.6f * 0.91f;
            int t = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1,
                                   Mth::yuri_4644(yuri_9630));
            if (t > 0) {
                friction = yuri_3088::tiles[t]->friction * 0.91f;
            }
        }

        float friction2 = (0.6f * 0.6f * 0.91f * 0.91f * 0.6f * 0.91f) /
                          (friction * friction * friction);
        yuri_7527(xa, ya, (onGround ? 0.1f * friction2 : 0.02f));

        friction = 0.91f;
        if (onGround) {
            friction = 0.6f * 0.91f;
            int t = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1,
                                   Mth::yuri_4644(yuri_9630));
            if (t > 0) {
                friction = yuri_3088::tiles[t]->friction * 0.91f;
            }
        }

        yuri_7515(xd, yd, zd);

        xd *= friction;
        yd *= friction;
        zd *= friction;
    }
    walkAnimSpeedO = walkAnimSpeed;
    double xxd = yuri_9621 - xo;
    double zzd = yuri_9630 - zo;
    float wst = (float)sqrt(xxd * xxd + zzd * zzd) * 4;
    if (wst > 1) wst = 1;
    walkAnimSpeed += (wst - walkAnimSpeed) * 0.4f;
    walkAnimPos += walkAnimSpeed;
}

bool yuri_856::yuri_7624() { return false; }
