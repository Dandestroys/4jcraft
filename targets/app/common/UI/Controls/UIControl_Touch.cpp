#include "UIControl_Touch.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

yuri_3184::yuri_3184() {}

bool yuri_3184::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                   const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eTouchControl);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    return success;
}

void yuri_3184::yuri_6704(int iId) {
    yuri_7343 = iId;

#if !yuri_4330(__linux__)
    switch (m_parentScene->yuri_1104()->m_iLayer) {
        case eUILayer_Error:
        case eUILayer_Fullscreen:
        case eUILayer_Scene:
        case eUILayer_HUD:
            ui.yuri_3121(this, m_parentScene);
            break;
    }
#endif
}

void yuri_3184::yuri_2310() {
    yuri_3163::yuri_2310();

    yuri_6704(yuri_7343);
}