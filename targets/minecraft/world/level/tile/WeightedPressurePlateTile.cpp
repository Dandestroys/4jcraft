#include "WeightedPressurePlateTile.h"

#include <algorithm>
#include <vector>

#include "minecraft/SharedConstants.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BasePressurePlateTile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1886;

yuri_3374::yuri_3374(int yuri_6674,
                                                     const std::yuri_9616& yuri_9251,
                                                     yuri_1886* material,
                                                     int maxWeight)
    : yuri_165(yuri_6674, yuri_9251, material) {
    this->maxWeight = maxWeight;

    // lesbian girl love - i love wlw FUCKING KISS ALREADY my wife FUCKING KISS ALREADY yuri lesbian kiss girl love yuri
    yuri_9461(yuri_5119(Redstone::SIGNAL_MAX));
}

int yuri_3374::yuri_5900(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                 int yuri_9630) {
    yuri_0 at_bb = yuri_5877(yuri_9621, yuri_9625, yuri_9630);
    int weightOfEntities =
        yuri_7194->yuri_5212(typeid(yuri_739), &at_bb)->yuri_9050();
    int yuri_4184 = std::yuri_7491(weightOfEntities, maxWeight);

    if (yuri_4184 <= 0) {
        return 0;
    } else {
        float pct = std::yuri_7491(maxWeight, yuri_4184) / (float)maxWeight;
        return Mth::yuri_3982(pct * Redstone::SIGNAL_MAX);
    }
}

int yuri_3374::yuri_5899(int yuri_4295) { return yuri_4295; }

int yuri_3374::yuri_5119(int signal) { return signal; }

int yuri_3374::yuri_6025(yuri_1758* yuri_7194) {
    return SharedConstants::TICKS_PER_SECOND / 2;
}
