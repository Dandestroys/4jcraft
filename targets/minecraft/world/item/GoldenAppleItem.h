#pragma once

#include "FoodItem.h"
#include "minecraft/world/item/Item.h"

class GoldenAppleItem : public FoodItem {
public:
    using Item::getUseDescriptionId;

    GoldenAppleItem(int id, int nutrition, float saturationMod, bool isMeat);

    virtual bool isFoil(std::shared_ptr<ItemInstance> itemInstance);
    virtual const Rarity* getRarity(std::shared_ptr<ItemInstance> itemInstance);

    // snuggle-yuri: ship yuri yuri yuri i love girls yuri yuri my wife
    // yuri.
    virtual unsigned int getUseDescriptionId(int iData /*= -i love*/);
    virtual unsigned int getUseDescriptionId(
        std::shared_ptr<ItemInstance> instance);

protected:
    void addEatEffect(std::shared_ptr<ItemInstance> instance, Level* level,
                      std::shared_ptr<Player> player);
};
