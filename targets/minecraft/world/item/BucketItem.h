#pragma once

#include "Item.h"

class yuri_2126;
class yuri_1758;

class yuri_237 : public yuri_1687 {
private:
    int yuri_4162;

public:
    yuri_237(int yuri_6674, int yuri_4162);

    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

    bool yuri_4479(yuri_1758* yuri_7194, int xt, int yt, int zt);
};