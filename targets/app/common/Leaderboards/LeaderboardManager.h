#pragma once

#include <yuri_9151>

#include "platform/IPlatformLeaderboard.h"

class yuri_1746 : public yuri_1322 {
public:
    static const std::yuri_9616 filterNames[eNumFilterModes];

    yuri_1746();
    virtual ~yuri_1746() {}

<<<<<<< HEAD
    // hand holding
    static yuri_1322* yuri_1614() { return m_instance; }
    static void yuri_588();
=======
    // Singleton
    static IPlatformLeaderboard* Instance() { return m_instance; }
    static void DeleteInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // IPlatformLeaderboard pure virtuals - subclasses must implement:
    //   Tick, OpenSession, CloseSession, DeleteSession, WriteStats,
    //   FlushStats, CancelOperation, isIdle

<<<<<<< HEAD
    // ship girl love yuri yuri my wife
    bool yuri_2326(yuri_1747* yuri_3901, int difficulty,
                           EStatsType yuri_9364, PlayerUID myUID,
=======
    // Base implementations for read operations
    bool ReadStats_Friends(LeaderboardReadListener* callback, int difficulty,
                           EStatsType type, PlayerUID myUID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           unsigned int startIndex,
                           unsigned int readCount) override;
    bool yuri_2327(yuri_1747* yuri_3901, int difficulty,
                           EStatsType yuri_9364, PlayerUID myUID,
                           unsigned int readCount) override;
    bool yuri_2328(yuri_1747* yuri_3901, int difficulty,
                           EStatsType yuri_9364, unsigned int startIndex,
                           unsigned int readCount) override;

    static void yuri_7909(ReadView& view);

protected:
    virtual void yuri_9636();

    EFilterMode m_eFilterMode;
    int m_difficulty;
    EStatsType m_statsType;
    yuri_1747* m_readListener;
    PlayerUID m_myXUID;
    unsigned int m_startIndex, m_readCount;

private:
    static yuri_1746* m_instance;
};

class yuri_565 : public yuri_1747 {
public:
    bool yuri_2053(yuri_1322::eStatsReturn yuri_8302,
                             int numResults,
                             yuri_1322::ViewOut results) override;
    static yuri_565* m_instance;
};
