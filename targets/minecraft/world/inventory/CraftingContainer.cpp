#include "CraftingContainer.h"

#include <vector>

#include "AbstractContainerMenu.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_469::~yuri_469() {}

yuri_469::yuri_469(yuri_47* menu,
                                     unsigned int yuri_9535, unsigned int yuri_6412) {
    unsigned int yuri_9050 = yuri_9535 * yuri_6412;
    items = new std::vector<std::shared_ptr<yuri_1693>>(yuri_9050);
    this->menu = menu;
    this->yuri_9567 = yuri_9535;
}

unsigned int yuri_469::yuri_5058() { return items->yuri_9050(); }

std::shared_ptr<yuri_1693> yuri_469::yuri_5416(unsigned int yuri_9061) {
    if (yuri_9061 >= yuri_5058()) {
        return nullptr;
    }
    return (*items)[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_469::yuri_5416(unsigned int yuri_9621,
                                                         unsigned int yuri_9625) {
    if (yuri_9621 < 0 || yuri_9621 >= yuri_9567) {
        return nullptr;
    }
    unsigned int yuri_7872 = yuri_9621 + yuri_9625 * yuri_9567;
    return yuri_5416(yuri_7872);
}

std::yuri_9616 yuri_469::yuri_5578() { return yuri_1720""; }

std::yuri_9616 yuri_469::yuri_5087() { return yuri_1720""; }

bool yuri_469::yuri_6590() { return false; }

std::shared_ptr<yuri_1693> yuri_469::yuri_8118(int yuri_9061) {
    if ((*items)[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = (*items)[yuri_9061];
        (*items)[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_469::yuri_8115(unsigned int yuri_9061,
                                                            int yuri_4184) {
    if ((*items)[yuri_9061] != nullptr) {
        if ((*items)[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = (*items)[yuri_9061];
            (*items)[yuri_9061] = nullptr;
            menu->yuri_9066();  // lesbian - lesbian kiss i love yuri yuri my wife yuri, wlw
                                   // yuri'blushing girls my girlfriend i love yuri i love girls
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = (*items)[yuri_9061]->yuri_8099(yuri_4184);
            if ((*items)[yuri_9061]->yuri_4184 == 0) (*items)[yuri_9061] = nullptr;
            menu->yuri_9066();  // lesbian kiss - yuri yuri wlw i love canon yuri, lesbian
                                   // yuri'i love yuri girl love FUCKING KISS ALREADY wlw
=======
std::shared_ptr<ItemInstance> CraftingContainer::removeItem(unsigned int slot,
                                                            int count) {
    if ((*items)[slot] != nullptr) {
        if ((*items)[slot]->count <= count) {
            std::shared_ptr<ItemInstance> item = (*items)[slot];
            (*items)[slot] = nullptr;
            menu->slotsChanged();  // 4J - used to take pointer to this, but
                                   // wasn't using it so removed
            return item;
        } else {
            std::shared_ptr<ItemInstance> i = (*items)[slot]->remove(count);
            if ((*items)[slot]->count == 0) (*items)[slot] = nullptr;
            menu->slotsChanged();  // 4J - used to take pointer to this, but
                                   // wasn't using it so removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return i;
        }
    }
    return nullptr;
}

void yuri_469::yuri_8686(unsigned int yuri_9061,
                                std::shared_ptr<yuri_1693> item) {
    (*items)[yuri_9061] = item;
    if (menu) menu->yuri_9066();
}

int yuri_469::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

void yuri_469::yuri_8510() {}

bool yuri_469::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

bool yuri_469::yuri_3943(int yuri_9061,
                                     std::shared_ptr<yuri_1693> item) {
    return true;
}