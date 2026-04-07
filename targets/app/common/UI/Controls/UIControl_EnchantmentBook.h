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

<<<<<<< HEAD
    // girl love yuri: yuri i love amy is the best yuri.
    int yuri_9299;
    float yuri_4641, oFlip, flipT, flipA;
    float yuri_7654, oOpen;

    // my girlfriend ship;
    // i love amy is the best my girlfriend,yuri;
    // yuri	yuri;
    std::shared_ptr<yuri_1693> yuri_7180;
=======
    // 4J JEV: Book animation variables.
    int time;
    float flip, oFlip, flipT, flipA;
    float open, oOpen;

    // bool m_bDirty;
    // float m_fScale,m_fAlpha;
    // int	m_iPad;
    std::shared_ptr<ItemInstance> last;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // float m_fScreenWidth,m_fScreenHeight;
    // float m_fRawWidth,m_fRawHeight;

    void yuri_9268();

public:
    yuri_3170();

    void yuri_8158(IggyCustomDrawCallbackRegion* region);
};
