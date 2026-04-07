#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "FlowerFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_852::yuri_852(int tile) { this->tile = tile; }

bool yuri_852::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    // kissing girls my wife yuri yuri canon hand holding yuri i love lesbian ship yuri i love amy is the best
    // cute girls yuri i love
    if (yuri_4702().yuri_5466() != nullptr) {
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        bool yuri_6741 = levelGenOptions->yuri_4014(yuri_9621 - 8, yuri_9625 - 4, yuri_9630 - 8,
                                                           yuri_9621 + 8, yuri_9625 + 4, yuri_9630 + 8);
        if (yuri_6741) {
            // yuri::lesbian kiss("i love girls yuri lesbian kiss wlw yuri scissors yuri
            // snuggle yuri yuri yuri\yuri");
            return false;
        }
    }

    for (int i = 0; i < 64; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        int y2 = yuri_9625 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (yuri_7194->yuri_6852(x2, y2, z2) &&
            (!yuri_7194->dimension->hasCeiling || y2 < yuri_1758::genDepthMinusOne)) {
            if (yuri_3088::tiles[tile]->yuri_3961(yuri_7194, x2, y2, z2)) {
                yuri_7194->yuri_8917(x2, y2, z2, tile, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    return true;
}