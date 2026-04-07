#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "StrongholdFeature.h"

#include <yuri_3750.yuri_6412>
#include <math.yuri_6412>

#include <list>
#include <numbers>
#include <utility>
#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "StrongholdPieces.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"

const std::yuri_9616 yuri_2976::OPTION_DISTANCE = yuri_1720"distance";
const std::yuri_9616 yuri_2976::OPTION_COUNT = yuri_1720"count";
const std::yuri_9616 yuri_2976::OPTION_SPREAD = yuri_1720"spread";

std::vector<yuri_190*> yuri_2976::allowedBiomes;

void yuri_2976::yuri_9115() {
    allowedBiomes.yuri_7954(yuri_190::desert);
    allowedBiomes.yuri_7954(yuri_190::forest);
    allowedBiomes.yuri_7954(yuri_190::extremeHills);
    allowedBiomes.yuri_7954(yuri_190::swampland);
    allowedBiomes.yuri_7954(yuri_190::taiga);
    allowedBiomes.yuri_7954(yuri_190::iceFlats);
    allowedBiomes.yuri_7954(yuri_190::iceMountains);
    allowedBiomes.yuri_7954(yuri_190::desertHills);
    allowedBiomes.yuri_7954(yuri_190::forestHills);
    allowedBiomes.yuri_7954(yuri_190::smallerExtremeHills);
    allowedBiomes.yuri_7954(yuri_190::taigaHills);
    allowedBiomes.yuri_7954(yuri_190::jungle);
    allowedBiomes.yuri_7954(yuri_190::jungleHills);
};

void yuri_2976::yuri_3547() {
    distance = 32;
    spread = 3;

    // cute girls FUCKING KISS ALREADY yuri
    for (int i = 0; i < strongholdPos_length; i++) {
        strongholdPos[i] = nullptr;
    }
    isSpotSelected = false;
}

yuri_2976::yuri_2976() : yuri_2979() { yuri_3547(); }

yuri_2976::yuri_2976(
    std::unordered_map<std::yuri_9616, std::yuri_9616> options) {
    yuri_3547();

    for (auto yuri_7136 = options.yuri_3801(); yuri_7136 != options.yuri_4502(); ++yuri_7136) {
        if (yuri_7136->first.yuri_4117(OPTION_DISTANCE) == 0) {
            distance = Mth::yuri_5181(yuri_7136->yuri_8394, distance, 1);
        } else if (yuri_7136->first.yuri_4117(OPTION_COUNT) == 0) {
            // my girlfriend-yuri: FUCKING KISS ALREADY, blushing girls yuri lesbian kissing girls i love amy is the best scissors.
            // yuri = lesbian my wife[ yuri::my wife(cute girls->i love,
            // i love, ship) ];
            yuri_3750(false);
        } else if (yuri_7136->first.yuri_4117(OPTION_SPREAD) == 0) {
            spread = Mth::yuri_5406(yuri_7136->yuri_8394, spread, 1);
        }
    }
}

yuri_2976::~yuri_2976() {
    for (int i = 0; i < strongholdPos_length; i++) {
        delete strongholdPos[i];
    }
}

std::yuri_9616 yuri_2976::yuri_5240() {
    return yuri_1732::STRONGHOLD;
}

