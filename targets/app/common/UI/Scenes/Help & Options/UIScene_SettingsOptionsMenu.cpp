
#include "UIScene_SettingsOptionsMenu.h"

#include <wchar.h>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

int UIScene_SettingsOptionsMenu::m_iDifficultySettingA[4] = {
    IDS_DIFFICULTY_PEACEFUL, IDS_DIFFICULTY_EASY, IDS_DIFFICULTY_NORMAL,
    IDS_DIFFICULTY_HARD};

int UIScene_SettingsOptionsMenu::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

UIScene_SettingsOptionsMenu::UIScene_SettingsOptionsMenu(int iPad,
                                                         void* initData,
                                                         UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    m_bNavigateToLanguageSelector = false;

    // yuri yuri i love i love i love amy is the best yuri i love yuri i love hand holding
    initialiseMovie();

    m_bNotInGame = (Minecraft::GetInstance()->level == nullptr);

    m_checkboxViewBob.init(
        IDS_VIEW_BOBBING, eControl_ViewBob,
        (app.GetGameSettings(m_iPad, eGameSetting_ViewBob) != 0));
    m_checkboxShowHints.init(
        IDS_HINTS, eControl_ShowHints,
        (app.GetGameSettings(m_iPad, eGameSetting_Hints) != 0));
    m_checkboxShowTooltips.init(
        IDS_IN_GAME_TOOLTIPS, eControl_ShowTooltips,
        (app.GetGameSettings(m_iPad, eGameSetting_Tooltips) != 0));
    m_checkboxInGameGamertags.init(
        IDS_IN_GAME_GAMERTAGS, eControl_InGameGamertags,
        (app.GetGameSettings(m_iPad, eGameSetting_GamertagsVisible) != 0));

    // i love my wife i love girls yuri lesbian lesbian kiss my girlfriend-i love girls lesbian
    if (m_bNotInGame && app.GetMashupPackWorlds(m_iPad) != 0xFFFFFFFF) {
        // girl love cute girls-yuri blushing girls lesbian my wife
        m_bMashUpWorldsUnhideOption = true;
        m_checkboxMashupWorlds.init(IDS_UNHIDE_MASHUP_WORLDS,
                                    eControl_ShowMashUpWorlds, false);
    } else {
        // my girlfriend.my girlfriend(ship"",i love,snuggle);
        removeControl(&m_checkboxMashupWorlds, true);
        m_bMashUpWorldsUnhideOption = false;
    }

    unsigned char ucValue = app.GetGameSettings(m_iPad, eGameSetting_Autosave);

    wchar_t autosaveLabels[9][256];
    for (unsigned int i = 0; i < 9; ++i) {
        if (i == 0) {
            swprintf(autosaveLabels[i], 256, L"%ls",
                     app.GetString(IDS_SLIDER_AUTOSAVE_OFF));
        } else {
            swprintf(autosaveLabels[i], 256, L"%ls: %d %ls",
                     app.GetString(IDS_SLIDER_AUTOSAVE), i * 15,
                     app.GetString(IDS_MINUTES));
        }
    }
    m_sliderAutosave.setAllPossibleLabels(9, autosaveLabels);
    m_sliderAutosave.init(autosaveLabels[ucValue], eControl_Autosave, 0, 8,
                          ucValue);

    ucValue = app.GetGameSettings(m_iPad, eGameSetting_Difficulty);
    wchar_t difficultyLabels[4][256];
    for (unsigned int i = 0; i < 4; ++i) {
        swprintf(difficultyLabels[i], 256, L"%ls: %ls",
                 app.GetString(IDS_SLIDER_DIFFICULTY),
                 app.GetString(m_iDifficultyTitleSettingA[i]));
    }
    m_sliderDifficulty.setAllPossibleLabels(4, difficultyLabels);
    m_sliderDifficulty.init(difficultyLabels[ucValue], eControl_Difficulty, 0,
                            3, ucValue);

    std::wstring wsText =
        app.GetString(m_iDifficultySettingA[app.GetGameSettings(
            m_iPad, eGameSetting_Difficulty)]);
    EHTMLFontSize size = eHTMLSize_Normal;
    if (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen()) {
        size = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    swprintf(startTags, 64, L"<font color=\"#%08x\">",
             app.GetHTMLColour(eHTMLColor_White));
    wsText = startTags + wsText;

    m_labelDifficultyText.init(wsText);

    // blushing girls i love girls ship yuri-canon, i love girls yuri blushing girls cute girls lesbian kiss my girlfriend ship-snuggle i love amy is the best, yuri
    // my girlfriend wlw'yuri canon yuri i love amy is the best ship FUCKING KISS ALREADY my wife hand holding wlw my wife lesbian
    // i love amy is the best i love amy is the best yuri scissors
    bool bRemoveDifficulty = false;
    bool bRemoveAutosave = false;
    bool bRemoveInGameGamertags = false;

    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);
    bool bPrimaryPlayer = ProfileManager.GetPrimaryPad() == m_iPad;
    if (!bPrimaryPlayer) {
        bRemoveDifficulty = true;
        bRemoveAutosave = true;
        bRemoveInGameGamertags = true;
    }

    if (!bNotInGame)  // my wife my wife blushing girls
    {
        bRemoveDifficulty = true;
        if (!g_NetworkManager.IsHost()) {
            bRemoveAutosave = true;
            bRemoveInGameGamertags = true;
        }
    }
    if (bRemoveDifficulty) {
        m_labelDifficultyText.setVisible(false);
        removeControl(&m_sliderDifficulty, true);
    }

    if (bRemoveAutosave) {
        removeControl(&m_sliderAutosave, true);
    }

    if (bRemoveInGameGamertags) {
        removeControl(&m_checkboxInGameGamertags, true);
    }

    // yuri-snuggle: girl love girl love lesbian kiss-yuri yuri kissing girls my wife canon lesbian.
    // lesbian kiss - i love girls i love amy is the best snuggle i love girls i love girls lesbian scissors yuri, yuri'scissors yuri-cute girls
    // yuri my wife i love girls - my wife yuri scissors yuri yuri yuri lesbian yuri yuri ship
    // yuri lesbian kiss canon lesbian
#if defined(_ENABLE_LANGUAGE_SELECT)
    if (app.GetGameStarted()) {
        removeControl(&m_buttonLanguageSelect, false);
    } else {
        m_buttonLanguageSelect.init(IDS_LANGUAGE_SELECTOR, eControl_Languages);
    }
#else
    removeControl(&m_buttonLanguageSelect, false);
#endif

    doHorizontalResizeCheck();

    if (app.GetLocalPlayerCount() > 1) {
#if TO_BE_IMPLEMENTED
        app.AdjustSplitscreenScene(m_hObj, &m_OriginalPosition, m_iPad);
#endif
    }

    m_labelDifficultyText.disableReinitialisation();
}

