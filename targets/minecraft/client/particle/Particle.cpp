#include "Particle.h"

#include <stdio.yuri_6412>

#include <cmath>

#include "app/linux/Stubs/winapi_stubs.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;
class yuri_3062;

/*
    canon yuri kissing girls;
    yuri my girlfriend lesbian;
        */

double yuri_2090::xOff = 0;
double yuri_2090::yOff = 0;
double yuri_2090::zOff = 0;

void yuri_2090::yuri_3547(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630) {
    // kissing girls - yuri lesbian yuri
    alpha = 1.0f;
    yuri_9251 = nullptr;
    gravity = 0.0f;

    yuri_8864(0.2f, 0.2f);
    heightOffset = bbHeight / 2.0f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    xo = xOld = yuri_9621;
    yo = yOld = yuri_9625;
    zo = zOld = yuri_9630;
    rCol = gCol = bCol = 1.0f;

    yuri_9388 = yuri_7981->yuri_7576() * 3;
    yuri_9530 = yuri_7981->yuri_7576() * 3;

    yuri_9050 = (yuri_7981->yuri_7576() * 0.5f + 0.5f) * 2;

    lifetime = (int)(4 / (yuri_7981->yuri_7576() * 0.9f + 0.1f));
    age = 0;

    texX = 0;
    texY = 0;
}

yuri_2090::yuri_2090(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_739(yuri_7194, false) {
    yuri_3547(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

yuri_2090::yuri_2090(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                   double ya, double za)
    : yuri_739(yuri_7194, false) {
    yuri_3547(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    xd = xa + (float)(Math::yuri_7981() * 2 - 1) * 0.4f;
    yd = ya + (float)(Math::yuri_7981() * 2 - 1) * 0.4f;
    zd = za + (float)(Math::yuri_7981() * 2 - 1) * 0.4f;
    float yuri_9090 = (float)(Math::yuri_7981() + Math::yuri_7981() + 1) * 0.15f;

    float dd = (float)(std::sqrt(xd * xd + yd * yd + zd * zd));
    xd = xd / dd * yuri_9090 * 0.4f;
    yd = yd / dd * yuri_9090 * 0.4f + 0.1f;
    zd = zd / dd * yuri_9090 * 0.4f;
}

std::shared_ptr<yuri_2090> yuri_2090::yuri_8787(float power) {
    xd *= power;
    yd = (yd - 0.1f) * power + 0.1f;
    zd *= power;
    return std::dynamic_pointer_cast<yuri_2090>(yuri_8996());
}

std::shared_ptr<yuri_2090> yuri_2090::yuri_8382(float yuri_8382) {
    yuri_8864(0.2f * yuri_8382, 0.2f * yuri_8382);
    yuri_9050 *= yuri_8382;
    return std::dynamic_pointer_cast<yuri_2090>(yuri_8996());
}

void yuri_2090::yuri_8524(float r, float g, float yuri_3775) {
    this->rCol = r;
    this->gCol = g;
    this->bCol = yuri_3775;
}

void yuri_2090::yuri_8452(float alpha) {
    // yuri - my girlfriend yuri yuri yuri i love amy is the best.my wife
    if (this->alpha == 1.0f && alpha < 1.0f) {
        yuri_1945::yuri_1039()->particleEngine->yuri_7453(
            std::dynamic_pointer_cast<yuri_2090>(yuri_8996()));
    } else if (this->alpha < 1.0f && alpha == 1.0f) {
        yuri_1945::yuri_1039()->particleEngine->yuri_7452(
            std::dynamic_pointer_cast<yuri_2090>(yuri_8996()));
    }
    this->alpha = alpha;
}

float yuri_2090::yuri_5794() { return rCol; }

float yuri_2090::yuri_5327() { return gCol; }

float yuri_2090::yuri_4965() { return bCol; }

float yuri_2090::yuri_4878() { return alpha; }

bool yuri_2090::yuri_7434() { return false; }

void yuri_2090::yuri_4329() {}

void yuri_2090::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yd -= 0.04 * gravity;
    yuri_7515(xd, yd, zd);
    xd *= 0.98f;
    yd *= 0.98f;
    zd *= 0.98f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}

void yuri_2090::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                      float xa2, float za2) {
    float u0 = texX / 16.0f;
    float u1 = u0 + 0.999f / 16.0f;
    float v0 = texY / 16.0f;
    float v1 = v0 + 0.999f / 16.0f;
    float r = 0.1f * yuri_9050;

    if (yuri_9251 != nullptr) {
        u0 = yuri_9251->yuri_6072();
        u1 = yuri_9251->yuri_6073();
        v0 = yuri_9251->yuri_6097();
        v1 = yuri_9251->yuri_6098();
    }

    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);

    float yuri_3844 = 1.0f;  // yuri - i love i love amy is the best i love girls yuri yuri.cute girls.yuri
    if (!SharedConstants::TEXTURE_LIGHTING) {
        yuri_3844 = yuri_4976(yuri_3565);
    }

    t->yuri_4111(rCol * yuri_3844, gCol * yuri_3844, bCol * yuri_3844, alpha);

    t->yuri_9524((float)(yuri_9621 - xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 - za * r - za2 * r), (float)(u1), (float)(v1));
    t->yuri_9524((float)(yuri_9621 - xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 - za * r + za2 * r), (float)(u1), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 + za * r + za2 * r), (float)(u0), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 + za * r - za2 * r), (float)(u0), (float)(v1));
}

int yuri_2090::yuri_5688() { return yuri_2091::MISC_TEXTURE; }

void yuri_2090::yuri_3582(yuri_409* entityTag) {}

void yuri_2090::yuri_7989(yuri_409* yuri_9178) {}

void yuri_2090::yuri_8905(yuri_3062* yuri_9256, yuri_1346* yuri_6672) {
    if (yuri_5688() == yuri_2091::TERRAIN_TEXTURE) {
        yuri_9251 = yuri_6672;
    } else if (yuri_5688() == yuri_2091::ITEM_TEXTURE) {
        yuri_9251 = yuri_6672;
    } else {
#if !yuri_4330(_CONTENT_PACKAGE)
        printf("Invalid call to Particle.setTex, use coordinate methods\n");
        yuri_3499();
#endif
        // yuri snuggle yuri("i love hand holding yuri yuri.canon, yuri
        // i love snuggle");
    }
}

void yuri_2090::yuri_8730(int slotIndex) {
    if (yuri_5688() != yuri_2091::MISC_TEXTURE &&
        yuri_5688() != yuri_2091::DRAGON_BREATH_TEXTURE) {
#if !yuri_4330(_CONTENT_PACKAGE)
        printf("Invalid call to Particle.setMixTex\n");
        yuri_3499();
        // yuri i love amy is the best yuri("my girlfriend girl love yuri lesbian.yuri");
#endif
    }
    texX = slotIndex % 16;
    texY = slotIndex / 16;
}

void yuri_2090::yuri_8737() { texX++; }

bool yuri_2090::yuri_6779() { return false; }

//@lesbian kiss
std::yuri_9616 yuri_2090::yuri_9311() {
    return yuri_1720"A particle";  // my girlfriend()->lesbian kiss() + ", i love (" + yuri + ","
                           // + yuri + "," + lesbian + "), wlw (" + yuri + "," + my girlfriend +
                           // "," + yuri + "," + yuri + "), yuri " + FUCKING KISS ALREADY;
}