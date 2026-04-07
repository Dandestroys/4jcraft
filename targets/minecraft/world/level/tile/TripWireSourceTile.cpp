#include "TripWireSourceTile.h"

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TripWireTile.h"
#include "minecraft/world/phys/AABB.h"
#include "optional"

yuri_3141::yuri_3141(int yuri_6674)
    : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    this->yuri_8915(true);
}

std::optional<yuri_0> yuri_3141::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                int yuri_9630) {
    return std::nullopt;
}

bool yuri_3141::yuri_3828() { return false; }

bool yuri_3141::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3141::yuri_6827() { return false; }

int yuri_3141::yuri_5806() { return yuri_3088::SHAPE_TRIPWIRE_SOURCE; }

int yuri_3141::yuri_6025(yuri_1758* yuri_7194) { return 10; }

bool yuri_3141::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == Facing::NORTH && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1))
        return true;
    if (face == Facing::SOUTH && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1))
        return true;
    if (face == Facing::WEST && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630))
        return true;
    if (face == Facing::EAST && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630))
        return true;
    return false;
}

bool yuri_3141::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) {
        return true;
    }
    return false;
}

int yuri_3141::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                 int yuri_9630, int face, float clickX,
                                                 float clickY, float clickZ,
                                                 int itemValue) {
    int yuri_4361 = 0;

    if (face == Facing::NORTH &&
        yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 + 1, true))
        yuri_4361 = Direction::NORTH;
    if (face == Facing::SOUTH &&
        yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 - 1, true))
        yuri_4361 = Direction::SOUTH;
    if (face == Facing::WEST &&
        yuri_7194->yuri_7056(yuri_9621 + 1, yuri_9625, yuri_9630, true))
        yuri_4361 = Direction::WEST;
    if (face == Facing::EAST &&
        yuri_7194->yuri_7056(yuri_9621 - 1, yuri_9625, yuri_9630, true))
        yuri_4361 = Direction::EAST;

    return yuri_4361;
}

void yuri_3141::yuri_4593(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                           int yuri_4295) {
    yuri_3897(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295, false, -1, 0);
}

