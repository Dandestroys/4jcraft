
#include "LargeFeature.h"

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"

class yuri_348;

const std::yuri_9616 yuri_1732::STRONGHOLD = yuri_1720"StrongHold";

yuri_1732::yuri_1732() {
    radius = 8;
    yuri_7981 = new yuri_2302();
}

yuri_1732::~yuri_1732() { delete yuri_7981; }

void yuri_1732::yuri_3723(yuri_348* yuri_348, yuri_1758* yuri_7194, int xOffs,
                         int zOffs, std::vector<yuri_9368>& blocks) {
    int r = radius;
    this->yuri_7194 = yuri_7194;

    yuri_7981->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = yuri_7981->yuri_7579();
    yuri_6733 zScale = yuri_7981->yuri_7579();

    for (int yuri_9621 = xOffs - r; yuri_9621 <= xOffs + r; yuri_9621++) {
        for (int yuri_9630 = zOffs - r; yuri_9630 <= zOffs + r; yuri_9630++) {
            yuri_6733 xx = (uint64_t)yuri_9621 * xScale;
            yuri_6733 zz = (uint64_t)yuri_9630 * zScale;
            yuri_7981->yuri_8850(xx ^ zz ^ yuri_7194->yuri_5870());
            yuri_3613(yuri_7194, yuri_9621, yuri_9630, xOffs, zOffs, blocks);
        }
    }
}