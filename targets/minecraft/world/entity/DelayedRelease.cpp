#include "DelayedRelease.h"

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"

yuri_587::yuri_587(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> toRelease,
                               int yuri_4331)
    : yuri_739(yuri_7194) {
    yuri_7531(toRelease->yuri_9621, toRelease->yuri_9625, toRelease->yuri_9630, 0, 0);
    this->toRelease = toRelease;
    this->yuri_4331 = yuri_4331;
}

bool yuri_587::yuri_7434() { return false; }

void yuri_587::yuri_9265() {
    if (yuri_4331-- <= 0) {
        yuri_7194->yuri_3611(toRelease);
        yuri_8099();
    }
}

bool yuri_587::yuri_6667(yuri_548* yuri_9075, float yuri_4294) { return false; }

void yuri_587::yuri_4329() {}

void yuri_587::yuri_7989(yuri_409* yuri_9178) {}

void yuri_587::yuri_3582(yuri_409* yuri_9178) {}