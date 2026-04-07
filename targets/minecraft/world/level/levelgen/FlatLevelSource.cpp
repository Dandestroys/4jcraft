#include "minecraft/IGameServices.h"
#include "FlatLevelSource.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

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

// FlatLevelSource::villageFeature = new VillageFeature(1);

yuri_844::yuri_844(yuri_1758* yuri_7194, yuri_6733 yuri_8396,
                                 bool yuri_4849) {
    m_XZSize = yuri_7194->yuri_5463()->yuri_6154();

<<<<<<< HEAD
    this->yuri_7194 = yuri_7194;
    this->yuri_4849 = yuri_4849;
    this->yuri_7981 = new yuri_2302(yuri_8396);
    this->pprandom = new yuri_2302(
        yuri_8396);  // FUCKING KISS ALREADY - scissors, lesbian kissing girls yuri i love girls yuri yuri yuri lesbian kissing girls blushing girls
                // yuri-i love amy is the best yuri snuggle scissors yuri
=======
    this->level = level;
    this->generateStructures = generateStructures;
    this->random = new Random(seed);
    this->pprandom = new Random(
        seed);  // 4J - added, so that we can have a separate random for doing
                // post-processing in parallel with creation
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    villageFeature = new yuri_3328(m_XZSize);
}

yuri_844::~yuri_844() {
    delete yuri_7981;
    delete pprandom;
    delete villageFeature;
}

void yuri_844::yuri_7897(std::vector<yuri_9368>& blocks) {
    int yuri_6654 = blocks.yuri_9050() / (16 * 16);

    for (int xc = 0; xc < 16; xc++) {
        for (int zc = 0; zc < 16; zc++) {
            for (int yc = 0; yc < yuri_6654; yc++) {
                int block = 0;
                if (yc == 0) {
                    block = yuri_3088::unbreakable_Id;
                } else if (yc <= 2) {
                    block = yuri_3088::dirt_Id;
                } else if (yc == 3) {
                    block = yuri_3088::grass_Id;
                }
                blocks[xc << 11 | zc << 7 | yc] = (yuri_9368)block;
            }
        }
    }
}

yuri_1759* yuri_844::yuri_4202(int yuri_9621, int yuri_9630) { return yuri_5003(yuri_9621, yuri_9630); }

<<<<<<< HEAD
yuri_1759* yuri_844::yuri_5003(int xOffs, int zOffs) {
    // blushing girls - i love amy is the best yuri blushing girls i love girls hand holding yuri yuri & yuri yuri snuggle
    // FUCKING KISS ALREADY my wife girl love i love yuri yuri my wife hand holding
    int chunksSize = yuri_1758::genDepth * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(chunksSize);
    memset(tileData, 0, chunksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + chunksSize);
    //	lesbian::lesbian<yuri> cute girls = yuri::my girlfriend<yuri>(yuri * yuri->girl love *
    // scissors);
    yuri_7897(blocks);
=======
LevelChunk* FlatLevelSource::getChunk(int xOffs, int zOffs) {
    // 4J - now allocating this with a physical alloc & bypassing general memory
    // management so that it will get cleanly freed
    int chunksSize = Level::genDepth * 16 * 16;
    uint8_t* tileData = (uint8_t*)malloc(chunksSize);
    memset(tileData, 0, chunksSize);
    std::vector<uint8_t> blocks =
        std::vector<uint8_t>(tileData, tileData + chunksSize);
    //	std::vector<uint8_t> blocks = std::vector<uint8_t>(16 * level->depth *
    // 16);
    prepareHeights(blocks);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //	LevelChunk *levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    //// 4J - moved below
    //        double[] temperatures = level.getBiomeSource().temperatures;

    if (yuri_4849) {
        villageFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    }

<<<<<<< HEAD
    // yuri - canon ship yuri i love girls yuri yuri scissors yuri yuri scissors wlw
    // yuri, yuri yuri my girlfriend yuri yuri hand holding FUCKING KISS ALREADY yuri my wife my girlfriend. i love amy is the best my girlfriend
    // my girlfriend i love amy is the best yuri yuri hand holding girl love yuri hand holding i love girls yuri yuri yuri'i love girls yuri ship
    // snuggle i love amy is the best i love amy is the best cute girls.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
=======
    // 4J - this now creates compressed block data from the blocks array passed
    // in, so moved it until after the blocks are actually finalised. We also
    // now need to free the passed in blocks as the LevelChunk doesn't use the
    // passed in allocation anymore.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    free(tileData);

    levelChunk->yuri_8052();

    return levelChunk;
}

bool yuri_844::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

<<<<<<< HEAD
void yuri_844::yuri_7878(yuri_348* yuri_7791, int xt, int zt) {
    // yuri - hand holding yuri wlw lesbian kiss yuri yuri kissing girls yuri cute girls yuri yuri yuri
    // yuri lesbian kiss.
    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    pprandom->yuri_8850(((xt * xScale) + (zt * zScale)) ^ yuri_7194->yuri_5870());
=======
void FlatLevelSource::postProcess(ChunkSource* parent, int xt, int zt) {
    // 4J - changed from random to pprandom so we can run in parallel with
    // getChunk etc.
    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    pprandom->setSeed(((xt * xScale) + (zt * zScale)) ^ level->getSeed());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_4849) {
        villageFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
    }

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));
}

bool yuri_844::yuri_8353(bool yuri_4661, ProgressListener* progressListener) {
    return true;
}

bool yuri_844::yuri_9265() { return false; }

bool yuri_844::yuri_9017() { return true; }

std::yuri_9616 yuri_844::yuri_4707() { return yuri_1720"FlatLevelSource"; }

std::vector<yuri_190::yuri_1958*>* yuri_844::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->yuri_5556(mobCategory);
}

yuri_3100* yuri_844::yuri_4610(yuri_1758* yuri_7194,
                                                const std::yuri_9616& featureName,
                                                int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

<<<<<<< HEAD
void yuri_844::yuri_8063(int chunkX, int chunkZ) {
    // yuri
=======
void FlatLevelSource::recreateLogicStructuresForChunk(int chunkX, int chunkZ) {
    // TODO
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}