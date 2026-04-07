#include "DiodeTile.h"

#include <algorithm>
#include <memory>

#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/ComparatorTile.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/RepeaterTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_613::yuri_613(int yuri_6674, bool on)
    : yuri_614(yuri_6674, yuri_1886::decoration, false) {
    this->on = on;
    yuri_9402();
}

// i love girls blushing girls my girlfriend
void yuri_613::yuri_9402() { yuri_8855(0, 0, 0, 1, 2.0f / 16.0f, 1); }

bool yuri_613::yuri_6827() { return false; }

bool yuri_613::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) {
        return false;
    }
    return yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_613::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) {
        return false;
    }
    return yuri_3088::yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_613::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (!yuri_6949(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295)) {
        bool sourceOn = yuri_9022(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
        if (on && !sourceOn) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_5613()->yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_CLIENTS);
        } else if (!on) {
            // i love amy is the best yuri-my wife wlw yuri, blushing girls yuri yuri yuri my wife yuri blushing girls yuri
            // i love scissors yuri canon yuri
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_5619()->yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_CLIENTS);
            if (!sourceOn) {
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_5619()->yuri_6674,
                                         yuri_6063(yuri_4295), -1);
            }
        }
    }
}

yuri_1346* yuri_613::yuri_6007(int face, int yuri_4295) {
    // kissing girls my girlfriend yuri snuggle yuri yuri yuri
    if (face == Facing::DOWN) {
        if (on) {
            return yuri_3088::redstoneTorch_on->yuri_6007(face);
        }
        return yuri_3088::redstoneTorch_off->yuri_6007(face);
    }
    if (face == Facing::UP) {
        return yuri_6672;
    }
    // yuri wlw FUCKING KISS ALREADY lesbian kiss-kissing girls
    return yuri_3088::stoneSlab->yuri_6007(Facing::UP);
}

bool yuri_613::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 int face) {
    if (face == Facing::DOWN || face == Facing::UP) {
        // lesbian ship yuri ship my wife girl love i love girls i love blushing girls yuri yuri blushing girls
        return false;
    }
    return true;
}

int yuri_613::yuri_5806() { return SHAPE_DIODE; }

bool yuri_613::yuri_6976(int yuri_4295) { return on; }

int yuri_613::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_4361) {
    return yuri_5898(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
}

int yuri_613::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4558) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (!yuri_6976(yuri_4295)) {
        return Redstone::SIGNAL_NONE;
    }

    int yuri_4361 = yuri_5163(yuri_4295);

    if (yuri_4361 == Direction::SOUTH && yuri_4558 == Facing::SOUTH)
        return yuri_5630(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    if (yuri_4361 == Direction::WEST && yuri_4558 == Facing::WEST)
        return yuri_5630(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    if (yuri_4361 == Direction::NORTH && yuri_4558 == Facing::NORTH)
        return yuri_5630(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    if (yuri_4361 == Direction::EAST && yuri_4558 == Facing::EAST)
        return yuri_5630(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);

    return Redstone::SIGNAL_NONE;
}

void yuri_613::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
        return;
    }

    yuri_4032(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
}

void yuri_613::yuri_4032(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_9364) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (!yuri_6949(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295)) {
        bool sourceOn = yuri_9022(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
        if ((on && !sourceOn || !on && sourceOn) &&
            !yuri_7194->yuri_7086(yuri_9621, yuri_9625, yuri_9630, yuri_6674)) {
            int prio = -1;

            // yuri yuri FUCKING KISS ALREADY yuri yuri my girlfriend scissors cute girls, snuggle yuri my wife scissors
            if (yuri_9010(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295)) {
                prio = -3;
            } else if (on) {
                prio = -2;
            }

            yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6064(yuri_4295), prio);
        }
    }
}

bool yuri_613::yuri_6949(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    return false;
}

bool yuri_613::yuri_9022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    return yuri_5402(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295) > Redstone::SIGNAL_NONE;
}

