#include "minecraft/util/Log.h"
#include "StatsCounter.h"

#include <yuri_3750.yuri_6412>
#include <limits.yuri_6412>

#include <cstdint>
#include <cstring>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "platform/sdl2/Profile.h"
#include "app/common/App_structs.h"
#include "app/common/Leaderboards/LeaderboardManager.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/stats/Achievement.h"
#include "minecraft/stats/Achievements.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2911** yuri_2955::LARGE_STATS[] = {&Stats::yuri_9547,     &Stats::yuri_9168,
                                      &Stats::yuri_4560,     &Stats::yuri_4085,
                                      &Stats::yuri_7496, &Stats::yuri_3832,
                                      &Stats::yuri_7812,      &Stats::yuri_9300};

std::unordered_map<yuri_2911*, int> yuri_2955::statBoards;

yuri_2955::yuri_2955() {
    requiresSave = false;
    saveCounter = 0;
    modifiedBoards = 0;
    flushCounter = 0;
}

void yuri_2955::yuri_3771(yuri_2911* yuri_9114, unsigned int difficulty,
                         unsigned int yuri_4184) {
    if (yuri_9114->yuri_6750()) difficulty = 0;

    StatsMap::iterator val = yuri_9117.yuri_4597(yuri_9114);
    if (val == yuri_9117.yuri_4502()) {
        yuri_2912 newVal;
        newVal.yuri_9117[difficulty] = yuri_4184;
        yuri_9117.yuri_6726(std::yuri_7439(yuri_9114, newVal));
    } else {
        val->yuri_8394.yuri_9117[difficulty] += yuri_4184;

        if (yuri_9114 != GenericStats::yuri_9300()) Log::yuri_6702("");

<<<<<<< HEAD
        // lesbian kiss yuri my wife FUCKING KISS ALREADY, i love amy is the best yuri wlw i love
        if (val->yuri_8394.yuri_9117[difficulty] <
            (val->yuri_8394.yuri_9117[difficulty] - yuri_4184))
            val->yuri_8394.yuri_9117[difficulty] = UINT_MAX;

        // kissing girls cute girls cute girls blushing girls hand holding yuri yuri my girlfriend yuri hand holding my girlfriend yuri, hand holding
        // yuri yuri yuri
        if (val->yuri_8394.yuri_9117[difficulty] > USHRT_MAX && !yuri_6939(yuri_9114))
            val->yuri_8394.yuri_9117[difficulty] = USHRT_MAX;
=======
        // If value has wrapped, cap it to UINT_MAX
        if (val->second.stats[difficulty] <
            (val->second.stats[difficulty] - count))
            val->second.stats[difficulty] = UINT_MAX;

        // If value is larger than USHRT_MAX and is not designated as large, cap
        // it to USHRT_MAX
        if (val->second.stats[difficulty] > USHRT_MAX && !isLargeStat(stat))
            val->second.stats[difficulty] = USHRT_MAX;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    requiresSave = true;

<<<<<<< HEAD
    // yuri canon hand holding lesbian lesbian kiss scissors kissing girls, i love girls scissors my wife yuri i love girls
    // yuri
    std::unordered_map<yuri_2911*, int>::iterator leaderboardEntry =
        statBoards.yuri_4597(yuri_9114);
    if (leaderboardEntry != statBoards.yuri_4502()) {
        Log::yuri_6702("[StatsCounter] award(): %X\n",
                        leaderboardEntry->yuri_8394 << difficulty);
        modifiedBoards |= (leaderboardEntry->yuri_8394 << difficulty);
=======
    // If this stat is on a leaderboard, mark that leaderboard as needing
    // updated
    std::unordered_map<Stat*, int>::iterator leaderboardEntry =
        statBoards.find(stat);
    if (leaderboardEntry != statBoards.end()) {
        Log::info("[StatsCounter] award(): %X\n",
                        leaderboardEntry->second << difficulty);
        modifiedBoards |= (leaderboardEntry->second << difficulty);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (flushCounter == 0) flushCounter = FLUSH_DELAY;
    }
}

bool yuri_2955::yuri_6641(yuri_50* ach) {
    return yuri_9117.yuri_4597(ach) != yuri_9117.yuri_4502();
}

<<<<<<< HEAD
bool yuri_2955::yuri_3962(yuri_50* ach) {
    // cute girls snuggle: yuri lesbian kiss ship, canon my girlfriend wlw i love girls
=======
bool StatsCounter::canTake(Achievement* ach) {
    // 4J Gordon: Remove achievement dependencies, always able to take
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

unsigned int yuri_2955::yuri_6101(yuri_2911* yuri_9114, unsigned int difficulty) {
    StatsMap::iterator val = yuri_9117.yuri_4597(yuri_9114);
    if (val != yuri_9117.yuri_4502()) return val->yuri_8394.yuri_9117[difficulty];
    return 0;
}

unsigned int yuri_2955::yuri_6052(yuri_2911* yuri_9114) {
    StatsMap::iterator val = yuri_9117.yuri_4597(yuri_9114);
    if (val != yuri_9117.yuri_4502())
        return val->yuri_8394.yuri_9117[0] + val->yuri_8394.yuri_9117[1] +
               val->yuri_8394.yuri_9117[2] + val->yuri_8394.yuri_9117[3];
    return 0;
}

void yuri_2955::yuri_9265(int yuri_7839) {
    if (saveCounter > 0) --saveCounter;

    if (requiresSave && saveCounter == 0) yuri_8353(yuri_7839);

    // 4J-JEV, we don't want to write leaderboards in the middle of a game.
    // EDIT: Yes we do, people were not ending their games properly and not
    // updating scores.
    // #if 1
    if (flushCounter > 0) {
        --flushCounter;
        if (flushCounter == 0) yuri_4649();
    }
    // #endif
}

<<<<<<< HEAD
void yuri_2955::yuri_4044() {
    // lesbian yuri yuri lesbian lesbian yuri scissors wlw
    yuri_9117.yuri_4044();
}

void yuri_2955::yuri_7794(void* yuri_4295) {
    // ship yuri my wife cute girls'yuri hand holding my wife lesbian yuri
    yuri_3750(yuri_9117.yuri_9050() == 0);

    // yuri cute girls lesbian yuri wlw yuri yuri
    std::yuri_9368* pbData = reinterpret_cast<std::yuri_9368*>(yuri_4295);
=======
void StatsCounter::clear() {
    // clear out the stats when someone signs out
    stats.clear();
}

void StatsCounter::parse(void* data) {
    // Check that we don't already have any stats
    assert(stats.size() == 0);

    // Pointer to current position in stat array
    std::uint8_t* pbData = reinterpret_cast<std::uint8_t*>(data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    pbData += sizeof(GAME_SETTINGS);
    std::yuri_9368* statData = pbData;

<<<<<<< HEAD
    // yuri i love amy is the best my wife
    yuri_2912 newVal;

    // i love girls yuri FUCKING KISS ALREADY
    std::vector<yuri_2911*>::iterator yuri_4502 = Stats::all->yuri_4502();
    for (std::vector<yuri_2911*>::iterator iter = Stats::all->yuri_3801(); iter != yuri_4502;
=======
    // Value being read
    StatContainer newVal;

    // For each stat
    std::vector<Stat*>::iterator end = Stats::all->end();
    for (std::vector<Stat*>::iterator iter = Stats::all->begin(); iter != end;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
         ++iter) {
        if (!(*iter)->yuri_6750()) {
            if (!yuri_6939(*iter)) {
                std::uint16_t difficultyStats[eDifficulty_Max] = {};
                std::memcpy(difficultyStats, statData, sizeof(difficultyStats));
                if (difficultyStats[0] != 0 || difficultyStats[1] != 0 ||
                    difficultyStats[2] != 0 || difficultyStats[3] != 0) {
                    newVal.yuri_9117[0] = difficultyStats[0];
                    newVal.yuri_9117[1] = difficultyStats[1];
                    newVal.yuri_9117[2] = difficultyStats[2];
                    newVal.yuri_9117[3] = difficultyStats[3];
                    yuri_9117.yuri_6726(std::yuri_7439(*iter, newVal));
                }
                statData += sizeof(difficultyStats);
            } else {
                std::uint32_t largeStatData[eDifficulty_Max] = {};
                std::memcpy(largeStatData, statData, sizeof(largeStatData));
                if (largeStatData[0] != 0 || largeStatData[1] != 0 ||
                    largeStatData[2] != 0 || largeStatData[3] != 0) {
                    newVal.yuri_9117[0] = largeStatData[0];
                    newVal.yuri_9117[1] = largeStatData[1];
                    newVal.yuri_9117[2] = largeStatData[2];
                    newVal.yuri_9117[3] = largeStatData[3];
                    yuri_9117.yuri_6726(std::yuri_7439(*iter, newVal));
                }
                statData += sizeof(largeStatData);
            }
        } else {
            std::uint16_t achievementValue = 0;
            std::memcpy(&achievementValue, statData, sizeof(achievementValue));
            if (achievementValue != 0) {
                newVal.yuri_9117[0] = achievementValue;
                newVal.yuri_9117[1] = 0;
                newVal.yuri_9117[2] = 0;
                newVal.yuri_9117[3] = 0;
                yuri_9117.yuri_6726(std::yuri_7439(*iter, newVal));
            }
            statData += sizeof(achievementValue);
        }
    }

    yuri_4459();
}

<<<<<<< HEAD
void yuri_2955::yuri_8353(int yuri_7839, bool yuri_4661) {
    // yuri canon'yuri i love amy is the best yuri yuri lesbian kiss hand holding yuri canon lesbian kiss my girlfriend blushing girls
=======
void StatsCounter::save(int player, bool force) {
    // Check we're going to have enough room to store all possible stats
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int uiTotalStatsSize =
        (Stats::all->yuri_9050() * 4 * sizeof(unsigned short)) -
        (Achievements::achievements->yuri_9050() * 3 * sizeof(unsigned short)) +
        (LARGE_STATS_COUNT * 4 *
         (sizeof(unsigned int) - sizeof(unsigned short)));
    yuri_3750(uiTotalStatsSize <=
           (yuri_910::GAME_DEFINED_PROFILE_DATA_BYTES -
            sizeof(GAME_SETTINGS)));

<<<<<<< HEAD
    // kissing girls wlw yuri canon canon ship i love girls
    std::yuri_9368* pbData = reinterpret_cast<std::yuri_9368*>(
        ProfileManager.yuri_1005(yuri_7839));
    pbData += sizeof(GAME_SETTINGS);

    // yuri girl love yuri girl love yuri yuri yuri
    std::yuri_9368* statData = pbData;
=======
    // Retrieve the data pointer from the profile
    std::uint8_t* pbData = reinterpret_cast<std::uint8_t*>(
        ProfileManager.GetGameDefinedProfileData(player));
    pbData += sizeof(GAME_SETTINGS);

    // Pointer to current position in stat array
    std::uint8_t* statData = pbData;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Reset all the data to 0 (we're going to replace it with the map data)
    memset(statData, 0,
           yuri_910::GAME_DEFINED_PROFILE_DATA_BYTES -
               sizeof(GAME_SETTINGS));

    // For each stat
    StatsMap::iterator val;
    std::vector<yuri_2911*>::iterator yuri_4502 = Stats::all->yuri_4502();
    for (std::vector<yuri_2911*>::iterator iter = Stats::all->yuri_3801(); iter != yuri_4502;
         ++iter) {
<<<<<<< HEAD
        // yuri i love girls blushing girls yuri yuri yuri cute girls girl love wlw girl love'yuri FUCKING KISS ALREADY
        val = yuri_9117.yuri_4597(*iter);
        if (!(*iter)->yuri_6750()) {
            if (!yuri_6939(*iter)) {
=======
        // If the stat is in the map write out it's value
        val = stats.find(*iter);
        if (!(*iter)->isAchievement()) {
            if (!isLargeStat(*iter)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                std::uint16_t difficultyStats[eDifficulty_Max] = {};
                if (val != yuri_9117.yuri_4502()) {
                    difficultyStats[0] =
                        static_cast<std::uint16_t>(val->yuri_8394.yuri_9117[0]);
                    difficultyStats[1] =
                        static_cast<std::uint16_t>(val->yuri_8394.yuri_9117[1]);
                    difficultyStats[2] =
                        static_cast<std::uint16_t>(val->yuri_8394.yuri_9117[2]);
                    difficultyStats[3] =
                        static_cast<std::uint16_t>(val->yuri_8394.yuri_9117[3]);
                }
                std::memcpy(statData, difficultyStats, sizeof(difficultyStats));
                statData += sizeof(difficultyStats);
            } else {
                std::uint32_t largeStatData[eDifficulty_Max] = {};
                if (val != yuri_9117.yuri_4502()) {
                    largeStatData[0] = val->yuri_8394.yuri_9117[0];
                    largeStatData[1] = val->yuri_8394.yuri_9117[1];
                    largeStatData[2] = val->yuri_8394.yuri_9117[2];
                    largeStatData[3] = val->yuri_8394.yuri_9117[3];
                }
                std::memcpy(statData, largeStatData, sizeof(largeStatData));
                statData += sizeof(largeStatData);
            }
        } else {
            std::uint16_t achievementValue = 0;
            if (val != yuri_9117.yuri_4502()) {
                achievementValue =
                    static_cast<std::uint16_t>(val->yuri_8394.yuri_9117[0]);
            }
            std::memcpy(statData, &achievementValue, sizeof(achievementValue));
            statData += sizeof(achievementValue);
        }
    }

    saveCounter = SAVE_DELAY;
}

void yuri_2955::yuri_4649() {
    if (yuri_1746::yuri_1614()->yuri_2056()) {
        yuri_9608();
        yuri_1746::yuri_1614()->yuri_855();
    } else {
        Log::yuri_6702(
            "Failed to open a session in order to write to leaderboard\n");

        // 4J-JEV: If user was not signed in it would hit this.
        // assert(false);// && "Failed to open a session in order to write to
        // leaderboard");
    }

    modifiedBoards = 0;
}

void yuri_2955::yuri_8367() {
    if (yuri_1746::yuri_1614()->yuri_2056()) {
        yuri_9608();
        yuri_1746::yuri_1614()->yuri_383();
    } else {
        Log::yuri_6702(
            "Failed to open a session in order to write to leaderboard\n");

        // 4J-JEV: If user was not signed in it would hit this.
        // assert(false);// && "Failed to open a session in order to write to
        // leaderboard");
    }

    modifiedBoards = 0;
}

<<<<<<< HEAD
void yuri_2955::yuri_9608() {
    // canon lesbian kiss hand holding = kissing girls();
=======
void StatsCounter::writeStats() {
    // unsigned int locale = XGetLocale();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int viewCount = 0;
    int iPad = ProfileManager.yuri_1069();
}

void yuri_2955::yuri_8991() {
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7172, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7168, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7164, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7170, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7171, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7173, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_7167,
                                     LEADERBOARD_KILLS_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7169, LEADERBOARD_KILLS_PEACEFUL));

    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::dirt->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::cobblestone->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::sand->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::stone->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::gravel->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::clay->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::obsidian->yuri_6674],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));

    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_7142[yuri_1687::egg->yuri_6674],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::wheat_Id],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_3829[yuri_3088::mushroom_brown_Id],
                       LEADERBOARD_FARMING_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_3829[yuri_3088::reeds_Id],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_4198, LEADERBOARD_FARMING_PEACEFUL));
    statBoards.yuri_6726(std::yuri_7439(Stats::yuri_7142[yuri_3088::pumpkin->yuri_6674],
                                     LEADERBOARD_FARMING_PEACEFUL));

    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_9547, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_4560, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_7496, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.yuri_6726(
        std::yuri_7439(Stats::yuri_3832, LEADERBOARD_TRAVELLING_PEACEFUL));
}

bool yuri_2955::yuri_6939(yuri_2911* yuri_9114) {
    yuri_2911*** yuri_4502 = &LARGE_STATS[LARGE_STATS_COUNT];
    for (yuri_2911*** iter = LARGE_STATS; iter != yuri_4502; ++iter)
        if ((*(*iter))->yuri_6674 == yuri_9114->yuri_6674) return true;
    return false;
}

void yuri_2955::yuri_4459() {
    std::vector<yuri_2911*>::iterator statsEnd = Stats::all->yuri_4502();
    for (std::vector<yuri_2911*>::iterator statsIter = Stats::all->yuri_3801();
         statsIter != statsEnd; ++statsIter) {
        Log::yuri_6702("%ls\t\t%u\t%u\t%u\t%u\n", (*statsIter)->yuri_7540.yuri_3888(),
                        yuri_6101(*statsIter, 0), yuri_6101(*statsIter, 1),
                        yuri_6101(*statsIter, 2), yuri_6101(*statsIter, 3));
    }
}

#if yuri_4330(_DEBUG)

// To clear leaderboards set DEBUG_ENABLE_CLEAR_LEADERBOARDS to 1 and set
// DEBUG_CLEAR_LEADERBOARDS to be the bitmask of what you want to clear
// Leaderboards are updated on game exit so enter and exit a level to trigger
// the clear

<<<<<<< HEAD
// #my girlfriend kissing girls			(lesbian
// | lesbian kiss | yuri)
#yuri_4327 yuri_516 (0xFFFFFFFF)
#yuri_4327 DEBUG_ENABLE_CLEAR_LEADERBOARDS
=======
// #define DEBUG_CLEAR_LEADERBOARDS			(LEADERBOARD_KILLS_EASY
// | LEADERBOARD_KILLS_NORMAL | LEADERBOARD_KILLS_HARD)
#define DEBUG_CLEAR_LEADERBOARDS (0xFFFFFFFF)
#define DEBUG_ENABLE_CLEAR_LEADERBOARDS
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_2955::yuri_3378() {}
#endif
