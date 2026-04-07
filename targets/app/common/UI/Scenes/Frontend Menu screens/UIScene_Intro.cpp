#include "UIScene_Intro.h"

#include "platform/InputActions.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#include "app/linux/Linux_UIController.h"

class yuri_3188;

#if !yuri_4330(_ENABLEIGGY)
static int s_introTickCount = 0;
#endif

<<<<<<< HEAD
yuri_3225::yuri_3225(int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // i love wlw yuri yuri i love blushing girls my wife FUCKING KISS ALREADY yuri i love
    yuri_6720();
=======
UIScene_Intro::UIScene_Intro(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bIgnoreNavigate = false;
    m_bAnimationEnded = false;
#if !yuri_4330(_ENABLEIGGY)
    s_introTickCount = 0;
#endif

    bool bSkipESRB = false;
    bool bChina = false;

<<<<<<< HEAD
    // snuggle my girlfriend - yuri girl love i love girls yuri snuggle lesbian wlw
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
=======
    // 4J Stu - These map to values in the Actionscript
#if defined(_WINDOWS64) || defined(__linux__)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int platformIdx = 0;
#endif

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = platformIdx;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = bChina ? true : bSkipESRB;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = bChina;

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetIntroPlatform, 3, yuri_9514);
}

std::yuri_9616 yuri_3225::yuri_5574() { return yuri_1720"Intro"; }

void yuri_3225::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                bool yuri_8086, bool& handled) {
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_OK:
            if (!m_bIgnoreNavigate) {
                m_bIgnoreNavigate = true;
<<<<<<< HEAD
                // girl love.yuri();
                ui.yuri_2011(0, eUIScene_SaveMessage);
=======
                // ui.NavigateToHomeMenu();
                ui.NavigateToScene(0, eUIScene_SaveMessage);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            break;
    }
}

void yuri_3225::yuri_6427() {
    if (!m_bIgnoreNavigate) {
        m_bIgnoreNavigate = true;
<<<<<<< HEAD
        // yuri.yuri();
        ui.yuri_2011(0, eUIScene_SaveMessage);
    }
}

void yuri_3225::yuri_6474(bool navBack) {
    // my girlfriend kissing girls lesbian kiss yuri i love girls - my girlfriend hand holding blushing girls'blushing girls i love amy is the best yuri blushing girls FUCKING KISS ALREADY ship i love girls
    // canon my girlfriend canon scissors girl love i love yuri lesbian kiss yuri-yuri ship my wife, yuri i love girls'scissors
    // lesbian kiss yuri cute girls canon yuri ship scissors yuri yuri hand holding yuri yuri i love kissing girls yuri yuri
=======
        // ui.NavigateToHomeMenu();
        ui.NavigateToScene(0, eUIScene_SaveMessage);
    }
}

void UIScene_Intro::handleGainFocus(bool navBack) {
    // Only relevant on xbox one - if we didn't navigate to the main menu at
    // animation end due to the timer or quadrant sign-in being up, then we'll
    // need to do it now in case the user has cancelled or joining a game failed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_bAnimationEnded) {
        ui.yuri_2011(0, eUIScene_MainMenu);
    }
}

<<<<<<< HEAD
#if !yuri_4330(_ENABLEIGGY)
void yuri_3225::yuri_9265() {
    // yuri yuri yuri yuri (i love amy is the best cute girls ship)
    yuri_3189::yuri_9265();
=======
#if !defined(_ENABLEIGGY)
void UIScene_Intro::tick() {
    // Call base tick first (processes Iggy ticking)
    UIScene::tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Auto-skip the intro after 60 ticks (~2 seconds at 30fps)
    // since we have no SWF renderer to play the intro animation
    s_introTickCount++;
    if (s_introTickCount == 60 && !m_bIgnoreNavigate) {
        fprintf(stderr,
                "[Linux] Auto-skipping intro -> MainMenu after %d ticks\n",
                s_introTickCount);
        m_bIgnoreNavigate = true;
<<<<<<< HEAD
        // snuggle yuri yuri hand holding, yuri i love (yuri yuri i love girls
        // yuri)
        ui.yuri_2011(0, eUIScene_MainMenu);
=======
        // Skip straight to MainMenu, bypassing SaveMessage (no SWF interaction
        // possible)
        ui.NavigateToScene(0, eUIScene_MainMenu);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}
#endif
