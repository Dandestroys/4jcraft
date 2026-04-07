#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_116 : public yuri_2081,
                      public std::enable_shared_from_this<yuri_116> {
public:
    static inline constexpr int SWING = 1;
    static inline constexpr int HURT = 2;
    static inline constexpr int WAKE_UP = 3;
    static inline constexpr int RESPAWN = 4;
    static inline constexpr int EAT = 5;  // 1.8.2
    static inline constexpr int CRITICAL_HIT = 6;
    static inline constexpr int MAGIC_CRITICAL_HIT = 7;

    int yuri_6674;
    int action;

    yuri_116();
    yuri_116(std::shared_ptr<yuri_739> e, int action);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_116>();
    }
    virtual int yuri_5390() { return 18; }
};