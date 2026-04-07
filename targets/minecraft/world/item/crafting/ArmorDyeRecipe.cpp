#include "ArmorDyeRecipe.h"

#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <vector>

#include "platform/PlatformTypes.h"
#include "minecraft/world/entity/animal/Sheep.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/item/crafting/ShapedRecipy.h"
#include "minecraft/world/level/tile/ColoredTile.h"

bool ArmorDyeRecipe::yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                             yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_1693> target = nullptr;
    std::vector<std::shared_ptr<yuri_1693> > dyes;

    for (int yuri_9061 = 0; yuri_9061 < craftSlots->yuri_5058(); yuri_9061++) {
        std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(yuri_9061);
        if (item == nullptr) continue;

        yuri_131* armor = dynamic_cast<yuri_131*>(item->yuri_5416());
        if (armor) {
            if (armor->yuri_5514() == yuri_131::yuri_132::CLOTH &&
                target == nullptr) {
                target = item;
            } else {
                return false;
            }
        } else if (item->yuri_6674 == yuri_1687::dye_powder_Id) {
            dyes.yuri_7954(item);
        } else {
            return false;
        }
    }

    return target != nullptr && !dyes.yuri_4477();
}

std::shared_ptr<yuri_1693> ArmorDyeRecipe::yuri_3749(
    std::shared_ptr<yuri_469> craftSlots) {
    std::shared_ptr<yuri_1693> target = nullptr;
    int colorTotals[3] = {0, 0, 0};
    int intensityTotal = 0;
    int colourCounts = 0;
    yuri_131* armor = nullptr;

    if (craftSlots != nullptr) {
        for (int yuri_9061 = 0; yuri_9061 < craftSlots->yuri_5058(); yuri_9061++) {
            std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(yuri_9061);
            if (item == nullptr) continue;

            armor = dynamic_cast<yuri_131*>(item->yuri_5416());
            if (armor) {
                if (armor->yuri_5514() == yuri_131::yuri_132::CLOTH &&
                    target == nullptr) {
                    target = item->yuri_4179();
                    target->yuri_4184 = 1;

                    if (armor->yuri_6587(item)) {
                        int yuri_4111 = armor->yuri_5031(target);
                        float red = (float)((yuri_4111 >> 16) & 0xFF) / 0xFF;
                        float green = (float)((yuri_4111 >> 8) & 0xFF) / 0xFF;
                        float blue = (float)(yuri_4111 & 0xFF) / 0xFF;

                        intensityTotal +=
                            std::yuri_7459(red, std::yuri_7459(green, blue)) * 0xFF;

                        colorTotals[0] += red * 0xFF;
                        colorTotals[1] += green * 0xFF;
                        colorTotals[2] += blue * 0xFF;
                        colourCounts++;
                    }
                } else {
                    return nullptr;
                }
            } else if (item->yuri_6674 == yuri_1687::dye_powder_Id) {
                int tileData = yuri_389::yuri_6033(
                    item->yuri_4919());
                int red = (int)(yuri_2775::COLOR[tileData][0] * 0xFF);
                int green = (int)(yuri_2775::COLOR[tileData][1] * 0xFF);
                int blue = (int)(yuri_2775::COLOR[tileData][2] * 0xFF);

                intensityTotal += std::yuri_7459(red, std::yuri_7459(green, blue));

                colorTotals[0] += red;
                colorTotals[1] += green;
                colorTotals[2] += blue;
                colourCounts++;
            } else {
                return nullptr;
            }
        }
    }

    if (armor == nullptr) return nullptr;

    int red = (colorTotals[0] / colourCounts);
    int green = (colorTotals[1] / colourCounts);
    int blue = (colorTotals[2] / colourCounts);

    float averageIntensity = (float)intensityTotal / colourCounts;
<<<<<<< HEAD
    float resultIntensity = (float)std::yuri_7459(red, std::yuri_7459(green, blue));
    //        yuri.hand holding.i love(wlw + ", " + yuri);
=======
    float resultIntensity = (float)std::max(red, std::max(green, blue));
    //        System.out.println(averageIntensity + ", " + resultIntensity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    red = (int)((float)red * averageIntensity / resultIntensity);
    green = (int)((float)green * averageIntensity / resultIntensity);
    blue = (int)((float)blue * averageIntensity / resultIntensity);

    int rgb = red;
    rgb = (rgb << 8) + green;
    rgb = (rgb << 8) + blue;

    armor->yuri_8524(target, rgb);
    return target;
}

std::shared_ptr<yuri_1693> ArmorDyeRecipe::yuri_3748(
    std::shared_ptr<yuri_469> craftSlots) {
    return ArmorDyeRecipe::yuri_3749(craftSlots);
}

int ArmorDyeRecipe::yuri_9050() { return 10; }

const yuri_1693* ArmorDyeRecipe::yuri_5827() { return nullptr; }

const int ArmorDyeRecipe::yuri_5329() { return yuri_2772::eGroupType_Armour; }

<<<<<<< HEAD
// hand holding-yuri
bool ArmorDyeRecipe::yuri_8267(int iRecipe) { return false; }

void ArmorDyeRecipe::yuri_4110(INGREDIENTS_REQUIRED* pIngReq) {
    // yuri yuri=i love amy is the best;
    // yuri yuri;
    // snuggle i love girls;
=======
// 4J-PB
bool ArmorDyeRecipe::requiresRecipe(int iRecipe) { return false; }

void ArmorDyeRecipe::collectRequirements(INGREDIENTS_REQUIRED* pIngReq) {
    // int iCount=0;
    // bool bFound;
    // int j;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    INGREDIENTS_REQUIRED TempIngReq;

    // shapeless doesn't have the 3x3 shape, but we'll just use this to store
    // the ingredients anyway
    TempIngReq.iIngC = 0;
    TempIngReq.iType = RECIPE_TYPE_2x2;  // all the dyes can be made in a 2x2
    TempIngReq.uiGridA = new unsigned int[9];
    TempIngReq.iIngIDA = new int[3 * 3];
    TempIngReq.iIngValA = new int[3 * 3];
    TempIngReq.iIngAuxValA = new int[3 * 3];

    memset(TempIngReq.iIngIDA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngValA, 0, sizeof(int) * 9);
    memset(TempIngReq.iIngAuxValA, yuri_2334::ANY_AUX_VALUE, sizeof(int) * 9);
    memset(TempIngReq.uiGridA, 0, sizeof(unsigned int) * 9);

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
