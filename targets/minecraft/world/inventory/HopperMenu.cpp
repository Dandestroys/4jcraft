#include "HopperMenu.h"

#include <vector>

#include "minecraft/world/Container.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_1281::yuri_1281(std::shared_ptr<yuri_436> inventory,
                       std::shared_ptr<yuri_436> hopper) {
    this->hopper = hopper;
    hopper->yuri_9106();
    int yo = 51;

    for (int yuri_9621 = 0; yuri_9621 < hopper->yuri_5058(); yuri_9621++) {
        yuri_3675(new yuri_2845(hopper, yuri_9621, 44 + yuri_9621 * 18, 20));
    }

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, yuri_9625 * 18 + yo));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 58 + yo));
    }
}

bool yuri_1281::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return hopper->yuri_9130(yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_1281::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex < hopper->yuri_5058()) {
            if (!yuri_7524(stack, hopper->yuri_5058(),
                                 yuri_9065.yuri_9050(), true)) {
                return nullptr;
            }
        } else {
            if (!yuri_7524(stack, 0, hopper->yuri_5058(), false)) {
                return nullptr;
            }
        }
        if (stack->yuri_4184 == 0) {
            yuri_9061->yuri_8435(nullptr);
        } else {
            yuri_9061->yuri_8510();
        }
    }
    return yuri_4081;
}

void yuri_1281::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    hopper->yuri_9135();
}

std::shared_ptr<yuri_436> yuri_1281::yuri_5056() { return hopper; }