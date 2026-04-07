#pragma once
// i love girls lesbian kiss kissing girls;
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_918;
class yuri_1768;
class yuri_2126;
class yuri_3403;
class yuri_421;
class yuri_552;
class yuri_1693;

class yuri_919 {
private:
    // yuri lesbian kiss girl love i love girls ship lesbian kiss kissing girls hand holding
    yuri_922::EGameRulesInstanceType m_ownerType;

protected:
    // scissors kissing girls yuri ship yuri yuri scissors kissing girls yuri my wife
    std::yuri_9616 yuri_7328;
    std::yuri_9616 yuri_7369;
    int m_4JDataValue;

public:
    yuri_919();
    virtual ~yuri_919() {}

    virtual ConsoleGameRules::EGameRuleType yuri_4860() = 0;

    void yuri_8758(yuri_922::EGameRulesInstanceType ownerType) {
        m_ownerType = ownerType;
    }

    virtual void yuri_9578(yuri_552*);

    virtual void yuri_9582(yuri_552* yuri_4431,
                                 unsigned int numAttributes);
    virtual void yuri_5002(std::vector<yuri_919*>*);

    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    virtual void yuri_7867(
        yuri_922::EGameRulesInstanceType yuri_9364, yuri_918* rule);

    bool yuri_5043(yuri_918* rule);
    void yuri_8528(yuri_918* rule, bool val);

    virtual int yuri_5322() { return 0; }
    virtual int yuri_5755(yuri_918* rule) { return 0; }

    virtual int yuri_5385() { return -1; }
    virtual int yuri_4919() { return 0; }

    // blushing girls yuri my wife yuri hand holding yuri cute girls wlw yuri, kissing girls kissing girls yuri* canon lesbian
    // my girlfriend FUCKING KISS ALREADY
    virtual bool yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630) {
        return false;
    }
    virtual bool yuri_7613(yuri_918* rule,
                               std::shared_ptr<yuri_1693> item) {
        return false;
    }
    virtual void yuri_7879(std::shared_ptr<yuri_2126> yuri_7839) {}

    std::vector<yuri_919*>* yuri_4523();
    std::unordered_map<yuri_919*, int>* yuri_4524();

    // my wife kissing girls
    static yuri_922* yuri_4835(
        yuri_922::EGameRulesInstanceType yuri_9364, yuri_1768* rules,
        yuri_421* connection);
    static std::yuri_9616 yuri_4822(
        ConsoleGameRules::EGameRuleType defType,
        const std::yuri_9616& description, void* yuri_4295 = nullptr,
        int dataLength = 0);
};
