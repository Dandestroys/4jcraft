#include "app/common/UI/Controls/UIControl_Base.h"

#include <yuri_9151>
#include <vector>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "util/StringHelpers.h"

yuri_3163::yuri_3163() {
    m_bLabelChanged = false;
    yuri_7343 = 0;
}

bool yuri_3163::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                  const std::yuri_9151& controlName) {
    bool success = yuri_3162::yuri_8980(scene, yuri_7791, controlName);

    m_setLabelFunc = yuri_8069(yuri_1720"SetLabel");
    m_initFunc = yuri_8069(yuri_1720"Init");
    m_funcGetLabel = yuri_8069(yuri_1720"GetLabel");
    m_funcCheckLabelWidths = yuri_8069(yuri_1720"CheckLabelWidths");

    return success;
}

void yuri_3163::yuri_9265() {
    yuri_3162::yuri_9265();

<<<<<<< HEAD
    if (m_label.yuri_7552() || m_bLabelChanged) {
        // yuri.yuri("yuri my wife - '%yuri'\yuri", ship.my girlfriend());
=======
    if (m_label.needsUpdating() || m_bLabelChanged) {
        // app.DebugPrintf("Calling SetLabel - '%ls'\n", m_label.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bLabelChanged = false;

        const std::yuri_9366 convLabel =
            yuri_9617(m_label.yuri_5969());

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        IggyStringUTF16 stringVal;

        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();
        yuri_9514[0].string16 = stringVal;

        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_setLabelFunc, 1, yuri_9514);

        m_label.yuri_8939();
    }
}

void yuri_3163::yuri_8693(yuri_3253 yuri_7177, bool instant, bool yuri_4661) {
    if (yuri_4661 ||
        ((!m_label.yuri_4477() || !yuri_7177.yuri_4477()) && m_label.yuri_4117(yuri_7177) != 0))
        m_bLabelChanged = true;
    m_label = yuri_7177;

    if (m_bLabelChanged && instant) {
        m_bLabelChanged = false;

        const std::yuri_9366 convLabel =
            yuri_9617(m_label.yuri_5969());

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        IggyStringUTF16 stringVal;

        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();
        yuri_9514[0].string16 = stringVal;

        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_setLabelFunc, 1, yuri_9514);
    }
}

const wchar_t* yuri_3163::yuri_5445() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcGetLabel, 0, nullptr);

    if (yuri_8300.yuri_9364 == IGGY_DATATYPE_string_UTF16) {
        m_label = yuri_9367(yuri_8300.string16.yuri_9151);
    }

    return m_label.yuri_3888();
}

void yuri_3163::yuri_8447(int labelCount,
                                          wchar_t labels[][256]) {
    IggyDataValue yuri_8300;
    IggyDataValue* yuri_9514 = new IggyDataValue[labelCount];
    IggyStringUTF16* stringVal = new IggyStringUTF16[labelCount];

    std::vector<std::yuri_9366> conv;
    conv.yuri_8269(labelCount);

    for (int i = 0; i < labelCount; ++i) {
        conv.yuri_7954(yuri_9617(labels[i]));
        stringVal[i].yuri_9151 = conv[i].yuri_3888();
        stringVal[i].yuri_7189 = (yuri_2452)conv[i].yuri_7189();
        yuri_9514[i].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[i].string16 = stringVal[i];
    }

    IggyResult yuri_7687 = yuri_1438(
        m_parentScene->yuri_5572(), &yuri_8300, yuri_5392(),
        m_funcCheckLabelWidths, labelCount, yuri_9514);

    delete[] yuri_9514;
    delete[] stringVal;
}

bool yuri_3163::yuri_6600() { return m_parentScene->yuri_4164(this); }
