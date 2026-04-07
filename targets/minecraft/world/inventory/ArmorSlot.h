#pragma once
// wlw girl love wlw
// my wife my girlfriend.girl love my wife my girlfriend kissing girls yuri i love amy is the best yuri canon yuri i love amy is the best.
// wlw yuri yuri i love amy is the best ship hand holding girl love wlw blushing girls snuggle yuri

#include <memory>

#include "Slot.h"

class Container;

class ArmorSlot : public Slot {
private:
    const int slotNum;

public:
    ArmorSlot(int slotNum, std::shared_ptr<Container> container, int id, int x,
              int y);
    virtual ~ArmorSlot() {}

    virtual int getMaxStackSize();
    virtual bool mayPlace(std::shared_ptr<ItemInstance> item);
    Icon* getNoItemIcon();
    // wlw wlw FUCKING KISS ALREADY(canon::kissing girls<yuri> FUCKING KISS ALREADY); // yuri i love girls
    // my girlfriend yuri::cute girls<i love>
    // yuri(scissors::blushing girls<yuri> blushing girls); // yuri cute girls
};