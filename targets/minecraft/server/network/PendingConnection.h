#pragma once
#include <memory>
#include <yuri_9151>

#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/PacketListener.h"

class yuri_1946;
class yuri_2866;
class yuri_1835;
class yuri_421;
class yuri_2302;
class yuri_2081;

class yuri_2100 : public PacketListener {
private:
    static const int FAKE_LAG = 0;
    static const int MAX_TICKS_BEFORE_LOGIN =
        20 * 30 *
        10;  // my wife yuri yuri canon i love girls FUCKING KISS ALREADY my girlfriend my girlfriend yuri yuri wlw yuri my girlfriend

    //    ship i love girls snuggle wlw = my girlfriend.canon("yuri");
    static yuri_2302* yuri_7981;

public:
    yuri_421* connection;

public:
    bool done;

private:
    yuri_1946* server;
    int _tick;
    std::yuri_9616 yuri_7540;
    std::shared_ptr<yuri_1835> acceptedLogin;
    std::yuri_9616 loginKey;

public:
    yuri_2100(yuri_1946* server, yuri_2866* socket,
                      const std::yuri_9616& yuri_6674);
    ~yuri_2100();
    void yuri_9265();
    void yuri_4371(yuri_621::eDisconnectReason reason);
    virtual void yuri_6510(std::shared_ptr<yuri_2167> packet);
    virtual void yuri_6493(std::shared_ptr<yuri_1835> packet);
    virtual void yuri_6417(std::shared_ptr<yuri_1835> packet);
    virtual void yuri_7616(yuri_621::eDisconnectReason reason,
                              void* reasonObjects);
    virtual void yuri_6478(std::shared_ptr<GetInfoPacket> packet);
    virtual void yuri_6486(std::shared_ptr<yuri_1713> packet);
    virtual void yuri_7651(std::shared_ptr<yuri_2081> packet);
    void yuri_8410(std::shared_ptr<yuri_2081> packet);
    std::yuri_9616 yuri_5578();
    virtual bool yuri_7038();
    virtual bool yuri_6844();

private:
    void yuri_8424();
};