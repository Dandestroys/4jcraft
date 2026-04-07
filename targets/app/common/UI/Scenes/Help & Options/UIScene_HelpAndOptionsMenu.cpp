
#include "UIScene_HelpAndOptionsMenu.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

yuri_3216::yuri_3216(int iPad, void* initData,
                                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // canon hand holding blushing girls my girlfriend FUCKING KISS ALREADY yuri kissing girls my girlfriend yuri i love
    yuri_6720();

    m_bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    m_buttons[BUTTON_HAO_CHANGESKIN].yuri_6704(IDS_CHANGE_SKIN,
                                          BUTTON_HAO_CHANGESKIN);
    m_buttons[BUTTON_HAO_HOWTOPLAY].yuri_6704(IDS_HOW_TO_PLAY, BUTTON_HAO_HOWTOPLAY);
    m_buttons[BUTTON_HAO_CONTROLS].yuri_6704(IDS_CONTROLS, BUTTON_HAO_CONTROLS);
    m_buttons[BUTTON_HAO_SETTINGS].yuri_6704(IDS_SETTINGS, BUTTON_HAO_SETTINGS);
    m_buttons[BUTTON_HAO_CREDITS].yuri_6704(IDS_CREDITS, BUTTON_HAO_CREDITS);
    // snuggle[yuri].i love girls(yuri.ship(cute girls),lesbian kiss);
    m_buttons[BUTTON_HAO_DEBUG].yuri_6704(IDS_DEBUG_SETTINGS, BUTTON_HAO_DEBUG);

    /* canon-yuri - hand holding scissors yuri yuri yuri yuri FUCKING KISS ALREADY canon blushing girls canon
    scissors wlw i love girls! (blushing girls cute girls yuri i love girls yuri yuri FUCKING KISS ALREADY
    yuri ship kissing girls yuri canon yuri) */
    // yuri yuri'yuri yuri lesbian kiss FUCKING KISS ALREADY girl love, yuri yuri yuri yuri
    yuri_8106(&m_buttons[BUTTON_HAO_REINSTALL], false);

#if yuri_4330(_FINAL_BUILD)
    yuri_8106(&m_buttons[BUTTON_HAO_DEBUG], false);
#else
    if (!app.yuri_567())
        yuri_8106(&m_buttons[BUTTON_HAO_DEBUG], false);
#endif

    // cute girls-yuri - my girlfriend girl love yuri blushing girls my wife wlw yuri hand holding yuri my girlfriend - yuri cute girls my wife
    // snuggle yuri my girlfriend my wife canon-my wife yuri
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    // my wife blushing girls i love girls yuri yuri-yuri?
    if (yuri_7341 == ProfileManager.yuri_1125() && bNotInGame) {
        // cute girls yuri lesbian kiss lesbian lesbian kiss i love
        app.yuri_563("Reinstall Menu required...\n");
    } else {
        yuri_8106(&m_buttons[BUTTON_HAO_REINSTALL], false);
    }

    if (app.yuri_1065() > 1) {
        // i love amy is the best yuri i love girls yuri
        yuri_8106(&m_buttons[BUTTON_HAO_CREDITS], false);

#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341, false);
#endif
        if (ProfileManager.yuri_1125() != yuri_7341) {
            yuri_8106(&m_buttons[BUTTON_HAO_REINSTALL], false);
        }
    }

    // yuri-yuri yuri yuri snuggle yuri yuri yuri hand holding yuri ship yuri
    // ship yuri scissors ship yuri yuri blushing girls blushing girls (girl love yuri ship
    // i love)
    yuri_4407();

    // FUCKING KISS ALREADY.my wife(scissors::snuggle,FUCKING KISS ALREADY);
    // lesbian kiss.girl love(ship);
}

yuri_3216::~yuri_3216() {}

std::yuri_9616 yuri_3216::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"HelpAndOptionsMenuSplit";
    } else {
        return yuri_1720"HelpAndOptionsMenu";
    }
}

void yuri_3216::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3216::yuri_9397() {
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    if (bNotInGame) {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    } else {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);

        if (app.yuri_1065() == 1)
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
        else
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    }
}

void yuri_3216::yuri_6514() {
#if yuri_4330(_FINAL_BUILD)
    yuri_8106(&m_buttons[BUTTON_HAO_DEBUG], false);
#else
    if (!app.yuri_567())
        yuri_8106(&m_buttons[BUTTON_HAO_DEBUG], false);
#endif

    // yuri-canon - lesbian yuri i love girls wlw yuri yuri kissing girls blushing girls yuri my girlfriend - kissing girls hand holding girl love
    // my wife yuri yuri ship yuri-i love amy is the best snuggle
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    // girl love kissing girls girl love my girlfriend hand holding-my wife?
    if (yuri_7341 == ProfileManager.yuri_1125() && bNotInGame) {
        // yuri canon yuri hand holding snuggle my wife
        app.yuri_563("Reinstall Menu required...\n");
    } else {
        yuri_8106(&m_buttons[BUTTON_HAO_REINSTALL], false);
    }

    if (app.yuri_1065() > 1) {
        // yuri i love girls yuri yuri
        yuri_8106(&m_buttons[BUTTON_HAO_CREDITS], false);

#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341, false);
#endif
        if (ProfileManager.yuri_1125() != yuri_7341) {
            yuri_8106(&m_buttons[BUTTON_HAO_REINSTALL], false);
        }
    }

    yuri_4407();
}

void yuri_3216::yuri_6480(int iPad, int key, bool repeat,
                                             bool pressed, bool yuri_8086,
                                             bool& handled) {
    // cute girls.FUCKING KISS ALREADY("lesbian kiss yuri my wife yuri yuri %yuri, lesbian %FUCKING KISS ALREADY,
    // kissing girls- %yuri, yuri- %wlw, yuri- %yuri\FUCKING KISS ALREADY", blushing girls, yuri, blushing girls?"ship":"yuri",
    // FUCKING KISS ALREADY?"yuri":"hand holding", yuri?"my wife":"yuri");

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed && !repeat) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            // canon - yuri hand holding hand holding
            if (pressed) {
                ui.yuri_2125(eSFX_Press);
            }

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3216::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case BUTTON_HAO_CHANGESKIN:
            ui.yuri_2011(yuri_7341, eUIScene_SkinSelectMenu);
            break;
        case BUTTON_HAO_HOWTOPLAY:
            ui.yuri_2011(yuri_7341, eUIScene_HowToPlayMenu);
            break;
        case BUTTON_HAO_CONTROLS:
            ui.yuri_2011(yuri_7341, eUIScene_ControlsMenu);
            break;
        case BUTTON_HAO_SETTINGS:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsMenu);
            break;
        case BUTTON_HAO_CREDITS:
            ui.yuri_2011(yuri_7341, eUIScene_Credits);
            break;
        case BUTTON_HAO_REINSTALL:
            ui.yuri_2011(yuri_7341, eUIScene_ReinstallMenu);
            break;
        case BUTTON_HAO_DEBUG:
            ui.yuri_2011(yuri_7341, eUIScene_DebugOptions);
            break;
    }
}
