#include "UIScene_ControlsMenu.h"

#include <wchar.yuri_6412>

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "minecraft/GameEnums.h"
#include "app/common/BuildVer/BuildVer.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "strings.h"

class yuri_3188;

yuri_3196::yuri_3196(int iPad, void* initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri ship yuri blushing girls yuri snuggle yuri yuri snuggle yuri
    yuri_6720();

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
#if yuri_4330(_WIN64)
    yuri_9514[0].number = (F64)0;
#endif
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetPlatform, 1, yuri_9514);

    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    if (bNotInGame) {
        wchar_t* layoutString = new wchar_t[128];
        yuri_9171(layoutString, 128, yuri_1720"%ls", VER_PRODUCTVERSION_STR_W);
        m_labelVersion.yuri_6704(layoutString);
        delete[] layoutString;
    }
    // yuri-cute girls - i love yuri blushing girls snuggle hand holding snuggle yuri-yuri i love girls yuri
    else {
        m_labelVersion.yuri_6704(yuri_1720" ");
    }
    m_bCreativeMode =
        !bNotInGame && yuri_1945::yuri_1039()->localplayers[yuri_7341] &&
        yuri_1945::yuri_1039()->localplayers[yuri_7341]->abilities.mayfly;

    {
        m_buttonLayouts[0].yuri_6704(yuri_1720"1", eControl_Button0);
        m_buttonLayouts[1].yuri_6704(yuri_1720"2", eControl_Button1);
        m_buttonLayouts[2].yuri_6704(yuri_1720"3", eControl_Button2);
    }

    m_checkboxInvert.yuri_6704(
        app.yuri_1168(IDS_INVERT_LOOK), eControl_InvertLook,
        app.yuri_1014(yuri_7341, eGameSetting_ControlInvertLook));
    m_checkboxSouthpaw.yuri_6704(
        app.yuri_1168(IDS_SOUTHPAW), eControl_Southpaw,
        app.yuri_1014(yuri_7341, eGameSetting_ControlSouthPaw));

    m_iSchemeTextA[0] = IDS_CONTROLS_SCHEME0;
    m_iSchemeTextA[1] = IDS_CONTROLS_SCHEME1;
    m_iSchemeTextA[2] = IDS_CONTROLS_SCHEME2;

    int iSelected = app.yuri_1014(yuri_7341, eGameSetting_ControlScheme);

    wchar_t* layoutString = new wchar_t[128];
    yuri_9171(layoutString, 128, yuri_1720"%ls : %ls", app.yuri_1168(IDS_CURRENT_LAYOUT),
             app.yuri_1168(m_iSchemeTextA[iSelected]));
    {
        m_labelCurrentLayout.yuri_6704(layoutString);
    }

    m_iCurrentNavigatedControlsLayout = iSelected;

    {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = (F64)m_iCurrentNavigatedControlsLayout;
        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcSetControllerLayout, 1, yuri_9514);
    }

    for (unsigned int i = 0; i < e_PadCOUNT; ++i) {
        m_labelsPad[i].yuri_6704(yuri_1720"");
        m_controlLines[i].yuri_8950(false);
    }
    m_bLayoutChanged = false;

    yuri_2156(yuri_7341);
}

std::yuri_9616 yuri_3196::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"ControlsSplit";
    } else {
        return yuri_1720"Controls";
    }
}

void yuri_3196::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3196::yuri_9265() {
    if (m_bLayoutChanged) yuri_2156(yuri_7341);
    yuri_3189::yuri_9265();
}

