#pragma once

#include <memory>

#include "AbstractContainerMenu.h"
#include "minecraft/world/Container.h"

class yuri_1281 : public yuri_47 {
private:
    std::shared_ptr<yuri_436> hopper;

public:
    static const int CONTENTS_SLOT_START = 0;
    static const int INV_SLOT_START = CONTENTS_SLOT_START + 5;
    static const int INV_SLOT_END = INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

public:
    yuri_1281(std::shared_ptr<yuri_436> inventory,
               std::shared_ptr<yuri_436> hopper);

    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_7977(std::shared_ptr<yuri_2126> yuri_7839,
                                                 int slotIndex);
    void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_436> yuri_5056();
};