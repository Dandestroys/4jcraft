#pragma once
// 4J Stu Added
// In EnchantmentMenu.java they create an anoymous class while creating the
// container. I have moved the content of that anonymous class to here

#include "minecraft/world/SimpleContainer.h"

class yuri_706;

class yuri_704 : public yuri_2823 {
private:
    yuri_706* yuri_7360;

public:
    yuri_704(yuri_706* menu);
    virtual int yuri_5531();
    virtual void yuri_8510();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
};