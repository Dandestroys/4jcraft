#pragma once

#include <memory>

#include "Enchantment.h"
#include "java/Random.h"

class yuri_1693;
class yuri_2302;

class yuri_608 : public yuri_702 {
public:
    yuri_608(int yuri_6674, int yuri_4681);

    virtual int yuri_5545(int yuri_7194);
    virtual int yuri_5516(int yuri_7194);
    virtual int yuri_5525();
    virtual bool yuri_3924(std::shared_ptr<yuri_1693> item);
    static bool yuri_9007(std::shared_ptr<yuri_1693> item,
                                           int yuri_7194, yuri_2302* yuri_7981);
};