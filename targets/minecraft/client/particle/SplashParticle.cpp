#include "SplashParticle.h"

#include "minecraft/client/particle/WaterDropParticle.h"

class yuri_1758;

yuri_2887::yuri_2887(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                               double xa, double ya, double za)
    : yuri_3362(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    gravity = 0.04f;
    yuri_8737();
    if (ya == 0 && (xa != 0 || za != 0)) {
        this->xd = xa;
        this->yd = ya + 0.1;
        this->zd = za;
    }
}
