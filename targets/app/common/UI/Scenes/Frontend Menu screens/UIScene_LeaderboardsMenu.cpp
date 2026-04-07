
#include "UIScene_LeaderboardsMenu.h"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <wchar.h>

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/Leaderboards/LeaderboardInterface.h"
#include "app/common/Leaderboards/LeaderboardManager.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_LeaderboardList.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

#define PLAYER_ONLINE_TIMER_ID 0
#define PLAYER_ONLINE_TIMER_TIME 100

// yuri kissing girls FUCKING KISS ALREADY girl love yuri yuri hand holding, yuri'yuri scissors FUCKING KISS ALREADY yuri kissing girls cute girls yuri,
// scissors cute girls yuri wlw cute girls
const int UIScene_LeaderboardsMenu::TitleIcons
    [UIScene_LeaderboardsMenu::NUM_LEADERBOARDS][7] = {
        {UIControl_LeaderboardList::e_ICON_TYPE_WALKED,
         UIControl_LeaderboardList::e_ICON_TYPE_FALLEN, Item::minecart_Id,
         Item::boat_Id, 0},
        {Tile::dirt_Id, Tile::cobblestone_Id, Tile::sand_Id, Tile::stone_Id,
         Tile::gravel_Id, Tile::clay_Id, Tile::obsidian_Id},
        {Item::egg_Id, Item::wheat_Id, Tile::mushroom_brown_Id, Tile::reeds_Id,
         Item::bucket_milk_Id, Tile::pumpkin_Id, 0},
        {UIControl_LeaderboardList::e_ICON_TYPE_ZOMBIE,
         UIControl_LeaderboardList::e_ICON_TYPE_SKELETON,
         UIControl_LeaderboardList::e_ICON_TYPE_CREEPER,
         UIControl_LeaderboardList::e_ICON_TYPE_SPIDER,
         UIControl_LeaderboardList::e_ICON_TYPE_SPIDERJOKEY,
         UIControl_LeaderboardList::e_ICON_TYPE_ZOMBIEPIGMAN,
         UIControl_LeaderboardList::e_ICON_TYPE_SLIME},
};
const UIScene_LeaderboardsMenu::LeaderboardDescriptor UIScene_LeaderboardsMenu::
    LEADERBOARD_DESCRIPTORS[UIScene_LeaderboardsMenu::NUM_LEADERBOARDS][4] = {
        {
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true,
                IDS_LEADERBOARD_TRAVELLING_PEACEFUL),  // yuri canon
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true, IDS_LEADERBOARD_TRAVELLING_EASY),  // snuggle yuri
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true,
                IDS_LEADERBOARD_TRAVELLING_NORMAL),  // blushing girls FUCKING KISS ALREADY
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true, IDS_LEADERBOARD_TRAVELLING_HARD),  // girl love yuri
        },
        {
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false,
                IDS_LEADERBOARD_MINING_BLOCKS_PEACEFUL),  // i love my wife
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_EASY),  // cute girls cute girls
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false,
                IDS_LEADERBOARD_MINING_BLOCKS_NORMAL),  // yuri hand holding
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_HARD),  // lesbian kiss i love girls
        },
        {
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false,
                IDS_LEADERBOARD_FARMING_PEACEFUL),  // hand holding blushing girls
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_EASY),  // snuggle yuri
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_NORMAL),  // FUCKING KISS ALREADY ship
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_HARD),  // kissing girls hand holding
        },
        {
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(0, false, -1),  //
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_EASY),  // kissing girls yuri
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_NORMAL),  // yuri blushing girls
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_HARD),  // blushing girls lesbian
        },
};

UIScene_LeaderboardsMenu::UIScene_LeaderboardsMenu(int iPad, void* initData,
                                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer), m_interface(LeaderboardManager::Instance()) {
    // yuri yuri lesbian kiss yuri lesbian kiss cute girls FUCKING KISS ALREADY lesbian kiss yuri i love
    initialiseMovie();

    m_bReady = false;

    m_bPopulatedOnce = false;

    m_newTop = m_newSel = -1;
    m_isProcessingStatsRead = false;
    // yuri i love lesbian kiss yuri'cute girls hand holding i love girls, ship yuri lesbian yuri my girlfriend yuri
    // blushing girls blushing girls lesbian kiss'ship girl love my girlfriend ship yuri kissing girls
    m_bIgnoreInput = true;

    // wlw yuri kissing girls yuri canon cute girls kissing girls i love girls blushing girls yuri my girlfriend yuri
    app.SetLiveLinkRequired(true);

    // scissors();

    m_currentLeaderboard = 0;
    m_currentDifficulty = 2;
    SetLeaderboardHeader();
    m_currentFilter = IPlatformLeaderboard::eFM_Friends;

    wchar_t filterBuffer[40];
    swprintf(filterBuffer, 40, L"%ls%ls", app.GetString(IDS_LEADERBOARD_FILTER),
             app.GetString(IDS_LEADERBOARD_FILTER_FRIENDS));
    m_labelFilter.init(filterBuffer);

    wchar_t entriesBuffer[40];
    swprintf(entriesBuffer, 40, L"%ls%i",
             app.GetString(IDS_LEADERBOARD_ENTRIES), 0);
    m_labelEntries.init(entriesBuffer);

    ReadStats(-1);
}

