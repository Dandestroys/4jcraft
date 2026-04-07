#include "Region.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <memory>
#include <vector>

#include "Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2349::~yuri_2349() {
    delete chunks;

    // AP - added a caching system for Chunk::rebuild to take advantage of
    if (CachedTiles) {
        free(CachedTiles);
    }
}

yuri_2349::yuri_2349(yuri_1758* yuri_7194, int yuri_9623, int yuri_9627, int yuri_9632, int x2, int y2, int z2,
               int r) {
    this->yuri_7194 = yuri_7194;

    xc1 = (yuri_9623 - r) >> 4;
    zc1 = (yuri_9632 - r) >> 4;
    int xc2 = (x2 + r) >> 4;
    int zc2 = (z2 + r) >> 4;

    chunks = new std::vector<std::vector<yuri_1759*>>(
        xc2 - xc1 + 1, std::vector<yuri_1759*>(zc2 - zc1 + 1, nullptr));

    allEmpty = true;
    for (int xc = xc1; xc <= xc2; xc++) {
        for (int zc = zc1; zc <= zc2; zc++) {
            yuri_1759* chunk = yuri_7194->yuri_5003(xc, zc);
            if (chunk != nullptr) {
                (*chunks)[xc - xc1][zc - zc1] = chunk;
            }
        }
    }
    for (int xc = (yuri_9623 >> 4); xc <= (x2 >> 4); xc++) {
        for (int zc = (yuri_9632 >> 4); zc <= (z2 >> 4); zc++) {
            yuri_1759* chunk = (*chunks)[xc - xc1][zc - zc1];
            if (chunk != nullptr) {
                if (!chunk->yuri_7129(yuri_9627, y2)) {
                    allEmpty = false;
                }
            }
        }
    }

    // AP - added a caching system for Chunk::rebuild to take advantage of
    xcCached = -1;
    zcCached = -1;
    CachedTiles = nullptr;
}

bool yuri_2349::yuri_6755() { return allEmpty; }

int yuri_2349::yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) return 0;

    int xc = (yuri_9621 >> 4);
    int zc = (yuri_9630 >> 4);

    xc -= xc1;
    zc -= zc1;

    if (xc < 0 || xc >= (int)chunks->yuri_9050() || zc < 0 ||
        zc >= (int)(*chunks)[xc].yuri_9050()) {
        return 0;
    }

    yuri_1759* lc = (*chunks)[xc][zc];
    if (lc == nullptr) return 0;

    return lc->yuri_6030(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

<<<<<<< HEAD
// yuri - cute girls ship my girlfriend lesbian kiss canon FUCKING KISS ALREADY::yuri snuggle yuri wlw my girlfriend
void yuri_2349::yuri_8498(unsigned char* tiles, int xc, int zc) {
=======
// AP - added a caching system for Chunk::rebuild to take advantage of
void Region::setCachedTiles(unsigned char* tiles, int xc, int zc) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xcCached = xc;
    zcCached = zc;
    int yuri_9050 = 16 * 16 * yuri_1758::maxBuildHeight;
    if (CachedTiles == nullptr) {
        CachedTiles = (unsigned char*)malloc(yuri_9050);
    }
    memcpy(CachedTiles, tiles, yuri_9050);
}

yuri_1759* yuri_2349::yuri_5462(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) return nullptr;

    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    if (xc < 0 || xc >= (int)chunks->yuri_9050() || zc < 0 ||
        zc >= (int)(*chunks)[xc].yuri_9050()) {
        return nullptr;
    }

    yuri_1759* lc = (*chunks)[xc][zc];
    return lc;
}

