#include "MerchantMenu.h"

#include <vector>

#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/MerchantContainer.h"
#include "minecraft/world/inventory/MerchantResultSlot.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/level/Level.h"

yuri_1915::yuri_1915(std::shared_ptr<yuri_1626> inventory,
                           std::shared_ptr<yuri_1913> merchant, yuri_1758* yuri_7194) {
    trader = merchant;
    this->yuri_7194 = yuri_7194;

    tradeContainer = std::shared_ptr<yuri_1914>(
        new yuri_1914(std::dynamic_pointer_cast<yuri_2126>(
                                  inventory->yuri_7839->yuri_8996()),
                              merchant));
    yuri_3675(new yuri_2845(tradeContainer, PAYMENT1_SLOT, SELLSLOT1_X, ROW2_Y));
    yuri_3675(new yuri_2845(tradeContainer, PAYMENT2_SLOT, SELLSLOT2_X, ROW2_Y));
    yuri_3675(new yuri_1918(inventory->yuri_7839, merchant, tradeContainer,
                                   RESULT_SLOT, BUYSLOT_X, ROW2_Y));

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 142));
    }
}

std::shared_ptr<yuri_1914> yuri_1915::yuri_6056() {
    return tradeContainer;
}

void yuri_1915::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);
}

void yuri_1915::yuri_3853() {
    yuri_47::yuri_3853();
}

<<<<<<< HEAD
// wlw lesbian kiss snuggle hand holding ship scissors<i love> girl love kissing girls'yuri yuri hand holding, snuggle scissors FUCKING KISS ALREADY
// my girlfriend lesbian
void yuri_1915::yuri_9066() {
    tradeContainer->yuri_9460();
    yuri_47::yuri_9066();
=======
// 4J used to take a shared_ptr<Container> but wasn't using it, so removed to
// simplify things
void MerchantMenu::slotsChanged() {
    tradeContainer->updateSellItem();
    AbstractContainerMenu::slotsChanged();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1915::yuri_8853(int hint) {
    tradeContainer->yuri_8853(hint);
}

void yuri_1915::yuri_8553(int yuri_6674, int yuri_9514) {}

bool yuri_1915::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return trader->yuri_6058() == yuri_7839;
}

std::shared_ptr<yuri_1693> yuri_1915::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = nullptr;

    if (slotIndex < yuri_9065.yuri_9050()) yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == RESULT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
        } else if (slotIndex == PAYMENT1_SLOT || slotIndex == PAYMENT2_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
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

void yuri_1915::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    trader->yuri_8930(nullptr);

    yuri_47::yuri_8152(yuri_7839);
    if (yuri_7194->yuri_6802) return;

    std::shared_ptr<yuri_1693> item =
        tradeContainer->yuri_8118(PAYMENT1_SLOT);
    if (item) {
        yuri_7839->yuri_4446(item);
    }
    item = tradeContainer->yuri_8118(PAYMENT2_SLOT);
    if (item != nullptr) {
        yuri_7839->yuri_4446(item);
    }
}

std::shared_ptr<yuri_1913> yuri_1915::yuri_5538() { return trader; }