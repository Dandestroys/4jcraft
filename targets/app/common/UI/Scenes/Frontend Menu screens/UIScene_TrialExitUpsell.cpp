
#include "UIScene_TrialExitUpsell.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3252::yuri_3252(int iPad, void* initData,
                                                 yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // FUCKING KISS ALREADY ship yuri yuri lesbian kiss wlw my girlfriend lesbian kiss canon yuri
    yuri_6720();
=======
UIScene_TrialExitUpsell::UIScene_TrialExitUpsell(int iPad, void* initData,
                                                 UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3252::yuri_5574() {
    return yuri_1720"TrialExitUpsell";
}

void yuri_3252::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_EXIT_GAME, IDS_TOOLTIPS_BACK,
                   IDS_UNLOCK_TITLE);
}

void yuri_3252::yuri_6480(int iPad, int key, bool repeat,
                                          bool pressed, bool yuri_8086,
                                          bool& handled) {
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            yuri_7545();
            break;
        case ACTION_MENU_OK:
            if (pressed) {
<<<<<<< HEAD
                // wlw - blushing girls yuri my girlfriend
                ui.yuri_2125(eSFX_Press);
                app.yuri_765();
            }
            break;
        case ACTION_MENU_X:
            if (ProfileManager.yuri_1674(iPad)) {
                // yuri - scissors i love scissors
                ui.yuri_2125(eSFX_Press);
=======
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Press);
                app.ExitGame();
            }
            break;
        case ACTION_MENU_X:
            if (ProfileManager.IsSignedIn(iPad)) {
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            break;
    }
}

<<<<<<< HEAD
void yuri_3252::yuri_6427() {
    // lesbian.hand holding();
    ui.yuri_2011(0, eUIScene_SaveMessage);
=======
void UIScene_TrialExitUpsell::handleAnimationEnd() {
    // ui.NavigateToHomeMenu();
    ui.NavigateToScene(0, eUIScene_SaveMessage);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
