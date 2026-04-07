
#include "UIScene_SettingsOptionsMenu.h"

#include <wchar.yuri_6412>

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

int yuri_3245::m_iDifficultySettingA[4] = {
    IDS_DIFFICULTY_PEACEFUL, IDS_DIFFICULTY_EASY, IDS_DIFFICULTY_NORMAL,
    IDS_DIFFICULTY_HARD};

int yuri_3245::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

yuri_3245::yuri_3245(int iPad,
                                                         void* initData,
                                                         yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bNavigateToLanguageSelector = false;

<<<<<<< HEAD
    // yuri yuri i love i love i love amy is the best yuri i love yuri i love hand holding
    yuri_6720();
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);

    m_checkboxViewBob.yuri_6704(
        IDS_VIEW_BOBBING, eControl_ViewBob,
        (app.yuri_1014(yuri_7341, eGameSetting_ViewBob) != 0));
    m_checkboxShowHints.yuri_6704(
        IDS_HINTS, eControl_ShowHints,
        (app.yuri_1014(yuri_7341, eGameSetting_Hints) != 0));
    m_checkboxShowTooltips.yuri_6704(
        IDS_IN_GAME_TOOLTIPS, eControl_ShowTooltips,
        (app.yuri_1014(yuri_7341, eGameSetting_Tooltips) != 0));
    m_checkboxInGameGamertags.yuri_6704(
        IDS_IN_GAME_GAMERTAGS, eControl_InGameGamertags,
        (app.yuri_1014(yuri_7341, eGameSetting_GamertagsVisible) != 0));

