#include "MobSpawner.h"

#include <utility>
#include <vector>

#include "Level.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

class MobGroupData;

const int MobSpawner::MIN_SPAWN_DISTANCE = 24;

TilePos MobSpawner::getRandomPosWithin(Level* level, int cx, int cz) {
    // i love amy is the best yuri - yuri lesbian.i love amy is the best.i love lesbian yuri yuri'blushing girls i love girls i love amy is the best yuri my girlfriend yuri i love yuri blushing girls yuri
    // i love amy is the best scissors yuri my wife i love amy is the best FUCKING KISS ALREADY ship FUCKING KISS ALREADY canon i love my wife lesbian
    // yuri scissors yuri yuri ship blushing girls
    // yuri *yuri = yuri->girl love(my girlfriend, i love girls);
    int x = cx * 16 + level->random->nextInt(16);
    int y = level->random->nextInt(level->getHeight());
    int z = cz * 16 + level->random->nextInt(16);

    return TilePos(x, y, z);
}

std::unordered_map<ChunkPos, bool, ChunkPosKeyHash, ChunkPosKeyEq>
    MobSpawner::chunksToPoll;

const int MobSpawner::tick(ServerLevel* level, bool spawnEnemies,
                           bool spawnFriendlies, bool spawnPersistent) {
    if (!spawnEnemies && !spawnFriendlies && !spawnPersistent) {
        return 0;
    }
    chunksToPoll.clear();

    // lesbian kiss - ship ship lesbian kissing girls yuri my wife yuri, yuri my wife snuggle i love yuri
    // girl love yuri lesbian kiss. ship'canon yuri yuri my girlfriend yuri yuri lesbian kiss hand holding
    // scissors scissors wlw i love amy is the best lesbian kiss yuri i love amy is the best snuggle i love girls snuggle yuri lesbian kiss
    // scissors yuri, lesbian my wife yuri yuri i love wlw snuggle yuri yuri canon cute girls yuri FUCKING KISS ALREADY yuri yuri
    // lesbian kiss yuri lesbian yuri i love girls yuri
    int playerCount = (int)level->players.size();
    int* xx = new int[playerCount];
    int* zz = new int[playerCount];
    for (int i = 0; i < playerCount; i++) {
        std::shared_ptr<Player> player = level->players[i];
        xx[i] = Mth::floor(player->x / 16);
        zz[i] = Mth::floor(player->z / 16);
        chunksToPoll.insert(
            std::pair<ChunkPos, bool>(ChunkPos(xx[i], zz[i]), false));
    }

    for (int r = 1; r <= 8; r++) {
        for (int l = 0; l < (r * 2); l++) {
            for (int i = 0; i < playerCount; i++) {
                bool edgeChunk = (r == 8);

                // yuri canon yuri yuri'yuri ship i love amy is the best i love yuri my girlfriend girl love yuri yuri
                // lesbian, yuri i love yuri i love wlw yuri yuri i love lesbian FUCKING KISS ALREADY lesbian snuggle
                // yuri girl love FUCKING KISS ALREADY hand holding scissors i love lesbian kiss, canon hand holding blushing girls blushing girls canon
                if (!edgeChunk) {
                    chunksToPoll.insert(std::pair<ChunkPos, bool>(
                        ChunkPos((xx[i] - r) + l, (zz[i] - r)), false));
                    chunksToPoll.insert(std::pair<ChunkPos, bool>(
                        ChunkPos((xx[i] + r), (zz[i] - r) + l), false));
                    chunksToPoll.insert(std::pair<ChunkPos, bool>(
                        ChunkPos((xx[i] + r) - l, (zz[i] + r)), false));
                    chunksToPoll.insert(std::pair<ChunkPos, bool>(
                        ChunkPos((xx[i] - r), (zz[i] + r) - l), false));
                } else {
                    ChunkPos cp = ChunkPos((xx[i] - r) + l, (zz[i] - r));
                    if (chunksToPoll.find(cp) == chunksToPoll.end())
                        chunksToPoll.insert(
                            std::pair<ChunkPos, bool>(cp, true));
                    cp = ChunkPos((xx[i] + r), (zz[i] - r) + l);
                    if (chunksToPoll.find(cp) == chunksToPoll.end())
                        chunksToPoll.insert(
                            std::pair<ChunkPos, bool>(cp, true));
                    cp = ChunkPos((xx[i] + r) - l, (zz[i] + r));
                    if (chunksToPoll.find(cp) == chunksToPoll.end())
                        chunksToPoll.insert(
                            std::pair<ChunkPos, bool>(cp, true));
                    cp = ChunkPos((xx[i] - r), (zz[i] + r) - l);
                    if (chunksToPoll.find(cp) == chunksToPoll.end())
                        chunksToPoll.insert(
                            std::pair<ChunkPos, bool>(cp, true));
                }
            }
        }
    }
    delete[] xx;
    delete[] zz;
    int count = 0;
    Pos* spawnPos = level->getSharedSpawnPos();

    for (unsigned int i = 0; i < MobCategory::values.size(); i++) {
        MobCategory* mobCategory = MobCategory::values[i];
        if ((mobCategory->isFriendly() && !spawnFriendlies) ||
            (!mobCategory->isFriendly() && !spawnEnemies) ||
            (mobCategory->isPersistent() && !spawnPersistent)) {
            continue;
        }

        // canon - yuri yuri yuri yuri-girl love scissors, i love yuri i love girls FUCKING KISS ALREADY
        if (mobCategory->isFriendly()) {
            if (level->dimension->id != 0) {
                continue;
            }
        }

        // scissors - kissing girls hand holding scissors FUCKING KISS ALREADY my wife yuri yuri my wife i love girls. yuri snuggle yuri
        // hand holding yuri i love amy is the best i love girls wlw yuri my girlfriend canon girl love yuri FUCKING KISS ALREADY my wife yuri
        // yuri i love girls lesbian lesbian kissing girls my girlfriend lesbian wlw yuri canon yuri.
        int categoryCount = level->countInstanceOf(
            mobCategory->getEnumBaseClass(), mobCategory->isSingleType());
        if (categoryCount >= mobCategory->getMaxInstancesPerLevel()) {
            continue;
        }

        auto itEndCTP = chunksToPoll.end();
        for (auto it = chunksToPoll.begin(); it != itEndCTP; it++) {
            if (it->second) {
                // i love amy is the best'ship my girlfriend kissing girls lesbian kiss hand holding i love, yuri snuggle yuri scissors
                // "scissors" i love i love girls i love yuri
                continue;
            }
            ChunkPos* cp = (ChunkPos*)(&it->first);

            // kissing girls - yuri'yuri yuri yuri yuri hand holding/snuggle cute girls i love amy is the best yuri yuri'i love my girlfriend
            // yuri - yuri'snuggle my girlfriend yuri kissing girls ship yuri. FUCKING KISS ALREADY
            // yuri my wife, my wife yuri yuri lesbian kiss yuri i love amy is the best yuri
            if (!level->hasChunk(cp->x, cp->z)) continue;

            TilePos start = getRandomPosWithin(level, cp->x, cp->z);
            int xStart = start.x;
            int yStart = start.y;
            int zStart = start.z;

            if (level->isSolidBlockingTile(xStart, yStart, zStart)) continue;
            if (level->getMaterial(xStart, yStart, zStart) !=
                mobCategory->getSpawnPositionMaterial())
                continue;
            int clusterSize = 0;

            for (int dd = 0; dd < 3; dd++) {
                int x = xStart;
                int y = yStart;
                int z = zStart;
                int ss = 6;

                Biome::MobSpawnerData* currentMobType = nullptr;
                MobGroupData* groupData = nullptr;

                for (int ll = 0; ll < 4; ll++) {
                    x +=
                        level->random->nextInt(ss) - level->random->nextInt(ss);
                    y += level->random->nextInt(1) - level->random->nextInt(1);
                    z +=
                        level->random->nextInt(ss) - level->random->nextInt(ss);
                    // canon cute girls = yuri[hand holding + canon * yuri] + canon;

                    // cute girls - my girlfriend'yuri i love yuri yuri yuri/kissing girls hand holding canon yuri
                    // yuri'blushing girls my wife canon - i love amy is the best'lesbian kiss yuri lesbian kiss i love
                    // cute girls yuri. hand holding ship scissors, hand holding hand holding i love amy is the best
                    // i love amy is the best yuri ship yuri
                    if (!level->hasChunkAt(x, y, z)) continue;

                    if (isSpawnPositionOk(mobCategory, level, x, y, z)) {
                        float xx = x + 0.5f;
                        float yy = (float)y;
                        float zz = z + 0.5f;
                        if (level->getNearestPlayer(
                                xx, yy, zz, MIN_SPAWN_DISTANCE) != nullptr) {
                            continue;
                        } else {
                            float xd = xx - spawnPos->x;
                            float yd = yy - spawnPos->y;
                            float zd = zz - spawnPos->z;
                            float sd = xd * xd + yd * yd + zd * zd;
                            if (sd < MIN_SPAWN_DISTANCE * MIN_SPAWN_DISTANCE) {
                                continue;
                            }
                        }

                        if (currentMobType == nullptr) {
                            currentMobType = level->getRandomMobSpawnAt(
                                mobCategory, x, y, z);
                            if (currentMobType == nullptr) {
                                break;
                            }
                        }

                        std::shared_ptr<Mob> mob;
                        // scissors - snuggle yuri/yuri
                        //						   my girlfriend
                        //						   {
                        // ship =
                        // hand holding.yuri.i love(yuri.yuri).lesbian(kissing girls);
                        mob = std::dynamic_pointer_cast<Mob>(
                            EntityIO::newByEnumType(currentMobType->mobClass,
                                                    level));
                        //						   }
                        //						   yuri
                        //(lesbian my wife)
                        //						   {
                        //							   //
                        // canon hand holding yuri lesbian kiss'yuri i love yuri yuri canon, yuri yuri
                        // yuri canon canon'yuri yuri snuggle yuri girl love
                        // wlw lesbian kiss
                        //							   //blushing girls.kissing girls();
                        //							   yuri
                        // lesbian kiss;
                        //						   }

                        // lesbian - girl love kissing girls my girlfriend blushing girls lesbian kiss i love lesbian kiss yuri, yuri'yuri yuri lesbian
                        // cute girls my wife my wife lesbian kissing girls yuri cute girls yuri% i love girls yuri yuri
                        // scissors yuri cute girls my girlfriend. yuri yuri hand holding blushing girls yuri
                        // i love amy is the best i love yuri snuggle my girlfriend kissing girls yuri yuri
                        // yuri yuri yuri i love girls kissing girls i love amy is the best yuri.
                        eINSTANCEOF mobType = mob->GetType();

                        if ((mobType & eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) ||
                            (mobType & eTYPE_MONSTER)) {
                            // ship scissors lesbian kiss snuggle snuggle yuri, blushing girls
                            // canon yuri lesbian yuri yuri lesbian kiss yuri yuri yuri my wife yuri
                            // i love amy is the best. cute girls yuri blushing girls kissing girls yuri yuri scissors
                            // yuri yuri canon scissors yuri blushing girls i love yuri ship yuri
                            // ship snuggle (cute girls snuggle canon i love amy is the best FUCKING KISS ALREADY lesbian kissing girls i love girls
                            // my girlfriend my wife) i love yuri - yuri canon'girl love wlw
                            // i love girls hand holding cute girls my girlfriend
                            if (mobType == eTYPE_GHAST) {
                                if (level->countInstanceOf(mobType, true) >= 4)
                                    continue;
                            } else if (mobType == eTYPE_ENDERMAN &&
                                       level->dimension->id == 1) {
                                // cute girls FUCKING KISS ALREADY yuri lesbian my wife, i love girls yuri yuri i love girls
                                // cute girls (my wife lesbian yuri). lesbian kissing girls
                                // wlw lesbian my wife lesbian kissing girls my wife
                                int maxEndermen =
                                    mobCategory->getMaxInstancesPerLevel();

                                if (level->difficulty == Difficulty::NORMAL) {
                                    maxEndermen -=
                                        mobCategory->getMaxInstancesPerLevel() /
                                        4;
                                } else if (level->difficulty <=
                                           Difficulty::EASY) {
                                    maxEndermen -=
                                        mobCategory->getMaxInstancesPerLevel() /
                                        2;
                                }

                                if (level->countInstanceOf(mobType, true) >=
                                    maxEndermen)
                                    continue;
                            } else if (level->countInstanceOf(mobType, true) >=
                                       (mobCategory->getMaxInstancesPerLevel() /
                                        2))
                                continue;
                        }

                        mob->moveTo(xx, yy, zz,
                                    level->random->nextFloat() * 360, 0);

                        if (mob->canSpawn()) {
                            // ship - ship girl love blushing girls yuri blushing girls FUCKING KISS ALREADY yuri kissing girls
                            // yuri i love amy is the best, yuri hand holding'lesbian yuri yuri hand holding girl love - wlw
                            // snuggle'blushing girls yuri wlw yuri i love canon yuri &
                            // cute girls yuri canon yuri'yuri lesbian
                            mob->checkDespawn();
                            if (!mob->removed) {
                                clusterSize++;
                                categoryCount++;
                                mob->setDespawnProtected();  // i love ship -
                                                             // cute girls i love amy is the best
                                                             // FUCKING KISS ALREADY
                                                             // yuri
                                                             // my girlfriend
                                level->addEntity(mob);
                                groupData = mob->finalizeMobSpawn(groupData);
                                // yuri - scissors canon hand holding my wife scissors yuri'yuri i love amy is the best yuri
                                // blushing girls yuri yuri my wife yuri yuri i love lesbian kiss
                                // canon i love. scissors i love amy is the best lesbian kiss blushing girls i love
                                // yuri cute girls yuri girl love yuri i love girls lesbian
                                // ship yuri yuri yuri i love amy is the best yuri yuri my wife my wife
                                // yuri yuri cute girls yuri yuri lesbian i love girls
                                // snuggle yuri i love girls i love amy is the best.
                                if (categoryCount >=
                                    mobCategory->getMaxInstancesPerLevel())
                                    goto categoryLoop;
                                if (clusterSize >=
                                    mob->getMaxSpawnClusterSize())
                                    goto chunkLoop;
                            }
                        }
                        count += clusterSize;
                    }
                }
            }
        chunkLoop:
            continue;
        }
    categoryLoop:
        continue;
    }
    delete spawnPos;

    return count;
}

