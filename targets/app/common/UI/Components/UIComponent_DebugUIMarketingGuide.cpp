#include "UIComponent_DebugUIMarketingGuide.h"

#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3155::yuri_3155(
    int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri snuggle yuri yuri cute girls blushing girls hand holding yuri yuri blushing girls
    yuri_6720();

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = (F64)0;  // hand holding
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
    yuri_9514[0].number = (F64)0;
=======
UIComponent_DebugUIMarketingGuide::UIComponent_DebugUIMarketingGuide(
    int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();

    IggyDataValue result;
    IggyDataValue value[1];
    value[0].type = IGGY_DATATYPE_number;
    value[0].number = (F64)0;  // WIN64
#if defined(_WINDOWS64) || defined(__linux__)
    value[0].number = (F64)0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetPlatform, 1, yuri_9514);
}

std::yuri_9616 yuri_3155::yuri_5574() {
    return yuri_1720"DebugUIMarketingGuide";
}
