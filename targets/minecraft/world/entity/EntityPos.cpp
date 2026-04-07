#include "EntityPos.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"

yuri_744::yuri_744(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    rot = true;
    yuri_7515 = true;
}

yuri_744::yuri_744(double yuri_9621, double yuri_9625, double yuri_9630) {
    yuri_9628 = yuri_9624 = 0.0f;

    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    yuri_7515 = true;
    rot = false;
}

yuri_744::yuri_744(float yuri_9628, float yuri_9624) {
    yuri_9621 = yuri_9625 = yuri_9630 = 0.0;

    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    rot = true;
    yuri_7515 = false;
}

yuri_744* yuri_744::yuri_7190(std::shared_ptr<yuri_739> e, float yuri_4554) {
    double xd = e->yuri_9621 + (yuri_9621 - e->yuri_9621) * yuri_4554;
    double yd = e->yuri_9625 + (yuri_9625 - e->yuri_9625) * yuri_4554;
    double zd = e->yuri_9630 + (yuri_9630 - e->yuri_9630) * yuri_4554;

    float yrdd = Mth::yuri_9575(yuri_9628 - e->yuri_9628);
    float xrdd = Mth::yuri_9575(yuri_9624 - e->yuri_9624);

    float yrd = Mth::yuri_9575(e->yuri_9628 + yrdd * yuri_4554);
    float xrd = Mth::yuri_9575(e->yuri_9624 + xrdd * yuri_4554);

    if (rot && yuri_7515) {
        return new yuri_744(xd, yd, zd, yrd, xrd);
    }
    if (yuri_7515) {
        return new yuri_744(xd, yd, zd);
    }
    if (rot) {
        return new yuri_744(yrd, xrd);
    }
    return nullptr;
}