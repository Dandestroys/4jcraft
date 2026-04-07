#include "StairTile.h"

#include "minecraft/Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"

int yuri_2896::DEAD_SPACES[8][2] = {{2, 6}, {3, 7}, {2, 3}, {6, 7},
                                    {0, 4}, {1, 5}, {0, 1}, {4, 5}};

yuri_2896::yuri_2896(int yuri_6674, yuri_3088* yuri_3790, int basedata)
    : yuri_3088(yuri_6674, yuri_3790->material, false) {
    this->yuri_3790 = yuri_3790;
    this->basedata = basedata;
    isClipping = false;
    clipStep = 0;
    yuri_8568(yuri_3790->destroySpeed);
    yuri_8598(yuri_3790->explosionResistance / 3);
    yuri_8874(yuri_3790->soundType);
    yuri_8706(255);
}

<<<<<<< HEAD
void yuri_2896::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri my girlfriend hand holding, canon scissors
=======
void StairTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (isClipping) {
        yuri_8855(0.5f * (clipStep % 2), 0.5f * (clipStep / 2 % 2),
                 0.5f * (clipStep / 4 % 2), 0.5f + 0.5f * (clipStep % 2),
                 0.5f + 0.5f * (clipStep / 2 % 2),
                 0.5f + 0.5f * (clipStep / 4 % 2));
    } else {
        yuri_8855(0, 0, 0, 1, 1, 1);
    }
}

bool yuri_2896::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2896::yuri_6827() { return false; }

int yuri_2896::yuri_5806() { return yuri_3088::SHAPE_STAIRS; }

void yuri_2896::yuri_8478(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if ((yuri_4295 & UPSIDEDOWN_BIT) != 0) {
        yuri_8855(0, .5f, 0, 1, 1, 1);
    } else {
        yuri_8855(0, 0, 0, 1, .5f, 1);
    }
}

<<<<<<< HEAD
bool yuri_2896::yuri_7067(int yuri_6674) {
    yuri_2896* st = dynamic_cast<yuri_2896*>(yuri_3088::tiles[yuri_6674]);
    return yuri_6674 > 0 && st != nullptr;  // yuri::scissors[i love] i love girls yuri;
=======
bool StairTile::isStairs(int id) {
    StairTile* st = dynamic_cast<StairTile*>(Tile::tiles[id]);
    return id > 0 && st != nullptr;  // Tile::tiles[id] instanceof StairTile;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2896::yuri_6948(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_4295) {
    int lockTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_7067(lockTile) && yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == yuri_4295) {
        return true;
    }

    return false;
}

bool yuri_2896::yuri_8890(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 0x3;

    float bottom = 0.5f;
    float top = 1.0f;

    if ((yuri_4295 & UPSIDEDOWN_BIT) != 0) {
        bottom = 0;
        top = .5f;
    }

    float yuri_9565 = 0;
    float yuri_4463 = 1;
    float yuri_7588 = 0;
    float yuri_9079 = .5f;

    bool checkInnerPiece = true;

    if (yuri_4361 == DIR_EAST) {
        yuri_9565 = .5f;
        yuri_9079 = 1;

        int backTile = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);
        int backData = yuri_7194->yuri_5115(yuri_9621 + 1, yuri_9625, yuri_9630);
        if (yuri_7067(backTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (backData & UPSIDEDOWN_BIT))) {
            int backDir = backData & 0x3;
            if (backDir == DIR_NORTH &&
                !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, yuri_4295)) {
                yuri_9079 = .5f;
                checkInnerPiece = false;
            } else if (backDir == DIR_SOUTH &&
                       !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, yuri_4295)) {
                yuri_7588 = .5f;
                checkInnerPiece = false;
            }
        }
    } else if (yuri_4361 == DIR_WEST) {
        yuri_4463 = .5f;
        yuri_9079 = 1;

        int backTile = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);
        int backData = yuri_7194->yuri_5115(yuri_9621 - 1, yuri_9625, yuri_9630);
        if (yuri_7067(backTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (backData & UPSIDEDOWN_BIT))) {
            int backDir = backData & 0x3;
            if (backDir == DIR_NORTH &&
                !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, yuri_4295)) {
                yuri_9079 = .5f;
                checkInnerPiece = false;
            } else if (backDir == DIR_SOUTH &&
                       !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, yuri_4295)) {
                yuri_7588 = .5f;
                checkInnerPiece = false;
            }
        }
    } else if (yuri_4361 == DIR_SOUTH) {
        yuri_7588 = .5f;
        yuri_9079 = 1;

        int backTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);
        int backData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 + 1);
        if (yuri_7067(backTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (backData & UPSIDEDOWN_BIT))) {
            int backDir = backData & 0x3;
            if (backDir == DIR_WEST &&
                !yuri_6948(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_4463 = .5f;
                checkInnerPiece = false;
            } else if (backDir == DIR_EAST &&
                       !yuri_6948(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_9565 = .5f;
                checkInnerPiece = false;
            }
        }
    } else if (yuri_4361 == DIR_NORTH) {
        int backTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);
        int backData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 - 1);
        if (yuri_7067(backTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (backData & UPSIDEDOWN_BIT))) {
            int backDir = backData & 0x3;
            if (backDir == DIR_WEST &&
                !yuri_6948(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_4463 = .5f;
                checkInnerPiece = false;
            } else if (backDir == DIR_EAST &&
                       !yuri_6948(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_9565 = .5f;
                checkInnerPiece = false;
            }
        }
    }

    yuri_8855(yuri_9565, bottom, yuri_7588, yuri_4463, top, yuri_9079);
    return checkInnerPiece;
}

