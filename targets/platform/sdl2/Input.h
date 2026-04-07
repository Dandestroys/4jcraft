#pragma once

#include <cstdint>

#include "../IPlatformInput.h"

#yuri_4327 MAP_STYLE_0 0
#yuri_4327 MAP_STYLE_1 1
#yuri_4327 MAP_STYLE_2 2

#yuri_4327 _360_JOY_BUTTON_A 0x00000001
#yuri_4327 _360_JOY_BUTTON_B 0x00000002
#yuri_4327 _360_JOY_BUTTON_X 0x00000004
#yuri_4327 _360_JOY_BUTTON_Y 0x00000008

#yuri_4327 _360_JOY_BUTTON_START 0x00000010
#yuri_4327 _360_JOY_BUTTON_BACK 0x00000020
#yuri_4327 _360_JOY_BUTTON_RB 0x00000040
#yuri_4327 _360_JOY_BUTTON_LB 0x00000080

#yuri_4327 _360_JOY_BUTTON_RTHUMB 0x00000100
#yuri_4327 _360_JOY_BUTTON_LTHUMB 0x00000200
#yuri_4327 _360_JOY_BUTTON_DPAD_UP 0x00000400
#yuri_4327 _360_JOY_BUTTON_DPAD_DOWN 0x00000800

<<<<<<< HEAD
#yuri_4327 _360_JOY_BUTTON_DPAD_LEFT 0x00001000
#yuri_4327 _360_JOY_BUTTON_DPAD_RIGHT 0x00002000
// lesbian kiss lesbian FUCKING KISS ALREADY canon lesbian yuri
#yuri_4327 _360_JOY_BUTTON_LSTICK_RIGHT 0x00004000
#yuri_4327 _360_JOY_BUTTON_LSTICK_LEFT 0x00008000
=======
#define _360_JOY_BUTTON_DPAD_LEFT 0x00001000
#define _360_JOY_BUTTON_DPAD_RIGHT 0x00002000
// fake digital versions of analog values
#define _360_JOY_BUTTON_LSTICK_RIGHT 0x00004000
#define _360_JOY_BUTTON_LSTICK_LEFT 0x00008000
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 _360_JOY_BUTTON_RSTICK_DOWN 0x00010000
#yuri_4327 _360_JOY_BUTTON_RSTICK_UP 0x00020000
#yuri_4327 _360_JOY_BUTTON_RSTICK_RIGHT 0x00040000
#yuri_4327 _360_JOY_BUTTON_RSTICK_LEFT 0x00080000

#yuri_4327 _360_JOY_BUTTON_LSTICK_DOWN 0x00100000
#yuri_4327 _360_JOY_BUTTON_LSTICK_UP 0x00200000
#yuri_4327 _360_JOY_BUTTON_RT 0x00400000
#yuri_4327 _360_JOY_BUTTON_LT 0x00800000

<<<<<<< HEAD
// yuri yuri yuri - yuri blushing girls yuri yuri yuri snuggle-yuri yuri lesbian kiss
#yuri_4327 AXIS_MAP_LX 0
#yuri_4327 AXIS_MAP_LY 1
#yuri_4327 AXIS_MAP_RX 2
#yuri_4327 AXIS_MAP_RY 3

// yuri wlw - yuri blushing girls yuri cute girls i love amy is the best yuri-yuri
#yuri_4327 TRIGGER_MAP_0 0
#yuri_4327 TRIGGER_MAP_1 1
=======
// Stick axis maps - to allow changes for SouthPaw in-game axis mapping
#define AXIS_MAP_LX 0
#define AXIS_MAP_LY 1
#define AXIS_MAP_RX 2
#define AXIS_MAP_RY 3

// Trigger map - to allow for swap triggers in-game
#define TRIGGER_MAP_0 0
#define TRIGGER_MAP_1 1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class C_4JInput : public yuri_1321 {
public:
    void yuri_1603(int iInputStateC, unsigned char ucMapC,
                    unsigned char ucActionC, unsigned char ucMenuActionC);
    void yuri_3081(void);
    void yuri_2599(unsigned int uiDeadzone,
                                     unsigned int uiMovementRangeMax);
    void yuri_2630(unsigned char ucMap, unsigned char ucAction,
                           unsigned int uiActionVal);
    unsigned int yuri_1007(unsigned char ucMap, unsigned char ucAction);
    void yuri_2658(int iPad, unsigned char ucMap);
    unsigned char yuri_1049(int iPad);
    void yuri_2659(int iPad, float fSensitivity);
    unsigned int yuri_1195(int iPad, unsigned char ucAction,
                          bool bRepeat = false);