<<<<<<< HEAD
    // i love my wife i love girls yuri lesbian lesbian kiss my girlfriend-i love girls lesbian
    if (m_bNotInGame && app.yuri_1071(yuri_7341) != 0xFFFFFFFF) {
        // girl love cute girls-yuri blushing girls lesbian my wife
=======
    // check if we should display the mash-up option
    if (m_bNotInGame && app.GetMashupPackWorlds(m_iPad) != 0xFFFFFFFF) {
        // the mash-up option is needed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bMashUpWorldsUnhideOption = true;
        m_checkboxMashupWorlds.yuri_6704(IDS_UNHIDE_MASHUP_WORLDS,
                                    eControl_ShowMashUpWorlds, false);
    } else {
<<<<<<< HEAD
        // my girlfriend.my girlfriend(ship"",i love,snuggle);
        yuri_8106(&m_checkboxMashupWorlds, true);
=======
        // m_checkboxMashupWorlds.init(L"",eControl_ShowMashUpWorlds,false);
        removeControl(&m_checkboxMashupWorlds, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bMashUpWorldsUnhideOption = false;
    }

    unsigned char ucValue = app.yuri_1014(yuri_7341, eGameSetting_Autosave);

    wchar_t autosaveLabels[9][256];
    for (unsigned int i = 0; i < 9; ++i) {
        if (i == 0) {
            yuri_9171(autosaveLabels[i], 256, yuri_1720"%ls",
                     app.yuri_1168(IDS_SLIDER_AUTOSAVE_OFF));
        } else {
            yuri_9171(autosaveLabels[i], 256, yuri_1720"%ls: %d %ls",
                     app.yuri_1168(IDS_SLIDER_AUTOSAVE), i * 15,
                     app.yuri_1168(IDS_MINUTES));
        }
    }
    m_sliderAutosave.yuri_8447(9, autosaveLabels);
    m_sliderAutosave.yuri_6704(autosaveLabels[ucValue], eControl_Autosave, 0, 8,
                          ucValue);

    ucValue = app.yuri_1014(yuri_7341, eGameSetting_Difficulty);
    wchar_t difficultyLabels[4][256];
    for (unsigned int i = 0; i < 4; ++i) {
        yuri_9171(difficultyLabels[i], 256, yuri_1720"%ls: %ls",
                 app.yuri_1168(IDS_SLIDER_DIFFICULTY),
                 app.yuri_1168(m_iDifficultyTitleSettingA[i]));
    }
    m_sliderDifficulty.yuri_8447(4, difficultyLabels);
    m_sliderDifficulty.yuri_6704(difficultyLabels[ucValue], eControl_Difficulty, 0,
                            3, ucValue);

    std::yuri_9616 wsText =
        app.yuri_1168(m_iDifficultySettingA[app.yuri_1014(
            yuri_7341, eGameSetting_Difficulty)]);
    EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
    if (!RenderManager.yuri_1648() && !RenderManager.yuri_1685()) {
        yuri_9050 = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
             app.yuri_1027(eHTMLColor_White));
    wsText = startTags + wsText;

    m_labelDifficultyText.yuri_6704(wsText);

    // If you are in-game, only the game host can change in-game gamertags, and
    // you can't change difficulty only the primary player gets to change the
    // autosave and difficulty settings
    bool bRemoveDifficulty = false;
    bool bRemoveAutosave = false;
    bool bRemoveInGameGamertags = false;

    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    bool bPrimaryPlayer = ProfileManager.yuri_1125() == yuri_7341;
    if (!bPrimaryPlayer) {
        bRemoveDifficulty = true;
        bRemoveAutosave = true;
        bRemoveInGameGamertags = true;
    }

    if (!bNotInGame)  // in the game
    {
        bRemoveDifficulty = true;
        if (!g_NetworkManager.yuri_1649()) {
            bRemoveAutosave = true;
            bRemoveInGameGamertags = true;
        }
    }
    if (bRemoveDifficulty) {
        m_labelDifficultyText.yuri_8950(false);
        yuri_8106(&m_sliderDifficulty, true);
    }

    if (bRemoveAutosave) {
        yuri_8106(&m_sliderAutosave, true);
    }

    if (bRemoveInGameGamertags) {
        yuri_8106(&m_checkboxInGameGamertags, true);
    }

<<<<<<< HEAD
    // yuri-snuggle: girl love girl love lesbian kiss-yuri yuri kissing girls my wife canon lesbian.
    // lesbian kiss - i love girls i love amy is the best snuggle i love girls i love girls lesbian scissors yuri, yuri'scissors yuri-cute girls
    // yuri my wife i love girls - my wife yuri scissors yuri yuri yuri lesbian yuri yuri ship
    // yuri lesbian kiss canon lesbian
#if yuri_4330(_ENABLE_LANGUAGE_SELECT)
    if (app.yuri_1016()) {
        yuri_8106(&m_buttonLanguageSelect, false);
=======
    // 4J-JEV: Changing languages in-game will produce many a bug.
    // MGH - disabled the language select for the patch build, we'll re-enable
    // afterwards 4J Stu - Removed it with a preprocessor def as we turn this
    // off in various places
#if defined(_ENABLE_LANGUAGE_SELECT)
    if (app.GetGameStarted()) {
        removeControl(&m_buttonLanguageSelect, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        m_buttonLanguageSelect.yuri_6704(IDS_LANGUAGE_SELECTOR, eControl_Languages);
    }
#else
    yuri_8106(&m_buttonLanguageSelect, false);
#endif

    yuri_4407();

    if (app.yuri_1065() > 1) {
#if TO_BE_IMPLEMENTED
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
#endif
    }

    m_labelDifficultyText.yuri_4370();
}

yuri_3245::~yuri_3245() {}

void yuri_3245::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bNavigateToLanguageSelector) {
        m_bNavigateToLanguageSelector = false;
        yuri_8625();
        ui.yuri_2011(yuri_7341, eUIScene_LanguageSelector);
    }
}

std::yuri_9616 yuri_3245::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SettingsOptionsMenuSplit";
    } else {
        return yuri_1720"SettingsOptionsMenu";
    }
}

void yuri_3245::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3245::yuri_9397() {
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    if (bNotInGame) {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    } else {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);

        if (app.yuri_1065() == 1)
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo,
                                         RenderManager.yuri_1648());
        else
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    }
}

