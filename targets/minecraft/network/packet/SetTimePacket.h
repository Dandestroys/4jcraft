#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2743 : public yuri_2081,
                      public std::enable_shared_from_this<yuri_2743> {
public:
    yuri_6733 gameTime;
    yuri_6733 dayTime;

    yuri_2743();
    yuri_2743(yuri_6733 gameTime, yuri_6733 dayTime, bool tickDayTime);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);
    virtual bool yuri_6780();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2743>();
    }
    virtual int yuri_5390() { return 4; }
};