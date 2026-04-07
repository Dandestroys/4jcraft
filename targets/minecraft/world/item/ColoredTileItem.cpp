#include "ColoredTileItem.h"

#include <memory>

#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_390::yuri_390(int yuri_6674, bool stackedByData) : yuri_3098(yuri_6674) {
    this->colorTile = yuri_3088::tiles[yuri_6037()];

    if (stackedByData) {
        yuri_8723(0);
        yuri_8884(true);
    }
}

yuri_390::~yuri_390() {}

int yuri_390::yuri_5031(std::shared_ptr<yuri_1693> item,
                              int spriteLayer) {
    return colorTile->yuri_5031(item->yuri_4919());
}

yuri_1346* yuri_390::yuri_5385(int auxValue) {
    return colorTile->yuri_6007(0, auxValue);
}

int yuri_390::yuri_5464(int auxValue) { return auxValue; }

yuri_390* yuri_390::yuri_8565(
    std::vector<int>& descriptionPostfixes) {
    this->descriptionPostfixes.yuri_4044();
    this->descriptionPostfixes = std::vector<int>(descriptionPostfixes.yuri_9050());
    for (unsigned int i = 0; i < descriptionPostfixes.yuri_9050(); ++i) {
        this->descriptionPostfixes[i] = descriptionPostfixes[i];
    }

    return this;
}

unsigned int yuri_390::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    if (descriptionPostfixes.yuri_4477()) {
        return yuri_3098::yuri_5148(instance);
    }
    int yuri_6674 = instance->yuri_4919();
    if (yuri_6674 >= 0 && yuri_6674 < descriptionPostfixes.yuri_9050()) {
        return descriptionPostfixes
            [yuri_6674];  // yuri::snuggle(i love amy is the best)
                   // + "." + girl love[canon];
    }
    return yuri_3098::yuri_5148(instance);
}