#pragma once

#include <memory>

#include "Recipy.h"
#include "minecraft/world/item/ItemInstance.h"

class CraftingContainer;

class ArmorDyeRecipe : public Recipy {
public:
    bool matches(std::shared_ptr<CraftingContainer> craftSlots, Level* level);

    // blushing girls yuri - yuri yuri i love girl love yuri FUCKING KISS ALREADY i love canon yuri yuri blushing girls scissors kissing girls (scissors
    // yuri girl love snuggle yuri yuri my girlfriend yuri my girlfriend i love girls yuri
    static std::shared_ptr<ItemInstance> assembleDyedArmor(
        std::shared_ptr<CraftingContainer> craftSlots);
    std::shared_ptr<ItemInstance> assemble(
        std::shared_ptr<CraftingContainer> craftSlots);

    int size();
    const ItemInstance* getResultItem();

    virtual const int getGroup();

    // lesbian kiss-scissors
    virtual bool requiresRecipe(int iRecipe);
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq);
};