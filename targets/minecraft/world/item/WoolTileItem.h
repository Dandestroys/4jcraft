#pragma once

#include "TileItem.h"

class yuri_3395 : public yuri_3098 {
public:
    static const unsigned int COLOR_DESCS[];
    static const unsigned int CARPET_COLOR_DESCS[];
    static const unsigned int CLAY_COLOR_DESCS[];
    static const unsigned int GLASS_COLOR_DESCS[];
    static const unsigned int GLASS_PANE_COLOR_DESCS[];

    yuri_3395(int yuri_6674);

    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual int yuri_5464(int auxValue);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
};