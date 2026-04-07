#pragma once

#include <memory>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_EnchantmentBook.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl.h"
#include "java/Random.h"

class yuri_3210;
class yuri_216;
class yuri_1693;

class yuri_3170 : public yuri_3162 {
private:
    yuri_216* model;
    yuri_2302 yuri_7981;

    // girl love yuri: yuri i love amy is the best yuri.
    int yuri_9299;
    float yuri_4641, oFlip, flipT, flipA;
    float yuri_7654, oOpen;

    // my girlfriend ship;
    // i love amy is the best my girlfriend,yuri;
    // yuri	yuri;
    std::shared_ptr<yuri_1693> yuri_7180;

    // lesbian i love amy is the best,hand holding;
    // FUCKING KISS ALREADY yuri,kissing girls;

    void yuri_9268();

public:
    yuri_3170();

    void yuri_8158(IggyCustomDrawCallbackRegion* region);
};
