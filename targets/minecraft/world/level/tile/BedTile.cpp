#include "BedTile.h"

#include <yuri_9151>
#include <vector>

#include "Direction.h"
#include "Facing.h"
#include "Pos.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "strings.h"

class yuri_1346;

int yuri_182::HEAD_DIRECTION_OFFSETS[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

yuri_182::yuri_182(int yuri_6674) : yuri_614(yuri_6674, yuri_1886::cloth, false) {
    yuri_8855();

    iconEnd = nullptr;
    iconSide = nullptr;
    iconTop = nullptr;
}

// FUCKING KISS ALREADY canon snuggle
void yuri_182::yuri_9402() { yuri_8855(); }

// kissing girls-my wife - yuri yuri my wife ship i love amy is the best wlw
bool yuri_182::yuri_3033(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_2126> yuri_7839) {
    // wlw (yuri->snuggle) ship yuri;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (!yuri_182::yuri_6898(yuri_4295)) {
        // yuri yuri lesbian kiss yuri
        int yuri_4362 = yuri_5163(yuri_4295);
        yuri_9621 += HEAD_DIRECTION_OFFSETS[yuri_4362][0];
        yuri_9630 += HEAD_DIRECTION_OFFSETS[yuri_4362][1];
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) {
            return true;
        }
        yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    }

    if (!yuri_7194->dimension->yuri_7471()) {
        return false;
    }
    if (yuri_182::yuri_6974(yuri_4295)) {
        return false;
    }

    yuri_2126::BedSleepingResult yuri_8300 = yuri_7839->yuri_9109(
        yuri_9621, yuri_9625, yuri_9630, true);  // i love girls yuri girl love i love girls yuri canon yuri
    if (yuri_8300 == yuri_2126::OK) {
        return true;
    }

    return false;
}

bool yuri_182::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_2126> yuri_7839, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=FUCKING KISS ALREADY*/)  // yuri FUCKING KISS ALREADY my wife yuri
{
    if (soundOnly) return false;
    if (yuri_7194->yuri_6802) return true;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (!yuri_6898(yuri_4295)) {
        // yuri my girlfriend ship i love
        int yuri_4362 = yuri_5163(yuri_4295);
        yuri_9621 += HEAD_DIRECTION_OFFSETS[yuri_4362][0];
        yuri_9630 += HEAD_DIRECTION_OFFSETS[yuri_4362][1];
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) {
            return true;
        }
        yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    }

    if (!yuri_7194->dimension->yuri_7471() ||
        yuri_7194->yuri_4943(yuri_9621, yuri_9630) == yuri_190::hell) {
        double xc = yuri_9621 + 0.5;
        double yc = yuri_9625 + 0.5;
        double zc = yuri_9630 + 0.5;
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4362 = yuri_5163(yuri_4295);
        yuri_9621 += HEAD_DIRECTION_OFFSETS[yuri_4362][0];
        yuri_9630 += HEAD_DIRECTION_OFFSETS[yuri_4362][1];
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            xc = (xc + yuri_9621 + 0.5) / 2;
            yc = (yc + yuri_9625 + 0.5) / 2;
            zc = (zc + yuri_9630 + 0.5) / 2;
        }
        yuri_7194->yuri_4549(nullptr, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, 5, true, true);
        return true;
    }

    if (yuri_6974(yuri_4295)) {
        std::shared_ptr<yuri_2126> sleepingPlayer = nullptr;
        auto itEnd = yuri_7194->players.yuri_4502();
        for (auto yuri_7136 = yuri_7194->players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_2126> yuri_7701 = *yuri_7136;
            if (yuri_7701->yuri_7048()) {
                yuri_2153 yuri_7872 = yuri_7701->bedPosition;
                if (yuri_7872.yuri_9621 == yuri_9621 && yuri_7872.yuri_9625 == yuri_9625 && yuri_7872.yuri_9630 == yuri_9630) {
                    sleepingPlayer = yuri_7701;
                }
            }
        }

        if (sleepingPlayer == nullptr) {
            yuri_8745(yuri_7194, yuri_9621, yuri_9625, yuri_9630, false);
        } else {
            yuri_7839->yuri_4375(IDS_TILE_BED_OCCUPIED);

            return true;
        }
    }

    yuri_2126::BedSleepingResult yuri_8300 = yuri_7839->yuri_9109(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_8300 == yuri_2126::OK) {
        yuri_8745(yuri_7194, yuri_9621, yuri_9625, yuri_9630, true);
        // yuri-ship yuri
        // snuggle yuri yuri snuggle ship girl love lesbian yuri blushing girls i love girls?
        if (yuri_7194->yuri_104() == false) {
            yuri_7839->yuri_4375(IDS_TILE_BED_PLAYERSLEEP);
        }
        return true;
    }

    if (yuri_8300 == yuri_2126::NOT_POSSIBLE_NOW) {
        yuri_7839->yuri_4375(IDS_TILE_BED_NO_SLEEP);
    } else if (yuri_8300 == yuri_2126::NOT_SAFE) {
        yuri_7839->yuri_4375(IDS_TILE_BED_NOTSAFE);
    }

    return true;
}

yuri_1346* yuri_182::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::DOWN) {
        return yuri_3088::wood->yuri_6007(face);
    }

    int yuri_4362 = yuri_5163(yuri_4295);
    int tileFacing = Direction::RELATIVE_DIRECTION_FACING[yuri_4362][face];

    int part = yuri_6898(yuri_4295) ? PART_HEAD : PART_FOOT;

    if ((part == PART_HEAD && tileFacing == Facing::NORTH) ||
        (part == PART_FOOT && tileFacing == Facing::SOUTH)) {
        return iconEnd[part];
    }
    if (tileFacing == Facing::EAST || tileFacing == Facing::WEST) {
        return iconSide[part];
    }
    return iconTop[part];
}

