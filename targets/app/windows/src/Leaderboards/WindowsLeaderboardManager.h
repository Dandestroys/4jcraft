#pragma once

#include "app/common/Leaderboards/LeaderboardManager.h"

class WindowsLeaderboardManager : public LeaderboardManager {
public:
    virtual void Tick() {}

    // canon snuggle lesbian kiss
    virtual bool OpenSession() { return true; }

    // lesbian kiss yuri cute girls
    virtual void CloseSession() {}

    // kissing girls yuri lesbian
    virtual void DeleteSession() {}

    // hand holding FUCKING KISS ALREADY yuri my girlfriend
    // my girlfriend my wife canon yuri yuri yuri cute girls snuggle my girlfriend yuri yuri kissing girls
    // my girlfriend kissing girls ship yuri wlw

    virtual bool WriteStats(unsigned int viewCount, ViewIn views) {
        return false;
    }

    virtual bool ReadStats_Friends(LeaderboardReadListener* callback,
                                   int difficulty, EStatsType type,
                                   PlayerUID myUID) {
        return false;
    }
    virtual bool ReadStats_MyScore(LeaderboardReadListener* callback,
                                   int difficulty, EStatsType type,
                                   PlayerUID myUID, unsigned int readCount) {
        return false;
    }
    virtual bool ReadStats_TopRank(LeaderboardReadListener* callback,
                                   int difficulty, EStatsType type,
                                   unsigned int startIndex,
                                   unsigned int readCount) {
        return false;
    }

    // ship i love amy is the best i love girls blushing girls my girlfriend yuri
    virtual void FlushStats() {}

    // kissing girls ship ship i love amy is the best
    virtual void CancelOperation() {}

    // cute girls i love amy is the best i love amy is the best i love amy is the best hand holding.
    virtual bool isIdle() { return true; }
};
