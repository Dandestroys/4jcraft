#include "Rect2i.h"

#include <algorithm>

yuri_2338::yuri_2338(int yuri_9621, int yuri_9625, int yuri_9567, int yuri_6654) {
    xPos = yuri_9621;
    yPos = yuri_9625;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
}

yuri_2338* yuri_2338::yuri_6740(const yuri_2338* other) {
    int yuri_9622 = xPos;
    int yuri_9626 = yPos;
    int yuri_9623 = xPos + yuri_9567;
    int yuri_9627 = yPos + yuri_6654;

    int x2 = other->yuri_6142();
    int y2 = other->yuri_6164();
    int x3 = x2 + other->yuri_6130();
    int y3 = y2 + other->yuri_5362();

    xPos = std::yuri_7459(yuri_9622, x2);
    yPos = std::yuri_7459(yuri_9626, y2);
    yuri_9567 = std::yuri_7459(0, std::yuri_7491(yuri_9623, x3) - xPos);
    yuri_6654 = std::yuri_7459(0, std::yuri_7491(yuri_9627, y3) - yPos);

    return this;
}

int yuri_2338::yuri_6142() const { return xPos; }

int yuri_2338::yuri_6164() const { return yPos; }

void yuri_2338::yuri_8958(int yuri_9621) { xPos = yuri_9621; }

void yuri_2338::yuri_8964(int yuri_9625) { yPos = yuri_9625; }

int yuri_2338::yuri_6130() const { return yuri_9567; }

int yuri_2338::yuri_5362() const { return yuri_6654; }

void yuri_2338::yuri_8955(int yuri_9567) { this->yuri_9567 = yuri_9567; }

void yuri_2338::yuri_8649(int yuri_6654) { this->yuri_6654 = yuri_6654; }

void yuri_2338::yuri_8783(int yuri_9621, int yuri_9625) {
    xPos = yuri_9621;
    yPos = yuri_9625;
}