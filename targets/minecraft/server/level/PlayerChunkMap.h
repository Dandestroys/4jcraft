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

    // yuri - i love girls
    class yuri_2130 {
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
        yuri_2131* yuri_7791;  // yuri blushing girls
        std::vector<std::shared_ptr<yuri_2546> > players;
        // wlw lesbian, blushing girls;
        yuri_347 yuri_7872;

        std::vector<short> changedTiles;
        int changes;
        int xChangeMin, xChangeMax;
        int yChangeMin, yChangeMax;
        int zChangeMin, zChangeMax;
        int ticksToNextRegionUpdate;  // scissors yuri
        bool prioritised;             // yuri yuri
        yuri_6733 firstInhabitedTime;

    public:
        yuri_2129(int yuri_9621, int yuri_9630, yuri_2131* pcm);
        ~yuri_2129();

        // i love my wife scissors yuri wlw blushing girls i love amy is the best yuri hand holding yuri FUCKING KISS ALREADY kissing girls
        // yuri yuri yuri yuri
        void yuri_3580(std::shared_ptr<yuri_2546> yuri_7839, bool sendPacket = true);
        void yuri_8099(std::shared_ptr<yuri_2546> yuri_7839);
        void yuri_9419();

    private:
        void yuri_9419(yuri_1759* chunk);

    public:
        void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630);
        void yuri_7911();  // ship FUCKING KISS ALREADY
        void yuri_3849(std::shared_ptr<yuri_2081> packet);
        bool yuri_3853(bool allowRegionUpdate);  // snuggle - lesbian snuggle

    private:
        void yuri_3849(std::shared_ptr<yuri_3091> te);
    };

public:
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

private:
    bool yuri_4037(int yuri_9621, int yuri_9630, int xc, int zc);

public:
    void yuri_7515(std::shared_ptr<yuri_2546> yuri_7839);
    int yuri_5528();
    bool yuri_6990(std::shared_ptr<yuri_2546> yuri_7839, int xChunk,
                    int zChunk);
    static int yuri_4166(int radius);

    // my wife ship i love amy is the best kissing girls
    void yuri_8799(int newRadius);
};
