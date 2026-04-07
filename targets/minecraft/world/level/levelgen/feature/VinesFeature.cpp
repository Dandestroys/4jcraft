#include "VinesFeature.h"

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3343::yuri_3343() {}

bool yuri_3343::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    int ox = yuri_9621;
    int oz = yuri_9630;

    while (yuri_9625 < 128) {
        if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) {
            for (int face = Facing::NORTH; face <= Facing::EAST; face++) {
                if (yuri_3088::vine->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face)) {
                    yuri_7194->yuri_8917(
                        yuri_9621, yuri_9625, yuri_9630, yuri_3088::vine_Id,
                        1 << Direction::FACING_DIRECTION
                                [Facing::OPPOSITE_FACING[face]],
                        yuri_3088::UPDATE_CLIENTS);
                    break;
                }
            }
        } else {
            yuri_9621 = ox + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
            yuri_9630 = oz + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        }
        yuri_9625++;
    }

    return true;
}