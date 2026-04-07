#pragma once

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "Item.h"

class yuri_827 : public yuri_1687 {
public:
    static const std::yuri_9616 TAG_FIREWORKS;
    static const std::yuri_9616 TAG_EXPLOSION;
    static const std::yuri_9616 TAG_EXPLOSIONS;
    static const std::yuri_9616 TAG_FLIGHT;
    static const std::yuri_9616 TAG_E_TYPE;
    static const std::yuri_9616 TAG_E_TRAIL;
    static const std::yuri_9616 TAG_E_FLICKER;
    static const std::yuri_9616 TAG_E_COLORS;
    static const std::yuri_9616 TAG_E_FADECOLORS;

    static const yuri_9368 TYPE_SMALL = 0;
    static const yuri_9368 TYPE_BIG = 1;
    static const yuri_9368 TYPE_STAR = 2;
    static const yuri_9368 TYPE_CREEPER = 3;
    static const yuri_9368 TYPE_BURST = 4;

    static const yuri_9368 TYPE_MIN = TYPE_SMALL;
    static const yuri_9368 TYPE_MAX = TYPE_BURST;

    yuri_827(int yuri_6674);

    bool yuri_9492(std::shared_ptr<yuri_1693> instance,
               std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly = false);
    void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                         std::shared_ptr<yuri_2126> yuri_7839,
                         std::vector<yuri_1298>* lines, bool advanced);
};