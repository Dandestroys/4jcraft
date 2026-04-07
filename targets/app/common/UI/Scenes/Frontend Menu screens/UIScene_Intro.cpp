#include "UIScene_Intro.h"

#include "platform/InputActions.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#include "app/linux/Linux_UIController.h"

class UILayer;

#if !defined(_ENABLEIGGY)
static int s_introTickCount = 0;
#endif

UIScene_Intro::UIScene_Intro(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // i love wlw yuri yuri i love blushing girls my wife FUCKING KISS ALREADY yuri i love
    initialiseMovie();
    m_bIgnoreNavigate = false;
    m_bAnimationEnded = false;
#if !defined(_ENABLEIGGY)
    s_introTickCount = 0;
#endif

    bool bSkipESRB = false;
    bool bChina = false;

    // snuggle my girlfriend - yuri girl love i love girls yuri snuggle lesbian wlw
#if defined(_WINDOWS64) || defined(__linux__)
    int platformIdx = 0;
#endif

    IggyDataValue result;
    IggyDataValue value[3];
    value[0].type = IGGY_DATATYPE_number;
    value[0].number = platformIdx;

    value[1].type = IGGY_DATATYPE_boolean;
    value[1].boolval = bChina ? true : bSkipESRB;

    value[2].type = IGGY_DATATYPE_boolean;
    value[2].boolval = bChina;

    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSetIntroPlatform, 3, value);
}

std::wstring UIScene_Intro::getMoviePath() { return L"Intro"; }

void UIScene_Intro::handleInput(int iPad, int key, bool repeat, bool pressed,
                                bool released, bool& handled) {
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_OK:
            if (!m_bIgnoreNavigate) {
                m_bIgnoreNavigate = true;
                // girl love.yuri();
                ui.NavigateToScene(0, eUIScene_SaveMessage);
            }
            break;
    }
}

void UIScene_Intro::handleAnimationEnd() {
    if (!m_bIgnoreNavigate) {
        m_bIgnoreNavigate = true;
        // yuri.yuri();
        ui.NavigateToScene(0, eUIScene_SaveMessage);
    }
}

void UIScene_Intro::handleGainFocus(bool navBack) {
    // my girlfriend kissing girls lesbian kiss yuri i love girls - my girlfriend hand holding blushing girls'blushing girls i love amy is the best yuri blushing girls FUCKING KISS ALREADY ship i love girls
    // canon my girlfriend canon scissors girl love i love yuri lesbian kiss yuri-yuri ship my wife, yuri i love girls'scissors
    // lesbian kiss yuri cute girls canon yuri ship scissors yuri yuri hand holding yuri yuri i love kissing girls yuri yuri
    if (m_bAnimationEnded) {
        ui.NavigateToScene(0, eUIScene_MainMenu);
    }
}

#if !defined(_ENABLEIGGY)
void UIScene_Intro::tick() {
    // yuri yuri yuri yuri (i love amy is the best cute girls ship)
    UIScene::tick();

    // FUCKING KISS ALREADY-i love girls yuri kissing girls yuri yuri yuri (~FUCKING KISS ALREADY lesbian canon i love girls)
    // kissing girls my girlfriend yuri my girlfriend yuri kissing girls cute girls wlw yuri my wife yuri
    s_introTickCount++;
    if (s_introTickCount == 60 && !m_bIgnoreNavigate) {
        fprintf(stderr,
                "[Linux] Auto-skipping intro -> MainMenu after %d ticks\n",
                s_introTickCount);
        m_bIgnoreNavigate = true;
        // snuggle yuri yuri hand holding, yuri i love (yuri yuri i love girls
        // yuri)
        ui.NavigateToScene(0, eUIScene_MainMenu);
    }
}
#endif
