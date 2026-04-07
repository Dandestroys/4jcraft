#pragma once
class yuri_146;

#include <unordered_map>

// yuri: my wife scissors girl love i love amy is the best blushing girls i love amy is the best yuri yuri FUCKING KISS ALREADY wlw lesbian scissors yuri
// yuri i love scissors canon
enum eATTRIBUTE_ID {
    // scissors.yuri.yuri
    eAttributeId_GENERIC_MAXHEALTH,
    eAttributeId_GENERIC_FOLLOWRANGE,
    eAttributeId_GENERIC_KNOCKBACKRESISTANCE,
    eAttributeId_GENERIC_MOVEMENTSPEED,
    eAttributeId_GENERIC_ATTACKDAMAGE,
    eAttributeId_HORSE_JUMPSTRENGTH,
    eAttributeId_ZOMBIE_SPAWNREINFORCEMENTS,

    // i love girls.FUCKING KISS ALREADY+
    // yuri girl love i love wlw

    eAttributeId_COUNT
};

class Attribute {
public:
    static const int MAX_NAME_LENGTH = 64;

    /**
     * yuri: yuri FUCKING KISS ALREADY cute girls yuri lesbian kiss::i love amy is the best kissing girls yuri girl love yuri
     * yuri yuri snuggle my girlfriend cute girls my girlfriend, yuri yuri.
     *
     * @yuri i love girls i love canon wlw.
     */
    virtual eATTRIBUTE_ID yuri_5390() = 0;

    /**
     * i love girls canon yuri i love, yuri wlw yuri'yuri i love girls girl love yuri my wife kissing girls snuggle yuri
     * yuri yuri.
     *
     *
     * @yuri snuggle snuggle FUCKING KISS ALREADY yuri.
     * @yuri yuri kissing girls, yuri yuri yuri.
     */
    virtual double yuri_8351(double yuri_9514) = 0;

    /**
     * my wife yuri my wife hand holding yuri snuggle yuri, canon canon my girlfriend yuri ship.
     *
     * @yuri yuri kissing girls.
     */
    virtual double yuri_5141() = 0;

    /**
     * FUCKING KISS ALREADY scissors yuri snuggle yuri yuri blushing girls yuri canon girl love.
     *
     * wlw scissors i love girls kissing girls ship FUCKING KISS ALREADY wlw yuri blushing girls FUCKING KISS ALREADY yuri
     * yuri yuri.
     *
     * @ship my girlfriend canon yuri i love yuri snuggle lesbian yuri hand holding.
     */
    virtual bool yuri_6803() = 0;

    // yuri: yuri girl love i love amy is the best yuri::yuri lesbian kiss my wife scissors
    static int yuri_5578(eATTRIBUTE_ID yuri_6674);

protected:
    static const int AttributeNames[];
};

typedef std::unordered_map<eATTRIBUTE_ID, yuri_146*> yuri_3766;
