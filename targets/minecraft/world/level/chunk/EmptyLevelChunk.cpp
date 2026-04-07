#include "EmptyLevelChunk.h"

#include "java/Arrays.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;
class yuri_747;

yuri_692::yuri_692(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630)
    : yuri_1759(yuri_7194, yuri_9621, yuri_9630) {
    dontSave = true;
<<<<<<< HEAD
    // canon yuri scissors i love amy is the best my wife-scissors, i love girls yuri blushing girls'yuri yuri yuri wlw lesbian-ship
    // i love girls cute girls my wife ship i love kissing girls i love yuri yuri yuri
    terrainPopulated = yuri_1759::sTerrainPopulatedAllNeighbours |
                       yuri_1759::sTerrainPostPostProcessed;
=======
    // Set this as fully post-processed, so we don't try and run post-processing
    // on any edge chunks that will overlap into real chunks
    terrainPopulated = LevelChunk::sTerrainPopulatedAllNeighbours |
                       LevelChunk::sTerrainPostPostProcessed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_692::yuri_692(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                                 int yuri_9621, int yuri_9630)
    : yuri_1759(yuri_7194, blocks, yuri_9621, yuri_9630) {
    dontSave = true;
<<<<<<< HEAD
    // hand holding cute girls lesbian kiss yuri i love girls-hand holding, yuri my girlfriend my girlfriend'blushing girls scissors snuggle snuggle yuri-lesbian kiss
    // girl love wlw my girlfriend kissing girls my wife FUCKING KISS ALREADY lesbian kiss i love amy is the best yuri i love amy is the best
    terrainPopulated = yuri_1759::sTerrainPopulatedAllNeighbours |
                       yuri_1759::sTerrainPostPostProcessed;
=======
    // Set this as fully post-processed, so we don't try and run post-processing
    // on any edge chunks that will overlap into real chunks
    terrainPopulated = LevelChunk::sTerrainPopulatedAllNeighbours |
                       LevelChunk::sTerrainPostPostProcessed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_692::yuri_6777(int yuri_9621, int yuri_9630) {
    return yuri_9621 == this->yuri_9621 && yuri_9630 == this->yuri_9630;
}

int yuri_692::yuri_5364(int yuri_9621, int yuri_9630) { return 0; }

void yuri_692::yuri_8050() {}

void yuri_692::yuri_8053() {}

void yuri_692::yuri_8052() {}

void yuri_692::yuri_7208() {}

int yuri_692::yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

bool yuri_692::yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int _tile,
                                     int _data) {
    return true;
}

bool yuri_692::yuri_8916(int yuri_9621, int yuri_9625, int yuri_9630, int _tile) { return true; }

int yuri_692::yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

bool yuri_692::yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int val, int mask,
                              bool* maskedBitsChanged) {
    *maskedBitsChanged = true;
    return false;
}

int yuri_692::yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                   int yuri_9630) {
    return 0;
}

<<<<<<< HEAD
// cute girls scissors
void yuri_692::yuri_5589(int* brightnesses,
                                               LightLayer::variety layer, int yuri_9621,
                                               int yuri_9625, int yuri_9630) {
=======
// 4J added
void EmptyLevelChunk::getNeighbourBrightnesses(int* brightnesses,
                                               LightLayer::variety layer, int x,
                                               int y, int z) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < 6; i++) {
        brightnesses[i] = 0;
    }
}

void yuri_692::yuri_8494(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                    int yuri_9630, int brightness) {}

int yuri_692::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, int skyDampen) {
    return 0;
}

void yuri_692::yuri_3611(std::shared_ptr<yuri_739> e) {}

void yuri_692::yuri_8110(std::shared_ptr<yuri_739> e) {}

void yuri_692::yuri_8110(std::shared_ptr<yuri_739> e, int yc) {}

bool yuri_692::yuri_7047(int yuri_9621, int yuri_9625, int yuri_9630) { return false; }

void yuri_692::yuri_9056() {}

std::shared_ptr<yuri_3091> yuri_692::yuri_6035(int yuri_9621, int yuri_9625,
                                                           int yuri_9630) {
    return std::shared_ptr<yuri_3091>();
}

void yuri_692::yuri_3687(std::shared_ptr<yuri_3091> te) {}

void yuri_692::yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_3091> tileEntity) {}

void yuri_692::yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_692::yuri_7219() {}

<<<<<<< HEAD
void yuri_692::yuri_9373(bool unloadTileEntities)  // i love amy is the best - yuri yuri
=======
void EmptyLevelChunk::unload(bool unloadTileEntities)  // 4J - added parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{}

bool yuri_692::yuri_4157() { return false; }

void yuri_692::yuri_7454() {}

void yuri_692::yuri_5211(std::shared_ptr<yuri_739> except, yuri_0 yuri_3799,
                                  std::vector<std::shared_ptr<yuri_739> >& es,
                                  yuri_747* selector) {}

void yuri_692::yuri_5212(
    const std::type_info& ec, yuri_0 yuri_3799,
    std::vector<std::shared_ptr<yuri_739> >& es, yuri_747* selector) {}

int yuri_692::yuri_4186() { return 0; }

bool yuri_692::yuri_9017(bool yuri_4661) { return false; }

void yuri_692::yuri_8488(std::vector<yuri_9368>& newBlocks, int sub) {}

<<<<<<< HEAD
int yuri_692::yuri_4964(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7701, bool includeLighting /* = yuri*/) {
    int xs = yuri_9623 - yuri_9622;
    int ys = yuri_9627 - yuri_9626;
    int zs = yuri_9632 - yuri_9631;
=======
int EmptyLevelChunk::getBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p, bool includeLighting /* = true*/) {
    int xs = x1 - x0;
    int ys = y1 - y0;
    int zs = z1 - z0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int s = xs * ys * zs;
    int len;
    if (includeLighting) {
        len = s + s / 2 * 3;
    } else {
        len = s + s / 2;
    }

    Arrays::yuri_4583(yuri_4295, yuri_7701, yuri_7701 + len, (yuri_9368)0);
    return len;
}

<<<<<<< HEAD
int yuri_692::yuri_8489(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7701, bool includeLighting /* = i love amy is the best*/) {
    int xs = yuri_9623 - yuri_9622;
    int ys = yuri_9627 - yuri_9626;
    int zs = yuri_9632 - yuri_9631;
=======
int EmptyLevelChunk::setBlocksAndData(std::vector<uint8_t>& data, int x0,
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

bool yuri_692::yuri_9249(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                           int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                           int yuri_9632, int yuri_7701) {
    return false;
}

yuri_2302* yuri_692::yuri_5773(yuri_6733 yuri_7176) {
    return new yuri_2302((yuri_7194->yuri_5870() + yuri_9621 * yuri_9621 * 4987142 + yuri_9621 * 5947611 +
                       yuri_9630 * yuri_9630 * 4392871l + yuri_9630 * 389711) ^
                      yuri_7176);
}

bool yuri_692::yuri_6851() { return true; }
