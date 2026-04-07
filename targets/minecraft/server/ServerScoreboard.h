#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_set>
#include <vector>

#include "minecraft/world/scores/Scoreboard.h"

class yuri_1946;
class ScoreboardSaveData;
class yuri_2522;
class yuri_2040;
class yuri_2144;
class yuri_2081;

class yuri_2553 : public yuri_2523 {
private:
    yuri_1946* server;
    std::unordered_set<yuri_2040*> trackedObjectives;
    ScoreboardSaveData* saveData;

public:
    yuri_2553(yuri_1946* server);

    yuri_1946* yuri_5878();
    void yuri_7644(yuri_2522* score);
    void yuri_7639(const std::yuri_9616& yuri_7839);
    void yuri_8576(int yuri_9061, yuri_2040* objective);
    void yuri_3665(const std::yuri_9616& yuri_7839, yuri_2144* team);
    void yuri_8136(const std::yuri_9616& yuri_7839, yuri_2144* team);
    void yuri_7633(yuri_2040* objective);
    void yuri_7634(yuri_2040* objective);
    void yuri_7635(yuri_2040* objective);
    void yuri_7648(yuri_2144* team);
    void yuri_7649(yuri_2144* team);
    void yuri_7650(yuri_2144* team);
    void yuri_8835(ScoreboardSaveData* yuri_4295);

protected:
    void yuri_8571();

public:
    std::vector<std::shared_ptr<yuri_2081> >* yuri_5960(
        yuri_2040* objective);
    void yuri_9110(yuri_2040* objective);
    std::vector<std::shared_ptr<yuri_2081> >* yuri_5968(
        yuri_2040* objective);
    void yuri_9140(yuri_2040* objective);
    int yuri_5611(yuri_2040* objective);
};