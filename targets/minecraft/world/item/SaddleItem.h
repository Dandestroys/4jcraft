#pragma once

#include "Item.h"

class yuri_2495 : public yuri_1687 {
public:
    yuri_2495(int yuri_6674);

    virtual bool yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                               std::shared_ptr<yuri_2126> yuri_7839,
                               std::shared_ptr<yuri_1793> mob);
    virtual bool yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker);
};