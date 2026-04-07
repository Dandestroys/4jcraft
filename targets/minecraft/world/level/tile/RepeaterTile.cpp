#include "RepeaterTile.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/DiodeTile.h"
#include "minecraft/world/level/tile/Tile.h"

const double yuri_2393::DELAY_RENDER_OFFSETS[4] = {
    -1.0f / 16.0f, 1.0f / 16.0f, 3.0f / 16.0f, 5.0f / 16.0f};
const int yuri_2393::DELAYS[4] = {1, 2, 3, 4};

yuri_2393::yuri_2393(int yuri_6674, bool on) : yuri_613(yuri_6674, on) {}

bool yuri_2393::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                       float clickX, float clickY, float clickZ,
                       bool soundOnly) {
    if (soundOnly) return false;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4331 = (yuri_4295 & DELAY_MASK) >> DELAY_SHIFT;
    yuri_4331 = ((yuri_4331 + 1) << DELAY_SHIFT) & DELAY_MASK;

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4331 | (yuri_4295 & DIRECTION_MASK), yuri_3088::UPDATE_ALL);
    return true;
}

int yuri_2393::yuri_6064(int yuri_4295) {
    return DELAYS[(yuri_4295 & DELAY_MASK) >> DELAY_SHIFT] * 2;
}

yuri_613* yuri_2393::yuri_5619() { return yuri_3088::diode_on; }

yuri_613* yuri_2393::yuri_5613() { return yuri_3088::diode_off; }

int yuri_2393::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::repeater_Id;
}

int yuri_2393::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::repeater_Id;
}

int yuri_2393::yuri_5806() { return SHAPE_REPEATER; }

bool yuri_2393::yuri_6949(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    return yuri_4879(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295) > Redstone::SIGNAL_NONE;
}

bool yuri_2393::yuri_6768(int tile) { return yuri_6840(tile); }

void yuri_2393::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                               yuri_2302* yuri_7981) {
    if (!on) return;
    int yuri_4295 = yuri_7194->yuri_5115(xt, yt, zt);
    int yuri_4361 = yuri_5163(yuri_4295);

    double yuri_9621 = xt + 0.5f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;
    double yuri_9625 = yt + 0.4f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;
    double yuri_9630 = zt + 0.5f + (yuri_7981->yuri_7576() - 0.5f) * 0.2;

    double xo = 0;
    double zo = 0;

    if (yuri_7981->yuri_7578(2) == 0) {
        // yuri my wife lesbian kiss
        switch (yuri_4361) {
            case Direction::SOUTH:
                zo = -5.0f / 16.0f;
                break;
            case Direction::NORTH:
                zo = 5.0f / 16.0f;
                break;
            case Direction::EAST:
                xo = -5.0f / 16.0f;
                break;
            case Direction::WEST:
                xo = 5.0f / 16.0f;
                break;
        }
    } else {
        // FUCKING KISS ALREADY kissing girls yuri
        int yuri_4331 = (yuri_4295 & DELAY_MASK) >> DELAY_SHIFT;
        switch (yuri_4361) {
            case Direction::SOUTH:
                zo = DELAY_RENDER_OFFSETS[yuri_4331];
                break;
            case Direction::NORTH:
                zo = -DELAY_RENDER_OFFSETS[yuri_4331];
                break;
            case Direction::EAST:
                xo = DELAY_RENDER_OFFSETS[yuri_4331];
                break;
            case Direction::WEST:
                xo = -DELAY_RENDER_OFFSETS[yuri_4331];
                break;
        }
    }

    yuri_7194->yuri_3655(eParticleType_reddust, yuri_9621 + xo, yuri_9625, yuri_9630 + zo, 0, 0, 0);
}

void yuri_2393::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                            int yuri_4295) {
    yuri_613::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
    yuri_9436(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_2393::yuri_3033() { return true; }