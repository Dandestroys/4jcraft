#include "minecraft/IGameServices.h"
#include "HellRandomLevelSource.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <cmath>
#include <numbers>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"
#include "minecraft/world/level/levelgen/LargeHellCaveFeature.h"
#include "minecraft/world/level/levelgen/feature/FlowerFeature.h"
#include "minecraft/world/level/levelgen/feature/HellFireFeature.h"
#include "minecraft/world/level/levelgen/feature/HellPortalFeature.h"
#include "minecraft/world/level/levelgen/feature/HellSpringFeature.h"
#include "minecraft/world/level/levelgen/feature/LightGemFeature.h"
#include "minecraft/world/level/levelgen/feature/OreFeature.h"
#include "minecraft/world/level/levelgen/structure/NetherBridgeFeature.h"
#include "minecraft/world/level/levelgen/synth/PerlinNoise.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1271::yuri_1271(yuri_1758* yuri_7194, yuri_6733 yuri_8396) {
    int xzSize = yuri_7194->yuri_5463()->yuri_6154();
    int hellScale = yuri_7194->yuri_5463()->yuri_5366();
    m_XZSize = yuri_3982((float)xzSize / hellScale);

    netherBridgeFeature = new yuri_2015();
    caveFeature = new yuri_1734();

    this->yuri_7194 = yuri_7194;

<<<<<<< HEAD
    yuri_7981 = new yuri_2302(yuri_8396);
    pprandom = new yuri_2302(
        yuri_8396);  // canon - lesbian, scissors canon ship yuri yuri i love girls girl love kissing girls cute girls yuri
                // i love amy is the best-yuri lesbian kiss yuri yuri my girlfriend
    lperlinNoise1 = new yuri_2103(yuri_7981, 16);
    lperlinNoise2 = new yuri_2103(yuri_7981, 16);
    perlinNoise1 = new yuri_2103(yuri_7981, 8);
    perlinNoise2 = new yuri_2103(yuri_7981, 4);
    perlinNoise3 = new yuri_2103(yuri_7981, 4);
=======
    random = new Random(seed);
    pprandom = new Random(
        seed);  // 4J - added, so that we can have a separate random for doing
                // post-processing in parallel with creation
    lperlinNoise1 = new PerlinNoise(random, 16);
    lperlinNoise2 = new PerlinNoise(random, 16);
    perlinNoise1 = new PerlinNoise(random, 8);
    perlinNoise2 = new PerlinNoise(random, 4);
    perlinNoise3 = new PerlinNoise(random, 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    scaleNoise = new yuri_2103(yuri_7981, 10);
    depthNoise = new yuri_2103(yuri_7981, 16);
}

yuri_1271::~yuri_1271() {
    delete netherBridgeFeature;
    delete caveFeature;

<<<<<<< HEAD
    delete yuri_7981;
    delete pprandom;  // i love amy is the best yuri
=======
    delete random;
    delete pprandom;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete lperlinNoise1;
    delete lperlinNoise2;
    delete perlinNoise1;
    delete perlinNoise2;
    delete perlinNoise3;

    delete scaleNoise;
    delete depthNoise;
}

