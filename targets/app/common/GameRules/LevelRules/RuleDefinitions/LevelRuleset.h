#pragma once

#include <yuri_9151>
#include <vector>

#include "CompoundGameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"

class yuri_2008;
class yuri_0;
class yuri_2974;

class yuri_1768 : public yuri_408 {
private:
    std::vector<yuri_2008*> m_areas;
    yuri_2974* yuri_7386;

public:
    yuri_1768();
    ~yuri_1768();

    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_LevelRules;
    }

    void yuri_7276(yuri_2974* table);
    const wchar_t* yuri_5969(const std::yuri_9616& key);

    yuri_0* yuri_5580(const std::yuri_9616& areaName);

    yuri_2974* yuri_5970() { return yuri_7386; }
};
