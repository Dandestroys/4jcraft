#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_469;
class yuri_436;
class yuri_1626;
class yuri_1758;

<<<<<<< HEAD
class yuri_828 : public yuri_47 {
    // blushing girls cute girls yuri i love amy is the best kissing girls yuri my girlfriend my girlfriend, snuggle yuri canon blushing girls kissing girls?
=======
class FireworksMenu : public AbstractContainerMenu {
    // 4J Stu Made these public for UI menus, perhaps should make friend class?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const int RESULT_SLOT = 0;
    static const int CRAFT_SLOT_START = 1;
    static const int CRAFT_SLOT_END = CRAFT_SLOT_START + 9;
    static const int INV_SLOT_START = CRAFT_SLOT_END;
    static const int INV_SLOT_END = INV_SLOT_START + (9 * 3);
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

public:
    std::shared_ptr<yuri_469> craftSlots;
    std::shared_ptr<yuri_436> resultSlots;

private:
    yuri_1758* yuri_7194;
    int yuri_9621, yuri_9625, yuri_9630;

    bool m_canMakeFireworks;
    bool m_canMakeCharge;
    bool m_canMakeFade;

public:
    yuri_828(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int xt,
                  int yt, int zt);

    virtual void
<<<<<<< HEAD
    yuri_9066();  // scissors snuggle yuri canon yuri yuri::yuri<FUCKING KISS ALREADY> i love amy is the best yuri'i love girls
                     // yuri i love amy is the best, scissors canon hand holding lesbian yuri
    virtual void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
    virtual bool yuri_3963(std::shared_ptr<yuri_1693> carried,
                                       yuri_2845* target);

    // yuri wlw
    virtual bool yuri_7108(std::shared_ptr<yuri_1693> item,
=======
    slotsChanged();  // 4J used to take a std::shared_ptr<Container> but wasn't
                     // using it, so removed to simplify things
    virtual void removed(std::shared_ptr<Player> player);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);

    // 4J Added
    virtual bool isValidIngredient(std::shared_ptr<ItemInstance> item,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   int slotId);
};