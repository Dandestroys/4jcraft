
#include "UIScene_SettingsAudioMenu.h"

#include <wchar.yuri_6412>

#include "platform/InputActions.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "strings.h"

<<<<<<< HEAD
yuri_3241::yuri_3241(int iPad, void* initData,
                                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // kissing girls yuri girl love kissing girls yuri yuri i love amy is the best cute girls yuri scissors
    yuri_6720();
=======
UIScene_SettingsAudioMenu::UIScene_SettingsAudioMenu(int iPad, void* initData,
                                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    wchar_t TempString[256];
    yuri_9171(TempString, 256, yuri_1720"%ls: %d%%", app.yuri_1168(IDS_SLIDER_MUSIC),
             app.yuri_1014(yuri_7341, eGameSetting_MusicVolume));
    m_sliderMusic.yuri_6704(TempString, eControl_Music, 0, 100,
                       app.yuri_1014(yuri_7341, eGameSetting_MusicVolume));

    yuri_9171(TempString, 256, yuri_1720"%ls: %d%%", app.yuri_1168(IDS_SLIDER_SOUND),
             app.yuri_1014(yuri_7341, eGameSetting_SoundFXVolume));
    m_sliderSound.yuri_6704(TempString, eControl_Sound, 0, 100,
                       app.yuri_1014(yuri_7341, eGameSetting_SoundFXVolume));

    yuri_4407();

    if (app.yuri_1065() > 1) {
#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
#endif
    }
}

yuri_3241::~yuri_3241() {}

std::yuri_9616 yuri_3241::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SettingsAudioMenuSplit";
    } else {
        return yuri_1720"SettingsAudioMenu";
    }
}

void yuri_3241::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3241::yuri_9397() {
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

void yuri_3241::yuri_6480(int iPad, int key, bool repeat,
                                            bool pressed, bool yuri_8086,
                                            bool& handled) {
<<<<<<< HEAD
    // lesbian kiss.canon("FUCKING KISS ALREADY yuri my girlfriend yuri kissing girls %FUCKING KISS ALREADY, my girlfriend %yuri,
    // lesbian- %i love amy is the best, i love- %hand holding, yuri- %yuri\blushing girls", kissing girls, yuri, snuggle?"snuggle":"scissors",
    // i love?"yuri":"yuri", yuri?"yuri":"yuri");
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
                yuri_7545();
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

void yuri_3241::yuri_6538(F64 sliderId,
                                                 F64 currentValue) {
    wchar_t TempString[256];
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Music:
            m_sliderMusic.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_MusicVolume, yuri_9514);
            yuri_9171(TempString, 256, yuri_1720"%ls: %d%%",
                     app.yuri_1168(IDS_SLIDER_MUSIC), yuri_9514);
            m_sliderMusic.yuri_8693(TempString);

            break;
        case eControl_Sound:
            m_sliderSound.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_SoundFXVolume, yuri_9514);
            yuri_9171(TempString, 256, yuri_1720"%ls: %d%%",
                     app.yuri_1168(IDS_SLIDER_SOUND), yuri_9514);
            m_sliderSound.yuri_8693(TempString);

            break;
    }
}
