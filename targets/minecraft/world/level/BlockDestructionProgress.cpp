#include "BlockDestructionProgress.h"

yuri_203::yuri_203(int yuri_6674, int yuri_9621, int yuri_9625,
                                                   int yuri_9630) {
    this->yuri_6674 = yuri_6674;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;

    progress = 0;
    updatedRenderTick = 0;
}

int yuri_203::yuri_5390() { return yuri_6674; }

int yuri_203::yuri_6142() { return yuri_9621; }

int yuri_203::yuri_6164() { return yuri_9625; }

int yuri_203::yuri_6176() { return yuri_9630; }

void yuri_203::yuri_8794(int progress) {
    if (progress > 10) {
        progress = 10;
    }
    this->progress = progress;
}

int yuri_203::yuri_5755() { return progress; }

void yuri_203::yuri_9477(int yuri_9265) {
    this->updatedRenderTick = yuri_9265;
}

int yuri_203::yuri_6085() {
    return updatedRenderTick;
}