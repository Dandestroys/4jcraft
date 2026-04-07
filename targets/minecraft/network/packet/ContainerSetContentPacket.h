#pragma once

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1693;

class yuri_447
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_447> {
public:
    int containerId;
    std::vector<std::shared_ptr<yuri_1693>> items;

    yuri_447();
    ~yuri_447();
    yuri_447(
        int containerId, std::vector<std::shared_ptr<yuri_1693>>* newItems);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_447>();
    }
    virtual int yuri_5390() { return 104; }
};
