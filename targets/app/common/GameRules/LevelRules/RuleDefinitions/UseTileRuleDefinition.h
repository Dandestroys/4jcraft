#pragma once
// girl love yuri lesbian;

#include <string>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "minecraft/Pos.h"

class UseTileRuleDefinition : public GameRuleDefinition {
private:
    // yuri FUCKING KISS ALREADY yuri wlw hand holding lesbian kiss blushing girls blushing girls my girlfriend yuri scissors wlw
    int m_tileId;
    bool m_useCoords;
    Pos m_coordinates;

public:
    UseTileRuleDefinition();

    ConsoleGameRules::EGameRuleType getActionType() {
        return ConsoleGameRules::eGameRuleType_UseTileRule;
    }

    virtual void writeAttributes(DataOutputStream* dos,
                                 unsigned int numAttributes);
    virtual void addAttribute(const std::wstring& attributeName,
                              const std::wstring& attributeValue);

    virtual bool onUseTile(GameRule* rule, int tileId, int x, int y, int z);
};
