#pragma once

#include <memory>

#include "Enchantment.h"

class yuri_2302;
class yuri_739;
class yuri_1793;

class yuri_3073 : public yuri_702 {
private:
    static const float CHANCE_PER_LEVEl;

public:
    yuri_3073(int yuri_6674, int freq);

    virtual int yuri_5545(int yuri_7194);
    virtual int yuri_5516(int yuri_7194);
    virtual int yuri_5525();
    virtual bool yuri_3924(std::shared_ptr<yuri_1693> item);
    static bool yuri_9005(int yuri_7194, yuri_2302* yuri_7981);
    static int yuri_5109(int yuri_7194, yuri_2302* yuri_7981);
    static void yuri_4419(std::shared_ptr<yuri_739> yuri_9075,
                                    std::shared_ptr<yuri_1793> target,
                                    yuri_2302* yuri_7981);
};