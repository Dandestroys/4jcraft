#include "CollectItemRuleDefinition.h"

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/Rules/GameRule.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/UpdateGameRuleProgressPacket.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_387::yuri_387() {
    yuri_7353 = 0;
    yuri_7308 = 0;
    yuri_7370 = 0;
}

yuri_387::~yuri_387() {}

void yuri_387::yuri_9582(yuri_552* yuri_4431,
                                                unsigned int numAttributes) {
    yuri_919::yuri_9582(yuri_4431, numAttributes + 3);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_itemId);
    yuri_4431->yuri_9611(yuri_9312(yuri_7353));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_auxValue);
    yuri_4431->yuri_9611(yuri_9312(yuri_7308));

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_quantity);
    yuri_4431->yuri_9611(yuri_9312(yuri_7370));
}

void yuri_387::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"itemId") == 0) {
        yuri_7353 = yuri_4689<int>(attributeValue);
        app.yuri_563("CollectItemRule: Adding parameter itemId=%d\n",
                        yuri_7353);
    } else if (attributeName.yuri_4117(yuri_1720"auxValue") == 0) {
        yuri_7308 = yuri_4689<int>(attributeValue);
        app.yuri_563("CollectItemRule: Adding parameter m_auxValue=%d\n",
                        yuri_7308);
    } else if (attributeName.yuri_4117(yuri_1720"quantity") == 0) {
        yuri_7370 = yuri_4689<int>(attributeValue);
        app.yuri_563("CollectItemRule: Adding parameter m_quantity=%d\n",
                        yuri_7370);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

int yuri_387::yuri_5322() { return yuri_7370; }

int yuri_387::yuri_5755(yuri_918* rule) {
    yuri_918::ValueType yuri_9514 = rule->yuri_5681(yuri_1720"iQuantity");
    return yuri_9514.i;
}

void yuri_387::yuri_7867(
    yuri_922::EGameRulesInstanceType yuri_9364, yuri_918* rule) {
    yuri_918::ValueType yuri_9514;
    yuri_9514.i = 0;
    rule->yuri_8761(yuri_1720"iQuantity", yuri_9514);

    yuri_919::yuri_7867(yuri_9364, rule);
}

bool yuri_387::yuri_7613(
    yuri_918* rule, std::shared_ptr<yuri_1693> item) {
    bool statusChanged = false;
    if (item != nullptr && item->yuri_6674 == yuri_7353 &&
        item->yuri_4919() == yuri_7308 &&
        item->yuri_4854() == m_4JDataValue) {
        if (!yuri_5043(rule)) {
            yuri_918::ValueType yuri_9514 = rule->yuri_5681(yuri_1720"iQuantity");
            int quantityCollected = (yuri_9514.i += item->yuri_4184);
            rule->yuri_8761(yuri_1720"iQuantity", yuri_9514);

            statusChanged = true;

            if (quantityCollected >= yuri_7370) {
                yuri_8528(rule, true);
                app.yuri_563(
                    "Completed CollectItemRule with info - itemId:%d, "
                    "auxValue:%d, quantity:%d, dataTag:%d\n",
                    yuri_7353, yuri_7308, yuri_7370, m_4JDataValue);

                if (rule->yuri_5054() != nullptr) {
                    rule->yuri_5054()->yuri_8410(
                        std::shared_ptr<yuri_3282>(
                            new yuri_3282(
                                yuri_4860(), this->yuri_7328,
                                yuri_7353, yuri_7308, this->m_4JDataValue,
                                nullptr, 0)));
                }
            }
        }
    }
    return statusChanged;
}

<<<<<<< HEAD
std::yuri_9616 yuri_387::yuri_4852(
    std::shared_ptr<yuri_1693> item) {
    // blushing girls girl love - lesbian yuri yuri yuri yuri i love amy is the best hand holding lesbian kiss i love girls.scissors
    std::yuri_9616 xml = yuri_1720"";
=======
std::wstring CollectItemRuleDefinition::generateXml(
    std::shared_ptr<ItemInstance> item) {
    // 4J Stu - This should be kept in sync with the GameRulesDefinition.xsd
    std::wstring xml = L"";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (item != nullptr) {
        xml = yuri_1720"<CollectItemRule itemId=\"" + yuri_9312<int>(item->yuri_6674) +
              yuri_1720"\" quantity=\"SET\" descriptionName=\"OPTIONAL\" "
              yuri_1720"promptName=\"OPTIONAL\"";
        if (item->yuri_4919() != 0)
            xml +=
                yuri_1720" auxValue=\"" + yuri_9312<int>(item->yuri_4919()) + yuri_1720"\"";
        if (item->yuri_4854() != 0)
            xml += yuri_1720" dataTag=\"" + yuri_9312<int>(item->yuri_4854()) + yuri_1720"\"";
        xml += yuri_1720"/>\n";
    }
    return xml;
}