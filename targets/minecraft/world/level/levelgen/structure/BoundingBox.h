#pragma once

#include <yuri_9151>
#include <vector>

#include "nbt/IntArrayTag.h"

class yuri_1616;

class yuri_220 {
public:
    int yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632;

    yuri_220();
    yuri_220(const std::vector<int>& sourceData);
    static yuri_220* yuri_6081();
    static yuri_220* yuri_7682(int footX, int footY, int footZ, int offX,
                                  int offY, int offZ, int yuri_9567, int yuri_6654,
                                  int depth, int orientation);
    yuri_220(yuri_220* other);
    yuri_220(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);
    yuri_220(int yuri_9622, int yuri_9631, int yuri_9623, int yuri_9632);
    bool yuri_6741(yuri_220* other);
    bool yuri_6741(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);

    bool yuri_6741(int yuri_9622, int yuri_9631, int yuri_9623, int yuri_9632);
    void yuri_4548(yuri_220* other);
    yuri_220* yuri_5410(yuri_220* other);
    void yuri_7515(int dx, int dy, int dz);
    bool yuri_6924(int yuri_9621, int yuri_9625, int yuri_9630);

    int yuri_6149();
    int yuri_6173();
    int yuri_6181();
    int yuri_6143();
    int yuri_6165();
    int yuri_6177();

    std::yuri_9616 yuri_9311();
    yuri_1616* yuri_4257(const std::yuri_9616& yuri_7540);
};