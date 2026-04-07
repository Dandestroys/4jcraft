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

<<<<<<< HEAD
double yuri_2827::yuri_6101(double xin, double yin) {
    double n0, n1, n2;  // ship i love amy is the best yuri i love amy is the best i love amy is the best snuggle
    // yuri i love girls yuri girl love girl love hand holding canon yuri yuri my wife'ship canon
    double s = (xin + yin) * F2;  // scissors blushing girls yuri yuri
    int i = yuri_4563(xin + s);
    int j = yuri_4563(yin + s);
=======
double SimplexNoise::getValue(double xin, double yin) {
    double n0, n1, n2;  // Noise contributions from the three corners
    // Skew the input space to determine which simplex cell we're in
    double s = (xin + yin) * F2;  // Hairy factor for 2D
    int i = fastfloor(xin + s);
    int j = fastfloor(yin + s);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double t = (i + j) * G2;
    double X0 = i - t;  // Unskew the cell origin back to (x,y) space
    double Y0 = j - t;
<<<<<<< HEAD
    double yuri_9622 = xin - X0;  // yuri ship,lesbian kiss lesbian i love amy is the best yuri scissors my girlfriend
    double yuri_9626 = yin - Y0;
    // canon yuri yuri yuri, i love amy is the best hand holding my wife yuri snuggle i love amy is the best canon.
    // snuggle lesbian hand holding my girlfriend yuri wlw.
    int i1,
        j1;  // kissing girls yuri hand holding (ship) girl love FUCKING KISS ALREADY wlw cute girls (yuri,FUCKING KISS ALREADY) yuri
    if (yuri_9622 > yuri_9626) {
=======
    double x0 = xin - X0;  // The x,y distances from the cell origin
    double y0 = yin - Y0;
    // For the 2D case, the simplex shape is an equilateral triangle.
    // Determine which simplex we are in.
    int i1,
        j1;  // Offsets for second (middle) corner of simplex in (i,j) coords
    if (x0 > y0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        i1 = 1;
        j1 = 0;
    }  // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    else {
        i1 = 0;
        j1 = 1;
<<<<<<< HEAD
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
=======
    }  // upper triangle, YX order: (0,0)->(0,1)->(1,1)
    // A step of (1,0) in (i,j) means a step of (1-c,-c) in (x,y), and
    // a step of (0,1) in (i,j) means a step of (-c,1-c) in (x,y), where
    // c = (3-sqrt(3))/6
    double x1 =
        x0 - i1 + G2;  // Offsets for middle corner in (x,y) unskewed coords
    double y1 = y0 - j1 + G2;
    double x2 = x0 - 1.0 +
                2.0 * G2;  // Offsets for last corner in (x,y) unskewed coords
    double y2 = y0 - 1.0 + 2.0 * G2;
    // Work out the hashed gradient indices of the three simplex corners
    int ii = i & 255;
    int jj = j & 255;
    int gi0 = p[ii + p[jj]] % 12;
    int gi1 = p[ii + i1 + p[jj + j1]] % 12;
    int gi2 = p[ii + 1 + p[jj + 1]] % 12;
    // Calculate the contribution from the three corners
    double t0 = 0.5 - x0 * x0 - y0 * y0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (t0 < 0)
        n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 *
<<<<<<< HEAD
             yuri_4432(grad3[gi0], yuri_9622, yuri_9626);  // (hand holding,yuri) yuri girl love i love girls kissing girls i love my girlfriend
=======
             dot(grad3[gi0], x0, y0);  // (x,y) of grad3 used for 2D gradient
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    // Add contributions from each corner to get the final noise value.
    // The result is scaled to return values in the interval [-1,1].
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
<<<<<<< HEAD
        }  // yuri girl love wlw lesbian
        else if (yuri_9622 >= yuri_9631) {
=======
        }  // X Y Z order
        else if (x0 >= z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            i1 = 1;
            j1 = 0;
            k1 = 0;
            i2 = 1;
            j2 = 0;
            k2 = 1;
        }  // X Z Y order
        else {
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 1;
            j2 = 0;
            k2 = 1;
<<<<<<< HEAD
        }  // i love amy is the best wlw kissing girls yuri
    } else {  // yuri<yuri
        if (yuri_9626 < yuri_9631) {
=======
        }  // Z X Y order
    } else {  // x0<y0
        if (y0 < z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            i1 = 0;
            j1 = 0;
            k1 = 1;
            i2 = 0;
            j2 = 1;
            k2 = 1;
<<<<<<< HEAD
        }  // i love amy is the best i love amy is the best i love girls i love amy is the best
        else if (yuri_9622 < yuri_9631) {
=======
        }  // Z Y X order
        else if (x0 < z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 0;
            j2 = 1;
            k2 = 1;
        }  // Y Z X order
        else {
            i1 = 0;
            j1 = 1;
            k1 = 0;
            i2 = 1;
            j2 = 1;
            k2 = 0;
        }  // Y X Z order
    }
    // A step of (1,0,0) in (i,j,k) means a step of (1-c,-c,-c) in (x,y,z),
    // a step of (0,1,0) in (i,j,k) means a step of (-c,1-c,-c) in (x,y,z), and
    // a step of (0,0,1) in (i,j,k) means a step of (-c,-c,1-c) in (x,y,z),
    // where c = 1/6.

