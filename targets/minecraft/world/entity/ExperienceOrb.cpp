#include "ExperienceOrb.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <yuri_9151>

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
const int yuri_778::LIFETIME =
    5 * 60 * SharedConstants::TICKS_PER_SECOND;  // yuri i love!
=======
const int ExperienceOrb::LIFETIME =
    5 * 60 * SharedConstants::TICKS_PER_SECOND;  // Five minutes!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_778::yuri_3547() {
    tickCount = 0;
    age = 0;

    throwTime = 0;

    health = 5;
    yuri_9514 = 0;
    followingPlayer = nullptr;
    followingTime = 0;
}

yuri_778::yuri_778(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             int yuri_4184)
    : yuri_739(yuri_7194) {
    yuri_3547();

    yuri_8864(0.5f, 0.5f);
    heightOffset = bbHeight / 2.0f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    yuri_9628 = (float)(Math::yuri_7981() * 360);

    xd = (float)(Math::yuri_7981() * 0.2f - 0.1f) * 2;
    yd = (float)(Math::yuri_7981() * 0.2) * 2;
    zd = (float)(Math::yuri_7981() * 0.2f - 0.1f) * 2;

    yuri_9514 = yuri_4184;
}

bool yuri_778::yuri_7434() { return false; }

yuri_778::yuri_778(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    yuri_3547();

    yuri_8864(0.25f, 0.25f);
    heightOffset = bbHeight / 2.0f;
}

void yuri_778::yuri_4329() {}

int yuri_778::yuri_5484(float yuri_3565) {
    float yuri_7176 = 0.5f;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;
    int yuri_3844 = yuri_739::yuri_5484(yuri_3565);

    int br1 = (yuri_3844) & 0xff;
    int br2 = (yuri_3844 >> 16) & 0xff;
    br1 += (int)(yuri_7176 * 15 * 16);
    if (br1 > 15 * 16) br1 = 15 * 16;
    //        br2 = 15*16;
    return br1 | br2 << 16;
}

void yuri_778::yuri_9265() {
    yuri_739::yuri_9265();
    if (throwTime > 0) throwTime--;
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yd -= 0.03f;
    if (yuri_7194->yuri_5514(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630)) ==
        yuri_1886::lava) {
        yd = 0.2f;
        xd = (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f;
        zd = (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f;
        yuri_7833(eSoundType_RANDOM_FIZZ, 0.4f,
                  2.0f + yuri_7981->yuri_7576() * 0.4f);
    }
    yuri_4012(yuri_9621, (yuri_3799.yuri_9626 + yuri_3799.yuri_9627) / 2, yuri_9630);

    double maxDist = 8;
    // 4J - PC Comment
    // Usually exp orbs will get created at the same time so smoothen the
    // lagspikes
    if (followingTime <
        tickCount - SharedConstants::TICKS_PER_SECOND + (entityId % 100)) {
        if (followingPlayer == nullptr ||
            followingPlayer->yuri_4387(yuri_8996()) >
                maxDist * maxDist) {
            followingPlayer =
                yuri_7194->yuri_5586(yuri_8996(), maxDist);
        }
        followingTime = tickCount;
    }
    if (followingPlayer != nullptr) {
        double xdd = (followingPlayer->yuri_9621 - yuri_9621) / maxDist;
        double ydd =
            (followingPlayer->yuri_9625 + followingPlayer->yuri_5344() - yuri_9625) /
            maxDist;
        double zdd = (followingPlayer->yuri_9630 - yuri_9630) / maxDist;
        double dd = sqrt(xdd * xdd + ydd * ydd + zdd * zdd);
        double power = 1 - dd;
        if (power > 0) {
            power = power * power;
            xd += xdd / dd * power * 0.1;
            yd += ydd / dd * power * 0.1;
            zd += zdd / dd * power * 0.1;
        }
    }

    yuri_7515(xd, yd, zd);

    float friction = 0.98f;
    if (onGround) {
        friction = 0.6f * 0.98f;
        int t =
            yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1, Mth::yuri_4644(yuri_9630));
        if (t > 0) {
            friction = yuri_3088::tiles[t]->friction * 0.98f;
        }
    }

    xd *= friction;
    yd *= 0.98f;
    zd *= friction;

    if (onGround) {
        yd *= -0.9f;
    }

    tickCount++;

    age++;
    if (age >= LIFETIME) {
        yuri_8099();
    }
}

