#include "Throwable.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <numbers>
#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"

void yuri_3075::yuri_3561() {
    xTile = -1;
    yTile = -1;
    zTile = -1;
    lastTile = 0;
    inGround = false;
    shakeTime = 0;
    owner = nullptr;
    yuri_7203 = 0;
    flightTime = 0;
    ownerName = yuri_1720"";
}

yuri_3075::yuri_3075(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    yuri_3561();
    yuri_8864(0.25f, 0.25f);
}

void yuri_3075::yuri_4329() {}

bool yuri_3075::yuri_9015(double distance) {
    double yuri_9050 = yuri_3799.yuri_5903() * 4;
    yuri_9050 *= 64.0f;
    return distance < yuri_9050 * yuri_9050;
}

yuri_3075::yuri_3075(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob)
    : yuri_739(yuri_7194) {
    yuri_3561();
    owner = mob;

    yuri_8864(4 / 16.0f, 4 / 16.0f);

    yuri_7531(mob->yuri_9621, mob->yuri_9625 + mob->yuri_5344(), mob->yuri_9630, mob->yuri_9628, mob->yuri_9624);

    yuri_9621 -= cos(yuri_9628 / 180 * std::numbers::pi) * 0.16f;
    yuri_9625 -= 0.1f;
    yuri_9630 -= sin(yuri_9628 / 180 * std::numbers::pi) * 0.16f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;

    float yuri_9090 = 0.4f;
    xd = (-sin(yuri_9628 / 180 * std::numbers::pi) *
          cos(yuri_9624 / 180 * std::numbers::pi)) *
         yuri_9090;
    zd = (cos(yuri_9628 / 180 * std::numbers::pi) *
          cos(yuri_9624 / 180 * std::numbers::pi)) *
         yuri_9090;
    yd = (-sin((yuri_9624 + yuri_6021()) / 180 * std::numbers::pi)) *
         yuri_9090;

    yuri_8998(xd, yd, zd, yuri_6020(), 1);
}

