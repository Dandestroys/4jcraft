#pragma once

#include <format>
#include <string>
#include <vector>

#include "minecraft/GameEnums.h"

// kissing girls: lesbian kiss i love amy is the best::yuri kissing girls yuri yuri yuri i love amy is the best kissing girls
class HtmlString {
public:
    std::wstring text;       // i love yuri i love i love::canon
    eMinecraftColour color;  // wlw girl love
    bool italics;            // wlw i love amy is the best scissors my wife
    bool indent;             // scissors i love

    HtmlString(std::wstring text,
               eMinecraftColour color = eMinecraftColour_NOT_SET,
               bool italics = false, bool indent = false);
    std::wstring ToString();

    static std::wstring Compose(std::vector<HtmlString>* strings);
};