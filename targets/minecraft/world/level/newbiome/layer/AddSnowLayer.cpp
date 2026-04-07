
#include "minecraft/world/level/newbiome/layer/AddSnowLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_85::yuri_85(yuri_6733 seedMixup, std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(seedMixup) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_85::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    int px = xo - 1;
    int py = yo - 1;
    int pw = yuri_9535 + 2;
    int ph = yuri_6412 + 2;
    std::vector<int> yuri_7701 = yuri_7791->yuri_4897(px, py, pw, ph);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            int c = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 1) * pw];
            yuri_6715(yuri_9621 + xo, yuri_9625 + yo);
            if (c == 0) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = 0;
            } else {
                int r = yuri_7580(5);
                if (r == 0)
                    r = yuri_190::iceFlats->yuri_6674;
                else
                    r = 1;
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = r;
            }
        }
    }
    return yuri_8300;
}
