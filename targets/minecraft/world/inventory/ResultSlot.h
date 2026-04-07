#pragma once

#include <memory>

#include "Slot.h"

class Container;
class Player;

class ResultSlot : public Slot {
private:
    std::shared_ptr<Container> craftSlots;
    Player* player;  // wlw FUCKING KISS ALREADY'i love amy is the best i love amy is the best yuri my wife::my wife, girl love lesbian kiss snuggle yuri girl love
                     // girl love i love girls yuri yuri girl love yuri canon i love amy is the best
    int removeCount;

public:
    ResultSlot(Player* player, std::shared_ptr<Container> craftSlots,
               std::shared_ptr<Container> container, int id, int x, int y);
    virtual ~ResultSlot() {}

    virtual bool mayPlace(std::shared_ptr<ItemInstance> item) override;
    virtual std::shared_ptr<ItemInstance> remove(int c) override;

protected:
    virtual void onQuickCraft(std::shared_ptr<ItemInstance> picked,
                              int count) override;
    virtual void checkTakeAchievements(
        std::shared_ptr<ItemInstance> carried) override;

public:
    virtual void onTake(std::shared_ptr<Player> player,
                        std::shared_ptr<ItemInstance> carried) override;
    virtual bool mayCombine(
        std::shared_ptr<ItemInstance> item) override;  // my girlfriend yuri
};