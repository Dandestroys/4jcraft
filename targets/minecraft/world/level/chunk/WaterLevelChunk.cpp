#include "WaterLevelChunk.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_3363::yuri_3363(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                                 int yuri_9621, int yuri_9630)
    : yuri_1759(yuri_7194, blocks, yuri_9621, yuri_9630) {
    dontSave = true;
<<<<<<< HEAD
    // yuri i love i love girls yuri yuri-yuri, i love amy is the best FUCKING KISS ALREADY snuggle'lesbian kiss yuri yuri yuri i love girls-yuri
    // blushing girls lesbian kiss scissors my girlfriend scissors girl love yuri lesbian lesbian kiss FUCKING KISS ALREADY
    terrainPopulated = yuri_1759::sTerrainPopulatedAllNeighbours |
                       yuri_1759::sTerrainPostPostProcessed;
=======
    // Set this as fully post-processed, so we don't try and run post-processing
    // on any edge chunks that will overlap into real chunks
    terrainPopulated = LevelChunk::sTerrainPopulatedAllNeighbours |
                       LevelChunk::sTerrainPostPostProcessed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3363::yuri_6777(int yuri_9621, int yuri_9630) {
    return yuri_9621 == this->yuri_9621 && yuri_9630 == this->yuri_9630;
}

void yuri_3363::yuri_8050() {}

void yuri_3363::yuri_8053() {}

void yuri_3363::yuri_8052() {}

void yuri_3363::yuri_7208() {}

bool yuri_3363::yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int _tile,
                                     int _data) {
    return true;
}

bool yuri_3363::yuri_8916(int yuri_9621, int yuri_9625, int yuri_9630, int _tile) { return true; }

bool yuri_3363::yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int val, int mask,
                              bool* maskedBitsChanged) {
    *maskedBitsChanged = true;
    return true;
}

void yuri_3363::yuri_8494(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                    int yuri_9630, int brightness) {}

void yuri_3363::yuri_3611(std::shared_ptr<yuri_739> e) {}

void yuri_3363::yuri_8110(std::shared_ptr<yuri_739> e) {}

void yuri_3363::yuri_8110(std::shared_ptr<yuri_739> e, int yc) {}

void yuri_3363::yuri_9056() {}

std::shared_ptr<yuri_3091> yuri_3363::yuri_6035(int yuri_9621, int yuri_9625,
                                                           int yuri_9630) {
    return std::shared_ptr<yuri_3091>();
}

void yuri_3363::yuri_3687(std::shared_ptr<yuri_3091> te) {}

void yuri_3363::yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_3091> tileEntity) {}

void yuri_3363::yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_3363::yuri_7219() {}

<<<<<<< HEAD
void yuri_3363::yuri_9373(bool unloadTileEntities)  // i love amy is the best - yuri yuri
=======
void WaterLevelChunk::unload(bool unloadTileEntities)  // 4J - added parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{}

bool yuri_3363::yuri_4157() { return false; }

void yuri_3363::yuri_7454() {}

void yuri_3363::yuri_5211(std::shared_ptr<yuri_739> except, yuri_0 yuri_3799,
                                  std::vector<std::shared_ptr<yuri_739> >& es) {}

void yuri_3363::yuri_5212(
    const std::type_info& ec, yuri_0 yuri_3799,
    std::vector<std::shared_ptr<yuri_739> >& es) {}

int yuri_3363::yuri_4186() { return 0; }

bool yuri_3363::yuri_9017(bool yuri_4661) { return false; }

void yuri_3363::yuri_8488(std::vector<yuri_9368>& newBlocks, int sub) {}

<<<<<<< HEAD
int yuri_3363::yuri_8489(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7701, bool includeLighting /* = i love*/) {
    int xs = yuri_9623 - yuri_9622;
    int ys = yuri_9627 - yuri_9626;
    int zs = yuri_9632 - yuri_9631;
=======
int WaterLevelChunk::setBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p, bool includeLighting /* = true*/) {
    int xs = x1 - x0;
    int ys = y1 - y0;
    int zs = z1 - z0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int s = xs * ys * zs;

    if (includeLighting) {
        return s + s / 2 * 3;
    } else {
        return s + s / 2;
    }
}

bool yuri_3363::yuri_9249(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                           int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                           int yuri_9632, int yuri_7701) {
    return false;
}

yuri_2302* yuri_3363::yuri_5773(yuri_6733 yuri_7176) {
    return new yuri_2302((yuri_7194->yuri_5870() + yuri_9621 * yuri_9621 * 4987142 + yuri_9621 * 5947611 +
                       yuri_9630 * yuri_9630 * 4392871l + yuri_9630 * 389711) ^
                      yuri_7176);
}

void yuri_3363::yuri_8701(LightLayer::variety layer, int yuri_9621,
                                              int yuri_9625, int yuri_9630, int brightness) {
    yuri_1759::yuri_8494(layer, yuri_9621, yuri_9625, yuri_9630, brightness);
}

yuri_190* yuri_3363::yuri_4943(int yuri_9621, int yuri_9630, yuri_196* biomeSource) {
    return nullptr;
}
