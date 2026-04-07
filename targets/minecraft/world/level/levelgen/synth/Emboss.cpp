#include "Emboss.h"

#include "minecraft/world/level/levelgen/synth/Synth.h"

yuri_690::yuri_690(yuri_2996* synth) { this->synth = synth; }

double yuri_690::yuri_6101(double yuri_9621, double yuri_9625) {
    return synth->yuri_6101(yuri_9621, yuri_9625) - synth->yuri_6101(yuri_9621 + 1, yuri_9625 + 1);
}