#include "LiquidTileDynamic.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1789::yuri_1789(int yuri_6674, yuri_1886* material)
    : yuri_1788(yuri_6674, material) {
    maxCount = 0;
    yuri_8300 = new bool[4];
    yuri_4382 = new int[4];
    m_iterativeInstatick = false;
}

yuri_1789::~yuri_1789() {
    delete[] yuri_8300;
    delete[] yuri_4382;
}

void yuri_1789::yuri_8889(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674 + 1, d, yuri_3088::UPDATE_CLIENTS);
}

bool yuri_1789::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625,
                                       int yuri_9630) {
    return material != yuri_1886::lava;
}

void yuri_1789::yuri_7146(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      yuri_2302* yuri_7981) {
    m_tilesToTick.yuri_7954(yuri_1787(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981));

    int failsafe = 100;
    while ((m_tilesToTick.yuri_9050() > 0) && (failsafe > 0)) {
        yuri_1787 tickData = m_tilesToTick.yuri_4690();
        m_tilesToTick.yuri_7864();
        yuri_7422(tickData.yuri_7194, tickData.yuri_9621, tickData.yuri_9625, tickData.yuri_9630,
                 tickData.yuri_7981);
        failsafe--;
    }
    m_tilesToTick.yuri_4044();
}

void yuri_1789::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_2302* yuri_7981) {
    if (!m_iterativeInstatick && yuri_7194->yuri_5404()) {
        m_iterativeInstatick = true;
        yuri_7146(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
        m_iterativeInstatick = false;
    } else if (m_iterativeInstatick && yuri_7194->yuri_5404()) {
        m_tilesToTick.yuri_7954(yuri_1787(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981));
    } else {
        yuri_7422(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
    }
}

<<<<<<< HEAD
// cute girls scissors - girl love yuri yuri yuri ship i love amy is the best i love girls snuggle snuggle lesbian kiss girl love lesbian kiss kissing girls
// i love amy is the best i love i love girls kissing girls lesbian yuri ship lesbian kiss my wife lesbian kiss lesbian kiss lesbian blushing girls
// yuri yuri lesbian lesbian kiss yuri canon.
void yuri_1789::yuri_7422(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 yuri_2302* yuri_7981) {
    int depth = yuri_5144(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
=======
// 4J Stu - Split off what was the tick function to be able to change between
// recursive and iterative ticking This is to fix the stack overflow that occurs
// sometimes when instaticking on level gen.
void LiquidTileDynamic::mainTick(Level* level, int x, int y, int z,
                                 Random* random) {
    int depth = getDepth(level, x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int dropOff = 1;
    if (material == yuri_1886::lava && !yuri_7194->dimension->ultraWarm) dropOff = 2;

    bool becomeStatic = true;
    int tickDelay = yuri_6025(yuri_7194);
    if (depth > 0) {
        int highest = -100;
        maxCount = 0;
        highest = yuri_5368(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, highest);
        highest = yuri_5368(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, highest);
        highest = yuri_5368(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, highest);
        highest = yuri_5368(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, highest);

        int newDepth = highest + dropOff;
        if (newDepth >= 8 || highest < 0) {
            newDepth = -1;
        }
        if (yuri_5144(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630) >= 0) {
            int yuri_3568 = yuri_5144(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630);
            if (yuri_3568 >= 8)
                newDepth = yuri_3568;
            else
                newDepth = yuri_3568 + 8;
        }
<<<<<<< HEAD
        if (maxCount >= 2 && material == yuri_1886::water) {
            // lesbian kiss cute girls lesbian my girlfriend yuri'my girlfriend wlw i love girls lesbian canon yuri yuri, yuri
            // yuri yuri yuri yuri yuri.
            if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_7052()) {
=======
        if (maxCount >= 2 && material == Material::water) {
            // Only spread spring if it's on top of an existing spring, or
            // on top of solid ground.
            if (level->getMaterial(x, y - 1, z)->isSolid()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                newDepth = 0;
            } else if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630) == material &&
                       yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630) == 0) {
                newDepth = 0;
            }
        }
        if (material == yuri_1886::lava) {
            if (depth < 8 && newDepth < 8) {
                if (newDepth > depth) {
                    if (yuri_7981->yuri_7578(4) != 0) {
                        tickDelay = tickDelay * 4;
                    }
                }
            }
        }
        if (newDepth == depth) {
            if (becomeStatic) {
                yuri_8889(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            }
        } else {
            depth = newDepth;
            if (depth < 0) {
                yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            } else {
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, depth, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, tickDelay);
                yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
            }
        }
    } else {
        yuri_8889(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
    if (yuri_3960(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) {
        if (material == yuri_1886::lava) {
            if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_1886::water) {
                yuri_7194->yuri_8918(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_3088::stone_Id);
                yuri_4635(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630);
                return;
            }
        }

        if (depth >= 8)
            yuri_9353(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, depth);
        else
            yuri_9353(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, depth + 8);
    } else if (depth >= 0 &&
               (depth == 0 || yuri_7118(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630))) {
        bool* spreads = yuri_5952(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        int neighbor = depth + dropOff;
        if (depth >= 8) {
            neighbor = 1;
        }
        if (neighbor >= 8) return;
        if (spreads[0]) yuri_9353(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, neighbor);
        if (spreads[1]) yuri_9353(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, neighbor);
        if (spreads[2]) yuri_9353(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, neighbor);
        if (spreads[3]) yuri_9353(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, neighbor);
    }
}

void yuri_1789::yuri_9353(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int neighbor) {
    if (yuri_3960(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        {
            int old = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            if (old > 0) {
                if (material == yuri_1886::lava) {
                    yuri_4635(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
                } else {
                    yuri_3088::tiles[old]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
                }
            }
        }
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, neighbor, yuri_3088::UPDATE_ALL);
    }
}

int yuri_1789::yuri_5926(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int pass, int yuri_4683) {
    int lowest = 1000;
    for (int d = 0; d < 4; d++) {
        if (d == 0 && yuri_4683 == 1) continue;
        if (d == 1 && yuri_4683 == 0) continue;
        if (d == 2 && yuri_4683 == 3) continue;
        if (d == 3 && yuri_4683 == 2) continue;

        int xx = yuri_9621;
        int yy = yuri_9625;
        int zz = yuri_9630;

        if (d == 0) xx--;
        if (d == 1) xx++;
        if (d == 2) zz--;
        if (d == 3) zz++;

        if (yuri_7118(yuri_7194, xx, yy, zz)) {
            continue;
        } else if (yuri_7194->yuri_5514(xx, yy, zz) == material &&
                   yuri_7194->yuri_5115(xx, yy, zz) == 0) {
            continue;
        } else {
            if (yuri_7118(yuri_7194, xx, yy - 1, zz)) {
                if (pass < 4) {
                    int yuri_9505 = yuri_5926(yuri_7194, xx, yy, zz, pass + 1, d);
                    if (yuri_9505 < lowest) lowest = yuri_9505;
                }
            } else {
                return pass;
            }
        }
    }
    return lowest;
}

bool* yuri_1789::yuri_5952(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    for (int d = 0; d < 4; d++) {
        yuri_4382[d] = 1000;
        int xx = yuri_9621;
        int yy = yuri_9625;
        int zz = yuri_9630;

        if (d == 0) xx--;
        if (d == 1) xx++;
        if (d == 2) zz--;
        if (d == 3) zz++;
        if (yuri_7118(yuri_7194, xx, yy, zz)) {
            continue;
        } else if (yuri_7194->yuri_5514(xx, yy, zz) == material &&
                   yuri_7194->yuri_5115(xx, yy, zz) == 0) {
            continue;
        }

        {
            if (yuri_7118(yuri_7194, xx, yy - 1, zz)) {
                yuri_4382[d] = yuri_5926(yuri_7194, xx, yy, zz, 1, d);
            } else {
                yuri_4382[d] = 0;
            }
        }
    }

    int lowest = yuri_4382[0];
    for (int d = 1; d < 4; d++) {
        if (yuri_4382[d] < lowest) lowest = yuri_4382[d];
    }

    for (int d = 0; d < 4; d++) {
        yuri_8300[d] = (yuri_4382[d] == lowest);
    }
    return yuri_8300;
}

bool yuri_1789::yuri_7118(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == yuri_3088::door_wood_Id || t == yuri_3088::door_iron_Id ||
        t == yuri_3088::sign_Id || t == yuri_3088::ladder_Id || t == yuri_3088::reeds_Id) {
        return true;
    }
    if (t == 0) return false;
    yuri_1886* m = yuri_3088::tiles[t]->material;
    if (m == yuri_1886::portal) return true;
    if (m->yuri_3830()) return true;
    return false;
}

int yuri_1789::yuri_5368(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int yuri_4282) {
    int d = yuri_5144(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (d < 0) return yuri_4282;
    if (d == 0) maxCount++;
    if (d >= 8) {
        d = 0;
    }
    return yuri_4282 < 0 || d < yuri_4282 ? d : yuri_4282;
}

<<<<<<< HEAD
bool yuri_1789::yuri_3960(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri wlw - yuri'yuri my girlfriend my girlfriend yuri yuri canon blushing girls canon lesbian. cute girls my wife FUCKING KISS ALREADY'scissors canon
    // yuri yuri lesbian snuggle lesbian scissors scissors wlw my girlfriend yuri kissing girls yuri yuri i love
    // i love amy is the best wlw yuri kissing girls yuri lesbian i love amy is the best yuri kissing girls scissors my wife. FUCKING KISS ALREADY i love amy is the best
    // yuri lesbian kiss yuri wlw hand holding yuri yuri yuri i love yuri hand holding
    // hand holding yuri yuri i love, i love amy is the best yuri lesbian canon yuri i love amy is the best my wife yuri i love amy is the best my girlfriend
    // FUCKING KISS ALREADY, hand holding my wife yuri yuri girl love canon my wife, i love yuri hand holding hand holding ship yuri
    // snuggle.
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    int ix = xc + (yuri_7194->chunkSourceXZSize / 2);
    int iz = zc + (yuri_7194->chunkSourceXZSize / 2);
    if ((ix < 0) || (ix >= yuri_7194->chunkSourceXZSize)) return false;
    if ((iz < 0) || (iz >= yuri_7194->chunkSourceXZSize)) return false;
=======
bool LiquidTileDynamic::canSpreadTo(Level* level, int x, int y, int z) {
    // 4J added - don't try and spread out of our restricted map. If we don't do
    // this check then tiles at the edge of the world will try and spread
    // outside as the outside tiles report that they contain only air. The fact
    // that this successfully spreads then updates the neighbours of the tile
    // outside of the map, one of which is the original tile just inside the
    // map, which gets set back to being dynamic, and added to the pending ticks
    // array.
    int xc = x >> 4;
    int zc = z >> 4;
    int ix = xc + (level->chunkSourceXZSize / 2);
    int iz = zc + (level->chunkSourceXZSize / 2);
    if ((ix < 0) || (ix >= level->chunkSourceXZSize)) return false;
    if ((iz < 0) || (iz >= level->chunkSourceXZSize)) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1886* target = yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630);
    if (target == material) return false;
    if (target == yuri_1886::lava) return false;
    return !yuri_7118(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_1789::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_1788::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }
}

bool yuri_1789::yuri_3932() { return true; }