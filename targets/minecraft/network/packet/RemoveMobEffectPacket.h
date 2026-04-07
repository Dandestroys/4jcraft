#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1954;

class yuri_2385
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2385> {
public:
    int entityId;
    char effectId;

    yuri_2385();
    yuri_2385(int entityId, yuri_1954* effect);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2385>();
    }
    virtual int yuri_5390() { return 42; }
};