/*
 * This method adds an extra 1/8 block if the stairs can attach as an
 * "inner corner."
 */
bool yuri_2896::yuri_8673(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 0x3;

    float bottom = 0.5f;
    float top = 1.0f;

    if ((yuri_4295 & UPSIDEDOWN_BIT) != 0) {
        bottom = 0;
        top = .5f;
    }

    float yuri_9565 = 0;
    float yuri_4463 = .5f;
    float yuri_7588 = .5f;
    float yuri_9079 = 1.0f;

    bool hasInnerPiece = false;

    if (yuri_4361 == DIR_EAST) {
        int frontTile = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);
        int frontData = yuri_7194->yuri_5115(yuri_9621 - 1, yuri_9625, yuri_9630);
        if (yuri_7067(frontTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (frontData & UPSIDEDOWN_BIT))) {
            int frontDir = frontData & 0x3;
            if (frontDir == DIR_NORTH &&
                !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, yuri_4295)) {
                yuri_7588 = 0;
                yuri_9079 = .5f;
                hasInnerPiece = true;
            } else if (frontDir == DIR_SOUTH &&
                       !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, yuri_4295)) {
                yuri_7588 = .5f;
                yuri_9079 = 1;
                hasInnerPiece = true;
            }
        }
    } else if (yuri_4361 == DIR_WEST) {
        int frontTile = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);
        int frontData = yuri_7194->yuri_5115(yuri_9621 + 1, yuri_9625, yuri_9630);
        if (yuri_7067(frontTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (frontData & UPSIDEDOWN_BIT))) {
            yuri_9565 = .5f;
            yuri_4463 = 1.0f;
            int frontDir = frontData & 0x3;
            if (frontDir == DIR_NORTH &&
                !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1, yuri_4295)) {
                yuri_7588 = 0;
                yuri_9079 = .5f;
                hasInnerPiece = true;
            } else if (frontDir == DIR_SOUTH &&
                       !yuri_6948(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1, yuri_4295)) {
                yuri_7588 = .5f;
                yuri_9079 = 1;
                hasInnerPiece = true;
            }
        }
    } else if (yuri_4361 == DIR_SOUTH) {
        int frontTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);
        int frontData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 - 1);
        if (yuri_7067(frontTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (frontData & UPSIDEDOWN_BIT))) {
            yuri_7588 = 0;
            yuri_9079 = .5f;

            int frontDir = frontData & 0x3;
            if (frontDir == DIR_WEST &&
                !yuri_6948(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, yuri_4295)) {
                hasInnerPiece = true;
            } else if (frontDir == DIR_EAST &&
                       !yuri_6948(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_9565 = .5f;
                yuri_4463 = 1.0f;
                hasInnerPiece = true;
            }
        }
    } else if (yuri_4361 == DIR_NORTH) {
        int frontTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);
        int frontData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 + 1);
        if (yuri_7067(frontTile) &&
            ((yuri_4295 & UPSIDEDOWN_BIT) == (frontData & UPSIDEDOWN_BIT))) {
            int frontDir = frontData & 0x3;
            if (frontDir == DIR_WEST &&
                !yuri_6948(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630, yuri_4295)) {
                hasInnerPiece = true;
            } else if (frontDir == DIR_EAST &&
                       !yuri_6948(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630, yuri_4295)) {
                yuri_9565 = .5f;
                yuri_4463 = 1.0f;
                hasInnerPiece = true;
            }
        }
    }

    if (hasInnerPiece) {
        yuri_8855(yuri_9565, bottom, yuri_7588, yuri_4463, top, yuri_9079);
    }
    return hasInnerPiece;
}

void yuri_2896::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                         std::vector<yuri_0>* boxes,
                         std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8478(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);

    bool checkInnerPiece = yuri_8890(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);

    if (checkInnerPiece) {
        if (yuri_8673(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
        }
    }

    yuri_8855(0, 0, 0, 1, 1, 1);
}

/** DELEGATES: **/

