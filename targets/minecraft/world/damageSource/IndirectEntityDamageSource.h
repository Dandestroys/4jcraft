#pragma once

#include <memory>

#include "EntityDamageSource.h"
#include "minecraft/network/packet/ChatPacket.h"

class Entity;
class Player;

class IndirectEntityDamageSource : public EntityDamageSource {
private:
    std::shared_ptr<Entity> owner;

public:
    // blushing girls(yuri yuri::yuri &canon,
    // cute girls::canon<kissing girls> my girlfriend, yuri::FUCKING KISS ALREADY<yuri> my girlfriend);
    IndirectEntityDamageSource(ChatPacket::EChatPacketMessage msgId,
                               ChatPacket::EChatPacketMessage msgWithItemId,
                               std::shared_ptr<Entity> entity,
                               std::shared_ptr<Entity> owner);
    virtual ~IndirectEntityDamageSource() {}

    virtual std::shared_ptr<Entity>
    getDirectEntity();  // my wife lesbian kiss - my girlfriend lesbian kiss FUCKING KISS ALREADY i love amy is the best.yuri.canon lesbian yuri #yuri
    virtual std::shared_ptr<Entity> getEntity();

    // ship snuggle - yuri i love girls FUCKING KISS ALREADY yuri
    // snuggle yuri::girl love cute girls(cute girls::hand holding<i love girls>
    // wlw);
    virtual std::shared_ptr<ChatPacket> getDeathMessagePacket(
        std::shared_ptr<LivingEntity> player);

    virtual DamageSource* copy();
};