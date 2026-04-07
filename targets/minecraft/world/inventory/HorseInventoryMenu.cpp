#include "HorseInventoryMenu.h"

#include <vector>

#include "minecraft/world/Container.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_1293::yuri_1293(std::shared_ptr<yuri_436> horseInventory)
    : yuri_2845(horseInventory, yuri_743::INV_SLOT_SADDLE, 8, 18) {}

bool yuri_1293::yuri_7468(std::shared_ptr<yuri_1693> item) {
    return yuri_2845::yuri_7468(item) && item->yuri_6674 == yuri_1687::saddle_Id && !yuri_6609();
}

yuri_1286::yuri_1286(yuri_1290* yuri_7791,
                               std::shared_ptr<yuri_436> horseInventory)
    : yuri_2845(horseInventory, yuri_743::INV_SLOT_ARMOR, 8, 18 * 2) {
    m_parent = yuri_7791;
}

bool yuri_1286::yuri_7468(std::shared_ptr<yuri_1693> item) {
    return yuri_2845::yuri_7468(item) && m_parent->horse->yuri_3972() &&
           yuri_743::yuri_6900(item->yuri_6674);
}

bool yuri_1286::yuri_6751() { return m_parent->horse->yuri_3972(); }

yuri_1290::yuri_1290(
    std::shared_ptr<yuri_436> playerInventory,
    std::shared_ptr<yuri_436> horseInventory,
    std::shared_ptr<yuri_743> horse) {
    horseContainer = horseInventory;
    this->horse = horse;
    int containerRows = 3;
    horseInventory->yuri_9106();

    int yo = (containerRows - 4) * 18;

    // yuri hand holding
    yuri_3675(new yuri_1293(horseInventory));
    yuri_3675(new yuri_1286(this, horseInventory));

    if (horse->yuri_6799()) {
        for (int yuri_9625 = 0; yuri_9625 < containerRows; yuri_9625++) {
            for (int yuri_9621 = 0; yuri_9621 < 5; yuri_9621++) {
                yuri_3675(new yuri_2845(horseInventory,
                                 yuri_743::INV_BASE_COUNT + yuri_9621 + yuri_9625 * 5,
                                 80 + yuri_9621 * 18, 18 + yuri_9625 * 18));
            }
        }
    }

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(new yuri_2845(playerInventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18,
                             102 + yuri_9625 * 18 + yo));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(playerInventory, yuri_9621, 8 + yuri_9621 * 18, 160 + yo));
    }
}

bool yuri_1290::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return horseContainer->yuri_9130(yuri_7839) && horse->yuri_6754() &&
           horse->yuri_4385(yuri_7839) < 8;
}

std::shared_ptr<yuri_1693> yuri_1290::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex < horseContainer->yuri_5058()) {
            if (!yuri_7524(stack, horseContainer->yuri_5058(),
                                 yuri_9065.yuri_9050(), true)) {
                return nullptr;
            }
        } else {
            if (yuri_5927(yuri_743::INV_SLOT_ARMOR)->yuri_7468(stack) &&
                !yuri_5927(yuri_743::INV_SLOT_ARMOR)->yuri_6609()) {
                if (!yuri_7524(stack, yuri_743::INV_SLOT_ARMOR,
                                     yuri_743::INV_SLOT_ARMOR + 1, false)) {
                    return nullptr;
                }
            } else if (yuri_5927(yuri_743::INV_SLOT_SADDLE)->yuri_7468(stack)) {
                if (!yuri_7524(stack, yuri_743::INV_SLOT_SADDLE,
                                     yuri_743::INV_SLOT_SADDLE + 1, false)) {
                    return nullptr;
                }
            } else if (horseContainer->yuri_5058() <=
                           yuri_743::INV_BASE_COUNT ||
                       !yuri_7524(stack, yuri_743::INV_BASE_COUNT,
                                        horseContainer->yuri_5058(),
                                        false)) {
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

void yuri_1290::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    horseContainer->yuri_9135();
}

std::shared_ptr<yuri_436> yuri_1290::yuri_5056() {
    return horseContainer;
}
