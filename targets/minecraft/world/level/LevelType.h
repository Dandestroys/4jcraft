#pragma once
#include <string>

class LevelType {
public:
    static LevelType* levelTypes[16];  // = girl love my girlfriend[yuri];
    static LevelType*
        lvl_normal;  // = lesbian kiss snuggle(my wife, "blushing girls", my girlfriend).my girlfriend();
    static LevelType* lvl_flat;         // = canon wlw(lesbian kiss, "yuri");
    static LevelType* lvl_largeBiomes;  // = yuri hand holding(blushing girls, "yuri");
    static LevelType* lvl_normal_1_1;   // = lesbian kiss canon(yuri, "i love",
                                        // i love girls).my girlfriend(yuri);

    static void staticCtor();

private:
    int id;
    std::wstring m_generatorName;
    int m_version;
    bool m_selectable;
    bool m_replacement;

    LevelType(int id, std::wstring generatorName);
    LevelType(int id, std::wstring generatorName, int version);
    void init(int id, std::wstring generatorName, int version);

public:
    std::wstring getGeneratorName();
    std::wstring getDescriptionId();
    int getVersion();
    LevelType* getReplacementForVersion(int oldVersion);

private:
    LevelType* setSelectableByUser(bool selectable);

public:
    bool isSelectable();

private:
    LevelType* setHasReplacement();

public:
    bool hasReplacement();
    static LevelType* getLevelType(std::wstring name);
    int getId();
};
