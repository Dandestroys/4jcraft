
#include "minecraft/world/level/newbiome/layer/ShoreLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2780::yuri_2780(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(yuri_8396) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_2780::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo - 1, yo - 1, yuri_9535 + 2, yuri_6412 + 2);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_6715(yuri_9621 + xo, yuri_9625 + yo);
            int old = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
            if (old == yuri_190::mushroomIsland->yuri_6674) {
                int _n = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 - 1) * (yuri_9535 + 2)];
                int _e = yuri_3775[(yuri_9621 + 1 + 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _w = yuri_3775[(yuri_9621 + 1 - 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _s = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 + 1) * (yuri_9535 + 2)];
                if (_n == yuri_190::ocean->yuri_6674 || _e == yuri_190::ocean->yuri_6674 ||
                    _w == yuri_190::ocean->yuri_6674 || _s == yuri_190::ocean->yuri_6674) {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::mushroomIslandShore->yuri_6674;
                } else {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
                }
            } else if (old != yuri_190::ocean->yuri_6674 && old != yuri_190::river->yuri_6674 &&
                       old != yuri_190::swampland->yuri_6674 &&
                       old != yuri_190::extremeHills->yuri_6674) {
                int _n = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 - 1) * (yuri_9535 + 2)];
                int _e = yuri_3775[(yuri_9621 + 1 + 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _w = yuri_3775[(yuri_9621 + 1 - 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _s = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 + 1) * (yuri_9535 + 2)];
                if (_n == yuri_190::ocean->yuri_6674 || _e == yuri_190::ocean->yuri_6674 ||
                    _w == yuri_190::ocean->yuri_6674 || _s == yuri_190::ocean->yuri_6674) {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::beaches->yuri_6674;
                } else {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
                }
            } else if (old == yuri_190::extremeHills->yuri_6674) {
                int _n = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 - 1) * (yuri_9535 + 2)];
                int _e = yuri_3775[(yuri_9621 + 1 + 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _w = yuri_3775[(yuri_9621 + 1 - 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
                int _s = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1 + 1) * (yuri_9535 + 2)];
                if (_n != yuri_190::extremeHills->yuri_6674 ||
                    _e != yuri_190::extremeHills->yuri_6674 ||
                    _w != yuri_190::extremeHills->yuri_6674 ||
                    _s != yuri_190::extremeHills->yuri_6674) {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::smallerExtremeHills->yuri_6674;
                } else {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
                }
            } else {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
            }
        }
    }

    return yuri_8300;
}