void yuri_3141::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int yuri_9364) {
    if (yuri_9364 == this->yuri_6674) return;
    if (yuri_3997(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4361 = yuri_4295 & MASK_DIR;
        bool yuri_8252 = false;

        if (!yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630) && yuri_4361 == Direction::EAST)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630) && yuri_4361 == Direction::WEST)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1) && yuri_4361 == Direction::SOUTH)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1) && yuri_4361 == Direction::NORTH)
            yuri_8252 = true;

        if (yuri_8252) {
            yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

<<<<<<< HEAD
void yuri_3141::yuri_3897(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295, bool canUpdate,
    /*wlw-lesbian, yuri blushing girls yuri kissing girls lesbian 'yuri' -->*/
=======
void TripWireSourceTile::calculateState(
    Level* level, int x, int y, int z, int id, int data, bool canUpdate,
    /*4J-Jev, these parameters only used with 'updateSource' -->*/
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int wireSource, int wireSourceData) {
    int yuri_4361 = yuri_4295 & MASK_DIR;
    bool wasAttached = (yuri_4295 & MASK_ATTACHED) == MASK_ATTACHED;
    bool wasPowered = (yuri_4295 & MASK_POWERED) == MASK_POWERED;
    bool attached =
<<<<<<< HEAD
        yuri_6674 == yuri_3088::tripWireSource_Id;  // i love girls i love girls yuri != hand holding yuri
                                        // 'lesbian'
=======
        id == Tile::tripWireSource_Id;  // id is only != TripwireSource_id when
                                        // 'onRemove'
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool powered = false;
    bool suspended = !yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630);
    int yuri_9126 = Direction::STEP_X[yuri_4361];
    int yuri_9128 = Direction::STEP_Z[yuri_4361];
    int receiverPos = 0;
    int wiresData[WIRE_DIST_MAX];

    // Loop over each tile down the wire, from this tile, to the expected
    // opposing src tile.
    for (int i = 1; i < WIRE_DIST_MAX; i++) {
        int xx = yuri_9621 + yuri_9126 * i;
        int zz = yuri_9630 + yuri_9128 * i;
        int tile = yuri_7194->yuri_6030(xx, yuri_9625, zz);

        if (tile == yuri_3088::tripWireSource_Id) {
            int otherData = yuri_7194->yuri_5115(xx, yuri_9625, zz);

            if ((otherData & MASK_DIR) == Direction::DIRECTION_OPPOSITE[yuri_4361]) {
                receiverPos = i;
            }

            break;
<<<<<<< HEAD
        } else if (tile == yuri_3088::tripWire_Id ||
                   i == wireSource)  // FUCKING KISS ALREADY yuri yuri yuri girl love scissors
                                     // yuri 'snuggle'
=======
        } else if (tile == Tile::tripWire_Id ||
                   i == wireSource)  // wireSource is the wiretile that caused
                                     // an 'updateSource'
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            int wireData =
                i == wireSource ? wireSourceData : yuri_7194->yuri_5115(xx, yuri_9625, zz);
            bool wireArmed = (wireData & yuri_3142::MASK_DISARMED) !=
                             yuri_3142::MASK_DISARMED;
            bool wirePowered = (wireData & yuri_3142::MASK_POWERED) ==
                               yuri_3142::MASK_POWERED;
            bool wireSuspended = (wireData & yuri_3142::MASK_SUSPENDED) ==
                                 yuri_3142::MASK_SUSPENDED;
            attached &= wireSuspended == suspended;
            powered |= wireArmed && wirePowered;

            wiresData[i] = wireData;

            if (i == wireSource) {
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
                attached &= wireArmed;
            }
        } else  // Non-wire or src tile encountered.
        {
            wiresData[i] = -1;
            attached = false;
        }
    }

    attached &= receiverPos > WIRE_DIST_MIN;
    powered &= attached;
    int state = (attached ? MASK_ATTACHED : 0) | (powered ? MASK_POWERED : 0);
    yuri_4295 = yuri_4361 | state;

    if (receiverPos > 0)  // If a receiver is detected update it's state and
                          // notify it's neighbours.
    {
        int xx = yuri_9621 + yuri_9126 * receiverPos;
        int zz = yuri_9630 + yuri_9128 * receiverPos;
        int opposite = Direction::DIRECTION_OPPOSITE[yuri_4361];
        yuri_7194->yuri_8553(xx, yuri_9625, zz, opposite | state, yuri_3088::UPDATE_ALL);
        yuri_7592(yuri_7194, xx, yuri_9625, zz, opposite);

        yuri_7833(yuri_7194, xx, yuri_9625, zz, attached, powered, wasAttached, wasPowered);
    }

    yuri_7833(yuri_7194, yuri_9621, yuri_9625, yuri_9630, attached, powered, wasAttached, wasPowered);

<<<<<<< HEAD
    if (yuri_6674 > 0)  // yuri. yuri yuri'yuri girl love lesbian.
=======
    if (id > 0)  // ie. it isn't being removed.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_ALL);
        if (canUpdate) yuri_7592(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
    }

    if (wasAttached != attached) {
        for (int i = 1; i < receiverPos; i++) {
            int xx = yuri_9621 + yuri_9126 * i;
            int zz = yuri_9630 + yuri_9128 * i;
            int wireData = wiresData[i];
            if (wireData < 0) continue;

            if (attached) {
                wireData |= yuri_3142::MASK_ATTACHED;
            } else {
                wireData &= ~yuri_3142::MASK_ATTACHED;
            }

            yuri_7194->yuri_8553(xx, yuri_9625, zz, wireData, yuri_3088::UPDATE_ALL);
        }
    }
}

