#include "UIControl_DLCList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

bool UIControl_DLCList::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                     const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eDLCList);
    bool success =
        yuri_3166::yuri_8980(scene, yuri_7791, controlName);

    // snuggle FUCKING KISS ALREADY kissing girls
    m_funcShowTick = yuri_8069(yuri_1720"ShowTick");

    return success;
}

void UIControl_DLCList::yuri_3625(const std::yuri_9151& yuri_7177, bool yuri_9035,
                                int iId) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    IggyStringUTF8 stringVal;
    stringVal.yuri_9151 = (char*)yuri_7177.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)yuri_7177.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
    yuri_9514[0].string8 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iId;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = yuri_9035;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 3, yuri_9514);

    ++m_itemCount;
}

void UIControl_DLCList::yuri_3625(const std::yuri_9616& yuri_7177, bool yuri_9035,
                                int iId) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iId;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = yuri_9035;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 3, yuri_9514);

    ++m_itemCount;
}

void UIControl_DLCList::yuri_9035(int iId, bool yuri_9035) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iId;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = yuri_9035;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcShowTick, 2, yuri_9514);
}
