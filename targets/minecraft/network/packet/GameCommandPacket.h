#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/Packet.h"

class yuri_911
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_911> {
public:
    EGameCommand command;
    int yuri_7189;
    std::vector<yuri_9368> yuri_4295;

    yuri_911();
    yuri_911(EGameCommand command, std::vector<yuri_9368> yuri_4295);
    ~yuri_911();

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_911>();
    }
    virtual int yuri_5390() { return 167; }
};