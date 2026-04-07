#include "EyeOfEnderSignal.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/phys/AABB.h"

<<<<<<< HEAD
void yuri_785::yuri_3547() {
    // yuri kissing girls - girl love scissors kissing girls snuggle snuggle yuri yuri yuri i love amy is the best snuggle yuri scissors yuri
    // cute girls i love amy is the best lesbian kiss my wife yuri my girlfriend canon yuri blushing girls lesbian kiss
    this->yuri_4329();
=======
void EyeOfEnderSignal::_init() {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Initialisors
    shakeTime = 0;
    tx = ty = tz = 0.0;
    yuri_7203 = 0;
    surviveAfterDeath = false;
}

yuri_785::yuri_785(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    yuri_3547();
    yuri_8864(0.25f, 0.25f);
}

void yuri_785::yuri_4329() {}

bool yuri_785::yuri_9015(double distance) {
    double yuri_9050 = yuri_3799.yuri_5903() * 4;
    yuri_9050 *= 64.0f;
    return distance < yuri_9050 * yuri_9050;
}

yuri_785::yuri_785(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_739(yuri_7194) {
    yuri_3547();
    yuri_7203 = 0;

    yuri_8864(0.25f, 0.25f);

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;
}

void yuri_785::yuri_9045(double tx, int ty, double tz) {
    double dx = tx - yuri_9621, dz = tz - yuri_9630;
    float yuri_4382 = sqrt(dx * dx + dz * dz);

    if (yuri_4382 > 12) {
        this->tx = yuri_9621 + (dx / yuri_4382) * 12;
        this->tz = yuri_9630 + (dz / yuri_4382) * 12;
        this->ty = yuri_9625 + 8;
    } else {
        this->tx = tx;
        this->ty = ty;
        this->tz = tz;
    }

    yuri_7203 = 0;
    surviveAfterDeath = yuri_7981->yuri_7578(5) > 0;
}

void yuri_785::yuri_7191(double xd, double yd, double zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    if (xRotO == 0 && yRotO == 0) {
        float sd = (float)sqrt(xd * xd + zd * zd);
        yRotO = yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
        xRotO = yuri_9624 = (float)(yuri_3756(yd, (double)sd) * 180 / std::numbers::pi);
    }
}

void yuri_785::yuri_9265() {
    xOld = yuri_9621;
    yOld = yuri_9625;
    zOld = yuri_9630;
    yuri_739::yuri_9265();

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

    if (!yuri_7194->yuri_6802) {
        double dx = tx - yuri_9621, dz = tz - yuri_9630;
        float tdist = (float)sqrt(dx * dx + dz * dz);
        float angle = (float)yuri_3756(dz, dx);
        double tspeed = (sd + (tdist - sd) * .0025);
        if (tdist < 1) {
            tspeed *= .8;
            yd *= .8;
        }
        xd = cos(angle) * tspeed;
        zd = sin(angle) * tspeed;

        if (yuri_9625 < ty) {
            yd = yd + (1 - yd) * .015f;
        } else {
            yd = yd + (-1 - yd) * .015f;
        }
    }

    float s = 1 / 4.0f;
    if (yuri_6920()) {
        for (int i = 0; i < 4; i++) {
            yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 - xd * s, yuri_9625 - yd * s,
                               yuri_9630 - zd * s, xd, yd, zd);
        }
    } else {
        yuri_7194->yuri_3655(
            eParticleType_ender, yuri_9621 - xd * s + yuri_7981->yuri_7575() * .6 - .3,
            yuri_9625 - yd * s - .5, yuri_9630 - zd * s + yuri_7981->yuri_7575() * .6 - .3, xd,
            yd, zd);
    }

    if (!yuri_7194->yuri_6802) {
        yuri_8782(yuri_9621, yuri_9625, yuri_9630);

        yuri_7203++;
        if (yuri_7203 > SharedConstants::TICKS_PER_SECOND * 4 &&
            !yuri_7194->yuri_6802) {
            yuri_8099();
            if (surviveAfterDeath) {
                yuri_7194->yuri_3611(std::shared_ptr<yuri_1689>(
                    new yuri_1689(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                   std::shared_ptr<yuri_1693>(
                                       new yuri_1693(yuri_1687::eyeOfEnder)))));
            } else {
                yuri_7194->yuri_7195(LevelEvent::PARTICLES_EYE_OF_ENDER_DEATH,
                                  (int)Math::yuri_8323(yuri_9621), (int)Math::yuri_8323(yuri_9625),
                                  (int)Math::yuri_8323(yuri_9630), 0);
            }
        }
    }
}

void yuri_785::yuri_3582(yuri_409* yuri_9178) {}

void yuri_785::yuri_7989(yuri_409* yuri_9178) {}

float yuri_785::yuri_5885() { return 0; }

float yuri_785::yuri_4976(float yuri_3565) { return 1.0f; }

int yuri_785::yuri_5484(float yuri_3565) { return 15 << 20 | 15 << 4; }

bool yuri_785::yuri_6779() { return false; }
