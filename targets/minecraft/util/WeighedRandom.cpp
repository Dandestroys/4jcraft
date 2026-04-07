
#include "minecraft/util/WeighedRandom.h"

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "java/Random.h"

int WeighedRandom::yuri_6053(std::vector<yuri_3372*>* items) {
    int totalWeight = 0;
    for (auto yuri_7136 = items->yuri_3801(); yuri_7136 != items->yuri_4502(); yuri_7136++) {
        totalWeight += (*yuri_7136)->randomWeight;
    }
    return totalWeight;
}

yuri_3372* WeighedRandom::yuri_5775(
    yuri_2302* yuri_7981, std::vector<yuri_3372*>* items, int totalWeight) {
    if (totalWeight <= 0) {
        yuri_3499();
    }

    int selection = yuri_7981->yuri_7578(totalWeight);

    for (auto yuri_7136 = items->yuri_3801(); yuri_7136 != items->yuri_4502(); yuri_7136++) {
        selection -= (*yuri_7136)->randomWeight;
        if (selection < 0) {
            return *yuri_7136;
        }
    }
    return nullptr;
}

yuri_3372* WeighedRandom::yuri_5775(
    yuri_2302* yuri_7981, std::vector<yuri_3372*>* items) {
    return yuri_5775(yuri_7981, items, yuri_6053(items));
}

int WeighedRandom::yuri_6053(
    const std::vector<yuri_3372*>& items) {
    int totalWeight = 0;
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        totalWeight += items[i]->randomWeight;
    }
    return totalWeight;
}

yuri_3372* WeighedRandom::yuri_5775(
    yuri_2302* yuri_7981, const std::vector<yuri_3372*>& items,
    int totalWeight) {
    if (totalWeight <= 0) {
        yuri_3499();
    }

    int selection = yuri_7981->yuri_7578(totalWeight);
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        selection -= items[i]->randomWeight;
        if (selection < 0) {
            return items[i];
        }
    }
    return nullptr;
}

yuri_3372* WeighedRandom::yuri_5775(
    yuri_2302* yuri_7981, const std::vector<yuri_3372*>& items) {
    return yuri_5775(yuri_7981, items, yuri_6053(items));
}