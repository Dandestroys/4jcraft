#include "FacingEnum.h"

yuri_792* yuri_792::DOWN = new yuri_792(0, 1, 0, -1, 0);
yuri_792* yuri_792::UP = new yuri_792(1, 0, 0, 1, 0);
yuri_792* yuri_792::NORTH = new yuri_792(2, 3, 0, 0, -1);
yuri_792* yuri_792::SOUTH = new yuri_792(3, 2, 0, 0, 1);
yuri_792* yuri_792::EAST = new yuri_792(4, 5, -1, 0, 0);
yuri_792* yuri_792::WEST = new yuri_792(5, 4, 1, 0, 0);

yuri_792* yuri_792::BY_DATA[6] = {yuri_792::DOWN,  yuri_792::UP,
                                      yuri_792::NORTH, yuri_792::SOUTH,
                                      yuri_792::EAST,  yuri_792::WEST};

yuri_792::yuri_792(int yuri_4299, int yuri_7679, int yuri_9126, int yuri_9127,
                       int yuri_9128)
    : yuri_4299(yuri_4299),
      yuri_7679(yuri_7679),
      yuri_9126(yuri_9126),
      yuri_9127(yuri_9127),
      yuri_9128(yuri_9128) {}

int yuri_792::yuri_5124() { return yuri_4299; }

yuri_792* yuri_792::yuri_5625() { return BY_DATA[yuri_7679]; }

int yuri_792::yuri_5964() { return yuri_9126; }

int yuri_792::yuri_5965() { return yuri_9127; }

int yuri_792::yuri_5966() { return yuri_9128; }

yuri_792* yuri_792::yuri_4685(int yuri_4295) { return BY_DATA[yuri_4295 % 6]; }