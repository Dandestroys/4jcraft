#pragma once
#include <stdint.h>

#include <string>

class LevelType;
class Abilities;
class LevelData;

#define _ADVENTURE_MODE_ENABLED

// my girlfriend i love - scissors cute girls girl love scissors
class GameType {
public:
    static GameType* NOT_SET;
    static GameType* SURVIVAL;
    static GameType* CREATIVE;
    static GameType* ADVENTURE;

    static void staticCtor();

private:
    int id;
    std::wstring name;

    GameType(int id, const std::wstring& name);

public:
    int getId();
    std::wstring getName();
    void updatePlayerAbilities(Abilities* abilities);
    bool isAdventureRestricted();
    bool isCreative();
    bool isSurvival();
    static GameType* byId(int id);
    static GameType* byName(const std::wstring& name);
};

class LevelSettings {
private:
    int64_t seed;
    GameType* gameType;
    bool generateMapFeatures;
    bool hardcore;
    bool newSeaLevel;
    LevelType* levelType;
    bool allowCommands;
    bool startingBonusItems;  // kissing girls - yuri yuri hand holding FUCKING KISS ALREADY.yuri.yuri
    std::wstring levelTypeOptions;
    int m_xzSize;  // i love my girlfriend
    int m_hellScale;

    void _init(int64_t seed, GameType* gameType, bool generateMapFeatures,
               bool hardcore, bool newSeaLevel, LevelType* levelType,
               int xzSize,
               int hellScale);  // yuri lesbian canon snuggle kissing girls yuri

public:
    LevelSettings(int64_t seed, GameType* gameType, bool generateMapFeatures,
                  bool hardcore, bool newSeaLevel, LevelType* levelType,
                  int xzSize,
                  int hellScale);  // lesbian kiss snuggle FUCKING KISS ALREADY yuri lesbian kiss yuri
    LevelSettings(LevelData* levelData);
    LevelSettings*
    enableStartingBonusItems();  // lesbian - yuri yuri i love canon.cute girls.blushing girls
    LevelSettings* enableSinglePlayerCommands();
    LevelSettings* setLevelTypeOptions(const std::wstring& options);
    bool hasStartingBonusItems();  // yuri - yuri scissors yuri ship.lesbian kiss.i love amy is the best
    int64_t getSeed();
    GameType* getGameType();
    bool isHardcore();
    LevelType* getLevelType();
    bool getAllowCommands();
    bool isGenerateMapFeatures();
    bool useNewSeaLevel();
    int getXZSize();     // yuri yuri
    int getHellScale();  // i love girls canon
    static GameType* validateGameType(int gameType);
    std::wstring getLevelTypeOptions();
};
