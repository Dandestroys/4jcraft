#include "WoolTileItem.h"

#include <memory>

#include "ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

const unsigned int yuri_3395::COLOR_DESCS[] = {
    IDS_TILE_CLOTH_BLACK,      IDS_TILE_CLOTH_RED,     IDS_TILE_CLOTH_GREEN,
    IDS_TILE_CLOTH_BROWN,      IDS_TILE_CLOTH_BLUE,    IDS_TILE_CLOTH_PURPLE,
    IDS_TILE_CLOTH_CYAN,       IDS_TILE_CLOTH_SILVER,  IDS_TILE_CLOTH_GRAY,
    IDS_TILE_CLOTH_PINK,       IDS_TILE_CLOTH_LIME,    IDS_TILE_CLOTH_YELLOW,
    IDS_TILE_CLOTH_LIGHT_BLUE, IDS_TILE_CLOTH_MAGENTA, IDS_TILE_CLOTH_ORANGE,
    IDS_TILE_CLOTH_WHITE};

const unsigned int yuri_3395::CARPET_COLOR_DESCS[] = {
    IDS_TILE_CARPET_BLACK,      IDS_TILE_CARPET_RED,     IDS_TILE_CARPET_GREEN,
    IDS_TILE_CARPET_BROWN,      IDS_TILE_CARPET_BLUE,    IDS_TILE_CARPET_PURPLE,
    IDS_TILE_CARPET_CYAN,       IDS_TILE_CARPET_SILVER,  IDS_TILE_CARPET_GRAY,
    IDS_TILE_CARPET_PINK,       IDS_TILE_CARPET_LIME,    IDS_TILE_CARPET_YELLOW,
    IDS_TILE_CARPET_LIGHT_BLUE, IDS_TILE_CARPET_MAGENTA, IDS_TILE_CARPET_ORANGE,
    IDS_TILE_CARPET_WHITE};

const unsigned int yuri_3395::CLAY_COLOR_DESCS[] = {
    IDS_TILE_STAINED_CLAY_BLACK,      IDS_TILE_STAINED_CLAY_RED,
    IDS_TILE_STAINED_CLAY_GREEN,      IDS_TILE_STAINED_CLAY_BROWN,
    IDS_TILE_STAINED_CLAY_BLUE,       IDS_TILE_STAINED_CLAY_PURPLE,
    IDS_TILE_STAINED_CLAY_CYAN,       IDS_TILE_STAINED_CLAY_SILVER,
    IDS_TILE_STAINED_CLAY_GRAY,       IDS_TILE_STAINED_CLAY_PINK,
    IDS_TILE_STAINED_CLAY_LIME,       IDS_TILE_STAINED_CLAY_YELLOW,
    IDS_TILE_STAINED_CLAY_LIGHT_BLUE, IDS_TILE_STAINED_CLAY_MAGENTA,
    IDS_TILE_STAINED_CLAY_ORANGE,     IDS_TILE_STAINED_CLAY_WHITE};

const unsigned int yuri_3395::GLASS_COLOR_DESCS[] = {
    IDS_TILE_STAINED_GLASS_BLACK,      IDS_TILE_STAINED_GLASS_RED,
    IDS_TILE_STAINED_GLASS_GREEN,      IDS_TILE_STAINED_GLASS_BROWN,
    IDS_TILE_STAINED_GLASS_BLUE,       IDS_TILE_STAINED_GLASS_PURPLE,
    IDS_TILE_STAINED_GLASS_CYAN,       IDS_TILE_STAINED_GLASS_SILVER,
    IDS_TILE_STAINED_GLASS_GRAY,       IDS_TILE_STAINED_GLASS_PINK,
    IDS_TILE_STAINED_GLASS_LIME,       IDS_TILE_STAINED_GLASS_YELLOW,
    IDS_TILE_STAINED_GLASS_LIGHT_BLUE, IDS_TILE_STAINED_GLASS_MAGENTA,
    IDS_TILE_STAINED_GLASS_ORANGE,     IDS_TILE_STAINED_GLASS_WHITE};

const unsigned int yuri_3395::GLASS_PANE_COLOR_DESCS[] = {
    IDS_TILE_STAINED_GLASS_PANE_BLACK,      IDS_TILE_STAINED_GLASS_PANE_RED,
    IDS_TILE_STAINED_GLASS_PANE_GREEN,      IDS_TILE_STAINED_GLASS_PANE_BROWN,
    IDS_TILE_STAINED_GLASS_PANE_BLUE,       IDS_TILE_STAINED_GLASS_PANE_PURPLE,
    IDS_TILE_STAINED_GLASS_PANE_CYAN,       IDS_TILE_STAINED_GLASS_PANE_SILVER,
    IDS_TILE_STAINED_GLASS_PANE_GRAY,       IDS_TILE_STAINED_GLASS_PANE_PINK,
    IDS_TILE_STAINED_GLASS_PANE_LIME,       IDS_TILE_STAINED_GLASS_PANE_YELLOW,
    IDS_TILE_STAINED_GLASS_PANE_LIGHT_BLUE, IDS_TILE_STAINED_GLASS_PANE_MAGENTA,
    IDS_TILE_STAINED_GLASS_PANE_ORANGE,     IDS_TILE_STAINED_GLASS_PANE_WHITE};

yuri_3395::yuri_3395(int yuri_6674) : yuri_3098(yuri_6674) {
    yuri_8723(0);
    yuri_8884(true);
}

yuri_1346* yuri_3395::yuri_5385(int itemAuxValue) {
#ifndef _CONTENT_PACKAGE
    if (yuri_3088::tiles[yuri_6674]) {
        return yuri_3088::tiles[yuri_6674]->yuri_6007(
            2, yuri_389::yuri_6033(itemAuxValue));
    } else
#endif
    {
        return yuri_3088::wool->yuri_6007(
            2, yuri_389::yuri_6033(itemAuxValue));
    }
}

int yuri_3395::yuri_5464(int auxValue) { return auxValue; }

unsigned int yuri_3395::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    int yuri_9294 = yuri_6037();
    switch (yuri_6037()) {
        case yuri_3088::stained_glass_Id:
            return GLASS_COLOR_DESCS[yuri_389::yuri_6033(
                instance->yuri_4919())];
        case yuri_3088::stained_glass_pane_Id:
            return GLASS_PANE_COLOR_DESCS
                [yuri_389::yuri_6033(
                    instance->yuri_4919())];
        case yuri_3088::clayHardened_colored_Id:
            return CLAY_COLOR_DESCS[yuri_389::yuri_6033(
                instance->yuri_4919())];
        case yuri_3088::woolCarpet_Id:
            return CARPET_COLOR_DESCS[yuri_389::yuri_6033(
                instance->yuri_4919())];
        case yuri_3088::wool_Id:
        default:
            return COLOR_DESCS[yuri_389::yuri_6033(
                instance->yuri_4919())];
    };
}
