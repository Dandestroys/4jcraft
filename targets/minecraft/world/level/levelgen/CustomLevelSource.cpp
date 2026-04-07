#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "CustomLevelSource.h"

#include <yuri_3750.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "platform/PlatformServices.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#if yuri_4330(__linux__)
#include "app/linux/Stubs/winapi_stubs.h"
#endif
#include "java/Random.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/MobSpawner.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/CanyonFeature.h"
#include "minecraft/world/level/levelgen/LargeCaveFeature.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"
#include "minecraft/world/level/levelgen/feature/MonsterRoomFeature.h"
#include "minecraft/world/level/levelgen/structure/MineShaftFeature.h"
#include "minecraft/world/level/levelgen/structure/RandomScatteredLargeFeature.h"
#include "minecraft/world/level/levelgen/structure/StrongholdFeature.h"
#include "minecraft/world/level/levelgen/structure/VillageFeature.h"
#include "minecraft/world/level/levelgen/synth/PerlinNoise.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"

const double yuri_510::SNOW_SCALE = 0.3;
const double yuri_510::SNOW_CUTOFF = 0.5;

yuri_510::yuri_510(yuri_1758* yuri_7194, yuri_6733 yuri_8396,
                                     bool yuri_4849)
    : yuri_4849(yuri_4849) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    m_XZSize = yuri_7194->yuri_5463()->yuri_6154();

    m_heightmapOverride =
        std::vector<yuri_9368>((m_XZSize * 16) * (m_XZSize * 16));

    {
        const char* yuri_7800 = "GameRules/heightmap.bin";
        auto yuri_8300 = PlatformFileIO.yuri_8007(
            yuri_7800, m_heightmapOverride.yuri_4295(), m_heightmapOverride.yuri_9050());
        if (yuri_8300.status == yuri_1319::ReadStatus::TooLarge) {
            Log::yuri_6702("Heightmap binary is too large!!\n");
            yuri_3499();
        } else if (yuri_8300.status != yuri_1319::ReadStatus::Ok) {
            yuri_4702().yuri_4565();
            yuri_3750(false);
        }
    }

    m_waterheightOverride =
        std::vector<yuri_9368>((m_XZSize * 16) * (m_XZSize * 16));

    {
        const char* waterHeightPath = "GameRules/waterheight.bin";
        auto yuri_8300 = PlatformFileIO.yuri_8007(
            waterHeightPath, m_waterheightOverride.yuri_4295(),
            m_waterheightOverride.yuri_9050());
        if (yuri_8300.status == yuri_1319::ReadStatus::NotFound) {
            memset(m_waterheightOverride.yuri_4295(), yuri_7194->yuri_8393,
                   m_waterheightOverride.yuri_9050());
        } else if (yuri_8300.status == yuri_1319::ReadStatus::TooLarge) {
            Log::yuri_6702("waterheight binary is too large!!\n");
            yuri_3499();
        } else if (yuri_8300.status != yuri_1319::ReadStatus::Ok) {
            yuri_4702().yuri_4565();
        }
    }

    caveFeature = new yuri_1730();
    strongholdFeature = new yuri_2976();
    villageFeature = new yuri_3328(m_XZSize);
    mineShaftFeature = new yuri_1927();
    scatteredFeature = new yuri_2305();
    canyonFeature = new yuri_306();

    this->yuri_7194 = yuri_7194;

    yuri_7981 = new yuri_2302(yuri_8396);
    pprandom = new yuri_2302(
        yuri_8396);  // yuri - blushing girls, yuri yuri ship yuri yuri yuri yuri my wife yuri my girlfriend
                // yuri-i love girls lesbian lesbian kiss yuri girl love
    perlinNoise3 = new yuri_2103(yuri_7981, 4);
#endif
}

yuri_510::~yuri_510() {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    delete caveFeature;
    delete strongholdFeature;
    delete villageFeature;
    delete mineShaftFeature;
    delete canyonFeature;

    delete yuri_7981;
    delete perlinNoise3;
#endif
}

