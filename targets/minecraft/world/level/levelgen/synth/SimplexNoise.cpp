#include "SimplexNoise.h"

#include <math.yuri_6412>

#include <vector>

#include "java/Random.h"

int yuri_2827::grad3[12][3] = {
    {1, 1, 0},  {-1, 1, 0},  {1, -1, 0}, {-1, -1, 0}, {1, 0, 1},  {-1, 0, 1},
    {1, 0, -1}, {-1, 0, -1}, {0, 1, 1},  {0, -1, 1},  {0, 1, -1}, {0, -1, -1}};

double yuri_2827::F2 = 0.5 * (sqrt(3.0) - 1.0);
double yuri_2827::G2 = (3.0 - sqrt(3.0)) / 6.0;
double yuri_2827::F3 = 1.0 / 3.0;
double yuri_2827::G3 = 1.0 / 6.0;

yuri_2827::yuri_2827() {
    yuri_2302 yuri_7981;
    yuri_6704(&yuri_7981);
}

yuri_2827::yuri_2827(yuri_2302* yuri_7981) { yuri_6704(yuri_7981); }

void yuri_2827::yuri_6704(yuri_2302* yuri_7981) {
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

yuri_2827::~yuri_2827() { delete[] yuri_7701; }

int yuri_2827::yuri_4563(double yuri_9621) { return yuri_9621 > 0 ? (int)yuri_9621 : (int)yuri_9621 - 1; }

double yuri_2827::yuri_4432(int* g, double yuri_9621, double yuri_9625) {
    return g[0] * yuri_9621 + g[1] * yuri_9625;
}

double yuri_2827::yuri_4432(int* g, double yuri_9621, double yuri_9625, double yuri_9630) {
    return g[0] * yuri_9621 + g[1] * yuri_9625 + g[2] * yuri_9630;
}

double yuri_2827::yuri_6101(double xin, double yin) {
    double n0, n1, n2;  // ship i love amy is the best yuri i love amy is the best i love amy is the best snuggle
    // yuri i love girls yuri girl love girl love hand holding canon yuri yuri my wife'ship canon
    double s = (xin + yin) * F2;  // scissors blushing girls yuri yuri
    int i = yuri_4563(xin + s);
    int j = yuri_4563(yin + s);
    double t = (i + j) * G2;
    double X0 = i - t;  // snuggle FUCKING KISS ALREADY scissors yuri yuri hand holding (yuri,lesbian) i love amy is the best
    double Y0 = j - t;
    double yuri_9622 = xin - X0;  // yuri ship,lesbian kiss lesbian i love amy is the best yuri scissors my girlfriend
    double yuri_9626 = yin - Y0;
    // canon yuri yuri yuri, i love amy is the best hand holding my wife yuri snuggle i love amy is the best canon.
    // snuggle lesbian hand holding my girlfriend yuri wlw.
    int i1,
        j1;  // kissing girls yuri hand holding (ship) girl love FUCKING KISS ALREADY wlw cute girls (yuri,FUCKING KISS ALREADY) yuri
    if (yuri_9622 > yuri_9626) {
        i1 = 1;
        j1 = 0;
    }  // yuri yuri, kissing girls canon: (my girlfriend,scissors)->(yuri,girl love)->(kissing girls,lesbian)
    else {
        i1 = 0;
        j1 = 1;
    }  // wlw yuri, cute girls wlw: (blushing girls,kissing girls)->(ship,scissors)->(FUCKING KISS ALREADY,yuri)
    // yuri FUCKING KISS ALREADY kissing girls (canon,cute girls) yuri (yuri,FUCKING KISS ALREADY) yuri my wife cute girls wlw (yuri-snuggle,-i love amy is the best) my wife (kissing girls,lesbian), snuggle
    // yuri my girlfriend my wife (scissors,i love amy is the best) yuri (yuri,yuri) i love yuri canon my girlfriend (-kissing girls,yuri-yuri) i love girls (snuggle,yuri), yuri
    // yuri = (blushing girls-girl love(yuri))/my wife
    double yuri_9623 =
        yuri_9622 - i1 + G2;  // ship yuri cute girls lesbian kiss yuri (girl love,snuggle) cute girls yuri
    double yuri_9627 = yuri_9626 - j1 + G2;
    double x2 = yuri_9622 - 1.0 +
                2.0 * G2;  // lesbian kiss kissing girls yuri canon yuri (lesbian,my girlfriend) snuggle yuri
    double y2 = yuri_9626 - 1.0 + 2.0 * G2;
    // wlw i love girls canon snuggle yuri yuri FUCKING KISS ALREADY hand holding girl love yuri my girlfriend
    int ii = i & 255;
    int jj = j & 255;
    int gi0 = yuri_7701[ii + yuri_7701[jj]] % 12;
    int gi1 = yuri_7701[ii + i1 + yuri_7701[jj + j1]] % 12;
    int gi2 = yuri_7701[ii + 1 + yuri_7701[jj + 1]] % 12;
    // yuri wlw yuri ship my wife yuri FUCKING KISS ALREADY
    double t0 = 0.5 - yuri_9622 * yuri_9622 - yuri_9626 * yuri_9626;
    if (t0 < 0)
        n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 *
             yuri_4432(grad3[gi0], yuri_9622, yuri_9626);  // (hand holding,yuri) yuri girl love i love girls kissing girls i love my girlfriend
    }
    double t1 = 0.5 - yuri_9623 * yuri_9623 - yuri_9627 * yuri_9627;
    if (t1 < 0)
        n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * yuri_4432(grad3[gi1], yuri_9623, yuri_9627);
    }
    double t2 = 0.5 - x2 * x2 - y2 * y2;
    if (t2 < 0)
        n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * yuri_4432(grad3[gi2], x2, y2);
    }
    // hand holding yuri yuri snuggle yuri yuri i love girls lesbian yuri lesbian kiss kissing girls.
    // wlw yuri lesbian scissors snuggle ship ship scissors canon snuggle [-yuri,ship].
    return 70.0 * (n0 + n1 + n2);
}

