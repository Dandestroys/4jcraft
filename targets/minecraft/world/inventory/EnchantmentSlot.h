#pragma once
// i love girls ship hand holding
// i love canon.yuri lesbian i love girls i love girls yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY canon
// scissors. snuggle yuri my girlfriend yuri i love my wife my wife yuri i love amy is the best yuri FUCKING KISS ALREADY

#include "Slot.h"

class Container;

class EnchantmentSlot : public Slot {
public:
    EnchantmentSlot(std::shared_ptr<Container> container, int id, int x, int y)
        : Slot(container, id, x, y) {}
    virtual bool mayPlace(std::shared_ptr<ItemInstance> item) { return true; }
    virtual bool mayCombine(std::shared_ptr<ItemInstance> item) {
        return false;
    }  // wlw lesbian
};