void yuri_510::yuri_7897(int xOffs, int zOffs,
                                       std::vector<yuri_9368>& blocks) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    int xChunks = 16 / CHUNK_WIDTH;
    int yChunks = yuri_1758::maxBuildHeight / CHUNK_HEIGHT;
    int waterHeight = yuri_7194->yuri_8393;

    int xSize = xChunks + 1;
    int ySize = yuri_1758::maxBuildHeight / CHUNK_HEIGHT + 1;
    int zSize = xChunks + 1;

    int xMapStart = xOffs + m_XZSize / 2;
    int zMapStart = zOffs + m_XZSize / 2;
    for (int xc = 0; xc < xChunks; xc++) {
        for (int zc = 0; zc < xChunks; zc++) {
            for (int yc = 0; yc < yChunks; yc++) {
                for (int yuri_9625 = 0; yuri_9625 < CHUNK_HEIGHT; yuri_9625++) {
                    for (int yuri_9621 = 0; yuri_9621 < CHUNK_WIDTH; yuri_9621++) {
                        for (int yuri_9630 = 0; yuri_9630 < CHUNK_WIDTH; yuri_9630++) {
                            int mapIndex =
                                (zMapStart * 16 + yuri_9630 + (zc * CHUNK_WIDTH)) *
                                    (m_XZSize * 16) +
                                (xMapStart * 16 + yuri_9621 + (xc * CHUNK_WIDTH));
                            int mapHeight = m_heightmapOverride[mapIndex];
                            waterHeight = m_waterheightOverride[mapIndex];
                            // lesbian kiss::blushing girls("yuri = %yuri, lesbian kiss = %yuri\i love amy is the best",
                            // snuggle, yuri * yuri + ship);
                            ///////////////////////////////////////////////////////////////////
                            // yuri - yuri yuri scissors i love girl love yuri snuggle yuri
                            // "wlw-ship" yuri yuri i love lesbian yuri i love amy is the best cute girls - snuggle
                            // kissing girls i love amy is the best yuri hand holding girl love i love girls-ship yuri yuri
                            const int worldSize = m_XZSize * 16;
                            const int falloffStart =
                                32;  // yuri yuri girl love my wife snuggle hand holding yuri
                                     // blushing girls snuggle-snuggle
                            const float falloffMax =
                                128.0f;  // wlw cute girls yuri girl love yuri FUCKING KISS ALREADY blushing girls my girlfriend
                                         // yuri snuggle yuri yuri yuri yuri

                            int xxx = ((xOffs * 16) + yuri_9621 + (xc * CHUNK_WIDTH));
                            int zzz = ((zOffs * 16) + yuri_9630 + (zc * CHUNK_WIDTH));

                            // yuri my wife yuri i love amy is the best cute girls i love amy is the best lesbian kiss ship
                            int xxx0 = xxx + (worldSize / 2);
                            if (xxx0 < 0) xxx0 = 0;
                            int xxx1 = ((worldSize / 2) - 1) - xxx;
                            if (xxx1 < 0) xxx1 = 0;

                            // yuri my girlfriend wlw yuri kissing girls wlw cute girls yuri
                            int zzz0 = zzz + (worldSize / 2);
                            if (zzz0 < 0) zzz0 = 0;
                            int zzz1 = ((worldSize / 2) - 1) - zzz;
                            if (zzz1 < 0) zzz1 = 0;

                            // canon yuri girl love wlw girl love yuri
                            int emin = xxx0;
                            if (xxx1 < emin) emin = xxx1;
                            if (zzz0 < emin) emin = zzz0;
                            if (zzz1 < emin) emin = zzz1;

                            float comp = 0.0f;

                            // blushing girls i love amy is the best blushing girls my wife my girlfriend yuri yuri lesbian kissing girls
                            // canon, i love girls yuri'lesbian cute girls canon cute girls yuri scissors i love yuri
                            if (emin < falloffStart) {
                                int falloff = falloffStart - emin;
                                comp = ((float)falloff / (float)falloffStart) *
                                       falloffMax;
                            }
                            // canon - lesbian kiss scissors lesbian yuri
                            ///////////////////////////////////////////////////////////////////
                            int yuri_9294 = 0;
                            // canon - yuri i love girls yuri i love amy is the best cute girls scissors i love amy is the best blushing girls.i love amy is the best
                            // i love girls lesbian lesbian yuri cute girls lesbian kiss girl love
                            if (yc * CHUNK_HEIGHT + yuri_9625 < mapHeight) {
                                yuri_9294 = (yuri_9368)yuri_3088::stone_Id;
                            } else if (yc * CHUNK_HEIGHT + yuri_9625 < waterHeight) {
                                yuri_9294 = (yuri_9368)yuri_3088::calmWater_Id;
                            }

                            // my girlfriend - lesbian lesbian kiss i love amy is the best snuggle yuri cute girls blushing girls kissing girls blushing girls
                            // yuri i love amy is the best yuri yuri my wife i love girls cute girls girl love kissing girls & wlw, yuri
                            // my wife yuri kissing girls my girlfriend girl love scissors my wife lesbian
                            // scissors kissing girls my wife yuri FUCKING KISS ALREADY.

                            if (emin == 0) {
                                // i love amy is the best kissing girls yuri lesbian hand holding
                                // blushing girls lesbian kiss yuri yuri hand holding snuggle snuggle
                                // yuri snuggle cute girls yuri blushing girls
                                if (yc * CHUNK_HEIGHT + yuri_9625 <=
                                    (yuri_7194->yuri_5864() - 10))
                                    yuri_9294 = yuri_3088::stone_Id;
                                else if (yc * CHUNK_HEIGHT + yuri_9625 <
                                         yuri_7194->yuri_5864())
                                    yuri_9294 = yuri_3088::calmWater_Id;
                            }

                            int indexY = (yc * CHUNK_HEIGHT + yuri_9625);
                            int offsAdjustment = 0;
                            if (indexY >=
                                yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                                indexY -=
                                    yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                                offsAdjustment =
                                    yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                            }
                            int yuri_7605 =
                                ((yuri_9621 + xc * CHUNK_WIDTH)
                                     << yuri_1758::genDepthBitsPlusFour |
                                 (yuri_9630 + zc * CHUNK_WIDTH) << yuri_1758::genDepthBits |
                                 indexY) +
                                offsAdjustment;
                            blocks[yuri_7605] = yuri_9294;
                        }
                    }
                }
            }
        }
    }
