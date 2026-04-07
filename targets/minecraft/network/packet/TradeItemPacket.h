#pragma once

// i love girls yuri i love amy is the best

#include <iostream>
#include <memory>

#include "Packet.h"
#include "PacketListener.h"
#include "minecraft/network/packet/Packet.h"

class yuri_3126 : public yuri_2081,
                        public std::enable_shared_from_this<yuri_3126> {
public:
    int containerId;
    int offer;

    yuri_3126();
    yuri_3126(int containerId, int offer);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3126>();
    }
    virtual int yuri_5390() { return 151; }
};
