#include "DetectorRailTile.h"

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/Facing.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1346;

yuri_606::yuri_606(int yuri_6674) : yuri_166(yuri_6674, true) {
    yuri_8915(true);
    icons = nullptr;
}

int yuri_606::yuri_6025(yuri_1758* yuri_7194) { return 20; }

bool yuri_606::yuri_7041() { return true; }

void yuri_606::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_739> entity) {
    if (yuri_7194->yuri_6802) {
        return;
    }

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & RAIL_DATA_BIT) != 0) {
        return;
    }

    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

void yuri_606::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & RAIL_DATA_BIT) == 0) {
        return;
    }

    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

int yuri_606::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361) {
    return (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & RAIL_DATA_BIT) != 0
               ? Redstone::SIGNAL_MAX
               : Redstone::SIGNAL_NONE;
}

int yuri_606::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4558) {
    if ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & RAIL_DATA_BIT) == 0)
        return Redstone::SIGNAL_NONE;
    return (yuri_4558 == Facing::UP) ? Redstone::SIGNAL_MAX
                                  : Redstone::SIGNAL_NONE;
}

void yuri_606::yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int currentData) {
    bool wasPressed = (currentData & RAIL_DATA_BIT) != 0;
    bool shouldBePressed = false;

    float yuri_3775 = 2 / 16.0f;
    yuri_0 yuri_7497(yuri_9621 + yuri_3775, yuri_9625, yuri_9630 + yuri_3775, yuri_9621 + yuri_3775 - yuri_3775, yuri_9625 + yuri_3775 - yuri_3775, yuri_9630 + 1 - yuri_3775);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5212(typeid(yuri_1931), &yuri_7497);
    if (!yuri_4516->yuri_4477()) {
        shouldBePressed = true;
    }

    if (shouldBePressed && !wasPressed) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, currentData | RAIL_DATA_BIT, yuri_3088::UPDATE_ALL);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }
    if (!shouldBePressed && wasPressed) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, currentData & RAIL_DIRECTION_MASK,
                       yuri_3088::UPDATE_ALL);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }

    if (shouldBePressed) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }

    yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);

    delete yuri_4516;
}

void yuri_606::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_166::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_606::yuri_6573() { return true; }

int yuri_606::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                            int yuri_4361) {
    if ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & RAIL_DATA_BIT) > 0) {
        float yuri_3775 = 2 / 16.0f;
        yuri_0 yuri_7498(yuri_9621 + yuri_3775, yuri_9625, yuri_9630 + yuri_3775, yuri_9621 + 1 - yuri_3775, yuri_9625 + 1 - yuri_3775, yuri_9630 + 1 - yuri_3775);
        std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
            yuri_7194->yuri_5212(
                typeid(yuri_1931), &yuri_7498,
                yuri_747::CONTAINER_ENTITY_SELECTOR);

        if (yuri_4516->yuri_9050() > 0) {
            std::shared_ptr<yuri_739> yuri_7687 = yuri_4516->yuri_3753(0);
            delete yuri_4516;
            return yuri_47::yuri_5795(
                std::dynamic_pointer_cast<yuri_436>(yuri_7687));
        }
    }

    return Redstone::SIGNAL_NONE;
}

void yuri_606::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[2];
    icons[0] = iconRegister->yuri_8071(yuri_1720"detectorRail");
    icons[1] = iconRegister->yuri_8071(yuri_1720"detectorRail_on");
}

yuri_1346* yuri_606::yuri_6007(int face, int yuri_4295) {
    if ((yuri_4295 & RAIL_DATA_BIT) != 0) {
        return icons[1];
    }
    return icons[0];
}
