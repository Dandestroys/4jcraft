#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_68
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_68> {
public:
    static const int LIGHTNING;

    int yuri_6674;
    int yuri_9621, yuri_9625, yuri_9630;
    int yuri_9364;

    yuri_68();
    yuri_68(std::shared_ptr<yuri_739> e);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_68>();
    }
    virtual int yuri_5390() { return 71; }
};