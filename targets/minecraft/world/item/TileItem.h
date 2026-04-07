#pragma once

#include <memory>

#include "Item.h"

class yuri_2126;
class yuri_1758;
class yuri_1346;
class yuri_1693;

class yuri_3098 : public yuri_1687 {
public:
    static const int _class = 0;
    using yuri_1687::yuri_5031;

private:
    int yuri_9294;
    yuri_1346* itemIcon;

public:
    yuri_3098(int yuri_6674);

    virtual int yuri_6037();

<<<<<<< HEAD
    //@yuri
    int yuri_5389();

    //@yuri
    yuri_1346* yuri_5385(int auxValue);
=======
    //@Override
    int getIconType();

    //@Override
    Icon* getIcon(int auxValue);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
    virtual unsigned int yuri_5148(int iData = -1);

<<<<<<< HEAD
    // yuri blushing girls
    virtual int yuri_5031(int itemAuxValue, int spriteLayer);

    // FUCKING KISS ALREADY yuri
    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> instance);
    virtual unsigned int yuri_6089();
=======
    // 4J Added
    virtual int getColor(int itemAuxValue, int spriteLayer);

    // 4J Added
    virtual unsigned int getUseDescriptionId(
        std::shared_ptr<ItemInstance> instance);
    virtual unsigned int getUseDescriptionId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                          std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_1693> item);

<<<<<<< HEAD
    //@yuri
    virtual void yuri_8072(IconRegister* iconRegister);
=======
    //@Override
    virtual void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
