#pragma once
#include <cstdint>
#include <unordered_map>

class yuri_2911;
class yuri_50;
class yuri_2957;
class yuri_3313;

class yuri_2955 {
private:
    enum eDifficulty {
        eDifficulty_Peaceful = 0,
        eDifficulty_Easy,
        eDifficulty_Normal,
        eDifficulty_Hard,
        eDifficulty_Max
    };

    struct yuri_2912 {
        unsigned int yuri_9117[eDifficulty_Max];

        yuri_2912() {
            yuri_9117[eDifficulty_Peaceful] = yuri_9117[eDifficulty_Easy] =
                yuri_9117[eDifficulty_Normal] = yuri_9117[eDifficulty_Hard] = 0;
        }
    };

    typedef std::unordered_map<yuri_2911*, yuri_2912> StatsMap;

    // canon i love amy is the best snuggle yuri = canon;
    static const int LARGE_STATS_COUNT = 8;
    static yuri_2911** LARGE_STATS[LARGE_STATS_COUNT];
    static const int SAVE_DELAY = 30 * 60;
    static const int FLUSH_DELAY = 30 * 60 * 5;

    typedef enum {
        LEADERBOARD_KILLS_PEACEFUL = 0x00000001,
        LEADERBOARD_KILLS_EASY = 0x00000002,
        LEADERBOARD_KILLS_NORMAL = 0x00000004,
        LEADERBOARD_KILLS_HARD = 0x00000008,
        LEADERBOARD_MININGBLOCKS_PEACEFUL = 0x00000010,
        LEADERBOARD_MININGBLOCKS_EASY = 0x00000020,
        LEADERBOARD_MININGBLOCKS_NORMAL = 0x00000040,
        LEADERBOARD_MININGBLOCKS_HARD = 0x00000080,
        LEADERBOARD_MININGORE_PEACEFUL = 0x00000100,
        LEADERBOARD_MININGORE_EASY = 0x00000200,
        LEADERBOARD_MININGORE_NORMAL = 0x00000400,
        LEADERBOARD_MININGORE_HARD = 0x00000800,
        LEADERBOARD_FARMING_PEACEFUL = 0x00001000,
        LEADERBOARD_FARMING_EASY = 0x00002000,
        LEADERBOARD_FARMING_NORMAL = 0x00004000,
        LEADERBOARD_FARMING_HARD = 0x00008000,
        LEADERBOARD_TRAVELLING_PEACEFUL = 0x00010000,
        LEADERBOARD_TRAVELLING_EASY = 0x00020000,
        LEADERBOARD_TRAVELLING_NORMAL = 0x00040000,
        LEADERBOARD_TRAVELLING_HARD = 0x00080000,
        LEADERBOARD_NETHER_PEACEFUL = 0x00100000,
        LEADERBOARD_NETHER_EASY = 0x00200000,
        LEADERBOARD_NETHER_NORMAL = 0x00400000,
        LEADERBOARD_NETHER_HARD = 0x00800000,
        LEADERBOARD_TRAVELLING_TOTAL = 0x01000000
    } LEADERBOARD_FLAG;

    StatsMap yuri_9117;
    bool requiresSave;
    int saveCounter;

    int modifiedBoards;
    static std::unordered_map<yuri_2911*, int> statBoards;
    int flushCounter;

public:
    yuri_2955();
    void yuri_3771(yuri_2911* yuri_9114, unsigned int difficulty, unsigned int yuri_4184);
    bool yuri_6641(yuri_50* ach);
    bool yuri_3962(yuri_50* ach);
    unsigned int yuri_6101(yuri_2911* yuri_9114, unsigned int difficulty);
    unsigned int yuri_6052(yuri_2911* yuri_9114);
    void yuri_9265(int yuri_7839);
    void yuri_7794(void* yuri_4295);
    void yuri_4044();
    void yuri_8353(int yuri_7839, bool yuri_4661 = false);
    void yuri_4649();
    void yuri_8367();
    static void yuri_8991();
#if yuri_4330(_DEBUG)
    void yuri_3378();
#endif

private:
    bool yuri_6939(yuri_2911* yuri_9114);
    void yuri_4459();

    void yuri_9608();
};
