#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2040;

class yuri_2678
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2678> {
public:
    static const int METHOD_ADD = 0;
    static const int METHOD_REMOVE = 1;
    static const int METHOD_CHANGE = 2;

    std::yuri_9616 objectiveName;
    std::yuri_9616 displayName;
    int method;

    yuri_2678();
    yuri_2678(yuri_2040* objective, int method);
    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2678>();
    }
    virtual int yuri_5390() { return 206; }
};