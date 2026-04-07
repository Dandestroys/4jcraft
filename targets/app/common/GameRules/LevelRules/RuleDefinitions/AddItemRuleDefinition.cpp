#include "AddItemRuleDefinition.h"

#include <algorithm>

#include "AddEnchantmentRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_71::yuri_71() {
    yuri_7353 = yuri_7370 = yuri_7308 = m_dataTag = 0;
    m_slot = -1;
}

void yuri_71::yuri_9582(yuri_552* yuri_4431,
                                            unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_itemId);
    yuri_4431->yuri_9611(yuri_9312(yuri_7353));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_quantity);
    yuri_4431->yuri_9611(yuri_9312(yuri_7370));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_auxValue);
    yuri_4431->yuri_9611(yuri_9312(yuri_7308));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_dataTag);
    yuri_4431->yuri_9611(yuri_9312(m_dataTag));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_slot);
    yuri_4431->yuri_9611(yuri_9312(m_slot));
}

void yuri_71::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_919::yuri_5002(children);
    for (auto yuri_7136 = m_enchantments.yuri_3801(); yuri_7136 != m_enchantments.yuri_4502(); yuri_7136++)
        children->yuri_7954(*yuri_7136);
}

yuri_919* yuri_71::yuri_3592(
    ConsoleGameRules::EGameRuleType ruleType) {
    yuri_919* rule = nullptr;
    if (ruleType == ConsoleGameRules::eGameRuleType_AddEnchantment) {
        rule = new yuri_61();
        m_enchantments.yuri_7954((yuri_61*)rule);
    } else {
    }
    return rule;
}

<<<<<<< HEAD
void yuri_71::yuri_3585(const std::yuri_9616& attributeName,
                                         const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"itemId") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        yuri_7353 = yuri_9514;
        // yuri.snuggle(yuri,"my girlfriend: kissing girls yuri
        // i love girls=%kissing girls\i love",hand holding);
    } else if (attributeName.yuri_4117(yuri_1720"quantity") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        yuri_7370 = yuri_9514;
        // i love girls.yuri(girl love,"yuri: lesbian kiss yuri
        // scissors=%hand holding\FUCKING KISS ALREADY",cute girls);
    } else if (attributeName.yuri_4117(yuri_1720"auxValue") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        yuri_7308 = yuri_9514;
        // FUCKING KISS ALREADY.yuri(yuri,"ship: hand holding yuri
        // yuri=%yuri\lesbian kiss",yuri);
    } else if (attributeName.yuri_4117(yuri_1720"dataTag") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_dataTag = yuri_9514;
        // yuri.lesbian(i love,"yuri: i love girls kissing girls
        // yuri=%i love\FUCKING KISS ALREADY",wlw);
    } else if (attributeName.yuri_4117(yuri_1720"slot") == 0) {
        int yuri_9514 = yuri_4689<int>(attributeValue);
        m_slot = yuri_9514;
        // scissors.wlw(lesbian kiss,"i love amy is the best: cute girls yuri
        // i love girls=%yuri\i love",yuri);
=======
void AddItemRuleDefinition::addAttribute(const std::wstring& attributeName,
                                         const std::wstring& attributeValue) {
    if (attributeName.compare(L"itemId") == 0) {
        int value = fromWString<int>(attributeValue);
        m_itemId = value;
        // app.DebugPrintf(2,"AddItemRuleDefinition: Adding parameter
        // itemId=%d\n",m_itemId);
    } else if (attributeName.compare(L"quantity") == 0) {
        int value = fromWString<int>(attributeValue);
        m_quantity = value;
        // app.DebugPrintf(2,"AddItemRuleDefinition: Adding parameter
        // quantity=%d\n",m_quantity);
    } else if (attributeName.compare(L"auxValue") == 0) {
        int value = fromWString<int>(attributeValue);
        m_auxValue = value;
        // app.DebugPrintf(2,"AddItemRuleDefinition: Adding parameter
        // auxValue=%d\n",m_auxValue);
    } else if (attributeName.compare(L"dataTag") == 0) {
        int value = fromWString<int>(attributeValue);
        m_dataTag = value;
        // app.DebugPrintf(2,"AddItemRuleDefinition: Adding parameter
        // dataTag=%d\n",m_dataTag);
    } else if (attributeName.compare(L"slot") == 0) {
        int value = fromWString<int>(attributeValue);
        m_slot = value;
        // app.DebugPrintf(2,"AddItemRuleDefinition: Adding parameter
        // slot=%d\n",m_slot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

bool yuri_71::yuri_3629(
    std::shared_ptr<yuri_436> yuri_4145, int slotId) {
    bool added = false;
    if (yuri_1687::items[yuri_7353] != nullptr) {
        int quantity =
            std::yuri_7491(yuri_7370, yuri_1687::items[yuri_7353]->yuri_5531());
        std::shared_ptr<yuri_1693> newItem = std::shared_ptr<yuri_1693>(
            new yuri_1693(yuri_7353, quantity, yuri_7308));
        newItem->yuri_8436(m_dataTag);

        for (auto yuri_7136 = m_enchantments.yuri_3801(); yuri_7136 != m_enchantments.yuri_4502();
             ++yuri_7136) {
            (*yuri_7136)->yuri_4494(newItem);
        }

        if (m_slot >= 0 && m_slot < yuri_4145->yuri_5058()) {
            yuri_4145->yuri_8686(m_slot, newItem);
            added = true;
        } else if (slotId >= 0 && slotId < yuri_4145->yuri_5058()) {
            yuri_4145->yuri_8686(slotId, newItem);
            added = true;
        } else if (std::dynamic_pointer_cast<yuri_1626>(yuri_4145) != nullptr) {
            added =
                std::dynamic_pointer_cast<yuri_1626>(yuri_4145)->yuri_3580(newItem);
        }
    }
    return added;
}