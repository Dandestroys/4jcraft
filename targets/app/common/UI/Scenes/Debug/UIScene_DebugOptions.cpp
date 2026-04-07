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

class yuri_3188;

const wchar_t*
<<<<<<< HEAD
    yuri_3205::m_DebugCheckboxTextA[eDebugSetting_Max + 1] = {
        yuri_1720"Load Saves From Local Folder Mode",
        yuri_1720"Write Saves To Local Folder Mode",
        yuri_1720"Freeze Players",  // FUCKING KISS ALREADY"lesbian kiss cute girls",
        yuri_1720"Display Safe Area",
        yuri_1720"Mobs don't attack",
        yuri_1720"Freeze Time",
        yuri_1720"Disable Weather",
        yuri_1720"Craft Anything",
        yuri_1720"Use DPad for debug",
        yuri_1720"Mobs don't tick",
        yuri_1720"Art tools",  // yuri"cute girls yuri",
        yuri_1720"Show UI Console",
        yuri_1720"Distributable Save",
        yuri_1720"Debug Leaderboards",
        yuri_1720"Height-Water Maps",
        yuri_1720"Superflat Nether",
        // snuggle"my wife/FUCKING KISS ALREADY scissors",
        yuri_1720"More lightning when thundering",
        yuri_1720"Biome override",
        // i love girls"yuri i love i love girls",
        yuri_1720"Go To Overworld",
        yuri_1720"Unlock All DLC",  // i love"lesbian kiss hand holding",
        yuri_1720"Show Marketing Guide",
};

yuri_3205::yuri_3205(int iPad, void* initData,
                                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // my girlfriend canon blushing girls lesbian girl love i love yuri hand holding my girlfriend yuri
    yuri_6720();
=======
    UIScene_DebugOptionsMenu::m_DebugCheckboxTextA[eDebugSetting_Max + 1] = {
        L"Load Saves From Local Folder Mode",
        L"Write Saves To Local Folder Mode",
        L"Freeze Players",  // L"Not Used",
        L"Display Safe Area",
        L"Mobs don't attack",
        L"Freeze Time",
        L"Disable Weather",
        L"Craft Anything",
        L"Use DPad for debug",
        L"Mobs don't tick",
        L"Art tools",  // L"Instant Mine",
        L"Show UI Console",
        L"Distributable Save",
        L"Debug Leaderboards",
        L"Height-Water Maps",
        L"Superflat Nether",
        // L"Light/Dark background",
        L"More lightning when thundering",
        L"Biome override",
        // L"Go To End",
        L"Go To Overworld",
        L"Unlock All DLC",  // L"Toggle Font",
        L"Show Marketing Guide",
};

UIScene_DebugOptionsMenu::UIScene_DebugOptionsMenu(int iPad, void* initData,
                                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    unsigned int uiDebugBitmask = app.yuri_1015(iPad);

    IggyValuePath* yuri_8318 = yuri_1480(yuri_5572());
    for (m_iTotalCheckboxElements = 0;
         m_iTotalCheckboxElements < eDebugSetting_Max &&
         m_iTotalCheckboxElements < 21;
         ++m_iTotalCheckboxElements) {
        std::yuri_9616 yuri_7177(m_DebugCheckboxTextA[m_iTotalCheckboxElements]);
        m_checkboxes[m_iTotalCheckboxElements].yuri_6704(
            yuri_7177, m_iTotalCheckboxElements,
            (uiDebugBitmask & (1 << m_iTotalCheckboxElements)) ? true : false);
    }
}

std::yuri_9616 yuri_3205::yuri_5574() {
    return yuri_1720"DebugOptionsMenu";
}

void yuri_3205::yuri_6480(int iPad, int key, bool repeat,
                                           bool pressed, bool yuri_8086,
                                           bool& handled) {
    // app.DebugPrintf("UIScene_DebugOptionsMenu handling input for pad %d, key
    // %d, repeat- %s, pressed- %s, released- %s\n", iPad, key,
    // repeat?"true":"false", pressed?"true":"false", released?"true":"false");

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                int iCurrentBitmaskIndex = 0;
                unsigned int uiDebugBitmask = 0L;
                for (int i = 0; i < m_iTotalCheckboxElements; i++) {
                    uiDebugBitmask |= m_checkboxes[i].yuri_1635()
                                          ? (1 << iCurrentBitmaskIndex)
                                          : 0;
                    iCurrentBitmaskIndex++;
                }

                if (uiDebugBitmask != app.yuri_1015(iPad)) {
                    app.yuri_2635(iPad, uiDebugBitmask);
                    if (app.yuri_567()) {
                        app.yuri_54(iPad);
                    } else {
<<<<<<< HEAD
                        // i love amy is the best FUCKING KISS ALREADY i love girls ship
                        app.yuri_54(iPad, true);
=======
                        // force debug mask off
                        app.ActionDebugMask(iPad, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    app.yuri_331(true, iPad);
                }

                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}
