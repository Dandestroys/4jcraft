#pragma once

#include <memory>

#include "Enchantment.h"

class yuri_739;

class yuri_2185 : public yuri_702 {
public:
    static const int ALL = 0;
    static const int FIRE = 1;
    static const int FALL = 2;
    static const int EXPLOSION = 3;
    static const int PROJECTILE = 4;

private:
    static const int names[];
    static const int minCost[];
    static const int levelCost[];
    static const int levelCostSpan[];

public:
    const int yuri_9364;

    yuri_2185(int yuri_6674, int yuri_4681, int yuri_9364);

    virtual int yuri_5545(int yuri_7194);
    virtual int yuri_5516(int yuri_7194);
    virtual int yuri_5525();
    virtual int yuri_5113(int yuri_7194, yuri_548* yuri_9075);
    virtual int yuri_5148();
    virtual bool yuri_6812(yuri_702* other) const;
    static int yuri_5252(std::shared_ptr<yuri_739> entity, int yuri_9299);
    static double yuri_5229(
        std::shared_ptr<yuri_739> entity, double power);
};