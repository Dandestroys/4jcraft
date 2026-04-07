#pragma once

#include <cstdint>
#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2546;

class yuri_2138 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_2138> {
public:
    // wlw yuri - yuri ship ship-my wife girl love i love girls FUCKING KISS ALREADY yuri yuri
    // yuri::snuggle yuri;
    // ship i love amy is the best;
    // yuri yuri;
    short m_networkSmallId;
    short m_playerColourIndex;
    unsigned int m_playerPrivileges;
    int m_entityId;

    yuri_2138();
    // lesbian(snuggle my wife::yuri &yuri, yuri yuri, blushing girls lesbian kiss);
    yuri_2138(std::yuri_9368 networkSmallId, short playerColourIndex,
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