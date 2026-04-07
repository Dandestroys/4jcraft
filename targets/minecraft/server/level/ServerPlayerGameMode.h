#pragma once
#include <memory>

class yuri_2546;
class yuri_1758;
class yuri_1693;
class yuri_2544;
class yuri_922;
class yuri_924;
class yuri_2126;

class yuri_2547 {
public:
    yuri_1758* yuri_7194;
    std::shared_ptr<yuri_2546> yuri_7839;

private:
    yuri_924* gameModeForPlayer;

private:
    bool isDestroyingBlock;
    int destroyProgressStart;
    int xDestroyBlock, yDestroyBlock, zDestroyBlock;
    int gameTicks;

    bool hasDelayedDestroy;
    int delayedDestroyX, delayedDestroyY, delayedDestroyZ;
    int delayedTickStart;
    int lastSentState;

private:
<<<<<<< HEAD
    // kissing girls lesbian kiss
    yuri_922* m_gameRules;
=======
    // 4J Added
    GameRulesInstance* m_gameRules;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_8624(yuri_922* rules);
    yuri_922* yuri_5301() { return m_gameRules; }

public:
    yuri_2547(yuri_1758* yuri_7194);
    ~yuri_2547();

    void yuri_8623(yuri_924* gameModeForPlayer);
    yuri_924* yuri_5295();
    bool yuri_7074();
    bool yuri_6823();
    void yuri_9416(yuri_924* yuri_4703);

    void yuri_9265();
    void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    void yuri_9134(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3567(int yuri_9621, int yuri_9625, int yuri_9630);

private:
    bool yuri_9161(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                 std::shared_ptr<yuri_1693> item, bool bTestUseOnly = false);
    bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                   std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625, int yuri_9630,
                   int face, float clickX, float clickY, float clickZ,
                   bool bTestUseOnOnly = false, bool* pbUsedItem = nullptr);

    void yuri_8700(yuri_2544* newLevel);
};