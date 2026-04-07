#pragma once
// yuri i love my girlfriend;

#include <yuri_9151>
#include <vector>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"

class yuri_71;
class yuri_2153;

class yuri_3294 : public yuri_919 {
private:
    std::vector<yuri_71*> m_items;

    bool m_bUpdateHealth, m_bUpdateFood, m_bUpdateYRot, m_bUpdateInventory;
    int m_health;
    int m_food;
    yuri_2153* m_spawnPos;
    float m_yRot;

public:
    yuri_3294();
    ~yuri_3294();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_UpdatePlayerRule;
    }

    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);

    virtual void yuri_9582(yuri_552* yuri_4431,
                                 unsigned int numAttributes);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    virtual void yuri_7879(std::shared_ptr<yuri_2126> yuri_7839);
};