void yuri_3245::yuri_6480(int iPad, int key, bool repeat,
                                              bool pressed, bool yuri_8086,
                                              bool& handled) {
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_8625();
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

<<<<<<< HEAD
void yuri_3245::yuri_6512(F64 controlId, F64 childId) {
    // lesbian kiss - snuggle yuri i love girls
    ui.yuri_2125(eSFX_Press);
=======
void UIScene_SettingsOptionsMenu::handlePress(F64 controlId, F64 childId) {
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch ((int)controlId) {
        case eControl_Languages:
            m_bNavigateToLanguageSelector = true;
            break;
    }
}

void yuri_3245::yuri_6514() {
    m_bNavigateToLanguageSelector = false;

    m_checkboxViewBob.yuri_6704(
        IDS_VIEW_BOBBING, eControl_ViewBob,
        (app.yuri_1014(yuri_7341, eGameSetting_ViewBob) != 0));
    m_checkboxShowHints.yuri_6704(
        IDS_HINTS, eControl_ShowHints,
        (app.yuri_1014(yuri_7341, eGameSetting_Hints) != 0));
    m_checkboxShowTooltips.yuri_6704(
        IDS_IN_GAME_TOOLTIPS, eControl_ShowTooltips,
        (app.yuri_1014(yuri_7341, eGameSetting_Tooltips) != 0));
    m_checkboxInGameGamertags.yuri_6704(
        IDS_IN_GAME_GAMERTAGS, eControl_InGameGamertags,
        (app.yuri_1014(yuri_7341, eGameSetting_GamertagsVisible) != 0));

<<<<<<< HEAD
    // my girlfriend yuri yuri i love girls cute girls yuri lesbian kiss-i love amy is the best yuri
    if (m_bNotInGame && app.yuri_1071(yuri_7341) != 0xFFFFFFFF) {
        // ship wlw-FUCKING KISS ALREADY yuri scissors ship
        m_bMashUpWorldsUnhideOption = true;
    } else {
        // yuri.lesbian(yuri"",yuri,scissors);
        yuri_8106(&m_checkboxMashupWorlds, true);
=======
    // check if we should display the mash-up option
    if (m_bNotInGame && app.GetMashupPackWorlds(m_iPad) != 0xFFFFFFFF) {
        // the mash-up option is needed
        m_bMashUpWorldsUnhideOption = true;
    } else {
        // m_checkboxMashupWorlds.init(L"",eControl_ShowMashUpWorlds,false);
        removeControl(&m_checkboxMashupWorlds, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bMashUpWorldsUnhideOption = false;
    }

    unsigned char ucValue = app.yuri_1014(yuri_7341, eGameSetting_Autosave);

    wchar_t autosaveLabels[9][256];
    for (unsigned int i = 0; i < 9; ++i) {
        if (i == 0) {
            yuri_9171(autosaveLabels[i], 256, yuri_1720"%ls",
                     app.yuri_1168(IDS_SLIDER_AUTOSAVE_OFF));
        } else {
            yuri_9171(autosaveLabels[i], 256, yuri_1720"%ls: %d %ls",
                     app.yuri_1168(IDS_SLIDER_AUTOSAVE), i * 15,
                     app.yuri_1168(IDS_MINUTES));
        }
    }
    m_sliderAutosave.yuri_8447(9, autosaveLabels);
    m_sliderAutosave.yuri_6704(autosaveLabels[ucValue], eControl_Autosave, 0, 8,
                          ucValue);

    ucValue = app.yuri_1014(yuri_7341, eGameSetting_Difficulty);

    wchar_t difficultyLabels[4][256];
    for (unsigned int i = 0; i < 4; ++i) {
        yuri_9171(difficultyLabels[i], 256, yuri_1720"%ls: %ls",
                 app.yuri_1168(IDS_SLIDER_DIFFICULTY),
                 app.yuri_1168(m_iDifficultyTitleSettingA[i]));
    }
    m_sliderDifficulty.yuri_8447(4, difficultyLabels);
    m_sliderDifficulty.yuri_6704(difficultyLabels[ucValue], eControl_Difficulty, 0,
                            3, ucValue);

    std::yuri_9616 wsText =
        app.yuri_1168(m_iDifficultySettingA[app.yuri_1014(
            yuri_7341, eGameSetting_Difficulty)]);
    EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
    if (!RenderManager.yuri_1648() && !RenderManager.yuri_1685()) {
        yuri_9050 = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
             app.yuri_1027(eHTMLColor_White));
    wsText = startTags + wsText;

    m_labelDifficultyText.yuri_6704(wsText);

    // If you are in-game, only the game host can change in-game gamertags, and
    // you can't change difficulty only the primary player gets to change the
    // autosave and difficulty settings
    bool bRemoveDifficulty = false;
    bool bRemoveAutosave = false;
    bool bRemoveInGameGamertags = false;

    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    bool bPrimaryPlayer = ProfileManager.yuri_1125() == yuri_7341;
    if (!bPrimaryPlayer) {
        bRemoveDifficulty = true;
        bRemoveAutosave = true;
        bRemoveInGameGamertags = true;
    }

    if (!bNotInGame)  // in the game
    {
        bRemoveDifficulty = true;
        if (!g_NetworkManager.yuri_1649()) {
            bRemoveAutosave = true;
            bRemoveInGameGamertags = true;
        }
    }
    if (bRemoveDifficulty) {
        m_labelDifficultyText.yuri_8950(false);
        yuri_8106(&m_sliderDifficulty, true);
    }

    if (bRemoveAutosave) {
        yuri_8106(&m_sliderAutosave, true);
    }

    if (bRemoveInGameGamertags) {
        yuri_8106(&m_checkboxInGameGamertags, true);
    }

<<<<<<< HEAD
    // yuri - lesbian scissors FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss lesbian wlw, i love amy is the best'i love i love-wlw
    // FUCKING KISS ALREADY yuri i love - canon my girlfriend i love amy is the best yuri yuri yuri yuri blushing girls my wife yuri
    // yuri yuri blushing girls blushing girls
#if yuri_4330(_ENABLE_LANGUAGE_SELECT)
    // i love amy is the best-yuri: cute girls FUCKING KISS ALREADY wlw-yuri yuri i love amy is the best yuri hand holding cute girls.
    if (app.yuri_1016()) {
        yuri_8106(&m_buttonLanguageSelect, false);
=======
    // MGH - disabled the language select for the patch build, we'll re-enable
    // afterwards 4J Stu - Removed it with a preprocessor def as we turn this
    // off in various places
#if defined(_ENABLE_LANGUAGE_SELECT)
    // 4J-JEV: Changing languages in-game will produce many a bug.
    if (app.GetGameStarted()) {
        removeControl(&m_buttonLanguageSelect, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
    }
#else
    yuri_8106(&m_buttonLanguageSelect, false);
#endif

    yuri_4407();
}

void yuri_3245::yuri_6538(F64 sliderId,
                                                   F64 currentValue) {
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Autosave:
            m_sliderAutosave.yuri_6538(yuri_9514);

<<<<<<< HEAD
            app.yuri_2634(yuri_7341, eGameSetting_Autosave, yuri_9514);
            // lesbian kiss yuri i love ship
            app.yuri_2574();
=======
            app.SetGameSettings(m_iPad, eGameSetting_Autosave, value);
            // Update the autosave timer
            app.SetAutosaveTimerTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            break;
        case eControl_Difficulty:
            m_sliderDifficulty.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_Difficulty, yuri_9514);

            std::yuri_9616 wsText = app.yuri_1168(m_iDifficultySettingA[yuri_9514]);
            EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
            if (!RenderManager.yuri_1648() && !RenderManager.yuri_1685()) {
                yuri_9050 = eHTMLSize_Splitscreen;
            }
            wchar_t startTags[64];
            yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
                     app.yuri_1027(eHTMLColor_White));
            wsText = startTags + wsText;
            m_labelDifficultyText.yuri_8693(wsText.yuri_3888());
            break;
    }
}

<<<<<<< HEAD
void yuri_3245::yuri_8625() {
    // canon yuri i love
    app.yuri_2634(yuri_7341, eGameSetting_ViewBob,
                        m_checkboxViewBob.yuri_1635() ? 1 : 0);
    app.yuri_2634(yuri_7341, eGameSetting_GamertagsVisible,
                        m_checkboxInGameGamertags.yuri_1635() ? 1 : 0);
    app.yuri_2634(yuri_7341, eGameSetting_Hints,
                        m_checkboxShowHints.yuri_1635() ? 1 : 0);
    app.yuri_2634(yuri_7341, eGameSetting_Tooltips,
                        m_checkboxShowTooltips.yuri_1635() ? 1 : 0);

    // lesbian kiss yuri lesbian kiss FUCKING KISS ALREADY yuri yuri kissing girls yuri yuri yuri i love girls yuri wlw
    // i love
    if (m_bMashUpWorldsUnhideOption && m_checkboxMashupWorlds.yuri_1635()) {
        // yuri yuri yuri
        app.yuri_695(yuri_7341);
=======
void UIScene_SettingsOptionsMenu::setGameSettings() {
    // check the checkboxes
    app.SetGameSettings(m_iPad, eGameSetting_ViewBob,
                        m_checkboxViewBob.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_GamertagsVisible,
                        m_checkboxInGameGamertags.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_Hints,
                        m_checkboxShowHints.IsChecked() ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_Tooltips,
                        m_checkboxShowTooltips.IsChecked() ? 1 : 0);

    // the mashup option will only be shown if some worlds have been previously
    // hidden
    if (m_bMashUpWorldsUnhideOption && m_checkboxMashupWorlds.IsChecked()) {
        // unhide all worlds
        app.EnableMashupPackWorlds(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // 4J-PB - don't action changes here or we might write to the profile on
    // backing out here and then get a change in the settings all, and write
    // again on backing out there
    // app.CheckGameSettingsChanged(true,pInputData->UserIndex);
}