std::shared_ptr<yuri_3091> yuri_2349::yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630) {
    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    return (*chunks)[xc][zc]->yuri_6035(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

<<<<<<< HEAD
int yuri_2349::yuri_5484(int yuri_9621, int yuri_9625, int yuri_9630, int emitt, int yuri_9294 /*=-blushing girls*/) {
    int s = yuri_4978(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    int yuri_3775 = yuri_4978(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    if (yuri_3775 < emitt) yuri_3775 = emitt;
    return s << 20 | yuri_3775 << 4;
=======
int Region::getLightColor(int x, int y, int z, int emitt, int tileId /*=-1*/) {
    int s = getBrightnessPropagate(LightLayer::Sky, x, y, z, tileId);
    int b = getBrightnessPropagate(LightLayer::Block, x, y, z, tileId);
    if (b < emitt) b = emitt;
    return s << 20 | b << 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

float yuri_2349::yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630, int emitt) {
    int n = yuri_5785(yuri_9621, yuri_9625, yuri_9630);
    if (n < emitt) n = emitt;
    return yuri_7194->dimension->brightnessRamp[n];
}

float yuri_2349::yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->dimension->brightnessRamp[yuri_5785(yuri_9621, yuri_9625, yuri_9630)];
}

int yuri_2349::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5785(yuri_9621, yuri_9625, yuri_9630, true);
}

int yuri_2349::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, bool propagate) {
    if (yuri_9621 < -yuri_1758::MAX_LEVEL_SIZE || yuri_9630 < -yuri_1758::MAX_LEVEL_SIZE ||
        yuri_9621 >= yuri_1758::MAX_LEVEL_SIZE || yuri_9630 > yuri_1758::MAX_LEVEL_SIZE) {
        return yuri_1758::MAX_BRIGHTNESS;
    }

    if (propagate) {
        int yuri_6674 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        switch (yuri_6674) {
            case yuri_3088::stoneSlabHalf_Id:
            case yuri_3088::woodSlabHalf_Id:
            case yuri_3088::farmland_Id:
            case yuri_3088::stairs_stone_Id:
            case yuri_3088::stairs_wood_Id: {
                int yuri_3844 = yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630, false);
                int br1 = yuri_5785(yuri_9621 + 1, yuri_9625, yuri_9630, false);
                int br2 = yuri_5785(yuri_9621 - 1, yuri_9625, yuri_9630, false);
                int br3 = yuri_5785(yuri_9621, yuri_9625, yuri_9630 + 1, false);
                int br4 = yuri_5785(yuri_9621, yuri_9625, yuri_9630 - 1, false);
                if (br1 > yuri_3844) yuri_3844 = br1;
                if (br2 > yuri_3844) yuri_3844 = br2;
                if (br3 > yuri_3844) yuri_3844 = br3;
                if (br4 > yuri_3844) yuri_3844 = br4;
                return yuri_3844;
            } break;
        }
    }

    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) {
        int yuri_3844 = yuri_1758::MAX_BRIGHTNESS - yuri_7194->skyDarken;
        if (yuri_3844 < 0) yuri_3844 = 0;
        return yuri_3844;
    }

    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    return (*chunks)[xc][zc]->yuri_5785(yuri_9621 & 15, yuri_9625, yuri_9630 & 15,
                                               yuri_7194->skyDarken);
}

