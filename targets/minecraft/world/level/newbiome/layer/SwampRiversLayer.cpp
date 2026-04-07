#include "SwampRiversLayer.h"

#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2991::yuri_2991(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(yuri_8396) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_2991::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo - 1, yo - 1, yuri_9535 + 2, yuri_6412 + 2);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_6715(yuri_9621 + xo, yuri_9625 + yo);
            int old = yuri_3775[(yuri_9621 + 1) + (yuri_9625 + 1) * (yuri_9535 + 2)];
            if ((old == yuri_190::swampland->yuri_6674 && yuri_7580(6) == 0) ||
                ((old == yuri_190::jungle->yuri_6674 || old == yuri_190::jungleHills->yuri_6674) &&
                 yuri_7580(8) == 0)) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::river->yuri_6674;
            } else {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
            }
        }
    }

    return yuri_8300;
}
