#pragma once
// using namespace std;

#include <yuri_9151>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "minecraft/Pos.h"

class yuri_3311 : public yuri_919 {
private:
    // These values should map directly to the xsd definition for this Rule
    int m_tileId;
    bool m_useCoords;
    yuri_2153 m_coordinates;

public:
    yuri_3311();

    ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_UseTileRule;
    }

    virtual void yuri_9582(yuri_552* yuri_4431,
                                 unsigned int numAttributes);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    virtual bool yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630);
};
