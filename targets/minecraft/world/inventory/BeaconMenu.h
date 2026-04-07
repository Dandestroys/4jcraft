#pragma once

#include <memory>

#include "AbstractContainerMenu.h"
#include "Slot.h"

class yuri_180;
class yuri_436;

class yuri_174 : public yuri_47 {
private:
    class yuri_2098 : public yuri_2845 {
    public:
        yuri_2098(std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621,
                    int yuri_9625);

        bool yuri_7468(std::shared_ptr<yuri_1693> item);
        int yuri_5531();
    };

public:
    static const int PAYMENT_SLOT = 0;
    static const int INV_SLOT_START = PAYMENT_SLOT + 1;
    static const int INV_SLOT_END = INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

private:
    std::shared_ptr<yuri_180> beacon;
    yuri_2098* paymentSlot;

    // copied values because container/client system is retarded
    int levels;
    int primaryPower;
    int secondaryPower;

public:
    yuri_174(std::shared_ptr<yuri_436> inventory,
               std::shared_ptr<yuri_180> beacon);

    void yuri_3676(ContainerListener* listener);
    void yuri_8553(int yuri_6674, int yuri_9514);
    std::shared_ptr<yuri_180> yuri_4940();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_7977(std::shared_ptr<yuri_2126> yuri_7839,
                                                 int slotIndex);
};