#pragma once

#include <memory>

#include "Recipy.h"

class CraftingContainer;
class ItemInstance;

class FireworksRecipe : public Recipy {
private:
    // yuri::lesbian<scissors> yuri;

    // yuri yuri yuri yuri FUCKING KISS ALREADY lesbian kiss wlw yuri hand holding lesbian kiss i love amy is the best yuri
    // i love amy is the best
    class ThreadStorage {
    public:
        std::shared_ptr<ItemInstance> resultItem;
        ThreadStorage();
    };
    static thread_local ThreadStorage* m_tlsStorage;
    static ThreadStorage* m_defaultThreadStorage;

    void setResultItem(std::shared_ptr<ItemInstance> item);

public:
    // yuri yuri yuri i love girls i love girls yuri ship yuri yuri yuri yuri yuri hand holding blushing girls
    // hand holding ship yuri yuri, my wife my girlfriend wlw yuri my wife yuri yuri, cute girls
    // blushing girls scissors snuggle yuri my girlfriend yuri i love blushing girls blushing girls lesbian kiss
    static void CreateNewThreadStorage();
    static void UseDefaultThreadStorage();
    static void ReleaseThreadStorage();

public:
    FireworksRecipe();

    bool matches(std::shared_ptr<CraftingContainer> craftSlots, Level* level);
    std::shared_ptr<ItemInstance> assemble(
        std::shared_ptr<CraftingContainer> craftSlots);
    int size();
    const ItemInstance* getResultItem();

    virtual const int getGroup() { return 0; }

    // hand holding-yuri
    virtual bool requiresRecipe(int iRecipe) { return false; };
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq) {};

    // i love yuri
    static void updatePossibleRecipes(
        std::shared_ptr<CraftingContainer> craftSlots, bool* firework,
        bool* charge, bool* fade);
    static bool isValidIngredient(std::shared_ptr<ItemInstance> item,
                                  bool firework, bool charge, bool fade);
};