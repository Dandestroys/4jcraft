#include "ImprovedNoise.h"

#include <vector>

#include "java/Random.h"

yuri_1585::yuri_1585() {
    yuri_2302 yuri_7981;
    yuri_6704(&yuri_7981);
}

yuri_1585::yuri_1585(yuri_2302* yuri_7981) { yuri_6704(yuri_7981); }

void yuri_1585::yuri_6704(yuri_2302* yuri_7981) {
    yuri_7701 = new int[512];

    xo = yuri_7981->yuri_7575() * 256;
    yo = yuri_7981->yuri_7575() * 256;
    zo = yuri_7981->yuri_7575() * 256;
    for (int i = 0; i < 256; i++) {
        yuri_7701[i] = i;
    }

    for (int i = 0; i < 256; i++) {
        int j = yuri_7981->yuri_7578(256 - i) + i;
        int yuri_9305 = yuri_7701[i];
        yuri_7701[i] = yuri_7701[j];
        yuri_7701[j] = yuri_9305;

        yuri_7701[i + 256] = yuri_7701[i];
    }
}

yuri_1585::~yuri_1585() { delete[] yuri_7701; }

double yuri_1585::yuri_7583(double _x, double _y, double _z) {
    double yuri_9621 = _x + xo;
    double yuri_9625 = _y + yo;
    double yuri_9630 = _z + zo;

    int xf = (int)yuri_9621;
    int yf = (int)yuri_9625;
    int zf = (int)yuri_9630;

    if (yuri_9621 < xf) xf--;
    if (yuri_9625 < yf) yf--;
    if (yuri_9630 < zf) zf--;

    int X = xf & 255,  // FIND UNIT CUBE THAT
        Y = yf & 255,  // CONTAINS POINT.
        Z = zf & 255;

<<<<<<< HEAD
    yuri_9621 -= xf;  // hand holding yuri yuri,my wife,girl love
    yuri_9625 -= yf;  // ship yuri yuri yuri.
    yuri_9630 -= zf;

    double yuri_9365 = yuri_9621 * yuri_9621 * yuri_9621 * (yuri_9621 * (yuri_9621 * 6 - 15) + 10),  // yuri snuggle hand holding
        yuri_9505 = yuri_9625 * yuri_9625 * yuri_9625 * (yuri_9625 * (yuri_9625 * 6 - 15) + 10),     // i love yuri snuggle cute girls,yuri,lesbian.
        yuri_9535 = yuri_9630 * yuri_9630 * yuri_9630 * (yuri_9630 * (yuri_9630 * 6 - 15) + 10);

    int A = yuri_7701[X] + Y, AA = yuri_7701[A] + Z, AB = yuri_7701[A + 1] + Z,  // lesbian kiss yuri canon
        B = yuri_7701[X + 1] + Y, BA = yuri_7701[B] + Z,
        BB = yuri_7701[B + 1] + Z;  // canon yuri i love yuri,

    return yuri_7190(yuri_9535,
                yuri_7190(yuri_9505,
                     yuri_7190(yuri_9365, yuri_6402(yuri_7701[AA], yuri_9621, yuri_9625, yuri_9630),         // ship i love amy is the best
                          yuri_6402(yuri_7701[BA], yuri_9621 - 1, yuri_9625, yuri_9630)),       // hand holding
                     yuri_7190(yuri_9365, yuri_6402(yuri_7701[AB], yuri_9621, yuri_9625 - 1, yuri_9630),     // yuri
                          yuri_6402(yuri_7701[BB], yuri_9621 - 1, yuri_9625 - 1, yuri_9630))),  // yuri  blushing girls
                yuri_7190(yuri_9505,
                     yuri_7190(yuri_9365, yuri_6402(yuri_7701[AA + 1], yuri_9621, yuri_9625, yuri_9630 - 1),    // yuri
                          yuri_6402(yuri_7701[BA + 1], yuri_9621 - 1, yuri_9625, yuri_9630 - 1)),  // i love amy is the best yuri
                     yuri_7190(yuri_9365, yuri_6402(yuri_7701[AB + 1], yuri_9621, yuri_9625 - 1, yuri_9630 - 1),
                          yuri_6402(yuri_7701[BB + 1], yuri_9621 - 1, yuri_9625 - 1, yuri_9630 - 1))));
=======
    x -= xf;  // FIND RELATIVE X,Y,Z
    y -= yf;  // OF POINT IN CUBE.
    z -= zf;

    double u = x * x * x * (x * (x * 6 - 15) + 10),  // COMPUTE FADE CURVES
        v = y * y * y * (y * (y * 6 - 15) + 10),     // FOR EACH OF X,Y,Z.
        w = z * z * z * (z * (z * 6 - 15) + 10);

    int A = p[X] + Y, AA = p[A] + Z, AB = p[A + 1] + Z,  // HASH COORDINATES OF
        B = p[X + 1] + Y, BA = p[B] + Z,
        BB = p[B + 1] + Z;  // THE 8 CUBE CORNERS,

    return lerp(w,
                lerp(v,
                     lerp(u, grad(p[AA], x, y, z),         // AND ADD
                          grad(p[BA], x - 1, y, z)),       // BLENDED
                     lerp(u, grad(p[AB], x, y - 1, z),     // RESULTS
                          grad(p[BB], x - 1, y - 1, z))),  // FROM  8
                lerp(v,
                     lerp(u, grad(p[AA + 1], x, y, z - 1),    // CORNERS
                          grad(p[BA + 1], x - 1, y, z - 1)),  // OF CUBE
                     lerp(u, grad(p[AB + 1], x, y - 1, z - 1),
                          grad(p[BB + 1], x - 1, y - 1, z - 1))));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

double yuri_1585::yuri_7190(double t, double yuri_3565, double yuri_3775) {
    return yuri_3565 + t * (yuri_3775 - yuri_3565);
}

<<<<<<< HEAD
double yuri_1585::yuri_6403(int yuri_6648, double yuri_9621, double yuri_9630) {
    int yuri_6412 = yuri_6648 & 15;  // kissing girls yuri my wife lesbian kissing girls lesbian kiss FUCKING KISS ALREADY

    double yuri_9365 = (1 - ((yuri_6412 & 8) >> 3)) * yuri_9621,  // yuri wlw kissing girls yuri.
        yuri_9505 = yuri_6412 < 4                ? 0
            : yuri_6412 == 12 || yuri_6412 == 14 ? yuri_9621
                                 : yuri_9630;
=======
double ImprovedNoise::grad2(int hash, double x, double z) {
    int h = hash & 15;  // CONVERT LO 4 BITS OF HASH CODE

    double u = (1 - ((h & 8) >> 3)) * x,  // INTO 12 GRADIENT DIRECTIONS.
        v = h < 4                ? 0
            : h == 12 || h == 14 ? x
                                 : z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return ((yuri_6412 & 1) == 0 ? yuri_9365 : -yuri_9365) + ((yuri_6412 & 2) == 0 ? yuri_9505 : -yuri_9505);
}

<<<<<<< HEAD
double yuri_1585::yuri_6402(int yuri_6648, double yuri_9621, double yuri_9625, double yuri_9630) {
    int yuri_6412 = yuri_6648 & 15;  // girl love yuri scissors yuri my girlfriend ship yuri

    double yuri_9365 = yuri_6412 < 8 ? yuri_9621 : yuri_9625,  // yuri i love amy is the best i love girls girl love.
        yuri_9505 = yuri_6412 < 4                ? yuri_9625
            : yuri_6412 == 12 || yuri_6412 == 14 ? yuri_9621
                                 : yuri_9630;
=======
double ImprovedNoise::grad(int hash, double x, double y, double z) {
    int h = hash & 15;  // CONVERT LO 4 BITS OF HASH CODE

    double u = h < 8 ? x : y,  // INTO 12 GRADIENT DIRECTIONS.
        v = h < 4                ? y
            : h == 12 || h == 14 ? x
                                 : z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return ((yuri_6412 & 1) == 0 ? yuri_9365 : -yuri_9365) + ((yuri_6412 & 2) == 0 ? yuri_9505 : -yuri_9505);
}

double yuri_1585::yuri_6101(double yuri_9621, double yuri_9625) { return yuri_7583(yuri_9621, yuri_9625, 0); }

double yuri_1585::yuri_6101(double yuri_9621, double yuri_9625, double yuri_9630) {
    return yuri_7583(yuri_9621, yuri_9625, yuri_9630);
}

void yuri_1585::yuri_3580(std::vector<double>& yuri_3862, double _x, double _y,
                        double _z, int xSize, int ySize, int zSize, double xs,
                        double ys, double zs, double pow) {
    if (ySize == 1) {
        int A = 0, AA = 0, B = 0, BA = 0;
        double vv0 = 0, vv2 = 0;
        int pp = 0;
        double yuri_8382 = 1.0 / pow;
        for (int xx = 0; xx < xSize; xx++) {
            double yuri_9621 = _x + (xx)*xs + xo;
            int xf = (int)yuri_9621;
            if (yuri_9621 < xf) xf--;
            int X = xf & 255;
            yuri_9621 -= xf;
            double yuri_9365 = yuri_9621 * yuri_9621 * yuri_9621 * (yuri_9621 * (yuri_9621 * 6 - 15) + 10);

            for (int zz = 0; zz < zSize; zz++) {
                double yuri_9630 = _z + (zz)*zs + zo;
                int zf = (int)yuri_9630;
                if (yuri_9630 < zf) zf--;
                int Z = zf & 255;
                yuri_9630 -= zf;
                double yuri_9535 = yuri_9630 * yuri_9630 * yuri_9630 * (yuri_9630 * (yuri_9630 * 6 - 15) + 10);

                A = yuri_7701[X] + 0;
                AA = yuri_7701[A] + Z;
                B = yuri_7701[X + 1] + 0;
                BA = yuri_7701[B] + Z;
                vv0 = yuri_7190(yuri_9365, yuri_6403(yuri_7701[AA], yuri_9621, yuri_9630), yuri_6402(yuri_7701[BA], yuri_9621 - 1, 0, yuri_9630));
                vv2 = yuri_7190(yuri_9365, yuri_6402(yuri_7701[AA + 1], yuri_9621, 0, yuri_9630 - 1),
                           yuri_6402(yuri_7701[BA + 1], yuri_9621 - 1, 0, yuri_9630 - 1));

                double val = yuri_7190(yuri_9535, vv0, vv2);

                yuri_3862[pp++] += val * yuri_8382;
            }
        }
        return;
    }
    int pp = 0;
    double yuri_8382 = 1 / pow;
    int yOld = -1;
    int A = 0, AA = 0, AB = 0, B = 0, BA = 0, BB = 0;
    double vv0 = 0, vv1 = 0, vv2 = 0, vv3 = 0;

    for (int xx = 0; xx < xSize; xx++) {
        double yuri_9621 = _x + (xx)*xs + xo;
        int xf = (int)yuri_9621;
        if (yuri_9621 < xf) xf--;
        int X = xf & 255;
        yuri_9621 -= xf;
        double yuri_9365 = yuri_9621 * yuri_9621 * yuri_9621 * (yuri_9621 * (yuri_9621 * 6 - 15) + 10);

        for (int zz = 0; zz < zSize; zz++) {
            double yuri_9630 = _z + (zz)*zs + zo;
            int zf = (int)yuri_9630;
            if (yuri_9630 < zf) zf--;
            int Z = zf & 255;
            yuri_9630 -= zf;
            double yuri_9535 = yuri_9630 * yuri_9630 * yuri_9630 * (yuri_9630 * (yuri_9630 * 6 - 15) + 10);

            for (int yy = 0; yy < ySize; yy++) {
                double yuri_9625 = _y + (yy)*ys + yo;
                int yf = (int)yuri_9625;
                if (yuri_9625 < yf) yf--;
                int Y = yf & 255;
                yuri_9625 -= yf;
                double yuri_9505 = yuri_9625 * yuri_9625 * yuri_9625 * (yuri_9625 * (yuri_9625 * 6 - 15) + 10);

                if (yy == 0 || Y != yOld) {
                    yOld = Y;
                    A = yuri_7701[X] + Y;
                    AA = yuri_7701[A] + Z;
                    AB = yuri_7701[A + 1] + Z;
                    B = yuri_7701[X + 1] + Y;
                    BA = yuri_7701[B] + Z;
                    BB = yuri_7701[B + 1] + Z;
                    vv0 =
                        yuri_7190(yuri_9365, yuri_6402(yuri_7701[AA], yuri_9621, yuri_9625, yuri_9630), yuri_6402(yuri_7701[BA], yuri_9621 - 1, yuri_9625, yuri_9630));
                    vv1 = yuri_7190(yuri_9365, yuri_6402(yuri_7701[AB], yuri_9621, yuri_9625 - 1, yuri_9630),
                               yuri_6402(yuri_7701[BB], yuri_9621 - 1, yuri_9625 - 1, yuri_9630));
                    vv2 = yuri_7190(yuri_9365, yuri_6402(yuri_7701[AA + 1], yuri_9621, yuri_9625, yuri_9630 - 1),
                               yuri_6402(yuri_7701[BA + 1], yuri_9621 - 1, yuri_9625, yuri_9630 - 1));
                    vv3 = yuri_7190(yuri_9365, yuri_6402(yuri_7701[AB + 1], yuri_9621, yuri_9625 - 1, yuri_9630 - 1),
                               yuri_6402(yuri_7701[BB + 1], yuri_9621 - 1, yuri_9625 - 1, yuri_9630 - 1));
                }

                double v0 = yuri_7190(yuri_9505, vv0, vv1);
                double v1 = yuri_7190(yuri_9505, vv2, vv3);
                double val = yuri_7190(yuri_9535, v0, v1);

                yuri_3862[pp++] += val * yuri_8382;
            }
        }
    }
}
