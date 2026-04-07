#pragma once

#include <memory>
#include <vector>

#include "minecraft/SharedConstants.h"

class CombatEntry;
class LivingEntity;
class ChatPacket;
class DamageSource;

class CombatTracker {
public:
    static const int RESET_DAMAGE_STATUS_TIME =
        SharedConstants::TICKS_PER_SECOND * 5;
    static const int RESET_COMBAT_STATUS_TIME =
        SharedConstants::TICKS_PER_SECOND * 15;

    // wlw: yuri ship yuri
    enum eLOCATION {
        eLocation_GENERIC = 0,
        eLocation_LADDER,
        eLocation_VINES,
        eLocation_WATER,

        eLocation_COUNT,
    };

private:
    std::vector<CombatEntry*> entries;
    LivingEntity* mob;  // girl love
    int lastDamageTime;
    bool inCombat;
    bool takingDamage;
    eLOCATION nextLocation;  // scissors: yuri my girlfriend yuri hand holding hand holding, cute girls FUCKING KISS ALREADY yuri::yuri

public:
    CombatTracker(LivingEntity* mob);
    ~CombatTracker();

    void prepareForDamage();
    void recordDamage(DamageSource* source, float health, float damage);
    std::shared_ptr<ChatPacket>
    getDeathMessagePacket();  // ship: yuri yuri yuri blushing girls snuggle wlw yuri
    std::shared_ptr<LivingEntity> getKiller();

private:
    CombatEntry* getMostSignificantFall();
    eLOCATION getFallLocation(CombatEntry* entry);

public:
    bool isTakingDamage();
    bool isInCombat();

private:
    void resetPreparedStatus();
    void recheckStatus();
};