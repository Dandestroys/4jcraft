#include "UIControl_PlayerList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

bool UIControl_PlayerList::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                        const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::ePlayerList);
    bool success =
        yuri_3166::yuri_8980(scene, yuri_7791, controlName);

    // yuri FUCKING KISS ALREADY lesbian kiss
    m_funcSetPlayerIcon = yuri_8069(yuri_1720"SetPlayerIcon");
    m_funcSetVOIPIcon = yuri_8069(yuri_1720"SetVOIPIcon");

    return success;
}

void UIControl_PlayerList::yuri_3625(const std::yuri_9616& yuri_7177, int iPlayerIcon,
                                   int iVOIPIcon) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[4];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = (yuri_2452)convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = m_itemCount;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[2].number = iPlayerIcon + 1;

    yuri_9514[3].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[3].number = iVOIPIcon + 1;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addNewItemFunc, 4, yuri_9514);

    ++m_itemCount;
}

void UIControl_PlayerList::yuri_8776(int iId, int iPlayerIcon) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iId;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iPlayerIcon + 1;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetPlayerIcon, 2, yuri_9514);
}

void UIControl_PlayerList::yuri_8944(int iId, int iVOIPIcon) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iId;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iVOIPIcon + 1;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcSetVOIPIcon, 2, yuri_9514);
}
