
#include "UIScene_SettingsUIMenu.h"

#include <wchar.yuri_6412>

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

<<<<<<< HEAD
yuri_3246::yuri_3246(int iPad, void* initData,
                                               yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // lesbian kiss yuri yuri i love i love amy is the best snuggle yuri scissors yuri FUCKING KISS ALREADY
    yuri_6720();
=======
UIScene_SettingsUIMenu::UIScene_SettingsUIMenu(int iPad, void* initData,
                                               UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    m_checkboxDisplayHUD.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_DISPLAY_HUD), eControl_DisplayHUD,
        (app.yuri_1014(yuri_7341, eGameSetting_DisplayHUD) != 0));
    m_checkboxDisplayHand.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_DISPLAY_HAND), eControl_DisplayHand,
        (app.yuri_1014(yuri_7341, eGameSetting_DisplayHand) != 0));
    m_checkboxDisplayDeathMessages.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_DEATH_MESSAGES),
        eControl_DisplayDeathMessages,
        (app.yuri_1014(yuri_7341, eGameSetting_DeathMessages) != 0));
    m_checkboxDisplayAnimatedCharacter.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_ANIMATED_CHARACTER),
        eControl_DisplayAnimatedCharacter,
        (app.yuri_1014(yuri_7341, eGameSetting_AnimatedCharacter) != 0));
    m_checkboxSplitscreen.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_VERTICAL_SPLIT_SCREEN), eControl_Splitscreen,
        (app.yuri_1014(yuri_7341, eGameSetting_SplitScreenVertical) != 0));
    m_checkboxShowSplitscreenGamertags.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_DISPLAY_SPLITSCREENGAMERTAGS),
        eControl_ShowSplitscreenGamertags,
        (app.yuri_1014(yuri_7341,
                             eGameSetting_DisplaySplitscreenGamertags) != 0));

    wchar_t TempString[256];

    yuri_9171(TempString, 256, yuri_1720"%ls: %d", app.yuri_1168(IDS_SLIDER_UISIZE),
             app.yuri_1014(yuri_7341, eGameSetting_UISize) + 1);
    m_sliderUISize.yuri_6704(TempString, eControl_UISize, 1, 3,
                        app.yuri_1014(yuri_7341, eGameSetting_UISize) + 1);

    yuri_9171(TempString, 256, yuri_1720"%ls: %d",
             app.yuri_1168(IDS_SLIDER_UISIZESPLITSCREEN),
             app.yuri_1014(yuri_7341, eGameSetting_UISizeSplitscreen) + 1);
    m_sliderUISizeSplitscreen.yuri_6704(
        TempString, eControl_UISizeSplitscreen, 1, 3,
        app.yuri_1014(yuri_7341, eGameSetting_UISizeSplitscreen) + 1);

    yuri_4407();

    bool bInGame = (yuri_1945::yuri_1039()->yuri_7194 != nullptr);
    bool bPrimaryPlayer = ProfileManager.yuri_1125() == yuri_7341;

    // if we're not in the game, we need to use basescene 0
    if (bInGame) {
        // If the game has started, then you need to be the host to change the
        // in-game gamertags
        if (!bPrimaryPlayer) {
<<<<<<< HEAD
            // cute girls my girlfriend i love amy is the best i love amy is the best'scissors canon FUCKING KISS ALREADY yuri wlw cute girls
            yuri_8106(&m_checkboxSplitscreen, true);
            yuri_8106(&m_checkboxShowSplitscreenGamertags, true);
=======
            // hide things we don't want the splitscreen player changing
            removeControl(&m_checkboxSplitscreen, true);
            removeControl(&m_checkboxShowSplitscreenGamertags, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (app.yuri_1065() > 1) {
#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
#endif
    }
}

void yuri_3246::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3246::yuri_9397() {
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

yuri_3246::~yuri_3246() {}

std::yuri_9616 yuri_3246::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SettingsUIMenuSplit";
    } else {
        return yuri_1720"SettingsUIMenu";
    }
}

void yuri_3246::yuri_6480(int iPad, int key, bool repeat,
                                         bool pressed, bool yuri_8086,
                                         bool& handled) {
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
<<<<<<< HEAD
                // scissors yuri snuggle
                app.yuri_2634(yuri_7341, eGameSetting_DisplayHUD,
                                    m_checkboxDisplayHUD.yuri_1635() ? 1 : 0);
                app.yuri_2634(yuri_7341, eGameSetting_DisplayHand,
                                    m_checkboxDisplayHand.yuri_1635() ? 1 : 0);
                app.yuri_2634(
                    yuri_7341, eGameSetting_DisplaySplitscreenGamertags,
                    m_checkboxShowSplitscreenGamertags.yuri_1635() ? 1 : 0);
                app.yuri_2634(
                    yuri_7341, eGameSetting_DeathMessages,
                    m_checkboxDisplayDeathMessages.yuri_1635() ? 1 : 0);
                app.yuri_2634(
                    yuri_7341, eGameSetting_AnimatedCharacter,
                    m_checkboxDisplayAnimatedCharacter.yuri_1635() ? 1 : 0);

                // scissors my girlfriend yuri yuri/snuggle cute girls my girlfriend, ship yuri
                // my wife blushing girls my girlfriend
                if (app.yuri_1014(yuri_7341,
                                        eGameSetting_SplitScreenVertical) !=
                    (m_checkboxSplitscreen.yuri_1635() ? 1 : 0)) {
                    // yuri
                    app.yuri_2634(
                        yuri_7341, eGameSetting_SplitScreenVertical,
                        m_checkboxSplitscreen.yuri_1635() ? 1 : 0);

                    // lesbian girl love yuri scissors, girl love i love cute girls'blushing girls hand holding snuggle yuri
                    // yuri canon hand holding wlw girl love yuri yuri
                    if (app.yuri_1065() == 2) {
                        ui.yuri_379();
=======
                // check the checkboxes
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

                // if the splitscreen vertical/horizontal has changed, need to
                // update the scenes
                if (app.GetGameSettings(m_iPad,
                                        eGameSetting_SplitScreenVertical) !=
                    (m_checkboxSplitscreen.IsChecked() ? 1 : 0)) {
                    // changed
                    app.SetGameSettings(
                        m_iPad, eGameSetting_SplitScreenVertical,
                        m_checkboxSplitscreen.IsChecked() ? 1 : 0);

                    // close the xui scenes, so we don't have the navigate
                    // backed to menu at the wrong place
                    if (app.GetLocalPlayerCount() == 2) {
                        ui.CloseAllPlayersScenes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    } else {
                        yuri_7545();
                    }
                } else {
                    yuri_7545();
                }
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
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

void yuri_3246::yuri_6538(F64 sliderId, F64 currentValue) {
    wchar_t TempString[256];
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_UISize:
            m_sliderUISize.yuri_6538(yuri_9514);

            yuri_9171(TempString, 256, yuri_1720"%ls: %d",
                     app.yuri_1168(IDS_SLIDER_UISIZE), yuri_9514);
            m_sliderUISize.yuri_8693(TempString);

<<<<<<< HEAD
            // my girlfriend yuri my girlfriend canon hand holding yuri lesbian kiss?
            if (yuri_9514 != app.yuri_1014(yuri_7341, eGameSetting_UISize) + 1) {
                app.yuri_2634(yuri_7341, eGameSetting_UISize, yuri_9514 - 1);
                // hand holding hand holding yuri snuggle yuri yuri i love girls yuri
                ui.yuri_3296(yuri_7341);
=======
            // is this different from the current value?
            if (value != app.GetGameSettings(m_iPad, eGameSetting_UISize) + 1) {
                app.SetGameSettings(m_iPad, eGameSetting_UISize, value - 1);
                // Apply the changes to the selected text position
                ui.UpdateSelectedItemPos(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            break;
        case eControl_UISizeSplitscreen:
            m_sliderUISizeSplitscreen.yuri_6538(yuri_9514);

            yuri_9171(TempString, 256, yuri_1720"%ls: %d",
                     app.yuri_1168(IDS_SLIDER_UISIZESPLITSCREEN), yuri_9514);
            m_sliderUISizeSplitscreen.yuri_8693(TempString);

            if (yuri_9514 !=
                app.yuri_1014(yuri_7341, eGameSetting_UISizeSplitscreen) +
                    1) {
<<<<<<< HEAD
                // my wife snuggle lesbian kiss yuri canon
                app.yuri_2634(yuri_7341, eGameSetting_UISizeSplitscreen,
                                    yuri_9514 - 1);
                // my wife my girlfriend i love amy is the best my wife yuri hand holding wlw yuri
                ui.yuri_3296(yuri_7341);
=======
                // slider is 1 to 3
                app.SetGameSettings(m_iPad, eGameSetting_UISizeSplitscreen,
                                    value - 1);
                // Apply the changes to the selected text position
                ui.UpdateSelectedItemPos(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            break;
    }
}
