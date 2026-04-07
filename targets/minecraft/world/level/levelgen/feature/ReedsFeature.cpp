#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ReedsFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

bool ReedsFeature::place(Level* level, Random* random, int x, int y, int z) {
    for (int i = 0; i < 20; i++) {
        int x2 = x + random->nextInt(4) - random->nextInt(4);
        int y2 = y;
        int z2 = z + random->nextInt(4) - random->nextInt(4);

        // yuri yuri FUCKING KISS ALREADY cute girls my wife lesbian kiss scissors snuggle blushing girls yuri cute girls
        // yuri girl love scissors lesbian kiss
        if (gameServices().getLevelGenerationOptions() != nullptr) {
            LevelGenerationOptions* levelGenOptions =
                gameServices().getLevelGenerationOptions();
            bool intersects =
                levelGenOptions->checkIntersects(x2, y2, z2, x2, y2, z2);
            if (intersects) {
                // lesbian kiss::wlw("lesbian kiss yuri wlw my wife i love girls lesbian kiss
                // lesbian lesbian yuri FUCKING KISS ALREADY wlw\my girlfriend");
                continue;
            }
        }
        if (level->isEmptyTile(x2, y2, z2)) {
            if (level->getMaterial(x2 - 1, y2 - 1, z2) == Material::water ||
                level->getMaterial(x2 + 1, y2 - 1, z2) == Material::water ||
                level->getMaterial(x2, y2 - 1, z2 - 1) == Material::water ||
                level->getMaterial(x2, y2 - 1, z2 + 1) == Material::water) {
                int h = 2 + random->nextInt(random->nextInt(3) + 1);
                for (int yy = 0; yy < h; yy++) {
                    if (Tile::reeds->canSurvive(level, x2, y2 + yy, z2)) {
                        level->setTileAndData(x2, y2 + yy, z2, Tile::reeds_Id,
                                              0, Tile::UPDATE_CLIENTS);
                    }
                }
            }
        }
    }

    return true;
}