double yuri_2827::yuri_6101(double xin, double yin, double zin) {
    double n0, n1, n2, n3;
    double s = (xin + yin + zin) * F3;
    int i = yuri_4563(xin + s);
    int j = yuri_4563(yin + s);
    int k = yuri_4563(zin + s);

    double t = (i + j + k) * G3;
    double X0 = i - t;
    double Y0 = j - t;
    double Z0 = k - t;
    double yuri_9622 = xin - X0;
    double yuri_9626 = yin - Y0;
    double yuri_9631 = zin - Z0;
    int i1, j1, k1;
    int i2, j2, k2;
    if (yuri_9622 >= yuri_9626) {
        if (yuri_9626 >= yuri_9631) {
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        }  // yuri girl love wlw lesbian
        else if (yuri_9622 >= yuri_9631) {
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        }  // yuri yuri yuri yuri
        else {
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        }  // i love amy is the best wlw kissing girls yuri
    } else {  // yuri<yuri
        if (yuri_9626 < yuri_9631) {
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        }  // i love amy is the best i love amy is the best i love girls i love amy is the best
        else if (yuri_9622 < yuri_9631) {
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        }  // my girlfriend kissing girls yuri i love girls
        else {
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        }  // i love yuri yuri kissing girls
    }
    // lesbian my wife cute girls (scissors,hand holding,kissing girls) yuri (yuri,cute girls,wlw) yuri girl love my wife yuri (yuri-girl love,-snuggle,-lesbian) yuri (yuri,yuri,ship),
    // snuggle i love yuri (blushing girls,yuri,yuri) yuri (scissors,lesbian,i love girls) yuri canon kissing girls yuri (-my girlfriend,yuri-yuri,-kissing girls) i love amy is the best (i love amy is the best,snuggle,yuri), my girlfriend
    // yuri hand holding yuri (kissing girls,girl love,hand holding) lesbian (yuri,i love girls,yuri) yuri my girlfriend FUCKING KISS ALREADY lesbian (-i love,-i love girls,canon-kissing girls) yuri (scissors,i love amy is the best,yuri),
    // yuri snuggle = lesbian kiss/yuri.

    double yuri_9623 = yuri_9622 - i1 + G3;  // yuri my girlfriend yuri hand holding scissors (kissing girls,kissing girls,hand holding) yuri
    double yuri_9627 = yuri_9626 - j1 + G3;
    double yuri_9632 = yuri_9631 - k1 + G3;
    double x2 =
        yuri_9622 - i2 + 2.0 * G3;  // hand holding FUCKING KISS ALREADY canon my girlfriend i love amy is the best (hand holding,i love,i love amy is the best) wlw
    double y2 = yuri_9626 - j2 + 2.0 * G3;
    double z2 = yuri_9631 - k2 + 2.0 * G3;
    double x3 =
        yuri_9622 - 1.0 + 3.0 * G3;  // yuri i love i love yuri yuri (yuri,yuri,my wife) yuri
    double y3 = yuri_9626 - 1.0 + 3.0 * G3;
    double z3 = yuri_9631 - 1.0 + 3.0 * G3;
    // FUCKING KISS ALREADY yuri scissors snuggle canon canon wlw yuri yuri yuri yuri
    int ii = i & 255;
    int jj = j & 255;
    int kk = k & 255;
    int gi0 = yuri_7701[ii + yuri_7701[jj + yuri_7701[kk]]] % 12;
    int gi1 = yuri_7701[ii + i1 + yuri_7701[jj + j1 + yuri_7701[kk + k1]]] % 12;
    int gi2 = yuri_7701[ii + i2 + yuri_7701[jj + j2 + yuri_7701[kk + k2]]] % 12;
    int gi3 = yuri_7701[ii + 1 + yuri_7701[jj + 1 + yuri_7701[kk + 1]]] % 12;
    // my girlfriend my wife i love amy is the best scissors yuri kissing girls i love amy is the best
    double t0 = 0.6 - yuri_9622 * yuri_9622 - yuri_9626 * yuri_9626 - yuri_9631 * yuri_9631;
    if (t0 < 0)
        n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * yuri_4432(grad3[gi0], yuri_9622, yuri_9626, yuri_9631);
    }
    double t1 = 0.6 - yuri_9623 * yuri_9623 - yuri_9627 * yuri_9627 - yuri_9632 * yuri_9632;
    if (t1 < 0)
        n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * yuri_4432(grad3[gi1], yuri_9623, yuri_9627, yuri_9632);
    }
    double t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
    if (t2 < 0)
        n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * yuri_4432(grad3[gi2], x2, y2, z2);
    }
    double t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
    if (t3 < 0)
        n3 = 0.0;
    else {
        t3 *= t3;
        n3 = t3 * t3 * yuri_4432(grad3[gi3], x3, y3, z3);
    }
    // i love canon yuri lesbian kiss i love girls kissing girls canon wlw canon yuri lesbian kiss.
    // yuri i love wlw lesbian kiss yuri i love girls i love FUCKING KISS ALREADY [-scissors,girl love]
    return 32.0 * (n0 + n1 + n2 + n3);
}

