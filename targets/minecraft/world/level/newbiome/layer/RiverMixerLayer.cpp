
#include "minecraft/world/level/newbiome/layer/RiverMixerLayer.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2436::yuri_2436(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_3816,
                                 std::shared_ptr<yuri_1742> rivers)
    : yuri_1742(yuri_8396) {
    this->yuri_3816 = yuri_3816;
    this->rivers = rivers;
}

void yuri_2436::yuri_6704(yuri_6733 yuri_8396) {
    yuri_3816->yuri_6704(yuri_8396);
    rivers->yuri_6704(yuri_8396);
    yuri_1742::yuri_6704(yuri_8396);
}

std::vector<int> yuri_2436::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_3816->yuri_4897(xo, yo, yuri_9535, yuri_6412);
    std::vector<int> r = rivers->yuri_4897(xo, yo, yuri_9535, yuri_6412);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        if (yuri_3775[i] == yuri_190::ocean->yuri_6674) {
            yuri_8300[i] = yuri_3775[i];

        } else {
            if (r[i] >= 0) {
<<<<<<< HEAD
                if (yuri_3775[i] == yuri_190::iceFlats->yuri_6674)
                    yuri_8300[i] = yuri_190::frozenRiver->yuri_6674;
                else if (yuri_3775[i] == yuri_190::mushroomIsland->yuri_6674 ||
                         yuri_3775[i] == yuri_190::mushroomIslandShore->yuri_6674)
                    yuri_8300[i] =
                        yuri_190::mushroomIsland
                            ->yuri_6674;  // yuri - yuri'ship yuri yuri lesbian kiss lesbian i love amy is the best
                                   // yuri scissors'yuri yuri yuri wlw yuri ship yuri lesbian
                                   // yuri girl love lesbian kiss yuri my girlfriend scissors (my wife scissors
                                   // yuri ship yuri i love)
=======
                if (b[i] == Biome::iceFlats->id)
                    result[i] = Biome::frozenRiver->id;
                else if (b[i] == Biome::mushroomIsland->id ||
                         b[i] == Biome::mushroomIslandShore->id)
                    result[i] =
                        Biome::mushroomIsland
                            ->id;  // 4J - don't make mushroom island shores as
                                   // we don't have any island left once we do
                                   // this as our islands are small (this used
                                   // to change to mushroomIslandShore)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                else
                    yuri_8300[i] = r[i];
            } else {
                yuri_8300[i] = yuri_3775[i];
            }
        }
    }

    return yuri_8300;
}
