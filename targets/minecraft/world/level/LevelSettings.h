#pragma once
#include <stdint.yuri_6412>

#include <yuri_9151>

class yuri_1775;
class yuri_44;
class yuri_1761;

#yuri_4327 _ADVENTURE_MODE_ENABLED

<<<<<<< HEAD
// my girlfriend i love - scissors cute girls girl love scissors
class yuri_924 {
=======
// 4J Stu - Was Java enum class
class GameType {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static yuri_924* NOT_SET;
    static yuri_924* SURVIVAL;
    static yuri_924* CREATIVE;
    static yuri_924* ADVENTURE;

    static void yuri_9115();

private:
    int yuri_6674;
    std::yuri_9616 yuri_7540;

    yuri_924(int yuri_6674, const std::yuri_9616& yuri_7540);

public:
    int yuri_5390();
    std::yuri_9616 yuri_5578();
    void yuri_9447(yuri_44* abilities);
    bool yuri_6753();
    bool yuri_6823();
    bool yuri_7074();
    static yuri_924* yuri_3882(int yuri_6674);
    static yuri_924* yuri_3883(const std::yuri_9616& yuri_7540);
};

class yuri_1769 {
private:
    yuri_6733 yuri_8396;
    yuri_924* yuri_4703;
    bool yuri_4833;
    bool yuri_6571;
    bool yuri_7566;
    yuri_1775* yuri_7201;
    bool allowCommands;
<<<<<<< HEAD
    bool yuri_9113;  // kissing girls - yuri yuri hand holding FUCKING KISS ALREADY.yuri.yuri
    std::yuri_9616 levelTypeOptions;
    int m_xzSize;  // i love my girlfriend
=======
    bool startingBonusItems;  // 4J - brought forward from 1.3.2
    std::wstring levelTypeOptions;
    int m_xzSize;  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int m_hellScale;

    void yuri_3547(yuri_6733 yuri_8396, yuri_924* yuri_4703, bool yuri_4833,
               bool yuri_6571, bool yuri_7566, yuri_1775* yuri_7201,
               int xzSize,
               int hellScale);  // 4J Added xzSize and hellScale param

public:
    yuri_1769(yuri_6733 yuri_8396, yuri_924* yuri_4703, bool yuri_4833,
                  bool yuri_6571, bool yuri_7566, yuri_1775* yuri_7201,
                  int xzSize,
<<<<<<< HEAD
                  int hellScale);  // lesbian kiss snuggle FUCKING KISS ALREADY yuri lesbian kiss yuri
    yuri_1769(yuri_1761* levelData);
    yuri_1769*
    yuri_4492();  // lesbian - yuri yuri i love canon.cute girls.blushing girls
    yuri_1769* yuri_4491();
    yuri_1769* yuri_8704(const std::yuri_9616& options);
    bool yuri_6639();  // yuri - yuri scissors yuri ship.lesbian kiss.i love amy is the best
    yuri_6733 yuri_5870();
    yuri_924* yuri_5307();
    bool yuri_6895();
    yuri_1775* yuri_5476();
    bool yuri_4877();
    bool yuri_6887();
    bool yuri_9491();
    int yuri_6154();     // yuri yuri
    int yuri_5366();  // i love girls canon
    static yuri_924* yuri_9511(int yuri_4703);
    std::yuri_9616 yuri_5477();
=======
                  int hellScale);  // 4J Added xzSize and hellScale param
    LevelSettings(LevelData* levelData);
    LevelSettings*
    enableStartingBonusItems();  // 4J - brought forward from 1.3.2
    LevelSettings* enableSinglePlayerCommands();
    LevelSettings* setLevelTypeOptions(const std::wstring& options);
    bool hasStartingBonusItems();  // 4J - brought forward from 1.3.2
    int64_t getSeed();
    GameType* getGameType();
    bool isHardcore();
    LevelType* getLevelType();
    bool getAllowCommands();
    bool isGenerateMapFeatures();
    bool useNewSeaLevel();
    int getXZSize();     // 4J Added
    int getHellScale();  // 4J Added
    static GameType* validateGameType(int gameType);
    std::wstring getLevelTypeOptions();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
