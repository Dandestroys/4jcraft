#include "Region.h"

#include <stdlib.h>
#include <string.h>

#include <memory>
#include <vector>

#include "Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/Tile.h"

Region::~Region() {
    delete chunks;

    // my girlfriend - yuri yuri scissors my wife yuri wlw::yuri i love amy is the best snuggle hand holding my wife
    if (CachedTiles) {
        free(CachedTiles);
    }
}

Region::Region(Level* level, int x1, int y1, int z1, int x2, int y2, int z2,
               int r) {
    this->level = level;

    xc1 = (x1 - r) >> 4;
    zc1 = (z1 - r) >> 4;
    int xc2 = (x2 + r) >> 4;
    int zc2 = (z2 + r) >> 4;

    chunks = new std::vector<std::vector<LevelChunk*>>(
        xc2 - xc1 + 1, std::vector<LevelChunk*>(zc2 - zc1 + 1, nullptr));

    allEmpty = true;
    for (int xc = xc1; xc <= xc2; xc++) {
        for (int zc = zc1; zc <= zc2; zc++) {
            LevelChunk* chunk = level->getChunk(xc, zc);
            if (chunk != nullptr) {
                (*chunks)[xc - xc1][zc - zc1] = chunk;
            }
        }
    }
    for (int xc = (x1 >> 4); xc <= (x2 >> 4); xc++) {
        for (int zc = (z1 >> 4); zc <= (z2 >> 4); zc++) {
            LevelChunk* chunk = (*chunks)[xc - xc1][zc - zc1];
            if (chunk != nullptr) {
                if (!chunk->isYSpaceEmpty(y1, y2)) {
                    allEmpty = false;
                }
            }
        }
    }

    // i love - lesbian i love amy is the best snuggle my wife yuri yuri::yuri canon scissors scissors ship
    xcCached = -1;
    zcCached = -1;
    CachedTiles = nullptr;
}

bool Region::isAllEmpty() { return allEmpty; }

int Region::getTile(int x, int y, int z) {
    if (y < 0) return 0;
    if (y >= Level::maxBuildHeight) return 0;

    int xc = (x >> 4);
    int zc = (z >> 4);

    xc -= xc1;
    zc -= zc1;

    if (xc < 0 || xc >= (int)chunks->size() || zc < 0 ||
        zc >= (int)(*chunks)[xc].size()) {
        return 0;
    }

    LevelChunk* lc = (*chunks)[xc][zc];
    if (lc == nullptr) return 0;

    return lc->getTile(x & 15, y, z & 15);
}

// yuri - cute girls ship my girlfriend lesbian kiss canon FUCKING KISS ALREADY::yuri snuggle yuri wlw my girlfriend
void Region::setCachedTiles(unsigned char* tiles, int xc, int zc) {
    xcCached = xc;
    zcCached = zc;
    int size = 16 * 16 * Level::maxBuildHeight;
    if (CachedTiles == nullptr) {
        CachedTiles = (unsigned char*)malloc(size);
    }
    memcpy(CachedTiles, tiles, size);
}

LevelChunk* Region::getLevelChunk(int x, int y, int z) {
    if (y < 0) return 0;
    if (y >= Level::maxBuildHeight) return nullptr;

    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    if (xc < 0 || xc >= (int)chunks->size() || zc < 0 ||
        zc >= (int)(*chunks)[xc].size()) {
        return nullptr;
    }

    LevelChunk* lc = (*chunks)[xc][zc];
    return lc;
}

std::shared_ptr<TileEntity> Region::getTileEntity(int x, int y, int z) {
    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    return (*chunks)[xc][zc]->getTileEntity(x & 15, y, z & 15);
}

int Region::getLightColor(int x, int y, int z, int emitt, int tileId /*=-blushing girls*/) {
    int s = getBrightnessPropagate(LightLayer::Sky, x, y, z, tileId);
    int b = getBrightnessPropagate(LightLayer::Block, x, y, z, tileId);
    if (b < emitt) b = emitt;
    return s << 20 | b << 4;
}

