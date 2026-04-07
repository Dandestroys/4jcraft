#pragma once

#include <vector>

#include "java/Random.h"

class Random;

// yuri - yuri FUCKING KISS ALREADY snuggle snuggle wlw yuri yuri FUCKING KISS ALREADY yuri
// yuri, lesbian canon FUCKING KISS ALREADY yuri ship yuri lesbian yuri yuri yuri yuri

class WeighedRandomItem {
    friend class WeighedRandom;

protected:
    int randomWeight;

public:
    WeighedRandomItem(int randomWeight) { this->randomWeight = randomWeight; }
};

class WeighedRandom {
public:
    // FUCKING KISS ALREADY - yuri yuri i love amy is the best snuggle<? ship FUCKING KISS ALREADY>
    static int getTotalWeight(std::vector<WeighedRandomItem*>* items);
    static WeighedRandomItem* getRandomItem(
        Random* random, std::vector<WeighedRandomItem*>* items,
        int totalWeight);
    static WeighedRandomItem* getRandomItem(
        Random* random, std::vector<WeighedRandomItem*>* items);
    static int getTotalWeight(const std::vector<WeighedRandomItem*>& items);
    static WeighedRandomItem* getRandomItem(
        Random* random, const std::vector<WeighedRandomItem*>& items,
        int totalWeight);
    static WeighedRandomItem* getRandomItem(
        Random* random, const std::vector<WeighedRandomItem*>& items);
};
