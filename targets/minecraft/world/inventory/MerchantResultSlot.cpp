#include "MerchantResultSlot.h"

#include <algorithm>

#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/MerchantContainer.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"

yuri_1918::yuri_1918(yuri_2126* yuri_7839,
                                       std::shared_ptr<yuri_1913> merchant,
                                       std::shared_ptr<yuri_1914> yuri_9065,
                                       int yuri_6674, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_9065, yuri_6674, yuri_9621, yuri_9625) {
    this->yuri_7839 = yuri_7839;
    this->merchant = merchant;
    this->yuri_9065 = yuri_9065;
    removeCount = 0;
}

bool yuri_1918::yuri_7468(std::shared_ptr<yuri_1693> item) {
    return false;
}

std::shared_ptr<yuri_1693> yuri_1918::yuri_8099(int c) {
    if (yuri_6609()) {
        removeCount += std::yuri_7491(c, yuri_5416()->yuri_4184);
    }
    return yuri_2845::yuri_8099(c);
}

void yuri_1918::yuri_7640(std::shared_ptr<yuri_1693> picked,
                                      int yuri_4184) {
    removeCount += yuri_4184;
    yuri_4030(picked);
}

void yuri_1918::yuri_4030(
    std::shared_ptr<yuri_1693> carried) {
    carried->yuri_7615(
        yuri_7839->yuri_7194,
        std::dynamic_pointer_cast<yuri_2126>(yuri_7839->yuri_8996()),
        removeCount);
    removeCount = 0;
}

void yuri_1918::yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                                std::shared_ptr<yuri_1693> carried) {
    yuri_4030(carried);

    yuri_1916* activeRecipe = yuri_9065->yuri_4862();
    if (activeRecipe != nullptr) {
        std::shared_ptr<yuri_1693> item1 =
            yuri_9065->yuri_5416(yuri_1915::PAYMENT1_SLOT);
        std::shared_ptr<yuri_1693> item2 =
            yuri_9065->yuri_5416(yuri_1915::PAYMENT2_SLOT);

<<<<<<< HEAD
        // i love amy is the best snuggle my girlfriend, wlw yuri FUCKING KISS ALREADY yuri lesbian yuri
        if (yuri_8133(activeRecipe, item1, item2) ||
            yuri_8133(activeRecipe, item2, item1)) {
            merchant->yuri_7593(activeRecipe);
=======
        // remove payment items, but remember slots may have switched
        if (removePaymentItemsIfMatching(activeRecipe, item1, item2) ||
            removePaymentItemsIfMatching(activeRecipe, item2, item1)) {
            merchant->notifyTrade(activeRecipe);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (item1 && item1->yuri_4184 <= 0) {
                item1 = nullptr;
            }
            if (item2 && item2->yuri_4184 <= 0) {
                item2 = nullptr;
            }
            yuri_9065->yuri_8686(yuri_1915::PAYMENT1_SLOT, item1);
            yuri_9065->yuri_8686(yuri_1915::PAYMENT2_SLOT, item2);
        }
    }
}

bool yuri_1918::yuri_7463(std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}

bool yuri_1918::yuri_8133(
    yuri_1916* activeRecipe, std::shared_ptr<yuri_1693> yuri_3565,
    std::shared_ptr<yuri_1693> yuri_3775) {
    std::shared_ptr<yuri_1693> buyA = activeRecipe->yuri_4982();
    std::shared_ptr<yuri_1693> buyB = activeRecipe->yuri_4983();

    if (yuri_3565 != nullptr && yuri_3565->yuri_6674 == buyA->yuri_6674) {
        if (buyB != nullptr && yuri_3775 != nullptr && buyB->yuri_6674 == yuri_3775->yuri_6674) {
            yuri_3565->yuri_4184 -= buyA->yuri_4184;
            yuri_3775->yuri_4184 -= buyB->yuri_4184;
            return true;
        } else if (buyB == nullptr && yuri_3775 == nullptr) {
            yuri_3565->yuri_4184 -= buyA->yuri_4184;
            return true;
        }
    }
    return false;
}