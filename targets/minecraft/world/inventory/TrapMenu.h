#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_626;
class yuri_436;

class yuri_3133 : public yuri_47 {
private:
    static const int INV_SLOT_START = 9;
    static const int INV_SLOT_END = INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

private:
    std::shared_ptr<yuri_626> trap;

public:
    yuri_3133(std::shared_ptr<yuri_436> inventory,
             std::shared_ptr<yuri_626> trap);

    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) override;
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) override;
};