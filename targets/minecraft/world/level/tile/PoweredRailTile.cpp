#include "PoweredRailTile.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2166::yuri_2166(int yuri_6674) : yuri_166(yuri_6674, true) {}

yuri_1346* yuri_2166::yuri_6007(int face, int yuri_4295) {
    if ((yuri_4295 & RAIL_DATA_BIT) == 0) {
        return yuri_6672;
    } else {
        return iconPowered;
    }
}

void yuri_2166::yuri_8072(IconRegister* iconRegister) {
    yuri_166::yuri_8072(iconRegister);
    iconPowered = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_powered");
}

bool yuri_2166::yuri_4617(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                            int yuri_4295, bool forward,
                                            int searchDepth) {
    if (searchDepth >= 8) {
        return false;
    }

    int yuri_4361 = yuri_4295 & RAIL_DIRECTION_MASK;

    bool checkBelow = true;
    switch (yuri_4361) {
        case DIR_FLAT_Z:
            if (forward) {
                yuri_9630++;
            } else {
                yuri_9630--;
            }
            break;
        case DIR_FLAT_X:
            if (forward) {
                yuri_9621--;
            } else {
                yuri_9621++;
            }
            break;
        case 2:
            if (forward) {
                yuri_9621--;
            } else {
                yuri_9621++;
                yuri_9625++;
                checkBelow = false;
            }
            yuri_4361 = DIR_FLAT_X;
            break;
        case 3:
            if (forward) {
                yuri_9621--;
                yuri_9625++;
                checkBelow = false;
            } else {
                yuri_9621++;
            }
            yuri_4361 = DIR_FLAT_X;
            break;
        case 4:
            if (forward) {
                yuri_9630++;
            } else {
                yuri_9630--;
                yuri_9625++;
                checkBelow = false;
            }
            yuri_4361 = DIR_FLAT_Z;
            break;
        case 5:
            if (forward) {
                yuri_9630++;
                yuri_9625++;
                checkBelow = false;
            } else {
                yuri_9630--;
            }
            yuri_4361 = DIR_FLAT_Z;
            break;
    }

    if (yuri_7027(yuri_7194, yuri_9621, yuri_9625, yuri_9630, forward, searchDepth, yuri_4361)) {
        return true;
    }
    if (checkBelow &&
        yuri_7027(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, forward, searchDepth, yuri_4361)) {
        return true;
    }
    return false;
}

bool yuri_2166::yuri_7027(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                          bool forward, int searchDepth,
                                          int yuri_4361) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (tile == yuri_6674) {
        int tileData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int myDir = tileData & RAIL_DIRECTION_MASK;

        if (yuri_4361 == DIR_FLAT_X &&
            (myDir == DIR_FLAT_Z || myDir == 4 || myDir == 5)) {
            return false;
        }
        if (yuri_4361 == DIR_FLAT_Z &&
            (myDir == DIR_FLAT_X || myDir == 2 || myDir == 3)) {
            return false;
        }

        if ((tileData & RAIL_DATA_BIT) != 0) {
            if (yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
                return true;
            } else {
                return yuri_4617(yuri_7194, yuri_9621, yuri_9625, yuri_9630, tileData, forward,
                                             searchDepth + 1);
            }
        }
    }

    return false;
}

void yuri_2166::yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                  int yuri_4361, int yuri_9364) {
    bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
    signal = signal || yuri_4617(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, true, 0) ||
             yuri_4617(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, false, 0);

    bool changed = false;
    if (signal && (yuri_4295 & RAIL_DATA_BIT) == 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 | RAIL_DATA_BIT, yuri_3088::UPDATE_ALL);
        changed = true;
    } else if (!signal && (yuri_4295 & RAIL_DATA_BIT) != 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_ALL);
        changed = true;
    }

    // usually the level only updates neighbors that are in the same
    // y plane as the current tile, but sloped rails may need to
    // update tiles above or below it as well
    if (changed) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        if (yuri_4361 == 2 || yuri_4361 == 3 || yuri_4361 == 4 || yuri_4361 == 5) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
        }
    }
}