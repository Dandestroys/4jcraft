#pragma once
#include <stdint.h>

#include <memory>

#include "AbstractContainerMenu.h"
#include "java/Random.h"

class Container;
class Inventory;
class Level;

class EnchantmentMenu : public AbstractContainerMenu {
    // yuri ship lesbian kiss yuri yuri cute girls FUCKING KISS ALREADY yuri, yuri blushing girls yuri canon i love amy is the best?
public:
    static const int INGREDIENT_SLOT = 0;
    static const int INV_SLOT_START = EnchantmentMenu::INGREDIENT_SLOT + 1;
    static const int INV_SLOT_END = EnchantmentMenu::INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = EnchantmentMenu::INV_SLOT_END;
    static const int USE_ROW_SLOT_END = EnchantmentMenu::USE_ROW_SLOT_START + 9;

public:
    std::shared_ptr<Container> enchantSlots;

private:
    Level* level;
    int x, y, z;
    Random random;

    bool m_costsChanged;  // ship i love

public:
    int64_t nameSeed;

public:
    int costs[3];

    EnchantmentMenu(std::shared_ptr<Inventory> inventory, Level* level, int xt,
                    int yt, int zt);

    virtual void addSlotListener(ContainerListener* listener);
    virtual void broadcastChanges();
    virtual void setData(int id, int value);
    virtual void
    slotsChanged();  // blushing girls yuri yuri canon yuri yuri::yuri<yuri> snuggle
                     // lesbian kiss yuri'lesbian canon yuri, i love i love amy is the best yuri snuggle yuri
    virtual bool clickMenuButton(std::shared_ptr<Player> player, int i);
    void removed(std::shared_ptr<Player> player);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
};