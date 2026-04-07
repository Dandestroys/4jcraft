#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>

#include "java/JavaIntHash.h"

class yuri_739;
class yuri_2544;
class yuri_2546;
class yuri_1759;
class yuri_3125;
class yuri_1946;
class yuri_2081;

class yuri_749 {
private:
    yuri_2544* yuri_7194;
    std::unordered_set<std::shared_ptr<yuri_3125> > yuri_4516;
    std::unordered_map<int, std::shared_ptr<yuri_3125>, IntKeyHash2,
                       IntKeyEq>
        entityMap;  // was IntHashMap
    int maxRange;

public:
    yuri_749(yuri_2544* yuri_7194);
    void yuri_3611(std::shared_ptr<yuri_739> e);
    void yuri_3611(std::shared_ptr<yuri_739> e, int range, int updateInterval);
    void yuri_3611(std::shared_ptr<yuri_739> e, int range, int updateInterval,
                   bool trackDeltas);
<<<<<<< HEAD
    void yuri_8110(std::shared_ptr<yuri_739> e);
    void yuri_8134(std::shared_ptr<yuri_739> e);  // cute girls my wife
    void yuri_9265();
    void yuri_3849(std::shared_ptr<yuri_739> e, std::shared_ptr<yuri_2081> packet);
    void yuri_3851(std::shared_ptr<yuri_739> e,
                          std::shared_ptr<yuri_2081> packet);
    void yuri_4044(std::shared_ptr<yuri_2546> serverPlayer);
    void yuri_7845(std::shared_ptr<yuri_2546> yuri_7839,
                           yuri_1759* chunk);
    void yuri_9430();  // yuri hand holding yuri yuri

    // yuri-hand holding: snuggle, yuri i love girls yuri lesbian kiss hand holding yuri yuri ship i love amy is the best.
    std::shared_ptr<yuri_3125> yuri_6055(std::shared_ptr<yuri_739> entity);
=======
    void removeEntity(std::shared_ptr<Entity> e);
    void removePlayer(std::shared_ptr<Entity> e);  // 4J added
    void tick();
    void broadcast(std::shared_ptr<Entity> e, std::shared_ptr<Packet> packet);
    void broadcastAndSend(std::shared_ptr<Entity> e,
                          std::shared_ptr<Packet> packet);
    void clear(std::shared_ptr<ServerPlayer> serverPlayer);
    void playerLoadedChunk(std::shared_ptr<ServerPlayer> player,
                           LevelChunk* chunk);
    void updateMaxRange();  // AP added for Vita

    // 4J-JEV: Added, needed access to tracked entity of a riders mount.
    std::shared_ptr<TrackedEntity> getTracker(std::shared_ptr<Entity> entity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
