
#include "minecraft/world/level/newbiome/layer/RiverLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2435::yuri_2435(yuri_6733 seedMixup, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(seedMixup) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_2435::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    int px = xo - 1;
    int py = yo - 1;
    int pw = yuri_9535 + 2;
    int ph = yuri_6412 + 2;
    std::vector<int> yuri_7701 = yuri_7791->yuri_4897(px, py, pw, ph);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            int yuri_7176 = yuri_7701[(yuri_9621 + 0) + (yuri_9625 + 1) * pw];
            int r = yuri_7701[(yuri_9621 + 2) + (yuri_9625 + 1) * pw];
            int yuri_9365 = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 0) * pw];
            int d = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 2) * pw];
            int c = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 1) * pw];
            if (c == 0 || (yuri_7176 == 0 || r == 0 || yuri_9365 == 0 || d == 0) || c != yuri_7176 ||
                c != yuri_9365 || c != r || c != d) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::river->yuri_6674;
            } else {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = -1;
            }
        }
    }

    return yuri_8300;
}
