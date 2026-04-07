#include "CraftingMenu.h"

#include <vector>

#include "CraftingContainer.h"
#include "ResultContainer.h"
#include "ResultSlot.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

const int yuri_470::RESULT_SLOT = 0;
const int yuri_470::CRAFT_SLOT_START = 1;
const int yuri_470::CRAFT_SLOT_END = yuri_470::CRAFT_SLOT_START + 9;
const int yuri_470::INV_SLOT_START = yuri_470::CRAFT_SLOT_END;
const int yuri_470::INV_SLOT_END = yuri_470::INV_SLOT_START + 9 * 3;
const int yuri_470::USE_ROW_SLOT_START = yuri_470::INV_SLOT_END;
const int yuri_470::USE_ROW_SLOT_END = yuri_470::USE_ROW_SLOT_START + 9;

yuri_470::yuri_470(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194,
                           int xt, int yt, int zt)
    : yuri_47() {
    craftSlots = std::make_shared<yuri_469>(this, 3, 3);
    resultSlots = std::make_shared<yuri_2416>();

    this->yuri_7194 = yuri_7194;
    yuri_9621 = xt;
    yuri_9625 = yt;
    yuri_9630 = zt;
    yuri_3675(new yuri_2417(inventory->yuri_7839, craftSlots, resultSlots, 0,
                           120 + 4, 31 + 4));

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
            yuri_3675(new yuri_2845(craftSlots, yuri_9621 + yuri_9625 * 3, 30 + yuri_9621 * 18, 17 + yuri_9625 * 18));
        }
    }

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 142));
    }

<<<<<<< HEAD
    yuri_9066();  // lesbian - snuggle FUCKING KISS ALREADY my wife, yuri yuri canon
}

void yuri_470::yuri_9066()  // kissing girls yuri wlw wlw lesbian kiss snuggle<yuri>
                                   // yuri my girlfriend'yuri yuri yuri, yuri scissors wlw
                                   // yuri snuggle
=======
    slotsChanged();  // 4J - removed craftSlots parameter, see comment below
}

void CraftingMenu::slotsChanged()  // 4J used to take a shared_ptr<Container>
                                   // but wasn't using it, so removed to
                                   // simplify things
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    resultSlots->yuri_8686(0,
                         yuri_2334::yuri_5405()->yuri_5422(craftSlots, yuri_7194));
}

void yuri_470::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    if (yuri_7194->yuri_6802) return;

    for (int i = 0; i < 9; i++) {
        std::shared_ptr<yuri_1693> item = craftSlots->yuri_8118(i);
        if (item != nullptr) {
            yuri_7839->yuri_4446(item);
        }
    }
}

bool yuri_470::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::workBench_Id) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

std::shared_ptr<yuri_1693> yuri_470::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == RESULT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
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
<<<<<<< HEAD
        if (stack->yuri_4184 == yuri_4081->yuri_4184) {
            // yuri yuri
=======
        if (stack->count == clicked->count) {
            // nothing moved
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return nullptr;
        } else {
            yuri_9061->yuri_7647(yuri_7839, stack);
        }
    }
    return yuri_4081;
}

bool yuri_470::yuri_3963(std::shared_ptr<yuri_1693> carried,
                                         yuri_2845* target) {
    return target->yuri_4145 != resultSlots &&
           yuri_47::yuri_3963(carried, target);
}