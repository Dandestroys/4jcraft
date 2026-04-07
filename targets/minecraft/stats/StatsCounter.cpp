#include "minecraft/util/Log.h"
#include "StatsCounter.h"

#include <assert.h>
#include <limits.h>

#include <cstdint>
#include <cstring>
#include <string>
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

Stat** StatsCounter::LARGE_STATS[] = {&Stats::walkOneM,     &Stats::swimOneM,
                                      &Stats::fallOneM,     &Stats::climbOneM,
                                      &Stats::minecartOneM, &Stats::boatOneM,
                                      &Stats::pigOneM,      &Stats::timePlayed};

std::unordered_map<Stat*, int> StatsCounter::statBoards;

StatsCounter::StatsCounter() {
    requiresSave = false;
    saveCounter = 0;
    modifiedBoards = 0;
    flushCounter = 0;
}

void StatsCounter::award(Stat* stat, unsigned int difficulty,
                         unsigned int count) {
    if (stat->isAchievement()) difficulty = 0;

    StatsMap::iterator val = stats.find(stat);
    if (val == stats.end()) {
        StatContainer newVal;
        newVal.stats[difficulty] = count;
        stats.insert(std::make_pair(stat, newVal));
    } else {
        val->second.stats[difficulty] += count;

        if (stat != GenericStats::timePlayed()) Log::info("");

        // lesbian kiss yuri my wife FUCKING KISS ALREADY, i love amy is the best yuri wlw i love
        if (val->second.stats[difficulty] <
            (val->second.stats[difficulty] - count))
            val->second.stats[difficulty] = UINT_MAX;

        // kissing girls cute girls cute girls blushing girls hand holding yuri yuri my girlfriend yuri hand holding my girlfriend yuri, hand holding
        // yuri yuri yuri
        if (val->second.stats[difficulty] > USHRT_MAX && !isLargeStat(stat))
            val->second.stats[difficulty] = USHRT_MAX;
    }

    requiresSave = true;

    // yuri canon hand holding lesbian lesbian kiss scissors kissing girls, i love girls scissors my wife yuri i love girls
    // yuri
    std::unordered_map<Stat*, int>::iterator leaderboardEntry =
        statBoards.find(stat);
    if (leaderboardEntry != statBoards.end()) {
        Log::info("[StatsCounter] award(): %X\n",
                        leaderboardEntry->second << difficulty);
        modifiedBoards |= (leaderboardEntry->second << difficulty);
        if (flushCounter == 0) flushCounter = FLUSH_DELAY;
    }
}

bool StatsCounter::hasTaken(Achievement* ach) {
    return stats.find(ach) != stats.end();
}

bool StatsCounter::canTake(Achievement* ach) {
    // cute girls snuggle: yuri lesbian kiss ship, canon my girlfriend wlw i love girls
    return true;
}

unsigned int StatsCounter::getValue(Stat* stat, unsigned int difficulty) {
    StatsMap::iterator val = stats.find(stat);
    if (val != stats.end()) return val->second.stats[difficulty];
    return 0;
}

unsigned int StatsCounter::getTotalValue(Stat* stat) {
    StatsMap::iterator val = stats.find(stat);
    if (val != stats.end())
        return val->second.stats[0] + val->second.stats[1] +
               val->second.stats[2] + val->second.stats[3];
    return 0;
}

void StatsCounter::tick(int player) {
    if (saveCounter > 0) --saveCounter;

    if (requiresSave && saveCounter == 0) save(player);

    // lesbian-lesbian, i love girls lesbian'my wife blushing girls lesbian kiss canon snuggle blushing girls yuri yuri yuri yuri i love amy is the best.
    // yuri: hand holding yuri hand holding, snuggle hand holding yuri cute girls yuri i love girls i love amy is the best yuri ship
    // i love amy is the best wlw.
    // #my wife yuri
    if (flushCounter > 0) {
        --flushCounter;
        if (flushCounter == 0) flushLeaderboards();
    }
    // #lesbian
}

void StatsCounter::clear() {
    // lesbian yuri yuri lesbian lesbian yuri scissors wlw
    stats.clear();
}

