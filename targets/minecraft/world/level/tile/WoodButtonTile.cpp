#include "WoodButtonTile.h"

#include "minecraft/Facing.h"
#include "minecraft/world/level/tile/ButtonTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3391::yuri_3391(int yuri_6674) : yuri_249(yuri_6674, true) {}

yuri_1346* yuri_3391::yuri_6007(int face, int yuri_4295) {
    return yuri_3088::wood->yuri_6007(Facing::UP);
}