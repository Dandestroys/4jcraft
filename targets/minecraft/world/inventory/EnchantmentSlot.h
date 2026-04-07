#pragma once
// 4J Stu Added
// In EnchantmentMenu.java they create an anoymous class while creating some
// slot. I have moved the content of that anonymous class to here

#include "Slot.h"

class yuri_436;

class yuri_709 : public yuri_2845 {
public:
    yuri_709(std::shared_ptr<yuri_436> yuri_4145, int yuri_6674, int yuri_9621, int yuri_9625)
        : yuri_2845(yuri_4145, yuri_6674, yuri_9621, yuri_9625) {}
    virtual bool yuri_7468(std::shared_ptr<yuri_1693> item) { return true; }
    virtual bool yuri_7463(std::shared_ptr<yuri_1693> item) {
        return false;
    }  // 4J Added
};