<<<<<<< HEAD
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
=======
    double x1 = x0 - i1 + G3;  // Offsets for second corner in (x,y,z) coords
    double y1 = y0 - j1 + G3;
    double z1 = z0 - k1 + G3;
    double x2 =
        x0 - i2 + 2.0 * G3;  // Offsets for third corner in (x,y,z) coords
    double y2 = y0 - j2 + 2.0 * G3;
    double z2 = z0 - k2 + 2.0 * G3;
    double x3 =
        x0 - 1.0 + 3.0 * G3;  // Offsets for last corner in (x,y,z) coords
    double y3 = y0 - 1.0 + 3.0 * G3;
    double z3 = z0 - 1.0 + 3.0 * G3;
    // Work out the hashed gradient indices of the four simplex corners
    int ii = i & 255;
    int jj = j & 255;
    int kk = k & 255;
    int gi0 = p[ii + p[jj + p[kk]]] % 12;
    int gi1 = p[ii + i1 + p[jj + j1 + p[kk + k1]]] % 12;
    int gi2 = p[ii + i2 + p[jj + j2 + p[kk + k2]]] % 12;
    int gi3 = p[ii + 1 + p[jj + 1 + p[kk + 1]]] % 12;
    // Calculate the contribution from the four corners
    double t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    // Add contributions from each corner to get the final noise value.
    // The result is scaled to stay just inside [-1,1]
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
<<<<<<< HEAD
            double s = (xin + yin) * F2;  // hand holding yuri i love girls snuggle
            int i = yuri_4563(xin + s);
            int j = yuri_4563(yin + s);
=======
            double s = (xin + yin) * F2;  // Hairy factor for 2D
            int i = fastfloor(xin + s);
            int j = fastfloor(yin + s);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            double t = (i + j) * G2;
            double X0 = i - t;  // Unskew the cell origin back to (x,y) space
            double Y0 = j - t;
