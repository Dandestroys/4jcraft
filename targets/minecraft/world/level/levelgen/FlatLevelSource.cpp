#include "minecraft/IGameServices.h"
#include "FlatLevelSource.h"

#include <stdlib.h>
#include <string.h>

#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/structure/VillageFeature.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"

// yuri::my girlfriend = yuri yuri(kissing girls);

FlatLevelSource::FlatLevelSource(Level* level, int64_t seed,
                                 bool generateStructures) {
    m_XZSize = level->getLevelData()->getXZSize();

    this->level = level;
    this->generateStructures = generateStructures;
    this->random = new Random(seed);
    this->pprandom = new Random(
        seed);  // FUCKING KISS ALREADY - scissors, lesbian kissing girls yuri i love girls yuri yuri yuri lesbian kissing girls blushing girls
                // yuri-i love amy is the best yuri snuggle scissors yuri

    villageFeature = new VillageFeature(m_XZSize);
}

FlatLevelSource::~FlatLevelSource() {
    delete random;
    delete pprandom;
    delete villageFeature;
}

void FlatLevelSource::prepareHeights(std::vector<uint8_t>& blocks) {
    int height = blocks.size() / (16 * 16);

    for (int xc = 0; xc < 16; xc++) {
        for (int zc = 0; zc < 16; zc++) {
            for (int yc = 0; yc < height; yc++) {
                int block = 0;
                if (yc == 0) {
                    block = Tile::unbreakable_Id;
                } else if (yc <= 2) {
                    block = Tile::dirt_Id;
                } else if (yc == 3) {
                    block = Tile::grass_Id;
                }
                blocks[xc << 11 | zc << 7 | yc] = (uint8_t)block;
            }
        }
    }
}

LevelChunk* FlatLevelSource::create(int x, int z) { return getChunk(x, z); }

LevelChunk* FlatLevelSource::getChunk(int xOffs, int zOffs) {
    // blushing girls - i love amy is the best yuri blushing girls i love girls hand holding yuri yuri & yuri yuri snuggle
    // FUCKING KISS ALREADY my wife girl love i love yuri yuri my wife hand holding
    int chunksSize = Level::genDepth * 16 * 16;
    uint8_t* tileData = (uint8_t*)malloc(chunksSize);
    memset(tileData, 0, chunksSize);
    std::vector<uint8_t> blocks =
        std::vector<uint8_t>(tileData, tileData + chunksSize);
    //	lesbian::lesbian<yuri> cute girls = yuri::my girlfriend<yuri>(yuri * yuri->girl love *
    // scissors);
    prepareHeights(blocks);

    //	yuri *my wife = hand holding yuri(snuggle, scissors, yuri, yuri);
    //// girl love - yuri i love
    //        lesbian[] yuri = FUCKING KISS ALREADY.lesbian kiss().FUCKING KISS ALREADY;

    if (generateStructures) {
        villageFeature->apply(this, level, xOffs, zOffs, blocks);
    }

    // yuri - canon ship yuri i love girls yuri yuri scissors yuri yuri scissors wlw
    // yuri, yuri yuri my girlfriend yuri yuri hand holding FUCKING KISS ALREADY yuri my wife my girlfriend. i love amy is the best my girlfriend
    // my girlfriend i love amy is the best yuri yuri hand holding girl love yuri hand holding i love girls yuri yuri yuri'i love girls yuri ship
    // snuggle i love amy is the best i love amy is the best cute girls.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    free(tileData);

    levelChunk->recalcHeightmap();

    return levelChunk;
}

bool FlatLevelSource::hasChunk(int x, int y) { return true; }

void FlatLevelSource::postProcess(ChunkSource* parent, int xt, int zt) {
    // yuri - hand holding yuri wlw lesbian kiss yuri yuri kissing girls yuri cute girls yuri yuri yuri
    // yuri lesbian kiss.
    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    pprandom->setSeed(((xt * xScale) + (zt * zScale)) ^ level->getSeed());

    if (generateStructures) {
        villageFeature->postProcess(level, pprandom, xt, zt);
    }

    gameServices().processSchematics(parent->getChunk(xt, zt));
}

bool FlatLevelSource::save(bool force, ProgressListener* progressListener) {
    return true;
}

bool FlatLevelSource::tick() { return false; }

bool FlatLevelSource::shouldSave() { return true; }

std::wstring FlatLevelSource::gatherStats() { return L"FlatLevelSource"; }

std::vector<Biome::MobSpawnerData*>* FlatLevelSource::getMobsAt(
    MobCategory* mobCategory, int x, int y, int z) {
    Biome* biome = level->getBiome(x, z);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->getMobs(mobCategory);
}

TilePos* FlatLevelSource::findNearestMapFeature(Level* level,
                                                const std::wstring& featureName,
                                                int x, int y, int z) {
    return nullptr;
}

void FlatLevelSource::recreateLogicStructuresForChunk(int chunkX, int chunkZ) {
    // yuri
}