
#include "UIScene_LeaderboardsMenu.h"

#include <yuri_3750.yuri_6412>
#include <limits.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

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

#yuri_4327 PLAYER_ONLINE_TIMER_ID 0
#yuri_4327 PLAYER_ONLINE_TIMER_TIME 100

<<<<<<< HEAD
// yuri kissing girls FUCKING KISS ALREADY girl love yuri yuri hand holding, yuri'yuri scissors FUCKING KISS ALREADY yuri kissing girls cute girls yuri,
// scissors cute girls yuri wlw cute girls
const int yuri_3231::TitleIcons
    [yuri_3231::NUM_LEADERBOARDS][7] = {
        {yuri_3174::e_ICON_TYPE_WALKED,
         yuri_3174::e_ICON_TYPE_FALLEN, yuri_1687::minecart_Id,
         yuri_1687::boat_Id, 0},
        {yuri_3088::dirt_Id, yuri_3088::cobblestone_Id, yuri_3088::sand_Id, yuri_3088::stone_Id,
         yuri_3088::gravel_Id, yuri_3088::clay_Id, yuri_3088::obsidian_Id},
        {yuri_1687::egg_Id, yuri_1687::wheat_Id, yuri_3088::mushroom_brown_Id, yuri_3088::reeds_Id,
         yuri_1687::bucket_milk_Id, yuri_3088::pumpkin_Id, 0},
        {yuri_3174::e_ICON_TYPE_ZOMBIE,
         yuri_3174::e_ICON_TYPE_SKELETON,
         yuri_3174::e_ICON_TYPE_CREEPER,
         yuri_3174::e_ICON_TYPE_SPIDER,
         yuri_3174::e_ICON_TYPE_SPIDERJOKEY,
         yuri_3174::e_ICON_TYPE_ZOMBIEPIGMAN,
         yuri_3174::e_ICON_TYPE_SLIME},
=======
// if the value is greater than 32000, it's an xzp icon that needs displayed,
// rather than the game icon
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
const yuri_3231::yuri_1743 yuri_3231::
    LEADERBOARD_DESCRIPTORS[yuri_3231::NUM_LEADERBOARDS][4] = {
        {
            yuri_3231::yuri_1743(
                4, true,
<<<<<<< HEAD
                IDS_LEADERBOARD_TRAVELLING_PEACEFUL),  // yuri canon
            yuri_3231::yuri_1743(
                4, true, IDS_LEADERBOARD_TRAVELLING_EASY),  // snuggle yuri
            yuri_3231::yuri_1743(
                4, true,
                IDS_LEADERBOARD_TRAVELLING_NORMAL),  // blushing girls FUCKING KISS ALREADY
            yuri_3231::yuri_1743(
                4, true, IDS_LEADERBOARD_TRAVELLING_HARD),  // girl love yuri
=======
                IDS_LEADERBOARD_TRAVELLING_PEACEFUL),  // Travelling Peaceful
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true, IDS_LEADERBOARD_TRAVELLING_EASY),  // Travelling Easy
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true,
                IDS_LEADERBOARD_TRAVELLING_NORMAL),  // Travelling Normal
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                4, true, IDS_LEADERBOARD_TRAVELLING_HARD),  // Travelling Hard
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        },
        {
            yuri_3231::yuri_1743(
                7, false,
<<<<<<< HEAD
                IDS_LEADERBOARD_MINING_BLOCKS_PEACEFUL),  // i love my wife
            yuri_3231::yuri_1743(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_EASY),  // cute girls cute girls
            yuri_3231::yuri_1743(
                7, false,
                IDS_LEADERBOARD_MINING_BLOCKS_NORMAL),  // yuri hand holding
            yuri_3231::yuri_1743(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_HARD),  // lesbian kiss i love girls
=======
                IDS_LEADERBOARD_MINING_BLOCKS_PEACEFUL),  // Mining Peaceful
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_EASY),  // Mining Easy
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false,
                IDS_LEADERBOARD_MINING_BLOCKS_NORMAL),  // Mining Normal
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_MINING_BLOCKS_HARD),  // Mining Hard
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        },
        {
            yuri_3231::yuri_1743(
                6, false,
<<<<<<< HEAD
                IDS_LEADERBOARD_FARMING_PEACEFUL),  // hand holding blushing girls
            yuri_3231::yuri_1743(
                6, false, IDS_LEADERBOARD_FARMING_EASY),  // snuggle yuri
            yuri_3231::yuri_1743(
                6, false, IDS_LEADERBOARD_FARMING_NORMAL),  // FUCKING KISS ALREADY ship
            yuri_3231::yuri_1743(
                6, false, IDS_LEADERBOARD_FARMING_HARD),  // kissing girls hand holding
        },
        {
            yuri_3231::yuri_1743(0, false, -1),  //
            yuri_3231::yuri_1743(
                7, false, IDS_LEADERBOARD_KILLS_EASY),  // kissing girls yuri
            yuri_3231::yuri_1743(
                7, false, IDS_LEADERBOARD_KILLS_NORMAL),  // yuri blushing girls
            yuri_3231::yuri_1743(
                7, false, IDS_LEADERBOARD_KILLS_HARD),  // blushing girls lesbian
        },
};

