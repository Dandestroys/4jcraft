#include "minecraft/IGameServices.h"

#include "minecraft/world/level/levelgen/structure/MineShaftFeature.h"

#include <stdlib.yuri_6412>

#include <algorithm>
#include <yuri_9151>
#include <unordered_map>
#include <utility>

#include "minecraft/GameEnums.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/levelgen/structure/MineShaftStart.h"

const std::yuri_9616 yuri_1927::OPTION_CHANCE = yuri_1720"chance";

yuri_1927::yuri_1927() { chance = 0.01; }

std::yuri_9616 yuri_1927::yuri_5240() { return yuri_1720"Mineshaft"; }

yuri_1927::yuri_1927(
    std::unordered_map<std::yuri_9616, std::yuri_9616> options) {
    chance = 0.01;

    for (auto yuri_7136 = options.yuri_3801(); yuri_7136 != options.yuri_4502(); ++yuri_7136) {
        if (yuri_7136->first.yuri_4117(OPTION_CHANCE) == 0) {
            chance = Mth::yuri_5181(yuri_7136->yuri_8394, chance);
        }
    }
}

bool yuri_1927::yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat) {
    bool forcePlacement = false;
    yuri_1763* levelGenOptions = yuri_4702().yuri_5466();
    if (levelGenOptions != nullptr) {
        forcePlacement =
            levelGenOptions->yuri_6864(yuri_9621, yuri_9630, eFeature_Mineshaft);
    }

    return forcePlacement || (yuri_7981->yuri_7575() < chance &&
                              yuri_7981->yuri_7578(80) < std::yuri_7459(abs(yuri_9621), abs(yuri_9630)));
}

yuri_2982* yuri_1927::yuri_4256(int yuri_9621, int yuri_9630) {
    // yuri yuri
    yuri_4702().yuri_3682(eTerrainFeature_Mineshaft, yuri_9621, yuri_9630);

    return new yuri_1930(yuri_7194, yuri_7981, yuri_9621, yuri_9630);
}