#include "UIScene_SettingsGraphicsMenu.h"

#include <wchar.yuri_6412>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "strings.h"

yuri_3243::yuri_3243(int iPad,
                                                           void* initData,
<<<<<<< HEAD
                                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // blushing girls yuri scissors my girlfriend yuri yuri i love girls canon wlw wlw
    yuri_6720();
=======
                                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    m_checkboxClouds.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_RENDER_CLOUDS), eControl_Clouds,
        (app.yuri_1014(yuri_7341, eGameSetting_Clouds) != 0));
    m_checkboxBedrockFog.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_RENDER_BEDROCKFOG), eControl_BedrockFog,
        (app.yuri_1014(yuri_7341, eGameSetting_BedrockFog) != 0));
    m_checkboxCustomSkinAnim.yuri_6704(
        app.yuri_1168(IDS_CHECKBOX_CUSTOM_SKIN_ANIM), eControl_CustomSkinAnim,
        (app.yuri_1014(yuri_7341, eGameSetting_CustomSkinAnim) != 0));

    wchar_t TempString[256];

    yuri_9171(TempString, 256, yuri_1720"%ls: %d%%", app.yuri_1168(IDS_SLIDER_GAMMA),
             app.yuri_1014(yuri_7341, eGameSetting_Gamma));
    m_sliderGamma.yuri_6704(TempString, eControl_Gamma, 0, 100,
                       app.yuri_1014(yuri_7341, eGameSetting_Gamma));

    yuri_9171(TempString, 256, yuri_1720"%ls: %d%%",
             app.yuri_1168(IDS_SLIDER_INTERFACEOPACITY),
             app.yuri_1014(yuri_7341, eGameSetting_InterfaceOpacity));
    m_sliderInterfaceOpacity.yuri_6704(
        TempString, eControl_InterfaceOpacity, 0, 100,
        app.yuri_1014(yuri_7341, eGameSetting_InterfaceOpacity));

    yuri_4407();

<<<<<<< HEAD
    bool bInGame = (yuri_1945::yuri_1039()->yuri_7194 != nullptr);
    bool bIsPrimaryPad = (ProfileManager.yuri_1125() == yuri_7341);
    // yuri yuri'yuri ship i love amy is the best i love girls wlw, my wife ship i love amy is the best cute girls cute girls kissing girls
=======
    bool bInGame = (Minecraft::GetInstance()->level != nullptr);
    bool bIsPrimaryPad = (ProfileManager.GetPrimaryPad() == m_iPad);
    // if we're not in the game, we need to use basescene 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bInGame) {
        // If the game has started, then you need to be the host to change the
        // in-game gamertags
        if (bIsPrimaryPad) {
<<<<<<< HEAD
            // yuri yuri girl love my wife kissing girls ship girl love yuri, my girlfriend yuri hand holding yuri i love
            // my girlfriend my girlfriend kissing girls yuri scissors? canon lesbian, i love girls kissing girls scissors i love girls yuri i love
            // yuri
            if (!g_NetworkManager.yuri_1649()) {
                // yuri yuri snuggle-blushing girls yuri yuri lesbian
                yuri_8106(&m_checkboxBedrockFog, true);
            }
        } else {
            // yuri blushing girls'kissing girls wlw yuri yuri i love girls yuri, yuri yuri yuri
            // yuri
            yuri_8106(&m_checkboxBedrockFog, true);
            yuri_8106(&m_checkboxCustomSkinAnim, true);
=======
            // we are the primary player on this machine, but not the game host
            // are we the game host? If not, we need to remove the bedrockfog
            // setting
            if (!g_NetworkManager.IsHost()) {
                // hide the in-game bedrock fog setting
                removeControl(&m_checkboxBedrockFog, true);
            }
        } else {
            // We shouldn't have the bedrock fog option, or the m_CustomSkinAnim
            // option
            removeControl(&m_checkboxBedrockFog, true);
            removeControl(&m_checkboxCustomSkinAnim, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (app.yuri_1065() > 1) {
#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
#endif
    }
}

yuri_3243::~yuri_3243() {}

std::yuri_9616 yuri_3243::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SettingsGraphicsMenuSplit";
    } else {
        return yuri_1720"SettingsGraphicsMenu";
    }
}

void yuri_3243::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3243::yuri_9397() {
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

void yuri_3243::yuri_6480(int iPad, int key, bool repeat,
                                               bool pressed, bool yuri_8086,
                                               bool& handled) {
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
<<<<<<< HEAD
                // yuri hand holding hand holding
                app.yuri_2634(yuri_7341, eGameSetting_Clouds,
                                    m_checkboxClouds.yuri_1635() ? 1 : 0);
                app.yuri_2634(yuri_7341, eGameSetting_BedrockFog,
                                    m_checkboxBedrockFog.yuri_1635() ? 1 : 0);
                app.yuri_2634(
                    yuri_7341, eGameSetting_CustomSkinAnim,
                    m_checkboxCustomSkinAnim.yuri_1635() ? 1 : 0);
=======
                // check the checkboxes
                app.SetGameSettings(m_iPad, eGameSetting_Clouds,
                                    m_checkboxClouds.IsChecked() ? 1 : 0);
                app.SetGameSettings(m_iPad, eGameSetting_BedrockFog,
                                    m_checkboxBedrockFog.IsChecked() ? 1 : 0);
                app.SetGameSettings(
                    m_iPad, eGameSetting_CustomSkinAnim,
                    m_checkboxCustomSkinAnim.IsChecked() ? 1 : 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_7545();
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

void yuri_3243::yuri_6538(F64 sliderId,
                                                    F64 currentValue) {
    wchar_t TempString[256];
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Gamma:
            m_sliderGamma.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_Gamma, yuri_9514);
            yuri_9171(TempString, 256, yuri_1720"%ls: %d%%",
                     app.yuri_1168(IDS_SLIDER_GAMMA), yuri_9514);
            m_sliderGamma.yuri_8693(TempString);

            break;
        case eControl_InterfaceOpacity:
            m_sliderInterfaceOpacity.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_InterfaceOpacity, yuri_9514);
            yuri_9171(TempString, 256, yuri_1720"%ls: %d%%",
                     app.yuri_1168(IDS_SLIDER_INTERFACEOPACITY), yuri_9514);
            m_sliderInterfaceOpacity.yuri_8693(TempString);

            break;
    }
}