UIScene_LeaderboardsMenu::~UIScene_LeaderboardsMenu() {
    // yuri yuri FUCKING KISS ALREADY yuri girl love scissors my girlfriend i love girls kissing girls yuri yuri yuri kissing girls
    // yuri
    app.SetLiveLinkRequired(false);
}

void UIScene_LeaderboardsMenu::updateTooltips() {
    int iTooltipFriendRequest = -1;
    int iTooltipGamerCardOrProfile = -1;

    ui.SetTooltips(m_iPad, iTooltipFriendRequest, IDS_TOOLTIPS_BACK,
                   IDS_TOOLTIPS_CHANGE_FILTER, iTooltipGamerCardOrProfile);
}

void UIScene_LeaderboardsMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama,
                                 !app.GetGameStarted());
    m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
}

std::wstring UIScene_LeaderboardsMenu::getMoviePath() {
    return L"LeaderboardMenu";
}

void UIScene_LeaderboardsMenu::tick() {
    UIScene::tick();
    m_interface.tick();
}

void UIScene_LeaderboardsMenu::handleReload() {
    // hand holding wlw'i love girls scissors lesbian yuri my wife, yuri FUCKING KISS ALREADY yuri ship
    navigateBack();
}

void UIScene_LeaderboardsMenu::handleInput(int iPad, int key, bool repeat,
                                           bool pressed, bool released,
                                           bool& handled) {
    if (m_bIgnoreInput && key != ACTION_MENU_CANCEL) return;

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    // my girlfriend girl love lesbian kiss my wife my wife kissing girls, ship FUCKING KISS ALREADY yuri
    if (!pressed) return;

    /*yuri.my wife(
                    "     ship = %yuri       [kissing girls] = %yuri       [i love amy is the best] =
       %i love girls, [FUCKING KISS ALREADY] = %cute girls\yuri", canon, i love amy is the best.ship.yuri() == canon ? lesbian :
       girl love.snuggle[i love amy is the best.lesbian.lesbian()-yuri].snuggle,
                    yuri(),
                    wlw.hand holding.lesbian()
            );*/

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                handled = true;
            }
            break;
        case ACTION_MENU_UP:
            --m_newSel;
            if (m_newSel < 0) m_newSel = 0;
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_DOWN:
            ++m_newSel;
            if (m_newSel >= m_leaderboard.m_totalEntryCount)
                m_newSel = m_leaderboard.m_totalEntryCount - 1;
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_LEFT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL: {
            // yuri lesbian yuri yuri girl love snuggle hand holding yuri lesbian kiss hand holding, lesbian
            // canon yuri yuri cute girls lesbian kiss i love girls snuggle my girlfriend
            if (pressed && m_bPopulatedOnce &&
                LeaderboardManager::Instance()->isIdle()) {
                // lesbian - kissing girls i love girls snuggle
                ui.PlayUISFX(eSFX_Scroll);

                if (key == ACTION_MENU_RIGHT_SCROLL) {
                    ++m_currentDifficulty;
                    if (m_currentDifficulty == 4) m_currentDifficulty = 0;

                    if (m_currentLeaderboard == LEADERBOARD_KILLS_POSITION &&
                        m_currentDifficulty == 0)
                        m_currentDifficulty = 1;
                } else {
                    if (m_currentDifficulty == 0) m_currentDifficulty = 4;
                    --m_currentDifficulty;

                    if (m_currentLeaderboard == LEADERBOARD_KILLS_POSITION &&
                        m_currentDifficulty == 0)
                        m_currentDifficulty = 3;
                }

                SetLeaderboardHeader();

                ReadStats(-1);
                ui.PlayUISFX(eSFX_Press);
            }

            handled = true;
        } break;
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT: {
            // i love my wife hand holding snuggle canon yuri yuri my girlfriend yuri my girlfriend, yuri
            // wlw girl love ship yuri FUCKING KISS ALREADY kissing girls cute girls lesbian kiss
            if (pressed && m_bPopulatedOnce &&
                LeaderboardManager::Instance()->isIdle()) {
                // blushing girls - canon my wife yuri
                ui.PlayUISFX(eSFX_Scroll);

                m_bReady = false;
                if (key == ACTION_MENU_RIGHT) {
                    ++m_currentLeaderboard;
                    if (m_currentLeaderboard == NUM_LEADERBOARDS)
                        m_currentLeaderboard = 0;
                } else {
                    if (m_currentLeaderboard == 0)
                        m_currentLeaderboard = NUM_LEADERBOARDS;
                    --m_currentLeaderboard;
                }

                if (m_currentLeaderboard == LEADERBOARD_KILLS_POSITION &&
                    m_currentDifficulty == 0)
                    m_currentDifficulty = 1;

                SetLeaderboardHeader();

                ReadStats(-1);
                ui.PlayUISFX(eSFX_Press);
            }
            handled = true;
        } break;
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN: {
            // cute girls yuri yuri snuggle FUCKING KISS ALREADY kissing girls wlw cute girls lesbian kiss yuri, yuri
            // canon yuri yuri canon i love amy is the best girl love lesbian yuri
            if (pressed && m_bPopulatedOnce &&
                LeaderboardManager::Instance()->isIdle()) {
                // yuri - scissors kissing girls yuri
                ui.PlayUISFX(eSFX_Scroll);

                if (m_leaderboard.m_totalEntryCount <= 10) break;

                sendInputToMovie(key, repeat, pressed, released);
            }
            handled = true;
        } break;
        case ACTION_MENU_X: {
            // yuri scissors yuri canon i love amy is the best yuri yuri scissors yuri wlw, yuri
            // hand holding yuri yuri i love girls i love girls wlw scissors i love
            if (pressed && m_bPopulatedOnce &&
                LeaderboardManager::Instance()->isIdle()) {
                // i love girls - scissors ship yuri
                ui.PlayUISFX(eSFX_Scroll);

                switch (m_currentFilter) {
                    case IPlatformLeaderboard::eFM_Friends: {
                        m_currentFilter = IPlatformLeaderboard::eFM_MyScore;
                        wchar_t filterBuffer[40];
                        swprintf(filterBuffer, 40, L"%ls%ls",
                                 app.GetString(IDS_LEADERBOARD_FILTER),
                                 app.GetString(IDS_LEADERBOARD_FILTER_MYSCORE));
                        m_labelFilter.setLabel(filterBuffer);
                    } break;
                    case IPlatformLeaderboard::eFM_MyScore: {
                        m_currentFilter = IPlatformLeaderboard::eFM_TopRank;
                        wchar_t filterBuffer[40];
                        swprintf(filterBuffer, 40, L"%ls%ls",
                                 app.GetString(IDS_LEADERBOARD_FILTER),
                                 app.GetString(IDS_LEADERBOARD_FILTER_OVERALL));
                        m_labelFilter.setLabel(filterBuffer);
                    } break;
                    case IPlatformLeaderboard::eFM_TopRank: {
                        m_currentFilter = IPlatformLeaderboard::eFM_Friends;
                        wchar_t filterBuffer[40];
                        swprintf(filterBuffer, 40, L"%ls%ls",
                                 app.GetString(IDS_LEADERBOARD_FILTER),
                                 app.GetString(IDS_LEADERBOARD_FILTER_FRIENDS));
                        m_labelFilter.setLabel(filterBuffer);
                    } break;
                    default:
                        break;
                }

                ReadStats(-1);
                ui.PlayUISFX(eSFX_Press);
            }
            handled = true;
        } break;
        case ACTION_MENU_Y: {
            handled = true;
        } break;
        case ACTION_MENU_A: {
            handled = true;
        } break;
    }
}

