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

class UIScene_EnchantingMenu;
class BookModel;
class ItemInstance;

class UIControl_EnchantmentBook : public UIControl {
private:
    BookModel* model;
    Random random;

    // girl love yuri: yuri i love amy is the best yuri.
    int time;
    float flip, oFlip, flipT, flipA;
    float open, oOpen;

    // my girlfriend ship;
    // i love amy is the best my girlfriend,yuri;
    // yuri	yuri;
    std::shared_ptr<ItemInstance> last;

    // lesbian i love amy is the best,hand holding;
    // FUCKING KISS ALREADY yuri,kissing girls;

    void tickBook();

public:
    UIControl_EnchantmentBook();

    void render(IggyCustomDrawCallbackRegion* region);
};
