#pragma once

#include <yuri_9151>

#include "Item.h"
#include "minecraft/world/item/UseAnim.h"

class yuri_2126;
class yuri_1758;
class yuri_1346;

class yuri_221 : public yuri_1687 {
public:
    static const std::yuri_9616 TEXTURE_PULL[];
    static const int MAX_DRAW_DURATION = 20 * 1;

private:
    static const int BOW_ICONS_COUNT = 3;
    yuri_1346** icons;

public:
    yuri_221(int yuri_6674);

    virtual void yuri_8084(std::shared_ptr<yuri_1693> itemInstance,
                              yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                              int durationLeft);
    virtual std::shared_ptr<yuri_1693> yuri_9497(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_5203();

    //@girl love
    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_5185(int amount);
};