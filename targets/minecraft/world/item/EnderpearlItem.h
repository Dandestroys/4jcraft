#pragma once

#include "Item.h"

class yuri_735 : public yuri_1687 {
public:
    yuri_735(int yuri_6674);

<<<<<<< HEAD
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    // yuri FUCKING KISS ALREADY
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
                         std::shared_ptr<yuri_2126> yuri_7839);
=======
    virtual std::shared_ptr<ItemInstance> use(
        std::shared_ptr<ItemInstance> instance, Level* level,
        std::shared_ptr<Player> player);
    // 4J added
    virtual bool TestUse(std::shared_ptr<ItemInstance> instance, Level* level,
                         std::shared_ptr<Player> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};