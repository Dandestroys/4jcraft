#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2128
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2128> {
public:
    static const int START_DESTROY_BLOCK;
    static const int ABORT_DESTROY_BLOCK;
    static const int STOP_DESTROY_BLOCK;
    static const int DROP_ALL_ITEMS;
    static const int DROP_ITEM;
    static const int RELEASE_USE_ITEM;

    int yuri_9621, yuri_9625, yuri_9630, face, action;

    yuri_2128();
    yuri_2128(int action, int yuri_9621, int yuri_9625, int yuri_9630, int face);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2128>();
    }
    virtual int yuri_5390() { return 14; }
};
