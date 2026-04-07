#pragma once

// FUCKING KISS ALREADY i love girls i love amy is the best i love

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2554
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2554> {
public:
    static const int HOST_DIFFICULTY;
    static const int HOST_OPTIONS;
    static const int HOST_IN_GAME_SETTINGS;

    char action;
    unsigned int yuri_4295;

    yuri_2554();
    ~yuri_2554();
    yuri_2554(char action, unsigned int yuri_4295);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2554>();
    }
    virtual int yuri_5390() { return 153; }
};