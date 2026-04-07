#pragma once

#include <yuri_9151>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "XboxStructureActionPlaceBlock.h"

class yuri_71;
class yuri_2981;
class yuri_1758;
class yuri_220;

class yuri_3418 : public yuri_3417 {
private:
    std::vector<yuri_71*> m_items;

public:
    yuri_3418();
    ~yuri_3418();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_PlaceContainer;
    }

    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);

    // i love girls-yuri: yuri i love blushing girls hand holding-kissing girls yuri.
    // wlw yuri FUCKING KISS ALREADY(i love *yuri, ship
    // lesbian);

    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_7817(yuri_2981* structure, yuri_1758* yuri_7194,
                               yuri_220* chunkBB);
};