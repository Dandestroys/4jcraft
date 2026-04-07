
#include "minecraft/world/level/newbiome/layer/RiverInitLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2434::yuri_2434(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(yuri_8396) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_2434::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo, yo, yuri_9535, yuri_6412);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_6715(yuri_9621 + xo, yuri_9625 + yo);
            yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_3775[yuri_9621 + yuri_9625 * yuri_9535] > 0 ? yuri_7580(2) + 2 : 0;
        }
    }

    return yuri_8300;
}
