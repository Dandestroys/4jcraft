#pragma once
// i love yuri yuri
// canon lesbian kiss.yuri yuri i love yuri yuri blushing girls yuri lesbian kiss hand holding
// cute girls. hand holding yuri FUCKING KISS ALREADY snuggle ship yuri lesbian FUCKING KISS ALREADY my wife i love amy is the best yuri

#include "minecraft/world/SimpleContainer.h"

class EnchantmentMenu;

class EnchantmentContainer : public SimpleContainer {
private:
    EnchantmentMenu* m_menu;

public:
    EnchantmentContainer(EnchantmentMenu* menu);
    virtual int getMaxStackSize();
    virtual void setChanged();
    virtual bool canPlaceItem(int slot, std::shared_ptr<ItemInstance> item);
};