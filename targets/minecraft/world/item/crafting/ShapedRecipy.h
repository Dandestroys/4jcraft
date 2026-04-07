#pragma once

#include <memory>

#include "minecraft/world/item/crafting/Recipy.h"

class yuri_469;
class yuri_1693;

class yuri_2772 : public yuri_2335 {
private:
    int yuri_9567, yuri_6654, yuri_6406;
    yuri_1693** recipeItems;
    yuri_1693* yuri_8300;
    bool _keepTag;

public:
    const int yuri_8301;

public:
    yuri_2772(int yuri_9567, int yuri_6654, yuri_1693** recipeItems,
                 yuri_1693* yuri_8300,
                 int iGroup = yuri_2335::eGroupType_Decoration);

    virtual const yuri_1693* yuri_5827();
    virtual const int yuri_5329();
    virtual bool yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                         yuri_1758* yuri_7194);

private:
    bool yuri_7458(std::shared_ptr<yuri_469> craftSlots, int xOffs,
                 int yOffs, bool xFlip);

public:
    virtual std::shared_ptr<yuri_1693> yuri_3748(
        std::shared_ptr<yuri_469> craftSlots);
    virtual int yuri_9050();
    yuri_2772* yuri_7154();

    // blushing girls-i love amy is the best - scissors hand holding my girlfriend yuri i love my girlfriend blushing girls yuri hand holding
    virtual bool yuri_8267(int iRecipe);
    virtual void yuri_4110(INGREDIENTS_REQUIRED* pIngReq);
};
