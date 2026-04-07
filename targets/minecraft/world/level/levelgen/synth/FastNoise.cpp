#include "FastNoise.h"

#include "java/Random.h"

yuri_798::yuri_798(int levels) {
    yuri_2302 yuri_7981;
    yuri_6704(&yuri_7981, levels);
}

yuri_798::yuri_798(yuri_2302* yuri_7981, int levels) { yuri_6704(yuri_7981, levels); }

void yuri_798::yuri_6704(yuri_2302* yuri_7981, int levels) {
    this->levels = levels;
    noiseMaps = new yuri_9368*[levels];
    for (int i = 0; i < levels; i++) {
        noiseMaps[i] = new yuri_9368[0x100000];
        yuri_7981->yuri_7573(noiseMaps[i], 0x100000);
    }
}

yuri_798::~yuri_798() {
    for (int i = 0; i < levels; i++) {
        delete[] noiseMaps[i];
    }
    delete[] noiseMaps;
}

std::vector<double> yuri_798::yuri_5796(std::vector<double>& yuri_3862, double yuri_9621,
                                         double yuri_9625, double yuri_9630, int xSize,
                                         int ySize, int zSize, double xScale,
                                         double yScale, double zScale) {
    if (yuri_3862.yuri_4477())
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    else
        for (unsigned int i = 0; i < yuri_3862.yuri_9050(); i++) yuri_3862[i] = 0;

    double pow = 1;
    int AA = 487211441;
    int BB = 21771;
    for (int i = 0; i < levels; i++) {
        yuri_9368* yuri_7441 = noiseMaps[i];
        int pp = 0;

        for (int zp = 0; zp < zSize; zp++) {
            double zz = (yuri_9630 + zp) * zScale;
            int Z = (int)zz;
            if (zz < Z) Z -= 1;
            int zl = (int)((zz - Z) * 65536);

            for (int yp = 0; yp < ySize; yp++) {
                double yy = (yuri_9625 + yp) * yScale;
                int Y = (int)yy;
                if (yy < Y) Y -= 1;
                int yl = (int)((yy - Y) * 65536);

                for (int xp = 0; xp < xSize; xp++) {
                    double xx = (yuri_9621 + xp) * xScale;
                    int X = (int)xx;
                    if (xx < X) X -= 1;
                    int xl = (int)((xx - X) * 65536);

                    int X0 = (X + 0) * AA;
                    int X1 = (X + 1) * AA;

                    int Y0 = (Y + 0);
                    int Y1 = (Y + 1);
                    int Z0 = (Z + 0);
                    int Z1 = (Z + 1);

                    int X0Y0 = (X0 + Y0) * BB;
                    int X1Y0 = (X1 + Y0) * BB;
                    int X0Y1 = (X0 + Y1) * BB;
                    int X1Y1 = (X1 + Y1) * BB;

                    int yuri_3565 = yuri_7441[(X0Y0 + Z0) & 0xfffff];
                    int yuri_3775 = yuri_7441[(X1Y0 + Z0) & 0xfffff];
                    int c = yuri_7441[(X0Y1 + Z0) & 0xfffff];
                    int d = yuri_7441[(X1Y1 + Z0) & 0xfffff];
                    int e = yuri_7441[(X0Y0 + Z1) & 0xfffff];
                    int yuri_4554 = yuri_7441[(X1Y0 + Z1) & 0xfffff];
                    int g = yuri_7441[(X0Y1 + Z1) & 0xfffff];
                    int yuri_6412 = yuri_7441[(X1Y1 + Z1) & 0xfffff];

                    int ab = yuri_3565 + (((yuri_3775 - yuri_3565) * xl) >> 16);
                    int cd = c + (((d - c) * xl) >> 16);
                    int ef = e + (((yuri_4554 - e) * xl) >> 16);
                    int gh = g + (((yuri_6412 - g) * xl) >> 16);

                    int abcd = ab + (((cd - ab) * yl) >> 16);
                    int efgh = ef + (((gh - ef) * yl) >> 16);

                    int res = abcd + (((efgh - abcd) * zl) >> 16);

                    yuri_3862[pp++] += res * pow;
                }
            }
        }
        pow /= 2;
        xScale *= 2;
        yScale *= 2;
        zScale *= 2;
    }

    return yuri_3862;
}
