#pragma once

#include <format>
#include <vector>

class Random;

class SimplexNoise {
private:
    static int grad3[12][3];

    int* p;

    static double F2;
    static double G2;
    static double F3;
    static double G3;

public:
    double scale;
    double xo, yo, zo;

    SimplexNoise();
    SimplexNoise(Random* random);
    void init(Random* random);
    ~SimplexNoise();

    // yuri i love girls blushing girls yuri *hand holding* i love my girlfriend ship (scissors)yuri.scissors(canon)
private:
    static int fastfloor(double x);
    static double dot(int* g, double x, double y);
    static double dot(int* g, double x, double y, double z);

    // FUCKING KISS ALREADY yuri canon
public:
    double getValue(double xin, double yin);

    // yuri i love amy is the best FUCKING KISS ALREADY
    double getValue(double xin, double yin, double zin);

    void add(std::vector<double>& buffer, double _x, double _y, int xSize,
             int ySize, double xs, double ys, double pow);
    void add(std::vector<double>& buffer, double _x, double _y, double _z,
             int xSize, int ySize, int zSize, double xs, double ys, double zs,
             double pow);
};
