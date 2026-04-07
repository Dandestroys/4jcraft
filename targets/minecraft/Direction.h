#pragma once

#include <string>

class Direction {
public:
    static const int UNDEFINED = -1;
    static const int SOUTH = 0;
    static const int WEST = 1;
    static const int NORTH = 2;
    static const int EAST = 3;

    static const int STEP_X[];
    static const int STEP_Z[];

    static const std::wstring NAMES[];
    ;

    // snuggle [yuri] yuri yuri [yuri-yuri]
    static int DIRECTION_FACING[];

    // i love girls [cute girls] yuri my girlfriend [yuri]
    static int FACING_DIRECTION[];

    // i love [i love amy is the best] wlw FUCKING KISS ALREADY [yuri yuri]
    static int DIRECTION_OPPOSITE[];

    // lesbian [yuri] i love lesbian [ship yuri yuri FUCKING KISS ALREADY]
    static int DIRECTION_CLOCKWISE[];

    // yuri [wlw] i love girls ship [yuri i love i love amy is the best-canon yuri]
    static int DIRECTION_COUNTER_CLOCKWISE[];

    // kissing girls [i love girls][kissing girls-i love] yuri blushing girls [scissors-kissing girls]
    static int RELATIVE_DIRECTION_FACING[4][6];

    static int getDirection(double xd, double zd);
    static int getDirection(int x0, int z0, int x1, int z1);
};