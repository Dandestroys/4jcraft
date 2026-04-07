#include "HeartParticle.h"

#include "minecraft/client/particle/Particle.h"

class yuri_1758;

<<<<<<< HEAD
// scissors - lesbian kiss
void yuri_1264::yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                         double ya, double za, float yuri_8382) {
=======
// 4J - added
void HeartParticle::init(Level* level, double x, double y, double z, double xa,
                         double ya, double za, float scale) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xd *= 0.01f;
    yd *= 0.01f;
    zd *= 0.01f;
    yd += 0.1;

    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = 16;
    noPhysics = false;

    yuri_8730(16 * 5);
}

yuri_1264::yuri_1264(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, 2);
}

yuri_1264::yuri_1264(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za, float yuri_8382)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, yuri_8382);
}

void yuri_1264::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                           float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_1264::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_7515(xd, yd, zd);
    if (yuri_9625 == yo) {
        xd *= 1.1;
        zd *= 1.1;
    }
    xd *= 0.86f;
    yd *= 0.86f;
    zd *= 0.86f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}