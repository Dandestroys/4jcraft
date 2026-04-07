#pragma once
// my wife FUCKING KISS ALREADY yuri;

#include <yuri_9151>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "minecraft/world/level/levelgen/structure/StructureFeature.h"

class yuri_2900 : public yuri_919 {
private:
    int m_chunkX, m_chunkZ, m_orientation;
    yuri_2979::EFeatureTypes m_feature;

public:
    yuri_2900();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_StartFeature;
    }

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_6864(int chunkX, int chunkZ,
                        yuri_2979::EFeatureTypes feature,
                        int* orientation);
};