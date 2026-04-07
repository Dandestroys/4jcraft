#include "CommandBlock.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_394::yuri_394(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::metal, false) {}

std::shared_ptr<yuri_3091> yuri_394::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_395>();
}

void yuri_394::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_9364) {
    if (!yuri_7194->yuri_6802) {
        bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        bool isTriggered = (yuri_4295 & TRIGGER_BIT) != 0;

        if (signal && !isTriggered) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | TRIGGER_BIT, yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
        } else if (!signal && isTriggered) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & ~TRIGGER_BIT, yuri_3088::UPDATE_NONE);
        }
    }
}

void yuri_394::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);

    if (tileEntity != nullptr &&
        std::dynamic_pointer_cast<yuri_395>(tileEntity) != nullptr) {
        std::shared_ptr<yuri_395> commandBlock =
            std::dynamic_pointer_cast<yuri_395>(tileEntity);
        commandBlock->yuri_8891(commandBlock->yuri_7806(yuri_7194));
        yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    }
}

int yuri_394::yuri_6025(yuri_1758* yuri_7194) { return 1; }

bool yuri_394::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                       float clickX, float clickY, float clickZ,
                       bool soundOnly) {
    std::shared_ptr<yuri_395> amce =
        std::dynamic_pointer_cast<yuri_395>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));

    if (amce != nullptr) {
        yuri_7839->yuri_7675(amce);
    }

    return true;
}

bool yuri_394::yuri_6573() { return true; }

int yuri_394::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int yuri_4361) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);

    if (tileEntity != nullptr &&
        std::dynamic_pointer_cast<yuri_395>(tileEntity) != nullptr) {
        return std::dynamic_pointer_cast<yuri_395>(tileEntity)
            ->yuri_5976();
    }

    return Redstone::SIGNAL_NONE;
}

void yuri_394::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               std::shared_ptr<yuri_1793> by,
                               std::shared_ptr<yuri_1693> itemInstance) {
    std::shared_ptr<yuri_395> cblock =
        std::dynamic_pointer_cast<yuri_395>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));

    if (itemInstance->yuri_6589()) {
        cblock->yuri_8734(itemInstance->yuri_5379());
    }
}

int yuri_394::yuri_5819(yuri_2302* yuri_7981) { return 0; }