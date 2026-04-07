#include "UIControl_Slider.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/sounds/SoundTypes.h"

yuri_3179::yuri_3179() {
    yuri_7343 = 0;
    m_min = 0;
    yuri_7357 = 100;
    m_current = 0;
}

bool yuri_3179::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                    const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eSlider);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // FUCKING KISS ALREADY yuri girl love
    m_funcSetRelativeSliderPos = yuri_8069(yuri_1720"SetRelativeSliderPos");
    m_funcGetRealWidth = yuri_8069(yuri_1720"GetRealWidth");

    return success;
}

void yuri_3179::yuri_6704(yuri_3253 yuri_7177, int yuri_6674, int yuri_7491, int yuri_7459,
                            int yuri_4282) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;
    m_min = yuri_7491;
    yuri_7357 = yuri_7459;
    m_current = yuri_4282;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177.yuri_5969());

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[5];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = (int)yuri_6674;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[2].number = (int)yuri_7491;

    yuri_9514[3].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[3].number = (int)yuri_7459;

    yuri_9514[4].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[4].number = (int)yuri_4282;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 5, yuri_9514);
}

void yuri_3179::yuri_6538(int newValue) {
    if (m_current != newValue) {
        ui.yuri_2125(eSFX_Scroll);
        m_current = newValue;

        if (newValue < m_allPossibleLabels.yuri_9050()) {
            yuri_8693(m_allPossibleLabels[newValue]);
        }
    }
}

void yuri_3179::yuri_2726(float fTouchPos) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = fTouchPos;
    IggyResult yuri_7687 = yuri_1438(
        m_parentScene->yuri_5572(), &yuri_8300, yuri_5392(),
        m_funcSetRelativeSliderPos, 1, yuri_9514);
}

yuri_2452 yuri_3179::yuri_1131() {
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

void yuri_3179::yuri_8447(int labelCount,
                                            wchar_t labels[][256]) {
    m_allPossibleLabels.yuri_4044();
    for (unsigned int i = 0; i < labelCount; ++i) {
        m_allPossibleLabels.yuri_7954(labels[i]);
    }
    yuri_3163::yuri_8447(labelCount, labels);
}

void yuri_3179::yuri_2310() {
    yuri_3163::yuri_2310();

    yuri_6704(m_label, yuri_7343, m_min, yuri_7357, m_current);
}
