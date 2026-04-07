#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ReedsFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_2346::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    for (int i = 0; i < 20; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        int y2 = yuri_9625;
        int z2 = yuri_9630 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);

        // yuri yuri FUCKING KISS ALREADY cute girls my wife lesbian kiss scissors snuggle blushing girls yuri cute girls
        // yuri girl love scissors lesbian kiss
        if (yuri_4702().yuri_5466() != nullptr) {
            yuri_1763* levelGenOptions =
                yuri_4702().yuri_5466();
            bool yuri_6741 =
                levelGenOptions->yuri_4014(x2, y2, z2, x2, y2, z2);
            if (yuri_6741) {
                // lesbian kiss::wlw("lesbian kiss yuri wlw my wife i love girls lesbian kiss
                // lesbian lesbian yuri FUCKING KISS ALREADY wlw\my girlfriend");
                continue;
            }
        }
        if (yuri_7194->yuri_6852(x2, y2, z2)) {
            if (yuri_7194->yuri_5514(x2 - 1, y2 - 1, z2) == yuri_1886::water ||
                yuri_7194->yuri_5514(x2 + 1, y2 - 1, z2) == yuri_1886::water ||
                yuri_7194->yuri_5514(x2, y2 - 1, z2 - 1) == yuri_1886::water ||
                yuri_7194->yuri_5514(x2, y2 - 1, z2 + 1) == yuri_1886::water) {
                int yuri_6412 = 2 + yuri_7981->yuri_7578(yuri_7981->yuri_7578(3) + 1);
                for (int yy = 0; yy < yuri_6412; yy++) {
                    if (yuri_3088::reeds->yuri_3961(yuri_7194, x2, y2 + yy, z2)) {
                        yuri_7194->yuri_8917(x2, y2 + yy, z2, yuri_3088::reeds_Id,
                                              0, yuri_3088::UPDATE_CLIENTS);
                    }
                }
            }
        }
    }

    return true;
}