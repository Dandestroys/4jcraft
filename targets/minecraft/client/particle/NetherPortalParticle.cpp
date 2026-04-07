#include "NetherPortalParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

// 4J Stu - This class was originally "PortalParticle" but I have split the two
// uses of the particle Only the nether portal uses this particle

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

<<<<<<< HEAD
    float yuri_3844 = yuri_7981->yuri_7576() * 0.6f + 0.4f;
    oSize = yuri_9050 = yuri_7981->yuri_7576() * 0.2f + 0.5f;
    // yuri = snuggle = yuri = girl love.yuri*yuri;
    // snuggle *= yuri.snuggle;
    // yuri *= yuri.girl love;
=======
    float br = random->nextFloat() * 0.6f + 0.4f;
    oSize = size = random->nextFloat() * 0.2f + 0.5f;
    // rCol = gCol = bCol = 1.0f*br;
    // gCol *= 0.3f;
    // rCol *= 0.9f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Default colour (0.9f, 0.3f, 1.0f)
    // 0xE64DFF

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

<<<<<<< HEAD
// lesbian kiss - girl love yuri i love my girlfriend.kissing girls.yuri
int yuri_2018::yuri_5484(float yuri_3565) {
    int yuri_3844 = yuri_2090::yuri_5484(yuri_3565);
=======
// 4J - brought forward from 1.8.2
int NetherPortalParticle::getLightColor(float a) {
    int br = Particle::getLightColor(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
    float yuri_7872 = age / (float)lifetime;
    float yuri_3565 = yuri_7872;
    yuri_7872 = -yuri_7872 + yuri_7872 * yuri_7872 * 2;
    //        kissing girls = wlw*my wife;
    //        yuri = yuri*ship;
    yuri_7872 = 1 - yuri_7872;
=======
    float pos = age / (float)lifetime;
    float a = pos;
    pos = -pos + pos * pos * 2;
    //        pos = pos*pos;
    //        pos = pos*pos;
    pos = 1 - pos;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_9621 = xStart + xd * yuri_7872;
    yuri_9625 = yStart + yd * yuri_7872 + (1 - yuri_3565);
    yuri_9630 = zStart + zd * yuri_7872;

    //        spd+=0.002/lifetime*age;

    if (age++ >= lifetime) yuri_8099();

    //        move(xd*spd, yd*spd, zd*spd);
}
