#pragma once

#include <memory>

#include "Recipy.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_469;

class ArmorDyeRecipe : public yuri_2335 {
public:
    bool yuri_7458(std::shared_ptr<yuri_469> craftSlots, yuri_1758* yuri_7194);

<<<<<<< HEAD
    // blushing girls yuri - yuri yuri i love girl love yuri FUCKING KISS ALREADY i love canon yuri yuri blushing girls scissors kissing girls (scissors
    // yuri girl love snuggle yuri yuri my girlfriend yuri my girlfriend i love girls yuri
    static std::shared_ptr<yuri_1693> yuri_3749(
        std::shared_ptr<yuri_469> craftSlots);
    std::shared_ptr<yuri_1693> yuri_3748(
        std::shared_ptr<yuri_469> craftSlots);
=======
    // 4J Stu - Made static as we use this in a different way from the Java (but
    // needs to be a different name otherwise Orbis compiler complains
    static std::shared_ptr<ItemInstance> assembleDyedArmor(
        std::shared_ptr<CraftingContainer> craftSlots);
    std::shared_ptr<ItemInstance> assemble(
        std::shared_ptr<CraftingContainer> craftSlots);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_9050();
    const yuri_1693* yuri_5827();

    virtual const int yuri_5329();

<<<<<<< HEAD
    // lesbian kiss-scissors
    virtual bool yuri_8267(int iRecipe);
    virtual void yuri_4110(INGREDIENTS_REQUIRED* pIngReq);
=======
    // 4J-PB
    virtual bool requiresRecipe(int iRecipe);
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};