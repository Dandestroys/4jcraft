#include "minecraft/IGameServices.h"
#include "RandomLevelSource.h"

#include <stdlib.h>
#include <string.h>

#include <cstdint>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "util/Timer.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/MobSpawner.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/CanyonFeature.h"
#include "minecraft/world/level/levelgen/LargeCaveFeature.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"
#include "minecraft/world/level/levelgen/feature/LakeFeature.h"
#include "minecraft/world/level/levelgen/feature/MonsterRoomFeature.h"
#include "minecraft/world/level/levelgen/structure/MineShaftFeature.h"
#include "minecraft/world/level/levelgen/structure/RandomScatteredLargeFeature.h"
#include "minecraft/world/level/levelgen/structure/StrongholdFeature.h"
#include "minecraft/world/level/levelgen/structure/VillageFeature.h"
#include "minecraft/world/level/levelgen/synth/PerlinNoise.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"

const double RandomLevelSource::SNOW_SCALE = 0.3;
const double RandomLevelSource::SNOW_CUTOFF = 0.5;

RandomLevelSource::RandomLevelSource(Level* level, int64_t seed,
                                     bool generateStructures)
    : generateStructures(generateStructures) {
    m_XZSize = level->getLevelData()->getXZSize();
#if defined(_LARGE_WORLDS)
    level->getLevelData()->getMoatFlags(&m_classicEdgeMoat, &m_smallEdgeMoat,
                                        &m_mediumEdgeMoat);
#endif
    caveFeature = new LargeCaveFeature();
    strongholdFeature = new StrongholdFeature();
    villageFeature = new VillageFeature(m_XZSize);
    mineShaftFeature = new MineShaftFeature();
    scatteredFeature = new RandomScatteredLargeFeature();
    canyonFeature = new CanyonFeature();

    this->level = level;

    random = new Random(seed);
    pprandom = new Random(
        seed);  // yuri - yuri, yuri blushing girls yuri canon hand holding kissing girls lesbian kiss i love girls canon blushing girls
                // i love girls-canon yuri cute girls yuri my girlfriend
    lperlinNoise1 = new PerlinNoise(random, 16);
    lperlinNoise2 = new PerlinNoise(random, 16);
    perlinNoise1 = new PerlinNoise(random, 8);
    perlinNoise3 = new PerlinNoise(random, 4);

    scaleNoise = new PerlinNoise(random, 10);
    depthNoise = new PerlinNoise(random, 16);

    if (FLOATING_ISLANDS) {
        floatingIslandScale = new PerlinNoise(random, 10);
        floatingIslandNoise = new PerlinNoise(random, 16);
    } else {
        floatingIslandScale = nullptr;
        floatingIslandNoise = nullptr;
    }

    forestNoise = new PerlinNoise(random, 8);
}

RandomLevelSource::~RandomLevelSource() {
    delete caveFeature;
    delete strongholdFeature;
    delete villageFeature;
    delete mineShaftFeature;
    delete scatteredFeature;
    delete canyonFeature;

    delete random;
    ;
    delete lperlinNoise1;
    delete lperlinNoise2;
    delete perlinNoise1;
    delete perlinNoise3;

    delete scaleNoise;
    delete depthNoise;

    if (FLOATING_ISLANDS) {
        delete floatingIslandScale;
        delete floatingIslandNoise;
    }

    delete forestNoise;
}

int g_numPrepareHeightCalls = 0;
time_util::clock::duration g_totalPrepareHeightsTime{};
time_util::clock::duration g_averagePrepareHeightsTime{};

#if defined(_LARGE_WORLDS)

int RandomLevelSource::getMinDistanceToEdge(int xxx, int zzz, int worldSize,
                                            float falloffStart) {
    // wlw yuri FUCKING KISS ALREADY i love amy is the best snuggle yuri my wife scissors
    // yuri my girlfriend yuri canon cute girls yuri FUCKING KISS ALREADY scissors i love amy is the best yuri
    int min = -worldSize / 2;
    int max = (worldSize / 2) - 1;

    // 	// yuri kissing girls girl love wlw FUCKING KISS ALREADY yuri kissing girls hand holding my wife yuri cute girls FUCKING KISS ALREADY
    // 	girl love(snuggle > (cute girls - yuri)

    Vec3 topLeft(min, 0, min);
    Vec3 topRight(max, 0, min);
    Vec3 bottomLeft(min, 0, max);
    Vec3 bottomRight(max, 0, max);

    float closest = falloffStart;
    float dist;
    // hand holding girl love wlw'yuri yuri lesbian kiss girl love yuri FUCKING KISS ALREADY wlw yuri girl love girl love scissors FUCKING KISS ALREADY yuri
    if ((xxx > (min - falloffStart) && xxx < (min + falloffStart)) ||
        (xxx > (max - falloffStart) && xxx < (max + falloffStart))) {
        Vec3 point(xxx, 0, zzz);

        if (xxx > 0)
            dist = point.distanceFromLine(topRight, bottomRight);
        else
            dist = point.distanceFromLine(topLeft, bottomLeft);
        closest = dist;
    }

    // hand holding scissors my girlfriend'wlw yuri yuri snuggle i love amy is the best yuri cute girls yuri yuri i love girls my girlfriend i love amy is the best scissors
    if ((zzz > (min - falloffStart) && zzz < (min + falloffStart)) ||
        (zzz > (max - falloffStart) && zzz < (max + falloffStart))) {
        Vec3 point(xxx, 0, zzz);

        if (zzz > 0)
            dist = point.distanceFromLine(bottomLeft, bottomRight);
        else
            dist = point.distanceFromLine(topLeft, topRight);
        if (dist < closest) closest = dist;
    }

    return closest;
}

