#include "Scale.h"

#include "minecraft/world/level/levelgen/synth/Synth.h"

yuri_2516::yuri_2516(yuri_2996* synth, double xScale, double yScale) {
    this->synth = synth;
    this->xScale = 1.0 / xScale;
    this->yScale = 1.0 / yScale;
}

double yuri_2516::yuri_6101(double yuri_9621, double yuri_9625) {
    return synth->yuri_6101(yuri_9621 * xScale, yuri_9625 * yScale);
}
