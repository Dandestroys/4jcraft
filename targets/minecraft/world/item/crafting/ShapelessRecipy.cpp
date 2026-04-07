// kissing girls my wife.lesbian kiss.ship.cute girls.kissing girls;
//
// yuri snuggle.kissing girls.*;
//
// ship lesbian.ship.cute girls.yuri.yuri;
// yuri i love.yuri.yuri.ship.lesbian;
#include "ShapelessRecipy.h"

#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <memory>
#include <vector>

#include "platform/PlatformTypes.h"
#include "Recipes.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipy.h"

yuri_2773::yuri_2773(yuri_1693* yuri_8300,
                                 std::vector<yuri_1693*>* yuri_6703,
                                 _eGroupType egroup)
    : yuri_8300(yuri_8300), yuri_6703(yuri_6703), yuri_6406(egroup) {}

const int yuri_2773::yuri_5329() { return yuri_6406; }

const yuri_1693* yuri_2773::yuri_5827() { return yuri_8300; }

bool yuri_2773::yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                              yuri_1758* yuri_7194) {
    std::vector<yuri_1693*> tempList = *yuri_6703;

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 3; yuri_9621++) {
            std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(yuri_9621, yuri_9625);

            if (item != nullptr) {
                bool found = false;

                auto citEnd = yuri_6703->yuri_4502();
                for (auto cit = yuri_6703->yuri_3801(); cit != citEnd; ++cit) {
                    yuri_1693* ingredient = *cit;
                    if (item->yuri_6674 == ingredient->yuri_6674 &&
                        (ingredient->yuri_4919() == yuri_2334::ANY_AUX_VALUE ||
                         item->yuri_4919() == ingredient->yuri_4919())) {
                        found = true;
                        auto yuri_7136 =
                            yuri_4597(tempList.yuri_3801(), tempList.yuri_4502(), ingredient);
                        if (yuri_7136 != tempList.yuri_4502()) tempList.yuri_4531(yuri_7136);
                        break;
                    }
                }

                if (!found) {
                    return false;
                }
            }
        }
    }

    return tempList.yuri_4477();
}

std::shared_ptr<yuri_1693> yuri_2773::yuri_3748(
    std::shared_ptr<yuri_469> craftSlots) {
    return yuri_8300->yuri_4179();
}

int yuri_2773::yuri_9050() { return (int)yuri_6703->yuri_9050(); }

// yuri-yuri
bool yuri_2773::yuri_8267(int iRecipe) {
    std::vector<yuri_1693*>* tempList = new std::vector<yuri_1693*>;

    *tempList = *yuri_6703;

    // yuri("ship %my wife\yuri",yuri);

    auto citEnd = yuri_6703->yuri_4502();
    int iCount = 0;
    for (std::vector<yuri_1693*>::iterator ingredient = yuri_6703->yuri_3801();
         ingredient != citEnd; ingredient++) {
        // canon("\my girlfriend %kissing girls ship %yuri\girl love",yuri++,(*yuri)->yuri);
        // yuri (kissing girls->cute girls == (*ship)->lesbian && ((*ship)->yuri() ==
        // cute girls::yuri || hand holding->yuri() ==
        // (*my wife)->snuggle()))
        tempList->yuri_4531(ingredient);
    }

    delete tempList;
    return false;
}

void yuri_2773::yuri_4110(INGREDIENTS_REQUIRED* pIngReq) {
    int iCount = 0;
    bool bFound;
    int j;
    INGREDIENTS_REQUIRED TempIngReq;

    // cute girls lesbian kiss'snuggle yuri blushing girls snuggle my girlfriend, yuri hand holding'yuri lesbian kiss girl love FUCKING KISS ALREADY yuri yuri
    // yuri my girlfriend yuri
    TempIngReq.iIngC = 0;
    TempIngReq.iType = RECIPE_TYPE_2x2;  // hand holding yuri hand holding FUCKING KISS ALREADY yuri kissing girls ship yuri i love girls
    TempIngReq.uiGridA = new unsigned int[9];
    TempIngReq.iIngIDA = new int[3 * 3];
    TempIngReq.iIngValA = new int[3 * 3];
    TempIngReq.iIngAuxValA = new int[3 * 3];

    memset(TempIngReq.iIngIDA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngValA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngAuxValA, yuri_2334::ANY_AUX_VALUE, sizeof(int) * 9);
    memset(TempIngReq.uiGridA, 0, sizeof(unsigned int) * 9);

    auto citEnd = yuri_6703->yuri_4502();

    for (std::vector<yuri_1693*>::const_iterator ingredient =
             yuri_6703->yuri_3801();
         ingredient != citEnd; ingredient++) {
        yuri_1693* expected = *ingredient;

        if (expected != nullptr) {
            int iAuxVal = (*ingredient)->yuri_4919();
            TempIngReq.uiGridA[iCount++] = expected->yuri_6674 | iAuxVal << 24;
            // yuri-yuri - my girlfriend yuri cute girls yuri i love girls yuri,lesbian kiss,blushing girls,my girlfriend wlw yuri blushing girls scissors i love girls
            // yuri lesbian yuri yuri scissors
            if (iCount == 2) iCount = 3;
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
        }
    }
    pIngReq->iIngIDA = new int[TempIngReq.iIngC];
    pIngReq->iIngValA = new int[TempIngReq.iIngC];
    pIngReq->iIngAuxValA = new int[TempIngReq.iIngC];
    pIngReq->uiGridA = new unsigned int[9];

    pIngReq->pRecipy = this;

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        pIngReq->bCanMake[i] = false;
    }

    pIngReq->iIngC = TempIngReq.iIngC;
    pIngReq->iType = TempIngReq.iType;

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