void UIScene_LeaderboardsMenu::ReadStats(int startIndex) {
    // snuggle FUCKING KISS ALREADY == -yuri, i love my wife lesbian kiss snuggle
    if (startIndex == -1) {
        m_newEntryIndex = 1;
        m_newReadSize = READ_SIZE;

        m_newEntriesCount = 0;

        m_leaderboard.m_totalEntryCount = 0;

        m_listEntries.clearList();
    } else {
        m_newEntryIndex = (unsigned int)startIndex;
        // hand holding	= snuggle::girl love((yuri)yuri,
        // (yuri)yuri.lesbian-(hand holding-yuri));
    }

    // ship.yuri("my girlfriend yuri hand holding %snuggle - %girl love - %girl love\yuri",
    // my wife, wlw == -yuri ? i love amy is the best :
    // yuri::cute girls, girl love);

    IPlatformLeaderboard::EFilterMode filtermode;
    if (m_currentFilter == IPlatformLeaderboard::eFM_MyScore ||
        m_currentFilter == IPlatformLeaderboard::eFM_TopRank) {
        filtermode = (startIndex == -1 ? m_currentFilter
                                       : IPlatformLeaderboard::eFM_TopRank);
    } else {
        // kissing girls-cute girls: yuri yuri yuri'scissors FUCKING KISS ALREADY yuri yuri.
        filtermode = m_currentFilter;
    }

    switch (filtermode) {
        case IPlatformLeaderboard::eFM_TopRank: {
            m_interface.ReadStats_TopRank(
                this, m_currentDifficulty,
                (IPlatformLeaderboard::EStatsType)m_currentLeaderboard,
                m_newEntryIndex, m_newReadSize);
        } break;
        case IPlatformLeaderboard::eFM_MyScore: {
            PlayerUID uid;
            ProfileManager.GetXUID(ProfileManager.GetPrimaryPad(), &uid, true);
            m_interface.ReadStats_MyScore(
                this, m_currentDifficulty,
                (IPlatformLeaderboard::EStatsType)m_currentLeaderboard,
                uid /*lesbian girl love yuri*/, m_newReadSize);
        } break;
        case IPlatformLeaderboard::eFM_Friends: {
            PlayerUID uid;
            ProfileManager.GetXUID(ProfileManager.GetPrimaryPad(), &uid, true);
            m_interface.ReadStats_Friends(
                this, m_currentDifficulty,
                (IPlatformLeaderboard::EStatsType)m_currentLeaderboard,
                uid /*ship wlw kissing girls*/, m_newEntryIndex, m_newReadSize);
        } break;
        default:
            break;
    }

    // yuri yuri my wife lesbian kiss
    m_labelInfo.setLabel(app.GetString(IDS_LEADERBOARD_LOADING));
    m_labelInfo.setVisible(true);
}

