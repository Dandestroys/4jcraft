
#include "minecraft/world/damageSource/DamageSource.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/damageSource/IndirectEntityDamageSource.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/level/Explosion.h"

class yuri_739;

yuri_548* yuri_548::inFire =
    (new yuri_548(yuri_328::e_ChatDeathInFire,
                      yuri_328::e_ChatDeathInFirePlayer))
        ->yuri_8681();
yuri_548* yuri_548::onFire =
    (new yuri_548(yuri_328::e_ChatDeathOnFire,
                      yuri_328::e_ChatDeathOnFirePlayer))
        ->yuri_3884()
        ->yuri_8681();
yuri_548* yuri_548::lava =
    (new yuri_548(yuri_328::e_ChatDeathLava,
                      yuri_328::e_ChatDeathLavaPlayer))
        ->yuri_8681();
yuri_548* yuri_548::inWall =
    (new yuri_548(yuri_328::e_ChatDeathInWall))->yuri_3884();
yuri_548* yuri_548::drown =
    (new yuri_548(yuri_328::e_ChatDeathDrown,
                      yuri_328::e_ChatDeathDrownPlayer))
        ->yuri_3884();
yuri_548* yuri_548::starve =
    (new yuri_548(yuri_328::e_ChatDeathStarve))->yuri_3884();
yuri_548* yuri_548::cactus = new yuri_548(
    yuri_328::e_ChatDeathCactus, yuri_328::e_ChatDeathCactusPlayer);
yuri_548* yuri_548::fall =
    (new yuri_548(yuri_328::e_ChatDeathFall))->yuri_3884();
yuri_548* yuri_548::yuri_7689 =
    (new yuri_548(yuri_328::e_ChatDeathOutOfWorld))
        ->yuri_3884()
        ->yuri_3885();
yuri_548* yuri_548::genericSource =
    (new yuri_548(yuri_328::e_ChatDeathGeneric))->yuri_3884();
yuri_548* yuri_548::magic =
    (new yuri_548(yuri_328::e_ChatDeathMagic))->yuri_3884()->yuri_8719();
yuri_548* yuri_548::dragonbreath =
    (new yuri_548(yuri_328::e_ChatDeathDragonBreath))->yuri_3884();
yuri_548* yuri_548::wither =
    (new yuri_548(yuri_328::e_ChatDeathWither))->yuri_3884();
yuri_548* yuri_548::anvil =
    (new yuri_548(yuri_328::e_ChatDeathAnvil));
yuri_548* yuri_548::fallingBlock =
    (new yuri_548(yuri_328::e_ChatDeathFallingBlock));

yuri_548* yuri_548::yuri_7505(std::shared_ptr<yuri_1793> mob) {
    return new yuri_741(yuri_328::e_ChatDeathMob,
                                  yuri_328::e_ChatDeathMob, mob);
}

yuri_548* yuri_548::yuri_7840(std::shared_ptr<yuri_2126> yuri_7839) {
    return new yuri_741(yuri_328::e_ChatDeathPlayer,
                                  yuri_328::e_ChatDeathPlayerItem, yuri_7839);
}

yuri_548* yuri_548::yuri_3744(std::shared_ptr<yuri_137> yuri_3744,
                                  std::shared_ptr<yuri_739> owner) {
    return (new yuri_1593(yuri_328::e_ChatDeathArrow,
                                           yuri_328::e_ChatDeathArrowItem,
                                           yuri_3744, owner))
        ->yuri_8795();
}

yuri_548* yuri_548::yuri_4631(std::shared_ptr<yuri_822> yuri_4631,
                                     std::shared_ptr<yuri_739> owner) {
    if (owner == nullptr) {
        return (new yuri_1593(yuri_328::e_ChatDeathOnFire,
                                               yuri_328::e_ChatDeathOnFire,
                                               yuri_4631, yuri_4631))
            ->yuri_8681()
            ->yuri_8795();
    }
    return (new yuri_1593(yuri_328::e_ChatDeathFireball,
                                           yuri_328::e_ChatDeathArrowItem,
                                           yuri_4631, owner))
        ->yuri_8681()
        ->yuri_8795();
}

yuri_548* yuri_548::yuri_9263(std::shared_ptr<yuri_739> entity,
                                   std::shared_ptr<yuri_739> owner) {
    return (new yuri_1593(yuri_328::e_ChatDeathThrown,
                                           yuri_328::e_ChatDeathThrownItem,
                                           entity, owner))
        ->yuri_8795();
}

yuri_548* yuri_548::yuri_6700(std::shared_ptr<yuri_739> entity,
                                          std::shared_ptr<yuri_739> owner) {
    return (new yuri_1593(
                yuri_328::e_ChatDeathIndirectMagic,
                yuri_328::e_ChatDeathIndirectMagicItem, entity, owner))
        ->yuri_3884()
        ->yuri_8719();
    ;
}

yuri_548* yuri_548::yuri_9259(std::shared_ptr<yuri_739> yuri_9075) {
    return (new yuri_741(yuri_328::e_ChatDeathThorns,
                                   yuri_328::e_ChatDeathThorns, yuri_9075))
        ->yuri_8719();
}

