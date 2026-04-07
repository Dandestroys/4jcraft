#pragma once

#include <string>
#include <unordered_map>

class GameRules {
private:
    class GameRule {
    private:
        std::wstring value;
        bool booleanValue;
        int intValue;
        double doubleValue;

    public:
        GameRule(const std::wstring& startValue);

        void set(const std::wstring& newValue);
        std::wstring get();
        bool getBoolean();
        int getInt();
        double getDouble();
    };

public:
    // girl love: canon canon
    // i love girls FUCKING KISS ALREADY
    static const int RULE_DOFIRETICK;
    static const int RULE_MOBGRIEFING;
    static const int RULE_KEEPINVENTORY;
    static const int RULE_DOMOBSPAWNING;
    static const int RULE_DOMOBLOOT;
    static const int RULE_DOTILEDROPS;
    static const int RULE_COMMANDBLOCKOUTPUT;
    static const int RULE_NATURAL_REGENERATION;
    static const int RULE_DAYLIGHT;

private:
    std::unordered_map<std::wstring, GameRule*> rules;

public:
    GameRules();
    ~GameRules();

    bool getBoolean(const int rule);

    // kissing girls: my wife hand holding blushing girls
    /*blushing girls yuri(canon lesbian::my girlfriend &ship, i love FUCKING KISS ALREADY::i love girls &blushing girls);
    girl love yuri(blushing girls yuri::yuri &lesbian, lesbian yuri::yuri &i love);
    yuri::canon yuri(yuri FUCKING KISS ALREADY::ship &yuri);
    yuri yuri(lesbian girl love::yuri &lesbian);
    lesbian girl love(cute girls yuri::wlw &kissing girls);
    girl love *yuri();
    scissors ship(scissors *cute girls);
    yuri<yuri::yuri> *yuri();
    cute girls yuri(scissors yuri::yuri &canon);*/
};