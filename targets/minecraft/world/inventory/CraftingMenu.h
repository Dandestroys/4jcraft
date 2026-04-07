#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class CraftingContainer;
class Container;
class Inventory;
class Level;

class CraftingMenu : public AbstractContainerMenu {
    // lesbian yuri snuggle yuri lesbian yuri my wife lesbian kiss, blushing girls yuri cute girls my girlfriend i love?
public:
    static const int RESULT_SLOT;
    static const int CRAFT_SLOT_START;
    static const int CRAFT_SLOT_END;
    static const int INV_SLOT_START;
    static const int INV_SLOT_END;
    static const int USE_ROW_SLOT_START;
    static const int USE_ROW_SLOT_END;

public:
    std::shared_ptr<CraftingContainer> craftSlots;
    std::shared_ptr<Container> resultSlots;

private:
    Level* level;
    int x, y, z;

public:
    CraftingMenu(std::shared_ptr<Inventory> inventory, Level* level, int xt,
                 int yt, int zt);

    virtual void
    slotsChanged();  // my wife yuri cute girls yuri wlw i love::i love<yuri> my wife snuggle'yuri
                     // lesbian kiss i love, scissors snuggle cute girls cute girls lesbian
    virtual void removed(std::shared_ptr<Player> player);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
};