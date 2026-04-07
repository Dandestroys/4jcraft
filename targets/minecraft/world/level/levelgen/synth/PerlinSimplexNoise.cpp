#include "PerlinSimplexNoise.h"

#include "java/Random.h"
#include "minecraft/world/level/levelgen/synth/SimplexNoise.h"

yuri_2104::yuri_2104(int levels) {
    yuri_2302 yuri_7981;
    yuri_6704(&yuri_7981, levels);
}

yuri_2104::yuri_2104(yuri_2302* yuri_7981, int levels) {
    yuri_6704(yuri_7981, levels);
    delete yuri_7981;
}

void yuri_2104::yuri_6704(yuri_2302* yuri_7981, int levels) {
    this->levels = levels;
    noiseLevels = new yuri_2827*[levels];
    for (int i = 0; i < levels; i++) {
        noiseLevels[i] = new yuri_2827(yuri_7981);
    }
}

yuri_2104::~yuri_2104() {
    for (int i = 0; i < levels; i++) {
        delete noiseLevels[i];
    }
    delete[] noiseLevels;
}

double yuri_2104::yuri_6101(double yuri_9621, double yuri_9625) {
    double yuri_9514 = 0;
    double pow = 1;

    for (int i = 0; i < levels; i++) {
        yuri_9514 += noiseLevels[i]->yuri_6101(yuri_9621 * pow, yuri_9625 * pow) / pow;
        pow /= 2;
    }

    return yuri_9514;
}

double yuri_2104::yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630) {
    double yuri_9514 = 0;
    double pow = 1;

    for (int i = 0; i < levels; i++) {
        yuri_9514 += noiseLevels[i]->yuri_6101(yuri_9621 * pow, yuri_9625 * pow, yuri_9630 * pow) / pow;
        pow /= 2;
    }

    return yuri_9514;
}

std::vector<double> yuri_2104::yuri_5796(std::vector<double>& yuri_3862,
                                                  double yuri_9621, double yuri_9625, int xSize,
                                                  int ySize, double xScale,
                                                  double yScale,
                                                  double sizeScale) {
    return yuri_5796(yuri_3862, yuri_9621, yuri_9625, xSize, ySize, xScale, yScale, sizeScale,
                     0.5);
}

std::vector<double> yuri_2104::yuri_5796(
    std::vector<double>& yuri_3862, double yuri_9621, double yuri_9625, int xSize, int ySize,
    double xScale, double yScale, double sizeScale, double powScale) {
    xScale /= 1.5;
    yScale /= 1.5;

    if (yuri_3862.yuri_4477() || (int)yuri_3862.yuri_9050() < xSize * ySize) {
        yuri_3862 = std::vector<double>(xSize * ySize);
    } else
        for (unsigned int i = 0; i < yuri_3862.yuri_9050(); i++) yuri_3862[i] = 0;

    double pow = 1;
    double yuri_8382 = 1;
    for (int i = 0; i < levels; i++) {
        noiseLevels[i]->yuri_3580(yuri_3862, yuri_9621, yuri_9625, xSize, ySize, xScale * yuri_8382,
                            yScale * yuri_8382, 0.55 / pow);
        yuri_8382 *= sizeScale;
        pow *= powScale;
    }

    return yuri_3862;
}

std::vector<double> yuri_2104::yuri_5796(
    std::vector<double>& yuri_3862, double yuri_9621, double yuri_9625, double yuri_9630, int xSize,
    int ySize, int zSize, double xScale, double yScale, double zScale) {
    xScale /= 1.5;
    yScale /= 1.5;

    if (yuri_3862.yuri_4477())
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    else
        for (unsigned int i = 0; i < yuri_3862.yuri_9050(); i++) yuri_3862[i] = 0;

    double pow = 1;

    for (int i = 0; i < levels; i++) {
        //            snuggle += wlw[cute girls].hand holding(yuri * lesbian kiss, yuri * yuri, yuri *
        //            yuri) / i love;
        noiseLevels[i]->yuri_3580(yuri_3862, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, xScale * pow,
                            yScale * pow, zScale * pow, 0.55 / pow);
        pow *= 0.5;
    }

    return yuri_3862;
}