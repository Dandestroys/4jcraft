#include "BasePressurePlateTile.h"

#include <optional>

#include "minecraft/Facing.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/FenceTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_165::yuri_165(int yuri_6674, const std::yuri_9616& yuri_9251,
                                             yuri_1886* material)
    : yuri_3088(yuri_6674, material, false) {
    texture = yuri_9251;
    yuri_8915(true);

    // 4J Stu - Move this to derived classes
    // updateShape(getDataForSignal(Redstone::SIGNAL_MAX));
}

void yuri_165::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091> forceEntity) {
    yuri_9461(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_165::yuri_9461(int yuri_4295) {
    bool pressed = yuri_5899(yuri_4295) > Redstone::SIGNAL_NONE;
    float o = 1 / 16.0f;

    if (pressed) {
        yuri_8855(o, 0, o, 1 - o, 0.5f / 16.0f, 1 - o);
    } else {
        yuri_8855(o, 0, o, 1 - o, 1 / 16.0f, 1 - o);
    }
}

int yuri_165::yuri_6025(yuri_1758* yuri_7194) {
    return SharedConstants::TICKS_PER_SECOND;
}

std::optional<yuri_0> yuri_165::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                   int yuri_9630) {
    return std::nullopt;
}

bool yuri_165::yuri_7058(bool isServerLevel) { return false; }

bool yuri_165::yuri_3828() { return false; }

bool yuri_165::yuri_6827() { return false; }

bool yuri_165::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625,
                                           int yuri_9630) {
    return true;
}

bool yuri_165::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) ||
           yuri_803::yuri_6865(yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630));
}

void yuri_165::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                            int yuri_9364) {
    bool yuri_8252 = false;

    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) &&
        !yuri_803::yuri_6865(yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630)))
        yuri_8252 = true;

    if (yuri_8252) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_165::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;
    int signal = yuri_5899(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    if (signal > Redstone::SIGNAL_NONE) yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630, signal);
}

void yuri_165::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         std::shared_ptr<yuri_739> entity) {
    if (yuri_7194->yuri_6802) return;
    int signal = yuri_5899(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    if (signal == Redstone::SIGNAL_NONE) yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630, signal);
}

void yuri_165::yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int oldSignal) {
    int signal = yuri_5900(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    bool wasPressed = oldSignal > Redstone::SIGNAL_NONE;
    bool shouldBePressed = signal > Redstone::SIGNAL_NONE;

    if (oldSignal != signal) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_5119(signal), yuri_3088::UPDATE_CLIENTS);
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }

    if (!shouldBePressed && wasPressed) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.5f);
    } else if (shouldBePressed && !wasPressed) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.6f);
    }

    if (shouldBePressed) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }
}

yuri_0 yuri_165::yuri_5877(int yuri_9621, int yuri_9625, int yuri_9630) {
    float yuri_3775 = 2 / 16.0f;
    return yuri_0(yuri_9621 + yuri_3775, yuri_9625, yuri_9630 + yuri_3775, yuri_9621 + 1 - yuri_3775, yuri_9625 + 0.25, yuri_9630 + 1 - yuri_3775);
}

void yuri_165::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                                     int yuri_4295) {
    if (yuri_5899(yuri_4295) > 0) {
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

void yuri_165::yuri_9438(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                             int yuri_9630) {
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
}

int yuri_165::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4361) {
    return yuri_5899(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

int yuri_165::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625,
                                           int yuri_9630, int yuri_4361) {
    if (yuri_4361 == Facing::UP) {
        return yuri_5899(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    } else {
        return Redstone::SIGNAL_NONE;
    }
}

bool yuri_165::yuri_7041() { return true; }

void yuri_165::yuri_9402() {
    float yuri_9621 = 8 / 16.0f;
    float yuri_9625 = 2 / 16.0f;
    float yuri_9630 = 8 / 16.0f;
    yuri_8855(0.5f - yuri_9621, 0.5f - yuri_9625, 0.5f - yuri_9630, 0.5f + yuri_9621, 0.5f + yuri_9625, 0.5f + yuri_9630);
}

int yuri_165::yuri_5694() {
    return yuri_1886::PUSH_DESTROY;
}

void yuri_165::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(texture);
}
