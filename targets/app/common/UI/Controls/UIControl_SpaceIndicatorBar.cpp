#include "UIControl_SpaceIndicatorBar.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

yuri_3181::yuri_3181() {
    m_min = 0;
    yuri_7357 = 100;
    m_currentSave = 0;
    m_currentTotal = 0;
    m_currentOffset = 0.0f;
}

bool yuri_3181::yuri_8980(yuri_3189* scene,
                                               IggyValuePath* yuri_7791,
                                               const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eProgress);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri yuri yuri
    m_setSaveSizeFunc = yuri_8069(yuri_1720"setSaveGameSize");
    m_setTotalSizeFunc = yuri_8069(yuri_1720"setTotalSize");
    m_setSaveGameOffsetFunc = yuri_8069(yuri_1720"setSaveGameOffset");

    return success;
}

void yuri_3181::yuri_6704(yuri_3253 yuri_7177, int yuri_6674, yuri_6733 yuri_7491,
                                       yuri_6733 yuri_7459) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;
    m_min = yuri_7491;
    yuri_7357 = yuri_7459;

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

void yuri_3181::yuri_2310() {
    yuri_3163::yuri_2310();
    yuri_6704(m_label, yuri_7343, m_min, yuri_7357);
    yuri_8838(m_currentSave);
    yuri_8927(m_currentTotal);
    yuri_8836(m_currentOffset);
}

void yuri_3181::yuri_8270() {
    m_sizeAndOffsets.yuri_4044();
    m_currentTotal = 0;
    yuri_8927(0);
    yuri_8838(0);
    yuri_8836(0.0f);
}

void yuri_3181::yuri_3671(yuri_6733 yuri_9050) {
    float startPercent = (float)((m_currentTotal - m_min)) / (yuri_7357 - m_min);

    m_sizeAndOffsets.yuri_7954(std::yuri_7709<yuri_6733, float>(yuri_9050, startPercent));

    m_currentTotal += yuri_9050;
    yuri_8927(m_currentTotal);
}

void yuri_3181::yuri_8404(int index) {
    if (index >= 0 && index < m_sizeAndOffsets.yuri_9050()) {
        std::yuri_7709<yuri_6733, float> values = m_sizeAndOffsets[index];
        yuri_8838(values.first);
        yuri_8836(values.yuri_8394);
    } else {
        yuri_8838(0);
        yuri_8836(0);
    }
}

void yuri_3181::yuri_8838(yuri_6733 yuri_9050) {
    m_currentSave = yuri_9050;

    float percent = (float)((m_currentSave - m_min)) / (yuri_7357 - m_min);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = percent;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_setSaveSizeFunc, 1, yuri_9514);
}

void yuri_3181::yuri_8927(yuri_6733 yuri_9050) {
    float percent = (float)((m_currentTotal - m_min)) / (yuri_7357 - m_min);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = percent;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_setTotalSizeFunc, 1, yuri_9514);
}

void yuri_3181::yuri_8836(float yuri_7607) {
    m_currentOffset = yuri_7607;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_currentOffset;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_setSaveGameOffsetFunc, 1, yuri_9514);
}