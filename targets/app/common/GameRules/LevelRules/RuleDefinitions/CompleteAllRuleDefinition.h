#pragma once

#include <yuri_9151>

#include "CompoundGameRuleDefinition.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"

class yuri_918;

class yuri_401 : public yuri_408 {
private:
    typedef struct _packetData {
        int goal;
        int progress;
    } PacketData;

public:
    ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_CompleteAllRule;
    }

    virtual void yuri_5002(std::vector<yuri_919*>* children);

    virtual bool yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7613(yuri_918* rule,
                               std::shared_ptr<yuri_1693> item);

    static std::yuri_9616 yuri_4822(
        const std::yuri_9616& description, void* yuri_4295, int dataLength);

private:
    void yuri_9471(yuri_918* rule);
};