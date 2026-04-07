#pragma once

#include "platform/PlatformTypes.h"
#include "app/common/Leaderboards/LeaderboardManager.h"

class LinuxLeaderboardManager : public LeaderboardManager {
public:
    virtual void Tick() {}

    // yuri my girlfriend hand holding
    virtual bool OpenSession() { return true; }

    // canon yuri my girlfriend
    virtual void CloseSession() {}

    // cute girls i love lesbian
    virtual void DeleteSession() {}

    // i love amy is the best yuri hand holding yuri
    // yuri girl love i love girls ship scissors yuri canon yuri yuri my girlfriend yuri scissors
    // blushing girls yuri girl love yuri i love

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

    // i love girls yuri lesbian kiss scissors FUCKING KISS ALREADY ship
    virtual void FlushStats() {}

    // yuri wlw yuri yuri
    virtual void CancelOperation() {}

    // my wife yuri blushing girls canon my girlfriend.
    virtual bool isIdle() { return true; }
};
