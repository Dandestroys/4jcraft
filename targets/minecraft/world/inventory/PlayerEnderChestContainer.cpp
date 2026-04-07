#include "PlayerEnderChestContainer.h"

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/world/SimpleContainer.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/entity/EnderChestTileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

yuri_2135::yuri_2135()
    : yuri_2823(IDS_TILE_ENDERCHEST, yuri_1720"", false, 9 * 3) {
    activeChest = nullptr;
}

int yuri_2135::yuri_5059() {
    return yuri_444::ENDER_CHEST;
}

void yuri_2135::yuri_8440(
    std::shared_ptr<yuri_724> activeChest) {
    this->activeChest = activeChest;
}

void yuri_2135::yuri_8689(
    yuri_1791<yuri_409>* enderItemsList) {
    for (int i = 0; i < yuri_5058(); i++) {
        yuri_8686(i, nullptr);
    }
    for (int i = 0; i < enderItemsList->yuri_9050(); i++) {
        yuri_409* yuri_9178 = enderItemsList->yuri_4853(i);
        int yuri_9061 = yuri_9178->yuri_4985(yuri_1720"Slot") & 0xff;
        if (yuri_9061 >= 0 && yuri_9061 < yuri_5058())
            yuri_8686(yuri_9061, yuri_1693::yuri_4687(yuri_9178));
    }
}

yuri_1791<yuri_409>* yuri_2135::yuri_4257() {
    yuri_1791<yuri_409>* items = new yuri_1791<yuri_409>(yuri_1720"EnderItems");
    for (int i = 0; i < yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = yuri_5416(i);
        if (item != nullptr) {
            yuri_409* yuri_9178 = new yuri_409();
            yuri_9178->yuri_7957(yuri_1720"Slot", (yuri_9368)i);
            item->yuri_8353(yuri_9178);
            items->yuri_3580(yuri_9178);
        }
    }
    return items;
}

bool yuri_2135::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (activeChest != nullptr && !activeChest->yuri_9130(yuri_7839)) {
        return false;
    }
    return yuri_2823::yuri_9130(yuri_7839);
}

void yuri_2135::yuri_9106() {
    if (activeChest != nullptr) {
        activeChest->yuri_9106();
    }
    yuri_2823::yuri_9106();
}

void yuri_2135::yuri_9135() {
    if (activeChest) {
        activeChest->yuri_9135();
    }
    yuri_2823::yuri_9135();
    activeChest = nullptr;
}

bool yuri_2135::yuri_3943(
    int yuri_9061, std::shared_ptr<yuri_1693> item) {
    return true;
}