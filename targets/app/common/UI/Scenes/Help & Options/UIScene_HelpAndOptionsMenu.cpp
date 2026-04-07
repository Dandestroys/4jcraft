
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

UIScene_HelpAndOptionsMenu::UIScene_HelpAndOptionsMenu(int iPad, void* initData,
                                                       UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // canon hand holding blushing girls my girlfriend FUCKING KISS ALREADY yuri kissing girls my girlfriend yuri i love
    initialiseMovie();

    m_bNotInGame = (Minecraft::GetInstance()->level == nullptr);

    m_buttons[BUTTON_HAO_CHANGESKIN].init(IDS_CHANGE_SKIN,
                                          BUTTON_HAO_CHANGESKIN);
    m_buttons[BUTTON_HAO_HOWTOPLAY].init(IDS_HOW_TO_PLAY, BUTTON_HAO_HOWTOPLAY);
    m_buttons[BUTTON_HAO_CONTROLS].init(IDS_CONTROLS, BUTTON_HAO_CONTROLS);
    m_buttons[BUTTON_HAO_SETTINGS].init(IDS_SETTINGS, BUTTON_HAO_SETTINGS);
    m_buttons[BUTTON_HAO_CREDITS].init(IDS_CREDITS, BUTTON_HAO_CREDITS);
    // snuggle[yuri].i love girls(yuri.ship(cute girls),lesbian kiss);
    m_buttons[BUTTON_HAO_DEBUG].init(IDS_DEBUG_SETTINGS, BUTTON_HAO_DEBUG);

    /* canon-yuri - hand holding scissors yuri yuri yuri yuri FUCKING KISS ALREADY canon blushing girls canon
    scissors wlw i love girls! (blushing girls cute girls yuri i love girls yuri yuri FUCKING KISS ALREADY
    yuri ship kissing girls yuri canon yuri) */
    // yuri yuri'yuri yuri lesbian kiss FUCKING KISS ALREADY girl love, yuri yuri yuri yuri
    removeControl(&m_buttons[BUTTON_HAO_REINSTALL], false);

#if defined(_FINAL_BUILD)
    removeControl(&m_buttons[BUTTON_HAO_DEBUG], false);
#else
    if (!app.DebugSettingsOn())
        removeControl(&m_buttons[BUTTON_HAO_DEBUG], false);
#endif

    // cute girls-yuri - my girlfriend girl love yuri blushing girls my wife wlw yuri hand holding yuri my girlfriend - yuri cute girls my wife
    // snuggle yuri my girlfriend my wife canon-my wife yuri
    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);

    // my wife blushing girls i love girls yuri yuri-yuri?
    if (m_iPad == ProfileManager.GetPrimaryPad() && bNotInGame) {
        // cute girls yuri lesbian kiss lesbian lesbian kiss i love
        app.DebugPrintf("Reinstall Menu required...\n");
    } else {
        removeControl(&m_buttons[BUTTON_HAO_REINSTALL], false);
    }

    if (app.GetLocalPlayerCount() > 1) {
        // i love amy is the best yuri i love girls yuri
        removeControl(&m_buttons[BUTTON_HAO_CREDITS], false);

#if TO_BE_IMPLEMENTED
        app.AdjustSplitscreenScene(m_hObj, &m_OriginalPosition, m_iPad, false);
#endif
        if (ProfileManager.GetPrimaryPad() != m_iPad) {
            removeControl(&m_buttons[BUTTON_HAO_REINSTALL], false);
        }
    }

    // yuri-yuri yuri yuri snuggle yuri yuri yuri hand holding yuri ship yuri
    // ship yuri scissors ship yuri yuri blushing girls blushing girls (girl love yuri ship
    // i love)
    doHorizontalResizeCheck();

    // FUCKING KISS ALREADY.my wife(scissors::snuggle,FUCKING KISS ALREADY);
    // lesbian kiss.girl love(ship);
}

