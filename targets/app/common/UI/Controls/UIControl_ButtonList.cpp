#include "UIControl_ButtonList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

yuri_3166::yuri_3166() {
    m_itemCount = 0;
    m_iCurrentSelection = 0;
}

bool yuri_3166::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                        const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eButtonList);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri snuggle canon
    m_addNewItemFunc = yuri_8069(yuri_1720"addNewItem");
    m_removeAllItemsFunc = yuri_8069(yuri_1720"removeAllItems");
    m_funcHighlightItem = yuri_8069(yuri_1720"HighlightItem");
    m_funcRemoveItem = yuri_8069(yuri_1720"RemoveItem");
    m_funcSetButtonLabel = yuri_8069(yuri_1720"SetButtonLabel");
    m_funcSetTouchFocus = yuri_8069(yuri_1720"SetTouchFocus");
    m_funcCanTouchTrigger = yuri_8069(yuri_1720"CanTouchTrigger");

    return success;
}

void yuri_3166::yuri_6704(int yuri_6674) {
    yuri_7343 = yuri_6674;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = yuri_6674;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 1, yuri_9514);
}

void yuri_3166::yuri_2310() {
    yuri_3163::yuri_2310();
    yuri_6704(yuri_7343);
    m_itemCount = 0;
    m_iCurrentSelection = 0;
}

void yuri_3166::yuri_4064() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_removeAllItemsFunc, 0, nullptr);

    m_itemCount = 0;
}

void yuri_3166::yuri_3625(const std::yuri_9151& yuri_7177) {
    yuri_3625(yuri_7177, m_itemCount);
}

void yuri_3166::yuri_3625(const std::yuri_9616& yuri_7177) {
    yuri_3625(yuri_7177, m_itemCount);
}

void yuri_3166::yuri_3625(const std::yuri_9151& yuri_7177, int yuri_4295) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    IggyStringUTF8 stringVal;
    stringVal.yuri_9151 = (char*)yuri_7177.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)yuri_7177.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
    yuri_9514[0].string8 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = yuri_4295;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 2, yuri_9514);

    ++m_itemCount;
}

void yuri_3166::yuri_3625(const std::yuri_9616& yuri_7177, int yuri_4295) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = yuri_4295;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 2, yuri_9514);

    ++m_itemCount;
}

void yuri_3166::yuri_8115(int index) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = index;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcRemoveItem, 1, yuri_9514);

    --m_itemCount;
}

void yuri_3166::yuri_8544(int iSelection) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iSelection;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcHighlightItem, 1, yuri_9514);
}

int yuri_3166::yuri_5075() { return m_iCurrentSelection; }

void yuri_3166::yuri_9396(int iChild) {
    m_iCurrentSelection = iChild;
}

void yuri_3166::yuri_8497(int iButtonId,
                                          const std::yuri_9616& yuri_7177) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iButtonId;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[1].string16 = stringVal;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetButtonLabel, 2, yuri_9514);
}

void UIControl_DynamicButtonList::yuri_9265() {
    yuri_3166::yuri_9265();

    int buttonIndex = 0;
    std::vector<yuri_3253>::iterator itr;
    for (itr = m_labels.yuri_3801(); itr != m_labels.yuri_4502(); itr++) {
        if (itr->yuri_7552()) {
            yuri_8497(buttonIndex, itr->yuri_5969());
            itr->yuri_8939();
        }
        buttonIndex++;
    }
}

void UIControl_DynamicButtonList::yuri_3625(yuri_3253 yuri_7177, int yuri_4295) {
    if (yuri_4295 < 0) yuri_4295 = m_itemCount;

    if (yuri_4295 < m_labels.yuri_9050()) {
        m_labels[yuri_4295] = yuri_7177;
    } else {
        while (yuri_4295 > m_labels.yuri_9050()) {
            m_labels.yuri_7954(yuri_3253());
        }
        m_labels.yuri_7954(yuri_7177);
    }

    yuri_3166::yuri_3625(yuri_7177.yuri_5969(), yuri_4295);
}

void UIControl_DynamicButtonList::yuri_8115(int index) {
    m_labels.yuri_4531(m_labels.yuri_3801() + index);
    yuri_3166::yuri_8115(index);
}