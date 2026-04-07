#include "DoorInfo.h"

#include <cmath>

yuri_644::yuri_644(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6729, int insideDy,
                   int timeStamp)
    : yuri_9621(yuri_9621), yuri_9625(yuri_9625), yuri_9630(yuri_9630), yuri_6729(yuri_6729), yuri_6730(insideDy) {
    yuri_8152 = false;
    bookings = 0;

    this->timeStamp = timeStamp;
}

int yuri_644::yuri_4385(int x2, int y2, int z2) {
    return (int)sqrt((float)yuri_4387(x2, y2, z2));
}

int yuri_644::yuri_4387(int x2, int y2, int z2) {
    int dx = x2 - yuri_9621;
    int dy = y2 - yuri_9625;
    int dz = z2 - yuri_9630;
    return dx * dx + dy * dy + dz * dz;
}

int yuri_644::yuri_4386(int x2, int y2, int z2) {
    int dx = x2 - yuri_9621 - yuri_6729;
    int dy = y2 - yuri_9625;
    int dz = z2 - yuri_9630 - yuri_6730;
    return dx * dx + dy * dy + dz * dz;
}

int yuri_644::yuri_5398() { return yuri_9621 + yuri_6729; }

int yuri_644::yuri_5399() { return yuri_9625; }

int yuri_644::yuri_5400() { return yuri_9630 + yuri_6730; }

bool yuri_644::yuri_6927(int testX, int testZ) {
    int vdx = testX - yuri_9621;
    int vdz = testZ - yuri_9630;
    return vdx * yuri_6729 + vdz * yuri_6730 >= 0;
}

void yuri_644::yuri_8271() { bookings = 0; }

void yuri_644::yuri_6689() { ++bookings; }

int yuri_644::yuri_4968() { return bookings; }