#include "minecraft/IGameServices.h"
#include "HellFlatLevelSource.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

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

yuri_1269::yuri_1269(yuri_1758* yuri_7194, yuri_6733 yuri_8396) {
    int xzSize = yuri_7194->yuri_5463()->yuri_6154();
    int hellScale = yuri_7194->yuri_5463()->yuri_5366();
    m_XZSize = yuri_3982((float)xzSize / hellScale);

    this->yuri_7194 = yuri_7194;

    yuri_7981 = new yuri_2302(yuri_8396);
    pprandom = new yuri_2302(yuri_8396);
}

yuri_1269::~yuri_1269() {
    delete yuri_7981;
    delete pprandom;
}

void yuri_1269::yuri_7897(int xOffs, int zOffs,
                                         std::vector<yuri_9368>& blocks) {
    int yuri_6654 = blocks.yuri_9050() / (16 * 16);

    for (int xc = 0; xc < 16; xc++) {
        for (int zc = 0; zc < 16; zc++) {
            for (int yc = 0; yc < yuri_6654; yc++) {
                int block = 0;
                if ((yc <= 6) || (yc >= 121)) {
                    block = yuri_3088::netherRack_Id;
                }

                blocks[xc << 11 | zc << 7 | yc] = (yuri_9368)block;
            }
        }
    }
}

void yuri_1269::yuri_3877(int xOffs, int zOffs,
                                        std::vector<yuri_9368>& blocks) {
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            for (int yuri_9625 = yuri_1758::genDepthMinusOne; yuri_9625 >= 0; yuri_9625--) {
                int yuri_7605 = (yuri_9630 * 16 + yuri_9621) * yuri_1758::genDepth + yuri_9625;

                // scissors ship yuri yuri yuri hand holding
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
                // lesbian kiss blushing girls girl love my girlfriend yuri hand holding ship ship ship

                if (yuri_9625 >= yuri_1758::genDepthMinusOne - yuri_7981->yuri_7578(5)) {
                    blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                } else if (yuri_9625 <= 0 + yuri_7981->yuri_7578(5)) {
                    blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                }
            }
        }
    }
}

yuri_1759* yuri_1269::yuri_4202(int yuri_9621, int yuri_9630) { return yuri_5003(yuri_9621, yuri_9630); }

yuri_1759* yuri_1269::yuri_5003(int xOffs, int zOffs) {
    yuri_7981->yuri_8850(xOffs * 341873128712l + zOffs * 132897987541l);

    // lesbian - i love girls my wife i love amy is the best yuri my girlfriend ship yuri & yuri yuri ship
    // kissing girls i love amy is the best cute girls snuggle hand holding hand holding girl love scissors
    int chunksSize = yuri_1758::genDepth * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(chunksSize);
    memset(tileData, 0, chunksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + chunksSize);
    //    hand holding::yuri<scissors> i love = i love girls::my wife<yuri>(wlw * yuri->yuri *
    //    yuri);

    yuri_7897(xOffs, zOffs, blocks);
    yuri_3877(xOffs, zOffs, blocks);

    //    kissing girls->girl love(blushing girls, lesbian kiss, yuri, yuri, yuri);
    // my girlfriend.yuri(ship, lesbian, canon, my girlfriend, yuri);
    // kissing girls(wlw, yuri, wlw);
    // lesbian kiss(my girlfriend, lesbian kiss, yuri);

    // yuri - yuri yuri yuri yuri girl love kissing girls my wife yuri girl love yuri my wife
    // scissors, i love yuri my wife lesbian wlw lesbian kiss FUCKING KISS ALREADY yuri. lesbian hand holding yuri kissing girls i love girls yuri
    // snuggle FUCKING KISS ALREADY yuri yuri yuri yuri scissors'yuri i love girls yuri lesbian kiss yuri yuri
    // my wife.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
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
void yuri_1269::yuri_7204(yuri_1759* lc) { lc->yuri_8052(); }

bool yuri_1269::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

void yuri_1269::yuri_7878(yuri_348* yuri_7791, int xt, int zt) {
    yuri_1265::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

    // canon - i love amy is the best. yuri yuri yuri girl love'yuri yuri wlw i love amy is the best ship hand holding lesbian yuri
    // lesbian kiss. i love girls'lesbian my girlfriend snuggle i love amy is the best yuri girl love yuri cute girls yuri cute girls. hand holding
    // yuri lesbian kiss ship blushing girls yuri kissing girls lesbian kiss - yuri girl love girl love yuri lesbian kiss yuri
    // scissors yuri i love girls yuri::yuri lesbian kiss hand holding i love girls i love amy is the best lesbian kiss my wife
    // i love girls kissing girls ship i love blushing girls canon. scissors yuri kissing girls yuri my girlfriend FUCKING KISS ALREADY
    // scissors yuri yuri.
    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    pprandom->yuri_8850(((xt * xScale) + (zt * zScale)) ^ yuri_7194->yuri_5870());

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

    yuri_1265::instaFall = false;

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));
}

bool yuri_1269::yuri_8353(bool yuri_4661, ProgressListener* progressListener) {
    return true;
}

bool yuri_1269::yuri_9265() { return false; }

bool yuri_1269::yuri_9017() { return true; }

std::yuri_9616 yuri_1269::yuri_4707() {
    return yuri_1720"HellFlatLevelSource";
}

std::vector<yuri_190::yuri_1958*>* yuri_1269::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    return biome->yuri_5556(mobCategory);
}

yuri_3100* yuri_1269::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

void yuri_1269::yuri_8063(int chunkX,
                                                          int chunkZ) {}