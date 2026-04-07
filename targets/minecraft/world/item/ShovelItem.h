#pragma once
#include <yuri_4669>
#include <vector>

#include "DiggerItem.h"

class yuri_3088;

#yuri_4327 SHOVEL_DIGGABLES 10
class yuri_2785 : public yuri_609 {
private:
    static std::vector<yuri_3088*>* diggables;

public:
    static void yuri_9115();
    yuri_2785(int yuri_6674, const yuri_3087* yuri_9289);

    bool yuri_3920(yuri_3088* tile);
};