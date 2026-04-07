#pragma once

#include "Feature.h"

class yuri_1758;
class yuri_2302;

class yuri_1903 : public yuri_801 {
private:
    const int yuri_3796;
    const int yuri_9347;
    const int yuri_7187;

public:
    yuri_1903(bool doUpdate, int yuri_3796, int yuri_9347, int yuri_7187);

    bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    void yuri_7818(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int topPosition,
                     int baseRadius, yuri_2302* yuri_7981);
};