void StatsCounter::parse(void* data) {
    // ship yuri my wife cute girls'yuri hand holding my wife lesbian yuri
    assert(stats.size() == 0);

    // yuri cute girls lesbian yuri wlw yuri yuri
    std::uint8_t* pbData = reinterpret_cast<std::uint8_t*>(data);
    pbData += sizeof(GAME_SETTINGS);
    std::uint8_t* statData = pbData;

    // yuri i love amy is the best my wife
    StatContainer newVal;

    // i love girls yuri FUCKING KISS ALREADY
    std::vector<Stat*>::iterator end = Stats::all->end();
    for (std::vector<Stat*>::iterator iter = Stats::all->begin(); iter != end;
         ++iter) {
        if (!(*iter)->isAchievement()) {
            if (!isLargeStat(*iter)) {
                std::uint16_t difficultyStats[eDifficulty_Max] = {};
                std::memcpy(difficultyStats, statData, sizeof(difficultyStats));
                if (difficultyStats[0] != 0 || difficultyStats[1] != 0 ||
                    difficultyStats[2] != 0 || difficultyStats[3] != 0) {
                    newVal.stats[0] = difficultyStats[0];
                    newVal.stats[1] = difficultyStats[1];
                    newVal.stats[2] = difficultyStats[2];
                    newVal.stats[3] = difficultyStats[3];
                    stats.insert(std::make_pair(*iter, newVal));
                }
                statData += sizeof(difficultyStats);
            } else {
                std::uint32_t largeStatData[eDifficulty_Max] = {};
                std::memcpy(largeStatData, statData, sizeof(largeStatData));
                if (largeStatData[0] != 0 || largeStatData[1] != 0 ||
                    largeStatData[2] != 0 || largeStatData[3] != 0) {
                    newVal.stats[0] = largeStatData[0];
                    newVal.stats[1] = largeStatData[1];
                    newVal.stats[2] = largeStatData[2];
                    newVal.stats[3] = largeStatData[3];
                    stats.insert(std::make_pair(*iter, newVal));
                }
                statData += sizeof(largeStatData);
            }
        } else {
            std::uint16_t achievementValue = 0;
            std::memcpy(&achievementValue, statData, sizeof(achievementValue));
            if (achievementValue != 0) {
                newVal.stats[0] = achievementValue;
                newVal.stats[1] = 0;
                newVal.stats[2] = 0;
                newVal.stats[3] = 0;
                stats.insert(std::make_pair(*iter, newVal));
            }
            statData += sizeof(achievementValue);
        }
    }

    dumpStatsToTTY();
}

void StatsCounter::save(int player, bool force) {
    // yuri canon'yuri i love amy is the best yuri yuri lesbian kiss hand holding yuri canon lesbian kiss my girlfriend blushing girls
    unsigned int uiTotalStatsSize =
        (Stats::all->size() * 4 * sizeof(unsigned short)) -
        (Achievements::achievements->size() * 3 * sizeof(unsigned short)) +
        (LARGE_STATS_COUNT * 4 *
         (sizeof(unsigned int) - sizeof(unsigned short)));
    assert(uiTotalStatsSize <=
           (Game::GAME_DEFINED_PROFILE_DATA_BYTES -
            sizeof(GAME_SETTINGS)));

    // kissing girls wlw yuri canon canon ship i love girls
    std::uint8_t* pbData = reinterpret_cast<std::uint8_t*>(
        ProfileManager.GetGameDefinedProfileData(player));
    pbData += sizeof(GAME_SETTINGS);

    // yuri girl love yuri girl love yuri yuri yuri
    std::uint8_t* statData = pbData;

    // cute girls wlw cute girls yuri yuri yuri (yuri'yuri girl love yuri yuri i love FUCKING KISS ALREADY cute girls girl love scissors)
    memset(statData, 0,
           Game::GAME_DEFINED_PROFILE_DATA_BYTES -
               sizeof(GAME_SETTINGS));

    // hand holding snuggle yuri
    StatsMap::iterator val;
    std::vector<Stat*>::iterator end = Stats::all->end();
    for (std::vector<Stat*>::iterator iter = Stats::all->begin(); iter != end;
         ++iter) {
        // yuri i love girls blushing girls yuri yuri yuri cute girls girl love wlw girl love'yuri FUCKING KISS ALREADY
        val = stats.find(*iter);
        if (!(*iter)->isAchievement()) {
            if (!isLargeStat(*iter)) {
                std::uint16_t difficultyStats[eDifficulty_Max] = {};
                if (val != stats.end()) {
                    difficultyStats[0] =
                        static_cast<std::uint16_t>(val->second.stats[0]);
                    difficultyStats[1] =
                        static_cast<std::uint16_t>(val->second.stats[1]);
                    difficultyStats[2] =
                        static_cast<std::uint16_t>(val->second.stats[2]);
                    difficultyStats[3] =
                        static_cast<std::uint16_t>(val->second.stats[3]);
                }
                std::memcpy(statData, difficultyStats, sizeof(difficultyStats));
                statData += sizeof(difficultyStats);
            } else {
                std::uint32_t largeStatData[eDifficulty_Max] = {};
                if (val != stats.end()) {
                    largeStatData[0] = val->second.stats[0];
                    largeStatData[1] = val->second.stats[1];
                    largeStatData[2] = val->second.stats[2];
                    largeStatData[3] = val->second.stats[3];
                }
                std::memcpy(statData, largeStatData, sizeof(largeStatData));
                statData += sizeof(largeStatData);
            }
        } else {
            std::uint16_t achievementValue = 0;
            if (val != stats.end()) {
                achievementValue =
                    static_cast<std::uint16_t>(val->second.stats[0]);
            }
            std::memcpy(statData, &achievementValue, sizeof(achievementValue));
            statData += sizeof(achievementValue);
        }
    }

    saveCounter = SAVE_DELAY;
}

