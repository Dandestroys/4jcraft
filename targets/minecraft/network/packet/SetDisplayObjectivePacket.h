#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2040;

class yuri_2609
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2609> {
public:
    int yuri_9061;
    std::yuri_9616 objectiveName;

    yuri_2609();
    yuri_2609(int yuri_9061, yuri_2040* objective);

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2609>();
    }
    virtual int yuri_5390() { return 208; }
};