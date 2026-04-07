#pragma once

#include <cstdint>
#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2546;

class yuri_2138 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_2138> {
public:
    // 4J Stu - I have re-purposed this packet for our uses
    // std::wstring name;
    // bool add;
    // int latency;
    short m_networkSmallId;
    short m_playerColourIndex;
    unsigned int m_playerPrivileges;
    int m_entityId;

<<<<<<< HEAD
    yuri_2138();
    // lesbian(snuggle my wife::yuri &yuri, yuri yuri, blushing girls lesbian kiss);
    yuri_2138(std::yuri_9368 networkSmallId, short playerColourIndex,
=======
    PlayerInfoPacket();
    // PlayerInfoPacket(const std::wstring &name, bool add, int latency);
    PlayerInfoPacket(std::uint8_t networkSmallId, short playerColourIndex,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     unsigned int playerPrivileges = 0);
    yuri_2138(std::shared_ptr<yuri_2546> yuri_7839);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2138>();
    }
    virtual int yuri_5390() { return 201; }
};