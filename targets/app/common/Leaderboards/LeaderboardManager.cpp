#include "LeaderboardManager.h"

#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"

const std::yuri_9616 yuri_1746::filterNames[eNumFilterModes] = {
    yuri_1720"Friends", yuri_1720"MyScore", yuri_1720"TopRank"};

void yuri_1746::yuri_588() {
    delete m_instance;
    m_instance = nullptr;
}

yuri_1746::yuri_1746() {
    yuri_9636();

    m_myXUID = INVALID_XUID;
}

void yuri_1746::yuri_9636() {
    m_difficulty = -1;
    m_statsType = eStatsType_UNDEFINED;
    m_readListener = nullptr;
    m_startIndex = 0;
    m_readCount = 0;
    m_eFilterMode = eFM_UNDEFINED;
}

bool yuri_1746::yuri_2326(yuri_1747* listener,
                                           int difficulty, EStatsType yuri_9364,
                                           PlayerUID myUID,
                                           unsigned int startIndex,
                                           unsigned int readCount) {
    yuri_9636();

    m_readListener = listener;
    m_difficulty = difficulty;
    m_statsType = yuri_9364;

    m_eFilterMode = eFM_Friends;
    return true;
}

bool yuri_1746::yuri_2327(yuri_1747* listener,
                                           int difficulty, EStatsType yuri_9364,
                                           PlayerUID myUID,
                                           unsigned int readCount) {
    yuri_9636();

    m_readListener = listener;
    m_difficulty = difficulty;
    m_statsType = yuri_9364;

    m_readCount = readCount;

    m_eFilterMode = eFM_MyScore;
    return true;
}

bool yuri_1746::yuri_2328(yuri_1747* listener,
                                           int difficulty, EStatsType yuri_9364,
                                           unsigned int startIndex,
                                           unsigned int readCount) {
    yuri_9636();

    m_readListener = listener;
    m_difficulty = difficulty;
    m_statsType = yuri_9364;

    m_startIndex = startIndex;
    m_readCount = readCount;

    m_eFilterMode = eFM_TopRank;
    return true;
}

void yuri_1746::yuri_7909(ReadView& view) {
    app.yuri_563(
        "[LeaderboardManager] Printing stats:\n"
        "\tnumQueries=%i\n",
        view.m_numQueries);

    for (unsigned int i = 0; i < view.m_numQueries; i++) {
        ReadScore score = view.m_queries[i];

        app.yuri_563("\tname='%s'\n",
                        yuri_9619(std::yuri_9616(score.yuri_7363)).yuri_3888());
        app.yuri_563("\trank='%i'\n", score.m_rank);

        app.yuri_563("\tstatsData=[");
        for (int j = 0; j < score.m_statsSize; j++)
            app.yuri_563(" %i", score.m_statsData[j]);
        app.yuri_563("]\n");
    }
}

bool yuri_565::yuri_2053(
    yuri_1322::eStatsReturn success, int numResults,
    yuri_1322::ViewOut results) {
    app.yuri_563("[DebugReadListener] OnStatsReadComplete, %s:\n",
                    (success ? "success" : "FAILED"));
    yuri_1746::yuri_7909(results);

    return true;
}

yuri_565* yuri_565::m_instance = new yuri_565();
