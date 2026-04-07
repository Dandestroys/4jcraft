#include "BeaconMenu.h"

#include <vector>

#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"

class yuri_436;

yuri_174::yuri_174(std::shared_ptr<yuri_436> inventory,
                       std::shared_ptr<yuri_180> beacon) {
    this->beacon = beacon;

    yuri_3675(paymentSlot =
                new yuri_174::yuri_2098(beacon, PAYMENT_SLOT, 136, 110));

    int xo = 36;
    int yo = 137;

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, xo + yuri_9621 * 18, yo + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, xo + yuri_9621 * 18, 58 + yo));
    }

    levels = beacon->yuri_5481();
    primaryPower = beacon->yuri_5753();
    secondaryPower = beacon->yuri_5865();
}

void yuri_174::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);

    listener->yuri_8530(this, 0, levels);
    listener->yuri_8530(this, 1, primaryPower);
    listener->yuri_8530(this, 2, secondaryPower);
}

void yuri_174::yuri_8553(int yuri_6674, int yuri_9514) {
    if (yuri_6674 == 0) beacon->yuri_8705(yuri_9514);
    if (yuri_6674 == 1) beacon->yuri_8789(yuri_9514);
    if (yuri_6674 == 2) beacon->yuri_8846(yuri_9514);
}

std::shared_ptr<yuri_180> yuri_174::yuri_4940() { return beacon; }

bool yuri_174::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return beacon->yuri_9130(yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_174::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == PAYMENT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
        } else if (!paymentSlot->yuri_6609() && paymentSlot->yuri_7468(stack) &&
                   stack->yuri_4184 == 1) {
            if (!yuri_7524(stack, PAYMENT_SLOT, PAYMENT_SLOT + 1,
                                 false)) {
                return nullptr;
            }
        } else if (slotIndex >= INV_SLOT_START && slotIndex < INV_SLOT_END) {
            if (!yuri_7524(stack, USE_ROW_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        } else if (slotIndex >= USE_ROW_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
            if (!yuri_7524(stack, INV_SLOT_START, INV_SLOT_END, false)) {
                return nullptr;
            }
        } else {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        }
        if (stack->yuri_4184 == 0) {
            yuri_9061->yuri_8435(nullptr);
        } else {
            yuri_9061->yuri_8510();
        }
        if (stack->yuri_4184 == yuri_4081->yuri_4184) {
            return nullptr;
        } else {
            yuri_9061->yuri_7647(yuri_7839, stack);
        }
    }
    return yuri_4081;
}

yuri_174::yuri_2098::yuri_2098(std::shared_ptr<yuri_436> yuri_4145,
                                     int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_9061, yuri_9621, yuri_9625) {}

bool yuri_174::yuri_2098::yuri_7468(std::shared_ptr<yuri_1693> item) {
    if (item != nullptr) {
        return (item->yuri_6674 == yuri_1687::emerald_Id || item->yuri_6674 == yuri_1687::diamond_Id ||
                item->yuri_6674 == yuri_1687::goldIngot_Id ||
                item->yuri_6674 == yuri_1687::ironIngot_Id);
    }
    return false;
}

int yuri_174::yuri_2098::yuri_5531() { return 1; }