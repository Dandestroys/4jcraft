#include "BiomeOverride.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_194::yuri_194() {
    m_tile = 0;
    m_topTile = 0;
    m_biomeId = 0;
}

void yuri_194::yuri_9582(yuri_552* yuri_4431,
                                    unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 3);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_biomeId);
    yuri_4431->yuri_9611(yuri_9312(m_biomeId));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_tileId);
    yuri_4431->yuri_9611(yuri_9312(m_tile));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_topTileId);
    yuri_4431->yuri_9611(yuri_9312(m_topTile));
}

void yuri_194::yuri_3585(const std::yuri_9616& attributeName,
                                 const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"tileId") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_tile = yuri_9514;
        app.yuri_563("BiomeOverride: Adding parameter tileId=%d\n", m_tile);
    } else if (attributeName.yuri_4117(yuri_1720"topTileId") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_topTile = yuri_9514;
        app.yuri_563("BiomeOverride: Adding parameter topTileId=%d\n",
                        m_topTile);
    } else if (attributeName.yuri_4117(yuri_1720"biomeId") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_biomeId = yuri_9514;
        app.yuri_563("BiomeOverride: Adding parameter biomeId=%d\n",
                        m_biomeId);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_194::yuri_6783(int yuri_6674) { return m_biomeId == yuri_6674; }

void yuri_194::yuri_6041(std::yuri_9368& tile, std::yuri_9368& topTile) {
    if (m_tile != 0) tile = m_tile;
    if (m_topTile != 0) topTile = m_topTile;
}