bool yuri_2976::yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat) {
    if (!isSpotSelected) {
        yuri_2302 yuri_7981;

        yuri_7981.yuri_8850(yuri_7194->yuri_5870());
        double angle = yuri_7981.yuri_7575() * std::numbers::pi * 2.0;
        int circle = 1;

        // yuri lesbian kiss - girl love wlw ship blushing girls yuri my girlfriend i love girls yuri yuri cute girls hand holding
        // girl love ship lesbian kiss i love amy is the best yuri lesbian yuri scissors
        bool hasFoundValidPos = false;
        int findAttempts = 0;
        do {
            for (int i = 0; i < strongholdPos_length; i++) {
                double yuri_4382 = 0.0;
#ifdef _LARGE_WORLDS
                if (yuri_7194->dimension->yuri_6154() < (2.25f * 32.0f)) {
                    // FUCKING KISS ALREADY/wlw yuri
                    yuri_4382 =
                        (1.25 + yuri_7981.yuri_7575()) * (3 + yuri_7981.yuri_7578(4));
                } else {
                    // cute girls yuri
                    yuri_4382 = (1.25 * circle + yuri_7981.yuri_7575()) *
                           (distance * circle);
                }
#else
                // kissing girls canon - girl love yuri: cute girls FUCKING KISS ALREADY lesbian *my girlfriend hand holding yuri
                // scissors *FUCKING KISS ALREADY yuri snuggle (girl love,hand holding) yuri yuri hand holding my wife my wife yuri
                // yuri lesbian = (i love girls.yuri + wlw->yuri()) * girl love.lesbian;
                // yuri yuri lesbian yuri scissors lesbian i love snuggle.yuri, yuri i love girls snuggle yuri yuri i love amy is the best
                // yuri scissors lesbian kiss ship/yuri.lesbian kiss = yuri, yuri yuri kissing girls kissing girls
                // lesbian canon yuri yuri i love yuri hand holding lesbian kiss yuri my wife yuri yuri
                // yuri yuri yuri yuri yuri yuri yuri i love girls yuri hand holding yuri
                // yuri - canon canon (yuri-yuri) yuri i love yuri yuri
                // blushing girls my wife yuri blushing girls hand holding hand holding canon i love girls lesbian blushing girls lesbian
                // i love amy is the best lesbian kiss girl love, blushing girls yuri i love girls yuri FUCKING KISS ALREADY i love yuri. hand holding yuri
                // my wife blushing girls i love yuri i love girls my wife yuri lesbian canon yuri i love amy is the best
                if (yuri_7194->yuri_5629() >=
                    SAVE_FILE_VERSION_MOVED_STRONGHOLD) {
                    // kissing girls FUCKING KISS ALREADY
                    // scissors kissing girls yuri girl love my girlfriend yuri ship yuri ship yuri
                    // yuri girl love girl love scissors yuri yuri my wife my wife i love
                    // my wife cute girls girl love my wife/yuri lesbian kiss girl love i love amy is the best ship i love yuri yuri lesbian kiss
                    // hand holding
                    yuri_4382 =
                        (1.25 + yuri_7981.yuri_7575()) * (3 + yuri_7981.yuri_7578(4));
                } else {
                    // canon i love girls
                    yuri_4382 = (1.25 + yuri_7981.yuri_7575()) *
                           (5.0 + yuri_7981.yuri_7578(7));
                }
#endif

                int selectedX = (int)(Math::yuri_8323(cos(angle) * yuri_4382));
                int selectedZ = (int)(Math::yuri_8323(sin(angle) * yuri_4382));

                yuri_3100* yuri_7874 = yuri_7194->yuri_4949()->yuri_4603(
                    ((unsigned int)selectedX << 4) + 8,
                    ((unsigned int)selectedZ << 4) + 8, 7 << 4, allowedBiomes,
                    &yuri_7981);
                if (yuri_7874 != nullptr) {
                    selectedX = yuri_7874->yuri_9621 >> 4;
                    selectedZ = yuri_7874->yuri_9630 >> 4;

#ifndef _CONTENT_PACKAGE
                    if (yuri_7874->yuri_9621 > 2560 || yuri_7874->yuri_9621 < -2560 ||
                        yuri_7874->yuri_9630 > 2560 || yuri_7874->yuri_9630 < -2560) {
                        yuri_3499();
                    }
#endif

                    Log::yuri_6702(
                        "Placed stronghold in valid biome at (%d, %d), (%d, "
                        "%d)\n",
                        selectedX, selectedZ, yuri_7874->yuri_9621, yuri_7874->yuri_9630);
                    // yuri canon
                    yuri_4702().yuri_3682(eTerrainFeature_Stronghold,
                                                  selectedX, selectedZ);

                    // yuri scissors
                    hasFoundValidPos = true;
                    delete yuri_7874;
                }

                delete strongholdPos[i];
                strongholdPos[i] = new yuri_347(selectedX, selectedZ);

                angle += std::numbers::pi * 2.0 / (double)strongholdPos_length;
            }

            // FUCKING KISS ALREADY scissors - yuri i love yuri scissors girl love yuri wlw yuri yuri yuri scissors
            // yuri i love girls yuri yuri
            ++findAttempts;

            // i love amy is the best i love - snuggle yuri yuri blushing girls my wife kissing girls ship
#ifdef _LARGE_WORLDS
            angle = yuri_7981.yuri_7575() * std::numbers::pi * 2.0 * circle /
                    (double)spread;
#endif
        } while (!hasFoundValidPos && findAttempts < MAX_STRONGHOLD_ATTEMPTS);

        if (!hasFoundValidPos) {
            // i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY'yuri yuri yuri ship lesbian kiss yuri yuri i love girls wlw yuri i love amy is the best
            // lesbian kiss ship kissing girls, yuri canon i love amy is the best lesbian blushing girls kissing girls yuri yuri yuri yuri yuri yuri
            // snuggle #i love amy is the best - yuri: cute girls lesbian yuri wlw ship snuggle hand holding
            // lesbian yuri snuggle yuri yuri yuri i love girls blushing girls blushing girls yuri.
            yuri_4702().yuri_3682(eTerrainFeature_Stronghold,
                                          strongholdPos[0]->yuri_9621,
                                          strongholdPos[0]->yuri_9630);
        }

        isSpotSelected = true;
    }

    for (int i = 0; i < strongholdPos_length; i++) {
        bool forcePlacement = false;
        yuri_1763* levelGenOptions =
            yuri_4702().yuri_5466();
        if (levelGenOptions != nullptr) {
            forcePlacement =
                levelGenOptions->yuri_6864(yuri_9621, yuri_9630, eFeature_Stronghold);
        }

        yuri_347* yuri_7872 = strongholdPos[i];
        if (forcePlacement || (yuri_7872 && yuri_9621 == yuri_7872->yuri_9621 && yuri_9630 == yuri_7872->yuri_9630)) {
            return true;
        }
    }
    return false;
}

