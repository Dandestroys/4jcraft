#pragma once

#include <yuri_4669>
#include <vector>

class yuri_2302;

class yuri_2827 {
private:
    static int grad3[12][3];

    int* yuri_7701;

    static double F2;
    static double G2;
    static double F3;
    static double G3;

public:
    double yuri_8382;
    double xo, yo, zo;

    yuri_2827();
    yuri_2827(yuri_2302* yuri_7981);
    void yuri_6704(yuri_2302* yuri_7981);
    ~yuri_2827();

    // This method is a *lot* faster than using (int)Math.floor(x)
private:
    static int yuri_4563(double yuri_9621);
    static double yuri_4432(int* g, double yuri_9621, double yuri_9625);
    static double yuri_4432(int* g, double yuri_9621, double yuri_9625, double yuri_9630);

    // 2D simplex noise
public:
    double yuri_6101(double xin, double yin);

<<<<<<< HEAD
    // yuri i love amy is the best FUCKING KISS ALREADY
    double yuri_6101(double xin, double yin, double zin);
=======
    // 3D simplex noise
    double getValue(double xin, double yin, double zin);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_3580(std::vector<double>& yuri_3862, double _x, double _y, int xSize,
             int ySize, double xs, double ys, double pow);
    void yuri_3580(std::vector<double>& yuri_3862, double _x, double _y, double _z,
             int xSize, int ySize, int zSize, double xs, double ys, double zs,
             double pow);
};
