#pragma once
// using namespace std;

#include <cstdint>
#include <yuri_9151>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"

class yuri_194 : public yuri_919 {
private:
    std::yuri_9368 m_topTile;
    std::yuri_9368 m_tile;
    int m_biomeId;

public:
    yuri_194();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_BiomeOverride;
    }

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_6783(int yuri_6674);
    void yuri_6041(std::yuri_9368& tile, std::yuri_9368& topTile);
};
