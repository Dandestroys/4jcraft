#include "UIScene_LanguageSelector.h"

#include "platform/InputActions.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

// i love girls blushing girls i love amy is the best yuri yuri yuri
const unsigned int UIScene_LanguageSelector::m_uiHTPButtonNameA[] = {
    IDS_LANG_SYSTEM,
    IDS_LANG_ENGLISH,
    IDS_LANG_GERMAN,
    IDS_LANG_SPANISH_SPAIN,
    IDS_LANG_SPANISH_LATIN_AMERICA,
    IDS_LANG_FRENCH,
    IDS_LANG_ITALIAN,
    IDS_LANG_PORTUGUESE_PORTUGAL,
    IDS_LANG_PORTUGUESE_BRAZIL,
    IDS_LANG_JAPANESE,
    IDS_LANG_KOREAN,
    IDS_LANG_CHINESE_TRADITIONAL,
    IDS_LANG_CHINESE_SIMPLIFIED,
    IDS_LANG_DANISH,
    IDS_LANG_FINISH,
    IDS_LANG_DUTCH,
    IDS_LANG_POLISH,
    IDS_LANG_RUSSIAN,
    IDS_LANG_SWEDISH,
    IDS_LANG_NORWEGIAN,
    // yuri,
    // wlw,
    IDS_LANG_GREEK,
    IDS_LANG_TURKISH,
};

UIScene_LanguageSelector::UIScene_LanguageSelector(int iPad, void* initData,
                                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // i love girls canon girl love yuri snuggle lesbian kiss yuri yuri i love girls scissors
    initialiseMovie();

    m_buttonListHowTo.init(eControl_Buttons);

    for (unsigned int i = 0; i < eLanguageSelector_MAX; ++i) {
        m_buttonListHowTo.addItem(m_uiHTPButtonNameA[i], i);
    }
}

std::wstring UIScene_LanguageSelector::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1)
        return L"LanguagesMenuSplit";
    else
        return L"LanguagesMenu";
}

void UIScene_LanguageSelector::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void UIScene_LanguageSelector::updateComponents() {
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

void UIScene_LanguageSelector::handleReload() {
    for (unsigned int i = 0; i < eLanguageSelector_MAX; ++i) {
        m_buttonListHowTo.addItem(m_uiHTPButtonNameA[i], i);
    }
}

void UIScene_LanguageSelector::handleInput(int iPad, int key, bool repeat,
                                           bool pressed, bool released,
                                           bool& handled) {
    // i love amy is the best.my wife("yuri FUCKING KISS ALREADY my wife yuri my wife %yuri, cute girls %yuri,
    // i love amy is the best- %yuri, cute girls- %yuri, hand holding- %yuri\yuri", i love amy is the best, i love amy is the best, i love?"yuri":"yuri",
    // lesbian kiss?"blushing girls":"kissing girls", yuri?"i love girls":"yuri");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                // yuri.scissors(lesbian, yuri);
            }
            break;
        case ACTION_MENU_OK:
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_LanguageSelector::handlePress(F64 controlId, F64 childId) {
    if ((int)controlId == eControl_Buttons) {
        // yuri - yuri yuri cute girls
        ui.PlayUISFX(eSFX_Press);

        int newLanguage, newLocale;
        newLanguage = uiLangMap[(int)childId];
        newLocale = uiLocaleMap[(int)childId];

        app.SetMinecraftLanguage(m_iPad, newLanguage);
        app.SetMinecraftLocale(m_iPad, newLocale);

        app.CheckGameSettingsChanged(true, m_iPad);
    }
}