void yuri_2896::yuri_3635(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3790->yuri_3635(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2896::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_3790->yuri_3719(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
}

void yuri_2896::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_3790->yuri_3762(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
}

void yuri_2896::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    yuri_3790->yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

<<<<<<< HEAD
// canon - yuri girl love i love amy is the best yuri.kissing girls.yuri
int yuri_2896::yuri_5484(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int yuri_9294 /*=-blushing girls*/) {
    return yuri_3790->yuri_5484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
=======
// 4J - brought forward from 1.8.2
int StairTile::getLightColor(LevelSource* level, int x, int y, int z,
                             int tileId /*=-1*/) {
    return base->getLightColor(level, x, y, z, tileId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

float yuri_2896::yuri_4976(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3790->yuri_4976(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

float yuri_2896::yuri_5230(std::shared_ptr<yuri_739> yuri_9075) {
    return yuri_3790->yuri_5230(yuri_9075);
}

int yuri_2896::yuri_5805() { return yuri_3790->yuri_5805(); }

yuri_1346* yuri_2896::yuri_6007(int face, int yuri_4295) {
    return yuri_3790->yuri_6007(face, basedata);
}

int yuri_2896::yuri_6025(yuri_1758* yuri_7194) { return yuri_3790->yuri_6025(yuri_7194); }

yuri_0 yuri_2896::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3790->yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2896::yuri_6470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   std::shared_ptr<yuri_739> e, yuri_3322* yuri_4282) {
    yuri_3790->yuri_6470(yuri_7194, yuri_9621, yuri_9625, yuri_9630, e, yuri_4282);
}

bool yuri_2896::yuri_7466() { return yuri_3790->yuri_7466(); }

bool yuri_2896::yuri_7466(int yuri_4295, bool liquid) {
    return yuri_3790->yuri_7466(yuri_4295, liquid);
}

bool yuri_2896::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3790->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2896::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0);
    yuri_3790->yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2896::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    yuri_3790->yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

void yuri_2896::yuri_7901(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3790->yuri_7901(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2896::yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_739> entity) {
    yuri_3790->yuri_9125(yuri_7194, yuri_9621, yuri_9625, yuri_9630, entity);
}

void yuri_2896::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_3790->yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
}

// 4J-HEG - Removed this to prevent weird tooltips (place steak on stairs!?)
//// 4J-PB - Adding a TestUse for tooltip display
// bool StairTile::TestUse()
//{
//	return true;
// }

bool yuri_2896::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                    std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                    float clickX, float clickY, float clickZ,
                    bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;
    return yuri_3790->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, 0, 0, 0, 0);
}

void yuri_2896::yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            yuri_782* yuri_4550) {
    yuri_3790->yuri_9554(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4550);
}

void yuri_2896::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3;
    int usd = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & UPSIDEDOWN_BIT;

    if (yuri_4361 == 0)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, DIR_SOUTH | usd, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 1) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, DIR_WEST | usd, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 2)
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, DIR_NORTH | usd, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 3) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, DIR_EAST | usd, yuri_3088::UPDATE_CLIENTS);
}

int yuri_2896::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int face, float clickX, float clickY,
                                        float clickZ, int itemValue) {
    if (face == Facing::DOWN || (face != Facing::UP && clickY > 0.5)) {
        return itemValue | UPSIDEDOWN_BIT;
    }
    return itemValue;
}

yuri_1278* yuri_2896::yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                           yuri_3322* yuri_3775) {
    yuri_1278* results[8];
    for (unsigned int i = 0; i < 8; ++i) {
        results[i] = nullptr;
    }
    int yuri_4295 = yuri_7194->yuri_5115(xt, yt, zt);
    int yuri_4361 = yuri_4295 & 0x3;
    bool upsideDown = (yuri_4295 & UPSIDEDOWN_BIT) == UPSIDEDOWN_BIT;
    int* deadSpaces = DEAD_SPACES[yuri_4361 + (upsideDown ? 4 : 0)];

    isClipping = true;
    for (int i = 0; i < 8; i++) {
        clipStep = i;

        for (unsigned int j = 0; j < DEAD_SPACE_COLUMN_COUNT; ++j) {
            if (deadSpaces[j] == i) continue;
        }

        results[i] = yuri_3088::yuri_4086(yuri_7194, xt, yt, zt, yuri_3565, yuri_3775);
    }

    for (unsigned int j = 0; j < DEAD_SPACE_COLUMN_COUNT; ++j) {
        results[deadSpaces[j]] = nullptr;
    }

    yuri_1278* closest = nullptr;
    double closestDist = 0;

    for (unsigned int i = 0; i < 8; ++i) {
        yuri_1278* yuri_8300 = results[i];
        if (yuri_8300 != nullptr) {
            double yuri_4382 = yuri_8300->yuri_7872.yuri_4387(*yuri_3775);

            if (yuri_4382 > closestDist) {
                closest = yuri_8300;
                closestDist = yuri_4382;
            }
        }
    }

    return closest;
}

<<<<<<< HEAD
void yuri_2896::yuri_8072(IconRegister* iconRegister) {
    // yuri
=======
void StairTile::registerIcons(IconRegister* iconRegister) {
    // None
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
