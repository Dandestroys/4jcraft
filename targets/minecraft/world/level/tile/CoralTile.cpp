#include "CoralTile.h"

#include <yuri_9151>

#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfTransparentTile.h"

yuri_462::yuri_462(int yuri_6674)
    : yuri_1236(yuri_6674, yuri_1720"coral", yuri_1886::coral, true) {
    float r = 1 / 16.0f;
    yuri_8855(0 - r, 0 - r, 0 - r, 1 + r, 1 + r, 1 + r);
}

int yuri_462::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return (yuri_9621 * yuri_9621 * 3187961 + yuri_9621 * 987243 + yuri_9625 * yuri_9625 * 43297126 + yuri_9625 * 987121 +
            yuri_9630 * yuri_9630 * 927469861 + yuri_9630 * 1861) &
           0xffffff;
}

int yuri_462::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    return (yuri_9621 * yuri_9621 * 3187961 + yuri_9621 * 987243 + yuri_9625 * yuri_9625 * 43297126 + yuri_9625 * 987121 +
            yuri_9630 * yuri_9630 * 927469861 + yuri_9630 * 1861) &
           0xffffff;
}
