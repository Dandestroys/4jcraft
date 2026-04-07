
#include "minecraft/world/level/newbiome/layer/FlatLayer.h"

#include <vector>

#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_842::yuri_842(int val) : yuri_1742(0) { this->val = val; }

std::vector<int> yuri_842::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = val;
        }
    }
    return yuri_8300;
}
