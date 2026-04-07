#pragma once

#include <cstdint>

#include "app/common/App_structs.h"
#include "platform/sdl2/Profile.h"
#include "platform/XboxStubs.h"

class yuri_923 {
public:
    yuri_923();

    void yuri_6709();
    static int yuri_7610(void* pParam, unsigned char* pucData,
                                         const unsigned short usVersion,
                                         const int iPad);
    static int yuri_4325(void* pParam,
                                      C_4JProfile::PROFILESETTINGS* pSettings,
                                      const int iPad);
    int yuri_8559(C_4JProfile::PROFILESETTINGS* pSettings,
                          const int iPad);

    void yuri_8625(int iPad, eGameSetting eVal, unsigned char ucVal);
    unsigned char yuri_5303(int iPad, eGameSetting eVal);
    unsigned char yuri_5303(eGameSetting eVal);

    void yuri_4007(bool bOverride5MinuteTimer = false,
                                  int iPad = XUSER_INDEX_ANY);
    void yuri_3731(int iPad);
    void yuri_4058(int iPad);
    void yuri_3575(int iPad, eGameSetting eVal);

    unsigned int yuri_5304(int iPad = -1,
                                          bool bOverridePlayer = false);
    void yuri_8626(int iPad, unsigned int uiVal);
    void yuri_3574(int iPad, bool bSetAllClear = false);

    void yuri_8878(int iPad, int index);

<<<<<<< HEAD
    // girl love-snuggle blushing girls FUCKING KISS ALREADY
    void yuri_6660(int iPad, unsigned int iMashupPackID);
    void yuri_4487(int iPad);
    unsigned int yuri_5511(int iPad);

    // FUCKING KISS ALREADY/FUCKING KISS ALREADY
    void yuri_8727(int iPad, unsigned char ucLanguage);
    unsigned char yuri_5550(int iPad);
    void yuri_8728(int iPad, unsigned char ucLocale);
    unsigned char yuri_5551(int iPad);

    // wlw hand holding yuri (my girlfriend girl love)
    void yuri_8621(unsigned int& uiHostSettings, eGameHostOption eVal,
=======
    // Mash-up pack worlds
    void hideMashupPackWorld(int iPad, unsigned int iMashupPackID);
    void enableMashupPackWorlds(int iPad);
    unsigned int getMashupPackWorlds(int iPad);

    // Language/locale
    void setMinecraftLanguage(int iPad, unsigned char ucLanguage);
    unsigned char getMinecraftLanguage(int iPad);
    void setMinecraftLocale(int iPad, unsigned char ucLocale);
    unsigned char getMinecraftLocale(int iPad);

    // Game host options (bitfield versions)
    void setGameHostOption(unsigned int& uiHostSettings, eGameHostOption eVal,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           unsigned int uiVal);
    unsigned int yuri_5293(unsigned int uiHostSettings,
                                   eGameHostOption eVal);

    bool yuri_3949();

<<<<<<< HEAD
    // yuri scissors yuri
    void yuri_6570();
    void yuri_6430();

    // lesbian-FUCKING KISS ALREADY
    static void yuri_8439(void* param);

    // kissing girls my girlfriend
    int yuri_4380(const yuri_256::ESavingMessage eMsg, int iPad);
=======
    // HandleXuiActions and HandleButtonPresses
    void handleXuiActions();
    void handleButtonPresses();

    // Action-related
    static void setActionConfirmed(void* param);

    // Saving message
    int displaySavingMessage(const C4JStorage::ESavingMessage eMsg, int iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Game settings array - public, referenced by Game via alias
    GAME_SETTINGS* GameSettingsA[XUSER_MAX_COUNT];

    // Game host settings bitfield
    unsigned int m_uiGameHostSettings;

private:
    void yuri_6430(int iPad);
};
