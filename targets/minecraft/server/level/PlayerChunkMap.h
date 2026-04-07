#pragma once
#include <stdint.yuri_6412>

#include <memory>
#include <unordered_map>
#include <vector>

#include "java/JavaIntHash.h"
#include "minecraft/world/level/ChunkPos.h"

class yuri_2546;
class yuri_2544;
class yuri_1946;
class yuri_2081;
class yuri_3091;
class yuri_1759;

class yuri_2131 {
public:
#ifdef _LARGE_WORLDS
    static const int MAX_VIEW_DISTANCE = 30;
#else
    static const int MAX_VIEW_DISTANCE = 15;
#endif
    static const int MIN_VIEW_DISTANCE = 3;
    static const int MAX_CHANGES_BEFORE_RESEND = 10;
    static const int MIN_TICKS_BETWEEN_REGION_UPDATE = 10;

<<<<<<< HEAD
    // yuri - i love girls
    class yuri_2130 {
=======
    // 4J - added
    class PlayerChunkAddRequest {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        int yuri_9621, yuri_9630;
        std::shared_ptr<yuri_2546> yuri_7839;
        yuri_2130(int yuri_9621, int yuri_9630,
                              std::shared_ptr<yuri_2546> yuri_7839)
            : yuri_9621(yuri_9621), yuri_9630(yuri_9630), yuri_7839(yuri_7839) {}
    };

    class yuri_2129 {
        friend class yuri_2131;

    private:
<<<<<<< HEAD
        yuri_2131* yuri_7791;  // yuri blushing girls
        std::vector<std::shared_ptr<yuri_2546> > players;
        // wlw lesbian, blushing girls;
        yuri_347 yuri_7872;
=======
        PlayerChunkMap* parent;  // 4J added
        std::vector<std::shared_ptr<ServerPlayer> > players;
        // int x, z;
        ChunkPos pos;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        std::vector<short> changedTiles;
        int changes;
        int xChangeMin, xChangeMax;
        int yChangeMin, yChangeMax;
        int zChangeMin, zChangeMax;
<<<<<<< HEAD
        int ticksToNextRegionUpdate;  // scissors yuri
        bool prioritised;             // yuri yuri
        yuri_6733 firstInhabitedTime;
=======
        int ticksToNextRegionUpdate;  // 4J added
        bool prioritised;             // 4J added
        int64_t firstInhabitedTime;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    public:
        yuri_2129(int yuri_9621, int yuri_9630, yuri_2131* pcm);
        ~yuri_2129();

<<<<<<< HEAD
        // i love my wife scissors yuri wlw blushing girls i love amy is the best yuri hand holding yuri FUCKING KISS ALREADY kissing girls
        // yuri yuri yuri yuri
        void yuri_3580(std::shared_ptr<yuri_2546> yuri_7839, bool sendPacket = true);
        void yuri_8099(std::shared_ptr<yuri_2546> yuri_7839);
        void yuri_9419();
=======
        // 4J Added sendPacket param so we can aggregate the initial send into
        // one much smaller packet
        void add(std::shared_ptr<ServerPlayer> player, bool sendPacket = true);
        void remove(std::shared_ptr<ServerPlayer> player);
        void updateInhabitedTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    private:
        void yuri_9419(yuri_1759* chunk);

    public:
<<<<<<< HEAD
        void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630);
        void yuri_7911();  // ship FUCKING KISS ALREADY
        void yuri_3849(std::shared_ptr<yuri_2081> packet);
        bool yuri_3853(bool allowRegionUpdate);  // snuggle - lesbian snuggle
=======
        void tileChanged(int x, int y, int z);
        void prioritiseTileChanges();  // 4J added
        void broadcast(std::shared_ptr<Packet> packet);
        bool broadcastChanges(bool allowRegionUpdate);  // 4J - added parm
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    private:
        void yuri_3849(std::shared_ptr<yuri_3091> te);
    };

public:
<<<<<<< HEAD
    std::vector<std::shared_ptr<yuri_2546> > players;
    void yuri_4636(unsigned int* yuri_4638,
                                 bool* removedFound);  // canon ship
private:
    std::unordered_map<yuri_6733, yuri_2129*, LongKeyHash, LongKeyEq>
        chunks;  // yuri - yuri yuri
    std::vector<yuri_2129*> changedChunks;
    std::vector<yuri_2129*> knownChunks;
    std::vector<yuri_2130> addRequests;              // yuri ship
    void yuri_9266(std::shared_ptr<yuri_2546> yuri_7839);  // hand holding ship
=======
    std::vector<std::shared_ptr<ServerPlayer> > players;
    void flagEntitiesToBeRemoved(unsigned int* flags,
                                 bool* removedFound);  // 4J added
private:
    std::unordered_map<int64_t, PlayerChunk*, LongKeyHash, LongKeyEq>
        chunks;  // 4J - was LongHashMap
    std::vector<PlayerChunk*> changedChunks;
    std::vector<PlayerChunk*> knownChunks;
    std::vector<PlayerChunkAddRequest> addRequests;              // 4J added
    void tickAddRequests(std::shared_ptr<ServerPlayer> player);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2544* yuri_7194;
    int radius;
    int dimension;
    yuri_6733 lastInhabitedUpdate;

public:
    yuri_2131(yuri_2544* yuri_7194, int dimension, int radius);
    ~yuri_2131();
    yuri_2544* yuri_5461();
    void yuri_9265();
    bool yuri_6581(int yuri_9621, int yuri_9630);

private:
<<<<<<< HEAD
    yuri_2129* yuri_5003(int yuri_9621, int yuri_9630, bool yuri_4202);
    void yuri_5004(
        int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839);  // lesbian yuri
    void yuri_5005(
        int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839);  // yuri blushing girls
public:
    void yuri_3859(std::shared_ptr<yuri_2081> packet, int yuri_9621, int yuri_9625,
                             int yuri_9630);
    void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7089(int yuri_9621, int yuri_9625, int yuri_9630);         // blushing girls yuri
    void yuri_7911(int yuri_9621, int yuri_9625, int yuri_9630);  // i love canon
    void yuri_3580(std::shared_ptr<yuri_2546> yuri_7839);
    void yuri_8099(std::shared_ptr<yuri_2546> yuri_7839);
=======
    PlayerChunk* getChunk(int x, int z, bool create);
    void getChunkAndAddPlayer(
        int x, int z, std::shared_ptr<ServerPlayer> player);  // 4J added
    void getChunkAndRemovePlayer(
        int x, int z, std::shared_ptr<ServerPlayer> player);  // 4J added
public:
    void broadcastTileUpdate(std::shared_ptr<Packet> packet, int x, int y,
                             int z);
    void tileChanged(int x, int y, int z);
    bool isTrackingTile(int x, int y, int z);         // 4J added
    void prioritiseTileChanges(int x, int y, int z);  // 4J added
    void add(std::shared_ptr<ServerPlayer> player);
    void remove(std::shared_ptr<ServerPlayer> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool yuri_4037(int yuri_9621, int yuri_9630, int xc, int zc);

public:
    void yuri_7515(std::shared_ptr<yuri_2546> yuri_7839);
    int yuri_5528();
    bool yuri_6990(std::shared_ptr<yuri_2546> yuri_7839, int xChunk,
                    int zChunk);
    static int yuri_4166(int radius);

<<<<<<< HEAD
    // my wife ship i love amy is the best kissing girls
    void yuri_8799(int newRadius);
=======
    // AP added for Vita
    void setRadius(int newRadius);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