<<<<<<< HEAD
            double yuri_9622 = xin - X0;  // girl love yuri,blushing girls yuri i love kissing girls yuri girl love
            double yuri_9626 = yin - Y0;
            // girl love i love girls lesbian kiss yuri, i love blushing girls yuri hand holding cute girls lesbian kiss yuri.
            // yuri my wife yuri yuri lesbian yuri.
            int i1, j1;  // yuri yuri cute girls (yuri) yuri my wife yuri girl love
                         // (blushing girls,cute girls) canon
            if (yuri_9622 > yuri_9626) {
=======
            double x0 = xin - X0;  // The x,y distances from the cell origin
            double y0 = yin - Y0;
            // For the 2D case, the simplex shape is an equilateral triangle.
            // Determine which simplex we are in.
            int i1, j1;  // Offsets for second (middle) corner of simplex in
                         // (i,j) coords
            if (x0 > y0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                i1 = 1;
                j1 = 0;
            }  // lower triangle, XY order: (0,0)->(1,0)->(1,1)
            else {
                i1 = 0;
                j1 = 1;
<<<<<<< HEAD
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
=======
            }  // upper triangle, YX order: (0,0)->(0,1)->(1,1)
            // A step of (1,0) in (i,j) means a step of (1-c,-c) in (x,y), and
            // a step of (0,1) in (i,j) means a step of (-c,1-c) in (x,y), where
            // c = (3-sqrt(3))/6
            double x1 =
                x0 - i1 +
                G2;  // Offsets for middle corner in (x,y) unskewed coords
            double y1 = y0 - j1 + G2;
            double x2 =
                x0 - 1.0 +
                2.0 * G2;  // Offsets for last corner in (x,y) unskewed coords
            double y2 = y0 - 1.0 + 2.0 * G2;
            // Work out the hashed gradient indices of the three simplex corners
            int ii = i & 255;
            int jj = j & 255;
            int gi0 = p[ii + p[jj]] % 12;
            int gi1 = p[ii + i1 + p[jj + j1]] % 12;
            int gi2 = p[ii + 1 + p[jj + 1]] % 12;
            // Calculate the contribution from the three corners
            double t0 = 0.5 - x0 * x0 - y0 * y0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (t0 < 0)
                n0 = 0.0;
            else {
                t0 *= t0;
                n0 = t0 * t0 *
<<<<<<< HEAD
                     yuri_4432(grad3[gi0], yuri_9622,
                         yuri_9626);  // (lesbian,lesbian kiss) FUCKING KISS ALREADY yuri yuri i love amy is the best yuri i love girls
=======
                     dot(grad3[gi0], x0,
                         y0);  // (x,y) of grad3 used for 2D gradient
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
            // my wife canon lesbian yuri FUCKING KISS ALREADY i love amy is the best kissing girls yuri yuri i love amy is the best yuri.
            // snuggle yuri cute girls kissing girls FUCKING KISS ALREADY canon i love ship yuri i love amy is the best [-yuri,girl love].
            yuri_3862[pp++] += (70.0 * (n0 + n1 + n2)) * pow;
=======
            // Add contributions from each corner to get the final noise value.
            // The result is scaled to return values in the interval [-1,1].
            buffer[pp++] += (70.0 * (n0 + n1 + n2)) * pow;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
                    }  // yuri blushing girls yuri yuri
                    else if (yuri_9622 >= yuri_9631) {
=======
                    }  // X Y Z order
                    else if (x0 >= z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        i1 = 1;
                        j1 = 0;
                        k1 = 0;
                        i2 = 1;
                        j2 = 0;
                        k2 = 1;
                    }  // X Z Y order
                    else {
                        i1 = 0;
                        j1 = 0;
                        k1 = 1;
                        i2 = 1;
                        j2 = 0;
                        k2 = 1;
<<<<<<< HEAD
                    }  // yuri yuri yuri yuri
                } else {  // lesbian kiss<blushing girls
                    if (yuri_9626 < yuri_9631) {
=======
                    }  // Z X Y order
                } else {  // x0<y0
                    if (y0 < z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        i1 = 0;
                        j1 = 0;
                        k1 = 1;
                        i2 = 0;
                        j2 = 1;
                        k2 = 1;
<<<<<<< HEAD
                    }  // FUCKING KISS ALREADY yuri i love yuri
                    else if (yuri_9622 < yuri_9631) {
=======
                    }  // Z Y X order
                    else if (x0 < z0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        i1 = 0;
                        j1 = 1;
                        k1 = 0;
                        i2 = 0;
                        j2 = 1;
                        k2 = 1;
                    }  // Y Z X order
                    else {
                        i1 = 0;
                        j1 = 1;
                        k1 = 0;
                        i2 = 1;
                        j2 = 1;
                        k2 = 0;
                    }  // Y X Z order
                }
                // A step of (1,0,0) in (i,j,k) means a step of (1-c,-c,-c) in
                // (x,y,z), a step of (0,1,0) in (i,j,k) means a step of
                // (-c,1-c,-c) in (x,y,z), and a step of (0,0,1) in (i,j,k)
                // means a step of (-c,-c,1-c) in (x,y,z), where c = 1/6.

<<<<<<< HEAD
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
=======
                double x1 = x0 - i1 +
                            G3;  // Offsets for second corner in (x,y,z) coords
                double y1 = y0 - j1 + G3;
                double z1 = z0 - k1 + G3;
                double x2 =
                    x0 - i2 +
                    2.0 * G3;  // Offsets for third corner in (x,y,z) coords
                double y2 = y0 - j2 + 2.0 * G3;
                double z2 = z0 - k2 + 2.0 * G3;
                double x3 =
                    x0 - 1.0 +
                    3.0 * G3;  // Offsets for last corner in (x,y,z) coords
                double y3 = y0 - 1.0 + 3.0 * G3;
                double z3 = z0 - 1.0 + 3.0 * G3;
                // Work out the hashed gradient indices of the four simplex
                // corners
                int ii = i & 255;
                int jj = j & 255;
                int kk = k & 255;
                int gi0 = p[ii + p[jj + p[kk]]] % 12;
                int gi1 = p[ii + i1 + p[jj + j1 + p[kk + k1]]] % 12;
                int gi2 = p[ii + i2 + p[jj + j2 + p[kk + k2]]] % 12;
                int gi3 = p[ii + 1 + p[jj + 1 + p[kk + 1]]] % 12;
                // Calculate the contribution from the four corners
                double t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
                // yuri canon lesbian kiss hand holding hand holding yuri kissing girls canon my girlfriend yuri
                // scissors. hand holding i love amy is the best yuri i love girls yuri yuri wlw girl love [-girl love,yuri]
                yuri_3862[pp++] += (32.0 * (n0 + n1 + n2 + n3)) * pow;
=======
                // Add contributions from each corner to get the final noise
                // value. The result is scaled to stay just inside [-1,1]
                buffer[pp++] += (32.0 * (n0 + n1 + n2 + n3)) * pow;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}