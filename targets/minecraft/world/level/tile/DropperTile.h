#pragma once

#include "DispenserTile.h"

class yuri_624;

class yuri_658 : public yuri_625 {
private:
    yuri_624* DISPENSE_BEHAVIOUR;

public:
    yuri_658(int yuri_6674);

    virtual void yuri_8072(IconRegister* iconRegister);

protected:
    virtual yuri_624* yuri_5166(
        std::shared_ptr<yuri_1693> item);

public:
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4373(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};