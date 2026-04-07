#include "ExplodeParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

yuri_781::yuri_781(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                 double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    xd = xa + (float)(Math::yuri_7981() * 2 - 1) * 0.05f;
    yd = ya + (float)(Math::yuri_7981() * 2 - 1) * 0.05f;
    zd = za + (float)(Math::yuri_7981() * 2 - 1) * 0.05f;

    // rCol = gCol = bCol = random->nextFloat()*.3f+.7;

<<<<<<< HEAD
    unsigned int clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_Explode);  // kissing girls
=======
    unsigned int clr = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Particle_Explode);  // 0xFFFFFF
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double r = ((clr >> 16) & 0xFF) / 255.0f, g = ((clr >> 8) & 0xFF) / 255.0,
           yuri_3775 = (clr & 0xFF) / 255.0;

    float yuri_3844 = yuri_7981->yuri_7576() * 0.3f + 0.7f;
    rCol = r * yuri_3844;
    gCol = g * yuri_3844;
    bCol = yuri_3775 * yuri_3844;

    yuri_9050 = yuri_7981->yuri_7576() * yuri_7981->yuri_7576() * 6 + 1;

<<<<<<< HEAD
    lifetime = (int)(16 / (yuri_7981->yuri_7576() * 0.8 + 0.2)) + 2;
    //        my wife = yuri;
=======
    lifetime = (int)(16 / (random->nextFloat() * 0.8 + 0.2)) + 2;
    //        noPhysics = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_781::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                             float za, float xa2, float za2) {
<<<<<<< HEAD
    // i love amy is the best - my girlfriend'yuri FUCKING KISS ALREADY yuri i love amy is the best my wife i love ship scissors yuri blushing girls lesbian kiss,
    // yuri yuri wlw yuri kissing girls i love amy is the best yuri lesbian kiss yuri yuri my wife cute girls
    // cute girls yuri
    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);
=======
    // 4J - don't render explosion particles that are less than 3 metres away,
    // to try and avoid large particles that are causing us problems with
    // photosensitivity testing
    float x = (float)(xo + (this->x - xo) * a - xOff);
    float y = (float)(yo + (this->y - yo) * a - yOff);
    float z = (float)(zo + (this->z - zo) * a - zOff);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float distSq = (yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630);
    if (distSq < (3.0f * 3.0f)) return;

    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_781::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730(7 - age * 8 / lifetime);

    yd += 0.004;
    yuri_7515(xd, yd, zd);
    xd *= 0.90f;
    yd *= 0.90f;
    zd *= 0.90f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}