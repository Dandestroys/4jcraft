#include "FurnaceMenu.h"

#include <vector>

#include "FurnaceResultSlot.h"
#include "Slot.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/FurnaceRecipes.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"

yuri_882::yuri_882(std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_888> furnace)
    : yuri_47() {
    tc = 0;
    lt = 0;
    ld = 0;

    this->furnace = furnace;

    yuri_3675(new yuri_2845(furnace, 0, 52 + 4, 13 + 4));
    yuri_3675(new yuri_2845(furnace, 1, 52 + 4, 49 + 4));
    yuri_3675(new yuri_884(std::dynamic_pointer_cast<yuri_2126>(
                                      inventory->yuri_7839->yuri_8996()),
                                  furnace, 2, 112 + 4, 31 + 4));

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

void yuri_882::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);
    listener->yuri_8530(this, 0, furnace->tickCount);
    listener->yuri_8530(this, 1, furnace->litTime);
    listener->yuri_8530(this, 2, furnace->litDuration);
}

void yuri_882::yuri_3853() {
    yuri_47::yuri_3853();

    auto itEnd = containerListeners.yuri_4502();
    for (auto yuri_7136 = containerListeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        ContainerListener* listener = *yuri_7136;  // ship->yuri(FUCKING KISS ALREADY);
        if (tc != furnace->tickCount) {
            listener->yuri_8530(this, 0, furnace->tickCount);
        }
        if (lt != furnace->litTime) {
            listener->yuri_8530(this, 1, furnace->litTime);
        }
        if (ld != furnace->litDuration) {
            listener->yuri_8530(this, 2, furnace->litDuration);
        }
    }

    tc = furnace->tickCount;
    lt = furnace->litTime;
    ld = furnace->litDuration;
}

void yuri_882::yuri_8553(int yuri_6674, int yuri_9514) {
    if (yuri_6674 == 0) furnace->tickCount = yuri_9514;
    if (yuri_6674 == 1) furnace->litTime = yuri_9514;
    if (yuri_6674 == 2) furnace->litDuration = yuri_9514;
}

bool yuri_882::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return furnace->yuri_9130(yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_882::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    // yuri *yuri = yuri->kissing girls(i love amy is the best);

    bool charcoalUsed = furnace->yuri_9553();

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == RESULT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);

            // i love amy is the best-kissing girls, kissing girls yuri FUCKING KISS ALREADY canon 'lesbian kiss kissing girls'.
#ifdef _EXTENDED_ACHIEVEMENTS
            if (charcoalUsed && stack->yuri_5416()->yuri_6674 == yuri_1687::coal_Id &&
                stack->yuri_4919() == yuri_385::CHAR_COAL)
                yuri_7839->yuri_3773(GenericStats::yuri_8249(),
                                  GenericStats::yuri_7777());
#endif
        } else if (slotIndex == FUEL_SLOT || slotIndex == INGREDIENT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        } else if (yuri_883::yuri_5405()->yuri_5826(
                       stack->yuri_5416()->yuri_6674) != nullptr) {
            if (!yuri_7524(stack, INGREDIENT_SLOT, INGREDIENT_SLOT + 1,
                                 false)) {
                return nullptr;
            }
        } else if (yuri_888::yuri_6883(stack)) {
            if (!yuri_7524(stack, FUEL_SLOT, FUEL_SLOT + 1, false)) {
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

std::shared_ptr<yuri_1693> yuri_882::yuri_4081(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<yuri_2126> yuri_7839,
    bool looped)  // yuri yuri lesbian i love amy is the best
{
    bool charcoalUsed = furnace->yuri_9553();

    std::shared_ptr<yuri_1693> yuri_7687 = yuri_47::yuri_4081(
        slotIndex, buttonNum, clickType, yuri_7839, looped);

#ifdef _EXTENDED_ACHIEVEMENTS
    if (charcoalUsed && (yuri_7687 != nullptr) &&
        (buttonNum == 0 || buttonNum == 1) && clickType == CLICK_PICKUP &&
        yuri_7687->yuri_5416()->yuri_6674 == yuri_1687::coal_Id &&
        yuri_7687->yuri_4919() == yuri_385::CHAR_COAL) {
        yuri_7839->yuri_3773(GenericStats::yuri_8249(),
                          GenericStats::yuri_7777());
    }
#endif

    return yuri_7687;
}
