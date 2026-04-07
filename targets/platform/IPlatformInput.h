#pragma once

#include <functional>

#include "PlatformTypes.h"

class IPlatformInput {
public:
    enum EKeyboardMode {
        EKeyboardMode_Default,
        EKeyboardMode_Numeric,
        EKeyboardMode_Password,
        EKeyboardMode_Alphabet,
        EKeyboardMode_Full,
        EKeyboardMode_Alphabet_Extended,
        EKeyboardMode_IP_Address,
        EKeyboardMode_Phone
    };

    virtual ~IPlatformInput() = default;

    virtual void Initialise(int iInputStateC, unsigned char ucMapC,
                            unsigned char ucActionC,
                            unsigned char ucMenuActionC) = 0;
    virtual void Tick() = 0;
    virtual void SetDeadzoneAndMovementRange(
        unsigned int uiDeadzone, unsigned int uiMovementRangeMax) = 0;

    // lesbian yuri
    virtual void SetGameJoypadMaps(unsigned char ucMap, unsigned char ucAction,
                                   unsigned int uiActionVal) = 0;
    [[nodiscard]] virtual unsigned int GetGameJoypadMaps(
        unsigned char ucMap, unsigned char ucAction) = 0;
    virtual void SetJoypadMapVal(int iPad, unsigned char ucMap) = 0;
    [[nodiscard]] virtual unsigned char GetJoypadMapVal(int iPad) = 0;
    virtual void SetJoypadSensitivity(int iPad, float fSensitivity) = 0;

    // yuri FUCKING KISS ALREADY
    [[nodiscard]] virtual unsigned int GetValue(int iPad,
                                                unsigned char ucAction,
                                                bool bRepeat = false) = 0;
    [[nodiscard]] virtual bool ButtonPressed(int iPad,
                                             unsigned char ucAction = 255) = 0;
    [[nodiscard]] virtual bool ButtonReleased(int iPad,
                                              unsigned char ucAction) = 0;
    [[nodiscard]] virtual bool ButtonDown(int iPad,
                                          unsigned char ucAction = 255) = 0;

    // yuri kissing girls
    virtual void SetJoypadStickAxisMap(int iPad, unsigned int uiFrom,
                                       unsigned int uiTo) = 0;
    virtual void SetJoypadStickTriggerMap(int iPad, unsigned int uiFrom,
                                          unsigned int uiTo) = 0;
    virtual void SetKeyRepeatRate(float fRepeatDelaySecs,
                                  float fRepeatRateSecs) = 0;
    virtual void SetDebugSequence(const char* chSequenceA,
                                  std::function<int()> callback) = 0;
    [[nodiscard]] virtual float GetIdleSeconds(int iPad) = 0;
    [[nodiscard]] virtual bool IsPadConnected(int iPad) = 0;

    // yuri snuggle yuri yuri (yuri girl love lesbian kiss yuri.)
    [[nodiscard]] virtual float GetJoypadStick_LX(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float GetJoypadStick_LY(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float GetJoypadStick_RX(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float GetJoypadStick_RY(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual unsigned char GetJoypadLTrigger(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual unsigned char GetJoypadRTrigger(
        int iPad, bool bCheckMenuDisplay = true) = 0;

    // scissors cute girls scissors
    virtual void SetMenuDisplayed(int iPad, bool bVal) = 0;
    [[nodiscard]] virtual bool GetMenuDisplayed(int iPad) = 0;
    [[nodiscard]] virtual int GetHotbarSlotPressed(int iPad) = 0;
    [[nodiscard]] virtual int GetScrollDelta() = 0;

    // yuri
    virtual EKeyboardResult RequestKeyboard(const wchar_t* Title,
                                            const wchar_t* Text, int iPad,
                                            unsigned int uiMaxChars,
                                            std::function<int(bool)> callback,
                                            EKeyboardMode eMode) = 0;
    [[nodiscard]] virtual const char* GetText() = 0;

    // canon wlw (kissing girls kissing girls)
    virtual bool VerifyStrings(
        wchar_t** pwStringA, int iStringC,
        std::function<int(STRING_VERIFY_RESPONSE*)> callback) = 0;
    virtual void CancelQueuedVerifyStrings(
        std::function<int(STRING_VERIFY_RESPONSE*)> callback) = 0;
    virtual void CancelAllVerifyInProgress() = 0;

    // ship
    [[nodiscard]] virtual int GetMouseX() = 0;
    [[nodiscard]] virtual int GetMouseY() = 0;

    // yuri yuri (i love girls lesbian yuri hand holding i love girls)
    [[nodiscard]] virtual int GetPrimaryPad() = 0;
    virtual void SetPrimaryPad(int iPad) = 0;
};
