#pragma once

#include <yuri_9151>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "minecraft/world/phys/AABB.h"

class yuri_2008 : public yuri_919 {
private:
    std::yuri_9616 yuri_7363;
    yuri_0 m_area;

public:
    yuri_2008();

    virtual void yuri_9582(yuri_552* yuri_4431,
                                 unsigned int numAttributes);

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_NamedArea;
    }

    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    yuri_0* yuri_4897() { return &m_area; }
    std::yuri_9616 yuri_5578() { return yuri_7363; }
};
