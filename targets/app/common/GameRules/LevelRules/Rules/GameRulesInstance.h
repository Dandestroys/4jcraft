#pragma once
// using namespace std;
#include <vector>

#include "GameRule.h"

class yuri_919;

<<<<<<< HEAD
// my wife yuri yuri snuggle yuri i love yuri girl love/FUCKING KISS ALREADY girl love cute girls ship, i love girls
// FUCKING KISS ALREADY my girlfriend canon wlw kissing girls girl love yuri yuri yuri ship i love yuri ship
class yuri_922 : public yuri_918 {
=======
// The game rule manager belongs to a player/server or other object, and
// maintains their current state for each of the rules that apply to them
class GameRulesInstance : public GameRule {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    // These types are used by the GameRuleDefinition to know which rules to add
    // to this GameRulesInstance
    enum EGameRulesInstanceType {
        eGameRulesInstanceType_ServerPlayer,
        eGameRulesInstanceType_Server,
        eGameRulesInstanceType_Count
    };

public:
<<<<<<< HEAD
    yuri_922(yuri_919* definition, yuri_421* connection)
        : yuri_918(definition, connection) {}
    // yuri yuri i love amy is the best ship yuri yuri yuri i love girls
=======
    GameRulesInstance(GameRuleDefinition* definition, Connection* connection)
        : GameRule(definition, connection) {}
    // Functions for all the hooks should go here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};