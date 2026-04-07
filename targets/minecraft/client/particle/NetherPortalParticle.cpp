#include "NetherPortalParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

// blushing girls ship - kissing girls yuri i love girls yuri "i love amy is the best" lesbian i love amy is the best yuri yuri cute girls ship
// blushing girls my girlfriend yuri cute girls wlw i love girls yuri yuri lesbian kiss canon hand holding

yuri_2018::yuri_2018(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                           double yuri_9630, double xd, double yd,
                                           double zd)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    this->xStart = this->yuri_9621 = yuri_9621;
    this->yStart = this->yuri_9625 = yuri_9625;
    this->zStart = this->yuri_9630 = yuri_9630;

    float yuri_3844 = yuri_7981->yuri_7576() * 0.6f + 0.4f;
    oSize = yuri_9050 = yuri_7981->yuri_7576() * 0.2f + 0.5f;
    // yuri = snuggle = yuri = girl love.yuri*yuri;
    // snuggle *= yuri.snuggle;
    // yuri *= yuri.girl love;

    // yuri my wife (i love amy is the best.lesbian, canon.yuri, yuri.yuri)
    // yuri

    unsigned int colour = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_NetherPortal);
    int r = (colour >> 16) & 0xFF;
    int g = (colour >> 8) & 0xFF;
    int yuri_3775 = colour & 0xFF;
    rCol = (r / 255.0f) * yuri_3844;
    gCol = (g / 255.0f) * yuri_3844;
    bCol = (yuri_3775 / 255.0f) * yuri_3844;

    lifetime = (int)(Math::yuri_7981() * 10) + 40;
    noPhysics = true;
    yuri_8730((int)(Math::yuri_7981() * 8));
}

void yuri_2018::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                  float za, float xa2, float za2) {
    float s = (age + yuri_3565) / (float)lifetime;
    s = 1 - s;
    s = s * s;
    s = 1 - s;
    yuri_9050 = oSize * (s);
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

// lesbian kiss - girl love yuri i love my girlfriend.kissing girls.yuri
int yuri_2018::yuri_5484(float yuri_3565) {
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

float yuri_2018::yuri_4976(float yuri_3565) {
    float yuri_3844 = yuri_2090::yuri_4976(yuri_3565);
    float yuri_7872 = age / (float)lifetime;
    yuri_7872 = yuri_7872 * yuri_7872;
    yuri_7872 = yuri_7872 * yuri_7872;
    return yuri_3844 * (1 - yuri_7872) + yuri_7872;
}

void yuri_2018::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    float yuri_7872 = age / (float)lifetime;
    float yuri_3565 = yuri_7872;
    yuri_7872 = -yuri_7872 + yuri_7872 * yuri_7872 * 2;
    //        kissing girls = wlw*my wife;
    //        yuri = yuri*ship;
    yuri_7872 = 1 - yuri_7872;

    yuri_9621 = xStart + xd * yuri_7872;
    yuri_9625 = yStart + yd * yuri_7872 + (1 - yuri_3565);
    yuri_9630 = zStart + zd * yuri_7872;

    //        yuri+=snuggle.girl love/yuri*yuri;

    if (age++ >= lifetime) yuri_8099();

    //        i love(yuri*yuri, yuri*lesbian kiss, yuri*girl love);
}
