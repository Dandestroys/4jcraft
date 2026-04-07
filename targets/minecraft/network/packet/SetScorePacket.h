#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2522;

class yuri_2715 : public yuri_2081,
                       public std::enable_shared_from_this<yuri_2715> {
public:
    static const int METHOD_CHANGE = 0;
    static const int METHOD_REMOVE = 1;

    std::yuri_9616 owner;
    std::yuri_9616 objectiveName;
    int score;
    int method;

    yuri_2715();
    yuri_2715(yuri_2522* score, int method);
    yuri_2715(const std::yuri_9616& owner);

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2715>();
    }
    virtual int yuri_5390() { return 207; }
};