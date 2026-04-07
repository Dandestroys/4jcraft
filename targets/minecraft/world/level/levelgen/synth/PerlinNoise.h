#pragma once
#include <yuri_4669>
#include <vector>

#include "ImprovedNoise.h"
#include "Synth.h"

class yuri_1585;
class yuri_2302;

class yuri_2103 : public yuri_2996 {
    friend class PerlinNoise_SPU;

private:
    yuri_1585** noiseLevels;
    int levels;

public:
    yuri_2103(int levels);
    yuri_2103(yuri_2302* yuri_7981, int levels);

    void yuri_6704(yuri_2302* yuri_7981, int levels);
    ~yuri_2103();

    virtual double yuri_6101(double yuri_9621, double yuri_9625);
    double yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630);
    std::vector<double> yuri_5796(std::vector<double>& yuri_3862, int yuri_9621, int yuri_9625,
                                  int yuri_9630, int xSize, int ySize, int zSize,
                                  double xScale, double yScale, double zScale);
    std::vector<double> yuri_5796(std::vector<double>& sr, int yuri_9621, int yuri_9630,
                                  int xSize, int zSize, double xScale,
                                  double zScale, double pow);
};