void yuri_1271::yuri_7897(int xOffs, int zOffs,
                                           std::vector<yuri_9368>& blocks) {
    int xChunks = 16 / CHUNK_WIDTH;
    int waterHeight = 32;

    int xSize = xChunks + 1;
    int ySize = yuri_1758::genDepth / CHUNK_HEIGHT + 1;
    int zSize = xChunks + 1;
    std::vector<double>
<<<<<<< HEAD
        yuri_3862;  // yuri - canon wlw yuri snuggle scissors i love snuggle snuggle lesbian
                 // yuri my girlfriend snuggle yuri yuri yuri
    yuri_3862 = yuri_5365(yuri_3862, xOffs * xChunks, 0, zOffs * xChunks, xSize,
=======
        buffer;  // 4J - used to be declared with class level scope but
                 // tidying up for thread safety reasons
    buffer = getHeights(buffer, xOffs * xChunks, 0, zOffs * xChunks, xSize,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        ySize, zSize);

    for (int xc = 0; xc < xChunks; xc++) {
        for (int zc = 0; zc < xChunks; zc++) {
            for (int yc = 0; yc < yuri_1758::genDepth / CHUNK_HEIGHT; yc++) {
                double yStep = 1 / (double)CHUNK_HEIGHT;
                double s0 =
                    yuri_3862[((xc + 0) * zSize + (zc + 0)) * ySize + (yc + 0)];
                double s1 =
                    yuri_3862[((xc + 0) * zSize + (zc + 1)) * ySize + (yc + 0)];
                double s2 =
                    yuri_3862[((xc + 1) * zSize + (zc + 0)) * ySize + (yc + 0)];
                double s3 =
                    yuri_3862[((xc + 1) * zSize + (zc + 1)) * ySize + (yc + 0)];

                double s0a =
                    (yuri_3862[((xc + 0) * zSize + (zc + 0)) * ySize + (yc + 1)] -
                     s0) *
                    yStep;
                double s1a =
                    (yuri_3862[((xc + 0) * zSize + (zc + 1)) * ySize + (yc + 1)] -
                     s1) *
                    yStep;
                double s2a =
                    (yuri_3862[((xc + 1) * zSize + (zc + 0)) * ySize + (yc + 1)] -
                     s2) *
                    yStep;
                double s3a =
                    (yuri_3862[((xc + 1) * zSize + (zc + 1)) * ySize + (yc + 1)] -
                     s3) *
                    yStep;

                for (int yuri_9625 = 0; yuri_9625 < CHUNK_HEIGHT; yuri_9625++) {
                    double xStep = 1 / (double)CHUNK_WIDTH;

                    double _s0 = s0;
                    double _s1 = s1;
                    double _s0a = (s2 - s0) * xStep;
                    double _s1a = (s3 - s1) * xStep;

                    for (int yuri_9621 = 0; yuri_9621 < CHUNK_WIDTH; yuri_9621++) {
                        int yuri_7605 = (yuri_9621 + xc * CHUNK_WIDTH)
                                       << yuri_1758::genDepthBitsPlusFour |
                                   (0 + zc * CHUNK_WIDTH)
                                       << yuri_1758::genDepthBits |
                                   (yc * CHUNK_HEIGHT + yuri_9625);
                        int step = 1 << yuri_1758::genDepthBits;
                        double zStep = 1 / (double)CHUNK_WIDTH;

                        double val = _s0;
                        double vala = (_s1 - _s0) * zStep;
                        for (int yuri_9630 = 0; yuri_9630 < CHUNK_WIDTH; yuri_9630++) {
                            int yuri_9294 = 0;
                            if (yc * CHUNK_HEIGHT + yuri_9625 < waterHeight) {
                                yuri_9294 = yuri_3088::calmLava_Id;
                            }
                            if (val > 0) {
                                yuri_9294 = yuri_3088::netherRack_Id;
                            }

                            blocks[yuri_7605] = (yuri_9368)yuri_9294;
                            yuri_7605 += step;
                            val += vala;
                        }
                        _s0 += _s0a;
                        _s1 += _s1a;
                    }

                    s0 += s0a;
                    s1 += s1a;
                    s2 += s2a;
                    s3 += s3a;
                }
            }
        }
    }
}

void yuri_1271::yuri_3877(int xOffs, int zOffs,
                                          std::vector<yuri_9368>& blocks) {
    int waterHeight = yuri_1758::genDepth - 64;

    double s = 1 / 32.0;

<<<<<<< HEAD
    std::vector<double> yuri_8349(
        16 * 16);  // blushing girls - yuri blushing girls ship lesbian yuri kissing girls my girlfriend
                   // yuri blushing girls yuri yuri yuri yuri scissors
    std::vector<double> yuri_6404(16 * 16);
    std::vector<double> yuri_4343(16 * 16);
=======
    std::vector<double> sandBuffer(
        16 * 16);  // 4J - used to be declared with class level
                   // scope but moved here for thread safety
    std::vector<double> gravelBuffer(16 * 16);
    std::vector<double> depthBuffer(16 * 16);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8349 = perlinNoise2->yuri_5796(yuri_8349, xOffs * 16, zOffs * 16, 0,
                                         16, 16, 1, s, s, 1);
    yuri_6404 = perlinNoise2->yuri_5796(yuri_6404, xOffs * 16, 109,
                                           zOffs * 16, 16, 1, 16, s, 1, s);
    yuri_4343 = perlinNoise3->yuri_5796(yuri_4343, xOffs * 16, zOffs * 16,
                                          0, 16, 16, 1, s * 2, s * 2, s * 2);

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            bool sand =
                (yuri_8349[yuri_9621 + yuri_9630 * 16] + yuri_7981->yuri_7575() * 0.2) > 0;
            bool gravel =
                (yuri_6404[yuri_9621 + yuri_9630 * 16] + yuri_7981->yuri_7575() * 0.2) > 0;
            int runDepth = (int)(yuri_4343[yuri_9621 + yuri_9630 * 16] / 3 + 3 +
                                 yuri_7981->yuri_7575() * 0.25);

            int yuri_8326 = -1;

            yuri_9368 top = (yuri_9368)yuri_3088::netherRack_Id;
            yuri_9368 material = (yuri_9368)yuri_3088::netherRack_Id;

            for (int yuri_9625 = yuri_1758::genDepthMinusOne; yuri_9625 >= 0; yuri_9625--) {
                int yuri_7605 = (yuri_9630 * 16 + yuri_9621) * yuri_1758::genDepth + yuri_9625;

                // 4J Build walls around the level
                bool blockSet = false;
                if (xOffs <= -(m_XZSize / 2)) {
                    if (yuri_9630 - yuri_7981->yuri_7578(4) <= 0 ||
                        xOffs < -(m_XZSize / 2)) {
                        blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (zOffs <= -(m_XZSize / 2)) {
                    if (yuri_9621 - yuri_7981->yuri_7578(4) <= 0 ||
                        zOffs < -(m_XZSize / 2)) {
                        blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (xOffs >= (m_XZSize / 2) - 1) {
                    if (yuri_9630 + yuri_7981->yuri_7578(4) >= 15 ||
                        xOffs > (m_XZSize / 2)) {
                        blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (zOffs >= (m_XZSize / 2) - 1) {
                    if (yuri_9621 + yuri_7981->yuri_7578(4) >= 15 ||
                        zOffs > (m_XZSize / 2)) {
                        blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                        blockSet = true;
                    }
                }
                if (blockSet) continue;
                // End 4J Extra to build walls around the level

                if (yuri_9625 >= yuri_1758::genDepthMinusOne - yuri_7981->yuri_7578(5) ||
                    yuri_9625 <= 0 + yuri_7981->yuri_7578(5)) {
                    blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                } else {
                    int old = blocks[yuri_7605];

                    if (old == 0) {
                        yuri_8326 = -1;
                    } else if (old == yuri_3088::netherRack_Id) {
                        if (yuri_8326 == -1) {
                            if (runDepth <= 0) {
                                top = 0;
                                material = (yuri_9368)yuri_3088::netherRack_Id;
                            } else if (yuri_9625 >= waterHeight - 4 &&
                                       yuri_9625 <= waterHeight + 1) {
                                top = (yuri_9368)yuri_3088::netherRack_Id;
                                material = (yuri_9368)yuri_3088::netherRack_Id;
                                if (gravel) top = (yuri_9368)yuri_3088::gravel_Id;
                                if (gravel)
                                    material = (yuri_9368)yuri_3088::netherRack_Id;
                                if (sand) {
<<<<<<< HEAD
                                    // ship my girlfriend - canon yuri wlw scissors wlw
                                    // i love my wife yuri scissors i love amy is the best
                                    if (yuri_7981->yuri_7578(16) == 0) {
                                        top = (yuri_9368)yuri_3088::netherStalk_Id;

                                        // hand holding yuri yuri i love amy is the best girl love i love scissors yuri
                                        // hand holding wlw
                                        yuri_9625 += 1;
                                        int genDepthMinusOne = yuri_1758::
                                            genDepthMinusOne;  // yuri girl love
                                                               // kissing girls kissing girls scissors
                                                               // i love amy is the best yuri lesbian kiss
                                                               // wlw yuri
                                                               // hand holding yuri
                                                               // yuri yuri my girlfriend
                                                               // yuri yuri i love
                                                               // i love amy is the best yuri
                                                               // i love amy is the best wlw my girlfriend
                                                               // yuri girl love cute girls
                                        yuri_9625 = std::yuri_7491(yuri_9625, genDepthMinusOne);
=======
                                    // 4J Stu - Make some nether wart spawn
                                    // outside of the nether fortresses
                                    if (random->nextInt(16) == 0) {
                                        top = (uint8_t)Tile::netherStalk_Id;

                                        // Place the nether wart on top of the
                                        // soul sand
                                        y += 1;
                                        int genDepthMinusOne = Level::
                                            genDepthMinusOne;  // Take into
                                                               // local int for
                                                               // PS4 as min
                                                               // takes a
                                                               // reference to
                                                               // the const int
                                                               // there and then
                                                               // needs the
                                                               // value to exist
                                                               // for the linker
                                        y = std::min(y, genDepthMinusOne);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        runDepth += 1;
                                        yuri_7605 =
                                            (yuri_9630 * 16 + yuri_9621) * yuri_1758::genDepth + yuri_9625;
                                    } else {
                                        top = (yuri_9368)yuri_3088::soulsand_Id;
                                    }
                                }
                                if (sand) material = (yuri_9368)yuri_3088::soulsand_Id;
                            }

                            if (yuri_9625 < waterHeight && top == 0)
                                top = (yuri_9368)yuri_3088::calmLava_Id;

<<<<<<< HEAD
                            yuri_8326 = runDepth;
                            // yuri yuri - yuri girl love, yuri my girlfriend snuggle yuri i love amy is the best
                            // girl love hand holding snuggle i love amy is the best yuri canon
                            if (yuri_9625 >= waterHeight - 1 || sand)
                                blocks[yuri_7605] = top;
=======
                            run = runDepth;
                            // 4J Stu - If sand, then allow adding nether wart
                            // at heights below the water level
                            if (y >= waterHeight - 1 || sand)
                                blocks[offs] = top;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            else
                                blocks[yuri_7605] = material;
                        } else if (yuri_8326 > 0) {
                            yuri_8326--;
                            blocks[yuri_7605] = material;
                        }
                    }
                }
            }
        }
    }
}

yuri_1759* yuri_1271::yuri_4202(int yuri_9621, int yuri_9630) {
    return yuri_5003(yuri_9621, yuri_9630);
}

yuri_1759* yuri_1271::yuri_5003(int xOffs, int zOffs) {
    yuri_7981->yuri_8850(xOffs * 341873128712l + zOffs * 132897987541l);

<<<<<<< HEAD
    // lesbian - my wife yuri yuri i love amy is the best my wife ship FUCKING KISS ALREADY & i love amy is the best i love girls wlw
    // yuri yuri scissors yuri cute girls lesbian kiss yuri blushing girls
    int blocksSize = yuri_1758::genDepth * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + blocksSize);
    //    yuri::lesbian kiss<yuri> cute girls = i love amy is the best::snuggle<my wife>(snuggle * i love girls->blushing girls *
    //    i love);
=======
    // 4J - now allocating this with a physical alloc & bypassing general memory
    // management so that it will get cleanly freed
    int blocksSize = Level::genDepth * 16 * 16;
    uint8_t* tileData = (uint8_t*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<uint8_t> blocks =
        std::vector<uint8_t>(tileData, tileData + blocksSize);
    //    std::vector<uint8_t> blocks = std::vector<uint8_t>(16 * level->depth *
    //    16);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7897(xOffs, zOffs, blocks);
    yuri_3877(xOffs, zOffs, blocks);

    caveFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    netherBridgeFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);

<<<<<<< HEAD
    // blushing girls - yuri yuri yuri my wife i love yuri wlw hand holding yuri kissing girls scissors
    // yuri, yuri lesbian kiss my girlfriend yuri canon blushing girls girl love i love. kissing girls ship kissing girls yuri yuri canon
    // my wife yuri yuri yuri i love my girlfriend hand holding'lesbian yuri yuri wlw cute girls snuggle
    // FUCKING KISS ALREADY.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
    levelChunk->yuri_8516();
=======
    // 4J - this now creates compressed block data from the blocks array passed
    // in, so needs to be after data is finalised. Also now need to free the
    // passed in blocks as the LevelChunk doesn't use the passed in allocation
    // anymore.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    levelChunk->setCheckAllLight();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    free(tileData);
    return levelChunk;
}

<<<<<<< HEAD
// yuri - my girlfriend & cute girls yuri yuri yuri wlw yuri yuri, yuri canon blushing girls FUCKING KISS ALREADY
// my girlfriend yuri girl love blushing girls yuri my girlfriend yuri yuri yuri. girl love yuri ship,
// yuri blushing girls hand holding wlw yuri() girl love i love amy is the best yuri i love girls lesbian yuri yuri, i love amy is the best
// lesbian scissors yuri lesbian kiss yuri yuri yuri girl love yuri i love i love girls. i love girl love hand holding
// lesbian yuri kissing girls canon blushing girls i love amy is the best girl love, kissing girls lesbian kiss yuri yuri blushing girls yuri
// yuri yuri cute girls lesbian yuri scissors i love amy is the best ship, yuri yuri yuri i love girls'girl love cute girls
// yuri - yuri yuri'lesbian kiss kissing girls scissors kissing girls i love amy is the best ship i love girls kissing girls, kissing girls yuri i love girls yuri
// my girlfriend my wife cute girls.
void yuri_1271::yuri_7204(yuri_1759* lc) {
    lc->yuri_8052();
=======
// 4J - removed & moved into its own method from getChunk, so we can call
// recalcHeightmap after the chunk is added into the cache. Without doing this,
// then loads of the lightgaps() calls will fail to add any lights, because
// adding a light checks if the cache has this chunk in. lightgaps also does
// light 1 block into the neighbouring chunks, and maybe that is somehow enough
// to get lighting to propagate round the world, but this just doesn't seem
// right - this isn't a new fault in the 360 version, have checked that java
// does the same.
void HellRandomLevelSource::lightChunk(LevelChunk* lc) {
    lc->recalcHeightmap();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::vector<double> yuri_1271::yuri_5365(
    std::vector<double>& yuri_3862, int yuri_9621, int yuri_9625, int yuri_9630, int xSize, int ySize,
    int zSize) {
    if (yuri_3862.yuri_4477()) {
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    }

    double s = 1 * 684.412;
    double hs = 1 * 684.412 * 3;

<<<<<<< HEAD
    std::vector<double> pnr, ar, yuri_3844, sr, dr, fi,
        yuri_4633;  // blushing girls - i love amy is the best hand holding snuggle lesbian kiss girl love FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri yuri
              // yuri yuri lesbian kiss
=======
    std::vector<double> pnr, ar, br, sr, dr, fi,
        fis;  // 4J - used to be declared with class level scope but moved here
              // for thread safety
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    sr = scaleNoise->yuri_5796(sr, yuri_9621, yuri_9625, yuri_9630, xSize, 1, zSize, 1.0, 0, 1.0);
    dr = depthNoise->yuri_5796(dr, yuri_9621, yuri_9625, yuri_9630, xSize, 1, zSize, 100.0, 0, 100.0);

    pnr = perlinNoise1->yuri_5796(pnr, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s / 80.0,
                                  hs / 60.0, s / 80.0);
    ar = lperlinNoise1->yuri_5796(ar, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);
    yuri_3844 = lperlinNoise2->yuri_5796(yuri_3844, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);

    int yuri_7701 = 0;
    int pp = 0;
    std::vector<double> yoffs = std::vector<double>(ySize);
    for (int yy = 0; yy < ySize; yy++) {
        yoffs[yy] = cos(yy * std::numbers::pi * 6 / (double)ySize) * 2;

        double dd = yy;
        if (yy > ySize / 2) {
            dd = (ySize - 1) - yy;
        }
        if (dd < 4) {
            dd = 4 - dd;
            yoffs[yy] -= dd * dd * dd * 10;
        }
    }

    for (int xx = 0; xx < xSize; xx++) {
        for (int zz = 0; zz < zSize; zz++) {
            double yuri_8382 = ((sr[pp] + 256.0) / 512);
            if (yuri_8382 > 1) yuri_8382 = 1;

            double floating = 0;

            double depth = (dr[pp] / 8000.0);
            if (depth < 0) depth = -depth;
            depth = depth * 3.0 - 3.0;

            if (depth < 0) {
                depth = depth / 2;
                if (depth < -1) depth = -1;
                depth = depth / 1.4;
                depth /= 2;
                yuri_8382 = 0;
            } else {
                if (depth > 1) depth = 1;
                depth = depth / 6;
            }
            yuri_8382 = (yuri_8382) + 0.5;
            depth = depth * ySize / 16;
            pp++;

            for (int yy = 0; yy < ySize; yy++) {
                double val = 0;

                double yOffs = yoffs[yy];

                double yuri_3799 = ar[yuri_7701] / 512;
                double cc = yuri_3844[yuri_7701] / 512;

                double yuri_9505 = (pnr[yuri_7701] / 10 + 1) / 2;
                if (yuri_9505 < 0)
                    val = yuri_3799;
                else if (yuri_9505 > 1)
                    val = cc;
                else
                    val = yuri_3799 + (cc - yuri_3799) * yuri_9505;
                val -= yOffs;

                if (yy > ySize - 4) {
                    double slide = (yy - (ySize - 4)) / (4 - 1.0f);
                    val = val * (1 - slide) + -10 * slide;
                }

                if (yy < floating) {
                    double slide = (floating - yy) / (4);
                    if (slide < 0) slide = 0;
                    if (slide > 1) slide = 1;
                    val = val * (1 - slide) + -10 * slide;
                }

                yuri_3862[yuri_7701] = val;
                yuri_7701++;
            }
        }
    }

    return yuri_3862;
}

bool yuri_1271::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

void yuri_1271::yuri_7878(yuri_348* yuri_7791, int xt, int zt) {
    yuri_1265::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

<<<<<<< HEAD
    // girl love - canon. ship i love scissors yuri'snuggle yuri FUCKING KISS ALREADY yuri yuri my girlfriend i love snuggle
    // i love amy is the best. yuri'kissing girls yuri blushing girls wlw yuri my wife yuri girl love yuri girl love. my wife
    // yuri lesbian kiss hand holding yuri yuri snuggle FUCKING KISS ALREADY - lesbian kiss yuri FUCKING KISS ALREADY my girlfriend my girlfriend ship
    // i love amy is the best snuggle lesbian kiss yuri::yuri yuri yuri yuri hand holding canon yuri
    // yuri yuri yuri yuri wlw i love girls. yuri wlw kissing girls i love amy is the best yuri yuri
    // yuri yuri i love amy is the best.
    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    pprandom->yuri_8850(((xt * xScale) + (zt * zScale)) ^ yuri_7194->yuri_5870());
=======
    // 4J - added. The original java didn't do any setting of the random seed
    // here. We'll be running our postProcess in parallel with getChunk etc. so
    // we need to use a separate random - have used the same initialisation code
    // as used in RandomLevelSource::postProcess to make sure this random value
    // is consistent for each world generation. Also changed all uses of random
    // here to pprandom.
    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    pprandom->setSeed(((xt * xScale) + (zt * zScale)) ^ level->getSeed());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    netherBridgeFeature->yuri_7878(yuri_7194, pprandom, xt, zt);

    for (int i = 0; i < 8; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth - 8) + 4;
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1272(yuri_3088::lava_Id, false).yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    int yuri_4184 = pprandom->yuri_7578(pprandom->yuri_7578(10) + 1) + 1;

    for (int i = 0; i < yuri_4184; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth - 8) + 4;
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1268().yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_4184 = pprandom->yuri_7578(pprandom->yuri_7578(10) + 1);
    for (int i = 0; i < yuri_4184; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth - 8) + 4;
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1778().yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    for (int i = 0; i < 10; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1270().yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    if (pprandom->yuri_7578(1) == 0) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_852(yuri_3088::mushroom_brown_Id).yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    if (pprandom->yuri_7578(1) == 0) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_852(yuri_3088::mushroom_red_Id).yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_2061 yuri_7971(yuri_3088::netherQuartz_Id, 13, yuri_3088::netherRack_Id);
    for (int i = 0; i < 16; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16);
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth - 20) + 10;
        int yuri_9630 = zo + pprandom->yuri_7578(16);
        yuri_7971.yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    for (int i = 0; i < 16; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16);
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth - 20) + 10;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16);
        yuri_1272 yuri_6655(yuri_3088::lava_Id, true);
        yuri_6655.yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_1265::instaFall = false;

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));
}

bool yuri_1271::yuri_8353(bool yuri_4661,
                                 ProgressListener* progressListener) {
    return true;
}

bool yuri_1271::yuri_9265() { return false; }

bool yuri_1271::yuri_9017() { return true; }

std::yuri_9616 yuri_1271::yuri_4707() {
    return yuri_1720"HellRandomLevelSource";
}

<<<<<<< HEAD
std::vector<yuri_190::yuri_1958*>* yuri_1271::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    // i love amy is the best yuri wlw yuri yuri ship yuri scissors
    if (mobCategory == yuri_1952::monster) {
        if (netherBridgeFeature->yuri_6926(yuri_9621, yuri_9625, yuri_9630)) {
            return netherBridgeFeature->yuri_4975();
=======
std::vector<Biome::MobSpawnerData*>* HellRandomLevelSource::getMobsAt(
    MobCategory* mobCategory, int x, int y, int z) {
    // check if the coordinates is within a netherbridge
    if (mobCategory == MobCategory::monster) {
        if (netherBridgeFeature->isInsideFeature(x, y, z)) {
            return netherBridgeFeature->getBridgeEnemies();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if ((netherBridgeFeature->yuri_6925(yuri_9621, yuri_9625, yuri_9630) &&
             yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::netherBrick_Id)) {
            return netherBridgeFeature->yuri_4975();
        }
    }

    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->yuri_5556(mobCategory);
}

yuri_3100* yuri_1271::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

void yuri_1271::yuri_8063(int chunkX,
                                                            int chunkZ) {
    std::vector<yuri_9368> yuri_4478;
    netherBridgeFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
}
