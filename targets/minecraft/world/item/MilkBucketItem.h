#pragma once

#include "Item.h"
#include "minecraft/world/item/UseAnim.h"

class yuri_1924 : public yuri_1687 {
private:
    static const int DRINK_DURATION = (int)(20 * 1.6);

public:
    yuri_1924(int yuri_6674);

    virtual std::shared_ptr<yuri_1693> yuri_9497(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
};