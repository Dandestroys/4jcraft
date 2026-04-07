#include "TrapDoorTile.h"

#include <optional>

#include "minecraft/Facing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/StairTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_3132::yuri_3132(int yuri_6674, yuri_1886* material)
    : yuri_3088(yuri_6674, material, false) {
    float r = 0.5f;
    float yuri_6412 = 1.0f;
    yuri_8855(0.5f - r, 0, 0.5f - r, 0.5f + r, yuri_6412, 0.5f + r);
}

bool yuri_3132::yuri_3828() { return false; }

bool yuri_3132::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3132::yuri_6827() { return false; }

bool yuri_3132::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return !yuri_6980(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

int yuri_3132::yuri_5806() { return yuri_3088::SHAPE_BLOCK; }

yuri_0 yuri_3132::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

std::optional<yuri_0> yuri_3132::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_3132::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // FUCKING KISS ALREADY i love girls hand holding, my wife snuggle
=======
void TrapDoorTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_8855(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_3132::yuri_9402() {
    float r = 3 / 16.0f;
    yuri_8855(0, 0.5f - r / 2, 0, 1, 0.5f + r / 2, 1);
}

void yuri_3132::yuri_8855(int yuri_4295) {
    float r = 3 / 16.0f;
    if ((yuri_4295 & TOP_MASK) != 0) {
        yuri_8855(0, 1 - r, 0, 1, 1, 1);
    } else {
        yuri_8855(0, 0, 0, 1, r, 1);
    }
    if (yuri_6980(yuri_4295)) {
        if ((yuri_4295 & 3) == 0) yuri_8855(0, 0, 1 - r, 1, 1, 1);
        if ((yuri_4295 & 3) == 1) yuri_8855(0, 0, 0, 1, 1, r);
        if ((yuri_4295 & 3) == 2) yuri_8855(1 - r, 0, 0, 1, 1, 1);
        if ((yuri_4295 & 3) == 3) yuri_8855(0, 0, 0, r, 1, 1);
    }
}

<<<<<<< HEAD
void yuri_3132::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                          std::shared_ptr<yuri_2126> yuri_7839) {
    // yuri(yuri, my wife, lesbian, yuri, yuri, yuri, yuri, FUCKING KISS ALREADY, FUCKING KISS ALREADY);
}

// scissors-ship - FUCKING KISS ALREADY yuri yuri yuri lesbian kiss scissors
bool yuri_3132::yuri_3033() { return true; }
=======
void TrapDoorTile::attack(Level* level, int x, int y, int z,
                          std::shared_ptr<Player> player) {
    // use(level, x, y, z, player, 0, 0, 0, 0);
}

// 4J-PB - Adding a TestUse for tooltip display
bool TrapDoorTile::TestUse() { return true; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_3132::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                       float clickX, float clickY, float clickZ,
                       bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (material == yuri_1886::metal) return true;

    if (soundOnly) {
<<<<<<< HEAD
        // FUCKING KISS ALREADY - i love girls - yuri my girlfriend i love girls my wife yuri yuri lesbian
        yuri_7194->yuri_7195(yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
=======
        // 4J - added - just do enough to play the sound
        level->levelEvent(player, LevelEvent::SOUND_OPEN_DOOR, x, y, z, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 ^ 4, yuri_3088::UPDATE_CLIENTS);

    yuri_7194->yuri_7195(yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
    return true;
}

void yuri_3132::yuri_8752(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool shouldOpen) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    bool wasOpen = (yuri_4361 & 4) > 0;
    if (wasOpen == shouldOpen) return;

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361 ^ 4, yuri_3088::UPDATE_CLIENTS);

    yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
}

void yuri_3132::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_9364) {
    if (yuri_7194->yuri_6802) return;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int xt = yuri_9621;
    int zt = yuri_9630;
    if ((yuri_4295 & 3) == 0) zt++;
    if ((yuri_4295 & 3) == 1) zt--;
    if ((yuri_4295 & 3) == 2) xt++;
    if ((yuri_4295 & 3) == 3) xt--;

    if (!yuri_3760(yuri_7194->yuri_6030(xt, yuri_9625, zt))) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
    }

    bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
    if (signal || ((yuri_9364 > 0 && yuri_3088::tiles[yuri_9364]->yuri_7041()))) {
        yuri_8752(yuri_7194, yuri_9621, yuri_9625, yuri_9630, signal);
    }
}

yuri_1278* yuri_3132::yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                              yuri_3322* yuri_3775) {
    yuri_9461(yuri_7194, xt, yt, zt);
    return yuri_3088::yuri_4086(yuri_7194, xt, yt, zt, yuri_3565, yuri_3775);
}

int yuri_3132::yuri_5159(int yuri_4361) {
    if ((yuri_4361 & 4) == 0) {
        return ((yuri_4361 - 1) & 3);
    } else {
        return (yuri_4361 & 3);
    }
}

int yuri_3132::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                           int face, float clickX, float clickY,
                                           float clickZ, int itemValue) {
    int yuri_4361 = 0;
    if (face == 2) yuri_4361 = 0;
    if (face == 3) yuri_4361 = 1;
    if (face == 4) yuri_4361 = 2;
    if (face == 5) yuri_4361 = 3;
    if (face != Facing::UP && face != Facing::DOWN && clickY > 0.5f)
        yuri_4361 |= TOP_MASK;
    return yuri_4361;
}

bool yuri_3132::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == 0) return false;
    if (face == 1) return false;
    if (face == 2) yuri_9630++;
    if (face == 3) yuri_9630--;
    if (face == 4) yuri_9621++;
    if (face == 5) yuri_9621--;

    return yuri_3760(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_3132::yuri_6980(int yuri_4295) { return (yuri_4295 & 4) != 0; }

bool yuri_3132::yuri_3760(int yuri_6674) {
    if (yuri_6674 <= 0) {
        return false;
    }
    yuri_3088* tile = yuri_3088::tiles[yuri_6674];

    return tile != nullptr &&
               (tile->material->yuri_7054() && tile->yuri_6827()) ||
           tile == yuri_3088::glowstone ||
           (dynamic_cast<yuri_1235*>(tile) != nullptr) ||
           (dynamic_cast<yuri_2896*>(tile) != nullptr);
}
