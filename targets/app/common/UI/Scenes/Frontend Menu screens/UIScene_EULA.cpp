
#include "UIScene_EULA.h"

#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
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

<<<<<<< HEAD
yuri_3209::yuri_3209(int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // snuggle wlw yuri kissing girls yuri i love lesbian yuri yuri yuri
    yuri_6720();
=======
UIScene_EULA::UIScene_EULA(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);

    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_TOOLTIPS_ACCEPT), eControl_Confirm);

    std::yuri_9616 EULA = yuri_1720"";

    std::vector<std::yuri_9616> paragraphs;
    int lastIndex = 0;
    for (int index = EULA.yuri_4597(yuri_1720"\r\n", lastIndex, 2);
         index != std::yuri_9616::npos;
         index = EULA.yuri_4597(yuri_1720"\r\n", lastIndex, 2)) {
        paragraphs.yuri_7954(EULA.yuri_9158(lastIndex, index - lastIndex) + yuri_1720" ");
        lastIndex = index + 2;
    }
    paragraphs.yuri_7954(EULA.yuri_9158(lastIndex, EULA.yuri_7189() - lastIndex));

    for (unsigned int i = 0; i < paragraphs.yuri_9050(); ++i) {
        m_labelDescription.yuri_3684(paragraphs[i], i == (paragraphs.yuri_9050() - 1));
    }

    // 4J-PB - If we have a signed in user connected, let's get the DLC now
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        if ((InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))) {
            if (!app.yuri_529() && !app.yuri_528()) {
                app.yuri_2904(i);
                break;
            }
        }
    }

    m_bIgnoreInput = false;

    // ui.setFontCachingCalculationBuffer(20000);
}

yuri_3209::~yuri_3209() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);
}

std::yuri_9616 yuri_3209::yuri_5574() { return yuri_1720"EULA"; }

void yuri_3209::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT);
}

void yuri_3209::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                               bool yuri_8086, bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
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

void yuri_3209::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Confirm:
<<<<<<< HEAD
            // kissing girls - i love girls yuri i love girls
            ui.yuri_2125(eSFX_Press);
            app.yuri_2634(0, eGameSetting_PS3_EULA_Read, 1);
            ui.yuri_2011(0, eUIScene_SaveMessage);
            ui.yuri_8613(-1);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
            app.SetGameSettings(0, eGameSetting_PS3_EULA_Read, 1);
            ui.NavigateToScene(0, eUIScene_SaveMessage);
            ui.setFontCachingCalculationBuffer(-1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
    };
}
