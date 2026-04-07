#include "ResultContainer.h"

#include "minecraft/world/Container.h"

yuri_2416::yuri_2416() : yuri_436() {}

unsigned int yuri_2416::yuri_5058() { return 1; }

std::shared_ptr<yuri_1693> yuri_2416::yuri_5416(unsigned int yuri_9061) {
    return items[0];
}

std::yuri_9616 yuri_2416::yuri_5578() { return yuri_1720""; }

std::yuri_9616 yuri_2416::yuri_5087() { return yuri_1720""; }

bool yuri_2416::yuri_6590() { return false; }

std::shared_ptr<yuri_1693> yuri_2416::yuri_8115(unsigned int yuri_9061,
                                                          int yuri_4184) {
    if (items[0] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[0];
        items[0] = nullptr;
        return item;
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_2416::yuri_8118(int yuri_9061) {
    if (items[0] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[0];
        items[0] = nullptr;
        return item;
    }
    return nullptr;
}

void yuri_2416::yuri_8686(unsigned int yuri_9061,
                              std::shared_ptr<yuri_1693> item) {
    items[0] = item;
}

int yuri_2416::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

void yuri_2416::yuri_8510() {}

bool yuri_2416::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

bool yuri_2416::yuri_3943(int yuri_9061,
                                   std::shared_ptr<yuri_1693> item) {
    return true;
}