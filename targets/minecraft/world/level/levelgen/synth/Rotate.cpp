#include "Rotate.h"

#include <cmath>

#include "minecraft/world/level/levelgen/synth/Synth.h"

yuri_2439::yuri_2439(yuri_2996* synth, float angle) {
    this->synth = synth;

    _sin = sin(angle);
    _cos = cos(angle);
}

double yuri_2439::yuri_6101(double yuri_9621, double yuri_9625) {
    return synth->yuri_6101(yuri_9621 * _cos + yuri_9625 * _sin, yuri_9625 * _cos - yuri_9621 * _sin);
}