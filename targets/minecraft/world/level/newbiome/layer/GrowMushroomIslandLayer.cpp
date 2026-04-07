
#include "minecraft/world/level/newbiome/layer/GrowMushroomIslandLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_1225::yuri_1225(yuri_6733 seedMixup,
                                                 std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(seedMixup) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_1225::yuri_4897(int xo, int yo, int yuri_9535,
                                                  int yuri_6412) {
    int px = xo - 1;
    int py = yo - 1;
    int pw = yuri_9535 + 2;
    int ph = yuri_6412 + 2;
    std::vector<int> yuri_7701 = yuri_7791->yuri_4897(px, py, pw, ph);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            int n1 = yuri_7701[(yuri_9621 + 0) + (yuri_9625 + 0) * pw];
            int n2 = yuri_7701[(yuri_9621 + 2) + (yuri_9625 + 0) * pw];
            int n3 = yuri_7701[(yuri_9621 + 0) + (yuri_9625 + 2) * pw];
            int n4 = yuri_7701[(yuri_9621 + 2) + (yuri_9625 + 2) * pw];

            int c = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 1) * pw];

            if ((n1 == yuri_190::mushroomIsland->yuri_6674) ||
                (n2 == yuri_190::mushroomIsland->yuri_6674) ||
                (n3 == yuri_190::mushroomIsland->yuri_6674) ||
                (n4 == yuri_190::mushroomIsland->yuri_6674)) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::mushroomIsland->yuri_6674;
            } else {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = c;
            }
        }
    }
    return yuri_8300;
}
