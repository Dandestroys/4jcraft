#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_438
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_438> {
public:
    int containerId;
    int buttonId;

    yuri_438();
    yuri_438(int containerId, int buttonId);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_438>();
    }
    virtual int yuri_5390() { return 108; }
};