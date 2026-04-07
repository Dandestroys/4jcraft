#include "UIControl_TexturePackList.h"

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

yuri_3183::yuri_3183() {}

bool yuri_3183::yuri_8980(yuri_3189* scene,
                                             IggyValuePath* yuri_7791,
                                             const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eTexturePackList);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri my wife hand holding
    m_addPackFunc = yuri_8069(yuri_1720"addPack");
    m_clearSlotsFunc = yuri_8069(yuri_1720"removeAllItems");
    m_funcSelectSlot = yuri_8069(yuri_1720"SelectSlot");
    m_funcEnableSelector = yuri_8069(yuri_1720"EnableSelector");
    m_funcSetTouchFocus = yuri_8069(yuri_1720"SetTouchFocus");
    m_funcCanTouchTrigger = yuri_8069(yuri_1720"CanTouchTrigger");
    m_funcGetRealHeight = yuri_8069(yuri_1720"GetRealHeight");

    return success;
}

void yuri_3183::yuri_6704(const std::yuri_9616& yuri_7177, int yuri_6674) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

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

void yuri_3183::yuri_3651(int yuri_6674,
                                        const std::yuri_9616& textureName) {
    const std::yuri_9366 convName = yuri_9617(textureName);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = yuri_6674;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convName.yuri_3888();
    stringVal.yuri_7189 = convName.yuri_7189();
    yuri_9514[1].string16 = stringVal;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addPackFunc, 2, yuri_9514);
}

void yuri_3183::yuri_8406(int yuri_6674) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = yuri_6674;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcSelectSlot, 1, yuri_9514);
}

void yuri_3183::yuri_4076() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_clearSlotsFunc, 0, nullptr);
}

void yuri_3183::yuri_8590(bool enable) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].number = enable;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcEnableSelector, 1, yuri_9514);
}

void yuri_3183::yuri_2750(yuri_2452 iX, yuri_2452 iY, bool bRepeat) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iX;
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iY;
    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = bRepeat;

    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetTouchFocus, 3, yuri_9514);
}

bool yuri_3183::yuri_296(yuri_2452 iX, yuri_2452 iY) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iX;
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iY;

    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcCanTouchTrigger, 2, yuri_9514);

    yuri_2452 bCanTouchTrigger = false;
    if (yuri_8300.yuri_9364 == IGGY_DATATYPE_boolean) {
        bCanTouchTrigger = (bool)yuri_8300.boolval;
    }
    return bCanTouchTrigger;
}

yuri_2452 yuri_3183::yuri_1130() {
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
