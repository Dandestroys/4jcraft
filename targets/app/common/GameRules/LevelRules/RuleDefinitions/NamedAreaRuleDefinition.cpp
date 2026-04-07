#include "NamedAreaRuleDefinition.h"

#include <wchar.yuri_6412>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2008::yuri_2008() {
    yuri_7363 = yuri_1720"";
    m_area = yuri_0(0, 0, 0, 0, 0, 0);
}

void yuri_2008::yuri_9582(yuri_552* yuri_4431,
                                              unsigned int numAttributes) {
    yuri_919::yuri_9582(yuri_4431, numAttributes + 7);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_name);
    yuri_4431->yuri_9611(yuri_7363);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x0);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9622));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y0);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9626));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z0);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9631));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x1);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9623));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y1);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9627));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z1);
    yuri_4431->yuri_9611(yuri_9312(m_area.yuri_9632));
}

void yuri_2008::yuri_3585(const std::yuri_9616& attributeName,
                                           const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"name") == 0) {
        yuri_7363 = attributeValue;
#ifndef _CONTENT_PACKAGE
        yuri_9573(yuri_1720"NamedAreaRuleDefinition: Adding parameter name=%ls\n",
                yuri_7363.yuri_3888());
#endif
    } else if (attributeName.yuri_4117(yuri_1720"x0") == 0) {
        m_area.yuri_9622 = yuri_4689<int>(attributeValue);
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter x0=%f\n",
                        m_area.yuri_9622);
    } else if (attributeName.yuri_4117(yuri_1720"y0") == 0) {
        m_area.yuri_9626 = yuri_4689<int>(attributeValue);
        if (m_area.yuri_9626 < 0) m_area.yuri_9626 = 0;
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter y0=%f\n",
                        m_area.yuri_9626);
    } else if (attributeName.yuri_4117(yuri_1720"z0") == 0) {
        m_area.yuri_9631 = yuri_4689<int>(attributeValue);
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter z0=%f\n",
                        m_area.yuri_9631);
    } else if (attributeName.yuri_4117(yuri_1720"x1") == 0) {
        m_area.yuri_9623 = yuri_4689<int>(attributeValue);
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter x1=%f\n",
                        m_area.yuri_9623);
    } else if (attributeName.yuri_4117(yuri_1720"y1") == 0) {
        m_area.yuri_9627 = yuri_4689<int>(attributeValue);
        if (m_area.yuri_9627 < 0) m_area.yuri_9627 = 0;
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter y1=%f\n",
                        m_area.yuri_9627);
    } else if (attributeName.yuri_4117(yuri_1720"z1") == 0) {
        m_area.yuri_9632 = yuri_4689<int>(attributeValue);
        app.yuri_563("NamedAreaRuleDefinition: Adding parameter z1=%f\n",
                        m_area.yuri_9632);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}
