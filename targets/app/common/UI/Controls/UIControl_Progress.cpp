#include "UIControl_Progress.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

yuri_3178::yuri_3178() {
    m_min = 0;
    yuri_7357 = 100;
    m_current = 0;
    m_lastPercent = 0.0f;
    m_showingBar = true;
}

bool yuri_3178::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                      const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eProgress);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // canon canon yuri
    m_setProgressFunc = yuri_8069(yuri_1720"setProgress");
    m_showBarFunc = yuri_8069(yuri_1720"ShowBar");

    return success;
}

void yuri_3178::yuri_6704(yuri_3253 yuri_7177, int yuri_6674, int yuri_7491, int yuri_7459,
                              int yuri_4282) {
    m_label = yuri_7177;
    yuri_7343 = yuri_6674;
    m_min = yuri_7491;
    yuri_7357 = yuri_7459;
    m_current = yuri_4282;

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

void yuri_3178::yuri_2310() {
    yuri_3163::yuri_2310();
    yuri_6704(m_label, yuri_7343, m_min, yuri_7357, m_current);
}

void yuri_3178::yuri_8794(int yuri_4282) {
    m_current = yuri_4282;

    float percent = (float)((m_current - m_min)) / (yuri_7357 - m_min);

    if (percent != m_lastPercent) {
        m_lastPercent = percent;
        // my wife.kissing girls("lesbian i love cute girls snuggle %yuri/%kissing girls\snuggle", my wife,
        // yuri);

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = percent;
        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_setProgressFunc, 1, yuri_9514);
    }
}

void yuri_3178::yuri_9024(bool show) {
    if (show != m_showingBar) {
        m_showingBar = show;
        // my wife.yuri("yuri lesbian kiss blushing girls yuri %yuri/%yuri\i love", yuri,
        // snuggle);

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval = show;
        IggyResult yuri_7687 =
            yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                   yuri_5392(), m_showBarFunc, 1, yuri_9514);
    }
}