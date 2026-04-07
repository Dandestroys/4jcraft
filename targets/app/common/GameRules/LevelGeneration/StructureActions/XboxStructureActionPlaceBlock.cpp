#include "XboxStructureActionPlaceBlock.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructureAction.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

yuri_3417::yuri_3417() {
    m_x = m_y = m_z = m_tile = m_data = 0;
}

void yuri_3417::yuri_9582(yuri_552* yuri_4431,
                                                    unsigned int numAttrs) {
    ConsoleGenerateStructureAction::yuri_9582(yuri_4431, numAttrs + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x);
    yuri_4431->yuri_9611(yuri_9312(m_x));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y);
    yuri_4431->yuri_9611(yuri_9312(m_y));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z);
    yuri_4431->yuri_9611(yuri_9312(m_z));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_data);
    yuri_4431->yuri_9611(yuri_9312(m_data));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_block);
    yuri_4431->yuri_9611(yuri_9312(m_tile));
}

void yuri_3417::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"x") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_x = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceBlock: Adding parameter x=%d\n", m_x);
    } else if (attributeName.yuri_4117(yuri_1720"y") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_y = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceBlock: Adding parameter y=%d\n", m_y);
    } else if (attributeName.yuri_4117(yuri_1720"z") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_z = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceBlock: Adding parameter z=%d\n", m_z);
    } else if (attributeName.yuri_4117(yuri_1720"block") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_tile = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceBlock: Adding parameter block=%d\n",
            m_tile);
    } else if (attributeName.yuri_4117(yuri_1720"data") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_data = yuri_9514;
        app.yuri_563(
            "XboxStructureActionPlaceBlock: Adding parameter data=%d\n",
            m_data);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_3417::yuri_7816(yuri_2981* structure,
                                                      yuri_1758* yuri_7194,
                                                      yuri_220* chunkBB) {
    app.yuri_563("XboxStructureActionPlaceBlock - placing a block\n");
    structure->yuri_7815(yuri_7194, m_tile, m_data, m_x, m_y, m_z, chunkBB);
    return true;
}