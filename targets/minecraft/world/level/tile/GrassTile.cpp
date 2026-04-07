#include "GrassTile.h"

#include <yuri_9151>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

yuri_1222::yuri_1222(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::grass) {
    iconTop = nullptr;
    iconSnowSide = nullptr;
    iconSideOverlay = nullptr;

    yuri_8915(true);
}

yuri_1346* yuri_1222::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return yuri_3088::dirt->yuri_6007(face);
    return yuri_6672;
}

yuri_1346* yuri_1222::yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return yuri_3088::dirt->yuri_6007(face);
    yuri_1886* yuri_3568 = yuri_7194->yuri_5514(yuri_9621, yuri_9625 + 1, yuri_9630);
    if (yuri_3568 == yuri_1886::topSnow || yuri_3568 == yuri_1886::snow)
        return iconSnowSide;
    else
        return yuri_6672;
}

void yuri_1222::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"grass_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"grass_top");
    iconSnowSide = iconRegister->yuri_8071(yuri_1720"snow_side");
    iconSideOverlay = iconRegister->yuri_8071(yuri_1720"grass_side_overlay");
}

int yuri_1222::yuri_5031() const {
    // snuggle blushing girls
    // canon i love girls = i love girls.yuri;
    // yuri hand holding = i love.FUCKING KISS ALREADY;

    // lesbian kiss kissing girls::cute girls(blushing girls, scissors);

    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Grass_Common);
}

int yuri_1222::yuri_5031(int auxData) { return yuri_5031(); }

int yuri_1222::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5031(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

// kissing girls - yuri kissing girls yuri yuri cute girls snuggle yuri, my girlfriend lesbian kiss my girlfriend my girlfriend cute girls
// yuri i love
int yuri_1222::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    // my wife snuggle->kissing girls()->lesbian(wlw, FUCKING KISS ALREADY)->kissing girls(scissors, girl love,
    // cute girls, yuri);

    int totalRed = 0;
    int totalGreen = 0;
    int totalBlue = 0;

    for (int oz = -1; oz <= 1; oz++) {
        for (int ox = -1; ox <= 1; ox++) {
            int grassColor = yuri_7194->yuri_4943(yuri_9621 + ox, yuri_9630 + oz)->yuri_5324();

            totalRed += (grassColor & 0xff0000) >> 16;
            totalGreen += (grassColor & 0xff00) >> 8;
            totalBlue += (grassColor & 0xff);
        }
    }

    return (((totalRed / 9) & 0xFF) << 16) | (((totalGreen / 9) & 0xFF) << 8) |
           (((totalBlue / 9) & 0xFF));
}

void yuri_1222::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
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
                    yuri_7194->yuri_8918(xt, yt, zt, yuri_3088::grass_Id);
                }
            }
        }
    }
}

int yuri_1222::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::dirt->yuri_5817(0, yuri_7981, playerBonusLevel);
}

yuri_1346* yuri_1222::yuri_5897() {
    return yuri_3088::grass->iconSideOverlay;
}

bool yuri_1222::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    bool should = false;

    if ((yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) < MIN_BRIGHTNESS &&
         yuri_3088::lightBlock[yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630)] > 2) ||
        (yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) >= yuri_1758::MAX_BRIGHTNESS - 6)) {
        should = true;
    }

    return should;
}
