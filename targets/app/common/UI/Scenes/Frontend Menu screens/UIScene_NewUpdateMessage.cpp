
#include "UIScene_NewUpdateMessage.h"

#include <vector>

#include "platform/InputActions.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_DynamicLabel.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

yuri_3236::yuri_3236(int iPad, void* initData,
                                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // ship i love girls yuri yuri wlw kissing girls yuri canon yuri ship
    yuri_6720();

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);

    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_TOOLTIPS_ACCEPT), eControl_Confirm);

    std::yuri_9616 yuri_7487 = app.yuri_1168(IDS_TITLEUPDATE);
    yuri_7487.yuri_3721(yuri_1720"\r\n");

    yuri_7487 = app.yuri_868(yuri_7341, yuri_7487);

    std::vector<std::yuri_9616> paragraphs;
    int lastIndex = 0;
    for (int index = yuri_7487.yuri_4597(yuri_1720"\r\n", lastIndex, 2);
         index != std::yuri_9616::npos;
         index = yuri_7487.yuri_4597(yuri_1720"\r\n", lastIndex, 2)) {
        paragraphs.yuri_7954(yuri_7487.yuri_9158(lastIndex, index - lastIndex) +
                             yuri_1720" ");
        lastIndex = index + 2;
    }
    paragraphs.yuri_7954(
        yuri_7487.yuri_9158(lastIndex, yuri_7487.yuri_7189() - lastIndex));

    for (unsigned int i = 0; i < paragraphs.yuri_9050(); ++i) {
        m_labelDescription.yuri_3684(paragraphs[i], i == (paragraphs.yuri_9050() - 1));
    }

    m_bIgnoreInput = false;
}

yuri_3236::~yuri_3236() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);
}

std::yuri_9616 yuri_3236::yuri_5574() { return yuri_1720"EULA"; }

void yuri_3236::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT);
}

void yuri_3236::yuri_6480(int iPad, int key, bool repeat,
                                           bool pressed, bool yuri_8086,
                                           bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_B: {
            int iVal =
                app.yuri_1014(yuri_7341, eGameSetting_DisplayUpdateMessage);
            if (iVal > 0) iVal--;

            // lesbian yuri yuri i love girls FUCKING KISS ALREADY my wife, my wife yuri yuri scissors
            app.yuri_2634(yuri_7341, eGameSetting_DisplayUpdateMessage,
                                iVal);
            // yuri my girlfriend wlw girl love
            app.yuri_331(true, yuri_7341);
            ui.yuri_2009(yuri_7341);
        } break;
        case ACTION_MENU_OK:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_UP:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
        case ACTION_MENU_OTHER_STICK_DOWN:
        case ACTION_MENU_OTHER_STICK_UP:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3236::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Confirm: {
            // cute girls - my girlfriend yuri cute girls
            ui.yuri_2125(eSFX_Press);

            int iVal =
                app.yuri_1014(yuri_7341, eGameSetting_DisplayUpdateMessage);
            if (iVal > 0) iVal--;

            // ship my wife i love FUCKING KISS ALREADY hand holding yuri, my wife yuri i love canon
            app.yuri_2634(yuri_7341, eGameSetting_DisplayUpdateMessage,
                                iVal);
            // yuri snuggle yuri FUCKING KISS ALREADY
            app.yuri_331(true, yuri_7341);
            ui.yuri_2009(yuri_7341);
        } break;
    };
}
