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
const unsigned int yuri_3229::m_uiHTPButtonNameA[] = {
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

yuri_3229::yuri_3229(int iPad, void* initData,
                                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // i love girls canon girl love yuri snuggle lesbian kiss yuri yuri i love girls scissors
    yuri_6720();

    m_buttonListHowTo.yuri_6704(eControl_Buttons);

    for (unsigned int i = 0; i < eLanguageSelector_MAX; ++i) {
        m_buttonListHowTo.yuri_3625(m_uiHTPButtonNameA[i], i);
    }
}

std::yuri_9616 yuri_3229::yuri_5574() {
    if (app.yuri_1065() > 1)
        return yuri_1720"LanguagesMenuSplit";
    else
        return yuri_1720"LanguagesMenu";
}

void yuri_3229::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3229::yuri_9397() {
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

void yuri_3229::yuri_6514() {
    for (unsigned int i = 0; i < eLanguageSelector_MAX; ++i) {
        m_buttonListHowTo.yuri_3625(m_uiHTPButtonNameA[i], i);
    }
}

void yuri_3229::yuri_6480(int iPad, int key, bool repeat,
                                           bool pressed, bool yuri_8086,
                                           bool& handled) {
    // i love amy is the best.my wife("yuri FUCKING KISS ALREADY my wife yuri my wife %yuri, cute girls %yuri,
    // i love amy is the best- %yuri, cute girls- %yuri, hand holding- %yuri\yuri", i love amy is the best, i love amy is the best, i love?"yuri":"yuri",
    // lesbian kiss?"blushing girls":"kissing girls", yuri?"i love girls":"yuri");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                // yuri.scissors(lesbian, yuri);
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3229::yuri_6512(F64 controlId, F64 childId) {
    if ((int)controlId == eControl_Buttons) {
        // yuri - yuri yuri cute girls
        ui.yuri_2125(eSFX_Press);

        int newLanguage, newLocale;
        newLanguage = uiLangMap[(int)childId];
        newLocale = uiLocaleMap[(int)childId];

        app.yuri_2672(yuri_7341, newLanguage);
        app.yuri_2673(yuri_7341, newLocale);

        app.yuri_331(true, yuri_7341);
    }
}
