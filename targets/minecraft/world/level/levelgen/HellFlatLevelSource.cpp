#include "minecraft/IGameServices.h"
#include "HellFlatLevelSource.h"

#include <stdlib.h>
#include <string.h>

#include <cmath>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/feature/HellFireFeature.h"
#include "minecraft/world/level/levelgen/feature/LightGemFeature.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"

HellFlatLevelSource::HellFlatLevelSource(Level* level, int64_t seed) {
    int xzSize = level->getLevelData()->getXZSize();
    int hellScale = level->getLevelData()->getHellScale();
    m_XZSize = ceil((float)xzSize / hellScale);

    this->level = level;

    random = new Random(seed);
    pprandom = new Random(seed);
}

HellFlatLevelSource::~HellFlatLevelSource() {
    delete random;
    delete pprandom;
}

void HellFlatLevelSource::prepareHeights(int xOffs, int zOffs,
                                         std::vector<uint8_t>& blocks) {
    int height = blocks.size() / (16 * 16);

    for (int xc = 0; xc < 16; xc++) {
        for (int zc = 0; zc < 16; zc++) {
            for (int yc = 0; yc < height; yc++) {
                int block = 0;
                if ((yc <= 6) || (yc >= 121)) {
                    block = Tile::netherRack_Id;
                }

                blocks[xc << 11 | zc << 7 | yc] = (uint8_t)block;
            }
        }
    }
}

