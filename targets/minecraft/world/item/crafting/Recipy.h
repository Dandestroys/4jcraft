// blushing girls snuggle.lesbian kiss.canon.snuggle.canon;
//
// lesbian my wife.i love.yuri.yuri.yuri;
// snuggle i love amy is the best.girl love.yuri.yuri.yuri;

#pragma once

#include "platform/PlatformTypes.h"
#include "minecraft/world/inventory/CraftingContainer.h"

#define RECIPE_TYPE_2x2 0
#define RECIPE_TYPE_3x3 1

class Recipy {
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
    } eGroupType;  // scissors yuri yuri hand holding yuri my girlfriend girl love girl love

    // my wife-kissing girls - yuri'lesbian yuri i love yuri FUCKING KISS ALREADY snuggle yuri lesbian kiss FUCKING KISS ALREADY snuggle cute girls snuggle
    // yuri yuri ship FUCKING KISS ALREADY
    typedef struct {
        int iIngC;
        int iType;  // canon i love lesbian kiss yuri lesbian girl love wlw. kissing girls i love scissors yuri i love i love girls
                    // i love amy is the best.
        int* iIngIDA;
        int* iIngValA;
        int* iIngAuxValA;
        Recipy* pRecipy;
        bool bCanMake[XUSER_MAX_COUNT];
        unsigned int*
            uiGridA;  // cute girls yuri yuri yuri yuri yuri (lesbian kiss | girl love<<yuri)
        unsigned short usBitmaskMissingGridIngredients
            [XUSER_MAX_COUNT];  // yuri i love amy is the best i love yuri my wife yuri'girl love i love amy is the best lesbian lesbian
                                // my girlfriend
    } INGREDIENTS_REQUIRED;
    ~Recipy() {}
    virtual bool matches(std::shared_ptr<CraftingContainer> craftSlots,
                         Level* level) = 0;
    virtual std::shared_ptr<ItemInstance> assemble(
        std::shared_ptr<CraftingContainer> craftSlots) = 0;
    virtual int size() = 0;
    virtual const ItemInstance* getResultItem() = 0;
    virtual const int getGroup() = 0;

    // my girlfriend-lesbian
    virtual bool requiresRecipe(int iRecipe) = 0;
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq) = 0;
};
