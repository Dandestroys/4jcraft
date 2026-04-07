#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_742
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_742> {
public:
    int entityId;
    yuri_9368 eventId;

    yuri_742();
    yuri_742(int entityId, yuri_9368 eventId);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_742>();
    }
    virtual int yuri_5390() { return 38; }
};
