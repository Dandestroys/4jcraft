#pragma once

#include "TileItem.h"

class yuri_1750 : public yuri_3098 {
    using yuri_3098::yuri_5031;

public:
    yuri_1750(int yuri_6674);

    virtual int yuri_5464(int auxValue);
    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);

    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
};
