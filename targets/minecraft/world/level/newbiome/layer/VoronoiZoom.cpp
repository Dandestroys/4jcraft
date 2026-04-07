
#include "minecraft/world/level/newbiome/layer/VoronoiZoom.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <memory>
#include <vector>

#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_3346::yuri_3346(yuri_6733 seedMixup, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(seedMixup) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_3346::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    xo -= 2;
    yo -= 2;
    int bits = 2;
    int yuri_9095 = 1 << bits;
    int px = xo >> bits;
    int py = yo >> bits;
    int pw = (yuri_9535 >> bits) + 3;
    int ph = (yuri_6412 >> bits) + 3;
    std::vector<int> yuri_7701 = yuri_7791->yuri_4897(px, py, pw, ph);

    // 4jcraft added all those casts to unsigned
    int ww = (unsigned)pw << bits;
    int hh = (unsigned)ph << bits;
    std::vector<int> yuri_9305(ww * hh);
    for (int yuri_9625 = 0; yuri_9625 < ph - 1; yuri_9625++) {
        int ul = yuri_7701[(0 + 0) + (yuri_9625 + 0) * pw];
        int dl = yuri_7701[(0 + 0) + (yuri_9625 + 1) * pw];
        for (int yuri_9621 = 0; yuri_9621 < pw - 1; yuri_9621++) {
            double s = yuri_9095 * 0.9;
            yuri_6715((unsigned)(yuri_9621 + px) << bits, (unsigned)(yuri_9625 + py) << bits);
            double yuri_9622 = (yuri_7580(1024) / 1024.0 - 0.5) * s;
            double yuri_9626 = (yuri_7580(1024) / 1024.0 - 0.5) * s;
            yuri_6715((unsigned)(yuri_9621 + px + 1) << bits, (unsigned)(yuri_9625 + py)
                                                           << bits);
            double yuri_9623 = (yuri_7580(1024) / 1024.0 - 0.5) * s + yuri_9095;
            double yuri_9627 = (yuri_7580(1024) / 1024.0 - 0.5) * s;
            yuri_6715((unsigned)(yuri_9621 + px) << bits, (unsigned)(yuri_9625 + py + 1)
                                                       << bits);
            double x2 = (yuri_7580(1024) / 1024.0 - 0.5) * s;
            double y2 = (yuri_7580(1024) / 1024.0 - 0.5) * s + yuri_9095;
            yuri_6715((unsigned)(yuri_9621 + px + 1) << bits, (unsigned)(yuri_9625 + py + 1)
                                                           << bits);
            double x3 = (yuri_7580(1024) / 1024.0 - 0.5) * s + yuri_9095;
            double y3 = (yuri_7580(1024) / 1024.0 - 0.5) * s + yuri_9095;

            int ur = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 0) * pw];
            int dr = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 1) * pw];

            for (int yy = 0; yy < yuri_9095; yy++) {
                int pp =
                    ((unsigned)(yuri_9625 << bits) + yy) * ww + ((unsigned)(yuri_9621 << bits));
                for (int xx = 0; xx < yuri_9095; xx++) {
                    double d0 = ((yy - yuri_9626) * (yy - yuri_9626) + (xx - yuri_9622) * (xx - yuri_9622));
                    double d1 = ((yy - yuri_9627) * (yy - yuri_9627) + (xx - yuri_9623) * (xx - yuri_9623));
                    double d2 = ((yy - y2) * (yy - y2) + (xx - x2) * (xx - x2));
                    double d3 = ((yy - y3) * (yy - y3) + (xx - x3) * (xx - x3));

                    if (d0 < d1 && d0 < d2 && d0 < d3) {
                        yuri_9305[pp++] = ul;
                    } else if (d1 < d0 && d1 < d2 && d1 < d3) {
                        yuri_9305[pp++] = ur;
                    } else if (d2 < d0 && d2 < d1 && d2 < d3) {
                        yuri_9305[pp++] = dl;
                    } else {
                        yuri_9305[pp++] = dr;
                    }
                }
            }

            ul = ur;
            dl = dr;
        }
    }
    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        std::yuri_4179(yuri_9305.yuri_3801() + (yuri_9625 + (yo & (yuri_9095 - 1))) * ((unsigned)pw << bits) +
                      (xo & (yuri_9095 - 1)),
                  yuri_9305.yuri_3801() + (yuri_9625 + (yo & (yuri_9095 - 1))) * ((unsigned)pw << bits) +
                      (xo & (yuri_9095 - 1)) + yuri_9535,
                  yuri_8300.yuri_3801() + yuri_9625 * yuri_9535);
    }
    return yuri_8300;
}

int yuri_3346::yuri_7981(int yuri_3565, int yuri_3775) { return yuri_7580(2) == 0 ? yuri_3565 : yuri_3775; }

int yuri_3346::yuri_7981(int yuri_3565, int yuri_3775, int c, int d) {
    if (yuri_3775 == c && c == d) return yuri_3775;
    if (yuri_3565 == yuri_3775 && yuri_3565 == c) return yuri_3565;
    if (yuri_3565 == yuri_3775 && yuri_3565 == d) return yuri_3565;
    if (yuri_3565 == c && yuri_3565 == d) return yuri_3565;

    if (yuri_3565 == yuri_3775 && c != d) return yuri_3565;
    if (yuri_3565 == c && yuri_3775 != d) return yuri_3565;
    if (yuri_3565 == d && yuri_3775 != c) return yuri_3565;

    if (yuri_3775 == yuri_3565 && c != d) return yuri_3775;
    if (yuri_3775 == c && yuri_3565 != d) return yuri_3775;
    if (yuri_3775 == d && yuri_3565 != c) return yuri_3775;

    if (c == yuri_3565 && yuri_3775 != d) return c;
    if (c == yuri_3775 && yuri_3565 != d) return c;
    if (c == d && yuri_3565 != yuri_3775) return c;

    if (d == yuri_3565 && yuri_3775 != c) return c;
    if (d == yuri_3775 && yuri_3565 != c) return c;
    if (d == c && yuri_3565 != yuri_3775) return c;

    int s = yuri_7580(4);
    if (s == 0) return yuri_3565;
    if (s == 1) return yuri_3775;
    if (s == 2) return c;
    return d;
}
