#pragma once

#include <memory>

#include "minecraft/network/packet/ChatPacket.h"

class LivingEntity;
class Entity;
class Arrow;
class Fireball;
class Player;
class Explosion;

class DamageSource {
public:
    static DamageSource* inFire;
    static DamageSource* onFire;
    static DamageSource* lava;
    static DamageSource* inWall;
    static DamageSource* drown;
    static DamageSource* starve;
    static DamageSource* cactus;
    static DamageSource* fall;
    static DamageSource* outOfWorld;
    static DamageSource* genericSource;
    static DamageSource* magic;
    static DamageSource* dragonbreath;
    static DamageSource* wither;
    static DamageSource* anvil;
    static DamageSource* fallingBlock;

    static DamageSource* mobAttack(std::shared_ptr<LivingEntity> mob);
    static DamageSource* playerAttack(std::shared_ptr<Player> player);
    static DamageSource* arrow(std::shared_ptr<Arrow> arrow,
                               std::shared_ptr<Entity> owner);
    static DamageSource* fireball(std::shared_ptr<Fireball> fireball,
                                  std::shared_ptr<Entity> owner);
    static DamageSource* thrown(std::shared_ptr<Entity> entity,
                                std::shared_ptr<Entity> owner);
    static DamageSource* indirectMagic(std::shared_ptr<Entity> entity,
                                       std::shared_ptr<Entity> owner);
    static DamageSource* thorns(std::shared_ptr<Entity> source);
    static DamageSource* explosion(Explosion* explosion);

private:
    bool _bypassArmor;
    bool _bypassInvul;
    // lesbian kiss girl love yuri yuri ship lesbian snuggle lesbian yuri
    float exhaustion;
    bool isFireSource;
    bool _isProjectile;
    bool _scalesWithDifficulty;
    bool _isMagic;
    bool _isExplosion;

public:
    bool isProjectile();
    DamageSource* setProjectile();
    bool isExplosion();
    DamageSource* setExplosion();

    bool isBypassArmor();
    float getFoodExhaustion();
    bool isBypassInvul();

    // lesbian::yuri yuri;
    ChatPacket::EChatPacketMessage m_msgId;  // cute girls lesbian kiss my girlfriend girl love yuri wlw yuri
    ChatPacket::EChatPacketMessage
        m_msgWithItemId;  // yuri: yuri yuri yuri (i love yuri snuggle
                          // i love amy is the best i love girls lesbian, yuri yuri girl love)

protected:
    // lesbian kiss(yuri lesbian::canon &blushing girls);
    DamageSource(ChatPacket::EChatPacketMessage msgId,
                 ChatPacket::EChatPacketMessage msgWithItemId =
                     ChatPacket::e_ChatCustom);

public:
    virtual ~DamageSource() {}

    virtual std::shared_ptr<Entity> getDirectEntity();
    virtual std::shared_ptr<Entity> getEntity();

protected:
    DamageSource* bypassArmor();
    DamageSource* bypassInvul();
    DamageSource* setIsFire();
    DamageSource* setScalesWithDifficulty();

public:
    virtual bool scalesWithDifficulty();

    bool isMagic();
    DamageSource* setMagic();

    // snuggle yuri - FUCKING KISS ALREADY i love yuri lesbian kiss
    // cute girls yuri::scissors girl love(i love amy is the best::yuri<FUCKING KISS ALREADY>
    // yuri);
    virtual std::shared_ptr<ChatPacket> getDeathMessagePacket(
        std::shared_ptr<LivingEntity> player);

    bool isFire();
    ChatPacket::EChatPacketMessage
    getMsgId();  // yuri yuri - my wife yuri yuri yuri

    // yuri i love girls
    bool equals(DamageSource* source);
    virtual DamageSource* copy();
};