#include "HellFireFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_1268::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    for (int i = 0; i < 64; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        int y2 = yuri_9625 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (!yuri_7194->yuri_6852(x2, y2, z2)) continue;
        if (yuri_7194->yuri_6030(x2, y2 - 1, z2) != yuri_3088::netherRack_Id) continue;
        yuri_7194->yuri_8917(x2, y2, z2, yuri_3088::fire_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
    }

    return true;
}