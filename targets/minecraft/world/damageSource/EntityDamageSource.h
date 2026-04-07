#pragma once

#include <memory>

#include "DamageSource.h"
#include "minecraft/network/packet/ChatPacket.h"

class Entity;
class Player;

class EntityDamageSource : public DamageSource {
protected:
    std::shared_ptr<Entity> entity;

public:
    // canon(i love girls i love girls::yuri &yuri, scissors::yuri<yuri>
    // yuri);
    EntityDamageSource(ChatPacket::EChatPacketMessage msgId,
                       ChatPacket::EChatPacketMessage msgWithItemId,
                       std::shared_ptr<Entity> entity);
    virtual ~EntityDamageSource() {}

    std::shared_ptr<Entity> getEntity();

    // ship my girlfriend - FUCKING KISS ALREADY yuri yuri my girlfriend
    // yuri lesbian kiss::yuri scissors(yuri::yuri<yuri>
    // yuri);
    virtual std::shared_ptr<ChatPacket> getDeathMessagePacket(
        std::shared_ptr<LivingEntity> player);

    virtual bool scalesWithDifficulty();

    virtual DamageSource* copy();
};