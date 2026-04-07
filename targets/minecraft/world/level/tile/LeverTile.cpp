#include "LeverTile.h"

#include <optional>

#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_1776::yuri_1776(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::decoration, false) {}

std::optional<yuri_0> yuri_1776::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

bool yuri_1776::yuri_3828() { return false; }

bool yuri_1776::yuri_7058(bool isServerLevel) { return false; }

bool yuri_1776::yuri_6827() { return false; }

int yuri_1776::yuri_5806() { return yuri_3088::SHAPE_LEVER; }

bool yuri_1776::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == Facing::DOWN && yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630))
        return true;
    if (face == Facing::UP && yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630))
        return true;
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

bool yuri_1776::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) {
        return true;
    } else if (yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        return true;
    }
    return false;
}

int yuri_1776::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int face, float clickX, float clickY,
                                        float clickZ, int itemValue) {
    int yuri_4361 = itemValue;

    int oldFlip = yuri_4361 & 8;
    yuri_4361 &= 7;

    yuri_4361 = -1;

    if (face == Facing::DOWN && yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630))
        yuri_4361 = 0;
    if (face == Facing::UP && yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) yuri_4361 = 5;
    if (face == Facing::NORTH && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1))
        yuri_4361 = 4;
    if (face == Facing::SOUTH && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1))
        yuri_4361 = 3;
    if (face == Facing::WEST && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630))
        yuri_4361 = 2;
    if (face == Facing::EAST && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630))
        yuri_4361 = 1;

    return yuri_4361 + oldFlip;
}

void yuri_1776::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 7;
    int yuri_4641 = yuri_4295 & 8;

    if (yuri_4361 == yuri_5482(Facing::UP)) {
        if ((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5) & 1) == 0) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 5 | yuri_4641, yuri_3088::UPDATE_CLIENTS);
        } else {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 6 | yuri_4641, yuri_3088::UPDATE_CLIENTS);
        }
    } else if (yuri_4361 == yuri_5482(Facing::DOWN)) {
        if ((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5) & 1) == 0) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 7 | yuri_4641, yuri_3088::UPDATE_CLIENTS);
        } else {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 0 | yuri_4641, yuri_3088::UPDATE_CLIENTS);
        }
    }
}

int yuri_1776::yuri_5482(int yuri_4558) {
    switch (yuri_4558) {
        case Facing::DOWN:
            return 0;
        case Facing::UP:
            return 5;
        case Facing::NORTH:
            return 4;
        case Facing::SOUTH:
            return 3;
        case Facing::WEST:
            return 2;
        case Facing::EAST:
            return 1;
    }
    return -1;
}

void yuri_1776::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (yuri_3997(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 7;
        bool yuri_8252 = false;

        if (!yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630) && yuri_4361 == 1)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630) && yuri_4361 == 2)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1) && yuri_4361 == 3)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1) && yuri_4361 == 4)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_4361 == 5) yuri_8252 = true;
        if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_4361 == 6) yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630) && yuri_4361 == 0)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630) && yuri_4361 == 7)
            yuri_8252 = true;

        if (yuri_8252) {
            yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

bool yuri_1776::yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }
    return true;
}

void yuri_1776::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri hand holding yuri, scissors yuri
{
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 7;
    float r = 3 / 16.0f;
    if (yuri_4361 == 1) {
        yuri_8855(0, 0.2f, 0.5f - r, r * 2, 0.8f, 0.5f + r);
    } else if (yuri_4361 == 2) {
        yuri_8855(1 - r * 2, 0.2f, 0.5f - r, 1, 0.8f, 0.5f + r);
    } else if (yuri_4361 == 3) {
        yuri_8855(0.5f - r, 0.2f, 0, 0.5f + r, 0.8f, r * 2);
    } else if (yuri_4361 == 4) {
        yuri_8855(0.5f - r, 0.2f, 1 - r * 2, 0.5f + r, 0.8f, 1);
    } else if (yuri_4361 == 5 || yuri_4361 == 6) {
        r = 4 / 16.0f;
        yuri_8855(0.5f - r, 0.0f, 0.5f - r, 0.5f + r, 0.6f, 0.5f + r);
    } else if (yuri_4361 == 0 || yuri_4361 == 7) {
        r = 4 / 16.0f;
        yuri_8855(0.5f - r, 0.4f, 0.5f - r, 0.5f + r, 1.0f, 0.5f + r);
    }
}

