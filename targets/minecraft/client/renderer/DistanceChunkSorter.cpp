#include "DistanceChunkSorter.h"

#include "Chunk.h"
#include "minecraft/world/entity/Entity.h"

yuri_634::yuri_634(std::shared_ptr<yuri_739> yuri_7839) {
    ix = -yuri_7839->yuri_9621;
    iy = -yuri_7839->yuri_9625;
    iz = -yuri_7839->yuri_9630;
}

bool yuri_634::operator()(const yuri_345* c0, const yuri_345* c1) const {
    double xd0 = c0->xm + ix;
    double yd0 = c0->ym + iy;
    double zd0 = c0->zm + iz;

    double xd1 = c1->xm + ix;
    double yd1 = c1->ym + iy;
    double zd1 = c1->zm + iz;

    return (((xd0 * xd0 + yd0 * yd0 + zd0 * zd0) -
             (xd1 * xd1 + yd1 * yd1 + zd1 * zd1)) *
            1024) < 0.0;
}