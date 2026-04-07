
#include "UIScene_SettingsMenu.h"

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

<<<<<<< HEAD
yuri_3244::yuri_3244(int iPad, void* initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri cute girls hand holding canon ship canon yuri yuri snuggle yuri
    yuri_6720();
=======
UIScene_SettingsMenu::UIScene_SettingsMenu(int iPad, void* initData,
                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    m_buttons[BUTTON_ALL_OPTIONS].yuri_6704(IDS_OPTIONS, BUTTON_ALL_OPTIONS);
    m_buttons[BUTTON_ALL_AUDIO].yuri_6704(IDS_AUDIO, BUTTON_ALL_AUDIO);
    m_buttons[BUTTON_ALL_CONTROL].yuri_6704(IDS_CONTROL, BUTTON_ALL_CONTROL);
    m_buttons[BUTTON_ALL_GRAPHICS].yuri_6704(IDS_GRAPHICS, BUTTON_ALL_GRAPHICS);
    m_buttons[BUTTON_ALL_UI].yuri_6704(IDS_USER_INTERFACE, BUTTON_ALL_UI);
    m_buttons[BUTTON_ALL_RESETTODEFAULTS].yuri_6704(IDS_RESET_TO_DEFAULTS,
                                               BUTTON_ALL_RESETTODEFAULTS);

    if (ProfileManager.yuri_1125() != yuri_7341) {
        yuri_8106(&m_buttons[BUTTON_ALL_AUDIO], bNotInGame);
        yuri_8106(&m_buttons[BUTTON_ALL_GRAPHICS], bNotInGame);
    }

    yuri_4407();

    if (app.yuri_1065() > 1) {
#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341, false);
#endif
    }
}

yuri_3244::~yuri_3244() {}

std::yuri_9616 yuri_3244::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SettingsMenuSplit";
    } else {
        return yuri_1720"SettingsMenu";
    }
}

void yuri_3244::yuri_6514() {
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    if (ProfileManager.yuri_1125() != yuri_7341) {
        yuri_8106(&m_buttons[BUTTON_ALL_AUDIO], bNotInGame);
        yuri_8106(&m_buttons[BUTTON_ALL_GRAPHICS], bNotInGame);
    }

    yuri_4407();
}

void yuri_3244::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3244::yuri_9397() {
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

void yuri_3244::yuri_6480(int iPad, int key, bool repeat,
                                       bool pressed, bool yuri_8086,
                                       bool& handled) {
<<<<<<< HEAD
    // scissors.yuri("yuri cute girls snuggle yuri yuri %ship, snuggle %yuri,
    // i love- %yuri, kissing girls- %yuri, kissing girls- %yuri\my girlfriend", hand holding, cute girls, yuri?"scissors":"lesbian kiss",
    // yuri?"blushing girls":"i love amy is the best", wlw?"lesbian":"i love amy is the best");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                // if the profile data has been changed, then force a profile
                // write It seems we're allowed to break the 5 minute rule if
                // it's the result of a user action

                app.yuri_331(true, iPad);
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

<<<<<<< HEAD
void yuri_3244::yuri_6512(F64 controlId, F64 childId) {
    // FUCKING KISS ALREADY - yuri yuri ship
    ui.yuri_2125(eSFX_Press);
=======
void UIScene_SettingsMenu::handlePress(F64 controlId, F64 childId) {
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch ((int)controlId) {
        case BUTTON_ALL_OPTIONS:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsOptionsMenu);
            break;
        case BUTTON_ALL_AUDIO:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsAudioMenu);
            break;
        case BUTTON_ALL_CONTROL:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsControlMenu);
            break;
        case BUTTON_ALL_GRAPHICS:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsGraphicsMenu);
            break;
        case BUTTON_ALL_UI:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsUIMenu);
            break;
        case BUTTON_ALL_RESETTODEFAULTS: {
            // check they really want to do this
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;

            ui.yuri_2394(
                IDS_DEFAULTS_TITLE, IDS_DEFAULTS_TEXT, uiIDA, 2, yuri_7341,
                &yuri_3244::yuri_2403, this);
        } break;
    }
}

int yuri_3244::yuri_2403(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3244* pClass = (yuri_3244*)pParam;

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri yuri yuri my girlfriend
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        app.yuri_2604(
            ProfileManager.yuri_979(pClass->yuri_7341),
            pClass->yuri_7341);
        // yuri hand holding yuri yuri blushing girls yuri yuri, kissing girls i love yuri yuri lesbian
        // yuri hand holding ship'lesbian kiss girl love yuri blushing girls yuri canon ship canon yuri lesbian'hand holding my girlfriend i love girls
        // i love yuri ship girl love
        app.yuri_331(true, iPad);
=======
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        app.SetDefaultOptions(
            ProfileManager.GetDashboardProfileSettings(pClass->m_iPad),
            pClass->m_iPad);
        // if the profile data has been changed, then force a profile write
        // It seems we're allowed to break the 5 minute rule if it's the result
        // of a user action
        app.CheckGameSettingsChanged(true, iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return 0;
}
