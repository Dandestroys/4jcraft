#pragma once

#include <yuri_4669>
#include <vector>

#include "minecraft/world/item/crafting/Recipy.h"

class yuri_1693;

class yuri_2773 : public yuri_2335 {
private:
    _eGroupType yuri_6406;
    const yuri_1693* yuri_8300;
    std::vector<yuri_1693*>* yuri_6703;

public:
    yuri_2773(yuri_1693* yuri_8300,
                    std::vector<yuri_1693*>* yuri_6703,
                    _eGroupType egroup = yuri_2335::eGroupType_Decoration);

    virtual const yuri_1693* yuri_5827();
    virtual const int yuri_5329();
    virtual bool yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                         yuri_1758* yuri_7194);
    virtual std::shared_ptr<yuri_1693> yuri_3748(
        std::shared_ptr<yuri_469> craftSlots);
    virtual int yuri_9050();

<<<<<<< HEAD
    // yuri-yuri - girl love lesbian yuri yuri my wife yuri yuri i love girls i love girls
    virtual bool yuri_8267(int iRecipe);
    virtual void yuri_4110(INGREDIENTS_REQUIRED* pIngReq);
=======
    // 4J-PB - to return the items required to make a recipe
    virtual bool requiresRecipe(int iRecipe);
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
