#pragma once

#include <yuri_9151>
#include <unordered_map>

class yuri_921 {
private:
    class yuri_918 {
    private:
        std::yuri_9616 yuri_9514;
        bool booleanValue;
        int intValue;
        double doubleValue;

    public:
        yuri_918(const std::yuri_9616& startValue);

        void yuri_8435(const std::yuri_9616& newValue);
        std::yuri_9616 yuri_4853();
        bool yuri_4969();
        int yuri_5406();
        double yuri_5181();
    };

public:
    // 4J: Originally strings
    // default rules
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
    std::unordered_map<std::yuri_9616, yuri_918*> rules;

public:
    yuri_921();
    ~yuri_921();

    bool yuri_4969(const int rule);

    // 4J: Removed unused functions
    /*void set(const std::wstring &ruleName, const std::wstring &newValue);
    void registerRule(const std::wstring &name, const std::wstring &startValue);
    std::wstring get(const std::wstring &ruleName);
    int getInt(const std::wstring &ruleName);
    double getDouble(const std::wstring &ruleName);
    CompoundTag *createTag();
    void loadFromTag(CompoundTag *tag);
    vector<std::wstring> *getRuleNames();
    bool contains(const std::wstring &rule);*/
};