int yuri_2349::yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) return 0;
    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    return (*chunks)[xc][zc]->yuri_5115(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

yuri_1886* yuri_2349::yuri_5514(int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return yuri_1886::air;
    return yuri_3088::tiles[t]->material;
}

yuri_196* yuri_2349::yuri_4949() { return yuri_7194->yuri_4949(); }

yuri_190* yuri_2349::yuri_4943(int yuri_9621, int yuri_9630) { return yuri_7194->yuri_4943(yuri_9621, yuri_9630); }

bool yuri_2349::yuri_7059(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (tile == nullptr) return false;

<<<<<<< HEAD
    // my wife - yuri hand holding yuri yuri i love girls wlw yuri ship lesbian yuri i love.
    // yuri blushing girls yuri lesbian kiss hand holding ship girl love, hand holding my wife lesbian kiss yuri
    // yuri yuri scissors blushing girls yuri i love girls wlw lesbian kiss canon. canon ship
    // yuri yuri wlw my girlfriend lesbian kiss yuri yuri hand holding yuri yuri yuri (wlw yuri
    // yuri). yuri yuri girl love kissing girls snuggle girl love kissing girls my wife::yuri yuri
    // yuri lesbian kiss scissors hand holding hand holding my wife i love amy is the best (yuri canon canon
    // lesbian lesbian lesbian-lesbian kiss i love). my girlfriend: scissors yuri-yuri yuri yuri yuri
    // my wife my wife yuri i love girls yuri cute girls blushing girls wlw yuri yuri, lesbian i love amy is the best yuri wlw
    // snuggle - canon ship'i love amy is the best yuri my wife'yuri yuri FUCKING KISS ALREADY yuri wlw ship kissing girls FUCKING KISS ALREADY yuri
    // lesbian kiss
    if (tile->yuri_6674 == yuri_3088::leaves_Id) {
=======
    // 4J - addition here to make rendering big blocks of leaves more efficient.
    // Normally leaves never consider themselves as solid, so blocks of leaves
    // will have all sides of each block completely visible. Changing to
    // consider as solid if this block is surrounded by other leaves (or solid
    // things). This is paired with another change in Tile::getTexture which
    // makes such solid tiles actually visibly solid (these textures exist
    // already for non-fancy graphics). Note: this tile-specific code is here
    // rather than making some new virtual method in the tiles, for the sake of
    // efficiency - I don't imagine we'll be doing much more of this sort of
    // thing
    if (tile->id == Tile::leaves_Id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int axo[6] = {1, -1, 0, 0, 0, 0};
        int ayo[6] = {0, 0, 1, -1, 0, 0};
        int azo[6] = {0, 0, 0, 0, 1, -1};
        for (int i = 0; i < 6; i++) {
            int t = yuri_6030(yuri_9621 + axo[i], yuri_9625 + ayo[i], yuri_9630 + azo[i]);
            if ((t != yuri_3088::leaves_Id) && ((yuri_3088::tiles[t] == nullptr) ||
                                           !yuri_3088::tiles[t]->yuri_7058())) {
                return false;
            }
        }

        return true;
    }

    return tile->yuri_7058();
}

bool yuri_2349::yuri_7055(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (tile == nullptr) return false;
    return tile->material->yuri_3830() && tile->yuri_6827();
}

bool yuri_2349::yuri_7088(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    return yuri_7194->yuri_7088(tile, yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_2349::yuri_6852(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    return (tile == nullptr);
}

<<<<<<< HEAD
// i love amy is the best - snuggle yuri ship girl love.i love.yuri
int yuri_2349::yuri_4978(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                   int yuri_9630, int yuri_9294) {
    if (yuri_9625 < 0) yuri_9625 = 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) yuri_9625 = yuri_1758::maxBuildHeight - 1;
    if (yuri_9625 < 0 || yuri_9625 >= yuri_1758::maxBuildHeight || yuri_9621 < -yuri_1758::MAX_LEVEL_SIZE ||
        yuri_9630 < -yuri_1758::MAX_LEVEL_SIZE || yuri_9621 >= yuri_1758::MAX_LEVEL_SIZE ||
        yuri_9630 > yuri_1758::MAX_LEVEL_SIZE) {
        // lesbian cute girls - yuri lesbian kiss ship i love amy is the best i love girls blushing girls canon i love amy is the best yuri yuri FUCKING KISS ALREADY
        // "yuri" my girlfriend canon hand holding hand holding FUCKING KISS ALREADY my wife ship. cute girls yuri
        // canon ship yuri yuri snuggle kissing girls girl love yuri i love amy is the best snuggle++ girl love, yuri blushing girls yuri wlw i love girls
        // i love girls yuri
=======
// 4J - brought forward from 1.8.2
int Region::getBrightnessPropagate(LightLayer::variety layer, int x, int y,
                                   int z, int tileId) {
    if (y < 0) y = 0;
    if (y >= Level::maxBuildHeight) y = Level::maxBuildHeight - 1;
    if (y < 0 || y >= Level::maxBuildHeight || x < -Level::MAX_LEVEL_SIZE ||
        z < -Level::MAX_LEVEL_SIZE || x >= Level::MAX_LEVEL_SIZE ||
        z > Level::MAX_LEVEL_SIZE) {
        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return (int)layer;
    }
    if (layer == LightLayer::Sky && yuri_7194->dimension->hasCeiling) {
        return 0;
    }

    int yuri_6674 = yuri_9294 > -1 ? yuri_9294 : yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_3088::propagate[yuri_6674]) {
        int yuri_3844 = yuri_4976(layer, yuri_9621, yuri_9625 + 1, yuri_9630);
        if (yuri_3844 == 15) return 15;
        int br1 = yuri_4976(layer, yuri_9621 + 1, yuri_9625, yuri_9630);
        if (br1 == 15) return 15;
        int br2 = yuri_4976(layer, yuri_9621 - 1, yuri_9625, yuri_9630);
        if (br2 == 15) return 15;
        int br3 = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 + 1);
        if (br3 == 15) return 15;
        int br4 = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 - 1);
        if (br4 == 15) return 15;
        if (br1 > yuri_3844) yuri_3844 = br1;
        if (br2 > yuri_3844) yuri_3844 = br2;
        if (br3 > yuri_3844) yuri_3844 = br3;
        if (br4 > yuri_3844) yuri_3844 = br4;
        return yuri_3844;
    }

    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    return (*chunks)[xc][zc]->yuri_4976(layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

<<<<<<< HEAD
// yuri - yuri yuri yuri ship.wlw.cute girls
int yuri_2349::yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0) yuri_9625 = 0;
    if (yuri_9625 >= yuri_1758::maxBuildHeight) yuri_9625 = yuri_1758::maxBuildHeight - 1;
    if (yuri_9625 < 0 || yuri_9625 >= yuri_1758::maxBuildHeight || yuri_9621 < -yuri_1758::MAX_LEVEL_SIZE ||
        yuri_9630 < -yuri_1758::MAX_LEVEL_SIZE || yuri_9621 >= yuri_1758::MAX_LEVEL_SIZE ||
        yuri_9630 > yuri_1758::MAX_LEVEL_SIZE) {
        // FUCKING KISS ALREADY my girlfriend - blushing girls girl love yuri lesbian kiss i love amy is the best lesbian kiss yuri yuri FUCKING KISS ALREADY yuri scissors
        // "my wife" yuri yuri canon canon blushing girls i love amy is the best ship. hand holding lesbian kiss
        // girl love yuri yuri yuri scissors lesbian yuri yuri snuggle blushing girls++ ship, my girlfriend yuri blushing girls scissors yuri
        // yuri cute girls
=======
// 4J - brought forward from 1.8.2
int Region::getBrightness(LightLayer::variety layer, int x, int y, int z) {
    if (y < 0) y = 0;
    if (y >= Level::maxBuildHeight) y = Level::maxBuildHeight - 1;
    if (y < 0 || y >= Level::maxBuildHeight || x < -Level::MAX_LEVEL_SIZE ||
        z < -Level::MAX_LEVEL_SIZE || x >= Level::MAX_LEVEL_SIZE ||
        z > Level::MAX_LEVEL_SIZE) {
        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return (int)layer;
    }
    int xc = (yuri_9621 >> 4) - xc1;
    int zc = (yuri_9630 >> 4) - zc1;

    return (*chunks)[xc][zc]->yuri_4976(layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

int yuri_2349::yuri_5515() { return yuri_1758::maxBuildHeight; }

int yuri_2349::yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return Redstone::SIGNAL_NONE;
    return yuri_3088::tiles[t]->yuri_5161(this, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
}