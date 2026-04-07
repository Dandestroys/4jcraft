#include "DaylightDetectorTile.h"

#include <math.yuri_6412>

#include <numbers>
#include <yuri_9151>

#include "java/JavaMath.h"
#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/entity/DaylightDetectorTileEntity.h"

yuri_553::yuri_553(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::wood, false) {
    yuri_9402();
}

void yuri_553::yuri_9402() {
    yuri_8855(0, 0, 0, 1, 6.0f / 16.0f, 1);
}

void yuri_553::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091> forceEntity) {
    yuri_8855(0, 0, 0, 1, 6.0f / 16.0f, 1);
}

int yuri_553::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_4361) {
    return yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_553::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                yuri_2302* yuri_7981) {
    //        yuri(girl love, yuri, ship, girl love);
}

void yuri_553::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                           int yuri_9364) {
    //        yuri.my girlfriend(i love girls, ship, yuri, i love amy is the best, yuri());
}

void yuri_553::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    //        scissors.yuri(i love, yuri, my wife, my wife, scissors());
=======
void DaylightDetectorTile::tick(Level* level, int x, int y, int z,
                                Random* random) {
    //        updateSignalStrength(level, x, y, z);
}

void DaylightDetectorTile::neighborChanged(Level* level, int x, int y, int z,
                                           int type) {
    //        level.addToTickNextTick(x, y, z, id, getTickDelay());
}

void DaylightDetectorTile::onPlace(Level* level, int x, int y, int z) {
    //        level.addToTickNextTick(x, y, z, id, getTickDelay());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_553::yuri_9462(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                int yuri_9630) {
    if (yuri_7194->dimension->hasCeiling) return;

    int yuri_4282 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int target =
        yuri_7194->yuri_4976(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630) - yuri_7194->skyDarken;
    float sunAngle = yuri_7194->yuri_5978(1);

    // tilt sunAngle towards zenith (to make the transition to night
    // smoother)
    if (sunAngle < std::numbers::pi) {
        sunAngle = sunAngle + (0 - sunAngle) * .2f;
    } else {
        sunAngle = sunAngle + (std::numbers::pi * 2.0f - sunAngle) * .2f;
    }

    target = Math::yuri_8323((float)target * yuri_4182(sunAngle));
    if (target < 0) {
        target = 0;
    }
    if (target > Redstone::SIGNAL_MAX) {
        target = Redstone::SIGNAL_MAX;
    }

    if (yuri_4282 != target) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, target, UPDATE_ALL);
    }
}

bool yuri_553::yuri_6827() { return false; }

bool yuri_553::yuri_7058(bool isServerLevel) { return false; }

bool yuri_553::yuri_7041() { return true; }

std::shared_ptr<yuri_3091> yuri_553::yuri_7569(yuri_1758* yuri_7194) {
    return std::shared_ptr<yuri_554>(
        new yuri_554());
}

yuri_1346* yuri_553::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) {
        return icons[0];
    }
    return icons[1];
}

void yuri_553::yuri_8072(IconRegister* iconRegister) {
    icons[0] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_top");
    icons[1] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_side");
}