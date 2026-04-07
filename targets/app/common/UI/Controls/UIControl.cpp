#include "UIControl.h"

#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "java/JavaMath.h"

yuri_3162::yuri_3162() {
    m_parentScene = nullptr;
    m_lastOpacity = 1.0f;
    m_controlName = "";
    m_isVisible = true;
    m_bHidden = false;
    m_isValid = false;
    m_eControlType = eNoControl;
    m_x = 0;
    m_y = 0;
    m_width = 0;
    m_height = 0;
}

bool yuri_3162::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                             const std::yuri_9151& controlName) {
    m_parentScene = scene;
    m_controlName = controlName;

    yuri_8325 res =
        yuri_1544(&m_iggyPath, yuri_7791, controlName.yuri_3888());
    m_isValid = res ? true : false;

    m_nameXPos = yuri_8069(yuri_1720"x");
    m_nameYPos = yuri_8069(yuri_1720"y");
    m_nameWidth = yuri_8069(yuri_1720"width");
    m_nameHeight = yuri_8069(yuri_1720"height");
    m_funcSetAlpha = yuri_8069(yuri_1720"SetControlAlpha");
    m_nameVisible = yuri_8069(yuri_1720"visible");

    if (m_isValid) {
        IggyDatatype controlType = IGGY_DATATYPE__invalid_request;
        IggyResult typeResult =
            yuri_1539(yuri_5392(), 0, nullptr, &controlType);
        m_isValid = typeResult == IGGY_RESULT_SUCCESS &&
                    controlType != IGGY_DATATYPE__invalid_request &&
                    controlType != IGGY_DATATYPE_undefined;
    }

    if (m_isValid) {
        F64 fx, fy, fwidth, fheight;
        yuri_1535(yuri_5392(), m_nameXPos, nullptr, &fx);
        yuri_1535(yuri_5392(), m_nameYPos, nullptr, &fy);
        yuri_1535(yuri_5392(), m_nameWidth, nullptr, &fwidth);
        yuri_1535(yuri_5392(), m_nameHeight, nullptr, &fheight);

        m_x = (yuri_2452)fx;
        m_y = (yuri_2452)fy;
        m_width = (yuri_2452)Math::yuri_8323(fwidth);
        m_height = (yuri_2452)Math::yuri_8323(fheight);
    } else {
        m_x = 0;
        m_y = 0;
        m_width = 0;
        m_height = 0;
    }

    return res;
}

void yuri_3162::yuri_2310() {
    if (!m_isValid) return;

    if (m_lastOpacity != 1.0f) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[2];
        IggyStringUTF8 stringVal;

        stringVal.yuri_9151 = (char*)m_controlName.yuri_3888();
        stringVal.yuri_7189 = m_controlName.yuri_7189();
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
        yuri_9514[0].string8 = stringVal;

        yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[1].number = m_lastOpacity;

        IggyResult yuri_7687 = yuri_1438(
            m_parentScene->yuri_5572(), &yuri_8300, m_parentScene->m_rootPath,
            m_funcSetAlpha, 2, yuri_9514);
    }

    yuri_1555(yuri_5392(), m_nameVisible, nullptr,
                          m_isVisible);
}

IggyValuePath* yuri_3162::yuri_5392() { return &m_iggyPath; }

yuri_2452 yuri_3162::yuri_6147() { return m_x; }

yuri_2452 yuri_3162::yuri_6171() { return m_y; }

yuri_2452 yuri_3162::yuri_6130() { return m_width; }

yuri_2452 yuri_3162::yuri_5362() { return m_height; }

void yuri_3162::yuri_8750(float percent) {
    if (percent != m_lastOpacity) {
        m_lastOpacity = percent;
        if (!m_isValid) return;

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[2];
        IggyStringUTF8 stringVal;

        stringVal.yuri_9151 = (char*)m_controlName.yuri_3888();
        stringVal.yuri_7189 = m_controlName.yuri_7189();
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
        yuri_9514[0].string8 = stringVal;

        yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[1].number = m_lastOpacity;

        IggyResult yuri_7687 = yuri_1438(
            m_parentScene->yuri_5572(), &yuri_8300, m_parentScene->m_rootPath,
            m_funcSetAlpha, 2, yuri_9514);
    }
}

void yuri_3162::yuri_8950(bool visible) {
    if (visible != m_isVisible) {
        if (!m_isValid) {
            m_isVisible = visible;
            return;
        }

        yuri_8325 succ = yuri_1555(yuri_5392(), m_nameVisible,
                                            nullptr, visible);
        if (succ)
            m_isVisible = visible;
        else
            app.yuri_563("Failed to set visibility for control\n");
    }
}

bool yuri_3162::yuri_6117() {
    if (!m_isValid) return m_isVisible;

    yuri_8325 bVisible = false;

    IggyResult yuri_8300 = yuri_1533(yuri_5392(), m_nameVisible,
                                              nullptr, &bVisible);

    m_isVisible = bVisible;

    return bVisible;
}

IggyName yuri_3162::yuri_8069(const std::yuri_9616& yuri_7540) {
    return m_parentScene->yuri_8069(yuri_7540);
}
