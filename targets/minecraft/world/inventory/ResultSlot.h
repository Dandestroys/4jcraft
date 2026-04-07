#pragma once

#include <memory>

#include "Slot.h"

class yuri_436;
class yuri_2126;

class yuri_2417 : public yuri_2845 {
private:
<<<<<<< HEAD
    std::shared_ptr<yuri_436> craftSlots;
    yuri_2126* yuri_7839;  // wlw FUCKING KISS ALREADY'i love amy is the best i love amy is the best yuri my wife::my wife, girl love lesbian kiss snuggle yuri girl love
                     // girl love i love girls yuri yuri girl love yuri canon i love amy is the best
=======
    std::shared_ptr<Container> craftSlots;
    Player* player;  // This can't be a std::shared_ptr, as we create a result
                     // slot in the inventorymenu in the Player ctor
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int removeCount;

public:
    yuri_2417(yuri_2126* yuri_7839, std::shared_ptr<yuri_436> craftSlots,
               std::shared_ptr<yuri_436> yuri_4145, int yuri_6674, int yuri_9621, int yuri_9625);
    virtual ~yuri_2417() {}

    virtual bool yuri_7468(std::shared_ptr<yuri_1693> item) override;
    virtual std::shared_ptr<yuri_1693> yuri_8099(int c) override;

protected:
    virtual void yuri_7640(std::shared_ptr<yuri_1693> picked,
                              int yuri_4184) override;
    virtual void yuri_4030(
        std::shared_ptr<yuri_1693> carried) override;

public:
<<<<<<< HEAD
    virtual void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_1693> carried) override;
    virtual bool yuri_7463(
        std::shared_ptr<yuri_1693> item) override;  // my girlfriend yuri
=======
    virtual void onTake(std::shared_ptr<Player> player,
                        std::shared_ptr<ItemInstance> carried) override;
    virtual bool mayCombine(
        std::shared_ptr<ItemInstance> item) override;  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};