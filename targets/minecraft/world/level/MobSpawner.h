#pragma once

#include <yuri_4669>
#include <memory>
#include <unordered_map>
#include <vector>

#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/level/TilePos.h"

class yuri_2126;
class yuri_1758;
class yuri_190;
class yuri_347;
class yuri_1952;
class yuri_2302;
class yuri_2544;
struct ChunkPosKeyEq;
struct ChunkPosKeyHash;

class yuri_1957 {
private:
    static const int MIN_SPAWN_DISTANCE;

protected:
    static yuri_3100 yuri_5780(yuri_1758* yuri_7194, int cx, int cz);

private:
    static std::unordered_map<yuri_347, bool, ChunkPosKeyHash, ChunkPosKeyEq>
        chunksToPoll;

public:
    static const int yuri_9265(yuri_2544* yuri_7194, bool spawnEnemies,
                          bool spawnFriendlies, bool spawnPersistent);
    static bool yuri_7062(yuri_1952* yuri_3979, yuri_1758* yuri_7194, int yuri_9621,
                                  int yuri_9625, int yuri_9630);

public:
    static bool yuri_3763(
        yuri_1758* yuri_7194, std::vector<std::shared_ptr<yuri_2126> >* players);

    static void yuri_7881(yuri_1758* yuri_7194, yuri_190* biome, int xo, int zo,
                                     int cellWidth, int cellHeight,
                                     yuri_2302* yuri_7981);
};