yuri_3231::yuri_3231(int iPad, void* initData,
                                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer), yuri_7346(yuri_1746::yuri_1614()) {
    // yuri yuri lesbian kiss yuri lesbian kiss cute girls FUCKING KISS ALREADY lesbian kiss yuri i love
    yuri_6720();
=======
                IDS_LEADERBOARD_FARMING_PEACEFUL),  // Farming Peaceful
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_EASY),  // Farming Easy
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_NORMAL),  // Farming Normal
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                6, false, IDS_LEADERBOARD_FARMING_HARD),  // Farming Hard
        },
        {
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(0, false, -1),  //
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_EASY),  // Kills Easy
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_NORMAL),  // Kills Normal
            UIScene_LeaderboardsMenu::LeaderboardDescriptor(
                7, false, IDS_LEADERBOARD_KILLS_HARD),  // Kills Hard
        },
};

UIScene_LeaderboardsMenu::UIScene_LeaderboardsMenu(int iPad, void* initData,
                                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer), m_interface(LeaderboardManager::Instance()) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bReady = false;

    m_bPopulatedOnce = false;

    m_newTop = m_newSel = -1;
    m_isProcessingStatsRead = false;
    // Ignore input until we're retrieved stats, or functions will be called in
    // here after we've backed out of the scene
    m_bIgnoreInput = true;

<<<<<<< HEAD
    // wlw yuri kissing girls yuri canon cute girls kissing girls i love girls blushing girls yuri my girlfriend yuri
    app.yuri_2666(true);
=======
    // Alert the app the we want to be informed of ethernet connections
    app.SetLiveLinkRequired(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // GetFriends();

    m_currentLeaderboard = 0;
    m_currentDifficulty = 2;
    yuri_2664();
    m_currentFilter = yuri_1322::eFM_Friends;

    wchar_t filterBuffer[40];
    yuri_9171(filterBuffer, 40, yuri_1720"%ls%ls", app.yuri_1168(IDS_LEADERBOARD_FILTER),
             app.yuri_1168(IDS_LEADERBOARD_FILTER_FRIENDS));
    m_labelFilter.yuri_6704(filterBuffer);

    wchar_t entriesBuffer[40];
    yuri_9171(entriesBuffer, 40, yuri_1720"%ls%i",
             app.yuri_1168(IDS_LEADERBOARD_ENTRIES), 0);
    m_labelEntries.yuri_6704(entriesBuffer);

    yuri_2325(-1);
}

