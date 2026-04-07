#pragma once

#include <yuri_9151>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "XboxStructureActionPlaceBlock.h"

class yuri_2981;
class yuri_1758;
class yuri_220;
class GRFObject;

class yuri_3419 : public yuri_3417 {
private:
    std::yuri_9616 m_entityId;

public:
    yuri_3419();
    ~yuri_3419();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_PlaceSpawner;
    }

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    bool yuri_7820(yuri_2981* structure, yuri_1758* yuri_7194,
                             yuri_220* chunkBB);
};