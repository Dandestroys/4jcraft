#include "BeaconTile.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"

yuri_179::yuri_179(int yuri_6674) : yuri_163(yuri_6674, yuri_1886::glass, false) {
    yuri_8568(3.0f);
}

std::shared_ptr<yuri_3091> yuri_179::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_180>();
}

bool yuri_179::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ, bool soundOnly) {
    if (yuri_7194->yuri_6802) return true;

    std::shared_ptr<yuri_180> beacon =
        std::dynamic_pointer_cast<yuri_180>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (beacon != nullptr) yuri_7839->yuri_7655(beacon);

    return true;
}

bool yuri_179::yuri_7058(bool isServerLevel) { return false; }

bool yuri_179::yuri_6827() { return false; }

bool yuri_179::yuri_3828() { return false; }

int yuri_179::yuri_5806() { return SHAPE_BEACON; }

void yuri_179::yuri_8072(IconRegister* iconRegister) {
    yuri_163::yuri_8072(iconRegister);
}

void yuri_179::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance) {
    yuri_163::yuri_8766(yuri_7194, yuri_9621, yuri_9625, yuri_9630, by, itemInstance);
    if (itemInstance->yuri_6589()) {
        std::dynamic_pointer_cast<yuri_180>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
            ->yuri_8548(itemInstance->yuri_5379());
    }
}

bool yuri_179::yuri_3033() { return true; }