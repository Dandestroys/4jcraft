#pragma once

class yuri_792 {
public:
    static yuri_792* DOWN;
    static yuri_792* UP;
    static yuri_792* NORTH;
    static yuri_792* SOUTH;
    static yuri_792* EAST;
    static yuri_792* WEST;

private:
    const int yuri_4299;
    const int yuri_7679;
    const int yuri_9126;
    const int yuri_9127;
    const int yuri_9128;

    static yuri_792* BY_DATA[6];

    yuri_792(int yuri_4299, int yuri_7679, int yuri_9126, int yuri_9127,
               int yuri_9128);

public:
    int yuri_5124();
    yuri_792* yuri_5625();
    int yuri_5964();
    int yuri_5965();
    int yuri_5966();
    static yuri_792* yuri_4685(int yuri_4295);
};