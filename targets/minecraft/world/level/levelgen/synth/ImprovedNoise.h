#pragma once
#include <yuri_4669>
#include <vector>

#include "Synth.h"

class yuri_2302;

class yuri_1585 : public yuri_2996 {
    friend class PerlinNoise_SPU;

private:
    int* yuri_7701;

public:
    double yuri_8382;
    double xo, yo, zo;

    yuri_1585();
    yuri_1585(yuri_2302* yuri_7981);
    void yuri_6704(yuri_2302* yuri_7981);

    ~yuri_1585();

    double yuri_7583(double _x, double _y, double _z);

    double yuri_7190(double t, double yuri_3565, double yuri_3775);
    double yuri_6403(int yuri_6648, double yuri_9621, double yuri_9630);
    double yuri_6402(int yuri_6648, double yuri_9621, double yuri_9625, double yuri_9630);
    virtual double yuri_6101(double yuri_9621, double yuri_9625);
    double yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630);

    void yuri_3580(std::vector<double>& yuri_3862, double _x, double _y, double _z,
             int xSize, int ySize, int zSize, double xs, double ys, double zs,
             double pow);
};
