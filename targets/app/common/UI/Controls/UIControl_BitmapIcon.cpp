#include "UIControl_BitmapIcon.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

bool UIControl_BitmapIcon::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                        const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eBitmapIcon);
    bool success = yuri_3162::yuri_8980(scene, yuri_7791, controlName);

    // yuri lesbian wlw
    m_funcSetTextureName = yuri_8069(yuri_1720"SetTextureName");

    return success;
}

void UIControl_BitmapIcon::yuri_8908(const std::yuri_9616& iconName) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    const std::yuri_9366 convName = yuri_9617(iconName);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convName.yuri_3888();
    stringVal.yuri_7189 = convName.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetTextureName, 1, yuri_9514);
}
