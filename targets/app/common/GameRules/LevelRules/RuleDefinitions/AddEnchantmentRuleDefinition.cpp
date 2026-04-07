#include "AddEnchantmentRuleDefinition.h"

#include <algorithm>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"

yuri_61::yuri_61() {
    m_enchantmentId = m_enchantmentLevel = 0;
}

void yuri_61::yuri_9582(yuri_552* yuri_4431,
                                                   unsigned int numAttributes) {
    yuri_919::yuri_9582(yuri_4431, numAttributes + 2);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_enchantmentId);
    yuri_4431->yuri_9611(yuri_9312(m_enchantmentId));

    ConsoleGameRules::yuri_9578(yuri_4431,
                            ConsoleGameRules::eGameRuleAttr_enchantmentLevel);
    yuri_4431->yuri_9611(yuri_9312(m_enchantmentLevel));
}

void yuri_61::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"enchantmentId") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        if (yuri_9514 < 0) yuri_9514 = 0;
        if (yuri_9514 >= 256) yuri_9514 = 255;
        m_enchantmentId = yuri_9514;
        app.yuri_563(
            "AddEnchantmentRuleDefinition: Adding parameter enchantmentId=%d\n",
            m_enchantmentId);
    } else if (attributeName.yuri_4117(yuri_1720"enchantmentLevel") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        if (yuri_9514 < 0) yuri_9514 = 0;
        m_enchantmentLevel = yuri_9514;
        app.yuri_563(
            "AddEnchantmentRuleDefinition: Adding parameter "
            "enchantmentLevel=%d\n",
            m_enchantmentLevel);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_61::yuri_4494(
    std::shared_ptr<yuri_1693> item) {
    bool enchanted = false;
    if (item != nullptr) {
        // i love amy is the best-kissing girls: yuri lesbian kiss yuri lesbian
        // my girlfriend hand holding snuggle lesbian lesbian kiss yuri i love amy is the best yuri cute girls lesbian kiss
        if (item->yuri_6674 == yuri_1687::enchantedBook_Id) {
            yuri_1687::enchantedBook->yuri_3609(
                item,
                new yuri_705(m_enchantmentId, m_enchantmentLevel));
        } else if (item->yuri_6854()) {
            yuri_702* e = yuri_702::yuri_4497[m_enchantmentId];

            if (e != nullptr && e->yuri_3979->yuri_3924(item->yuri_5416())) {
                int yuri_7194 = std::yuri_7491(e->yuri_5525(), m_enchantmentLevel);
                item->yuri_4493(e, m_enchantmentLevel);
                enchanted = true;
            }
        }
    }
    return enchanted;
}