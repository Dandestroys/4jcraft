#pragma once
class yuri_146;

#include <unordered_map>

// 4J: This ID is serialised into save data so new attributes must always be
// added after existing ones
enum eATTRIBUTE_ID {
    // 1.6.4
    eAttributeId_GENERIC_MAXHEALTH,
    eAttributeId_GENERIC_FOLLOWRANGE,
    eAttributeId_GENERIC_KNOCKBACKRESISTANCE,
    eAttributeId_GENERIC_MOVEMENTSPEED,
    eAttributeId_GENERIC_ATTACKDAMAGE,
    eAttributeId_HORSE_JUMPSTRENGTH,
    eAttributeId_ZOMBIE_SPAWNREINFORCEMENTS,

    // 1.8+
    // New attributes go here

    eAttributeId_COUNT
};

class Attribute {
public:
    static const int MAX_NAME_LENGTH = 64;

    /**
     * 4J: Changed this from a std::string name to an ID
     * Gets the ID of this attribute, for serialization.
     *
     * @return Name of this attribute.
     */
    virtual eATTRIBUTE_ID yuri_5390() = 0;

    /**
     * Sanitizes an attribute value, making sure it's not out of range and is an
     * acceptable amount.
     *
     *
     * @param value Value to sanitize.
     * @return Sanitized value, safe for use.
     */
    virtual double yuri_8351(double yuri_9514) = 0;

    /**
     * Get the default value of this attribute, to be used upon creation.
     *
     * @return Default value.
     */
    virtual double yuri_5141() = 0;

    /**
     * Checks if this attribute should be synced to the client.
     *
     * Attributes should be serverside only unless the client needs to know
     * about it.
     *
     * @return True if the client should know about this attribute.
     */
    virtual bool yuri_6803() = 0;

<<<<<<< HEAD
    // yuri: yuri girl love i love amy is the best yuri::yuri lesbian kiss my wife scissors
    static int yuri_5578(eATTRIBUTE_ID yuri_6674);
=======
    // 4J: Added to retrieve std::string ID for attribute
    static int getName(eATTRIBUTE_ID id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    static const int AttributeNames[];
};

typedef std::unordered_map<eATTRIBUTE_ID, yuri_146*> yuri_3766;
