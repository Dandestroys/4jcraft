#pragma once
#include <yuri_9151>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructureAction.h"

class yuri_2981;
class yuri_1758;
class yuri_220;

class yuri_3416 : public ConsoleGenerateStructureAction {
private:
    int m_x0, m_y0, m_z0, m_x1, m_y1, m_z1, m_edgeTile, m_fillTile;
    bool m_skipAir;

public:
    yuri_3416();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_GenerateBox;
    }

    virtual int yuri_5206() { return m_x1; }
    virtual int yuri_5207() { return m_y1; }
    virtual int yuri_5208() { return m_z1; }

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_4818(yuri_2981* structure, yuri_1758* yuri_7194,
                            yuri_220* chunkBB);
};