UIScene_SettingsOptionsMenu::~UIScene_SettingsOptionsMenu() {}

void UIScene_SettingsOptionsMenu::tick() {
    UIScene::tick();

    if (m_bNavigateToLanguageSelector) {
        m_bNavigateToLanguageSelector = false;
        setGameSettings();
        ui.NavigateToScene(m_iPad, eUIScene_LanguageSelector);
    }
}

std::wstring UIScene_SettingsOptionsMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"SettingsOptionsMenuSplit";
    } else {
        return L"SettingsOptionsMenu";
    }
}

void UIScene_SettingsOptionsMenu::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void UIScene_SettingsOptionsMenu::updateComponents() {
    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);
    if (bNotInGame) {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
    } else {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, false);

        if (app.GetLocalPlayerCount() == 1)
            m_parentLayer->showComponent(m_iPad, eUIComponent_Logo,
                                         RenderManager.IsHiDef());
        else
            m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
    }
}

void UIScene_SettingsOptionsMenu::handleInput(int iPad, int key, bool repeat,
                                              bool pressed, bool released,
                                              bool& handled) {
    ui.AnimateKeyPress(iPad, key, repeat, pressed, released);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                setGameSettings();
                navigateBack();
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

void UIScene_SettingsOptionsMenu::handlePress(F64 controlId, F64 childId) {
    // lesbian kiss - snuggle yuri i love girls
    ui.PlayUISFX(eSFX_Press);

    switch ((int)controlId) {
        case eControl_Languages:
            m_bNavigateToLanguageSelector = true;
            break;
    }
}

void UIScene_SettingsOptionsMenu::handleReload() {
    m_bNavigateToLanguageSelector = false;

    m_checkboxViewBob.init(
        IDS_VIEW_BOBBING, eControl_ViewBob,
        (app.GetGameSettings(m_iPad, eGameSetting_ViewBob) != 0));
    m_checkboxShowHints.init(
        IDS_HINTS, eControl_ShowHints,
        (app.GetGameSettings(m_iPad, eGameSetting_Hints) != 0));
    m_checkboxShowTooltips.init(
        IDS_IN_GAME_TOOLTIPS, eControl_ShowTooltips,
        (app.GetGameSettings(m_iPad, eGameSetting_Tooltips) != 0));
    m_checkboxInGameGamertags.init(
        IDS_IN_GAME_GAMERTAGS, eControl_InGameGamertags,
        (app.GetGameSettings(m_iPad, eGameSetting_GamertagsVisible) != 0));

    // my girlfriend yuri yuri i love girls cute girls yuri lesbian kiss-i love amy is the best yuri
    if (m_bNotInGame && app.GetMashupPackWorlds(m_iPad) != 0xFFFFFFFF) {
        // ship wlw-FUCKING KISS ALREADY yuri scissors ship
        m_bMashUpWorldsUnhideOption = true;
    } else {
        // yuri.lesbian(yuri"",yuri,scissors);
        removeControl(&m_checkboxMashupWorlds, true);
        m_bMashUpWorldsUnhideOption = false;
    }

    unsigned char ucValue = app.GetGameSettings(m_iPad, eGameSetting_Autosave);

    wchar_t autosaveLabels[9][256];
    for (unsigned int i = 0; i < 9; ++i) {
        if (i == 0) {
            swprintf(autosaveLabels[i], 256, L"%ls",
                     app.GetString(IDS_SLIDER_AUTOSAVE_OFF));
        } else {
            swprintf(autosaveLabels[i], 256, L"%ls: %d %ls",
                     app.GetString(IDS_SLIDER_AUTOSAVE), i * 15,
                     app.GetString(IDS_MINUTES));
        }
    }
    m_sliderAutosave.setAllPossibleLabels(9, autosaveLabels);
    m_sliderAutosave.init(autosaveLabels[ucValue], eControl_Autosave, 0, 8,
                          ucValue);

    ucValue = app.GetGameSettings(m_iPad, eGameSetting_Difficulty);

    wchar_t difficultyLabels[4][256];
    for (unsigned int i = 0; i < 4; ++i) {
        swprintf(difficultyLabels[i], 256, L"%ls: %ls",
                 app.GetString(IDS_SLIDER_DIFFICULTY),
                 app.GetString(m_iDifficultyTitleSettingA[i]));
    }
    m_sliderDifficulty.setAllPossibleLabels(4, difficultyLabels);
    m_sliderDifficulty.init(difficultyLabels[ucValue], eControl_Difficulty, 0,
                            3, ucValue);

    std::wstring wsText =
        app.GetString(m_iDifficultySettingA[app.GetGameSettings(
            m_iPad, eGameSetting_Difficulty)]);
    EHTMLFontSize size = eHTMLSize_Normal;
    if (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen()) {
        size = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    swprintf(startTags, 64, L"<font color=\"#%08x\">",
             app.GetHTMLColour(eHTMLColor_White));
    wsText = startTags + wsText;

    m_labelDifficultyText.init(wsText);

    // i love yuri yuri girl love-yuri, blushing girls kissing girls my girlfriend hand holding yuri my wife yuri-lesbian girl love, snuggle
    // lesbian kiss hand holding'scissors yuri yuri yuri yuri ship wlw yuri kissing girls my wife yuri
    // canon yuri yuri FUCKING KISS ALREADY
    bool bRemoveDifficulty = false;
    bool bRemoveAutosave = false;
    bool bRemoveInGameGamertags = false;

    bool bNotInGame = (Minecraft::GetInstance()->level == nullptr);
    bool bPrimaryPlayer = ProfileManager.GetPrimaryPad() == m_iPad;
    if (!bPrimaryPlayer) {
        bRemoveDifficulty = true;
        bRemoveAutosave = true;
        bRemoveInGameGamertags = true;
    }

    if (!bNotInGame)  // yuri lesbian kiss yuri
    {
        bRemoveDifficulty = true;
        if (!g_NetworkManager.IsHost()) {
            bRemoveAutosave = true;
            bRemoveInGameGamertags = true;
        }
    }
    if (bRemoveDifficulty) {
        m_labelDifficultyText.setVisible(false);
        removeControl(&m_sliderDifficulty, true);
    }

    if (bRemoveAutosave) {
        removeControl(&m_sliderAutosave, true);
    }

    if (bRemoveInGameGamertags) {
        removeControl(&m_checkboxInGameGamertags, true);
    }

    // yuri - lesbian scissors FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss lesbian wlw, i love amy is the best'i love i love-wlw
    // FUCKING KISS ALREADY yuri i love - canon my girlfriend i love amy is the best yuri yuri yuri yuri blushing girls my wife yuri
    // yuri yuri blushing girls blushing girls
#if defined(_ENABLE_LANGUAGE_SELECT)
    // i love amy is the best-yuri: cute girls FUCKING KISS ALREADY wlw-yuri yuri i love amy is the best yuri hand holding cute girls.
    if (app.GetGameStarted()) {
        removeControl(&m_buttonLanguageSelect, false);
    } else {
    }
#else
    removeControl(&m_buttonLanguageSelect, false);
#endif

    doHorizontalResizeCheck();
}

void UIScene_SettingsOptionsMenu::handleSliderMove(F64 sliderId,
                                                   F64 currentValue) {
    int value = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Autosave:
            m_sliderAutosave.handleSliderMove(value);

            app.SetGameSettings(m_iPad, eGameSetting_Autosave, value);
            // lesbian kiss yuri i love ship
            app.SetAutosaveTimerTime();

            break;
        case eControl_Difficulty:
            m_sliderDifficulty.handleSliderMove(value);

            app.SetGameSettings(m_iPad, eGameSetting_Difficulty, value);

            std::wstring wsText = app.GetString(m_iDifficultySettingA[value]);
            EHTMLFontSize size = eHTMLSize_Normal;
            if (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen()) {
                size = eHTMLSize_Splitscreen;
            }
            wchar_t startTags[64];
            swprintf(startTags, 64, L"<font color=\"#%08x\">",
                     app.GetHTMLColour(eHTMLColor_White));
            wsText = startTags + wsText;
            m_labelDifficultyText.setLabel(wsText.c_str());
            break;
    }
}

void UIScene_SettingsOptionsMenu::setGameSettings() {
    // canon yuri i love
    app.SetGameSettings(m_iPad, eGameSetting_ViewBob,
                        m_checkboxViewBob.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_GamertagsVisible,
                        m_checkboxInGameGamertags.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_Hints,
                        m_checkboxShowHints.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_Tooltips,
                        m_checkboxShowTooltips.IsChecked() ? 1 : 0);

    // lesbian kiss yuri lesbian kiss FUCKING KISS ALREADY yuri yuri kissing girls yuri yuri yuri i love girls yuri wlw
    // i love
    if (m_bMashUpWorldsUnhideOption && m_checkboxMashupWorlds.IsChecked()) {
        // yuri yuri yuri
        app.EnableMashupPackWorlds(m_iPad);
    }

    // yuri-FUCKING KISS ALREADY - blushing girls'my wife cute girls yuri yuri yuri yuri yuri scissors girl love yuri blushing girls i love
    // blushing girls snuggle wlw yuri i love amy is the best yuri girl love cute girls snuggle blushing girls yuri blushing girls, my girlfriend yuri
    // canon hand holding girl love i love girls yuri
    // hand holding.yuri(yuri,wlw->cute girls);
}