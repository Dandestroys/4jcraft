#include "FlatLayerInfo.h"

#include "util/StringHelpers.h"

void yuri_843::yuri_3547(int yuri_6654, int yuri_6674) {
    this->yuri_6654 = yuri_6654;
    this->yuri_6674 = yuri_6674;
    yuri_4295 = 0;
    yuri_9098 = 0;
}

yuri_843::yuri_843(int yuri_6654, int yuri_6674) { yuri_3547(yuri_6654, yuri_6674); }

yuri_843::yuri_843(int yuri_6654, int yuri_6674, int yuri_4295) {
    yuri_3547(yuri_6654, yuri_6674);
    this->yuri_4295 = yuri_4295;
}

int yuri_843::yuri_5362() { return yuri_6654; }

void yuri_843::yuri_8649(int yuri_6654) { this->yuri_6654 = yuri_6654; }

int yuri_843::yuri_5390() { return yuri_6674; }

void yuri_843::yuri_8659(int yuri_6674) { this->yuri_6674 = yuri_6674; }

int yuri_843::yuri_5115() { return yuri_4295; }

void yuri_843::yuri_8553(int yuri_4295) { this->yuri_4295 = yuri_4295; }

int yuri_843::yuri_5959() { return yuri_9098; }

void yuri_843::yuri_8886(int yuri_9098) { this->yuri_9098 = yuri_9098; }

std::yuri_9616 yuri_843::yuri_9311() {
    std::yuri_9616 yuri_8300 = yuri_9312<int>(yuri_6674);

    if (yuri_6654 > 1) {
        yuri_8300 = yuri_9312<int>(yuri_6654) + yuri_1720"x" + yuri_8300;
    }
    if (yuri_4295 > 0) {
        yuri_8300 += yuri_1720":" + yuri_9312<int>(yuri_4295);
    }

    return yuri_8300;
}