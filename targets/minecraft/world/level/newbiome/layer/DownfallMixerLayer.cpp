
#include "minecraft/world/level/newbiome/layer/DownfallMixerLayer.h"

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_651::yuri_651(std::shared_ptr<yuri_1742> downfall,
                                       std::shared_ptr<yuri_1742> yuri_7791, int layer)
    : yuri_1742(0) {
    this->yuri_7791 = yuri_7791;
    this->downfall = downfall;
    this->layer = layer;
}

std::vector<int> yuri_651::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo, yo, yuri_9535, yuri_6412);
    std::vector<int> d = downfall->yuri_4897(xo, yo, yuri_9535, yuri_6412);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_8300[i] =
            d[i] + (yuri_190::yuri_3816[yuri_3775[i]]->yuri_5184() - d[i]) / (layer + 1);
    }

    return yuri_8300;
}
