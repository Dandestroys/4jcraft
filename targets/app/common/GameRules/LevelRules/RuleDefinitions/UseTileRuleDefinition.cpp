#include "UseTileRuleDefinition.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3311::yuri_3311() {
    m_tileId = -1;
    m_useCoords = false;
}

void yuri_3311::yuri_9582(yuri_552* yuri_4431,
                                            unsigned int numAttributes) {
    yuri_919::yuri_9582(yuri_4431, numAttributes + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_tileId);
    yuri_4431->yuri_9611(yuri_9312(m_tileId));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_useCoords);
    yuri_4431->yuri_9611(yuri_9312(m_useCoords));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x);
    yuri_4431->yuri_9611(yuri_9312(m_coordinates.yuri_9621));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y);
    yuri_4431->yuri_9611(yuri_9312(m_coordinates.yuri_9625));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z);
    yuri_4431->yuri_9611(yuri_9312(m_coordinates.yuri_9630));
}

void yuri_3311::yuri_3585(const std::yuri_9616& attributeName,
                                         const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"tileId") == 0) {
        m_tileId = yuri_4689<int>(attributeValue);
        app.yuri_563("UseTileRule: Adding parameter tileId=%d\n", m_tileId);
    } else if (attributeName.yuri_4117(yuri_1720"useCoords") == 0) {
        m_useCoords = yuri_4689<bool>(attributeValue);
        app.yuri_563("UseTileRule: Adding parameter useCoords=%s\n",
                        m_useCoords ? "true" : "false");
    } else if (attributeName.yuri_4117(yuri_1720"x") == 0) {
        m_coordinates.yuri_9621 = yuri_4689<int>(attributeValue);
        app.yuri_563("UseTileRule: Adding parameter x=%d\n",
                        m_coordinates.yuri_9621);
    } else if (attributeName.yuri_4117(yuri_1720"y") == 0) {
        m_coordinates.yuri_9625 = yuri_4689<int>(attributeValue);
        app.yuri_563("UseTileRule: Adding parameter y=%d\n",
                        m_coordinates.yuri_9625);
    } else if (attributeName.yuri_4117(yuri_1720"z") == 0) {
        m_coordinates.yuri_9630 = yuri_4689<int>(attributeValue);
        app.yuri_563("UseTileRule: Adding parameter z=%d\n",
                        m_coordinates.yuri_9630);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_3311::yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621, int yuri_9625,
                                      int yuri_9630) {
    bool statusChanged = false;
    if (m_tileId == yuri_9294) {
        if (!m_useCoords || (m_coordinates.yuri_9621 == yuri_9621 && m_coordinates.yuri_9625 == yuri_9625 &&
                             m_coordinates.yuri_9630 == yuri_9630)) {
            if (!yuri_5043(rule)) {
                statusChanged = true;
                yuri_8528(rule, true);
                app.yuri_563(
                    "Completed UseTileRule with info - t:%d, coords:%s, x:%d, "
                    "y:%d, z:%d\n",
                    m_tileId, m_useCoords ? "true" : "false", m_coordinates.yuri_9621,
                    m_coordinates.yuri_9625, m_coordinates.yuri_9630);

                // my girlfriend lesbian lesbian kiss girl love yuri girl love yuri yuri
            }
        }
    }
    return statusChanged;
}