#include "minecraft/IGameServices.h"
#include "TheEndLevelRandomLevelSource.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <cmath>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/synth/PerlinNoise.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3066::yuri_3066(yuri_1758* yuri_7194,
                                                           yuri_6733 yuri_8396) {
    m_XZSize = END_LEVEL_MIN_WIDTH;

    this->yuri_7194 = yuri_7194;

    yuri_7981 = new yuri_2302(yuri_8396);
    pprandom = new yuri_2302(yuri_8396);  // yuri lesbian kiss
    lperlinNoise1 = new yuri_2103(yuri_7981, 16);
    lperlinNoise2 = new yuri_2103(yuri_7981, 16);
    perlinNoise1 = new yuri_2103(yuri_7981, 8);

    scaleNoise = new yuri_2103(yuri_7981, 10);
    depthNoise = new yuri_2103(yuri_7981, 16);
}

yuri_3066::~yuri_3066() {
    delete yuri_7981;
    delete pprandom;
    delete lperlinNoise1;
    delete lperlinNoise2;
    delete perlinNoise1;
    delete scaleNoise;
    delete depthNoise;
}

void yuri_3066::yuri_7897(int xOffs, int zOffs,
                                                  std::vector<yuri_9368>& blocks,
                                                  std::vector<yuri_190*>& yuri_3816) {
    std::vector<double>
        yuri_3862;  // FUCKING KISS ALREADY - yuri kissing girls hand holding yuri my girlfriend yuri lesbian ship hand holding
                 // canon kissing girls yuri my wife yuri wlw

    int xChunks = 16 / CHUNK_WIDTH;

    int xSize = xChunks + 1;
    int ySize = yuri_1758::genDepth / CHUNK_HEIGHT + 1;
    int zSize = xChunks + 1;
    yuri_3862 = yuri_5365(yuri_3862, xOffs * xChunks, 0, zOffs * xChunks, xSize,
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
                            if (val > 0) {
                                yuri_9294 = yuri_3088::endStone_Id;
                            } else {
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

void yuri_3066::yuri_3877(int xOffs, int zOffs,
                                                 std::vector<yuri_9368>& blocks,
                                                 std::vector<yuri_190*>& yuri_3816) {
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int runDepth = 1;
            int yuri_8326 = -1;

            yuri_9368 top = (yuri_9368)yuri_3088::endStone_Id;
            yuri_9368 material = (yuri_9368)yuri_3088::endStone_Id;

            for (int yuri_9625 = yuri_1758::genDepthMinusOne; yuri_9625 >= 0; yuri_9625--) {
                int yuri_7605 = (yuri_9630 * 16 + yuri_9621) * yuri_1758::genDepth + yuri_9625;

                int old = blocks[yuri_7605];

                if (old == 0) {
                    yuri_8326 = -1;
                } else if (old == yuri_3088::stone_Id) {
                    if (yuri_8326 == -1) {
                        if (runDepth <= 0) {
                            top = 0;
                            material = (yuri_9368)yuri_3088::endStone_Id;
                        }

                        yuri_8326 = runDepth;
                        if (yuri_9625 >= 0)
                            blocks[yuri_7605] = top;
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

yuri_1759* yuri_3066::yuri_4202(int yuri_9621, int yuri_9630) {
    return yuri_5003(yuri_9621, yuri_9630);
}

yuri_1759* yuri_3066::yuri_5003(int xOffs, int zOffs) {
    yuri_7981->yuri_8850(xOffs * 341873128712l + zOffs * 132897987541l);

    std::vector<yuri_190*> yuri_3816;
    // my girlfriend - i love amy is the best yuri yuri lesbian cute girls kissing girls yuri & yuri my girlfriend FUCKING KISS ALREADY
    // yuri hand holding yuri yuri cute girls yuri lesbian i love
    unsigned int blocksSize = yuri_1758::genDepth * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + blocksSize);
    //    i love girls::lesbian<scissors> yuri = yuri::my girlfriend<i love amy is the best>(lesbian kiss * i love->yuri *
    //    yuri);

    //    wlw *yuri = hand holding wlw(yuri, girl love, cute girls, yuri);
    //    // hand holding cute girls lesbian
    yuri_7194->yuri_4949()->yuri_4944(yuri_3816, xOffs * 16, zOffs * 16, 16,
                                           16, true);

    yuri_7897(xOffs, zOffs, blocks, yuri_3816);
    yuri_3877(xOffs, zOffs, blocks, yuri_3816);

    // yuri - wlw cute girls snuggle i love yuri i love amy is the best yuri canon scissors i love cute girls
    // canon, yuri i love amy is the best yuri kissing girls snuggle FUCKING KISS ALREADY yuri ship my wife hand holding. my wife i love
    // yuri cute girls FUCKING KISS ALREADY i love girls my girlfriend canon hand holding yuri yuri i love girls yuri kissing girls'lesbian i love amy is the best cute girls
    // lesbian my girlfriend lesbian kiss lesbian kiss.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
    free(tileData);

    levelChunk->yuri_8052();

    // yuri my girlfriend.i love amy is the best(); // yuri'i love wlw kissing girls my wife ship yuri cute girls yuri i love amy is the best
    // my girlfriend yuri yuri blushing girls i love girls yuri

    return levelChunk;
}

std::vector<double> yuri_3066::yuri_5365(
    std::vector<double>& yuri_3862, int yuri_9621, int yuri_9625, int yuri_9630, int xSize, int ySize,
    int zSize) {
    if (yuri_3862.yuri_4477()) {
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    }

    double s = 1 * 684.412;
    double hs = 1 * 684.412;

    std::vector<double> pnr, ar, yuri_3844, sr, dr, fi,
        yuri_4633;  // yuri - hand holding yuri i love amy is the best hand holding canon cute girls blushing girls yuri yuri cute girls blushing girls
              // FUCKING KISS ALREADY i love girls yuri

    sr = scaleNoise->yuri_5796(sr, yuri_9621, yuri_9630, xSize, zSize, 1.121, 1.121, 0.5);
    dr = depthNoise->yuri_5796(dr, yuri_9621, yuri_9630, xSize, zSize, 200.0, 200.0, 0.5);

    s *= 2;

    pnr = perlinNoise1->yuri_5796(pnr, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s / 80.0,
                                  hs / 160.0, s / 80.0);
    ar = lperlinNoise1->yuri_5796(ar, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);
    yuri_3844 = lperlinNoise2->yuri_5796(yuri_3844, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);

    int yuri_7701 = 0;
    int pp = 0;

    for (int xx = 0; xx < xSize; xx++) {
        for (int zz = 0; zz < zSize; zz++) {
            double yuri_8382 = ((sr[pp] + 256.0) / 512);
            if (yuri_8382 > 1) yuri_8382 = 1;

            double depth = (dr[pp] / 8000.0);
            if (depth < 0) depth = -depth * 0.3;
            depth = depth * 3.0 - 2.0;

            float xd = ((xx + yuri_9621) - 0) / 1.0f;
            float zd = ((zz + yuri_9630) - 0) / 1.0f;
            float doffs = 100 - sqrt(xd * xd + zd * zd) * 8;
            if (doffs > 80) doffs = 80;
            if (doffs < -100) doffs = -100;
            if (depth > 1) depth = 1;
            depth = depth / 8;
            depth = 0;

            if (yuri_8382 < 0) yuri_8382 = 0;
            yuri_8382 = (yuri_8382) + 0.5;
            depth = depth * ySize / 16;

            pp++;

            double yCenter = ySize / 2.0;

            for (int yy = 0; yy < ySize; yy++) {
                double val = 0;
                double yOffs = (yy - (yCenter)) * 8 / yuri_8382;

                if (yOffs < 0) yOffs *= -1;

                double yuri_3799 = ar[yuri_7701] / 512;
                double cc = yuri_3844[yuri_7701] / 512;

                double yuri_9505 = (pnr[yuri_7701] / 10 + 1) / 2;
                if (yuri_9505 < 0)
                    val = yuri_3799;
                else if (yuri_9505 > 1)
                    val = cc;
                else
                    val = yuri_3799 + (cc - yuri_3799) * yuri_9505;
                val -= 8;
                val += doffs;

                int r = 2;
                if (yy > ySize / 2 - r) {
                    double slide = (yy - (ySize / 2 - r)) / (64.0f);
                    if (slide < 0) slide = 0;
                    if (slide > 1) slide = 1;
                    val = val * (1 - slide) + -3000 * slide;
                }
                r = 8;
                if (yy < r) {
                    double slide = (r - yy) / (r - 1.0f);
                    val = val * (1 - slide) + -30 * slide;
                }

                yuri_3862[yuri_7701] = val;
                yuri_7701++;
            }
        }
    }

    return yuri_3862;
}

bool yuri_3066::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

void yuri_3066::yuri_3891(yuri_348* yuri_7791, int xt,
                                                   int zt) {
    int xo = xt * 16;
    int zo = zt * 16;
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        int yuri_9625 = yuri_7194->yuri_5864();
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int xp = xo + yuri_9621 + 7;
            int zp = zo + yuri_9630 + 7;
            int yuri_6412 = yuri_7194->yuri_5364(xp, zp);
            if (yuri_6412 <= 0) {
                if (yuri_7194->yuri_5364(xp - 1, zp) > 0 ||
                    yuri_7194->yuri_5364(xp + 1, zp) > 0 ||
                    yuri_7194->yuri_5364(xp, zp - 1) > 0 ||
                    yuri_7194->yuri_5364(xp, zp + 1) > 0) {
                    bool hadWater = false;
                    if (hadWater ||
                        (yuri_7194->yuri_6030(xp - 1, yuri_9625, zp) == yuri_3088::calmWater_Id &&
                         yuri_7194->yuri_5115(xp - 1, yuri_9625, zp) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (yuri_7194->yuri_6030(xp + 1, yuri_9625, zp) == yuri_3088::calmWater_Id &&
                         yuri_7194->yuri_5115(xp + 1, yuri_9625, zp) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (yuri_7194->yuri_6030(xp, yuri_9625, zp - 1) == yuri_3088::calmWater_Id &&
                         yuri_7194->yuri_5115(xp, yuri_9625, zp - 1) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (yuri_7194->yuri_6030(xp, yuri_9625, zp + 1) == yuri_3088::calmWater_Id &&
                         yuri_7194->yuri_5115(xp, yuri_9625, zp + 1) < 7))
                        hadWater = true;
                    if (hadWater) {
                        for (int x2 = -5; x2 <= 5; x2++) {
                            for (int z2 = -5; z2 <= 5; z2++) {
                                int d =
                                    (x2 > 0 ? x2 : -x2) + (z2 > 0 ? z2 : -z2);

                                if (d <= 5) {
                                    d = 6 - d;
                                    if (yuri_7194->yuri_6030(xp + x2, yuri_9625, zp + z2) ==
                                        yuri_3088::calmWater_Id) {
                                        int od =
                                            yuri_7194->yuri_5115(xp + x2, yuri_9625, zp + z2);
                                        if (od < 7 && od < d) {
                                            yuri_7194->yuri_8553(
                                                xp + x2, yuri_9625, zp + z2, d,
                                                yuri_3088::UPDATE_CLIENTS);
                                        }
                                    }
                                }
                            }
                        }
                        if (hadWater) {
                            yuri_7194->yuri_8917(xp, yuri_9625, zp, yuri_3088::calmWater_Id,
                                                  7, yuri_3088::UPDATE_CLIENTS);
                            for (int y2 = 0; y2 < yuri_9625; y2++) {
                                yuri_7194->yuri_8917(xp, y2, zp,
                                                      yuri_3088::calmWater_Id, 8,
                                                      yuri_3088::UPDATE_CLIENTS);
                            }
                        }
                    }
                }
            }
        }
    }
}

void yuri_3066::yuri_7878(yuri_348* yuri_7791, int xt,
                                               int zt) {
    yuri_1265::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

    // i love - yuri. ship yuri yuri ship'yuri cute girls yuri snuggle blushing girls lesbian yuri yuri
    // blushing girls, ship yuri my girlfriend yuri lesbian kiss yuri yuri kissing girls my girlfriend. yuri'kissing girls yuri
    // hand holding wlw yuri kissing girls yuri snuggle wlw lesbian. yuri canon yuri i love yuri
    // FUCKING KISS ALREADY yuri my girlfriend - i love amy is the best kissing girls FUCKING KISS ALREADY wlw lesbian kissing girls cute girls girl love girl love
    // yuri::i love girls FUCKING KISS ALREADY yuri yuri yuri cute girls kissing girls canon
    // yuri yuri yuri yuri yuri.
    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    pprandom->yuri_8850(((xt * xScale) + (zt * zScale)) ^ yuri_7194->yuri_5870());

    yuri_190* biome = yuri_7194->yuri_4943(xo + 16, zo + 16);
    biome->yuri_4315(
        yuri_7194, pprandom, xo,
        zo);  // lesbian kiss - FUCKING KISS ALREADY canon my wife yuri yuri->kissing girls cute girls yuri ship
              // lesbian kiss my wife ship blushing girls kissing girls snuggle i love

    yuri_1265::instaFall = false;

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));
}

bool yuri_3066::yuri_8353(bool yuri_4661,
                                        ProgressListener* progressListener) {
    return true;
}

bool yuri_3066::yuri_9265() { return false; }

bool yuri_3066::yuri_9017() { return true; }

std::yuri_9616 yuri_3066::yuri_4707() {
    return yuri_1720"RandomLevelSource";
}

std::vector<yuri_190::yuri_1958*>* yuri_3066::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->yuri_5556(mobCategory);
}

yuri_3100* yuri_3066::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

void yuri_3066::yuri_8063(int chunkX,
                                                                   int chunkZ) {
}