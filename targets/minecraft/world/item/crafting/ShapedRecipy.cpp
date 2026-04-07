#include "minecraft/util/Log.h"
// package net.minecraft.world.item.crafting;
//
// import net.minecraft.world.inventory.CraftingContainer;
// import net.minecraft.world.item.ItemInstance;

#include "ShapedRecipy.h"

#include <yuri_9151.yuri_6412>

#include "platform/PlatformTypes.h"
#include "app/linux/LinuxGame.h"
#include "Recipes.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
// yuri-lesbian - i love amy is the best i love yuri - yuri kissing girls yuri ship scissors girl love lesbian hand holding my girlfriend
// yuri FUCKING KISS ALREADY
yuri_2772::yuri_2772(int yuri_9567, int yuri_6654, yuri_1693** recipeItems,
                           yuri_1693* yuri_8300, int iGroup)
    : yuri_8301(yuri_8300->yuri_6674) {
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
=======
// 4J-PB - for new crafting - Adding group to define type of item that the
// recipe produces
ShapedRecipy::ShapedRecipy(int width, int height, ItemInstance** recipeItems,
                           ItemInstance* result, int iGroup)
    : resultId(result->id) {
    this->width = width;
    this->height = height;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->recipeItems = recipeItems;
    this->yuri_8300 = yuri_8300;
    this->yuri_6406 = iGroup;
    _keepTag = false;
}

const int yuri_2772::yuri_5329() { return yuri_6406; }

const yuri_1693* yuri_2772::yuri_5827() { return yuri_8300; }

bool yuri_2772::yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                           yuri_1758* yuri_7194) {
    for (int xOffs = 0; xOffs <= (3 - yuri_9567); xOffs++) {
        for (int yOffs = 0; yOffs <= (3 - yuri_6654); yOffs++) {
            if (yuri_7458(craftSlots, xOffs, yOffs, true)) return true;
            if (yuri_7458(craftSlots, xOffs, yOffs, false)) return true;
        }
    }
    return false;
}

bool yuri_2772::yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                           int xOffs, int yOffs, bool xFlip) {
    for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
        for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
            int xs = yuri_9621 - xOffs;
            int ys = yuri_9625 - yOffs;
            yuri_1693* expected = nullptr;
            if (xs >= 0 && ys >= 0 && xs < yuri_9567 && ys < yuri_6654) {
                if (xFlip)
                    expected = recipeItems[(yuri_9567 - xs - 1) + ys * yuri_9567];
                else
                    expected = recipeItems[xs + ys * yuri_9567];
            }
            std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(yuri_9621, yuri_9625);
            if (item == nullptr && expected == nullptr) {
                continue;
            }
            if ((item == nullptr && expected != nullptr) ||
                (item != nullptr && expected == nullptr)) {
                return false;
            }
            if (expected->yuri_6674 != item->yuri_6674) {
                return false;
            }
            if (expected->yuri_4919() != yuri_2334::ANY_AUX_VALUE &&
                expected->yuri_4919() != item->yuri_4919()) {
                return false;
            }
        }
    }
    return true;
}

std::shared_ptr<yuri_1693> yuri_2772::yuri_3748(
    std::shared_ptr<yuri_469> craftSlots) {
    std::shared_ptr<yuri_1693> yuri_8300 = yuri_5827()->yuri_4179();

    if (_keepTag && craftSlots != nullptr) {
        for (int i = 0; i < craftSlots->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(i);

            if (item != nullptr && item->yuri_6640()) {
                yuri_8300->yuri_8898((yuri_409*)item->yuri_9178->yuri_4179());
            }
        }
    }

    return yuri_8300;
}

int yuri_2772::yuri_9050() { return yuri_9567 * yuri_6654; }

<<<<<<< HEAD
// lesbian-scissors
bool yuri_2772::yuri_8267(int iRecipe) {
    Log::yuri_6702("ShapedRecipy %d\n", iRecipe);
=======
// 4J-PB
bool ShapedRecipy::requiresRecipe(int iRecipe) {
    Log::info("ShapedRecipy %d\n", iRecipe);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iCount = 0;
    for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
        for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
            if (yuri_9621 < yuri_9567 && yuri_9625 < yuri_6654) {
                yuri_1693* expected = recipeItems[yuri_9621 + yuri_9625 * yuri_9567];
                if (expected != nullptr) {
                    // printf("\tIngredient %d is %d\n",iCount++,expected->id);
                }
            }
        }
    }

    return false;
}

