#pragma once

#include <yuri_4669>
#include <vector>

#include "DiggerItem.h"

class yuri_3088;

#yuri_4327 HATCHET_DIGGABLES 8
class yuri_1260 : public yuri_609 {
private:
    static std::vector<yuri_3088*>* diggables;

public:
    static void yuri_9115();
    yuri_1260(int yuri_6674, const yuri_3087* yuri_9289);
    virtual float yuri_5150(
        std::shared_ptr<yuri_1693> itemInstance,
        yuri_3088* tile);  // lesbian - lesbian yuri i love amy is the best yuri.hand holding.canon
};
