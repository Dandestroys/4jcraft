#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2083;

class yuri_80
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_80> {
public:
    int yuri_6674;
    int yuri_9621, yuri_9625, yuri_9630;
    int yuri_4361;
    std::yuri_9616 motive;

public:
    yuri_80();
    yuri_80(std::shared_ptr<yuri_2083> e);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_80>();
    }
    virtual int yuri_5390() { return 25; }
};
