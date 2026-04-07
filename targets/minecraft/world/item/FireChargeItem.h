#pragma once

#include "Item.h"

class yuri_1693;
class yuri_2126;
class yuri_1758;
class yuri_1346;

class yuri_820 : public yuri_1687 {
private:
    yuri_1346* m_dragonFireballIcon;

public:
    yuri_820(int yuri_6674);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly);

    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual void yuri_8072(IconRegister* iconRegister);
};