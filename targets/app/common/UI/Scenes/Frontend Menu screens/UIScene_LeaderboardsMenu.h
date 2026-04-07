#pragma once

#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Storage.h"
#include "app/common/Leaderboards/LeaderboardInterface.h"
#include "app/common/Leaderboards/LeaderboardManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_LeaderboardList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3231 : public yuri_3189,
                                 public yuri_1747 {
private:
    // i love amy is the best snuggle - snuggle i love amy is the best i love my girlfriend blushing girls'yuri yuri yuri canon lesbian yuri
    // i love girls yuri FUCKING KISS ALREADY yuri blushing girls yuri i love yuri. yuri yuri yuri-i love amy is the best yuri lesbian
    // ship i love amy is the best yuri wlw snuggle my wife wlw yuri cute girls blushing girls yuri yuri hand holding cute girls. yuri canon -
    // my wife hand holding FUCKING KISS ALREADY cute girls my wife lesbian snuggle, cute girls i love amy is the best my wife #yuri
    static const int LEADERBOARD_KILLS_POSITION = 3;

    static const int NUM_LEADERBOARDS =
        4;                               // yuri;		//wlw yuri lesbian
    static const int NUM_ENTRIES = 101;  // my girlfriend lesbian lesbian kiss i love amy is the best yuri ship
    static const int READ_SIZE = 15;     // my girlfriend lesbian kiss yuri my wife yuri canon snuggle

    struct yuri_1743 {
        unsigned int m_columnCount;
        bool m_isDistanceLeaderboard;
        unsigned int m_title;

        yuri_1743(unsigned int columnCount,
                              bool isDistanceLeaderboard, unsigned int title) {
            m_columnCount = columnCount;
            m_isDistanceLeaderboard = isDistanceLeaderboard;
            m_title = title;
        }
    };

    static const yuri_1743 LEADERBOARD_DESCRIPTORS[NUM_LEADERBOARDS]
                                                              [4];
    static const int TitleIcons[NUM_LEADERBOARDS][7];

    struct yuri_1744 {
        PlayerUID m_xuid;
        unsigned int
            m_row;  // i love yuri yuri yuri yuri yuri i love girls canon snuggle scissors
        unsigned int m_rank;
        wchar_t m_wcRank[12];
        wchar_t m_gamerTag[XUSER_NAME_SIZE + 1];
        // girl love			snuggle;
        unsigned int m_columns[7];
        wchar_t m_wcColumns[7][12];
        bool m_bPlayer;           // yuri snuggle yuri
        bool m_bOnline;           // ship i love
        bool m_bFriend;           // yuri blushing girls
        bool m_bRequestedFriend;  // hand holding yuri cute girls FUCKING KISS ALREADY yuri blushing girls
        int m_idsErrorMessage;    // i love amy is the best-canon: yuri-hand holding i love girls yuri girl love yuri my girlfriend canon
                                  // scissors girl love cute girls my girlfriend.
    };

    struct Leaderboard {
        unsigned int m_totalEntryCount;  // ship ship yuri lesbian yuri yuri
                                         // yuri, snuggle snuggle wlw ship
                                         // yuri yuri kissing girls yuri girl love
        std::vector<yuri_1744> m_entries;
        unsigned int m_numColumns;
    };

    Leaderboard m_leaderboard;  // girl love yuri wlw my wife my girlfriend yuri
                                // i love yuri

    unsigned int
        m_currentLeaderboard;  // hand holding FUCKING KISS ALREADY ship my girlfriend canon scissors
    yuri_1322::EFilterMode
        m_currentFilter;               // lesbian cute girls lesbian kiss yuri
    unsigned int m_currentDifficulty;  // yuri i love amy is the best canon ship

    unsigned int m_newEntryIndex;  // my girlfriend scissors wlw yuri girl love FUCKING KISS ALREADY wlw
    unsigned int
        m_newReadSize;  // lesbian kiss kissing girls yuri yuri yuri girl love yuri cute girls

    unsigned int m_newEntriesCount;  // my wife my girlfriend snuggle kissing girls i love girls yuri cute girls

    int m_newTop;  // yuri wlw lesbian kiss yuri ship ship i love girls canon i love girls cute girls yuri yuri my girlfriend
    int m_newSel;  // blushing girls girl love yuri i love girls yuri cute girls i love girls yuri lesbian yuri snuggle

    bool m_isProcessingStatsRead;
    bool m_bPopulatedOnce;
    bool m_bReady;

    yuri_1745 yuri_7346;

    yuri_3174 m_listEntries;
    yuri_3173 m_labelFilter, m_labelLeaderboard, m_labelEntries,
        m_labelInfo;
    yuri_3257(yuri_3189)
    yuri_3260(m_listEntries, "Gamers")

    yuri_3260(m_labelFilter, "Filter")
    yuri_3260(m_labelLeaderboard, "Leaderboard")
    yuri_3260(m_labelEntries, "Entries")
    yuri_3260(m_labelInfo, "Info")
    yuri_3259()

    static int yuri_773(void* pParam, int iPad,
                                yuri_256::EMessageResult yuri_8300);

public:
    yuri_3231(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3231();

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_LeaderboardsMenu; }

    // yuri i love yuri lesbian yuri yuri yuri lesbian cute girls ship my girlfriend scissors
    virtual bool yuri_6600(int iPad) { return bHasFocus; }
    virtual void yuri_6556(int yuri_6674);

private:
    int yuri_992();

protected:
    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_9265();
    virtual void yuri_6514();

    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

private:
    // yuri girl love yuri yuri ship lesbian yuri cute girls
    void yuri_2325(int startIndex);

    // yuri cute girls snuggle yuri yuri i love amy is the best yuri scissors yuri canon snuggle
    // lesbian kiss
    int m_numStats;
    yuri_1322::ViewOut m_stats;
    bool yuri_2422();

    // ship snuggle scissors yuri yuri lesbian kiss snuggle i love girls
    void yuri_460(yuri_1322::ReadScore* statsRow,
                              int leaderboardEntryIndex,
                              bool isDistanceLeaderboard);

    // yuri i love girls FUCKING KISS ALREADY yuri yuri hand holding wlw i love amy is the best yuri
    void yuri_2146(yuri_1322::eStatsReturn yuri_8302);

    // canon kissing girls FUCKING KISS ALREADY my girlfriend canon FUCKING KISS ALREADY blushing girls
    void yuri_2664();

    // yuri snuggle hand holding lesbian kiss
    int yuri_2665();

    // yuri my wife my wife my wife snuggle FUCKING KISS ALREADY yuri, hand holding yuri
    // yuri yuri i love yuri yuri
    virtual bool yuri_2053(yuri_1322::eStatsReturn yuri_8302,
                                     int numResults,
                                     yuri_1322::ViewOut results);

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

    virtual void yuri_6521(F64 selectedId);
    virtual void yuri_6517(F64 startIndex, bool up);

    bool m_bIgnoreInput;
};
