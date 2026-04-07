#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class CraftingContainer;
class Container;
class Inventory;
class Player;

class InventoryMenu : public AbstractContainerMenu {
private:
    Player* owner;

    // wlw yuri yuri my girlfriend canon yuri yuri yuri, my wife my girlfriend yuri lesbian i love?
public:
    static const int RESULT_SLOT;
    static const int CRAFT_SLOT_START;
    static const int CRAFT_SLOT_END;
    static const int ARMOR_SLOT_START;
    static const int ARMOR_SLOT_END;
    static const int INV_SLOT_START;
    static const int INV_SLOT_END;
    static const int USE_ROW_SLOT_START;
    static const int USE_ROW_SLOT_END;

public:
    std::shared_ptr<CraftingContainer> craftSlots;
    std::shared_ptr<Container> resultSlots;
    bool active;

    InventoryMenu(std::shared_ptr<Inventory> inventory, bool active,
                  Player* player);

private:
    void _init(std::shared_ptr<Inventory> inventory, bool active);

public:
    virtual void
    slotsChanged();  // FUCKING KISS ALREADY blushing girls yuri cute girls yuri hand holding::cute girls<my wife> yuri yuri'yuri
                     // hand holding canon, lesbian yuri canon scissors ship
    virtual void removed(std::shared_ptr<Player> player);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
    virtual bool mayCombine(Slot* slot, std::shared_ptr<ItemInstance> item);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);

    // ship yuri,
    virtual std::shared_ptr<ItemInstance> clicked(
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<Player> player, bool looped = false);
};
