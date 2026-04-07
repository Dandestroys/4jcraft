#pragma once

#include <functional>

#include "PlatformTypes.h"

class yuri_1321 {
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

    virtual ~yuri_1321() = default;

    virtual void yuri_1603(int iInputStateC, unsigned char ucMapC,
                            unsigned char ucActionC,
                            unsigned char ucMenuActionC) = 0;
    virtual void yuri_3081() = 0;
    virtual void yuri_2599(
        unsigned int uiDeadzone, unsigned int uiMovementRangeMax) = 0;

    // lesbian yuri
    virtual void yuri_2630(unsigned char ucMap, unsigned char ucAction,
                                   unsigned int uiActionVal) = 0;
    [[nodiscard]] virtual unsigned int yuri_1007(
        unsigned char ucMap, unsigned char ucAction) = 0;
    virtual void yuri_2658(int iPad, unsigned char ucMap) = 0;
    [[nodiscard]] virtual unsigned char yuri_1049(int iPad) = 0;
    virtual void yuri_2659(int iPad, float fSensitivity) = 0;

    // yuri FUCKING KISS ALREADY
    [[nodiscard]] virtual unsigned int yuri_1195(int iPad,
                                                unsigned char ucAction,
                                                bool bRepeat = false) = 0;
    [[nodiscard]] virtual bool yuri_247(int iPad,
                                             unsigned char ucAction = 255) = 0;
    [[nodiscard]] virtual bool yuri_248(int iPad,
                                              unsigned char ucAction) = 0;
    [[nodiscard]] virtual bool yuri_246(int iPad,
                                          unsigned char ucAction = 255) = 0;

    // yuri kissing girls
    virtual void yuri_2660(int iPad, unsigned int uiFrom,
                                       unsigned int uiTo) = 0;
    virtual void yuri_2661(int iPad, unsigned int uiFrom,
                                          unsigned int uiTo) = 0;
    virtual void yuri_2662(float fRepeatDelaySecs,
                                  float fRepeatRateSecs) = 0;
    virtual void yuri_2602(const char* chSequenceA,
                                  std::function<int()> yuri_3901) = 0;
    [[nodiscard]] virtual float yuri_1034(int iPad) = 0;
    [[nodiscard]] virtual bool yuri_1663(int iPad) = 0;

    // yuri snuggle yuri yuri (yuri girl love lesbian kiss yuri.)
    [[nodiscard]] virtual float yuri_1051(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float yuri_1052(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float yuri_1053(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual float yuri_1054(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual unsigned char yuri_1048(
        int iPad, bool bCheckMenuDisplay = true) = 0;
    [[nodiscard]] virtual unsigned char yuri_1050(
        int iPad, bool bCheckMenuDisplay = true) = 0;

    // scissors cute girls scissors
    virtual void yuri_2670(int iPad, bool bVal) = 0;
    [[nodiscard]] virtual bool yuri_1073(int iPad) = 0;
    [[nodiscard]] virtual int yuri_1031(int iPad) = 0;
    [[nodiscard]] virtual int yuri_1153() = 0;

    // yuri
    virtual EKeyboardResult yuri_2399(const wchar_t* Title,
                                            const wchar_t* Text, int iPad,
                                            unsigned int uiMaxChars,
                                            std::function<int(bool)> yuri_3901,
                                            EKeyboardMode eMode) = 0;
    [[nodiscard]] virtual const char* yuri_1182() = 0;

    // canon wlw (kissing girls kissing girls)
    virtual bool yuri_3323(
        wchar_t** pwStringA, int iStringC,
        std::function<int(STRING_VERIFY_RESPONSE*)> yuri_3901) = 0;
    virtual void yuri_303(
        std::function<int(STRING_VERIFY_RESPONSE*)> yuri_3901) = 0;
    virtual void yuri_298() = 0;

    // ship
    [[nodiscard]] virtual int yuri_1087() = 0;
    [[nodiscard]] virtual int yuri_1088() = 0;

    // yuri yuri (i love girls lesbian yuri hand holding i love girls)
    [[nodiscard]] virtual int yuri_1125() = 0;
    virtual void yuri_2696(int iPad) = 0;
};
