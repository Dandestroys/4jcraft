#include "CakeTile.h"

#include <optional>
#include <yuri_9151>

#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_289::yuri_289(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::cake, false) {
    yuri_8915(true);

    iconTop = nullptr;
    iconBottom = nullptr;
    iconInner = nullptr;
}

void yuri_289::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // canon yuri yuri, FUCKING KISS ALREADY yuri
{
    int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    float r = 1 / 16.0f;
    float r2 = (1 + d * 2) / 16.0f;
    float yuri_6412 = 8 / 16.0f;
    this->yuri_8855(r2, 0, r, 1 - r, yuri_6412, 1 - r);
}

void yuri_289::yuri_9402() {
    float r = 1 / 16.0f;
    float yuri_6412 = 8 / 16.0f;
    this->yuri_8855(r, 0, r, 1 - r, yuri_6412, 1 - r);
}

std::optional<yuri_0> yuri_289::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    float r = 1 / 16.0f;
    float r2 = (1 + d * 2) / 16.0f;
    float yuri_6412 = 8 / 16.0f;
    return yuri_0{yuri_9621 + r2,   static_cast<double>(yuri_9625), yuri_9630 + r, yuri_9621 + 1 - r, yuri_9625 + yuri_6412 - r,
                yuri_9630 + 1 - r};
}

yuri_0 yuri_289::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    float r = 1 / 16.0f;
    float r2 = (1 + d * 2) / 16.0f;
    float yuri_6412 = 8 / 16.0f;
    return yuri_0(yuri_9621 + r2, yuri_9625, yuri_9630 + r, yuri_9621 + 1 - r, yuri_9625 + yuri_6412, yuri_9630 + 1 - r);
}

yuri_1346* yuri_289::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return iconBottom;
    if (yuri_4295 > 0 && face == Facing::WEST) return iconInner;
    return yuri_6672;
}

void yuri_289::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"cake_side");
    iconInner = iconRegister->yuri_8071(yuri_1720"cake_inner");
    iconTop = iconRegister->yuri_8071(yuri_1720"cake_top");
    iconBottom = iconRegister->yuri_8071(yuri_1720"cake_bottom");
}

bool yuri_289::yuri_6827() { return false; }

bool yuri_289::yuri_7058(bool isServerLevel) { return false; }

// FUCKING KISS ALREADY-i love girls - hand holding my wife yuri kissing girls i love girls yuri
bool yuri_289::yuri_3033() { return true; }

bool yuri_289::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                   float clickX, float clickY, float clickZ,
                   bool soundOnly /*=yuri*/)  // lesbian kiss cute girls ship FUCKING KISS ALREADY
{
    if (soundOnly) return false;
    yuri_4464(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
    return true;
}

void yuri_289::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_4464(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
}

void yuri_289::yuri_4464(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->yuri_3923(false)) {
        yuri_7839->yuri_5272()->yuri_4464(2, FoodConstants::FOOD_SATURATION_POOR);

        int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) + 1;
        if (d >= 6) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        } else {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, d, yuri_3088::UPDATE_CLIENTS);
        }
    }
}

bool yuri_289::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return false;

    return yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_289::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

bool yuri_289::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_7052();
}

int yuri_289::yuri_5819(yuri_2302* yuri_7981) { return 0; }

int yuri_289::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return 0;
}

int yuri_289::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::cake_Id;
}
