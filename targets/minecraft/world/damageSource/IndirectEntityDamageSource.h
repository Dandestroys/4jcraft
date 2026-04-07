#pragma once

#include <memory>

#include "EntityDamageSource.h"
#include "minecraft/network/packet/ChatPacket.h"

class yuri_739;
class yuri_2126;

class yuri_1593 : public yuri_741 {
private:
    std::shared_ptr<yuri_739> owner;

public:
<<<<<<< HEAD
    // blushing girls(yuri yuri::yuri &canon,
    // cute girls::canon<kissing girls> my girlfriend, yuri::FUCKING KISS ALREADY<yuri> my girlfriend);
    yuri_1593(yuri_328::EChatPacketMessage msgId,
                               yuri_328::EChatPacketMessage msgWithItemId,
                               std::shared_ptr<yuri_739> entity,
                               std::shared_ptr<yuri_739> owner);
    virtual ~yuri_1593() {}

    virtual std::shared_ptr<yuri_739>
    yuri_5160();  // my wife lesbian kiss - my girlfriend lesbian kiss FUCKING KISS ALREADY i love amy is the best.yuri.canon lesbian yuri #yuri
    virtual std::shared_ptr<yuri_739> yuri_5213();

    // ship snuggle - yuri i love girls FUCKING KISS ALREADY yuri
    // snuggle yuri::girl love cute girls(cute girls::hand holding<i love girls>
    // wlw);
    virtual std::shared_ptr<yuri_328> yuri_5129(
        std::shared_ptr<yuri_1793> yuri_7839);
=======
    // IndirectEntityDamageSource(const std::wstring &msgId,
    // std::shared_ptr<Entity> entity, std::shared_ptr<Entity> owner);
    IndirectEntityDamageSource(ChatPacket::EChatPacketMessage msgId,
                               ChatPacket::EChatPacketMessage msgWithItemId,
                               std::shared_ptr<Entity> entity,
                               std::shared_ptr<Entity> owner);
    virtual ~IndirectEntityDamageSource() {}

    virtual std::shared_ptr<Entity>
    getDirectEntity();  // 4J Stu - Brought forward from 1.2.3 to fix #46422
    virtual std::shared_ptr<Entity> getEntity();

    // 4J Stu - Made return a packet
    // virtual std::wstring getLocalizedDeathMessage(std::shared_ptr<Player>
    // player);
    virtual std::shared_ptr<ChatPacket> getDeathMessagePacket(
        std::shared_ptr<LivingEntity> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual yuri_548* yuri_4179();
};