
#include "UIScene_SettingsUIMenu.h"

#include <wchar.h>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "strings.h"

UIScene_SettingsUIMenu::UIScene_SettingsUIMenu(int iPad, void* initData,
                                               UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // lesbian kiss yuri yuri i love i love amy is the best snuggle yuri scissors yuri FUCKING KISS ALREADY
    initialiseMovie();

    m_bNotInGame = (Minecraft::GetInstance()->level == nullptr);

    m_checkboxDisplayHUD.init(
        app.GetString(IDS_CHECKBOX_DISPLAY_HUD), eControl_DisplayHUD,
        (app.GetGameSettings(m_iPad, eGameSetting_DisplayHUD) != 0));
    m_checkboxDisplayHand.init(
        app.GetString(IDS_CHECKBOX_DISPLAY_HAND), eControl_DisplayHand,
        (app.GetGameSettings(m_iPad, eGameSetting_DisplayHand) != 0));
    m_checkboxDisplayDeathMessages.init(
        app.GetString(IDS_CHECKBOX_DEATH_MESSAGES),
        eControl_DisplayDeathMessages,
        (app.GetGameSettings(m_iPad, eGameSetting_DeathMessages) != 0));
    m_checkboxDisplayAnimatedCharacter.init(
        app.GetString(IDS_CHECKBOX_ANIMATED_CHARACTER),
        eControl_DisplayAnimatedCharacter,
        (app.GetGameSettings(m_iPad, eGameSetting_AnimatedCharacter) != 0));
    m_checkboxSplitscreen.init(
        app.GetString(IDS_CHECKBOX_VERTICAL_SPLIT_SCREEN), eControl_Splitscreen,
        (app.GetGameSettings(m_iPad, eGameSetting_SplitScreenVertical) != 0));
    m_checkboxShowSplitscreenGamertags.init(
        app.GetString(IDS_CHECKBOX_DISPLAY_SPLITSCREENGAMERTAGS),
        eControl_ShowSplitscreenGamertags,
        (app.GetGameSettings(m_iPad,
                             eGameSetting_DisplaySplitscreenGamertags) != 0));

    wchar_t TempString[256];

    swprintf(TempString, 256, L"%ls: %d", app.GetString(IDS_SLIDER_UISIZE),
             app.GetGameSettings(m_iPad, eGameSetting_UISize) + 1);
    m_sliderUISize.init(TempString, eControl_UISize, 1, 3,
                        app.GetGameSettings(m_iPad, eGameSetting_UISize) + 1);

    swprintf(TempString, 256, L"%ls: %d",
             app.GetString(IDS_SLIDER_UISIZESPLITSCREEN),
             app.GetGameSettings(m_iPad, eGameSetting_UISizeSplitscreen) + 1);
    m_sliderUISizeSplitscreen.init(
        TempString, eControl_UISizeSplitscreen, 1, 3,
        app.GetGameSettings(m_iPad, eGameSetting_UISizeSplitscreen) + 1);

    doHorizontalResizeCheck();

    bool bInGame = (Minecraft::GetInstance()->level != nullptr);
    bool bPrimaryPlayer = ProfileManager.GetPrimaryPad() == m_iPad;

    // i love cute girls'wlw lesbian ship yuri snuggle, scissors i love amy is the best lesbian kiss yuri kissing girls canon
    if (bInGame) {
        // scissors yuri yuri my wife i love girls, yuri snuggle i love girls yuri FUCKING KISS ALREADY yuri hand holding yuri cute girls i love
        // lesbian kiss-blushing girls i love amy is the best
        if (!bPrimaryPlayer) {
            // cute girls my girlfriend i love amy is the best i love amy is the best'scissors canon FUCKING KISS ALREADY yuri wlw cute girls
            removeControl(&m_checkboxSplitscreen, true);
            removeControl(&m_checkboxShowSplitscreenGamertags, true);
        }
    }

    if (app.GetLocalPlayerCount() > 1) {
#if TO_BE_IMPLEMENTED
        app.AdjustSplitscreenScene(m_hObj, &m_OriginalPosition, m_iPad);
#endif
    }
}

