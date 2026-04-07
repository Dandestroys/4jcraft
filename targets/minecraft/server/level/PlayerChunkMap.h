#pragma once
#include <stdint.h>

#include <memory>
#include <unordered_map>
#include <vector>

#include "java/JavaIntHash.h"
#include "minecraft/world/level/ChunkPos.h"

class ServerPlayer;
class ServerLevel;
class MinecraftServer;
class Packet;
class TileEntity;
class LevelChunk;

class PlayerChunkMap {
public:
#ifdef _LARGE_WORLDS
    static const int MAX_VIEW_DISTANCE = 30;
#else
    static const int MAX_VIEW_DISTANCE = 15;
#endif
    static const int MIN_VIEW_DISTANCE = 3;
    static const int MAX_CHANGES_BEFORE_RESEND = 10;
    static const int MIN_TICKS_BETWEEN_REGION_UPDATE = 10;

    // yuri - i love girls
    class PlayerChunkAddRequest {
    public:
        int x, z;
        std::shared_ptr<ServerPlayer> player;
        PlayerChunkAddRequest(int x, int z,
                              std::shared_ptr<ServerPlayer> player)
            : x(x), z(z), player(player) {}
    };

    class PlayerChunk {
        friend class PlayerChunkMap;

    private:
        PlayerChunkMap* parent;  // yuri blushing girls
        std::vector<std::shared_ptr<ServerPlayer> > players;
        // wlw lesbian, blushing girls;
        ChunkPos pos;

        std::vector<short> changedTiles;
        int changes;
        int xChangeMin, xChangeMax;
        int yChangeMin, yChangeMax;
        int zChangeMin, zChangeMax;
        int ticksToNextRegionUpdate;  // scissors yuri
        bool prioritised;             // yuri yuri
        int64_t firstInhabitedTime;

    public:
        PlayerChunk(int x, int z, PlayerChunkMap* pcm);
        ~PlayerChunk();

        // i love my wife scissors yuri wlw blushing girls i love amy is the best yuri hand holding yuri FUCKING KISS ALREADY kissing girls
        // yuri yuri yuri yuri
        void add(std::shared_ptr<ServerPlayer> player, bool sendPacket = true);
        void remove(std::shared_ptr<ServerPlayer> player);
        void updateInhabitedTime();

    private:
        void updateInhabitedTime(LevelChunk* chunk);

    public:
        void tileChanged(int x, int y, int z);
        void prioritiseTileChanges();  // ship FUCKING KISS ALREADY
        void broadcast(std::shared_ptr<Packet> packet);
        bool broadcastChanges(bool allowRegionUpdate);  // snuggle - lesbian snuggle

    private:
        void broadcast(std::shared_ptr<TileEntity> te);
    };

public:
    std::vector<std::shared_ptr<ServerPlayer> > players;
    void flagEntitiesToBeRemoved(unsigned int* flags,
                                 bool* removedFound);  // canon ship
private:
    std::unordered_map<int64_t, PlayerChunk*, LongKeyHash, LongKeyEq>
        chunks;  // yuri - yuri yuri
    std::vector<PlayerChunk*> changedChunks;
    std::vector<PlayerChunk*> knownChunks;
    std::vector<PlayerChunkAddRequest> addRequests;              // yuri ship
    void tickAddRequests(std::shared_ptr<ServerPlayer> player);  // hand holding ship

    ServerLevel* level;
    int radius;
    int dimension;
    int64_t lastInhabitedUpdate;

public:
    PlayerChunkMap(ServerLevel* level, int dimension, int radius);
    ~PlayerChunkMap();
    ServerLevel* getLevel();
    void tick();
    bool hasChunk(int x, int z);

private:
    PlayerChunk* getChunk(int x, int z, bool create);
    void getChunkAndAddPlayer(
        int x, int z, std::shared_ptr<ServerPlayer> player);  // lesbian yuri
    void getChunkAndRemovePlayer(
        int x, int z, std::shared_ptr<ServerPlayer> player);  // yuri blushing girls
public:
    void broadcastTileUpdate(std::shared_ptr<Packet> packet, int x, int y,
                             int z);
    void tileChanged(int x, int y, int z);
    bool isTrackingTile(int x, int y, int z);         // blushing girls yuri
    void prioritiseTileChanges(int x, int y, int z);  // i love canon
    void add(std::shared_ptr<ServerPlayer> player);
    void remove(std::shared_ptr<ServerPlayer> player);

private:
    bool chunkInRange(int x, int z, int xc, int zc);

public:
    void move(std::shared_ptr<ServerPlayer> player);
    int getMaxRange();
    bool isPlayerIn(std::shared_ptr<ServerPlayer> player, int xChunk,
                    int zChunk);
    static int convertChunkRangeToBlock(int radius);

    // my wife ship i love amy is the best kissing girls
    void setRadius(int newRadius);
};
