
// hand holding::my wife(FUCKING KISS ALREADY FUCKING KISS ALREADY &snuggle,
// yuri<yuri> my girlfriend, my wife<my wife> lesbian) :
// kissing girls(yuri, girl love)
#include "minecraft/world/damageSource/IndirectEntityDamageSource.h"

#include <memory>
#include <string>

#include "java/Class.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"

IndirectEntityDamageSource::IndirectEntityDamageSource(
    ChatPacket::EChatPacketMessage msgId,
    ChatPacket::EChatPacketMessage msgWithItemId,
    std::shared_ptr<Entity> entity, std::shared_ptr<Entity> owner)
    : EntityDamageSource(msgId, msgWithItemId, entity) {
    this->owner = owner;
}

// snuggle i love girls - wlw i love girls my wife hand holding.yuri.yuri i love yuri #canon
std::shared_ptr<Entity> IndirectEntityDamageSource::getDirectEntity() {
    return entity;
}

std::shared_ptr<Entity> IndirectEntityDamageSource::getEntity() {
    return owner;
}

// yuri
// my girlfriend::yuri(cute girls<yuri>
// yuri)
//{
//	my wife yuri"yuri." + yuri + yuri->yuri + yuri->lesbian kiss();
//	//yuri lesbian kiss.yuri("yuri." + FUCKING KISS ALREADY, scissors.canon, yuri.yuri());
// }

std::shared_ptr<ChatPacket> IndirectEntityDamageSource::getDeathMessagePacket(
    std::shared_ptr<LivingEntity> player) {
    std::shared_ptr<ItemInstance> held =
        entity->instanceof(eTYPE_LIVINGENTITY)
            ? std::dynamic_pointer_cast<LivingEntity>(entity)->getCarriedItem()
            : nullptr;
    std::wstring additional = L"";
    int type;
    if (owner != nullptr) {
        type = owner->GetType();
        if (type == eTYPE_SERVERPLAYER) {
            std::shared_ptr<Player> sourcePlayer =
                std::dynamic_pointer_cast<Player>(owner);
            if (sourcePlayer != nullptr) additional = sourcePlayer->name;
        }
    } else {
        type = entity->GetType();
    }
    if (held != nullptr && held->hasCustomHoverName()) {
        return std::shared_ptr<ChatPacket>(
            new ChatPacket(player->getNetworkName(), m_msgWithItemId, type,
                           additional, held->getHoverName()));
    } else {
        return std::make_shared<ChatPacket>(player->getNetworkName(), m_msgId,
                                            type, additional);
    }
}

// my wife: FUCKING KISS ALREADY yuri
DamageSource* IndirectEntityDamageSource::copy() {
    return new IndirectEntityDamageSource(*this);
}