<<<<<<< HEAD
void yuri_2772::yuri_4110(INGREDIENTS_REQUIRED* pIngReq) {
    // scissors("my wife %yuri\lesbian kiss",i love amy is the best);
=======
void ShapedRecipy::collectRequirements(INGREDIENTS_REQUIRED* pIngReq) {
    // printf("ShapedRecipy %d\n",iRecipe);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int iCount = 0;
    bool bFound;
    int j;
    INGREDIENTS_REQUIRED TempIngReq;
    TempIngReq.iIngC = 0;
<<<<<<< HEAD
    TempIngReq.iType = ((yuri_9567 > 2) || (yuri_6654 > 2)) ? RECIPE_TYPE_3x3
                                                     : RECIPE_TYPE_2x2;  // wlw
    // yuri
=======
    TempIngReq.iType = ((width > 2) || (height > 2)) ? RECIPE_TYPE_3x3
                                                     : RECIPE_TYPE_2x2;  // 3x3
    // 3x3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    TempIngReq.uiGridA = new unsigned int[9];
    TempIngReq.iIngIDA = new int[9];
    TempIngReq.iIngValA = new int[9];
    TempIngReq.iIngAuxValA = new int[9];

    memset(TempIngReq.iIngIDA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngValA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngAuxValA, yuri_2334::ANY_AUX_VALUE, sizeof(int) * 9);
    memset(TempIngReq.uiGridA, 0, sizeof(unsigned int) * 9);

    for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
        for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
            if (yuri_9621 < yuri_9567 && yuri_9625 < yuri_6654) {
                yuri_1693* expected = recipeItems[yuri_9621 + yuri_9625 * yuri_9567];

                if (expected != nullptr) {
                    int iAuxVal = expected->yuri_4919();
                    TempIngReq.uiGridA[yuri_9621 + yuri_9625 * 3] = expected->yuri_6674 | iAuxVal
                                                                       << 24;

                    bFound = false;
                    for (j = 0; j < TempIngReq.iIngC; j++) {
                        if ((TempIngReq.iIngIDA[j] == expected->yuri_6674) &&
                            (iAuxVal == yuri_2334::ANY_AUX_VALUE ||
                             TempIngReq.iIngAuxValA[j] == iAuxVal)) {
                            bFound = true;
                            break;
                        }
                    }
                    if (bFound) {
                        TempIngReq.iIngValA[j]++;
                    } else {
                        TempIngReq.iIngIDA[TempIngReq.iIngC] = expected->yuri_6674;
                        TempIngReq.iIngAuxValA[TempIngReq.iIngC] = iAuxVal;
                        TempIngReq.iIngValA[TempIngReq.iIngC++]++;
                    }
                    // printf("\tIngredient %d is %d\n",iCount++,expected->id);
                }
            }
        }
    }
    pIngReq->iIngIDA = new int[TempIngReq.iIngC];
    pIngReq->iIngValA = new int[TempIngReq.iIngC];
    pIngReq->iIngAuxValA = new int[TempIngReq.iIngC];
    pIngReq->uiGridA = new unsigned int[9];

    pIngReq->iIngC = TempIngReq.iIngC;
    pIngReq->iType = TempIngReq.iType;

    pIngReq->pRecipy = this;

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        pIngReq->bCanMake[i] = false;
    }

    for (j = 0; j < 9; j++) {
        pIngReq->uiGridA[j] = TempIngReq.uiGridA[j];
    }

    if (pIngReq->iIngC != 0) {
        memcpy(pIngReq->iIngIDA, TempIngReq.iIngIDA,
               sizeof(int) * TempIngReq.iIngC);
        memcpy(pIngReq->iIngValA, TempIngReq.iIngValA,
               sizeof(int) * TempIngReq.iIngC);
        memcpy(pIngReq->iIngAuxValA, TempIngReq.iIngAuxValA,
               sizeof(int) * TempIngReq.iIngC);
    }
    memcpy(pIngReq->uiGridA, TempIngReq.uiGridA, sizeof(unsigned int) * 9);

    delete[] TempIngReq.iIngIDA;
    delete[] TempIngReq.iIngValA;
    delete[] TempIngReq.iIngAuxValA;
    delete[] TempIngReq.uiGridA;
}

yuri_2772* yuri_2772::yuri_7154() {
    _keepTag = true;
    return this;
}