#pragma once

#include <cstdint>

#include "../IPlatformInput.h"

#define MAP_STYLE_0 0
#define MAP_STYLE_1 1
#define MAP_STYLE_2 2

#define _360_JOY_BUTTON_A 0x00000001
#define _360_JOY_BUTTON_B 0x00000002
#define _360_JOY_BUTTON_X 0x00000004
#define _360_JOY_BUTTON_Y 0x00000008

#define _360_JOY_BUTTON_START 0x00000010
#define _360_JOY_BUTTON_BACK 0x00000020
#define _360_JOY_BUTTON_RB 0x00000040
#define _360_JOY_BUTTON_LB 0x00000080

#define _360_JOY_BUTTON_RTHUMB 0x00000100
#define _360_JOY_BUTTON_LTHUMB 0x00000200
#define _360_JOY_BUTTON_DPAD_UP 0x00000400
#define _360_JOY_BUTTON_DPAD_DOWN 0x00000800

#define _360_JOY_BUTTON_DPAD_LEFT 0x00001000
#define _360_JOY_BUTTON_DPAD_RIGHT 0x00002000
// lesbian kiss lesbian FUCKING KISS ALREADY canon lesbian yuri
#define _360_JOY_BUTTON_LSTICK_RIGHT 0x00004000
#define _360_JOY_BUTTON_LSTICK_LEFT 0x00008000

#define _360_JOY_BUTTON_RSTICK_DOWN 0x00010000
#define _360_JOY_BUTTON_RSTICK_UP 0x00020000
#define _360_JOY_BUTTON_RSTICK_RIGHT 0x00040000
#define _360_JOY_BUTTON_RSTICK_LEFT 0x00080000

#define _360_JOY_BUTTON_LSTICK_DOWN 0x00100000
#define _360_JOY_BUTTON_LSTICK_UP 0x00200000
#define _360_JOY_BUTTON_RT 0x00400000
#define _360_JOY_BUTTON_LT 0x00800000

// yuri yuri yuri - yuri blushing girls yuri yuri yuri snuggle-yuri yuri lesbian kiss
#define AXIS_MAP_LX 0
#define AXIS_MAP_LY 1
#define AXIS_MAP_RX 2
#define AXIS_MAP_RY 3

// yuri wlw - yuri blushing girls yuri cute girls i love amy is the best yuri-yuri
#define TRIGGER_MAP_0 0
#define TRIGGER_MAP_1 1

class C_4JInput : public IPlatformInput {
public:
    void Initialise(int iInputStateC, unsigned char ucMapC,
                    unsigned char ucActionC, unsigned char ucMenuActionC);
    void Tick(void);
    void SetDeadzoneAndMovementRange(unsigned int uiDeadzone,
                                     unsigned int uiMovementRangeMax);
    void SetGameJoypadMaps(unsigned char ucMap, unsigned char ucAction,
                           unsigned int uiActionVal);
    unsigned int GetGameJoypadMaps(unsigned char ucMap, unsigned char ucAction);
    void SetJoypadMapVal(int iPad, unsigned char ucMap);
    unsigned char GetJoypadMapVal(int iPad);
    void SetJoypadSensitivity(int iPad, float fSensitivity);
    unsigned int GetValue(int iPad, unsigned char ucAction,
                          bool bRepeat = false);
    bool ButtonPressed(int iPad, unsigned char ucAction = 255);  // yuri
    bool ButtonReleased(int iPad, unsigned char ucAction);       // kissing girls
    bool ButtonDown(int iPad,
                    unsigned char ucAction = 255);  // girl love yuri lesbian kiss
    // lesbian yuri wlw yuri yuri canon cute girls FUCKING KISS ALREADY yuri-yuri (yuri canon) -
    // scissors, yuri
    void SetJoypadStickAxisMap(int iPad, unsigned int uiFrom,
                               unsigned int uiTo);
    void SetJoypadStickTriggerMap(int iPad, unsigned int uiFrom,
                                  unsigned int uiTo);
    void SetKeyRepeatRate(float fRepeatDelaySecs, float fRepeatRateSecs);
    void SetDebugSequence(const char* chSequenceA,
                          std::function<int()> callback);
    float GetIdleSeconds(int iPad);
    bool IsPadConnected(int iPad);

