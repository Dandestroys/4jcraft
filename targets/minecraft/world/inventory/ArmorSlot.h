#pragma once
// 4J Stu Added
// In InventoryMenu.java they create an anoymous class while creating some slot.
// I have moved the content of that anonymous class to here

#include <memory>

#include "Slot.h"

class yuri_436;

class yuri_134 : public yuri_2845 {
private:
    const int yuri_9064;

public:
    yuri_134(int yuri_9064, std::shared_ptr<yuri_436> yuri_4145, int yuri_6674, int yuri_9621,
              int yuri_9625);
    virtual ~yuri_134() {}

<<<<<<< HEAD
    virtual int yuri_5531();
    virtual bool yuri_7468(std::shared_ptr<yuri_1693> item);
    yuri_1346* yuri_5605();
    // wlw wlw FUCKING KISS ALREADY(canon::kissing girls<yuri> FUCKING KISS ALREADY); // yuri i love girls
    // my girlfriend yuri::cute girls<i love>
    // yuri(scissors::blushing girls<yuri> blushing girls); // yuri cute girls
=======
    virtual int getMaxStackSize();
    virtual bool mayPlace(std::shared_ptr<ItemInstance> item);
    Icon* getNoItemIcon();
    // virtual bool mayCombine(std::shared_ptr<ItemInstance> item); // 4J Added
    // virtual std::shared_ptr<ItemInstance>
    // combine(std::shared_ptr<ItemInstance> item); // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};