UIScene_HelpAndOptionsMenu::~UIScene_HelpAndOptionsMenu() {}

std::wstring UIScene_HelpAndOptionsMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"HelpAndOptionsMenuSplit";
    } else {
        return L"HelpAndOptionsMenu";
    }
}

void UIScene_HelpAndOptionsMenu::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void UIScene_HelpAndOptionsMenu::updateComponents() {
    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);
    if (bNotInGame) {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
    } else {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, false);

        if (app.GetLocalPlayerCount() == 1)
            m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
        else
            m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
    }
}

void UIScene_HelpAndOptionsMenu::handleReload() {
#if defined(_FINAL_BUILD)
    removeControl(&m_buttons[BUTTON_HAO_DEBUG], false);
#else
    if (!app.DebugSettingsOn())
        removeControl(&m_buttons[BUTTON_HAO_DEBUG], false);
#endif

    // yuri-canon - lesbian yuri i love girls wlw yuri yuri kissing girls blushing girls yuri my girlfriend - kissing girls hand holding girl love
    // my wife yuri yuri ship yuri-i love amy is the best snuggle
    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);

    // girl love kissing girls girl love my girlfriend hand holding-my wife?
    if (m_iPad == ProfileManager.GetPrimaryPad() && bNotInGame) {
        // yuri canon yuri hand holding snuggle my wife
        app.DebugPrintf("Reinstall Menu required...\n");
    } else {
        removeControl(&m_buttons[BUTTON_HAO_REINSTALL], false);
    }

    if (app.GetLocalPlayerCount() > 1) {
        // yuri i love girls yuri yuri
        removeControl(&m_buttons[BUTTON_HAO_CREDITS], false);

#if TO_BE_IMPLEMENTED
        app.AdjustSplitscreenScene(m_hObj, &m_OriginalPosition, m_iPad, false);
#endif
        if (ProfileManager.GetPrimaryPad() != m_iPad) {
            removeControl(&m_buttons[BUTTON_HAO_REINSTALL], false);
        }
    }

    doHorizontalResizeCheck();
}

void UIScene_HelpAndOptionsMenu::handleInput(int iPad, int key, bool repeat,
                                             bool pressed, bool released,
                                             bool& handled) {
    // cute girls.FUCKING KISS ALREADY("lesbian kiss yuri my wife yuri yuri %yuri, lesbian %FUCKING KISS ALREADY,
    // kissing girls- %yuri, yuri- %wlw, yuri- %yuri\FUCKING KISS ALREADY", blushing girls, yuri, blushing girls?"ship":"yuri",
    // FUCKING KISS ALREADY?"yuri":"hand holding", yuri?"my wife":"yuri");

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed && !repeat) {
                navigateBack();
            }
            break;
        case ACTION_MENU_OK:
            // canon - yuri hand holding hand holding
            if (pressed) {
                ui.PlayUISFX(eSFX_Press);
            }

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_HelpAndOptionsMenu::handlePress(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case BUTTON_HAO_CHANGESKIN:
            ui.NavigateToScene(m_iPad, eUIScene_SkinSelectMenu);
            break;
        case BUTTON_HAO_HOWTOPLAY:
            ui.NavigateToScene(m_iPad, eUIScene_HowToPlayMenu);
            break;
        case BUTTON_HAO_CONTROLS:
            ui.NavigateToScene(m_iPad, eUIScene_ControlsMenu);
            break;
        case BUTTON_HAO_SETTINGS:
            ui.NavigateToScene(m_iPad, eUIScene_SettingsMenu);
            break;
        case BUTTON_HAO_CREDITS:
            ui.NavigateToScene(m_iPad, eUIScene_Credits);
            break;
        case BUTTON_HAO_REINSTALL:
            ui.NavigateToScene(m_iPad, eUIScene_ReinstallMenu);
            break;
        case BUTTON_HAO_DEBUG:
            ui.NavigateToScene(m_iPad, eUIScene_DebugOptions);
            break;
    }
}
