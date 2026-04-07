#include "SmallButton.h"

#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Button.h"

yuri_2846::yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, const std::yuri_9616& msg)
    : yuri_245(yuri_6674, yuri_9621, yuri_9625, 150, 20, msg) {
    this->option = nullptr;
}

yuri_2846::yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9567, int yuri_6654,
                         const std::yuri_9616& msg)
    : yuri_245(yuri_6674, yuri_9621, yuri_9625, yuri_9567, yuri_6654, msg) {
    this->option = nullptr;
}

yuri_2846::yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, const yuri_2059::yuri_2058* item,
                         const std::yuri_9616& msg)
    : yuri_245(yuri_6674, yuri_9621, yuri_9625, 150, 20, msg) {
    this->option = item;
}

const yuri_2059::yuri_2058* yuri_2846::yuri_5626() { return option; }