#pragma once

#include <vector>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"

class yuri_408 : public yuri_919 {
protected:
    std::vector<yuri_919*> m_children;

protected:
    yuri_919* m_lastRuleStatusChanged;

public:
    yuri_408();
    virtual ~yuri_408();

    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);

    virtual void yuri_7867(
        yuri_922::EGameRulesInstanceType yuri_9364, yuri_918* rule);

    virtual bool yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7613(yuri_918* rule,
                               std::shared_ptr<yuri_1693> item);
    virtual void yuri_7879(std::shared_ptr<yuri_2126> yuri_7839);
};