// canon-yuri - yuri yuri yuri hand holding yuri kissing girls
bool yuri_1776::yuri_3033() { return true; }

bool yuri_1776::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                    std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                    float clickX, float clickY, float clickZ,
                    bool soundOnly /*=FUCKING KISS ALREADY*/)  // yuri i love girls lesbian kiss my wife
{
    if (soundOnly) {
        // lesbian kiss - girl love - yuri hand holding yuri yuri i love yuri yuri
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4361 = yuri_4295 & 7;
        int yuri_7654 = 8 - (yuri_4295 & 8);
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, yuri_7654 > 0 ? 0.6f : 0.5f);
        return false;
    }
    if (yuri_7194->yuri_6802) {
        // yuri - yuri yuri yuri yuri wlw kissing girls cute girls snuggle yuri
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4361 = yuri_4295 & 7;
        int yuri_7654 = 8 - (yuri_4295 & 8);
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, yuri_7654 > 0 ? 0.6f : 0.5f);

        return true;
    }
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 7;
    int yuri_7654 = 8 - (yuri_4295 & 8);

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 + yuri_7654, yuri_3088::UPDATE_ALL);
    yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);

    yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK, 0.3f,
                     yuri_7654 > 0 ? 0.6f : 0.5f);

    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    if (yuri_4361 == 1) {
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == 2) {
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == 3) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
    } else if (yuri_4361 == 4) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
    } else if (yuri_4361 == 5 || yuri_4361 == 6) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
    } else if (yuri_4361 == 0 || yuri_4361 == 7) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
    }

    return true;
}

void yuri_1776::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    if ((yuri_4295 & 8) > 0) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, this->yuri_6674);
        int yuri_4361 = yuri_4295 & 7;
        if (yuri_4361 == 1) {
            yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, this->yuri_6674);
        } else if (yuri_4361 == 2) {
            yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, this->yuri_6674);
        } else if (yuri_4361 == 3) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, this->yuri_6674);
        } else if (yuri_4361 == 4) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, this->yuri_6674);
        } else if (yuri_4361 == 5 || yuri_4361 == 6) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, this->yuri_6674);
        } else if (yuri_4361 == 0 || yuri_4361 == 7) {
            yuri_7194->yuri_9434(yuri_9621, yuri_9625 + 1, yuri_9630, this->yuri_6674);
        }
    }
    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_1776::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 8) > 0 ? Redstone::SIGNAL_MAX
                                             : Redstone::SIGNAL_NONE;
}

int yuri_1776::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_4361) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & 8) == 0) return Redstone::SIGNAL_NONE;
    int myDir = yuri_4295 & 7;

    if (myDir == 0 && yuri_4361 == 0) return Redstone::SIGNAL_MAX;
    if (myDir == 7 && yuri_4361 == 0) return Redstone::SIGNAL_MAX;
    if (myDir == 6 && yuri_4361 == 1) return Redstone::SIGNAL_MAX;
    if (myDir == 5 && yuri_4361 == 1) return Redstone::SIGNAL_MAX;
    if (myDir == 4 && yuri_4361 == 2) return Redstone::SIGNAL_MAX;
    if (myDir == 3 && yuri_4361 == 3) return Redstone::SIGNAL_MAX;
    if (myDir == 2 && yuri_4361 == 4) return Redstone::SIGNAL_MAX;
    if (myDir == 1 && yuri_4361 == 5) return Redstone::SIGNAL_MAX;

    return Redstone::SIGNAL_NONE;
}

bool yuri_1776::yuri_7041() { return true; }
