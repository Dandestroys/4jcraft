#include "BlockSourceImpl.h"

#include <memory>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_205::yuri_205(yuri_1758* world, int yuri_9621, int yuri_9625, int yuri_9630) {
    this->world = world;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

yuri_1758* yuri_205::yuri_6134() { return world; }

double yuri_205::yuri_6142() { return yuri_9621 + 0.5; }

double yuri_205::yuri_6164() { return yuri_9625 + 0.5; }

double yuri_205::yuri_6176() { return yuri_9630 + 0.5; }

int yuri_205::yuri_4959() { return yuri_9621; }

int yuri_205::yuri_4960() { return yuri_9625; }

int yuri_205::yuri_4961() { return yuri_9630; }

yuri_3088* yuri_205::yuri_6068() {
    return yuri_3088::tiles[world->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
}

int yuri_205::yuri_5115() { return world->yuri_5115(yuri_9621, yuri_9625, yuri_9630); }

yuri_1886* yuri_205::yuri_5514() { return world->yuri_5514(yuri_9621, yuri_9625, yuri_9630); }

std::shared_ptr<yuri_3091> yuri_205::yuri_5213() {
    return world->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
}