#pragma once

#include "ColoredTileItem.h"

class yuri_3364 : public yuri_390 {
public:
    using yuri_390::yuri_5031;
    yuri_3364(int yuri_6674);

    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_5031(int yuri_4295, int spriteLayer);
};
