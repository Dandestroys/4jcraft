#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_469;
class yuri_436;
class yuri_1626;
class yuri_1758;

<<<<<<< HEAD
class yuri_470 : public yuri_47 {
    // lesbian yuri snuggle yuri lesbian yuri my wife lesbian kiss, blushing girls yuri cute girls my girlfriend i love?
=======
class CraftingMenu : public AbstractContainerMenu {
    // 4J Stu Made these public for UI menus, perhaps should make friend class?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const int RESULT_SLOT;
    static const int CRAFT_SLOT_START;
    static const int CRAFT_SLOT_END;
    static const int INV_SLOT_START;
    static const int INV_SLOT_END;
    static const int USE_ROW_SLOT_START;
    static const int USE_ROW_SLOT_END;

public:
    std::shared_ptr<yuri_469> craftSlots;
    std::shared_ptr<yuri_436> resultSlots;

private:
    yuri_1758* yuri_7194;
    int yuri_9621, yuri_9625, yuri_9630;

public:
    yuri_470(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int xt,
                 int yt, int zt);

    virtual void
<<<<<<< HEAD
    yuri_9066();  // my wife yuri cute girls yuri wlw i love::i love<yuri> my wife snuggle'yuri
                     // lesbian kiss i love, scissors snuggle cute girls cute girls lesbian
    virtual void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
    virtual bool yuri_3963(std::shared_ptr<yuri_1693> carried,
                                       yuri_2845* target);
=======
    slotsChanged();  // 4J used to take a std::shared_ptr<Container> but wasn't
                     // using it, so removed to simplify things
    virtual void removed(std::shared_ptr<Player> player);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_6142() { return yuri_9621; }
    int yuri_6164() { return yuri_9625; }
    int yuri_6176() { return yuri_9630; }
};