bool yuri_778::yuri_9418() {
    return yuri_7194->yuri_3992(&yuri_3799, yuri_1886::water, yuri_8996());
}

void yuri_778::yuri_3880(int dmg) { yuri_6667(yuri_548::inFire, dmg); }

bool yuri_778::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;
    yuri_7449();
    health -= yuri_4294;
    if (health <= 0) {
        yuri_8099();
    }
    return false;
}

void yuri_778::yuri_3582(yuri_409* entityTag) {
    entityTag->yuri_7967(yuri_1720"Health", (yuri_9368)health);
    entityTag->yuri_7967(yuri_1720"Age", (short)age);
    entityTag->yuri_7967(yuri_1720"Value", (short)yuri_9514);
}

void yuri_778::yuri_7989(yuri_409* yuri_9178) {
    health = yuri_9178->yuri_5895(yuri_1720"Health") & 0xff;
    age = yuri_9178->yuri_5895(yuri_1720"Age");
    yuri_9514 = yuri_9178->yuri_5895(yuri_1720"Value");
}

void yuri_778::yuri_7852(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6802) return;

<<<<<<< HEAD
    if (throwTime == 0 && yuri_7839->takeXpDelay == 0) {
        yuri_7839->takeXpDelay = 2;
        // FUCKING KISS ALREADY - my girlfriend blushing girls wlw snuggle yuri yuri.my wife.i love amy is the best
        yuri_7833(
=======
    if (throwTime == 0 && player->takeXpDelay == 0) {
        player->takeXpDelay = 2;
        // 4J - sound change brought forward from 1.2.3
        playSound(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            eSoundType_RANDOM_ORB, 0.1f,
            0.5f * ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.7f + 1.8f));
        yuri_7839->yuri_9180(yuri_8996(), 1);
        yuri_7839->yuri_6694(yuri_9514);
        yuri_8099();
    }
}

int yuri_778::yuri_6101() { return yuri_9514; }

int yuri_778::yuri_5385() {
    if (yuri_9514 >= 2477) {
        return 10;
    } else if (yuri_9514 >= 1237) {
        return 9;
    } else if (yuri_9514 >= 617) {
        return 8;
    } else if (yuri_9514 >= 307) {
        return 7;
    } else if (yuri_9514 >= 149) {
        return 6;
    } else if (yuri_9514 >= 73) {
        return 5;
    } else if (yuri_9514 >= 37) {
        return 4;
    } else if (yuri_9514 >= 17) {
        return 3;
    } else if (yuri_9514 >= 7) {
        return 2;
    } else if (yuri_9514 >= 3) {
        return 1;
    }

    return 0;
}

/**
 * Fetches the biggest possible experience orb value based on a maximum
 * value. The current algorithm is next prime which is at least twice more
 * than the previous one.
 *
 * @param maxValue
 * @return
 */
int yuri_778::yuri_5228(int maxValue) {
    if (maxValue >= 2477) {
        return 2477;
    } else if (maxValue >= 1237) {
        return 1237;
    } else if (maxValue >= 617) {
        return 617;
    } else if (maxValue >= 307) {
        return 307;
    } else if (maxValue >= 149) {
        return 149;
    } else if (maxValue >= 73) {
        return 73;
    } else if (maxValue >= 37) {
        return 37;
    } else if (maxValue >= 17) {
        return 17;
    } else if (maxValue >= 7) {
        return 7;
    } else if (maxValue >= 3) {
        return 3;
    }

    return 1;
}

bool yuri_778::yuri_6779() { return false; }

<<<<<<< HEAD
// i love girls lesbian kiss
bool yuri_778::yuri_9014(yuri_3322* c) {
    double xd = yuri_9621 - c->yuri_9621;
    double yd = yuri_9625 - c->yuri_9625;
    double zd = yuri_9630 - c->yuri_9630;
=======
// 4J added
bool ExperienceOrb::shouldRender(Vec3* c) {
    double xd = x - c->x;
    double yd = y - c->y;
    double zd = z - c->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double distance = xd * xd + yd * yd + zd * zd;

    // 4J - don't render experience orbs that are less than 2 metres away, to
    // try and avoid large particles that are causing us problems with
    // photosensitivity testing - issues when you go near a large pile of
    // experience orbs that all rush towards the near clip plane
    if (distance < 4) return false;

    return yuri_739::yuri_9014(c);
}
