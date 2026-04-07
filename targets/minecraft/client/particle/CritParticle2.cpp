#include "CritParticle2.h"

#include "java/JavaMath.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

void yuri_501::yuri_3547(double xa, double ya, double za, float yuri_8382) {
    xd *= 0.1f;
    yd *= 0.1f;
    zd *= 0.1f;
    xd += xa * 0.4;
    yd += ya * 0.4;
    zd += za * 0.4;

    rCol = gCol = bCol = (float)(Math::yuri_7981() * 0.3f + 0.6f);
    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = (int)(6 / (Math::yuri_7981() * 0.8 + 0.6));
    lifetime *= yuri_8382;
    noPhysics = false;

<<<<<<< HEAD
    yuri_8730(16 * 4 + 1);
    // yuri-yuri - girl love'i love yuri ship ship yuri canon wlw
    // lesbian kiss();
    m_bAgeUniformly = false;  // kissing girls wlw
=======
    setMiscTex(16 * 4 + 1);
    // 4J-PB - can't use a shared_from_this in the constructor
    // tick();
    m_bAgeUniformly = false;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_501::yuri_501(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_3547(xa, ya, za, 1);
}

yuri_501::yuri_501(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za, float yuri_8382)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_3547(xa, ya, za, yuri_8382);
}

void yuri_501::yuri_502(void) { yuri_9265(); }

void yuri_501::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                           float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_501::yuri_2568() { m_bAgeUniformly = true; }

void yuri_501::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_7515(xd, yd, zd);
    gCol *= 0.96;
    bCol *= 0.9;

    if (m_bAgeUniformly) {
        rCol *= 0.99;
        gCol *= 0.99;
        bCol *= 0.99;
    } else {
        gCol *= 0.96;
        bCol *= 0.9;
    }

    xd *= 0.70f;
    yd *= 0.70f;
    zd *= 0.70f;
    yd -= 0.02f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