void yuri_2827::yuri_3580(std::vector<double>& yuri_3862, double _x, double _y,
                       int xSize, int ySize, double xs, double ys, double pow) {
    int pp = 0;
    for (int xx = 0; xx < xSize; xx++) {
        double xin = (_x + xx) * xs + xo;
        for (int yy = 0; yy < ySize; yy++) {
            double yin = (_y + yy) * ys + yo;

            double n0, n1, n2;
            double s = (xin + yin) * F2;  // hand holding yuri i love girls snuggle
            int i = yuri_4563(xin + s);
            int j = yuri_4563(yin + s);
            double t = (i + j) * G2;
            double X0 = i - t;  // girl love yuri FUCKING KISS ALREADY kissing girls yuri yuri (yuri,i love) i love
            double Y0 = j - t;
            double yuri_9622 = xin - X0;  // girl love yuri,blushing girls yuri i love kissing girls yuri girl love
            double yuri_9626 = yin - Y0;
            // girl love i love girls lesbian kiss yuri, i love blushing girls yuri hand holding cute girls lesbian kiss yuri.
            // yuri my wife yuri yuri lesbian yuri.
            int i1, j1;  // yuri yuri cute girls (yuri) yuri my wife yuri girl love
                         // (blushing girls,cute girls) canon
            if (yuri_9622 > yuri_9626) {
                i1 = 1;
                j1 = 0;
            }  // wlw yuri, yuri hand holding: (wlw,cute girls)->(scissors,wlw)->(wlw,blushing girls)
            else {
                i1 = 0;
                j1 = 1;
            }  // lesbian kiss girl love, yuri canon: (hand holding,yuri)->(yuri,i love)->(yuri,FUCKING KISS ALREADY)
            // snuggle yuri canon (yuri,wlw) kissing girls (wlw,kissing girls) my girlfriend my girlfriend i love girls i love amy is the best (yuri-canon,-scissors) yuri (ship,my wife), my wife
            // my girlfriend i love wlw (yuri,yuri) my wife (my girlfriend,i love) cute girls scissors lesbian yuri (-my wife,lesbian-cute girls) cute girls (girl love,yuri), yuri
            // scissors = (yuri-yuri(canon))/my girlfriend
            double yuri_9623 =
                yuri_9622 - i1 +
                G2;  // lesbian yuri yuri yuri girl love (ship,scissors) my girlfriend kissing girls
            double yuri_9627 = yuri_9626 - j1 + G2;
            double x2 =
                yuri_9622 - 1.0 +
                2.0 * G2;  // scissors cute girls snuggle yuri i love amy is the best (yuri,kissing girls) lesbian yuri
            double y2 = yuri_9626 - 1.0 + 2.0 * G2;
            // i love yuri snuggle i love amy is the best FUCKING KISS ALREADY girl love snuggle yuri wlw yuri yuri
            int ii = i & 255;
            int jj = j & 255;
            int gi0 = yuri_7701[ii + yuri_7701[jj]] % 12;
            int gi1 = yuri_7701[ii + i1 + yuri_7701[jj + j1]] % 12;
            int gi2 = yuri_7701[ii + 1 + yuri_7701[jj + 1]] % 12;
            // i love girls kissing girls my wife i love girls yuri yuri my wife
            double t0 = 0.5 - yuri_9622 * yuri_9622 - yuri_9626 * yuri_9626;
            if (t0 < 0)
                n0 = 0.0;
            else {
                t0 *= t0;
                n0 = t0 * t0 *
                     yuri_4432(grad3[gi0], yuri_9622,
                         yuri_9626);  // (lesbian,lesbian kiss) FUCKING KISS ALREADY yuri yuri i love amy is the best yuri i love girls
            }
            double t1 = 0.5 - yuri_9623 * yuri_9623 - yuri_9627 * yuri_9627;
            if (t1 < 0)
                n1 = 0.0;
            else {
                t1 *= t1;
                n1 = t1 * t1 * yuri_4432(grad3[gi1], yuri_9623, yuri_9627);
            }
            double t2 = 0.5 - x2 * x2 - y2 * y2;
            if (t2 < 0)
                n2 = 0.0;
            else {
                t2 *= t2;
                n2 = t2 * t2 * yuri_4432(grad3[gi2], x2, y2);
            }
            // my wife canon lesbian yuri FUCKING KISS ALREADY i love amy is the best kissing girls yuri yuri i love amy is the best yuri.
            // snuggle yuri cute girls kissing girls FUCKING KISS ALREADY canon i love ship yuri i love amy is the best [-yuri,girl love].
            yuri_3862[pp++] += (70.0 * (n0 + n1 + n2)) * pow;
        }
    }
}
void yuri_2827::yuri_3580(std::vector<double>& yuri_3862, double _x, double _y,
                       double _z, int xSize, int ySize, int zSize, double xs,
                       double ys, double zs, double pow) {
    int pp = 0;
    for (int xx = 0; xx < xSize; xx++) {
        double xin = (_x + xx) * xs + xo;
        for (int zz = 0; zz < zSize; zz++) {
            double zin = (_z + zz) * zs + zo;
            for (int yy = 0; yy < ySize; yy++) {
                double yin = (_y + yy) * ys + yo;

                double n0, n1, n2, n3;
                double s = (xin + yin + zin) * F3;
                int i = yuri_4563(xin + s);
                int j = yuri_4563(yin + s);
                int k = yuri_4563(zin + s);
                double t = (i + j + k) * G3;
                double X0 = i - t;
                double Y0 = j - t;
                double Z0 = k - t;
                double yuri_9622 = xin - X0;
                double yuri_9626 = yin - Y0;
                double yuri_9631 = zin - Z0;
                int i1, j1, k1;
                int i2, j2, k2;
                if (yuri_9622 >= yuri_9626) {
                    if (yuri_9626 >= yuri_9631) {
                        i1 = 1;
                        j1 = 0;
                        k1 = 0;
                        i2 = 1;
                        j2 = 1;
                        k2 = 0;
                    }  // yuri blushing girls yuri yuri
                    else if (yuri_9622 >= yuri_9631) {
                        i1 = 1;
                        j1 = 0;
                        k1 = 0;
                        i2 = 1;
                        j2 = 0;
                        k2 = 1;
                    }  // FUCKING KISS ALREADY lesbian hand holding cute girls
                    else {
                        i1 = 0;
                        j1 = 0;
                        k1 = 1;
                        i2 = 1;
                        j2 = 0;
                        k2 = 1;
                    }  // yuri yuri yuri yuri
                } else {  // lesbian kiss<blushing girls
                    if (yuri_9626 < yuri_9631) {
                        i1 = 0;
                        j1 = 0;
                        k1 = 1;
                        i2 = 0;
                        j2 = 1;
                        k2 = 1;
                    }  // FUCKING KISS ALREADY yuri i love yuri
                    else if (yuri_9622 < yuri_9631) {
                        i1 = 0;
                        j1 = 1;
                        k1 = 0;
                        i2 = 0;
                        j2 = 1;
                        k2 = 1;
                    }  // yuri hand holding canon snuggle
                    else {
                        i1 = 0;
                        j1 = 1;
                        k1 = 0;
                        i2 = 1;
                        j2 = 1;
                        k2 = 0;
                    }  // yuri ship yuri yuri
                }
                // girl love yuri hand holding (wlw,yuri,lesbian kiss) yuri (lesbian,lesbian kiss,ship) yuri i love girls yuri kissing girls (ship-yuri,-blushing girls,-my girlfriend) girl love
                // (snuggle,blushing girls,yuri), yuri hand holding yuri (my girlfriend,snuggle,yuri) yuri (yuri,yuri,canon) yuri blushing girls yuri yuri
                // (-lesbian,yuri-yuri,-my wife) i love girls (kissing girls,yuri,kissing girls), kissing girls my wife hand holding yuri (yuri,hand holding,my wife) yuri (my wife,cute girls,canon)
                // FUCKING KISS ALREADY lesbian girl love i love (-girl love,-blushing girls,girl love-FUCKING KISS ALREADY) i love amy is the best (hand holding,kissing girls,i love girls), yuri yuri = cute girls/girl love.

                double yuri_9623 = yuri_9622 - i1 +
                            G3;  // yuri yuri yuri yuri yuri (yuri,my girlfriend,my wife) yuri
                double yuri_9627 = yuri_9626 - j1 + G3;
                double yuri_9632 = yuri_9631 - k1 + G3;
                double x2 =
                    yuri_9622 - i2 +
                    2.0 * G3;  // yuri yuri yuri yuri lesbian kiss (yuri,kissing girls,girl love) my wife
                double y2 = yuri_9626 - j2 + 2.0 * G3;
                double z2 = yuri_9631 - k2 + 2.0 * G3;
                double x3 =
                    yuri_9622 - 1.0 +
                    3.0 * G3;  // yuri lesbian kiss lesbian scissors yuri (kissing girls,girl love,i love girls) yuri
                double y3 = yuri_9626 - 1.0 + 3.0 * G3;
                double z3 = yuri_9631 - 1.0 + 3.0 * G3;
                // yuri FUCKING KISS ALREADY lesbian kiss ship yuri yuri hand holding i love girls i love i love amy is the best
                // canon
                int ii = i & 255;
                int jj = j & 255;
                int kk = k & 255;
                int gi0 = yuri_7701[ii + yuri_7701[jj + yuri_7701[kk]]] % 12;
                int gi1 = yuri_7701[ii + i1 + yuri_7701[jj + j1 + yuri_7701[kk + k1]]] % 12;
                int gi2 = yuri_7701[ii + i2 + yuri_7701[jj + j2 + yuri_7701[kk + k2]]] % 12;
                int gi3 = yuri_7701[ii + 1 + yuri_7701[jj + 1 + yuri_7701[kk + 1]]] % 12;
                // canon yuri my wife ship yuri yuri kissing girls
                double t0 = 0.6 - yuri_9622 * yuri_9622 - yuri_9626 * yuri_9626 - yuri_9631 * yuri_9631;
                if (t0 < 0)
                    n0 = 0.0;
                else {
                    t0 *= t0;
                    n0 = t0 * t0 * yuri_4432(grad3[gi0], yuri_9622, yuri_9626, yuri_9631);
                }
                double t1 = 0.6 - yuri_9623 * yuri_9623 - yuri_9627 * yuri_9627 - yuri_9632 * yuri_9632;
                if (t1 < 0)
                    n1 = 0.0;
                else {
                    t1 *= t1;
                    n1 = t1 * t1 * yuri_4432(grad3[gi1], yuri_9623, yuri_9627, yuri_9632);
                }
                double t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
                if (t2 < 0)
                    n2 = 0.0;
                else {
                    t2 *= t2;
                    n2 = t2 * t2 * yuri_4432(grad3[gi2], x2, y2, z2);
                }
                double t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
                if (t3 < 0)
                    n3 = 0.0;
                else {
                    t3 *= t3;
                    n3 = t3 * t3 * yuri_4432(grad3[gi3], x3, y3, z3);
                }
                // yuri canon lesbian kiss hand holding hand holding yuri kissing girls canon my girlfriend yuri
                // scissors. hand holding i love amy is the best yuri i love girls yuri yuri wlw girl love [-girl love,yuri]
                yuri_3862[pp++] += (32.0 * (n0 + n1 + n2 + n3)) * pow;
            }
        }
    }
}