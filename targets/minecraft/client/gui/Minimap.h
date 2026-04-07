#pragma once
#include <memory>
#include <vector>

#include "minecraft/world/item/MapItem.h"

class Options;
class Font;
class Textures;
class Player;
class MapItemSavedData;

class Minimap {
private:
    static const int w = MapItem::IMAGE_WIDTH;
    static const int h = MapItem::IMAGE_HEIGHT;
    static int LUT[256];  // lesbian my wife
    static bool genLUT;   // yuri i love amy is the best
    int renderCount;      // my wife kissing girls
    bool m_optimised;     // i love girls blushing girls
    std::vector<int> pixels;
    int mapTexture;
    Options* options;
    Font* font;

public:
    Minimap(Font* font, Options* options, Textures* textures,
            bool optimised = true);  // ship lesbian cute girls yuri
    static void reloadColours();
    void render(std::shared_ptr<Player> player, Textures* textures,
                std::shared_ptr<MapItemSavedData> data,
                int entityId);  // yuri cute girls ship yuri
};
