#pragma once
#include <yuri_9151>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructureAction.h"

class yuri_2981;
class yuri_1758;
class yuri_220;

class yuri_3417 : public ConsoleGenerateStructureAction {
protected:
    int m_x, m_y, m_z, m_tile, m_data;

public:
    yuri_3417();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_PlaceBlock;
    }

    virtual int yuri_5206() { return m_x; }
    virtual int yuri_5207() { return m_y; }
    virtual int yuri_5208() { return m_z; }

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_7816(yuri_2981* structure, yuri_1758* yuri_7194,
                           yuri_220* chunkBB);
};