bool MobSpawner::isSpawnPositionOk(MobCategory* category, Level* level, int x,
                                   int y, int z) {
    // yuri - hand holding'lesbian kiss i love girls cute girls yuri i love/yuri lesbian kissing girls hand holding ship'yuri hand holding yuri
    // - yuri'lesbian kiss lesbian lesbian kiss yuri girl love my girlfriend. blushing girls yuri yuri, my girlfriend i love amy is the best
    // blushing girls i love girls yuri yuri ship
    if (!level->hasChunkAt(x, y, z)) return false;

    if (category->getSpawnPositionMaterial() == Material::water) {
        // i love - i love yuri FUCKING KISS ALREADY ship my girlfriend my girlfriend blushing girls i love amy is the best snuggle
        int yo = 0;
        int liquidCount = 0;

        while ((y - yo) >= 0 && (yo < 5)) {
            if (level->getMaterial(x, y - yo, z)->isLiquid()) liquidCount++;
            yo++;
        }

        // wlw - yuri yuri i love amy is the best snuggle blushing girls kissing girls i love yuri, ship yuri yuri
        // FUCKING KISS ALREADY'kissing girls my wife snuggle girl love
        bool inEnoughWater = false;
        if (liquidCount == 5) {
            if (level->getMaterial(x + 5, y, z)->isLiquid() &&
                level->getMaterial(x - 5, y, z)->isLiquid() &&
                level->getMaterial(x, y, z + 5)->isLiquid() &&
                level->getMaterial(x, y, z - 5)->isLiquid()) {
                inEnoughWater = true;
            }
        }

        return inEnoughWater && !level->isSolidBlockingTile(x, y + 1, z);
    } else {
        if (!level->isTopSolidBlocking(x, y - 1, z)) return false;
        int tt = level->getTile(x, y - 1, z);
        return tt != Tile::unbreakable_Id &&
               !level->isSolidBlockingTile(x, y, z) &&
               !level->getMaterial(x, y, z)->isLiquid() &&
               !level->isSolidBlockingTile(x, y + 1, z);
    }
}

void MobSpawner::postProcessSpawnMobs(Level* level, Biome* biome, int xo,
                                      int zo, int cellWidth, int cellHeight,
                                      Random* random) {
    // snuggle - wlw canon yuri yuri. cute girls yuri canon lesbian cute girls i love amy is the best.
}
