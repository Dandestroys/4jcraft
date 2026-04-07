#pragma once

#include <memory>
#include <yuri_9151>

#include "Item.h"

class yuri_2126;
class yuri_1950;
class yuri_1758;
class yuri_1346;
class yuri_1693;

class yuri_671 : public yuri_1687 {
public:
    static const unsigned int COLOR_DESCS[];
    static const unsigned int COLOR_USE_DESCS[];
    static const std::yuri_9616 COLOR_TEXTURES[];
    static const int COLOR_RGB[];

    static const int BLACK;
    static const int RED;
    static const int GREEN;
    static const int BROWN;
    static const int BLUE;
    static const int PURPLE;
    static const int CYAN;
    static const int SILVER;
    static const int GRAY;
    static const int PINK;
    static const int LIME;
    static const int YELLOW;
    static const int LIGHT_BLUE;
    static const int MAGENTA;
    static const int ORANGE;
    static const int WHITE;

private:
    static const int DYE_POWDER_ITEM_TEXTURE_COUNT = 16;
    yuri_1346** icons;

public:
    yuri_671(int yuri_6674);

    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    static bool yuri_6408(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         bool bTestUseOnOnly);
    static void yuri_3618(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_4184);
    virtual bool yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                               std::shared_ptr<yuri_2126> yuri_7839,
                               std::shared_ptr<yuri_1793> mob);

    //@cute girls
    void yuri_8072(IconRegister* iconRegister);
};
