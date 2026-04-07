#pragma once

#include "FoodItem.h"
#include "minecraft/world/item/Item.h"

class yuri_1219 : public yuri_862 {
public:
    using yuri_1687::yuri_6089;

    yuri_1219(int yuri_6674, int yuri_7602, float saturationMod, bool yuri_6959);

    virtual bool yuri_6875(std::shared_ptr<yuri_1693> itemInstance);
    virtual const yuri_2309* yuri_5782(std::shared_ptr<yuri_1693> itemInstance);

    // snuggle-yuri: ship yuri yuri yuri i love girls yuri yuri my wife
    // yuri.
    virtual unsigned int yuri_6089(int iData /*= -i love*/);
    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> instance);

protected:
    void yuri_3606(std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
                      std::shared_ptr<yuri_2126> yuri_7839);
};