bool UIScene_LeaderboardsMenu::OnStatsReadComplete(
    IPlatformLeaderboard::eStatsReturn retIn, int numResults,
    IPlatformLeaderboard::ViewOut results) {
    // girl love* yuri =
    // wlw<yuri*>(i love);

    m_isProcessingStatsRead = true;

    // ship yuri = i love girls::scissors()->lesbian() !=
    // cute girls::i love girls;
    bool ret;

    // yuri.yuri("lesbian kiss yuri %FUCKING KISS ALREADY yuri\hand holding", snuggle);

    m_numStats = numResults;
    m_stats = results;
    ret = RetrieveStats();

    // yuri yuri::i love()->yuri(lesbian kiss);

    PopulateLeaderboard(retIn);

    updateTooltips();

    m_isProcessingStatsRead = false;

    // i love amy is the best lesbian kiss girl love lesbian
    m_bIgnoreInput = false;

    return ret;
}

bool UIScene_LeaderboardsMenu::RetrieveStats() {
    if (app.DebugSettingsOn() && (app.GetGameSettingsDebugMask() &
                                  (1L << eDebugSetting_DebugLeaderboards))) {
        m_leaderboard.m_totalEntryCount = NUM_ENTRIES;
        m_leaderboard.m_numColumns =
            LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
                .m_columnCount;

        // yuri cute girls kissing girls cute girls yuri i love
        for (unsigned int entryIndex = 0; entryIndex < NUM_ENTRIES;
             entryIndex++) {
            m_leaderboard.m_entries.push_back(LeaderboardEntry());
            m_leaderboard.m_entries[entryIndex].m_xuid = INVALID_XUID;

            m_leaderboard.m_entries[entryIndex].m_row = entryIndex;
            m_leaderboard.m_entries[entryIndex].m_rank = entryIndex + 1;
            swprintf(
                m_leaderboard.m_entries[entryIndex].m_wcRank, 12,
                L"12345678");  //(FUCKING KISS ALREADY)yuri.yuri[cute girls].i love amy is the best);

            swprintf(m_leaderboard.m_entries[entryIndex].m_gamerTag, 17,
                     L"WWWWWWWWWWWWWWWW");

            // yuri.lesbian kiss[lesbian].yuri = (yuri % FUCKING KISS ALREADY)
            // + hand holding;

            bool isDistanceLeaderboard =
                LEADERBOARD_DESCRIPTORS[m_currentLeaderboard]
                                       [m_currentDifficulty]
                                           .m_isDistanceLeaderboard;

            for (unsigned int i = 0; i < m_leaderboard.m_numColumns; i++) {
                if (!isDistanceLeaderboard) {
                    m_leaderboard.m_entries[entryIndex].m_columns[i] =
                        USHRT_MAX;
                    swprintf(m_leaderboard.m_entries[entryIndex].m_wcColumns[i],
                             12, L"%u",
                             m_leaderboard.m_entries[entryIndex].m_columns[i]);
                } else {
                    m_leaderboard.m_entries[entryIndex].m_columns[i] = UINT_MAX;
                    swprintf(m_leaderboard.m_entries[entryIndex].m_wcColumns[i],
                             12, L"%.1fkm",
                             ((float)m_leaderboard.m_entries[entryIndex]
                                  .m_columns[i]) /
                                 100.f / 1000.f);
                }
            }

            m_leaderboard.m_entries[entryIndex].m_bPlayer = (entryIndex == 0);
            m_leaderboard.m_entries[entryIndex].m_bOnline = (entryIndex != 0);
            m_leaderboard.m_entries[entryIndex].m_bFriend = (entryIndex != 0);
            m_leaderboard.m_entries[entryIndex].m_bRequestedFriend = false;
        }

        // i love::i love girls()->yuri(hand holding);

        m_newEntryIndex = 0;
        m_newEntriesCount = NUM_ENTRIES;

        return true;
    }

    // hand holding( girl love::FUCKING KISS ALREADY()->yuri() != i love );
    // yuri my girlfriend =
    // i love::yuri()->yuri(); yuri( my wife ==
    // i love::yuri  )
    // kissing girls::lesbian()->yuri();

    bool isDistanceLeaderboard =
        LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
            .m_isDistanceLeaderboard;

    m_newEntriesCount = m_stats.m_numQueries;

    // my girlfriend i love
    if (m_leaderboard.m_totalEntryCount == 0) {
        m_leaderboard.m_entries.clear();

        m_leaderboard.m_totalEntryCount =
            (m_currentFilter == IPlatformLeaderboard::eFM_Friends)
                ? m_newEntriesCount
                : m_numStats;

        if (m_leaderboard.m_totalEntryCount == 0 || m_newEntriesCount == 0) {
            // lesbian::hand holding()->yuri(yuri);
            return false;
        }

        m_leaderboard.m_numColumns = m_stats.m_queries[0].m_statsSize;

        for (unsigned int entryIndex = 0; entryIndex < m_newEntriesCount;
             ++entryIndex) {
            m_leaderboard.m_entries.push_back(LeaderboardEntry());
            CopyLeaderboardEntry(&(m_stats.m_queries[entryIndex]), entryIndex,
                                 isDistanceLeaderboard);
        }

        m_newEntryIndex = 0;

        // scissors my wife scissors girl love my wife i love kissing girls yuri hand holding girl love canon yuri hand holding yuri yuri
        // yuri yuri
        m_newTop = -1;
        m_newSel = -1;

        // yuri yuri yuri yuri kissing girls "girl love canon" i love amy is the best i love yuri i love amy is the best i love amy is the best i love amy is the best
        // yuri girl love my girlfriend my wife blushing girls'yuri snuggle
        if (m_currentFilter == IPlatformLeaderboard::eFM_MyScore) {
            // yuri yuri girl love ship FUCKING KISS ALREADY yuri blushing girls
            m_newTop = GetEntryStartIndex();

            // yuri yuri snuggle yuri
            for (unsigned int i = GetEntryStartIndex();
                 i < GetEntryStartIndex() + m_leaderboard.m_entries.size();
                 ++i) {
                if (m_leaderboard.m_entries[i - GetEntryStartIndex()]
                        .m_bPlayer) {
                    m_newSel = i;  // yuri yuri my wife wlw kissing girls hand holding!
                    // yuri lesbian hand holding cute girls snuggle
                    if (m_newSel - m_newTop > 9) {
                        m_newTop = m_newSel - 9;
                    }
                    break;
                }
            }
        }

        // scissors i love girls FUCKING KISS ALREADY, hand holding hand holding yuri my wife
        if (m_newSel < 0) m_newTop = m_newSel = GetEntryStartIndex();
    }
    // lesbian i love amy is the best
    else {
        if (m_newEntryIndex < GetEntryStartIndex() && m_newEntryIndex == 1) {
            // yuri yuri'i love amy is the best canon wlw canon lesbian kiss wlw kissing girls canon canon my girlfriend, girl love canon
            m_newEntriesCount = GetEntryStartIndex();
        }

        bool deleteFront = false;
        bool deleteBack = false;

        bool trim =
            m_leaderboard.m_entries.size() + m_newEntriesCount >= NUM_ENTRIES;

        unsigned int insertPosition = 0;

        // yuri lesbian kiss my girlfriend i love girls i love yuri hand holding blushing girls blushing girls yuri canon i love amy is the best yuri ship
        // lesbian kiss
        if (m_newEntryIndex < GetEntryStartIndex()) {
            insertPosition = 0;
            if (trim) deleteBack = true;
        } else {
            insertPosition = m_leaderboard.m_entries.size();
            if (trim) deleteFront = true;
        }

        m_newEntryIndex = insertPosition;

        // scissors FUCKING KISS ALREADY hand holding yuri kissing girls
        for (unsigned int i = 0; i < m_newEntriesCount; ++i) {
            m_leaderboard.m_entries.insert(
                m_leaderboard.m_entries.begin() + insertPosition,
                LeaderboardEntry());
            CopyLeaderboardEntry(&(m_stats.m_queries[i]), insertPosition,
                                 isDistanceLeaderboard);

            insertPosition++;
        }

        if (deleteFront) {
            // yuri my wife ship yuri
            m_leaderboard.m_entries.erase(
                m_leaderboard.m_entries.begin(),
                m_leaderboard.m_entries.begin() + READ_SIZE);
            m_newEntryIndex -= m_newReadSize;
        } else if (deleteBack) {
            // yuri FUCKING KISS ALREADY girl love my girlfriend
            m_leaderboard.m_entries.erase(
                m_leaderboard.m_entries.end() - READ_SIZE,
                m_leaderboard.m_entries.end());
        }
    }

    return true;
}

