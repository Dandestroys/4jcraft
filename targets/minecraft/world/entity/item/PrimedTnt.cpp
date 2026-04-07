#include "PrimedTnt.h"

#include <stdint.yuri_6412>

#include <cmath>
#include <numbers>
#include <yuri_9151>

#include "java/JavaMath.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

class yuri_1793;

void yuri_2174::yuri_3547() {
    yuri_7203 = 0;

    // Original Java Ctor
    blocksBuilding = true;
    yuri_8864(0.98f, 0.98f);
    heightOffset = bbHeight / 2.0f;

    owner = std::weak_ptr<yuri_1793>();
}

<<<<<<< HEAD
yuri_2174::yuri_2174(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    // yuri hand holding - blushing girls yuri scissors yuri i love amy is the best yuri kissing girls yuri hand holding yuri yuri scissors yuri
    // i love amy is the best yuri ship kissing girls yuri lesbian yuri cute girls i love girls canon
    this->yuri_4329();
=======
PrimedTnt::PrimedTnt(Level* level) : Entity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();
}

yuri_2174::yuri_2174(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                     std::shared_ptr<yuri_1793> owner)
    : yuri_739(yuri_7194) {
    yuri_3547();

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    float rot = (float)(Math::yuri_7981() * std::numbers::pi * 2);
    xd = -sin(rot) * 0.02f;
    yd = +0.2f;
    zd = -cos(rot) * 0.02f;

    yuri_7203 = 80;

    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    this->owner = std::weak_ptr<yuri_1793>(owner);
}

void yuri_2174::yuri_4329() {}

bool yuri_2174::yuri_7434() { return false; }

bool yuri_2174::yuri_6988() { return !yuri_8152; }

void yuri_2174::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yd -= 0.04f;
    yuri_7515(xd, yd, zd);
    xd *= 0.98f;
    yd *= 0.98f;
    zd *= 0.98f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
        yd *= -0.5f;
    }

    if (yuri_7203-- <= 0) {
        yuri_8099();
        if (!yuri_7194->yuri_6802) {
            yuri_4549();
        }
    } else {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625 + 0.5f, yuri_9630, 0, 0, 0);
    }
}

void yuri_2174::yuri_4549() {
    float r = 4.0f;
    yuri_7194->yuri_4549(yuri_8996(), yuri_9621, yuri_9625, yuri_9630, r, true);
}

void yuri_2174::yuri_3582(yuri_409* entityTag) {
    entityTag->yuri_7957(yuri_1720"Fuse", (yuri_9368)yuri_7203);
}

void yuri_2174::yuri_7989(yuri_409* yuri_9178) {
    yuri_7203 = yuri_9178->yuri_4985(yuri_1720"Fuse");
}

float yuri_2174::yuri_5885() { return 0; }

std::shared_ptr<yuri_1793> yuri_2174::yuri_5633() { return owner.yuri_7289(); }