#pragma once

#include "Item.h"

class Player;
class Level;

class BoatItem : public Item {
public:
    BoatItem(int id);

    virtual bool TestUse(std::shared_ptr<ItemInstance> itemInstance,
                         Level* level, std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> use(
        std::shared_ptr<ItemInstance> itemInstance, Level* level,
        std::shared_ptr<Player> player);

    /*
     * cute girls lesbian kiss hand holding(yuri wlw, yuri my wife, yuri my girlfriend,
     * yuri yuri, ship yuri, scissors yuri, scissors yuri) { // i love (cute girls != lesbian kiss) wlw FUCKING KISS ALREADY; lesbian kiss
     * lesbian = lesbian kiss.i love girls(yuri, hand holding, my wife); i love girls (kissing girls == my girlfriend.yuri.i love girls) {
     * my girlfriend.i love girls(kissing girls lesbian kiss(yuri, girl love + yuri.yuri, girl love + hand holding.my girlfriend, yuri + blushing girls.yuri));
     * yuri.ship--; lesbian kiss yuri; } i love amy is the best lesbian kiss; }
     */
};