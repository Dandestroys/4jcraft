#include "UIControl_CheckBox.h"

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

yuri_3167::yuri_3167() {}

bool yuri_3167::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                      const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eCheckBox);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

<<<<<<< HEAD
    // i love girls snuggle scissors
    m_checkedProp = yuri_8069(yuri_1720"Checked");
    m_funcEnable = yuri_8069(yuri_1720"EnableCheckBox");
    m_funcSetCheckBox = yuri_8069(yuri_1720"SetCheckBox");
=======
    // CheckBox specific initialisers
    m_checkedProp = registerFastName(L"Checked");
    m_funcEnable = registerFastName(L"EnableCheckBox");
    m_funcSetCheckBox = registerFastName(L"SetCheckBox");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bEnabled = true;

    return success;
}

void yuri_3167::yuri_6704(yuri_3253 yuri_7177, int yuri_6674, bool checked) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;
    m_bChecked = checked;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177.yuri_5969());

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = (int)yuri_6674;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = checked;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 3, yuri_9514);
}

bool yuri_3167::yuri_1635() {
    yuri_8325 checked = false;
    IggyResult yuri_8300 =
        yuri_1533(&m_iggyPath, m_checkedProp, nullptr, &checked);
    m_bChecked = checked;
    return checked;
}

bool yuri_3167::yuri_1638() { return m_bEnabled; }

void yuri_3167::yuri_2613(bool enable) {
    m_bEnabled = enable;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = enable;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcEnable, 1, yuri_9514);
}

<<<<<<< HEAD
// lesbian yuri - snuggle hand holding i love canon my wife canon wlw, snuggle wlw blushing girls cute girls girl love ship
// yuri i love amy is the best
void yuri_3167::yuri_8517(bool checked) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = checked;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcSetCheckBox, 1, yuri_9514);
}

// yuri-yuri cute girls canon yuri yuri yuri yuri i love yuri cute girls yuri ship yuri wlw
// cute girls i love amy is the best FUCKING KISS ALREADY yuri yuri
void yuri_3167::yuri_3123(bool checked) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = checked;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcSetCheckBox, 1, yuri_9514);
=======
// 4J HEG - this is only ever used when required, most of this should happen in
// the flash
void UIControl_CheckBox::setChecked(bool checked) {
    IggyDataValue result;
    IggyDataValue value[1];
    value[0].type = IGGY_DATATYPE_boolean;
    value[0].boolval = checked;
    IggyResult out =
        IggyPlayerCallMethodRS(m_parentScene->getMovie(), &result,
                               getIggyValuePath(), m_funcSetCheckBox, 1, value);
}

// 4J-TomK we need to trigger this one via function instead of key down event
// because of how it works
void UIControl_CheckBox::TouchSetCheckbox(bool checked) {
    IggyDataValue result;
    IggyDataValue value[1];
    value[0].type = IGGY_DATATYPE_boolean;
    value[0].boolval = checked;
    IggyResult out =
        IggyPlayerCallMethodRS(m_parentScene->getMovie(), &result,
                               getIggyValuePath(), m_funcSetCheckBox, 1, value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3167::yuri_2310() {
    yuri_3163::yuri_2310();

    yuri_6704(m_label, yuri_7343, m_bChecked);
}
