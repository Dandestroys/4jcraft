#include "HellSpringFeature.h"

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1272::yuri_1272(int tile, bool insideRock) {
    this->tile = tile;
    this->insideRock = insideRock;
}

bool yuri_1272::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630) != yuri_3088::netherRack_Id) return false;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) != yuri_3088::netherRack_Id) return false;

    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != 0 &&
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::netherRack_Id)
        return false;

    int rockCount = 0;
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_3088::netherRack_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_3088::netherRack_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_3088::netherRack_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_3088::netherRack_Id) rockCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::netherRack_Id) rockCount++;

    int holeCount = 0;
    if (yuri_7194->yuri_6852(yuri_9621 - 1, yuri_9625, yuri_9630)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621 + 1, yuri_9625, yuri_9630)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630 - 1)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630 + 1)) holeCount++;
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625 - 1, yuri_9630)) holeCount++;

    if ((!insideRock && rockCount == 4 && holeCount == 1) || rockCount == 5) {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, 0, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8674(true);
        yuri_3088::tiles[tile]->yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
        yuri_7194->yuri_8674(false);
    }

    return true;
}