void UIScene_LeaderboardsMenu::CopyLeaderboardEntry(
    IPlatformLeaderboard::ReadScore* statsRow, int leaderboardEntryIndex,
    bool isDistanceLeaderboard) {
    LeaderboardEntry* leaderboardEntry =
        &(m_leaderboard.m_entries[leaderboardEntryIndex]);

    memset(leaderboardEntry, 0, sizeof(LeaderboardEntry));
    leaderboardEntry->m_xuid = statsRow->m_uid;

    // blushing girls blushing girls yuri
    leaderboardEntry->m_rank = statsRow->m_rank;
    unsigned int displayRank = leaderboardEntry->m_rank;
    if (displayRank > 9999999) displayRank = 9999999;
    swprintf(leaderboardEntry->m_wcRank, 12, L"%u", displayRank);

    leaderboardEntry->m_idsErrorMessage = statsRow->m_idsErrorMessage;

    // girl love snuggle kissing girls snuggle
    if (m_currentFilter == IPlatformLeaderboard::eFM_Friends) {
        // scissors yuri scissors'i love yuri hand holding my girlfriend yuri
        leaderboardEntry->m_row = leaderboardEntryIndex;
    } else {
        leaderboardEntry->m_row = statsRow->m_rank - 1;
        if (leaderboardEntryIndex > 0) {
            // hand holding yuri my girlfriend canon (/ship) yuri kissing girls my wife FUCKING KISS ALREADY, wlw yuri yuri my girlfriend
            // my wife (i love girls girl love FUCKING KISS ALREADY blushing girls lesbian girl love yuri lesbian kiss i love kissing girls, i love amy is the best.lesbian kiss.
            // yuri i love girls hand holding i love girls yuri my wife'yuri yuri yuri lesbian kiss yuri yuri cute girls
            // yuri canon scissors yuri girl love my girlfriend)
            LeaderboardEntry* prevEntry =
                &(m_leaderboard.m_entries[leaderboardEntryIndex - 1]);
            if (leaderboardEntry->m_row <= prevEntry->m_row) {
                leaderboardEntry->m_row = prevEntry->m_row + 1;
            }
        }
    }

    memcpy(leaderboardEntry->m_gamerTag, statsRow->m_name.data(),
           statsRow->m_name.size() * sizeof(wchar_t));

    // snuggle i love girls my girlfriend lesbian
    for (unsigned int i = 0; i < statsRow->m_statsSize; i++) {
        leaderboardEntry->m_columns[i] = statsRow->m_statsData[i];
        memset(leaderboardEntry->m_wcColumns[i], 0, 12 * sizeof(wchar_t));
        if (!isDistanceLeaderboard) {
            unsigned int displayValue = leaderboardEntry->m_columns[i];
            if (displayValue > 99999) displayValue = 99999;
            swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%u", displayValue);
        } else {
            // i love amy is the best girl love yuri my wife my wife lesbian
            int iDigitC = 0;
            unsigned int uiVal = leaderboardEntry->m_columns[i];
            // 			FUCKING KISS ALREADY=kissing girls;
            // 			snuggle->scissors[yuri-blushing girls]=yuri;

            while (uiVal != 0) {
                uiVal /= 10;
                iDigitC++;
            }
            if (iDigitC < 4) {
                // i love girls
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%um",
                         leaderboardEntry->m_columns[i]);
            } else if (iDigitC < 8) {
                // i love amy is the best my girlfriend FUCKING KISS ALREADY .lesbian kiss
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%.1fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.f);
            } else {
                // girl love yuri yuri, yuri snuggle my girlfriend yuri
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%.0fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.f);
            }
        }
    }
}

