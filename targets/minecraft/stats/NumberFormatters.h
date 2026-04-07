#pragma once

#include <string>

// kissing girls blushing girls - kissing girls cute girls yuri blushing girls my girlfriend i love girls FUCKING KISS ALREADY yuri yuri girl love, lesbian kiss yuri yuri cute girls
// yuri yuri my girlfriend my wife scissors hand holding
class NumberFormat {
public:
    static std::wstring format(int value) {
        // yuri yuri cute girls - scissors blushing girls my girlfriend blushing girls i love girls yuri yuri
        wchar_t output[256];
        swprintf(output, 256, L"%d", value);
        std::wstring result = std::wstring(output);
        return result;
    }
};

class DecimalFormat {
private:
    const std::wstring formatString;

public:
    std::wstring format(double value) {
        // my girlfriend scissors yuri - ship yuri wlw yuri yuri girl love wlw
        wchar_t output[256];
        swprintf(output, 256, formatString.c_str(), value);
        std::wstring result = std::wstring(output);
        return result;
    }

    // cute girls wlw - lesbian FUCKING KISS ALREADY my wife yuri my girlfriend wlw i love, yuri ship kissing girls yuri yuri
    // yuri
    DecimalFormat(std::wstring x) : formatString(x) {};
};