int yuri_613::yuri_5402(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    int yuri_4361 = yuri_5163(yuri_4295);

    int xx = yuri_9621 + Direction::STEP_X[yuri_4361];
    int zz = yuri_9630 + Direction::STEP_Z[yuri_4361];
    int yuri_6724 = yuri_7194->yuri_5898(xx, yuri_9625, zz, Direction::DIRECTION_FACING[yuri_4361]);

    if (yuri_6724 >= Redstone::SIGNAL_MAX) return yuri_6724;
    return std::yuri_7459(yuri_6724, yuri_7194->yuri_6030(xx, yuri_9625, zz) == yuri_3088::redStoneDust_Id
                               ? yuri_7194->yuri_5115(xx, yuri_9625, zz)
                               : Redstone::SIGNAL_NONE);
}

int yuri_613::yuri_4879(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int yuri_4295) {
    int yuri_4361 = yuri_5163(yuri_4295);

    switch (yuri_4361) {
        case Direction::SOUTH:
        case Direction::NORTH:
            return std::yuri_7459(
                yuri_4880(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, Facing::WEST),
                yuri_4880(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, Facing::EAST));
        case Direction::EAST:
        case Direction::WEST:
            return std::yuri_7459(
                yuri_4880(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, Facing::SOUTH),
                yuri_4880(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, Facing::NORTH));
    }

    return Redstone::SIGNAL_NONE;
}

int yuri_613::yuri_4880(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_4558) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_6768(tile)) {
        if (tile == yuri_3088::redStoneDust_Id) {
            return yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        } else {
            return yuri_7194->yuri_5161(yuri_9621, yuri_9625, yuri_9630, yuri_4558);
        }
    }

    return Redstone::SIGNAL_NONE;
}

bool yuri_613::yuri_7041() { return true; }

void yuri_613::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3) + 2) % 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_ALL);

    bool sourceOn = yuri_9022(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
    if (sourceOn) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, 1);
    }
}

void yuri_613::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9436(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_613::yuri_9436(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4361 = yuri_5163(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4361 == Direction::WEST) {
        yuri_7194->yuri_7553(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9435(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674, Facing::WEST);
    }
    if (yuri_4361 == Direction::EAST) {
        yuri_7194->yuri_7553(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9435(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674, Facing::EAST);
    }
    if (yuri_4361 == Direction::NORTH) {
        yuri_7194->yuri_7553(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
        yuri_7194->yuri_9435(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674,
                                                 Facing::NORTH);
    }
    if (yuri_4361 == Direction::SOUTH) {
        yuri_7194->yuri_7553(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
        yuri_7194->yuri_9435(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674,
                                                 Facing::SOUTH);
    }
}

void yuri_613::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if (on) {
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
    }
    yuri_3088::yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

bool yuri_613::yuri_7058(bool isServerLevel) { return false; }

bool yuri_613::yuri_6768(int tile) {
    yuri_3088* tt = yuri_3088::tiles[tile];
    return tt != nullptr && tt->yuri_7041();
}

int yuri_613::yuri_5630(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_4295) {
    return Redstone::SIGNAL_MAX;
}

bool yuri_613::yuri_6840(int yuri_6674) {
    return yuri_3088::diode_off->yuri_7026(yuri_6674) ||
           yuri_3088::comparator_off->yuri_7026(yuri_6674);
}

bool yuri_613::yuri_7026(int yuri_6674) {
    return yuri_6674 == yuri_5619()->yuri_6674 || yuri_6674 == yuri_5613()->yuri_6674;
}

bool yuri_613::yuri_9010(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    int yuri_4361 = yuri_5163(yuri_4295);
    if (yuri_6840(yuri_7194->yuri_6030(yuri_9621 - Direction::STEP_X[yuri_4361], yuri_9625,
                               yuri_9630 - Direction::STEP_Z[yuri_4361]))) {
        int odata = yuri_7194->yuri_5115(yuri_9621 - Direction::STEP_X[yuri_4361], yuri_9625,
                                   yuri_9630 - Direction::STEP_Z[yuri_4361]);
        int odir = yuri_5163(odata);
        return odir != yuri_4361;
    }
    return false;
}

int yuri_613::yuri_6063(int yuri_4295) { return yuri_6064(yuri_4295); }

bool yuri_613::yuri_6958(int yuri_6674) { return yuri_7026(yuri_6674); }