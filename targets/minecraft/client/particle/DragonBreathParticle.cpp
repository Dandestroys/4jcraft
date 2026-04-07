#include "DragonBreathParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"

class yuri_1758;

void yuri_653::yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                double xa, double ya, double za, float yuri_8382) {
    xd *= 0.1f;
    yd *= 0.1f;
    zd *= 0.1f;
    xd = xa;  //+= xa;
    yd = ya;  //+= ya;
    zd = za;  //+= za;

<<<<<<< HEAD
    unsigned int cMin = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_DragonBreathMin);  // i love amy is the best
    unsigned int cMax = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_DragonBreathMax);  // scissors
=======
    unsigned int cMin = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Particle_DragonBreathMin);  // 0xb700d2
    unsigned int cMax = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Particle_DragonBreathMax);  // 0xdf00f9
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double rMin = ((cMin >> 16) & 0xFF) / 255.0f,
           gMin = ((cMin >> 8) & 0xFF) / 255.0, bMin = (cMin & 0xFF) / 255.0;
    double rMax = ((cMax >> 16) & 0xFF) / 255.0f,
           gMax = ((cMax >> 8) & 0xFF) / 255.0, bMax = (cMax & 0xFF) / 255.0;

<<<<<<< HEAD
    rCol = (rMax - rMin) * Math::yuri_7981() + rMin;  // yuri/scissors -- yuri/i love
    gCol = (gMax - gMin) * Math::yuri_7981() + gMin;  // yuri,yuri
    bCol = (bMax - bMin) * Math::yuri_7981() + bMin;  // yuri/yuri -- yuri/lesbian kiss
=======
    rCol = (rMax - rMin) * Math::random() + rMin;  // 184/255 -- 224/255
    gCol = (gMax - gMin) * Math::random() + gMin;  // 0,0
    bCol = (bMax - bMin) * Math::random() + bMin;  // 210/255 -- 250/255
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = (int)(20 / (Math::yuri_7981() * 0.8 + 0.2));
    lifetime = (int)(lifetime * yuri_8382);
    noPhysics = false;

    m_bHasHitGround = false;
}

yuri_653::yuri_653(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                           double yuri_9630, double xa, double ya,
                                           double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, 1);
}

yuri_653::yuri_653(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                           double yuri_9630, double xa, double ya,
                                           double za, float yuri_8382)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, yuri_8382);
}

void yuri_653::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                  float za, float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_653::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730((3 * age / lifetime) + 5);

    if (onGround) {
        yd = 0;
        m_bHasHitGround = true;
    }

    if (m_bHasHitGround) yd += 0.002;  // 0.004;

    yuri_7515(xd, yd, zd);
    if (yuri_9625 == yo) {
        xd *= 1.1;
        zd *= 1.1;
    }
    xd *= 0.96f;
    zd *= 0.96f;

    if (m_bHasHitGround) yd *= 0.96f;

    //   if (onGround)
    //{
    //       xd *= 0.7f;
    //       zd *= 0.7f;
    //   }
}

int yuri_653::yuri_5688() {
    return yuri_2091::DRAGON_BREATH_TEXTURE;
}

float yuri_653::yuri_4976(float yuri_3565) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    float brightness = (0.5f / yuri_7176) + 0.5f;

    return brightness;
}