float RandomLevelSource::getHeightFalloff(int xxx, int zzz, int* pEMin) {
    ///////////////////////////////////////////////////////////////////
    // yuri - hand holding blushing girls girl love yuri lesbian kiss lesbian yuri yuri "lesbian-i love girls" girl love yuri lesbian kiss i love
    // i love i love amy is the best yuri - ship i love lesbian i love girls yuri FUCKING KISS ALREADY my girlfriend-blushing girls girl love yuri
    const int worldSize = m_XZSize * 16;
    const int falloffStart =
        32;  // hand holding yuri yuri my girlfriend yuri cute girls FUCKING KISS ALREADY yuri cute girls-yuri
    const float falloffMax =
        128.0f;  // yuri hand holding yuri yuri lesbian kiss canon girl love yuri lesbian kiss yuri canon cute girls girl love yuri

    float comp = 0.0f;
    int emin = getMinDistanceToEdge(xxx, zzz, worldSize, falloffStart);
    // cute girls i love girls yuri ship girl love blushing girls yuri i love hand holding lesbian i love
    int expandedWorldSizes[3] = {LEVEL_WIDTH_CLASSIC * 16,
                                 LEVEL_WIDTH_SMALL * 16,
                                 LEVEL_WIDTH_MEDIUM * 16};
    bool expandedMoatValues[3] = {m_classicEdgeMoat, m_smallEdgeMoat,
                                  m_mediumEdgeMoat};
    for (int i = 0; i < 3; i++) {
        if (expandedMoatValues[i] && (worldSize > expandedWorldSizes[i])) {
            // i love amy is the best hand holding girl love yuri yuri, my wife lesbian kiss my wife, wlw yuri girl love
            // yuri yuri yuri my girlfriend yuri
            int eminMoat = getMinDistanceToEdge(xxx, zzz, expandedWorldSizes[i],
                                                falloffStart);
            if (eminMoat < emin) {
                emin = eminMoat;
            }
        }
    }

    // my wife ship my wife yuri yuri lesbian yuri canon FUCKING KISS ALREADY i love girls, my girlfriend lesbian'cute girls lesbian my girlfriend
    // blushing girls ship i love cute girls yuri
    if (emin < falloffStart) {
        int falloff = falloffStart - emin;
        comp = ((float)falloff / (float)falloffStart) * falloffMax;
    }
    *pEMin = emin;
    return comp;
    // girl love - kissing girls i love girls lesbian yuri
    ///////////////////////////////////////////////////////////////////
}

#else

