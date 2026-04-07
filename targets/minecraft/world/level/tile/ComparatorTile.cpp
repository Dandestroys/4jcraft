#include "ComparatorTile.h"

#include <algorithm>

#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/DiodeTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ComparatorTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class yuri_2302;

yuri_397::yuri_397(int yuri_6674, bool on) : yuri_613(yuri_6674, on) {
    _isEntityTile = true;
}

int yuri_397::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                int playerBonusLevel) {
    return yuri_1687::comparator_Id;
}

int yuri_397::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::comparator_Id;
}

int yuri_397::yuri_6064(int yuri_4295) { return 2; }

yuri_613* yuri_397::yuri_5619() { return yuri_3088::comparator_on; }

yuri_613* yuri_397::yuri_5613() { return yuri_3088::comparator_off; }

int yuri_397::yuri_5806() { return SHAPE_COMPARATOR; }

<<<<<<< HEAD
yuri_1346* yuri_397::yuri_6007(int face, int yuri_4295) {
    bool yuri_6976 = on || (yuri_4295 & BIT_IS_LIT) != 0;
    // hand holding canon my wife yuri lesbian kiss girl love yuri
=======
Icon* ComparatorTile::getTexture(int face, int data) {
    bool isOn = on || (data & BIT_IS_LIT) != 0;
    // down is used by the torch tesselator
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (face == Facing::DOWN) {
        if (yuri_6976) {
            return yuri_3088::redstoneTorch_on->yuri_6007(face);
        }
        return yuri_3088::redstoneTorch_off->yuri_6007(face);
    }
    if (face == Facing::UP) {
        if (yuri_6976) {
            return yuri_3088::comparator_on->yuri_6672;
        }
        return yuri_6672;
    }
<<<<<<< HEAD
    // yuri yuri cute girls yuri-yuri
    return yuri_3088::stoneSlab->yuri_6007(Facing::UP);
=======
    // edge of stone half-step
    return Tile::stoneSlab->getTexture(Facing::UP);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_397::yuri_6976(int yuri_4295) { return on || (yuri_4295 & BIT_IS_LIT) != 0; }

int yuri_397::yuri_5630(yuri_1771* levelSource, int yuri_9621, int yuri_9625,
                                    int yuri_9630, int yuri_4295) {
    return yuri_5042(levelSource, yuri_9621, yuri_9625, yuri_9630)->yuri_5630();
}

int yuri_397::yuri_3896(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                          int yuri_4295) {
    if (!yuri_7015(yuri_4295)) {
        return yuri_5402(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    } else {
        return std::yuri_7459(yuri_5402(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295) -
                            yuri_4879(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295),
                        Redstone::SIGNAL_NONE);
    }
}

bool yuri_397::yuri_7015(int yuri_4295) {
    return (yuri_4295 & BIT_OUTPUT_SUBTRACT) == BIT_OUTPUT_SUBTRACT;
}

bool yuri_397::yuri_9022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    int yuri_6724 = yuri_5402(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    if (yuri_6724 >= Redstone::SIGNAL_MAX) return true;
    if (yuri_6724 == Redstone::SIGNAL_NONE) return false;

    int alt = yuri_4879(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    if (alt == Redstone::SIGNAL_NONE) return true;

    return yuri_6724 >= alt;
}

int yuri_397::yuri_5402(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_4295) {
    int yuri_8300 = yuri_613::yuri_5402(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);

    int yuri_4361 = yuri_5163(yuri_4295);
    int xx = yuri_9621 + Direction::STEP_X[yuri_4361];
    int zz = yuri_9630 + Direction::STEP_Z[yuri_4361];
    int tile = yuri_7194->yuri_6030(xx, yuri_9625, zz);

    if (tile > 0) {
        if (yuri_3088::tiles[tile]->yuri_6573()) {
            yuri_8300 = yuri_3088::tiles[tile]->yuri_4886(
                yuri_7194, xx, yuri_9625, zz, Direction::DIRECTION_OPPOSITE[yuri_4361]);
        } else if (yuri_8300 < Redstone::SIGNAL_MAX &&
                   yuri_3088::yuri_7055(tile)) {
            xx += Direction::STEP_X[yuri_4361];
            zz += Direction::STEP_Z[yuri_4361];
            tile = yuri_7194->yuri_6030(xx, yuri_9625, zz);

            if (tile > 0 && yuri_3088::tiles[tile]->yuri_6573()) {
                yuri_8300 = yuri_3088::tiles[tile]->yuri_4886(
                    yuri_7194, xx, yuri_9625, zz, Direction::DIRECTION_OPPOSITE[yuri_4361]);
            }
        }
    }

    return yuri_8300;
}

std::shared_ptr<yuri_398> yuri_397::yuri_5042(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::dynamic_pointer_cast<yuri_398>(
        yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_397::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                         float clickX, float clickY, float clickZ,
                         bool soundOnly) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool yuri_6976 = on || ((yuri_4295 & BIT_IS_LIT) != 0);
    bool subtract = !yuri_7015(yuri_4295);
    int outputBit = subtract ? BIT_OUTPUT_SUBTRACT : 0;
    outputBit |= yuri_6976 ? BIT_IS_LIT : 0;

    yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK, 0.3f,
                     subtract ? 0.55f : 0.5f);

    if (!soundOnly) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, outputBit | (yuri_4295 & DIRECTION_MASK),
                       yuri_3088::UPDATE_CLIENTS);
        yuri_8065(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_7981);
    }

    return true;
}

void yuri_397::yuri_4032(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int yuri_9364) {
    if (!yuri_7194->yuri_7086(yuri_9621, yuri_9625, yuri_9630, yuri_6674)) {
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int outputValue = yuri_3896(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
        int oldValue = yuri_5042(yuri_7194, yuri_9621, yuri_9625, yuri_9630)->yuri_5630();

        if (outputValue != oldValue ||
<<<<<<< HEAD
            (yuri_6976(yuri_4295) != yuri_9022(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295))) {
            // yuri yuri i love
            if (yuri_9010(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6064(0), -1);
=======
            (isOn(data) != shouldTurnOn(level, x, y, z, data))) {
            // prioritize locking comparators
            if (shouldPrioritize(level, x, y, z, data)) {
                level->addToTickNextTick(x, y, z, id, getTurnOnDelay(0), -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6064(0), 0);
            }
        }
    }
}

void yuri_397::yuri_8065(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        yuri_2302* yuri_7981) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int outputValue = yuri_3896(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    int oldValue = yuri_5042(yuri_7194, yuri_9621, yuri_9625, yuri_9630)->yuri_5630();
    yuri_5042(yuri_7194, yuri_9621, yuri_9625, yuri_9630)->yuri_8754(outputValue);

    if (oldValue != outputValue || !yuri_7015(yuri_4295)) {
        bool sourceOn = yuri_9022(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
        bool yuri_6976 = on || (yuri_4295 & BIT_IS_LIT) != 0;
        if (yuri_6976 && !sourceOn) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & ~BIT_IS_LIT, yuri_3088::UPDATE_CLIENTS);
        } else if (!yuri_6976 && sourceOn) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | BIT_IS_LIT, yuri_3088::UPDATE_CLIENTS);
        }
        yuri_9436(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_397::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (on) {
<<<<<<< HEAD
        // yuri-yuri yuri yuri lesbian FUCKING KISS ALREADY 'hand holding' hand holding
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_5613()->yuri_6674, yuri_4295 | BIT_IS_LIT,
                              yuri_3088::UPDATE_NONE);
=======
        // clean-up old tiles with the 'on' id
        int data = level->getData(x, y, z);
        level->setTileAndData(x, y, z, getOffTile()->id, data | BIT_IS_LIT,
                              Tile::UPDATE_NONE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_8065(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
}

void yuri_397::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_613::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_7194->yuri_8921(yuri_9621, yuri_9625, yuri_9630, yuri_7569(yuri_7194));
}

void yuri_397::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                              int yuri_4295) {
    yuri_613::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
    yuri_7194->yuri_8148(yuri_9621, yuri_9625, yuri_9630);

    yuri_9436(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_397::yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0,
                                  int b1) {
    yuri_613::yuri_9342(yuri_7194, yuri_9621, yuri_9625, yuri_9630, b0, b1);
    std::shared_ptr<yuri_3091> te = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    if (te != nullptr) {
        return te->yuri_9342(b0, b1);
    }
    return false;
}

std::shared_ptr<yuri_3091> yuri_397::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_398>();
}

bool yuri_397::yuri_3033() { return true; }