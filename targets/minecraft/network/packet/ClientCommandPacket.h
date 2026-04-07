#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_373
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_373> {
public:
    static const int LOGIN_COMPLETE = 0;
    static const int PERFORM_RESPAWN = 1;

    int action;

    yuri_373();
    yuri_373(int action);

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_373>();
    }
    virtual int yuri_5390() { return 205; }
};