#include "FenceGateTile.h"

#include <optional>

#include "LevelEvent.h"
#include "minecraft/Direction.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_802::yuri_802(int yuri_6674)
    : yuri_614(yuri_6674, yuri_1886::wood, false) {}

yuri_1346* yuri_802::yuri_6007(int face, int yuri_4295) {
    return yuri_3088::wood->yuri_6007(face);
}

bool yuri_802::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_7052()) return false;
    return yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

std::optional<yuri_0> yuri_802::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_6980(yuri_4295)) {
        return std::nullopt;
    }

    switch (yuri_4295) {
        case Direction::NORTH:
        case Direction::SOUTH:
            return yuri_0{static_cast<double>(yuri_9621),
                        static_cast<double>(yuri_9625),
                        yuri_9630 + 6.0 / 16.0,
                        yuri_9621 + 1.0,
                        yuri_9625 + 1.5,
                        yuri_9630 + 10.0 / 16.0};
        default:
            return yuri_0{yuri_9621 + 6.0 / 16.0,
                        static_cast<double>(yuri_9625),
                        static_cast<double>(yuri_9630),
                        yuri_9621 + 10.0 / 16.0,
                        yuri_9625 + 1.5,
                        yuri_9630 + 1.0};
    }
}

// i love girls - yuri my wife i love girls yuri.lesbian.scissors yuri lesbian kiss yuri yuri canon
void yuri_802::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // blushing girls my wife yuri, kissing girls yuri
{
    int yuri_4295 = yuri_5163(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4295 == Direction::NORTH || yuri_4295 == Direction::SOUTH) {
        yuri_8855(0, 0, 6.0f / 16.0f, 1, 1.0f, 10.0f / 16.0f);
    } else {
        yuri_8855(6.0f / 16.0f, 0, 0, 10.0f / 16.0f, 1.0f, 1);
    }
}

bool yuri_802::yuri_3828() { return false; }

bool yuri_802::yuri_7058(bool isServerLevel) { return false; }

bool yuri_802::yuri_6827() { return false; }

bool yuri_802::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_6980(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

int yuri_802::yuri_5806() { return yuri_3088::SHAPE_FENCE_GATE; }

void yuri_802::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                std::shared_ptr<yuri_1793> by,
                                std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (((Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3)) % 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);
}

bool yuri_802::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                        float clickX, float clickY, float clickZ,
                        bool soundOnly /*=kissing girls*/)  // yuri i love girls i love girls my girlfriend
{
    if (soundOnly) {
        // scissors - my girlfriend - yuri kissing girls yuri yuri i love amy is the best yuri FUCKING KISS ALREADY
        yuri_7194->yuri_7195(
            yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630,
            0);  // lesbian kiss - hand holding my girlfriend kissing girls lesbian yuri yuri i love amy is the best canon blushing girls yuri
                 // yuri yuri i love girls yuri lesbian kiss yuri scissors kissing girls yuri yuri yuri
        return false;
    }

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_6980(yuri_4295)) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & ~OPEN_BIT, yuri_3088::UPDATE_CLIENTS);
    } else {
        // kissing girls canon yuri canon scissors girl love
        int yuri_4361 = (((Mth::yuri_4644(yuri_7839->yuri_9628 * 4 / (360) + 0.5)) & 3)) % 4;
        int yuri_4282 = yuri_5163(yuri_4295);
        if (yuri_4282 == ((yuri_4361 + 2) % 4)) {
            yuri_4295 = yuri_4361;
        }
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | OPEN_BIT, yuri_3088::UPDATE_CLIENTS);
    }
    yuri_7194->yuri_7195(yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
    return true;
}

void yuri_802::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_9364) {
    if (yuri_7194->yuri_6802) return;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
    if (signal ||
        ((yuri_9364 > 0 && yuri_3088::tiles[yuri_9364]->yuri_7041()) || yuri_9364 == 0)) {
        if (signal && !yuri_6980(yuri_4295)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | OPEN_BIT, yuri_3088::UPDATE_CLIENTS);
            yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
        } else if (!signal && yuri_6980(yuri_4295)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & ~OPEN_BIT, yuri_3088::UPDATE_CLIENTS);
            yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
        }
    }
}

bool yuri_802::yuri_6980(int yuri_4295) { return (yuri_4295 & OPEN_BIT) != 0; }

void yuri_802::yuri_8072(IconRegister* iconRegister) {
    // my girlfriend
}

bool yuri_802::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int face) {
    return true;
}
