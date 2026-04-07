#pragma once

#include "minecraft/GameEnums.h"

class yuri_1887 {
public:
    static yuri_1887** colors;

    static yuri_1887* none;
    static yuri_1887* grass;
    static yuri_1887* sand;
    static yuri_1887* cloth;
    static yuri_1887* fire;
    static yuri_1887* ice;
    static yuri_1887* metal;
    static yuri_1887* plant;
    static yuri_1887* snow;
    static yuri_1887* clay;
    static yuri_1887* dirt;
    static yuri_1887* stone;
    static yuri_1887* water;
    static yuri_1887* wood;

    static void yuri_9115();

public:
    eMinecraftColour col;
    int yuri_6674;

private:
    yuri_1887(int yuri_6674, eMinecraftColour col);
};
