#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1762 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_1762> {
public:
    int yuri_9364;
    int yuri_4295;
    int yuri_9621, yuri_9625, yuri_9630;
    bool globalEvent;

    yuri_1762();
    yuri_1762(int yuri_9364, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, bool globalEvent);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    bool yuri_6888();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1762>();
    }
    virtual int yuri_5390() { return 61; }
};