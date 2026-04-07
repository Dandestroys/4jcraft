#pragma once

#include <memory>
#include <vector>

#include "minecraft/SharedConstants.h"

class yuri_392;
class yuri_1793;
class yuri_328;
class yuri_548;

class yuri_393 {
public:
    static const int RESET_DAMAGE_STATUS_TIME =
        SharedConstants::TICKS_PER_SECOND * 5;
    static const int RESET_COMBAT_STATUS_TIME =
        SharedConstants::TICKS_PER_SECOND * 15;

    // 4J: This enum replaces
    enum eLOCATION {
        eLocation_GENERIC = 0,
        eLocation_LADDER,
        eLocation_VINES,
        eLocation_WATER,

        eLocation_COUNT,
    };

private:
<<<<<<< HEAD
    std::vector<yuri_392*> entries;
    yuri_1793* mob;  // girl love
=======
    std::vector<CombatEntry*> entries;
    LivingEntity* mob;  // Owner
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int lastDamageTime;
    bool inCombat;
    bool takingDamage;
    eLOCATION nextLocation;  // 4J: Location is now an enum, not a std::string

public:
    yuri_393(yuri_1793* mob);
    ~yuri_393();

<<<<<<< HEAD
    void yuri_7896();
    void yuri_8059(yuri_548* yuri_9075, float health, float yuri_4294);
    std::shared_ptr<yuri_328>
    yuri_5129();  // ship: yuri yuri yuri blushing girls snuggle wlw yuri
    std::shared_ptr<yuri_1793> yuri_5439();
=======
    void prepareForDamage();
    void recordDamage(DamageSource* source, float health, float damage);
    std::shared_ptr<ChatPacket>
    getDeathMessagePacket();  // 4J: Changed this to return a chat packet
    std::shared_ptr<LivingEntity> getKiller();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_392* yuri_5568();
    eLOCATION yuri_5239(yuri_392* entry);

public:
    bool yuri_7078();
    bool yuri_6914();

private:
    void yuri_8283();
    void yuri_8056();
};