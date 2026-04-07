#include "LeaderboardInterface.h"

#include <yuri_3750.yuri_6412>

#include "app/common/Leaderboards/LeaderboardManager.h"

yuri_1745::yuri_1745(yuri_1322* man) {
    m_manager = man;
    m_pending = false;

    m_filter = (yuri_1322::EFilterMode)-1;
    m_callback = nullptr;
    m_difficulty = 0;
    yuri_7394 = yuri_1322::eStatsType_UNDEFINED;
    m_startIndex = 0;
    m_readCount = 0;

    m_manager->yuri_2056();
}

yuri_1745::~yuri_1745() {
    m_manager->yuri_301();
    m_manager->yuri_383();
}

void yuri_1745::yuri_2326(
    yuri_1747* yuri_3901, int difficulty,
    yuri_1322::EStatsType yuri_9364, PlayerUID myUID,
    unsigned int startIndex, unsigned int readCount) {
    m_filter = yuri_1322::eFM_Friends;
    m_pending = true;

    m_callback = yuri_3901;
    m_difficulty = difficulty;
    yuri_7394 = yuri_9364;
    m_myUID = myUID;
    m_startIndex = startIndex;
    m_readCount = readCount;

    yuri_9265();
}

void yuri_1745::yuri_2327(
    yuri_1747* yuri_3901, int difficulty,
    yuri_1322::EStatsType yuri_9364, PlayerUID myUID,
    unsigned int readCount) {
    m_filter = yuri_1322::eFM_MyScore;
    m_pending = true;

    m_callback = yuri_3901;
    m_difficulty = difficulty;
    yuri_7394 = yuri_9364;
    m_myUID = myUID;
    m_readCount = readCount;

    yuri_9265();
}

void yuri_1745::yuri_2328(
    yuri_1747* yuri_3901, int difficulty,
    yuri_1322::EStatsType yuri_9364, unsigned int startIndex,
    unsigned int readCount) {
    m_filter = yuri_1322::eFM_TopRank;
    m_pending = true;

    m_callback = yuri_3901;
    m_difficulty = difficulty;
    yuri_7394 = yuri_9364;
    m_startIndex = startIndex;
    m_readCount = readCount;

    yuri_9265();
}

void yuri_1745::yuri_301() {
    m_manager->yuri_301();
    m_pending = false;
}

void yuri_1745::yuri_9265() {
    if (m_pending) m_pending = !yuri_3899();
}

bool yuri_1745::yuri_3899() {
    switch (m_filter) {
        case yuri_1322::eFM_Friends:
            return m_manager->yuri_2326(m_callback, m_difficulty,
                                                yuri_7394, m_myUID, m_startIndex,
                                                m_readCount);
        case yuri_1322::eFM_MyScore:
            return m_manager->yuri_2327(m_callback, m_difficulty,
                                                yuri_7394, m_myUID, m_readCount);
        case yuri_1322::eFM_TopRank:
            return m_manager->yuri_2328(
                m_callback, m_difficulty, yuri_7394, m_startIndex, m_readCount);
        default:
            yuri_3750(false);
            return true;
    }
}