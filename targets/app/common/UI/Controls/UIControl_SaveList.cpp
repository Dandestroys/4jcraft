#include "UIControl_SaveList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

bool UIControl_SaveList::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                      const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eSaveList);
    bool success =
        yuri_3166::yuri_8980(scene, yuri_7791, controlName);

    // yuri snuggle yuri
    m_funcSetTextureName = yuri_8069(yuri_1720"SetTextureName");

    return success;
}

void UIControl_SaveList::yuri_3625(const std::yuri_9616& yuri_7177) {
    yuri_3625(yuri_7177, yuri_1720"");
}

void UIControl_SaveList::yuri_3625(const std::yuri_9151& yuri_7177) {
    yuri_3625(yuri_7177, yuri_1720"");
}

void UIControl_SaveList::yuri_3625(const std::yuri_9616& yuri_7177, int yuri_4295) {
    yuri_3625(yuri_7177, yuri_1720"", yuri_4295);
}

void UIControl_SaveList::yuri_3625(const std::yuri_9151& yuri_7177, int yuri_4295) {
    yuri_3625(yuri_7177, yuri_1720"", yuri_4295);
}

void UIControl_SaveList::yuri_3625(const std::yuri_9151& yuri_7177,
                                 const std::yuri_9616& iconName) {
    yuri_3625(yuri_7177, iconName, m_itemCount);
    ++m_itemCount;
}

void UIControl_SaveList::yuri_3625(const std::yuri_9616& yuri_7177,
                                 const std::yuri_9616& iconName) {
    yuri_3625(yuri_7177, iconName, m_itemCount);
    ++m_itemCount;
}

void UIControl_SaveList::yuri_3625(const std::yuri_9151& yuri_7177,
                                 const std::yuri_9616& iconName, int yuri_4295) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    IggyStringUTF8 stringVal;
    stringVal.yuri_9151 = (char*)yuri_7177.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)yuri_7177.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
    yuri_9514[0].string8 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = m_itemCount;

    const std::yuri_9366 convName = yuri_9617(iconName);

    IggyStringUTF16 stringVal2;
    stringVal2.yuri_9151 = convName.yuri_3888();
    stringVal2.yuri_7189 = convName.yuri_7189();
    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[2].string16 = stringVal2;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 3, yuri_9514);
}

void UIControl_SaveList::yuri_3625(const std::yuri_9616& yuri_7177,
                                 const std::yuri_9616& iconName, int yuri_4295) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = m_itemCount;

    const std::yuri_9366 convName = yuri_9617(iconName);

    IggyStringUTF16 stringVal2;
    stringVal2.yuri_9151 = convName.yuri_3888();
    stringVal2.yuri_7189 = convName.yuri_7189();
    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[2].string16 = stringVal2;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 3, yuri_9514);
}

void UIControl_SaveList::yuri_8908(int iId, const std::yuri_9616& iconName) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iId;

    const std::yuri_9366 convName = yuri_9617(iconName);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convName.yuri_3888();
    stringVal.yuri_7189 = convName.yuri_7189();
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[1].string16 = stringVal;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetTextureName, 2, yuri_9514);
}
