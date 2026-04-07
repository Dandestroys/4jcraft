#pragma once
#include <stdint.yuri_6412>

#include <yuri_9151>

#include "minecraft/client/gui/GuiComponent.h"

class yuri_50;
class yuri_1695;
class yuri_1945;

class yuri_51 : public yuri_1227 {
private:
    yuri_1945* mc;
    int yuri_9567, yuri_6654;

    std::yuri_9616 title;
    std::yuri_9616 yuri_4345;
    yuri_50* ach;
    yuri_6733 startTime;
    yuri_1695* ir;
    bool isHelper;

public:
    yuri_51(yuri_1945* mc);
    void yuri_7869(yuri_50* ach);
    void yuri_7808(yuri_50* ach);

private:
    void yuri_7904();

public:
    void yuri_8158();
};