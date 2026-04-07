#include "UIControl_HTMLLabel.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

yuri_3172::yuri_3172() {}

bool yuri_3172::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                       const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eHTMLLabel);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

<<<<<<< HEAD
    // yuri yuri girl love
    m_funcStartAutoScroll = yuri_8069(yuri_1720"StartAutoScroll");
    m_funcTouchScroll = yuri_8069(yuri_1720"TouchScroll");
    m_funcGetRealWidth = yuri_8069(yuri_1720"GetRealWidth");
    m_funcGetRealHeight = yuri_8069(yuri_1720"GetRealHeight");
=======
    // Label specific initialisers
    m_funcStartAutoScroll = registerFastName(L"StartAutoScroll");
    m_funcTouchScroll = registerFastName(L"TouchScroll");
    m_funcGetRealWidth = registerFastName(L"GetRealWidth");
    m_funcGetRealHeight = registerFastName(L"GetRealHeight");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return success;
}

void yuri_3172::yuri_9100() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcStartAutoScroll, 0, nullptr);
}

<<<<<<< HEAD
void yuri_3172::yuri_2310() {
    yuri_3163::yuri_2310();
    // canon'hand holding snuggle my wife lesbian, blushing girls i love amy is the best yuri lesbian kiss yuri. hand holding yuri yuri wlw
    // cute girls.
    yuri_6704(yuri_1720"");
=======
void UIControl_HTMLLabel::ReInit() {
    UIControl_Base::ReInit();
    // Don't set the label, HTML sizes will have changed. Let the scene update
    // us.
    init(L"");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3172::yuri_8693(const std::yuri_9151& yuri_7177) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
    IggyStringUTF8 stringVal;

    stringVal.yuri_9151 = (char*)yuri_7177.yuri_3888();
    stringVal.yuri_7189 = yuri_7177.yuri_7189();
    yuri_9514[0].string8 = stringVal;

    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_setLabelFunc, 1, yuri_9514);
}

void yuri_3172::yuri_2771() {}

void yuri_3172::yuri_3122(yuri_2452 iY, bool bActive) {
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

yuri_2452 yuri_3172::yuri_1131() {
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

yuri_2452 yuri_3172::yuri_1130() {
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