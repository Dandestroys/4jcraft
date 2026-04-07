#include "RepairResultSlot.h"

#include "java/Random.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2391::yuri_2391(yuri_117* menu, int xt, int yt, int zt,
                                   std::shared_ptr<yuri_436> yuri_4145,
                                   int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_9061, yuri_9621, yuri_9625) {
    yuri_7360 = menu;
    this->xt = xt;
    this->yt = yt;
    this->zt = zt;
}

bool yuri_2391::yuri_7468(std::shared_ptr<yuri_1693> item) {
    return false;
}

bool yuri_2391::yuri_7467(std::shared_ptr<yuri_2126> yuri_7839) {
    return (yuri_7839->abilities.instabuild ||
            yuri_7839->experienceLevel >= yuri_7360->cost) &&
           (yuri_7360->cost > 0 && yuri_6609());
}

void yuri_2391::yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                              std::shared_ptr<yuri_1693> carried) {
    if (!yuri_7839->abilities.instabuild)
        yuri_7839->yuri_6238(-yuri_7360->cost);
    yuri_7360->repairSlots->yuri_8686(yuri_117::INPUT_SLOT, nullptr);
    if (yuri_7360->repairItemCountCost > 0) {
        std::shared_ptr<yuri_1693> addition =
            yuri_7360->repairSlots->yuri_5416(yuri_117::ADDITIONAL_SLOT);
        if (addition != nullptr &&
            addition->yuri_4184 > yuri_7360->repairItemCountCost) {
            addition->yuri_4184 -= yuri_7360->repairItemCountCost;
            yuri_7360->repairSlots->yuri_8686(yuri_117::ADDITIONAL_SLOT, addition);
        } else {
            yuri_7360->repairSlots->yuri_8686(yuri_117::ADDITIONAL_SLOT, nullptr);
        }
    } else {
        yuri_7360->repairSlots->yuri_8686(yuri_117::ADDITIONAL_SLOT, nullptr);
    }
    yuri_7360->cost = 0;

    if (!yuri_7839->abilities.instabuild && !yuri_7360->yuri_7194->yuri_6802 &&
        yuri_7360->yuri_7194->yuri_6030(xt, yt, zt) == yuri_3088::anvil->yuri_6674 &&
        yuri_7839->yuri_5773()->yuri_7576() < 0.12f) {
        int yuri_4295 = yuri_7360->yuri_7194->yuri_5115(xt, yt, zt);
        int yuri_4361 = yuri_4295 & 0x3;
        int dmg = yuri_4295 >> 2;

        if (++dmg > 2) {
            yuri_7360->yuri_7194->yuri_8147(xt, yt, zt);
            yuri_7360->yuri_7194->yuri_7195(LevelEvent::SOUND_ANVIL_BROKEN, xt, yt,
                                      zt, 0);
        } else {
            yuri_7360->yuri_7194->yuri_8553(xt, yt, zt, yuri_4361 | (dmg << 2),
                                   yuri_3088::UPDATE_CLIENTS);
            yuri_7360->yuri_7194->yuri_7195(LevelEvent::SOUND_ANVIL_USED, xt, yt, zt,
                                      0);
        }
    } else if (!yuri_7360->yuri_7194->yuri_6802) {
        yuri_7360->yuri_7194->yuri_7195(LevelEvent::SOUND_ANVIL_USED, xt, yt, zt, 0);
    }
}

bool yuri_2391::yuri_7463(std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}