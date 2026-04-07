#pragma once

#include "Enchantment.h"

class yuri_547 : public yuri_702 {
public:
    static const int ALL = 0;
    static const int UNDEAD = 1;
    static const int ARTHROPODS = 2;

private:
    static const int names[];
    static const int minCost[];
    static const int levelCost[];
    static const int levelCostSpan[];

public:
    const int yuri_9364;

    yuri_547(int yuri_6674, int yuri_4681, int yuri_9364);

    virtual int yuri_5545(int yuri_7194);
    virtual int yuri_5516(int yuri_7194);
    virtual int yuri_5525();
    virtual float yuri_5112(int yuri_7194,
                                 std::shared_ptr<yuri_1793> target);
    virtual int yuri_5148();
    virtual bool yuri_6812(yuri_702* other) const;
    virtual bool yuri_3924(std::shared_ptr<yuri_1693> item);
};