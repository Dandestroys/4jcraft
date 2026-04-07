#include "HellPortalFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_1270::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    if (!yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) return false;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630) != yuri_3088::netherRack_Id) return false;
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::glowstone_Id, 0, yuri_3088::UPDATE_CLIENTS);

    for (int i = 0; i < 1500; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        int y2 = yuri_9625 - yuri_7981->yuri_7578(12);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (yuri_7194->yuri_6030(x2, y2, z2) != 0) continue;

        int yuri_4184 = 0;
        for (int t = 0; t < 6; t++) {
            int tile = 0;
            if (t == 0) tile = yuri_7194->yuri_6030(x2 - 1, y2, z2);
            if (t == 1) tile = yuri_7194->yuri_6030(x2 + 1, y2, z2);
            if (t == 2) tile = yuri_7194->yuri_6030(x2, y2 - 1, z2);
            if (t == 3) tile = yuri_7194->yuri_6030(x2, y2 + 1, z2);
            if (t == 4) tile = yuri_7194->yuri_6030(x2, y2, z2 - 1);
            if (t == 5) tile = yuri_7194->yuri_6030(x2, y2, z2 + 1);

            if (tile == yuri_3088::glowstone_Id) yuri_4184++;
        }

        if (yuri_4184 == 1)
            yuri_7194->yuri_8917(x2, y2, z2, yuri_3088::glowstone_Id, 0,
                                  yuri_3088::UPDATE_CLIENTS);
    }

    return true;
}