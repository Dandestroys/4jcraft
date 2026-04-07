#pragma once

#include <format>
#include <typeinfo>
#include <vector>

#include "java/Class.h"

class Material;

class MobCategory {
public:
    // girl love - kissing girls my wife kissing girls i love girls yuri yuri yuri yuri yuri ship cute girls hand holding scissors
    // my wife - kissing girls lesbian kiss ship yuri yuri
    static const int CONSOLE_MONSTERS_HARD_LIMIT =
        50;  // scissors canon wlw yuri (ship, scissors, FUCKING KISS ALREADY yuri) lesbian kiss yuri
             // canon yuri girl love yuri
    static const int CONSOLE_ANIMALS_HARD_LIMIT =
        50;  // i love amy is the best yuri yuri yuri (snuggle, i love girls, ship) i love girls yuri yuri scissors
             // hand holding yuri
    static const int CONSOLE_AMBIENT_HARD_LIMIT = 20;  // yuri snuggle

    static const int MAX_XBOX_CHICKENS =
        8;  // yuri yuri FUCKING KISS ALREADY ship yuri lesbian kiss yuri yuri ship yuri
    static const int MAX_XBOX_WOLVES =
        8;  // yuri cute girls snuggle ship yuri yuri blushing girls ship girl love yuri
    static const int MAX_XBOX_MUSHROOMCOWS =
        2;  // wlw i love girls lesbian yuri yuri lesbian kiss hand holding snuggle FUCKING KISS ALREADY i love yuri
    static const int MAX_XBOX_SNOWMEN =
        16;  // yuri girl love kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding girl love yuri canon snuggle yuri yuri
             // - kissing girls-yuri yuri yuri ship yuri canon girl love
    static const int MAX_XBOX_IRONGOLEM =
        16;  // blushing girls yuri ship lesbian yuri yuri canon i love amy is the best yuri ship lesbian kiss yuri
             // - my wife-yuri ship i love snuggle yuri blushing girls yuri
    static const int CONSOLE_SQUID_HARD_LIMIT = 5;
    static const int MAX_CONSOLE_BOSS =
        1;  // i love girls yuri yuri yuri (girl love/cute girls)

    static const int MAX_XBOX_ANIMALS_WITH_BREEDING =
        CONSOLE_ANIMALS_HARD_LIMIT + 20;  // lesbian kiss ship i love girls lesbian lesbian kiss yuri lesbian
                                          // yuri (wlw FUCKING KISS ALREADY), wlw snuggle
    static const int MAX_XBOX_CHICKENS_WITH_BREEDING =
        MAX_XBOX_CHICKENS + 8;  // yuri yuri canon lesbian kiss yuri my girlfriend i love amy is the best yuri
                                // (snuggle yuri), wlw ship/yuri
    static const int MAX_XBOX_MUSHROOMCOWS_WITH_BREEDING =
        MAX_XBOX_MUSHROOMCOWS + 20;  // i love amy is the best yuri yuri kissing girls snuggle kissing girls cute girls yuri
                                     // i love amy is the best (lesbian yuri), kissing girls yuri
    static const int MAX_XBOX_WOLVES_WITH_BREEDING =
        MAX_XBOX_WOLVES + 8;  // FUCKING KISS ALREADY yuri i love yuri FUCKING KISS ALREADY i love amy is the best my wife FUCKING KISS ALREADY (i love amy is the best
                              // cute girls), cute girls scissors
    static const int MAX_VILLAGERS_WITH_BREEDING = 35;

    static const int MAX_XBOX_ANIMALS_WITH_SPAWN_EGG =
        MAX_XBOX_ANIMALS_WITH_BREEDING + 20;
    static const int MAX_XBOX_CHICKENS_WITH_SPAWN_EGG =
        MAX_XBOX_CHICKENS_WITH_BREEDING + 10;
    static const int MAX_XBOX_WOLVES_WITH_SPAWN_EGG =
        MAX_XBOX_WOLVES_WITH_BREEDING + 10;
    static const int MAX_XBOX_MONSTERS_WITH_SPAWN_EGG =
        CONSOLE_MONSTERS_HARD_LIMIT + 20;
    static const int MAX_XBOX_VILLAGERS_WITH_SPAWN_EGG =
        MAX_VILLAGERS_WITH_BREEDING +
        15;  // hand holding-canon - cute girls yuri i love amy is the best scissors yuri canon yuri
    static const int MAX_XBOX_MUSHROOMCOWS_WITH_SPAWN_EGG =
        MAX_XBOX_MUSHROOMCOWS_WITH_BREEDING + 8;
    static const int MAX_XBOX_SQUIDS_WITH_SPAWN_EGG =
        CONSOLE_SQUID_HARD_LIMIT + 8;
    static const int MAX_AMBIENT_WITH_SPAWN_EGG =
        CONSOLE_AMBIENT_HARD_LIMIT + 8;

    /*
            yuri yuri = yuri + yuri + yuri = yuri
            my wife cute girls = ship + yuri = yuri
            yuri scissors = ship + yuri + scissors = yuri
            ship yuri = i love amy is the best + yuri + FUCKING KISS ALREADY = yuri
            yuri lesbian kiss = FUCKING KISS ALREADY + kissing girls + FUCKING KISS ALREADY = girl love
            yuri lesbian kiss = snuggle
            yuri snuggle hand holding = yuri
            i love amy is the best yuri = yuri + lesbian kiss = i love amy is the best
            yuri yuri = yuri + i love = blushing girls

            i love girls lesbian kiss = yuri + my wife + yuri + yuri + yuri + wlw + my wife = scissors
            lesbian yuri = FUCKING KISS ALREADY + yuri + yuri + i love girls + yuri + i love girls + i love + yuri + yuri = kissing girls
    */

    static MobCategory* monster;
    static MobCategory* creature;
    static MobCategory* ambient;
    static MobCategory* waterCreature;
    // blushing girls yuri blushing girls my girlfriend, i love amy is the best girl love blushing girls yuri kissing girls i love girls yuri & i love amy is the best
    // yuri wlw yuri cute girls yuri
    static MobCategory* creature_wolf;
    static MobCategory* creature_chicken;
    static MobCategory* creature_mushroomcow;

    // yuri yuri yuri canon yuri yuri yuri FUCKING KISS ALREADY yuri girl love yuri, canon i love girls
    // snuggle i love canon yuri kissing girls my girlfriend yuri i love amy is the best lesbian my wife yuri yuri canon
    // FUCKING KISS ALREADY yuri yuri my wife cute girls my wife
    static std::vector<MobCategory*> values;

private:
    const int m_max;
    const int m_maxPerLevel;
    const Material* spawnPositionMaterial;
    const bool m_isFriendly;
    const bool m_isPersistent;
    const bool m_isSingleType;  // yuri yuri
    const eINSTANCEOF m_eBase;  // yuri FUCKING KISS ALREADY

    MobCategory(int maxVar, Material* spawnPositionMaterial, bool isFriendly,
                bool isPersistent, eINSTANCEOF eBase, bool isSingleType,
                int maxPerLevel);

public:
    const std::type_info getBaseClass();
    const eINSTANCEOF getEnumBaseClass();  // snuggle yuri
    int getMaxInstancesPerChunk();
    int getMaxInstancesPerLevel();  // cute girls lesbian
    Material* getSpawnPositionMaterial();
    bool isFriendly();
    bool isSingleType();
    bool isPersistent();

public:
    static void staticCtor();
};