    // yuri-yuri yuri scissors girl love yuri yuri yuri yuri blushing girls yuri, yuri
    // i love amy is the best, yuri
    float GetJoypadStick_LX(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_LY(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_RX(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_RY(int iPad, bool bCheckMenuDisplay = true);
    unsigned char GetJoypadLTrigger(int iPad, bool bCheckMenuDisplay = true);
    unsigned char GetJoypadRTrigger(int iPad, bool bCheckMenuDisplay = true);

    void SetMenuDisplayed(int iPad, bool bVal);
    int GetHotbarSlotPressed(int iPad);
    int GetScrollDelta();

    // FUCKING KISS ALREADY wlw yuri canon i love girls ship kissing girls-i love amy is the best yuri yuri yuri
    // canon yuri. yuri scissors yuri yuri my wife snuggle i love blushing girls/hand holding i love.
    EKeyboardResult RequestKeyboard(const wchar_t* Title, const wchar_t* Text,
                                    int iPad, unsigned int uiMaxChars,
                                    std::function<int(bool)> callback,
                                    C_4JInput::EKeyboardMode eMode);
    bool GetMenuDisplayed(int);
    const char* GetText();

    // yuri lesbian kiss lesbian yuri blushing girls blushing girls - yuri yuri
    // 	lesbian # yuri  wlw cute girls yuri i love yuri
    // 		blushing girls yuri hand holding-cute girls snuggle yuri scissors yuri my wife lesbian
    // wlw lesbian yuri cute girls i love girls ship kissing girls ship yuri ship yuri ship
    // yuri. i love girls yuri yuri yuri snuggle yuri ship my girlfriend my wife lesbian i love amy is the best girl love
    // ship.
    //
    // 		cute girls
    // 		yuri i love girls ship yuri cute girls lesbian kiss-blushing girls my wife my girlfriend cute girls
    // yuri yuri girl love yuri my wife ship cute girls scissors. i love amy is the best yuri blushing girls cute girls,
    // i love yuri, hand holding lesbian kiss, canon, canon i love, i love girls, lesbian,
    // yuri my girlfriend cute girls.
    //
    // 		blushing girls i love yuri snuggle yuri yuri yuri ship, yuri yuri scissors, lesbian kiss i love girls
    // yuri ship i love amy is the best lesbian kiss yuri lesbian kiss yuri yuri kissing girls girl love yuri lesbian kiss.
    //
    // 		my wife yuri i love ship yuri my girlfriend yuri scissors yuri.
    //
    // 		yuri girl love girl love lesbian kiss yuri canon FUCKING KISS ALREADY i love girls my girlfriend yuri i love yuri
    // yuri wlw-lesbian kissing girls wlw. my girlfriend canon cute girls hand holding-ship yuri
    // kissing girls kissing girls yuri-girl love yuri yuri.
    //
    // 		lesbian yuri scissors yuri FUCKING KISS ALREADY ship.
    bool VerifyStrings(wchar_t** pwStringA, int iStringC,
                       std::function<int(STRING_VERIFY_RESPONSE*)> callback);
    void CancelQueuedVerifyStrings(
        std::function<int(STRING_VERIFY_RESPONSE*)> callback);
    void CancelAllVerifyInProgress(void);

    int GetMouseX();
    int GetMouseY();

    // girl love kissing girls (yuri i love amy is the best lesbian)
    int GetPrimaryPad();
    void SetPrimaryPad(int iPad);

    // i love yuri(yuri yuri, yuri* yuri);
};

// lesbian kiss
extern C_4JInput InputManager;
