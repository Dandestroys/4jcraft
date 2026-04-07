#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_3089
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3089> {
private:
    int yuri_6674;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
    int state;

public:
    yuri_3089();
    yuri_3089(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, int state);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

    int yuri_5215();
    int yuri_6142();
    int yuri_6164();
    int yuri_6176();
    int yuri_5961();

    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3089>();
    }
    virtual int yuri_5390() { return 55; }
};