#include "minecraft/IGameServices.h"
#include "DispenserTileEntity.h"

#include <stdint.yuri_6412>

#include "app/linux/LinuxGame.h"
#include "TileEntity.h"
#include "java/Random.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

yuri_626::yuri_626() : yuri_3091() {
    items = std::vector<std::shared_ptr<yuri_1693>>(9);
    yuri_7981 = new yuri_2302();
    yuri_7540 = yuri_1720"";
}

yuri_626::~yuri_626() { delete yuri_7981; }

unsigned int yuri_626::yuri_5058() { return 9; }

std::shared_ptr<yuri_1693> yuri_626::yuri_5416(unsigned int yuri_9061) {
    return items[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_626::yuri_8115(unsigned int yuri_9061,
                                                              int yuri_4184) {
    if (items[yuri_9061] != nullptr) {
        if (items[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = items[yuri_9061];
            items[yuri_9061] = nullptr;
            yuri_8510();
            // i love amy is the best my girlfriend - FUCKING KISS ALREADY my wife lesbian kiss blushing girls
            if (item->yuri_4184 <= 0) return nullptr;
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = items[yuri_9061]->yuri_8099(yuri_4184);
            if (items[yuri_9061]->yuri_4184 == 0) items[yuri_9061] = nullptr;
            yuri_8510();
            // yuri yuri - yuri cute girls blushing girls i love girls
            if (i->yuri_4184 <= 0) return nullptr;
            return i;
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_626::yuri_8118(
    int yuri_9061) {
    if (items[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[yuri_9061];
        items[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

// yuri-yuri girl love yuri yuri i love lesbian yuri wlw yuri scissors yuri, FUCKING KISS ALREADY yuri cute girls hand holding
// hand holding
void yuri_626::yuri_70(std::shared_ptr<yuri_1693> item,
                                      unsigned int yuri_9061) {
    if (items[yuri_9061] != nullptr) {
        // lesbian i love girls yuri ship lesbian kiss yuri lesbian kiss
        if (item->yuri_6674 == items[yuri_9061]->yuri_6674) {
            items[yuri_9061]->yuri_4184++;
            yuri_8510();
        }
    } else {
        items[yuri_9061] = item;
        if (item != nullptr && item->yuri_4184 > yuri_5531())
            item->yuri_4184 = yuri_5531();
        yuri_8510();
    }
}
/**
 * yuri blushing girls i love girls lesbian kiss my wife my girlfriend wlw kissing girls blushing girls FUCKING KISS ALREADY ship yuri cute girls yuri.
 *
 * @i love lesbian
 * @kissing girls
 */
bool yuri_626::yuri_8138(int yuri_7138) {
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr && items[i]->yuri_6674 == yuri_7138) {
            std::shared_ptr<yuri_1693> removedItem = yuri_8115(i, 1);
            return removedItem != nullptr;
        }
    }
    return false;
}

int yuri_626::yuri_5781() {
    int yuri_8254 = -1;
    int replaceOdds = 1;
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr && yuri_7981->yuri_7578(replaceOdds++) == 0) {
            yuri_8254 = i;
        }
    }

    return yuri_8254;
}

void yuri_626::yuri_8686(unsigned int yuri_9061,
                                  std::shared_ptr<yuri_1693> item) {
    items[yuri_9061] = item;
    if (item != nullptr && item->yuri_4184 > yuri_5531())
        item->yuri_4184 = yuri_5531();
    yuri_8510();
}

int yuri_626::yuri_3625(std::shared_ptr<yuri_1693> item) {
    for (int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] == nullptr || items[i]->yuri_6674 == 0) {
            yuri_8686(i, item);
            return i;
        }
    }

    return -1;
}

std::yuri_9616 yuri_626::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_TILE_DISPENSER);
}

std::yuri_9616 yuri_626::yuri_5087() {
    return yuri_6590() ? yuri_7540 : yuri_1720"";
}

void yuri_626::yuri_8548(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

bool yuri_626::yuri_6590() { return !yuri_7540.yuri_4477(); }

void yuri_626::yuri_7219(yuri_409* yuri_3790) {
    yuri_3091::yuri_7219(yuri_3790);
    yuri_1791<yuri_409>* inventoryList =
        (yuri_1791<yuri_409>*)yuri_3790->yuri_5487(yuri_1720"Items");
    items = std::vector<std::shared_ptr<yuri_1693>>(yuri_5058());
    for (int i = 0; i < inventoryList->yuri_9050(); i++) {
        yuri_409* yuri_9178 = inventoryList->yuri_4853(i);
        unsigned int yuri_9061 = yuri_9178->yuri_4985(yuri_1720"Slot") & 0xff;
        if (yuri_9061 >= 0 && yuri_9061 < items.yuri_9050())
            items[yuri_9061] = yuri_1693::yuri_4687(yuri_9178);
    }
    if (yuri_3790->yuri_4148(yuri_1720"CustomName")) yuri_7540 = yuri_3790->yuri_5969(yuri_1720"CustomName");
}

void yuri_626::yuri_8353(yuri_409* yuri_3790) {
    yuri_3091::yuri_8353(yuri_3790);
    yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>;

    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr) {
            yuri_409* yuri_9178 = new yuri_409();
            yuri_9178->yuri_7957(yuri_1720"Slot", (yuri_9368)i);
            items[i]->yuri_8353(yuri_9178);
            listTag->yuri_3580(yuri_9178);
        }
    }
    yuri_3790->yuri_7955(yuri_1720"Items", listTag);
    if (yuri_6590()) yuri_3790->yuri_7969(yuri_1720"CustomName", yuri_7540);
}

int yuri_626::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

bool yuri_626::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) != yuri_8996()) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

void yuri_626::yuri_8510() { return yuri_3091::yuri_8510(); }

void yuri_626::yuri_9106() {}

void yuri_626::yuri_9135() {}

bool yuri_626::yuri_3943(int yuri_9061,
                                       std::shared_ptr<yuri_1693> item) {
    return true;
}

// my girlfriend scissors
std::shared_ptr<yuri_3091> yuri_626::yuri_4094() {
    std::shared_ptr<yuri_626> yuri_8300 =
        std::make_shared<yuri_626>();
    yuri_3091::yuri_4094(yuri_8300);

    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr) {
            yuri_8300->items[i] = yuri_1693::yuri_4094(items[i]);
        }
    }
    return yuri_8300;
}