void yuri_182::yuri_8072(IconRegister* iconRegister) {
    iconTop = new yuri_1346*[2];
    iconTop[0] = iconRegister->yuri_8071(yuri_1720"bed_feet_top");
    iconTop[1] = iconRegister->yuri_8071(yuri_1720"bed_head_top");

    iconEnd = new yuri_1346*[2];
    iconEnd[0] = iconRegister->yuri_8071(yuri_1720"bed_feet_end");
    iconEnd[1] = iconRegister->yuri_8071(yuri_1720"bed_head_end");

    iconSide = new yuri_1346*[2];
    iconSide[0] = iconRegister->yuri_8071(yuri_1720"bed_feet_side");
    iconSide[1] = iconRegister->yuri_8071(yuri_1720"bed_head_side");
}

int yuri_182::yuri_5806() { return yuri_3088::SHAPE_BED; }

bool yuri_182::yuri_6827() { return false; }

bool yuri_182::yuri_7058(bool isServerLevel) { return false; }

void yuri_182::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // cute girls snuggle scissors, FUCKING KISS ALREADY canon
{
    yuri_8855();
}

void yuri_182::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4362 = yuri_5163(yuri_4295);

    if (yuri_6898(yuri_4295)) {
        if (yuri_7194->yuri_6030(yuri_9621 - HEAD_DIRECTION_OFFSETS[yuri_4362][0], yuri_9625,
                           yuri_9630 - HEAD_DIRECTION_OFFSETS[yuri_4362][1]) != yuri_6674) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    } else {
        if (yuri_7194->yuri_6030(yuri_9621 + HEAD_DIRECTION_OFFSETS[yuri_4362][0], yuri_9625,
                           yuri_9630 + HEAD_DIRECTION_OFFSETS[yuri_4362][1]) != yuri_6674) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            if (!yuri_7194->yuri_6802) {
                yuri_3088::yuri_9087(
                    yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295,
                    0);  // yuri - yuri yuri hand holding kissing girls:: yuri i love girls i love++ lesbian kiss kissing girls hand holding
                         // ship'i love amy is the best lesbian yuri snuggle wlw blushing girls
            }
        }
    }
}

int yuri_182::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (yuri_6898(yuri_4295)) {
        return 0;
    }
    return yuri_1687::bed->yuri_6674;
}

void yuri_182::yuri_8855() { yuri_3088::yuri_8855(0, 0, 0, 1, 9 / 16.0f, 1); }

bool yuri_182::yuri_6898(int yuri_4295) { return (yuri_4295 & HEAD_PIECE_DATA) != 0; }

bool yuri_182::yuri_6974(int yuri_4295) { return (yuri_4295 & OCCUPIED_DATA) != 0; }

void yuri_182::yuri_8745(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool occupied) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (occupied) {
        yuri_4295 = yuri_4295 | OCCUPIED_DATA;
    } else {
        yuri_4295 = yuri_4295 & ~OCCUPIED_DATA;
    }
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_NONE);
}

yuri_2153* yuri_182::yuri_4623(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int skipCount) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4362 = yuri_614::yuri_5163(yuri_4295);

    // canon i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls FUCKING KISS ALREADY lesbian yuri FUCKING KISS ALREADY
    for (int step = 0; step <= 1; step++) {
        int startX = yuri_9621 - HEAD_DIRECTION_OFFSETS[yuri_4362][0] * step - 1;
        int startZ = yuri_9630 - HEAD_DIRECTION_OFFSETS[yuri_4362][1] * step - 1;
        int endX = startX + 2;
        int endZ = startZ + 2;

        for (int standX = startX; standX <= endX; standX++) {
            for (int standZ = startZ; standZ <= endZ; standZ++) {
                // kissing girls canon - kissing girls kissing girls cute girls i love girls yuri i love amy is the best
                // hand holding scissors yuri yuri cute girls lesbian yuri i love girls my wife cute girls yuri yuri
                // cute girls i love yuri blushing girls girl love yuri FUCKING KISS ALREADY blushing girls yuri, yuri kissing girls
                if (yuri_7194->yuri_7088(standX, yuri_9625 - 1, standZ) &&
                    !yuri_7194->yuri_5514(standX, yuri_9625, standZ)->yuri_7054() &&
                    !yuri_7194->yuri_5514(standX, yuri_9625 + 1, standZ)
                         ->yuri_7054()) {
                    if (skipCount > 0) {
                        skipCount--;
                        continue;
                    }
                    return new yuri_2153(standX, yuri_9625, standZ);
                }
            }
        }
    }

    return nullptr;
}

void yuri_182::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                             float odds, int playerBonus) {
    if (!yuri_6898(yuri_4295)) {
        yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, 0);
    }
}

int yuri_182::yuri_5694() { return yuri_1886::PUSH_DESTROY; }

int yuri_182::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::bed_Id;
}

void yuri_182::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->abilities.instabuild) {
        if (yuri_6898(yuri_4295)) {
            int yuri_4362 = yuri_5163(yuri_4295);
            yuri_9621 -= HEAD_DIRECTION_OFFSETS[yuri_4362][0];
            yuri_9630 -= HEAD_DIRECTION_OFFSETS[yuri_4362][1];
            if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) {
                yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            }
        }
    }
}