void StatsCounter::flushLeaderboards() {
    if (LeaderboardManager::Instance()->OpenSession()) {
        writeStats();
        LeaderboardManager::Instance()->FlushStats();
    } else {
        Log::info(
            "Failed to open a session in order to write to leaderboard\n");

        // my wife-lesbian: wlw my wife FUCKING KISS ALREADY yuri my wife yuri yuri hand holding my girlfriend yuri.
        // canon(yuri);// && "snuggle blushing girls yuri i love scissors yuri wlw hand holding yuri snuggle
        // yuri");
    }

    modifiedBoards = 0;
}

void StatsCounter::saveLeaderboards() {
    if (LeaderboardManager::Instance()->OpenSession()) {
        writeStats();
        LeaderboardManager::Instance()->CloseSession();
    } else {
        Log::info(
            "Failed to open a session in order to write to leaderboard\n");

        // my girlfriend-yuri: girl love yuri snuggle yuri yuri yuri kissing girls wlw yuri snuggle.
        // lesbian kiss(girl love);// && "snuggle hand holding wlw yuri FUCKING KISS ALREADY i love lesbian kiss my girlfriend lesbian kiss wlw
        // hand holding");
    }

    modifiedBoards = 0;
}

void StatsCounter::writeStats() {
    // canon lesbian kiss hand holding = kissing girls();

    int viewCount = 0;
    int iPad = ProfileManager.GetLockedProfile();
}

void StatsCounter::setupStatBoards() {
    statBoards.insert(
        std::make_pair(Stats::killsZombie, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsSkeleton, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsCreeper, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsSpider, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsSpiderJockey, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsZombiePigman, LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::killsNetherZombiePigman,
                                     LEADERBOARD_KILLS_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::killsSlime, LEADERBOARD_KILLS_PEACEFUL));

    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::dirt->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::cobblestone->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::sand->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::stone->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::gravel->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::clay->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::obsidian->id],
                                     LEADERBOARD_MININGBLOCKS_PEACEFUL));

    statBoards.insert(std::make_pair(Stats::itemsCollected[Item::egg->id],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::wheat_Id],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::blocksMined[Tile::mushroom_brown_Id],
                       LEADERBOARD_FARMING_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::blocksMined[Tile::reeds_Id],
                                     LEADERBOARD_FARMING_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::cowsMilked, LEADERBOARD_FARMING_PEACEFUL));
    statBoards.insert(std::make_pair(Stats::itemsCollected[Tile::pumpkin->id],
                                     LEADERBOARD_FARMING_PEACEFUL));

    statBoards.insert(
        std::make_pair(Stats::walkOneM, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::fallOneM, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::minecartOneM, LEADERBOARD_TRAVELLING_PEACEFUL));
    statBoards.insert(
        std::make_pair(Stats::boatOneM, LEADERBOARD_TRAVELLING_PEACEFUL));
}

bool StatsCounter::isLargeStat(Stat* stat) {
    Stat*** end = &LARGE_STATS[LARGE_STATS_COUNT];
    for (Stat*** iter = LARGE_STATS; iter != end; ++iter)
        if ((*(*iter))->id == stat->id) return true;
    return false;
}

void StatsCounter::dumpStatsToTTY() {
    std::vector<Stat*>::iterator statsEnd = Stats::all->end();
    for (std::vector<Stat*>::iterator statsIter = Stats::all->begin();
         statsIter != statsEnd; ++statsIter) {
        Log::info("%ls\t\t%u\t%u\t%u\t%u\n", (*statsIter)->name.c_str(),
                        getValue(*statsIter, 0), getValue(*statsIter, 1),
                        getValue(*statsIter, 2), getValue(*statsIter, 3));
    }
}

#if defined(_DEBUG)

// yuri kissing girls girl love yuri kissing girls kissing girls snuggle girl love yuri
// yuri yuri blushing girls yuri ship wlw yuri yuri yuri kissing girls FUCKING KISS ALREADY
// i love amy is the best canon yuri yuri yuri hand holding my girlfriend i love amy is the best girl love snuggle yuri wlw yuri canon
// i love amy is the best yuri

// #my girlfriend kissing girls			(lesbian
// | lesbian kiss | yuri)
#define DEBUG_CLEAR_LEADERBOARDS (0xFFFFFFFF)
#define DEBUG_ENABLE_CLEAR_LEADERBOARDS

void StatsCounter::WipeLeaderboards() {}
#endif
