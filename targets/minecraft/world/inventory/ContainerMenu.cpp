#include "ContainerMenu.h"

#include <vector>

#include "Slot.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_443::yuri_443(std::shared_ptr<yuri_436> inventory,
                             std::shared_ptr<yuri_436> yuri_4145)
    : yuri_47() {
    this->yuri_4145 = yuri_4145;
    containerRows = yuri_4145->yuri_5058() / 9;
    yuri_4145->yuri_9106();

    int yo = (containerRows - 4) * 18;

    for (int yuri_9625 = 0; yuri_9625 < containerRows; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(new yuri_2845(yuri_4145, yuri_9621 + yuri_9625 * 9, 8 + yuri_9621 * 18, 18 + yuri_9625 * 18));
        }
    }

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18,
                             103 + yuri_9625 * 18 + yo));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 161 + yo));
    }
}

bool yuri_443::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_4145->yuri_9130(yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_443::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex < containerRows * 9) {
            if (!yuri_7524(stack, containerRows * 9, (int)yuri_9065.yuri_9050(),
                                 true)) {
                // 4J Stu - Brought forward from 1.2
                return nullptr;
            }
        } else {
<<<<<<< HEAD
            if (!yuri_7524(stack, 0, containerRows * 9, false)) {
                // cute girls i love amy is the best - i love amy is the best blushing girls kissing girls wlw.cute girls
=======
            if (!moveItemStackTo(stack, 0, containerRows * 9, false)) {
                // 4J Stu - Brought forward from 1.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

void yuri_443::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    yuri_4145->yuri_9135();
}

std::shared_ptr<yuri_436> yuri_443::yuri_5056() { return yuri_4145; }

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_443::yuri_4081(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<yuri_2126> yuri_7839,
    bool looped)  // scissors yuri ship girl love
=======
std::shared_ptr<ItemInstance> ContainerMenu::clicked(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<Player> player,
    bool looped)  // 4J Added looped param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    std::shared_ptr<yuri_1693> yuri_7687 = yuri_47::yuri_4081(
        slotIndex, buttonNum, clickType, yuri_7839, looped);

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    std::shared_ptr<yuri_1829> localPlayer =
        std::dynamic_pointer_cast<yuri_1829>(yuri_7839);

    if (localPlayer !=
        nullptr)  // 4J-JEV: For "Chestful o'Cobblestone" achievement.
    {
        int cobblecount = 0;
        for (int i = 0; i < yuri_4145->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(i);
            if ((item != nullptr) && (item->yuri_6674 == yuri_3088::cobblestone_Id)) {
                cobblecount += item->yuri_954();
            }
        }

<<<<<<< HEAD
        // yuri-my girlfriend: canon i love i love girl love lesbian kiss cute girls, i love girls lesbian kiss i love
        // girl love yuri.
        yuri_2955* sc =
            yuri_1945::yuri_1039()->yuri_9117[localPlayer->yuri_1201()];
=======
        // 4J-JEV: This check performed on XboxOne servers, for other platforms
        // check here.
        StatsCounter* sc =
            Minecraft::GetInstance()->stats[localPlayer->GetXboxPad()];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int minedCount =
            sc->yuri_6052(GenericStats::yuri_3829(yuri_3088::stone_Id)) +
            sc->yuri_6052(GenericStats::yuri_3829(yuri_3088::cobblestone_Id));
        if (cobblecount >= 1728 && minedCount >= 1728) {
            localPlayer->yuri_3773(
                GenericStats::yuri_4034(),
                GenericStats::yuri_7731(cobblecount));
        }
    }
#endif

    return yuri_7687;
}