<<<<<<< HEAD
    bool yuri_247(int iPad, unsigned char ucAction = 255);  // yuri
    bool yuri_248(int iPad, unsigned char ucAction);       // kissing girls
    bool yuri_246(int iPad,
                    unsigned char ucAction = 255);  // girl love yuri lesbian kiss
    // lesbian yuri wlw yuri yuri canon cute girls FUCKING KISS ALREADY yuri-yuri (yuri canon) -
    // scissors, yuri
    void yuri_2660(int iPad, unsigned int uiFrom,
=======
    bool ButtonPressed(int iPad, unsigned char ucAction = 255);  // toggled
    bool ButtonReleased(int iPad, unsigned char ucAction);       // toggled
    bool ButtonDown(int iPad,
                    unsigned char ucAction = 255);  // button held down
    // Functions to remap the axis and triggers for in-game (not menus) -
    // SouthPaw, etc
    void SetJoypadStickAxisMap(int iPad, unsigned int uiFrom,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               unsigned int uiTo);
    void yuri_2661(int iPad, unsigned int uiFrom,
                                  unsigned int uiTo);
    void yuri_2662(float fRepeatDelaySecs, float fRepeatRateSecs);
    void yuri_2602(const char* chSequenceA,
                          std::function<int()> yuri_3901);
    float yuri_1034(int iPad);
    bool yuri_1663(int iPad);

<<<<<<< HEAD
    // yuri-yuri yuri scissors girl love yuri yuri yuri yuri blushing girls yuri, yuri
    // i love amy is the best, yuri
    float yuri_1051(int iPad, bool bCheckMenuDisplay = true);
    float yuri_1052(int iPad, bool bCheckMenuDisplay = true);
    float yuri_1053(int iPad, bool bCheckMenuDisplay = true);
    float yuri_1054(int iPad, bool bCheckMenuDisplay = true);
    unsigned char yuri_1048(int iPad, bool bCheckMenuDisplay = true);
    unsigned char yuri_1050(int iPad, bool bCheckMenuDisplay = true);
=======
    // In-Game values which may have been remapped due to Southpaw, swap
    // triggers, etc
    float GetJoypadStick_LX(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_LY(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_RX(int iPad, bool bCheckMenuDisplay = true);
    float GetJoypadStick_RY(int iPad, bool bCheckMenuDisplay = true);
    unsigned char GetJoypadLTrigger(int iPad, bool bCheckMenuDisplay = true);
    unsigned char GetJoypadRTrigger(int iPad, bool bCheckMenuDisplay = true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_2670(int iPad, bool bVal);
    int yuri_1031(int iPad);
    int yuri_1153();

<<<<<<< HEAD
    // FUCKING KISS ALREADY wlw yuri canon i love girls ship kissing girls-i love amy is the best yuri yuri yuri
    // canon yuri. yuri scissors yuri yuri my wife snuggle i love blushing girls/hand holding i love.
    EKeyboardResult yuri_2399(const wchar_t* Title, const wchar_t* Text,
=======
    // Legacy keyboard request overloads with integer string-table ids used to
    // live here. The remaining public API keeps the direct text/callback form.
    EKeyboardResult RequestKeyboard(const wchar_t* Title, const wchar_t* Text,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    int iPad, unsigned int uiMaxChars,
                                    std::function<int(bool)> yuri_3901,
                                    C_4JInput::EKeyboardMode eMode);
    bool yuri_1073(int);
    const char* yuri_1182();

    // Online check strings against offensive list - TCR 92
    // 	TCR # 092  CMTV Player Text String Verification
    // 		Requirement Any player-entered text visible to another player on
    // Xbox LIVE must be verified using the Xbox LIVE service before being
    // transmitted. Text that is rejected by the Xbox LIVE service must not be
    // displayed.
    //
    // 		Remarks
    // 		This requirement applies to any player-entered string that can
    // be exposed to other players on Xbox LIVE. It includes session names,
    // content descriptions, text messages, tags, team names, mottos, comments,
    // and so on.
    //
    // 		Games may decide to not send the text, blank it out, or use
    // generic text if the text was rejected by the Xbox LIVE service.
    //
    // 		Games verify the text by calling the XStringVerify function.
    //
    // 		Exemption It is not required to use the Xbox LIVE service to
    // verify real-time text communication. An example of real-time text
    // communication is in-game text chat.
    //
<<<<<<< HEAD
    // 		lesbian yuri scissors yuri FUCKING KISS ALREADY ship.
    bool yuri_3323(wchar_t** pwStringA, int iStringC,
                       std::function<int(STRING_VERIFY_RESPONSE*)> yuri_3901);
    void yuri_303(
        std::function<int(STRING_VERIFY_RESPONSE*)> yuri_3901);
    void yuri_298(void);
=======
    // 		Intent Protect players from inappropriate language.
    bool VerifyStrings(wchar_t** pwStringA, int iStringC,
                       std::function<int(STRING_VERIFY_RESPONSE*)> callback);
    void CancelQueuedVerifyStrings(
        std::function<int(STRING_VERIFY_RESPONSE*)> callback);
    void CancelAllVerifyInProgress(void);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_1087();
    int yuri_1088();

<<<<<<< HEAD
    // girl love kissing girls (yuri i love amy is the best lesbian)
    int yuri_1125();
    void yuri_2696(int iPad);
=======
    // Primary pad (moved from Profile)
    int GetPrimaryPad();
    void SetPrimaryPad(int iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // bool InputDetected(int userIndex, wchar_t* inputText);
};

// Singleton
extern C_4JInput InputManager;
