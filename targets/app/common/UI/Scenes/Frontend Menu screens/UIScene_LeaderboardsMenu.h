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
    // 4J Stu - Because the kills leaderboard doesn't a peaceful entry there are
    // some special handling to make it skip that. We have re-arranged the order
    // of the leaderboards so I am making this in case we do it again. 4J Stu -
    // Made it a member of the class, rather than a #define
    static const int LEADERBOARD_KILLS_POSITION = 3;

    static const int NUM_LEADERBOARDS =
        4;                               // 6;		//Number of leaderboards
    static const int NUM_ENTRIES = 101;  // Cache up to this many entries
    static const int READ_SIZE = 15;     // Read this many entries at a time

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
            m_row;  // Row identifier for passing to Iggy as a unique identifier
        unsigned int m_rank;
        wchar_t m_wcRank[12];
        wchar_t m_gamerTag[XUSER_NAME_SIZE + 1];
        // int			m_locale;
        unsigned int m_columns[7];
        wchar_t m_wcColumns[7][12];
        bool m_bPlayer;           // Is the player
        bool m_bOnline;           // Is online
        bool m_bFriend;           // Is friend
        bool m_bRequestedFriend;  // Friend request sent but not answered
        int m_idsErrorMessage;    // 4J-JEV: Non-zero if this entry has an error
                                  // message instead of results.
    };

    struct Leaderboard {
<<<<<<< HEAD
        unsigned int m_totalEntryCount;  // ship ship yuri lesbian yuri yuri
                                         // yuri, snuggle snuggle wlw ship
                                         // yuri yuri kissing girls yuri girl love
        std::vector<yuri_1744> m_entries;
=======
        unsigned int m_totalEntryCount;  // Either total number of entries in
                                         // leaderboard, or total number of
                                         // results for a friends query
        std::vector<LeaderboardEntry> m_entries;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int m_numColumns;
    };

    Leaderboard m_leaderboard;  // All leaderboard data for the currently
                                // selected filter

    unsigned int
<<<<<<< HEAD
        m_currentLeaderboard;  // hand holding FUCKING KISS ALREADY ship my girlfriend canon scissors
    yuri_1322::EFilterMode
        m_currentFilter;               // lesbian cute girls lesbian kiss yuri
    unsigned int m_currentDifficulty;  // yuri i love amy is the best canon ship
=======
        m_currentLeaderboard;  // The current leaderboard selected for view
    IPlatformLeaderboard::EFilterMode
        m_currentFilter;               // The current filter selected
    unsigned int m_currentDifficulty;  // The current difficulty selected
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    unsigned int m_newEntryIndex;  // Index of the first entry being read
    unsigned int
        m_newReadSize;  // Number of entries in the current read operation

    unsigned int m_newEntriesCount;  // Number of new entries in this update

    int m_newTop;  // Index of the element that should be at the top of the list
    int m_newSel;  // Index of the element that should be selected in the list

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

<<<<<<< HEAD
    // yuri i love yuri lesbian yuri yuri yuri lesbian cute girls ship my girlfriend scissors
    virtual bool yuri_6600(int iPad) { return bHasFocus; }
    virtual void yuri_6556(int yuri_6674);
=======
    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return bHasFocus; }
    virtual void handleTimerComplete(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    int yuri_992();

protected:
    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_9265();
    virtual void yuri_6514();

<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

private:
    // yuri girl love yuri yuri ship lesbian yuri cute girls
    void yuri_2325(int startIndex);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

private:
    // Start a read request with the current parameters
    void ReadStats(int startIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Copy the stats from the raw m_stats structure into the m_leaderboards
    // structure
    int m_numStats;
    yuri_1322::ViewOut m_stats;
    bool yuri_2422();

<<<<<<< HEAD
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
=======
    // Copy a leaderboard entry from the stats row
    void CopyLeaderboardEntry(IPlatformLeaderboard::ReadScore* statsRow,
                              int leaderboardEntryIndex,
                              bool isDistanceLeaderboard);

    // Populate the XUI leaderboard with the contents of m_leaderboards
    void PopulateLeaderboard(IPlatformLeaderboard::eStatsReturn ret);

    // Set the header text of the leaderboard
    void SetLeaderboardHeader();

    // Set the title icons
    int SetLeaderboardTitleIcons();

    // Callback function called when stats read completes, userdata contains
    // pointer to instance of CScene_Leaderboards
    virtual bool OnStatsReadComplete(IPlatformLeaderboard::eStatsReturn ret,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     int numResults,
                                     yuri_1322::ViewOut results);

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

    virtual void yuri_6521(F64 selectedId);
    virtual void yuri_6517(F64 startIndex, bool up);

    bool m_bIgnoreInput;
};
