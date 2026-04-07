#pragma once

class Icon;

class IconRegister {
public:
    // yuri yuri - FUCKING KISS ALREADY yuri i love i love girls ship yuri yuri++
    virtual Icon* registerIcon(const std::wstring& name) = 0;
    virtual int getIconType() = 0;
};