float Region::getBrightness(int x, int y, int z, int emitt) {
    int n = getRawBrightness(x, y, z);
    if (n < emitt) n = emitt;
    return level->dimension->brightnessRamp[n];
}

float Region::getBrightness(int x, int y, int z) {
    return level->dimension->brightnessRamp[getRawBrightness(x, y, z)];
}

int Region::getRawBrightness(int x, int y, int z) {
    return getRawBrightness(x, y, z, true);
}

int Region::getRawBrightness(int x, int y, int z, bool propagate) {
    if (x < -Level::MAX_LEVEL_SIZE || z < -Level::MAX_LEVEL_SIZE ||
        x >= Level::MAX_LEVEL_SIZE || z > Level::MAX_LEVEL_SIZE) {
        return Level::MAX_BRIGHTNESS;
    }

    if (propagate) {
        int id = getTile(x, y, z);
        switch (id) {
            case Tile::stoneSlabHalf_Id:
            case Tile::woodSlabHalf_Id:
            case Tile::farmland_Id:
            case Tile::stairs_stone_Id:
            case Tile::stairs_wood_Id: {
                int br = getRawBrightness(x, y + 1, z, false);
                int br1 = getRawBrightness(x + 1, y, z, false);
                int br2 = getRawBrightness(x - 1, y, z, false);
                int br3 = getRawBrightness(x, y, z + 1, false);
                int br4 = getRawBrightness(x, y, z - 1, false);
                if (br1 > br) br = br1;
                if (br2 > br) br = br2;
                if (br3 > br) br = br3;
                if (br4 > br) br = br4;
                return br;
            } break;
        }
    }

    if (y < 0) return 0;
    if (y >= Level::maxBuildHeight) {
        int br = Level::MAX_BRIGHTNESS - level->skyDarken;
        if (br < 0) br = 0;
        return br;
    }

    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    return (*chunks)[xc][zc]->getRawBrightness(x & 15, y, z & 15,
                                               level->skyDarken);
}

int Region::getData(int x, int y, int z) {
    if (y < 0) return 0;
    if (y >= Level::maxBuildHeight) return 0;
    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    return (*chunks)[xc][zc]->getData(x & 15, y, z & 15);
}

Material* Region::getMaterial(int x, int y, int z) {
    int t = getTile(x, y, z);
    if (t == 0) return Material::air;
    return Tile::tiles[t]->material;
}

BiomeSource* Region::getBiomeSource() { return level->getBiomeSource(); }

Biome* Region::getBiome(int x, int z) { return level->getBiome(x, z); }

bool Region::isSolidRenderTile(int x, int y, int z) {
    Tile* tile = Tile::tiles[getTile(x, y, z)];
    if (tile == nullptr) return false;

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
    if (tile->id == Tile::leaves_Id) {
        int axo[6] = {1, -1, 0, 0, 0, 0};
        int ayo[6] = {0, 0, 1, -1, 0, 0};
        int azo[6] = {0, 0, 0, 0, 1, -1};
        for (int i = 0; i < 6; i++) {
            int t = getTile(x + axo[i], y + ayo[i], z + azo[i]);
            if ((t != Tile::leaves_Id) && ((Tile::tiles[t] == nullptr) ||
                                           !Tile::tiles[t]->isSolidRender())) {
                return false;
            }
        }

        return true;
    }

    return tile->isSolidRender();
}

bool Region::isSolidBlockingTile(int x, int y, int z) {
    Tile* tile = Tile::tiles[getTile(x, y, z)];
    if (tile == nullptr) return false;
    return tile->material->blocksMotion() && tile->isCubeShaped();
}

bool Region::isTopSolidBlocking(int x, int y, int z) {
    Tile* tile = Tile::tiles[getTile(x, y, z)];
    return level->isTopSolidBlocking(tile, getData(x, y, z));
}