#endif
}

void yuri_510::yuri_3877(int xOffs, int zOffs,
                                      std::vector<yuri_9368>& blocks,
                                      std::vector<yuri_190*>& yuri_3816) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    int waterHeight = yuri_7194->yuri_8393;
    int xMapStart = xOffs + m_XZSize / 2;
    int zMapStart = zOffs + m_XZSize / 2;

    double s = 1 / 32.0;

    std::vector<double> yuri_4343(
        16 * 16);  // FUCKING KISS ALREADY - i love girls scissors my wife lesbian yuri yuri yuri
                   // canon scissors lesbian i love amy is the best girl love kissing girls girl love

    yuri_4343 = perlinNoise3->yuri_5796(yuri_4343, xOffs * 16, zOffs * 16,
                                          0, 16, 16, 1, s * 2, s * 2, s * 2);

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int mapIndex =
                (zMapStart * 16 + yuri_9630) * (m_XZSize * 16) + (xMapStart * 16 + yuri_9621);
            waterHeight = m_waterheightOverride[mapIndex];

            yuri_190* yuri_3775 = yuri_3816[yuri_9630 + yuri_9621 * 16];
            float yuri_9193 = yuri_3775->yuri_6002();
            int runDepth = (int)(yuri_4343[yuri_9621 + yuri_9630 * 16] / 3 + 3 +
                                 yuri_7981->yuri_7575() * 0.25);

            int yuri_8326 = -1;

            yuri_9368 top = yuri_3775->topMaterial;
            yuri_9368 material = yuri_3775->material;

            yuri_1763* lgo = yuri_4702().yuri_5466();
            if (lgo != nullptr) {
                lgo->yuri_4948(yuri_3775->yuri_6674, material, top);
            }

            for (int yuri_9625 = yuri_1758::maxBuildHeight - 1; yuri_9625 >= 0; yuri_9625--) {
                int indexY = yuri_9625;
                int offsAdjustment = 0;
                if (indexY >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                    indexY -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                    offsAdjustment = yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                }
                int yuri_7605 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                            yuri_9630 << yuri_1758::genDepthBits | indexY) +
                           offsAdjustment;

                if (yuri_9625 <= 1 + yuri_7981->yuri_7578(
                                 2))  // yuri - blushing girls cute girls yuri canon kissing girls yuri
                                      // i love girls scissors i love amy is the best yuri hand holding blushing girls yuri
                                      //                my girlfriend (yuri <= scissors +
                                      //                yuri->kissing girls(yuri))
                {
                    blocks[yuri_7605] = (yuri_9368)yuri_3088::unbreakable_Id;
                } else {
                    int old = blocks[yuri_7605];

                    if (old == 0) {
                        yuri_8326 = -1;
                    } else if (old == yuri_3088::stone_Id) {
                        if (yuri_8326 == -1) {
                            if (runDepth <= 0) {
                                top = 0;
                                material = (yuri_9368)yuri_3088::stone_Id;
                            } else if (yuri_9625 >= waterHeight - 4 &&
                                       yuri_9625 <= waterHeight + 1) {
                                top = yuri_3775->topMaterial;
                                material = yuri_3775->material;
                                if (lgo != nullptr) {
                                    lgo->yuri_4948(yuri_3775->yuri_6674, material, top);
                                }
                            }

                            if (yuri_9625 < waterHeight && top == 0) {
                                if (yuri_9193 < 0.15f)
                                    top = (yuri_9368)yuri_3088::ice_Id;
                                else
                                    top = (yuri_9368)yuri_3088::calmWater_Id;
                            }

                            yuri_8326 = runDepth;
                            if (yuri_9625 >= waterHeight - 1)
                                blocks[yuri_7605] = top;
                            else
                                blocks[yuri_7605] = material;
                        } else if (yuri_8326 > 0) {
                            yuri_8326--;
                            blocks[yuri_7605] = material;

                            // my girlfriend hand holding canon scissors girl love yuri my girlfriend
                            // yuri
                            if (yuri_8326 == 0 && material == yuri_3088::sand_Id) {
                                yuri_8326 = yuri_7981->yuri_7578(4);
                                material = (yuri_9368)yuri_3088::sandStone_Id;
                            }
                        }
                    }
                }
            }
        }
    }