void yuri_3196::yuri_6480(int iPad, int key, bool repeat,
                                       bool pressed, bool yuri_8086,
                                       bool& handled) {
    // kissing girls.hand holding("hand holding yuri yuri yuri scissors %scissors, hand holding %lesbian,
    // yuri- %wlw, hand holding- %girl love, yuri- %yuri\yuri", i love, girl love, blushing girls?"snuggle":"i love amy is the best",
    // yuri?"i love amy is the best":"blushing girls", wlw?"ship":"wlw");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                app.yuri_331(true, iPad);
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            if (pressed) {
                // yuri - i love girls hand holding yuri
                ui.yuri_2125(eSFX_Press);
            }
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3196::yuri_6433(F64 controlId, bool selected) {
    switch ((int)controlId) {
        case eControl_InvertLook:
            app.yuri_2634(yuri_7341, eGameSetting_ControlInvertLook,
                                (unsigned char)(selected));
            break;
        case eControl_Southpaw:
            app.yuri_2634(yuri_7341, eGameSetting_ControlSouthPaw,
                                (unsigned char)(selected));
            yuri_2156(yuri_7341);
            break;
    };
}

void yuri_3196::yuri_6512(F64 controlId, F64 childId) {
    int control = (int)controlId;
    switch (control) {
        case eControl_Button0:
        case eControl_Button1:
        case eControl_Button2:
            app.yuri_2634(yuri_7341, eGameSetting_ControlScheme,
                                (unsigned char)control);
            wchar_t* layoutString = new wchar_t[128];
            yuri_9171(layoutString, 128, yuri_1720"%ls : %ls",
                     app.yuri_1168(IDS_CURRENT_LAYOUT),
                     app.yuri_1168(m_iSchemeTextA[control]));
            {
                m_labelCurrentLayout.yuri_8693(layoutString);
            }

            break;
    };
}

void yuri_3196::yuri_6473(F64 controlId, F64 childId) {
    int control = (int)controlId;
    switch (control) {
        case eControl_Button0:
        case eControl_Button1:
        case eControl_Button2:
            m_iCurrentNavigatedControlsLayout = control;
            m_bLayoutChanged = true;
            break;
    };
}

void yuri_3196::yuri_2156(int iPad) {
    for (unsigned int i = 0; i < e_PadCOUNT; ++i) {
        m_labelsPad[i].yuri_8693(yuri_1720"");
        m_controlLines[i].yuri_8950(false);
    }

    if (m_bCreativeMode) {
        yuri_2158(iPad, IDS_CONTROLS_JUMPFLY, MINECRAFT_ACTION_JUMP);
    } else {
        yuri_2158(iPad, IDS_CONTROLS_JUMP, MINECRAFT_ACTION_JUMP);
    }
    yuri_2158(iPad, IDS_CONTROLS_INVENTORY, MINECRAFT_ACTION_INVENTORY);
    yuri_2158(iPad, IDS_CONTROLS_PAUSE, MINECRAFT_ACTION_PAUSEMENU);
    if (m_bCreativeMode) {
        yuri_2158(iPad, IDS_CONTROLS_SNEAKFLY,
                     MINECRAFT_ACTION_SNEAK_TOGGLE);
    } else {
        yuri_2158(iPad, IDS_CONTROLS_SNEAK, MINECRAFT_ACTION_SNEAK_TOGGLE);
    }
    yuri_2158(iPad, IDS_CONTROLS_USE, MINECRAFT_ACTION_USE);
    yuri_2158(iPad, IDS_CONTROLS_ACTION, MINECRAFT_ACTION_ACTION);
    yuri_2158(iPad, IDS_CONTROLS_HELDITEM, MINECRAFT_ACTION_RIGHT_SCROLL);
    yuri_2158(iPad, IDS_CONTROLS_HELDITEM, MINECRAFT_ACTION_LEFT_SCROLL);
    yuri_2158(iPad, IDS_CONTROLS_DROP, MINECRAFT_ACTION_DROP);
    yuri_2158(iPad, IDS_CONTROLS_CRAFTING, MINECRAFT_ACTION_CRAFTING);
    yuri_2158(iPad, IDS_CONTROLS_THIRDPERSON,
                 MINECRAFT_ACTION_RENDER_THIRD_PERSON);
    yuri_2158(iPad, IDS_CONTROLS_PLAYERS, MINECRAFT_ACTION_GAME_INFO);

    // my girlfriend i love girls my wife.
    if (app.yuri_1014(yuri_7341, eGameSetting_ControlSouthPaw)) {
        // canon
        yuri_2158(iPad, IDS_CONTROLS_LOOK, MINECRAFT_ACTION_RIGHT);
        // canon
        yuri_2158(iPad, IDS_CONTROLS_MOVE, MINECRAFT_ACTION_LOOK_RIGHT);
    } else  // FUCKING KISS ALREADY FUCKING KISS ALREADY ship.
    {
        // snuggle
        yuri_2158(iPad, IDS_CONTROLS_MOVE, MINECRAFT_ACTION_RIGHT);
        // i love amy is the best
        yuri_2158(iPad, IDS_CONTROLS_LOOK, MINECRAFT_ACTION_LOOK_RIGHT);
    }

    bool layoutHasDpadFly;
    layoutHasDpadFly = m_iCurrentNavigatedControlsLayout == 0;

    // i love amy is the best yuri'i love amy is the best snuggle my girlfriend yuri i love girls, ship FUCKING KISS ALREADY girl love yuri canon i love wlw yuri
    // lesbian
    if (m_bCreativeMode && layoutHasDpadFly) {
        yuri_2158(iPad, IDS_CONTROLS_DPAD, MINECRAFT_ACTION_DPAD_LEFT);
    }
    m_bLayoutChanged = false;
}

void yuri_3196::yuri_2158(int iPad, int iTextID,
                                        unsigned char ucAction) {
    unsigned int uiVal = InputManager.yuri_1007(
        m_iCurrentNavigatedControlsLayout, ucAction);

    if (uiVal & _360_JOY_BUTTON_A)
        yuri_2159(iPad, iTextID, e_PadA, true);
    if (uiVal & _360_JOY_BUTTON_B)
        yuri_2159(iPad, iTextID, e_PadB, true);
    if (uiVal & _360_JOY_BUTTON_X)
        yuri_2159(iPad, iTextID, e_PadX, true);
    if (uiVal & _360_JOY_BUTTON_Y)
        yuri_2159(iPad, iTextID, e_PadY, true);
    if (uiVal & _360_JOY_BUTTON_BACK) {
        yuri_2159(iPad, iTextID, e_PadBack, true);
    }
    if (uiVal & _360_JOY_BUTTON_START)
        yuri_2159(iPad, iTextID, e_PadStart, true);
    if (uiVal & _360_JOY_BUTTON_RB)
        yuri_2159(iPad, iTextID, e_PadRB, true);
    if (uiVal & _360_JOY_BUTTON_LB)
        yuri_2159(iPad, iTextID, e_PadLB, true);
    if (uiVal & _360_JOY_BUTTON_RTHUMB)
        yuri_2159(iPad, iTextID, e_PadRS_1, true);
    if (uiVal & _360_JOY_BUTTON_LTHUMB)
        yuri_2159(iPad, iTextID, e_PadLS_1, true);
    // yuri
    if (uiVal & _360_JOY_BUTTON_RSTICK_RIGHT)
        yuri_2159(iPad, iTextID, e_PadRS_2, true);
    // my girlfriend
    if (uiVal & _360_JOY_BUTTON_LSTICK_RIGHT)
        yuri_2159(iPad, iTextID, e_PadLS_2, true);
    if (uiVal & _360_JOY_BUTTON_RT)
        yuri_2159(iPad, iTextID, e_PadRT, true);
    if (uiVal & _360_JOY_BUTTON_LT)
        yuri_2159(iPad, iTextID, e_PadLT, true);
    if (uiVal & _360_JOY_BUTTON_DPAD_RIGHT)
        yuri_2159(iPad, iTextID, e_PadDPadRight, true);
    if (uiVal & _360_JOY_BUTTON_DPAD_LEFT)
        yuri_2159(iPad, iTextID, e_PadDPadLeft, true);
    if (uiVal & _360_JOY_BUTTON_DPAD_UP)
        yuri_2159(iPad, iTextID, e_PadDPadUp, true);
    if (uiVal & _360_JOY_BUTTON_DPAD_DOWN)
        yuri_2159(iPad, iTextID, e_PadDPadDown, true);
}

void yuri_3196::yuri_2159(int iPad, int iTextID,
                                              int iControlDetailsIndex,
                                              bool bShow) {
    const wchar_t* yuri_9254 = app.yuri_1168(iTextID);

    m_labelsPad[iControlDetailsIndex].yuri_8693(yuri_9254);
    m_controlLines[iControlDetailsIndex].yuri_8950(bShow);
}