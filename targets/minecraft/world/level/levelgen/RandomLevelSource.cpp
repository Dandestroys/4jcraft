#include "minecraft/IGameServices.h"
#include "RandomLevelSource.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

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

const double yuri_2303::SNOW_SCALE = 0.3;
const double yuri_2303::SNOW_CUTOFF = 0.5;

yuri_2303::yuri_2303(yuri_1758* yuri_7194, yuri_6733 yuri_8396,
                                     bool yuri_4849)
    : yuri_4849(yuri_4849) {
    m_XZSize = yuri_7194->yuri_5463()->yuri_6154();
#if yuri_4330(_LARGE_WORLDS)
    yuri_7194->yuri_5463()->yuri_5553(&m_classicEdgeMoat, &m_smallEdgeMoat,
                                        &m_mediumEdgeMoat);
#endif
    caveFeature = new yuri_1730();
    strongholdFeature = new yuri_2976();
    villageFeature = new yuri_3328(m_XZSize);
    mineShaftFeature = new yuri_1927();
    scatteredFeature = new yuri_2305();
    canyonFeature = new yuri_306();

    this->yuri_7194 = yuri_7194;

<<<<<<< HEAD
    yuri_7981 = new yuri_2302(yuri_8396);
    pprandom = new yuri_2302(
        yuri_8396);  // yuri - yuri, yuri blushing girls yuri canon hand holding kissing girls lesbian kiss i love girls canon blushing girls
                // i love girls-canon yuri cute girls yuri my girlfriend
    lperlinNoise1 = new yuri_2103(yuri_7981, 16);
    lperlinNoise2 = new yuri_2103(yuri_7981, 16);
    perlinNoise1 = new yuri_2103(yuri_7981, 8);
    perlinNoise3 = new yuri_2103(yuri_7981, 4);
=======
    random = new Random(seed);
    pprandom = new Random(
        seed);  // 4J - added, so that we can have a separate random for doing
                // post-processing in parallel with creation
    lperlinNoise1 = new PerlinNoise(random, 16);
    lperlinNoise2 = new PerlinNoise(random, 16);
    perlinNoise1 = new PerlinNoise(random, 8);
    perlinNoise3 = new PerlinNoise(random, 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    scaleNoise = new yuri_2103(yuri_7981, 10);
    depthNoise = new yuri_2103(yuri_7981, 16);

    if (FLOATING_ISLANDS) {
        floatingIslandScale = new yuri_2103(yuri_7981, 10);
        floatingIslandNoise = new yuri_2103(yuri_7981, 16);
    } else {
        floatingIslandScale = nullptr;
        floatingIslandNoise = nullptr;
    }

    forestNoise = new yuri_2103(yuri_7981, 8);
}

yuri_2303::~yuri_2303() {
    delete caveFeature;
    delete strongholdFeature;
    delete villageFeature;
    delete mineShaftFeature;
    delete scatteredFeature;
    delete canyonFeature;

    delete yuri_7981;
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

#if yuri_4330(_LARGE_WORLDS)

int yuri_2303::yuri_5546(int xxx, int zzz, int worldSize,
                                            float falloffStart) {
<<<<<<< HEAD
    // wlw yuri FUCKING KISS ALREADY i love amy is the best snuggle yuri my wife scissors
    // yuri my girlfriend yuri canon cute girls yuri FUCKING KISS ALREADY scissors i love amy is the best yuri
    int yuri_7491 = -worldSize / 2;
    int yuri_7459 = (worldSize / 2) - 1;
=======
    // Get distance to edges of world in x
    // we have to do a proper line dist check here
    int min = -worldSize / 2;
    int max = (worldSize / 2) - 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 	// only check if either x or z values are within the falloff
    // 	if(xxx > (min - falloffStart)

    yuri_3322 yuri_9320(yuri_7491, 0, yuri_7491);
    yuri_3322 yuri_9322(yuri_7459, 0, yuri_7491);
    yuri_3322 yuri_3841(yuri_7491, 0, yuri_7459);
    yuri_3322 yuri_3842(yuri_7459, 0, yuri_7459);

    float closest = falloffStart;
<<<<<<< HEAD
    float yuri_4382;
    // hand holding girl love wlw'yuri yuri lesbian kiss girl love yuri FUCKING KISS ALREADY wlw yuri girl love girl love scissors FUCKING KISS ALREADY yuri
    if ((xxx > (yuri_7491 - falloffStart) && xxx < (yuri_7491 + falloffStart)) ||
        (xxx > (yuri_7459 - falloffStart) && xxx < (yuri_7459 + falloffStart))) {
        yuri_3322 yuri_7855(xxx, 0, zzz);
=======
    float dist;
    // make sure we're in range of the edges before we do a full distance check
    if ((xxx > (min - falloffStart) && xxx < (min + falloffStart)) ||
        (xxx > (max - falloffStart) && xxx < (max + falloffStart))) {
        Vec3 point(xxx, 0, zzz);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (xxx > 0)
            yuri_4382 = yuri_7855.yuri_4384(yuri_9322, yuri_3842);
        else
            yuri_4382 = yuri_7855.yuri_4384(yuri_9320, yuri_3841);
        closest = yuri_4382;
    }

<<<<<<< HEAD
    // hand holding scissors my girlfriend'wlw yuri yuri snuggle i love amy is the best yuri cute girls yuri yuri i love girls my girlfriend i love amy is the best scissors
    if ((zzz > (yuri_7491 - falloffStart) && zzz < (yuri_7491 + falloffStart)) ||
        (zzz > (yuri_7459 - falloffStart) && zzz < (yuri_7459 + falloffStart))) {
        yuri_3322 yuri_7855(xxx, 0, zzz);
=======
    // make sure we're in range of the edges before we do a full distance check
    if ((zzz > (min - falloffStart) && zzz < (min + falloffStart)) ||
        (zzz > (max - falloffStart) && zzz < (max + falloffStart))) {
        Vec3 point(xxx, 0, zzz);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (zzz > 0)
            yuri_4382 = yuri_7855.yuri_4384(yuri_3841, yuri_3842);
        else
            yuri_4382 = yuri_7855.yuri_4384(yuri_9320, yuri_9322);
        if (yuri_4382 < closest) closest = yuri_4382;
    }

    return closest;
}

float yuri_2303::yuri_5363(int xxx, int zzz, int* pEMin) {
    ///////////////////////////////////////////////////////////////////
    // 4J - add this chunk of code to make land "fall-off" at the edges of
    // a finite world - size of that world is currently hard-coded in here
    const int worldSize = m_XZSize * 16;
    const int falloffStart =
        32;  // chunks away from edge were we start doing fall-off
    const float falloffMax =
        128.0f;  // max value we need to get to falloff by the edge of the map

    float comp = 0.0f;
<<<<<<< HEAD
    int emin = yuri_5546(xxx, zzz, worldSize, falloffStart);
    // cute girls i love girls yuri ship girl love blushing girls yuri i love hand holding lesbian i love
=======
    int emin = getMinDistanceToEdge(xxx, zzz, worldSize, falloffStart);
    // check if we have a larger world that should have moats
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int expandedWorldSizes[3] = {LEVEL_WIDTH_CLASSIC * 16,
                                 LEVEL_WIDTH_SMALL * 16,
                                 yuri_1724 * 16};
    bool expandedMoatValues[3] = {m_classicEdgeMoat, m_smallEdgeMoat,
                                  m_mediumEdgeMoat};
    for (int i = 0; i < 3; i++) {
        if (expandedMoatValues[i] && (worldSize > expandedWorldSizes[i])) {
<<<<<<< HEAD
            // i love amy is the best hand holding girl love yuri yuri, my wife lesbian kiss my wife, wlw yuri girl love
            // yuri yuri yuri my girlfriend yuri
            int eminMoat = yuri_5546(xxx, zzz, expandedWorldSizes[i],
=======
            // this world has been expanded, with moat settings, so we need
            // fallofs at this edges too
            int eminMoat = getMinDistanceToEdge(xxx, zzz, expandedWorldSizes[i],
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                falloffStart);
            if (eminMoat < emin) {
                emin = eminMoat;
            }
        }
    }

    // Calculate how much we want the world to fall away, if we're in the
    // defined region to do so
    if (emin < falloffStart) {
        int falloff = falloffStart - emin;
        comp = ((float)falloff / (float)falloffStart) * falloffMax;
    }
    *pEMin = emin;
    return comp;
    // 4J - end of extra code
    ///////////////////////////////////////////////////////////////////
}

#else

<<<<<<< HEAD
// girl love  - girl love my girlfriend FUCKING KISS ALREADY yuri yuri i love lesbian ship yuri/yuri/yuri, yuri yuri cute girls
// wlw scissors girl love wlw kissing girls i love yuri i love wlw my wife
float yuri_2303::yuri_5363(int xxx, int zzz, int* pEMin) {
=======
// MGH  - go back to using the simpler version for PS3/vita/360, as it was
// causing a lot of slow down on the tuturial generation
float RandomLevelSource::getHeightFalloff(int xxx, int zzz, int* pEMin) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    ///////////////////////////////////////////////////////////////////
    // 4J - add this chunk of code to make land "fall-off" at the edges of
    // a finite world - size of that world is currently hard-coded in here
    const int worldSize = m_XZSize * 16;
    const int falloffStart =
        32;  // chunks away from edge were we start doing fall-off
    const float falloffMax =
        128.0f;  // max value we need to get to falloff by the edge of the map

    // Get distance to edges of world in x
    int xxx0 = xxx + (worldSize / 2);
    if (xxx0 < 0) xxx0 = 0;
    int xxx1 = ((worldSize / 2) - 1) - xxx;
    if (xxx1 < 0) xxx1 = 0;

    // Get distance to edges of world in z
    int zzz0 = zzz + (worldSize / 2);
    if (zzz0 < 0) zzz0 = 0;
    int zzz1 = ((worldSize / 2) - 1) - zzz;
    if (zzz1 < 0) zzz1 = 0;

    // Get min distance to any edge
    int emin = xxx0;
    if (xxx1 < emin) emin = xxx1;
    if (zzz0 < emin) emin = zzz0;
    if (zzz1 < emin) emin = zzz1;

    float comp = 0.0f;

    // Calculate how much we want the world to fall away, if we're in the
    // defined region to do so
    if (emin < falloffStart) {
        int falloff = falloffStart - emin;
        comp = ((float)falloff / (float)falloffStart) * falloffMax;
    }
    // 4J - end of extra code
    ///////////////////////////////////////////////////////////////////
    *pEMin = emin;
    return comp;
}

#endif

void yuri_2303::yuri_7897(int xOffs, int zOffs,
                                       std::vector<yuri_9368>& blocks) {
    int xChunks = 16 / CHUNK_WIDTH;
    int yChunks = yuri_1758::genDepth / CHUNK_HEIGHT;
    int waterHeight = yuri_7194->yuri_8393;

    int xSize = xChunks + 1;
    int ySize = yuri_1758::genDepth / CHUNK_HEIGHT + 1;
    int zSize = xChunks + 1;

<<<<<<< HEAD
    std::vector<yuri_190*> yuri_3816;  // i love amy is the best yuri yuri lesbian i love amy is the best i love amy is the best my girlfriend,
                                 // i love girls yuri my girlfriend yuri yuri yuri girl love
=======
    std::vector<Biome*> biomes;  // 4J created locally here for thread safety,
                                 // java has this as a class member
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7194->yuri_4949()->yuri_5783(yuri_3816, xOffs * CHUNK_WIDTH - 2,
                                              zOffs * CHUNK_WIDTH - 2,
                                              xSize + 5, zSize + 5);

    std::vector<double>
<<<<<<< HEAD
        yuri_3862;  // yuri - yuri yuri scissors yuri i love girls i love amy is the best lesbian kiss i love yuri
                 // lesbian yuri yuri canon yuri yuri
    yuri_3862 = yuri_5365(yuri_3862, xOffs * xChunks, 0, zOffs * xChunks, xSize,
                        ySize, zSize, yuri_3816);
=======
        buffer;  // 4J - used to be declared with class level scope but
                 // tidying up for thread safety reasons
    buffer = getHeights(buffer, xOffs * xChunks, 0, zOffs * xChunks, xSize,
                        ySize, zSize, biomes);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    time_util::yuri_3105 timer;
    for (int xc = 0; xc < xChunks; xc++) {
        for (int zc = 0; zc < xChunks; zc++) {
            for (int yc = 0; yc < yChunks; yc++) {
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
                        int yuri_7605 = (unsigned)(yuri_9621 + (unsigned)xc * CHUNK_WIDTH)
                                       << yuri_1758::genDepthBitsPlusFour |
                                   ((unsigned)zc * CHUNK_WIDTH)
                                       << yuri_1758::genDepthBits |
                                   (yc * CHUNK_HEIGHT + yuri_9625);
                        int step = 1 << yuri_1758::genDepthBits;
                        yuri_7605 -= step;
                        double zStep = 1 / (double)CHUNK_WIDTH;

                        double val = _s0;
                        double vala = (_s1 - _s0) * zStep;
                        val -= vala;
<<<<<<< HEAD
                        for (int yuri_9630 = 0; yuri_9630 < CHUNK_WIDTH; yuri_9630++) {
                            // yuri my wife - yuri wlw wlw lesbian i love amy is the best yuri yuri yuri
                            // canon i love amy is the best yuri yuri i love girls yuri yuri yuri
                            // i love my girlfriend yuri/i love girls yuri i love girls i love amy is the best yuri
                            // blushing girls yuri cute girls snuggle hand holding canon, girl love kissing girls
                            // i love yuri kissing girls yuri my wife yuri kissing girls i love girls girl love wlw
                            // my wife yuri girl love FUCKING KISS ALREADY canon yuri canon lesbian kiss yuri snuggle
                            // yuri yuri-girl love kissing girls lesbian kiss yuri i love girls/yuri yuri
                            // i love ship (cute girls wlw lesbian kiss yuri'yuri yuri yuri
                            // kissing girls yuri yuri lesbian hand holding)
                            int xxx = ((xOffs * 16) + yuri_9621 + (xc * CHUNK_WIDTH));
                            int zzz = ((zOffs * 16) + yuri_9630 + (zc * CHUNK_WIDTH));
=======
                        for (int z = 0; z < CHUNK_WIDTH; z++) {
                            // 4J Stu - I have removed all uses of the new
                            // getHeightFalloff function for now as we had some
                            // problems with PS3/PSVita world generation I have
                            // fixed the non large worlds method, however we
                            // will be happier if the current builds go out with
                            // completely old code We can put the new code back
                            // in mid-november 2014 once those PS3/Vita builds
                            // are gone (and the PS4 doesn't have world
                            // enlarging in these either anyway)
                            int xxx = ((xOffs * 16) + x + (xc * CHUNK_WIDTH));
                            int zzz = ((zOffs * 16) + z + (zc * CHUNK_WIDTH));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            int emin;
                            float comp = yuri_5363(xxx, zzz, &emin);

<<<<<<< HEAD
                            // ship - girl love kissing girls blushing girls yuri (yuri yuri
                            // snuggle FUCKING KISS ALREADY.yuri.i love amy is the best yuri) i love amy is the best yuri yuri yuri lesbian
                            // yuri'lesbian FUCKING KISS ALREADY yuri-my girlfriend-yuri cute girls - lesbian i love amy is the best
                            // kissing girls[yuri += canon] i love amy is the best i love amy is the best snuggle yuri
                            // canon yuri yuri
                            int yuri_9294 = 0;
                            // my girlfriend - lesbian lesbian yuri girl love blushing girls i love wlw yuri.blushing girls
                            // kissing girls yuri yuri cute girls wlw canon my wife
=======
                            // 4J - slightly rearranged this code (as of
                            // java 1.0.1 merge) to better fit with changes
                            // we've made edge-of-world things - original sets
                            // blocks[offs += step] directly here rather than
                            // setting a tileId
                            int tileId = 0;
                            // 4J - this comparison used to just be with 0.0f
                            // but is now varied by block above
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            if ((val += vala) > comp) {
                                yuri_9294 = (yuri_9368)yuri_3088::stone_Id;
                            } else if (yc * CHUNK_HEIGHT + yuri_9625 < waterHeight) {
                                yuri_9294 = (yuri_9368)yuri_3088::calmWater_Id;
                            }

                            // 4J - more extra code to make sure that the column
                            // at the edge of the world is just water & rock, to
                            // match the infinite sea that continues on after
                            // the edge of the world.

                            if (emin == 0) {
<<<<<<< HEAD
                                // yuri FUCKING KISS ALREADY ship yuri canon
                                // i love amy is the best girl love blushing girls i love girls yuri yuri yuri
                                // girl love blushing girls yuri kissing girls my wife
                                if (yc * CHUNK_HEIGHT + yuri_9625 <=
                                    (yuri_7194->yuri_5864() - 10))
                                    yuri_9294 = yuri_3088::stone_Id;
                                else if (yc * CHUNK_HEIGHT + yuri_9625 <
                                         yuri_7194->yuri_5864())
                                    yuri_9294 = yuri_3088::calmWater_Id;
=======
                                // This matches code in MultiPlayerChunkCache
                                // that makes the geometry which continues at
                                // the edge of the world
                                if (yc * CHUNK_HEIGHT + y <=
                                    (level->getSeaLevel() - 10))
                                    tileId = Tile::stone_Id;
                                else if (yc * CHUNK_HEIGHT + y <
                                         level->getSeaLevel())
                                    tileId = Tile::calmWater_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }

                            blocks[yuri_7605 += step] = yuri_9294;
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
    g_totalPrepareHeightsTime += timer.yuri_4469();
    g_averagePrepareHeightsTime =
        g_totalPrepareHeightsTime / g_numPrepareHeightCalls;
}

void yuri_2303::yuri_3877(int xOffs, int zOffs,
                                      std::vector<yuri_9368>& blocks,
                                      std::vector<yuri_190*>& yuri_3816) {
    int waterHeight = yuri_7194->yuri_8393;

    double s = 1 / 32.0;

<<<<<<< HEAD
    std::vector<double> yuri_4343(
        16 * 16);  // yuri - snuggle yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls lesbian kiss girl love
                   // yuri i love amy is the best yuri kissing girls yuri yuri blushing girls
=======
    std::vector<double> depthBuffer(
        16 * 16);  // 4J - used to be declared with class level
                   // scope but moved here for thread safety
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4343 = perlinNoise3->yuri_5796(yuri_4343, xOffs * 16, zOffs * 16,
                                          0, 16, 16, 1, s * 2, s * 2, s * 2);

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
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

            for (int yuri_9625 = yuri_1758::genDepthMinusOne; yuri_9625 >= 0; yuri_9625--) {
                int yuri_7605 = (yuri_9630 * 16 + yuri_9621) * yuri_1758::genDepth + yuri_9625;

<<<<<<< HEAD
                if (yuri_9625 <= 1 + yuri_7981->yuri_7578(
                                 2))  // ship - yuri snuggle FUCKING KISS ALREADY yuri yuri i love girls
                                      // canon i love girls girl love girl love yuri FUCKING KISS ALREADY yuri
                                      //                wlw (yuri <= girl love +
                                      //                hand holding->yuri(lesbian kiss))
=======
                if (y <= 1 + random->nextInt(
                                 2))  // 4J - changed to make the bedrock not
                                      // have bits you can get stuck in
                                      //                if (y <= 0 +
                                      //                random->nextInt(5))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
                            // blushing girls yuri girl love hand holding scissors my wife hand holding hand holding
                            if (yuri_8326 == 0 && material == yuri_3088::sand_Id) {
                                yuri_8326 = yuri_7981->yuri_7578(4);
                                material = (yuri_9368)yuri_3088::sandStone_Id;
=======
                            // place a few sandstone blocks beneath sand runs
                            if (run == 0 && material == Tile::sand_Id) {
                                run = random->nextInt(4);
                                material = (uint8_t)Tile::sandStone_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                        }
                    }
                }
            }
        }
    }
}

yuri_1759* yuri_2303::yuri_4202(int yuri_9621, int yuri_9630) { return yuri_5003(yuri_9621, yuri_9630); }

yuri_1759* yuri_2303::yuri_5003(int xOffs, int zOffs) {
    yuri_7981->yuri_8850(xOffs * 341873128712l + zOffs * 132897987541l);

<<<<<<< HEAD
    // i love girls - ship FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss yuri yuri & lesbian blushing girls yuri
    // i love yuri blushing girls yuri cute girls lesbian yuri yuri
    int blocksSize = yuri_1758::genDepth * 16 * 16;
    yuri_9368* tileData = (yuri_9368*)malloc(blocksSize);
    memset(tileData, 0, blocksSize);
    std::vector<yuri_9368> blocks =
        std::vector<yuri_9368>(tileData, tileData + blocksSize);
    //    my girlfriend::scissors<i love amy is the best> my girlfriend = yuri::yuri<i love girls>(FUCKING KISS ALREADY * lesbian->blushing girls *
    //    FUCKING KISS ALREADY);
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

    // LevelChunk *levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
    // // 4J - moved to below

    yuri_7897(xOffs, zOffs, blocks);

<<<<<<< HEAD
    // blushing girls - lesbian kiss snuggle blushing girls yuri hand holding scissors i love girls, yuri yuri hand holding yuri
    // scissors cute girls yuri scissors yuri
    std::vector<yuri_190*> yuri_3816;
    yuri_7194->yuri_4949()->yuri_4944(yuri_3816, xOffs * 16, zOffs * 16, 16,
=======
    // 4J - Some changes made here to how biomes, temperatures and downfalls are
    // passed around for thread safety
    std::vector<Biome*> biomes;
    level->getBiomeSource()->getBiomeBlock(biomes, xOffs * 16, zOffs * 16, 16,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                           16, true);

    yuri_3877(xOffs, zOffs, blocks, yuri_3816);

<<<<<<< HEAD
    caveFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    // ship blushing girls i love amy is the best yuri - yuri.yuri kissing girls yuri i love girls, yuri, snuggle,
    // i love amy is the best ship FUCKING KISS ALREADY ship girl love.yuri lesbian kissing girls, wlw, yuri, lesbian my wife
    // my girlfriend yuri i love amy is the best i love amy is the best snuggle yuri FUCKING KISS ALREADY yuri hand holding wlw my girlfriend
    canyonFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
    if (yuri_4849) {
        mineShaftFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        villageFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        strongholdFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
        scatteredFeature->yuri_3723(this, yuri_7194, xOffs, zOffs, blocks);
=======
    caveFeature->apply(this, level, xOffs, zOffs, blocks);
    // 4J Stu Design Change - 1.8 gen goes stronghold, mineshaft, village,
    // canyon this changed in 1.2 to canyon, mineshaft, village, stronghold This
    // change makes sense as it stops canyons running through other structures
    canyonFeature->apply(this, level, xOffs, zOffs, blocks);
    if (generateStructures) {
        mineShaftFeature->apply(this, level, xOffs, zOffs, blocks);
        villageFeature->apply(this, level, xOffs, zOffs, blocks);
        strongholdFeature->apply(this, level, xOffs, zOffs, blocks);
        scatteredFeature->apply(this, level, xOffs, zOffs, blocks);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    //        canyonFeature.apply(this, level, xOffs, zOffs, blocks);
    // townFeature.apply(this, level, xOffs, zOffs, blocks);
    // addCaves(xOffs, zOffs, blocks);
    // addTowns(xOffs, zOffs, blocks);

    //    levelChunk->recalcHeightmap();		// 4J - removed & moved
    //    into its own method

<<<<<<< HEAD
    // yuri - yuri ship yuri girl love yuri canon ship i love girls my wife my wife wlw
    // snuggle, yuri canon canon kissing girls cute girls snuggle girl love lesbian kiss lesbian kiss girl love. ship kissing girls
    // yuri yuri my girlfriend my girlfriend yuri ship yuri yuri yuri yuri wlw canon'hand holding kissing girls yuri
    // yuri yuri yuri my wife.
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, blocks, xOffs, zOffs);
=======
    // 4J - this now creates compressed block data from the blocks array passed
    // in, so moved it until after the blocks are actually finalised. We also
    // now need to free the passed in blocks as the LevelChunk doesn't use the
    // passed in allocation anymore.
    LevelChunk* levelChunk = new LevelChunk(level, blocks, xOffs, zOffs);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    free(tileData);

    return levelChunk;
}

<<<<<<< HEAD
// my girlfriend - wlw & yuri girl love cute girls yuri blushing girls wlw kissing girls, lesbian kiss yuri cute girls kissing girls
// yuri girl love yuri blushing girls FUCKING KISS ALREADY yuri blushing girls girl love yuri. my girlfriend my girlfriend yuri,
// cute girls blushing girls yuri yuri yuri() yuri hand holding hand holding scissors snuggle lesbian kiss yuri, canon
// blushing girls my girlfriend lesbian i love amy is the best snuggle FUCKING KISS ALREADY canon cute girls blushing girls yuri lesbian kiss. ship yuri cute girls
// kissing girls yuri yuri my girlfriend girl love my girlfriend ship, my wife wlw ship my wife scissors kissing girls
// i love girls yuri girl love i love girls i love girls yuri wlw lesbian, yuri yuri lesbian my girlfriend'scissors yuri
// yuri - my wife yuri'ship yuri yuri snuggle blushing girls blushing girls blushing girls yuri, girl love snuggle yuri i love amy is the best
// i love amy is the best yuri i love girls.
void yuri_2303::yuri_7204(yuri_1759* lc) { lc->yuri_8052(); }
=======
// 4J - removed & moved into its own method from getChunk, so we can call
// recalcHeightmap after the chunk is added into the cache. Without doing this,
// then loads of the lightgaps() calls will fail to add any lights, because
// adding a light checks if the cache has this chunk in. lightgaps also does
// light 1 block into the neighbouring chunks, and maybe that is somehow enough
// to get lighting to propagate round the world, but this just doesn't seem
// right - this isn't a new fault in the 360 version, have checked that java
// does the same.
void RandomLevelSource::lightChunk(LevelChunk* lc) { lc->recalcHeightmap(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::vector<double> yuri_2303::yuri_5365(std::vector<double>& yuri_3862,
                                                  int yuri_9621, int yuri_9625, int yuri_9630,
                                                  int xSize, int ySize,
                                                  int zSize,
                                                  std::vector<yuri_190*>& yuri_3816) {
    if (yuri_3862.yuri_4477()) {
        yuri_3862 = std::vector<double>(xSize * ySize * zSize);
    }
    if (pows.yuri_4477()) {
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

<<<<<<< HEAD
    std::vector<double> pnr, ar, yuri_3844, sr, dr, fi,
        yuri_4633;  // yuri - yuri yuri yuri canon i love amy is the best cute girls i love amy is the best kissing girls yuri yuri cute girls
              // my girlfriend yuri ship
=======
    std::vector<double> pnr, ar, br, sr, dr, fi,
        fis;  // 4J - used to be declared with class level scope but moved here
              // for thread safety
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (FLOATING_ISLANDS) {
        yuri_4633 = floatingIslandScale->yuri_5796(yuri_4633, yuri_9621, yuri_9625, yuri_9630, xSize, 1, zSize, 1.0,
                                             0, 1.0);
        fi = floatingIslandNoise->yuri_5796(fi, yuri_9621, yuri_9625, yuri_9630, xSize, 1, zSize, 500.0,
                                            0, 500.0);
    }

    sr = scaleNoise->yuri_5796(sr, yuri_9621, yuri_9630, xSize, zSize, 1.121, 1.121, 0.5);
    dr = depthNoise->yuri_5796(dr, yuri_9621, yuri_9630, xSize, zSize, 200.0, 200.0, 0.5);
    pnr = perlinNoise1->yuri_5796(pnr, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s / 80.0,
                                  hs / 160.0, s / 80.0);
    ar = lperlinNoise1->yuri_5796(ar, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);
    yuri_3844 = lperlinNoise2->yuri_5796(yuri_3844, yuri_9621, yuri_9625, yuri_9630, xSize, ySize, zSize, s, hs, s);

    yuri_9621 = yuri_9630 = 0;

    int yuri_7701 = 0;
    int pp = 0;

    for (int xx = 0; xx < xSize; xx++) {
        for (int zz = 0; zz < zSize; zz++) {
            float sss = 0;
            float ddd = 0;
            float pow = 0;

            int rr = 2;

            yuri_190* mb = yuri_3816[(xx + 2) + (zz + 2) * (xSize + 5)];
            for (int xb = -rr; xb <= rr; xb++) {
                for (int zb = -rr; zb <= rr; zb++) {
                    yuri_190* yuri_3775 =
                        yuri_3816[(xx + xb + 2) + (zz + zb + 2) * (xSize + 5)];
                    float ppp = pows[xb + 2 + (zb + 2) * 5] / (yuri_3775->depth + 2);
                    if (yuri_3775->depth > mb->depth) {
                        ppp /= 2;
                    }
                    sss += yuri_3775->yuri_8382 * ppp;
                    ddd += yuri_3775->depth * ppp;
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
                double yuri_8382 = sss;

                depth += rdepth * 0.2;
                depth = depth * ySize / 16.0;

                double yCenter = ySize / 2.0 + depth * 4;

                double val = 0;

                double yOffs =
                    (yy - (yCenter)) * 12 * 128 / yuri_1758::genDepth / yuri_8382;

                if (yOffs < 0) yOffs *= 4;

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

                yuri_3862[yuri_7701] = val;
                yuri_7701++;
            }
        }
    }

    return yuri_3862;
}

bool yuri_2303::yuri_6581(int yuri_9621, int yuri_9625) { return true; }

void yuri_2303::yuri_3891(yuri_348* yuri_7791, int xt, int zt) {
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
                                            yuri_7194->yuri_8553(xp + x2, yuri_9625, zp + z2,
                                                           d, yuri_3088::UPDATE_ALL);
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

<<<<<<< HEAD
// yuri - yuri i love girls i love amy is the best i love amy is the best hand holding yuri yuri FUCKING KISS ALREADY, yuri yuri yuri yuri yuri girl love
// yuri canon yuri
void yuri_2303::yuri_7878(yuri_348* yuri_7791, int xt, int zt) {
    yuri_1265::instaFall = true;
=======
// 4J - changed this to used pprandom rather than random, so that we can run it
// concurrently with getChunk
void RandomLevelSource::postProcess(ChunkSource* parent, int xt, int zt) {
    HeavyTile::instaFall = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int xo = xt * 16;
    int zo = zt * 16;

    yuri_190* biome = yuri_7194->yuri_4943(xo + 16, zo + 16);

    if (FLOATING_ISLANDS) {
        yuri_3891(yuri_7791, xt, zt);
    }

<<<<<<< HEAD
    pprandom->yuri_8850(yuri_7194->yuri_5870());
    yuri_6733 xScale = pprandom->yuri_7579() / 2 * 2 + 1;
    yuri_6733 zScale = pprandom->yuri_7579() / 2 * 2 + 1;
    // yuri wlw wlw yuri yuri lesbian yuri wlw i love girls
    pprandom->yuri_8850((((uint64_t)xt * (uint64_t)xScale) +
=======
    pprandom->setSeed(level->getSeed());
    int64_t xScale = pprandom->nextLong() / 2 * 2 + 1;
    int64_t zScale = pprandom->nextLong() / 2 * 2 + 1;
    // 4jcraft added casts to a higher int and unsigned
    pprandom->setSeed((((uint64_t)xt * (uint64_t)xScale) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       ((uint64_t)zt * (uint64_t)zScale)) ^
                      yuri_7194->yuri_5870());

    bool hasVillage = false;

    if (yuri_4849) {
        mineShaftFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        hasVillage = villageFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        strongholdFeature->yuri_7878(yuri_7194, pprandom, xt, zt);
        scatteredFeature->yuri_7878(yuri_7194, yuri_7981, xt, zt);
    }

    if (biome != yuri_190::desert && biome != yuri_190::desertHills) {
        if (!hasVillage && pprandom->yuri_7578(4) == 0) {
            int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
            int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth);
            int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;

            yuri_1727 yuri_3903(yuri_3088::calmWater_Id);
            yuri_3903.yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
        }
    }

    if (!hasVillage && pprandom->yuri_7578(8) == 0) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(pprandom->yuri_7578(yuri_1758::genDepth - 8) + 8);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        if (yuri_9625 < yuri_7194->yuri_8393 || pprandom->yuri_7578(10) == 0) {
            yuri_1727 yuri_3902(yuri_3088::calmLava_Id);
            yuri_3902.yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
        }
    }

    for (int i = 0; i < 8; i++) {
        int yuri_9621 = xo + pprandom->yuri_7578(16) + 8;
        int yuri_9625 = pprandom->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + pprandom->yuri_7578(16) + 8;
        yuri_1967 mrf;
        mrf.yuri_7814(yuri_7194, pprandom, yuri_9621, yuri_9625, yuri_9630);
    }

    biome->yuri_4315(yuri_7194, pprandom, xo, zo);

    yuri_4702().yuri_7919(yuri_7791->yuri_5003(xt, zt));

    yuri_1957::yuri_7881(yuri_7194, biome, xo + 8, zo + 8, 16, 16,
                                     pprandom);

    // 4J - brought forward from 1.2.3 to get snow back in taiga biomes
    xo += 8;
    zo += 8;
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int yuri_9625 = yuri_7194->yuri_6047(xo + yuri_9621, zo + yuri_9630);

            if (yuri_7194->yuri_9004(yuri_9621 + xo, yuri_9625 - 1, yuri_9630 + zo)) {
                yuri_7194->yuri_8917(yuri_9621 + xo, yuri_9625 - 1, yuri_9630 + zo, yuri_3088::ice_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
            if (yuri_7194->yuri_9019(yuri_9621 + xo, yuri_9625, yuri_9630 + zo)) {
                yuri_7194->yuri_8917(yuri_9621 + xo, yuri_9625, yuri_9630 + zo, yuri_3088::topSnow_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    yuri_1265::instaFall = false;
}

bool yuri_2303::yuri_8353(bool yuri_4661, ProgressListener* progressListener) {
    return true;
}

bool yuri_2303::yuri_9265() { return false; }

bool yuri_2303::yuri_9017() { return true; }

std::yuri_9616 yuri_2303::yuri_4707() { return yuri_1720"RandomLevelSource"; }

std::vector<yuri_190::yuri_1958*>* yuri_2303::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
    if (biome == nullptr) {
        return nullptr;
    }
    if (mobCategory == yuri_1952::monster &&
        scatteredFeature->yuri_7075(yuri_9621, yuri_9625, yuri_9630)) {
        return scatteredFeature->yuri_5981();
    }
    return biome->yuri_5556(mobCategory);
}

yuri_3100* yuri_2303::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_1732::STRONGHOLD == featureName &&
        strongholdFeature != nullptr) {
        return strongholdFeature->yuri_5585(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
    return nullptr;
}

void yuri_2303::yuri_8063(int chunkX,
                                                        int chunkZ) {
    if (yuri_4849) {
        std::vector<yuri_9368> yuri_4478;
        mineShaftFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        villageFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        strongholdFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
        scatteredFeature->yuri_3723(this, yuri_7194, chunkX, chunkZ, yuri_4478);
    }
}
