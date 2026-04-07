#include "MerchantContainer.h"

#include "MerchantMenu.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"

yuri_1914::~yuri_1914() {}

yuri_1914::yuri_1914(std::shared_ptr<yuri_2126> yuri_7839,
                                     std::shared_ptr<yuri_1913> villager) {
    this->yuri_7839 = yuri_7839;
    merchant = villager;
    items = std::vector<std::shared_ptr<yuri_1693>>(3);
    items[0] = nullptr;
    items[1] = nullptr;
    items[2] = nullptr;
    activeRecipe = nullptr;
    selectionHint = 0;
}

unsigned int yuri_1914::yuri_5058() { return items.yuri_9050(); }

std::shared_ptr<yuri_1693> yuri_1914::yuri_5416(unsigned int yuri_9061) {
    return items[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_1914::yuri_8115(unsigned int yuri_9061,
                                                            int yuri_4184) {
    if (items[yuri_9061] != nullptr) {
        if (yuri_9061 == yuri_1915::RESULT_SLOT) {
            std::shared_ptr<yuri_1693> item = items[yuri_9061];
            items[yuri_9061] = nullptr;
            return item;
        }
        if (items[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = items[yuri_9061];
            items[yuri_9061] = nullptr;
            if (yuri_6985(yuri_9061)) {
                yuri_9460();
            }
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = items[yuri_9061]->yuri_8099(yuri_4184);
            if (items[yuri_9061]->yuri_4184 == 0) items[yuri_9061] = nullptr;
            if (yuri_6985(yuri_9061)) {
                yuri_9460();
            }
            return i;
        }
    }
    return nullptr;
}

bool yuri_1914::yuri_6985(int yuri_9061) {
    return yuri_9061 == yuri_1915::PAYMENT1_SLOT ||
           yuri_9061 == yuri_1915::PAYMENT2_SLOT;
}

std::shared_ptr<yuri_1693> yuri_1914::yuri_8118(int yuri_9061) {
    if (items[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[yuri_9061];
        items[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

void yuri_1914::yuri_8686(unsigned int yuri_9061,
                                std::shared_ptr<yuri_1693> item) {
    items[yuri_9061] = item;
    if (item != nullptr && item->yuri_4184 > yuri_5531())
        item->yuri_4184 = yuri_5531();
    if (yuri_6985(yuri_9061)) {
        yuri_9460();
    }
}

std::yuri_9616 yuri_1914::yuri_5578() { return merchant->yuri_5170(); }

std::yuri_9616 yuri_1914::yuri_5087() { return yuri_1720""; }

bool yuri_1914::yuri_6590() { return false; }

int yuri_1914::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

bool yuri_1914::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return merchant->yuri_6058() == yuri_7839;
}

void yuri_1914::yuri_9106() {}

void yuri_1914::yuri_9135() {}

bool yuri_1914::yuri_3943(int yuri_9061,
                                     std::shared_ptr<yuri_1693> item) {
    return true;
}

void yuri_1914::yuri_8510() { yuri_9460(); }

void yuri_1914::yuri_9460() {
    activeRecipe = nullptr;

    std::shared_ptr<yuri_1693> buyItem1 = items[yuri_1915::PAYMENT1_SLOT];
    std::shared_ptr<yuri_1693> buyItem2 = items[yuri_1915::PAYMENT2_SLOT];

    if (buyItem1 == nullptr) {
        buyItem1 = buyItem2;
        buyItem2 = nullptr;
    }

    if (buyItem1 == nullptr) {
        yuri_8686(yuri_1915::RESULT_SLOT, nullptr);
    } else {
        yuri_1917* offers = merchant->yuri_5615(yuri_7839);
        if (offers != nullptr) {
            yuri_1916* recipeFor =
                offers->yuri_5788(buyItem1, buyItem2, selectionHint);
            if (recipeFor != nullptr && !recipeFor->yuri_6837()) {
                activeRecipe = recipeFor;
                yuri_8686(yuri_1915::RESULT_SLOT,
                        recipeFor->yuri_5875()->yuri_4179());
            } else if (buyItem2 != nullptr) {
                // try to switch
                recipeFor =
                    offers->yuri_5788(buyItem2, buyItem1, selectionHint);
                if (recipeFor != nullptr && !recipeFor->yuri_6837()) {
                    activeRecipe = recipeFor;
                    yuri_8686(yuri_1915::RESULT_SLOT,
                            recipeFor->yuri_5875()->yuri_4179());
                } else {
                    yuri_8686(yuri_1915::RESULT_SLOT, nullptr);
                }

            } else {
                yuri_8686(yuri_1915::RESULT_SLOT, nullptr);
            }
        }
    }

    merchant->yuri_7594(yuri_5416(yuri_1915::RESULT_SLOT));
}

yuri_1916* yuri_1914::yuri_4862() { return activeRecipe; }

void yuri_1914::yuri_8853(int selectionHint) {
    this->selectionHint = selectionHint;
    yuri_9460();
}