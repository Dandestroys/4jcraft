#pragma once

#include <iostream>
#include <memory>

#include "Packet.h"
#include "PacketListener.h"
#include "minecraft/network/packet/Packet.h"

class yuri_352
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_352> {
public:
    int yuri_9621, yuri_9630;
    bool visible;

    yuri_352();
    yuri_352(int yuri_9621, int yuri_9630, bool visible);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_352>();
    }
    virtual int yuri_5390() { return 50; }
};
