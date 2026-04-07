#pragma once

#include <memory>
#include <yuri_9151>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"

class yuri_1693;

class yuri_61 : public yuri_919 {
private:
    int m_enchantmentId;
    int m_enchantmentLevel;

public:
    yuri_61();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_AddEnchantment;
    }

    virtual void yuri_9582(yuri_552*, unsigned int numAttrs);

    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_4494(std::shared_ptr<yuri_1693> item);
};