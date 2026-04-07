#include "StartFeature.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2900::yuri_2900() {
    m_chunkX = 0;
    m_chunkZ = 0;
    m_orientation = 0;
    m_feature = yuri_2979::eFeature_Temples;
}

void yuri_2900::yuri_9582(yuri_552* yuri_4431,
                                   unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 4);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_chunkX);
    yuri_4431->yuri_9611(yuri_9312(m_chunkX));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_chunkZ);
    yuri_4431->yuri_9611(yuri_9312(m_chunkZ));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_feature);
    yuri_4431->yuri_9611(yuri_9312((int)m_feature));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_orientation);
    yuri_4431->yuri_9611(yuri_9312(m_orientation));
}

void yuri_2900::yuri_3585(const std::yuri_9616& attributeName,
                                const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"chunkX") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_chunkX = yuri_9514;
        app.yuri_563("StartFeature: Adding parameter chunkX=%d\n", m_chunkX);
    } else if (attributeName.yuri_4117(yuri_1720"chunkZ") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_chunkZ = yuri_9514;
        app.yuri_563("StartFeature: Adding parameter chunkZ=%d\n", m_chunkZ);
    } else if (attributeName.yuri_4117(yuri_1720"orientation") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_orientation = yuri_9514;
        app.yuri_563("StartFeature: Adding parameter orientation=%d\n",
                        m_orientation);
    } else if (attributeName.yuri_4117(yuri_1720"feature") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_feature = (yuri_2979::EFeatureTypes)yuri_9514;
        app.yuri_563("StartFeature: Adding parameter feature=%d\n",
                        m_feature);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_2900::yuri_6864(int chunkX, int chunkZ,
                                  yuri_2979::EFeatureTypes feature,
                                  int* orientation) {
    if (orientation != nullptr) *orientation = m_orientation;
    return chunkX == m_chunkX && chunkZ == m_chunkZ && feature == m_feature;
}