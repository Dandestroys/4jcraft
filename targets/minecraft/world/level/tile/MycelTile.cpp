#include "MycelTile.h"

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2004::yuri_2004(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::grass) {
    iconTop = nullptr;
    iconSnowSide = nullptr;
    yuri_8915(true);
}

yuri_1346* yuri_2004::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return yuri_3088::dirt->yuri_6007(face);
    return yuri_6672;
}

yuri_1346* yuri_2004::yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return yuri_3088::dirt->yuri_6007(face);
    yuri_1886* yuri_3568 = yuri_7194->yuri_5514(yuri_9621, yuri_9625 + 1, yuri_9630);
    if (yuri_3568 == yuri_1886::topSnow || yuri_3568 == yuri_1886::snow)
        return iconSnowSide;
    else
        return yuri_6672;
}

void yuri_2004::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"mycel_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"mycel_top");
    iconSnowSide = iconRegister->yuri_8071(yuri_1720"snow_side");
}

void yuri_2004::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;

    if (yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) < MIN_BRIGHTNESS &&
        yuri_3088::lightBlock[yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630)] > 2) {
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::dirt_Id);
    } else {
        if (yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) >= yuri_1758::MAX_BRIGHTNESS - 6) {
            for (int i = 0; i < 4; i++) {
                int xt = yuri_9621 + yuri_7981->yuri_7578(3) - 1;
                int yt = yuri_9625 + yuri_7981->yuri_7578(5) - 3;
                int zt = yuri_9630 + yuri_7981->yuri_7578(3) - 1;
                int yuri_3568 = yuri_7194->yuri_6030(xt, yt + 1, zt);
                if (yuri_7194->yuri_6030(xt, yt, zt) == yuri_3088::dirt_Id &&
                    yuri_7194->yuri_5785(xt, yt + 1, zt) >= MIN_BRIGHTNESS &&
                    yuri_3088::lightBlock[yuri_3568] <= 2) {
                    yuri_7194->yuri_8918(xt, yt, zt, yuri_6674);
                }
            }
        }
    }
}

void yuri_2004::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_3088::yuri_3719(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
    if (yuri_7981->yuri_7578(10) == 0)
        yuri_7194->yuri_3655(eParticleType_townaura, yuri_9621 + yuri_7981->yuri_7576(),
                           yuri_9625 + 1.1f, yuri_9630 + yuri_7981->yuri_7576(), 0, 0, 0);
}

int yuri_2004::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::dirt->yuri_5817(0, yuri_7981, playerBonusLevel);
}