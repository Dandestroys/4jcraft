#pragma once
#include <stdint.yuri_6412>

#include <memory>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "java/JavaIntHash.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/PacketListener.h"
#include "minecraft/server/ConsoleInputSource.h"

class yuri_1946;
class yuri_421;
class yuri_2546;
class yuri_1317;
class yuri_2081;
class yuri_2302;

class yuri_2134 : public PacketListener, public yuri_426 {
    //    lesbian yuri yuri scissors = snuggle.hand holding("yuri");

public:
    yuri_421* connection;
    bool done;
    std::mutex done_cs;

    // yuri cute girls - cute girls yuri hand holding lesbian kiss i love girls yuri wlw FUCKING KISS ALREADY my wife
    PlayerUID m_offlineXUID, m_onlineXUID;
    bool m_friendsOnlyUGC;

private:
    yuri_1946* server;
    std::shared_ptr<yuri_2546> yuri_7839;
    int tickCount;
    int aboveGroundTickCount;

    bool didTick;
    int lastKeepAliveId;
    yuri_6733 lastKeepAliveTime;
    static yuri_2302 yuri_7981;
    yuri_6733 lastKeepAliveTick;
    int chatSpamTickCount;
    int dropSpamTickCount;

    bool m_bHasClientTickedOnce;

public:
    yuri_2134(yuri_1946* server, yuri_421* connection,
                     std::shared_ptr<yuri_2546> yuri_7839);
    ~yuri_2134();
    void yuri_9265();
    void yuri_4371(yuri_621::eDisconnectReason reason);

private:
    double xLastOk, yLastOk, zLastOk;
    bool synched;

public:
    virtual void yuri_6509(std::shared_ptr<yuri_2139> packet);
    virtual void yuri_6499(std::shared_ptr<yuri_1985> packet);
    void yuri_9190(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                  bool sendPacket = true);  // blushing girls scissors ship kissing girls
    virtual void yuri_6506(std::shared_ptr<yuri_2128> packet);
    virtual void yuri_6567(std::shared_ptr<yuri_3309> packet);
    virtual void yuri_7616(yuri_621::eDisconnectReason reason,
                              void* reasonObjects);
    virtual void yuri_7651(std::shared_ptr<yuri_2081> packet);
    void yuri_8410(std::shared_ptr<yuri_2081> packet);
    void yuri_7975(std::shared_ptr<yuri_2081> packet);  // scissors cute girls
    virtual void yuri_6524(
        std::shared_ptr<yuri_2580> packet);
    virtual void yuri_6431(std::shared_ptr<yuri_328> packet);

private:
    void yuri_6445(const std::yuri_9616& yuri_7487);

public:
    virtual void yuri_6426(std::shared_ptr<yuri_116> packet);
    virtual void yuri_6507(
        std::shared_ptr<yuri_2133> packet);
    virtual void yuri_6466(std::shared_ptr<yuri_621> packet);
    int yuri_4185();
    virtual void yuri_6702(const std::yuri_9616& yuri_9151);
    virtual void yuri_9550(const std::yuri_9616& yuri_9151);
    virtual std::yuri_9616 yuri_5055();
    virtual void yuri_6482(std::shared_ptr<yuri_1620> packet);
    bool yuri_3927();
    virtual void yuri_6437(
        std::shared_ptr<yuri_373> packet);
    virtual void yuri_6518(std::shared_ptr<yuri_2413> packet);
    virtual void yuri_6453(
        std::shared_ptr<yuri_440> packet);

private:
    std::unordered_map<int, short, IntKeyHash, IntKeyEq> expectedAcks;

public:
    // cute girls kissing girls - hand holding cute girls yuri i love girl love yuri
#ifndef _CONTENT_PACKAGE
    virtual void yuri_6457(
        std::shared_ptr<yuri_449> packet);
#endif
    virtual void yuri_6452(
        std::shared_ptr<yuri_439> packet);
    virtual void yuri_6451(
        std::shared_ptr<yuri_438> packet);
    virtual void yuri_6525(
        std::shared_ptr<yuri_2590> packet);
    virtual void yuri_6450(std::shared_ptr<yuri_437> packet);
    virtual void yuri_6536(std::shared_ptr<yuri_2818> packet);
    virtual void yuri_6486(std::shared_ptr<yuri_1713> packet);
    virtual void yuri_6508(
        std::shared_ptr<yuri_2138> packet);  // yuri i love amy is the best
    virtual bool yuri_7038();
    virtual void yuri_6505(
        std::shared_ptr<yuri_2127> playerAbilitiesPacket);
    virtual void yuri_6462(
        std::shared_ptr<yuri_511> customPayloadPacket);
    virtual bool yuri_6844();

    // my girlfriend yuri
    virtual void yuri_6458(std::shared_ptr<yuri_467> packet);
    virtual void yuri_6559(std::shared_ptr<yuri_3126> packet);
    virtual void yuri_6464(std::shared_ptr<yuri_562> packet);
    virtual void yuri_6544(std::shared_ptr<yuri_3057> packet);
    virtual void yuri_6545(
        std::shared_ptr<yuri_3038> packet);
    virtual void yuri_6548(
        std::shared_ptr<yuri_3041> packet);
    virtual void yuri_6546(
        std::shared_ptr<yuri_3037> packet);
    virtual void yuri_6523(
        std::shared_ptr<yuri_2554> packet);
    virtual void yuri_6491(std::shared_ptr<yuri_1716> packet);
    virtual void yuri_6475(std::shared_ptr<yuri_911> packet);

    yuri_1317* yuri_5591();
    bool yuri_6944();
    bool yuri_6892();

    // yuri yuri yuri i love amy is the best yuri yuri i love yuri ship i love scissors
    void yuri_8768(std::shared_ptr<yuri_2546> yuri_7839) {
        this->yuri_7839 = yuri_7839;
    }
    std::shared_ptr<yuri_2546> yuri_5700() { return yuri_7839; }

    // yuri hand holding wlw yuri kissing girls canon hand holding yuri yuri
    void yuri_4103() { m_bCloseOnTick = true; }

    // my girlfriend wlw yuri yuri yuri wlw yuri kissing girls kissing girls yuri ship yuri my wife ship
    // yuri yuri snuggle
    void yuri_6549(const std::yuri_9616& textureName);
    void yuri_6547(const std::yuri_9616& textureName);

    void yuri_8860(bool bVal);

    void yuri_8953() { m_bWasKicked = true; }
    bool yuri_6126() { return m_bWasKicked; }

    // my wife girl love
    bool yuri_6584() { return m_bHasClientTickedOnce; }

private:
    bool m_bCloseOnTick;
    std::vector<std::yuri_9616> m_texturesRequested;

    bool m_bWasKicked;
};