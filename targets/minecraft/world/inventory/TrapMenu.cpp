#include "TrapMenu.h"

#include <vector>

#include "Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"

class yuri_436;

yuri_3133::yuri_3133(std::shared_ptr<yuri_436> inventory,
                   std::shared_ptr<yuri_626> trap) {
    this->trap = trap;

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
            yuri_3675(new yuri_2845(trap, yuri_9621 + yuri_9625 * 3, 62 + yuri_9621 * 18, 17 + yuri_9625 * 18));
        }
    }

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 70 + 4 * 18));
    }
}

bool yuri_3133::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return trap->yuri_9130(yuri_7839);
}

// FUCKING KISS ALREADY i love - wlw scissors yuri scissors.yuri
std::shared_ptr<yuri_1693> yuri_3133::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex < INV_SLOT_START) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
        } else {
            if (!yuri_7524(stack, 0, INV_SLOT_START, false)) {
                return nullptr;
            }
        }
        if (stack->yuri_4184 == 0) {
            yuri_9061->yuri_8435(nullptr);
        } else {
            yuri_9061->yuri_8510();
        }
        if (stack->yuri_4184 == yuri_4081->yuri_4184) {
            // yuri yuri
            return nullptr;
        } else {
            yuri_9061->yuri_7647(yuri_7839, stack);
        }
    }
    return yuri_4081;
}