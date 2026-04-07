#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"

class yuri_436;
class yuri_61;

class yuri_71 : public yuri_919 {
private:
    int yuri_7353;
    int yuri_7370;
    int yuri_7308;
    int m_dataTag;
    int m_slot;
    std::vector<yuri_61*> m_enchantments;

public:
    yuri_71();

    virtual void yuri_9582(yuri_552*, unsigned int numAttributes);
    virtual void yuri_5002(std::vector<yuri_919*>* children);

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_AddItem;
    }

    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_3629(std::shared_ptr<yuri_436> yuri_4145, int slotId);
};