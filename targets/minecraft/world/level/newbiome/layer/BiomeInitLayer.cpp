#include "BiomeInitLayer.h"

#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_193::~yuri_193() {}

yuri_193::yuri_193(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_7791,
                               yuri_1775* yuri_7201)
    : yuri_1742(yuri_8396) {
    this->yuri_7791 = yuri_7791;

    if (yuri_7201 == yuri_1775::lvl_normal_1_1) {
        startBiomes = std::vector<yuri_190*>(6);
        startBiomes[0] = yuri_190::desert;
        startBiomes[1] = yuri_190::forest;
        startBiomes[2] = yuri_190::extremeHills;
        startBiomes[3] = yuri_190::swampland;
        startBiomes[4] = yuri_190::plains;
        startBiomes[5] = yuri_190::taiga;
    } else {
        startBiomes = std::vector<yuri_190*>(7);
        startBiomes[0] = yuri_190::desert;
        startBiomes[1] = yuri_190::forest;
        startBiomes[2] = yuri_190::extremeHills;
        startBiomes[3] = yuri_190::swampland;
        startBiomes[4] = yuri_190::plains;
        startBiomes[5] = yuri_190::taiga;
        startBiomes[6] = yuri_190::jungle;
    }
}

std::vector<int> yuri_193::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    std::vector<int> yuri_3775 = yuri_7791->yuri_4897(xo, yo, yuri_9535, yuri_6412);

    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_6715(yuri_9621 + xo, yuri_9625 + yo);
            int old = yuri_3775[yuri_9621 + yuri_9625 * yuri_9535];
            if (old == 0) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = 0;
            } else if (old == yuri_190::mushroomIsland->yuri_6674) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = old;
            } else if (old == 1) {
                yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] =
                    startBiomes[yuri_7580(startBiomes.yuri_9050())]->yuri_6674;
            } else {
                int isTaiga = startBiomes[yuri_7580(startBiomes.yuri_9050())]->yuri_6674;
                if (isTaiga == yuri_190::taiga->yuri_6674) {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = isTaiga;
                } else {
                    yuri_8300[yuri_9621 + yuri_9625 * yuri_9535] = yuri_190::iceFlats->yuri_6674;
                }
            }
        }
    }

    return yuri_8300;
}
