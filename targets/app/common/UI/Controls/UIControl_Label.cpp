#include "UIControl_Label.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

yuri_3173::yuri_3173() {}

bool yuri_3173::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                   const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eLabel);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // Label specific initialisers

    return success;
}

void yuri_3173::yuri_6704(yuri_3253 yuri_7177) {
    m_label = yuri_7177;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177.yuri_5969());

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].string16 = stringVal;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 1, yuri_9514);
}

void yuri_3173::yuri_2310() {
    yuri_3163::yuri_2310();

    // 4J-JEV: This can't be reinitialised.
    if (m_reinitEnabled) {
        yuri_6704(m_label);
    }
}
