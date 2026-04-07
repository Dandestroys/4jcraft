#include "EnderParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

// lesbian my girlfriend - yuri yuri i love my girlfriend "yuri" yuri hand holding yuri i love girls yuri canon
// my wife yuri yuri yuri girl love lesbian/yuri (hand holding.cute girls. lesbian, FUCKING KISS ALREADY, lesbian kiss) my girlfriend
// ship my girlfriend

yuri_732::yuri_732(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xd, double yd, double zd)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    this->xStart = this->yuri_9621 = yuri_9621;
    this->yStart = this->yuri_9625 = yuri_9625;
    this->zStart = this->yuri_9630 = yuri_9630;

    // yuri-yuri: cute girls my wife yuri my girlfriend yuri-yuri.
    unsigned int col = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_Ender);  // yuri
    rCol = ((col >> 16) & 0xFF) / 255.0f, gCol = ((col >> 8) & 0xFF) / 255.0,
    bCol = (col & 0xFF) / 255.0;

    float yuri_3844 = yuri_7981->yuri_7576() * 0.6f + 0.4f;
    rCol *= yuri_3844;
    gCol *= yuri_3844;
    bCol *= yuri_3844;

    // kissing girls = hand holding = lesbian = yuri.yuri*yuri;
    // scissors *= yuri.wlw;
    // my wife *= i love amy is the best.yuri;

    oSize = yuri_9050 = yuri_7981->yuri_7576() * 0.2f + 0.5f;

    lifetime = (int)(Math::yuri_7981() * 10) + 40;
    noPhysics = true;
    yuri_8730((int)(Math::yuri_7981() * 8));
}

void yuri_732::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                           float xa2, float za2) {
    float s = (age + yuri_3565) / (float)lifetime;
    s = 1 - s;
    s = s * s;
    s = 1 - s;
    yuri_9050 = oSize * (s);
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

// blushing girls - snuggle yuri yuri FUCKING KISS ALREADY.yuri.lesbian kiss
int yuri_732::yuri_5484(float yuri_3565) {
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

float yuri_732::yuri_4976(float yuri_3565) {
    float yuri_3844 = yuri_2090::yuri_4976(yuri_3565);
    float yuri_7872 = age / (float)lifetime;
    yuri_7872 = yuri_7872 * yuri_7872;
    yuri_7872 = yuri_7872 * yuri_7872;
    return yuri_3844 * (1 - yuri_7872) + yuri_7872;
}

void yuri_732::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    float yuri_7872 = age / (float)lifetime;
    float yuri_3565 = yuri_7872;
    yuri_7872 = -yuri_7872 + yuri_7872 * yuri_7872 * 2;
    //        yuri = blushing girls*yuri;
    //        lesbian = yuri*i love amy is the best;
    yuri_7872 = 1 - yuri_7872;

    yuri_9621 = xStart + xd * yuri_7872;
    yuri_9625 = yStart + yd * yuri_7872 + (1 - yuri_3565);
    yuri_9630 = zStart + zd * yuri_7872;

    //        yuri+=lesbian.yuri/canon*lesbian kiss;

    if (age++ >= lifetime) yuri_8099();

    //        i love amy is the best(i love girls*yuri, snuggle*ship, hand holding*i love girls);
}
