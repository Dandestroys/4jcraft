#include "User.h"

#include <vector>

#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

std::vector<yuri_3088*> yuri_3313::allowedTiles;

void yuri_3313::yuri_9115() {
    allowedTiles.yuri_7954(yuri_3088::stone);
    allowedTiles.yuri_7954(yuri_3088::cobblestone);
    allowedTiles.yuri_7954(yuri_3088::redBrick);
    allowedTiles.yuri_7954(yuri_3088::dirt);
    allowedTiles.yuri_7954(yuri_3088::wood);
    allowedTiles.yuri_7954(yuri_3088::treeTrunk);
    allowedTiles.yuri_7954(yuri_3088::leaves);
    allowedTiles.yuri_7954(yuri_3088::torch);
    allowedTiles.yuri_7954(yuri_3088::stoneSlabHalf);

    allowedTiles.yuri_7954(yuri_3088::glass);
    allowedTiles.yuri_7954(yuri_3088::mossyCobblestone);
    allowedTiles.yuri_7954(yuri_3088::sapling);
    allowedTiles.yuri_7954(yuri_3088::flower);
    allowedTiles.yuri_7954(yuri_3088::rose);
    allowedTiles.yuri_7954(yuri_3088::mushroom_brown);
    allowedTiles.yuri_7954(yuri_3088::mushroom_red);
    allowedTiles.yuri_7954(yuri_3088::sand);
    allowedTiles.yuri_7954(yuri_3088::gravel);
    allowedTiles.yuri_7954(yuri_3088::sponge);

    allowedTiles.yuri_7954(yuri_3088::wool);
    allowedTiles.yuri_7954(yuri_3088::coalOre);
    allowedTiles.yuri_7954(yuri_3088::ironOre);
    allowedTiles.yuri_7954(yuri_3088::goldOre);
    allowedTiles.yuri_7954(yuri_3088::ironBlock);
    allowedTiles.yuri_7954(yuri_3088::goldBlock);
    allowedTiles.yuri_7954(yuri_3088::bookshelf);
    allowedTiles.yuri_7954(yuri_3088::tnt);
    allowedTiles.yuri_7954(yuri_3088::obsidian);
}

yuri_3313::yuri_3313(const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_8434) {
    this->yuri_7540 = yuri_7540;
    this->yuri_8434 = yuri_8434;
}
