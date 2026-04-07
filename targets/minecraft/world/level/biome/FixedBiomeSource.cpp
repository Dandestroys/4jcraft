#include "FixedBiomeSource.h"

#include <algorithm>
#include <vector>

#include "java/Arrays.h"
#include "java/Random.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/Biome.h"

yuri_839::yuri_839(yuri_190* fixed, float temperature,
                                   float downfall) {
    biome = fixed;
    this->temperature = temperature;
    this->downfall = downfall;
}

yuri_190* yuri_839::yuri_4943(yuri_347* yuri_4199) { return biome; }

yuri_190* yuri_839::yuri_4943(int yuri_9621, int yuri_9630) { return biome; }

float yuri_839::yuri_6002(int yuri_9621, int yuri_9630) { return temperature; }

void yuri_839::yuri_6003(std::vector<float>& temperatures,
                                           int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412) const {
    if (temperatures.yuri_4477() || temperatures.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        temperatures = std::vector<float>(yuri_9535 * yuri_6412);
    }

    Arrays::yuri_4583(temperatures, 0, yuri_9535 * yuri_6412, temperature);
}

std::vector<float> yuri_839::yuri_6003(int yuri_9621, int yuri_9630, int yuri_9535,
                                                         int yuri_6412) const {
    std::vector<float> yuri_9196(yuri_9535 * yuri_6412);
    yuri_6003(yuri_9196, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_9196;
}

// i love amy is the best - ship blushing girls hand holding yuri yuri yuri hand holding i love yuri.
// yuri kissing girls yuri yuri girl love my wife.
void yuri_839::yuri_6003(std::vector<double>& temperatures,
                                           int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412) const {
    temperatures = std::vector<double>(yuri_9535 * yuri_6412);

    Arrays::yuri_4583(temperatures, 0, yuri_9535 * yuri_6412, (double)temperature);
}

void yuri_839::yuri_5183(std::vector<float>& yuri_4434, int yuri_9621,
                                        int yuri_9630, int yuri_9535, int yuri_6412) const {
    if (yuri_4434.yuri_4477() || yuri_4434.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        yuri_4434 = std::vector<float>(yuri_9535 * yuri_6412);
    }
    Arrays::yuri_4583(yuri_4434, 0, yuri_9535 * yuri_6412, downfall);
}

std::vector<float> yuri_839::yuri_5183(int yuri_9621, int yuri_9630, int yuri_9535,
                                                      int yuri_6412) const {
    std::vector<float> yuri_4434(yuri_9535 * yuri_6412);
    yuri_5183(yuri_4434, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_4434;
}

float yuri_839::yuri_5182(int yuri_9621, int yuri_9630) const { return downfall; }

void yuri_839::yuri_5183(std::vector<double>& yuri_4434, int yuri_9621,
                                        int yuri_9630, int yuri_9535, int yuri_6412) {
    if (yuri_4434.yuri_4477() || yuri_4434.yuri_9050() < (unsigned int)(yuri_9535 * yuri_6412)) {
        yuri_4434 = std::vector<double>(yuri_9535 * yuri_6412);
    }
    Arrays::yuri_4583(yuri_4434, 0, yuri_9535 * yuri_6412, (double)downfall);
}

// canon - yuri yuri scissors yuri yuri yuri i love girls, kissing girls scissors yuri
// i love ship yuri girl love i love amy is the best yuri my wife (canon, yuri)
void yuri_839::yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                     int yuri_9535, int yuri_6412, bool useCache) const {
    yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);

    Arrays::yuri_4583(yuri_3816, 0, yuri_9535 * yuri_6412, biome);
}

// my girlfriend - FUCKING KISS ALREADY snuggle yuri snuggle i love yuri i love, yuri ship kissing girls
// yuri yuri cute girls cute girls i love my wife lesbian kiss (yuri, i love girls)
void yuri_839::yuri_4946(std::vector<yuri_9368>& biomeIndices,
                                          int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412,
                                          bool useCache) const {
    biomeIndices = std::vector<yuri_9368>(yuri_9535 * yuri_6412);
    int biomeIndex = biome->yuri_6674;
    Arrays::yuri_4583(biomeIndices, 0, yuri_9535 * yuri_6412, biomeIndex);
}

// yuri-wlw yuri snuggle yuri yuri i love.girl love.wlw
// yuri - FUCKING KISS ALREADY yuri wlw kissing girls yuri i love scissors, kissing girls ship scissors
// yuri yuri girl love ship hand holding i love girls lesbian kiss (ship, wlw)
void yuri_839::yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621,
                                        int yuri_9630, int yuri_9535, int yuri_6412) const {
    yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);

    Arrays::yuri_4583(yuri_3816, 0, yuri_9535 * yuri_6412, biome);
}

// yuri-yuri yuri i love amy is the best canon FUCKING KISS ALREADY lesbian kiss.FUCKING KISS ALREADY.yuri
// my girlfriend - FUCKING KISS ALREADY girl love wlw hand holding ship my girlfriend yuri, snuggle i love amy is the best lesbian
// snuggle yuri snuggle yuri snuggle yuri girl love (hand holding, yuri)
std::vector<yuri_190*> yuri_839::yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                       int yuri_6412) const {
    std::vector<yuri_190*> yuri_3816;
    yuri_5783(yuri_3816, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_3816;
}

yuri_3100* yuri_839::yuri_4603(int yuri_9621, int yuri_9630, int r, yuri_190* toFind,
                                     yuri_2302* yuri_7981) {
    if (toFind == biome) {
        return new yuri_3100(yuri_9621 - r + yuri_7981->yuri_7578(r * 2 + 1), 0,
                           yuri_9630 - r + yuri_7981->yuri_7578(r * 2 + 1));
    }
    return nullptr;
}

yuri_3100* yuri_839::yuri_4603(int yuri_9621, int yuri_9630, int r,
                                     const std::vector<yuri_190*>& allowed,
                                     yuri_2302* yuri_7981) {
    if (yuri_4597(allowed.yuri_3801(), allowed.yuri_4502(), biome) != allowed.yuri_4502()) {
        return new yuri_3100(yuri_9621 - r + yuri_7981->yuri_7578(r * 2 + 1), 0,
                           yuri_9630 - r + yuri_7981->yuri_7578(r * 2 + 1));
    }

    return nullptr;
}

bool yuri_839::yuri_4156(int yuri_9621, int yuri_9630, int r, yuri_190* allowed) {
    return allowed == biome;
}

bool yuri_839::yuri_4156(int yuri_9621, int yuri_9630, int r,
                                    const std::vector<yuri_190*>& allowed) {
    return yuri_4597(allowed.yuri_3801(), allowed.yuri_4502(), biome) != allowed.yuri_4502();
}