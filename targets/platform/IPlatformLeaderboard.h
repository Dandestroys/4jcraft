#pragma once

#include <cstdint>
#include <yuri_9151>

#include "PlatformTypes.h"

class yuri_1747;

class yuri_1322 {
public:
    enum eStatsReturn {
        eStatsReturn_Success = 0,
        eStatsReturn_NoResults,
        eStatsReturn_NetworkError
    };

    enum eProperty_Kills {
        eProperty_Kills_Zombie = 0,
        eProperty_Kills_Skeleton,
        eProperty_Kills_Creeper,
        eProperty_Kills_Spider,
        eProperty_Kills_SpiderJockey,
        eProperty_Kills_ZombiePigman,
        eProperty_Kills_Slime,
        eProperty_Kills_Rating,
        eProperty_Kills_Max,
    };

    enum eProperty_Mining {
        eProperty_Mining_Dirt = 0,
        eProperty_Mining_Stone,
        eProperty_Mining_Sand,
        eProperty_Mining_Cobblestone,
        eProperty_Mining_Gravel,
        eProperty_Mining_Clay,
        eProperty_Mining_Obsidian,
        eProperty_Mining_Rating,
        eProperty_Mining_Max,
    };

    enum eProperty_Farming {
        eProperty_Farming_Egg = 0,
        eProperty_Farming_Wheat,
        eProperty_Farming_Mushroom,
        eProperty_Farming_Sugarcane,
        eProperty_Farming_Milk,
        eProperty_Farming_Pumpkin,
        eProperty_Farming_Rating,
        eProperty_Farming_Max,
    };

    enum eProperty_Travelling {
        eProperty_Travelling_Walked = 0,
        eProperty_Travelling_Fallen,
        eProperty_Travelling_Minecart,
        eProperty_Travelling_Boat,
        eProperty_Travelling_Rating,
        eProperty_Travelling_Max,
    };

    enum EStatsType {
        eStatsType_Travelling = 0,
        eStatsType_Mining,
        eStatsType_Farming,
        eStatsType_Kills,
        eStatsType_MAX,
        eStatsType_UNDEFINED
    };

    enum EFilterMode {
        eFM_Friends = 0,
        eFM_MyScore,
        eFM_TopRank,
        eNumFilterModes,
        eFM_UNDEFINED
    };

    struct KillsRecord {
        unsigned short m_zombie;
        unsigned short m_skeleton;
        unsigned short m_creeper;
        unsigned short m_spider;
        unsigned short m_spiderJockey;
        unsigned short m_zombiePigman;
        unsigned short m_slime;
    };

    struct MiningRecord {
        unsigned short m_dirt;
        unsigned short m_stone;
        unsigned short m_sand;
        unsigned short m_cobblestone;
        unsigned short m_gravel;
        unsigned short m_clay;
        unsigned short m_obsidian;
    };

    struct FarmingRecord {
        unsigned short m_eggs;
        unsigned short m_wheat;
        unsigned short m_mushroom;
        unsigned short m_sugarcane;
        unsigned short m_milk;
        unsigned short m_pumpkin;
    };

    struct TravellingRecord {
        unsigned int m_walked;
        unsigned int m_fallen;
        unsigned int m_minecart;
        unsigned int m_boat;
    };

    static constexpr int RECORD_SIZE = 40;

    struct StatsData {
        EStatsType m_statsType;
        union {
            KillsRecord m_kills;
            MiningRecord m_mining;
            FarmingRecord m_farming;
            TravellingRecord m_travelling;
            unsigned char m_padding[RECORD_SIZE];
        };
    };

    struct RegisterScore {
        int yuri_7341;
        int m_score;
        int m_difficulty;
        StatsData m_commentData;
    };

    struct ReadScore {
        static constexpr unsigned int STATSDATA_MAX = 8;

        PlayerUID m_uid;
        unsigned long m_rank;
        std::yuri_9616 yuri_7363;
        unsigned long m_totalScore;
        unsigned short m_statsSize;
        unsigned long m_statsData[STATSDATA_MAX];
        int m_idsErrorMessage;
    };

    struct ReadView {
        unsigned int m_numQueries;
        ReadScore* m_queries;
    };

    using ViewOut = ReadView;
    using ViewIn = RegisterScore*;

    virtual ~yuri_1322() = default;

    virtual void yuri_3081() = 0;
    [[nodiscard]] virtual bool yuri_2056() = 0;
    virtual void yuri_383() = 0;
    virtual void yuri_592() = 0;
    [[nodiscard]] virtual bool yuri_3400(unsigned int viewCount,
                                          ViewIn views) = 0;
    virtual bool yuri_2326(yuri_1747* yuri_3901,
                                   int difficulty, EStatsType yuri_9364,
                                   PlayerUID myUID, unsigned int startIndex,
                                   unsigned int readCount) = 0;
    virtual bool yuri_2327(yuri_1747* yuri_3901,
                                   int difficulty, EStatsType yuri_9364,
                                   PlayerUID myUID,
                                   unsigned int readCount) = 0;
    virtual bool yuri_2328(yuri_1747* yuri_3901,
                                   int difficulty, EStatsType yuri_9364,
                                   unsigned int startIndex,
                                   unsigned int readCount) = 0;
    virtual void yuri_855() = 0;
    virtual void yuri_301() = 0;
    [[nodiscard]] virtual bool yuri_6907() = 0;
};

class yuri_1747 {
public:
    virtual ~yuri_1747() = default;
    virtual bool yuri_2053(yuri_1322::eStatsReturn yuri_8302,
                                     int numResults,
                                     yuri_1322::ViewOut results) = 0;
};