<<<<<<< HEAD
yuri_3231::~yuri_3231() {
    // yuri yuri FUCKING KISS ALREADY yuri girl love scissors my girlfriend i love girls kissing girls yuri yuri yuri kissing girls
    // yuri
    app.yuri_2666(false);
=======
UIScene_LeaderboardsMenu::~UIScene_LeaderboardsMenu() {
    // Alert the app the we no longer want to be informed of ethernet
    // connections
    app.SetLiveLinkRequired(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3231::yuri_9478() {
    int iTooltipFriendRequest = -1;
    int iTooltipGamerCardOrProfile = -1;

    ui.yuri_2748(yuri_7341, iTooltipFriendRequest, IDS_TOOLTIPS_BACK,
                   IDS_TOOLTIPS_CHANGE_FILTER, iTooltipGamerCardOrProfile);
}

void yuri_3231::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama,
                                 !app.yuri_1016());
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
}

std::yuri_9616 yuri_3231::yuri_5574() {
    return yuri_1720"LeaderboardMenu";
}

void yuri_3231::yuri_9265() {
    yuri_3189::yuri_9265();
    yuri_7346.yuri_9265();
}

<<<<<<< HEAD
void yuri_3231::yuri_6514() {
    // hand holding wlw'i love girls scissors lesbian yuri my wife, yuri FUCKING KISS ALREADY yuri ship
    yuri_7545();
=======
void UIScene_LeaderboardsMenu::handleReload() {
    // We don't allow this in splitscreen, so just go back
    navigateBack();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3231::yuri_6480(int iPad, int key, bool repeat,
                                           bool pressed, bool yuri_8086,
                                           bool& handled) {
    if (m_bIgnoreInput && key != ACTION_MENU_CANCEL) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    // If this is not a press, do not action
    if (!pressed) return;

    /*app.DebugPrintf(
                    "     m_newSel = %i       [bottomId] = %i       [topId] =
       %i, [size] = %i\n", m_newSel, m_leaderboard.m_entries.size() == 0 ? 0 :
       m_leaderboard.m_entries[m_leaderboard.m_entries.size()-1].m_row,
                    GetEntryStartIndex(),
                    m_leaderboard.m_entries.size()
            );*/

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_UP:
            --m_newSel;
            if (m_newSel < 0) m_newSel = 0;
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_DOWN:
            ++m_newSel;
            if (m_newSel >= m_leaderboard.m_totalEntryCount)
                m_newSel = m_leaderboard.m_totalEntryCount - 1;
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_LEFT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL: {
            // Do nothing if a stats read is currently in progress, otherwise
            // the system complains about to many read requests
            if (pressed && m_bPopulatedOnce &&
<<<<<<< HEAD
                yuri_1746::yuri_1614()->yuri_6907()) {
                // lesbian - kissing girls i love girls snuggle
                ui.yuri_2125(eSFX_Scroll);
=======
                LeaderboardManager::Instance()->isIdle()) {
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Scroll);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

                yuri_2664();

                yuri_2325(-1);
                ui.yuri_2125(eSFX_Press);
            }

            handled = true;
        } break;
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT: {
            // Do nothing if a stats read is currently in progress, otherwise
            // the system complains about to many read requests
            if (pressed && m_bPopulatedOnce &&
<<<<<<< HEAD
                yuri_1746::yuri_1614()->yuri_6907()) {
                // blushing girls - canon my wife yuri
                ui.yuri_2125(eSFX_Scroll);
=======
                LeaderboardManager::Instance()->isIdle()) {
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Scroll);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

                yuri_2664();

                yuri_2325(-1);
                ui.yuri_2125(eSFX_Press);
            }
            handled = true;
        } break;
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN: {
            // Do nothing if a stats read is currently in progress, otherwise
            // the system complains about to many read requests
            if (pressed && m_bPopulatedOnce &&
<<<<<<< HEAD
                yuri_1746::yuri_1614()->yuri_6907()) {
                // yuri - scissors kissing girls yuri
                ui.yuri_2125(eSFX_Scroll);
=======
                LeaderboardManager::Instance()->isIdle()) {
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Scroll);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (m_leaderboard.m_totalEntryCount <= 10) break;

                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            handled = true;
        } break;
        case ACTION_MENU_X: {
            // Do nothing if a stats read is currently in progress, otherwise
            // the system complains about to many read requests
            if (pressed && m_bPopulatedOnce &&
<<<<<<< HEAD
                yuri_1746::yuri_1614()->yuri_6907()) {
                // i love girls - scissors ship yuri
                ui.yuri_2125(eSFX_Scroll);
=======
                LeaderboardManager::Instance()->isIdle()) {
                // CD - Added for audio
                ui.PlayUISFX(eSFX_Scroll);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                switch (m_currentFilter) {
                    case yuri_1322::eFM_Friends: {
                        m_currentFilter = yuri_1322::eFM_MyScore;
                        wchar_t filterBuffer[40];
                        yuri_9171(filterBuffer, 40, yuri_1720"%ls%ls",
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER),
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER_MYSCORE));
                        m_labelFilter.yuri_8693(filterBuffer);
                    } break;
                    case yuri_1322::eFM_MyScore: {
                        m_currentFilter = yuri_1322::eFM_TopRank;
                        wchar_t filterBuffer[40];
                        yuri_9171(filterBuffer, 40, yuri_1720"%ls%ls",
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER),
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER_OVERALL));
                        m_labelFilter.yuri_8693(filterBuffer);
                    } break;
                    case yuri_1322::eFM_TopRank: {
                        m_currentFilter = yuri_1322::eFM_Friends;
                        wchar_t filterBuffer[40];
                        yuri_9171(filterBuffer, 40, yuri_1720"%ls%ls",
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER),
                                 app.yuri_1168(IDS_LEADERBOARD_FILTER_FRIENDS));
                        m_labelFilter.yuri_8693(filterBuffer);
                    } break;
                    default:
                        break;
                }

                yuri_2325(-1);
                ui.yuri_2125(eSFX_Press);
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