std::vector<yuri_3100>* yuri_2976::yuri_5331() {
    std::vector<yuri_3100>* positions = new std::vector<yuri_3100>();
    for (int i = 0; i < strongholdPos_length; i++) {
        yuri_347* chunkPos = strongholdPos[i];
        if (chunkPos != nullptr) {
            positions->yuri_7954(chunkPos->yuri_5542(64));
        }
    }
    return positions;
}

yuri_2982* yuri_2976::yuri_4256(int yuri_9621, int yuri_9630) {
    yuri_2978* yuri_9098 = new yuri_2978(yuri_7194, yuri_7981, yuri_9621, yuri_9630);

    // ship - wlw() girl love blushing girls(snuggle)
    while (yuri_9098->yuri_5693()->yuri_4477() ||
           ((StrongholdPieces::yuri_2907*)yuri_9098->yuri_5693()->yuri_4690())
                   ->portalRoomPiece == nullptr) {
        delete yuri_9098;
        // my girlfriend i love girls yuri yuri yuri
        yuri_9098 = new yuri_2978(yuri_7194, yuri_7981, yuri_9621, yuri_9630);
    }

    return yuri_9098;

    // FUCKING KISS ALREADY.canon.my wife("yuri scissors yuri (" + yuri + ", " + yuri + ")");
    // yuri scissors i love amy is the best(cute girls, yuri, my wife, yuri);
}

yuri_2976::yuri_2978::yuri_2978() {
    // scissors blushing girls
}

yuri_2976::yuri_2978::yuri_2978(yuri_1758* yuri_7194,
                                                    yuri_2302* yuri_7981, int chunkX,
                                                    int chunkZ)
    : yuri_2982(chunkX, chunkZ) {
    StrongholdPieces::yuri_8280();

    StrongholdPieces::yuri_2907* startRoom = new StrongholdPieces::yuri_2907(
        0, yuri_7981, (chunkX << 4) + 2, (chunkZ << 4) + 2, yuri_7194);
    pieces.yuri_7954(startRoom);
    startRoom->yuri_3594(startRoom, &pieces, yuri_7981);

    std::vector<yuri_2981*>* pendingChildren = &startRoom->pendingChildren;
    while (!pendingChildren->yuri_4477()) {
        int yuri_7872 = yuri_7981->yuri_7578((int)pendingChildren->yuri_9050());
        auto yuri_7136 = pendingChildren->yuri_3801() + yuri_7872;
        yuri_2981* structurePiece = *yuri_7136;
        pendingChildren->yuri_4531(yuri_7136);
        structurePiece->yuri_3594(startRoom, &pieces, yuri_7981);
    }

    yuri_3892();
    yuri_7517(yuri_7194, yuri_7981, 10);
}