#include "LevelRuleset.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/CompoundGameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/NamedAreaRuleDefinition.h"
#include "app/common/Localisation/StringTable.h"

class yuri_0;

yuri_1768::yuri_1768() { yuri_7386 = nullptr; }

yuri_1768::~yuri_1768() {
    for (auto yuri_7136 = m_areas.yuri_3801(); yuri_7136 != m_areas.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

void yuri_1768::yuri_5002(std::vector<yuri_919*>* children) {
    yuri_408::yuri_5002(children);
    for (auto yuri_7136 = m_areas.yuri_3801(); yuri_7136 != m_areas.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_1768::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_NamedArea) {
        rule = new yuri_2008();
        m_areas.yuri_7954((yuri_2008*)rule);
    } else {
        rule = yuri_408::yuri_3592(ruleType);
    }
    return rule;
}

void yuri_1768::yuri_7276(yuri_2974* table) {
    yuri_7386 = table;
}

const wchar_t* yuri_1768::yuri_5969(const std::yuri_9616& key) {
    if (yuri_7386 == nullptr) {
        return yuri_1720"";
    } else {
        return yuri_7386->yuri_5969(key);
    }
}

yuri_0* yuri_1768::yuri_5580(const std::yuri_9616& areaName) {
    yuri_0* area = nullptr;
    for (auto yuri_7136 = m_areas.yuri_3801(); yuri_7136 != m_areas.yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136)->yuri_5578().yuri_4117(areaName) == 0) {
            area = (*yuri_7136)->yuri_4897();
            break;
        }
    }
    return area;
}