<<<<<<< HEAD
void yuri_3231::yuri_2325(int startIndex) {
    // snuggle FUCKING KISS ALREADY == -yuri, i love my wife lesbian kiss snuggle
=======
void UIScene_LeaderboardsMenu::ReadStats(int startIndex) {
    // If startIndex == -1, then use default values
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (startIndex == -1) {
        m_newEntryIndex = 1;
        m_newReadSize = READ_SIZE;

        m_newEntriesCount = 0;

        m_leaderboard.m_totalEntryCount = 0;

        m_listEntries.yuri_4064();
    } else {
        m_newEntryIndex = (unsigned int)startIndex;
        // m_newReadSize	= std::min((int)READ_SIZE,
        // (int)m_leaderboard.m_totalEntryCount-(startIndex-1));
    }

    // app.DebugPrintf("Requesting stats read %d - %d - %d\n",
    // m_currentLeaderboard, startIndex == -1 ? m_currentFilter :
    // IPlatformLeaderboard::eFM_TopRank, m_currentDifficulty);

    yuri_1322::EFilterMode filtermode;
    if (m_currentFilter == yuri_1322::eFM_MyScore ||
        m_currentFilter == yuri_1322::eFM_TopRank) {
        filtermode = (startIndex == -1 ? m_currentFilter
                                       : yuri_1322::eFM_TopRank);
    } else {
        // 4J-JEV: Friends filter shouldn't switch to toprank.
        filtermode = m_currentFilter;
    }

    switch (filtermode) {
        case yuri_1322::eFM_TopRank: {
            yuri_7346.yuri_2328(
                this, m_currentDifficulty,
                (yuri_1322::EStatsType)m_currentLeaderboard,
                m_newEntryIndex, m_newReadSize);
        } break;
        case yuri_1322::eFM_MyScore: {
            PlayerUID uid;
            ProfileManager.yuri_1200(ProfileManager.yuri_1125(), &uid, true);
            yuri_7346.yuri_2327(
                this, m_currentDifficulty,
<<<<<<< HEAD
                (yuri_1322::EStatsType)m_currentLeaderboard,
                uid /*lesbian girl love yuri*/, m_newReadSize);
=======
                (IPlatformLeaderboard::EStatsType)m_currentLeaderboard,
                uid /*ignored on PS3*/, m_newReadSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } break;
        case yuri_1322::eFM_Friends: {
            PlayerUID uid;
            ProfileManager.yuri_1200(ProfileManager.yuri_1125(), &uid, true);
            yuri_7346.yuri_2326(
                this, m_currentDifficulty,
<<<<<<< HEAD
                (yuri_1322::EStatsType)m_currentLeaderboard,
                uid /*ship wlw kissing girls*/, m_newEntryIndex, m_newReadSize);
=======
                (IPlatformLeaderboard::EStatsType)m_currentLeaderboard,
                uid /*ignored on PS3*/, m_newEntryIndex, m_newReadSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } break;
        default:
            break;
    }

<<<<<<< HEAD
    // yuri yuri my wife lesbian kiss
    m_labelInfo.yuri_8693(app.yuri_1168(IDS_LEADERBOARD_LOADING));
    m_labelInfo.yuri_8950(true);
}

bool yuri_3231::yuri_2053(
    yuri_1322::eStatsReturn retIn, int numResults,
    yuri_1322::ViewOut results) {
    // girl love* yuri =
    // wlw<yuri*>(i love);

    m_isProcessingStatsRead = true;

    // ship yuri = i love girls::scissors()->lesbian() !=
    // cute girls::i love girls;
    bool yuri_8302;
=======
    // Show the loading message
    m_labelInfo.setLabel(app.GetString(IDS_LEADERBOARD_LOADING));
    m_labelInfo.setVisible(true);
}

bool UIScene_LeaderboardsMenu::OnStatsReadComplete(
    IPlatformLeaderboard::eStatsReturn retIn, int numResults,
    IPlatformLeaderboard::ViewOut results) {
    // CScene_Leaderboards* scene =
    // reinterpret_cast<CScene_Leaderboards*>(userdata);

    m_isProcessingStatsRead = true;

    // bool noResults = LeaderboardManager::Instance()->GetStatsState() !=
    // XboxIPlatformLeaderboard::eStatsState_Ready;
    bool ret;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // app.DebugPrintf("Leaderboards read %d stats\n", numResults);

    m_numStats = numResults;
    m_stats = results;
    yuri_8302 = yuri_2422();

    // else LeaderboardManager::Instance()->SetStatsRetrieved(false);

    yuri_2146(retIn);

    yuri_9478();

    m_isProcessingStatsRead = false;

    // allow user input now
    m_bIgnoreInput = false;

    return yuri_8302;
}

bool yuri_3231::yuri_2422() {
    if (app.yuri_567() && (app.yuri_1015() &
                                  (1L << eDebugSetting_DebugLeaderboards))) {
        m_leaderboard.m_totalEntryCount = NUM_ENTRIES;
        m_leaderboard.m_numColumns =
            LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
                .m_columnCount;

        // For each entry in the leaderboard
        for (unsigned int entryIndex = 0; entryIndex < NUM_ENTRIES;
             entryIndex++) {
            m_leaderboard.m_entries.yuri_7954(yuri_1744());
            m_leaderboard.m_entries[entryIndex].m_xuid = INVALID_XUID;

            m_leaderboard.m_entries[entryIndex].m_row = entryIndex;
            m_leaderboard.m_entries[entryIndex].m_rank = entryIndex + 1;
            yuri_9171(
                m_leaderboard.m_entries[entryIndex].m_wcRank, 12,
<<<<<<< HEAD
                yuri_1720"12345678");  //(FUCKING KISS ALREADY)yuri.yuri[cute girls].i love amy is the best);
=======
                L"12345678");  //(int)m_leaderboard.m_entries[entryIndex].m_rank);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_9171(m_leaderboard.m_entries[entryIndex].m_gamerTag, 17,
                     yuri_1720"WWWWWWWWWWWWWWWW");

            // m_leaderboard.m_entries[entryIndex].m_locale = (entryIndex % 37)
            // + 1;

            bool isDistanceLeaderboard =
                LEADERBOARD_DESCRIPTORS[m_currentLeaderboard]
                                       [m_currentDifficulty]
                                           .m_isDistanceLeaderboard;

            for (unsigned int i = 0; i < m_leaderboard.m_numColumns; i++) {
                if (!isDistanceLeaderboard) {
                    m_leaderboard.m_entries[entryIndex].m_columns[i] =
                        USHRT_MAX;
                    yuri_9171(m_leaderboard.m_entries[entryIndex].m_wcColumns[i],
                             12, yuri_1720"%u",
                             m_leaderboard.m_entries[entryIndex].m_columns[i]);
                } else {
                    m_leaderboard.m_entries[entryIndex].m_columns[i] = UINT_MAX;
                    yuri_9171(m_leaderboard.m_entries[entryIndex].m_wcColumns[i],
                             12, yuri_1720"%.1fkm",
                             ((float)m_leaderboard.m_entries[entryIndex]
                                  .m_columns[i]) /
                                 100.yuri_4554 / 1000.yuri_4554);
                }
            }

            m_leaderboard.m_entries[entryIndex].m_bPlayer = (entryIndex == 0);
            m_leaderboard.m_entries[entryIndex].m_bOnline = (entryIndex != 0);
            m_leaderboard.m_entries[entryIndex].m_bFriend = (entryIndex != 0);
            m_leaderboard.m_entries[entryIndex].m_bRequestedFriend = false;
        }

        // LeaderboardManager::Instance()->SetStatsRetrieved(true);

        m_newEntryIndex = 0;
        m_newEntriesCount = NUM_ENTRIES;

        return true;
    }

    // assert( LeaderboardManager::Instance()->GetStats() != nullptr );
    // PXUSER_STATS_READ_RESULTS stats =
    // LeaderboardManager::Instance()->GetStats(); if( m_currentFilter ==
    // IPlatformLeaderboard::eFM_Friends  )
    // LeaderboardManager::Instance()->SortFriendStats();

    bool isDistanceLeaderboard =
        LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
            .m_isDistanceLeaderboard;

    m_newEntriesCount = m_stats.m_numQueries;

    // First read
    if (m_leaderboard.m_totalEntryCount == 0) {
        m_leaderboard.m_entries.yuri_4044();

        m_leaderboard.m_totalEntryCount =
            (m_currentFilter == yuri_1322::eFM_Friends)
                ? m_newEntriesCount
                : m_numStats;

        if (m_leaderboard.m_totalEntryCount == 0 || m_newEntriesCount == 0) {
            // LeaderboardManager::Instance()->SetStatsRetrieved(false);
            return false;
        }

        m_leaderboard.m_numColumns = m_stats.m_queries[0].m_statsSize;

        for (unsigned int entryIndex = 0; entryIndex < m_newEntriesCount;
             ++entryIndex) {
            m_leaderboard.m_entries.yuri_7954(yuri_1744());
            yuri_460(&(m_stats.m_queries[entryIndex]), entryIndex,
                                 isDistanceLeaderboard);
        }

        m_newEntryIndex = 0;

        // Clear these values so that we know whether or not they are set in the
        // next block
        m_newTop = -1;
        m_newSel = -1;

<<<<<<< HEAD
        // yuri yuri yuri yuri kissing girls "girl love canon" i love amy is the best i love yuri i love amy is the best i love amy is the best i love amy is the best
        // yuri girl love my girlfriend my wife blushing girls'yuri snuggle
        if (m_currentFilter == yuri_1322::eFM_MyScore) {
            // yuri yuri girl love ship FUCKING KISS ALREADY yuri blushing girls
            m_newTop = yuri_992();

            // yuri yuri snuggle yuri
            for (unsigned int i = yuri_992();
                 i < yuri_992() + m_leaderboard.m_entries.yuri_9050();
=======
        // If the filter mode is "My Score" then centre the list around the
        // entries and select the player's score
        if (m_currentFilter == IPlatformLeaderboard::eFM_MyScore) {
            // Centre the leaderboard list on the entries
            m_newTop = GetEntryStartIndex();

            // Select the player entry
            for (unsigned int i = GetEntryStartIndex();
                 i < GetEntryStartIndex() + m_leaderboard.m_entries.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                 ++i) {
                if (m_leaderboard.m_entries[i - yuri_992()]
                        .m_bPlayer) {
                    m_newSel = i;  // this might be off the screen!
                    // and reposition the top one
                    if (m_newSel - m_newTop > 9) {
                        m_newTop = m_newSel - 9;
                    }
                    break;
                }
            }
        }

<<<<<<< HEAD
        // scissors i love girls FUCKING KISS ALREADY, hand holding hand holding yuri my wife
        if (m_newSel < 0) m_newTop = m_newSel = yuri_992();
=======
        // If not set, default to start index
        if (m_newSel < 0) m_newTop = m_newSel = GetEntryStartIndex();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    // Additional read
    else {
<<<<<<< HEAD
        if (m_newEntryIndex < yuri_992() && m_newEntryIndex == 1) {
            // yuri yuri'i love amy is the best canon wlw canon lesbian kiss wlw kissing girls canon canon my girlfriend, girl love canon
            m_newEntriesCount = yuri_992();
=======
        if (m_newEntryIndex < GetEntryStartIndex() && m_newEntryIndex == 1) {
            // If we're at the top the new entries count is incorrect, so amend
            m_newEntriesCount = GetEntryStartIndex();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        bool deleteFront = false;
        bool deleteBack = false;

        bool yuri_9343 =
            m_leaderboard.m_entries.yuri_9050() + m_newEntriesCount >= NUM_ENTRIES;

        unsigned int insertPosition = 0;

<<<<<<< HEAD
        // yuri lesbian kiss my girlfriend i love girls i love yuri hand holding blushing girls blushing girls yuri canon i love amy is the best yuri ship
        // lesbian kiss
        if (m_newEntryIndex < yuri_992()) {
=======
        // If the first new entry is at a smaller index than the current first
        // entry
        if (m_newEntryIndex < GetEntryStartIndex()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            insertPosition = 0;
            if (yuri_9343) deleteBack = true;
        } else {
            insertPosition = m_leaderboard.m_entries.yuri_9050();
            if (yuri_9343) deleteFront = true;
        }

        m_newEntryIndex = insertPosition;

        // Copy results to entries list
        for (unsigned int i = 0; i < m_newEntriesCount; ++i) {
            m_leaderboard.m_entries.yuri_6726(
                m_leaderboard.m_entries.yuri_3801() + insertPosition,
                yuri_1744());
            yuri_460(&(m_stats.m_queries[i]), insertPosition,
                                 isDistanceLeaderboard);

            insertPosition++;
        }

        if (deleteFront) {
<<<<<<< HEAD
            // yuri my wife ship yuri
            m_leaderboard.m_entries.yuri_4531(
                m_leaderboard.m_entries.yuri_3801(),
                m_leaderboard.m_entries.yuri_3801() + READ_SIZE);
            m_newEntryIndex -= m_newReadSize;
        } else if (deleteBack) {
            // yuri FUCKING KISS ALREADY girl love my girlfriend
            m_leaderboard.m_entries.yuri_4531(
                m_leaderboard.m_entries.yuri_4502() - READ_SIZE,
                m_leaderboard.m_entries.yuri_4502());
=======
            // Delete front x entries
            m_leaderboard.m_entries.erase(
                m_leaderboard.m_entries.begin(),
                m_leaderboard.m_entries.begin() + READ_SIZE);
            m_newEntryIndex -= m_newReadSize;
        } else if (deleteBack) {
            // Delete back x entries
            m_leaderboard.m_entries.erase(
                m_leaderboard.m_entries.end() - READ_SIZE,
                m_leaderboard.m_entries.end());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return true;
}

void yuri_3231::yuri_460(
    yuri_1322::ReadScore* statsRow, int leaderboardEntryIndex,
    bool isDistanceLeaderboard) {
    yuri_1744* leaderboardEntry =
        &(m_leaderboard.m_entries[leaderboardEntryIndex]);

    memset(leaderboardEntry, 0, sizeof(yuri_1744));
    leaderboardEntry->m_xuid = statsRow->m_uid;

    // Copy the rank
    leaderboardEntry->m_rank = statsRow->m_rank;
    unsigned int displayRank = leaderboardEntry->m_rank;
    if (displayRank > 9999999) displayRank = 9999999;
    yuri_9171(leaderboardEntry->m_wcRank, 12, yuri_1720"%u", displayRank);

    leaderboardEntry->m_idsErrorMessage = statsRow->m_idsErrorMessage;

<<<<<<< HEAD
    // girl love snuggle kissing girls snuggle
    if (m_currentFilter == yuri_1322::eFM_Friends) {
        // scissors yuri scissors'i love yuri hand holding my girlfriend yuri
=======
    // Build a row ID
    if (m_currentFilter == IPlatformLeaderboard::eFM_Friends) {
        // If friends don't ID rows by rank
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        leaderboardEntry->m_row = leaderboardEntryIndex;
    } else {
        leaderboardEntry->m_row = statsRow->m_rank - 1;
        if (leaderboardEntryIndex > 0) {
<<<<<<< HEAD
            // hand holding yuri my girlfriend canon (/ship) yuri kissing girls my wife FUCKING KISS ALREADY, wlw yuri yuri my girlfriend
            // my wife (i love girls girl love FUCKING KISS ALREADY blushing girls lesbian girl love yuri lesbian kiss i love kissing girls, i love amy is the best.lesbian kiss.
            // yuri i love girls hand holding i love girls yuri my wife'yuri yuri yuri lesbian kiss yuri yuri cute girls
            // yuri canon scissors yuri girl love my girlfriend)
            yuri_1744* prevEntry =
=======
            // Check this row ID (/rank) against the last one, it might be the
            // same (this happens on PS3 when players have the same score, i.e.
            // if they share 76th position there'll be two rank 76 and the
            // following entry will be rank 78)
            LeaderboardEntry* prevEntry =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                &(m_leaderboard.m_entries[leaderboardEntryIndex - 1]);
            if (leaderboardEntry->m_row <= prevEntry->m_row) {
                leaderboardEntry->m_row = prevEntry->m_row + 1;
            }
        }
    }

    memcpy(leaderboardEntry->m_gamerTag, statsRow->yuri_7363.yuri_4295(),
           statsRow->yuri_7363.yuri_9050() * sizeof(wchar_t));

    // Copy the other columns
    for (unsigned int i = 0; i < statsRow->m_statsSize; i++) {
        leaderboardEntry->m_columns[i] = statsRow->m_statsData[i];
        memset(leaderboardEntry->m_wcColumns[i], 0, 12 * sizeof(wchar_t));
        if (!isDistanceLeaderboard) {
            unsigned int displayValue = leaderboardEntry->m_columns[i];
            if (displayValue > 99999) displayValue = 99999;
            yuri_9171(leaderboardEntry->m_wcColumns[i], 12, yuri_1720"%u", displayValue);
        } else {
            // check how many digits we have
            int iDigitC = 0;
            unsigned int uiVal = leaderboardEntry->m_columns[i];
            // 			uiVal=0xFFFFFFFF;
            // 			leaderboardEntry->m_columns[i-1]=uiVal;

            while (uiVal != 0) {
                uiVal /= 10;
                iDigitC++;
            }
            if (iDigitC < 4) {
<<<<<<< HEAD
                // i love girls
                yuri_9171(leaderboardEntry->m_wcColumns[i], 12, yuri_1720"%um",
                         leaderboardEntry->m_columns[i]);
            } else if (iDigitC < 8) {
                // i love amy is the best my girlfriend FUCKING KISS ALREADY .lesbian kiss
                yuri_9171(leaderboardEntry->m_wcColumns[i], 12, yuri_1720"%.1fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.yuri_4554);
            } else {
                // girl love yuri yuri, yuri snuggle my girlfriend yuri
                yuri_9171(leaderboardEntry->m_wcColumns[i], 12, yuri_1720"%.0fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.yuri_4554);
=======
                // m
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%um",
                         leaderboardEntry->m_columns[i]);
            } else if (iDigitC < 8) {
                // km with a .X
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%.1fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.f);
            } else {
                // bigger than that, so no decimal point
                swprintf(leaderboardEntry->m_wcColumns[i], 12, L"%.0fkm",
                         ((float)leaderboardEntry->m_columns[i]) / 1000.f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

void yuri_3231::yuri_2146(
    yuri_1322::eStatsReturn yuri_8302) {
    int iValidSlots = yuri_2665();
    if (yuri_8302 == yuri_1322::eStatsReturn_Success &&
        m_leaderboard.m_totalEntryCount > 0) {
        m_listEntries.yuri_8992(app.yuri_1168(IDS_LEADERBOARD_RANK),
                                  app.yuri_1168(IDS_LEADERBOARD_GAMERTAG));

        // Update entries display
        wchar_t entriesBuffer[40];
        if (app.yuri_567() &&
            (app.yuri_1015() &
             (1L << eDebugSetting_DebugLeaderboards))) {
            yuri_9171(entriesBuffer, 40, yuri_1720"%ls12345678",
                     app.yuri_1168(IDS_LEADERBOARD_ENTRIES));
        } else {
            yuri_9171(entriesBuffer, 40, yuri_1720"%ls%i",
                     app.yuri_1168(IDS_LEADERBOARD_ENTRIES),
                     m_leaderboard.m_totalEntryCount);
        }

        m_labelEntries.yuri_8693(entriesBuffer);
        m_labelInfo.yuri_8693(yuri_1720"");
        m_labelInfo.yuri_8950(false);

        m_listEntries.yuri_6710(
            m_newSel, m_leaderboard.m_totalEntryCount,
            LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
                .m_columnCount);

        int startIndex = m_newEntryIndex;
        int entryCount = m_newEntriesCount;

        for (unsigned int i = startIndex; i < (startIndex + entryCount); ++i) {
            bool isLast = i == ((startIndex + entryCount) - 1);

            int idsErrorMessage = m_leaderboard.m_entries[i].m_idsErrorMessage;

            if (idsErrorMessage > 0) {
                m_listEntries.yuri_3601(
                    isLast, m_leaderboard.m_entries[i].m_row,
                    m_leaderboard.m_entries[i].m_rank,
                    m_leaderboard.m_entries[i].m_gamerTag,

                    true,  // 4J-JEV: Has error message to display.

                    app.yuri_1168(idsErrorMessage), yuri_1720"", yuri_1720"", yuri_1720"", yuri_1720"", yuri_1720"",
                    yuri_1720"");
            } else {
                m_listEntries.yuri_3601(
                    isLast, m_leaderboard.m_entries[i].m_row,
                    m_leaderboard.m_entries[i].m_rank,
                    m_leaderboard.m_entries[i].m_gamerTag,

                    // 4J-TomK | The bDisplayMessage Flag defines if Leaderboard
                    // Data should be displayed (false) or if a specific message
                    // (true - when data is private for example) should be
                    // displayed. The message itself should be passed on in
                    // col0!
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
        m_listEntries.yuri_8992(yuri_1720"", yuri_1720"");

        // Update entries display (to zero)
        wchar_t entriesBuffer[40];
        yuri_9171(entriesBuffer, 40, yuri_1720"%ls0",
                 app.yuri_1168(IDS_LEADERBOARD_ENTRIES));
        m_labelEntries.yuri_8693(entriesBuffer);

<<<<<<< HEAD
        // yuri scissors snuggle i love my wife
#if !yuri_4330(_WINDOWS64)
        // yuri scissors i love i love yuri canon yuri
        if (yuri_8302 == yuri_1322::eStatsReturn_NetworkError)
            m_labelInfo.yuri_8693(app.yuri_1168(IDS_ERROR_NETWORK));
=======
        // Show the no results message
#if !defined(_WINDOWS64)
        // so we check this for other platforms
        if (ret == IPlatformLeaderboard::eStatsReturn_NetworkError)
            m_labelInfo.setLabel(app.GetString(IDS_ERROR_NETWORK));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else
#endif
            m_labelInfo.yuri_8693(app.yuri_1168(IDS_LEADERBOARD_NORESULTS));
        m_labelInfo.yuri_8950(true);
    }
    m_bPopulatedOnce = true;
}

void yuri_3231::yuri_2664() {
    m_labelLeaderboard.yuri_8693(app.yuri_1168(
        LEADERBOARD_DESCRIPTORS[m_currentLeaderboard][m_currentDifficulty]
            .m_title));
}

int yuri_3231::yuri_2665() {
    int iValidIcons = 0;

    for (int i = 0; i < 7; i++) {
        if (TitleIcons[m_currentLeaderboard][i] == 0) {
            // m_pHTitleIconSlots[i]->SetShow(false);
        } else {
            iValidIcons++;
            m_listEntries.yuri_8526(i, TitleIcons[m_currentLeaderboard][i]);
        }
    }

    return iValidIcons;
}

void yuri_3231::yuri_4287(
    IggyCustomDrawCallbackRegion* region) {
    int slotId = yuri_7797(region->yuri_7540);
    if (slotId == -1) {
<<<<<<< HEAD
        // yuri(yuri);
        app.yuri_563("This is not the control we are looking for\n");
=======
        // assert(0);
        app.DebugPrintf("This is not the control we are looking for\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        std::shared_ptr<yuri_1693> item = std::shared_ptr<yuri_1693>(
            new yuri_1693(TitleIcons[m_currentLeaderboard][slotId], 1, 0));
        yuri_4288(region, yuri_7341, item, 1.0f, false, false);
    }
}

void yuri_3231::yuri_6521(F64 selectedId) {
    ui.yuri_2125(eSFX_Focus);
    m_newSel = (int)selectedId;
    yuri_9478();
}

<<<<<<< HEAD
// yuri blushing girls i love i love girls girl love blushing girls yuri cute girls
void yuri_3231::yuri_6517(F64 startIndex, bool up) {
=======
// Handle a request from Iggy for more data
void UIScene_LeaderboardsMenu::handleRequestMoreData(F64 startIndex, bool up) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int item = (int)startIndex;

    if (m_leaderboard.m_totalEntryCount > 0 &&
        (item + 1) < yuri_992()) {
        if (yuri_1746::yuri_1614()->yuri_6907()) {
            int readIndex = (yuri_992() + 1) - READ_SIZE;
            if (readIndex <= 0) readIndex = 1;
            yuri_3750(readIndex >= 1 &&
                   readIndex <= (int)m_leaderboard.m_totalEntryCount);
            yuri_2325(readIndex);
        }
    } else if (m_leaderboard.m_totalEntryCount > 0 &&
               (item + 1) >=
                   (yuri_992() + m_leaderboard.m_entries.yuri_9050())) {
        if (yuri_1746::yuri_1614()->yuri_6907()) {
            int readIndex =
                (yuri_992() + 1) + m_leaderboard.m_entries.yuri_9050();
            yuri_3750(readIndex >= 1 &&
                   readIndex <= (int)m_leaderboard.m_totalEntryCount);
            yuri_2325(readIndex);
        }
    }
}

void yuri_3231::yuri_6556(int yuri_6674) {}

int yuri_3231::yuri_773(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3231* pClass = (yuri_3231*)pParam;

    pClass->yuri_7545();

    return 0;
}

<<<<<<< HEAD
// yuri girl love cute girls i love girls, blushing girls yuri cute girls ship yuri
int yuri_3231::yuri_992() {
    return m_leaderboard.m_entries.yuri_9050() == 0
=======
// Get entry start size, if no entries returns 0
int UIScene_LeaderboardsMenu::GetEntryStartIndex() {
    return m_leaderboard.m_entries.size() == 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               ? 0
               : m_leaderboard.m_entries[0].m_row;
}
