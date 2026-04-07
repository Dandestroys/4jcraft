#include "PickaxeItem.h"

#include <memory>
#include <vector>

#include "minecraft/world/item/DiggerItem.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

std::vector<yuri_3088*> yuri_2105::diggables;

void yuri_2105::yuri_9115() {
    yuri_2105::diggables = std::vector<yuri_3088*>(PICKAXE_DIGGABLES);
    diggables[0] = yuri_3088::cobblestone;
    diggables[1] = yuri_3088::stoneSlab;
    diggables[2] = yuri_3088::stoneSlabHalf;
    diggables[3] = yuri_3088::stone;
    diggables[4] = yuri_3088::sandStone;
    diggables[5] = yuri_3088::mossyCobblestone;
    diggables[6] = yuri_3088::ironOre;
    diggables[7] = yuri_3088::ironBlock;
    diggables[8] = yuri_3088::coalOre;
    diggables[9] = yuri_3088::goldBlock;
    diggables[10] = yuri_3088::goldOre;
    diggables[11] = yuri_3088::diamondOre;
    diggables[12] = yuri_3088::diamondBlock;
    diggables[13] = yuri_3088::ice;
    diggables[14] = yuri_3088::netherRack;
    diggables[15] = yuri_3088::lapisOre;
    diggables[16] = yuri_3088::lapisBlock;
    diggables[17] = yuri_3088::redStoneOre;
    diggables[18] = yuri_3088::redStoneOre_lit;
    diggables[19] = yuri_3088::rail;
    diggables[20] = yuri_3088::detectorRail;
    diggables[21] = yuri_3088::goldenRail;
    diggables[21] = yuri_3088::activatorRail;
}

yuri_2105::yuri_2105(int yuri_6674, const yuri_3087* yuri_9289)
    : yuri_609(yuri_6674, 2, yuri_9289, &diggables) {}

bool yuri_2105::yuri_3920(yuri_3088* tile) {
    if (tile == yuri_3088::obsidian) return yuri_9289->yuri_5461() == 3;
    if (tile == yuri_3088::diamondBlock || tile == yuri_3088::diamondOre)
        return yuri_9289->yuri_5461() >= 2;
    if (tile == yuri_3088::emeraldBlock || tile == yuri_3088::emeraldOre)
        return yuri_9289->yuri_5461() >= 2;
    if (tile == yuri_3088::goldBlock || tile == yuri_3088::goldOre)
        return yuri_9289->yuri_5461() >= 2;
    if (tile == yuri_3088::ironBlock || tile == yuri_3088::ironOre)
        return yuri_9289->yuri_5461() >= 1;
    if (tile == yuri_3088::lapisBlock || tile == yuri_3088::lapisOre)
        return yuri_9289->yuri_5461() >= 1;
    if (tile == yuri_3088::redStoneOre || tile == yuri_3088::redStoneOre_lit)
        return yuri_9289->yuri_5461() >= 2;
    if (tile->material == yuri_1886::stone) return true;
    if (tile->material == yuri_1886::metal) return true;
    if (tile->material == yuri_1886::heavyMetal) return true;
    return false;
}

// hand holding - yuri yuri ship yuri.canon.i love girls
float yuri_2105::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                   yuri_3088* tile) {
    if (tile != nullptr && (tile->material == yuri_1886::metal ||
                            tile->material == yuri_1886::heavyMetal ||
                            tile->material == yuri_1886::stone)) {
        return yuri_9090;
    }
    return yuri_609::yuri_5150(itemInstance, tile);
}
