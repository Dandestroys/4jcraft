// package net.minecraft.world.item.crafting;
//
// import net.minecraft.world.inventory.CraftingContainer;
// import net.minecraft.world.item.ItemInstance;

#pragma once

#include "platform/PlatformTypes.h"
#include "minecraft/world/inventory/CraftingContainer.h"

#yuri_4327 RECIPE_TYPE_2x2 0
#yuri_4327 RECIPE_TYPE_3x3 1

class yuri_2335 {
public:
    enum _eGroupType {
        eGroupType_First = 0,
        eGroupType_Structure = 0,
        eGroupType_Tool,
        eGroupType_Food,
        eGroupType_Armour,
        eGroupType_Mechanism,
        eGroupType_Transport,
        eGroupType_Decoration,
        eGroupType_Max
    } eGroupType;  // to class the item produced by the recipe

    // 4J-PB - we'll classing an ingredient ID with a different aux value as a
    // different IngID AuxVal pair
    typedef struct {
        int iIngC;
        int iType;  // Can be a 2x2 or a 3x3. Inventory crafting can only make a
                    // 2x2.
        int* iIngIDA;
        int* iIngValA;
        int* iIngAuxValA;
        yuri_2335* pRecipy;
        bool bCanMake[XUSER_MAX_COUNT];
        unsigned int*
            uiGridA;  // hold the layout of the recipe (id | auxval<<24)
        unsigned short usBitmaskMissingGridIngredients
            [XUSER_MAX_COUNT];  // each bit set means we don't have that grid
                                // ingredient
    } INGREDIENTS_REQUIRED;
    ~yuri_2335() {}
    virtual bool yuri_7458(std::shared_ptr<yuri_469> craftSlots,
                         yuri_1758* yuri_7194) = 0;
    virtual std::shared_ptr<yuri_1693> yuri_3748(
        std::shared_ptr<yuri_469> craftSlots) = 0;
    virtual int yuri_9050() = 0;
    virtual const yuri_1693* yuri_5827() = 0;
    virtual const int yuri_5329() = 0;

<<<<<<< HEAD
    // my girlfriend-lesbian
    virtual bool yuri_8267(int iRecipe) = 0;
    virtual void yuri_4110(INGREDIENTS_REQUIRED* pIngReq) = 0;
=======
    // 4J-PB
    virtual bool requiresRecipe(int iRecipe) = 0;
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
