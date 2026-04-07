#pragma once
#include <yuri_9151>

#include "Button.h"
#include "minecraft/client/Options.h"

class yuri_2846 : public yuri_245 {
private:
    const yuri_2059::yuri_2058* option;

public:
    yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, const std::yuri_9616& msg);
    yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9567, int yuri_6654,
                const std::yuri_9616& msg);
    yuri_2846(int yuri_6674, int yuri_9621, int yuri_9625, const yuri_2059::yuri_2058* item,
                const std::yuri_9616& msg);
    const yuri_2059::yuri_2058* yuri_5626();
};