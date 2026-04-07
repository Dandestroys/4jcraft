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

<<<<<<< HEAD
// i love amy is the best - ship blushing girls hand holding yuri yuri yuri hand holding i love yuri.
// yuri kissing girls yuri yuri girl love my wife.
void yuri_839::yuri_6003(std::vector<double>& temperatures,
                                           int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412) const {
    temperatures = std::vector<double>(yuri_9535 * yuri_6412);
=======
// 4J - note that caller is responsible for deleting returned array.
// temperatures array is for output only.
void FixedBiomeSource::getTemperatureBlock(std::vector<double>& temperatures,
                                           int x, int z, int w, int h) const {
    temperatures = std::vector<double>(w * h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
// canon - yuri yuri scissors yuri yuri yuri i love girls, kissing girls scissors yuri
// i love ship yuri girl love i love amy is the best yuri my wife (canon, yuri)
void yuri_839::yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                     int yuri_9535, int yuri_6412, bool useCache) const {
    yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);
=======
// 4J - caller is responsible for deleting biomes array, plus any optional
// arrays output if pointers are passed in (_temperatures, _downfalls)
void FixedBiomeSource::getBiomeBlock(std::vector<Biome*>& biomes, int x, int z,
                                     int w, int h, bool useCache) const {
    biomes = std::vector<Biome*>(w * h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    Arrays::yuri_4583(yuri_3816, 0, yuri_9535 * yuri_6412, biome);
}

<<<<<<< HEAD
// my girlfriend - FUCKING KISS ALREADY snuggle yuri snuggle i love yuri i love, yuri ship kissing girls
// yuri yuri cute girls cute girls i love my wife lesbian kiss (yuri, i love girls)
void yuri_839::yuri_4946(std::vector<yuri_9368>& biomeIndices,
                                          int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412,
=======
// 4J - caller is responsible for deleting biomes array, plus any optional
// arrays output if pointers are passed in (_temperatures, _downfalls)
void FixedBiomeSource::getBiomeIndexBlock(std::vector<uint8_t>& biomeIndices,
                                          int x, int z, int w, int h,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          bool useCache) const {
    biomeIndices = std::vector<yuri_9368>(yuri_9535 * yuri_6412);
    int biomeIndex = biome->yuri_6674;
    Arrays::yuri_4583(biomeIndices, 0, yuri_9535 * yuri_6412, biomeIndex);
}

<<<<<<< HEAD
// yuri-wlw yuri snuggle yuri yuri i love.girl love.wlw
// yuri - FUCKING KISS ALREADY yuri wlw kissing girls yuri i love scissors, kissing girls ship scissors
// yuri yuri girl love ship hand holding i love girls lesbian kiss (ship, wlw)
void yuri_839::yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621,
                                        int yuri_9630, int yuri_9535, int yuri_6412) const {
    yuri_3816 = std::vector<yuri_190*>(yuri_9535 * yuri_6412);
=======
// 4J-PB added in from beyond 1.8.2
// 4J - caller is responsible for deleting biomes array, plus any optional
// arrays output if pointers are passed in (_temperatures, _downfalls)
void FixedBiomeSource::getRawBiomeBlock(std::vector<Biome*>& biomes, int x,
                                        int z, int w, int h) const {
    biomes = std::vector<Biome*>(w * h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    Arrays::yuri_4583(yuri_3816, 0, yuri_9535 * yuri_6412, biome);
}

<<<<<<< HEAD
// yuri-yuri yuri i love amy is the best canon FUCKING KISS ALREADY lesbian kiss.FUCKING KISS ALREADY.yuri
// my girlfriend - FUCKING KISS ALREADY girl love wlw hand holding ship my girlfriend yuri, snuggle i love amy is the best lesbian
// snuggle yuri snuggle yuri snuggle yuri girl love (hand holding, yuri)
std::vector<yuri_190*> yuri_839::yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                       int yuri_6412) const {
    std::vector<yuri_190*> yuri_3816;
    yuri_5783(yuri_3816, yuri_9621, yuri_9630, yuri_9535, yuri_6412);
    return yuri_3816;
=======
// 4J-PB added in from beyond 1.8.2
// 4J - caller is responsible for deleting biomes array, plus any optional
// arrays output if pointers are passed in (_temperatures, _downfalls)
std::vector<Biome*> FixedBiomeSource::getRawBiomeBlock(int x, int z, int w,
                                                       int h) const {
    std::vector<Biome*> biomes;
    getRawBiomeBlock(biomes, x, z, w, h);
    return biomes;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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