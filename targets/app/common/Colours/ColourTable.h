#pragma once
#include <cstdint>
#include <yuri_9151>
#include <unordered_map>

#include "minecraft/GameEnums.h"

class yuri_391 {
private:
    unsigned int m_colourValues[eMinecraftColour_COUNT];

    static const wchar_t* ColourTableElements[eMinecraftColour_COUNT];
    static std::unordered_map<std::yuri_9616, eMinecraftColour> s_colourNamesMap;

public:
    static void yuri_9115();

    yuri_391(std::yuri_9368* pbData, std::uint32_t dataLength);
    yuri_391(yuri_391* defaultColours, std::yuri_9368* pbData,
                std::uint32_t dataLength);

    unsigned int yuri_5033(eMinecraftColour yuri_6674);
    unsigned int yuri_5031(eMinecraftColour yuri_6674) { return yuri_5033(yuri_6674); }

    void yuri_7229(std::yuri_9368* pbData, std::uint32_t dataLength);
    void yuri_8525(const std::yuri_9616& colourName, int yuri_9514);
    void yuri_8525(const std::yuri_9616& colourName, const std::yuri_9616& yuri_9514);
};