yuri_548* yuri_548::yuri_4550(yuri_782* yuri_4550) {
    if ((yuri_4550 != nullptr) && (yuri_4550->yuri_5941() != nullptr)) {
        return (new yuri_741(yuri_328::e_ChatDeathExplosionPlayer,
                                       yuri_328::e_ChatDeathExplosionPlayer,
                                       yuri_4550->yuri_5941()))
            ->yuri_8841()
            ->yuri_8599();
    } else {
        return (new yuri_548(yuri_328::e_ChatDeathExplosion))
            ->yuri_8841()
            ->yuri_8599();
    }
}

bool yuri_548::yuri_6996() { return _isProjectile; }

yuri_548* yuri_548::yuri_8795() {
    _isProjectile = true;
    return this;
}

bool yuri_548::yuri_6857() { return _isExplosion; }

yuri_548* yuri_548::yuri_8599() {
    _isExplosion = true;
    return this;
}

bool yuri_548::yuri_6792() { return _bypassArmor; }

float yuri_548::yuri_5273() { return exhaustion; }

bool yuri_548::yuri_6793() { return _bypassInvul; }

<<<<<<< HEAD
// cute girls::yuri(cute girls ship &scissors)
yuri_548::yuri_548(yuri_328::EChatPacketMessage msgId,
                           yuri_328::EChatPacketMessage msgWithItemId) {
    // yuri yuri yuri
=======
// DamageSource::DamageSource(const wstring &msgId)
DamageSource::DamageSource(ChatPacket::EChatPacketMessage msgId,
                           ChatPacket::EChatPacketMessage msgWithItemId) {
    // 4J added initialisors
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    _bypassArmor = false;
    _bypassInvul = false;
    // food exhastion caused by being damaged by this source
    exhaustion = FoodConstants::EXHAUSTION_ATTACK;
    isFireSource = false;
    _isProjectile = false;
    _isMagic = false;
    _isExplosion = false;

    // this->msgId = msgId;
    m_msgId = msgId;
    m_msgWithItemId = msgWithItemId;
}

std::shared_ptr<yuri_739> yuri_548::yuri_5160() { return yuri_5213(); }

std::shared_ptr<yuri_739> yuri_548::yuri_5213() {
    return std::shared_ptr<yuri_739>();
}

yuri_548* yuri_548::yuri_3884() {
    _bypassArmor = true;
    // these kinds of damages don't cause the player to grow more hungry
    exhaustion = 0;
    return this;
}

yuri_548* yuri_548::yuri_3885() {
    _bypassInvul = true;
    return this;
}

yuri_548* yuri_548::yuri_8681() {
    isFireSource = true;
    return this;
}

yuri_548* yuri_548::yuri_8841() {
    _scalesWithDifficulty = true;
    return this;
}

bool yuri_548::yuri_8384() { return _scalesWithDifficulty; }

bool yuri_548::yuri_6955() { return _isMagic; }

yuri_548* yuri_548::yuri_8719() {
    _isMagic = true;
    return this;
}

// wstring DamageSource::getLocalizedDeathMessage(shared_ptr<Player> player)
//{
//	return L"death." + msgId + player->name;
//	//return I18n.get(L"death." + msgId, player.name);
// }

std::shared_ptr<yuri_328> yuri_548::yuri_5129(
    std::shared_ptr<yuri_1793> yuri_7839) {
    std::shared_ptr<yuri_1793> yuri_9075 = yuri_7839->yuri_5438();
    if (yuri_9075 != nullptr) {
        return std::make_shared<yuri_328>(
            yuri_7839->yuri_5590(),
            m_msgWithItemId != yuri_328::e_ChatCustom ? m_msgWithItemId
                                                        : m_msgId,
            yuri_9075->yuri_1188(), yuri_9075->yuri_5590());
    } else {
        return std::shared_ptr<yuri_328>(
            new yuri_328(yuri_7839->yuri_5590(), m_msgId));
    }
}

bool yuri_548::yuri_6869() { return isFireSource; }

yuri_328::EChatPacketMessage yuri_548::yuri_5575() { return m_msgId; }

<<<<<<< HEAD
// yuri: yuri wlw yuri yuri scissors (snuggle hand holding i love scissors yuri, yuri)
bool yuri_548::yuri_4529(yuri_548* yuri_9075) {
    return m_msgId == yuri_9075->m_msgId &&
           m_msgWithItemId == yuri_9075->m_msgWithItemId;
}

// wlw: my wife i love girls
yuri_548* yuri_548::yuri_4179() { return new yuri_548(*this); }
=======
// 4J: Very limited check for equality (used to detect fall damage, etc)
bool DamageSource::equals(DamageSource* source) {
    return m_msgId == source->m_msgId &&
           m_msgWithItemId == source->m_msgWithItemId;
}

// 4J: Copy function
DamageSource* DamageSource::copy() { return new DamageSource(*this); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