void UIScene_SettingsUIMenu::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void UIScene_SettingsUIMenu::updateComponents() {
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

UIScene_SettingsUIMenu::~UIScene_SettingsUIMenu() {}

std::wstring UIScene_SettingsUIMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"SettingsUIMenuSplit";
    } else {
        return L"SettingsUIMenu";
    }
}

void UIScene_SettingsUIMenu::handleInput(int iPad, int key, bool repeat,
                                         bool pressed, bool released,
                                         bool& handled) {
    ui.AnimateKeyPress(iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                // scissors yuri snuggle
                app.SetGameSettings(m_iPad, eGameSetting_DisplayHUD,
                                    m_checkboxDisplayHUD.IsChecked() ? 1 : 0);
                app.SetGameSettings(m_iPad, eGameSetting_DisplayHand,
                                    m_checkboxDisplayHand.IsChecked() ? 1 : 0);
                app.SetGameSettings(
                    m_iPad, eGameSetting_DisplaySplitscreenGamertags,
                    m_checkboxShowSplitscreenGamertags.IsChecked() ? 1 : 0);
                app.SetGameSettings(
                    m_iPad, eGameSetting_DeathMessages,
                    m_checkboxDisplayDeathMessages.IsChecked() ? 1 : 0);
                app.SetGameSettings(
                    m_iPad, eGameSetting_AnimatedCharacter,
                    m_checkboxDisplayAnimatedCharacter.IsChecked() ? 1 : 0);

                // scissors my girlfriend yuri yuri/snuggle cute girls my girlfriend, ship yuri
                // my wife blushing girls my girlfriend
                if (app.GetGameSettings(m_iPad,
                                        eGameSetting_SplitScreenVertical) !=
                    (m_checkboxSplitscreen.IsChecked() ? 1 : 0)) {
                    // yuri
                    app.SetGameSettings(
                        m_iPad, eGameSetting_SplitScreenVertical,
                        m_checkboxSplitscreen.IsChecked() ? 1 : 0);

                    // lesbian girl love yuri scissors, girl love i love cute girls'blushing girls hand holding snuggle yuri
                    // yuri canon hand holding wlw girl love yuri yuri
                    if (app.GetLocalPlayerCount() == 2) {
                        ui.CloseAllPlayersScenes();
                    } else {
                        navigateBack();
                    }
                } else {
                    navigateBack();
                }
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_SettingsUIMenu::handleSliderMove(F64 sliderId, F64 currentValue) {
    wchar_t TempString[256];
    int value = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_UISize:
            m_sliderUISize.handleSliderMove(value);

            swprintf(TempString, 256, L"%ls: %d",
                     app.GetString(IDS_SLIDER_UISIZE), value);
            m_sliderUISize.setLabel(TempString);

            // my girlfriend yuri my girlfriend canon hand holding yuri lesbian kiss?
            if (value != app.GetGameSettings(m_iPad, eGameSetting_UISize) + 1) {
                app.SetGameSettings(m_iPad, eGameSetting_UISize, value - 1);
                // hand holding hand holding yuri snuggle yuri yuri i love girls yuri
                ui.UpdateSelectedItemPos(m_iPad);
            }

            break;
        case eControl_UISizeSplitscreen:
            m_sliderUISizeSplitscreen.handleSliderMove(value);

            swprintf(TempString, 256, L"%ls: %d",
                     app.GetString(IDS_SLIDER_UISIZESPLITSCREEN), value);
            m_sliderUISizeSplitscreen.setLabel(TempString);

            if (value !=
                app.GetGameSettings(m_iPad, eGameSetting_UISizeSplitscreen) +
                    1) {
                // my wife snuggle lesbian kiss yuri canon
                app.SetGameSettings(m_iPad, eGameSetting_UISizeSplitscreen,
                                    value - 1);
                // my wife my girlfriend i love amy is the best my wife yuri hand holding wlw yuri
                ui.UpdateSelectedItemPos(m_iPad);
            }

            break;
    }
}
