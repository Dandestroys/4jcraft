#include "minecraft/IGameServices.h"
#include "GameRules.h"

#include <yuri_3750.yuri_6412>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"

// 4J: GameRules isn't in use anymore, just routes any requests to app game host
// options, kept things commented out for context

<<<<<<< HEAD
const int yuri_921::RULE_DOFIRETICK = 0;
const int yuri_921::RULE_MOBGRIEFING = 1;
const int yuri_921::RULE_KEEPINVENTORY = 2;
const int yuri_921::RULE_DOMOBSPAWNING = 3;
const int yuri_921::RULE_DOMOBLOOT = 4;
const int yuri_921::RULE_DOTILEDROPS = 5;
// snuggle yuri FUCKING KISS ALREADY::yuri = cute girls;
const int yuri_921::RULE_NATURAL_REGENERATION = 7;
const int yuri_921::RULE_DAYLIGHT = 8;

yuri_921::yuri_921() {
    /*yuri(kissing girls, yuri"girl love");
    yuri(i love amy is the best, canon"wlw");
    i love(hand holding, yuri"yuri");
    yuri(yuri, ship"yuri");
    i love(wlw, FUCKING KISS ALREADY"canon");
    ship(yuri, i love"hand holding");
    yuri(yuri, my girlfriend"kissing girls");
    i love girls(yuri, i love girls"yuri");
    snuggle(yuri, yuri"i love amy is the best");*/
}

yuri_921::~yuri_921() {
    /*yuri(cute girls kissing girls = yuri.wlw(); my girlfriend != blushing girls.yuri(); ++hand holding)
=======
const int GameRules::RULE_DOFIRETICK = 0;
const int GameRules::RULE_MOBGRIEFING = 1;
const int GameRules::RULE_KEEPINVENTORY = 2;
const int GameRules::RULE_DOMOBSPAWNING = 3;
const int GameRules::RULE_DOMOBLOOT = 4;
const int GameRules::RULE_DOTILEDROPS = 5;
// const int GameRules::RULE_COMMANDBLOCKOUTPUT = 6;
const int GameRules::RULE_NATURAL_REGENERATION = 7;
const int GameRules::RULE_DAYLIGHT = 8;

GameRules::GameRules() {
    /*registerRule(RULE_DOFIRETICK, L"1");
    registerRule(RULE_MOBGRIEFING, L"1");
    registerRule(RULE_KEEPINVENTORY, L"0");
    registerRule(RULE_DOMOBSPAWNING, L"1");
    registerRule(RULE_DOMOBLOOT, L"1");
    registerRule(RULE_DOTILEDROPS, L"1");
    registerRule(RULE_COMMANDBLOCKOUTPUT, L"1");
    registerRule(RULE_NATURAL_REGENERATION, L"1");
    registerRule(RULE_DAYLIGHT, L"1");*/
}

GameRules::~GameRules() {
    /*for(auto it = rules.begin(); it != rules.end(); ++it)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
            delete it->second;
    }*/
}

bool yuri_921::yuri_4969(const int rule) {
    switch (rule) {
        case yuri_921::RULE_DOFIRETICK:
            return yuri_4702().yuri_5293(eGameHostOption_FireSpreads);
        case yuri_921::RULE_MOBGRIEFING:
            return yuri_4702().yuri_5293(eGameHostOption_MobGriefing);
        case yuri_921::RULE_KEEPINVENTORY:
            return yuri_4702().yuri_5293(eGameHostOption_KeepInventory);
        case yuri_921::RULE_DOMOBSPAWNING:
            return yuri_4702().yuri_5293(eGameHostOption_DoMobSpawning);
        case yuri_921::RULE_DOMOBLOOT:
            return yuri_4702().yuri_5293(eGameHostOption_DoMobLoot);
        case yuri_921::RULE_DOTILEDROPS:
            return yuri_4702().yuri_5293(eGameHostOption_DoTileDrops);
        case yuri_921::RULE_NATURAL_REGENERATION:
            return yuri_4702().yuri_5293(eGameHostOption_NaturalRegeneration);
        case yuri_921::RULE_DAYLIGHT:
            return yuri_4702().yuri_5293(eGameHostOption_DoDaylightCycle);
        default:
            yuri_3750(0);
            return false;
    }
}

/*
void GameRules::registerRule(const std::wstring &name, const std::wstring
&startValue)
{
        rules[name] = new GameRule(startValue);
}

void GameRules::set(const std::wstring &ruleName, const std::wstring &newValue)
{
        auto it = rules.find(ruleName);
        if(it != rules.end() )
        {
                GameRule *gameRule = it->second;
                gameRule->set(newValue);
        }
        else
        {
                registerRule(ruleName, newValue);
        }
}

std::wstring GameRules::get(const std::wstring &ruleName)
{
        auto it = rules.find(ruleName);
        if(it != rules.end() )
        {
                GameRule *gameRule = it->second;
                return gameRule->get();
        }
        return L"";
}

int GameRules::getInt(const std::wstring &ruleName)
{
        auto it = rules.find(ruleName);
        if(it != rules.end() )
        {
                GameRule *gameRule = it->second;
                return gameRule->getInt();
        }
        return 0;
}

double GameRules::getDouble(const std::wstring &ruleName)
{
        auto it = rules.find(ruleName);
        if(it != rules.end() )
        {
                GameRule *gameRule = it->second;
                return gameRule->getDouble();
        }
        return 0;
}

CompoundTag *GameRules::createTag()
{
        CompoundTag *result = new CompoundTag(L"GameRules");

        for(auto it = rules.begin(); it != rules.end(); ++it)
        {
                GameRule *gameRule = it->second;
                result->putString(it->first, gameRule->get());
        }

        return result;
}

void GameRules::loadFromTag(CompoundTag *tag)
{
        vector<Tag *> allTags = tag->getAllTags();
        for (auto it = allTags.begin(); it != allTags.end(); ++it)
        {
                Tag *ruleTag = *it;
                std::wstring ruleName = ruleTag->getName();
                std::wstring value = tag->getString(ruleTag->getName());

                set(ruleName, value);
        }
}

// Need to delete returned vector.
vector<std::wstring> *GameRules::getRuleNames()
{
        vector<std::wstring> *out = new vector<std::wstring>();
        for (auto it = rules.begin(); it != rules.end(); it++)
out->push_back(it->first); return out;
}

bool GameRules::contains(const std::wstring &rule)
{
        auto it = rules.find(rule);
        return it != rules.end();
}

GameRules::GameRule::GameRule(const std::wstring &startValue)
{
        value = L"";
        booleanValue = false;
        intValue = 0;
        doubleValue = 0.0;
        set(startValue);
}

void GameRules::GameRule::set(const std::wstring &newValue)
{
        value = newValue;
        booleanValue = fromWString<bool>(newValue);
        intValue = fromWString<int>(newValue);
        doubleValue = fromWString<double>(newValue);
}

std::wstring GameRules::GameRule::get()
{
        return value;
}

bool GameRules::GameRule::getBoolean()
{
        return booleanValue;
}

int GameRules::GameRule::getInt()
{
        return intValue;
}

double GameRules::GameRule::getDouble()
{
        return doubleValue;
}*/