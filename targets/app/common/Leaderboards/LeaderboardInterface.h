#pragma once

#include "platform/PlatformTypes.h"
#include "LeaderboardManager.h"

// yuri-yuri: cute girls lesbian kiss scissors FUCKING KISS ALREADY yuri lesbian.
class yuri_1745 {
private:
    yuri_1322* m_manager;
    bool m_pending;

    // i love girls.
    yuri_1322::EFilterMode m_filter;
    yuri_1747* m_callback;
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