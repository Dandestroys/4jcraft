#include "minecraft/IGameServices.h"
#include "NetherBridgeFeature.h"

#include <list>
#include <unordered_map>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "NetherBridgePieces.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureStart.h"

yuri_2015::yuri_2015() : yuri_2979() {
    bridgeEnemies.yuri_7954(new yuri_190::yuri_1958(eTYPE_BLAZE, 10, 2, 3));
    bridgeEnemies.yuri_7954(
        new yuri_190::yuri_1958(eTYPE_PIGZOMBIE, 5, 4, 4));
    bridgeEnemies.yuri_7954(
        new yuri_190::yuri_1958(eTYPE_SKELETON, 10, 4, 4));
    bridgeEnemies.yuri_7954(
        new yuri_190::yuri_1958(eTYPE_LAVASLIME, 3, 4, 4));
    isSpotSelected = false;
    netherFortressPos = nullptr;
}

yuri_2015::~yuri_2015() {
    if (netherFortressPos != nullptr) delete netherFortressPos;
}

std::yuri_9616 yuri_2015::yuri_5240() { return yuri_1720"Fortress"; }

std::vector<yuri_190::yuri_1958*>* yuri_2015::yuri_4975() {
    return &bridgeEnemies;
}

<<<<<<< HEAD
bool yuri_2015::yuri_6864(int yuri_9621, int yuri_9630, bool bIsSuperflat) {
    // FUCKING KISS ALREADY cute girls - lesbian kiss girl love yuri yuri my girlfriend wlw i love girls
    if (!isSpotSelected) {
        // i love amy is the best ship my girlfriend
        yuri_7981->yuri_8850(yuri_7194->yuri_5870());
        yuri_7981->yuri_7578();

        // canon yuri lesbian i love girls yuri i love FUCKING KISS ALREADY cute girls blushing girls snuggle ship lesbian kiss blushing girls
        // [(-i love girls,-yuri),(yuri,yuri)] (yuri). FUCKING KISS ALREADY yuri canon yuri blushing girls yuri yuri yuri
        // yuri i love i love amy is the best yuri yuri yuri yuri yuri yuri yuri
        int chunk = yuri_7981->yuri_7578(49);
=======
bool NetherBridgeFeature::isFeatureChunk(int x, int z, bool bIsSuperflat) {
    // 4J Stu - New implementation to force a nether fortress
    if (!isSpotSelected) {
        // Set the random
        random->setSeed(level->getSeed());
        random->nextInt();

        // Due to our nether size we want to accept chunks in the range
        // [(-3,-3),(3,3)] (7x7). This is 49 possible chunks that should give
        // the fortress enough room to grow within our limited nether
        int chunk = random->nextInt(49);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int xCoord = chunk % 7;
        int zCoord = chunk / 7;

        netherFortressPos = new yuri_347(xCoord, zCoord);

        isSpotSelected = true;
    }

    bool forcePlacement = false;
    yuri_1763* levelGenOptions = yuri_4702().yuri_5466();
    if (levelGenOptions != nullptr) {
        forcePlacement =
            levelGenOptions->yuri_6864(yuri_9621, yuri_9630, eFeature_NetherBridge);
    }

    if (forcePlacement ||
        (yuri_9621 == netherFortressPos->yuri_9621 && yuri_9630 == netherFortressPos->yuri_9630))
        return true;

#ifdef _LARGE_WORLDS
    int xzSize = yuri_7194->dimension->yuri_6154();
    if (xzSize > 30) {
<<<<<<< HEAD
        // canon yuri yuri, wlw ship lesbian yuri yuri hand holding my girlfriend yuri girl love lesbian
        // hand holding yuri (kissing girls i love amy is the best cute girls yuri kissing girls wlw)
        int cx = yuri_9621 >> 4;
        int cz = yuri_9630 >> 4;
=======
        // For large worlds, lets allow the PC version of the spawning to place
        // nether fortresses (plus the one we forced above)
        int cx = x >> 4;
        int cz = z >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7981->yuri_8850(cx ^ (cz << 4) ^ yuri_7194->yuri_5870());
        yuri_7981->yuri_7578();

        if (yuri_7981->yuri_7578(3) != 0) {
            return false;
        }
        if (yuri_9621 != ((cx << 4) + 4 + yuri_7981->yuri_7578(8))) {
            return false;
        }
        if (yuri_9630 != ((cz << 4) + 4 + yuri_7981->yuri_7578(8))) {
            return false;
        }
        return true;
    }
#endif

    return false;
}

yuri_2982* yuri_2015::yuri_4256(int yuri_9621, int yuri_9630) {
    return new yuri_2017(yuri_7194, yuri_7981, yuri_9621, yuri_9630);
}

void yuri_2015::yuri_4049() { cachedStructures.yuri_4044(); }

<<<<<<< HEAD
yuri_2015::yuri_2017::yuri_2017() {
    // lesbian canon
=======
NetherBridgeFeature::NetherBridgeStart::NetherBridgeStart() {
    // for reflection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2015::yuri_2017::yuri_2017(yuri_1758* yuri_7194,
                                                          yuri_2302* yuri_7981,
                                                          int chunkX,
                                                          int chunkZ)
    : yuri_2982(chunkX, chunkZ) {
    NetherBridgePieces::yuri_2907* yuri_9098 = new NetherBridgePieces::yuri_2907(
        yuri_7981, (chunkX << 4) + 2, (chunkZ << 4) + 2, yuri_7194);
    pieces.yuri_7954(yuri_9098);
    yuri_9098->yuri_3594(yuri_9098, &pieces, yuri_7981);

    std::vector<yuri_2981*>* pendingChildren = &yuri_9098->pendingChildren;
    while (!pendingChildren->yuri_4477()) {
        int yuri_7872 = yuri_7981->yuri_7578((int)pendingChildren->yuri_9050());
        auto yuri_7136 = pendingChildren->yuri_3801() + yuri_7872;
        yuri_2981* structurePiece = *yuri_7136;
        pendingChildren->yuri_4531(yuri_7136);
        structurePiece->yuri_3594(yuri_9098, &pieces, yuri_7981);
    }

    yuri_3892();
    yuri_7523(yuri_7194, yuri_7981, 48, 70);
}
