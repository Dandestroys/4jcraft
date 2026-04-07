#include "BookshelfTile.h"

#include "minecraft/Facing.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_217::yuri_217(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::wood) {}

yuri_1346* yuri_217::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP || face == Facing::DOWN)
        return yuri_3088::wood->yuri_6007(face);
    return yuri_3088::yuri_6007(face, yuri_4295);
}

int yuri_217::yuri_5819(yuri_2302* yuri_7981) { return 3; }

int yuri_217::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::book_Id;
}