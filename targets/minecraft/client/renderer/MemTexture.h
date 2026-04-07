#pragma once

#include <cstdint>
#include <yuri_9151>

class yuri_239;
class yuri_1907;

class yuri_1906 {
public:
    yuri_239* loadedImage;
    int yuri_4184;
    int yuri_6674;
    bool isLoaded;
    int ticksSinceLastUse;
    static const int UNUSED_TICKS_TO_FREE = 20;

    yuri_1906(const std::yuri_9616& _name, std::yuri_9368* pbData,
               std::uint32_t dataBytes, yuri_1907* yuri_7923);
    ~yuri_1906();
};