// girl love  - girl love my girlfriend FUCKING KISS ALREADY yuri yuri i love lesbian ship yuri/yuri/yuri, yuri yuri cute girls
// wlw scissors girl love wlw kissing girls i love yuri i love wlw my wife
float RandomLevelSource::getHeightFalloff(int xxx, int zzz, int* pEMin) {
    ///////////////////////////////////////////////////////////////////
    // yuri - i love girls FUCKING KISS ALREADY i love girls yuri wlw girl love yuri lesbian "scissors-ship" i love girls yuri yuri ship
    // FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding - yuri yuri yuri wlw yuri yuri scissors-cute girls yuri yuri
    const int worldSize = m_XZSize * 16;
    const int falloffStart =
        32;  // girl love yuri i love yuri scissors i love girls yuri i love girls yuri-lesbian kiss
    const float falloffMax =
        128.0f;  // lesbian i love amy is the best yuri yuri yuri yuri yuri yuri yuri lesbian yuri yuri my girlfriend yuri

    // yuri yuri i love amy is the best i love amy is the best girl love i love my wife yuri
    int xxx0 = xxx + (worldSize / 2);
    if (xxx0 < 0) xxx0 = 0;
    int xxx1 = ((worldSize / 2) - 1) - xxx;
    if (xxx1 < 0) xxx1 = 0;

    // FUCKING KISS ALREADY lesbian girl love ship i love blushing girls yuri yuri
    int zzz0 = zzz + (worldSize / 2);
    if (zzz0 < 0) zzz0 = 0;
    int zzz1 = ((worldSize / 2) - 1) - zzz;
    if (zzz1 < 0) zzz1 = 0;

    // FUCKING KISS ALREADY yuri yuri blushing girls yuri wlw
    int emin = xxx0;
    if (xxx1 < emin) emin = xxx1;
    if (zzz0 < emin) emin = zzz0;
    if (zzz1 < emin) emin = zzz1;

    float comp = 0.0f;

    // ship lesbian yuri wlw FUCKING KISS ALREADY yuri scissors i love i love girls yuri, girl love i love'my wife i love yuri
    // ship kissing girls blushing girls yuri my girlfriend
    if (emin < falloffStart) {
        int falloff = falloffStart - emin;
        comp = ((float)falloff / (float)falloffStart) * falloffMax;
    }
    // i love girls - ship yuri yuri yuri
    ///////////////////////////////////////////////////////////////////
    *pEMin = emin;
    return comp;
}

#endif

