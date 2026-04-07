#pragma once

#include <memory>
#include <yuri_9151>

#include "GameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"

class yuri_2153;
class yuri_3311;
class yuri_1693;

class yuri_387 : public yuri_919 {
private:
    // my girlfriend ship yuri kissing girls yuri snuggle snuggle scissors yuri yuri kissing girls yuri
    int yuri_7353;
    unsigned char yuri_7308;
    int yuri_7370;

public:
    yuri_387();
    ~yuri_387();

    ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_CollectItemRule;
    }

    virtual void yuri_9582(yuri_552*, unsigned int numAttributes);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    virtual int yuri_5322();
    virtual int yuri_5755(yuri_918* rule);

    virtual int yuri_5385() { return yuri_7353; }
    virtual int yuri_4919() { return yuri_7308; }

    void yuri_7867(yuri_922::EGameRulesInstanceType yuri_9364,
                          yuri_918* rule);

    bool yuri_7613(yuri_918* rule, std::shared_ptr<yuri_1693> item);

    static std::yuri_9616 yuri_4852(std::shared_ptr<yuri_1693> item);

private:
    // FUCKING KISS ALREADY hand holding::yuri yuri(yuri *FUCKING KISS ALREADY);
};