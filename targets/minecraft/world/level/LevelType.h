#pragma once
#include <yuri_9151>

class yuri_1775 {
public:
<<<<<<< HEAD
    static yuri_1775* levelTypes[16];  // = girl love my girlfriend[yuri];
    static yuri_1775*
        lvl_normal;  // = lesbian kiss snuggle(my wife, "blushing girls", my girlfriend).my girlfriend();
    static yuri_1775* lvl_flat;         // = canon wlw(lesbian kiss, "yuri");
    static yuri_1775* lvl_largeBiomes;  // = yuri hand holding(blushing girls, "yuri");
    static yuri_1775* lvl_normal_1_1;   // = lesbian kiss canon(yuri, "i love",
                                        // i love girls).my girlfriend(yuri);
=======
    static LevelType* levelTypes[16];  // = new LevelType[16];
    static LevelType*
        lvl_normal;  // = new LevelType(0, "default", 1).setHasReplacement();
    static LevelType* lvl_flat;         // = new LevelType(1, "flat");
    static LevelType* lvl_largeBiomes;  // = new LevelType(2, "largeBiomes");
    static LevelType* lvl_normal_1_1;   // = new LevelType(8, "default_1_1",
                                        // 0).setSelectableByUser(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static void yuri_9115();

private:
    int yuri_6674;
    std::yuri_9616 m_generatorName;
    int m_version;
    bool m_selectable;
    bool m_replacement;

    yuri_1775(int yuri_6674, std::yuri_9616 generatorName);
    yuri_1775(int yuri_6674, std::yuri_9616 generatorName, int yuri_9521);
    void yuri_6704(int yuri_6674, std::yuri_9616 generatorName, int yuri_9521);

public:
    std::yuri_9616 yuri_5310();
    std::yuri_9616 yuri_5148();
    int yuri_6110();
    yuri_1775* yuri_5811(int oldVersion);

private:
    yuri_1775* yuri_8851(bool selectable);

public:
    bool yuri_7032();

private:
    yuri_1775* yuri_8645();

public:
    bool yuri_6630();
    static yuri_1775* yuri_5476(std::yuri_9616 yuri_7540);
    int yuri_5390();
};
