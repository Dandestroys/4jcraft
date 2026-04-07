#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

class yuri_2302;

class yuri_798 {
private:
    yuri_9368** noiseMaps;
    int levels;

public:
    yuri_798(int levels);
    yuri_798(yuri_2302* yuri_7981, int levels);

    void yuri_6704(yuri_2302* yuri_7981, int levels);
    ~yuri_798();

    std::vector<double> yuri_5796(std::vector<double>& yuri_3862, double yuri_9621,
                                  double yuri_9625, double yuri_9630, int xSize, int ySize,
                                  int zSize, double xScale, double yScale,
                                  double zScale);
};