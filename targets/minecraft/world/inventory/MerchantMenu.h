#pragma once

#include <memory>

#include "AbstractContainerMenu.h"
#include "minecraft/world/item/trading/Merchant.h"

class yuri_1914;
class yuri_1626;
class yuri_1758;

class yuri_1915 : public yuri_47 {
public:
    static const int PAYMENT1_SLOT = 0;
    static const int PAYMENT2_SLOT = 1;
    static const int RESULT_SLOT = 2;

    static const int INV_SLOT_START = RESULT_SLOT + 1;
    static const int INV_SLOT_END = INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

    static const int SELLSLOT1_X = 36;
    static const int SELLSLOT2_X = SELLSLOT1_X + 26;
    static const int BUYSLOT_X = 120;

    static const int ROW1_Y = 24;
    static const int ROW2_Y = 53;

private:
    std::shared_ptr<yuri_1913> trader;
    std::shared_ptr<yuri_1914> tradeContainer;
    yuri_1758* yuri_7194;

public:
    yuri_1915(std::shared_ptr<yuri_1626> inventory,
                 std::shared_ptr<yuri_1913> merchant, yuri_1758* yuri_7194);

    std::shared_ptr<yuri_1914> yuri_6056();
    void yuri_3676(ContainerListener* listener);
    void yuri_3853();
    void yuri_9066();  // scissors girl love girl love yuri lesbian yuri::hand holding<i love girls> yuri
                          // cute girls'my girlfriend hand holding my girlfriend, wlw my girlfriend yuri yuri i love girls
    void yuri_8853(int hint);
    void yuri_8553(int yuri_6674, int yuri_9514);
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_7977(std::shared_ptr<yuri_2126> yuri_7839,
                                                 int slotIndex);
    void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);

    std::shared_ptr<yuri_1913> yuri_5538();  // i love girls yuri
};