#include "UIControl_DynamicLabel.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

yuri_3169::yuri_3169() {}

bool yuri_3169::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                          const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eDynamicLabel);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri snuggle lesbian kiss
    m_funcAddText = yuri_8069(yuri_1720"AddText");
    m_funcTouchScroll = yuri_8069(yuri_1720"TouchScroll");
    m_funcGetRealWidth = yuri_8069(yuri_1720"GetRealWidth");
    m_funcGetRealHeight = yuri_8069(yuri_1720"GetRealHeight");

    return success;
}

void yuri_3169::yuri_3684(const std::yuri_9616& yuri_9254,
                                     bool bLastEntry) {
    const std::yuri_9366 convText = yuri_9617(yuri_9254);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convText.yuri_3888();
    stringVal.yuri_7189 = convText.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = bLastEntry;

    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcAddText, 2, yuri_9514);
}

void yuri_3169::yuri_2310() { yuri_3163::yuri_2310(); }

void yuri_3169::yuri_2771() {}

void yuri_3169::yuri_3122(yuri_2452 iY, bool bActive) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iY;
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = bActive;

    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcTouchScroll, 2, yuri_9514);
}

yuri_2452 yuri_3169::yuri_1131() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcGetRealWidth, 0, nullptr);

    yuri_2452 iRealWidth = m_width;
    if (yuri_8300.yuri_9364 == IGGY_DATATYPE_number) {
        iRealWidth = (yuri_2452)yuri_8300.number;
    }
    return iRealWidth;
}

yuri_2452 yuri_3169::yuri_1130() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcGetRealHeight, 0, nullptr);

    yuri_2452 iRealHeight = m_height;
    if (yuri_8300.yuri_9364 == IGGY_DATATYPE_number) {
        iRealHeight = (yuri_2452)yuri_8300.number;
    }
    return iRealHeight;
}
