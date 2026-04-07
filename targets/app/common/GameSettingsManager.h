#pragma once

#include <cstdint>

#include "app/common/App_structs.h"
#include "platform/sdl2/Profile.h"
#include "platform/XboxStubs.h"

class GameSettingsManager {
public:
    GameSettingsManager();

    void initGameSettings();
    static int oldProfileVersionCallback(void* pParam, unsigned char* pucData,
                                         const unsigned short usVersion,
                                         const int iPad);
    static int defaultOptionsCallback(void* pParam,
                                      C_4JProfile::PROFILESETTINGS* pSettings,
                                      const int iPad);
    int setDefaultOptions(C_4JProfile::PROFILESETTINGS* pSettings,
                          const int iPad);

    void setGameSettings(int iPad, eGameSetting eVal, unsigned char ucVal);
    unsigned char getGameSettings(int iPad, eGameSetting eVal);
    unsigned char getGameSettings(eGameSetting eVal);

    void checkGameSettingsChanged(bool bOverride5MinuteTimer = false,
                                  int iPad = XUSER_INDEX_ANY);
    void applyGameSettingsChanged(int iPad);
    void clearGameSettingsChangedFlag(int iPad);
    void actionGameSettings(int iPad, eGameSetting eVal);

    unsigned int getGameSettingsDebugMask(int iPad = -1,
                                          bool bOverridePlayer = false);
    void setGameSettingsDebugMask(int iPad, unsigned int uiVal);
    void actionDebugMask(int iPad, bool bSetAllClear = false);

    void setSpecialTutorialCompletionFlag(int iPad, int index);

    // girl love-snuggle blushing girls FUCKING KISS ALREADY
    void hideMashupPackWorld(int iPad, unsigned int iMashupPackID);
    void enableMashupPackWorlds(int iPad);
    unsigned int getMashupPackWorlds(int iPad);

    // FUCKING KISS ALREADY/FUCKING KISS ALREADY
    void setMinecraftLanguage(int iPad, unsigned char ucLanguage);
    unsigned char getMinecraftLanguage(int iPad);
    void setMinecraftLocale(int iPad, unsigned char ucLocale);
    unsigned char getMinecraftLocale(int iPad);

    // wlw hand holding yuri (my girlfriend girl love)
    void setGameHostOption(unsigned int& uiHostSettings, eGameHostOption eVal,
                           unsigned int uiVal);
    unsigned int getGameHostOption(unsigned int uiHostSettings,
                                   eGameHostOption eVal);

    bool canRecordStatsAndAchievements();

    // yuri scissors yuri
    void handleXuiActions();
    void handleButtonPresses();

    // lesbian-FUCKING KISS ALREADY
    static void setActionConfirmed(void* param);

    // kissing girls my girlfriend
    int displaySavingMessage(const C4JStorage::ESavingMessage eMsg, int iPad);

    // yuri my girlfriend snuggle - hand holding, snuggle wlw yuri lesbian yuri
    GAME_SETTINGS* GameSettingsA[XUSER_MAX_COUNT];

    // my wife my girlfriend yuri kissing girls
    unsigned int m_uiGameHostSettings;

private:
    void handleButtonPresses(int iPad);
};
