#include "UpdatePlayerRuleDefinition.h"

#include <wchar.yuri_6412>

#include <memory>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/AddItemRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/Pos.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodData.h"

yuri_3294::yuri_3294() {
    m_bUpdateHealth = m_bUpdateFood = m_bUpdateYRot = false;
    ;
    m_health = 0;
    m_food = 0;
    m_spawnPos = nullptr;
    m_yRot = 0.0f;
}

yuri_3294::~yuri_3294() {
    for (auto yuri_7136 = m_items.yuri_3801(); yuri_7136 != m_items.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

void yuri_3294::yuri_9582(yuri_552* yuri_4431,
                                                 unsigned int numAttributes) {
    int attrCount = 3;
    if (m_bUpdateHealth) ++attrCount;
    if (m_bUpdateFood) ++attrCount;
    if (m_bUpdateYRot) ++attrCount;
    yuri_919::yuri_9582(yuri_4431, numAttributes + attrCount);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnX);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9621));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnY);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9625));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_spawnZ);
    yuri_4431->yuri_9611(yuri_9312(m_spawnPos->yuri_9630));

    if (m_bUpdateYRot) {
        ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_yRot);
        yuri_4431->yuri_9611(yuri_9312(m_yRot));
    }
    if (m_bUpdateHealth) {
        ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_food);
        yuri_4431->yuri_9611(yuri_9312(m_health));
    }
    if (m_bUpdateFood) {
        ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_health);
        yuri_4431->yuri_9611(yuri_9312(m_food));
    }
}

void yuri_3294::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_919::yuri_5002(children);
    for (auto yuri_7136 = m_items.yuri_3801(); yuri_7136 != m_items.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_3294::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_AddItem) {
        rule = new yuri_71();
        m_items.yuri_7954((yuri_71*)rule);
    } else {
#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"UpdatePlayerRuleDefinition: Attempted to add invalid child rule "
            yuri_1720"- %d\n",
            ruleType);
#endif
    }
    return rule;
}

void yuri_3294::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"spawnX") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9621 = yuri_9514;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter spawnX=%d\n", yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"spawnY") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9625 = yuri_9514;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter spawnY=%d\n", yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"spawnZ") == 0) {
        if (m_spawnPos == nullptr) m_spawnPos = new yuri_2153();
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_spawnPos->yuri_9630 = yuri_9514;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter spawnZ=%d\n", yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"health") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_health = yuri_9514;
        m_bUpdateHealth = true;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter health=%d\n", yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"food") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_food = yuri_9514;
        m_bUpdateFood = true;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter health=%d\n", yuri_9514);
    } else if (attributeName.yuri_4117(yuri_1720"yRot") == 0) {
        float yuri_9514 = yuri_4689<float>(attributeValue);
        m_yRot = yuri_9514;
        m_bUpdateYRot = true;
        app.yuri_563(
            "UpdatePlayerRuleDefinition: Adding parameter yRot=%f\n", yuri_9514);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

void yuri_3294::yuri_7879(
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (m_bUpdateHealth) {
        yuri_7839->lastHealth = m_health;
        yuri_7839->yuri_8648(m_health);
    }

    if (m_bUpdateFood) {
        yuri_7839->yuri_5272()->yuri_8614(m_food);
    }

    double yuri_9621 = yuri_7839->yuri_9621;
    double yuri_9625 = yuri_7839->yuri_9625;
    double yuri_9630 = yuri_7839->yuri_9630;
    float yuri_9628 = yuri_7839->yuri_9628;
    float yuri_9624 = yuri_7839->yuri_9624;
    if (m_spawnPos != nullptr) {
        yuri_9621 = m_spawnPos->yuri_9621;
        yuri_9625 = m_spawnPos->yuri_9625;
        yuri_9630 = m_spawnPos->yuri_9630;
    }

    if (m_bUpdateYRot) {
        yuri_9628 = m_yRot;
    }

    if (m_spawnPos != nullptr || m_bUpdateYRot)
        yuri_7839->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);

    for (auto yuri_7136 = m_items.yuri_3801(); yuri_7136 != m_items.yuri_4502(); ++yuri_7136) {
        yuri_71* yuri_3625 = *yuri_7136;

        yuri_3625->yuri_3629(yuri_7839->inventory, -1);
    }
}