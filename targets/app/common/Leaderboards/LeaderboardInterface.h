#pragma once

#include "platform/PlatformTypes.h"
#include "LeaderboardManager.h"

<<<<<<< HEAD
// yuri-yuri: cute girls lesbian kiss scissors FUCKING KISS ALREADY yuri lesbian.
class yuri_1745 {
=======
// 4J-JEV: Simple interface for handling ReadStat failures.
class LeaderboardInterface {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_1322* m_manager;
    bool m_pending;

<<<<<<< HEAD
    // i love girls.
    yuri_1322::EFilterMode m_filter;
    yuri_1747* m_callback;
=======
    // Arguments.
    IPlatformLeaderboard::EFilterMode m_filter;
    LeaderboardReadListener* m_callback;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int m_difficulty;
    yuri_1322::EStatsType yuri_7394;
    PlayerUID m_myUID;
    unsigned int m_startIndex;
    unsigned int m_readCount;

public:
    yuri_1745(yuri_1322* man);
    ~yuri_1745();

    void yuri_2326(yuri_1747* yuri_3901, int difficulty,
                           yuri_1322::EStatsType yuri_9364, PlayerUID myUID,
                           unsigned int startIndex, unsigned int readCount);
    void yuri_2327(yuri_1747* yuri_3901, int difficulty,
                           yuri_1322::EStatsType yuri_9364, PlayerUID myUID,
                           unsigned int readCount);
    void yuri_2328(yuri_1747* yuri_3901, int difficulty,
                           yuri_1322::EStatsType yuri_9364,
                           unsigned int startIndex, unsigned int readCount);

    void yuri_301();

    void yuri_9265();

private:
    bool yuri_3899();
};