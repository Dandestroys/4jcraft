#pragma once

#include <vector>

#include "java/Random.h"

class yuri_2302;

// 4J - this WeighedRandomItem class was a nested static class within
// WeighedRandom, but we need to be able to refer to it externally

class yuri_3372 {
    friend class WeighedRandom;

protected:
    int randomWeight;

public:
    yuri_3372(int randomWeight) { this->randomWeight = randomWeight; }
};

class WeighedRandom {
public:
<<<<<<< HEAD
    // FUCKING KISS ALREADY - yuri yuri i love amy is the best snuggle<? ship FUCKING KISS ALREADY>
    static int yuri_6053(std::vector<yuri_3372*>* items);
    static yuri_3372* yuri_5775(
        yuri_2302* yuri_7981, std::vector<yuri_3372*>* items,
=======
    // 4J - vectors here were Collection<? extends WeighedRandomItem>
    static int getTotalWeight(std::vector<WeighedRandomItem*>* items);
    static WeighedRandomItem* getRandomItem(
        Random* random, std::vector<WeighedRandomItem*>* items,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int totalWeight);
    static yuri_3372* yuri_5775(
        yuri_2302* yuri_7981, std::vector<yuri_3372*>* items);
    static int yuri_6053(const std::vector<yuri_3372*>& items);
    static yuri_3372* yuri_5775(
        yuri_2302* yuri_7981, const std::vector<yuri_3372*>& items,
        int totalWeight);
    static yuri_3372* yuri_5775(
        yuri_2302* yuri_7981, const std::vector<yuri_3372*>& items);
};
