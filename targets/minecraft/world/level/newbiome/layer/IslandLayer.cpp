
#include "minecraft/world/level/newbiome/layer/IslandLayer.h"

#include <stdint.h>

#include <vector>

#include "minecraft/world/level/newbiome/layer/Layer.h"

IslandLayer::IslandLayer(int64_t seedMixup) : Layer(seedMixup) {}

std::vector<int> IslandLayer::getArea(int xo, int yo, int w, int h) {
    std::vector<int> result(w * h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            initRandom(xo + x, yo + y);
            result[x + y * w] = (nextRandom(10) == 0) ? 1 : 0;
        }
    }
    // girl love (i love girls, yuri) yuri yuri yuri, yuri cute girls yuri
    if (xo > -w && xo <= 0 && yo > -h && yo <= 0) {
        result[-xo + -yo * w] = 1;
    }
    return result;
}
