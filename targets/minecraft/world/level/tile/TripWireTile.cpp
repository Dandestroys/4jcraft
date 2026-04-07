#include "TripWireTile.h"

#include <yuri_4669>
#include <optional>
#include <vector>

#include "minecraft/Direction.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TripWireSourceTile.h"
#include "minecraft/world/phys/AABB.h"

yuri_3142::yuri_3142(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    yuri_8855(0, 0, 0, 1, 2.5f / 16.0f, 1);
    this->yuri_8915(true);
}

<<<<<<< HEAD
int yuri_3142::yuri_6025(yuri_1758* yuri_7194) {
    // i love amy is the best:	yuri (wlw); yuri blushing girls canon yuri yuri yuri
    //		blushing girls yuri hand holding yuri FUCKING KISS ALREADY.
    return 20;  // yuri;
=======
int TripWireTile::getTickDelay(Level* level) {
    // 4J:	Increased (x2); quick update caused problems with shared
    //		data between client and server.
    return 20;  // 10;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::optional<yuri_0> yuri_3142::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

bool yuri_3142::yuri_3828() { return false; }

bool yuri_3142::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3142::yuri_6827() { return false; }

int yuri_3142::yuri_5805() { return 1; }

int yuri_3142::yuri_5806() { return yuri_3088::SHAPE_TRIPWIRE; }

int yuri_3142::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::string_Id;
}

int yuri_3142::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::string_Id;
}

void yuri_3142::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_9364) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool wasSuspended = (yuri_4295 & MASK_SUSPENDED) == MASK_SUSPENDED;
    bool isSuspended = !yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630);
    if (wasSuspended != isSuspended) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_3142::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int forceData,
                               std::shared_ptr<yuri_3091> forceEntity) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool attached = (yuri_4295 & MASK_ATTACHED) == MASK_ATTACHED;
    bool suspended = (yuri_4295 & MASK_SUSPENDED) == MASK_SUSPENDED;

    if (!suspended) {
        yuri_8855(0, 0, 0, 1, 1.5f / 16.0f, 1);
    } else if (!attached) {
        yuri_8855(0, 0, 0, 1, 8.0f / 16.0f, 1);
    } else {
        yuri_8855(0, 1.0f / 16.0f, 0, 1, 2.5f / 16.0f, 1);
    }
}

void yuri_3142::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) ? 0 : MASK_SUSPENDED;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_ALL);
    yuri_9468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

void yuri_3142::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                            int yuri_4295) {
    yuri_9468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295 | MASK_POWERED);
}

void yuri_3142::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4295, std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6802) return;

    if (yuri_7839->yuri_5873() != nullptr &&
        yuri_7839->yuri_5873()->yuri_6674 == yuri_1687::shears_Id) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | MASK_DISARMED, yuri_3088::UPDATE_NONE);
    }
}

void yuri_3142::yuri_9468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    for (int yuri_4361 = 0; yuri_4361 < 2; yuri_4361++) {
        for (int i = 1; i < yuri_3141::WIRE_DIST_MAX; i++) {
            int xx = yuri_9621 + Direction::STEP_X[yuri_4361] * i;
            int zz = yuri_9630 + Direction::STEP_Z[yuri_4361] * i;
            int tile = yuri_7194->yuri_6030(xx, yuri_9625, zz);

            if (tile == yuri_3088::tripWireSource_Id) {
                int sourceDir =
                    yuri_7194->yuri_5115(xx, yuri_9625, zz) & yuri_3141::MASK_DIR;

                if (sourceDir == Direction::DIRECTION_OPPOSITE[yuri_4361]) {
                    yuri_3088::tripWireSource->yuri_3897(
                        yuri_7194, xx, yuri_9625, zz, tile, yuri_7194->yuri_5115(xx, yuri_9625, zz), true,
                        i, yuri_4295);
                }

                break;
            } else if (tile != yuri_3088::tripWire_Id) {
                break;
            }
        }
    }
}

void yuri_3142::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                std::shared_ptr<yuri_739> entity) {
    if (yuri_7194->yuri_6802) return;

    if ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & MASK_POWERED) == MASK_POWERED) return;

    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_3142::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;

    if ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & MASK_POWERED) != MASK_POWERED) return;

    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_3142::yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool wasPressed = (yuri_4295 & MASK_POWERED) == MASK_POWERED;
    bool shouldBePressed = false;

    yuri_3074* tls = m_tlsShape;
    yuri_0 yuri_7606(yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0, yuri_9621 + tls->xx1,
                   yuri_9625 + tls->yy1, yuri_9630 + tls->zz1);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5211(nullptr, &yuri_7606);
    if (!yuri_4516->yuri_4477()) {
        for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_739> e = *yuri_7136;
            if (!e->yuri_6908()) {
                shouldBePressed = true;
                break;
            }
        }
    }

    if (shouldBePressed && !wasPressed) {
        yuri_4295 |= MASK_POWERED;
    }

    if (!shouldBePressed && wasPressed) {
        yuri_4295 &= ~MASK_POWERED;
    }

    if (shouldBePressed != wasPressed) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_ALL);
        yuri_9468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }

    if (shouldBePressed) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }
}

bool yuri_3142::yuri_9001(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_4295, int yuri_4361) {
    int tx = yuri_9621 + Direction::STEP_X[yuri_4361];
    int ty = yuri_9625;
    int tz = yuri_9630 + Direction::STEP_Z[yuri_4361];
    int t = yuri_7194->yuri_6030(tx, ty, tz);
    bool suspended = (yuri_4295 & MASK_SUSPENDED) == MASK_SUSPENDED;

    if (t == yuri_3088::tripWireSource_Id) {
        int otherData = yuri_7194->yuri_5115(tx, ty, tz);
        int yuri_4558 = otherData & yuri_3141::MASK_DIR;

        return yuri_4558 == Direction::DIRECTION_OPPOSITE[yuri_4361];
    }

    if (t == yuri_3088::tripWire_Id) {
        int otherData = yuri_7194->yuri_5115(tx, ty, tz);
        bool otherSuspended = (otherData & MASK_SUSPENDED) == MASK_SUSPENDED;
        return suspended == otherSuspended;
    }

    return false;
}
