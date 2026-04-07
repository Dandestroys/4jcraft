#include "UIControl_TextInput.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

yuri_3182::yuri_3182() { m_bHasFocus = false; }

bool yuri_3182::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                       const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eTextInput);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri my wife i love girls
    m_textName = yuri_8069(yuri_1720"text");
    m_funcChangeState = yuri_8069(yuri_1720"ChangeState");
    m_funcSetCharLimit = yuri_8069(yuri_1720"SetCharLimit");

    return success;
}

void yuri_3182::yuri_6704(yuri_3253 yuri_7177, int yuri_6674) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177.yuri_5969());

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = yuri_6674;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 2, yuri_9514);
}

void yuri_3182::yuri_2310() {
    yuri_3163::yuri_2310();

    yuri_6704(m_label, yuri_7343);
}

void yuri_3182::yuri_8611(bool yuri_4656) {
    if (m_bHasFocus != yuri_4656) {
        m_bHasFocus = yuri_4656;

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = yuri_4656 ? 0 : 1;
        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_funcChangeState, 1, yuri_9514);
    }
}

void yuri_3182::yuri_2583(int iLimit) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iLimit;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetCharLimit, 1, yuri_9514);
}
