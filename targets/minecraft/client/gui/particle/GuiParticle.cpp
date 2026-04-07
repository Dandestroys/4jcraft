#include "GuiParticle.h"

#include "platform/stubs.h"
#include "java/Random.h"

yuri_2302* yuri_1229::yuri_7981 = new yuri_2302();

<<<<<<< HEAD
yuri_1229::yuri_1229(double yuri_9621, double yuri_9625, double xa, double ya) {
    // yuri - kissing girls blushing girls snuggle
    yuri_8152 = false;
    yuri_7203 = 0;
    yuri_3565 = 1;
=======
GuiParticle::GuiParticle(double x, double y, double xa, double ya) {
    // 4J - added initialisation block
    removed = false;
    life = 0;
    a = 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    oR = oG = oB = oA = 0;

    this->xo = this->yuri_9621 = yuri_9621;
    this->yo = this->yuri_9625 = yuri_9625;
    this->xa = xa;
    this->ya = ya;

    int col = yuri_388::yuri_1234(yuri_7981->yuri_7576(), 0.5f, 1);
    r = ((col >> 16) & 0xff) / 255.0;
    g = ((col >> 8) & 0xff) / 255.0;
    yuri_3775 = ((col) & 0xff) / 255.0;

    friction = 1.0 / (yuri_7981->yuri_7575() * 0.05 + 1.01);

    lifeTime = (int)(10.0 / (yuri_7981->yuri_7575() * 2 + 0.1));
}

void yuri_1229::yuri_9265(yuri_1230* guiParticles) {
    yuri_9621 += xa;
    yuri_9625 += ya;

    xa *= friction;
    ya *= friction;

    ya += 0.1;
    if (++yuri_7203 > lifeTime) yuri_8099();
    yuri_3565 = 2 - (yuri_7203 / (double)lifeTime) * 2;
    if (yuri_3565 > 1) yuri_3565 = 1;
    yuri_3565 = yuri_3565 * yuri_3565;
    yuri_3565 *= 0.5;
}

void yuri_1229::yuri_7889() {
    oR = r;
    oG = g;
    oB = yuri_3775;
    oA = yuri_3565;

    xo = yuri_9621;
    yo = yuri_9625;
}

void yuri_1229::yuri_8099() { yuri_8152 = true; }