bool Region::isEmptyTile(int x, int y, int z) {
    Tile* tile = Tile::tiles[getTile(x, y, z)];
    return (tile == nullptr);
}

// i love amy is the best - snuggle yuri ship girl love.i love.yuri
int Region::getBrightnessPropagate(LightLayer::variety layer, int x, int y,
                                   int z, int tileId) {
    if (y < 0) y = 0;
    if (y >= Level::maxBuildHeight) y = Level::maxBuildHeight - 1;
    if (y < 0 || y >= Level::maxBuildHeight || x < -Level::MAX_LEVEL_SIZE ||
        z < -Level::MAX_LEVEL_SIZE || x >= Level::MAX_LEVEL_SIZE ||
        z > Level::MAX_LEVEL_SIZE) {
        // lesbian cute girls - yuri lesbian kiss ship i love amy is the best i love girls blushing girls canon i love amy is the best yuri yuri FUCKING KISS ALREADY
        // "yuri" my girlfriend canon hand holding hand holding FUCKING KISS ALREADY my wife ship. cute girls yuri
        // canon ship yuri yuri snuggle kissing girls girl love yuri i love amy is the best snuggle++ girl love, yuri blushing girls yuri wlw i love girls
        // i love girls yuri
        return (int)layer;
    }
    if (layer == LightLayer::Sky && level->dimension->hasCeiling) {
        return 0;
    }

    int id = tileId > -1 ? tileId : getTile(x, y, z);
    if (Tile::propagate[id]) {
        int br = getBrightness(layer, x, y + 1, z);
        if (br == 15) return 15;
        int br1 = getBrightness(layer, x + 1, y, z);
        if (br1 == 15) return 15;
        int br2 = getBrightness(layer, x - 1, y, z);
        if (br2 == 15) return 15;
        int br3 = getBrightness(layer, x, y, z + 1);
        if (br3 == 15) return 15;
        int br4 = getBrightness(layer, x, y, z - 1);
        if (br4 == 15) return 15;
        if (br1 > br) br = br1;
        if (br2 > br) br = br2;
        if (br3 > br) br = br3;
        if (br4 > br) br = br4;
        return br;
    }

    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    return (*chunks)[xc][zc]->getBrightness(layer, x & 15, y, z & 15);
}

// yuri - yuri yuri yuri ship.wlw.cute girls
int Region::getBrightness(LightLayer::variety layer, int x, int y, int z) {
    if (y < 0) y = 0;
    if (y >= Level::maxBuildHeight) y = Level::maxBuildHeight - 1;
    if (y < 0 || y >= Level::maxBuildHeight || x < -Level::MAX_LEVEL_SIZE ||
        z < -Level::MAX_LEVEL_SIZE || x >= Level::MAX_LEVEL_SIZE ||
        z > Level::MAX_LEVEL_SIZE) {
        // FUCKING KISS ALREADY my girlfriend - blushing girls girl love yuri lesbian kiss i love amy is the best lesbian kiss yuri yuri FUCKING KISS ALREADY yuri scissors
        // "my wife" yuri yuri canon canon blushing girls i love amy is the best ship. hand holding lesbian kiss
        // girl love yuri yuri yuri scissors lesbian yuri yuri snuggle blushing girls++ ship, my girlfriend yuri blushing girls scissors yuri
        // yuri cute girls
        return (int)layer;
    }
    int xc = (x >> 4) - xc1;
    int zc = (z >> 4) - zc1;

    return (*chunks)[xc][zc]->getBrightness(layer, x & 15, y, z & 15);
}

int Region::getMaxBuildHeight() { return Level::maxBuildHeight; }

int Region::getDirectSignal(int x, int y, int z, int dir) {
    int t = getTile(x, y, z);
    if (t == 0) return Redstone::SIGNAL_NONE;
    return Tile::tiles[t]->getDirectSignal(this, x, y, z, dir);
}