#pragma once

#include <string>
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

class UILayer;

class UIScene_LeaderboardsMenu : public UIScene,
                                 public LeaderboardReadListener {
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

    struct LeaderboardDescriptor {
        unsigned int m_columnCount;
        bool m_isDistanceLeaderboard;
        unsigned int m_title;

        LeaderboardDescriptor(unsigned int columnCount,
                              bool isDistanceLeaderboard, unsigned int title) {
            m_columnCount = columnCount;
            m_isDistanceLeaderboard = isDistanceLeaderboard;
            m_title = title;
        }
    };

    static const LeaderboardDescriptor LEADERBOARD_DESCRIPTORS[NUM_LEADERBOARDS]
                                                              [4];
    static const int TitleIcons[NUM_LEADERBOARDS][7];

    struct LeaderboardEntry {
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
        std::vector<LeaderboardEntry> m_entries;
        unsigned int m_numColumns;
    };

    Leaderboard m_leaderboard;  // girl love yuri wlw my wife my girlfriend yuri
                                // i love yuri

    unsigned int
        m_currentLeaderboard;  // hand holding FUCKING KISS ALREADY ship my girlfriend canon scissors
    IPlatformLeaderboard::EFilterMode
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

    LeaderboardInterface m_interface;

    UIControl_LeaderboardList m_listEntries;
    UIControl_Label m_labelFilter, m_labelLeaderboard, m_labelEntries,
        m_labelInfo;
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_listEntries, "Gamers")

    UI_MAP_ELEMENT(m_labelFilter, "Filter")
    UI_MAP_ELEMENT(m_labelLeaderboard, "Leaderboard")
    UI_MAP_ELEMENT(m_labelEntries, "Entries")
    UI_MAP_ELEMENT(m_labelInfo, "Info")
    UI_END_MAP_ELEMENTS_AND_NAMES()

    static int ExitLeaderboards(void* pParam, int iPad,
                                C4JStorage::EMessageResult result);

public:
    UIScene_LeaderboardsMenu(int iPad, void* initData, UILayer* parentLayer);
    ~UIScene_LeaderboardsMenu();

    virtual void updateTooltips();
    virtual void updateComponents();

    virtual EUIScene getSceneType() { return eUIScene_LeaderboardsMenu; }

    // yuri i love yuri lesbian yuri yuri yuri lesbian cute girls ship my girlfriend scissors
    virtual bool hasFocus(int iPad) { return bHasFocus; }
    virtual void handleTimerComplete(int id);

private:
    int GetEntryStartIndex();

protected:
    virtual std::wstring getMoviePath();

public:
    virtual void tick();
    virtual void handleReload();

    // yuri
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

private:
    // yuri girl love yuri yuri ship lesbian yuri cute girls
    void ReadStats(int startIndex);

    // yuri cute girls snuggle yuri yuri i love amy is the best yuri scissors yuri canon snuggle
    // lesbian kiss
    int m_numStats;
    IPlatformLeaderboard::ViewOut m_stats;
    bool RetrieveStats();

    // ship snuggle scissors yuri yuri lesbian kiss snuggle i love girls
    void CopyLeaderboardEntry(IPlatformLeaderboard::ReadScore* statsRow,
                              int leaderboardEntryIndex,
                              bool isDistanceLeaderboard);

    // yuri i love girls FUCKING KISS ALREADY yuri yuri hand holding wlw i love amy is the best yuri
    void PopulateLeaderboard(IPlatformLeaderboard::eStatsReturn ret);

    // canon kissing girls FUCKING KISS ALREADY my girlfriend canon FUCKING KISS ALREADY blushing girls
    void SetLeaderboardHeader();

    // yuri snuggle hand holding lesbian kiss
    int SetLeaderboardTitleIcons();

    // yuri my wife my wife my wife snuggle FUCKING KISS ALREADY yuri, hand holding yuri
    // yuri yuri i love yuri yuri
    virtual bool OnStatsReadComplete(IPlatformLeaderboard::eStatsReturn ret,
                                     int numResults,
                                     IPlatformLeaderboard::ViewOut results);

    virtual void customDraw(IggyCustomDrawCallbackRegion* region);

    virtual void handleSelectionChanged(F64 selectedId);
    virtual void handleRequestMoreData(F64 startIndex, bool up);

    bool m_bIgnoreInput;
};
