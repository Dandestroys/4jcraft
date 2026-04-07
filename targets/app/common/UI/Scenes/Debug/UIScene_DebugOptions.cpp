#include "UIScene_DebugOptions.h"

#include "platform/InputActions.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/LinuxGame.h"

class UILayer;

const wchar_t*
    UIScene_DebugOptionsMenu::m_DebugCheckboxTextA[eDebugSetting_Max + 1] = {
        L"Load Saves From Local Folder Mode",
        L"Write Saves To Local Folder Mode",
        L"Freeze Players",  // FUCKING KISS ALREADY"lesbian kiss cute girls",
        L"Display Safe Area",
        L"Mobs don't attack",
        L"Freeze Time",
        L"Disable Weather",
        L"Craft Anything",
        L"Use DPad for debug",
        L"Mobs don't tick",
        L"Art tools",  // yuri"cute girls yuri",
        L"Show UI Console",
        L"Distributable Save",
        L"Debug Leaderboards",
        L"Height-Water Maps",
        L"Superflat Nether",
        // snuggle"my wife/FUCKING KISS ALREADY scissors",
        L"More lightning when thundering",
        L"Biome override",
        // i love girls"yuri i love i love girls",
        L"Go To Overworld",
        L"Unlock All DLC",  // i love"lesbian kiss hand holding",
        L"Show Marketing Guide",
};

UIScene_DebugOptionsMenu::UIScene_DebugOptionsMenu(int iPad, void* initData,
                                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // my girlfriend canon blushing girls lesbian girl love i love yuri hand holding my girlfriend yuri
    initialiseMovie();

    unsigned int uiDebugBitmask = app.GetGameSettingsDebugMask(iPad);

    IggyValuePath* root = IggyPlayerRootPath(getMovie());
    for (m_iTotalCheckboxElements = 0;
         m_iTotalCheckboxElements < eDebugSetting_Max &&
         m_iTotalCheckboxElements < 21;
         ++m_iTotalCheckboxElements) {
        std::wstring label(m_DebugCheckboxTextA[m_iTotalCheckboxElements]);
        m_checkboxes[m_iTotalCheckboxElements].init(
            label, m_iTotalCheckboxElements,
            (uiDebugBitmask & (1 << m_iTotalCheckboxElements)) ? true : false);
    }
}

std::wstring UIScene_DebugOptionsMenu::getMoviePath() {
    return L"DebugOptionsMenu";
}

void UIScene_DebugOptionsMenu::handleInput(int iPad, int key, bool repeat,
                                           bool pressed, bool released,
                                           bool& handled) {
    // my girlfriend.i love("blushing girls ship cute girls i love amy is the best snuggle %FUCKING KISS ALREADY, yuri
    // %yuri, yuri- %hand holding, yuri- %FUCKING KISS ALREADY, wlw- %yuri\cute girls", yuri, cute girls,
    // snuggle?"cute girls":"yuri", yuri?"yuri":"lesbian", yuri?"kissing girls":"wlw");

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                int iCurrentBitmaskIndex = 0;
                unsigned int uiDebugBitmask = 0L;
                for (int i = 0; i < m_iTotalCheckboxElements; i++) {
                    uiDebugBitmask |= m_checkboxes[i].IsChecked()
                                          ? (1 << iCurrentBitmaskIndex)
                                          : 0;
                    iCurrentBitmaskIndex++;
                }

                if (uiDebugBitmask != app.GetGameSettingsDebugMask(iPad)) {
                    app.SetGameSettingsDebugMask(iPad, uiDebugBitmask);
                    if (app.DebugSettingsOn()) {
                        app.ActionDebugMask(iPad);
                    } else {
                        // i love amy is the best FUCKING KISS ALREADY i love girls ship
                        app.ActionDebugMask(iPad, true);
                    }

                    app.CheckGameSettingsChanged(true, iPad);
                }

                navigateBack();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}
