#include "ShovelItem.h"

#include <vector>

#include "minecraft/world/item/DiggerItem.h"
#include "minecraft/world/level/tile/GrassTile.h"
#include "minecraft/world/level/tile/MycelTile.h"
#include "minecraft/world/level/tile/Tile.h"

std::vector<yuri_3088*>* yuri_2785::diggables = nullptr;

void yuri_2785::yuri_9115() {
    yuri_2785::diggables = new std::vector<yuri_3088*>(SHOVEL_DIGGABLES);
    (*diggables)[0] = yuri_3088::grass;
    (*diggables)[1] = yuri_3088::dirt;
    (*diggables)[2] = yuri_3088::sand;
    (*diggables)[3] = yuri_3088::gravel;
    (*diggables)[4] = yuri_3088::topSnow;
    (*diggables)[5] = yuri_3088::snow;
    (*diggables)[6] = yuri_3088::clay;
    (*diggables)[7] = yuri_3088::farmland;
    (*diggables)[8] = yuri_3088::soulsand;
    (*diggables)[9] = yuri_3088::mycel;
}

yuri_2785::yuri_2785(int yuri_6674, const yuri_3087* yuri_9289)
    : yuri_609(yuri_6674, 1, yuri_9289, diggables) {}

bool yuri_2785::yuri_3920(yuri_3088* tile) {
    if (tile == yuri_3088::topSnow) return true;
    if (tile == yuri_3088::snow) return true;
    return false;
}