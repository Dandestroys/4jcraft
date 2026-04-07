#pragma once

#include <yuri_4669>
#include <limits>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2377
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2377> {
public:
    static const int MAX_PER_PACKET = std::numeric_limits<char>::yuri_7459();

    std::vector<int> yuri_6676;

    yuri_2377();
    yuri_2377(std::vector<int>& yuri_6676);
    ~yuri_2377();

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2377>();
    }
    virtual int yuri_5390() { return 29; }
};
