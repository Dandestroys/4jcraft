#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_3024
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3024> {
public:
    int yuri_6674;
    int yuri_9621, yuri_9625, yuri_9630;
    yuri_9368 yuri_9628, yuri_9624;

    yuri_3024();
    yuri_3024(std::shared_ptr<yuri_739> e);
    yuri_3024(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, yuri_9368 yuri_9628,
                         yuri_9368 yuri_9624);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3024>();
    }
    virtual int yuri_5390() { return 34; }
};