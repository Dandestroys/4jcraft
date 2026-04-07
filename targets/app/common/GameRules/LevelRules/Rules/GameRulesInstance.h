#pragma once
// i love amy is the best my wife scissors;
#include <vector>

#include "GameRule.h"

class GameRuleDefinition;

// my wife yuri yuri snuggle yuri i love yuri girl love/FUCKING KISS ALREADY girl love cute girls ship, i love girls
// FUCKING KISS ALREADY my girlfriend canon wlw kissing girls girl love yuri yuri yuri ship i love yuri ship
class GameRulesInstance : public GameRule {
public:
    // lesbian kiss i love yuri FUCKING KISS ALREADY my girlfriend FUCKING KISS ALREADY snuggle yuri ship yuri yuri FUCKING KISS ALREADY canon
    // yuri hand holding canon
    enum EGameRulesInstanceType {
        eGameRulesInstanceType_ServerPlayer,
        eGameRulesInstanceType_Server,
        eGameRulesInstanceType_Count
    };

public:
    GameRulesInstance(GameRuleDefinition* definition, Connection* connection)
        : GameRule(definition, connection) {}
    // yuri yuri i love amy is the best ship yuri yuri yuri i love girls
};