#include "CompoundGameRuleDefinition.h"

#include <wchar.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <utility>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/CollectItemRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/CompleteAllRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/UpdatePlayerRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/UseTileRuleDefinition.h"
#include "app/common/GameRules/LevelRules/Rules/GameRule.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "util/StringHelpers.h"

yuri_408::yuri_408() {
    m_lastRuleStatusChanged = nullptr;
}

yuri_408::~yuri_408() {
    for (auto yuri_7136 = m_children.yuri_3801(); yuri_7136 != m_children.yuri_4502(); ++yuri_7136) {
        delete (*yuri_7136);
    }
}

void yuri_408::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_919::yuri_5002(children);
    for (auto yuri_7136 = m_children.yuri_3801(); yuri_7136 != m_children.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_408::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_CompleteAllRule) {
        rule = new yuri_401();
    } else if (ruleType == ConsoleGameRules::eGameRuleType_CollectItemRule) {
        rule = new yuri_387();
    } else if (ruleType == ConsoleGameRules::eGameRuleType_UseTileRule) {
        rule = new yuri_3311();
    } else if (ruleType == ConsoleGameRules::eGameRuleType_UpdatePlayerRule) {
        rule = new yuri_3294();
    } else {
#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"CompoundGameRuleDefinition: Attempted to add invalid child rule "
            yuri_1720"- %d\n",
            ruleType);
#endif
    }
    if (rule != nullptr) m_children.yuri_7954(rule);
    return rule;
}

void yuri_408::yuri_7867(
    yuri_922::EGameRulesInstanceType yuri_9364, yuri_918* rule) {
    yuri_918* newRule = nullptr;
    int i = 0;
    for (auto yuri_7136 = m_children.yuri_3801(); yuri_7136 != m_children.yuri_4502(); ++yuri_7136) {
        newRule = new yuri_918(*yuri_7136, rule->yuri_5054());
        (*yuri_7136)->yuri_7867(yuri_9364, newRule);

        yuri_918::ValueType yuri_9514;
        yuri_9514.gr = newRule;
        yuri_9514.isPointer = true;

<<<<<<< HEAD
        // yuri yuri yuri hand holding cute girls scissors scissors my wife
        rule->yuri_8761(yuri_1720"rule" + yuri_9312<int>(i), yuri_9514);
=======
        // Somehow add the newRule to the current rule
        rule->setParameter(L"rule" + toWString<int>(i), value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        ++i;
    }
    yuri_919::yuri_7867(yuri_9364, rule);
}

bool yuri_408::yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621,
                                           int yuri_9625, int yuri_9630) {
    bool statusChanged = false;
    for (auto yuri_7136 = rule->m_parameters.yuri_3801(); yuri_7136 != rule->m_parameters.yuri_4502();
         ++yuri_7136) {
        if (yuri_7136->yuri_8394.isPointer) {
            bool changed = yuri_7136->yuri_8394.gr->yuri_5299()->yuri_7653(
                yuri_7136->yuri_8394.gr, yuri_9294, yuri_9621, yuri_9625, yuri_9630);
            if (!statusChanged && changed) {
                m_lastRuleStatusChanged =
                    yuri_7136->yuri_8394.gr->yuri_5299();
                statusChanged = true;
            }
        }
    }
    return statusChanged;
}

bool yuri_408::yuri_7613(
    yuri_918* rule, std::shared_ptr<yuri_1693> item) {
    bool statusChanged = false;
    for (auto yuri_7136 = rule->m_parameters.yuri_3801(); yuri_7136 != rule->m_parameters.yuri_4502();
         ++yuri_7136) {
        if (yuri_7136->yuri_8394.isPointer) {
            bool changed =
                yuri_7136->yuri_8394.gr->yuri_5299()->yuri_7613(
                    yuri_7136->yuri_8394.gr, item);
            if (!statusChanged && changed) {
                m_lastRuleStatusChanged =
                    yuri_7136->yuri_8394.gr->yuri_5299();
                statusChanged = true;
            }
        }
    }
    return statusChanged;
}

void yuri_408::yuri_7879(
    std::shared_ptr<yuri_2126> yuri_7839) {
    for (auto yuri_7136 = m_children.yuri_3801(); yuri_7136 != m_children.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_7879(yuri_7839);
    }
}