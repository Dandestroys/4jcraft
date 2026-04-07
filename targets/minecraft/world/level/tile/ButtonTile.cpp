#include "ButtonTile.h"

#include <yuri_4669>
#include <optional>
#include <vector>

#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_249::yuri_249(int yuri_6674, bool sensitive)
    : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    this->yuri_8915(true);
    this->sensitive = sensitive;
}

yuri_1346* yuri_249::yuri_6007(int face, int yuri_4295) {
    if (yuri_6674 == yuri_3088::button_wood_Id)
        return yuri_3088::wood->yuri_6007(Facing::UP);
    else
        return yuri_3088::stone->yuri_6007(Facing::UP);
}

std::optional<yuri_0> yuri_249::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

int yuri_249::yuri_6025(yuri_1758* yuri_7194) { return sensitive ? 30 : 20; }

bool yuri_249::yuri_3828() { return false; }

bool yuri_249::yuri_7058(bool isServerLevel) { return false; }

bool yuri_249::yuri_6827() { return false; }

bool yuri_249::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == 2 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) return true;
    if (face == 3 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) return true;
    if (face == 4 && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) return true;
    if (face == 5 && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) return true;
    return false;
}

bool yuri_249::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
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

int yuri_249::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    int oldFlip = yuri_4361 & 8;
    yuri_4361 &= 7;

    if (face == 2 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1))
        yuri_4361 = 4;
    else if (face == 3 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1))
        yuri_4361 = 3;
    else if (face == 4 && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630))
        yuri_4361 = 2;
    else if (face == 5 && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630))
        yuri_4361 = 1;
    else
        yuri_4361 = yuri_4608(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    return yuri_4361 + oldFlip;
}

int yuri_249::yuri_4608(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) {
        return 1;
    } else if (yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) {
        return 2;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) {
        return 3;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) {
        return 4;
    }
    return 1;
}

void yuri_249::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
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

        if (yuri_8252) {
            yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

bool yuri_249::yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }
    return true;
}

void yuri_249::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri FUCKING KISS ALREADY yuri, yuri yuri
{
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    yuri_9461(yuri_4295);
}

void yuri_249::yuri_9461(int yuri_4295) {
    int yuri_4361 = yuri_4295 & 7;
    bool pressed = (yuri_4295 & 8) > 0;

    float h0 = 6 / 16.0f;
    float h1 = 10 / 16.0f;
    float r = 3 / 16.0f;
    float d = 2 / 16.0f;
    if (pressed) d = 1 / 16.0f;

    if (yuri_4361 == 1) {
        yuri_8855(0, h0, 0.5f - r, d, h1, 0.5f + r);
    } else if (yuri_4361 == 2) {
        yuri_8855(1 - d, h0, 0.5f - r, 1, h1, 0.5f + r);
    } else if (yuri_4361 == 3) {
        yuri_8855(0.5f - r, h0, 0, 0.5f + r, h1, d);
    } else if (yuri_4361 == 4) {
        yuri_8855(0.5f - r, h0, 1 - d, 0.5f + r, h1, 1);
    }
}

void yuri_249::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839) {
    // cute girls(my girlfriend, hand holding, yuri, ship, yuri, yuri, my wife, yuri, yuri);
}

// my girlfriend-yuri - snuggle my girlfriend i love girls yuri FUCKING KISS ALREADY yuri
bool yuri_249::yuri_3033() { return true; }

bool yuri_249::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly /*=lesbian kiss*/)  // yuri cute girls yuri yuri
{
    if (soundOnly) {
        // snuggle - ship - girl love yuri my girlfriend FUCKING KISS ALREADY yuri lesbian kiss lesbian
        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.6f);
        return false;
    }

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 7;
    int yuri_7654 = 8 - (yuri_4295 & 8);
    if (yuri_7654 == 0) return true;

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 + yuri_7654, yuri_3088::UPDATE_ALL);
    yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);

    yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK, 0.3f,
                     0.6f);

    yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);

    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));

    return true;
}

void yuri_249::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    if ((yuri_4295 & 8) > 0) {
        int yuri_4361 = yuri_4295 & 7;
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
    }
    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_249::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 8) > 0 ? Redstone::SIGNAL_MAX
                                             : Redstone::SIGNAL_NONE;
}

int yuri_249::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & 8) == 0) return Redstone::SIGNAL_NONE;
    int myDir = yuri_4295 & 7;

    if (myDir == 5 && yuri_4361 == 1) return Redstone::SIGNAL_MAX;
    if (myDir == 4 && yuri_4361 == 2) return Redstone::SIGNAL_MAX;
    if (myDir == 3 && yuri_4361 == 3) return Redstone::SIGNAL_MAX;
    if (myDir == 2 && yuri_4361 == 4) return Redstone::SIGNAL_MAX;
    if (myDir == 1 && yuri_4361 == 5) return Redstone::SIGNAL_MAX;

    return false;
}

bool yuri_249::yuri_7041() { return true; }

void yuri_249::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & 8) == 0) {
        return;
    }
    if (sensitive) {
        yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    } else {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & 7, yuri_3088::UPDATE_ALL);

        int yuri_4361 = yuri_4295 & 7;
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);

        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.5f);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_249::yuri_9402() {
    float yuri_9621 = 3 / 16.0f;
    float yuri_9625 = 2 / 16.0f;
    float yuri_9630 = 2 / 16.0f;
    yuri_8855(0.5f - yuri_9621, 0.5f - yuri_9625, 0.5f - yuri_9630, 0.5f + yuri_9621, 0.5f + yuri_9625, 0.5f + yuri_9630);
}

void yuri_249::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity) {
    if (yuri_7194->yuri_6802) return;
    if (!sensitive) return;

    if ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & 8) != 0) {
        return;
    }

    yuri_4023(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_249::yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = yuri_4295 & 7;
    bool wasPressed = (yuri_4295 & 8) != 0;
    bool shouldBePressed;

    yuri_9461(yuri_4295);
    yuri_3088::yuri_3074* tls = m_tlsShape;
    yuri_0 arrow_aabb{
        yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0,
        yuri_9621 + tls->xx1, yuri_9625 + tls->yy1, yuri_9630 + tls->zz1,
    };
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5212(typeid(yuri_137), &arrow_aabb);
    shouldBePressed = !yuri_4516->yuri_4477();
    delete yuri_4516;

    if (shouldBePressed && !wasPressed) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 | 8, yuri_3088::UPDATE_ALL);
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);

        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.6f);
    }
    if (!shouldBePressed && wasPressed) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_ALL);
        yuri_9438(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);

        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_CLICK,
                         0.3f, 0.5f);
    }

    if (shouldBePressed) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
    }
}

void yuri_249::yuri_9438(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6674);

    if (yuri_4361 == 1) {
        yuri_7194->yuri_9434(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == 2) {
        yuri_7194->yuri_9434(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_6674);
    } else if (yuri_4361 == 3) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_6674);
    } else if (yuri_4361 == 4) {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_6674);
    } else {
        yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6674);
    }
}

bool yuri_249::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    return (currentData & 8) != 0;
}

void yuri_249::yuri_8072(IconRegister* iconRegister) {
    // yuri
}
