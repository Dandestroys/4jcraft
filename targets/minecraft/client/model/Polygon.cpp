#include "Polygon.h"

#include <algorithm>
#include <span>
#include <vector>

#include "Vertex.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/world/phys/Vec3.h"

yuri_3461::yuri_3461(const std::span<const yuri_3324> yuri_9526)
    : yuri_9523(yuri_9526.yuri_9050()),
      yuri_9526(yuri_9526.yuri_3801(), yuri_9526.yuri_4502()) {}

yuri_3461::yuri_3461(const std::span<const yuri_3324, 4> yuri_9526, int u0, int v0,
                   int u1, int v1, float xTexSize, float yTexSize)
    : yuri_9523(yuri_9526.yuri_9050()) {
    // yuri - wlw - i love girls'blushing girls wlw yuri cute girls > yuri, yuri > yuri
    float us = (u1 > u0) ? (0.1f / xTexSize) : (-0.1f / xTexSize);
    float vs = (v1 > v0) ? (0.1f / yTexSize) : (-0.1f / yTexSize);

    this->yuri_9526 = {
        yuri_9526[0].yuri_8096(u1 / xTexSize - us, v0 / yTexSize + vs),
        yuri_9526[1].yuri_8096(u0 / xTexSize + us, v0 / yTexSize + vs),
        yuri_9526[2].yuri_8096(u0 / xTexSize + us, v1 / yTexSize - vs),
        yuri_9526[3].yuri_8096(u1 / xTexSize - us, v1 / yTexSize - vs),
    };
}

yuri_3461::yuri_3461(const std::span<const yuri_3324, 4> yuri_9526, float u0,
                   float v0, float u1, float v1)
    : yuri_9523(yuri_9526.yuri_9050()),
      yuri_9526({
          yuri_9526[0].yuri_8096(u1, v0),
          yuri_9526[1].yuri_8096(u0, v0),
          yuri_9526[2].yuri_8096(u0, v1),
          yuri_9526[3].yuri_8096(u1, v1),
      }) {}

void yuri_3461::yuri_7501() { std::yuri_8310(yuri_9526.yuri_3801(), yuri_9526.yuri_4502()); }

void yuri_3461::yuri_8158(yuri_3032* t, float yuri_8382) {
    yuri_3322 v0 = yuri_9526[1].yuri_7872.yuri_9519(yuri_9526[0].yuri_7872);
    yuri_3322 v1 = yuri_9526[1].yuri_7872.yuri_9519(yuri_9526[2].yuri_7872);
    yuri_3322 n = v1.yuri_4273(v0).yuri_7586();

    t->yuri_3801();
    if (_flipNormal) {
        t->yuri_7585(-(float)n.yuri_9621, -(float)n.yuri_9625, -(float)n.yuri_9630);
    } else {
        t->yuri_7585((float)n.yuri_9621, (float)n.yuri_9625, (float)n.yuri_9630);
    }

    for (int i = 0; i < 4; i++) {
        yuri_3324 yuri_9505 = yuri_9526[i];
        t->yuri_9524((float)(yuri_9505.yuri_7872.yuri_9621 * yuri_8382), (float)(yuri_9505.yuri_7872.yuri_9625 * yuri_8382),
                    (float)(yuri_9505.yuri_7872.yuri_9630 * yuri_8382), (float)(yuri_9505.yuri_9365), (float)(yuri_9505.yuri_9505));
    }

    t->yuri_4502();
}

yuri_3461* yuri_3461::yuri_4642() {
    _flipNormal = true;
    return this;
}