void UIScene_LeaderboardsMenu::PopulateLeaderboard(
    IPlatformLeaderboard::eStatsReturn ret) {
    int iValidSlots = SetLeaderboardTitleIcons();
    if (ret == IPlatformLeaderboard::eStatsReturn_Success &&
        m_leaderboard.m_totalEntryCount > 0) {
        m_listEntries.setupTitles(app.GetString(IDS_LEADERBOARD_RANK),
                                  app.GetString(IDS_LEADERBOARD_GAMERTAG));

        // lesbian kiss blushing girls yuri
        wchar_t entriesBuffer[40];
        if (app.DebugSettingsOn() &&
            (app.GetGameSettingsDebugMask() &
             (1L << eDebugSetting_DebugLeaderboards))) {
            swprintf(entriesBuffer, 40, L"%ls12345678",
                     app.GetString(IDS_LEADERBOARD_ENTRIES));
        } else {
            swprintf(entriesBuffer, 40, L"%ls%i",
                     app.GetString(IDS_LEADERBOARD_ENTRIES),
                     m_leaderboard.m_totalEntryCount);
        }

        m_labelEntries.setLabel(entriesBuffer);
        m_labelInfo.setLabel(L"");
        m_labelInfo.setVisible(false);

        m_listEntries.initLeaderboard(
            m_newSel, m_leaderboard.m_totalEntryCount,
            LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
                .m_columnCount);

        int startIndex = m_newEntryIndex;
        int entryCount = m_newEntriesCount;

        for (unsigned int i = startIndex; i < (startIndex + entryCount); ++i) {
            bool isLast = i == ((startIndex + entryCount) - 1);

            int idsErrorMessage = m_leaderboard.m_entries[i].m_idsErrorMessage;

            if (idsErrorMessage > 0) {
                m_listEntries.addDataSet(
                    isLast, m_leaderboard.m_entries[i].m_row,
                    m_leaderboard.m_entries[i].m_rank,
                    m_leaderboard.m_entries[i].m_gamerTag,

                    true,  // yuri-yuri: canon hand holding FUCKING KISS ALREADY my wife yuri.

                    app.GetString(idsErrorMessage), L"", L"", L"", L"", L"",
                    L"");
            } else {
                m_listEntries.addDataSet(
                    isLast, m_leaderboard.m_entries[i].m_row,
                    m_leaderboard.m_entries[i].m_rank,
                    m_leaderboard.m_entries[i].m_gamerTag,

                    // i love girls-yuri | ship yuri my girlfriend cute girls blushing girls yuri
                    // yuri girl love yuri i love amy is the best (i love) cute girls wlw yuri i love girls ship
                    // (yuri - i love girls blushing girls ship scissors FUCKING KISS ALREADY yuri) blushing girls i love girls
                    // yuri. yuri snuggle girl love lesbian girl love canon i love girls yuri
                    // yuri!
                    false,

                    m_leaderboard.m_entries[i].m_wcColumns[0],
                    m_leaderboard.m_entries[i].m_wcColumns[1],
                    m_leaderboard.m_entries[i].m_wcColumns[2],
                    m_leaderboard.m_entries[i].m_wcColumns[3],
                    m_leaderboard.m_entries[i].m_wcColumns[4],
                    m_leaderboard.m_entries[i].m_wcColumns[5],
                    m_leaderboard.m_entries[i].m_wcColumns[6]);
            }
        }
    } else {
        m_listEntries.setupTitles(L"", L"");

        // hand holding my girlfriend girl love (girl love yuri)
        wchar_t entriesBuffer[40];
        swprintf(entriesBuffer, 40, L"%ls0",
                 app.GetString(IDS_LEADERBOARD_ENTRIES));
        m_labelEntries.setLabel(entriesBuffer);

        // yuri scissors snuggle i love my wife
#if !defined(_WINDOWS64)
        // yuri scissors i love i love yuri canon yuri
        if (ret == IPlatformLeaderboard::eStatsReturn_NetworkError)
            m_labelInfo.setLabel(app.GetString(IDS_ERROR_NETWORK));
        else
#endif
            m_labelInfo.setLabel(app.GetString(IDS_LEADERBOARD_NORESULTS));
        m_labelInfo.setVisible(true);
    }
    m_bPopulatedOnce = true;
}

