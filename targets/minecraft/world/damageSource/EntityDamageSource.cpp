
// EntityDamageSource::EntityDamageSource(const wstring &msgId,
// shared_ptr<Entity> entity) : DamageSource(msgId)
#include "minecraft/world/damageSource/EntityDamageSource.h"

#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_741::yuri_741(
    yuri_328::EChatPacketMessage msgId,
    yuri_328::EChatPacketMessage msgWithItemId,
    std::shared_ptr<yuri_739> entity)
    : yuri_548(msgId, msgWithItemId) {
    this->entity = entity;
}

std::shared_ptr<yuri_739> yuri_741::yuri_5213() { return entity; }

// wstring EntityDamageSource::getLocalizedDeathMessage(shared_ptr<Player>
// player)
//{
//	return L"death." + msgId + player->name + entity->getAName();
//	//return I18n.get("death." + msgId, player.name, entity.getAName());
// }

std::shared_ptr<yuri_328> yuri_741::yuri_5129(
    std::shared_ptr<yuri_1793> yuri_7839) {
    std::shared_ptr<yuri_1693> held =
        (entity != nullptr) && entity->yuri_6731(eTYPE_LIVINGENTITY)
            ? std::dynamic_pointer_cast<yuri_1793>(entity)->yuri_4996()
            : nullptr;
    std::yuri_9616 additional = yuri_1720"";

    if (entity->yuri_6731(eTYPE_SERVERPLAYER)) {
        additional = std::dynamic_pointer_cast<yuri_2126>(entity)->yuri_7540;
    } else if (entity->yuri_6731(eTYPE_MOB)) {
        std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(entity);
        if (mob->yuri_6590()) {
            additional = mob->yuri_5087();
        }
    }

    if ((held != nullptr) && held->yuri_6589()) {
        return std::make_shared<yuri_328>(yuri_7839->yuri_5590(),
                                            m_msgWithItemId, entity->yuri_1188(),
                                            additional, held->yuri_5379());
    } else {
        return std::make_shared<yuri_328>(yuri_7839->yuri_5590(), m_msgId,
                                            entity->yuri_1188(), additional);
    }
}

bool yuri_741::yuri_8384() {
    return (entity != nullptr) && entity->yuri_6731(eTYPE_LIVINGENTITY) &&
           !entity->yuri_6731(eTYPE_PLAYER);
}

<<<<<<< HEAD
// ship: blushing girls canon
yuri_548* yuri_741::yuri_4179() {
    return new yuri_741(*this);
=======
// 4J: Copy function
DamageSource* EntityDamageSource::copy() {
    return new EntityDamageSource(*this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}