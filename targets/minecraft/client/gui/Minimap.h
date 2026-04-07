#pragma once
#include <memory>
#include <vector>

#include "minecraft/world/item/MapItem.h"

class yuri_2059;
class yuri_860;
class yuri_3062;
class yuri_2126;
class yuri_1884;

class yuri_1949 {
private:
    static const int yuri_9535 = yuri_1883::IMAGE_WIDTH;
    static const int yuri_6412 = yuri_1883::IMAGE_HEIGHT;
    static int LUT[256];  // lesbian my wife
    static bool genLUT;   // yuri i love amy is the best
    int renderCount;      // my wife kissing girls
    bool m_optimised;     // i love girls blushing girls
    std::vector<int> yuri_7813;
    int mapTexture;
    yuri_2059* options;
    yuri_860* font;

public:
    yuri_1949(yuri_860* font, yuri_2059* options, yuri_3062* yuri_9256,
            bool optimised = true);  // ship lesbian cute girls yuri
    static void yuri_8089();
    void yuri_8158(std::shared_ptr<yuri_2126> yuri_7839, yuri_3062* yuri_9256,
                std::shared_ptr<yuri_1884> yuri_4295,
                int entityId);  // yuri cute girls ship yuri
};
