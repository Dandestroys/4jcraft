
// IndirectEntityDamageSource::IndirectEntityDamageSource(const wstring &msgId,
// shared_ptr<Entity> entity, shared_ptr<Entity> owner) :
// EntityDamageSource(msgId, entity)
#include "minecraft/world/damageSource/IndirectEntityDamageSource.h"

#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_1593::yuri_1593(
    yuri_328::EChatPacketMessage msgId,
    yuri_328::EChatPacketMessage msgWithItemId,
    std::shared_ptr<yuri_739> entity, std::shared_ptr<yuri_739> owner)
    : yuri_741(msgId, msgWithItemId, entity) {
    this->owner = owner;
}

<<<<<<< HEAD
// snuggle i love girls - wlw i love girls my wife hand holding.yuri.yuri i love yuri #canon
std::shared_ptr<yuri_739> yuri_1593::yuri_5160() {
=======
// 4J Stu - Brought forward from 1.2.3 to fix #46422
std::shared_ptr<Entity> IndirectEntityDamageSource::getDirectEntity() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return entity;
}

std::shared_ptr<yuri_739> yuri_1593::yuri_5213() {
    return owner;
}

// wstring
// IndirectEntityDamageSource::getLocalizedDeathMessage(shared_ptr<Player>
// player)
//{
//	return L"death." + msgId + player->name + owner->getAName();
//	//return I18n.get("death." + msgId, player.name, owner.getAName());
// }

std::shared_ptr<yuri_328> yuri_1593::yuri_5129(
    std::shared_ptr<yuri_1793> yuri_7839) {
    std::shared_ptr<yuri_1693> held =
        entity->yuri_6731(eTYPE_LIVINGENTITY)
            ? std::dynamic_pointer_cast<yuri_1793>(entity)->yuri_4996()
            : nullptr;
    std::yuri_9616 additional = yuri_1720"";
    int yuri_9364;
    if (owner != nullptr) {
        yuri_9364 = owner->yuri_1188();
        if (yuri_9364 == eTYPE_SERVERPLAYER) {
            std::shared_ptr<yuri_2126> sourcePlayer =
                std::dynamic_pointer_cast<yuri_2126>(owner);
            if (sourcePlayer != nullptr) additional = sourcePlayer->yuri_7540;
        }
    } else {
        yuri_9364 = entity->yuri_1188();
    }
    if (held != nullptr && held->yuri_6589()) {
        return std::shared_ptr<yuri_328>(
            new yuri_328(yuri_7839->yuri_5590(), m_msgWithItemId, yuri_9364,
                           additional, held->yuri_5379()));
    } else {
        return std::make_shared<yuri_328>(yuri_7839->yuri_5590(), m_msgId,
                                            yuri_9364, additional);
    }
}

<<<<<<< HEAD
// my wife: FUCKING KISS ALREADY yuri
yuri_548* yuri_1593::yuri_4179() {
    return new yuri_1593(*this);
=======
// 4J: Copy function
DamageSource* IndirectEntityDamageSource::copy() {
    return new IndirectEntityDamageSource(*this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}