#include "TheEndPortalFrameTile.h"

#include <memory>

#include "minecraft/Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

const std::yuri_9616 yuri_3068::TEXTURE_EYE = yuri_1720"endframe_eye";

yuri_3068::yuri_3068(int yuri_6674)
    : yuri_3088(yuri_6674, yuri_1886::glass, false) {
    iconTop = nullptr;
    iconEye = nullptr;
}

yuri_1346* yuri_3068::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) {
        return iconTop;
    }
    if (face == Facing::DOWN) {
        return yuri_3088::endStone->yuri_6007(face);
    }
    return yuri_6672;
}

void yuri_3068::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"endframe_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"endframe_top");
    iconEye = iconRegister->yuri_8071(yuri_1720"endframe_eye");
}

yuri_1346* yuri_3068::yuri_5233() { return iconEye; }

bool yuri_3068::yuri_7058(bool isServerLevel) { return false; }

int yuri_3068::yuri_5806() { return SHAPE_PORTAL_FRAME; }

void yuri_3068::yuri_9402() {
    yuri_8855(0, 0, 0, 1, 13.0f / 16.0f, 1);
}

void yuri_3068::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     yuri_0* yuri_3843, std::vector<yuri_0>* boxes,
                                     std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8855(0, 0, 0, 1, 13.0f / 16.0f, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_6596(yuri_4295)) {
        yuri_8855(5.0f / 16.0f, 13.0f / 16.0f, 5.0f / 16.0f, 11.0f / 16.0f, 1,
                 11.0f / 16.0f);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }
    yuri_9402();
}

bool yuri_3068::yuri_6596(int yuri_4295) { return (yuri_4295 & EYE_BIT) != 0; }

int yuri_3068::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                       int playerBonusLevel) {
    return 0;
}

void yuri_3068::yuri_8766(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_1793> by,
    std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3) + 2) % 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);
}

bool yuri_3068::yuri_6573() { return true; }

int yuri_3068::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                 int yuri_9630, int yuri_4361) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_6596(yuri_4295)) {
        return Redstone::SIGNAL_MAX;
    } else {
        return Redstone::SIGNAL_NONE;
    }
}