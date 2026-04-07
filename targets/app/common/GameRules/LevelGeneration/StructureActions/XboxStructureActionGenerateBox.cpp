#include "XboxStructureActionGenerateBox.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelGeneration/ConsoleGenerateStructureAction.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

yuri_3416::yuri_3416() {
    m_x0 = m_y0 = m_z0 = m_x1 = m_y1 = m_z1 = m_edgeTile = m_fillTile = 0;
    m_skipAir = false;
}

void yuri_3416::yuri_9582(yuri_552* yuri_4431,
                                                     unsigned int numAttrs) {
    ConsoleGenerateStructureAction::yuri_9582(yuri_4431, numAttrs + 9);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x0);
    yuri_4431->yuri_9611(yuri_9312(m_x0));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y0);
    yuri_4431->yuri_9611(yuri_9312(m_y0));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z0);
    yuri_4431->yuri_9611(yuri_9312(m_z0));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x1);
    yuri_4431->yuri_9611(yuri_9312(m_x1));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y1);
    yuri_4431->yuri_9611(yuri_9312(m_y1));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z1);
    yuri_4431->yuri_9611(yuri_9312(m_z1));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_edgeTile);
    yuri_4431->yuri_9611(yuri_9312(m_edgeTile));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_fillTile);
    yuri_4431->yuri_9611(yuri_9312(m_fillTile));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_skipAir);
    yuri_4431->yuri_9611(yuri_9312(m_skipAir));
}

void yuri_3416::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"x0") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_x0 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter x0=%d\n", m_x0);
    } else if (attributeName.yuri_4117(yuri_1720"y0") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_y0 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter y0=%d\n", m_y0);
    } else if (attributeName.yuri_4117(yuri_1720"z0") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_z0 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter z0=%d\n", m_z0);
    } else if (attributeName.yuri_4117(yuri_1720"x1") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_x1 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter x1=%d\n", m_x1);
    } else if (attributeName.yuri_4117(yuri_1720"y1") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_y1 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter y1=%d\n", m_y1);
    } else if (attributeName.yuri_4117(yuri_1720"z1") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_z1 = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter z1=%d\n", m_z1);
    } else if (attributeName.yuri_4117(yuri_1720"edgeTile") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_edgeTile = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter edgeTile=%d\n",
            m_edgeTile);
    } else if (attributeName.yuri_4117(yuri_1720"fillTile") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_fillTile = yuri_9514;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter fillTile=%d\n",
            m_fillTile);
    } else if (attributeName.yuri_4117(yuri_1720"skipAir") == 0) {
        if (attributeValue.yuri_4117(yuri_1720"true") == 0) m_skipAir = true;
        app.yuri_563(
            "XboxStructureActionGenerateBox: Adding parameter skipAir=%s\n",
            m_skipAir ? "true" : "false");
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_3416::yuri_4818(
    yuri_2981* structure, yuri_1758* yuri_7194, yuri_220* chunkBB) {
    app.yuri_563("XboxStructureActionGenerateBox - generating a box\n");
    structure->yuri_4817(yuri_7194, chunkBB, m_x0, m_y0, m_z0, m_x1, m_y1, m_z1,
                           m_edgeTile, m_fillTile, m_skipAir);
    return true;
}