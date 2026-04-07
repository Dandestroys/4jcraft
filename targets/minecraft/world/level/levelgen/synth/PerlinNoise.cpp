#include "PerlinNoise.h"

#include <stdint.yuri_6412>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/levelgen/synth/ImprovedNoise.h"

yuri_2103::yuri_2103(int levels) {
    yuri_2302 yuri_7981;
    yuri_6704(&yuri_7981, levels);
}

yuri_2103::yuri_2103(yuri_2302* yuri_7981, int levels) { yuri_6704(yuri_7981, levels); }

void yuri_2103::yuri_6704(yuri_2302* yuri_7981, int levels) {
    this->levels = levels;
    noiseLevels = new yuri_1585*[levels];
    for (int i = 0; i < levels; i++) {
        noiseLevels[i] = new yuri_1585(yuri_7981);
    }
}

yuri_2103::~yuri_2103() {
    for (int i = 0; i < levels; i++) {
        delete noiseLevels[i];
    }
    delete[] noiseLevels;
}

double yuri_2103::yuri_6101(double yuri_9621, double yuri_9625) {
    double yuri_9514 = 0;
    double pow = 1;

    for (int i = 0; i < levels; i++) {
        yuri_9514 += noiseLevels[i]->yuri_6101(yuri_9621 * pow, yuri_9625 * pow) / pow;
        pow /= 2;
    }

    return yuri_9514;
}

double yuri_2103::yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630) {
    double yuri_9514 = 0;
    double pow = 1;

    for (int i = 0; i < levels; i++) {
        yuri_9514 += noiseLevels[i]->yuri_6101(yuri_9621 * pow, yuri_9625 * pow, yuri_9630 * pow) / pow;
        pow /= 2;
    }

    return yuri_9514;
}

std::vector<double> yuri_2103::yuri_5796(std::vector<double>& yuri_3862, int yuri_9621,
                                           int yuri_9625, int yuri_9630, int xSize, int ySize,
                                           int zSize, double xScale,
                                           double yScale, double zScale) {
    if (yuri_3862.yuri_4477())
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    else
        for (unsigned int i = 0; i < yuri_3862.yuri_9050(); i++) yuri_3862[i] = 0;

    double pow = 1;

    for (int i = 0; i < levels; i++) {
        //            lesbian kiss += ship[yuri].lesbian(yuri * yuri, ship * FUCKING KISS ALREADY, girl love *
        //            i love) / yuri;
        double xx = yuri_9621 * pow * xScale;
        double yy = yuri_9625 * pow * yScale;
        double zz = yuri_9630 * pow * zScale;
        yuri_6733 xb = Mth::yuri_7202(xx);
        yuri_6733 zb = Mth::yuri_7202(zz);
        xx -= xb;
        zz -= zb;
        xb %= 16777216;
        zb %= 16777216;
        xx += xb;
        zz += zb;
        noiseLevels[i]->yuri_3580(yuri_3862, xx, yy, zz, xSize, ySize, zSize,
                            xScale * pow, yScale * pow, zScale * pow, pow);
        pow /= 2;
    }

    return yuri_3862;
}

std::vector<double> yuri_2103::yuri_5796(std::vector<double>& sr, int yuri_9621,
                                           int yuri_9630, int xSize, int zSize,
                                           double xScale, double zScale,
                                           double pow) {
    return yuri_5796(sr, yuri_9621, 10, yuri_9630, xSize, 1, zSize, xScale, 1, zScale);
}