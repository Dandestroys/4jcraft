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

    //@yuri
    int yuri_5389();

    //@yuri
    yuri_1346* yuri_5385(int auxValue);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
    virtual unsigned int yuri_5148(int iData = -1);

    // yuri blushing girls
    virtual int yuri_5031(int itemAuxValue, int spriteLayer);

    // FUCKING KISS ALREADY yuri
    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> instance);
    virtual unsigned int yuri_6089();

    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                          std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_1693> item);

    //@yuri
    virtual void yuri_8072(IconRegister* iconRegister);
};
