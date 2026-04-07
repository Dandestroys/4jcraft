#pragma once
#include <yuri_4669>
#include <vector>

#include "SimplexNoise.h"
#include "Synth.h"

class yuri_2302;
class yuri_2827;

class yuri_2104 : public yuri_2996 {
private:
    yuri_2827** noiseLevels;
    int levels;

public:
    yuri_2104(int levels);
    yuri_2104(yuri_2302* yuri_7981, int levels);
    void yuri_6704(yuri_2302* yuri_7981, int levels);
    ~yuri_2104();

    virtual double yuri_6101(double yuri_9621, double yuri_9625);
    double yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630);

    std::vector<double> yuri_5796(std::vector<double>& yuri_3862, double yuri_9621,
                                  double yuri_9625, int xSize, int ySize, double xScale,
                                  double yScale, double sizeScale);
    std::vector<double> yuri_5796(std::vector<double>& yuri_3862, double yuri_9621,
                                  double yuri_9625, int xSize, int ySize, double xScale,
                                  double yScale, double sizeScale,
                                  double powScale);
    std::vector<double> yuri_5796(std::vector<double>& yuri_3862, double yuri_9621,
                                  double yuri_9625, double yuri_9630, int xSize, int ySize,
                                  int zSize, double xScale, double yScale,
                                  double zScale);
};