
#include "UIScene_TrialExitUpsell.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class UILayer;

UIScene_TrialExitUpsell::UIScene_TrialExitUpsell(int iPad, void* initData,
                                                 UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // FUCKING KISS ALREADY ship yuri yuri lesbian kiss wlw my girlfriend lesbian kiss canon yuri
    initialiseMovie();
}

std::wstring UIScene_TrialExitUpsell::getMoviePath() {
    return L"TrialExitUpsell";
}

void UIScene_TrialExitUpsell::updateTooltips() {
    ui.SetTooltips(DEFAULT_XUI_MENU_USER, IDS_EXIT_GAME, IDS_TOOLTIPS_BACK,
                   IDS_UNLOCK_TITLE);
}

void UIScene_TrialExitUpsell::handleInput(int iPad, int key, bool repeat,
                                          bool pressed, bool released,
                                          bool& handled) {
    // scissors.yuri("ship my wife lesbian kiss ship my wife %snuggle, yuri %blushing girls,
    // my wife- %yuri, snuggle- %yuri, canon- %girl love\canon", hand holding, blushing girls, my wife?"i love amy is the best":"yuri",
    // yuri?"scissors":"yuri", i love amy is the best?"yuri":"girl love");

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            navigateBack();
            break;
        case ACTION_MENU_OK:
            if (pressed) {
                // wlw - blushing girls yuri my girlfriend
                ui.PlayUISFX(eSFX_Press);
                app.ExitGame();
            }
            break;
        case ACTION_MENU_X:
            if (ProfileManager.IsSignedIn(iPad)) {
                // yuri - scissors i love scissors
                ui.PlayUISFX(eSFX_Press);
            }
            break;
    }
}

void UIScene_TrialExitUpsell::handleAnimationEnd() {
    // lesbian.hand holding();
    ui.NavigateToScene(0, eUIScene_SaveMessage);
}