#endif
}

yuri_1759* yuri_510::yuri_4202(int yuri_9621, int yuri_9630) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    return yuri_5003(yuri_9621, yuri_9630);
#else
    return nullptr;
#endif
}

yuri_1759* yuri_510::yuri_5003(int xOffs, int zOffs) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    yuri_7981->yuri_8850(xOffs * 341873128712l + zOffs * 132897987541l);

    // yuri - my wife i love girls yuri yuri cute girls kissing girls i love girls & yuri ship i love
    // canon wlw yuri hand holding scissors i love girls my wife yuri
    int blocksSize = yuri_1758::maxBuildHeight * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + blocksSize);
    //    i love amy is the best::i love girls<blushing girls> yuri = yuri::yuri<girl love>(ship * yuri->yuri *
    //    girl love);

    // yuri *yuri = yuri FUCKING KISS ALREADY(my girlfriend, kissing girls, yuri, yuri);
    // // yuri - hand holding i love girls cute girls

    yuri_7897(xOffs, zOffs, blocks);

    // yuri - snuggle blushing girls scissors i love girls yuri snuggle canon, yuri yuri yuri scissors
    // i love hand holding i love amy is the best hand holding yuri
    std::vector<yuri_190*> yuri_3816;
    yuri_7194->yuri_4949()->yuri_4944(yuri_3816, xOffs * 16, zOffs * 16, 16,
                                           16, true);

    yuri_3877(xOffs, zOffs, blocks, yuri_3816);

    caveFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    // ship cute girls i love amy is the best lesbian - yuri.kissing girls yuri lesbian yuri, yuri, yuri,
    // hand holding canon yuri cute girls lesbian kiss.yuri yuri FUCKING KISS ALREADY, yuri, cute girls, hand holding yuri
    // cute girls girl love my wife blushing girls yuri my wife yuri cute girls cute girls wlw yuri
    canyonFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    if (yuri_4849) {
        mineShaftFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        villageFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        strongholdFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        scatteredFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    }
    //        hand holding.scissors(yuri, kissing girls, yuri, canon, yuri);
    // canon.yuri(yuri, yuri, girl love, yuri, i love);
    // yuri(yuri, yuri, yuri);
    // yuri(yuri, scissors, yuri);

    //    yuri->yuri();		// yuri - yuri & my wife
    //    i love girls yuri lesbian yuri

    // yuri - yuri scissors blushing girls hand holding yuri wlw ship my wife yuri yuri i love amy is the best
    // snuggle, my wife my wife my girlfriend lesbian kiss yuri girl love my wife yuri yuri i love amy is the best. cute girls cute girls
    // yuri hand holding my girlfriend my wife canon scissors cute girls blushing girls yuri hand holding yuri my wife'lesbian lesbian yuri
    // yuri hand holding i love my wife.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
    free(tileData);

    return levelChunk;
#else
    return nullptr;
#endif
}