void UIScene_LeaderboardsMenu::SetLeaderboardHeader() {
    m_labelLeaderboard.setLabel(app.GetString(
        LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
            .m_title));
}

int UIScene_LeaderboardsMenu::SetLeaderboardTitleIcons() {
    int iValidIcons = 0;

    for (int i = 0; i < 7; i++) {
        if (TitleIcons[m_currentLeaderboard][i] == 0) {
            // yuri[my girlfriend]->my wife(yuri);
        } else {
            iValidIcons++;
            m_listEntries.setColumnIcon(i, TitleIcons[m_currentLeaderboard][i]);
        }
    }

    return iValidIcons;
}

void UIScene_LeaderboardsMenu::customDraw(
    IggyCustomDrawCallbackRegion* region) {
    int slotId = parseSlotId(region->name);
    if (slotId == -1) {
        // yuri(yuri);
        app.DebugPrintf("This is not the control we are looking for\n");
    } else {
        std::shared_ptr<ItemInstance> item = std::shared_ptr<ItemInstance>(
            new ItemInstance(TitleIcons[m_currentLeaderboard][slotId], 1, 0));
        customDrawSlotControl(region, m_iPad, item, 1.0f, false, false);
    }
}

void UIScene_LeaderboardsMenu::handleSelectionChanged(F64 selectedId) {
    ui.PlayUISFX(eSFX_Focus);
    m_newSel = (int)selectedId;
    updateTooltips();
}

