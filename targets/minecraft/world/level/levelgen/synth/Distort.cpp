#include "Distort.h"

#include "minecraft/world/level/levelgen/synth/Synth.h"

yuri_636::yuri_636(yuri_2996* yuri_9075, yuri_2996* distort) {
    this->yuri_9075 = yuri_9075;
    this->distort = distort;
}

double yuri_636::yuri_6101(double yuri_9621, double yuri_9625) {
    return yuri_9075->yuri_6101(yuri_9621 + distort->yuri_6101(yuri_9621, yuri_9625), yuri_9625);
}
