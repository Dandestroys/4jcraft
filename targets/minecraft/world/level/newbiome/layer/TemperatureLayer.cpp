
#include "minecraft/world/level/newbiome/layer/TemperatureLayer.h"

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_3026::yuri_3026(std::shared_ptr<yuri_1742> yuri_7791) : yuri_1742(0) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_3026::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo, yo, yuri_9535, yuri_6412);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_8300[i] = yuri_190::yuri_3816[yuri_3775[i]]->yuri_6004();
    }
    return yuri_8300;
}
