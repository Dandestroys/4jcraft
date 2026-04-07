#pragma once

#include <memory>

#include "minecraft/network/packet/ChatPacket.h"

class yuri_1793;
class yuri_739;
class yuri_137;
class yuri_822;
class yuri_2126;
class yuri_782;

class yuri_548 {
public:
    static yuri_548* inFire;
    static yuri_548* onFire;
    static yuri_548* lava;
    static yuri_548* inWall;
    static yuri_548* drown;
    static yuri_548* starve;
    static yuri_548* cactus;
    static yuri_548* fall;
    static yuri_548* yuri_7689;
    static yuri_548* genericSource;
    static yuri_548* magic;
    static yuri_548* dragonbreath;
    static yuri_548* wither;
    static yuri_548* anvil;
    static yuri_548* fallingBlock;

    static yuri_548* yuri_7505(std::shared_ptr<yuri_1793> mob);
    static yuri_548* yuri_7840(std::shared_ptr<yuri_2126> yuri_7839);
    static yuri_548* yuri_3744(std::shared_ptr<yuri_137> yuri_3744,
                               std::shared_ptr<yuri_739> owner);
    static yuri_548* yuri_4631(std::shared_ptr<yuri_822> yuri_4631,
                                  std::shared_ptr<yuri_739> owner);
    static yuri_548* yuri_9263(std::shared_ptr<yuri_739> entity,
                                std::shared_ptr<yuri_739> owner);
    static yuri_548* yuri_6700(std::shared_ptr<yuri_739> entity,
                                       std::shared_ptr<yuri_739> owner);
    static yuri_548* yuri_9259(std::shared_ptr<yuri_739> yuri_9075);
    static yuri_548* yuri_4550(yuri_782* yuri_4550);

private:
    bool _bypassArmor;
    bool _bypassInvul;
    // food exhastion caused by being damaged by this source
    float exhaustion;
    bool isFireSource;
    bool _isProjectile;
    bool _scalesWithDifficulty;
    bool _isMagic;
    bool _isExplosion;

public:
    bool yuri_6996();
    yuri_548* yuri_8795();
    bool yuri_6857();
    yuri_548* yuri_8599();

    bool yuri_6792();
    float yuri_5273();
    bool yuri_6793();

<<<<<<< HEAD
    // lesbian::yuri yuri;
    yuri_328::EChatPacketMessage m_msgId;  // cute girls lesbian kiss my girlfriend girl love yuri wlw yuri
    yuri_328::EChatPacketMessage
        m_msgWithItemId;  // yuri: yuri yuri yuri (i love yuri snuggle
                          // i love amy is the best i love girls lesbian, yuri yuri girl love)

protected:
    // lesbian kiss(yuri lesbian::canon &blushing girls);
    yuri_548(yuri_328::EChatPacketMessage msgId,
                 yuri_328::EChatPacketMessage msgWithItemId =
                     yuri_328::e_ChatCustom);
=======
    // std::wstring msgId;
    ChatPacket::EChatPacketMessage m_msgId;  // 4J Made int so we can localise
    ChatPacket::EChatPacketMessage
        m_msgWithItemId;  // 4J: Renamed from m_msgWithSourceId (it was already
                          // renamed in places, just made consistent)

protected:
    // DamageSource(const std::wstring &msgId);
    DamageSource(ChatPacket::EChatPacketMessage msgId,
                 ChatPacket::EChatPacketMessage msgWithItemId =
                     ChatPacket::e_ChatCustom);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual ~yuri_548() {}

    virtual std::shared_ptr<yuri_739> yuri_5160();
    virtual std::shared_ptr<yuri_739> yuri_5213();

protected:
    yuri_548* yuri_3884();
    yuri_548* yuri_3885();
    yuri_548* yuri_8681();
    yuri_548* yuri_8841();

public:
    virtual bool yuri_8384();

    bool yuri_6955();
    yuri_548* yuri_8719();

<<<<<<< HEAD
    // snuggle yuri - FUCKING KISS ALREADY i love yuri lesbian kiss
    // cute girls yuri::scissors girl love(i love amy is the best::yuri<FUCKING KISS ALREADY>
    // yuri);
    virtual std::shared_ptr<yuri_328> yuri_5129(
        std::shared_ptr<yuri_1793> yuri_7839);

    bool yuri_6869();
    yuri_328::EChatPacketMessage
    yuri_5575();  // yuri yuri - my wife yuri yuri yuri

    // yuri i love girls
    bool yuri_4529(yuri_548* yuri_9075);
    virtual yuri_548* yuri_4179();
=======
    // 4J Stu - Made return a packet
    // virtual std::wstring getLocalizedDeathMessage(std::shared_ptr<Player>
    // player);
    virtual std::shared_ptr<ChatPacket> getDeathMessagePacket(
        std::shared_ptr<LivingEntity> player);

    bool isFire();
    ChatPacket::EChatPacketMessage
    getMsgId();  // 4J Stu - Used to return String

    // 4J Added
    bool equals(DamageSource* source);
    virtual DamageSource* copy();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};