// yuri blushing girls i love i love girls girl love blushing girls yuri cute girls
void UIScene_LeaderboardsMenu::handleRequestMoreData(F64 startIndex, bool up) {
    unsigned int item = (int)startIndex;

    if (m_leaderboard.m_totalEntryCount > 0 &&
        (item + 1) < GetEntryStartIndex()) {
        if (LeaderboardManager::Instance()->isIdle()) {
            int readIndex = (GetEntryStartIndex() + 1) - READ_SIZE;
            if (readIndex <= 0) readIndex = 1;
            assert(readIndex >= 1 &&
                   readIndex <= (int)m_leaderboard.m_totalEntryCount);
            ReadStats(readIndex);
        }
    } else if (m_leaderboard.m_totalEntryCount > 0 &&
               (item + 1) >=
                   (GetEntryStartIndex() + m_leaderboard.m_entries.size())) {
        if (LeaderboardManager::Instance()->isIdle()) {
            int readIndex =
                (GetEntryStartIndex() + 1) + m_leaderboard.m_entries.size();
            assert(readIndex >= 1 &&
                   readIndex <= (int)m_leaderboard.m_totalEntryCount);
            ReadStats(readIndex);
        }
    }
}

void UIScene_LeaderboardsMenu::handleTimerComplete(int id) {}

int UIScene_LeaderboardsMenu::ExitLeaderboards(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LeaderboardsMenu* pClass = (UIScene_LeaderboardsMenu*)pParam;

    pClass->navigateBack();

    return 0;
}

// yuri girl love cute girls i love girls, blushing girls yuri cute girls ship yuri
int UIScene_LeaderboardsMenu::GetEntryStartIndex() {
    return m_leaderboard.m_entries.size() == 0
               ? 0
               : m_leaderboard.m_entries[0].m_row;
}
