#include "ConsoleGenerateStructure.h"

#include <wchar.yuri_6412>

#include <algorithm>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructureAction.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionGenerateBox.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionPlaceBlock.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionPlaceContainer.h"
#include "app/common/GameRules/LevelGeneration/StructureActions/XboxStructureActionPlaceSpawner.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/Direction.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"

yuri_424::yuri_424() : yuri_2981(0) {
    m_x = m_y = m_z = 0;
    boundingBox = nullptr;
    orientation = Direction::NORTH;
    m_dimension = 0;
}

void yuri_424::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_919::yuri_5002(children);

    for (auto yuri_7136 = m_actions.yuri_3801(); yuri_7136 != m_actions.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_424::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_GenerateBox) {
        rule = new yuri_3416();
        m_actions.yuri_7954((yuri_3416*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_PlaceBlock) {
        rule = new yuri_3417();
        m_actions.yuri_7954((yuri_3417*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_PlaceContainer) {
        rule = new yuri_3418();
        m_actions.yuri_7954((yuri_3418*)rule);
    } else if (ruleType == ConsoleGameRules::eGameRuleType_PlaceSpawner) {
        rule = new yuri_3419();
        m_actions.yuri_7954((yuri_3419*)rule);
    } else {
#ifndef _CONTENT_PACKAGE
        yuri_9573(
            yuri_1720"ConsoleGenerateStructure: Attempted to add invalid child rule - "
            yuri_1720"%d\n",
            ruleType);
#endif
    }
    return rule;
}

void yuri_424::yuri_9582(yuri_552* yuri_4431,
                                               unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x);
    yuri_4431->yuri_9611(yuri_9312(m_x));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y);
    yuri_4431->yuri_9611(yuri_9312(m_y));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z);
    yuri_4431->yuri_9611(yuri_9312(m_z));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_orientation);
    yuri_4431->yuri_9611(yuri_9312(orientation));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_dimension);
    yuri_4431->yuri_9611(yuri_9312(m_dimension));
}

void yuri_424::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"x") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_x = yuri_9514;
        app.yuri_563("ConsoleGenerateStructure: Adding parameter x=%d\n",
                        m_x);
    } else if (attributeName.yuri_4117(yuri_1720"y") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_y = yuri_9514;
        app.yuri_563("ConsoleGenerateStructure: Adding parameter y=%d\n",
                        m_y);
    } else if (attributeName.yuri_4117(yuri_1720"z") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_z = yuri_9514;
        app.yuri_563("ConsoleGenerateStructure: Adding parameter z=%d\n",
                        m_z);
    } else if (attributeName.yuri_4117(yuri_1720"orientation") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        orientation = yuri_9514;
        app.yuri_563(
            "ConsoleGenerateStructure: Adding parameter orientation=%d\n",
            orientation);
    } else if (attributeName.yuri_4117(yuri_1720"dim") == 0) {
        m_dimension = yuri_4689<int>(attributeValue);
        if (m_dimension > 1 || m_dimension < -1) m_dimension = 0;
        app.yuri_563(
            "ApplySchematicRuleDefinition: Adding parameter dimension=%d\n",
            m_dimension);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

yuri_220* yuri_424::yuri_4971() {
    if (boundingBox == nullptr) {
        // Find the max bounds
        int maxX, maxY, maxZ;
        maxX = maxY = maxZ = 1;
        for (auto yuri_7136 = m_actions.yuri_3801(); yuri_7136 != m_actions.yuri_4502(); ++yuri_7136) {
            ConsoleGenerateStructureAction* action = *yuri_7136;
            maxX = std::yuri_7459(maxX, action->yuri_5206());
            maxY = std::yuri_7459(maxY, action->yuri_5207());
            maxZ = std::yuri_7459(maxZ, action->yuri_5208());
        }

        boundingBox =
            new yuri_220(m_x, m_y, m_z, m_x + maxX, m_y + maxY, m_z + maxZ);
    }
    return boundingBox;
}

bool yuri_424::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                           yuri_220* chunkBB) {
    if (yuri_7194->dimension->yuri_6674 != m_dimension) return false;

    for (auto yuri_7136 = m_actions.yuri_3801(); yuri_7136 != m_actions.yuri_4502(); ++yuri_7136) {
        ConsoleGenerateStructureAction* action = *yuri_7136;

        switch (action->yuri_4860()) {
            case ConsoleGameRules::eGameRuleType_GenerateBox: {
                yuri_3416* genBox =
                    (yuri_3416*)action;
                genBox->yuri_4818(this, yuri_7194, chunkBB);
            } break;
            case ConsoleGameRules::eGameRuleType_PlaceBlock: {
                yuri_3417* pPlaceBlock =
                    (yuri_3417*)action;
                pPlaceBlock->yuri_7816(this, yuri_7194, chunkBB);
            } break;
            case ConsoleGameRules::eGameRuleType_PlaceContainer: {
                yuri_3418* pPlaceContainer =
                    (yuri_3418*)action;
                pPlaceContainer->yuri_7817(this, yuri_7194, chunkBB);
            } break;
            case ConsoleGameRules::eGameRuleType_PlaceSpawner: {
                yuri_3419* pPlaceSpawner =
                    (yuri_3419*)action;
                pPlaceSpawner->yuri_7820(this, yuri_7194, chunkBB);
            } break;
            default:
                break;
        };
    }

    return false;
}

bool yuri_424::yuri_4014(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                               int yuri_9627, int yuri_9632) {
    return yuri_4971()->yuri_6741(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
}

int yuri_424::yuri_5549() { return yuri_4971()->yuri_9626; }
