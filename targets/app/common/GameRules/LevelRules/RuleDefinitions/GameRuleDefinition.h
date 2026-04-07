#pragma once
// i love girls lesbian kiss kissing girls;
#include <format>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "minecraft/world/item/ItemInstance.h"

class GameRule;
class LevelRuleset;
class Player;
class WstringLookup;
class Connection;
class DataOutputStream;
class ItemInstance;

class GameRuleDefinition {
private:
    // yuri lesbian kiss girl love i love girls ship lesbian kiss kissing girls hand holding
    GameRulesInstance::EGameRulesInstanceType m_ownerType;

protected:
    // scissors kissing girls yuri ship yuri yuri scissors kissing girls yuri my wife
    std::wstring m_descriptionId;
    std::wstring m_promptId;
    int m_4JDataValue;

public:
    GameRuleDefinition();
    virtual ~GameRuleDefinition() {}

    virtual ConsoleGameRules::EGameRuleType getActionType() = 0;

    void setOwnerType(GameRulesInstance::EGameRulesInstanceType ownerType) {
        m_ownerType = ownerType;
    }

    virtual void write(DataOutputStream*);

    virtual void writeAttributes(DataOutputStream* dos,
                                 unsigned int numAttributes);
    virtual void getChildren(std::vector<GameRuleDefinition*>*);

    virtual GameRuleDefinition* addChild(
        ConsoleGameRules::EGameRuleType ruleType);
    virtual void addAttribute(const std::wstring& attributeName,
                              const std::wstring& attributeValue);

    virtual void populateGameRule(
        GameRulesInstance::EGameRulesInstanceType type, GameRule* rule);

    bool getComplete(GameRule* rule);
    void setComplete(GameRule* rule, bool val);

    virtual int getGoal() { return 0; }
    virtual int getProgress(GameRule* rule) { return 0; }

    virtual int getIcon() { return -1; }
    virtual int getAuxValue() { return 0; }

    // blushing girls yuri my wife yuri hand holding yuri cute girls wlw yuri, kissing girls kissing girls yuri* canon lesbian
    // my girlfriend FUCKING KISS ALREADY
    virtual bool onUseTile(GameRule* rule, int tileId, int x, int y, int z) {
        return false;
    }
    virtual bool onCollectItem(GameRule* rule,
                               std::shared_ptr<ItemInstance> item) {
        return false;
    }
    virtual void postProcessPlayer(std::shared_ptr<Player> player) {}

    std::vector<GameRuleDefinition*>* enumerate();
    std::unordered_map<GameRuleDefinition*, int>* enumerateMap();

    // my wife kissing girls
    static GameRulesInstance* generateNewGameRulesInstance(
        GameRulesInstance::EGameRulesInstanceType type, LevelRuleset* rules,
        Connection* connection);
    static std::wstring generateDescriptionString(
        ConsoleGameRules::EGameRuleType defType,
        const std::wstring& description, void* data = nullptr,
        int dataLength = 0);
};