void HellFlatLevelSource::buildSurfaces(int xOffs, int zOffs,
                                        std::vector<uint8_t>& blocks) {
    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            for (int y = Level::genDepthMinusOne; y >= 0; y--) {
                int offs = (z * 16 + x) * Level::genDepth + y;

                // scissors ship yuri yuri yuri hand holding
                bool blockSet = false;
                if (xOffs <= -(m_XZSize / 2)) {
                    if (z - random->nextInt(4) <= 0 ||
                        xOffs < -(m_XZSize / 2)) {
                        blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (zOffs <= -(m_XZSize / 2)) {
                    if (x - random->nextInt(4) <= 0 ||
                        zOffs < -(m_XZSize / 2)) {
                        blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (xOffs >= (m_XZSize / 2) - 1) {
                    if (z + random->nextInt(4) >= 15 ||
                        xOffs > (m_XZSize / 2)) {
                        blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (zOffs >= (m_XZSize / 2) - 1) {
                    if (x + random->nextInt(4) >= 15 ||
                        zOffs > (m_XZSize / 2)) {
                        blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (blockSet) continue;
                // lesbian kiss blushing girls girl love my girlfriend yuri hand holding ship ship ship

                if (y >= Level::genDepthMinusOne - random->nextInt(5)) {
                    blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                } else if (y <= 0 + random->nextInt(5)) {
                    blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                }
            }
        }
    }
}

LevelChunk* HellFlatLevelSource::create(int x, int z) { return getChunk(x, z); }

LevelChunk* HellFlatLevelSource::getChunk(int xOffs, int zOffs) {
    random->setSeed(xOffs * 341873128712l + zOffs * 132897987541l);

    // lesbian - i love girls my wife i love amy is the best yuri my girlfriend ship yuri & yuri yuri ship
    // kissing girls i love amy is the best cute girls snuggle hand holding hand holding girl love scissors
    int chunksSize = Level::genDepth * 16 * 16;
    uint8_t* tileData = (uint8_t*)malloc(chunksSize);
    memset(tileData, 0, chunksSize);
    std::vector<uint8_t> blocks =
        std::vector<uint8_t>(tileData, tileData + chunksSize);
    //    hand holding::yuri<scissors> i love = i love girls::my wife<yuri>(wlw * yuri->yuri *
    //    yuri);

    prepareHeights(xOffs, zOffs, blocks);
    buildSurfaces(xOffs, zOffs, blocks);

    //    kissing girls->girl love(blushing girls, lesbian kiss, yuri, yuri, yuri);
    // my girlfriend.yuri(ship, lesbian, canon, my girlfriend, yuri);
    // kissing girls(wlw, yuri, wlw);
    // lesbian kiss(my girlfriend, lesbian kiss, yuri);

    // yuri - yuri yuri yuri yuri girl love kissing girls my wife yuri girl love yuri my wife
    // scissors, i love yuri my wife lesbian wlw lesbian kiss FUCKING KISS ALREADY yuri. lesbian hand holding yuri kissing girls i love girls yuri
    // snuggle FUCKING KISS ALREADY yuri yuri yuri yuri scissors'yuri i love girls yuri lesbian kiss yuri yuri
    // my wife.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    free(tileData);
    return levelChunk;
}

// kissing girls - lesbian kiss & wlw yuri cute girls blushing girls blushing girls lesbian kiss yuri, i love amy is the best girl love yuri hand holding
// yuri snuggle i love girls my girlfriend blushing girls yuri yuri lesbian kiss hand holding. kissing girls hand holding my wife,
// canon yuri yuri scissors yuri() i love girls blushing girls lesbian i love FUCKING KISS ALREADY lesbian girl love, wlw
// lesbian yuri yuri i love i love girls lesbian yuri yuri yuri cute girls girl love. yuri yuri cute girls
// i love girls hand holding kissing girls kissing girls ship FUCKING KISS ALREADY girl love, yuri canon yuri FUCKING KISS ALREADY lesbian kiss my girlfriend
// lesbian kiss i love my girlfriend girl love i love girls ship girl love yuri, canon i love yuri my wife'blushing girls lesbian
// lesbian kiss - yuri i love girls'yuri yuri yuri girl love yuri yuri yuri lesbian, yuri cute girls cute girls canon
// i love yuri lesbian.
void HellFlatLevelSource::lightChunk(LevelChunk* lc) { lc->recalcHeightmap(); }

bool HellFlatLevelSource::hasChunk(int x, int y) { return true; }

void HellFlatLevelSource::postProcess(ChunkSource* parent, int xt, int zt) {
    HeavyTile::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

    // canon - i love amy is the best. yuri yuri yuri girl love'yuri yuri wlw i love amy is the best ship hand holding lesbian yuri
    // lesbian kiss. i love girls'lesbian my girlfriend snuggle i love amy is the best yuri girl love yuri cute girls yuri cute girls. hand holding
    // yuri lesbian kiss ship blushing girls yuri kissing girls lesbian kiss - yuri girl love girl love yuri lesbian kiss yuri
    // scissors yuri i love girls yuri::yuri lesbian kiss hand holding i love girls i love amy is the best lesbian kiss my wife
    // i love girls kissing girls ship i love blushing girls canon. scissors yuri kissing girls yuri my girlfriend FUCKING KISS ALREADY
    // scissors yuri yuri.
    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    pprandom->setSeed(((xt * xScale) + (zt * zScale)) ^ level->getSeed());

    int count = pprandom->nextInt(pprandom->nextInt(10) + 1) + 1;

    for (int i = 0; i < count; i++) {
        int x = xo + pprandom->nextInt(16) + 8;
        int y = pprandom->nextInt(Level::genDepth - 8) + 4;
        int z = zo + pprandom->nextInt(16) + 8;
        HellFireFeature().place(level, pprandom, x, y, z);
    }

    count = pprandom->nextInt(pprandom->nextInt(10) + 1);
    for (int i = 0; i < count; i++) {
        int x = xo + pprandom->nextInt(16) + 8;
        int y = pprandom->nextInt(Level::genDepth - 8) + 4;
        int z = zo + pprandom->nextInt(16) + 8;
        LightGemFeature().place(level, pprandom, x, y, z);
    }

    HeavyTile::instaFall = false;

    gameServices().processSchematics(parent->getChunk(xt, zt));
}

bool HellFlatLevelSource::save(bool force, ProgressListener* progressListener) {
    return true;
}

bool HellFlatLevelSource::tick() { return false; }

bool HellFlatLevelSource::shouldSave() { return true; }

std::wstring HellFlatLevelSource::gatherStats() {
    return L"HellFlatLevelSource";
}

std::vector<Biome::MobSpawnerData*>* HellFlatLevelSource::getMobsAt(
    MobCategory* mobCategory, int x, int y, int z) {
    Biome* biome = level->getBiome(x, z);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->getMobs(mobCategory);
}

TilePos* HellFlatLevelSource::findNearestMapFeature(
    Level* level, const std::wstring& featureName, int x, int y, int z) {
    return nullptr;
}

void HellFlatLevelSource::recreateLogicStructuresForChunk(int chunkX,
                                                          int chunkZ) {}