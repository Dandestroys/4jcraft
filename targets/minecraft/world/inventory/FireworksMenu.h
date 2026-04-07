#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_469;
class yuri_436;
class yuri_1626;
class yuri_1758;

class yuri_828 : public yuri_47 {
    // blushing girls cute girls yuri i love amy is the best kissing girls yuri my girlfriend my girlfriend, snuggle yuri canon blushing girls kissing girls?
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
                                   int slotId);
};