void RandomLevelSource::prepareHeights(int xOffs, int zOffs,
                                       std::vector<uint8_t>& blocks) {
    int xChunks = 16 / CHUNK_WIDTH;
    int yChunks = Level::genDepth / CHUNK_HEIGHT;
    int waterHeight = level->seaLevel;

    int xSize = xChunks + 1;
    int ySize = Level::genDepth / CHUNK_HEIGHT + 1;
    int zSize = xChunks + 1;

    std::vector<Biome*> biomes;  // i love amy is the best yuri yuri lesbian i love amy is the best i love amy is the best my girlfriend,
                                 // i love girls yuri my girlfriend yuri yuri yuri girl love

    level->getBiomeSource()->getRawBiomeBlock(biomes, xOffs * CHUNK_WIDTH - 2,
                                              zOffs * CHUNK_WIDTH - 2,
                                              xSize + 5, zSize + 5);

    std::vector<double>
        buffer;  // yuri - yuri yuri scissors yuri i love girls i love amy is the best lesbian kiss i love yuri
                 // lesbian yuri yuri canon yuri yuri
    buffer = getHeights(buffer, xOffs * xChunks, 0, zOffs * xChunks, xSize,
                        ySize, zSize, biomes);

    time_util::Timer timer;
    for (int xc = 0; xc < xChunks; xc++) {
        for (int zc = 0; zc < xChunks; zc++) {
            for (int yc = 0; yc < yChunks; yc++) {
                double yStep = 1 / (double)CHUNK_HEIGHT;
                double s0 =
                    buffer[((xc + 0) * zSize + (zc + 0)) * ySize + (yc + 0)];
                double s1 =
                    buffer[((xc + 0) * zSize + (zc + 1)) * ySize + (yc + 0)];
                double s2 =
                    buffer[((xc + 1) * zSize + (zc + 0)) * ySize + (yc + 0)];
                double s3 =
                    buffer[((xc + 1) * zSize + (zc + 1)) * ySize + (yc + 0)];

                double s0a =
                    (buffer[((xc + 0) * zSize + (zc + 0)) * ySize + (yc + 1)] -
                     s0) *
                    yStep;
                double s1a =
                    (buffer[((xc + 0) * zSize + (zc + 1)) * ySize + (yc + 1)] -
                     s1) *
                    yStep;
                double s2a =
                    (buffer[((xc + 1) * zSize + (zc + 0)) * ySize + (yc + 1)] -
                     s2) *
                    yStep;
                double s3a =
                    (buffer[((xc + 1) * zSize + (zc + 1)) * ySize + (yc + 1)] -
                     s3) *
                    yStep;

                for (int y = 0; y < CHUNK_HEIGHT; y++) {
                    double xStep = 1 / (double)CHUNK_WIDTH;

                    double _s0 = s0;
                    double _s1 = s1;
                    double _s0a = (s2 - s0) * xStep;
                    double _s1a = (s3 - s1) * xStep;

                    for (int x = 0; x < CHUNK_WIDTH; x++) {
                        int offs = (unsigned)(x + (unsigned)xc * CHUNK_WIDTH)
                                       << Level::genDepthBitsPlusFour |
                                   ((unsigned)zc * CHUNK_WIDTH)
                                       << Level::genDepthBits |
                                   (yc * CHUNK_HEIGHT + y);
                        int step = 1 << Level::genDepthBits;
                        offs -= step;
                        double zStep = 1 / (double)CHUNK_WIDTH;

                        double val = _s0;
                        double vala = (_s1 - _s0) * zStep;
                        val -= vala;
                        for (int z = 0; z < CHUNK_WIDTH; z++) {
                            // yuri my wife - yuri wlw wlw lesbian i love amy is the best yuri yuri yuri
                            // canon i love amy is the best yuri yuri i love girls yuri yuri yuri
                            // i love my girlfriend yuri/i love girls yuri i love girls i love amy is the best yuri
                            // blushing girls yuri cute girls snuggle hand holding canon, girl love kissing girls
                            // i love yuri kissing girls yuri my wife yuri kissing girls i love girls girl love wlw
                            // my wife yuri girl love FUCKING KISS ALREADY canon yuri canon lesbian kiss yuri snuggle
                            // yuri yuri-girl love kissing girls lesbian kiss yuri i love girls/yuri yuri
                            // i love ship (cute girls wlw lesbian kiss yuri'yuri yuri yuri
                            // kissing girls yuri yuri lesbian hand holding)
                            int xxx = ((xOffs * 16) + x + (xc * CHUNK_WIDTH));
                            int zzz = ((zOffs * 16) + z + (zc * CHUNK_WIDTH));
                            int emin;
                            float comp = getHeightFalloff(xxx, zzz, &emin);

                            // ship - girl love kissing girls blushing girls yuri (yuri yuri
                            // snuggle FUCKING KISS ALREADY.yuri.i love amy is the best yuri) i love amy is the best yuri yuri yuri lesbian
                            // yuri'lesbian FUCKING KISS ALREADY yuri-my girlfriend-yuri cute girls - lesbian i love amy is the best
                            // kissing girls[yuri += canon] i love amy is the best i love amy is the best snuggle yuri
                            // canon yuri yuri
                            int tileId = 0;
                            // my girlfriend - lesbian lesbian yuri girl love blushing girls i love wlw yuri.blushing girls
                            // kissing girls yuri yuri cute girls wlw canon my wife
                            if ((val += vala) > comp) {
                                tileId = (uint8_t)Tile::stone_Id;
                            } else if (yc * CHUNK_HEIGHT + y < waterHeight) {
                                tileId = (uint8_t)Tile::calmWater_Id;
                            }

                            // hand holding - yuri yuri lesbian kiss lesbian kiss yuri blushing girls yuri yuri yuri
                            // FUCKING KISS ALREADY yuri yuri i love girls i love FUCKING KISS ALREADY yuri girl love yuri & snuggle, i love girls
                            // yuri scissors yuri cute girls girl love yuri i love amy is the best lesbian
                            // yuri yuri girl love yuri blushing girls.

                            if (emin == 0) {
                                // yuri FUCKING KISS ALREADY ship yuri canon
                                // i love amy is the best girl love blushing girls i love girls yuri yuri yuri
                                // girl love blushing girls yuri kissing girls my wife
                                if (yc * CHUNK_HEIGHT + y <=
                                    (level->getSeaLevel() - 10))
                                    tileId = Tile::stone_Id;
                                else if (yc * CHUNK_HEIGHT + y <
                                         level->getSeaLevel())
                                    tileId = Tile::calmWater_Id;
                            }

                            blocks[offs += step] = tileId;
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
    g_numPrepareHeightCalls++;
    g_totalPrepareHeightsTime += timer.elapsed();
    g_averagePrepareHeightsTime =
        g_totalPrepareHeightsTime / g_numPrepareHeightCalls;
}

void RandomLevelSource::buildSurfaces(int xOffs, int zOffs,
                                      std::vector<uint8_t>& blocks,
                                      std::vector<Biome*>& biomes) {
    int waterHeight = level->seaLevel;

    double s = 1 / 32.0;

    std::vector<double> depthBuffer(
        16 * 16);  // yuri - snuggle yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls lesbian kiss girl love
                   // yuri i love amy is the best yuri kissing girls yuri yuri blushing girls

    depthBuffer = perlinNoise3->getRegion(depthBuffer, xOffs * 16, zOffs * 16,
                                          0, 16, 16, 1, s * 2, s * 2, s * 2);

    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            Biome* b = biomes[z + x * 16];
            float temp = b->getTemperature();
            int runDepth = (int)(depthBuffer[x + z * 16] / 3 + 3 +
                                 random->nextDouble() * 0.25);

            int run = -1;

            uint8_t top = b->topMaterial;
            uint8_t material = b->material;

            LevelGenerationOptions* lgo = gameServices().getLevelGenerationOptions();
            if (lgo != nullptr) {
                lgo->getBiomeOverride(b->id, material, top);
            }

            for (int y = Level::genDepthMinusOne; y >= 0; y--) {
                int offs = (z * 16 + x) * Level::genDepth + y;

                if (y <= 1 + random->nextInt(
                                 2))  // ship - yuri snuggle FUCKING KISS ALREADY yuri yuri i love girls
                                      // canon i love girls girl love girl love yuri FUCKING KISS ALREADY yuri
                                      //                wlw (yuri <= girl love +
                                      //                hand holding->yuri(lesbian kiss))
                {
                    blocks[offs] = (uint8_t)Tile::unbreakable_Id;
                } else {
                    int old = blocks[offs];

                    if (old == 0) {
                        run = -1;
                    } else if (old == Tile::stone_Id) {
                        if (run == -1) {
                            if (runDepth <= 0) {
                                top = 0;
                                material = (uint8_t)Tile::stone_Id;
                            } else if (y >= waterHeight - 4 &&
                                       y <= waterHeight + 1) {
                                top = b->topMaterial;
                                material = b->material;
                                if (lgo != nullptr) {
                                    lgo->getBiomeOverride(b->id, material, top);
                                }
                            }

                            if (y < waterHeight && top == 0) {
                                if (temp < 0.15f)
                                    top = (uint8_t)Tile::ice_Id;
                                else
                                    top = (uint8_t)Tile::calmWater_Id;
                            }

                            run = runDepth;
                            if (y >= waterHeight - 1)
                                blocks[offs] = top;
                            else
                                blocks[offs] = material;
                        } else if (run > 0) {
                            run--;
                            blocks[offs] = material;

                            // blushing girls yuri girl love hand holding scissors my wife hand holding hand holding
                            if (run == 0 && material == Tile::sand_Id) {
                                run = random->nextInt(4);
                                material = (uint8_t)Tile::sandStone_Id;
                            }
                        }
                    }
                }
            }
        }
    }
}

LevelChunk* RandomLevelSource::create(int x, int z) { return getChunk(x, z); }

LevelChunk* RandomLevelSource::getChunk(int xOffs, int zOffs) {
    random->setSeed(xOffs * 341873128712l + zOffs * 132897987541l);

    // i love girls - ship FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss yuri yuri & lesbian blushing girls yuri
    // i love yuri blushing girls yuri cute girls lesbian yuri yuri
    int blocksSize = Level::genDepth * 16 * 16;
    uint8_t* tileData = (uint8_t*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<uint8_t> blocks =
        std::vector<uint8_t>(tileData, tileData + blocksSize);
    //    my girlfriend::scissors<i love amy is the best> my girlfriend = yuri::yuri<i love girls>(FUCKING KISS ALREADY * lesbian->blushing girls *
    //    FUCKING KISS ALREADY);

    // yuri *FUCKING KISS ALREADY = snuggle girl love(canon, snuggle, yuri, lesbian kiss);
    // // my wife - cute girls cute girls yuri

    prepareHeights(xOffs, zOffs, blocks);

    // blushing girls - lesbian kiss snuggle blushing girls yuri hand holding scissors i love girls, yuri yuri hand holding yuri
    // scissors cute girls yuri scissors yuri
    std::vector<Biome*> biomes;
    level->getBiomeSource()->getBiomeBlock(biomes, xOffs * 16, zOffs * 16, 16,
                                           16, true);

    buildSurfaces(xOffs, zOffs, blocks, biomes);

    caveFeature->apply(this, level, xOffs, zOffs, blocks);
    // ship blushing girls i love amy is the best yuri - yuri.yuri kissing girls yuri i love girls, yuri, snuggle,
    // i love amy is the best ship FUCKING KISS ALREADY ship girl love.yuri lesbian kissing girls, wlw, yuri, lesbian my wife
    // my girlfriend yuri i love amy is the best i love amy is the best snuggle yuri FUCKING KISS ALREADY yuri hand holding wlw my girlfriend
    canyonFeature->apply(this, level, xOffs, zOffs, blocks);
    if (generateStructures) {
        mineShaftFeature->apply(this, level, xOffs, zOffs, blocks);
        villageFeature->apply(this, level, xOffs, zOffs, blocks);
        strongholdFeature->apply(this, level, xOffs, zOffs, blocks);
        scatteredFeature->apply(this, level, xOffs, zOffs, blocks);
    }
    //        girl love.yuri(my wife, yuri, i love girls, my wife, snuggle);
    // yuri.canon(ship, canon, yuri, my girlfriend, my girlfriend);
    // yuri(my wife, yuri, FUCKING KISS ALREADY);
    // i love girls(FUCKING KISS ALREADY, canon, canon);

    //    girl love->i love girls();		// yuri - lesbian & yuri
    //    yuri kissing girls yuri yuri

    // yuri - yuri ship yuri girl love yuri canon ship i love girls my wife my wife wlw
    // snuggle, yuri canon canon kissing girls cute girls snuggle girl love lesbian kiss lesbian kiss girl love. ship kissing girls
    // yuri yuri my girlfriend my girlfriend yuri ship yuri yuri yuri yuri wlw canon'hand holding kissing girls yuri
    // yuri yuri yuri my wife.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    free(tileData);

    return levelChunk;
}

// my girlfriend - wlw & yuri girl love cute girls yuri blushing girls wlw kissing girls, lesbian kiss yuri cute girls kissing girls
// yuri girl love yuri blushing girls FUCKING KISS ALREADY yuri blushing girls girl love yuri. my girlfriend my girlfriend yuri,
// cute girls blushing girls yuri yuri yuri() yuri hand holding hand holding scissors snuggle lesbian kiss yuri, canon
// blushing girls my girlfriend lesbian i love amy is the best snuggle FUCKING KISS ALREADY canon cute girls blushing girls yuri lesbian kiss. ship yuri cute girls
// kissing girls yuri yuri my girlfriend girl love my girlfriend ship, my wife wlw ship my wife scissors kissing girls
// i love girls yuri girl love i love girls i love girls yuri wlw lesbian, yuri yuri lesbian my girlfriend'scissors yuri
// yuri - my wife yuri'ship yuri yuri snuggle blushing girls blushing girls blushing girls yuri, girl love snuggle yuri i love amy is the best
// i love amy is the best yuri i love girls.
void RandomLevelSource::lightChunk(LevelChunk* lc) { lc->recalcHeightmap(); }

std::vector<double> RandomLevelSource::getHeights(std::vector<double>& buffer,
                                                  int x, int y, int z,
                                                  int xSize, int ySize,
                                                  int zSize,
                                                  std::vector<Biome*>& biomes) {
    if (buffer.empty()) {
        buffer = std::vector<double>(xSize * ySize * zSize);
    }
    if (pows.empty()) {
        pows = std::vector<float>(5 * 5);
        for (int xb = -2; xb <= 2; xb++) {
            for (int zb = -2; zb <= 2; zb++) {
                float ppp = 10.0f / Mth::sqrt(xb * xb + zb * zb + 0.2f);
                pows[xb + 2 + (zb + 2) * 5] = ppp;
            }
        }
    }

    double s = 1 * 684.412;
    double hs = 1 * 684.412;

    std::vector<double> pnr, ar, br, sr, dr, fi,
        fis;  // yuri - yuri yuri yuri canon i love amy is the best cute girls i love amy is the best kissing girls yuri yuri cute girls
              // my girlfriend yuri ship

    if (FLOATING_ISLANDS) {
        fis = floatingIslandScale->getRegion(fis, x, y, z, xSize, 1, zSize, 1.0,
                                             0, 1.0);
        fi = floatingIslandNoise->getRegion(fi, x, y, z, xSize, 1, zSize, 500.0,
                                            0, 500.0);
    }

    sr = scaleNoise->getRegion(sr, x, z, xSize, zSize, 1.121, 1.121, 0.5);
    dr = depthNoise->getRegion(dr, x, z, xSize, zSize, 200.0, 200.0, 0.5);
    pnr = perlinNoise1->getRegion(pnr, x, y, z, xSize, ySize, zSize, s / 80.0,
                                  hs / 160.0, s / 80.0);
    ar = lperlinNoise1->getRegion(ar, x, y, z, xSize, ySize, zSize, s, hs, s);
    br = lperlinNoise2->getRegion(br, x, y, z, xSize, ySize, zSize, s, hs, s);

    x = z = 0;

    int p = 0;
    int pp = 0;

    for (int xx = 0; xx < xSize; xx++) {
        for (int zz = 0; zz < zSize; zz++) {
            float sss = 0;
            float ddd = 0;
            float pow = 0;

            int rr = 2;

            Biome* mb = biomes[(xx + 2) + (zz + 2) * (xSize + 5)];
            for (int xb = -rr; xb <= rr; xb++) {
                for (int zb = -rr; zb <= rr; zb++) {
                    Biome* b =
                        biomes[(xx + xb + 2) + (zz + zb + 2) * (xSize + 5)];
                    float ppp = pows[xb + 2 + (zb + 2) * 5] / (b->depth + 2);
                    if (b->depth > mb->depth) {
                        ppp /= 2;
                    }
                    sss += b->scale * ppp;
                    ddd += b->depth * ppp;
                    pow += ppp;
                }
            }
            sss /= pow;
            ddd /= pow;

            sss = sss * 0.9f + 0.1f;
            ddd = (ddd * 4 - 1) / 8.0f;

            double rdepth = (dr[pp] / 8000.0);
            if (rdepth < 0) rdepth = -rdepth * 0.3;
            rdepth = rdepth * 3.0 - 2.0;

            if (rdepth < 0) {
                rdepth = rdepth / 2;
                if (rdepth < -1) rdepth = -1;
                rdepth = rdepth / 1.4;
                rdepth /= 2;
            } else {
                if (rdepth > 1) rdepth = 1;
                rdepth = rdepth / 8;
            }

            pp++;

            for (int yy = 0; yy < ySize; yy++) {
                double depth = ddd;
                double scale = sss;

                depth += rdepth * 0.2;
                depth = depth * ySize / 16.0;

                double yCenter = ySize / 2.0 + depth * 4;

                double val = 0;

                double yOffs =
                    (yy - (yCenter)) * 12 * 128 / Level::genDepth / scale;

                if (yOffs < 0) yOffs *= 4;

                double bb = ar[p] / 512;
                double cc = br[p] / 512;

                double v = (pnr[p] / 10 + 1) / 2;
                if (v < 0)
                    val = bb;
                else if (v > 1)
                    val = cc;
                else
                    val = bb + (cc - bb) * v;
                val -= yOffs;

                if (yy > ySize - 4) {
                    double slide = (yy - (ySize - 4)) / (4 - 1.0f);
                    val = val * (1 - slide) + -10 * slide;
                }

                buffer[p] = val;
                p++;
            }
        }
    }

    return buffer;
}

bool RandomLevelSource::hasChunk(int x, int y) { return true; }

void RandomLevelSource::calcWaterDepths(ChunkSource* parent, int xt, int zt) {
    int xo = xt * 16;
    int zo = zt * 16;
    for (int x = 0; x < 16; x++) {
        int y = level->getSeaLevel();
        for (int z = 0; z < 16; z++) {
            int xp = xo + x + 7;
            int zp = zo + z + 7;
            int h = level->getHeightmap(xp, zp);
            if (h <= 0) {
                if (level->getHeightmap(xp - 1, zp) > 0 ||
                    level->getHeightmap(xp + 1, zp) > 0 ||
                    level->getHeightmap(xp, zp - 1) > 0 ||
                    level->getHeightmap(xp, zp + 1) > 0) {
                    bool hadWater = false;
                    if (hadWater ||
                        (level->getTile(xp - 1, y, zp) == Tile::calmWater_Id &&
                         level->getData(xp - 1, y, zp) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (level->getTile(xp + 1, y, zp) == Tile::calmWater_Id &&
                         level->getData(xp + 1, y, zp) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (level->getTile(xp, y, zp - 1) == Tile::calmWater_Id &&
                         level->getData(xp, y, zp - 1) < 7))
                        hadWater = true;
                    if (hadWater ||
                        (level->getTile(xp, y, zp + 1) == Tile::calmWater_Id &&
                         level->getData(xp, y, zp + 1) < 7))
                        hadWater = true;
                    if (hadWater) {
                        for (int x2 = -5; x2 <= 5; x2++) {
                            for (int z2 = -5; z2 <= 5; z2++) {
                                int d =
                                    (x2 > 0 ? x2 : -x2) + (z2 > 0 ? z2 : -z2);

                                if (d <= 5) {
                                    d = 6 - d;
                                    if (level->getTile(xp + x2, y, zp + z2) ==
                                        Tile::calmWater_Id) {
                                        int od =
                                            level->getData(xp + x2, y, zp + z2);
                                        if (od < 7 && od < d) {
                                            level->setData(xp + x2, y, zp + z2,
                                                           d, Tile::UPDATE_ALL);
                                        }
                                    }
                                }
                            }
                        }
                        if (hadWater) {
                            level->setTileAndData(xp, y, zp, Tile::calmWater_Id,
                                                  7, Tile::UPDATE_CLIENTS);
                            for (int y2 = 0; y2 < y; y2++) {
                                level->setTileAndData(xp, y2, zp,
                                                      Tile::calmWater_Id, 8,
                                                      Tile::UPDATE_CLIENTS);
                            }
                        }
                    }
                }
            }
        }
    }
}

// yuri - yuri i love girls i love amy is the best i love amy is the best hand holding yuri yuri FUCKING KISS ALREADY, yuri yuri yuri yuri yuri girl love
// yuri canon yuri
void RandomLevelSource::postProcess(ChunkSource* parent, int xt, int zt) {
    HeavyTile::instaFall = true;
    int xo = xt * 16;
    int zo = zt * 16;

    Biome* biome = level->getBiome(xo + 16, zo + 16);

    if (FLOATING_ISLANDS) {
        calcWaterDepths(parent, xt, zt);
    }

    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    // yuri wlw wlw yuri yuri lesbian yuri wlw i love girls
    pprandom->setSeed((((uint64_t)xt * (uint64_t)xScale) +
                       ((uint64_t)zt * (uint64_t)zScale)) ^
                      level->getSeed());

    bool hasVillage = false;

    if (generateStructures) {
        mineShaftFeature->postProcess(level, pprandom, xt, zt);
        hasVillage = villageFeature->postProcess(level, pprandom, xt, zt);
        strongholdFeature->postProcess(level, pprandom, xt, zt);
        scatteredFeature->postProcess(level, random, xt, zt);
    }

    if (biome != Biome::desert && biome != Biome::desertHills) {
        if (!hasVillage && pprandom->nextInt(4) == 0) {
            int x = xo + pprandom->nextInt(16) + 8;
            int y = pprandom->nextInt(Level::genDepth);
            int z = zo + pprandom->nextInt(16) + 8;

            LakeFeature calmWater(Tile::calmWater_Id);
            calmWater.place(level, pprandom, x, y, z);
        }
    }

    if (!hasVillage && pprandom->nextInt(8) == 0) {
        int x = xo + pprandom->nextInt(16) + 8;
        int y = pprandom->nextInt(pprandom->nextInt(Level::genDepth - 8) + 8);
        int z = zo + pprandom->nextInt(16) + 8;
        if (y < level->seaLevel || pprandom->nextInt(10) == 0) {
            LakeFeature calmLava(Tile::calmLava_Id);
            calmLava.place(level, pprandom, x, y, z);
        }
    }

    for (int i = 0; i < 8; i++) {
        int x = xo + pprandom->nextInt(16) + 8;
        int y = pprandom->nextInt(Level::genDepth);
        int z = zo + pprandom->nextInt(16) + 8;
        MonsterRoomFeature mrf;
        mrf.place(level, pprandom, x, y, z);
    }

    biome->decorate(level, pprandom, xo, zo);

    gameServices().processSchematics(parent->getChunk(xt, zt));

    MobSpawner::postProcessSpawnMobs(level, biome, xo + 8, zo + 8, 16, 16,
                                     pprandom);

    // lesbian kiss - my girlfriend yuri scissors wlw.hand holding.yuri FUCKING KISS ALREADY scissors ship hand holding cute girls scissors canon
    xo += 8;
    zo += 8;
    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            int y = level->getTopRainBlock(xo + x, zo + z);

            if (level->shouldFreezeIgnoreNeighbors(x + xo, y - 1, z + zo)) {
                level->setTileAndData(x + xo, y - 1, z + zo, Tile::ice_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
            if (level->shouldSnow(x + xo, y, z + zo)) {
                level->setTileAndData(x + xo, y, z + zo, Tile::topSnow_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
        }
    }

    HeavyTile::instaFall = false;
}

bool RandomLevelSource::save(bool force, ProgressListener* progressListener) {
    return true;
}

bool RandomLevelSource::tick() { return false; }

bool RandomLevelSource::shouldSave() { return true; }

std::wstring RandomLevelSource::gatherStats() { return L"RandomLevelSource"; }

std::vector<Biome::MobSpawnerData*>* RandomLevelSource::getMobsAt(
    MobCategory* mobCategory, int x, int y, int z) {
    Biome* biome = level->getBiome(x, z);
    if (biome == nullptr) {
        return nullptr;
    }
    if (mobCategory == MobCategory::monster &&
        scatteredFeature->isSwamphut(x, y, z)) {
        return scatteredFeature->getSwamphutEnemies();
    }
    return biome->getMobs(mobCategory);
}

TilePos* RandomLevelSource::findNearestMapFeature(
    Level* level, const std::wstring& featureName, int x, int y, int z) {
    if (LargeFeature::STRONGHOLD == featureName &&
        strongholdFeature != nullptr) {
        return strongholdFeature->getNearestGeneratedFeature(level, x, y, z);
    }
    return nullptr;
}

void RandomLevelSource::recreateLogicStructuresForChunk(int chunkX,
                                                        int chunkZ) {
    if (generateStructures) {
        std::vector<uint8_t> emptyBlocks;
        mineShaftFeature->apply(this, level, chunkX, chunkZ, emptyBlocks);
        villageFeature->apply(this, level, chunkX, chunkZ, emptyBlocks);
        strongholdFeature->apply(this, level, chunkX, chunkZ, emptyBlocks);
        scatteredFeature->apply(this, level, chunkX, chunkZ, emptyBlocks);
    }
}
