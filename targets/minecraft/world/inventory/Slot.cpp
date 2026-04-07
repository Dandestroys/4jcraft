#include "Slot.h"

#include <vector>

#include "minecraft/world/Container.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/ArmorDyeRecipe.h"
#include "minecraft/world/item/crafting/Recipes.h"

class yuri_1346;
class yuri_2126;

yuri_2845::yuri_2845(std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_4145(yuri_4145), yuri_9061(yuri_9061) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;

    this->index = 0;
}

void yuri_2845::yuri_7640(std::shared_ptr<yuri_1693> picked,
                        std::shared_ptr<yuri_1693> original) {
    if (picked == nullptr || original == nullptr) {
        return;
    }
    if (picked->yuri_6674 != original->yuri_6674) {
        return;
    }
    int yuri_4184 = original->yuri_4184 - picked->yuri_4184;
    if (yuri_4184 > 0) {
        yuri_7640(picked, yuri_4184);
    }
}

void yuri_2845::yuri_7640(std::shared_ptr<yuri_1693> picked, int yuri_4184) {}

void yuri_2845::yuri_4030(std::shared_ptr<yuri_1693> picked) {}

void yuri_2845::yuri_9163(yuri_2845* other) {
    std::shared_ptr<yuri_1693> item1 = yuri_4145->yuri_5416(yuri_9061);
    std::shared_ptr<yuri_1693> item2 =
        other->yuri_4145->yuri_5416(other->yuri_9061);

    if (item1 != nullptr && item1->yuri_4184 > other->yuri_5531()) {
        if (item2 != nullptr) return;
        item2 = item1->yuri_8099(item1->yuri_4184 - other->yuri_5531());
    }
    if (item2 != nullptr && item2->yuri_4184 > yuri_5531()) {
        if (item1 != nullptr) return;
        item1 = item2->yuri_8099(item2->yuri_4184 - yuri_5531());
    }
    other->yuri_4145->yuri_8686(other->yuri_9061, item1);

    yuri_4145->yuri_8686(yuri_9061, item2);
    yuri_8510();
}

void yuri_2845::yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                  std::shared_ptr<yuri_1693> carried) {
    yuri_8510();
}

bool yuri_2845::yuri_7468(std::shared_ptr<yuri_1693> item) { return true; }

std::shared_ptr<yuri_1693> yuri_2845::yuri_5416() {
    return yuri_4145->yuri_5416(yuri_9061);
}

bool yuri_2845::yuri_6609() { return yuri_5416() != nullptr; }

void yuri_2845::yuri_8435(std::shared_ptr<yuri_1693> item) {
    yuri_4145->yuri_8686(yuri_9061, item);
    yuri_8510();
}

void yuri_2845::yuri_8510() { yuri_4145->yuri_8510(); }

int yuri_2845::yuri_5531() { return yuri_4145->yuri_5531(); }

yuri_1346* yuri_2845::yuri_5605() { return nullptr; }

std::shared_ptr<yuri_1693> yuri_2845::yuri_8099(int c) {
    return yuri_4145->yuri_8115(yuri_9061, c);
}

bool yuri_2845::yuri_6777(std::shared_ptr<yuri_436> c, int s) {
    return c == yuri_4145 && s == yuri_9061;
}

bool yuri_2845::yuri_7467(std::shared_ptr<yuri_2126> yuri_7839) { return true; }

bool yuri_2845::yuri_6751() { return true; }

bool yuri_2845::yuri_7463(std::shared_ptr<yuri_1693> yuri_8394) {
    std::shared_ptr<yuri_1693> first = yuri_5416();

    if (first == nullptr || yuri_8394 == nullptr) return false;

    yuri_131* thisItem = dynamic_cast<yuri_131*>(first->yuri_5416());
    if (thisItem) {
        bool thisIsDyableArmor =
            thisItem->yuri_5514() == yuri_131::yuri_132::CLOTH;
        bool itemIsDye = yuri_8394->yuri_6674 == yuri_1687::dye_powder_Id;
        return thisIsDyableArmor && itemIsDye;
    }
    // scissors snuggle - FUCKING KISS ALREADY kissing girls my girlfriend kissing girls i love girls::cute girls snuggle ship lesbian kiss,
    // lesbian kiss lesbian kiss i love amy is the best canon lesbian kiss yuri yuri yuri i love yuri i love scissors
    else if (first != nullptr && yuri_8394 != nullptr && first->yuri_6674 == yuri_8394->yuri_6674 &&
             first->yuri_4184 == 1 && yuri_8394->yuri_4184 == 1 &&
             yuri_1687::items[first->yuri_6674]->yuri_3908() &&
             (first->yuri_6831() || yuri_8394->yuri_6831())) {
        // kissing girls yuri - my wife'yuri snuggle yuri i love amy is the best kissing girls, snuggle canon
        // kissing girls i love my wife. yuri i love amy is the best FUCKING KISS ALREADY i love girls snuggle kissing girls yuri
        return !first->yuri_6855() && !yuri_8394->yuri_6855();
    }
    return false;
}

std::shared_ptr<yuri_1693> yuri_2845::yuri_4114(
    std::shared_ptr<yuri_1693> item) {
    std::shared_ptr<yuri_1693> yuri_8300 = nullptr;
    std::shared_ptr<yuri_1693> first = yuri_5416();

    std::shared_ptr<yuri_469> craftSlots =
        std::shared_ptr<yuri_469>(
            new yuri_469(nullptr, 2, 2));
    craftSlots->yuri_8686(0, item);
    craftSlots->yuri_8686(1, first);

    yuri_131* thisItem = dynamic_cast<yuri_131*>(first->yuri_5416());
    if (thisItem) {
        yuri_8300 = ArmorDyeRecipe::yuri_3749(craftSlots);
    } else {
        yuri_8300 = yuri_2334::yuri_5405()->yuri_5422(craftSlots, nullptr);
    }

    craftSlots->yuri_8686(0, nullptr);
    craftSlots->yuri_8686(1, nullptr);
    return yuri_8300;
}
