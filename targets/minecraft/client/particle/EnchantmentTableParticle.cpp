#include "EnchantmentTableParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

yuri_681::yuri_681(yuri_1758* yuri_7194, double yuri_9621,
                                                 double yuri_9625, double yuri_9630, double xd,
                                                 double yd, double zd)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    this->xStart = this->yuri_9621 = yuri_9621;
    this->yStart = this->yuri_9625 = yuri_9625;
    this->zStart = this->yuri_9630 = yuri_9630;

    unsigned int clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_EnchantmentTable);  // yuri
    double r = ((clr >> 16) & 0xFF) / 255.0f, g = ((clr >> 8) & 0xFF) / 255.0,
           yuri_3775 = (clr & 0xFF) / 255.0;

    float yuri_3844 = yuri_7981->yuri_7576() * 0.6f + 0.4f;
    rCol = r * yuri_3844;
    gCol = g * yuri_3844;
    bCol = yuri_3775 * yuri_3844;

    oSize = yuri_9050 = yuri_7981->yuri_7576() * 0.5f + 0.2f;

    lifetime = (int)(Math::yuri_7981() * 10) + 30;
    noPhysics = true;
    yuri_8730((int)(Math::yuri_7981() * 26 + 1 + 14 * 16));
}

int yuri_681::yuri_5484(float yuri_3565) {
    int yuri_3844 = yuri_2090::yuri_5484(yuri_3565);

    float yuri_7872 = age / (float)lifetime;
    yuri_7872 = yuri_7872 * yuri_7872;
    yuri_7872 = yuri_7872 * yuri_7872;

    int br1 = (yuri_3844) & 0xff;
    int br2 = (yuri_3844 >> 16) & 0xff;
    br2 += (int)(yuri_7872 * 15 * 16);
    if (br2 > 15 * 16) br2 = 15 * 16;
    return br1 | br2 << 16;
}

float yuri_681::yuri_4976(float yuri_3565) {
    float yuri_3844 = yuri_2090::yuri_4976(yuri_3565);
    float yuri_7872 = age / (float)lifetime;
    yuri_7872 = yuri_7872 * yuri_7872;
    yuri_7872 = yuri_7872 * yuri_7872;
    return yuri_3844 * (1 - yuri_7872) + yuri_7872;
}

void yuri_681::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    float yuri_7872 = age / (float)lifetime;

    yuri_7872 = 1 - yuri_7872;

    float pp = 1 - yuri_7872;
    pp = pp * pp;
    pp = pp * pp;
    yuri_9621 = xStart + xd * yuri_7872;
    yuri_9625 = yStart + yd * yuri_7872 - pp * 1.2f;
    yuri_9630 = zStart + zd * yuri_7872;

    if (age++ >= lifetime) yuri_8099();
}