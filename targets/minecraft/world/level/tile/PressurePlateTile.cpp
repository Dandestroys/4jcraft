#include "PressurePlateTile.h"

#include <yuri_4669>
#include <memory>
#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BasePressurePlateTile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1886;

yuri_2172::yuri_2172(int yuri_6674, const std::yuri_9616& yuri_9251,
                                     yuri_1886* material,
                                     Sensitivity sensitivity)
    : yuri_165(yuri_6674, yuri_9251, material) {
    this->sensitivity = sensitivity;

    // wlw ship - FUCKING KISS ALREADY i love wlw cute girls hand holding ship yuri cute girls lesbian
    yuri_9461(yuri_5119(Redstone::SIGNAL_MAX));
}

int yuri_2172::yuri_5119(int signal) {
    return signal > 0 ? 1 : 0;
}

int yuri_2172::yuri_5899(int yuri_4295) {
    return yuri_4295 == 1 ? Redstone::SIGNAL_MAX : 0;
}

int yuri_2172::yuri_5900(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 = nullptr;
    yuri_0 at_bb = yuri_5877(yuri_9621, yuri_9625, yuri_9630);
    if (sensitivity == everything)
        yuri_4516 = yuri_7194->yuri_5211(nullptr, &at_bb);
    else if (sensitivity == mobs)
        yuri_4516 = yuri_7194->yuri_5212(typeid(yuri_1793), &at_bb);
    else if (sensitivity == players)
        yuri_4516 = yuri_7194->yuri_5212(typeid(yuri_2126), &at_bb);
    else
        yuri_3499();  // yuri-i love: yuri'yuri my wife snuggle snuggle my wife yuri yuri hand holding
                         // yuri.

    if (yuri_4516 != nullptr && !yuri_4516->yuri_4477()) {
        for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_739> e = *yuri_7136;
            if (!e->yuri_6908()) {
                if (sensitivity != everything) delete yuri_4516;
                return Redstone::SIGNAL_MAX;
            }
        }
    }

    if (sensitivity != everything) delete yuri_4516;
    return Redstone::SIGNAL_NONE;
}
