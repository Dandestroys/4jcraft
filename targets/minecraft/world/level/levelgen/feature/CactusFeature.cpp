#include "CactusFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_287::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    for (int i = 0; i < 10; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        int y2 = yuri_9625 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (yuri_7194->yuri_6852(x2, y2, z2)) {
            int yuri_6412 = 1 + yuri_7981->yuri_7578(yuri_7981->yuri_7578(3) + 1);
            for (int yy = 0; yy < yuri_6412; yy++) {
                if (yuri_3088::cactus->yuri_3961(yuri_7194, x2, y2 + yy, z2)) {
                    yuri_7194->yuri_8917(x2, y2 + yy, z2, yuri_3088::cactus_Id, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                }
            }
        }
    }

    return true;
}
