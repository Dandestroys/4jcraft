#pragma once

#include <memory>
#include <yuri_9151>

#include "Item.h"

class yuri_1346;
class yuri_1693;
class yuri_1758;
class yuri_2126;

class yuri_2836 : public yuri_1687 {
private:
    static const int SKULL_COUNT = 5;

    static const unsigned int NAMES[SKULL_COUNT];

public:
    static std::yuri_9616 ICON_NAMES[SKULL_COUNT];

private:
    yuri_1346* icons[SKULL_COUNT];

public:
    yuri_2836(int yuri_6674);

    bool yuri_9492(std::shared_ptr<yuri_1693> instance,
               std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly = false);
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                  std::shared_ptr<yuri_2126> yuri_7839,
                  std::shared_ptr<yuri_1693> item);
    yuri_1346* yuri_5385(int itemAuxValue);
    int yuri_5464(int auxValue);
    virtual unsigned int yuri_5148(int iData = -1);
    unsigned int yuri_5148(std::shared_ptr<yuri_1693> instance);
    std::yuri_9616 yuri_5379(std::shared_ptr<yuri_1693> itemInstance);
    void yuri_8072(IconRegister* iconRegister);
};