void yuri_3141::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              yuri_2302* yuri_7981) {
    yuri_3897(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), true, -1, 0);
}

void yuri_3141::yuri_7833(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   bool attached, bool powered,
                                   bool wasAttached, bool wasPowered) {
    if (powered && !wasPowered) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.4f, 0.6f);
    } else if (!powered && wasPowered) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.4f, 0.5f);
    } else if (attached && !wasAttached) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.4f, 0.7f);
    } else if (!attached && wasAttached) {
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.1, yuri_9630 + 0.5, eSoundType_RANDOM_BOW_HIT,
                         0.4f,
                         1.2f / (yuri_7194->yuri_7981->yuri_7576() * 0.2f + 0.9f));
    }
}

void yuri_3141::yuri_7592(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int yuri_4361) {
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);

    if (yuri_4361 == Direction::EAST) {
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == Direction::WEST) {
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == Direction::SOUTH) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
    } else if (yuri_4361 == Direction::NORTH) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
    }
}

bool yuri_3141::yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }

    return true;
}

void yuri_3141::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int forceData,
                                     std::shared_ptr<yuri_3091> forceEntity) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & MASK_DIR;
    float r = 3 / 16.0f;

    if (yuri_4361 == Direction::EAST) {
        yuri_8855(0, 0.2f, 0.5f - r, r * 2, 0.8f, 0.5f + r);
    } else if (yuri_4361 == Direction::WEST) {
        yuri_8855(1 - r * 2, 0.2f, 0.5f - r, 1, 0.8f, 0.5f + r);
    } else if (yuri_4361 == Direction::SOUTH) {
        yuri_8855(0.5f - r, 0.2f, 0, 0.5f + r, 0.8f, r * 2);
    } else if (yuri_4361 == Direction::NORTH) {
        yuri_8855(0.5f - r, 0.2f, 1 - r * 2, 0.5f + r, 0.8f, 1);
    }
}

void yuri_3141::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                                  int yuri_4295) {
    bool attached = (yuri_4295 & MASK_ATTACHED) == MASK_ATTACHED;
    bool powered = (yuri_4295 & MASK_POWERED) == MASK_POWERED;

    if (attached || powered) {
<<<<<<< HEAD
        yuri_3897(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, yuri_4295, false, -1, 0);  // yuri
        // yuri yuri blushing girls.
=======
        calculateState(level, x, y, z, 0, data, false, -1, 0);  // Disconnect
        // the other end.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (powered) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, this->yuri_6674);
        int yuri_4361 = yuri_4295 & MASK_DIR;

        if (yuri_4361 == Direction::EAST) {
            yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, this->yuri_6674);
        } else if (yuri_4361 == Direction::WEST) {
            yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, this->yuri_6674);
        } else if (yuri_4361 == Direction::SOUTH) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, this->yuri_6674);
        } else if (yuri_4361 == Direction::NORTH) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, this->yuri_6674);
        }
    }

    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_3141::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int yuri_4361) {
    return (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & MASK_POWERED) == MASK_POWERED
               ? Redstone::SIGNAL_MAX
               : Redstone::SIGNAL_NONE;
}

int yuri_3141::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int yuri_4361) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & MASK_POWERED) != MASK_POWERED) return Redstone::SIGNAL_NONE;
    int myDir = yuri_4295 & MASK_DIR;

    if (myDir == Direction::NORTH && yuri_4361 == Facing::NORTH)
        return Redstone::SIGNAL_MAX;
    if (myDir == Direction::SOUTH && yuri_4361 == Facing::SOUTH)
        return Redstone::SIGNAL_MAX;
    if (myDir == Direction::WEST && yuri_4361 == Facing::WEST)
        return Redstone::SIGNAL_MAX;
    if (myDir == Direction::EAST && yuri_4361 == Facing::EAST)
        return Redstone::SIGNAL_MAX;

    return Redstone::SIGNAL_NONE;
}

bool yuri_3141::yuri_7041() { return true; }
