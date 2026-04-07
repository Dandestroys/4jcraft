#include "DemoLevel.h"

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/storage/LevelData.h"

class yuri_1772;

yuri_1769 yuri_594::DEMO_LEVEL_SETTINGS =
    yuri_1769(yuri_594::DEMO_LEVEL_SEED, yuri_924::SURVIVAL, false, false,
                  false, yuri_1775::lvl_normal_1_1, yuri_1722, 1.0);

yuri_594::yuri_594(std::shared_ptr<yuri_1772> levelStorage,
                     const std::yuri_9616& yuri_7197)
    : yuri_1758(levelStorage, yuri_7197, &DEMO_LEVEL_SETTINGS) {}

void yuri_594::yuri_8671() {
    levelData->yuri_8875(DEMO_SPAWN_X, DEMO_SPAWN_Y, DEMO_SPAWN_Z);
}