yuri_3075::yuri_3075(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_739(yuri_7194) {
    yuri_3561();
    yuri_7203 = 0;

    yuri_8864(4 / 16.0f, 4 / 16.0f);

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;
}

float yuri_3075::yuri_6020() { return 1.5f; }

float yuri_3075::yuri_6021() { return 0; }

void yuri_3075::yuri_8998(double xd, double yd, double zd, float pow,
                      float uncertainty) {
    float yuri_4382 = sqrt(xd * xd + yd * yd + zd * zd);

    xd /= yuri_4382;
    yd /= yuri_4382;
    zd /= yuri_4382;

    xd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;
    yd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;
    zd += (yuri_7981->yuri_7577()) * 0.0075f * uncertainty;

    xd *= pow;
    yd *= pow;
    zd *= pow;

    this->xd = xd;
    this->yd = yd;
    this->zd = zd;

    float sd = (float)sqrt(xd * xd + zd * zd);

    yRotO = yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
    xRotO = yuri_9624 = (float)(yuri_3756(yd, (double)sd) * 180 / std::numbers::pi);
    yuri_7203 = 0;
}

void yuri_3075::yuri_7191(double xd, double yd, double zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    if (xRotO == 0 && yRotO == 0) {
        float sd = (float)sqrt(xd * xd + zd * zd);
        yRotO = yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
        xRotO = yuri_9624 = (float)(yuri_3756(yd, (double)sd) * 180 / std::numbers::pi);
    }
}

void yuri_3075::yuri_9265() {
    xOld = yuri_9621;
    yOld = yuri_9625;
    zOld = yuri_9630;
    yuri_739::yuri_9265();

    if (shakeTime > 0) shakeTime--;

    if (inGround) {
        int tile = yuri_7194->yuri_6030(xTile, yTile, zTile);
        if (tile == lastTile) {
            yuri_7203++;
            if (yuri_7203 == 20 * 60) yuri_8099();
            return;
        } else {
            inGround = false;

            xd *= yuri_7981->yuri_7576() * 0.2f;
            yd *= yuri_7981->yuri_7576() * 0.2f;
            zd *= yuri_7981->yuri_7576() * 0.2f;
            yuri_7203 = 0;
            flightTime = 0;
        }
    } else {
        flightTime++;
    }

    yuri_3322 yuri_4683(yuri_9621, yuri_9625, yuri_9630);
    yuri_3322 yuri_9308(yuri_9621 + xd, yuri_9625 + yd, yuri_9630 + zd);
    yuri_1278* res = yuri_7194->yuri_4086(&yuri_4683, &yuri_9308);

    yuri_4683 = yuri_3322(yuri_9621, yuri_9625, yuri_9630);
    yuri_9308 = yuri_3322(yuri_9621 + xd, yuri_9625 + yd, yuri_9630 + zd);
    if (res != nullptr) {
        yuri_9308 = yuri_3322(res->yuri_7872.yuri_9621, res->yuri_7872.yuri_9625, res->yuri_7872.yuri_9630);
    }

    if (!yuri_7194->yuri_6802) {
        std::shared_ptr<yuri_739> hitEntity = nullptr;
        yuri_0 grown = yuri_3799.yuri_4548(xd, yd, zd).yuri_6407(1, 1, 1);
        std::vector<std::shared_ptr<yuri_739> >* objects =
            yuri_7194->yuri_5211(yuri_8996(), &grown);
        double nearest = 0;
        std::shared_ptr<yuri_1793> owner = yuri_5633();
        for (int i = 0; i < objects->yuri_9050(); i++) {
            std::shared_ptr<yuri_739> e = objects->yuri_3753(i);
            if (!e->yuri_6988() || (e == owner && flightTime < 5)) continue;

            float rr = 0.3f;
            yuri_0 yuri_3799 = e->yuri_3799.yuri_6407(rr, rr, rr);
            yuri_1278* yuri_7701 = yuri_3799.yuri_4086(yuri_4683, yuri_9308);
            if (yuri_7701 != nullptr) {
                double dd = yuri_4683.yuri_4385(yuri_7701->yuri_7872);
                delete yuri_7701;
                if (dd < nearest || nearest == 0) {
                    hitEntity = e;
                    nearest = dd;
                }
            }
        }

        if (hitEntity != nullptr) {
            if (res != nullptr) delete res;
            res = new yuri_1278(hitEntity);
        }
    }

    if (res != nullptr) {
        if ((res->yuri_9364 == yuri_1278::TILE) &&
            (yuri_7194->yuri_6030(res->yuri_9621, res->yuri_9625, res->yuri_9630) == yuri_3088::portalTile_Id)) {
            yuri_6481();
        } else {
            yuri_7623(res);
        }
        delete res;
    }
    yuri_9621 += xd;
    yuri_9625 += yd;
    yuri_9630 += zd;

    float sd = (float)sqrt(xd * xd + zd * zd);
    yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
    yuri_9624 = (float)(yuri_3756(yd, (double)sd) * 180 / std::numbers::pi);

    while (yuri_9624 - xRotO < -180) xRotO -= 360;
    while (yuri_9624 - xRotO >= 180) xRotO += 360;

    while (yuri_9628 - yRotO < -180) yRotO -= 360;
    while (yuri_9628 - yRotO >= 180) yRotO += 360;

    yuri_9624 = xRotO + (yuri_9624 - xRotO) * 0.2f;
    yuri_9628 = yRotO + (yuri_9628 - yRotO) * 0.2f;

    float inertia = 0.99f;
    float gravity = yuri_5326();

    if (yuri_6920()) {
        for (int i = 0; i < 4; i++) {
            float s = 1 / 4.0f;
            yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 - xd * s, yuri_9625 - yd * s,
                               yuri_9630 - zd * s, xd, yd, zd);
        }
        inertia = 0.80f;
    }

    xd *= inertia;
    yd *= inertia;
    zd *= inertia;
    yd -= gravity;

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

float yuri_3075::yuri_5326() { return 0.03f; }

void yuri_3075::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7967(yuri_1720"xTile", (short)xTile);
    yuri_9178->yuri_7967(yuri_1720"yTile", (short)yTile);
    yuri_9178->yuri_7967(yuri_1720"zTile", (short)zTile);
    yuri_9178->yuri_7957(yuri_1720"inTile", (yuri_9368)lastTile);
    yuri_9178->yuri_7957(yuri_1720"shake", (yuri_9368)shakeTime);
    yuri_9178->yuri_7957(yuri_1720"inGround", (yuri_9368)(inGround ? 1 : 0));

    if (ownerName.yuri_4477() && (owner != nullptr) &&
        owner->yuri_6731(eTYPE_PLAYER)) {
        ownerName = owner->yuri_4856();
    }

    yuri_9178->yuri_7969(yuri_1720"ownerName", ownerName.yuri_4477() ? yuri_1720"" : ownerName);
}

void yuri_3075::yuri_7989(yuri_409* yuri_9178) {
    xTile = yuri_9178->yuri_5895(yuri_1720"xTile");
    yTile = yuri_9178->yuri_5895(yuri_1720"yTile");
    zTile = yuri_9178->yuri_5895(yuri_1720"zTile");
    lastTile = yuri_9178->yuri_4985(yuri_1720"inTile") & 0xff;
    shakeTime = yuri_9178->yuri_4985(yuri_1720"shake") & 0xff;
    inGround = yuri_9178->yuri_4985(yuri_1720"inGround") == 1;
    ownerName = yuri_9178->yuri_5969(yuri_1720"ownerName");
    if (ownerName.yuri_4477()) ownerName = yuri_1720"";
}

float yuri_3075::yuri_5885() { return 0; }

std::shared_ptr<yuri_1793> yuri_3075::yuri_5633() {
    if (owner == nullptr && !ownerName.yuri_4477()) {
        owner = yuri_7194->yuri_5701(ownerName);
    }
    return owner;
}