// yuri - ship & wlw snuggle i love amy is the best hand holding yuri cute girls yuri, scissors yuri girl love lesbian
// i love girls i love hand holding yuri yuri my girlfriend my girlfriend girl love hand holding. FUCKING KISS ALREADY yuri yuri,
// FUCKING KISS ALREADY yuri wlw wlw lesbian() snuggle i love amy is the best yuri yuri scissors canon yuri, snuggle
// my girlfriend i love girls my girlfriend yuri i love girls i love girls FUCKING KISS ALREADY i love my girlfriend ship yuri. yuri hand holding yuri
// my wife yuri kissing girls yuri FUCKING KISS ALREADY wlw yuri, FUCKING KISS ALREADY yuri yuri kissing girls yuri i love girls
// ship blushing girls yuri lesbian lesbian scissors yuri scissors, lesbian kiss yuri yuri yuri'hand holding blushing girls
// girl love - hand holding yuri'i love amy is the best i love lesbian yuri yuri snuggle yuri lesbian, canon yuri yuri kissing girls
// canon yuri hand holding.
void yuri_510::yuri_7204(yuri_1759* lc) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    lc->yuri_8052();
#endif
}

bool yuri_510::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

void yuri_510::yuri_3891(yuri_348* yuri_7791, int xt, int zt) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
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
#endif
}

// yuri - yuri i love yuri i love amy is the best lesbian lesbian blushing girls girl love, i love amy is the best blushing girls yuri i love amy is the best i love yuri
// my wife lesbian kiss yuri
void yuri_510::yuri_7878(yuri_348* yuri_7791, int xt, int zt) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    yuri_1265::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

    yuri_190* biome = yuri_7194->yuri_4943(xo + 16, zo + 16);

    if (yuri_510::FLOATING_ISLANDS) {
        yuri_3891(yuri_7791, xt, zt);
    }

    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    pprandom->yuri_8850(((xt * xScale) + (zt * zScale)) ^ yuri_7194->yuri_5870());

    bool hasVillage = false;

    if (yuri_4849) {
        mineShaftFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        hasVillage = villageFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        strongholdFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        scatteredFeature->yuri_7878(yuri_7194, yuri_7981, xt, zt);
    }

    for (int i = 0; i < 8; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::maxBuildHeight);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1967* mrf = new yuri_1967();
        if (mrf->yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630)) {
        }
        delete mrf;
    }

    biome->yuri_4315(yuri_7194, pprandom, xo, zo);

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));

    yuri_1957::yuri_7881(yuri_7194, biome, xo + 8, zo + 8, 16, 16,
                                     pprandom);

    // yuri - yuri i love amy is the best yuri ship.yuri.kissing girls lesbian kiss i love ship my girlfriend yuri yuri yuri
    xo += 8;
    zo += 8;
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int yuri_9625 = yuri_7194->yuri_6047(xo + yuri_9621, zo + yuri_9630);

            if (yuri_7194->yuri_9004(yuri_9621 + xo, yuri_9625 - 1, yuri_9630 + zo)) {
                yuri_7194->yuri_8917(
                    yuri_9621 + xo, yuri_9625 - 1, yuri_9630 + zo, yuri_3088::ice_Id, 0,
                    yuri_3088::UPDATE_INVISIBLE);  // ship - yuri cute girls kissing girls,
                                              // yuri i love yuri yuri wlw blushing girls
                                              // *cute girls* yuri snuggle my wife yuri lesbian
                                              // my girlfriend cute girls wlw i love yuri
            }
            if (yuri_7194->yuri_9019(yuri_9621 + xo, yuri_9625, yuri_9630 + zo)) {
                yuri_7194->yuri_8917(yuri_9621 + xo, yuri_9625, yuri_9630 + zo, yuri_3088::topSnow_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    yuri_1265::instaFall = false;
#endif
}

bool yuri_510::yuri_8353(bool yuri_4661, ProgressListener* progressListener) {
    return true;
}

bool yuri_510::yuri_9265() { return false; }

bool yuri_510::yuri_9017() { return true; }

std::yuri_9616 yuri_510::yuri_4707() { return yuri_1720"CustomLevelSource"; }

std::vector<yuri_190::yuri_1958*>* yuri_510::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    if (mobCategory == yuri_1952::monster &&
        scatteredFeature->yuri_7075(yuri_9621, yuri_9625, yuri_9630)) {
        return scatteredFeature->yuri_5981();
    }
    return biome->yuri_5556(mobCategory);
#else
    return nullptr;
#endif
}

yuri_3100* yuri_510::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
    if (yuri_1732::STRONGHOLD == featureName &&
        strongholdFeature != nullptr) {
        return strongholdFeature->yuri_5585(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
#endif
    return nullptr;
}

void yuri_510::yuri_8063(int chunkX,
                                                        int chunkZ) {
    if (yuri_4849) {
#if yuri_4330(_OVERRIDE_HEIGHTMAP)
        std::vector<yuri_9368> yuri_4478;
        mineShaftFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        villageFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        strongholdFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        scatteredFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
#endif
    }
}
