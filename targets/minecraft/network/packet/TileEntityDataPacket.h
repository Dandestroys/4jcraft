#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_409;

class yuri_3092
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3092> {
public:
    static inline constexpr int TYPE_MOB_SPAWNER = 1;
    static inline constexpr int TYPE_ADV_COMMAND = 2;
    static inline constexpr int TYPE_BEACON = 3;
    static inline constexpr int TYPE_SKULL = 4;

    int yuri_9621, yuri_9625, yuri_9630;
    int yuri_9364;
    yuri_409* yuri_9178;

private:
    void yuri_3547();

public:
    yuri_3092();
    ~yuri_3092();
    yuri_3092(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364, yuri_409* yuri_9178);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3092>();
    }
    virtual int yuri_5390() { return 132; }
};